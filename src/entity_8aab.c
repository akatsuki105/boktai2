#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"
#include "vm.h"

struct Entity8AAB;

// パレットの補間に使う色, 各チャンネルは 0..31
typedef struct Rgb8 {
  s8 r;
  s8 g;
  s8 b;
} Rgb8;

typedef u8 E8AABElemFlags;
#define E8AABFLAG_UNK_0 (1 << 0)
#define E8AABFLAG_UNK_1 (1 << 1)
#define E8AABFLAG_UNK_2 (1 << 2)

typedef struct Entity8AABElem {
  AuxSprite sprite;                                              // 0x00
  AuxSpriteGfx gfx;                                              // 0x2C, SPRITE_HINT_PANEL
  Vec3 pos;                                                      // 0x48, プレイヤーとの相対角度を求めるときの基点
  u8 unk_50[0xA0 - 0x50];                                        // 0x50, このモジュールのどの関数も読み書きしない
  u32 unk_a0;                                                    // 0xA0, '.C'
  u32 unk_a4;                                                    // 0xA4, '.a'
  void (*callback)(struct Entity8AAB*, struct Entity8AABElem*);  // 0xA8, 代入のみで呼び出し箇所が見つかっていない
  u8 index;                                                      // 0xAC, elems 内の自分の添字
  E8AABElemFlags flags;                                          // 0xAD, see E8AABFLAG_*
  u8 unk_ae;                                                     // 0xAE, 0 かどうかでポーズと向きの符号を選ぶ
  bool8 stopSound;                                               // 0xAF, Entity8AAB の同名フィールドへ写される
  u8 unk_b0;                                                     // 0xB0, 0 から 10 までを往復するカウンタ
  u8 unk_b1[3];                                                  // 0xB1, まだ未解析
  s32 unk_b4;                                                    // 0xB4
  ZoneID32 zoneID;                                               // 0xB8, gStat->zoneID (エリアID) と比べる
  u8 unk_bc[0xCA - 0xBC];                                        // 0xBC, まだ未解析
  u8 unk_ca;                                                     // 0xCA
  u8 unk_cb;                                                     // 0xCB, 0 になるまで毎フレーム減るカウンタ
  u16 plttBase;                                                  // 0xCC, gObjPlttData のパレット行の基準, +0/+1/+2 の行を使う
  u8 unk_ce[2];                                                  // 0xCE, まだ未解析
  s32 unk_d0;                                                    // 0xD0
  u8 unk_d4;                                                     // 0xD4, 0 か 1 が入る, 読み手は見つかっていない
  u8 unk_d5[3];                                                  // 0xD5, まだ未解析
} Entity8AABElem;
static_assert(sizeof(Entity8AABElem) == 216);

typedef struct Entity8AAB {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  Player* player;                              // 0x018, _Init が gPlayerPtr[0] を入れる
  Entity8AABElem elems[16];                    // 0x01C, _Init が16個ぶん Video_GetAuxSprite / AuxSprite_Add する
  AuxSprite sprite;                            // 0xD9C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx;                            // 0xDC8, SPRITE_OTENKO_00
  AuxAnimState anim;                           // 0xDE4
  ParticleShadow shadow;                       // 0xDF4, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
  AuxAnimFile* animFile;                       // 0xE34, ANIM_OTENKO
  u16 unk_e38;                                 // 0xE38, _Init が 0 を入れる
  s8 unk_e3a;                                  // 0xE3A, _Init が 1 を入れる
  u8 unk_e3b;                                  // 0xE3B, まだ未解析
  u16 unk_e3c;                                 // 0xE3C, _Init が 0 を入れる
  u8 unk_e3e[2];                               // 0xE3E, まだ未解析
  Mover unk_e40;                               // 0xE40, _Destroy が Mover_Unlink に渡す
  s16 unk_e84;                                 // 0xE84, _Init が書き込む
  s16 unk_e86;                                 // 0xE86, _Init が書き込む
  s16 unk_e88;                                 // 0xE88, _Init が書き込む
  u8 unk_e8a[2];                               // 0xE8A, まだ未解析
  s16 unk_e8c;                                 // 0xE8C, _Init が 0x19 を入れる
  s16 unk_e8e;                                 // 0xE8E, _Init が 0x66 を入れる
  s16 unk_e90;                                 // 0xE90, _Init が 0 を入れる
  u8 unk_e92[2];                               // 0xE92, まだ未解析
  Vec3 startPos;                               // 0xE94
  WorldPos pos;                                // 0xE9C, unk_e40.pos へ写される, 既定はプレイヤーの座標
  rgb555 pltt0[16];                            // 0xEA4, _Init が gfx.pltt の 0x10..0x1F 番を写す
  rgb555 pltt1[16];                            // 0xEC4, _Init が gfx.pltt の 0x00..0x0F 番を写す
  rgb555 pltt2[16];                            // 0xEE4, pltt1 と pltt0 の補間結果, 差し替え中の gfx.pltt
  rgb555* plttSrc;                             // 0xF04, gfx.pltt の写し
  s16 unk_f08;                                 // 0xF08
  u16 unk_f0a;                                 // 0xF0A
  u32 scriptID;                                // 0xF0C, 一度実行したら 0 に戻す
  s32 unk_f10;                                 // 0xF10, '.p'
  bool8 unk_f14;                               // 0xF14
  u8 unk_f15;                                  // 0xF15, まだ未解析
  u16 substate : 4;                            // 0xF16, bit0-3, PTR_ARRAY_085b0100 の添字, 0 なら _Update が何もしない
  u16 state : 12;                              // 0xF16, bit4-15, PTR_ARRAY_085b00c4 の添字
  u16 unk_f18;                                 // 0xF18, substate の退避先
  u16 unk_f1a;                                 // 0xF1A, _Init が 200 を入れる
  s16 unk_f1c;                                 // 0xF1C, _Init が 0 を入れる
  s16 unk_f1e;                                 // 0xF1E
  u8 unk_f20;                                  // 0xF20, bit0 は state を変えた印
  u8 unk_f21;                                  // 0xF21, まだ未解析
  u8 unk_f22;                                  // 0xF22, _Init が 0 を入れる
  s8 unk_f23;                                  // 0xF23, '.d=-1'
  u8 unk_f24;                                  // 0xF24, まだ未解析
  s8 unk_f25;                                  // 0xF25, まだ未解析
  bool8 stopSound;                             // 0xF26, '.A', 立っていると停止時にEntityとBGMも止める
  u8 unk_f27;                                  // 0xF27, _Init が 0 を入れる
  u8 unk_f28;                                  // 0xF28, '.r'
  u8 unk_f29[2];                               // 0xF29, まだ未解析
  u8 unk_f2b;                                  // 0xF2B
  u8 unk_f2c[0xF32 - 0xF2C];                   // 0xF2C, まだ未解析
  u8 unk_f32;                                  // 0xF32, '.p'
  u8 unk_f33;                                  // 0xF33, '.u'
  u8 unk_f34[0xF36 - 0xF34];                   // 0xF34, まだ未解析
  u16 unk_f36;                                 // 0xF36, _Init が 0 を入れる
  u8 unk_f38;                                  // 0xF38, まだ未解析
  bool8 unk_f39;                               // 0xF39, 何かボタンが押された
  u16 unk_f3a;                                 // 0xF3A, 最後に要求された state
  u16 unk_f3c;                                 // 0xF3C
  s16 unk_f3e;                                 // 0xF3E
  u16 unk_f40;                                 // 0xF40
  u8 savedCmdIdx;                              // 0xF42, anim.cmdIdx の退避先
  u8 savedTick;                                // 0xF43, anim.tick の退避先
  u8 stepTimer;                                // 0xF44, 0 になると stepCallback を NULL にする
  u8 unk_f45;                                  // 0xF45, まだ未解析
  u16 unk_f46;                                 // 0xF46, _Destroy が Mover_FindByID_Proxy に渡す ID
  void (*unk_f48)(struct Entity8AAB*);         // 0xF48
  void (*unk_f4c)(struct Entity8AAB*);         // 0xF4C
  void (*updateCallback)(struct Entity8AAB*);  // 0xF50, _Update が最初に呼ぶ, 処理が終わると自分で NULL にする
  void (*stepCallback)(struct Entity8AAB*);    // 0xF54, _Update が updateCallback の後に呼ぶ, 次の手順へ自分を差し替えていく
  s32 unk_f58;                                 // 0xF58
  u32 frameCounter;                            // 0xF5C, _Update が毎フレーム増やす
} Entity8AAB;
static_assert(sizeof(Entity8AAB) == 3936);

