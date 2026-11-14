#include "camera_inline.h"
#include "eff_scatter.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "player.h"
#include "puff.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"
#include "vm.h"

struct OtenkoGuide;

// パレットの補間に使う色, 各チャンネルは 0..31
typedef struct Rgb8 {
  s8 r;
  s8 g;
  s8 b;
} Rgb8;

typedef u8 OtenkoPanelFlags;
#define OTENKOPANEL_FLAG_UNK_0 (1 << 0)
#define OTENKOPANEL_FLAG_UNK_1 (1 << 1)
#define OTENKOPANEL_FLAG_UNK_2 (1 << 2)

// 前作のおてんこパネル, 調べるとその場におてんこが出てきて話す, Cmd_PlaceOtenkoPanels でしか置かれず今作のスクリプトからは使われない (今作のヒントパネルは InteractPoint)
typedef struct OtenkoPanel {
  AuxSprite sprite;                                            // 0x00
  AuxSpriteGfx gfx;                                            // 0x2C, SPRITE_HINT_PANEL
  Vec3 pos;                                                    // 0x48, プレイヤーとの相対角度を求めるときの基点
  u8 unk_50[0xA0 - 0x50];                                      // 0x50, このモジュールのどの関数も読み書きしない
  u32 unk_a0;                                                  // 0xA0, '.C'
  u32 unk_a4;                                                  // 0xA4, '.a'
  void (*callback)(struct OtenkoGuide*, struct OtenkoPanel*);  // 0xA8, 代入のみで呼び出し箇所が見つかっていない
  u8 index;                                                    // 0xAC, elems 内の自分の添字
  OtenkoPanelFlags flags;                                      // 0xAD, see OTENKOPANEL_FLAG_*
  u8 unk_ae;                                                   // 0xAE, 0 かどうかでポーズと向きの符号を選ぶ
  bool8 stopSound;                                             // 0xAF, OtenkoGuide の同名フィールドへ写される
  u8 unk_b0;                                                   // 0xB0, 0 から 10 までを往復するカウンタ
  u8 unk_b1[3];                                                // 0xB1, まだ未解析
  s32 unk_b4;                                                  // 0xB4
  ZoneID32 zoneID;                                             // 0xB8, gStat->zoneID (エリアID) と比べる
  u8 unk_bc[0xCA - 0xBC];                                      // 0xBC, まだ未解析
  u8 unk_ca;                                                   // 0xCA
  u8 unk_cb;                                                   // 0xCB, 0 になるまで毎フレーム減るカウンタ
  u16 plttBase;                                                // 0xCC, gObjPlttData のパレット行の基準, +0/+1/+2 の行を使う
  u8 unk_ce[2];                                                // 0xCE, まだ未解析
  s32 unk_d0;                                                  // 0xD0
  u8 unk_d4;                                                   // 0xD4, 0 か 1 が入る, 読み手は見つかっていない
  u8 unk_d5[3];                                                // 0xD5, まだ未解析
} OtenkoPanel;
static_assert(sizeof(OtenkoPanel) == 216);

// 解説役のおてんこさま, 前作のおてんこパネル (panels) と今作のタイトルデモの太陽センサー解説 (SensorGuide と一緒に出る) の両方を受け持つ, 今作で使われるのはセンサー解説だけ
typedef struct OtenkoGuide {
  Entity e;                                     // 0x000, ENTITY_UNK_11
  Player* player;                               // 0x018, _Init が gPlayerPtr[0] を入れる
  OtenkoPanel elems[16];                        // 0x01C, _Init が16個ぶん Video_GetAuxSprite / AuxSprite_Add する
  AuxSprite sprite;                             // 0xD9C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx;                             // 0xDC8, SPRITE_OTENKO_00
  AuxAnimState anim;                            // 0xDE4
  ParticleShadow shadow;                        // 0xDF4, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
  AuxAnimFile* animFile;                        // 0xE34, ANIM_OTENKO
  u16 bobTimer;                                 // 0xE38, 上下に揺らす間隔を数える, 4 フレームごとに bobStep だけ動かす
  s8 bobStep;                                   // 0xE3A, 上下に揺らす1回ぶんの量, 画面座標なら ±1, マップ座標なら ±8
  u8 unk_e3b;                                   // 0xE3B, まだ未解析
  u16 unk_e3c;                                  // 0xE3C, _Init が 0 を入れる
  u8 unk_e3e[2];                                // 0xE3E, まだ未解析
  Mover unk_e40;                                // 0xE40, _Destroy が Mover_Unlink に渡す
  s16 moveDeltaX;                               // 0xE84, OtenkoGuide_UpdateMoveTo の移動量 x
  s16 moveDeltaY;                               // 0xE86, OtenkoGuide_UpdateMoveTo の移動量 y
  s16 unk_e88;                                  // 0xE88, _Init が書き込む
  u8 unk_e8a[2];                                // 0xE8A, まだ未解析
  s16 targetX;                                  // 0xE8C, 移動先 x, Cmd_MoveOtenkoGuideTo の '.t'
  s16 targetY;                                  // 0xE8E, 移動先 y
  s16 targetZ;                                  // 0xE90, 移動先 z
  u8 unk_e92[2];                                // 0xE92, まだ未解析
  Vec3 startPos;                                // 0xE94
  WorldPos pos;                                 // 0xE9C, unk_e40.pos へ写される, 既定はプレイヤーの座標
  rgb555 pltt0[16];                             // 0xEA4, _Init が gfx.pltt の 0x10..0x1F 番を写す
  rgb555 pltt1[16];                             // 0xEC4, _Init が gfx.pltt の 0x00..0x0F 番を写す
  rgb555 pltt2[16];                             // 0xEE4, pltt1 と pltt0 の補間結果, 差し替え中の gfx.pltt
  rgb555* plttSrc;                              // 0xF04, gfx.pltt の写し
  s16 plttBlendStep;                            // 0xF08, パレット補間の進み
  u16 plttBlendDuration;                        // 0xF0A, パレット補間にかけるフレーム数
  u32 scriptID;                                 // 0xF0C, 一度実行したら 0 に戻す
  s32 plttDoneScript;                           // 0xF10, パレット補間が終わったら実行するスクリプト, '.p'
  bool8 animDone;                               // 0xF14, anim が一巡したフレームだけ TRUE
  u8 animIdx;                                   // 0xF15, 再生中の ANIM_OTENKO のアニメ番号
  u16 substate : 4;                             // 0xF16, bit0-3, PTR_ARRAY_085b0100 の添字, 0 なら _Update が何もしない
  u16 state : 12;                               // 0xF16, bit4-15, PTR_ARRAY_085b00c4 の添字
  u16 unk_f18;                                  // 0xF18, substate の退避先
  u16 unk_f1a;                                  // 0xF1A, _Init が 200 を入れる
  s16 moveAngle;                                // 0xF1C, 移動先への向き
  s16 unk_f1e;                                  // 0xF1E
  u8 unk_f20;                                   // 0xF20, bit0 は state を変えた印
  u8 unk_f21;                                   // 0xF21, まだ未解析
  u8 animVariant;                               // 0xF22, アニメの variant (向き)
  s8 unk_f23;                                   // 0xF23, '.d=-1'
  u8 unk_f24;                                   // 0xF24, まだ未解析
  s8 swaySign;                                  // 0xF25, 移動中に上下に揺れる向き, frameCounter の偶奇で ±1
  bool8 stopSound;                              // 0xF26, '.A', 立っていると停止時にEntityとBGMも止める
  u8 animXflip;                                 // 0xF27, アニメの左右反転
  u8 gestureFlags;                              // 0xF28, '.r', 身振りのアニメの再生フラグ (左右反転), Cmd_SetOtenkoGuideFlip が書く
  u8 unk_f29[2];                                // 0xF29, まだ未解析
  u8 isDaytime;                                 // 0xF2B, 現れたときに夜でなかったか, 立っていると定位置で拡大する
  u8 unk_f2c[0xF32 - 0xF2C];                    // 0xF2C, まだ未解析
  u8 unk_f32;                                   // 0xF32, '.p'
  u8 unk_f33;                                   // 0xF33, '.u'
  u8 unk_f34[0xF36 - 0xF34];                    // 0xF34, まだ未解析
  u16 dozeBaseY;                                // 0xF36, 寝始めたときの y
  u8 unk_f38;                                   // 0xF38, まだ未解析
  bool8 wakeRequested;                          // 0xF39, 寝ている間にボタンが押された
  u16 lastGesture;                              // 0xF3A, 寝る前の身振りの state, 起きたらここへ戻る
  u16 unk_f3c;                                  // 0xF3C
  s16 unk_f3e;                                  // 0xF3E
  u16 dozeWait;                                 // 0xF40, 入力がないまま寝るまでのフレーム数, 夜は 1800, 昼は 10800
  u8 savedCmdIdx;                               // 0xF42, anim.cmdIdx の退避先
  u8 savedTick;                                 // 0xF43, anim.tick の退避先
  u8 stepTimer;                                 // 0xF44, 0 になると stepCallback を NULL にする
  u8 unk_f45;                                   // 0xF45, まだ未解析
  u16 unk_f46;                                  // 0xF46, _Destroy が Mover_FindByID_Proxy に渡す ID
  void (*plttCallback)(struct OtenkoGuide*);    // 0xF48, パレット補間の処理, 終わると NULL
  void (*dozeCallback)(struct OtenkoGuide*);    // 0xF4C, 放置で寝る・起きるを見張る処理
  void (*updateCallback)(struct OtenkoGuide*);  // 0xF50, _Update が最初に呼ぶ, 処理が終わると自分で NULL にする
  void (*stepCallback)(struct OtenkoGuide*);    // 0xF54, _Update が updateCallback の後に呼ぶ, 次の手順へ自分を差し替えていく
  s32 timer;                                    // 0xF58, 移動や放置を数える汎用のカウンタ
  u32 frameCounter;                             // 0xF5C, _Update が毎フレーム増やす
} OtenkoGuide;
static_assert(sizeof(OtenkoGuide) == 3936);

