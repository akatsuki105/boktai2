#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// マップ切り替え時に毎回生成される(時間帯によるマップのパレット処理と思われる)
typedef struct {
  Entity e;                   // ENTITY_UNK_11
  u16 unk_18;                 // 0x18, 0xE231, 0x317B, 0xF68D, 0xA58E, 0x4AE5 などがあるが、意味は不明
  u8 unk_1a;                  // 0x1A, なんかのbitfield
  u8 unk_1b;                  // 0x1B, PTR_ARRAY_085aa634 の idx
  u8 bytesize_1c;             // 0x1C, 0x08001e62
  u8 unk_1d;                  // 0x1D
  u8 unk_1e;                  // 0x1E
  u8 unk_1f;                  // 0x1F
  u8 unk_20;                  // 0x20
  u8 unk_21[0x24 - 0x21];     // 0x21
  const rgb555* srcPltt1;     // 0x24, PLTTファイルのRGB555データその1
  const rgb555* srcPltt2;     // 0x28, PLTTファイルのRGB555データその2
  rgb555* dstPltt;            // 0x2C, gBgPlttBuffer
  rgb555* pltt_30;            // 0x030
  rgb555 pltt_34[256];        // 0x034
  rgb555 pltt_234[256];       // 0x234
  rgb555 pltt_434[256];       // 0x434
  FileID plttFileIDs[3];      // 0x634
  u8 unk_63a[0x63c - 0x63a];  // 0x63A
  u16 unk_63c;                // 0x63C
  u16 unk_63e;                // 0x63E
  u8 bytesize_640;            // 0x640, 0x08001bf0
  u8 bytesize_641;            // 0x641, 0x080022da
  u8 bytesize_642;            // 0x642, 0x08001c76
  u8 bytesize_643;            // 0x643, 0x08001c96
  u8 unk_644;                 // 0x644, PTR_ARRAY_085aa624 の idx
  u16 unk_648;                // 0x648, 0x08002276
  u16 unk_64a;                // 0x64A
  u16 spanOfTime;             // 0x64C
  u16 unk_64e;                // 0x64E, gClock.unk_0f
  u16 unk_650;                // 0x650, Entity4AE5_Update のフレームカウンタ, unk_656 に達すると混合を進める
  u16 unk_652;                // 0x652, script keyword 0x61 の1番目 (既定 4)
  u16 unk_654;                // 0x654, MapPltt_BlendRows が s16 として読み >>1 して混合比に使う
  u16 unk_656;                // 0x656, script keyword 0x61 の2番目 (既定 2), unk_650 の上限
  u8 unk_658;                 // 0x658, MapPltt_BlendRows の開始インデックス
  u8 unk_659;                 // 0x659, script keyword 0x61 の3番目 (既定 8), MapPltt_BlendRows の加算数
  u8 unk_65a;                 // 0x65A, 0 以外なら Entity4AE5_Update が MapPltt_BlendRows を呼ぶ
  u8 unk_65b;                 // 0x65B
  u16 unk_65c;                // 0x65C, script keyword 0x61 の4番目 (既定 0xFFFF), MapPltt_BlendRows のビットマスク
  u16 unk_65e;                // 0x65E, 混合を止めている間のカウントダウン
  u16 unk_660;                // 0x660, script keyword 0x61 の5番目 (既定 0x20), unk_654 の増分
  u16 unk_662;                // 0x662, script keyword 0x61 の6番目 (既定 0), 折り返し時の待ち時間
  s32 unk_664;                // 0x664, MapPltt_PushCommand
  u16 unk_668[64];            // 0x668, MapPltt_PushCommand
  u8 unk_6e8[16];             // 0x6E8
} Entity4AE5;
static_assert(sizeof(Entity4AE5) == 1784);

extern s32 s32_03004048;
extern u16 gBgPlttFadeRowMask;

COMMON_DATA u16 gMapInitScriptID = 0;        // 0x03002B28
COMMON_DATA Entity4AE5* gEntity4AE5 = NULL;  // 0x03002B2C