IWRAM_DATA Entity8AAB* gEntity8AAB = NULL;  // 0x03000248

void FUN_080a6e88(bool32 stopSound);
s32 FUN_08015d3c(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8);
s32 Entity080146e0_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 param_10, s32 param_11);
void FUN_080a6edc(void);
void Map_GetZoneMin(u16 id, u16* out);
Entity8AAB* Entity8AAB_Create(u32 val, u32 _);
void Entity8AAB_Pause(Entity8AAB* p);
void FUN_08223cdc(Entity8AAB* p);
void FUN_08223d00(Entity8AAB*);
void FUN_08223d20(Entity8AAB*);
void FUN_08222d60(Entity8AAB* p);
void FUN_08222f0c(Entity8AAB* p);
void FUN_08223154(Entity8AAB* p);
void FUN_08223374(Entity8AAB* p);
void FUN_08223ad0(Entity8AAB* p);
void FUN_08223bf0(Entity8AAB* p);
void Entity8AAB_ScaleUp(Entity8AAB* p);
void FUN_08224dd0(Entity8AAB* p, Entity8AABElem* elem);
void FUN_08224f14(Entity8AAB* p, Entity8AABElem* elem);
void FUN_08224e10(Entity8AAB* p, Entity8AABElem* elem);
void FUN_08224f74(Entity8AAB* p, Entity8AABElem* elem);

// flag が立っていれば下ろして TRUE を返す
static inline bool8 Entity8AABElem_ConsumeFlag(Entity8AABElem* elem, E8AABElemFlags flag) {
  if (TEST_FLAGS(elem->flags, flag)) {
    CLEAR_FLAGS(elem->flags, flag);
    return TRUE;
  }
  return FALSE;
}

// state が変わった直後の最初の更新だけ TRUE を返す
static inline bool8 Entity8AAB_ConsumeEntered(Entity8AAB* p) {
  if (TEST_FLAGS(p->unk_f20, 1)) {
    CLEAR_FLAGS(p->unk_f20, 1);
    p->unk_f14 = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 角度をアニメーションの向きと左右反転に変換して, 8方向の向きを返す
static inline s32 Entity8AAB_AngleToAnimDir(s16 angle, u8* animDir, u8* xflip) {
  while (angle < 0) {
    angle += 256;
  }
  while (angle > 255) {
    angle -= 256;
  }
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
static inline void Entity8AABElem_SetCallback(Entity8AABElem* elem, void (*callback)(struct Entity8AAB*, struct Entity8AABElem*)) {
  elem->callback = callback;
  SET_FLAGS(elem->flags, E8AABFLAG_UNK_0);
}

// substate を退避して state を要求する
static inline void Entity8AAB_RequestState(Entity8AAB* p, u16 substate, u16 state) {
  p->unk_f18 = p->substate;
  p->substate = substate;
  p->state = state;
  if (p->unk_f18 == 3 && p->substate == 3) {
    p->savedCmdIdx = p->anim.cmdIdx;
    p->savedTick = p->anim.tick;
  }
  SET_FLAGS(p->unk_f20, 1);
}

#define IS_NIGHT() (gClock.spanOfTime == TIME_UNK5 || gClock.spanOfTime == TIME_NIGHT || gClock.spanOfTime == TIME_UNK4)

void FUN_08222cd4(void) { gEntity8AAB = NULL; }

void FUN_08222ce0(Entity8AAB* p) {
  p->unk_f08 = 0;
  p->unk_f0a = 50;
  Video_SetAuxSpritePltt(&p->gfx, 280);
  p->plttSrc = p->gfx.pltt;
  p->gfx.pltt = p->pltt2;
  if (p->substate == 2) {
    p->unk_f48 = FUN_08222f0c;
  } else {
    p->unk_f48 = FUN_08222d60;
  }
}

// pltt1 から pltt0 へパレットを補間する
void FUN_08222d60(Entity8AAB* p) {
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
    cur.r = Div((to.r - from.r) * p->unk_f08, p->unk_f0a) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->unk_f08, p->unk_f0a);
    cur.b = Div((to.b - from.b) * p->unk_f08, p->unk_f0a) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (++p->unk_f08 > p->unk_f0a) {
    p->unk_f48 = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 280);
    p->gfx.pltt = p->plttSrc;
  }
}

// pltt1 から pltt0 へパレットを補間し, 終わったらスクリプトを実行する
void FUN_08222f0c(Entity8AAB* p) {
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
    cur.r = Div((to.r - from.r) * p->unk_f08, p->unk_f0a) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->unk_f08, p->unk_f0a);
    cur.b = Div((to.b - from.b) * p->unk_f08, p->unk_f0a) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (++p->unk_f08 > p->unk_f0a) {
    p->unk_f48 = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 280);
    p->gfx.pltt = p->plttSrc;
    {
      s32* script = &p->unk_f10;
      s32 id = *script;

      if (id != 0) {
        *script = 0;
        VM_ExecByID(id, NULL);
      }
    }
  }
}

