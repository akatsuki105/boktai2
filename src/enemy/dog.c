#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// バンデット(ENEID_BANDIT), ヘルハウンド(ENEID_HELLHOUND), グレイブキーパー(ENEID_GRAVEKEEPER)
// 共通の特徴として におい でサーチする (処理の上でどうしているのかはまだ不明)
// バンデットは攻撃時にプレイヤーからアイテムを奪う, ヘルハウンドはファイヤーブレスを吐く
typedef struct {
  Enemy e;
  u8 unk_654[4];              // 0x654
  HitboxData unk_658;         // 0x658, 2つ目の攻撃判定, atkPower[1] などの攻撃値を載せる
  u32 unk_6a8;                // 0x6A8, bit0 は待ちが明けたときに立てる
  u32 unk_6ac;                // 0x6AC, unk_1e4 がこれ未満なら副状態 (0,2,0) へ
  u32 unk_6b0;                // 0x6B0, unk_1e4 がこれ未満でほぼ正面なら副状態 (0,2,1) へ
  u32 unk_6b4;                // 0x6B4, プレイヤーとの距離の2乗がこれ未満なら飛びかかりに入る
  u32 unk_6b8;                // 0x6B8, unk_1e4 と比べる距離の閾値, unk_6bc と対
  u32 unk_6bc;                // 0x6BC, unk_1e4 がこれを超えると副状態 19 へ移る
  u16 unk_6c0;                // 0x6C0, 0 になるまで数え下ろし, 0 になると unk_6c2 か unk_6c4 から入れ直す
  u16 unk_6c2;                // 0x6C2
  u16 unk_6c4;                // 0x6C4, ENEFLAG3_UNK_7 のときの unk_6c2
  u16 unk_6c6;                // 0x6C6, 0 になるまで毎フレーム減る
  u16 unk_6c8;                // 0x6C8, 0 になるまで毎フレーム減る
  u16 unk_6ca;                // 0x6CA, 0 になるまで毎フレーム減る
  u16 unk_6cc;                // 0x6CC, unk_6c8 に入れ直す値
  u16 unk_6ce;                // 0x6CE, unk_6ca に入れ直す値
  s16 unk_6d0;                // 0x6D0, 負なら unk_6d2/unk_6d4 は無効
  s16 unk_6d2;                // 0x6D2
  s16 unk_6d4;                // 0x6D4
  u8 unk_6d6;                 // 0x6D6
  u8 unk_6d7;                 // 0x6D7
  u8 unk_6d8;                 // 0x6D8, 0 になるまで毎フレーム減る
  u8 unk_6d9;                 // 0x6D9, 盗んだ食べ物で回復する割合 (maxHp の %)
  u8 unk_6da[0x708 - 0x6DA];  // 0x6DA
  Vec3 unk_708;               // 0x708, 飛びかかる直前のプレイヤーの位置
} Dog;
static_assert(sizeof(Dog) == 1808);

static inline bool8 Dog_TestUnk6a8(Dog* p, u32 bit) {
  if (p->unk_6a8 & bit) return TRUE;
  return FALSE;
}

static inline void Dog_ClearUnk6a8(Dog* p, u32 bit) { p->unk_6a8 &= ~bit; }
static inline void Dog_SetUnk6a8(Dog* p, u32 bit) { p->unk_6a8 |= bit; }

static inline AuxAnimState* Enemy_GetAuxAnim(Enemy* p) { return &((EnemyAuxSpriteData*)p->sprite)->anim; }

const u16 u16_ARRAY_085ad8c0[2][8] = {
    {450, 480,  480, 540, 450, 459, 459, 540},
    {800, 1280, 560, 360, 300, 306, 306, 360}
};  // 0x085AD8C0

extern const char s_dogcom_c_082520e4[];  // "dogcom.c"

struct Entity081ee2a0Elem* Entity081ee2a0_SpawnEx(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority);
bool8 PickItemToSteal(s16* outSlot, s16* outItem, s16* outRot);
s32 ItemIconPopupManager_AddIcon(ItemCategory32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key);
void* Entity081f26bc_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY);
struct Entity081f1770Elem* Entity081f1770_Spawn(Vec3* pos, u32 angle, SpriteFlags flags);
void FUN_0814ca30(Dog* p, s32 timer);
void FUN_0814e8ec(Dog* p, s32 timer);
void FUN_0814e1b0(Dog* p);
void FUN_0814e1fc(Dog* p);
void FUN_0814caa0(Dog* p);
bool8 FUN_0814b3a0(Dog* p);
void enemy_dog_0814a320(Dog* p);
void enemy_dog_0814b500(Dog* p);
void FUN_0814deb0(Dog* p);
void FUN_0814dd38(Dog* p, s32 timer);
void FUN_0814de34(Dog* p, s32 timer);
void FUN_0814e424(Dog* p);
void Dog_StatePounce(Dog* p);
void Dog_OnHit(HitboxData* a, HitboxData* b, Dog* p);
void Dog_OnStealHit(HitboxData* a, HitboxData* b, Dog* p);
void Dog_OnHurt(HitboxData* a, HitboxData* b, Dog* p);
void FUN_0814fba4(Dog*);
void FUN_0814fc7c(Dog*);
void FUN_08150534(Dog*);
void FUN_08150660(Dog*);
void FUN_08150790(Dog*);
void FUN_08150b18(Dog*);
void FUN_08150de8(Dog*);
void FUN_081514f0(Dog*);
void FUN_081516d8(Dog*);
void FUN_081517a8(Dog*);

