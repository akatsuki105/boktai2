#include "coffin.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef u16 ElevatorFlags;                 // Elevator.flags
#define ELEVATOR_TILEOVERRIDE (1 << 0)     // tileOverride を登録済み
#define ELEVATOR_MOVE_UP (1 << 1)          // 上に動く, Elevator_Start が '.m=2' のとき立て '.m=1' のとき落とす
#define ELEVATOR_STOPPED (1 << 2)          // 止まっている, Elevator_Start が '.m=4' のとき立てる
#define PLAYER_RIDING (1 << 3)             // プレイヤーが乗っている, ElevatorManager.ridingID と対
#define COFFIN_RIDING (1 << 4)             // 棺桶が乗っている, FUN_081d3fac が第2引数で落とし分ける
#define ELEVATOR_SHAKE (1 << 5)            // 揺らす, Cmd_ShakeElevator が立てて Elevator_UpdateShake が落とす
#define ELEVATOR_UNK_7 (1 << 7)            // 立っていると Elevator_UpdateShake が揺らさずにフラグだけ落とす
#define ELEVATOR_RIDER_KNOCKBACK (1 << 8)  // プレイヤーを弾き返した, 立っていると FUN_081d4590 がプレイヤーを運ばずにフラグだけ落とす
#define ELEVATOR_UNK_9 (1 << 9)            // FUN_081d4658 が見て落とす
#define ELEVATOR_TILEOVERRIDES (1 << 11)   // tileOverrides[] を登録済み
#define ELEVATOR_FLAG_12 (1 << 12)         // まだ不明

struct Elevator;
typedef void ElevatorFunc(struct Elevator* e);

// このゲームには、水平方向と垂直方向に動く床が存在するが、これがどっちも担うのかはまだ不明
// 水平方向 は 移動床, 垂直方向 は 昇降床　と呼ぶようにすること
typedef struct Elevator {
  AuxSprite sprite;                  // 0x000
  AuxSpriteGfx gfx;                  // 0x02C, e.g. SPRITE_LIFT_IRON
  u8 unk_48[0x058 - 0x048];          // 0x048
  Vec3 moveDelta;                    // 0x058, そのフレームに動いた量, 乗っているプレイヤーや棺桶の座標に足して一緒に運ぶ
  u8 unk_60[0x0B0 - 0x060];          // 0x060
  s16 slotIdx;                       // 0x0B0, ElevatorManager_AllocSlot が確保したスロット番号, 解放時は 0xFFFF
  s16 state;                         // 0x0B2, sElevatorUpdates の添字, 6 はスキップ
  ElevatorFlags flags;               // 0x0B4, see ElevatorFlags
  bool8 arrived;                     // 0x0B6, ノードに着いたら 1, 到着時のスクリプトを呼ぶと 0 に戻る
  u8 unk_b7;                         // 0x0B7
  s16 waitTimer;                     // 0x0B8, プレイヤーが乗ってからのフレーム数, waitTime に達すると動き出す
  s16 speed;                         // 0x0BA, '.s=6', 1フレームに動く量
  u16 waitTime;                      // 0x0BC, '.w=120', プレイヤーが乗ってから動き出すまでのフレーム数
  u16 unk_be;                        // 0x0BE
  u16 unk_c0;                        // 0x0C0, '.p', 乗っているプレイヤーが足場を外れて水の上に出たら呼ぶスクリプト
  u16 arriveScriptID;                // 0x0C2, '.R', プレイヤーが乗っているときノードに着いたら呼ぶスクリプト
  u16 departScriptID;                // 0x0C4, '.S', プレイヤーが乗っているときノードを離れたら呼ぶスクリプト
  s16 sinkY;                         // 0x0C6, プレイヤーが乗った瞬間に -32 が入り, 負の間だけ sprite.pos.y に足されて半分ずつ減る沈み込み量
  u16 unk_c8;                        // 0x0C8, '.T', FUN_081d21d8 が 0〜3 と比較して効果音を選ぶ
  u8 unk_ca[0x0CC - 0x0CA];          // 0x0CA
  s32 minY;                          // 0x0CC, '.l', 昇降床が下りる下限の高さ
  s32 maxY;                          // 0x0D0, '.h', 昇降床が上る上限の高さ
  u16 id;                            // 0x0D4, Elevator_FindByID が Player.elevatorID や '.n' の値と比較して探す
  u16 unk_d6;                        // 0x0D6, '.m', bit0 が立つと乗って waitTime たつと動き出す, bit1 が立つと昇降床, bit2 が立つと音を鳴らさない, bit4 が立つとプレイヤーが乗っていなくても走行音を鳴らす, bit5 で効果音を選ぶ
  ElevatorFunc* unk_d8;              // 0x0D8, ElevatorManager_Update が毎フレーム呼ぶ
  ElevatorFunc* unk_dc;              // 0x0DC
  ElevatorFunc* unk_e0;              // 0x0E0
  u8 unk_e4;                         // 0x0E4, Elevator_Create が VM 値を入れる
  u8 unk_e5;                         // 0x0E5
  u8 unk_e6;                         // 0x0E6, Elevator_Create が VM 値を入れて Map_GetPathNodePos に渡す
  u8 unk_e7;                         // 0x0E7, ElevatorManager_UpdateSound が 0/1/3 で走行音を出し分ける
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
  u16 coffinRidingID;            // 0x12B2, 棺桶が乗っているエレベータの id, 降りると 0
  bool8 soundPlaying;            // 0x12B4, 走行音を鳴らしているか
  u8 unk_12b5[0x12B8 - 0x12B5];  // 0x12B5
} ElevatorManager;
static_assert(sizeof(ElevatorManager) == 4792);

