#include "coffin.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vm.h"

struct ElevatorUnkData;
typedef void ElevatorUnkDataFunc(struct ElevatorUnkData* p);

typedef u16 ElevatorFlags;                // ElevatorUnkData.flags
#define ELEVATOR_TILEOVERRIDE (1 << 0)    // tileOverride を登録済み
#define ELEVATOR_TILEOVERRIDES (1 << 11)  // tileOverrides[] を登録済み
#define ELEVATOR_UNK_1 (1 << 1)           // Elevator_Start が '.m=2' のとき立てる
#define ELEVATOR_UNK_2 (1 << 2)           // Elevator_Start が '.m=4' のとき立てる
#define ELEVATOR_PLAYER_RIDING (1 << 3)   // プレイヤーが乗っている, Elevator.ridingID と対
#define ELEVATOR_UNK_4 (1 << 4)           // 不死の棺桶が乗っている?, FUN_081d3fac が第2引数で落とし分ける
#define ELEVATOR_UNK_9 (1 << 9)           // FUN_081d4658 が見て落とす
#define ELEVATOR_UNK_8 (1 << 8)           // 立っていると FUN_081d4590 がプレイヤーを運ばずにフラグだけ落とす
#define ELEVATOR_UNK_7 (1 << 7)           // 立っていると Elevator_UpdateShake が揺らさずにフラグだけ落とす
#define ELEVATOR_SHAKE (1 << 5)           // 揺らす, Elevator_Shake が立てて Elevator_UpdateShake が落とす
#define ELEVATOR_FLAG_12 (1 << 12)        // まだ不明

typedef struct ElevatorUnkData {
  AuxSprite sprite;                  // 0x000
  AuxSpriteGfx gfx;                  // 0x02C, Elevator_SetPltt が Video_SetAuxSpritePltt に渡す
  u8 unk_48[0x058 - 0x048];          // 0x048
  Vec3 unk_58;                       // 0x058, FUN_081d4540 が ClearMemory で 0 にする, FUN_081d4658 が棺桶の座標に足す
  u8 unk_60[0x0B0 - 0x060];          // 0x060
  s16 slotIdx;                       // 0x0B0, ElevatorController_AllocSlot が確保したスロット番号, 解放時は 0xFFFF
  s16 state;                         // 0x0B2, ElevatorController_Update が 0x085AE0E8 の関数テーブルを引く, 6 はスキップ
  ElevatorFlags flags;               // 0x0B4, bit0=tileOverride登録済, bit5=Elevator_Shake, bit11=tileOverrides登録済
  u8 unk_b6;                         // 0x0B6, FUN_081d2a14 が到着時に 1 を入れる
  u8 unk_b7[0x0BA - 0x0B7];          // 0x0B7
  s16 unk_ba;                        // 0x0BA, FUN_081d5414 が '.s=6' を入れる
  u8 unk_bc[0x0C6 - 0x0BC];          // 0x0BC
  s16 unk_c6;                        // 0x0C6, 負の間だけ sprite.pos.y に足されて半分ずつ減る沈み込み量
  u16 unk_c8;                        // 0x0C8, FUN_081d21d8 が 0〜3 と比較して効果音を選ぶ
  u8 unk_ca[0x0CC - 0x0CA];          // 0x0CA
  s32 unk_cc;                        // 0x0CC, FUN_081d54a8 が '.l' の値 (正のときだけ) を入れる
  s32 unk_d0;                        // 0x0D0, FUN_081d54a8 が '.h' の値 (正のときだけ) を入れる
  u16 id;                            // 0x0D4, Elevator_FindByID が Player.elevatorID や '.n' の値と比較して探す
  u16 unk_d6;                        // 0x0D6, '.m', FUN_081d21d8 / FUN_081d2a64 が bit2,bit5 を見る
  ElevatorUnkDataFunc* unk_d8;       // 0x0D8, ElevatorController_Update が毎フレーム呼ぶ
  ElevatorUnkDataFunc* unk_dc;       // 0x0DC
  ElevatorUnkDataFunc* unk_e0;       // 0x0E0
  u8 unk_e4;                         // 0x0E4, Elevator_Create が VM 値を入れる
  u8 unk_e5;                         // 0x0E5
  u8 unk_e6;                         // 0x0E6, Elevator_Create が VM 値を入れて Map_GetPathNodePos に渡す
  u8 unk_e7;                         // 0x0E7, FUN_081d2a64 が 0/1/3 で走行音を出し分ける
  PathWalker pathWalker;             // 0x0E8, hitbox.path がここを指す, FUN_081d5340 が '.r' の経路で初期化する
  Mover hitbox;                      // 0x0F4, pos を x-0x100 して sprite.pos にコピーする
  MapTileOverride tileOverride;      // 0x138, flags bit0 が立っているときだけ有効
  MapTileOverride tileOverrides[4];  // 0x148, flags bit11 が立っているときだけ有効
  bool8 tileOverrideActive[4];       // 0x188, tileOverrides[i] の登録有無
} ElevatorUnkData;
static_assert(sizeof(ElevatorUnkData) == 396);

