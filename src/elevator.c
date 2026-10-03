#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

struct ElevatorUnkData;

typedef void ElevatorUnkDataFunc(struct ElevatorUnkData* p);

typedef u16 ElevatorFlags;               // ElevatorUnkData.flags
#define ELEVATOR_PLAYER_RIDING (1 << 3)  // プレイヤーが乗っている, Elevator.ridingID と対
#define ELEVATOR_SHAKE (1 << 5)          // 揺らす, Elevator_Shake が立てて Elevator_UpdateShake が落とす
#define ELEVATOR_FLAG_12 (1 << 12)       // まだ不明

typedef struct ElevatorUnkData {
  AuxSprite sprite;                  // 0x000
  AuxSpriteGfx gfx;                  // 0x02C, Elevator_SetPltt が Video_SetAuxSpritePltt に渡す
  u8 unk_48[0x0B0 - 0x048];          // 0x048
  u16 slotIdx;                       // 0x0B0, ElevatorController_AllocSlot が確保したスロット番号
  s16 state;                         // 0x0B2, ElevatorController_Update が 0x085AE0E8 の関数テーブルを引く, 6 はスキップ
  ElevatorFlags flags;               // 0x0B4, bit0=tileOverride登録済, bit5=Elevator_Shake, bit11=tileOverrides登録済
  u8 unk_b6[0x0BA - 0x0B6];          // 0x0B6
  s16 unk_ba;                        // 0x0BA, FUN_081d5414 が '.s=6' を入れる
  u8 unk_bc[0x0C8 - 0x0BC];          // 0x0BC
  u16 unk_c8;                        // 0x0C8, FUN_081d21d8 が 0〜3 と比較して効果音を選ぶ
  u8 unk_ca[0x0CC - 0x0CA];          // 0x0CA
  s32 unk_cc;                        // 0x0CC, FUN_081d54a8 が '.l' の値 (正のときだけ) を入れる
  s32 unk_d0;                        // 0x0D0, FUN_081d54a8 が '.h' の値 (正のときだけ) を入れる
  u16 id;                            // 0x0D4, Elevator_FindByID が Player.elevatorID や '.n' の値と比較して探す
  u16 unk_d6;                        // 0x0D6, FUN_081d21d8 / FUN_081d2a64 が bit2,bit5 を見る
  ElevatorUnkDataFunc* unk_d8;       // 0x0D8, ElevatorController_Update が毎フレーム呼ぶ
  ElevatorUnkDataFunc* unk_dc;       // 0x0DC
  ElevatorUnkDataFunc* unk_e0;       // 0x0E0
  u8 unk_e4;                         // 0x0E4, Elevator_Create が VM 値を入れる
  u8 unk_e5;                         // 0x0E5
  u8 unk_e6;                         // 0x0E6, Elevator_Create が VM 値を入れて FUN_08234f90 に渡す
  u8 unk_e7;                         // 0x0E7, FUN_081d2a64 が 0/1/3 で走行音を出し分ける
  u8 unk_e8[0x0F4 - 0x0E8];          // 0x0E8
  Mover hitbox;                      // 0x0F4, pos を x-0x100 して sprite.pos にコピーする
  MapTileOverride tileOverride;      // 0x138, flags bit0 が立っているときだけ有効
  MapTileOverride tileOverrides[4];  // 0x148, flags bit11 が立っているときだけ有効
  bool8 tileOverrideActive[4];       // 0x188, tileOverrides[i] の登録有無
} ElevatorUnkData;
static_assert(sizeof(ElevatorUnkData) == 396);

typedef struct Elevator {
  Entity e;                      // 0x0000, ENTITY_UNK_5
  AuxAnimFile* animFile;         // 0x0018, ANIM_13F9
  ElevatorUnkData unk_1c[12];    // 0x001C
  u32 usedMask;                  // 0x12AC, スロット i を確保すると bit i が立つ
  u16 ridingID;                  // 0x12B0, 搭乗中のエレベータの id, 降りると 0
  u16 unk_12b2;                  // 0x12B2, ridingID と同じ作り, FUN_081d4704 / FUN_081d42c4 が 0x03002C00 の乗り手について持つ
  bool8 soundPlaying;            // 0x12B4, 走行音を鳴らしているか
  u8 unk_12b5[0x12B8 - 0x12B5];  // 0x12B5
} Elevator;
static_assert(sizeof(Elevator) == 4792);

extern Elevator* gElevator;            // 0x03000194
extern const Vec3 gElevatorRanges[3];  // 0x085AE0D0

static inline void Vec3_Delta(Vec3* out, Vec3* origin, Vec3* target) {
  out->x = target->x - origin->x;
  out->y = target->y - origin->y;
  out->z = target->z - origin->z;
}

static inline void Elevator_SetFlags(ElevatorUnkData* p, ElevatorFlags bits) { p->flags |= bits; }
static inline void Elevator_ClearFlags(ElevatorUnkData* p, ElevatorFlags bits) { p->flags &= ~bits; }

