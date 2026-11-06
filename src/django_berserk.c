#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"

// プレイヤーの周りを旋回する粒子1個ぶんの枠,16個を使い回す
typedef struct {
  Particle ptcl;  // 0x00, Particle_Remove / Particle_SetPose に Particle* として渡る
  bool8 active;   // 0x28, FUN_0807f8d0 が 0 の枠を飛ばし、lifetime が尽きると 0 に戻す
  u8 angle;       // 0x29, FUN_0807f650 が毎フレーム angleStep を足し、gSineTable の8bit索引にする
  u8 riseSpeed;   // 0x2A, FUN_0807f650 が ptcl.pos.y に足す
  u8 startDelay;  // 0x2B, frameCounter がこれを超えるまで radius の伸びが 1/フレームに抑えられる
  u8 animTimer;   // 0x2C, 0..7 を巡回,0 で anim 4、4 で anim 5 に差し替える
  u8 angleStep;   // 0x2D, angle に足す量,8フレームごとに 2 まで減衰する
  u8 lifetime;    // 0x2E, FUN_0807f8d0 が毎フレーム -1,0 で ptcl を隠して active を落とす
  u8 mode;        // 0x2F, 0 なら FUN_0807f650 (旋回)、それ以外なら FUN_0807f750 (直進)
  u16 radius;     // 0x30, 旋回半径,startDelay 経過後は毎フレーム +6、手前は +1
  u8 unk_32[2];   // 0x32, padding?
  Vec3 vel;       // 0x34, FUN_0807f750 が ptcl.pos.x と .z に足す (y は読まれない)
} DjangoBerserkParticle;
static_assert(sizeof(DjangoBerserkParticle) == 60);

// 黒ジャンゴが暴走する処理(暴走: プレイヤーのHPが半分になるが、画面上の全ての敵にダメージ)
typedef struct DjangoBerserk {
  Entity e;                                       // 0x000, ENTITY_UNK_11
  Player* player;                                 // 0x018
  MainSpriteGfx gfx;                              // 0x01C, SPRITE_DJANGO_SABATA
  MainSprite sprite;                              // 0x03C, SPRITE_DJANGO_SABATA
  HitboxData hitbox;                              // 0x09C
  u8 unk_ec[2];                                   // 0x0EC
  u16 timer;                                      // 0x0EE, SetState が状態を差し替えるたび 0 に戻す
  u16 hpDrainStep;                                // 0x0F0, Init: (player->hp - hpTarget) / 0x48 + 1,毎フレーム player->hp から引く量
  u16 hpTarget;                                   // 0x0F2, Init: player->hp >> 1 (0 なら 1),ここまで削って止める
  ParticleGroup* group;                           // 0x0F4, PTCL_GROUP_2
  DjangoBerserkParticle ptcls[16];                // 0x0F8, 根拠: _Destroy が stride 0x3C で 16回 Particle_Remove する
  u16 frameCounter;                               // 0x4B8, FUN_0807f8d0 が毎フレーム +1,リセットされない,ptcls[].startDelay と比較される
  u8 unk_4ba[6];                                  // 0x4BA
  void (*updateCallback)(struct DjangoBerserk*);  // 0x4C0
} DjangoBerserk;
static_assert(sizeof(DjangoBerserk) == 1220);

static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

void FUN_0807f9d8(DjangoBerserk* p);
void FUN_0807fdac(DjangoBerserk* p);
void FUN_0807fd1c(DjangoBerserk* p);
void FUN_0807f78c(DjangoBerserk* p, Vec3* pos, u32 angle);