typedef struct {
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

IWRAM_DATA Elevator* gElevator = NULL;  // 0x03000194

// エレベータが乗り手との距離を測るときの許容範囲 (±), Elevator_FindAtPos ほかが引く
const Vec3 gElevatorRanges[3] = {
    {128, 32, 128},
    {128, 32, 128},
    {98,  32, 98 }
};  // 0x085AE0D0

bool32 FUN_0807a954(Player* p, u32 mask);
bool32 FUN_08086978(u32 mask);
void FUN_081d5588(ElevatorUnkData* p);

static inline void Vec3_Delta(Vec3* out, Vec3* origin, Vec3* target) {
  out->x = target->x - origin->x;
  out->y = target->y - origin->y;
  out->z = target->z - origin->z;
}

static inline bool32 Elevator_IsSlotUsed(Elevator* p, s32 i) {
  if (p->usedMask & (1 << i)) {
    return TRUE;
  }
  return FALSE;
}

static inline bool32 Elevator_TestFlags(ElevatorUnkData* p, ElevatorFlags bits) {
  if (p->flags & bits) {
    return TRUE;
  }
  return FALSE;
}

static inline void Elevator_SetFlags(ElevatorUnkData* p, ElevatorFlags bits) { p->flags |= bits; }
static inline void Elevator_ClearFlags(ElevatorUnkData* p, ElevatorFlags bits) { p->flags &= ~bits; }

void FUN_0807a97c(Player* p, u32 flags, u32 value);
void FUN_0807a99c(Player* p, u32 flags);
void FUN_080869c8(u32 flags, u32 value);
void FUN_080869f8(u32 flags);

// unk_c8 の種類ごとに走行音を鳴らす
void FUN_081d21d8(ElevatorUnkData* p) {
  if (!(p->unk_d6 & 4)) {
    switch (p->unk_c8) {
      case 0: {
        PlaySound_082406e0(SONG_344);
        break;
      }
      case 1:
      case 2: {
        PlaySound_082406e0(SONG_609);
        break;
      }
      case 3: {
        if (p->unk_d6 & 0x20) {
          PlaySound_082406e0(SONG_344);
        } else {
          PlaySound_082406e0(SONG_609);
        }
        break;
      }
      default: {
        PlaySound_082406e0(SONG_609);
        break;
      }
    }
  }
}

NAKED ElevatorUnkData* Elevator_FindAtPos(Vec3* pos) { INCFUNC("asm/func/Elevator_FindAtPos.inc"); }

// 空いているスロットを1つ確保して返す, 全部埋まっていれば NULL
// 残差はビット判定を 0/1 の値に起こす分だけ: 原典は (flags & bits) を movs 1 / movs 0 で値にしてから test するが, agbcc はどう書いても分岐に畳む
// Tier A-B 試済: static inline の if/else, ローカルの bool32 受け, != 0, == FALSE, !!(...), static (非 inline) は bl が出て不可
NON_MATCH ElevatorUnkData* ElevatorController_AllocSlot(Elevator* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Elevator_IsSlotUsed(p, i)) {
      p->usedMask |= 1 << i;
      p->unk_1c[i].slotIdx = i;
      return &p->unk_1c[i];
    }
  }

  return NULL;
#else
  INCFUNC("asm/func/ElevatorController_AllocSlot.inc");
#endif
}