IWRAM_DATA OtenkoGuide* gOtenkoGuide = NULL;  // 0x03000248

void FUN_080a6e88(bool32 stopSound);
void FUN_080a6edc(void);
void Map_GetZoneMin(u16 id, u16* out);
OtenkoGuide* OtenkoGuide_Create(u32 val, u32 _);
void OtenkoGuide_Pause(OtenkoGuide* p);
void OtenkoGuide_StartCallVoice(OtenkoGuide* p);
void OtenkoGuide_DelayCallVoice(OtenkoGuide*);
void OtenkoGuide_PlayCallVoice(OtenkoGuide*);
void OtenkoGuide_StepPlttBlend(OtenkoGuide* p);
void OtenkoGuide_StepPlttBlendThenScript(OtenkoGuide* p);
void OtenkoGuide_StepPlttBlendBack(OtenkoGuide* p);
void OtenkoGuide_ToScreenCoord(OtenkoGuide* p);
void OtenkoGuide_WaitDoze(OtenkoGuide* p);
void OtenkoGuide_WaitWake(OtenkoGuide* p);
void OtenkoGuide_ScaleUp(OtenkoGuide* p);
void OtenkoPanel_08224dd0(OtenkoGuide* p, OtenkoPanel* elem);
void OtenkoPanel_08224f14(OtenkoGuide* p, OtenkoPanel* elem);
void OtenkoPanel_08224e10(OtenkoGuide* p, OtenkoPanel* elem);
void OtenkoPanel_08224f74(OtenkoGuide* p, OtenkoPanel* elem);

// flag が立っていれば下ろして TRUE を返す
static inline bool8 OtenkoPanel_ConsumeFlag(OtenkoPanel* elem, OtenkoPanelFlags flag) {
  if (TEST_FLAGS(elem->flags, flag)) {
    CLEAR_FLAGS(elem->flags, flag);
    return TRUE;
  }
  return FALSE;
}

// state が変わった直後の最初の更新だけ TRUE を返す
static inline bool8 OtenkoGuide_ConsumeEntered(OtenkoGuide* p) {
  if (TEST_FLAGS(p->unk_f20, 1)) {
    CLEAR_FLAGS(p->unk_f20, 1);
    p->animDone = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 角度をアニメーションの向きと左右反転に変換して, 8方向の向きを返す
static inline s32 OtenkoGuide_AngleToAnimDir(s16 angle, u8* animDir, u8* xflip) {
  while (angle < 0) {
    angle += 256;
  }
  while (angle > 255) {
    angle -= 256;
  }

  // 本当は s32 dir8 を使うべきだが, angle に上書きしないと現状一致が崩れる
  angle = ((angle - 16) >> 5) & 7;
  if (angle == 4) {
    *animDir = 0;
  } else if (angle == 0) {
    *animDir = 4;
  } else {
    if (angle <= 3) {
      *animDir = 4 - angle;
      *xflip = TRUE;
    } else {
      *animDir = angle - 4;
      *xflip = FALSE;
    }
  }
  return angle;
}

// コールバックを差し替えて呼び出しを有効にする
static inline void OtenkoPanel_SetCallback(OtenkoPanel* elem, void (*callback)(struct OtenkoGuide*, struct OtenkoPanel*)) {
  elem->callback = callback;
  SET_FLAGS(elem->flags, OTENKOPANEL_FLAG_UNK_0);
}

// substate を退避して state を要求する
static inline void OtenkoGuide_RequestState(OtenkoGuide* p, u16 substate, u16 state) {
  p->unk_f18 = p->substate;
  p->substate = substate;
  p->state = state;
  if (p->unk_f18 == 3 && p->substate == 3) {
    p->savedCmdIdx = p->anim.cmdIdx;
    p->savedTick = p->anim.tick;
  }
  SET_FLAGS(p->unk_f20, 1);
}

#define IS_NIGHT() (gClock.spanOfTime == TIME_NIGHT_MID || gClock.spanOfTime == TIME_NIGHT_DAWN || gClock.spanOfTime == TIME_NIGHT_DUSK)

void FUN_08222cd4(void) { gOtenkoGuide = NULL; }

void OtenkoGuide_StartPlttBlend(OtenkoGuide* p) {
  p->plttBlendStep = 0;
  p->plttBlendDuration = 50;
  Video_SetAuxSpritePltt(&p->gfx, 280);
  p->plttSrc = p->gfx.pltt;
  p->gfx.pltt = p->pltt2;
  if (p->substate == 2) {
    p->plttCallback = OtenkoGuide_StepPlttBlendThenScript;
  } else {
    p->plttCallback = OtenkoGuide_StepPlttBlend;
  }
}

// pltt1 から pltt0 へパレットを補間する
void OtenkoGuide_StepPlttBlend(OtenkoGuide* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    Rgb8 from;
    Rgb8 to;
    Rgb8 cur;

    from.r = p->pltt1[i] & 31;
    from.g = (p->pltt1[i] >> 5) & 31;
    from.b = (p->pltt1[i] >> 10) & 31;
    to.r = p->pltt0[i] & 31;
    to.g = (p->pltt0[i] >> 5) & 31;
    to.b = (p->pltt0[i] >> 10) & 31;
    cur.r = Div((to.r - from.r) * p->plttBlendStep, p->plttBlendDuration) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->plttBlendStep, p->plttBlendDuration);
    cur.b = Div((to.b - from.b) * p->plttBlendStep, p->plttBlendDuration) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (++p->plttBlendStep > p->plttBlendDuration) {
    p->plttCallback = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 280);
    p->gfx.pltt = p->plttSrc;
  }
}

// pltt1 から pltt0 へパレットを補間し, 終わったらスクリプトを実行する
void OtenkoGuide_StepPlttBlendThenScript(OtenkoGuide* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    Rgb8 from;
    Rgb8 to;
    Rgb8 cur;

    from.r = p->pltt1[i] & 31;
    from.g = (p->pltt1[i] >> 5) & 31;
    from.b = (p->pltt1[i] >> 10) & 31;
    to.r = p->pltt0[i] & 31;
    to.g = (p->pltt0[i] >> 5) & 31;
    to.b = (p->pltt0[i] >> 10) & 31;
    cur.r = Div((to.r - from.r) * p->plttBlendStep, p->plttBlendDuration) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->plttBlendStep, p->plttBlendDuration);
    cur.b = Div((to.b - from.b) * p->plttBlendStep, p->plttBlendDuration) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (++p->plttBlendStep > p->plttBlendDuration) {
    p->plttCallback = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 280);
    p->gfx.pltt = p->plttSrc;
    {
      s32* script = &p->plttDoneScript;
      s32 id = *script;

      if (id != 0) {
        *script = 0;
        VM_ExecByID(id, NULL);
      }
    }
  }
}