void (*const PTR_ARRAY_085ad8e0[2])(Dog*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Dog*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Dog*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

// 134/133 命令, オフセット定数の作り方 (前の定数から足し引きするか作り直すか) とストアの並びが違う, 試済: 枝の向き
NON_MATCH void enemy_dog_08149f6c(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  q->unk_6c0 = q->unk_6c2;
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Dog_ClearUnk6a8(q, 4 | 8);
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  } else {
    Enemy_BeginChase(&p->e);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) || !FUN_0814b3a0(p)) {
      if (!Dog_TestUnk6a8(q, 8)) {
        enemy_dog_0814b500(p);
      }
      return;
    }
    enemy_dog_0814a320(p);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
#else
  INCFUNC("asm/func/enemy_dog_08149f6c.inc");
#endif
}

// 気付いて待つ状態へ移り, 追いかけ中なら 20 フレーム後に状態26へ, そうでなければ 60 フレーム後に状態1へ戻る予約をし, unk_4a8 に経路の今のノードを入れてプレイヤーへの経路を引き直す
// 269/277命令, FUN_0812edf8 と同じ保留状態の格納の壁 (原典はハンドラを先に読み, 副状態2の定数を r8 に置き, 0 は前の r7 を使い回す), 経路は二出口の Enemy_TryRouteToEx で揃う, 試済: 保留状態を (p, delay, handler, s0, s1, s2) の inline にする (悪化)
NON_MATCH void FUN_0814a098(Dog* p) {
#ifdef NONMATCHING_C
  WorldPos* dst;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 20;
    (p->e).pendingHandler = (p->e).unk_5b8;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).unk_24e += 300;
      if ((p->e).unk_24e > (p->e).unk_24c) {
        (p->e).unk_24e = (p->e).unk_24c;
      }
    }
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).unk_5a0;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  }
  dst = (p->e).unk_4a8;
  dst->x = (p->e).pathWalker.node->x;
  dst->z = (p->e).pathWalker.node->y;
  dst->y = TileHeightAt(dst);
  (p->e).unk_4a8->val = 0;
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).unk_5c4(&p->e);
  }
#else
  INCFUNC("asm/func/FUN_0814a098.inc");
#endif
}

// プレイヤーが前方にいて近ければ攻撃の副状態へ移り, そうでなければ次の動きを決める
// 300/301命令, 原典は flags3 の検査の 0x100 を unk_1cc のオフセット 0x1CC から subs で作るが, こちらは 0x100 を r7 に置いて角度の折り返しの +256 と使い回す, 末尾の enemy_dog_0814b500 の呼び出しは3か所に書くと揃う, 試済: 検査を TEST_FLAGS / & / Enemy_TestFlag3
NON_MATCH void enemy_dog_0814a320(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if ((p->e).unk_1e4 < (p->e).unk_1e8) {
    Vec3 diff;
    s32 d;
    s32 ad;

    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    d = ArcTan2_8(diff.x, diff.z) - (p->e).mover.angle;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    ad = abs(d);
    if (ad <= 23) {
      if ((p->e).variant <= 1 || (p->e).variant == 4) {
        if ((p->e).unk_1e4 < q->unk_6ac && q->unk_6c8 == 0) {
          Enemy_ResetState(&p->e, 0, 2, 0);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082520e4, 111);
          return;
        }
      } else {
        if ((p->e).unk_1e4 < q->unk_6ac && q->unk_6c8 == 0) {
          Enemy_ResetState(&p->e, 0, 2, 0);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082520e4, 124);
          return;
        }
        if ((p->e).unk_1e4 < q->unk_6b0 && ad <= 5 && q->unk_6ca == 0) {
          Enemy_ResetState(&p->e, 0, 2, 1);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082520e4, 129);
          return;
        }
      }
      if (!Dog_TestUnk6a8(q, 8)) {
        enemy_dog_0814b500(p);
      }
    } else if (!Dog_TestUnk6a8(q, 8)) {
      enemy_dog_0814b500(p);
    }
  } else if (!Dog_TestUnk6a8(q, 8)) {
    enemy_dog_0814b500(p);
  }
#else
  INCFUNC("asm/func/enemy_dog_0814a320.inc");
#endif
}

// angle の方向が視野の外ならそちらへ振り向く状態に入る
bool8 FUN_0814a5e0(Dog* p, u32 angle) {
  s32 diff = angle - (p->e).mover.angle;

  if (diff > 128) {
    diff -= 256;
  } else if (diff < -128) {
    diff += 256;
  }
  if (diff < 0) {
    diff = -diff;
  }
  if (diff < (p->e).unk_1fd || (p->e).state == ES_UNK_2) {
    return FALSE;
  }
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_ResetState(&p->e, 0, 0, 13);
  } else {
    Enemy_ResetState(&p->e, 0, 0, 6);
  }
  (p->e).unk_1dc = Angle_ToDir8(angle);
  return TRUE;
}