NAKED void FUN_081d2368(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2368.inc"); }

// 経路ノードが pos から dx/dz の範囲内かどうか
bool8 FUN_081d2660(PathWalker* walker, Vec3* pos, u32 dx, u32 dz) {
  s32 ddx = walker->node->x - pos->x;
  s32 ddz = walker->node->y - pos->z;

  if (abs(ddx) <= dx && abs(ddz) <= dz) {
    return TRUE;
  }
  return FALSE;
}

// 経路ノードへ向けて mover を進める, dx/dz の範囲に入っていたら飛びついて TRUE
bool8 FUN_081d2698(Mover* mover, PathWalker* walker, Vec3* out, u32 dx, u32 dz, s32 speed) {
  s32 ddx, ddz;

  ClearMemory(out, 8);
  ddx = walker->node->x - mover->pos.x;
  ddz = walker->node->y - mover->pos.z;

  if (abs(ddx) <= dx && abs(ddz) <= dz) {
    mover->pos.x += ddx;
    mover->pos.z += ddz;
    out->x = ddx;
    out->z = ddz;
    return TRUE;
  }

  if (ddx != 0 || ddz != 0) {
    s32 angle = ((((u8)ArcTan2_8(ddx, ddz) + 0x20) & 0xFF) >> 6) << 6;
    s32 vx, vz;

    mover->angle = angle;
    vx = COS(angle, speed);
    vz = SIN(angle, speed);
    mover->pos.x += vx;
    mover->pos.z += vz;
    out->x = vx;
    out->z = vz;
  }

  return FALSE;
}

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

// プレイヤーか不死の棺桶のどちらか一方だけが乗っていて、かつ行動6 (乗り込み中?) かどうか
// 残差は gPlayerPtr のアドレスの扱いだけ (29対29), 原典は r4 に置いて2回読むがこちらはプール定数を2回ロードする
NON_MATCH bool32 FUN_081d27c8(void) {
#ifdef NONMATCHING_C
  if (FUN_0807a954(gPlayerPtr[0], 1)) {
    if (FUN_08086978(3)) {
      return FALSE;
    }
  } else if (!FUN_08086978(3)) {
    return FALSE;
  }

  if (gPlayerPtr[0]->action != 6) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_081d27c8.inc");
#endif
}

void FUN_081d280c(ElevatorUnkData* p) {}

NAKED void FUN_081d2810(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d2810.inc"); }

// 目的地に着いていたら状態3へ進め, まだなら移動を続ける
void FUN_081d2a14(ElevatorUnkData* p) {
  if (FUN_081d2698(&p->hitbox, &p->pathWalker, &p->unk_58, p->unk_ba, p->unk_ba, p->unk_ba)) {
    p->state = 3;
    p->unk_b6 = 1;
    FUN_081d5588(p);
  } else {
    FUN_081d2368(p);
  }
}

NAKED void FUN_081d2a64(Elevator* p) { INCFUNC("asm/func/FUN_081d2a64.inc"); }

void FUN_081d2c10(void) {
  WorldPos pos = gPlayerPtr[0]->mover.pos;

  pos.x += 0x80;
  FUN_0807a91c(gPlayerPtr[0], &pos);
  Coffin_CopyPos(&pos);
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

// 沈み込みを戻しつつ, 揺れフラグが立っていればスプライト位置を乱数で揺らす
// 残差11命令 (81/92): FUN_081d515c と同じく, 原典は flags 判定を分岐で 0/1 に起こしてから cmp で読み直す (2箇所)
NON_MATCH void Elevator_UpdateShake(ElevatorUnkData* p) {
#ifdef NONMATCHING_C
  if (p->unk_c6 < 0) {
    p->sprite.pos.y += p->unk_c6;
    p->unk_c6 = Div(p->unk_c6, 2);
  }

  if (!Elevator_TestFlags(p, ELEVATOR_UNK_7)) {
    if (!Elevator_TestFlags(p, ELEVATOR_SHAKE)) {
      return;
    }

    p->sprite.pos.x += Mod(Random(), 12) - 6;
    p->sprite.pos.y += Random() & 3;
    p->sprite.pos.z += Mod(Random(), 12) - 6;
  }

  p->flags &= ~(ELEVATOR_TILEOVERRIDE | ELEVATOR_SHAKE);
#else
  INCFUNC("asm/func/Elevator_UpdateShake.inc");
#endif
}

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

// 登録してあった上書きタイルを全部外す
// 残差はビット判定を 0/1 の値に起こす分だけ: 原典は (flags & bits) を movs 1 / movs 0 で値にしてから test するが, agbcc はどう書いても分岐に畳む
// Tier A-B 試済: static inline の if/else, ローカルの bool32 受け, != 0, == FALSE, !!(...), static (非 inline) は bl が出て不可
NON_MATCH void Elevator_RemoveTileOverrides(ElevatorUnkData* p) {
#ifdef NONMATCHING_C
  if (Elevator_TestFlags(p, ELEVATOR_TILEOVERRIDES)) {
    s32 i;

    for (i = 0; i < 4; i++) {
      if (p->tileOverrideActive[i]) {
        Map_RemoveTileOverride(&p->tileOverrides[i]);
        p->tileOverrideActive[i] = 0;
      }
    }

    Elevator_ClearFlags(p, ELEVATOR_TILEOVERRIDES);
  }
#else
  INCFUNC("asm/func/Elevator_RemoveTileOverrides.inc");
#endif
}

NAKED void Elevator_UpdateTileOverrides(ElevatorUnkData* p) { INCFUNC("asm/func/Elevator_UpdateTileOverrides.inc"); }

NAKED void FUN_081d33f8(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d33f8.inc"); }

// tileIdx の上書きタイルを登録しているエレベータがあるかどうか
// 残差はビット判定を 0/1 の値に起こす分だけ: 原典は (flags & bits) を movs 1 / movs 0 で値にしてから test するが, agbcc はどう書いても分岐に畳む
// Tier A-B 試済: static inline の if/else, ローカルの bool32 受け, != 0, == FALSE, !!(...), static (非 inline) は bl が出て不可
NON_MATCH bool32 FUN_081d34e8(s32 tileIdx) {
#ifdef NONMATCHING_C
  Elevator* q = gElevator;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Elevator_TestFlags(&q->unk_1c[i], ELEVATOR_TILEOVERRIDE) && q->unk_1c[i].tileOverride.tileIdx == tileIdx) {
      return TRUE;
    }
  }

  return FALSE;
#else
  INCFUNC("asm/func/FUN_081d34e8.inc");
#endif
}

NAKED void FUN_081d3534(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3534.inc"); }

NAKED void FUN_081d36c0(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d36c0.inc"); }

NAKED void FUN_081d38a4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d38a4.inc"); }

NAKED void FUN_081d3a8c(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3a8c.inc"); }

NAKED void FUN_081d3c24(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3c24.inc"); }

NAKED void FUN_081d3dd0(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d3dd0.inc"); }

// 残差はビット判定を 0/1 の値に起こす分だけ (src/elevator.c の ElevatorController_AllocSlot と同じ現象)
NON_MATCH void FUN_081d3fac(s32 id, s32 which) {
#ifdef NONMATCHING_C
  Elevator* q = gElevator;
  s32 i;

  if (q->usedMask != 0) {
    for (i = 0; i < 12; i++) {
      if (Elevator_IsSlotUsed(q, i) && q->unk_1c[i].id == id) {
        if (which == 0) {
          q->unk_1c[i].flags &= ~ELEVATOR_PLAYER_RIDING;
        } else {
          q->unk_1c[i].flags &= ~ELEVATOR_UNK_4;
        }
        return;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d3fac.inc");
#endif
}

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

void FUN_081d4590(ElevatorUnkData* p);
void FUN_081d4658(ElevatorUnkData* p);

NAKED void FUN_081d40b4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d40b4.inc"); }

NAKED void FUN_081d42c4(ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d42c4.inc"); }

NAKED void FUN_081d43d4(Vec3* a, Vec3* b, ElevatorUnkData* p) { INCFUNC("asm/func/FUN_081d43d4.inc"); }

void FUN_081d4540(ElevatorUnkData* p) {
  if (gPlayerPtr[0] != NULL) {
    FUN_081d40b4(p);
    FUN_081d42c4(p);

    if (FUN_0807a954(gPlayerPtr[0], 1)) {
      FUN_081d4590(p);
    }

    if (FUN_08086978(1)) {
      FUN_081d4658(p);
    }

    ClearMemory(&p->unk_58, sizeof(p->unk_58));
  }
}

// 乗っているプレイヤーをエレベータの移動ぶんだけ運ぶ
// 残差10命令 (74/84): FUN_081d515c と同じく, 原典は flags 判定を分岐で 0/1 に起こしてから cmp で読み直す
NON_MATCH void FUN_081d4590(ElevatorUnkData* p) {
#ifdef NONMATCHING_C
  Elevator* q = gElevator;

  if (gPlayerPtr[0] == NULL) {
    return;
  }
  if (p->id != q->ridingID) {
    return;
  }

  if (!Elevator_TestFlags(p, ELEVATOR_UNK_8)) {
    Vec3 v;

    v.x = p->unk_58.x + gPlayerPtr[0]->mover.pos.x;
    v.y = p->unk_58.y + gPlayerPtr[0]->mover.pos.y;
    v.z = p->unk_58.z + gPlayerPtr[0]->mover.pos.z;
    FUN_081d43d4(&v, &gPlayerPtr[0]->mover.pos, p);
    FUN_0807a91c(gPlayerPtr[0], &v);
  }

  p->flags &= ~ELEVATOR_UNK_8;
#else
  INCFUNC("asm/func/FUN_081d4590.inc");
#endif
}

// 乗っている棺桶をエレベータの移動ぶんだけ動かす
// 残差23命令 (54/77): 原典は棺桶と hitbox.pos の差分を Vec3 に組み立てるがどこからも読まないので agbcc が消す, 加えて flags 判定の 0/1 起こしも畳まれる
NON_MATCH void FUN_081d4658(ElevatorUnkData* p) {
#ifdef NONMATCHING_C
  if (gElevator->unk_12b2 == p->id) {
    WorldPos pos;
    WorldPos delta;

    Coffin_CopyPos(&pos);
    delta.x = pos.x - p->hitbox.pos.x;
    delta.y = pos.y - p->hitbox.pos.y;
    delta.z = pos.z - p->hitbox.pos.z;

    if (!Elevator_TestFlags(p, ELEVATOR_UNK_9)) {
      pos.x = p->unk_58.x + pos.x;
      pos.y = pos.y + p->unk_58.y;
      pos.z = p->unk_58.z + pos.z;
      FUN_08086a4c(&pos);
    }

    p->flags &= ~ELEVATOR_UNK_9;
  }
#else
  INCFUNC("asm/func/FUN_081d4658.inc");
#endif
}

// 棺桶がエレベータの許容範囲に収まっていたら乗り手として登録する
// 棺桶がエレベータの許容範囲に収まっていたら乗り手として登録する
// 残差13命令 (92/79): 原典は差分 Vec3 をスタックに置いて s16 で読み直すが, agbcc はレジスタに畳んで半語を詰め替える
// Tier A-C は試済: 2要素の WorldPos 配列にするとメモリには乗るが 87 で一致せず
NON_MATCH void FUN_081d4704(Elevator* q, ElevatorUnkData* p) {
#ifdef NONMATCHING_C
  if (p->unk_e7 == 2) {
    WorldPos pos;
    WorldPos delta;

    Coffin_CopyPos(&pos);
    delta.x = pos.x - p->hitbox.pos.x;
    delta.y = pos.y - p->hitbox.pos.y;
    delta.z = pos.z - p->hitbox.pos.z;

    if (delta.x > gElevatorRanges[0].x) {
      return;
    }
    if (delta.x < -gElevatorRanges[0].x) {
      return;
    }
    if (delta.z > gElevatorRanges[0].z) {
      return;
    }
    if (delta.z < -gElevatorRanges[0].z) {
      return;
    }

    FUN_08086a4c(&p->hitbox.pos);
    FUN_081d3fac(q->unk_12b2, 1);
    q->unk_12b2 = p->id;
    FUN_080869c8(3, p->id);
    p->flags |= ELEVATOR_UNK_4;
  }
#else
  INCFUNC("asm/func/FUN_081d4704.inc");
#endif
}

NAKED void Elevator_Create(void) { INCFUNC("asm/func/Elevator_Create.inc"); }

void (*const PTR_ARRAY_085ae0e8[7])(ElevatorUnkData*) = {
    FUN_081d280c,
    FUN_081d2a14,
    FUN_081d2810,
    FUN_081d2fd0,
    FUN_081d2cf8,
    FUN_081d3110,
    FUN_081d3114,
};  // 0x085AE0E8

NAKED s32 ElevatorController_Update(Elevator* p) { INCFUNC("asm/func/ElevatorController_Update.inc"); }

// 走行音を止め, 使用中のスロットの上書きタイル・Mover・スプライトを片付ける
// 残差7命令 (69/76): FUN_081d515c と同じく, 原典は使用中判定と flags 判定を分岐で 0/1 に起こしてから cmp で読み直す
NON_MATCH s32 ElevatorController_Destroy(Elevator* p) {
#ifdef NONMATCHING_C
  s32 i;

  sound_08240740(SONG_344);
  sound_08240740(SONG_609);
  sound_08240740(SONG_649);
  sound_08240740(SONG_650);
  sound_08240740(SONG_648);

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i)) {
      ElevatorUnkData* e = &p->unk_1c[i];

      if (Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDE)) {
        Map_RemoveTileOverride(&e->tileOverride);
      }

      Elevator_RemoveTileOverrides(e);
      Mover_Unlink(&e->hitbox);
      AuxSprite_Remove(&e->sprite);
    }
  }

  gElevator = NULL;
  return 0;
#else
  INCFUNC("asm/func/ElevatorController_Destroy.inc");
#endif
}

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

// 不死の棺桶が乗っているエレベータの id を返す, 見つからなければ -1
// 残差7命令 (52/59): 原典は使用中判定と flags 判定を分岐で 0/1 に起こし, 要素と &flags を別々の誘導ポインタで回す
// Tier A-C は試済: 要素をポインタで走査する形 (無影響)
NON_MATCH s32 FUN_081d515c(void) {
#ifdef NONMATCHING_C
  Elevator* q = gElevator;
  s32 i;

  if (q == NULL) {
    return -1;
  }
  if (q->usedMask == 0) {
    return -1;
  }
  if (!FUN_08086978(1)) {
    return -1;
  }

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(q, i) && Elevator_TestFlags(&q->unk_1c[i], ELEVATOR_UNK_4)) {
      return q->unk_1c[i].id;
    }
  }

  return -1;
#else
  INCFUNC("asm/func/FUN_081d515c.inc");
#endif
}

// VM: 指定した id のエレベータを動かす, '.m' で動かし方を選ぶ
// 残差は割当だけ (61対61): 原典は定数 2 を r6 に置いて ~2 を mvns で作り, mode の値も r4 に残すが, こちらは ~2 をプール定数にして mode を 4 に伝播させる
NON_MATCH void Elevator_Start(void) {
#ifdef NONMATCHING_C
  s32 mode = VM_GetNamedArgValue('m', 1);
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL && (p->unk_d6 & ELEVATOR_UNK_1)) {
      p->state = 2;
      if (mode == 4) {
        p->flags = (p->flags & ~ELEVATOR_UNK_1) | mode;
      } else {
        p->flags &= ~ELEVATOR_UNK_2;
        if (mode == 2) {
          p->flags |= mode;
        } else {
          p->flags &= ~ELEVATOR_UNK_1;
        }

        FUN_081d21d8(p);
      }
    }
  }
#else
  INCFUNC("asm/func/Elevator_Start.inc");
#endif
}

void FUN_081d5268(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    p->unk_d6 = VM_GetNamedArgValue('m', -1);
  }
}

// 残差はビット判定を 0/1 の値に起こす分だけ (src/elevator.c の ElevatorController_AllocSlot と同じ現象)
NON_MATCH void Elevator_Destroy(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);
    Elevator* q = gElevator;

    if (Elevator_TestFlags(p, ELEVATOR_TILEOVERRIDE)) {
      Map_RemoveTileOverride(&p->tileOverride);
      Elevator_ClearFlags(p, ELEVATOR_TILEOVERRIDE);
    }

    Elevator_RemoveTileOverrides(p);
    Mover_Unlink(&p->hitbox);
    p->id = 0;
    p->state = 6;
    AuxSprite_Remove(&p->sprite);
    q->usedMask &= ~(1 << p->slotIdx);
    p->slotIdx = 0xFFFF;
  }
#else
  INCFUNC("asm/func/Elevator_Destroy.inc");
#endif
}