// 状態関数を差し替えて経過フレームを 0 に戻す
void DjangoBerserk_SetState(DjangoBerserk* p, void* fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

void FUN_0807f650(DjangoBerserk* p, DjangoBerserkParticle* e) {
  e->angle += e->angleStep;
  e->ptcl.pos.x = p->player->mover.pos.x + POLAR_X(e->radius, e->angle);
  e->ptcl.pos.z = p->player->mover.pos.z + POLAR_Z(e->radius, e->angle);
  if (p->frameCounter >= e->startDelay) {
    if ((p->frameCounter & 7) == 0 && e->angleStep > 2) {
      e->angleStep--;
    }
    e->radius += 6;
    e->ptcl.pos.y += e->riseSpeed;
  } else {
    e->radius++;
  }
  if (e->animTimer == 0) {
    Particle_SetPose(&e->ptcl, p->group, 4);
  } else if (e->animTimer == 4) {
    Particle_SetPose(&e->ptcl, p->group, 5);
  }
  if (++e->animTimer > 7) {
    e->animTimer = 0;
  }
}

// 直進モードの粒子, vel のぶん進めて animTimer が 5 になったらコマを差し替える
void FUN_0807f750(DjangoBerserk* p, DjangoBerserkParticle* ptcl) {
  ptcl->ptcl.pos.x += ptcl->vel.x;
  ptcl->ptcl.pos.z += ptcl->vel.z;
  ptcl->animTimer++;

  if (ptcl->animTimer == 5) {
    Particle_SetPose(&ptcl->ptcl, p->group, PTCL2_DARK_S);
  }
}

// 空いている粒子を1つ pos の周りから angle の向きへ直進させる
// 残差: 位置に乱数を足すところで, 原典は乱数を引いてから pos を ldrh で読み (pos - 63) + 乱数 にする (EntityE534 系と同じ壁)
NON_MATCH void FUN_0807f78c(DjangoBerserk* p, Vec3* pos, u32 angle) {
#ifdef NONMATCHING_C
  DjangoBerserkParticle* e;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (!p->ptcls[i].active) {
      break;
    }
  }
  if (i > 15) {
    return;
  }
  e = &p->ptcls[i];
  e->ptcl.flags &= ~SPRFLAG_HIDDEN;
  e->ptcl.pos = *pos;
  {
    u16* table = gRandomTable;

    e->ptcl.pos.x += (_Random(table) & 127) - 63;
    e->ptcl.pos.z += (_Random(table) & 127) - 63;
  }
  e->ptcl.pos.y += 128;
  Particle_SetPose(&e->ptcl, p->group, 4);
  e->vel.x = POLAR_X(6, angle);
  e->vel.z = POLAR_Z(6, angle);
  e->animTimer = 0;
  e->mode = 1;
  e->lifetime = (Random() & 7) + 8;
  e->active = TRUE;
#else
  INCFUNC("asm/func/FUN_0807f78c.inc");
#endif
}

// 粒子を寿命まで mode ごとに動かす
void FUN_0807f8d0(DjangoBerserk* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->ptcls[i].active) {
      if (--p->ptcls[i].lifetime == 0) {
        p->ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
        p->ptcls[i].active = FALSE;
      } else if (p->ptcls[i].mode == 0) {
        FUN_0807f650(p, &p->ptcls[i]);
      } else {
        FUN_0807f750(p, &p->ptcls[i]);
      }
    }
  }
  p->frameCounter++;
}

// 暴走の始まり, 声を出しつつスプライトの高さをプレイヤーへ寄せ, 60 フレームで次へ移る
void FUN_0807f94c(DjangoBerserk* p) {
  Player* player;

  if (p->timer == 0) {
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    PlaySound_082406e0(VO_DARK_DJANGO_UGH_770);
    PlaySound_082406e0(SE_506);
  }
  player = gPlayerPtr[0];
  player->human.flags |= SPRFLAG_HIDDEN;
  p->sprite.pos.y = (p->sprite.pos.y * 15 + player->mover.pos.y + 150) >> 4;
  MainSprite_AdvanceAnim(&p->sprite, &p->gfx);
  if (++p->timer > 59) {
    p->sprite.priority = 1;
    DjangoBerserk_SetState(p, FUN_0807f9d8);
  }
}