void Dog_InitAnims(Dog* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
  Enemy_SetAnimEntry(&p->e, 11, 2, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 2, 13, 0);
  Enemy_SetAnimEntry(&p->e, 15, 5, 0);
  Enemy_SetAnimEntry(&p->e, 5, 6, 0);
  Enemy_SetAnimEntry(&p->e, 16, 7, 0);
  Enemy_SetAnimEntry(&p->e, 17, 8, 0);
  Enemy_SetAnimEntry(&p->e, 3, 9, 0);
  Enemy_SetAnimEntry(&p->e, 6, 10, 0);
  Enemy_SetAnimEntry(&p->e, 7, 11, 0);
  Enemy_SetAnimEntry(&p->e, 10, 12, 0);
}

// 復帰時に作業値を消して経路の次のノードへ向き直り, 待機アニメを流して1コマ送る
// 残差1命令, 原典は p->sprite を r0 に読んでから r5 へ移す (Slime_OnReset / Boku_OnReset / Mimic_OnReset と同じ壁)
NON_MATCH void Dog_OnReset(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_6a8 = 0;
  q->unk_6c0 = 0;
  q->unk_6d0 = -1;
  q->unk_6d4 = 0;
  q->unk_6d6 = 0;
  q->unk_6d7 = 0;
  ClearMemory(&q->unk_708, sizeof(Vec3));
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
#else
  INCFUNC("asm/func/Dog_OnReset.inc");
#endif
}

void FUN_0814a8c8(Dog* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// アニメのコマの頭でコマ番号と追いかけ中かに応じた値を返し, バリアント2なら決まったコマで後ろへ土煙を出す
// 221/221命令, 残差は末尾の表引きで高位レジスタから写す一時レジスタの番号 (r0/r3 と原典 r3/r4) だけ, 加算は Vec3_Sum の b 側が先に読まれるので引数の向きを合わせてある, 試済: 早期 return の形
NON_MATCH s32 FUN_0814a8dc(Dog* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    bool32 run = Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_7);

    Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_16);
    if ((p->e).variant == 2 && (anim->cmdIdx == 7 || anim->cmdIdx == 5 || anim->cmdIdx == 1)) {
      Vec3 pos;
      Vec3 off;
      Vec3 vel;
      s32 life;
      u16* table = gRandomTable;

      pos.x = (_Random(table) & 63) - 48;
      pos.z = (_Random(table) & 63) - 48;
      Vec3_Sum(&pos, &(p->e).mover.pos, &pos);
      Vec3_SetPolar(&off, ((p->e).mover.angle + 128) & 0xFF, 80);
      Vec3_Sum(&pos, &off, &pos);
      pos.y = (p->e).mover.pos.y;
      Vec3_Clear(&vel);
      life = (Random() & 63) + 20;
      Entity081f26bc_Spawn(&pos, &vel, 0x1C1A, ANIM_D1B8, 3, 0, 0x31, 0, 1, 0, 0, life, 4, 1, 0x00200004, 30, 8, 8);
    }
    return u16_ARRAY_085ad8c0[run][anim->cmdIdx & 7];
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0814a8dc.inc");
#endif
}

void FUN_0814aad4(Dog* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_9)) {
    Enemy_SetAnimEntry(&p->e, 1, 4, 0);
  } else {
    Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    (p->e).animSpeedDiv = 2;
  }
}

void Dog_InitHitboxes(Dog* p) {
  Dog* self = (p->e).unk_1cc;
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset, hit2Size, hit2Offset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Dog_OnHurt, p);
  VEC3_SET(hitSize, 64, 120, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Dog_OnHit, 0, p);
  VEC3_SET(hit2Size, 0, 120, 0);
  VEC3_SET(hit2Offset, 0, 128, 0);
  Enemy_InitHitboxWithAtk(&p->e, &self->unk_658, &hit2Size, &hit2Offset, Dog_OnStealHit, 1, p);
  Hitbox_SetFlags(&self->unk_658, HBFLAG_ANGLE);
}

// 向きに合わせて攻撃判定と食らい判定の大きさを置き直し, 2つ目の攻撃判定を前方へ出す
void Dog_UpdateHitboxes(Dog* p) {
  Dog* q = (p->e).unk_1cc;
  WorldPos pos;
  Vec3 big;
  Vec3 size;
  s32 angle;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  pos = (p->e).mover.pos;
  angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;
  if (Dog_TestUnk6a8(q, 2)) {
    pos.x += POLAR_X(512, angle);
    pos.z += POLAR_Z(512, angle);
  } else {
    pos.x += POLAR_X(128, angle);
    pos.z += POLAR_Z(128, angle);
  }
  Hitbox_SetPos(&q->unk_658, &pos, 0);
  q->unk_658.angle = angle;
  pos = (p->e).mover.pos;
  switch (FixToInt(6, angle)) {
    case 0:
    case 2: {
      if (Dog_TestUnk6a8(q, 2)) {
        big.x = 240;
        big.z = 128;
      }
      size.x = 120;
      size.z = 64;
      break;
    }
    case 1:
    case 3: {
      if (Dog_TestUnk6a8(q, 2)) {
        big.x = 128;
        big.z = 240;
      }
      size.x = 64;
      size.z = 120;
      break;
    }
  }
  size.y = 100;
  Hitbox_SetHalfSize(&(p->e).atkHitbox, &size);
  Hitbox_SetPos(&(p->e).atkHitbox, &pos, 0);
  Hitbox_SetHalfSize(&(p->e).hurtbox, &size);
  Hitbox_SetPos(&(p->e).hurtbox, &pos, 0);
  if (Dog_TestUnk6a8(q, 2)) {
    Hitbox_SetHalfSize(&q->unk_658, &big);
  } else {
    Hitbox_SetHalfSize(&q->unk_658, &size);
  }
}