void FUN_082230d0(Entity8AAB* p) {
  s32 i;
  rgb555* src;
  rgb555* dst;

  p->unk_f08 = 50;
  p->unk_f0a = 50;
  Video_SetAuxSpritePltt(&p->gfx, 279);
  p->plttSrc = p->gfx.pltt;
  Video_SetAuxSpritePltt(&p->gfx, 280);
  src = p->gfx.pltt;
  dst = p->pltt2;
  for (i = 0; i < 16; i++) {
    *dst++ = *src++;
  }
  p->gfx.pltt = p->pltt2;
  p->unk_f48 = FUN_08223154;
}

// pltt1 から pltt0 へパレットを補間する
void FUN_08223154(Entity8AAB* p) {
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
    cur.r = Div((to.r - from.r) * p->unk_f08, p->unk_f0a) + from.r;
    cur.g = from.g + Div((to.g - from.g) * p->unk_f08, p->unk_f0a);
    cur.b = Div((to.b - from.b) * p->unk_f08, p->unk_f0a) + from.b;
    p->pltt2[i] = (cur.b << 10) | (cur.g << 5) | cur.r;
  }

  if (--p->unk_f08 < 0) {
    p->unk_f48 = NULL;
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->gfx.pltt = p->plttSrc;
    Entity8AAB_RequestState(p, 2, 13);
  }
}

void FUN_08223374(Entity8AAB* p) {
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

void FUN_08223470(Entity8AAB* p, Entity8AABElem* elem) {
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
      if (abs(elem->pos.y - p->player->mover.pos.y) < 120 && (gInput[0].pressed & A_BUTTON) && !(gEntityDisableFlags & ENTITY_DISABLE_2) && p->player->mode != 4) {
        if (elem->unk_a4 != 0) {
          VM_ExecByID(elem->unk_a4, NULL);
        }
        p->sprite.pos.x = elem->sprite.pos.x;
        p->sprite.pos.y = elem->sprite.pos.y;
        p->sprite.pos.z = elem->sprite.pos.z;
        p->scriptID = elem->unk_a0;
        p->stopSound = elem->stopSound;
        if (elem->flags & 0x10) {
          Entity8AAB_RequestState(p, 1, 3);
          Entity8AABElem_SetCallback(elem, FUN_08224f14);
          Entity8AAB_Pause(p);
        } else {
          Entity8AAB_RequestState(p, 1, 2);
          Entity8AABElem_SetCallback(elem, FUN_08224e10);
          FUN_08223cdc(p);
        }
      }
    }
  }
}

// 264/266 命令, r10 まで使う局所の持ち方が違う, 下書き段階
// 266/266 命令, elem と dz の r5/r4 の入れ替わりだけ
NON_MATCH void FUN_08223748(Entity8AAB* p) {
#ifdef NONMATCHING_C
  s32 i;

  p->unk_f45 = 0xFF;
  for (i = 0; i < 16; i++) {
    Entity8AABElem* elem = &p->elems[i];

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
    Entity8AABElem* elem = &p->elems[i];

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
  INCFUNC("asm/func/FUN_08223748.inc");
#endif
}

void Entity8AAB_Pause(Entity8AAB* p) { FUN_080a6e88(p->stopSound); }

void Entity8AAB_RestoreAnimState(Entity8AAB* p) {
  p->anim.cmdIdx = p->savedCmdIdx;
  p->anim.tick = p->savedTick;
}

void Entity8AAB_ScaleUp(Entity8AAB* p) {
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

void FUN_082239fc(Entity8AAB* p) {
  if (p->sprite.pos.x == 25 && p->sprite.pos.z == 0 && abs(p->sprite.pos.y - 102) < 10) {
    p->unk_f58 = 0;
    p->unk_f4c = FUN_08223ad0;
    if (IS_NIGHT()) {
      p->unk_f40 = 1800;
    } else {
      p->unk_f40 = 10800;
    }
    if (p->unk_f2b && p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = Entity8AAB_ScaleUp;
    }
  } else {
    p->unk_f4c = NULL;
  }
}

// 残差は pos 周りのアドレスを作るレジスタと state だけ書き換える行の形
NON_MATCH void FUN_08223ad0(Entity8AAB* p) {
#ifdef NONMATCHING_C
  if (*(u32*)gInput != 0) {
    p->unk_f58 = 0;
    if (IS_NIGHT()) {
      p->unk_f40 = 1800;
    } else {
      p->unk_f40 = 10800;
    }
  }
  if (++p->unk_f58 > p->unk_f40 && p->unk_f14) {
    p->unk_f39 = FALSE;
    p->unk_f3a = p->state;
    p->state = 5;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    p->unk_f4c = FUN_08223bf0;
    p->unk_e38 = 0;
    p->unk_f36 = p->sprite.pos.y;
  }
#else
  INCFUNC("asm/func/FUN_08223ad0.inc");
#endif
}

void FUN_08223bf0(Entity8AAB* p) {
  if (*(u32*)gInput != 0) {
    p->unk_f39 = TRUE;
    p->unk_e38 = 0;
  }
  if (p->unk_f39 && p->unk_f14) {
    p->sprite.pos.y = p->unk_f36 - 1;
    p->unk_f58 = 0;
    p->unk_f4c = FUN_08223ad0;
    Entity8AAB_RequestState(p, 3, p->unk_f3a);
  }
}

void FUN_08223cdc(Entity8AAB* p) {
  PlaySound_082406e0(SE_INFO);
  p->stepCallback = FUN_08223d00;
}

void FUN_08223d00(Entity8AAB* p) {
  p->stepTimer = 12;
  p->stepCallback = FUN_08223d20;
}

void FUN_08223d20(Entity8AAB* p) {
  if (--p->stepTimer == 0) {
    p->stepCallback = NULL;
    if (gClock.spanOfTime >= TIME_MORNING && gClock.spanOfTime <= TIME_SUNSET) {
      PlaySound_082406e0(VO_OTENKO_OTNK);
    } else {
      Time_GetHour();
    }
  }
}

void Cmd_A99F(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 1);
}

void Cmd_0447(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 2);
}