void OtenkoGuide_StartPlttBlendBack(OtenkoGuide* p) {
  s32 i;
  rgb555* src;
  rgb555* dst;

  p->plttBlendStep = 50;
  p->plttBlendDuration = 50;
  Video_SetAuxSpritePltt(&p->gfx, 279);
  p->plttSrc = p->gfx.pltt;
  Video_SetAuxSpritePltt(&p->gfx, 280);
  src = p->gfx.pltt;
  dst = p->pltt2;
  for (i = 0; i < 16; i++) {
    *dst++ = *src++;
  }
  p->gfx.pltt = p->pltt2;
  p->plttCallback = OtenkoGuide_StepPlttBlendBack;
}

// pltt1 から pltt0 へパレットを補間する
void OtenkoGuide_StepPlttBlendBack(OtenkoGuide* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    Rgb8 from;
    Rgb8 to;
    Rgb8 cur;

    from.r = p->pltt1[i] & 31;
    from.g = (p->pltt1[i] >> 5) & 31;
    from.b = (p->pltt1[i] >> 10) & 31;
    to.r = p->pltt0[i] & 31;
    to.g = (p->pltt0[i] >> 5) & 31;
    to.b = (p->pltt0[i] >> 10) & 31;
    cur.r = Div((to.r - from.r) * p->plttBlendStep, p->plttBlendDuration) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->plttBlendStep, p->plttBlendDuration);
    cur.b = Div((to.b - from.b) * p->plttBlendStep, p->plttBlendDuration) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (--p->plttBlendStep < 0) {
    p->plttCallback = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->gfx.pltt = p->plttSrc;
    OtenkoGuide_RequestState(p, 2, 13);
  }
}

void OtenkoGuide_ToScreenCoord(OtenkoGuide* p) {
  Vec3 screen;

  p->sprite.flags |= SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
  WorldToScreen(&screen, &p->sprite.pos);
  if (screen.x > 240) {
    screen.x = 240;
  } else if (screen.x < 0) {
    screen.x = 0;
  }
  if (screen.y > 180) {
    screen.y = 180;
  } else if (screen.y < 0) {
    screen.y = 0;
  }
  p->sprite.pos.x = screen.x;
  p->sprite.pos.y = screen.y;
  p->sprite.pos.z = 0;
}

void OtenkoPanel_08223470(OtenkoGuide* p, OtenkoPanel* elem) {
  s32 ofsX;
  s32 ofsZ;
  s32 dx;
  s32 dz;

  if (elem->index != (s8)p->unk_f45) {
    return;
  }

  if (elem->unk_ae == 0) {
    ofsX = 0;
    ofsZ = 128;
  } else {
    ofsX = 128;
    ofsZ = 0;
  }
  dx = p->player->mover.pos.x - elem->pos.x - ofsX;
  dz = p->player->mover.pos.z - elem->pos.z - ofsZ;
  if (dx * dx + dz * dz < p->unk_f1a * p->unk_f1a) {
    s8 a;
    s8 b;
    s8 c;
    u8 angle;

    if (elem->unk_ae == 0) {
      c = 0;
      a = 6, b = 7;
    } else {
      c = 0;
      a = 1, b = 2;
    }
    angle = ArcTan2_8(dx, dz) - 16;
    if (c != angle >> 5 && a != angle >> 5 && b != angle >> 5) {
      b = -1;
      a = -1;
      c = -1;
    }
    if (c == (s16)gStat->sunAngle || a == (s16)gStat->sunAngle || b == (s16)gStat->sunAngle) {
      if (abs(elem->pos.y - p->player->mover.pos.y) < 120 && (gInput[0].pressed & A_BUTTON) && !(gSuspendFlags & SUSPEND_MENU) && p->player->mode != 4) {
        if (elem->unk_a4 != 0) {
          VM_ExecByID(elem->unk_a4, NULL);
        }
        p->sprite.pos.x = elem->sprite.pos.x;
        p->sprite.pos.y = elem->sprite.pos.y;
        p->sprite.pos.z = elem->sprite.pos.z;
        p->scriptID = elem->unk_a0;
        p->stopSound = elem->stopSound;
        if (elem->flags & 0x10) {
          OtenkoGuide_RequestState(p, 1, 3);
          OtenkoPanel_SetCallback(elem, OtenkoPanel_08224f14);
          OtenkoGuide_Pause(p);
        } else {
          OtenkoGuide_RequestState(p, 1, 2);
          OtenkoPanel_SetCallback(elem, OtenkoPanel_08224e10);
          OtenkoGuide_StartCallVoice(p);
        }
      }
    }
  }
}

// 264/266 命令, r10 まで使う局所の持ち方が違う, 下書き段階
// 266/266 命令, elem と dz の r5/r4 の入れ替わりだけ
NON_MATCH void OtenkoPanel_08223748(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  s32 i;

  p->unk_f45 = 0xFF;
  for (i = 0; i < 16; i++) {
    OtenkoPanel* elem = &p->elems[i];

    elem->unk_d4 = 0;
    if ((elem->flags & 10) == 0) {
      s32 ofsX;
      s32 ofsZ;
      s32 dx;
      s32 dz;

      if (elem->unk_ae == 0) {
        ofsX = 0;
        ofsZ = 128;
      } else {
        ofsX = 128;
        ofsZ = 0;
      }
      dx = p->player->mover.pos.x - elem->pos.x - ofsX;
      dz = p->player->mover.pos.z - elem->pos.z - ofsZ;
      if (dx * dx + dz * dz < p->unk_f1a * p->unk_f1a) {
        s8 a;
        s8 b;
        s8 c;
        u8 angle;

        if (elem->unk_ae == 0) {
          c = 0;
          a = 6, b = 7;
        } else {
          c = 0;
          a = 1, b = 2;
        }
        angle = ArcTan2_8(dx, dz) - 16;
        if (c != angle >> 5 && a != angle >> 5 && b != angle >> 5) {
          b = -1;
          a = -1;
          c = -1;
        }
        if (c == (s16)gStat->sunAngle || a == (s16)gStat->sunAngle || b == (s16)gStat->sunAngle) {
          if (abs(elem->pos.y - p->player->mover.pos.y) < 120) {
            elem->unk_d4 = 1;
            elem->unk_d0 = dx * dx + dz * dz;
            if ((s8)p->unk_f45 == -1) {
              p->unk_f45 = i;
            } else if (elem->unk_d0 < p->elems[(s8)p->unk_f45].unk_d0) {
              p->unk_f45 = i;
            }
          }
        }
      }
    }
  }

  for (i = 0; i < 16; i++) {
    OtenkoPanel* elem = &p->elems[i];

    if (i == (s8)p->unk_f45) {
      if (++elem->unk_b0 > 10) {
        Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase);
        elem->unk_b0 = 10;
      } else {
        Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 1);
      }
    } else {
      u8 prev = elem->unk_b0--;

      if (prev == 0) {
        elem->unk_b0 = 0;
        Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 2);
      } else {
        Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 1);
      }
    }
  }
#else
  INCFUNC("asm/func/OtenkoPanel_08223748.inc");
#endif
}

void OtenkoGuide_Pause(OtenkoGuide* p) { FUN_080a6e88(p->stopSound); }

void OtenkoGuide_RestoreAnimState(OtenkoGuide* p) {
  p->anim.cmdIdx = p->savedCmdIdx;
  p->anim.tick = p->savedTick;
}

void OtenkoGuide_ScaleUp(OtenkoGuide* p) {
  s32 scaleX = p->sprite.scaleX;
  s32 scaleY = p->sprite.scaleY;

  scaleX += 2;
  scaleY += 2;

  if (scaleX > 0x7F) {
    scaleX = scaleY = 0x7F;
    p->updateCallback = NULL;
  }
  p->sprite.scaleX = scaleX;
  p->sprite.scaleY = scaleY;
}

void OtenkoGuide_StartDozeTimer(OtenkoGuide* p) {
  if (p->sprite.pos.x == 25 && p->sprite.pos.z == 0 && abs(p->sprite.pos.y - 102) < 10) {
    p->timer = 0;
    p->dozeCallback = OtenkoGuide_WaitDoze;
    if (IS_NIGHT()) {
      p->dozeWait = 1800;
    } else {
      p->dozeWait = 10800;
    }
    if (p->isDaytime && p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = OtenkoGuide_ScaleUp;
    }
  } else {
    p->dozeCallback = NULL;
  }
}

// 残差は pos 周りのアドレスを作るレジスタと state だけ書き換える行の形
NON_MATCH void OtenkoGuide_WaitDoze(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  if (*(u32*)gInput != 0) {
    p->timer = 0;
    if (IS_NIGHT()) {
      p->dozeWait = 1800;
    } else {
      p->dozeWait = 10800;
    }
  }
  if (++p->timer > p->dozeWait && p->animDone) {
    p->wakeRequested = FALSE;
    p->lastGesture = p->state;
    p->state = 5;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    p->dozeCallback = OtenkoGuide_WaitWake;
    p->bobTimer = 0;
    p->dozeBaseY = p->sprite.pos.y;
  }
#else
  INCFUNC("asm/func/OtenkoGuide_WaitDoze.inc");
#endif
}