void FUN_0814ae80(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (q->unk_6c8 != 0) {
    q->unk_6c8--;
  }
  if (q->unk_6ca != 0) {
    q->unk_6ca--;
  }
}

void FUN_0814aeb0(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (q->unk_6c6 != 0) {
    q->unk_6c6--;
  }
}

void FUN_0814aed0(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_14 | ENEFLAG3_UNK_15) &&
      !TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4) && (p->e).state < 2) {
    if (q->unk_6c0 != 0) {
      q->unk_6c0--;
    } else {
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        q->unk_6c0 = q->unk_6c4;
      } else {
        q->unk_6c0 = q->unk_6c2;
      }
      SET_FLAGS(q->unk_6a8, 1);
      if (Dog_TestUnk6a8((p->e).unk_1cc, 1)) {
        Enemy_ResetState(&p->e, 0, 0, 15);
        Dog_ClearUnk6a8((p->e).unk_1cc, 1);
      }
    }
  }
}

// 倒されたときのスクリプトを, 位置や種族などを引数にして呼ぶ
void FUN_0814afc8(Dog* p) {
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_19)) {
    Dog* q = (p->e).unk_1cc;

    if ((p->e).unk_198 != 0) {
      u32 argv[10];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      if (q->unk_6d0 < 0) {
        argv[6] = -1;
        argv[7] = -1;
      } else {
        argv[6] = q->unk_6d2;
        argv[7] = q->unk_6d4;
      }
      argv[8] = (p->e).kind;
      argv[9] = (p->e).variant;
      sa.argc = 10;
      sa.argv = argv;
      VM_ExecByID((p->e).unk_198, &sa);
    }
  }
}

// angle から 90 度ずつ回して隣のタイルへ歩ける向きを探し, そのタイルへの経路を引けたら unk_6d7 を数えて TRUE, 向きは angle に戻す
// 332/344命令, Slime_PickWalkDest と同じタイル探索の割り当ての壁 (原典はフレーム 0x20 で &unk_256 / &mover.pos / 回数などをスタックに置く), 試済: ポインタのローカルと do-while (336命令)
NON_MATCH bool8 Dog_PickWalkDest(Dog* p, u32 angle) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;
  u32 target;
  s32 i;
  WorldPos pos;

  for (i = 0; i < 4; i++) {
    u32 tileIdx = (p->e).unk_256;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    s32 idx;
    s32 n;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).unk_256;
        break;
      }
    }
    if (target != (p->e).unk_256) {
      break;
    }
    if (q->unk_6d6) {
      (p->e).mover.angle += 64;
    } else {
      (p->e).mover.angle -= 64;
    }
  }
  q->unk_6d6 = (u8)Random() < 128;
  (p->e).mover.angle = angle;
  TilePosAtIndex(&pos, target);
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
    q->unk_6d7++;
    return TRUE;
  }
  (p->e).unk_5c4(&p->e);
  return FALSE;
#else
  INCFUNC("asm/func/Dog_PickWalkDest.inc");
#endif
}

// 残差1命令, 原典は 0x6C8 のオフセットに 2 を足して 0x6CA を作るがこちらはプールから読む, 試済: 2つを u16[2] にする形
NON_MATCH bool8 FUN_0814b3a0(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  if ((p->e).variant <= 1 || (p->e).variant == 4) {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
  } else {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
    if (q->unk_6ca == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0814b3a0.inc");
#endif
}

// 攻撃が当たった相手に気付いて追いかけ始める
bool8 FUN_0814b3e0(Dog* p) {
  if ((p->e).hitTargetID > 0) {
    Vec3 diff;

    Enemy_Alert(&p->e);
    CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    (p->e).unk_25e = GetCollisionTileIdx(&(p->e).playerMover->pos);
    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    (p->e).mover.angle = ArcTan2_8(diff.x, diff.z);
    Dog_ClearUnk6a8((p->e).unk_1cc, 4 | 8);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  }
  return FALSE;
}

// 次の動きを決める, 近いときは向きを反転して副状態17へ, unk_6bc より遠ければプレイヤーへの経路を引いて状態26へ, どちらでもなければ状態42へ
// 273/274命令, 残差は unk_6b8 のオフセットを 0x6D7 の定数から subs で作るか (こちら), movs/lsls で作り直すか (原典) だけ, 副状態3つの比較は *(u32*)&subState0 & 0xFFFFFF を直接書くと揃う (inline 経由だとアドレスが r8 に持ち越される), 試済: 比較の向きを逆に (順が入れ替わる)
NON_MATCH void enemy_dog_0814b500(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  Enemy_ClearPendingState(&p->e, s_dogcom_c_082520e4, 656);
  if (q->unk_6d7 <= 3) {
    if (((p->e).unk_1e4 < q->unk_6b8 || !FUN_0814b3a0(p)) && q->unk_6d7 <= 3) {
      u8 angle = (p->e).mover.angle;

      (p->e).mover.angle = (p->e).unk_1fc + 128;
      if (Dog_PickWalkDest(p, angle)) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 0, 17);
      }
      return;
    }
    if ((p->e).unk_1e4 > q->unk_6bc) {
      if ((p->e).state == ES_UNK_26) {
        return;
      }
      if ((*(u32*)&(p->e).subState0 & 0xFFFFFF) == ENEMY_SUBSTATE(0, 0, 12)) {
        return;
      }
      if (IsLinkPlay()) {
        if (!FUN_080faa98(&p->e)) {
          return;
        }
      } else {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
      }
      if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
        (p->e).unk_5c4(&p->e);
        return;
      }
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return;
    }
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, FUN_0814e424, ES_UNK_42);
#else
  INCFUNC("asm/func/enemy_dog_0814b500.inc");