void Cmd_03CA(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 3);
}

void Cmd_225B(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 4);
}

void Cmd_FA5D(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 5);
}

void Cmd_B838(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 6);
}

void Cmd_667C(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 7);
}

void Cmd_3E17(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 8);
}

void Cmd_AB9C(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p != NULL) {
    p->unk_f32 = VM_GetNamedArgValue('p', 0);
    if (!(p->sprite.flags & SPRFLAG_HIDDEN)) {
      Entity8AAB_RequestState(p, 3, 9);
    }
  }
}

void FUN_082242f4(s32 kind) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  if (kind == 12) {
    PlaySound_082406e0(VO_OTENKO_OTNK);
  } else if (kind == 14) {
    FUN_080a6edc();
  } else {
    Entity8AAB_RequestState(p, 3, kind);
    p->unk_f3a = p->state;
  }
}

void FUN_082243bc(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 10);
}

void FUN_08224458(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 11);
}

void FUN_082244f4(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 3, 13);
}

void Cmd_3D17(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  if (VM_SeekToNamedArg('t')) {
    p->unk_e8c = VM_GetValue();
    p->unk_e8e = VM_GetValue() + 160;
    p->unk_e90 = VM_GetValue();
  } else {
    p->unk_e8c = p->player->mover.pos.x;
    p->unk_e8e = p->player->mover.pos.y + 160;
    p->unk_e90 = p->player->mover.pos.z;
  }
  p->unk_f23 = VM_GetNamedArgValue('d', -1);
  p->scriptID = VM_GetNamedArgValue('p', 0);
  Entity8AAB_RequestState(p, 2, 10);
}

// 0xD0CE
void Cmd_D0CE(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  p->unk_f33 = VM_GetNamedArgValue('u', 0);
  p->scriptID = VM_GetNamedArgValue('p', 0);
  FUN_08223374(p);
  Entity8AAB_RequestState(p, 2, 8);
}

// 0x1A35
void Cmd_1A35(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->scriptID = VM_GetNamedArgValue('p', 0);
  if (VM_SeekToNamedArg('t')) {
    p->unk_e8c = VM_GetValue();
    p->unk_e8e = VM_GetValue();
  } else {
    p->unk_e8e = 0;
    p->unk_e8c = 0;
  }
  Entity8AAB_RequestState(p, 2, 9);
}

// 0x69CD
void Cmd_69CD(void) {
  Entity8AAB* p = gEntity8AAB;
  u8 dir;
  bool8 xflip;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  dir = VM_GetNamedArgValue('d', 0);
  xflip = FALSE;
  dir &= 7;
  p->unk_f24 = dir;
  if (dir > 4) {
    dir = 8 - dir;
    xflip = TRUE;
  }
  p->unk_f22 = dir;
  p->unk_f27 = xflip;
  AuxAnim_SetAnim(&p->anim, p->animFile, 0, p->unk_f22, p->unk_f27);
  Entity8AAB_RequestState(p, 2, 0);
}

// 0x7F67
void Cmd_7F67(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  Entity8AAB_RequestState(p, 2, 11);
  p->unk_f10 = VM_GetNamedArgValue('p', 0);
}

void Cmd_7F44(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  p->unk_f46 = VM_GetValue();
  Entity8AAB_RequestState(p, 2, 12);
  p->unk_f10 = VM_GetNamedArgValue('p', 0);
}

// 0xA3B3
void Cmd_A3B3(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 2, 7);
}

// 0x5276
void Cmd_5276(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
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
  Entity8AAB_RequestState(p, 2, 14);
}

// 0xD169
void Cmd_D169(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) {
      return;
    }
  }
  Entity8AAB_RequestState(p, 2, 15);
}

// 0xB50D
s32 Cmd_B50D(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return 0;
  }
  return p->unk_f24;
}

// 0x48B3
void Entity8AAB_SetPriorityScripted(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->sprite.priority = VM_GetNamedArgValue('p', 0);
}

// 0x30A3
void Cmd_30A3(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->unk_f28 = VM_GetNamedArgValue('r', 0);
}

void Entity8AAB_ElemCallbackNone(Entity8AAB* _, Entity8AABElem* __) {}

// 残差は先頭の引数の複写 2 命令の順序だけ
NON_MATCH void FUN_08224dd0(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  if (Entity8AABElem_ConsumeFlag(elem, E8AABFLAG_UNK_0)) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  FUN_08223470(p, elem);
#else
  INCFUNC("asm/func/FUN_08224dd0.inc");
#endif
}

// 残差は先頭の引数の複写 2 命令の順序だけ
NON_MATCH void FUN_08224e10(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  if (Entity8AABElem_ConsumeFlag(elem, E8AABFLAG_UNK_0)) {
    p->unk_f58 = 10;
    if (!IS_NIGHT()) {
      p->unk_f2b = TRUE;
    } else {
      p->unk_f2b = FALSE;
    }
    p->unk_f33 = elem->unk_ca;
  }
  if (--p->unk_f58 == -1) {
    Entity8AAB_RequestState(p, 2, 4);
  }
#else
  INCFUNC("asm/func/FUN_08224e10.inc");
#endif
}

// 残差は先頭の引数の複写の順序と scriptID のレジスタ
NON_MATCH void FUN_08224f14(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  if (Entity8AABElem_ConsumeFlag(elem, E8AABFLAG_UNK_0)) {
    u32 scriptID = p->scriptID;

    if (scriptID != 0) {
      p->scriptID = 0;
      VM_ExecByID(scriptID, NULL);
    }
    elem->callback = FUN_08224dd0;
    SET_FLAGS(elem->flags, E8AABFLAG_UNK_0);
  }
#else
  INCFUNC("asm/func/FUN_08224f14.inc");
#endif
}

