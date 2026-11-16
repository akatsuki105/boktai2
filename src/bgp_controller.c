#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// スクリプトの '.f' で選ぶ動き, どちらも立っていなければ渡されたパレットをそのまま出すだけ (屋内など)
typedef u8 BgPlttControllerFlags;
#define BGPLTTCTRL_TIMEOFDAY (1 << 0)  // 0x1, 屋外用, 現実の時刻に合わせて昼・夕方・夜のパレットを切り替え, 雨が降ると暗くする
#define BGPLTTCTRL_OSCILLATE (1 << 1)  // 0x2, 2枚のパレットの間を一定の周期で行き来させる

// マップの BG パレットを受け持つシングルトン, HashName("背景パレットキャラ"), マップに入るたびにスクリプト (Scr_CreateBgPlttController など) が作る
// 屋外では現実の時刻に合わせて昼・夕方・夜のパレットを切り替え, 時間帯が変わると約1秒かけて移り変わり, 雨が降っている間は暗くする
// 画面のフェードや別のパレットへのクロスフェードは BG パレットコマンド (Cmd_SendBgPlttCommand, StartBgObjPlttFade) で受ける, OBJ 側は ObjPlttController
// スクリプトが渡すインスタンスIDは 0xE231 (Scr_CreateBgPlttController), 0x317B, 0xF68D, 0x4AE5 (クラスと同じ) と HashName("ＢＧパレットキャラ") = 0xA58E
typedef struct {
  Entity e;                      // ENTITY_UNK_11
  u16 id;                        // 0x018
  BgPlttControllerFlags flags;   // 0x01A, '.f', see BgPlttControllerFlags
  u8 state;                      // 0x01B, いま進めている演出, 0 なし, 1 別パレットへのクロスフェード, 2/4 フェードイン, 3/5 フェードアウト, 6 フェードアウトし終えて暗いまま, 4 以上の間は 4/5 のフェードしか受け付けない
  u8 crossfadeLevel;             // 0x01C, クロスフェード (コマンド1) の進み具合, 0x40 を超えたら乗り換え完了
  u8 crossfadeRow;               // 0x01D, クロスフェードで次に混ぜるパレット行, 1フレームで全行は混ぜず数行ずつ進める
  u8 crossfadeLevelStep;         // 0x01E, 全行を混ぜ終えるたびに crossfadeLevel を上げる量, 既定 7
  u8 crossfadeRowStep;           // 0x01F, 1フレームに混ぜるパレット行数, 既定 4
  bool8 plttUpdated;             // 0x020, dstPltt を書いたら 1, _Update の先頭で 0, BgPlttController_IsPlttUpdated で bgp_blend.c などが見て自分の処理を重ね直す
  u8 unk_21[0x24 - 0x21];        // 0x021, padding?
  const rgb555* srcPltt1;        // 0x024, 時間帯連動では切り替わり元の時間帯のパレット, それ以外は基本のパレット
  const rgb555* srcPltt2;        // 0x028, 時間帯連動では切り替わり先の時間帯のパレット, それ以外は混ぜ先のパレット
  rgb555* dstPltt;               // 0x02C, gBgPlttBuffer, 画面に出る BG パレット
  rgb555* curPltt;               // 0x030, いま画面へ書くパレット, 晴れなら plttTimeBlend, 雨なら plttWeatherBlend
  rgb555 plttTimeBlend[256];     // 0x034, 時間帯のパレット, 切り替わりの途中なら前後の時間帯を混ぜたもの
  rgb555 plttWeatherBlend[256];  // 0x234, plttTimeBlend を雨の暗さ (weatherLevel) だけ plttWeather に寄せたもの
  rgb555 plttWeather[256];       // 0x434, 雨のときに寄せる暗いパレット, 夜のパレット (bgpIDs[2]) をさらに 50/64 に落としたもの
  FileID bgpIDs[4];              // 0x634, '.p', 時間帯連動では [0] 昼, [1] 夕方, [2] 夜, それ以外は '.c' / '.m' がこの番号で基本と混ぜ先を選ぶ
  u16 fadeTimer;                 // 0x63C, 画面のフェード (コマンド2〜5) の経過フレーム, (1 << fadeShift) に達したら終わり
  u16 fadeShift;                 // 0x63E, フェードの長さの log2
  u8 timeBlendLevel;             // 0x640, 時間帯が変わったときの移り変わりの進み具合, 1フレームに1ずつ進み 0x40 (64フレーム) で完了
  u8 prevTimeBlendLevel;         // 0x641, 前フレームの timeBlendLevel の控え, 読み手は未発見
  u8 weatherLevel;               // 0x642, 雨による暗さ, 晴れなら 0, 雨の間は昼 (朝を含む) なら 0x20, 夕方と夜なら 0x40 まで暗くなる
  u8 prevWeatherLevel;           // 0x643, 前フレームの weatherLevel, 変わったときだけ暗いパレットを混ぜ直す
  u8 weatherState;               // 0x644, 雨の進み具合, 0 晴れ, 1 降り始め, 2 降っている, 3 止み際, RainManager が BgPlttController_SetWeatherState で入れる
  u16 unk_648;                   // 0x648, _Init と時間帯の変わり目で 0 を入れるだけ, 読み手は未発見
  u16 unk_64a;                   // 0x64A, 0 のときだけ weatherState の処理を回す, 非0 を入れる箇所は未発見
  u16 spanOfTime;                // 0x64C, 前フレームの時間帯 (TIME_XXX), gClock と違っていたら移り変わりを始める
  u16 twilightLevel;             // 0x64E, gClock.twilightLevel の写し, 書くだけで読み手がいない
  u16 oscTimer;                  // 0x650, oscPeriod に達すると oscLevel を1段動かす
  u16 unk_652;                   // 0x652, '.a[0]=4', 読み手は未発見
  u16 oscLevel;                  // 0x654, 往復の今の位置, 0 で srcPltt1, 0x40 で srcPltt2
  u16 oscPeriod;                 // 0x656, '.a[1]=2', oscTimer の上限
  u8 oscRow;                     // 0x658, 往復で次に混ぜるパレット行, 数フレームに分けて全行を混ぜる
  u8 oscRowStep;                 // 0x659, '.a[2]=8', 1回に進めるパレット行数
  bool8 oscActive;               // 0x65A, 0 以外なら BgPlttController_Update が BgPlttController_BlendRows を呼ぶ
  u8 unk_65b;                    // 0x65B
  u16 oscRowMask;                // 0x65C, '.a[3]=0xFFFF', 混合するパレット行のビットマスク
  u16 oscWait;                   // 0x65E, 端で止まっている残りフレーム
  u16 oscStep;                   // 0x660, '.a[4]=0x20', 1周期ごとに oscLevel を動かす量, 端で折り返すと符号が反転する
  u16 oscWaitLength;             // 0x662, '.a[5]=0', srcPltt2 側の端で止まっている長さ
  u32 cmdCount;                  // 0x664, cmds に積まれた件数, 最大8
  u16 cmds[8];                   // 0x668, BG パレットコマンドの番号, 1 クロスフェード, 2/4 フェードイン, 3/5 フェードアウト (4/5 は終わるまでほかのコマンドを受け付けない), 6 1色で塗る
  u16 cmdArgs[8][8];             // 0x678, コマンド1件につき引数8個, フェードなら [0] 長さの log2, [1..3] フェード色の R/G/B, [4] フェードするパレット行のマスク
} BgPlttController;
static_assert(sizeof(BgPlttController) == 1784);