IWRAM_DATA ElevatorManager* gElevatorManager = NULL;  // 0x03000194

// エレベータが乗り手との距離を測るときの許容範囲 (±)
const Vec3 gElevatorRange0 = {Q8(0.5), Q8(0.125), Q8(0.5)};      // 0x085AE0D0
const Vec3 gElevatorRange1 = {Q8(0.5), Q8(0.125), Q8(0.5)};      // 0x085AE0D8, Elevator_ClampRiderPos が unk_e7 == 1 のときに使う
const Vec3 gElevatorRange2 = {Q8(0.383), Q8(0.125), Q8(0.383)};  // 0x085AE0E0, 棺桶用

bool32 FUN_08086978(u32 mask);
Elevator* Elevator_FindByID(s32 id);
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

// 残差は p と添字オフセットの r8/r9 入れ替えと, 先頭で作った &usedMask をループで使い回さない点のみ (110/108), Tier A-C は試済 (早期 return の形, 宣言順, グローバル直参照)
NON_MATCH Elevator* Elevator_FindAtPos(Vec3* pos) {
#ifdef NONMATCHING_C
  ElevatorManager* p = gElevatorManager;
  s32 i;

  if (p == NULL) return NULL;
  if (p->usedMask == 0) return NULL;

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i)) {
      Vec3 delta;

      Vec3_Delta(&delta, &p->elevators[i].mover.pos, pos);
      if (delta.x <= gElevatorRange0.x && delta.x >= -gElevatorRange0.x && delta.y <= gElevatorRange0.y && delta.y >= -gElevatorRange0.y && delta.z <= gElevatorRange0.z && delta.z >= -gElevatorRange0.z) {
        return &p->elevators[i];
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/Elevator_FindAtPos.inc");
#endif
}

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
NON_MATCH bool8 FUN_081d27c8(Elevator* e) {
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

// 昇降床を speed ずつ上下に動かし, minY か maxY に着いたら止める
void Elevator_UpdateState2(Elevator* e) {
  Vec3 v;
  bool8 up;

  ClearMemory(&e->moveDelta, sizeof(Vec3));
  Vec3_Delta(&v, &e->mover.pos, &gPlayerPtr[0]->mover.pos);

  if (e->arrived) {
    FUN_081d21d8(e);
    e->arrived = FALSE;
  }

  if (Elevator_TestFlags(e, ELEVATOR_STOPPED)) return;

  up = Elevator_TestFlags(e, ELEVATOR_MOVE_UP);
  if (up) {
    e->mover.pos.y += e->speed;
    e->moveDelta.y = e->speed;
    if (e->maxY <= e->mover.pos.y) {
      e->mover.pos.y = e->maxY;
      if (FUN_0807a954(gPlayerPtr[0], 1)) {
        v = gPlayerPtr[0]->mover.pos;
        v.y = e->mover.pos.y;
        FUN_0807a91c(gPlayerPtr[0], &v);
        SET_FLAGS(e->flags, ELEVATOR_RIDER_KNOCKBACK);
        e->moveDelta.y = 0;
      }
      e->state = 4;
      e->arrived = TRUE;
      if (!(e->unk_d6 & 4)) {
        sound_08240740(SONG_344);
        sound_08240740(SONG_609);
        sound_08240740(SONG_649);
        sound_08240740(SONG_650);
        sound_08240740(SONG_648);
        PlaySound_082406e0(SONG_345);
      }
    }
  } else {
    e->mover.pos.y -= e->speed;
    e->moveDelta.y = -e->speed;
    if (e->minY >= e->mover.pos.y) {
      e->mover.pos.y = e->minY;
      if (FUN_0807a954(gPlayerPtr[0], 1)) {
        v = gPlayerPtr[0]->mover.pos;
        v.y = e->mover.pos.y;
        FUN_0807a91c(gPlayerPtr[0], &v);
        SET_FLAGS(e->flags, ELEVATOR_RIDER_KNOCKBACK);
        e->moveDelta.y = 0;
      }
      e->state = 4;
      e->arrived = TRUE;
      if (!(e->unk_d6 & 4)) {
        sound_08240740(SONG_344);
        sound_08240740(SONG_609);
        sound_08240740(SONG_649);
        sound_08240740(SONG_650);
        sound_08240740(SONG_648);
        PlaySound_082406e0(SONG_345);
      }
    }
  }
}

// 目的地に着いていたら状態3へ進め, まだなら移動を続ける
void Elevator_UpdateState1(Elevator* e) {
  if (FUN_081d2698(&e->mover, &e->pathWalker, &e->moveDelta, e->speed, e->speed, e->speed)) {
    e->state = 3;
    e->arrived = TRUE;
    FUN_081d5588(e);
  } else {
    FUN_081d2368(e);
  }
}

// 動いているエレベータに合わせて走行音を鳴らし始め, 止まったら止める
// 残差17ハンク (162/158), 原典はループ側の &elevators[i] を p+0x1C から始まる別の誘導変数に持ち, 鳴らす音の選択は2か所に展開したまま PlaySound の呼び出しだけを共有する
// Tier A-C は試済 (添字/ポインタの持ち方, 音の選択の switch 化, 停止/開始の static inline 化, unk_d6 の s16 化)
NON_MATCH void ElevatorManager_UpdateSound(ElevatorManager* p) {
#ifdef NONMATCHING_C
  bool32 riding = FALSE;
  Elevator* e;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Elevator_IsSlotUsed(p, i) && p->elevators[i].state != 6 && (p->elevators[i].unk_d6 & 0x10)) {
      if (p->elevators[i].state != 1) {
        if (p->soundPlaying == TRUE) {
          sound_08240740(SONG_648);
          sound_08240740(SONG_650);
          sound_08240740(SONG_649);
          p->soundPlaying = FALSE;
        }
      } else if (p->soundPlaying == FALSE) {
        s32 id;

        switch (p->elevators[i].unk_e7) {
          case 0: {
            id = SONG_650;
            break;
          }
          case 3: {
            id = SONG_648;
            break;
          }
          default: {
            id = SONG_649;
            break;
          }
        }
        PlaySound_082406e0(id);
        p->soundPlaying = TRUE;
      }
      return;
    }
  }

  if (FUN_0807a954(gPlayerPtr[0], 1)) riding = TRUE;

  e = Elevator_FindByID(gPlayerPtr[0]->elevatorID);
  if (e == NULL) return;
  if (e->unk_d6 & 4) return;

  if (riding) {
    if (e->state != 1) {
      if (p->soundPlaying == TRUE) {
        sound_08240740(SONG_648);
        sound_08240740(SONG_650);
        sound_08240740(SONG_649);
        p->soundPlaying = FALSE;
      }
    } else if (p->soundPlaying == FALSE) {
      s32 id;

      switch (e->unk_e7) {
        case 0: {
          id = SONG_650;
          break;
        }
        case 3: {
          id = SONG_648;
          break;
        }
        default: {
          id = SONG_649;
          break;
        }
      }
      PlaySound_082406e0(id);
      p->soundPlaying = TRUE;
    }
  } else if (p->soundPlaying == TRUE) {
    sound_08240740(SONG_648);
    sound_08240740(SONG_650);
    sound_08240740(SONG_649);
    p->soundPlaying = FALSE;
  }
#else
  INCFUNC("asm/func/ElevatorManager_UpdateSound.inc");
#endif
}