#endif
}

void FUN_0814b78c(Dog* p) {
  if (p->unk_6d8 != 0) {
    p->unk_6d8--;
  }
}

// pos の周りにランダムな向きと速さで粒を1つ飛ばす
// 残差は79/78命令, gRandTableIdx のアドレスがレジスタに載らず毎回読み直す割当の差, Entity081f9cb8_SpawnWaitEffect と同じ壁, 試済: 全部 Random(), 前半だけブロックで table, 3つとも table
NON_MATCH void FUN_0814b7a4(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle;
  s32 speed;
  u16* table = gRandomTable;

  angle = _Random(table) & 0xFF;
  speed = _Random(table) & 31;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 63) - 48;
  Entity081ee2a0_SpawnEx(pos, &vel, 60, 3, 3);
#else
  INCFUNC("asm/func/FUN_0814b7a4.inc");
#endif
}

void Dog_OnHit(HitboxData* a, HitboxData* b, Dog* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 2つ目の攻撃判定が当たったとき, 押し出す向きを決め, プレイヤーから食べ物を盗めたら回復ぶんをダメージの欄に入れて追いかけに戻る
// 304/359命令の1回目の下書き, 原典はフレーム 0x28 で p を r9, &mover.pos を r7 に写し, 盗んだあとの処理が長い (inline の展開が多いらしい), 1回目の下書きで切り上げ
NON_MATCH void Dog_OnStealHit(HitboxData* a, HitboxData* b, Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  if (!Enemy_IsDead(&p->e)) {
    s16 x = a->center.x;
    s16 z = a->center.z;

    switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
      case 0: {
        x -= 256;
        break;
      }
      case 1: {
        z -= 256;
        break;
      }
      case 2: {
        x += 256;
        break;
      }
      case 3: {
        z += 256;
        break;
      }
    }
    a->angle = ArcTan2_8(b->center.x - x, b->center.z - z);
    Enemy_SetHitTarget(&p->e, b);
    if (!IsLinkPlay() && b->ignoreMask == HIM_0 && q->unk_6d0 < 0 && ((p->e).variant == 0 || (p->e).variant == 4)) {
      WorldPos pos = gPlayerPtr[0]->mover.pos;

      pos.y += 200;
      if (PickItemToSteal(&q->unk_6d0, &q->unk_6d2, &q->unk_6d4)) {
        if (ItemIconPopupManager_AddIcon(0, q->unk_6d2, 3, 0, &pos, &(p->e).mover.pos, 24, (u32)p) < 0) {
          q->unk_6d0 = -1;
        } else {
          RemoveItem(q->unk_6d0);
          switch (q->unk_6d2) {
            case 8:
            case 11:
            case 14:
            case 17: {
              s32 heal = Div((p->e).maxHp * q->unk_6d9, 100);

              if ((p->e).hp - heal <= 0) {
                heal = (u16)(p->e).hp;
              }
              (p->e).unk_48a = heal;
              q->unk_6d0 = -1;
              (p->e).playerMover = &gPlayerPtr[0]->mover;
              (p->e).unk_4a0 = 1;
              (p->e).weaponExpMask = 0;
              (p->e).flags6 = 0;
              (p->e).weaponExpMask = 0;
              (p->e).flags6 = 0;
              (p->e).hurtbox.damage = (p->e).unk_48a;
              (p->e).hurtbox.knockbackPower = 1;
              (p->e).hurtbox.invincibleTime = 30;
              (p->e).unk_48c = 1;
              if ((p->e).flags5 & ENEFLAG5_UNK_1) {
                (p->e).playerMover = &gPlayerPtr[0]->mover;
              }
              if ((p->e).playerMover != NULL) {
                s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
                s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

                (p->e).unk_1fc = ArcTan2_8(dx, dz);
                (p->e).unk_1e4 = dx * dx + dz * dz;
              }
              break;
            }
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Dog_OnStealHit.inc");
#endif
}

NAKED void Dog_OnHurt(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/Dog_OnHurt.inc"); }

void FUN_0814c28c(Dog* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void FUN_0814c2b0(Dog* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

NAKED void FUN_0814c2d4(Dog* p) { INCFUNC("asm/func/FUN_0814c2d4.inc"); }

void FUN_0814c970(Dog* p) {}

void FUN_0814c974(Dog* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 6);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, FUN_0814ca30, ES_UNK_6);
  }
}

void FUN_0814ca30(Dog* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// 97/94 命令, 原典は flags3 のアドレスを1本のレジスタに持って2回の判定に使い, animSpeedDiv のアドレスは枝ごとに作る, 試済: inline の TEST_FLAGS 版, flags3 のポインタ, 判定を展開した形
NON_MATCH void FUN_0814caa0(Dog* p) {
#ifdef NONMATCHING_C
  u16 saved;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
    (p->e).animForceRestart = FALSE;
  }
  saved = (p->e).animSpeedDiv;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).animSpeedDiv = 3;
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  (p->e).animSpeedDiv = saved;
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/FUN_0814caa0.inc");
#endif
}

// アニメが終わったら, 追いかけ中なら経路の通過点へ向き直って状態26へ, そうでなければ止まる
void FUN_0814cb8c(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
    (p->e).animForceRestart = FALSE;
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = TRUE;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      (p->e).animSpeedDiv = 2;
    } else {
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 7);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    }
  }
}

NAKED void Dog_StateDamaged(Dog* p) { INCFUNC("asm/func/Dog_StateDamaged.inc"); }

// 火を吐く前に, 口の前あたりに4フレームおきに火の粉を散らす
void FUN_0814dd38(Dog* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
  }
  Enemy_GetAuxAnim(&p->e)->cmdIdx = 0;
  Enemy_GetAuxAnim(&p->e)->tick = 0;
  if (Mod(timer, 4) == 0) {
    s32 dir = (((p->e).mover.angle + 0x20) & 0xFF) >> 6;
    Vec3 pos = (p->e).mover.pos;

    switch (dir) {
      case 0: {
        pos.x += 128;
        break;
      }
      case 1: {
        pos.z += 128;
        break;
      }
      case 2: {
        pos.x -= 160;
        break;
      }
      case 3: {
        pos.z -= 128;
        break;
      }
    }
    FUN_0814b7a4(&pos);
  }
  if (timer > 30) {
    Enemy_EnterState(&p->e, FUN_0814de34, ES_UNK_37);
  }
}

