#include "coffin.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef u16 ElevatorFlags;                // Elevator.flags
#define ELEVATOR_TILEOVERRIDE (1 << 0)    // tileOverride を登録済み
#define ELEVATOR_UNK_1 (1 << 1)           // Elevator_Start が '.m=2' のとき立てる
#define ELEVATOR_UNK_2 (1 << 2)           // Elevator_Start が '.m=4' のとき立てる
#define PLAYER_RIDING (1 << 3)            // プレイヤーが乗っている, ElevatorManager.ridingID と対
#define COFFIN_RIDING (1 << 4)            // 棺桶が乗っている, FUN_081d3fac が第2引数で落とし分ける
#define ELEVATOR_SHAKE (1 << 5)           // 揺らす, Cmd_ShakeElevator が立てて Elevator_UpdateShake が落とす
#define ELEVATOR_UNK_7 (1 << 7)           // 立っていると Elevator_UpdateShake が揺らさずにフラグだけ落とす
#define ELEVATOR_UNK_8 (1 << 8)           // 立っていると FUN_081d4590 がプレイヤーを運ばずにフラグだけ落とす
#define ELEVATOR_UNK_9 (1 << 9)           // FUN_081d4658 が見て落とす
#define ELEVATOR_TILEOVERRIDES (1 << 11)  // tileOverrides[] を登録済み
#define ELEVATOR_FLAG_12 (1 << 12)        // まだ不明

struct Elevator;
typedef void ElevatorFunc(struct Elevator* e);

// このゲームには、水平方向と垂直方向に動く床が存在するが、これがどっちも担うのかはまだ不明
// 水平方向 は 移動床, 垂直方向 は 昇降床　と呼ぶようにすること
typedef struct Elevator {
  AuxSprite sprite;                  // 0x000
  AuxSpriteGfx gfx;                  // 0x02C, e.g. SPRITE_LIFT_IRON
  u8 unk_48[0x058 - 0x048];          // 0x048
  Vec3 unk_58;                       // 0x058, FUN_081d4540 が ClearMemory で 0 にする, FUN_081d4658 が棺桶の座標に足す
  u8 unk_60[0x0B0 - 0x060];          // 0x060
  s16 slotIdx;                       // 0x0B0, ElevatorManager_AllocSlot が確保したスロット番号, 解放時は 0xFFFF
  s16 state;                         // 0x0B2, sElevatorUpdates の添字, 6 はスキップ
  ElevatorFlags flags;               // 0x0B4, see ElevatorFlags
  u8 unk_b6;                         // 0x0B6, Elevator_UpdateState1 が到着時に 1 を入れる
  u8 unk_b7[0x0BA - 0x0B7];          // 0x0B7
  s16 unk_ba;                        // 0x0BA, Cmd_15ED が '.s=6' を入れる
  u8 unk_bc[0x0C6 - 0x0BC];          // 0x0BC
  s16 unk_c6;                        // 0x0C6, 負の間だけ sprite.pos.y に足されて半分ずつ減る沈み込み量
  u16 unk_c8;                        // 0x0C8, FUN_081d21d8 が 0〜3 と比較して効果音を選ぶ
  u8 unk_ca[0x0CC - 0x0CA];          // 0x0CA
  s32 unk_cc;                        // 0x0CC, Cmd_CED9 が '.l' の値 (正のときだけ) を入れる
  s32 unk_d0;                        // 0x0D0, Cmd_CED9 が '.h' の値 (正のときだけ) を入れる
  u16 id;                            // 0x0D4, Elevator_FindByID が Player.elevatorID や '.n' の値と比較して探す
  u16 unk_d6;                        // 0x0D6, '.m', FUN_081d21d8 / FUN_081d2a64 が bit2,bit5 を見る
  ElevatorFunc* unk_d8;              // 0x0D8, ElevatorManager_Update が毎フレーム呼ぶ
  ElevatorFunc* unk_dc;              // 0x0DC
  ElevatorFunc* unk_e0;              // 0x0E0
  u8 unk_e4;                         // 0x0E4, Elevator_Create が VM 値を入れる
  u8 unk_e5;                         // 0x0E5
  u8 unk_e6;                         // 0x0E6, Elevator_Create が VM 値を入れて Map_GetPathNodePos に渡す
  u8 unk_e7;                         // 0x0E7, FUN_081d2a64 が 0/1/3 で走行音を出し分ける
  PathWalker pathWalker;             // 0x0E8, mover.path がここを指す, Cmd_5D74 が '.r' の経路で初期化する
  Mover mover;                       // 0x0F4, pos を x-0x100 して sprite.pos にコピーする
  MapTileOverride tileOverride;      // 0x138, flags bit0 が立っているときだけ有効
  MapTileOverride tileOverrides[4];  // 0x148, flags bit11 が立っているときだけ有効
  bool8 tileOverrideActive[4];       // 0x188, tileOverrides[i] の登録有無
} Elevator;
static_assert(sizeof(Elevator) == 396);