void OtenkoGuide_WaitWake(OtenkoGuide* p) {
  if (*(u32*)gInput != 0) {
    p->wakeRequested = TRUE;
    p->bobTimer = 0;
  }
  if (p->wakeRequested && p->animDone) {
    p->sprite.pos.y = p->dozeBaseY - 1;
    p->timer = 0;
    p->dozeCallback = OtenkoGuide_WaitDoze;
    OtenkoGuide_RequestState(p, 3, p->lastGesture);
  }
}

void OtenkoGuide_StartCallVoice(OtenkoGuide* p) {
  PlaySound_082406e0(SE_INFO);
  p->stepCallback = OtenkoGuide_DelayCallVoice;
}

void OtenkoGuide_DelayCallVoice(OtenkoGuide* p) {
  p->stepTimer = 12;
  p->stepCallback = OtenkoGuide_PlayCallVoice;
}

void OtenkoGuide_PlayCallVoice(OtenkoGuide* p) {
  if (--p->stepTimer == 0) {
    p->stepCallback = NULL;
    if (gClock.spanOfTime >= TIME_MORNING && gClock.spanOfTime <= TIME_SUNSET) {
      PlaySound_082406e0(VO_OTENKO_OTNK);
    } else {
      Time_GetHour();
    }
  }
}

// 0xA99F, ANIM_OTENKO のアニメ 2 (通常の顔) を流す, タイトルデモの場面の最初に使う
void Cmd_OtenkoGuideIdle(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 1);
}

// 0x0447, ANIM_OTENKO のアニメ 3 (気合い入れて行けよと鼓舞する顔) を流す, ガイド項目の締めに使う (Cmd_OtenkoGuideWink と同じ使いどころの別バリエーション)
void Cmd_OtenkoGuideCheer(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 2);
}

// 0x03CA, ANIM_OTENKO のアニメ 4 (ウィンク) を流す, ガイド項目の締めに使う (Cmd_OtenkoGuideCheer と同じ使いどころの別バリエーション)
void Cmd_OtenkoGuideWink(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 3);
}

// 0x225B, ANIM_OTENKO のアニメ 5 を流す, 今作のスクリプトからは使われない
void Cmd_225B(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 4);
}

// 0xFA5D, ANIM_OTENKO のアニメ 6 (寝る) を流す
void Cmd_OtenkoGuideSleep(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 5);
}

// 0xB838, ANIM_OTENKO のアニメ 7 (しょんぼりした顔) を流す, ネガティブな説明のときに使う
void Cmd_OtenkoGuideSad(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 6);
}

// 0x667C, ANIM_OTENKO のアニメ 8 (ムスッとした顔) を流す, ネガティブな説明のときに使う
void Cmd_OtenkoGuidePout(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 7);
}

// 0x3E17, ANIM_OTENKO のアニメ 9 を流す, 今作のスクリプトからは使われない
void Cmd_3E17(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 8);
}

// 0xAB9C, 花が玉に戻るアニメ (10) と効果音で消える
void Cmd_HideOtenkoGuide(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p != NULL) {
    p->unk_f32 = VM_GetNamedArgValue('p', 0);
    if (!(p->sprite.flags & SPRFLAG_HIDDEN)) {
      OtenkoGuide_RequestState(p, 3, 9);
    }
  }
}

void OtenkoGuide_SetGesture(s32 kind) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  if (kind == 12) {
    PlaySound_082406e0(VO_OTENKO_OTNK);
  } else if (kind == 14) {
    FUN_080a6edc();
  } else {
    OtenkoGuide_RequestState(p, 3, kind);
    p->lastGesture = p->state;
  }
}

void FUN_082243bc(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 10);
}

void FUN_08224458(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 11);
}

void FUN_082244f4(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 3, 13);
}

void Cmd_3D17(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  if (VM_SeekToNamedArg('t')) {
    p->targetX = VM_GetValue();
    p->targetY = VM_GetValue() + 160;
    p->targetZ = VM_GetValue();
  } else {
    p->targetX = p->player->mover.pos.x;
    p->targetY = p->player->mover.pos.y + 160;
    p->targetZ = p->player->mover.pos.z;
  }
  p->unk_f23 = VM_GetNamedArgValue('d', -1);
  p->scriptID = VM_GetNamedArgValue('p', 0);
  OtenkoGuide_RequestState(p, 2, 10);
}

// 0xD0CE
void Cmd_D0CE(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  p->unk_f33 = VM_GetNamedArgValue('u', 0);
  p->scriptID = VM_GetNamedArgValue('p', 0);
  OtenkoGuide_ToScreenCoord(p);
  OtenkoGuide_RequestState(p, 2, 8);
}

// 0x1A35, '.t' の位置へ揺れながら移動し, 着いたら '.p' のスクリプトを実行する
void Cmd_MoveOtenkoGuideTo(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->scriptID = VM_GetNamedArgValue('p', 0);
  if (VM_SeekToNamedArg('t')) {
    p->targetX = VM_GetValue();
    p->targetY = VM_GetValue();
  } else {
    p->targetY = 0;
    p->targetX = 0;
  }
  OtenkoGuide_RequestState(p, 2, 9);
}

// 0x69CD
void Cmd_69CD(void) {
  OtenkoGuide* p = gOtenkoGuide;
  u8 dir;
  bool8 xflip;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  dir = VM_GetNamedArgValue('d', 0);
  xflip = FALSE;
  dir &= 7;
  p->unk_f24 = dir;
  if (IS_8DIR_LEFT(dir)) {
    dir = 8 - dir;
    xflip = TRUE;
  }
  p->animVariant = dir;
  p->animXflip = xflip;
  AuxAnim_SetAnim(&p->anim, p->animFile, 0, p->animVariant, p->animXflip);
  OtenkoGuide_RequestState(p, 2, 0);
}

// 0x7F67
void Cmd_7F67(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  OtenkoGuide_RequestState(p, 2, 11);
  p->plttDoneScript = VM_GetNamedArgValue('p', 0);
}

void Cmd_7F44(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  OtenkoGuide_RequestState(p, 2, 12);
  p->plttDoneScript = VM_GetNamedArgValue('p', 0);
}

// 0xA3B3
void Cmd_A3B3(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 2, 7);
}

// 0x5276
void Cmd_5276(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  if (VM_SeekToNamedArg('p')) {
    p->sprite.pos.x = VM_GetValue();
    p->sprite.pos.y = VM_GetValue();
    p->sprite.pos.z = VM_GetValue();
  } else {
    p->sprite.pos.x = p->player->mover.pos.x;
    p->sprite.pos.y = p->player->mover.pos.y + 160;
    p->sprite.pos.z = p->player->mover.pos.z;
  }
  OtenkoGuide_RequestState(p, 2, 14);
}

// 0xD169
void Cmd_D169(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  OtenkoGuide_RequestState(p, 2, 15);
}

// 0xB50D
s32 Cmd_B50D(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) return 0;
  }
  return p->unk_f24;
}

// 0x48B3
void Cmd_SetOtenkoGuidePriority(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->sprite.priority = VM_GetNamedArgValue('p', 0);
}

// 0x30A3, '.r' を身振りのアニメの再生フラグに入れる (左右反転)
void Cmd_SetOtenkoGuideFlip(void) {
  OtenkoGuide* p = gOtenkoGuide;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->gestureFlags = VM_GetNamedArgValue('r', 0);
}

void OtenkoPanel_CallbackNone(OtenkoGuide* _, OtenkoPanel* __) {}

// 残差は先頭の引数の複写 2 命令の順序だけ
NON_MATCH void OtenkoPanel_08224dd0(OtenkoGuide* p, OtenkoPanel* elem) {
#ifdef NONMATCHING_C
  if (OtenkoPanel_ConsumeFlag(elem, OTENKOPANEL_FLAG_UNK_0)) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  OtenkoPanel_08223470(p, elem);
#else
  INCFUNC("asm/func/OtenkoPanel_08224dd0.inc");
#endif
}

