#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"
#include "vm.h"

struct Entity8AAB;

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
  u8 unk_bc[0xCB - 0xBC];                                        // 0xBC, まだ未解析
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
  u8 unk_e3a;                                  // 0xE3A, _Init が 1 を入れる
  u8 unk_e3b;                                  // 0xE3B, まだ未解析
  u16 unk_e3c;                                 // 0xE3C, _Init が 0 を入れる
  u8 unk_e3e[2];                               // 0xE3E, まだ未解析
  Mover unk_e40;                               // 0xE40, _Destroy が Mover_Unlink に渡す
  u16 unk_e84;                                 // 0xE84, _Init が書き込む
  u16 unk_e86;                                 // 0xE86, _Init が書き込む
  u16 unk_e88;                                 // 0xE88, _Init が書き込む
  u8 unk_e8a[2];                               // 0xE8A, まだ未解析
  u16 unk_e8c;                                 // 0xE8C, _Init が 0x19 を入れる
  u16 unk_e8e;                                 // 0xE8E, _Init が 0x66 を入れる
  u16 unk_e90;                                 // 0xE90, _Init が 0 を入れる
  u8 unk_e92[0xE9C - 0xE92];                   // 0xE92, まだ未解析
  WorldPos pos;                                // 0xE9C, unk_e40.pos へ写される, 既定はプレイヤーの座標
  rgb555 pltt0[16];                            // 0xEA4, _Init が gfx.pltt の 0x10..0x1F 番を写す
  rgb555 pltt1[32];                            // 0xEC4, _Init が gfx.pltt の 0x00..0x0F 番を2組ぶん写す
  rgb555* plttSrc;                             // 0xF04, gfx.pltt の写し
  u8 unk_f08[4];                               // 0xF08, まだ未解析
  u32 scriptID;                                // 0xF0C, 一度実行したら 0 に戻す
  u8 unk_f10[6];                               // 0xF10, まだ未解析
  u16 substate : 4;                            // 0xF16 bit0-3, PTR_ARRAY_085b0100 の添字, 0 なら _Update が何もしない
  u16 state : 12;                              // 0xF16 bit4-15, PTR_ARRAY_085b00c4 の添字
  u16 unk_f18;                                 // 0xF18, substate の退避先
  u16 unk_f1a;                                 // 0xF1A, _Init が 200 を入れる
  u16 unk_f1c;                                 // 0xF1C, _Init が 0 を入れる
  u8 unk_f1e[4];                               // 0xF1E, まだ未解析
  u8 unk_f22;                                  // 0xF22, _Init が 0 を入れる
  u8 unk_f23;                                  // 0xF23, まだ未解析
  u8 unk_f24;                                  // 0xF24, まだ未解析
  u8 unk_f25;                                  // 0xF25, まだ未解析
  bool8 stopSound;                             // 0xF26, '.A', 立っていると停止時にEntityとBGMも止める
  u8 unk_f27;                                  // 0xF27, _Init が 0 を入れる
  u8 unk_f28;                                  // 0xF28, '.r'
  u8 unk_f29[0xF36 - 0xF29];                   // 0xF29, まだ未解析
  u16 unk_f36;                                 // 0xF36, _Init が 0 を入れる
  u8 unk_f38[0xF42 - 0xF38];                   // 0xF38, まだ未解析
  u8 savedCmdIdx;                              // 0xF42, anim.cmdIdx の退避先
  u8 savedTick;                                // 0xF43, anim.tick の退避先
  u8 stepTimer;                                // 0xF44, 0 になると stepCallback を NULL にする
  u8 unk_f45;                                  // 0xF45, まだ未解析
  u16 unk_f46;                                 // 0xF46, _Destroy が Mover_FindByID_Proxy に渡す ID
  u8 unk_f48[0xF50 - 0xF48];                   // 0xF48, まだ未解析
  void (*updateCallback)(struct Entity8AAB*);  // 0xF50, _Update が最初に呼ぶ, 処理が終わると自分で NULL にする
  void (*stepCallback)(struct Entity8AAB*);    // 0xF54, _Update が updateCallback の後に呼ぶ, 次の手順へ自分を差し替えていく
  u8 unk_f58[4];                               // 0xF58, まだ未解析
  u32 frameCounter;                            // 0xF5C, _Update が毎フレーム増やす
} Entity8AAB;
static_assert(sizeof(Entity8AAB) == 3936);

IWRAM_DATA Entity8AAB* gEntity8AAB = NULL;  // 0x03000248

