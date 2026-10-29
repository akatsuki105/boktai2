#include "coffin.h"
#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "particle.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

typedef struct {
  Particle ptcl;  // 0x00
  Vec3 vel;       // 0x28, 毎フレーム ptcl.pos に足す
  bool16 active;  // 0x30, 0 でない枠だけ更新する
  u16 timer;      // 0x32, 16 フレームで消える
} SolarCirclePtcl;
static_assert(sizeof(SolarCirclePtcl) == 52);

// 太陽結界(この上に置いたイモータルが入った棺桶は逃げ出さない)
typedef struct SolarCircle {
  Entity e;                                     // 0x000, ENTITY_UNK_9
  AuxSprite sprite;                             // 0x018, flags に SPRFLAG_BLINK_ODD が立つ, pos より y が 0x1E 高い (立体的に見せるため)
  AuxSpriteGfx gfx;                             // 0x044, SPRITE_MAGIC_CIRCLE, パレット 99
  AuxSprite sprite2;                            // 0x060, flags に SPRFLAG_BLINK_EVEN が立つ
  AuxSpriteGfx gfx2;                            // 0x08C, SPRITE_MAGIC_CIRCLE, パレット 97
  bool16 enabled;                               // 0x0A8, IsCoffinInside の結果
  u16 stateTimer;                               // 0x0AA, Init が 0 を書く
  Vec3 pos;                                     // 0x0AC, '.p', y はタイルの attr から計算し直す
  void (*updateCallback)(struct SolarCircle*);  // 0x0B4, '.m' があるかで切り替える
  ParticleGroup* group;                         // 0x0B8, PTCL_GROUP_2
  u8 unk_bc;                                    // 0x0BC
  u8 unk_bd;                                    // 0x0BD
  u16 unk_be;                                   // 0x0BE, 2フレームに1回だけ FUN_080a1e78 を呼ぶためのカウンタ
  SolarCirclePtcl ptcls[8];                     // 0x0C0
  u32 scriptIn;                                 // 0x260, '.i', 棺桶が太陽結界に入った時に呼ばれるスクリプトID
  u32 scriptOut;                                // 0x264, '.o', 棺桶が太陽結界から出た時に呼ばれるスクリプトID
} SolarCircle;
static_assert(sizeof(SolarCircle) == 616);

// 1枠を1フレーム進める, 16フレームで消える
// 残差1命令 (37/38) でこちらが短い: 原典は timer の 16bit 切り詰めを使うたびに作り直すが, こちらは最初の (timer << 16) を使い回す
NON_MATCH void FUN_080a1e28(SolarCirclePtcl* elem, ParticleGroup* g) {
#ifdef NONMATCHING_C
  elem->timer++;
  if (elem->timer > 15) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
  } else {
    elem->ptcl.pos.x += elem->vel.x;
    elem->ptcl.pos.y += elem->vel.y;
    elem->ptcl.pos.z += elem->vel.z;
    Particle_SetPose(&elem->ptcl, g, ((elem->timer >> 2) & 1) + 2);
  }
#else
  INCFUNC("asm/func/FUN_080a1e28.inc");
#endif
}

// 空いている枠を1つ起こして結界の内側に散らす
// 残差5命令 (102/107) でこちらが短い: 原典は &unk_bd や定数 0xFF を高位レジスタに巻き上げて回すが, こちらは低位レジスタで足りる
NON_MATCH void FUN_080a1e78(SolarCircle* p, ParticleGroup* g) {
#ifdef NONMATCHING_C
  SolarCirclePtcl* q = &p->ptcls[p->unk_bd];
  s32 idx;

  Particle_SetPose(&q->ptcl, g, 2);
  q->ptcl.flags &= ~SPRFLAG_HIDDEN;

  idx = (gRandTableIdx + 1) & 0x3FF;
  q->ptcl.pos.x = ((*(gRandomTable + idx) >> 4) & 0xFF) + p->pos.x - 0x7F;
  idx = (idx + 1) & 0x3FF;
  q->ptcl.pos.y = (*(gRandomTable + idx) & 0x3F) + p->pos.y;
  idx = (idx + 1) & 0x3FF;
  q->ptcl.pos.z = ((*(gRandomTable + idx) >> 4) & 0xFF) + p->pos.z - 0x7F;
  q->vel.x = 0;
  idx = (idx + 1) & 0x3FF;
  gRandTableIdx = idx;
  q->vel.y = (*(gRandomTable + idx) & 0xF) + 0x10;
  q->vel.z = 0;
  q->timer = 0;
  q->active = TRUE;

  p->unk_bd++;
  if (p->unk_bd > 7) {
    p->unk_bd = 0;
  }
#else
  INCFUNC("asm/func/FUN_080a1e78.inc");
#endif
}