void FUN_08001878(void) { gEntity4AE5 = NULL; }

// src1 と src2 を (0x20-scale):scale の比で混ぜて dst に書く。scale が 0x20 以上なら src2 をそのままコピーする
NON_MATCH void BlendPltt2(rgb555* dst, const rgb555* src1, const rgb555* src2, u32 bytesize, u32 param_5, u32 param_6) {
#ifdef NONMATCHING_C
  const rgb555* s1;
  const rgb555* s2;
  rgb555* d;
  u32 scale;
  u32 inv;
  s32 count;
  u32 rb;
  u32 g;

  scale = bytesize >> 1;
  inv = 0x20 - scale;
  count = param_6 - param_5;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src2 + param_5, dst + param_5, count * 2);
    } else {
      s1 = src1 + param_5;
      s2 = src2 + param_5;
      d = dst + param_5;
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

// src を bytesize/2 倍(5bit精度)して dst に書く。等倍以上ならそのままコピーする
NON_MATCH void ScalePltt(rgb555* dst, rgb555* src, u32 bytesize, u32 param_4, u32 param_5) {
#ifdef NONMATCHING_C
  const rgb555* s;
  rgb555* d;
  u32 scale;
  s32 count;
  u32 rb;
  u32 g;

  scale = bytesize >> 1;
  count = param_5 - param_4;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src + param_4, dst + param_4, count * 2);
    } else {
      s = src + param_4;
      d = dst + param_4;
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

void FUN_080019dc(Entity4AE5* p) {
  FileID id = p->plttFileIDs[2];
  rgb555* src = GetBgPlttFile(id)->body;
  ScalePltt(p->pltt_434, src, 50, 0, 208);
}

void MapPltt_Fill(Entity4AE5* p, u32 rgb555val) {
  rgb555* dst;
  s32 i;

  dst = p->dstPltt;
  for (i = 0xCF; i >= 0; i--) {
    *dst = rgb555val;
    dst++;
  }
  p->unk_20 = 1;
}

void MapPltt_Commit(Entity4AE5* p) {
  const rgb555* src;

  if (p->unk_1a & 1) {
    src = p->pltt_30;
  } else {
    src = p->srcPltt1;
  }
  CpuCopy32(src, p->dstPltt, 416);
  p->unk_20 = 1;
}

// 朝と夕方は 0x20、それ以外は 0x40 を返す
s32 MapPltt_GetTargetLevel(void* _) {
  if ((u8)(gClock.spanOfTime - 1) <= 1) {
    return 0x20;
  }
  return 0x40;
}

void MapPltt_LevelReset(Entity4AE5* p) { p->bytesize_642 = 0; }

void MapPltt_LevelIncrease(Entity4AE5* p) {
  u8 v;

  v = p->bytesize_642;
  if (v < MapPltt_GetTargetLevel(p)) {
    p->bytesize_642 += 4;
  } else {
    p->bytesize_642 = MapPltt_GetTargetLevel(p);
    p->unk_644 = 2;
  }
}

// 目標値へ1回あたり最大8ずつ近づける
void MapPltt_LevelApproach(Entity4AE5* p) {
  u8 cur;
  s32 target;
  s32 diff;
  s32 step;

  target = MapPltt_GetTargetLevel(p);
  cur = p->bytesize_642;
  diff = cur - target;
  if (diff < 0) {
    diff = -diff;
  }
  if (cur < MapPltt_GetTargetLevel(p)) {
    step = diff;
    if (step > 8) {
      step = 8;
    }
    p->bytesize_642 += step;
  } else {
    cur = p->bytesize_642;
    if (cur > MapPltt_GetTargetLevel(p)) {
      step = diff;
      if (step > 8) {
        step = 8;
      }
      p->bytesize_642 -= step;
    } else {
      p->bytesize_642 = MapPltt_GetTargetLevel(p);
    }
  }
}

void MapPltt_LevelDecrease(Entity4AE5* p) {
  if (p->bytesize_642 > 1) {
    p->bytesize_642 -= 2;
  } else {
    p->bytesize_642 = 0;
    p->unk_644 = 0;
  }
}

void MapPltt_Rebuild(Entity4AE5* p) {
  rgb555* dst;

  dst = p->pltt_34;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->bytesize_640, 0, 0xD0);
  CpuCopy32(dst, p->dstPltt, 416);
  FUN_080019dc(p);
  BlendPltt2(p->pltt_234, dst, p->pltt_434, p->bytesize_642, 0, 0xD0);
  p->pltt_30 = dst;
  p->unk_20 = 1;
}