typedef struct {
  Entity e;                      // 0x0000, ENTITY_UNK_5
  AuxAnimFile* animFile;         // 0x0018, ANIM_13F9
  Elevator elevators[12];        // 0x001C
  u32 usedMask;                  // 0x12AC, スロット i を確保すると bit i が立つ
  u16 ridingID;                  // 0x12B0, 搭乗中のエレベータの id, 降りると 0
  u16 unk_12b2;                  // 0x12B2, ridingID と同じ作り, FUN_081d4704 / FUN_081d42c4 が 0x03002C00 の乗り手について持つ
  bool8 soundPlaying;            // 0x12B4, 走行音を鳴らしているか
  u8 unk_12b5[0x12B8 - 0x12B5];  // 0x12B5
} ElevatorManager;
static_assert(sizeof(ElevatorManager) == 4792);

IWRAM_DATA ElevatorManager* gElevatorManager = NULL;  // 0x03000194

// エレベータが乗り手との距離を測るときの許容範囲 (±), Elevator_FindAtPos ほかが引く
const Vec3 gElevatorRanges[3] = {
    {Q8(0.5),   Q8(0.125), Q8(0.5)  },
    {Q8(0.5),   Q8(0.125), Q8(0.5)  },
    {Q8(0.383), Q8(0.125), Q8(0.383)}
};  // 0x085AE0D0

bool32 FUN_08086978(u32 mask);
void FUN_081d4590(Elevator* e);
void FUN_081d4658(Elevator* e);
void FUN_081d5588(Elevator* e);

static inline void Vec3_Delta(Vec3* out, Vec3* origin, Vec3* target) {
  out->x = target->x - origin->x;
  out->y = target->y - origin->y;
  out->z = target->z - origin->z;
}