// 火を吐く, 決まったフレームの間だけ2つ目の攻撃判定を出す
void FUN_0814de34(Dog* p, s32 timer) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    Entity081f1770_Spawn(&(p->e).mover.pos, (p->e).mover.angle, 0);
    PlaySound_082406e0(SONG_933);
  }
  if (timer >= 13 && timer <= 23) {
    Hitbox_Register(&q->unk_658);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_0814deb0(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    q->unk_708 = (p->e).playerMover->pos;
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Dog_StatePounce, ES_UNK_34);
  }
}

// 飛びかかる状態, 入ったときに覚えたプレイヤーの位置が前方 16 度以内なら真っ直ぐ, そうでなければ左右 16 度へ跳び, 着地したら状態35へ移る
// 命令数は揃い残差は左右に跳ぶ2つの塊の並び順だけ, 角度は u8 に詰めて Vec3_SetPolar に渡すと SIN 側の & 0xFF が消えて揃う, q は塊の中で取り直す, 未試行: u8 キャストのまま d <= 0 の塊を先に書く順
NON_MATCH void Dog_StatePounce(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3 v;
    s32 target;
    s32 face;
    s32 d;

    q = (p->e).unk_1cc;
    Vec3_Delta(&v, &(p->e).mover.pos, &q->unk_708);
    target = ArcTan2_8(v.x, v.z);
    face = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64;
    d = target - face;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) < 16) {
      Vec3_SetPolar(&v, target, 24);
    } else if (d > 0) {
      Vec3_SetPolar(&v, (u8)(face + 16), 24);
    } else {
      Vec3_SetPolar(&v, (u8)(face - 17), 24);
    }
    (p->e).jumpVel.x = v.x;
    (p->e).jumpVel.y = 32;
    (p->e).jumpVel.z = v.z;
    PlaySound_082406e0(CRY_DOG_ALERT);
  }
  Hitbox_Register(&q->unk_658);
  if ((p->e).mover.tile->unk_0[0] & 1) {
    (p->e).jumpVel.x = FixToInt(1, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(1, (p->e).jumpVel.z);
  }
  Enemy_PlayAnim(&p->e, 5);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    Enemy_EnterState(&p->e, FUN_0814e1b0, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/Dog_StatePounce.inc");
#endif
}

void FUN_0814e1b0(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 16);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_0814e1fc(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 14);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// 見回す状態, 残り回数 unk_542 が尽きるまで 20 フレームごとに向きを変え, 尽きたら退避していた状態へ戻る
// 193/198命令, Enemy_080eff14 と同形, 原典は *count |= 0xFF 用の ldrb を検査の前に読み, 乱数ループの前に mover.angle を r4 に読んで比較用に r3 へ写し, 回数切れのとき angle = 元の向き を残す (こちらは同値と見抜かれて消える), 試済: 型の組み合わせ, for + 後判定 (213命令)
NON_MATCH void FUN_0814e248(Dog* p, s32 timer) {
#ifdef NONMATCHING_C
  u8* count;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).animSpeedDiv = 2;
  }
  count = &(p->e).unk_542;
  if ((s8)*count > 0) {
    if (timer > 20) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
      if ((s8)*count == 1) {
        (p->e).unk_1dc = (((p->e).unk_541 >> 5) + 3) & 7;
      } else {
        u8 cur = (p->e).mover.angle;
        s32 angle;
        s32 i;

        i = 0;
        while (TRUE) {
          angle = (Random() & 3) << 6;
          if (angle != cur) {
            break;
          }
          if (++i > 3) {
            angle = cur;
            break;
          }
        }
        (p->e).unk_1dc = ((angle >> 5) + 3) & 7;
      }
      (p->e).unk_542--;
    }
  } else {
    *count |= 0xFF;
    if (timer > 6) {
      Enemy_EnterState(&p->e, (p->e).unk_548, (p->e).unk_54f);
      Enemy_ResetState(&p->e, (p->e).unk_54c, (p->e).unk_54d, (p->e).unk_54e);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    }
  }