// 暴走本体, 画面を斜めに駆け回りながら粒子を撒き, プレイヤーの体力を hpTarget まで削る
// 残差: 369 対 364 命令, timer * 32 - 定数 + カメラ座標 の足し算の順と, 同じ定数の作り方 (原典は定数をプールから読む) が区間ごとに少しずつ違う
NON_MATCH void FUN_0807f9d8(DjangoBerserk* p) {
#ifdef NONMATCHING_C
  Player* player;

  if (p->timer == 0) {
    PlaySound_082406e0(VO_BERSERK);
    PlaySound_082406e0(SONG_507);
  }
  player = gPlayerPtr[0];
  player->human.flags |= SPRFLAG_HIDDEN;
  ParticleShadow_Hide(&player->shadow);
  if (p->timer < 8) {
    if (p->timer == 0) {
      p->sprite.flags |= SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 399, 1, 0);
    }
    p->sprite.pos.x = p->player->mover.pos.x - p->timer * 128;
    p->sprite.pos.z = p->player->mover.pos.z;
    FUN_0807f78c(p, &p->sprite.pos, 128);
  } else if (p->timer < 24) {
    if (p->timer == 8) {
      p->sprite.flags &= ~SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 399, 1, 1);
    }
    p->sprite.pos.x = p->timer * 32 - 768 + gCameraCoords.worldPos.x;
    p->sprite.pos.z = gCameraCoords.worldPos.z - (p->timer - 16) * 128;
    FUN_0807f78c(p, &p->sprite.pos, 72);
  } else if (p->timer < 40) {
    if (p->timer == 24) {
      p->sprite.flags |= SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 400, 1, 1);
    }
    p->sprite.pos.x = gCameraCoords.worldPos.x - (p->timer * 32 - 1280);
    p->sprite.pos.z = (p->timer - 32) * 128 + gCameraCoords.worldPos.z;
    FUN_0807f78c(p, &p->sprite.pos, 200);
  } else if (p->timer < 56) {
    if (p->timer == 40) {
      p->sprite.flags |= SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 399, 1, 1);
    }
    p->sprite.pos.x = gCameraCoords.worldPos.x - (p->timer - 48) * 128;
    p->sprite.pos.z = p->timer * 32 - 1280 + gCameraCoords.worldPos.z;
    FUN_0807f78c(p, &p->sprite.pos, 9);
  } else if (p->timer < 72) {
    if (p->timer == 56) {
      p->sprite.flags &= ~SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 400, 1, 1);
    }
    p->sprite.pos.x = (p->timer - 64) * 128 + gCameraCoords.worldPos.x;
    p->sprite.pos.z = p->timer * 32 - 2304 + gCameraCoords.worldPos.z;
    FUN_0807f78c(p, &p->sprite.pos, 137);
  } else {
    if ((p->timer & 3) == 0) {
      FUN_0807f78c(p, &p->sprite.pos, 192);
    }
    if (p->timer == 72) {
      p->sprite.flags |= SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 400, 1, 1);
    }
    if (p->timer == 96) {
      p->sprite.flags |= SPRFLAG_XFLIP;
      MainSprite_SetAnim(&p->sprite, &p->gfx, 402, 1, 0);
    }
    p->sprite.pos.x = p->player->mover.pos.x;
    p->sprite.pos.z = p->player->mover.pos.z - (104 - p->timer) * 32;
    if (p->sprite.pos.y > gPlayerPtr[0]->mover.pos.y) {
      p->sprite.pos.y -= 10;
    } else {
      p->sprite.pos.y = gPlayerPtr[0]->mover.pos.y;
    }
  }
  MainSprite_AdvanceAnim(&p->sprite, &p->gfx);
  if (p->player->hp > p->hpTarget) {
    s32 hp = p->player->hp - p->hpDrainStep;

    if (hp < p->hpTarget) {
      p->player->hp = p->hpTarget;
    } else {
      p->player->hp = hp;
    }
  }
  if (++p->timer > 104) {
    p->sprite.priority = 2;
    p->player->hp = p->hpTarget;
    DjangoBerserk_SetState(p, FUN_0807fd1c);
  }
#else
  INCFUNC("asm/func/FUN_0807f9d8.inc");
#endif
}

// 暴走の終わり, アニメが終わったらプレイヤーの向きと姿を戻して最後の状態へ移る
void FUN_0807fd1c(DjangoBerserk* p) {
  if (p->timer == 0) {
    PlaySound_082406e0(SONG_432);
    p->timer++;
  }
  gPlayerPtr[0]->human.flags |= SPRFLAG_HIDDEN;
  ParticleShadow_Show(&gPlayerPtr[0]->shadow);
  if (MainSprite_AdvanceAnim(&p->sprite, &p->gfx)) {
    gPlayerPtr[0]->action = 0;
    gPlayerPtr[0]->facing = 5;
    gPlayerPtr[0]->animIDOffset = 3;
    gPlayerPtr[0]->xflip = TRUE;
    DjangoBerserk_SetState(p, FUN_0807fdac);
  }
}

// 最後の状態, 6 フレームだけ攻撃判定を出してから消える
void FUN_0807fdac(DjangoBerserk* p) {
  p->sprite.flags |= SPRFLAG_HIDDEN;
  if (p->timer == 0) {
    EnableEntityFlags(ENTITY_DISABLE_2);
    gGameFlags &= ~GAMEFLAG_UNK_0;
  }
  if (++p->timer <= 5) {
    Hitbox_Register(&p->hitbox);
  } else {
    KillEntity((Entity*)p);
  }
}

