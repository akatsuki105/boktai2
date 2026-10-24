#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

typedef struct {
  Vec3* basePos;  // 0x00, 位置の基準, オフセットを足して粒子の座標にする
  s16 offsetX;    // 0x04
  s16 offsetY;    // 0x06
  s16 offsetZ;    // 0x08
  u8 unk_a[12];   // 0x0A
  u8 state;       // 0x16, PTR_ARRAY_085ad32c の添字, FUN_080dc00c が 0 に戻す
  s8 idx;         // 0x17, 自分の添字, ptcls と activeMask のビットを指す
  u16 timer;      // 0x18, 毎フレーム +1
  s16 delay;      // 0x1A, 0 を超えている間は数え下げるだけで何もしない
} Entity080dc44cSlot;
static_assert(sizeof(Entity080dc44cSlot) == 28);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;            // 0x018, ANIM_D1B8
  ParticleGroup* group;         // 0x01C, PTCL_GROUP_0
  Particle ptcls[8];            // 0x020, slots[i].idx が添字
  AuxAnimState anims[8];        // 0x160, slots[i].idx が添字, ANIM_D1B8 の再生状態
  u32 activeMask;               // 0x1E0, 使用中の slots のビットマスク
  Entity080dc44cSlot slots[8];  // 0x1E4, 根拠: _Destroy の stride 0x1C × 8
} Entity080dc44c;
static_assert(sizeof(Entity080dc44c) == 708);

IWRAM_DATA Entity080dc44c* gEntity080dc44c = NULL;  // 0x03000168

void FUN_080dbeb0(Entity080dc44c* p, Entity080dc44cSlot* elem) {}

s32 FUN_080dc0d0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);

// state 1 の更新, 粒子を基準位置へ置いてアニメを1コマ進め, 一巡したら state 2 へ移す
// 残差6命令 (163/169). 原典は slot を ip に追い出して使うたび低位レジスタへ mov し直すほどレジスタが足りていないが, こちらは r7 に収まってしまう
// p->group をローカルに取っても変わらず (163). アニメ進行の本体は eff_smoke.c の SmokeEmitter_Update と同形
NON_MATCH void FUN_080dbeb4(Entity080dc44c* p, Entity080dc44cSlot* slot) {
#ifdef NONMATCHING_C
  Particle* ptcl = &p->ptcls[slot->idx];
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  bool32 finished;

  if (slot->delay > 0) {
    slot->delay--;
    return;
  }

  ptcl->flags &= ~SPRFLAG_HIDDEN;
  ptcl->pos.x = slot->offsetX + slot->basePos->x;
  ptcl->pos.y = slot->offsetY + slot->basePos->y;
  ptcl->pos.z = slot->offsetZ + slot->basePos->z;

  anim = &p->anims[slot->idx];
  cmd = &anim->cmds[anim->cmdIdx];
  ptcl->tileNum = (*cmd >> 6) * ((ptcl->spriteWidth >> 3) * (ptcl->spriteHeight >> 3)) + p->group->tile;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    ptcl->flags |= SPRFLAG_XFLIP;
  } else {
    ptcl->flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    ptcl->flags |= SPRFLAG_YFLIP;
  } else {
    ptcl->flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick < anim->wait) {
    finished = FALSE;
  } else {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        finished = TRUE;
      } else {
        anim->cmdIdx--;
        finished = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx < anim->cmdCount) {
        finished = FALSE;
      } else {
        anim->cmdIdx = 0;
        finished = TRUE;
      }
    }
    anim->wait = (anim->speed * (anim->cmds[anim->cmdIdx] & 0xF)) >> 6;
  }

  if (finished) {
    slot->state = 2;
  }
  slot->timer++;
#else
  INCFUNC("asm/func/FUN_080dbeb4.inc");
#endif
}