void FUN_0807a91c(Player* p, Vec3* pos);
void FUN_0807a97c(Player* p, u32 flags, u32 value);
void FUN_0807a99c(Player* p, u32 flags);
void FUN_080869c8(u32 flags, u32 value);
bool32 FUN_08086a28(Vec3* pos);
void FUN_08086a4c(Vec3* pos);
void FUN_080869f8(u32 flags);

NAKED void FUN_081d21d8(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d21d8.inc"); }

NAKED ElevatorUnkData* Elevator_FindAtPos(Vec3* pos) { INCFUNC("asm/func/Elevator_FindAtPos.inc"); }

NAKED ElevatorUnkData* ElevatorController_AllocSlot(Elevator* p) { INCFUNC("asm/func/ElevatorController_AllocSlot.inc"); }

NAKED void FUN_081d2368(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2368.inc"); }

NAKED bool32 FUN_081d2660(unknown* q, Vec3* pos, s32 dx, s32 dy) { INCFUNC("asm/func/FUN_081d2660.inc"); }

NAKED bool32 FUN_081d2698(Mover* hitbox, unknown* q, Vec3* out, s32 dx, s32 dz, s32 d) { INCFUNC("asm/func/FUN_081d2698.inc"); }

void FUN_081d276c(ElevatorUnkData* p) {
  Elevator* q = gElevator;
  s32 i;

  for (i = 0; i < 1; i++) {
    Player* player = gPlayerPtr[i];

    if (player != NULL && p->id == q->ridingID) {
      player->mover.tile = (p->state == 3 || p->state == 4) ? &player->tile : NULL;
    }
  }
}

NAKED bool32 FUN_081d27c8(void) { INCFUNC("asm/func/FUN_081d27c8.inc"); }

void FUN_081d280c(ElevatorUnkData* p) {}

NAKED void FUN_081d2810(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2810.inc"); }

NAKED void FUN_081d2a14(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2a14.inc"); }

NAKED void FUN_081d2a64(Elevator* p) { INCFUNC("asm/func/FUN_081d2a64.inc"); }

void FUN_081d2c10(void) {
  Vec3 pos = gPlayerPtr[0]->mover.pos;

  pos.x += 0x80;
  FUN_0807a91c(gPlayerPtr[0], &pos);
  FUN_08086a28(&pos);
  pos.x += 0x80;
  FUN_08086a4c(&pos);
}

// プレイヤーがこのエレベータの上にいるか
bool32 FUN_081d2c60(ElevatorUnkData* p) {
  Vec3 d;

  if (gPlayerPtr[0] != NULL) {
    Vec3_Delta(&d, &p->hitbox.pos, &gPlayerPtr[0]->mover.pos);

    if (d.x <= gElevatorRanges[0].x && d.x >= -gElevatorRanges[0].x && d.y <= gElevatorRanges[0].y && d.y >= -gElevatorRanges[0].y && d.z <= gElevatorRanges[0].z && d.z >= -gElevatorRanges[0].z) {
      return TRUE;
    }
  }

  return FALSE;
}

NAKED void FUN_081d2cf8(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2cf8.inc"); }

NAKED void Elevator_UpdateShake(ElevatorUnkData* p) { INCFUNC("asm/func/Elevator_UpdateShake.inc"); }

NAKED void FUN_081d2fd0(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2fd0.inc"); }

void FUN_081d3110(ElevatorUnkData* p) {}

void FUN_081d3114(ElevatorUnkData* p) {}

// id が一致する要素を探す
ElevatorUnkData* Elevator_FindByID(s32 id) {
  Elevator* q = gElevator;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (q->unk_1c[i].id == id) {
      return &q->unk_1c[i];
    }
  }

  return NULL;
}

// プレイヤーが乗っているエレベータを探す
ElevatorUnkData* Elevator_FindRiding(void) {
  Elevator* q = gElevator;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (q->ridingID == q->unk_1c[i].id) {
      return &q->unk_1c[i];
    }
  }

  return NULL;
}

NAKED void Elevator_RemoveTileOverrides(ElevatorUnkData* p) { INCFUNC("asm/func/Elevator_RemoveTileOverrides.inc"); }

NAKED void Elevator_UpdateTileOverrides(ElevatorUnkData* p) { INCFUNC("asm/func/Elevator_UpdateTileOverrides.inc"); }

NAKED void FUN_081d33f8(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d33f8.inc"); }

NAKED bool32 FUN_081d34e8(u32 tileIdx) { INCFUNC("asm/func/FUN_081d34e8.inc"); }

NAKED void FUN_081d3534(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3534.inc"); }

NAKED void FUN_081d36c0(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d36c0.inc"); }

NAKED void FUN_081d38a4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d38a4.inc"); }

NAKED void FUN_081d3a8c(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3a8c.inc"); }

NAKED void FUN_081d3c24(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3c24.inc"); }

NAKED void FUN_081d3dd0(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3dd0.inc"); }

NAKED void FUN_081d3fac(u32 id, s32 kind) { INCFUNC("asm/func/FUN_081d3fac.inc"); }

void FUN_081d4034(ElevatorUnkData* p) {
  if (p->state != 3 && p->state != 4) {
    FUN_0807a97c(gPlayerPtr[0], 5, p->id);
  } else {
    FUN_0807a97c(gPlayerPtr[0], 1, p->id);
    FUN_0807a99c(gPlayerPtr[0], 4);
  }
}

void FUN_081d407c(ElevatorUnkData* p) {
  if (p->state != 3 && p->state != 4) {
    FUN_080869c8(7, p->id);
  } else {
    FUN_080869c8(3, p->id);
    FUN_080869f8(4);
  }
}

NAKED void FUN_081d40b4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d40b4.inc"); }

NAKED void FUN_081d42c4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d42c4.inc"); }

NAKED void FUN_081d43d4(Vec3* a, Vec3* b, ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d43d4.inc"); }

NAKED void FUN_081d4540(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d4540.inc"); }

NAKED void FUN_081d4590(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d4590.inc"); }

NAKED void FUN_081d4658(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d4658.inc"); }

NAKED void FUN_081d4704(Elevator* q, ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d4704.inc"); }

NAKED void Elevator_Create(void) { INCFUNC("asm/func/Elevator_Create.inc"); }

NAKED s32 ElevatorController_Update(Elevator* p) { INCFUNC("asm/func/ElevatorController_Update.inc"); }

NAKED s32 ElevatorController_Destroy(Elevator* p) { INCFUNC("asm/func/ElevatorController_Destroy.inc"); }

s32 ElevatorController_Init(Elevator* p) {
  p->animFile = GetFile(DIR_ANIMATION, ANIM_13F9);
  gElevator = p;
  p->usedMask = 0;
  return 0;
}

Elevator* ElevatorController_Create(void) {
  Elevator* p;

  if (gElevator != NULL) {
    return gElevator;
  }

  p = CreateEntity(ENTITY_UNK_5, sizeof(Elevator));
  if (p != NULL) {
    SetEntityRoutine(p, ElevatorController_Update, ElevatorController_Destroy);
    if (ElevatorController_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void ElevatorController_ClearPtr(void) { gElevator = NULL; }

// VM: 指定した id のエレベータを揺らす
void Elevator_Shake(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      Elevator_SetFlags(p, ELEVATOR_SHAKE);
    }
  }
}

NAKED s32 FUN_081d515c(void) { INCFUNC("asm/func/FUN_081d515c.inc"); }

NAKED void Elevator_Start(void) { INCFUNC("asm/func/Elevator_Start.inc"); }

void FUN_081d5268(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    p->unk_d6 = VM_GetNamedArgValue('m', -1);
  }
}

NAKED void Elevator_Destroy(void) { INCFUNC("asm/func/Elevator_Destroy.inc"); }

NAKED void FUN_081d5340(void) { INCFUNC("asm/func/FUN_081d5340.inc"); }

// VM: 指定した id のエレベータのパレットを差し替える
void Elevator_SetPltt(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      s32 plttID = VM_GetNamedArgValue('c', 0);

      Video_SetAuxSpritePltt(&p->gfx, plttID + 0x1B7);
    }
  }
}

void FUN_081d5414(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      p->unk_ba = VM_GetNamedArgValue('s', 6);
    }
  }
}

// VM: プレイヤーをエレベータから降ろす
void FUN_081d5450(void) {
  Elevator* q = gElevator;
  ElevatorUnkData* p = Elevator_FindRiding();

  q->ridingID = 0;
  gPlayerPtr[0]->mover.tile = &gPlayerPtr[0]->tile;
  FUN_0807a99c(gPlayerPtr[0], 1);
  Elevator_ClearFlags(p, ELEVATOR_PLAYER_RIDING);
  gPlayerPtr[0]->unk_60e &= ~1;
}

void FUN_081d54a8(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      s32 h = VM_GetNamedArgValue('h', -1);
      s32 l = VM_GetNamedArgValue('l', -1);

      if (h > 0) {
        p->unk_d0 = h;
      }

      if (l > 0) {
        p->unk_cc = l;
      }
    }
  }
}

void FUN_081d5504(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      Elevator_ClearFlags(p, ELEVATOR_FLAG_12);
    }
  }
}

Vec3* Elevator_GetPosByID(s32 id) {
  ElevatorUnkData* p;

  if (gElevator == NULL || id == 0) {
    return NULL;
  }

  p = Elevator_FindByID(id);
  if (p == NULL) {
    return NULL;
  }

  return &p->hitbox.pos;
}

Vec3* Elevator_GetPos(ElevatorUnkData* p) {
  if (gElevator == NULL) {
    return NULL;
  }

  return &p->hitbox.pos;
}

NAKED void FUN_081d5588(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d5588.inc"); }