void nop_0822a4f8(void* _, s32 unused1, s32 unused2);
void FUN_080a6e88(bool32 stopSound);
Entity8AAB* Entity8AAB_Create(u32 val, u32 _);
void FUN_08223d00(Entity8AAB* p);
void FUN_08223d20(Entity8AAB* p);

void FUN_08224fb8(Entity8AAB*);
void FUN_0822517c(Entity8AAB*);
void FUN_082253e4(Entity8AAB*);
void FUN_08225658(Entity8AAB*);
void FUN_082258bc(Entity8AAB*);
void FUN_08225b18(Entity8AAB*);
void FUN_08225d40(Entity8AAB*);
void FUN_08225f50(Entity8AAB*);
void FUN_08226048(Entity8AAB*);
void FUN_08226520(Entity8AAB*);
void FUN_08226990(Entity8AAB*);
void FUN_08226fd0(Entity8AAB*);
void FUN_08227168(Entity8AAB*);
void FUN_082272f0(Entity8AAB*);
void FUN_08227498(Entity8AAB*);
void FUN_08227608(Entity8AAB*);

void (*const PTR_ARRAY_085b0084[16])(Entity8AAB*) = {
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

void FUN_082279e0(Entity8AAB*);
void FUN_082279e4(Entity8AAB*);
void FUN_08227c14(Entity8AAB*);
void FUN_08227e44(Entity8AAB*);
void FUN_08228074(Entity8AAB*);
void FUN_082282a4(Entity8AAB*);
void FUN_082284b8(Entity8AAB*);
void FUN_082286e8(Entity8AAB*);
void FUN_08228918(Entity8AAB*);
void FUN_08228b48(Entity8AAB*);
void FUN_08228d8c(Entity8AAB*);
void FUN_08228e94(Entity8AAB*);
void FUN_08228f9c(Entity8AAB*);

void (*const PTR_ARRAY_085b00c4[15])(Entity8AAB*) = {
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

void FUN_0822913c(Entity8AAB*);
void FUN_08229140(Entity8AAB*);
void FUN_08229238(Entity8AAB*);
void Entity8AAB_CallStateHandler(Entity8AAB*);

void (*const PTR_ARRAY_085b0100[4])(Entity8AAB*) = {
    FUN_0822913c,
    FUN_08229140,
    FUN_08229238,
    Entity8AAB_CallStateHandler,
};  // 0x085B0100

void FUN_08222cd4(void) { gEntity8AAB = NULL; }

NAKED void FUN_08222ce0(Entity8AAB* p) { INCFUNC("asm/func/FUN_08222ce0.inc"); }

NAKED void FUN_08222d60(Entity8AAB* p) { INCFUNC("asm/func/FUN_08222d60.inc"); }

NAKED void FUN_08222f0c(Entity8AAB* p) { INCFUNC("asm/func/FUN_08222f0c.inc"); }

NAKED void FUN_082230d0(Entity8AAB* p) { INCFUNC("asm/func/FUN_082230d0.inc"); }

NAKED void FUN_08223154(Entity8AAB* p) { INCFUNC("asm/func/FUN_08223154.inc"); }

NAKED void FUN_08223374(Entity8AAB* p) { INCFUNC("asm/func/FUN_08223374.inc"); }

NAKED void FUN_08223470(Entity8AAB* p, Entity8AABElem* elem) { INCFUNC("asm/func/FUN_08223470.inc"); }

NAKED void FUN_08223748(Entity8AAB* p) { INCFUNC("asm/func/FUN_08223748.inc"); }

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

NAKED void FUN_082239fc(Entity8AAB* p) { INCFUNC("asm/func/FUN_082239fc.inc"); }

NAKED void FUN_08223ad0(Entity8AAB* p) { INCFUNC("asm/func/FUN_08223ad0.inc"); }

NAKED void FUN_08223bf0(Entity8AAB* p) { INCFUNC("asm/func/FUN_08223bf0.inc"); }

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
    if ((u8)(gClock.spanOfTime - 1) <= 2) {
      PlaySound_082406e0(VO_OTENKO_OTNK);
    } else {
      Time_GetHour();
    }
  }
}

NAKED void FUN_08223d68(void) { INCFUNC("asm/func/FUN_08223d68.inc"); }

NAKED void FUN_08223e04(void) { INCFUNC("asm/func/FUN_08223e04.inc"); }

NAKED void FUN_08223ea0(void) { INCFUNC("asm/func/FUN_08223ea0.inc"); }

NAKED void FUN_08223f3c(void) { INCFUNC("asm/func/FUN_08223f3c.inc"); }

NAKED void FUN_08223fd8(void) { INCFUNC("asm/func/FUN_08223fd8.inc"); }