void MapPltt_StepBlend(Entity4AE5* p) {
  rgb555* dst;
  u32 zero;
  u32 count;

  dst = p->pltt_34;
  p->pltt_30 = dst;
  zero = 0;
  count = 0xD0;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->bytesize_640, zero, count);
  if (++p->bytesize_640 > 0x3F) {
    p->bytesize_640 = 0x40;
  }
}

void (*const PTR_ARRAY_085aa624[4])(Entity4AE5*) = {
    MapPltt_LevelReset,
    MapPltt_LevelIncrease,
    MapPltt_LevelApproach,
    MapPltt_LevelDecrease,
};  // 0x085aa624

bool32 WeatherManager_IsActive(void);

NON_MATCH void FUN_08001c10(Entity4AE5* p) {
#ifdef NONMATCHING_C
  u16* flag;
  u32 zero;
  u32 count;

  if (WeatherManager_IsActive()) {
    flag = &p->unk_64a;
    if (*flag == 0) {
      PTR_ARRAY_085aa624[p->unk_644](p);
    }
    if (p->bytesize_642 != p->bytesize_643 || p->bytesize_640 <= 0x3F) {
      zero = 0;
      count = 0xD0;
      BlendPltt2(p->pltt_234, p->pltt_34, p->pltt_434, p->bytesize_642, zero, count);
      *flag = 0;
    }
    if (p->bytesize_642 != 0) {
      p->pltt_30 = p->pltt_234;
    }
    p->bytesize_643 = p->bytesize_642;
  }
#else
  INCFUNC("asm/func/FUN_08001c10.inc");
#endif
}

