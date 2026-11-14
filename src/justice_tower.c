#include "camera.h"
#include "camera_inline.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"

#define TYPE_JUSTICE 0  // 正義のカード (演出: 鉄球, 対象: 敵のみ)
#define TYPE_TOWER 1    // 塔のカード (演出: パーティクル, 対象: 自分も含む全て)

// 演出で飛ばす粒子1個ぶんの枠, 8個を使い回す
typedef struct Entity080aace8Particle {
  Particle ptcl;                               // 0x00, _Destroy が Particle_Remove に渡す
  u16 timer;                                   // 0x28, 16 フレームで消える
  u16 active;                                  // 0x2A, FUN_080aa208 が 0 の枠を飛ばす
  u16 velX;                                    // 0x2C, 毎フレーム ptcl.pos.x に足す
  u16 velY;                                    // 0x2E, 毎フレーム ptcl.pos.y に足す, 8フレームごとに 1 増える
  u8 unk_30[4];                                // 0x30
  ParticleGroup* group2;                       // 0x34, PTCL_GROUP_2
  void (*fn)(struct Entity080aace8Particle*);  // 0x38, FUN_080aa208 が active な枠について呼ぶ
} Entity080aace8Particle;
static_assert(sizeof(Entity080aace8Particle) == 60);

// IET_AOE ("正義のカード", "塔のカード") の 効果処理 及び 演出
typedef struct Entity080aace8 {
  Entity e;                                        // 0x000, ENTITY_UNK_11
  Player* player;                                  // 0x018, _Init の第2引数
  MainSprite icon;                                 // 0x01C, SPRITE_INVENTORY_ICONS
  Vec3 spritePos;                                  // 0x07C, screen から少しずらした icon の表示位置
  Vec3 screen;                                     // 0x084, player->mover.pos の y に +0x96 した点を投影した画面座標
  u8 unk_8c[8];                                    // 0x08C
  HitboxData hitbox;                               // 0x094
  AuxSprite auxSprites[2];                         // 0x0E4
  AuxSpriteGfx gfx;                                // 0x13C, SPRITE_SPIKEBALL
  u16 unk_158;                                     // 0x158, 次に使う auxSprites の添字 (0 と 1 を交互)
  u8 unk_15a[2];                                   // 0x15A, auxSprites[i] の演出段階 (0: 停止, 1: 落下, 2: 跳ね)
  u16 unk_15c[2];                                  // 0x15C, auxSprites[i] の着地する y
  u16 unk_160[2];                                  // 0x160, 段階ごとの経過フレーム数
  Entity080aace8Particle ptcls[8];                 // 0x164
  u8 unk_344[4];                                   // 0x344
  u16 kind;                                        // 0x348, 0: TYPE_JUSTICE, 1: TYPE_TOWER
  u16 unk_34a;                                     // 0x34A, 消えるまでの経過フレーム数
  void (*updateCallback)(struct Entity080aace8*);  // 0x34C
} Entity080aace8;
static_assert(sizeof(Entity080aace8) == 848);

// 1枠を1フレーム進める, 16フレームで消える
void FUN_080aa08c(Entity080aace8Particle* q) {
  if (++q->timer > 15) {
    q->ptcl.flags |= SPRFLAG_HIDDEN;
    q->active = 0;
  } else {
    Particle_SetPose(&q->ptcl, q->group2, PTCL2_SOL_L + ((q->timer >> 2) & 1));
    q->ptcl.pos.x += q->velX;
    q->ptcl.pos.y += q->velY;
    if ((q->timer & 7) == 0) {
      q->velY++;
    }
  }
}

// 8枠を spritePos から放射状に飛ばす
// 残差1命令 (135/135, レジスタは全一致): 原典は i * 32 の lsls を乱数のロードとシフトの間に出すが, 文の順序では挟めない (digit をローカルに分ける前は早すぎ, 分けると遅すぎ)
// Tier A-C は試済: RNG の項を先に書く / % 16 と % 4 (シフト後の値には符号補正が入って悪化) はいずれも hunk 増加
NON_MATCH void FUN_080aa0e4(Entity080aace8* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    s32 digit;
    s32 angle;
    s32 speed;

    p->ptcls[i].ptcl.pos.x = p->spritePos.x + 8;
    p->ptcls[i].ptcl.pos.y = p->spritePos.y + 8;

    digit = (RandomNext() >> 3) & 0xF;
    angle = i * 32 + digit - 8;
    speed = ((RandomNext() >> 3) & 3) + 4;
    p->ptcls[i].velX = POLAR_X(speed, angle);
    p->ptcls[i].velY = POLAR_Z(speed, angle);
    p->ptcls[i].ptcl.flags &= ~SPRFLAG_HIDDEN;
    p->ptcls[i].active = 1;
    p->ptcls[i].timer = 0;
    p->ptcls[i].fn = FUN_080aa08c;
  }