void FUN_081d2c10(void) {
  WorldPos pos = gPlayerPtr[0]->mover.pos;

  pos.x += 0x80;
  FUN_0807a91c(gPlayerPtr[0], &pos);
  Coffin_CopyPos(&pos);
  pos.x += 0x80;
  FUN_08086a4c(&pos);
}

// プレイヤーがこのエレベータの上にいるか
bool8 Elevator_IsPlayerInRange(Elevator* e) {
  if (gPlayerPtr[0] != NULL) {
    Vec3 d;
    Vec3_Delta(&d, &e->mover.pos, &gPlayerPtr[0]->mover.pos);

    if (d.x <= gElevatorRange0.x && d.x >= -gElevatorRange0.x && d.y <= gElevatorRange0.y && d.y >= -gElevatorRange0.y && d.z <= gElevatorRange0.z && d.z >= -gElevatorRange0.z) {
      return TRUE;
    }
  }

  return FALSE;
}

// 端で止まっている昇降床, プレイヤーが waitTime だけ乗っていたら逆向きに動き出す
void Elevator_UpdateState4(Elevator* e) {
  if (e->arrived) {
    ElevatorManager* p = gElevatorManager;

    if (e->id == p->ridingID && e->arriveScriptID != 0) {
      u32 argv[3];
      ScriptArgs sa;

      if (e->unk_e7 == 2) {
        if (Elevator_TestFlags(e, ELEVATOR_MOVE_UP)) {
          argv[0] = 2;
        } else {
          argv[0] = 1;
        }
      } else {
        argv[0] = e->pathWalker.nodeIdx;
      }
      argv[1] = e->mover.pos.x;
      argv[2] = e->mover.pos.z;
      sa.argc = 3;
      sa.argv = argv;
      VM_ExecByID(e->arriveScriptID, &sa);
    }
    e->arrived = FALSE;
    e->waitTimer = 1;
  }

  if (!FUN_081d27c8(e)) {
    ElevatorManager* p;
    Elevator* at;

    if (e->unk_d6 & 1) {
      if (e->waitTimer >= e->waitTime && Elevator_IsPlayerInRange(e)) {
        e->state = 2;
        if (Elevator_TestFlags(e, ELEVATOR_MOVE_UP)) {
          CLEAR_FLAGS(e->flags, ELEVATOR_MOVE_UP);
        } else {
          SET_FLAGS(e->flags, ELEVATOR_MOVE_UP);
        }
        e->waitTimer = 0;
        e->arrived = TRUE;
        p = gElevatorManager;
        if (e->id == p->ridingID && e->departScriptID != 0) {
          u32 arg = e->id;
          ScriptArgs sa;

          sa.argc = 1;
          sa.argv = &arg;
          VM_ExecByID(e->departScriptID, &sa);
        }
        return;
      }
      if (e->waitTimer > e->waitTime - 10) {
        SET_FLAGS(e->flags, ELEVATOR_SHAKE);
      }
    }

    at = Elevator_FindAtPos(&gPlayerPtr[0]->mover.pos);
    if (at != NULL) {
      if (at->id == e->id) {
        if (!Elevator_TestFlags(e, ELEVATOR_FLAG_12) && e->waitTimer == 0) {
          e->sinkY = -32;
          PlaySound_082406e0(SONG_546);
        }
        if (e->waitTimer < 32000) {
          e->waitTimer++;
        }
      }
    } else {
      e->waitTimer = 0;
      e->sinkY = 0;
    }
  }
}