NAKED void FUN_08224074(void) { INCFUNC("asm/func/FUN_08224074.inc"); }

NAKED void FUN_08224110(void) { INCFUNC("asm/func/FUN_08224110.inc"); }

NAKED void FUN_082241ac(void) { INCFUNC("asm/func/FUN_082241ac.inc"); }

NAKED void FUN_08224248(void) { INCFUNC("asm/func/FUN_08224248.inc"); }

NAKED void FUN_082242f4(s32 kind) { INCFUNC("asm/func/FUN_082242f4.inc"); }

NAKED void FUN_082243bc(void) { INCFUNC("asm/func/FUN_082243bc.inc"); }

NAKED void FUN_08224458(void) { INCFUNC("asm/func/FUN_08224458.inc"); }

NAKED void FUN_082244f4(void) { INCFUNC("asm/func/FUN_082244f4.inc"); }

NAKED void FUN_08224590(void) { INCFUNC("asm/func/FUN_08224590.inc"); }

NAKED void FUN_082246bc(void) { INCFUNC("asm/func/FUN_082246bc.inc"); }

NAKED void FUN_08224790(void) { INCFUNC("asm/func/FUN_08224790.inc"); }

NAKED void FUN_08224878(void) { INCFUNC("asm/func/FUN_08224878.inc"); }

NAKED void FUN_08224980(void) { INCFUNC("asm/func/FUN_08224980.inc"); }

NAKED void FUN_08224a3c(void) { INCFUNC("asm/func/FUN_08224a3c.inc"); }

NAKED void FUN_08224af8(void) { INCFUNC("asm/func/FUN_08224af8.inc"); }

NAKED void FUN_08224b94(void) { INCFUNC("asm/func/FUN_08224b94.inc"); }

NAKED void FUN_08224c8c(void) { INCFUNC("asm/func/FUN_08224c8c.inc"); }

s32 FUN_08224d28(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return 0;
  }
  return p->unk_f24;
}

void Entity8AAB_SetPriorityScripted(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->sprite.priority = VM_GetNamedArgValue('p', 0);
}

void FUN_08224d94(void) {
  Entity8AAB* p = gEntity8AAB;

  if (p == NULL) {
    p = Entity8AAB_Create(0xBB34, 0);
    if (p == NULL) return;
  }
  p->unk_f28 = VM_GetNamedArgValue('r', 0);
}

void Entity8AAB_ElemCallbackNone(Entity8AAB* _, Entity8AABElem* __) {}

// 残差は bool の 0/1 materialize と ~E8AABFLAG_UNK_0 が 32bit (-2) のまま残る点, Tier A-B は試済, 未: diamond を潰さずに残す書き方
NON_MATCH void FUN_08224dd0(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  u32 flags = elem->flags;
  bool32 unhide;

  if (flags & E8AABFLAG_UNK_0) {
    elem->flags = flags & ~E8AABFLAG_UNK_0;
    unhide = TRUE;
  } else {
    unhide = FALSE;
  }

  if (unhide) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  FUN_08223470(p, elem);
#else
  INCFUNC("asm/func/FUN_08224dd0.inc");
#endif
}

NAKED void FUN_08224e10(Entity8AAB* p) { INCFUNC("asm/func/FUN_08224e10.inc"); }

// 残差は FUN_08224dd0 と同一 (bool の 0/1 materialize と 32bit の ~E8AABFLAG_UNK_0), Tier A-B は試済
NON_MATCH void FUN_08224f14(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  u32 flags = elem->flags;
  bool32 run;

  if (flags & E8AABFLAG_UNK_0) {
    elem->flags = flags & ~E8AABFLAG_UNK_0;
    run = TRUE;
  } else {
    run = FALSE;
  }

  if (run) {
    u32 scriptID = p->scriptID;

    if (scriptID != 0) {
      p->scriptID = 0;
      VM_ExecByID(scriptID, NULL);
    }
    elem->callback = FUN_08224dd0;
    elem->flags |= E8AABFLAG_UNK_0;
  }
#else
  INCFUNC("asm/func/FUN_08224f14.inc");
#endif
}