void FUN_08224f74(Entity8AAB* p, Entity8AABElem* elem) {
  if (Entity8AABElem_ConsumeFlag(elem, E8AABFLAG_UNK_0)) {
    Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 2);
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

// 199/199 命令, 定数 3 を写して使う r2 と r1 の割当だけが違う
NON_MATCH void FUN_08224fb8(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  Entity8AAB_ConsumeEntered(p);
  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    p->sprite.pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08224fb8.inc");
#endif
}

void FUN_0822517c(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.flags &= ~SPRFLAG_SCREEN_COORD;
    p->sprite.flags &= ~SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    p->sprite.pos.y += 160;
    p->pos.y = p->sprite.pos.y;
    PlaySound_082406e0(SE_INFO);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
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

void FUN_082253e4(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_e8c = 25;
    p->unk_e8e = 102;
    p->unk_e90 = 0;
    p->unk_f15 = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_INFO);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    u32* script;
    s32 scriptID;

    Entity8AAB_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
}

void FUN_08225658(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_e8c = 25;
    p->unk_e8e = 102;
    p->unk_e90 = 0;
    p->unk_f15 = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->unk_f33 = 0;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    FUN_08223374(p);
    p->sprite.pos.y += 8;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_INFO);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    p->state = 8;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
  }
}

void FUN_082258bc(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_e8c = 25;
    p->unk_e8e = 102;
    p->unk_e90 = 0;
    p->unk_f15 = 1;
    AuxAnim_SetAnim(&p->anim, p->animFile, 1, 0, p->unk_f29[0]);
    p->unk_f33 = 0;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    FUN_08223374(p);
    p->sprite.pos.y += 8;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Hide(&p->shadow);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    p->state = 8;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
  }
}

void FUN_08225b18(Entity8AAB* p) {
  u32* script;
  s32 scriptID;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.flags &= ~SPRFLAG_SCREEN_COORD;
    p->sprite.flags &= ~SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 64;
    p->sprite.scaleX = 64;
    p->sprite.pos.y += 160;
    p->pos.y = p->sprite.pos.y;
    ParticleShadow_Show(&p->shadow);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    AuxAnim_SetAnim(&p->anim, p->animFile, 0, 4, 0);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  script = &p->scriptID;
  scriptID = *script;
  if (scriptID != 0) {
    *script = 0;
    VM_ExecByID(scriptID, NULL);
  }
}

void FUN_08225d40(Entity8AAB* p) {
  u32* script;
  s32 scriptID;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
    p->sprite.scaleY = 127;
    p->sprite.scaleX = 127;
    ParticleShadow_Hide(&p->shadow);
    Entity8AAB_Pause(p);
    Video_SetAuxSpritePltt(&p->gfx, 279);
    p->state = 0;
    if (p->unk_f18 == 3 && p->substate == 3) {
      p->savedCmdIdx = p->anim.cmdIdx;
      p->savedTick = p->anim.tick;
    }
    SET_FLAGS(p->unk_f20, 1);
    AuxAnim_SetAnim(&p->anim, p->animFile, 0, 4, 0);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  script = &p->scriptID;
  scriptID = *script;
  if (scriptID != 0) {
    *script = 0;
    VM_ExecByID(scriptID, NULL);
  }
}

// 残差は movs r3, #15 の位置だけ
NON_MATCH void FUN_08225f50(Entity8AAB* p) {
#ifdef NONMATCHING_C
  if (Entity8AAB_ConsumeEntered(p)) {
    s32 i;
    Entity8AABElem* elem;

    FUN_080a6edc();
    ParticleShadow_Hide(&p->shadow);
    p->sprite.flags |= SPRFLAG_HIDDEN;
    Entity8AAB_RequestState(p, 1, 2);
    for (i = 0, elem = p->elems; i < 16; i++) {
      if (TEST_FLAGS(elem->flags, E8AABFLAG_UNK_2)) {
        elem->callback = FUN_08224dd0;
        SET_FLAGS(elem->flags, E8AABFLAG_UNK_0);
      }
      elem++;
    }
  }
#else
  INCFUNC("asm/func/FUN_08225f50.inc");
#endif
}

// 499/499 命令, sign の定数の置き場所が違う
NON_MATCH void FUN_08226048(Entity8AAB* p) {
#ifdef NONMATCHING_C
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f58 = 0;
    p->startPos.x = p->sprite.pos.x;
    p->startPos.y = p->sprite.pos.y;
    p->startPos.z = p->sprite.pos.z;
    p->unk_f15 = 0;
    {
      s32 sign = -1;

      if (p->frameCounter & 1) {
        sign = 1;
      }
      p->unk_f25 = sign;
    }
    ParticleShadow_Hide(&p->shadow);
    if (p->unk_f2b != 0 && p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = Entity8AAB_ScaleUp;
    }
    if (p->unk_f33 == 0) {
      p->unk_e8c = 25;
      p->unk_e8e = 102;
    } else if (IS_NIGHT()) {
      p->unk_e8c = 25;
      p->unk_e8e = 75;
    } else {
      p->unk_e8c = 25;
      p->unk_e8e = 92;
    }
    p->unk_e90 = 0;
  }

  p->unk_f1c = ArcTan2_8((s16)p->unk_e8c - p->sprite.pos.x, (s16)p->unk_e8e - p->sprite.pos.y) & 0xFF;
  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f58++ < 32) {
    s16 angle = p->unk_f1c - 16;
    u32 dir;

    while (angle < 0) {
      angle += 256;
    }
    while (angle > 255) {
      angle -= 256;
    }
    dir = ((angle - 16) >> 5) & 7;
    if (dir == 4) {
      p->unk_f22 = 0;
    } else if (dir == 0) {
      p->unk_f22 = 4;
    } else {
      if (dir > 3) {
        p->unk_f22 = dir - 4;
      } else {
        p->unk_f22 = 4 - dir;
      }
      p->unk_f27 = dir <= 3;
    }
    AuxAnim_SetAnim(&p->anim, p->animFile, p->unk_f15, p->unk_f22, p->unk_f27);
    p->sprite.pos.x = p->startPos.x + Div(((s16)p->unk_e8c - p->startPos.x) * p->unk_f58, 32);
    p->sprite.pos.y = p->startPos.y + Div(((s16)p->unk_e8e - p->startPos.y) * p->unk_f58, 32) + (s8)p->unk_f25 * (gSineTable[(p->unk_f58 & 63) * 4] >> 7);
  } else {
    u32* script;
    s32 scriptID;

    p->sprite.pos.x = p->unk_e8c;
    p->sprite.pos.y = p->unk_e8e;
    Entity8AAB_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
#else
  INCFUNC("asm/func/FUN_08226048.inc");
#endif
}