extern s32 gBgBrightnessApplied;

COMMON_DATA u16 gMapInitScriptID = 0;                    // 0x03002B28, 魔物図鑑や太陽鍛冶にも専用のIDがある(スタートメニューはない)ので、SceneIDとかの方が意味は近いかも？
COMMON_DATA BgPlttController* gBgPlttController = NULL;  // 0x03002B2C

void BgPlttController_ClearPtr(void) { gBgPlttController = NULL; }

// src1 と src2 を (0x20-scale):scale の比で [start, end) の範囲だけ混ぜて dst に書く, scale は level/2, 0x20 以上なら src2 をそのままコピーする
NON_MATCH void BlendPltt2(rgb555* dst, const rgb555* src1, const rgb555* src2, u32 level, u32 start, u32 end) {
#ifdef NONMATCHING_C
  const rgb555* s1;
  const rgb555* s2;
  rgb555* d;
  u32 scale;
  u32 inv;
  s32 count;
  u32 rb;
  u32 g;

  scale = level >> 1;
  inv = 0x20 - scale;
  count = end - start;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src2 + start, dst + start, count * 2);
    } else {
      s1 = src1 + start;
      s2 = src2 + start;
      d = dst + start;
      while (count > 0) {
        rb = ((*s2 & 0x7C1F) * scale + (*s1 & 0x7C1F) * inv) & 0xF83E0;
        g = ((*s2 & 0x3E0) * scale + (*s1 & 0x3E0) * inv) & 0x7C00;
        *d = (rb | g) >> 5;
        s1++;
        s2++;
        d++;
        count--;
      }
    }
  }