static inline bool8 Elevator_IsSlotUsed(ElevatorManager* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

static inline void Elevator_FreeSlot(ElevatorManager* p, s32 i) { p->usedMask &= ~(1 << i); }

static inline bool8 Elevator_TestFlags(Elevator* e, ElevatorFlags bits) {
  if (TEST_FLAGS(e->flags, bits)) return TRUE;
  return FALSE;
}

// unk_c8 の種類ごとに走行音を鳴らす
void FUN_081d21d8(Elevator* e) {
  if (!(e->unk_d6 & 4)) {
    switch (e->unk_c8) {
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
        if (e->unk_d6 & 0x20) {
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

NAKED Elevator* Elevator_FindAtPos(Vec3* pos) { INCFUNC("asm/func/Elevator_FindAtPos.inc"); }

// 空いているスロットを1つ確保して返す, 全部埋まっていれば NULL
// 残差はビット判定を 0/1 の値に起こす分だけ: 原典は (flags & bits) を movs 1 / movs 0 で値にしてから test するが, agbcc はどう書いても分岐に畳む
// Tier A-B 試済: static inline の if/else, ローカルの bool32 受け, != 0, == FALSE, !!(...), static (非 inline) は bl が出て不可
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出る (39/39) が, ループ外に置く定数とポインタの順が原典と違う
NON_MATCH Elevator* ElevatorManager_AllocSlot(ElevatorManager* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Elevator_IsSlotUsed(p, i)) {
      p->usedMask |= 1 << i;
      p->elevators[i].slotIdx = i;
      return &p->elevators[i];
    }
  }

  return NULL;
#else
  INCFUNC("asm/func/ElevatorManager_AllocSlot.inc");
#endif
}

NAKED void FUN_081d2368(Elevator* e) { INCFUNC("asm/func/FUN_081d2368.inc"); }

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
    vx = POLAR_X(speed, angle);
    vz = POLAR_Z(speed, angle);
    mover->pos.x += vx;
    mover->pos.z += vz;
    out->x = vx;
    out->z = vz;
  }

  return FALSE;
}

void FUN_081d276c(Elevator* e) {
  ElevatorManager* p = gElevatorManager;
  s32 i;

  for (i = 0; i < 1; i++) {
    Player* player = gPlayerPtr[i];

    if (player != NULL && e->id == p->ridingID) {
      player->mover.tile = (e->state == 3 || e->state == 4) ? &player->tile : NULL;
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

  if (gPlayerPtr[0]->action != PACT_PULL_COFFIN) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_081d27c8.inc");
#endif
}

void Elevator_UpdateState0(Elevator* e) {}

NAKED void Elevator_UpdateState2(Elevator* e) { INCFUNC("asm/func/Elevator_UpdateState2.inc"); }

// 目的地に着いていたら状態3へ進め, まだなら移動を続ける
void Elevator_UpdateState1(Elevator* e) {
  if (FUN_081d2698(&e->mover, &e->pathWalker, &e->unk_58, e->unk_ba, e->unk_ba, e->unk_ba)) {
    e->state = 3;
    e->unk_b6 = 1;
    FUN_081d5588(e);
  } else {
    FUN_081d2368(e);
  }
}

NAKED void FUN_081d2a64(ElevatorManager* p) { INCFUNC("asm/func/FUN_081d2a64.inc"); }

void FUN_081d2c10(void) {
  WorldPos pos = gPlayerPtr[0]->mover.pos;

  pos.x += 0x80;
  FUN_0807a91c(gPlayerPtr[0], &pos);
  Coffin_CopyPos(&pos);
  pos.x += 0x80;
  FUN_08086a4c(&pos);
}

// プレイヤーがこのエレベータの上にいるか
bool32 FUN_081d2c60(Elevator* e) {
  if (gPlayerPtr[0] != NULL) {
    Vec3 d;
    Vec3_Delta(&d, &e->mover.pos, &gPlayerPtr[0]->mover.pos);

    if (d.x <= gElevatorRanges[0].x && d.x >= -gElevatorRanges[0].x && d.y <= gElevatorRanges[0].y && d.y >= -gElevatorRanges[0].y && d.z <= gElevatorRanges[0].z && d.z >= -gElevatorRanges[0].z) {
      return TRUE;
    }
  }

  return FALSE;
}

NAKED void Elevator_UpdateState4(Elevator* e) { INCFUNC("asm/func/Elevator_UpdateState4.inc"); }

// 沈み込みを戻しつつ, 揺れフラグが立っていればスプライト位置を乱数で揺らす
// 残差11命令 (81/92): Cmd_7A75 と同じく, 原典は flags 判定を分岐で 0/1 に起こしてから cmp で読み直す (2箇所)
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (93/92)
NON_MATCH void Elevator_UpdateShake(Elevator* e) {
#ifdef NONMATCHING_C
  if (e->unk_c6 < 0) {
    e->sprite.pos.y += e->unk_c6;
    e->unk_c6 = Div(e->unk_c6, 2);
  }

  if (!Elevator_TestFlags(e, ELEVATOR_UNK_7)) {
    if (!Elevator_TestFlags(e, ELEVATOR_SHAKE)) {
      return;
    }

    e->sprite.pos.x += Mod(Random(), 12) - 6;
    e->sprite.pos.y += Random() & 3;
    e->sprite.pos.z += Mod(Random(), 12) - 6;
  }

  e->flags &= ~(ELEVATOR_TILEOVERRIDE | ELEVATOR_SHAKE);
#else
  INCFUNC("asm/func/Elevator_UpdateShake.inc");
#endif
}

NAKED void Elevator_UpdateState3(Elevator* e) { INCFUNC("asm/func/Elevator_UpdateState3.inc"); }

void Elevator_UpdateState5(Elevator* e) {}

void Elevator_UpdateState6(Elevator* e) {}

// id が一致する要素を探す
Elevator* Elevator_FindByID(s32 id) {
  ElevatorManager* p = gElevatorManager;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (p->elevators[i].id == id) {
      return &p->elevators[i];
    }
  }

  return NULL;
}

// プレイヤーが乗っているエレベータを探す
Elevator* Elevator_FindRiding(void) {
  ElevatorManager* p = gElevatorManager;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (p->ridingID == p->elevators[i].id) {
      return &p->elevators[i];
    }
  }

  return NULL;
}

// 登録してあった上書きタイルを全部外す
void Elevator_RemoveTileOverrides(Elevator* e) {
  if (Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDES)) {
    s32 i;

    for (i = 0; i < 4; i++) {
      if (e->tileOverrideActive[i]) {
        Map_RemoveTileOverride(&e->tileOverrides[i]);
        e->tileOverrideActive[i] = 0;
      }
    }

    CLEAR_FLAGS(e->flags, ELEVATOR_TILEOVERRIDES);
  }
}