// 寝台の位置から目標地点へ揺れながら移動する
void FUN_08226520(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f58 = 0;
    p->startPos.x = p->sprite.pos.x;
    p->startPos.y = p->sprite.pos.y;
    p->startPos.z = p->sprite.pos.z;
    p->unk_e84 = (s16)p->unk_e8c - p->sprite.pos.x;
    p->unk_e86 = (s16)p->unk_e8e - p->sprite.pos.y;
    p->unk_f15 = 0;
    p->unk_f25 = (p->frameCounter & 1) ? 1 : -1;
    ParticleShadow_Hide(&p->shadow);
    if (p->sprite.scaleX != 127 && (p->sprite.flags & SPRFLAG_SCREEN_COORD)) {
      p->updateCallback = Entity8AAB_ScaleUp;
    }
  }

  p->unk_f1c = (u8)ArcTan2_8((s16)p->unk_e8c - p->sprite.pos.x, (s16)p->unk_e8e - p->sprite.pos.y);
  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f58++ >= 32) {
    u32* script;
    s32 scriptID;

    p->sprite.pos.x = p->unk_e8c;
    p->sprite.pos.y = p->unk_e8e;
    Entity8AAB_RequestState(p, 3, 1);
    script = &p->scriptID;
    scriptID = *script;
    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
  } else {
    Entity8AAB_AngleToAnimDir(p->unk_f1c - 16, &p->unk_f22, &p->unk_f27);
    AuxAnim_SetAnim(&p->anim, p->animFile, p->unk_f15, p->unk_f22, p->unk_f27);
    p->sprite.pos.x = p->startPos.x + Div(p->unk_e84 * p->unk_f58, 32);
    {
      s32 move = Div(p->unk_e86 * p->unk_f58, 32);
      s32 wave = SIN(p->unk_f58 * 4);
      s32 amp = p->unk_f25 * 30;

      amp *= wave;
      wave = amp >= 0 ? amp >> 12 : -(-amp >> 12);
      p->sprite.pos.y = p->startPos.y + move + wave;
    }
  }
}

// 682/679 命令, switch の各経路で &p->unk_e3a を作って持ち越す形だけが違う
NON_MATCH void FUN_08226990(Entity8AAB* p) {
#ifdef NONMATCHING_C
  s32 dx = (s16)p->unk_e8c - p->sprite.pos.x;
  s32 dz = (s16)p->unk_e90 - p->sprite.pos.z;
  bool8 entered;
  u16* timer;
  AuxSprite* sprite;
  AuxAnimState* anim;

  p->unk_f1c = (u8)ArcTan2_8(dx, dz);
  entered = Entity8AAB_ConsumeEntered(p);
  timer = &p->unk_e38;
  if (entered) {
    p->unk_f15 = 0;
    p->unk_f24 = (Entity8AAB_AngleToAnimDir(p->unk_f1c, &p->unk_f22, &p->unk_f27) - 4) & 7;
    p->unk_f38 = 0;
    ParticleShadow_Show(&p->shadow);
  }

  sprite = &p->sprite;
  if (((*timer)++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, p->unk_f15, p->unk_f22, p->unk_f27);
  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, anim);
  if (abs(dx) + abs(dz) < 10 && p->unk_f38 != 0) {
    p->sprite.pos.x = p->unk_e8c;
    p->sprite.pos.z = p->unk_e90;
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
        if (masked > 4) {
          dir = 8 - masked;
          xflip = TRUE;
        }
        anim = &p->anim;
        AuxAnim_SetAnim(anim, p->animFile, p->unk_f15, dir, xflip);
        p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, anim);
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
    s16* target = &p->unk_e8e;
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
    p->unk_e84 = Div(COS(p->unk_f1c), 500);
    p->unk_e88 = Div(SIN(p->unk_f1c), 500);
    p->sprite.pos.x += p->unk_e84;
    p->sprite.pos.z += p->unk_e88;
    p->pos.x = p->sprite.pos.x;
    p->pos.z = p->sprite.pos.z;
  }
#else
  INCFUNC("asm/func/FUN_08226990.inc");
#endif
}

void FUN_08226fd0(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 11;
    AuxAnim_SetAnim(&p->anim, p->animFile, 11, 0, 0);
    ParticleShadow_Show(&p->shadow);
    p->unk_f48 = FUN_08222ce0;
  }

  if (p->unk_f48 != NULL) {
    p->unk_f48(p);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    p->anim.cmdIdx = 1;
  }
}

void FUN_08227168(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 19;
    AuxAnim_SetAnim(&p->anim, p->animFile, 19, 0, 0);
    ParticleShadow_Show(&p->shadow);
    p->unk_f48 = FUN_082230d0;
  }

  if (p->unk_f48 != NULL) {
    p->unk_f48(p);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
}

void FUN_082272f0(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 18;
    AuxAnim_SetAnim(&p->anim, p->animFile, 18, 0, 0);
    ParticleShadow_Show(&p->shadow);
  }

  if (p->unk_f48 != NULL) {
    p->unk_f48(p);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    s32* script = &p->unk_f10;
    s32 scriptID = *script;

    if (scriptID != 0) {
      *script = 0;
      VM_ExecByID(scriptID, NULL);
    }
    if (p->unk_f14) {
      p->anim.cmdIdx = 1;
    }
  }
}