#else
  INCFUNC("asm/func/FUN_080aa0e4.inc");
#endif
}

void FUN_080aa208(Entity080aace8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active != 0) {
      p->ptcls[i].fn(&p->ptcls[i]);
    }
  }
}

// 画面を揺らしながら 16 フレームで消える
void FUN_080aa23c(Entity080aace8* p) {
  Camera_Shake((0x10 - p->unk_34a) * 2);
  if (p->unk_34a <= 5) {
    Hitbox_Register(&p->hitbox);
  } else if (p->unk_34a == 6) {
    gGameFlags &= ~GAMEFLAG_NO_PAUSE;
  }

  p->unk_34a++;
  if (p->unk_34a > 15) {
    KillEntity((Entity*)p);
  }
}

// 棘鉄球を1つ、カメラ注視点から見て乱数で決めた方角・距離の空中に出す
// 残差2命令 (256/254): 原典は gRandomTable と gRandTableIdx のアドレスを両方低位レジスタに置くが, こちらは片方を ip に追い出す
NON_MATCH void FUN_080aa29c(Entity080aace8* p) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &p->auxSprites[p->unk_158];
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 angle;
  s32 dist;
  s32 dx;
  s32 dy;
  s32 idx;
  s32 bx;
  s32 bz;
  s32 tileIdx;

  angle = Div(p->unk_34a, 0x12);
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = ((angle << 6) + (*(gRandomTable + idx) & 0x3F)) & 0xFF;
  idx = (idx + 1) & 0x3FF;
  gRandTableIdx = idx;
  dist = (*(gRandomTable + idx) & 0xFF) + 0x80;

  dx = FixToInt(12, dist * COS(angle));
  dy = FixToInt(13, gSineTable[angle] * dist * 3);

  spr->flags &= ~SPRFLAG_HIDDEN;
  spr->pos = gCameraCoords.worldPos;
  spr->pos.x = spr->pos.x - 0x4B + (dx - dy);
  spr->pos.y = 0x352 + spr->pos.y;
  spr->pos.z = spr->pos.z - 0x4B + (dx + dy);

  p->unk_15a[p->unk_158] = 1;
  p->unk_160[p->unk_158] = 0;

  bx = (s8)(spr->pos.x >> 8);
  bz = (s8)(spr->pos.z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    tileIdx = 0;
  } else {
    tileIdx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(tileIdx, 1);
  if (ov != NULL) {
    tile = &ov->tile;
  } else {
    tile = &gCollisionMap->tiledata->tiles[tileIdx];
  }

  if (tile->attr & TATTR_FALLDEATH) {
    p->unk_15c[p->unk_158] = 0;
  } else {
    p->unk_15c[p->unk_158] = TileHeightAt(&spr->pos);
  }

  p->unk_158 = 1 - p->unk_158;
#else
  INCFUNC("asm/func/FUN_080aa29c.inc");
#endif
}