NAKED void Elevator_UpdateTileOverrides(Elevator* e) { INCFUNC("asm/func/Elevator_UpdateTileOverrides.inc"); }

NAKED void FUN_081d33f8(Elevator* e) { INCFUNC("asm/func/FUN_081d33f8.inc"); }

// tileIdx の上書きタイルを登録しているエレベータがあるかどうか
bool32 FUN_081d34e8(s32 tileIdx) {
  ElevatorManager* p = gElevatorManager;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Elevator_TestFlags(&p->elevators[i], ELEVATOR_TILEOVERRIDE) && p->elevators[i].tileOverride.tileIdx == tileIdx) {
      return TRUE;
    }
  }

  return FALSE;
}

NAKED void FUN_081d3534(Elevator* e) { INCFUNC("asm/func/FUN_081d3534.inc"); }

NAKED void FUN_081d36c0(Elevator* e) { INCFUNC("asm/func/FUN_081d36c0.inc"); }

NAKED void FUN_081d38a4(Elevator* e) { INCFUNC("asm/func/FUN_081d38a4.inc"); }

NAKED void FUN_081d3a8c(Elevator* e) { INCFUNC("asm/func/FUN_081d3a8c.inc"); }

NAKED void FUN_081d3c24(Elevator* e) { INCFUNC("asm/func/FUN_081d3c24.inc"); }

NAKED void FUN_081d3dd0(Elevator* e) { INCFUNC("asm/func/FUN_081d3dd0.inc"); }