#else
  INCFUNC("asm/func/BlendPltt2.inc");
#endif
}

// src を level/2 倍(5bit精度)して dst に書く, 等倍以上ならそのままコピーする
NON_MATCH void ScalePltt(rgb555* dst, rgb555* src, u32 level, u32 start, u32 end) {
#ifdef NONMATCHING_C
  const rgb555* s;
  rgb555* d;
  u32 scale;
  s32 count;
  u32 rb;
  u32 g;

  scale = level >> 1;
  count = end - start;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src + start, dst + start, count * 2);
    } else {
      s = src + start;
      d = dst + start;
      while (count != 0) {
        rb = (*s & 0x7C1F) * scale & 0xF83E0;
        g = (*s & 0x3E0) * scale & 0x7C00;
        *d = (rb | g) >> 5;
        s++;
        d++;
        count--;
      }
    }
  }
#else
  INCFUNC("asm/func/ScalePltt.inc");
#endif
}

// 雨のときに寄せる暗いパレットを夜のパレットから作る
void BgPlttController_BuildWeather(BgPlttController* p) {
  FileID id = p->bgpIDs[2];
  ScalePltt(p->plttWeather, GetBgPlttFile(id)->body, 50, 0, 208);
}

// 画面の BG パレットを1色で塗る (コマンド6)
void BgPlttController_Fill(BgPlttController* p, u32 rgb555val) {
  s32 i;

  rgb555* dst = p->dstPltt;
  for (i = 0; i < 208; i++) {
    *dst = rgb555val;
    dst++;
  }
  p->plttUpdated = 1;
}

// できあがったパレットを画面の BG パレットへ書く
void BgPlttController_Commit(BgPlttController* p) {
  const rgb555* src = (p->flags & BGPLTTCTRL_TIMEOFDAY) ? p->curPltt : p->srcPltt1;
  CpuCopy32(src, p->dstPltt, 208 * sizeof(rgb555));
  p->plttUpdated = 1;
}

// 雨で暗くする上限, 昼 (朝を含む) は半分の 0x20, 夕方と夜は 0x40
s32 BgPlttController_GetTargetLevel(void* _) {
  if (gClock.spanOfTime == TIME_MORNING || gClock.spanOfTime == TIME_DAYTIME) {
    return 0x20;
  }
  return 0x40;
}

// 晴れ, 暗さなし
void BgPlttController_LevelReset(BgPlttController* p) { p->weatherLevel = 0; }

// 降り始め, 4ずつ暗くして上限に達したら降っている状態へ
void BgPlttController_LevelIncrease(BgPlttController* p) {
  if (p->weatherLevel < BgPlttController_GetTargetLevel(p)) {
    p->weatherLevel += 4;
  } else {
    p->weatherLevel = BgPlttController_GetTargetLevel(p);
    p->weatherState = 2;
  }
}

// 降っている間, 暗さを時間帯に合った上限へ1フレーム最大8ずつ寄せる (時間帯が変わっても追いつく)
void BgPlttController_LevelApproach(BgPlttController* p) {
  s32 target = BgPlttController_GetTargetLevel(p);
  u8 cur = p->weatherLevel;
  s32 diff = abs(cur - target);
  if (cur < BgPlttController_GetTargetLevel(p)) {
    s32 step = diff;
    if (step > 8) {
      step = 8;
    }
    p->weatherLevel += step;
  } else {
    cur = p->weatherLevel;
    if (cur > BgPlttController_GetTargetLevel(p)) {
      s32 step = diff;
      if (step > 8) {
        step = 8;
      }
      p->weatherLevel -= step;
    } else {
      p->weatherLevel = BgPlttController_GetTargetLevel(p);
    }
  }
}

// 止み際, 2ずつ明るくして暗さがなくなったら晴れへ
void BgPlttController_LevelDecrease(BgPlttController* p) {
  if (p->weatherLevel > 1) {
    p->weatherLevel -= 2;
  } else {
    p->weatherLevel = 0;
    p->weatherState = 0;
  }
}