// 残差は FUN_08224dd0 と同一 (bool の 0/1 materialize と 32bit の ~E8AABFLAG_UNK_0), Tier A-B は試済
NON_MATCH void FUN_08224f74(Entity8AAB* p, Entity8AABElem* elem) {
#ifdef NONMATCHING_C
  u32 flags = elem->flags;
  bool32 unhide;

  if (flags & E8AABFLAG_UNK_0) {
    elem->flags = flags & ~E8AABFLAG_UNK_0;
    unhide = TRUE;
  } else {
    unhide = FALSE;
  }

  if (unhide) {
    Video_SetAuxSpritePltt(&elem->gfx, elem->plttBase + 2);
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_08224f74.inc");
#endif
}

NAKED void FUN_08224fb8(Entity8AAB* p) { INCFUNC("asm/func/FUN_08224fb8.inc"); }

NAKED void FUN_0822517c(Entity8AAB* p) { INCFUNC("asm/func/FUN_0822517c.inc"); }

NAKED void FUN_082253e4(Entity8AAB* p) { INCFUNC("asm/func/FUN_082253e4.inc"); }

NAKED void FUN_08225658(Entity8AAB* p) { INCFUNC("asm/func/FUN_08225658.inc"); }

NAKED void FUN_082258bc(Entity8AAB* p) { INCFUNC("asm/func/FUN_082258bc.inc"); }

NAKED void FUN_08225b18(Entity8AAB* p) { INCFUNC("asm/func/FUN_08225b18.inc"); }

NAKED void FUN_08225d40(Entity8AAB* p) { INCFUNC("asm/func/FUN_08225d40.inc"); }

NAKED void FUN_08225f50(Entity8AAB* p) { INCFUNC("asm/func/FUN_08225f50.inc"); }

NAKED void FUN_08226048(Entity8AAB* p) { INCFUNC("asm/func/FUN_08226048.inc"); }

NAKED void FUN_08226520(Entity8AAB* p) { INCFUNC("asm/func/FUN_08226520.inc"); }

NAKED void FUN_08226990(Entity8AAB* p) { INCFUNC("asm/func/FUN_08226990.inc"); }

NAKED void FUN_08226fd0(Entity8AAB* p) { INCFUNC("asm/func/FUN_08226fd0.inc"); }

NAKED void FUN_08227168(Entity8AAB* p) { INCFUNC("asm/func/FUN_08227168.inc"); }

NAKED void FUN_082272f0(Entity8AAB* p) { INCFUNC("asm/func/FUN_082272f0.inc"); }

NAKED void FUN_08227498(Entity8AAB* p) { INCFUNC("asm/func/FUN_08227498.inc"); }

NAKED void FUN_08227608(Entity8AAB* p) { INCFUNC("asm/func/FUN_08227608.inc"); }

void FUN_082279e0(Entity8AAB* _) {}

NAKED void FUN_082279e4(Entity8AAB* p) { INCFUNC("asm/func/FUN_082279e4.inc"); }

NAKED void FUN_08227c14(Entity8AAB* p) { INCFUNC("asm/func/FUN_08227c14.inc"); }

NAKED void FUN_08227e44(Entity8AAB* p) { INCFUNC("asm/func/FUN_08227e44.inc"); }

NAKED void FUN_08228074(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228074.inc"); }

NAKED void FUN_082282a4(Entity8AAB* p) { INCFUNC("asm/func/FUN_082282a4.inc"); }

NAKED void FUN_082284b8(Entity8AAB* p) { INCFUNC("asm/func/FUN_082284b8.inc"); }

NAKED void FUN_082286e8(Entity8AAB* p) { INCFUNC("asm/func/FUN_082286e8.inc"); }

NAKED void FUN_08228918(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228918.inc"); }

NAKED void FUN_08228b48(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228b48.inc"); }

NAKED void FUN_08228d8c(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228d8c.inc"); }

NAKED void FUN_08228e94(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228e94.inc"); }

NAKED void FUN_08228f9c(Entity8AAB* p) { INCFUNC("asm/func/FUN_08228f9c.inc"); }

void FUN_0822913c(Entity8AAB* _) {}

NAKED void FUN_08229140(Entity8AAB* p) { INCFUNC("asm/func/FUN_08229140.inc"); }

void FUN_08229238(Entity8AAB* p) {
  p->unk_e40.pos.x = p->pos.x;
  p->unk_e40.pos.y = p->pos.y;
  p->unk_e40.pos.z = p->pos.z;
  PTR_ARRAY_085b0084[p->state](p);
}

void Entity8AAB_CallStateHandler(Entity8AAB* p) { PTR_ARRAY_085b00c4[p->state](p); }

void Entity8AAB_CallSubstateHandler(Entity8AAB* p) {
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

NAKED void FUN_08229394(void) { INCFUNC("asm/func/FUN_08229394.inc"); }

NAKED void FUN_0822970c(void) { INCFUNC("asm/func/FUN_0822970c.inc"); }

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
    p->pltt1[i + 16] = src[i];
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