// unk_65c で指定されたパレット行だけを、混合比に応じて転送または合成する
NON_MATCH void MapPltt_BlendRows(Entity4AE5* p) {
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

  scale = (s16)p->unk_654 >> 1;
  end = p->unk_658 + p->unk_659;
  if (end > 0xC) {
    p->unk_65a = 0;
    end = 0xD;
  }
  if (scale > 0x1F) {
    for (i = p->unk_658; i < end; i++) {
      if ((p->unk_65c >> i) & 1) {
        CpuCopy32(p->srcPltt2 + i * 16, p->dstPltt + i * 16, 32);
      }
    }
  } else {
    inv = 0x20 - scale;
    for (i = p->unk_658; i < end; i++) {
      if ((p->unk_65c >> i) & 1) {
        d = p->dstPltt + i * 16;
        s1 = p->srcPltt1 + i * 16;
        s2 = p->srcPltt2 + i * 16;
        for (j = 0xF; j >= 0; j--) {
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
  p->unk_658 = end;
  p->unk_20 = 1;
#else
  INCFUNC("asm/func/MapPltt_BlendRows.inc");
#endif
}

// パレットを 13 段階ずつ送りながら合成する。1周したら送り元を切り替えて終了する
void MapPltt_StepCrossfade(Entity4AE5* p) {
  const rgb555* src;
  u32 step;
  u32 rest;

  step = p->unk_1d << 4;
  if (p->unk_1a & 1) {
    src = p->pltt_30 + (p->unk_1d << 4);
  } else {
    src = p->srcPltt1 + (p->unk_1d << 4);
  }
  if (p->unk_1d + p->unk_1f <= 0xD) {
    rest = p->unk_1f << 4;
  } else {
    rest = (0xD - p->unk_1d) << 4;
  }
  BlendPltt2(p->dstPltt, src, p->srcPltt2, (s8)p->bytesize_1c, step, rest);
  p->unk_1d += p->unk_1f;
  if (p->unk_1d > 0xC) {
    p->unk_1d = 0;
    p->bytesize_1c += p->unk_1e;
    if ((s8)p->bytesize_1c > 0x40) {
      p->bytesize_1c = 0;
      p->srcPltt1 = p->srcPltt2;
      p->unk_1b = 0;
    }
  }
  p->unk_20 = 1;
}

extern s32 s32_03004040;

// 暗→明のフェード: 進捗に応じて明るさを 0 に近づけ、終わったら次の処理へ移る
void MapPltt_FadeIn(Entity4AE5* p) {
  s32_03004040 = 0x40 - ((p->unk_63c << 6) >> p->unk_63e);
  if ((p->unk_63c = p->unk_63c + 1) >= (1 << p->unk_63e)) {
    s32_03004040 = 0;
    if (p->unk_1b == 3) {
      p->unk_1b = 0;
    } else {
      p->unk_1b = 6;
    }
  }
}

// 明→暗のフェード: 進捗に応じて明るさを 0x40 に近づけ、終わったら暗転状態で止める
void MapPltt_FadeOut(Entity4AE5* p) {
  rgb555* pltt;

  s32_03004040 = (p->unk_63c << 6) >> p->unk_63e;
  if ((p->unk_63c = p->unk_63c + 1) >= (1 << p->unk_63e)) {
    pltt = FUN_0822d00c();
    s32_03004040 = 0x40;
    gBgPlttBlendColor = 0x1084;
    *pltt = 0x1084;
    p->unk_1b = 0;
  }
}

s32 FUN_0823ce10(u16* a, u16* b);

// スクリプトから指定されたPLTTファイルを登録し、時間帯に応じた2枚を読み直す
NON_MATCH void MapPltt_SetFile(s32 idx, FileID plttFileID, u32 kw_f) {
#ifdef NONMATCHING_C
  Entity4AE5* p = gEntity4AE5;
  if (p != NULL) {
    p->plttFileIDs[idx] = plttFileID;
    if (kw_f & 1) {
      if (p->unk_1a & 1) {
        u16 id0, id1;
        FUN_0823ce10(&id0, &id1);
        p->srcPltt1 = GetBgPlttFile(p->plttFileIDs[id0])->body;
        p->srcPltt2 = GetBgPlttFile(p->plttFileIDs[id1])->body;
        if (id0 == 2 || id1 == 2) {
          FUN_080019dc(p);
        }
        MapPltt_Rebuild(p);
        p->unk_1d = 0;
        p->bytesize_1c = 64;
      } else {
        p->srcPltt1 = GetBgPlttFile(p->plttFileIDs[idx])->body;
        CpuCopy32(p->srcPltt1, p->dstPltt, 416);
        p->unk_1d = 0;
        p->bytesize_1c = 0;
      }
      p->unk_1e = 7;
      p->unk_1f = 4;
    }
    p->unk_20 = 1;
  }
#else
  INCFUNC("asm/func/MapPltt_SetFile.inc");
#endif
}

void VM_SubCA7D(void) {
  if (gEntity4AE5 != NULL) {
    s32 kw_i = VM_GetKeywordValue('i', 0);
    FileID plttFileID = VM_GetKeywordValue('n', 0);
    u32 kw_f = VM_GetKeywordValue('f', 0);
    MapPltt_SetFile(kw_i, plttFileID, kw_f);
  }
}

NON_MATCH void MapPltt_PushCommand(s32 val, s32 count, u32* args) {
#ifdef NONMATCHING_C
  Entity4AE5* p;
  s32 i;
  u16* dst;

  p = gEntity4AE5;
  if (p != NULL) {
    if ((u32)p->unk_664 <= 7) {
      p->unk_668[p->unk_664] = val;
      dst = &p->unk_668[8];
      for (i = 0; i < count; i++) {
        dst[p->unk_664 * 8 + i] = *args++;
      }
      p->unk_664++;
    }
  }
#else
  INCFUNC("asm/func/MapPltt_PushCommand.inc");
#endif
}

void FUN_080020bc(void) {
  u32 args[8];

  s32 kw_r = VM_GetKeywordValue('r', 0);
  s32 count = 0;
  if (VM_SeekToKeyword('p')) {
    while (VM_GetPC() != NULL && count < 8) {
      args[count] = Script_GetValue();
      count++;
    }
  }
  MapPltt_PushCommand(kw_r, count, args);
}

// clang-format off
void (*const PTR_ARRAY_085aa634[7])(Entity4AE5*) = {
    (void*)NULL,
    MapPltt_StepCrossfade,
    MapPltt_FadeOut,
    MapPltt_FadeIn,
    MapPltt_FadeOut,
    MapPltt_FadeIn,
    (void*)NULL,
}; // 0x085aa634
// clang-format on

// unk_668 に積まれたコマンドを順に処理し、時間帯の変化やフェードの進行を反映する
NON_MATCH s32 Entity4AE5_Update(Entity4AE5* p) {
#ifdef NONMATCHING_C
  void (*fn)(Entity4AE5*);
  u16* args;
  u16 cmd;
  s32 i;
  u16 id0;
  u16 id1;

  p->unk_20 = 0;
  for (i = 0; i < p->unk_664; i++) {
    cmd = p->unk_668[i];
    args = &p->unk_668[8 + i * 8];
    p->unk_668[i] = 0;
    if (p->unk_1b > 3) {
      if (cmd == 4 || cmd == 5) {
        p->unk_1b = cmd;
        p->unk_63c = 0;
        p->unk_63e = args[0];
        gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
        gBgPlttFadeRowMask = args[4];
      }
    } else {
      switch (cmd) {
        case 1: {
          p->srcPltt2 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[(s16)args[0]]) + 0x14);
          p->unk_1b = 1;
          p->unk_1d = 0;
          p->bytesize_1c = args[1];
          p->unk_1e = args[2];
          p->unk_1f = args[3];
          break;
        }
        case 2:
        case 4: {
          if (cmd == 2) {
            p->unk_1b = 2;
          } else {
            p->unk_1b = 4;
          }
          p->unk_63c = 0;
          p->unk_63e = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 3:
        case 5: {
          if (cmd == 3) {
            p->unk_1b = 3;
          } else {
            p->unk_1b = 5;
          }
          p->unk_63c = 0;
          p->unk_63e = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 6: {
          MapPltt_Fill(p, (s16)args[0] | ((s16)args[1] << 5) | ((s16)args[2] << 10));
          break;
        }
      }
    }
  }
  p->unk_664 = 0;
  if (p->unk_1a & 1) {
    if (p->spanOfTime != gClock.spanOfTime) {
      FUN_0823ce10(&id0, &id1);
      p->bytesize_640 = 0;
      p->unk_648 = 0;
      p->srcPltt1 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id0]) + 0x14);
      p->srcPltt2 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id1]) + 0x14);
    }
    p->spanOfTime = gClock.spanOfTime;
    p->unk_64e = gClock.unk_0f;
    p->pltt_30 = p->pltt_34;
    if (p->bytesize_640 <= 0x3F) {
      MapPltt_StepBlend(p);
    }
    FUN_08001c10(p);
    MapPltt_Commit(p);
    p->bytesize_641 = p->bytesize_640;
  } else if (p->unk_1a & 2) {
    if (p->unk_65e == 0) {
      if (++p->unk_650 >= p->unk_656) {
        p->unk_650 = 0;
        p->unk_654 += p->unk_660;
        if ((s16)p->unk_654 <= 0) {
          p->unk_654 = 0;
          p->unk_660 = -p->unk_660;
          p->unk_65e = p->unk_660;
        } else if ((s16)p->unk_654 > 0x3F) {
          p->unk_654 = 0x40;
          p->unk_660 = -p->unk_660;
          p->unk_65e = p->unk_662;
        }
        p->unk_65a = 1;
        p->unk_658 = 0;
      }
    } else {
      p->unk_65e--;
    }
    if (p->unk_65a != 0) {
      MapPltt_BlendRows(p);
    }
  }
  fn = PTR_ARRAY_085aa634[p->unk_1b];
  if (fn != NULL) {
    fn(p);
  }