// 残差は先頭の引数の複写 2 命令の順序だけ
NON_MATCH void OtenkoPanel_08224e10(OtenkoGuide* p, OtenkoPanel* elem) {
#ifdef NONMATCHING_C
  if (OtenkoPanel_ConsumeFlag(elem, OTENKOPANEL_FLAG_UNK_0)) {
    p->timer = 10;
    if (!IS_NIGHT()) {
      p->isDaytime = TRUE;
    } else {
      p->isDaytime = FALSE;
    }
    p->unk_f33 = elem->unk_ca;
  }
  if (--p->timer == -1) {
    OtenkoGuide_RequestState(p, 2, 4);
  }
#else
  INCFUNC("asm/func/OtenkoPanel_08224e10.inc");
#endif
}

// 残差は先頭の引数の複写の順序と scriptID のレジスタ
NON_MATCH void OtenkoPanel_08224f14(OtenkoGuide* p, OtenkoPanel* elem) {
#ifdef NONMATCHING_C
  if (OtenkoPanel_ConsumeFlag(elem, OTENKOPANEL_FLAG_UNK_0)) {
    u32 scriptID = p->scriptID;

    if (scriptID != 0) {
      p->scriptID = 0;
      VM_ExecByID(scriptID, NULL);
    }
    elem->callback = OtenkoPanel_08224dd0;
    SET_FLAGS(elem->flags, OTENKOPANEL_FLAG_UNK_0);
  }
#else
  INCFUNC("asm/func/OtenkoPanel_08224f14.inc");
#endif
}

void OtenkoPanel_08224f74(OtenkoGuide* p, OtenkoPanel* elem) {
  if (OtenkoPanel_ConsumeFlag(elem, OTENKOPANEL_FLAG_UNK_0)) {
    Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 2);
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

// 199/199 命令, 定数 3 を写して使う r2 と r1 の割当だけが違う
NON_MATCH void OtenkoGuide_UpdateHover(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  OtenkoGuide_ConsumeEntered(p);
  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    p->sprite.pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateHover.inc");
#endif
}

void OtenkoGuide_UpdateAppearInWorld(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.flags &= ~SPRFLAG_SCREEN_COORD;
    p->sprite.flags &= ~SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    p->sprite.pos.y += 160;
    p->pos.y = p->sprite.pos.y;
    PlaySound_082406e0(SE_INFO);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    u32* script;
    s32 scriptID;

    ParticleShadow_Show(&p->shadow);
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    AuxAnim_SetAnim(&p->anim, p->animFile, 0, 4, 0);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
}

void OtenkoGuide_UpdateAppearOnScreen(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->targetX = 25;
    p->targetY = 102;
    p->targetZ = 0;
    p->animIdx = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_INFO);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    u32* script;
    s32 scriptID;

    OtenkoGuide_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
}

void OtenkoGuide_UpdateAppearToTalk(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->targetX = 25;
    p->targetY = 102;
    p->targetZ = 0;
    p->animIdx = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->unk_f33 = 0;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    OtenkoGuide_ToScreenCoord(p);
    p->sprite.pos.y += 8;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_INFO);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    p->state = 8;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
  }
}

void OtenkoGuide_UpdateAppearToTalkQuiet(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->targetX = 25;
    p->targetY = 102;
    p->targetZ = 0;
    p->animIdx = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->unk_f33 = 0;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    OtenkoGuide_ToScreenCoord(p);
    p->sprite.pos.y += 8;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    p->state = 8;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
  }
}

void OtenkoGuide_UpdateShowInWorld(OtenkoGuide* p) {
  u32* script;
  s32 scriptID;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.flags &= ~SPRFLAG_SCREEN_COORD;
    p->sprite.flags &= ~SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    p->sprite.pos.y += 160;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Show(&p->shadow);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    AuxAnim_SetAnim(&p->anim, p->animFile, 0, 4, 0);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  script = &p->scriptID;
  scriptID = *script;
  if (scriptID != 0) {
    *script = 0;
    VM_ExecByID(scriptID, NULL);
  }
}

void OtenkoGuide_UpdateShowOnScreen(OtenkoGuide* p) {
  u32* script;
  s32 scriptID;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 127;
    p->sprite.scaleX = 127;
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    AuxAnim_SetAnim(&p->anim, p->animFile, 0, 4, 0);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  script = &p->scriptID;
  scriptID = *script;
  if (scriptID != 0) {
    *script = 0;
    VM_ExecByID(scriptID, NULL);
  }
}

// 残差は movs r3, #15 の位置だけ
NON_MATCH void OtenkoGuide_UpdateLeave(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  if (OtenkoGuide_ConsumeEntered(p)) {
    s32 i;
    OtenkoPanel* elem;

    FUN_080a6edc();
    ParticleShadow_Hide(&p->shadow);
    p->sprite.flags |= SPRFLAG_HIDDEN;
    OtenkoGuide_RequestState(p, 1, 2);
    for (i = 0, elem = p->elems; i < 16; i++) {
      if (TEST_FLAGS(elem->flags, OTENKOPANEL_FLAG_UNK_2)) {
        elem->callback = OtenkoPanel_08224dd0;
        SET_FLAGS(elem->flags, OTENKOPANEL_FLAG_UNK_0);
      }
      elem++;
    }
  }
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateLeave.inc");
#endif
}

// 499/499 命令, sign の定数の置き場所が違う
NON_MATCH void OtenkoGuide_UpdateMoveToTalkPos(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->timer = 0;
    p->startPos.x = p->sprite.pos.x;
    p->startPos.y = p->sprite.pos.y;
    p->startPos.z = p->sprite.pos.z;
    p->animIdx = 0;
    {
      s32 sign = -1;

      if (p->frameCounter & 1) {
        sign = 1;
      }
      p->swaySign = sign;
    }
    ParticleShadow_Hide(&p->shadow);
    if (p->isDaytime != 0 && p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = OtenkoGuide_ScaleUp;
    }
    if (p->unk_f33 == 0) {
      p->targetX = 25;
      p->targetY = 102;
    } else if (IS_NIGHT()) {
      p->targetX = 25;
      p->targetY = 75;
    } else {
      p->targetX = 25;
      p->targetY = 92;
    }
    p->targetZ = 0;
  }

  p->moveAngle = ArcTan2_8((s16)p->targetX - p->sprite.pos.x, (s16)p->targetY - p->sprite.pos.y) & 0xFF;
  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->timer++ < 32) {
    s16 angle = p->moveAngle - 16;
    u32 dir;

    while (angle < 0) {
      angle += 256;
    }
    while (angle > 255) {
      angle -= 256;
    }
    dir = ((angle - 16) >> 5) & 7;
    if (dir == 4) {
      p->animVariant = 0;
    } else if (dir == 0) {
      p->animVariant = 4;
    } else {
      if (dir > 3) {
        p->animVariant = dir - 4;
      } else {
        p->animVariant = 4 - dir;
      }
      p->animXflip = dir <= 3;
    }
    AuxAnim_SetAnim(&p->anim, p->animFile, p->animIdx, p->animVariant, p->animXflip);
    p->sprite.pos.x = p->startPos.x + Div(((s16)p->targetX - p->startPos.x) * p->timer, 32);
    p->sprite.pos.y = p->startPos.y + Div(((s16)p->targetY - p->startPos.y) * p->timer, 32) + (s8)p->swaySign * (gSineTable[(p->timer & 63) * 4] >> 7);
  } else {
    u32* script;
    s32 scriptID;

    p->sprite.pos.x = p->targetX;
    p->sprite.pos.y = p->targetY;
    OtenkoGuide_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateMoveToTalkPos.inc");
#endif
}

// 今の位置から targetX / targetY へ 32 フレームで揺れながら移動し, 着いたら身振りに入ってスクリプトを実行する
void OtenkoGuide_UpdateMoveTo(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->timer = 0;
    p->startPos.x = p->sprite.pos.x;
    p->startPos.y = p->sprite.pos.y;
    p->startPos.z = p->sprite.pos.z;
    p->moveDeltaX = (s16)p->targetX - p->sprite.pos.x;
    p->moveDeltaY = (s16)p->targetY - p->sprite.pos.y;
    p->animIdx = 0;
    p->swaySign = (p->frameCounter & 1) ? 1 : -1;
    ParticleShadow_Hide(&p->shadow);
    if (p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = OtenkoGuide_ScaleUp;
    }
  }

  p->moveAngle = (u8)ArcTan2_8((s16)p->targetX - p->sprite.pos.x, (s16)p->targetY - p->sprite.pos.y);
  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->timer++ >= 32) {
    u32* script;
    s32 scriptID;

    p->sprite.pos.x = p->targetX;
    p->sprite.pos.y = p->targetY;
    OtenkoGuide_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  } else {
    OtenkoGuide_AngleToAnimDir(p->moveAngle - 16, &p->animVariant, &p->animXflip);
    AuxAnim_SetAnim(&p->anim, p->animFile, p->animIdx, p->animVariant, p->animXflip);
    p->sprite.pos.x = p->startPos.x + Div(p->moveDeltaX * p->timer, 32);
    {
      s32 move = Div(p->moveDeltaY * p->timer, 32);
      s32 wave = SIN(p->timer * 4);
      s32 amp = p->swaySign * 30;

      amp *= wave;
      wave = amp >= 0 ? amp >> 12 : -(-amp >> 12);
      p->sprite.pos.y = p->startPos.y + move + wave;
    }
  }
}