// 棘鉄球2つを落として跳ねさせる
// 残差1命令 (113/112): スタックスロットが1つ多いだけの割当差
NON_MATCH void FUN_080aa4e8(Entity080aace8* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 2; i++) {
    if (p->unk_15a[i] != 0) {
      AuxSprite* spr = &p->auxSprites[i];

      if (p->unk_15a[i] == 1) {
        spr->pos.y -= 0x32;
        if (spr->pos.y > p->unk_15c[i]) {
          p->unk_160[i]++;
          if (p->unk_160[i] > 0x18) {
            spr->flags |= SPRFLAG_HIDDEN;
            p->unk_15a[i] = 0;
            p->unk_160[i] = 0;
          }
        } else {
          PlaySound_082406e0(SE_SPIKEBALL);
          spr->pos.y = p->unk_15c[i];
          p->unk_15a[i] = 2;
          p->unk_160[i] = 0;
        }
      } else {
        p->unk_160[i]++;
        if (p->unk_160[i] <= 0xB) {
          spr->pos.y -= (p->unk_160[i] >> 2) - 0xC;
        } else {
          spr->flags |= SPRFLAG_HIDDEN;
          p->unk_15a[i] = 0;
          p->unk_160[i] = 0;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080aa4e8.inc");
#endif
}

// 0x12 フレームごとに波を1回出し、0x7A フレームで片付けて FUN_080aa23c に移る
void FUN_080aa5d0(Entity080aace8* p) {
  if (p->unk_34a == 0 || p->unk_34a == 0x12 || p->unk_34a == 0x24 || p->unk_34a == 0x36 || p->unk_34a == 0x48 || p->unk_34a == 0x5A) {
    FUN_080aa29c(p);
  }

  FUN_080aa4e8(p);
  p->unk_34a++;
  if (p->unk_34a > 0x79) {
    s32 i;

    for (i = 0; i < 2; i++) {
      p->auxSprites[i].flags |= SPRFLAG_HIDDEN;
    }

    CLEAR_FLAGS(gSuspendFlags, SUSPEND_MENU);
    p->updateCallback = FUN_080aa23c;
    p->unk_34a = 0;
  }
}

// 画面を揺らしつつ 0x30 フレームで消える, 最初の1フレームでフラッシュを入れる
void FUN_080aa658(Entity080aace8* p) {
  if (p->unk_34a == 0) {
    CLEAR_FLAGS(gSuspendFlags, SUSPEND_MENU);
    PlaySound_082406e0(SE_THE_TOWER);
    StartBgObjPlttFade(2, 4, 0x1F, 0x1F, 0x1F, 0x1FFF, 1);
  }

  if (p->unk_34a <= 5) {
    Hitbox_Register(&p->hitbox);
  } else if (p->unk_34a == 6) {
    gGameFlags &= ~GAMEFLAG_NO_PAUSE;
  }
  if (++p->unk_34a > 0x2F) {
    KillEntity((Entity*)p);
  } else if (p->unk_34a <= 0xF) {
    Camera_Shake(0x20);
  } else {
    Camera_Shake(0x30 - p->unk_34a);
  }
}

// アイコンを8フレーム揺らし、0x1E フレームで弾けさせて 0x2D フレームで次の演出に移る
// 残差10命令 (115/125) でこちらが短い: 原典は p を r7 に置き &unk_34a を r10 に巻き上げて読み回す (高位レジスタ3本) が, こちらは p が r4 で2本, &unk_34a は使用箇所でプールから作り直す
// レジスタ名違いの hunk は全部この派生, Tier C は試済 (amp は >> 1 でなければ符号付き除算の補正が入る, kind の u16 は正しい)
NON_MATCH void FUN_080aa708(Entity080aace8* p) {
#ifdef NONMATCHING_C
  p->unk_34a++;
  if (p->unk_34a < 8) {
    s32 amp = 8 - p->unk_34a;
    p->icon.pos.x = p->spritePos.x + Mod(RandomNext() / 8, amp) - (amp >> 1);
    p->icon.pos.y = p->spritePos.y + Mod(RandomNext() / 8, amp) - (amp >> 1);
  }

  if (p->unk_34a == 30) {
    FUN_080aa0e4(p);
    PlaySound_082406e0(SONG_645);
    p->icon.flags |= SPRFLAG_HIDDEN;
  }

  if (p->kind == TYPE_TOWER && p->unk_34a == 29) {
    StartBgObjPlttFade(3, 5, 4, 4, 4, 0x1FFF, 1);
  }

  if (p->unk_34a > 44) {
    if (p->kind == TYPE_JUSTICE) {
      p->updateCallback = FUN_080aa5d0;
    } else {
      p->updateCallback = FUN_080aa658;
    }

    p->unk_34a = 0;
  }
#else
  INCFUNC("asm/func/FUN_080aa708.inc");
#endif
}

// 8フレームかけてアイコンを spritePos から screen へ寄せながら拡大する
void FUN_080aa834(Entity080aace8* p) {
  p->icon.flags &= ~SPRFLAG_HIDDEN;
  p->unk_34a++;
  if (p->unk_34a > 7) {
    p->icon.flags &= ~SPRFLAG_AFFINE;
    p->updateCallback = FUN_080aa708;
    p->unk_34a = 0;
    PlaySound_082406e0(SONG_644);
  } else {
    s32 scale = p->unk_34a * 2 + 0x20;

    p->icon.scaleY = scale;
    p->icon.scaleX = scale;
    p->icon.pos.x = Div(p->spritePos.x * p->unk_34a + p->screen.x * (8 - p->unk_34a), 8);
    p->icon.pos.y = Div(p->spritePos.y * p->unk_34a + p->screen.y * (8 - p->unk_34a), 8);
  }
}

s32 Entity080aace8_Update(Entity080aace8* p) {
  FUN_080aa208(p);
  p->updateCallback(p);
  return 0;
}

s32 Entity080aace8_Destroy(Entity080aace8* p) {
  s32 i;

  MainSprite_Remove(&p->icon);
  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  if (p->kind == 0) {
    for (i = 0; i < 2; i++) {
      AuxSprite_Remove(&p->auxSprites[i]);
    }
  }
  return 0;
}

// アイテムアイコンのスプライトを画面に出す
void FUN_080aa940(Entity080aace8* p) {
  MainSpriteGfx gfx;
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  s32 poseIdx;

  gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&gfx, f);
  poseIdx = p->kind == 0 ? ITEM_JUSTICE : ITEM_THE_TOWER;

  p->spritePos.x = p->screen.x - 8;
  p->spritePos.y = p->screen.y - 0x28;
  p->spritePos.z = p->screen.z;
  MainSprite_Add(&p->icon, &gfx, ICON_ITEM(poseIdx), SPRFLAG_AFFINE | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 1, PLAYMODE_PAUSE, 60, &p->screen);
  p->icon.scaleY = 0x22;
  p->icon.scaleX = 0x22;
}

// 鉄球のスプライトを2枚用意してプレイヤーの位置に置く
void FUN_080aa9d0(Entity080aace8* p) {
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPRITE_SPIKEBALL);
  for (i = 0; i < 2; i++) {
    AuxSprite_Add(&p->auxSprites[i], &p->gfx, SPRFLAG_HIDDEN);
    Video_SetAuxSpritePltt(&p->gfx, OBP_SPIKEBALL(2));
    p->auxSprites[i].pos = p->player->mover.pos;
  }
}

// 8枠ぶんのパーティクルを用意して全部止めておく
// 残差12命令 (43/55) でこちらが短い: 原典は定数 0 と枠のオフセットを高位レジスタに巻き上げて group2 だけ p + オフセットで触るが, こちらは1本のポインタで済ませる
NON_MATCH void FUN_080aaa2c(Entity080aace8* p) {
#ifdef NONMATCHING_C
  ParticleGroup* g = GetParticleGroup(PTCL_GROUP_2);
  Entity080aace8Particle* q = p->ptcls;
  s32 i;

  for (i = 0; i < 8; i++) {
    q->group2 = g;
    Particle_Add(&q->ptcl, g, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    Particle_SetOffset(&q->ptcl, -4, -4);
    Particle_SetPose(&q->ptcl, q->group2, PTCL2_SOL_L);
    Particle_SetPltt(&q->ptcl, 1);
    q->ptcl.priority = 0;
    q->timer = 0;
    q->active = 0;
    q++;
  }
#else
  INCFUNC("asm/func/FUN_080aaa2c.inc");
#endif
}

// 画面全体を覆う当たり判定を作る, 威力は失った HP か (変身中なら) レベル から決める
// 残差1命令 (105/106) でこちらが短い: 原典は HBATTR_NAMAKURA の 0x1000 を Hitbox_Init の前に作って高位レジスタに持ち越すが, こちらは使う直前に作る
NON_MATCH void FUN_080aaaa8(Entity080aace8* p) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;
  s32 power;
  s32 ignoreMask;

  halfSize.x = 0x7530, halfSize.y = 0x7530, halfSize.z = 0x7530;
  offset.x = 0, offset.y = 0, offset.z = 0;

  if (p->kind == TYPE_JUSTICE) {
    ignoreMask = 1 << p->player->mover.unk_4;
    power = p->player->maxHP - p->player->hp;
  } else {
    // TYPE_TOWER
    s32 lv;
    if (p->player->kind == PLAYER_SABATA) {
      lv = gStat->lv + 10;
      if (lv > 99) lv = 99;
    } else {
      lv = gStat->lv;
    }

    ignoreMask = 0;
    power = lv * 8;
  }

  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, ignoreMask, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, 10, 0, HBATTR_NAMAKURA, 30);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->player->mover.pos, 0);