// 沈み込みを戻しつつ, 揺れフラグが立っていればスプライト位置を乱数で揺らす
// 残差11命令 (81/92): Cmd_7A75 と同じく, 原典は flags 判定を分岐で 0/1 に起こしてから cmp で読み直す (2箇所)
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (93/92)
NON_MATCH void Elevator_UpdateShake(Elevator* e) {
#ifdef NONMATCHING_C
  if (e->sinkY < 0) {
    e->sprite.pos.y += e->sinkY;
    e->sinkY = Div(e->sinkY, 2);
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

// 残差は後半の gElevatorManager のアドレスを原典が FUN_081d27c8 の前に r6 へ先読みして持つ点のみ (143/143), 前半は Elevator_UpdateState4 と同じくブロック内の p で一致
// Tier A-C は試済 (比較の向き, 判定の分け方, walker ローカル, argv[0] の書き方, p ローカルの置き場所)
NON_MATCH void Elevator_UpdateState3(Elevator* e) {
#ifdef NONMATCHING_C
  if (e->arrived) {
    ElevatorManager* p = gElevatorManager;

    if (e->id == p->ridingID && e->arriveScriptID != 0) {
      u32 argv[3];
      ScriptArgs sa;

      if (e->unk_e7 == 2) {
        if (Elevator_TestFlags(e, ELEVATOR_MOVE_UP)) {
          argv[0] = 2;
        } else {
          argv[0] = 1;
        }
      } else {
        argv[0] = e->pathWalker.nodeIdx;
      }
      argv[1] = e->mover.pos.x;
      argv[2] = e->mover.pos.z;
      sa.argc = 3;
      sa.argv = argv;
      VM_ExecByID(e->arriveScriptID, &sa);
    }
    e->waitTimer = 0;
    e->arrived = FALSE;
  }

  if (!FUN_081d27c8(e)) {
    PathWalker* walker = &e->pathWalker;

    if (walker->unk_3++ >= (walker->node->delay & 0xFFF)) {
      Map_AdvancePathWalker(walker);
      if (Map_IsPosOutsidePathNode(walker, &e->mover.pos, 16, 16)) {
        ElevatorManager* p;

        e->state = 1;
        p = gElevatorManager;
        if (e->id == p->ridingID && e->departScriptID != 0) {
          u32 arg = e->id;
          ScriptArgs sa;

          sa.argc = 1;
          sa.argv = &arg;
          VM_ExecByID(e->departScriptID, &sa);
        }
      } else {
        e->state = 3;
      }
    }
  }
#else
  INCFUNC("asm/func/Elevator_UpdateState3.inc");
#endif
}

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

// 棺桶を引くプレイヤーを乗せて止まっている間, 隣の特殊床や水のタイルを足場の高さで上書きする
// 残差は使われない center の計算 (189/231), 原典は center を static inline の出力引数 (Vec3* out) で埋めるのでスタックへの格納が残る, その形にすると 228/231 まで寄り, 残りは e を r8 に置くか base をスタックに置くかの割当と hit の 0/1 起こし
// Tier A-C は試済 (center の inline 化, 属性判定の bool8 inline, 添字計算の手書き, 宣言順, override ポインタ)
NON_MATCH void Elevator_UpdateTileOverrides(Elevator* e) {
#ifdef NONMATCHING_C
  ElevatorManager* p = gElevatorManager;

  if (p == NULL || e->id != p->ridingID || e->unk_e7 == 2 || gPlayerPtr[0]->action != PACT_PULL_COFFIN || e->state != 3) {
    Elevator_RemoveTileOverrides(e);
    return;
  }

  if (!Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDES)) {
    s32 base = GetCollisionTileIdx(&e->mover.pos);
    s32 idx = base + 1;
    s32 i;

    for (i = 0; i < 4; i++) {
      MapTileOverride* ov = Map_FindTileOverride(idx, 1);
      CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
      bool8 hit = (tile->attr & (TATTR_SPECIAL | TATTR_UNK_6)) ? TRUE : FALSE;

      if (hit) {
        Vec3 center;
        s32 bx, bz;

        Map_AddTileOverride(&e->tileOverrides[i], idx, STAIRS_NONE, (s8)(e->mover.pos.y >> 8), 0xFF, TATTR_UNK_0 | TATTR_UNK_2);
        e->tileOverrideActive[i] = TRUE;
        bx = Mod(idx, gCollisionMap->tiledata->width);
        bz = Div(idx, gCollisionMap->tiledata->width);
        center.x = bx * Q8(1) + Q8(0.5);
        ov = Map_FindTileOverride(idx, 1);
        tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
        center.y = (tile->heightStairs & 0xF) << 8;
        center.z = bz * Q8(1) + Q8(0.5);
        SET_FLAGS(e->flags, ELEVATOR_TILEOVERRIDES);
      }

      switch (i) {
        case 0: {
          idx = base + gCollisionMap->tiledata->width;
          break;
        }
        case 1: {
          idx = base - 1;
          break;
        }
        case 2: {
          idx = base - gCollisionMap->tiledata->width;
          break;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Elevator_UpdateTileOverrides.inc");
#endif
}

// 状態 3/4 の間はプレイヤーと同じ高さにいれば足元のタイルを移動床で上書きし, それ以外の状態では上書きを外す
void Elevator_UpdateTileOverride(Elevator* e) {
  if (e->state != 3 && e->state != 4) {
    if (Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDE)) {
      Map_RemoveTileOverride(&e->tileOverride);
      CLEAR_FLAGS(e->flags, ELEVATOR_TILEOVERRIDE);
    }
  } else {
    if (!Elevator_TestFlags(e, ELEVATOR_TILEOVERRIDE) && gCollisionMap != NULL && e->mover.pos.y == gPlayerPtr[0]->mover.pos.y) {
      Map_AddTileOverride(&e->tileOverride, GetCollisionTileIdx(&e->mover.pos), STAIRS_NONE, (s8)(e->mover.pos.y >> 8), 0xFF, TATTR_UNK_2);
      SET_FLAGS(e->flags, ELEVATOR_TILEOVERRIDE);
    }
  }
}

// tileIdx の上書きタイルを登録しているエレベータがあるかどうか
bool8 Elevator_IsTileOverridden(s32 tileIdx) {
  ElevatorManager* p = gElevatorManager;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Elevator_TestFlags(&p->elevators[i], ELEVATOR_TILEOVERRIDE) && p->elevators[i].tileOverride.tileIdx == tileIdx) {
      return TRUE;
    }
  }

  return FALSE;
}

// 乗っているプレイヤーが足場の範囲を外れて特殊床の上に出たら, エレベータの位置から弾き返す
void Elevator_KnockbackRider(Elevator* e) {
  s32 i;

  for (i = 0; i < 1; i++) {
    if (gPlayerPtr[i] != NULL && FUN_0807a954(gPlayerPtr[i], 1) && Elevator_TestFlags(e, PLAYER_RIDING)) {
      s32 idx = GetCollisionTileIdx(&gPlayerPtr[i]->mover.pos);

      if (!Elevator_IsTileOverridden(idx)) {
        MapTileOverride* ov = Map_FindTileOverride(idx, 1);
        CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
        TileAttr attr = tile->attr;

        if (attr & TATTR_SPECIAL) {
          Vec3 d;

          Vec3_Delta(&d, &e->mover.pos, &gPlayerPtr[i]->mover.pos);
          if (d.x > gElevatorRange0.x || d.x < -gElevatorRange0.x || d.y > gElevatorRange0.y || d.y < -gElevatorRange0.y || d.z > gElevatorRange0.z || d.z < -gElevatorRange0.z) {
            Player_SetKnockbackOrigin(gPlayerPtr[i], &e->mover.pos);
            SET_FLAGS(e->flags, ELEVATOR_RIDER_KNOCKBACK);
          }
        }
      }
    }
  }
}

// 乗っているプレイヤーが足場の範囲を外れて水の上に出たら unk_c0 のスクリプトを呼ぶ
void Elevator_CheckRiderFallInWater(Elevator* e) {
  s32 i;

  for (i = 0; i < 1; i++) {
    bool32 outside = FALSE;

    if (gPlayerPtr[i] != NULL) {
      if (!FUN_0807a954(gPlayerPtr[i], 1) && !FUN_0807a954(gPlayerPtr[i], 2)) return;

      if (Elevator_TestFlags(e, PLAYER_RIDING)) {
        s32 bx = (s8)(gPlayerPtr[i]->mover.pos.x >> 8);
        s32 bz = (s8)(gPlayerPtr[i]->mover.pos.z >> 8);
        s32 idx;
        MapTileOverride* ov;
        CollisionMapTile* tile;
        TileAttr attr;

        if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
          idx = 0;
        } else {
          idx = gCollisionMap->rowOffsets[bz] + bx;
        }
        ov = Map_FindTileOverride(idx, 1);
        tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
        attr = tile->attr;

        if ((attr & TATTR_UNK_6) && !Elevator_IsTileOverridden(idx)) {
          Vec3 d;

          Vec3_Delta(&d, &e->mover.pos, &gPlayerPtr[i]->mover.pos);
          if (e->unk_d6 & 8) {
            if (d.x > gElevatorRange0.x || d.x < -gElevatorRange0.x || d.y > gElevatorRange0.y || d.y < -gElevatorRange0.y || d.z > gElevatorRange0.z || d.z < -gElevatorRange0.z) {
              outside = TRUE;
            }
          } else {
            if (d.x > gElevatorRange1.x || d.x < -gElevatorRange1.x || d.y > gElevatorRange1.y || d.y < -gElevatorRange1.y || d.z > gElevatorRange1.z || d.z < -gElevatorRange1.z) {
              outside = TRUE;
            }
          }
          if (outside && e->unk_c0 != 0) {
            VM_ExecByID(e->unk_c0, NULL);
          }
        }
      }
    }
  }
}

// 乗っているプレイヤーが足場の範囲を外れたら範囲の端まで引き戻す
void Elevator_ClampRiderToRange(Elevator* e) {
  s32 i;

  for (i = 0; i < 1; i++) {
    if (gPlayerPtr[i] != NULL && e->state != 4 && FUN_0807a954(gPlayerPtr[i], 1)) {
      Vec3 d;

      if (!Elevator_TestFlags(e, PLAYER_RIDING)) return;
      if (Elevator_IsTileOverridden(GetCollisionTileIdx(&e->mover.pos)) && gPlayerPtr[i]->mover.pos.y == e->mover.pos.y) continue;

      Vec3_Delta(&d, &e->mover.pos, &gPlayerPtr[i]->mover.pos);
      if (d.x <= gElevatorRange2.x && d.x >= -gElevatorRange2.x && d.y <= gElevatorRange2.y && d.y >= -gElevatorRange2.y && d.z <= gElevatorRange2.z && d.z >= -gElevatorRange2.z) continue;

      if (d.x > gElevatorRange2.x) {
        d.x = gElevatorRange2.x;
      } else if (d.x < -gElevatorRange2.x) {
        d.x = -gElevatorRange2.x;
      }
      if (d.z > gElevatorRange2.z) {
        d.z = gElevatorRange2.z;
      } else if (d.z < -gElevatorRange2.z) {
        d.z = -gElevatorRange2.z;
      }

      d.x = e->mover.pos.x + d.x;
      d.y = e->mover.pos.y;
      d.z = e->mover.pos.z + d.z;
      FUN_0807a91c(gPlayerPtr[i], &d);
      SET_FLAGS(e->flags, ELEVATOR_RIDER_KNOCKBACK);
    }
  }
}

// 乗っている棺桶が足場の範囲を外れたら範囲の端まで引き戻す
void Elevator_ClampCoffinPos(Elevator* e) {
  WorldPos pos;
  Vec3 d;

  if (!FUN_08086978(1)) return;
  if (!Elevator_TestFlags(e, COFFIN_RIDING)) return;

  Coffin_CopyPos(&pos);
  if (Elevator_IsTileOverridden(GetCollisionTileIdx(&e->mover.pos)) && pos.y == e->mover.pos.y) return;

  Vec3_Delta(&d, &e->mover.pos, &pos);
  if (d.x <= gElevatorRange2.x && d.x >= -gElevatorRange2.x && d.y <= gElevatorRange2.y && d.y >= -gElevatorRange2.y && d.z <= gElevatorRange2.z && d.z >= -gElevatorRange2.z) return;

  if (d.x > gElevatorRange2.x) {
    d.x = gElevatorRange2.x;
  } else if (d.x < -gElevatorRange2.x) {
    d.x = -gElevatorRange2.x;
  }
  if (d.z > gElevatorRange2.z) {
    d.z = gElevatorRange2.z;
  } else if (d.z < -gElevatorRange2.z) {
    d.z = -gElevatorRange2.z;
  }

  pos.x = e->mover.pos.x + d.x;
  pos.y = e->mover.pos.y;
  pos.z = e->mover.pos.z + d.z;
  FUN_08086a4c(&pos);
  SET_FLAGS(e->flags, ELEVATOR_UNK_9);
}

// 乗っている棺桶が特殊床の上で足場の範囲を外れたら範囲の端まで引き戻す
void Elevator_ClampCoffinOnSpecialTile(Elevator* e) {
  WorldPos pos;
  Vec3 d;

  if (!FUN_08086978(1)) return;
  if (!Elevator_TestFlags(e, COFFIN_RIDING)) return;

  Coffin_CopyPos(&pos);
  if (!(GetTileAttrAt(&pos) & TATTR_SPECIAL)) return;

  Vec3_Delta(&d, &e->mover.pos, &pos);
  if (d.x <= gElevatorRange0.x && d.x >= -gElevatorRange0.x && d.y <= gElevatorRange0.y && d.y >= -gElevatorRange0.y && d.z <= gElevatorRange0.z && d.z >= -gElevatorRange0.z) return;

  if (d.x > gElevatorRange0.x) {
    d.x = gElevatorRange0.x;
  } else if (d.x < -gElevatorRange0.x) {
    d.x = -gElevatorRange0.x;
  }
  if (d.z > gElevatorRange0.z) {
    d.z = gElevatorRange0.z;
  } else if (d.z < -gElevatorRange0.z) {
    d.z = -gElevatorRange0.z;
  }

  pos.x = e->mover.pos.x + d.x;
  pos.y = e->mover.pos.y;
  pos.z = e->mover.pos.z + d.z;
  FUN_08086a4c(&pos);
  SET_FLAGS(e->flags, ELEVATOR_UNK_9);
}

// 乗っている棺桶が床の高さにいないか水の上にいて, 足場の範囲を外れたら範囲の端まで引き戻す
void Elevator_ClampCoffinOffFloor(Elevator* e) {
  WorldPos pos;
  Vec3 d;

  if (!FUN_08086978(1)) return;
  if (!Elevator_TestFlags(e, COFFIN_RIDING)) return;

  Coffin_CopyPos(&pos);
  {
    s32 bx = (s8)(pos.x >> 8);
    s32 bz = (s8)(pos.z >> 8);
    s32 idx;
    s32 y;
    MapTileOverride* ov;
    CollisionMapTile* tile;
    TileAttr attr;

    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->rowOffsets[bz] + bx;
    }
    y = pos.y;
    ov = Map_FindTileOverride(idx, 1);
    tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

    if (y == (tile->heightStairs & 0xF) << 8) {
      ov = Map_FindTileOverride(idx, 1);
      tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
      attr = tile->attr;
      if (!(attr & TATTR_UNK_6)) return;
    }
  }

  Vec3_Delta(&d, &e->mover.pos, &pos);
  if (d.x <= gElevatorRange0.x && d.x >= -gElevatorRange0.x && d.y <= gElevatorRange0.y && d.y >= -gElevatorRange0.y && d.z <= gElevatorRange0.z && d.z >= -gElevatorRange0.z) return;

  if (d.x > gElevatorRange0.x) {
    d.x = gElevatorRange0.x;
  } else if (d.x < -gElevatorRange0.x) {
    d.x = -gElevatorRange0.x;
  }
  if (d.z > gElevatorRange0.z) {
    d.z = gElevatorRange0.z;
  } else if (d.z < -gElevatorRange0.z) {
    d.z = -gElevatorRange0.z;
  }

  pos.x = e->mover.pos.x + d.x;
  pos.y = e->mover.pos.y;
  pos.z = e->mover.pos.z + d.z;
  FUN_08086a4c(&pos);
  SET_FLAGS(e->flags, ELEVATOR_UNK_9);
}

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