// 時間帯と雨の暗さを今の値で混ぜ直して画面へ書く, パレットを差し替えたとき用
void BgPlttController_Rebuild(BgPlttController* p) {
  rgb555* dst = p->plttTimeBlend;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->timeBlendLevel, 0, 208);
  CpuCopy32(dst, p->dstPltt, 208 * sizeof(rgb555));
  BgPlttController_BuildWeather(p);
  BlendPltt2(p->plttWeatherBlend, dst, p->plttWeather, p->weatherLevel, 0, 208);
  p->curPltt = dst;
  p->plttUpdated = 1;
}

// 時間帯の移り変わりを1フレーム進める
void BgPlttController_StepBlend(BgPlttController* p) {
  u32 zero;
  u32 count;

  rgb555* dst = p->plttTimeBlend;
  p->curPltt = dst;
  zero = 0;
  count = 208;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->timeBlendLevel, zero, count);
  if (++p->timeBlendLevel >= 0x40) {
    p->timeBlendLevel = 0x40;
  }
}

static void (*const sBgPlttControllerWeatherSteps[4])(BgPlttController*) = {
    BgPlttController_LevelReset,
    BgPlttController_LevelIncrease,
    BgPlttController_LevelApproach,
    BgPlttController_LevelDecrease,
};  // 0x085aa624

bool32 RainManager_IsActive(void);

// 天気が有効なマップで雨による暗さを1フレーム進め, 暗さが変わったときだけ暗いパレットを混ぜ直す
NON_MATCH void BgPlttController_UpdateWeather(BgPlttController* p) {
#ifdef NONMATCHING_C
  u16* flag;
  u32 zero;
  u32 count;

  if (RainManager_IsActive()) {
    flag = &p->unk_64a;
    if (*flag == 0) {
      sBgPlttControllerWeatherSteps[p->weatherState](p);
    }
    if (p->weatherLevel != p->prevWeatherLevel || p->timeBlendLevel <= 0x3F) {
      zero = 0;
      count = 0xD0;
      BlendPltt2(p->plttWeatherBlend, p->plttTimeBlend, p->plttWeather, p->weatherLevel, zero, count);
      *flag = 0;
    }
    if (p->weatherLevel != 0) {
      p->curPltt = p->plttWeatherBlend;
    }
    p->prevWeatherLevel = p->weatherLevel;
  }
#else
  INCFUNC("asm/func/BgPlttController_UpdateWeather.inc");
#endif
}

// 往復の今の位置で2枚を混ぜる, oscRowMask の行だけを数行ずつ
NON_MATCH void BgPlttController_BlendRows(BgPlttController* p) {
#ifdef NONMATCHING_C
  const rgb555* s1;
  const rgb555* s2;
  rgb555* d;
  s32 scale;
  s32 inv;
  s32 i;
  s32 end;
  s32 j;
  u32 rb;
  u32 g;

  scale = (s16)p->oscLevel >> 1;
  end = p->oscRow + p->oscRowStep;
  if (end > 0xC) {
    p->oscActive = 0;
    end = 0xD;
  }
  if (scale > 0x1F) {
    for (i = p->oscRow; i < end; i++) {
      if ((p->oscRowMask >> i) & 1) {
        CpuCopy32(p->srcPltt2 + i * 16, p->dstPltt + i * 16, 32);
      }
    }
  } else {
    inv = 0x20 - scale;
    for (i = p->oscRow; i < end; i++) {
      if ((p->oscRowMask >> i) & 1) {
        d = p->dstPltt + i * 16;
        s1 = p->srcPltt1 + i * 16;
        s2 = p->srcPltt2 + i * 16;
        for (j = 0; j < 16; j++) {
          rb = ((*s2 & 0x7C1F) * scale + (*s1 & 0x7C1F) * inv) & 0xF83E0;
          g = ((*s2 & 0x3E0) * scale + (*s1 & 0x3E0) * inv) & 0x7C00;
          *d = (rb | g) >> 5;
          s1++;
          s2++;
          d++;
        }
      }
    }
  }
  p->oscRow = end;
  p->plttUpdated = 1;
#else
  INCFUNC("asm/func/BgPlttController_BlendRows.inc");
#endif
}