#else
  INCFUNC("asm/func/FUN_080aaaa8.inc");
#endif
}

// プレイヤーの頭上に画面座標を作り、アイコンと棘鉄球と全画面判定を用意する
s32 Entity080aace8_Init(Entity080aace8* p, Player* player, u32 kind) {
  WorldPos pos;

  p->player = player;
  p->kind = kind;
  pos = p->player->mover.pos;
  pos.y += 0x96;
  WorldToScreen(&p->screen, &pos);

  FUN_080aa940(p);
  FUN_080aaa2c(p);
  FUN_080aaaa8(p);
  if (p->player->useAuxSprite == 0) {
    p->player->human.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->player->beast.flags &= ~SPRFLAG_HIDDEN;
  }

  p->player->hurtbox.iframes = 0;
  gGameFlags |= GAMEFLAG_NO_PAUSE;
  SET_FLAGS(gSuspendFlags, SUSPEND_MENU);
  if (p->kind == TYPE_JUSTICE) {
    FUN_080aa9d0(p);
  }

  p->updateCallback = FUN_080aa834;
  p->unk_34a = 0;
  return 0;
}

Entity080aace8* Entity080aace8_Create(Player* player, u32 kind) {
  Entity080aace8* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity080aace8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080aace8_Update, Entity080aace8_Destroy);
    if (Entity080aace8_Init(p, player, kind) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