// 682/679 命令, switch の各経路で &p->bobStep を作って持ち越す形だけが違う
NON_MATCH void FUN_08226990(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  s32 dx = (s16)p->targetX - p->sprite.pos.x;
  s32 dz = (s16)p->targetZ - p->sprite.pos.z;
  bool8 entered;
  u16* timer;
  AuxSprite* sprite;
  AuxAnimState* anim;

  p->moveAngle = (u8)ArcTan2_8(dx, dz);
  entered = OtenkoGuide_ConsumeEntered(p);
  timer = &p->bobTimer;
  if (entered) {
    p->animIdx = 0;
    p->unk_f24 = (OtenkoGuide_AngleToAnimDir(p->moveAngle, &p->animVariant, &p->animXflip) - 4) & 7;
    p->unk_f38 = 0;
    ParticleShadow_Show(&p->shadow);
  }

  sprite = &p->sprite;
  if (((*timer)++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, p->animIdx, p->animVariant, p->animXflip);
  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, anim);
  if (abs(dx) + abs(dz) < 10 && p->unk_f38 != 0) {
    p->sprite.pos.x = p->targetX;
    p->sprite.pos.z = p->targetZ;
    {
      s8* defaultDir = &p->unk_f23;

      if (*defaultDir >= 0) {
        bool8 xflip = FALSE;
        s8 raw;
        s32 masked;
        u8 dir;

        p->unk_f24 = *defaultDir;
        raw = *defaultDir;
        masked = raw & 7;
        dir = masked;
        if (IS_8DIR_LEFT(masked)) {
          dir = 8 - masked;
          xflip = TRUE;
        }
        anim = &p->anim;
        AuxAnim_SetAnim(anim, p->animFile, p->animIdx, dir, xflip);
        p->animDone = AuxSprite_AdvanceAnim(&p->sprite, anim);
      }
    }
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    {
      u32* script = &p->scriptID;
      s32 scriptID = *script;

      if (scriptID != 0) {
        *script = 0;
        VM_ExecByID(scriptID, NULL);
      }
    }
    return;
  }

  if (p->unk_f38 == 0) {
    s16* target = &p->targetY;
    s16* y = &p->sprite.pos.y;

    if (*target > *y) {
      *y += 7;
      p->pos.y += 7;
      if (*target < *y) {
        *y = *target;
        p->pos.y = *target;
        p->unk_f38 = 1;
      }
    } else if (*target < *y) {
      *y -= 7;
      p->pos.y -= 7;
      if (*target > *y) {
        *y = *target;
        p->pos.y = *target;
        p->unk_f38 = 1;
      }
    }
  }

  if (dx != 0 || dz != 0) {
    p->moveDeltaX = Div(COS(p->moveAngle), 500);
    p->unk_e88 = Div(SIN(p->moveAngle), 500);
    p->sprite.pos.x += p->moveDeltaX;
    p->sprite.pos.z += p->unk_e88;
    p->pos.x = p->sprite.pos.x;
    p->pos.z = p->sprite.pos.z;
  }
#else
  INCFUNC("asm/func/FUN_08226990.inc");
#endif
}

void FUN_08226fd0(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 11;
    AuxAnim_SetAnim(&p->anim, p->animFile, 11, 0, 0);
    ParticleShadow_Show(&p->shadow);
    p->plttCallback = OtenkoGuide_StartPlttBlend;
  }

  if (p->plttCallback != NULL) {
    p->plttCallback(p);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    p->anim.cmdIdx = 1;
  }
}

void FUN_08227168(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 19;
    AuxAnim_SetAnim(&p->anim, p->animFile, 19, 0, 0);
    ParticleShadow_Show(&p->shadow);
    p->plttCallback = OtenkoGuide_StartPlttBlendBack;
  }

  if (p->plttCallback != NULL) {
    p->plttCallback(p);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
}

void FUN_082272f0(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 18;
    AuxAnim_SetAnim(&p->anim, p->animFile, 18, 0, 0);
    ParticleShadow_Show(&p->shadow);
  }

  if (p->plttCallback != NULL) {
    p->plttCallback(p);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    s32* script = &p->plttDoneScript;
    s32 scriptID = *script;

    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
    if (p->animDone) {
      p->anim.cmdIdx = 1;
    }
  }
}