// 別のパレットへのクロスフェード (コマンド1) を1フレーム進める, 数行ずつ混ぜて全行を混ぜたら1段階進め, 乗り換えたら終わる
void BgPlttController_StepCrossfade(BgPlttController* p) {
  const rgb555* src;
  u32 step;
  u32 rest;

  step = p->crossfadeRow << 4;
  if (p->flags & BGPLTTCTRL_TIMEOFDAY) {
    src = p->curPltt + (p->crossfadeRow << 4);
  } else {
    src = p->srcPltt1 + (p->crossfadeRow << 4);
  }
  if (p->crossfadeRow + p->crossfadeRowStep <= 0xD) {
    rest = p->crossfadeRowStep << 4;
  } else {
    rest = (0xD - p->crossfadeRow) << 4;
  }
  BlendPltt2(p->dstPltt, src, p->srcPltt2, (s8)p->crossfadeLevel, step, rest);
  p->crossfadeRow += p->crossfadeRowStep;
  if (p->crossfadeRow > 0xC) {
    p->crossfadeRow = 0;
    p->crossfadeLevel += p->crossfadeLevelStep;
    if ((s8)p->crossfadeLevel > 0x40) {
      p->crossfadeLevel = 0;
      p->srcPltt1 = p->srcPltt2;
      p->state = 0;
    }
  }
  p->plttUpdated = 1;
}

// 画面のフェードアウト, BG をフェード色へ寄せていく, コマンド5で始めたものは終わったあとも暗いまま止める
void BgPlttController_FadeOut(BgPlttController* p) {
  gBgBrightness = 0x40 - ((p->fadeTimer << 6) >> p->fadeShift);
  if ((p->fadeTimer = p->fadeTimer + 1) >= (1 << p->fadeShift)) {
    gBgBrightness = 0;
    if (p->state == 3) {
      p->state = 0;
    } else {
      p->state = 6;
    }
  }
}

// 画面のフェードイン, フェード色から元のパレットへ戻していく
void BgPlttController_FadeIn(BgPlttController* p) {
  rgb555* pltt;

  gBgBrightness = (p->fadeTimer << 6) >> p->fadeShift;
  if ((p->fadeTimer = p->fadeTimer + 1) >= (1 << p->fadeShift)) {
    pltt = GetBgPlttBlendBuffer();
    gBgBrightness = 0x40;
    gBgPlttBlendColor = RGB(4, 4, 4);
    *pltt = RGB(4, 4, 4);
    p->state = 0;
  }
}

s32 GetTimeOfDayPlttPair(u16* from, u16* to);

// パレットを差し替える, kw_f の bit0 が立っていればすぐ画面に反映し, 時間帯連動なら今の時間帯のパレットを読み直す
NON_MATCH void BgPlttController_SetFile(s32 idx, FileID plttFileID, u32 kw_f) {
#ifdef NONMATCHING_C
  BgPlttController* p = gBgPlttController;
  if (p != NULL) {
    p->bgpIDs[idx] = plttFileID;
    if (kw_f & 1) {
      if (p->flags & BGPLTTCTRL_TIMEOFDAY) {
        u16 id0, id1;
        GetTimeOfDayPlttPair(&id0, &id1);
        p->srcPltt1 = GetBgPlttFile(p->bgpIDs[id0])->body;
        p->srcPltt2 = GetBgPlttFile(p->bgpIDs[id1])->body;
        if (id0 == 2 || id1 == 2) {
          BgPlttController_BuildWeather(p);
        }
        BgPlttController_Rebuild(p);
        p->crossfadeRow = 0;
        p->crossfadeLevel = 64;
      } else {
        p->srcPltt1 = GetBgPlttFile(p->bgpIDs[idx])->body;
        CpuCopy32(p->srcPltt1, p->dstPltt, 416);
        p->crossfadeRow = 0;
        p->crossfadeLevel = 0;
      }
      p->crossfadeLevelStep = 7;
      p->crossfadeRowStep = 4;
    }
    p->plttUpdated = 1;
  }
#else
  INCFUNC("asm/func/BgPlttController_SetFile.inc");
#endif
}

// 0xCA7D, HashName("BGパレット変更")
void Cmd_SetBgPlttFile(void) {
  if (gBgPlttController != NULL) {
    s32 kw_i = VM_GetNamedArgValue('i', 0);
    FileID plttFileID = VM_GetNamedArgValue('n', 0);
    u32 kw_f = VM_GetNamedArgValue('f', 0);
    BgPlttController_SetFile(kw_i, plttFileID, kw_f);
  }
}