// 棺桶が結界の内側にいるかどうか
static bool32 IsCoffinInside(SolarCircle* p) {
  WorldPos* pos = Coffin_GetPos();
  u16 dx, dz;

  if (pos == NULL) {
    return FALSE;
  }

  dx = abs(pos->x - p->pos.x);
  dz = abs(pos->z - p->pos.z);
  if (dx >= Q8(0.5) || dz >= Q8(0.5)) {
    return FALSE;
  }

  if (dx * dx + dz * dz < (Q8(0.5) * Q8(0.5))) {
    return TRUE;
  }

  // 原典は円の外のとき return を書き忘れている
}

// 結界の内側に棺桶が入ったかどうかを見て、入った/出たタイミングでスクリプトを実行する
// 残差7命令 (81/88) でこちらが短い: 原典は unk_be の 16bit 切り詰め (0xFFFF のレジスタ AND) が & 7 / & 3 と畳まれずに残る
// Tier A-B 試済: (u16) の明示キャスト, ローカルへの代入 (どちらも畳まれたまま)
NON_MATCH void FUN_080a1fc4(SolarCircle* p) {
#ifdef NONMATCHING_C
  if (!p->enabled) {
    if (IsCoffinInside(p) && gCoffin->state == 1) {
      p->enabled = TRUE;
      if (p->scriptIn != 0) {
        VM_ExecByID(p->scriptIn, NULL);
      }
      Coffin_SetInsideSolarCircle(TRUE);
      PlaySound_082406e0(SONG_408);
    }

    p->unk_be++;
    if ((p->unk_be & 7) == 0) {
      FUN_080a1e78(p, p->group);
    }
  } else {
    if (!IsCoffinInside(p)) {
      if (p->scriptOut != 0) {
        VM_ExecByID(p->scriptOut, NULL);
      }
      Coffin_SetInsideSolarCircle(FALSE);
      p->enabled = FALSE;
      PlaySound_082406e0(SONG_409);
    }

    p->unk_be++;
    if ((p->unk_be & 3) == 0) {
      FUN_080a1e78(p, p->group);
    }
  }
#else
  INCFUNC("asm/func/FUN_080a1fc4.inc");
#endif
}

// 結界が出きったあと, 15フレームかけて浮かせてから FUN_080a1fc4 に移る
// 残差3命令 (50/53) でこちらが短い: 原典は stateTimer の加算結果を別レジスタに作って 16bit 切り詰めと *2 の両方で使い回すが, こちらは加算を破壊的に行う
NON_MATCH void FUN_080a20a0(SolarCircle* p) {
#ifdef NONMATCHING_C
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->stateTimer++;
  if (p->stateTimer > 14) {
    p->sprite.pos.y = p->pos.y + Q8(0.12);
    p->stateTimer = 0;
    p->updateCallback = FUN_080a1fc4;
  } else {
    p->sprite.pos.y = p->stateTimer * 2 + p->pos.y;
  }

  p->unk_be++;
  if ((p->unk_be & 1) == 0) {
    FUN_080a1e78(p, p->group);
  }
#else
  INCFUNC("asm/func/FUN_080a20a0.inc");
#endif
}

// 結界が立ち上がる演出, 64フレームかけて sprite2 を拡大回転させてから FUN_080a20a0 に移る
void FUN_080a2114(SolarCircle* p) {
  p->sprite.flags |= SPRFLAG_HIDDEN;
  p->sprite2.flags &= ~SPRFLAG_HIDDEN;
  p->stateTimer++;
  if (p->stateTimer > 0x3F) {
    p->sprite2.flags &= ~SPRFLAG_AFFINE;
    p->sprite2.scaleX = Q6(1);
    p->sprite2.scaleY = Q6(1);
    p->stateTimer = 0;
    p->updateCallback = FUN_080a20a0;
    PlaySound_082406e0(SONG_815);
  } else {
    p->sprite2.flags |= SPRFLAG_AFFINE;
    p->sprite2.scaleX = p->stateTimer;
    p->sprite2.scaleY = p->stateTimer;
    p->sprite2.rotation = (u8)p->stateTimer * 4;
  }
}