// '.n' のエレベータに '.r' の経路をたどらせる
// 残差3命令 (57/60): 原典は 0 の定数を変数ごとに作り直すが, agbcc は1つの 0 を使い回す
NON_MATCH void FUN_081d5340(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);
    u32 pathIdx = 0;
    u32 unk = 0;
    u32 nodeIdx = 0;

    if (VM_SeekToNamedArg('r')) {
      if (VM_GetPC() != NULL) {
        pathIdx = (u8)VM_GetValue();
      } else {
        pathIdx = 0;
      }

      unk = 0;
      if (VM_GetPC() != NULL) {
        nodeIdx = (u8)VM_GetValue();
      } else {
        nodeIdx = 0;
      }
    }

    Map_InitPathWalker(&p->pathWalker, pathIdx, unk, nodeIdx);
    p->hitbox.path = &p->pathWalker;
  }
#else
  INCFUNC("asm/func/FUN_081d5340.inc");
#endif
}

// VM: 指定した id のエレベータのパレットを差し替える
void Elevator_SetPltt(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevator != NULL && id != 0) {
    ElevatorUnkData* p = Elevator_FindByID(id);

    if (p != NULL) {
      s32 plttID = VM_GetNamedArgValue('c', 0);

      Video_SetAuxSpritePltt(&p->gfx, plttID + 439);
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
  gPlayerPtr[0]->shadow.flags &= ~1;
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