void FUN_08227498(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 12;
    AuxAnim_SetAnim(&p->anim, p->animFile, 12, 0, 0);
    Video_SetAuxSpritePltt(&p->gfx, 282);
    AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    p->sprite.priority = 3;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

// 439/435 命令, ループ外に定数を持つ形が違う, 下書き段階
NON_MATCH void FUN_08227608(Entity8AAB* p) {
#ifdef NONMATCHING_C
  u16* timer;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 13;
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

      FUN_08015d3c(pos, 1, 512, 48, 8, 8, 8, 4);
      FUN_08015d3c(pos, 1, 512, 48, 8, 8, 8, 4);
      FUN_08015d3c(pos, 1, 512, 48, 8, 8, 8, 4);
      FUN_08015d3c(pos, 1, 512, 48, 8, 8, 8, 4);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 32, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 64, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 96, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 128, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 160, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 192, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 224, 60, 10, 3, 10, 5, 60, 10);
      Entity080146e0_SpawnAtAngle(1, 3, pos, 256, 60, 10, 3, 10, 5, 60, 10);
      ParticleShadow_Hide(&p->shadow);
      p->sprite.flags |= SPRFLAG_HIDDEN;
      Entity8AAB_RequestState(p, 1, 2);
      for (i = 0; i < 16; i++) {
        if (p->elems[i].flags & 4) {
          p->elems[i].callback = FUN_08224dd0;
          p->elems[i].flags |= 1;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08227608.inc");
#endif
}

void FUN_082279e0(Entity8AAB* _) {}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_082279e4(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 2;
    AuxAnim_SetAnim(&p->anim, p->animFile, 2, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_082279e4.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_08227c14(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 3;
    AuxAnim_SetAnim(&p->anim, p->animFile, 3, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08227c14.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_08227e44(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 4;
    AuxAnim_SetAnim(&p->anim, p->animFile, 4, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08227e44.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_08228074(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 5;
    AuxAnim_SetAnim(&p->anim, p->animFile, 5, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08228074.inc");
#endif
}

void FUN_082282a4(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 6;
    AuxAnim_SetAnim(&p->anim, p->animFile, 6, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  switch (p->anim.cmdIdx & 7) {
    case 0:
    case 1:
    case 6:
    case 7: {
      p->unk_e3a = 1;
      break;
    }
    case 2:
    case 3:
    case 4:
    case 5: {
      p->unk_e3a = -1;
      break;
    }
  }

  if (Mod(p->anim.tick, 5) == 0) {
    p->sprite.pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_082284b8(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 7;
    AuxAnim_SetAnim(&p->anim, p->animFile, 7, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_082284b8.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_082286e8(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 8;
    AuxAnim_SetAnim(&p->anim, p->animFile, 8, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_082286e8.inc");
#endif
}

// 234/236 命令, switch を抜けた後で &p->unk_e3a を r1 に持ち越す形が作れない
NON_MATCH void FUN_08228918(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;

  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 9;
    AuxAnim_SetAnim(&p->anim, p->animFile, 9, 0, p->unk_f28);
    Entity8AAB_RestoreAnimState(p);
    ParticleShadow_Hide(&p->shadow);
    FUN_082239fc(p);
  }

  if (p->unk_f4c != NULL) {
    p->unk_f4c(p);
  }

  sprite = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (sprite->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    sprite->pos.y += p->unk_e3a;
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
#else
  INCFUNC("asm/func/FUN_08228918.inc");
#endif
}

// 248/248 命令, ループ前の定数 r3 の位置とレジスタの割当だけが違う
NON_MATCH void FUN_08228b48(Entity8AAB* p) {
#ifdef NONMATCHING_C
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 10;
    AuxAnim_SetAnim(&p->anim, p->animFile, 10, 0, p->unk_f28);
    ParticleShadow_Hide(&p->shadow);
    PlaySound_082406e0(SE_UNK_287);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    Entity8AABElem* elem;
    s32 i;

    if (p->unk_f32 != 0) {
      FUN_080a6edc();
    }
    p->sprite.flags |= SPRFLAG_HIDDEN;
    Entity8AAB_RequestState(p, 1, 2);
    elem = p->elems;
    for (i = 0; i < 16; i++) {
      if (elem->flags & 4) {
        elem->callback = FUN_08224dd0;
        elem->flags |= 1;
      }
      elem++;
    }
  }
#else
  INCFUNC("asm/func/FUN_08228b48.inc");
#endif
}

// 100/106 命令, switch の分岐ごとに unk_e3a のアドレスを作る形が未解決
NON_MATCH void FUN_08228d8c(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  s32 scaleX;
  s32 scaleY;

  if (Entity8AAB_ConsumeEntered(p)) {
    ParticleShadow_Hide(&p->shadow);
  }
  spr = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    spr->pos.y += p->unk_e3a;
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
NON_MATCH void FUN_08228e94(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  s32 scaleX;
  s32 scaleY;

  if (Entity8AAB_ConsumeEntered(p)) {
    ParticleShadow_Hide(&p->shadow);
  }
  spr = &p->sprite;
  if ((p->unk_e38++ & 3) == 0) {
    switch (p->anim.cmdIdx & 3) {
      case 0:
      case 3: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = 1;
        } else {
          p->unk_e3a = -8;
        }
        break;
      }
      case 1:
      case 2: {
        if (spr->flags & SPRFLAG_SCREEN_COORD) {
          p->unk_e3a = -1;
        } else {
          p->unk_e3a = 8;
        }
        break;
      }
    }
    spr->pos.y += p->unk_e3a;
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

void FUN_08228f9c(Entity8AAB* p) {
  if (Entity8AAB_ConsumeEntered(p)) {
    p->unk_f15 = 11;
    AuxAnim_SetAnim(&p->anim, p->animFile, 11, 0, p->unk_f28);
    ParticleShadow_Hide(&p->shadow);
    p->unk_f48 = FUN_08222ce0;
  }

  if (p->unk_f48 != NULL) {
    p->unk_f48(p);
  }

  p->unk_f14 = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->unk_f14) {
    p->anim.cmdIdx = 1;
  }
}

void FUN_0822913c(Entity8AAB* _) {}

// 112/121 命令, sp に局所を1つ持つ形と zoneID を歩くポインタが違う
NON_MATCH void FUN_08229140(Entity8AAB* p) {
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
  INCFUNC("asm/func/FUN_08229140.inc");
#endif
}

void FUN_08229238(Entity8AAB* p) {
  static void (*const PTR_ARRAY_085b0084[16])(Entity8AAB*) = {
      FUN_08224fb8,
      FUN_0822517c,
      FUN_082253e4,
      FUN_08225658,
      FUN_082258bc,
      FUN_08225b18,
      FUN_08225d40,
      FUN_08225f50,
      FUN_08226048,
      FUN_08226520,
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

void Entity8AAB_CallStateHandler(Entity8AAB* p) {
  static void (*const PTR_ARRAY_085b00c4[15])(Entity8AAB*) = {
      FUN_082279e0,
      FUN_082279e4,
      FUN_08227c14,
      FUN_08227e44,
      FUN_08228074,
      FUN_082282a4,
      FUN_082284b8,
      FUN_082286e8,
      FUN_08228918,
      FUN_08228b48,
      FUN_08228d8c,
      FUN_08228e94,
      NULL,
      FUN_08228f9c,
      NULL,
  };  // 0x085B00C4
  PTR_ARRAY_085b00c4[p->state](p);
}

void Entity8AAB_CallSubstateHandler(Entity8AAB* p) {
  static void (*const PTR_ARRAY_085b0100[4])(Entity8AAB*) = {
      FUN_0822913c,
      FUN_08229140,
      FUN_08229238,
      Entity8AAB_CallStateHandler,
  };  // 0x085B0100

  FUN_08223748(p);
  PTR_ARRAY_085b0100[p->substate](p);
}

s32 Entity8AAB_Update(Entity8AAB* p) {
  if (p->substate == 0) {
    return 1;
  }

  Entity8AAB_CallSubstateHandler(p);
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  if (p->stepCallback != NULL) {
    p->stepCallback(p);
  }
  p->frameCounter++;
  // 戻り値のある宣言だが return なし
}

s32 Entity8AAB_Destroy(Entity8AAB* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  ParticleShadow_Remove(&p->shadow);
  for (i = 0; i < 16; i++) {
    AuxSprite_Remove(&p->elems[i].sprite);
  }
  if (Mover_FindByID_Proxy(p->unk_f46) != NULL) {
    Mover_Unlink(&p->unk_e40);
  }
  gEntity8AAB = NULL;
  // 戻り値のある宣言だが return なし
}

// 0xA3AA
// 413/387 命令, ループ外へ出すアドレスの組が違う, 空ループの j も位置が合わない
NON_MATCH void Cmd_A3AA(void) {
#ifdef NONMATCHING_C
  Entity8AAB* p = gEntity8AAB;
  s32 i;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
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
          Entity8AAB_RequestState(p, 1, 1);
          Entity8AABElem_SetCallback(&p->elems[i], FUN_08224dd0);
          break;
        }
        case 1: {
          p->elems[i].flags |= 8;
          p->elems[i].plttBase = 73;
          Entity8AAB_RequestState(p, 4, 1);
          Entity8AABElem_SetCallback(&p->elems[i], FUN_08224f74);
          break;
        }
        case 2: {
          p->elems[i].flags |= 16;
          p->elems[i].plttBase = 76;
          p->elems[i].sprite.poseIdx = 1;
          Entity8AAB_RequestState(p, 1, 1);
          Entity8AABElem_SetCallback(&p->elems[i], FUN_08224dd0);
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
  INCFUNC("asm/func/Cmd_A3AA.inc");
#endif
}

// 0x5B01
void Cmd_5B01(void) {
  Entity8AAB* p = gEntity8AAB;
  AuxSprite* sprite;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
  }

  sprite = &p->sprite;
  Video_SetAuxSpritePltt(&p->gfx, 279);
  p->sprite.priority = 0;
  p->unk_f28 = 0;
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
    p->unk_f2b = 1;
  } else {
    p->unk_f2b = 0;
  }
  ParticleShadow_Hide(&p->shadow);
  p->sprite.flags |= SPRFLAG_HIDDEN;
  switch (p->unk_f21) {
    case 0: {
      Entity8AAB_RequestState(p, 0, 0);
      break;
    }
    case 1: {
      Entity8AAB_RequestState(p, 2, 1);
      break;
    }
    case 2: {
      Entity8AAB_RequestState(p, 2, 2);
      break;
    }
    case 3: {
      Entity8AAB_RequestState(p, 2, 3);
      break;
    }
    case 4: {
      Entity8AAB_RequestState(p, 2, 5);
      break;
    }
    case 5: {
      Entity8AAB_RequestState(p, 2, 6);
      break;
    }
  }
}

// 残差8命令, 原典は pltt1 へのコピーで u16 切り捨て (0xFFFF) をプール定数で作る (src/pile_driver.c と同じ事例, agbcc はこれを畳む), その1レジスタ分の差で p/sprite の割当も r6,r8 と r7,r5 でずれる
NON_MATCH s32 Entity8AAB_Init(Entity8AAB* p) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;
  rgb555* src;
  s32 i;

  gEntity8AAB = p;
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
  p->unk_e3a = 1;
  p->unk_e38 = 0;
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
  p->unk_f22 = 0;
  p->unk_f1c = 0;
  p->unk_f27 = 0;
  for (i = 0; i < 16; i++) {
    Entity8AABElem* elem = &p->elems[i];

    Video_GetAuxSprite(&elem->gfx, SPRITE_HINT_PANEL);
    AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
    nop_0822a4f8(&elem->sprite, -8, -16);
    elem->sprite.flags = SPRFLAG_HIDDEN;
    elem->index = i;
    elem->flags = E8AABFLAG_UNK_1;
    elem->callback = Entity8AAB_ElemCallbackNone;
    elem->flags |= E8AABFLAG_UNK_0;
  }
  p->updateCallback = NULL;
  p->stepCallback = NULL;
  sprite->pos.x = 0, sprite->pos.y = 0, sprite->pos.z = 0;
  p->unk_e88 = 0;
  p->unk_e86 = 0;
  p->unk_e84 = 0;
  p->unk_f36 = 0;
  p->unk_e8c = 25;
  p->unk_e8e = 102;
  p->unk_e90 = 0;
  p->unk_f1a = 200;
  if (Mover_FindByID_Proxy(p->unk_f46) == NULL) {
    Mover_Init(&p->unk_e40, p->unk_f46, &p->pos, 0, 7, p);
  }
  p->frameCounter = 0;
  return 0;
#else
  INCFUNC("asm/func/Entity8AAB_Init.inc");
#endif
}

Entity8AAB* Entity8AAB_Create(u32 val, u32 _) {
  Entity8AAB* p;

  if (gEntity8AAB != NULL) {
    return gEntity8AAB;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(Entity8AAB));
  if (p != NULL) {
    p->unk_f46 = val;
    SetEntityRoutine(p, Entity8AAB_Update, Entity8AAB_Destroy);
    if (Entity8AAB_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