// 残差はビット判定を 0/1 の値に起こす分だけ (src/elevator.c の ElevatorManager_AllocSlot と同じ現象)
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (62/63)
NON_MATCH void FUN_081d3fac(s32 id, s32 which) {
#ifdef NONMATCHING_C
  ElevatorManager* p = gElevatorManager;
  s32 i;

  if (p->usedMask != 0) {
    for (i = 0; i < 12; i++) {
      if (Elevator_IsSlotUsed(p, i) && p->elevators[i].id == id) {
        if (which == 0) {
          p->elevators[i].flags &= ~PLAYER_RIDING;
        } else {
          p->elevators[i].flags &= ~COFFIN_RIDING;
        }
        return;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d3fac.inc");
#endif
}

void FUN_081d4034(Elevator* e) {
  if (e->state != 3 && e->state != 4) {
    FUN_0807a97c(gPlayerPtr[0], 5, e->id);
  } else {
    FUN_0807a97c(gPlayerPtr[0], 1, e->id);
    FUN_0807a99c(gPlayerPtr[0], 4);
  }
}

void FUN_081d407c(Elevator* e) {
  if (e->state != 3 && e->state != 4) {
    FUN_080869c8(7, e->id);
  } else {
    FUN_080869c8(3, e->id);
    FUN_080869f8(4);
  }
}

NAKED void FUN_081d40b4(Elevator* e) { INCFUNC("asm/func/FUN_081d40b4.inc"); }

NAKED void FUN_081d42c4(Elevator* e) { INCFUNC("asm/func/FUN_081d42c4.inc"); }

NAKED void FUN_081d43d4(Vec3* a, Vec3* b, Elevator* e) { INCFUNC("asm/func/FUN_081d43d4.inc"); }

void FUN_081d4540(Elevator* e) {
  if (gPlayerPtr[0] != NULL) {
    FUN_081d40b4(e);
    FUN_081d42c4(e);

    if (FUN_0807a954(gPlayerPtr[0], 1)) {
      FUN_081d4590(e);
    }
    if (FUN_08086978(1)) {
      FUN_081d4658(e);
    }

    ClearMemory(&e->unk_58, sizeof(e->unk_58));
  }
}

// 乗っているプレイヤーをエレベータの移動ぶんだけ運ぶ
// 残差10命令 (74/84): Cmd_7A75 と同じく, 原典は flags 判定を分岐で 0/1 に起こしてから cmp で読み直す
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (83/84)
NON_MATCH void FUN_081d4590(Elevator* e) {
#ifdef NONMATCHING_C
  ElevatorManager* p = gElevatorManager;

  if (gPlayerPtr[0] == NULL) {
    return;
  }
  if (e->id != p->ridingID) {
    return;
  }

  if (!Elevator_TestFlags(e, ELEVATOR_UNK_8)) {
    Vec3 v;

    v.x = e->unk_58.x + gPlayerPtr[0]->mover.pos.x;
    v.y = e->unk_58.y + gPlayerPtr[0]->mover.pos.y;
    v.z = e->unk_58.z + gPlayerPtr[0]->mover.pos.z;
    FUN_081d43d4(&v, &gPlayerPtr[0]->mover.pos, e);
    FUN_0807a91c(gPlayerPtr[0], &v);
  }

  e->flags &= ~ELEVATOR_UNK_8;
#else
  INCFUNC("asm/func/FUN_081d4590.inc");
#endif
}

// 乗っている棺桶をエレベータの移動ぶんだけ動かす
// 残差23命令 (54/77): 原典は棺桶と mover.pos の差分を Vec3 に組み立てるがどこからも読まないので agbcc が消す, 加えて flags 判定の 0/1 起こしも畳まれる
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (60/77)
NON_MATCH void FUN_081d4658(Elevator* e) {
#ifdef NONMATCHING_C
  if (gElevatorManager->unk_12b2 == e->id) {
    WorldPos pos;
    WorldPos delta;

    Coffin_CopyPos(&pos);
    delta.x = pos.x - e->mover.pos.x;
    delta.y = pos.y - e->mover.pos.y;
    delta.z = pos.z - e->mover.pos.z;

    if (!Elevator_TestFlags(e, ELEVATOR_UNK_9)) {
      pos.x = e->unk_58.x + pos.x;
      pos.y = pos.y + e->unk_58.y;
      pos.z = e->unk_58.z + pos.z;
      FUN_08086a4c(&pos);
    }

    e->flags &= ~ELEVATOR_UNK_9;
  }
#else
  INCFUNC("asm/func/FUN_081d4658.inc");
#endif
}

// 棺桶がエレベータの許容範囲に収まっていたら乗り手として登録する
// 残差13命令 (92/79): 原典は差分 Vec3 をスタックに置いて s16 で読み直すが, agbcc はレジスタに畳んで半語を詰め替える
// Tier A-C は試済: 2要素の WorldPos 配列にするとメモリには乗るが 87 で一致せず
NON_MATCH void FUN_081d4704(ElevatorManager* p, Elevator* e) {
#ifdef NONMATCHING_C
  if (e->unk_e7 == 2) {
    WorldPos pos;
    WorldPos delta;

    Coffin_CopyPos(&pos);
    delta.x = pos.x - e->mover.pos.x;
    delta.y = pos.y - e->mover.pos.y;
    delta.z = pos.z - e->mover.pos.z;

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

    FUN_08086a4c(&e->mover.pos);
    FUN_081d3fac(p->unk_12b2, 1);
    p->unk_12b2 = e->id;
    FUN_080869c8(3, e->id);
    e->flags |= COFFIN_RIDING;
  }
#else
  INCFUNC("asm/func/FUN_081d4704.inc");
#endif
}

// 0xA4FC
NAKED void Elevator_Create(void) { INCFUNC("asm/func/Elevator_Create.inc"); }

void (*const sElevatorUpdates[7])(Elevator*) = {
    Elevator_UpdateState0,
    Elevator_UpdateState1,
    Elevator_UpdateState2,
    Elevator_UpdateState3,
    Elevator_UpdateState4,
    Elevator_UpdateState5,
    Elevator_UpdateState6,
};  // 0x085AE0E8

// 残差は usedMask のアドレスをループ外に括り出すかどうかのみ (原典は毎周 p+0x12AC を作り直す), Tier A-C は試済 (e の持ち方, ネスト, TEST_FLAGS/& の書き分け)
NON_MATCH s32 ElevatorManager_Update(ElevatorManager* p) {
#ifdef NONMATCHING_C
  Elevator* elevators = p->elevators;
  s32 i;

  if (p->usedMask == 0) return 0;

  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    sound_08240740(SONG_344);
    sound_08240740(SONG_609);
    sound_08240740(SONG_649);
    sound_08240740(SONG_650);
    sound_08240740(SONG_648);
    return 0;
  }

  if ((gEntityDisableFlags & ENTITY_DISABLE_3)) return 0;

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i) && elevators[i].state != 6) {
      elevators[i].unk_d8(&elevators[i]);
      sElevatorUpdates[elevators[i].state](&elevators[i]);
      elevators[i].unk_dc(&elevators[i]);
      elevators[i].unk_e0(&elevators[i]);
      Elevator_UpdateTileOverrides(&elevators[i]);
      FUN_081d4540(&elevators[i]);
      FUN_081d276c(&elevators[i]);
      elevators[i].sprite.pos = elevators[i].mover.pos;
      elevators[i].sprite.pos.x -= Q8(1);
      Elevator_UpdateShake(&elevators[i]);
    }
  }

  FUN_081d2a64(p);
  return 0;