// 有効な枠だけパーティクルを進めてから updateCallback を呼ぶ
s32 SolarCircle_Update(SolarCircle* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      FUN_080a1e28(&p->ptcls[i], p->group);
    }
  }

  p->updateCallback(p);
  return 0;
}

s32 SolarCircle_Destroy(SolarCircle* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  for (i = 0; i < 8; i++) {
    Particle_Remove((Particle*)&p->ptcls[i]);
  }
  return 0;
}

// 8枠ぶんのパーティクルを用意して全部隠しておく
void FUN_080a21fc(SolarCircle* p) {
  s32 i;

  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    Particle* ptcl = &p->ptcls[i].ptcl;

    Particle_Add(ptcl, p->group, 0);
    Particle_SetOffset(ptcl, -4, -4);
    Particle_SetPose(ptcl, p->group, 2);
    Particle_SetPltt(ptcl, 1);
    ptcl->priority = 1;
    ptcl->offsetZ = 0x14;
    ptcl->flags |= SPRFLAG_HIDDEN;
    p->ptcls[i].active = FALSE;
  }

  p->unk_bd = 0;
  p->unk_be = 0;
}

// 残差2命令 (251/249): p のレジスタだけ違う (原典は r7, こちらは r8) ので p 経由のロードに mov が2回余計に要る
NON_MATCH s32 SolarCircle_Init(SolarCircle* p, u32 id, u32 _) {
#ifdef NONMATCHING_C
  AuxSpriteGfx* gfx;
  AuxSprite* spr;

  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
    p->pos.y = TileHeightAt(&p->pos);
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
  }

  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_MAGIC_CIRCLE);
  spr = &p->sprite;
  AuxSprite_Add(spr, gfx, 0);
  spr->poseIdx = 6;
  Video_SetAuxSpritePltt(gfx, 99);
  p->sprite.flags |= SPRFLAG_BLINK_ODD;
  p->sprite.priority = 3;
  p->sprite.pos = p->pos;
  p->sprite.pos.y += Q8(0.12);

  gfx = &p->gfx2;
  Video_GetAuxSprite(gfx, SPRITE_MAGIC_CIRCLE);
  spr = &p->sprite2;
  AuxSprite_Add(spr, gfx, 0);
  spr->poseIdx = 6;
  Video_SetAuxSpritePltt(gfx, 97);
  p->sprite2.flags |= SPRFLAG_BLINK_EVEN;
  p->sprite2.priority = 3;
  p->sprite2.pos = p->pos;

  FUN_080a21fc(p);

  if (VM_SeekToNamedArg('m') && VM_GetValue()) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    p->updateCallback = FUN_080a2114;
    PlaySound_082406e0(SONG_350);
  } else {
    p->updateCallback = FUN_080a1fc4;
  }

  p->stateTimer = 0;
  if (IsCoffinInside(p)) {
    p->enabled = TRUE;
  } else {
    p->enabled = FALSE;
  }

  if (VM_SeekToNamedArg('i')) {
    p->scriptIn = VM_GetValue();
  } else {
    p->scriptIn = 0;
  }

  if (VM_SeekToNamedArg('o')) {
    p->scriptOut = VM_GetValue();
  } else {
    p->scriptOut = 0;
  }

  if (IsCoffinInside(p)) {
    p->enabled = TRUE;
    Coffin_SetInsideSolarCircle(TRUE);
  } else {
    p->enabled = FALSE;
    Coffin_SetInsideSolarCircle(FALSE);
  }

  return 0;
#else
  INCFUNC("asm/func/SolarCircle_Init.inc");
#endif
}

// 0xF156, HashName("太陽結界")
SolarCircle* SolarCircle_Create(u32 id, u32 unused) {
  SolarCircle* p = CreateEntity(ENTITY_UNK_9, sizeof(SolarCircle));

  if (p != NULL) {
    SetEntityRoutine(p, SolarCircle_Update, SolarCircle_Destroy);
    if (SolarCircle_Init(p, id, unused) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