void Elevator_UpdatePlayerRiding(Elevator* e) {
  ElevatorManager* p;
  Vec3 pos;
  Vec3 delta;

  pos.x = gPlayerPtr[0]->mover.pos.x + e->moveDelta.x;
  pos.y = gPlayerPtr[0]->mover.pos.y + e->moveDelta.y;
  pos.z = gPlayerPtr[0]->mover.pos.z + e->moveDelta.z;
  Vec3_Delta(&delta, &e->mover.pos, &pos);

  p = gElevatorManager;
  if (delta.x <= gElevatorRange0.x && delta.x >= -gElevatorRange0.x && delta.y <= gElevatorRange0.y && delta.y >= -gElevatorRange0.y && delta.z <= gElevatorRange0.z && delta.z >= -gElevatorRange0.z) {
    FUN_081d3fac(p->ridingID, 0);
    p->ridingID = e->id;
    FUN_081d4034(e);
    SET_FLAGS(e->flags, PLAYER_RIDING);
    gPlayerPtr[0]->shadow.flags |= 1;
  } else if (p->ridingID == e->id) {
    if (e->unk_e7 == 1 && !(e->unk_d6 & 8)) {
      if (delta.x <= gElevatorRange1.x && delta.x >= -gElevatorRange1.x && delta.y <= gElevatorRange1.y && delta.y >= -gElevatorRange1.y && delta.z <= gElevatorRange1.z && delta.z >= -gElevatorRange1.z) {
        FUN_081d4034(e);
        return;
      }
    } else {
      if (delta.x <= gElevatorRange0.x && delta.x >= -gElevatorRange0.x && delta.y <= gElevatorRange0.y && delta.y >= -gElevatorRange0.y && delta.z <= gElevatorRange0.z && delta.z >= -gElevatorRange0.z) {
        FUN_081d4034(e);
        return;
      }
    }
    p->ridingID = 0;
    gPlayerPtr[0]->mover.tile = &gPlayerPtr[0]->tile;
    FUN_0807a99c(gPlayerPtr[0], 5);
    CLEAR_FLAGS(e->flags, PLAYER_RIDING);
    gPlayerPtr[0]->shadow.flags &= ~1;
  }
}