#else
  INCFUNC("asm/func/ElevatorManager_Update.inc");
#endif
}

// 走行音を止め, 使用中のスロットの上書きタイル・Mover・スプライトを片付ける
// 残差7命令 (69/76): Cmd_7A75 と同じく, 原典は使用中判定と flags 判定を分岐で 0/1 に起こしてから cmp で読み直す
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出る (76/76) が, 原典は &usedMask をマスクより先に作る
NON_MATCH s32 ElevatorManager_Destroy(ElevatorManager* p) {
#ifdef NONMATCHING_C
  s32 i;

  sound_08240740(SONG_344);
  sound_08240740(SONG_609);
  sound_08240740(SONG_649);
  sound_08240740(SONG_650);
  sound_08240740(SONG_648);

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i)) {
      Elevator* e = &p->elevators[i];

      if (Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDE)) {
        Map_RemoveTileOverride(&e->tileOverride);
      }

      Elevator_RemoveTileOverrides(e);
      Mover_Unlink(&e->mover);
      AuxSprite_Remove(&e->sprite);
    }
  }

  gElevatorManager = NULL;
  return 0;
#else
  INCFUNC("asm/func/ElevatorManager_Destroy.inc");
#endif
}

s32 ElevatorManager_Init(ElevatorManager* p) {
  p->animFile = GetFile(DIR_ANIMATION, ANIM_13F9);
  gElevatorManager = p;
  p->usedMask = 0;
  return 0;
}

ElevatorManager* ElevatorManager_Create(void) {
  ElevatorManager* p;

  if (gElevatorManager != NULL) {
    return gElevatorManager;
  }

  p = CreateEntity(ENTITY_UNK_5, sizeof(ElevatorManager));
  if (p != NULL) {
    SetEntityRoutine(p, ElevatorManager_Update, ElevatorManager_Destroy);
    if (ElevatorManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void ElevatorManager_ClearPtr(void) { gElevatorManager = NULL; }

// 0xB1C4, 指定した id のエレベータを揺らす
void Cmd_ShakeElevator(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);
    if (e != NULL) {
      SET_FLAGS(e->flags, ELEVATOR_SHAKE);
    }
  }
}

// 0x7A75, 棺桶が乗っているエレベータの id を返す, 見つからなければ -1
// 残差7命令 (52/59): 原典は使用中判定と flags 判定を分岐で 0/1 に起こし, 要素と &flags を別々の誘導ポインタで回す
// Tier A-C は試済: 要素をポインタで走査する形 (無影響)
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (65/59)
NON_MATCH s32 Cmd_7A75(void) {
#ifdef NONMATCHING_C
  ElevatorManager* p = gElevatorManager;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  if (p->usedMask == 0) {
    return -1;
  }
  if (!FUN_08086978(1)) {
    return -1;
  }

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i) && Elevator_TestFlags(&p->elevators[i], COFFIN_RIDING)) {
      return p->elevators[i].id;
    }
  }

  return -1;
#else
  INCFUNC("asm/func/Cmd_7A75.inc");
#endif
}