void FUN_08227498(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 12;
    AuxAnim_SetAnim(&p->anim, p->animFile, 12, 0, 0);
    Video_SetAuxSpritePltt(&p->gfx, 282);
    AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    p->sprite.priority = 3;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

// 439/435 命令, ループ外に定数を持つ形が違う, 下書き段階
NON_MATCH void FUN_08227608(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  u16* timer;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 13;
    AuxAnim_SetAnim(&p->anim, p->animFile, 13, 0, 0);
    Video_SetAuxSpritePltt(&p->gfx, 282);
    AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    p->unk_f3c = 0;
    p->unk_f3e = 15;
  }

  timer = &p->unk_f3c;
  if (Mod(++*timer, p->unk_f3e) == 0) {
    *timer = 0;
    if (p->sprite.flags & SPRFLAG_HIDDEN) {
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprite.flags |= SPRFLAG_HIDDEN;
    }
    if (--p->unk_f3e == 0) {
      Vec3* pos = &p->sprite.pos;
      s32 i;

      Puff_SpawnSprayOne(pos, 1, 512, Q6(0.75), 8, 8, 8, 4);
      Puff_SpawnSprayOne(pos, 1, 512, Q6(0.75), 8, 8, 8, 4);
      Puff_SpawnSprayOne(pos, 1, 512, Q6(0.75), 8, 8, 8, 4);
      Puff_SpawnSprayOne(pos, 1, 512, Q6(0.75), 8, 8, 8, 4);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 32, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 64, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 96, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 128, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 160, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 192, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 224, 60, 10, 3, 10, 5, 60, 10);
      ScatterEffect_SpawnAtAngle(1, SCATTER_STONE, pos, 256, 60, 10, 3, 10, 5, 60, 10);
      ParticleShadow_Hide(&p->shadow);
      p->sprite.flags |= SPRFLAG_HIDDEN;
      OtenkoGuide_RequestState(p, 1, 2);
      for (i = 0; i < 16; i++) {
        if (p->elems[i].flags & 4) {
          p->elems[i].callback = OtenkoPanel_08224dd0;
          p->elems[i].flags |= 1;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08227608.inc");
#endif
}

void FUN_082279e0(OtenkoGuide* _) {}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void OtenkoGuide_UpdateIdle(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 2;
    AuxAnim_SetAnim(&p->anim, p->animFile, 2, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateIdle.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void OtenkoGuide_UpdateCheer(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 3;
    AuxAnim_SetAnim(&p->anim, p->animFile, 3, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateCheer.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void OtenkoGuide_UpdateWink(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 4;
    AuxAnim_SetAnim(&p->anim, p->animFile, 4, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateWink.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void FUN_08228074(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 5;
    AuxAnim_SetAnim(&p->anim, p->animFile, 5, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08228074.inc");
#endif
}

void OtenkoGuide_UpdateSleep(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 6;
    AuxAnim_SetAnim(&p->anim, p->animFile, 6, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  switch (p->anim.cmdIdx & 7) {
    case 0:
    case 1:
    case 6:
    case 7: {
      p->bobStep = 1;
      break;
    }
    case 2:
    case 3:
    case 4:
    case 5: {
      p->bobStep = -1;
      break;
    }
  }

  if (Mod(p->anim.tick, 5) == 0) {
    p->sprite.pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void OtenkoGuide_UpdateSad(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 7;
    AuxAnim_SetAnim(&p->anim, p->animFile, 7, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateSad.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void OtenkoGuide_UpdatePout(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 8;
    AuxAnim_SetAnim(&p->anim, p->animFile, 8, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/OtenkoGuide_UpdatePout.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->bobStep を r1 に持ち越す形が作れない
NON_MATCH void FUN_08228918(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 9;
    AuxAnim_SetAnim(&p->anim, p->animFile, 9, 0, p->gestureFlags);
    OtenkoGuide_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    OtenkoGuide_StartDozeTimer(p);
  }

  if (p->dozeCallback != NULL) {
    p->dozeCallback(p);
  }

  sprite = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->bobStep;
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08228918.inc");
#endif
}

// 248/248 命令, ループ前の定数 r3 の位置とレジスタの割当だけが違う
NON_MATCH void OtenkoGuide_UpdateHide(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 10;
    AuxAnim_SetAnim(&p->anim, p->animFile, 10, 0, p->gestureFlags);
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_UNK_287);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    OtenkoPanel* elem;
    s32 i;

    if (p->unk_f32 != 0) {
      FUN_080a6edc();
    }
    p->sprite.flags |= SPRFLAG_HIDDEN;
    OtenkoGuide_RequestState(p, 1, 2);
    elem = p->elems;
    for (i = 0; i < 16; i++) {
      if (elem->flags & 4) {
        elem->callback = OtenkoPanel_08224dd0;
        elem->flags |= 1;
      }
      elem++;
    }
  }
#else
  INCFUNC("asm/func/OtenkoGuide_UpdateHide.inc");
#endif
}

// 100/106 命令, switch の分岐ごとに bobStep のアドレスを作る形が未解決
NON_MATCH void FUN_08228d8c(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  s32 scaleX;
  s32 scaleY;

  if (OtenkoGuide_ConsumeEntered(p)) {
    ParticleShadow_Hide(&p->shadow);
  }
  spr = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    spr->pos.y += p->bobStep;
  }
  scaleX = spr->scaleX + 1;
  scaleY = spr->scaleY + 1;
  if (scaleX > 127) {
    scaleY = 127;
    scaleX = 127;
  }
  spr->scaleX = scaleX;
  spr->scaleY = scaleY;
#else
  INCFUNC("asm/func/FUN_08228d8c.inc");
#endif
}

// FUN_08228d8c と同じ残差
NON_MATCH void FUN_08228e94(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  s32 scaleX;
  s32 scaleY;

  if (OtenkoGuide_ConsumeEntered(p)) {
    ParticleShadow_Hide(&p->shadow);
  }
  spr = &p->sprite;
  if ((p->bobTimer++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = 1;
        } else {
          p->bobStep = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->bobStep = -1;
        } else {
          p->bobStep = 8;
        }
        break;
      }
    }
    spr->pos.y += p->bobStep;
  }
  scaleX = spr->scaleX - 1;
  scaleY = spr->scaleY - 1;
  if (scaleX < 64) {
    scaleY = 64;
    scaleX = 64;
  }
  spr->scaleX = scaleX;
  spr->scaleY = scaleY;
#else
  INCFUNC("asm/func/FUN_08228e94.inc");
#endif
}

void FUN_08228f9c(OtenkoGuide* p) {
  if (OtenkoGuide_ConsumeEntered(p)) {
    p->animIdx = 11;
    AuxAnim_SetAnim(&p->anim, p->animFile, 11, 0, p->gestureFlags);
    ParticleShadow_Hide(&p->shadow);
    p->plttCallback = OtenkoGuide_StartPlttBlend;
  }

  if (p->plttCallback != NULL) {
    p->plttCallback(p);
  }

  p->animDone = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->animDone) {
    p->anim.cmdIdx = 1;
  }
}

void FUN_0822913c(OtenkoGuide* _) {}

// 112/121 命令, sp に局所を1つ持つ形と zoneID を歩くポインタが違う
NON_MATCH void OtenkoPanel_08229140(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  for (i = 0; i < 16; i++) {
    bool32 visible = FALSE;

    for (j = 0; j < p->elems[i].unk_b4; j++) {
      if (gStat->zoneID == (&p->elems[i].zoneID)[j]) {
        visible = TRUE;
      }
    }
    if (visible) {
      p->elems[i].sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->elems[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }

  for (i = 0; i < 16; i++) {
    if ((p->elems[i].flags & 4) && !(p->elems[i].sprite.flags & SPRFLAG_HIDDEN)) {
      if (p->elems[i].unk_cb != 0) {
        p->elems[i].unk_cb--;
      }
      p->elems[i].callback(p, &p->elems[i]);
    }
  }
#else
  INCFUNC("asm/func/OtenkoPanel_08229140.inc");
#endif
}

void OtenkoGuide_CallActionHandler(OtenkoGuide* p) {
  static void (*const PTR_ARRAY_085b0084[16])(OtenkoGuide*) = {
      OtenkoGuide_UpdateHover,
      OtenkoGuide_UpdateAppearInWorld,
      OtenkoGuide_UpdateAppearOnScreen,
      OtenkoGuide_UpdateAppearToTalk,
      OtenkoGuide_UpdateAppearToTalkQuiet,
      OtenkoGuide_UpdateShowInWorld,
      OtenkoGuide_UpdateShowOnScreen,
      OtenkoGuide_UpdateLeave,
      OtenkoGuide_UpdateMoveToTalkPos,
      OtenkoGuide_UpdateMoveTo,
      FUN_08226990,
      FUN_08226fd0,
      FUN_08227168,
      FUN_082272f0,
      FUN_08227498,
      FUN_08227608,
  };  // 0x085B0084

  VEC3_SET(p->unk_e40.pos, p->pos.x, p->pos.y, p->pos.z);
  PTR_ARRAY_085b0084[p->state](p);
}

void OtenkoGuide_CallGestureHandler(OtenkoGuide* p) {
  static void (*const PTR_ARRAY_085b00c4[15])(OtenkoGuide*) = {
      FUN_082279e0,
      OtenkoGuide_UpdateIdle,
      OtenkoGuide_UpdateCheer,
      OtenkoGuide_UpdateWink,
      FUN_08228074,
      OtenkoGuide_UpdateSleep,
      OtenkoGuide_UpdateSad,
      OtenkoGuide_UpdatePout,
      FUN_08228918,
      OtenkoGuide_UpdateHide,
      FUN_08228d8c,
      FUN_08228e94,
      NULL,
      FUN_08228f9c,
      NULL,
  };  // 0x085B00C4
  PTR_ARRAY_085b00c4[p->state](p);
}

void OtenkoGuide_CallSubstateHandler(OtenkoGuide* p) {
  static void (*const PTR_ARRAY_085b0100[4])(OtenkoGuide*) = {
      FUN_0822913c,
      OtenkoPanel_08229140,
      OtenkoGuide_CallActionHandler,
      OtenkoGuide_CallGestureHandler,
  };  // 0x085B0100

  OtenkoPanel_08223748(p);
  PTR_ARRAY_085b0100[p->substate](p);
}

s32 OtenkoGuide_Update(OtenkoGuide* p) {
  if (p->substate == 0) {
    return 1;
  }

  OtenkoGuide_CallSubstateHandler(p);
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  if (p->stepCallback != NULL) {
    p->stepCallback(p);
  }
  p->frameCounter++;
  // 戻り値のある宣言だが return なし
}

s32 OtenkoGuide_Destroy(OtenkoGuide* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  ParticleShadow_Remove(&p->shadow);
  for (i = 0; i < 16; i++) {
    AuxSprite_Remove(&p->elems[i].sprite);
  }
  if (Mover_FindByID_Proxy(p->unk_f46) != NULL) {
    Mover_Unlink(&p->unk_e40);
  }
  gOtenkoGuide = NULL;
  // 戻り値のある宣言だが return なし
}

// 0xA3AA, おてんこパネル ('.t' の種類) を並べる, 今作のスクリプトからは使われない
// 413/387 命令, ループ外へ出すアドレスの組が違う, 空ループの j も位置が合わない
NON_MATCH void Cmd_PlaceOtenkoPanels(void) {
#ifdef NONMATCHING_C
  OtenkoGuide* p = gOtenkoGuide;
  s32 i;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }

  for (i = 0; i < 16; i++) {
    if (p->elems[i].flags & 2) {
      AuxSprite* sprite;
      Vec3 pos;
      s32 j;

      p->elems[i].flags = 4;
      switch (VM_GetNamedArgValue('t', 0)) {
        case 0: {
          p->elems[i].plttBase = 73;
          OtenkoGuide_RequestState(p, 1, 1);
          OtenkoPanel_SetCallback(&p->elems[i], OtenkoPanel_08224dd0);
          break;
        }
        case 1: {
          p->elems[i].flags |= 8;
          p->elems[i].plttBase = 73;
          OtenkoGuide_RequestState(p, 4, 1);
          OtenkoPanel_SetCallback(&p->elems[i], OtenkoPanel_08224f74);
          break;
        }
        case 2: {
          p->elems[i].flags |= 16;
          p->elems[i].plttBase = 76;
          p->elems[i].sprite.poseIdx = 1;
          OtenkoGuide_RequestState(p, 1, 1);
          OtenkoPanel_SetCallback(&p->elems[i], OtenkoPanel_08224dd0);
          break;
        }
      }
      sprite = &p->elems[i].sprite;
      p->elems[i].unk_ae = VM_GetNamedArgValue('r', 0);
      p->elems[i].stopSound = VM_GetNamedArgValue('A', 0);
      if (VM_SeekToNamedArg('R')) {
        Map_GetZoneMin(VM_GetValue(), (u16*)&pos);
      } else {
        if (!VM_SeekToNamedArg('p')) {
          return;
        }
        pos.x = VM_GetValue();
        pos.y = VM_GetValue() - 64;
        pos.z = VM_GetValue();
      }
      if (p->elems[i].unk_ae != 0) {
        p->elems[i].pos.x = pos.x;
        sprite->pos.x = pos.x;
        p->elems[i].pos.y = pos.y;
        sprite->pos.y = pos.y;
        p->elems[i].pos.z = pos.z;
        sprite->pos.z = pos.z - 128;
      } else {
        p->elems[i].pos.x = pos.x;
        sprite->pos.x = pos.x - 128;
        p->elems[i].pos.y = pos.y;
        sprite->pos.y = pos.y;
        p->elems[i].pos.z = pos.z;
        sprite->pos.z = pos.z;
      }
      sprite->pos.x += 60;
      sprite->pos.z += 60;
      sprite->pos.y += 84;
      sprite->priority = 2;
      if (VM_SeekToNamedArg('m')) {
        p->elems[i].unk_b4 = 0;
        while (VM_GetPC() != NULL) {
          (&p->elems[i].zoneID)[p->elems[i].unk_b4] = VM_GetValue();
          p->elems[i].unk_b4++;
        }
      } else {
        p->elems[i].unk_b4 = 1;
        p->elems[i].zoneID = GetZoneAt(&pos);
      }
      if (VM_SeekToNamedArg('C')) {
        p->elems[i].unk_a0 = VM_GetValue();
      } else {
        p->elems[i].unk_a0 = 0;
      }
      if (VM_SeekToNamedArg('a')) {
        p->elems[i].unk_a4 = VM_GetValue();
      } else {
        p->elems[i].unk_a4 = 0;
      }
      p->elems[i].unk_ca = VM_GetNamedArgValue('u', 0);
      if (p->elems[i].unk_ae == 0) {
        p->unk_f1e = -64;
      } else {
        p->elems[i].sprite.flags |= SPRFLAG_XFLIP;
        p->unk_f1e = 64;
      }
      for (j = 0; j < p->elems[i].unk_b4; j++) {
      }
      return;
    }
  }
#else
  INCFUNC("asm/func/Cmd_PlaceOtenkoPanels.inc");
#endif
}

// 0x5B01, 位置・パレット・終わったときのスクリプト ('.c') を決め, 点から花に開くアニメで現れる
void Cmd_ShowOtenkoGuide(void) {
  OtenkoGuide* p = gOtenkoGuide;
  AuxSprite* sprite;

  if (p == NULL) {
    p = OtenkoGuide_Create(0xBB34, 0);
  }

  sprite = &p->sprite;
  Video_SetAuxSpritePltt(&p->gfx, 279);
  p->sprite.priority = 0;
  p->gestureFlags = 0;
  p->unk_f46 = VM_GetValue();
  p->unk_f29[0] = VM_GetNamedArgValue('r', 0);
  p->stopSound = VM_GetNamedArgValue('A', 0);
  if (VM_SeekToNamedArg('p')) {
    sprite->pos.x = p->pos.x = VM_GetValue();
    sprite->pos.y = p->pos.y = VM_GetValue();
    sprite->pos.z = p->pos.z = VM_GetValue();
  } else {
    Player* player = p->player;

    p->pos.x = player->mover.pos.x;
    sprite->pos.x = player->mover.pos.x;
    player = p->player;
    p->pos.y = player->mover.pos.y;
    sprite->pos.y = player->mover.pos.y;
    player = p->player;
    p->pos.z = player->mover.pos.z;
    sprite->pos.z = player->mover.pos.z;
  }
  if (VM_SeekToNamedArg('c')) {
    p->scriptID = VM_GetValue();
  }
  p->unk_f21 = VM_GetNamedArgValue('s', 0);
  if (!IS_NIGHT()) {
    p->isDaytime = 1;
  } else {
    p->isDaytime = 0;
  }
  ParticleShadow_Hide(&p->shadow);
  p->sprite.flags |= SPRFLAG_HIDDEN;
  switch (p->unk_f21) {
    case 0: {
      OtenkoGuide_RequestState(p, 0, 0);
      break;
    }
    case 1: {
      OtenkoGuide_RequestState(p, 2, 1);
      break;
    }
    case 2: {
      OtenkoGuide_RequestState(p, 2, 2);
      break;
    }
    case 3: {
      OtenkoGuide_RequestState(p, 2, 3);
      break;
    }
    case 4: {
      OtenkoGuide_RequestState(p, 2, 5);
      break;
    }
    case 5: {
      OtenkoGuide_RequestState(p, 2, 6);
      break;
    }
  }
}

// 残差8命令, 原典は pltt1 へのコピーで u16 切り捨て (0xFFFF) をプール定数で作る (src/pile_driver.c と同じ事例, agbcc はこれを畳む), その1レジスタ分の差で p/sprite の割当も r6,r8 と r7,r5 でずれる
NON_MATCH s32 OtenkoGuide_Init(OtenkoGuide* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;
  rgb555* src;
  s32 i;

  gOtenkoGuide = p;
  p->player = gPlayerPtr[0];
  sprite = &p->sprite;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_OTENKO);
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_OTENKO_00);
  AuxSprite_Add(sprite, gfx, 0);
  nop_0822a4f8(sprite, -8, -19);
  sprite->priority = 0;
  sprite->flags = SPRFLAG_HIDDEN | SPRFLAG_AFFINE;
  ParticleShadow_Init(&p->shadow, &sprite->pos, 0);
  ParticleShadow_Hide(&p->shadow);
  p->bobStep = 1;
  p->bobTimer = 0;
  p->unk_e3c = 0;
  src = p->gfx.pltt;
  p->plttSrc = src;
  for (i = 0; i < 16; i++) {
    p->pltt2[i] = src[i];
    p->pltt1[i] = src[i];
  }
  src += 16;
  for (i = 0; i < 16; i++) {
    p->pltt0[i] = src[i];
  }
  p->animVariant = 0;
  p->moveAngle = 0;
  p->animXflip = 0;
  for (i = 0; i < 16; i++) {
    OtenkoPanel* elem = &p->elems[i];

    Video_GetAuxSprite(&elem->gfx, SPRITE_HINT_PANEL);
    AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
    nop_0822a4f8(&elem->sprite, -8, -16);
    elem->sprite.flags = SPRFLAG_HIDDEN;
    elem->index = i;
    elem->flags = OTENKOPANEL_FLAG_UNK_1;
    elem->callback = OtenkoPanel_CallbackNone;
    elem->flags |= OTENKOPANEL_FLAG_UNK_0;
  }
  p->updateCallback = NULL;
  p->stepCallback = NULL;
  sprite->pos.x = 0, sprite->pos.y = 0, sprite->pos.z = 0;
  p->unk_e88 = 0;
  p->moveDeltaY = 0;
  p->moveDeltaX = 0;
  p->dozeBaseY = 0;
  p->targetX = 25;
  p->targetY = 102;
  p->targetZ = 0;
  p->unk_f1a = 200;
  if (Mover_FindByID_Proxy(p->unk_f46) == NULL) {
    Mover_Init(&p->unk_e40, p->unk_f46, &p->pos, 0, 7, p);
  }
  p->frameCounter = 0;
  return 0;
#else
  INCFUNC("asm/func/OtenkoGuide_Init.inc");
#endif
}

OtenkoGuide* OtenkoGuide_Create(u32 val, u32 _) {
  OtenkoGuide* p;

  if (gOtenkoGuide != NULL) {
    return gOtenkoGuide;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(OtenkoGuide));
  if (p != NULL) {
    p->unk_f46 = val;
    SetEntityRoutine(p, OtenkoGuide_Update, OtenkoGuide_Destroy);
    if (OtenkoGuide_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