s32 DjangoBerserk_Update(DjangoBerserk* p) {
  FUN_0807f8d0(p);
  p->updateCallback(p);
  return 0;
}

s32 DjangoBerserk_Destroy(DjangoBerserk* p) {
  s32 i;

  MainSprite_Remove(&p->sprite);
  for (i = 0; i < 16; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

void LoadPlayerSprite_0807fe48(DjangoBerserk* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);

  if (f != NULL) {
    p->gfx = *f;
    OpenMainSpriteFile(&p->gfx, f);
    MainSprite_Add(&p->sprite, &p->gfx, 0, SPRFLAG_UNK_15 | SPRFLAG_GAMEOVER, 2, 0, 60, &p->player->mover.pos);
    MainSprite_SetAnim(&p->sprite, &p->gfx, 398, 1, 0);
    p->sprite.plttID = 38;
    p->sprite.pltt = p->player->human.pltt;
  }
}

// 画面全体に届く攻撃判定を用意する, 威力はプレイヤーの最大体力の半分
void FUN_0807fed0(DjangoBerserk* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size;
  Vec3 offset;

  VEC3_SET(size, 30000, 30000, 30000);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, (u16)(1 << p->player->mover.unk_4), &size, &offset);
  Hitbox_SetAttack(hitbox, p->player->maxHP >> 1, 50, 0, HBATTR_18, 50);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->player->mover.pos, 0);
}

// プレイヤーの周りに 16 個の粒子を等間隔から少しずらして並べる
// 残差: 214 対 209 命令, 原典はループ中で乱数表のアドレスを毎回読み直し, 添字はスタックに i と i * 16 の2本で持つ (HealingEffect_InitParticles と同系統)
NON_MATCH void FUN_0807ff78(DjangoBerserk* p) {
#ifdef NONMATCHING_C
  s32 baseAngle = Random() & 0xFF;
  s32 i;

  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 16; i++) {
    DjangoBerserkParticle* e = &p->ptcls[i];

    Particle_Add(&e->ptcl, p->group, 0);
    Particle_SetOffset(&e->ptcl, -4, -4);
    Particle_SetPltt(&e->ptcl, 1);
    e->angle = baseAngle + i * 16 + (Random() & 7);
    e->angleStep = (Random() & 3) + 7;
    e->radius = ((Random() >> 3) & 0x5F) + 96;
    e->riseSpeed = (i & 3) * 2 + 1;
    e->startDelay = (Random() & 31) + 8;
    e->ptcl.pos.x = p->player->mover.pos.x + POLAR_X(e->radius, e->angle);
    e->ptcl.pos.y = p->player->mover.pos.y;
    e->ptcl.pos.z = p->player->mover.pos.z + POLAR_Z(e->radius, e->angle);
    e->ptcl.priority = 2;
    e->ptcl.offsetZ = -20;
    e->animTimer = Random() & 7;
    if (e->animTimer <= 3) {
      Particle_SetPose(&e->ptcl, p->group, 4);
    } else {
      Particle_SetPose(&e->ptcl, p->group, 5);
    }
    e->animTimer = 0;
    e->mode = 0;
    e->lifetime = (Random() & 15) + 56;
    e->active = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_0807ff78.inc");
#endif
}

// HP を半分まで削る演出を開始する, hpTarget が下限、hpDrainStep が毎フレーム引く量
s32 DjangoBerserk_Init(DjangoBerserk* p, Player* player) {
  p->player = player;
  LoadPlayerSprite_0807fe48(p);
  FUN_0807fed0(p);
  FUN_0807ff78(p);
  DjangoBerserk_SetState(p, FUN_0807f94c);
  gGameFlags |= GAMEFLAG_UNK_0;
  p->hpTarget = p->player->hp >> 1;
  if (p->hpTarget == 0) {
    p->hpTarget = 1;
  }
  p->hpDrainStep = Div(p->player->hp - p->hpTarget, 72) + 1;
  return 0;
}

DjangoBerserk* DjangoBerserk_Create(Player* player) {
  DjangoBerserk* p = CreateEntity(ENTITY_UNK_11, sizeof(DjangoBerserk));

  if (p != NULL) {
    SetEntityRoutine(p, DjangoBerserk_Update, DjangoBerserk_Destroy);
    if (DjangoBerserk_Init(p, player) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