#else
  INCFUNC("asm/func/FUN_0814e248.inc");
#endif
}

void FUN_0814e420(Dog* p) {}

void FUN_0814e424(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 11);
  if (FUN_0814b3a0(p)) {
    Enemy_PlayAnim(&p->e, 0);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
      ((EnemyHandler)(p->e).unk_5c4)(&p->e);
    } else {
      Dog_ClearUnk6a8(q, 4);
      Enemy_ResetState(&p->e, 0, 0, 17);
    }
  }
}

void FUN_0814e530(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  if (Dog_TestUnk6a8(q, 4)) {
    if ((p->e).unk_1e4 > q->unk_6bc) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      (p->e).unk_1dc = (FixToInt(5, (p->e).unk_1fc) + 3) & 7;
    } else {
      Dog_ClearUnk6a8(q, 4);
      if (q->unk_6d7 < 4) {
        if (Dog_PickWalkDest(p, (p->e).mover.angle)) {
          Enemy_ResetState(&p->e, 0, 0, 17);
        }
      } else {
        Enemy_ResetState(&p->e, 0, 0, 19);
        (p->e).unk_1dc = (FixToInt(5, (p->e).unk_1fc) + 3) & 7;
      }
    }
  } else {
    Enemy_PlayAnim(&p->e, 1);
  }
}

// 倒されて跳ね飛ぶ状態, アニメが終わったら, 落下死なら倒されたスクリプトを呼んで消え, そうでなければ点滅して消える状態38へ移る
void Dog_StateDying(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = FALSE;
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if ((p->e).animForceRestart) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      s32 idx;

      (p->e).subStateDone = 1;
      FUN_0814afc8(p);
      if ((p->e).unk_19a != 0) {
        u32 argv[8];
        ScriptArgs sa;

        argv[0] = (p->e).mover.pos.x;
        argv[1] = (p->e).mover.pos.y;
        argv[2] = (p->e).mover.pos.z;
        argv[3] = (p->e).unk_19c;
        argv[4] = (p->e).unk_1a0;
        argv[5] = (p->e).unk_1a4;
        argv[6] = (p->e).unk_4a0;
        argv[7] = (p->e).mover.id;
        sa.argc = 8;
        sa.argv = argv;
        VM_ExecByID((p->e).unk_19a, &sa);
      }
      idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
      if (idx < 32) {
        gStat->enemyDexSeen[0] |= 1 << idx;
      } else {
        gStat->enemyDexSeen[1] |= 1 << (idx - 32);
      }
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 1, 0, 2);
      }
      ParticleShadow_Hide(&(p->e).shadow);
      Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    } else {
      Enemy_EnterState(&p->e, FUN_0814e8ec, ES_UNK_38);
    }
  }
}

// 跳ねながら点滅して消え, 消えきったら倒されたスクリプトを呼び図鑑に載せて止まる
void FUN_0814e8ec(Dog* p, s32 timer) {
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if (Sprite_UpdateVanishBlink(&((AuxSprite*)(p->e).sprite)->flags, timer, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
    FUN_0814afc8(p);
    if ((p->e).unk_19a != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).unk_19a, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 1, 0, 2);
    }
    ParticleShadow_Hide(&(p->e).shadow);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  } else if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    ParticleShadow_Show(&(p->e).shadow);
  }
}

NAKED bool8 FUN_0814eacc(Dog* p) { INCFUNC("asm/func/FUN_0814eacc.inc"); }

void FUN_0814fba4(Dog* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0814caa0, ES_UNK_10);
    (p->e).mover.angle = (p->e).unk_1fc;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    enemy_dog_0814a320(p);
  } else {
    (p->e).subStateTimer++;
  }
}

NAKED void FUN_0814fc7c(Dog* p) { INCFUNC("asm/func/FUN_0814fc7c.inc"); }

void FUN_081504e8(Dog* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad8e0; }

s32 FUN_081504f8(Dog* p) {
  FUN_0814aad4(p);
  FUN_0814aed0(p);
  return 1;
}

s32 FUN_08150510(Dog* p) {
  Dog_UpdateHitboxes(p);
  FUN_0814ae80(p);
  FUN_0814aeb0(p);
  FUN_0814b78c(p);
  return 1;
}