void Elevator_UpdateCoffinRiding(Elevator* e) {
  ElevatorManager* p;
  WorldPos pos;
  Vec3 delta;

  Coffin_CopyPos(&pos);
  pos.x += e->moveDelta.x;
  pos.y += e->moveDelta.y;
  pos.z += e->moveDelta.z;
  Vec3_Delta(&delta, &e->mover.pos, &pos);

  p = gElevatorManager;
  if (delta.x <= gElevatorRange0.x && delta.x >= -gElevatorRange0.x && delta.y <= gElevatorRange0.y && delta.y >= -gElevatorRange0.y && delta.z <= gElevatorRange0.z && delta.z >= -gElevatorRange0.z) {
    FUN_081d3fac(p->coffinRidingID, 1);
    p->coffinRidingID = e->id;
    FUN_081d407c(e);
    SET_FLAGS(e->flags, COFFIN_RIDING);
  } else if (e->id == p->coffinRidingID) {
    p->coffinRidingID = 0;
    FUN_080869f8(7);
    CLEAR_FLAGS(e->flags, COFFIN_RIDING);
  }
}

// pos がエレベータの範囲 (gElevatorRange0/1) をはみ出していたら, 速さのぶん内側に戻す
void Elevator_ClampRiderPos(Vec3* pos, Vec3* b, Elevator* e) {
  Vec3 d;
  Vec3 range;

  d.x = pos->x - e->mover.pos.x;
  d.y = pos->y - e->mover.pos.y;
  d.z = pos->z - e->mover.pos.z;

  if (e->unk_e7 == 2) return;

  if (e->unk_e7 == 1 && !(e->unk_d6 & 8)) {
    range = gElevatorRange1;
  } else {
    range = gElevatorRange0;
  }

  if (d.x < 0) {
    if (d.x < -range.x) d.x = e->speed - range.x;
  } else {
    if (d.x > range.x) d.x = range.x - e->speed;
  }
  if (d.y < 0) {
    if (d.y < -range.y) d.y = e->speed - range.y;
  } else {
    if (d.y > range.y) d.y = range.y - e->speed;
  }
  if (d.z < 0) {
    if (d.z < -range.z) d.z = e->speed - range.z;
  } else {
    if (d.z > range.z) d.z = range.z - e->speed;
  }

  pos->x = d.x + e->mover.pos.x;
  pos->y = d.y + e->mover.pos.y;
  pos->z = d.z + e->mover.pos.z;
}