// 0x7E33, 指定した id のエレベータを動かす, '.m' で動かし方を選ぶ
// 残差は割当だけ (61対61): 原典は定数 2 を r6 に置いて ~2 を mvns で作り, mode の値も r4 に残すが, こちらは ~2 をプール定数にして mode を 4 に伝播させる
NON_MATCH void Elevator_Start(void) {
#ifdef NONMATCHING_C
  s32 mode = VM_GetNamedArgValue('m', 1);
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);

    if (e != NULL && (e->unk_d6 & ELEVATOR_UNK_1)) {
      e->state = 2;
      if (mode == 4) {
        e->flags = (e->flags & ~ELEVATOR_UNK_1) | mode;
      } else {
        e->flags &= ~ELEVATOR_UNK_2;
        if (mode == 2) {
          e->flags |= mode;
        } else {
          e->flags &= ~ELEVATOR_UNK_1;
        }

        FUN_081d21d8(e);
      }
    }
  }
#else
  INCFUNC("asm/func/Elevator_Start.inc");
#endif
}

void Cmd_AE3A(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);

    e->unk_d6 = VM_GetNamedArgValue('m', -1);
  }
}

void Elevator_Destroy(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);
    ElevatorManager* p = gElevatorManager;

    if (Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDE)) {
      Map_RemoveTileOverride(&e->tileOverride);
      CLEAR_FLAGS(e->flags, ELEVATOR_TILEOVERRIDE);
    }

    Elevator_RemoveTileOverrides(e);
    Mover_Unlink(&e->mover);
    e->id = 0;
    e->state = 6;
    AuxSprite_Remove(&e->sprite);
    Elevator_FreeSlot(p, e->slotIdx);
    e->slotIdx = 0xFFFF;
  }
}

// 0x5D74, '.n' のエレベータに '.r' の経路をたどらせる
// 残差3命令 (57/60): 原典は 0 の定数を変数ごとに作り直すが, agbcc は1つの 0 を使い回す
NON_MATCH void Cmd_5D74(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);
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

    Map_InitPathWalker(&e->pathWalker, pathIdx, unk, nodeIdx);
    e->mover.path = &e->pathWalker;
  }
#else
  INCFUNC("asm/func/Cmd_5D74.inc");
#endif
}

// VM: 指定した id のエレベータのパレットを差し替える
void Elevator_SetPltt(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);

    if (e != NULL) {
      s32 plttID = VM_GetNamedArgValue('c', 0);

      Video_SetAuxSpritePltt(&e->gfx, plttID + 439);
    }
  }
}

// 0x15ED
void Cmd_15ED(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);

    if (e != NULL) {
      e->unk_ba = VM_GetNamedArgValue('s', 6);
    }
  }
}

// 0x5844, プレイヤーをエレベータから降ろす
void Cmd_5844(void) {
  ElevatorManager* p = gElevatorManager;
  Elevator* e = Elevator_FindRiding();

  p->ridingID = 0;
  gPlayerPtr[0]->mover.tile = &gPlayerPtr[0]->tile;
  FUN_0807a99c(gPlayerPtr[0], 1);
  CLEAR_FLAGS(e->flags, PLAYER_RIDING);
  gPlayerPtr[0]->shadow.flags &= ~1;
}

// 0xCED9
void Cmd_CED9(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);

    if (e != NULL) {
      s32 h = VM_GetNamedArgValue('h', -1);
      s32 l = VM_GetNamedArgValue('l', -1);
      if (h > 0) e->unk_d0 = h;
      if (l > 0) e->unk_cc = l;
    }
  }
}

// 0x0BCE
void Cmd_0BCE(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (gElevatorManager != NULL && id != 0) {
    Elevator* e = Elevator_FindByID(id);
    if (e != NULL) {
      CLEAR_FLAGS(e->flags, ELEVATOR_FLAG_12);
    }
  }
}

Vec3* Elevator_GetPosByID(s32 id) {
  Elevator* e;

  if (gElevatorManager == NULL || id == 0) {
    return NULL;
  }

  e = Elevator_FindByID(id);
  if (e == NULL) {
    return NULL;
  }

  return &e->mover.pos;
}

Vec3* Elevator_GetPos(Elevator* e) {
  if (gElevatorManager == NULL) {
    return NULL;
  }

  return &e->mover.pos;
}

NAKED void FUN_081d5588(Elevator* e) { INCFUNC("asm/func/FUN_081d5588.inc"); }