void FUN_08150534(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Dog_ClearUnk6a8(q, 8);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, FUN_0814deb0, ES_UNK_33);
    Dog_ClearUnk6a8((p->e).unk_1cc, 2);
    Hitbox_SetAttack(&q->unk_658, (p->e).atkPower[1], (p->e).atkUnk40[1], 0, (p->e).atkAttrs[1], (p->e).atkInvincibleTime[1]);
    q->unk_6d7 = 0;
    q->unk_6c8 = q->unk_6cc;
  }
  if ((p->e).subStateDone) {
    q->unk_6c8 = q->unk_6cc;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    enemy_dog_0814b500(p);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08150660(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Dog_ClearUnk6a8(q, 8);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, FUN_0814dd38, ES_UNK_36);
    Dog_SetUnk6a8((p->e).unk_1cc, 2);
    Hitbox_SetAttack(&q->unk_658, (p->e).atkPower[2], (p->e).atkUnk40[2], 0, (p->e).atkAttrs[2], (p->e).atkInvincibleTime[2]);
    q->unk_6d7 = 0;
  }
  if ((p->e).subStateDone) {
    q->unk_6ca = q->unk_6ce;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    enemy_dog_0814b500(p);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0815077c(Dog* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad8e8; }

// 吠えながら待つ副状態, 吠えるコマの終わりにプレイヤーが近ければ驚いて飛びかかりの副状態16へ, アニメが終わったら追いかけか状態1へ戻る
// 2回目の下書き, 原典は &mover.pos を r8 に写し, 距離の2乗をコマの判定より先に作る, 状態の格納やタイル高さの塊の割り当てがまだずれる
NON_MATCH void FUN_08150790(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;
  AuxAnimState* anim;
  WorldPos* pos;
  Vec3 d;
  u32 distSq;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0814e1fc, ES_UNK_39);
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  pos = &(p->e).mover.pos;
  Vec3_Delta(&d, pos, &gPlayerPtr[0]->mover.pos);
  distSq = d.x * d.x + d.z * d.z;
  anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;
  if ((anim->cmdIdx == 6 || anim->cmdIdx == 12 || anim->cmdIdx == 19 || anim->cmdIdx == 25) && anim->tick == anim->wait - 1 && distSq < q->unk_6b4) {
    Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
    Enemy_ResetState(&p->e, 0, 0, 16);
    q->unk_708 = gPlayerPtr[0]->mover.pos;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).unk_24e += 300;
      if ((p->e).unk_24e > (p->e).unk_24c) {
        (p->e).unk_24e = (p->e).unk_24c;
      }
    }
    return;
  }
  if ((p->e).subStateDone) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_ResetState(&p->e, 0, 0, 12);
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    } else {
      d.x = (p->e).pathWalker.node->x;
      d.z = (p->e).pathWalker.node->y;
      d.y = TileHeightAt(&d);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 2);
      if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, pos, &d)) {
        (p->e).unk_5c4(&p->e);
      }
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08150790.inc");
#endif
}

// 飛びかかる前の位置へ向かう副状態, 着いたら追いかけ中なら状態26へ, そうでなければ経路の今のノードへ戻って状態1へ
void FUN_08150b18(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0814caa0, ES_UNK_10);
  }
  if ((p->e).unk_608(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateDone) {
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->unk_708)) {
      (p->e).unk_5c4(&p->e);
      return;
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_ResetState(&p->e, 0, 0, 12);
      Enemy_EnterState(&p->e, (p->e).unk_5b8, ES_UNK_26);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    } else {
      WorldPos* dst = (p->e).unk_4a8;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      (p->e).unk_4a8->val = 0;
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
    }
  } else {
    (p->e).subStateTimer++;
  }
}

NAKED void FUN_08150de8(Dog* p) { INCFUNC("asm/func/FUN_08150de8.inc"); }

// 経路に沿って歩き, 経路の終わりに着いたら副状態 (3,1,0) へ, 通過点が変わって曲がれたら副状態18へ移る
void FUN_081514f0(Dog* p) {
  Dog* q = (p->e).unk_1cc;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0814e530, ES_UNK_41);
    Dog_SetUnk6a8(q, 8);
  }
  speed = (p->e).unk_588(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Dog_SetUnk6a8(q, 4);
      return;
    }
  } else if (FUN_080e60b8(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 18);
  }
  if (FUN_0814b3a0(p)) {
    if ((p->e).unk_608(&p->e)) {
      return;
    }
    if (FUN_080f0a0c(&p->e)) {
      return;
    }
  }
  (p->e).subStateTimer++;
}

void FUN_081516d8(Dog* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  }
  if (!FUN_0814b3a0(p) || (!(p->e).unk_608(&p->e) && !FUN_080f0a0c(&p->e))) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 17);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_081517a8(Dog* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_590, ES_UNK_2);
  }
  if (!FUN_0814b3a0(p) || (!(p->e).unk_608(&p->e) && !FUN_080f0a0c(&p->e))) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, FUN_0814e424, ES_UNK_42);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_081518ac(Dog* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad8f0; }

s32 FUN_081518c0(Dog* p) {
  Dog* self = p;

  FUN_081504f8(p);
  if ((p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  FUN_08150510(self);
  return 1;
}

s32 Dog_Update(Dog* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Dog_Destroy(Dog* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).unk_44c) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).unk_44c = 1;
  }
  if (!(p->e).unk_44d) {
    Eff082473e0Emitter_Destroy(&(p->e).emitter);
    (p->e).unk_44d = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Dog_Init(Dog* p) { INCFUNC("asm/func/Dog_Init.inc"); }

void Dog_Create(void) {
  Dog* p = Malloc(sizeof(Dog));

  if (p != NULL) {
    ClearMemory(p, sizeof(Dog));
    if (Dog_Init(p) < 0) {
      Dog_Destroy(p);
      Free(p);
    }
  }
}