#else
  INCFUNC("asm/func/Entity4AE5_Update.inc");
#endif
}

s32 Entity4AE5_Destroy(Entity4AE5* p) { gEntity4AE5 = NULL; }

// パレット処理の初期化。unk_1a のビットで、時間帯連動・2枚合成・単純転送のどれかを選ぶ
NON_MATCH s32 Entity4AE5_Init(Entity4AE5* p, u16 val) {
#ifdef NONMATCHING_C
  const rgb555* src;
  u16 id0;
  u16 id1;
  s32 i;

  gEntity4AE5 = p;
  p->unk_18 = val;
  p->dstPltt = gBgPlttBuffer;
  s32_03004040 = 0x40;
  s32_03004048 = 0x40;
  gBgPlttBlendColor = 0x1084;
  gBgPlttFadeRowMask = 0;
  p->unk_1a = VM_GetKeywordValue('f', 0);
  p->unk_1d = 0;
  p->unk_648 = 0;
  p->unk_1b = 0;
  p->unk_1e = 7;
  p->unk_1f = 4;
  i = 0;
  if (VM_SeekToKeyword('p')) {
    while (VM_GetPC() != NULL && i <= 3) {
      p->plttFileIDs[i] = Script_GetValue();
      i++;
    }
  }
  p->unk_63c = 0;
  p->unk_63e = 0;
  p->bytesize_1c = 0;
  p->unk_64e = 0;
  p->bytesize_640 = 0;
  if (p->unk_1a & 1) {
    FUN_0823ce10(&id0, &id1);
    p->bytesize_640 = 0x40;
    p->srcPltt1 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id0]) + 0x14);
    p->srcPltt2 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id1]) + 0x14);
    MapPltt_Rebuild(p);
    p->unk_64e = gClock.unk_0f;
    p->spanOfTime = gClock.spanOfTime;
    src = p->pltt_234;
  } else if (p->unk_1a & 2) {
    id0 = VM_GetKeywordValue('c', 0);
    id1 = VM_GetKeywordValue('m', 0);
    p->srcPltt1 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id0]) + 0x14);
    p->srcPltt2 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id1]) + 0x14);
    if (VM_SeekToKeyword('a')) {
      p->unk_652 = Script_GetValue();
      p->unk_656 = Script_GetValue();
      p->unk_659 = Script_GetValue();
      p->unk_65c = Script_GetValue();
      p->unk_660 = Script_GetValue();
      p->unk_662 = Script_GetValue();
    } else {
      p->unk_652 = 4;
      p->unk_656 = 2;
      p->unk_659 = 8;
      p->unk_65c = 0xFFFF;
      p->unk_660 = 0x20;
      p->unk_662 = 0;
    }
    p->unk_650 = 0;
    p->unk_654 = 0;
    p->unk_658 = 0;
    p->unk_65a = 0;
    src = p->srcPltt1;
  } else {
    id0 = VM_GetKeywordValue('c', 0);
    id1 = VM_GetKeywordValue('m', 0);
    p->srcPltt1 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id0]) + 0x14);
    p->srcPltt2 = (const rgb555*)((u8*)GetFile(DIR_BGPLTT, p->plttFileIDs[id1]) + 0x14);
    src = p->srcPltt1;
  }
  CpuCopy32(src, p->dstPltt, 416);
  p->unk_644 = 0;
  p->unk_20 = 1;
  return 0;
#else
  INCFUNC("asm/func/Entity4AE5_Init.inc");
#endif
}

Entity4AE5* Entity4AE5_Create(u32 val) {
  if (gEntity4AE5 == NULL) {
    Entity4AE5* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity4AE5));
    if (p != NULL) {
      SetEntityRoutine(p, Entity4AE5_Update, Entity4AE5_Destroy);
      if (Entity4AE5_Init(p, val) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity4AE5;
}