// BG パレットコマンドを1件積む, 次の _Update で処理される, 8件たまっていたら捨てる
void BgPlttController_PushCommand(s32 val, s32 count, u32* args) {
  BgPlttController* p = gBgPlttController;

  if (p != NULL && p->cmdCount <= 7) {
    s32 i;

    p->cmds[p->cmdCount] = val;
    for (i = 0; i < count; i++) {
      p->cmdArgs[p->cmdCount][i] = args[i];
    }
    p->cmdCount++;
  }
}

// 0x62BC, HashName("BGパレットコマンド")
void Cmd_SendBgPlttCommand(void) {
  u32 args[8];

  s32 kw_r = VM_GetNamedArgValue('r', 0);
  s32 count = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL && count < 8) {
      args[count] = VM_GetValue();
      count++;
    }
  }
  BgPlttController_PushCommand(kw_r, count, args);
}

static void (*const sBgPlttControllerStates[7])(BgPlttController*) = {
    NULL,
    BgPlttController_StepCrossfade,
    BgPlttController_FadeIn,
    BgPlttController_FadeOut,
    BgPlttController_FadeIn,
    BgPlttController_FadeOut,
    NULL,
};  // 0x085aa634

// 積まれた BG パレットコマンドを処理し, 時間帯の移り変わり・雨の暗さ・往復・フェードを1フレーム進める
NON_MATCH s32 BgPlttController_Update(BgPlttController* p) {
#ifdef NONMATCHING_C
  void (*fn)(BgPlttController*);
  u16* args;
  u16 cmd;
  s32 i;
  u16 id0;
  u16 id1;

  p->plttUpdated = 0;
  for (i = 0; i < p->cmdCount; i++) {
    cmd = p->cmds[i];
    args = p->cmdArgs[i];
    p->cmds[i] = 0;
    if (p->state > 3) {
      if (cmd == 4 || cmd == 5) {
        p->state = cmd;
        p->fadeTimer = 0;
        p->fadeShift = args[0];
        gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
        gBgPlttFadeRowMask = args[4];
      }
    } else {
      switch (cmd) {
        case 1: {
          p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[(s16)args[0]])->body;
          p->state = 1;
          p->crossfadeRow = 0;
          p->crossfadeLevel = args[1];
          p->crossfadeLevelStep = args[2];
          p->crossfadeRowStep = args[3];
          break;
        }
        case 2:
        case 4: {
          if (cmd == 2) {
            p->state = 2;
          } else {
            p->state = 4;
          }
          p->fadeTimer = 0;
          p->fadeShift = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 3:
        case 5: {
          if (cmd == 3) {
            p->state = 3;
          } else {
            p->state = 5;
          }
          p->fadeTimer = 0;
          p->fadeShift = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 6: {
          BgPlttController_Fill(p, (s16)args[0] | ((s16)args[1] << 5) | ((s16)args[2] << 10));
          break;
        }
      }
    }
  }
  p->cmdCount = 0;
  if (p->flags & BGPLTTCTRL_TIMEOFDAY) {
    if (p->spanOfTime != gClock.spanOfTime) {
      GetTimeOfDayPlttPair(&id0, &id1);
      p->timeBlendLevel = 0;
      p->unk_648 = 0;
      p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
      p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    }
    p->spanOfTime = gClock.spanOfTime;
    p->twilightLevel = gClock.twilightLevel;
    p->curPltt = p->plttTimeBlend;
    if (p->timeBlendLevel <= 0x3F) {
      BgPlttController_StepBlend(p);
    }
    BgPlttController_UpdateWeather(p);
    BgPlttController_Commit(p);
    p->prevTimeBlendLevel = p->timeBlendLevel;
  } else if (p->flags & BGPLTTCTRL_OSCILLATE) {
    if (p->oscWait == 0) {
      if (++p->oscTimer >= p->oscPeriod) {
        p->oscTimer = 0;
        p->oscLevel += p->oscStep;
        if ((s16)p->oscLevel <= 0) {
          p->oscLevel = 0;
          p->oscStep = -p->oscStep;
          p->oscWait = p->oscStep;
        } else if ((s16)p->oscLevel > 0x3F) {
          p->oscLevel = 0x40;
          p->oscStep = -p->oscStep;
          p->oscWait = p->oscWaitLength;
        }
        p->oscActive = 1;
        p->oscRow = 0;
      }
    } else {
      p->oscWait--;
    }
    if (p->oscActive != 0) {
      BgPlttController_BlendRows(p);
    }
  }
  fn = sBgPlttControllerStates[p->state];
  if (fn != NULL) {
    fn(p);
  }
#else
  INCFUNC("asm/func/BgPlttController_Update.inc");
#endif
}

s32 BgPlttController_Destroy(BgPlttController* p) { gBgPlttController = NULL; }

// '.f' で動きを選ぶ, 時間帯連動 (屋外), 2枚の往復, 1枚をそのまま出す (屋内など)
NON_MATCH s32 BgPlttController_Init(BgPlttController* p, u16 id) {
#ifdef NONMATCHING_C
  const rgb555* src;
  u16 id0;
  u16 id1;
  s32 i;

  gBgPlttController = p;
  p->id = id;
  p->dstPltt = gBgPlttBuffer;
  gBgBrightness = 0x40;
  gBgBrightnessApplied = 0x40;
  gBgPlttBlendColor = RGB(4, 4, 4);
  gBgPlttFadeRowMask = 0;
  p->flags = VM_GetNamedArgValue('f', 0);
  p->crossfadeRow = 0;
  p->unk_648 = 0;
  p->state = 0;
  p->crossfadeLevelStep = 7;
  p->crossfadeRowStep = 4;
  i = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL && i <= 3) {
      p->bgpIDs[i] = VM_GetValue();
      i++;
    }
  }
  p->fadeTimer = 0;
  p->fadeShift = 0;
  p->crossfadeLevel = 0;
  p->twilightLevel = 0;
  p->timeBlendLevel = 0;
  if (p->flags & BGPLTTCTRL_TIMEOFDAY) {
    GetTimeOfDayPlttPair(&id0, &id1);
    p->timeBlendLevel = 0x40;
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    BgPlttController_Rebuild(p);
    p->twilightLevel = gClock.twilightLevel;
    p->spanOfTime = gClock.spanOfTime;
    src = p->plttWeatherBlend;
  } else if (p->flags & BGPLTTCTRL_OSCILLATE) {
    id0 = VM_GetNamedArgValue('c', 0);
    id1 = VM_GetNamedArgValue('m', 0);
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    if (VM_SeekToNamedArg('a')) {
      p->unk_652 = VM_GetValue();
      p->oscPeriod = VM_GetValue();
      p->oscRowStep = VM_GetValue();
      p->oscRowMask = VM_GetValue();
      p->oscStep = VM_GetValue();
      p->oscWaitLength = VM_GetValue();
    } else {
      p->unk_652 = 4;
      p->oscPeriod = 2;
      p->oscRowStep = 8;
      p->oscRowMask = 0xFFFF;
      p->oscStep = 0x20;
      p->oscWaitLength = 0;
    }
    p->oscTimer = 0;
    p->oscLevel = 0;
    p->oscRow = 0;
    p->oscActive = 0;
    src = p->srcPltt1;
  } else {
    id0 = VM_GetNamedArgValue('c', 0);
    id1 = VM_GetNamedArgValue('m', 0);
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    src = p->srcPltt1;
  }
  CpuCopy32(src, p->dstPltt, 208 * sizeof(rgb555));
  p->weatherState = 0;
  p->plttUpdated = 1;
  return 0;
#else
  INCFUNC("asm/func/BgPlttController_Init.inc");
#endif
}

// 0x4AE5, HashName("背景パレットキャラ")
BgPlttController* BgPlttController_Create(u32 id) {
  if (gBgPlttController == NULL) {
    BgPlttController* p = CreateEntity(ENTITY_UNK_11, sizeof(BgPlttController));
    if (p != NULL) {
      SetEntityRoutine(p, BgPlttController_Update, BgPlttController_Destroy);
      if (BgPlttController_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gBgPlttController;
}

// 天気の変化を伝える, RainManager が雨の降り始め・本降り・止み際・晴れで呼ぶ
void BgPlttController_SetWeatherState(u32 val) {
  if (gBgPlttController != NULL) {
    gBgPlttController->weatherState = val;
  }
}

// このフレームに BG パレットを書き直したか, パレットに上乗せする演出 (bgp_blend.c など) はこれを見て掛け直す
s32 BgPlttController_IsPlttUpdated(void) {
  if (gBgPlttController == NULL) {
    return 0;
  }
  return gBgPlttController->plttUpdated;
}