void FUN_081d4540(Elevator* e) {
  if (gPlayerPtr[0] != NULL) {
    Elevator_UpdatePlayerRiding(e);
    Elevator_UpdateCoffinRiding(e);

    if (FUN_0807a954(gPlayerPtr[0], 1)) {
      FUN_081d4590(e);
    }
    if (FUN_08086978(1)) {
      FUN_081d4658(e);
    }

    ClearMemory(&e->moveDelta, sizeof(e->moveDelta));
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

  if (!Elevator_TestFlags(e, ELEVATOR_RIDER_KNOCKBACK)) {
    Vec3 v;

    v.x = e->moveDelta.x + gPlayerPtr[0]->mover.pos.x;
    v.y = e->moveDelta.y + gPlayerPtr[0]->mover.pos.y;
    v.z = e->moveDelta.z + gPlayerPtr[0]->mover.pos.z;
    Elevator_ClampRiderPos(&v, &gPlayerPtr[0]->mover.pos, e);
    FUN_0807a91c(gPlayerPtr[0], &v);
  }

  e->flags &= ~ELEVATOR_RIDER_KNOCKBACK;
#else
  INCFUNC("asm/func/FUN_081d4590.inc");
#endif
}

// 乗っている棺桶をエレベータの移動ぶんだけ動かす
// 残差23命令 (54/77): 原典は棺桶と mover.pos の差分を Vec3 に組み立てるがどこからも読まないので agbcc が消す, 加えて flags 判定の 0/1 起こしも畳まれる
// Elevator_IsSlotUsed / Elevator_TestFlags を bool8 を返す形にすると 0/1 の作り置きは出るが, それだけでは一致しない (60/77)
NON_MATCH void FUN_081d4658(Elevator* e) {
#ifdef NONMATCHING_C
  if (gElevatorManager->coffinRidingID == e->id) {
    WorldPos pos;
    WorldPos delta;

    Coffin_CopyPos(&pos);
    delta.x = pos.x - e->mover.pos.x;
    delta.y = pos.y - e->mover.pos.y;
    delta.z = pos.z - e->mover.pos.z;

    if (!Elevator_TestFlags(e, ELEVATOR_UNK_9)) {
      pos.x = e->moveDelta.x + pos.x;
      pos.y = pos.y + e->moveDelta.y;
      pos.z = e->moveDelta.z + pos.z;
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

    if (delta.x > gElevatorRange0.x) {
      return;
    }
    if (delta.x < -gElevatorRange0.x) {
      return;
    }
    if (delta.z > gElevatorRange0.z) {
      return;
    }
    if (delta.z < -gElevatorRange0.z) {
      return;
    }

    FUN_08086a4c(&e->mover.pos);
    FUN_081d3fac(p->coffinRidingID, 1);
    p->coffinRidingID = e->id;
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

  ElevatorManager_UpdateSound(p);
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

    if (e != NULL && (e->unk_d6 & 2)) {
      e->state = 2;
      if (mode == 4) {
        e->flags = (e->flags & ~ELEVATOR_MOVE_UP) | mode;
      } else {
        e->flags &= ~ELEVATOR_STOPPED;
        if (mode == 2) {
          e->flags |= mode;
        } else {
          e->flags &= ~ELEVATOR_MOVE_UP;
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
      e->speed = VM_GetNamedArgValue('s', 6);
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
      if (h > 0) e->maxY = h;
      if (l > 0) e->minY = l;
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