// 枠を解放する, パーティクルを外して activeMask のビットを落とす
// 残差は命令の並び順のみ (31 対 31), 原典は idx の ldrsb を activeMask のアドレス計算より前に出す
NON_MATCH void FUN_080dc00c(Entity080dc44c* p, Entity080dc44cSlot* slot) {
#ifdef NONMATCHING_C
  Particle_Remove(&p->ptcls[slot->idx]);
  slot->unk_16 = 0;
  p->activeMask &= ~(1 << slot->idx);
  ClearMemory(slot, sizeof(*slot));
  slot->idx = -1;
#else
  INCFUNC("asm/func/FUN_080dc00c.inc");
#endif
}

// 空いている枠を確保して返す, 無ければ NULL
// 残差11命令 (28/39). 使用中判定の 0/1 の作り置きと, 原典が i*0x1C のバイトオフセットを ip に別途ためて毎回 p + 0x1E4 + offset を作り直す点 (agbcc は誘導変数に落として基底をループ外へ巻き上げる)
// FUN_080dad4c (entity_080db520.c) と全く同じ2つの壁
NON_MATCH Entity080dc44cSlot* FUN_080dc050(Entity080dc44c* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->activeMask & (1 << i))) {
      Entity080dc44cSlot* slot = &p->slots[i];

      slot->idx = i;
      p->activeMask |= 1 << i;
      return slot;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_080dc050.inc");
#endif
}

s32 FUN_080dc0a0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { return FUN_080dc0d0(p, param_2, param_3, param_4, param_5, param_6); }

s32 FUN_080dc0b8(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { return FUN_080dc0d0(p, param_2, param_3, param_4, param_5, 2); }

NAKED s32 FUN_080dc0d0(Entity080dc44c* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_080dc0d0.inc"); }

void (*const PTR_ARRAY_085ad32c[3])(Entity080dc44c*, Entity080dc44cSlot*) = {
    FUN_080dbeb0,
    FUN_080dbeb4,
    FUN_080dc00c,
};  // 0x085AD32C

// 使用中の枠について state ごとの更新関数を呼ぶ
// 残差7命令 (40/47). 5命令は使用中判定の 0/1 の作り置き, 残り2命令は原典が &activeMask と &slots の定数を別々に作るのに対しこちらは片方から差分で導くため
// Entity080db520_Update と同じ壁. slot の初期化を for の初期化節に移すと i=0 の位置だけは合う
NON_MATCH s32 Entity080dc44c_Update(Entity080dc44c* p) {
#ifdef NONMATCHING_C
  if (p->activeMask != 0) {
    Entity080dc44cSlot* slot;
    s32 i;

    for (i = 0, slot = &p->slots[0]; i < 8; i++, slot++) {
      if (p->activeMask & (1 << i)) {
        PTR_ARRAY_085ad32c[slot->state](p, slot);
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/Entity080dc44c_Update.inc");
#endif
}

// 使用中の枠の粒子をまとめて外す
// 残差6命令 (32 対 38), 原典はビット判定の結果を 1/0 として作ってから改めて 0 と比べる (0/1 の作り置き)
NON_MATCH s32 Entity080dc44c_Destroy(Entity080dc44c* p) {
#ifdef NONMATCHING_C
  Entity080dc44cSlot* slot = &p->slots[0];
  s32 i;

  for (i = 0; i < 8; i++, slot++) {
    if (p->activeMask & (1 << i)) {
      Particle_Remove(&p->ptcls[slot->idx]);
    }
  }
  gEntity080dc44c = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity080dc44c_Destroy.inc");
#endif
}

void FUN_080dc418(Entity080dc44c* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
}

s32 Entity080dc44c_Init(Entity080dc44c* p) {
  FUN_080dc418(p);
  return 0;
}

Entity080dc44c* Entity080dc44c_Create(void) {
  if (gEntity080dc44c == NULL) {
    Entity080dc44c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080dc44c));
    gEntity080dc44c = p;
    if (p != NULL) {
      SetEntityRoutine(p, Entity080dc44c_Update, Entity080dc44c_Destroy);
      if (Entity080dc44c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080dc44c;
}

void FUN_080dc498(void) { gEntity080dc44c = NULL; }
