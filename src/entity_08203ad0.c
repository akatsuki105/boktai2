#include "animation.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

// 8個で使い回す当たり判定つきエフェクトの枠, FUN_0820372c が ttl == 0 かつ非表示のものを空きとして拾う
typedef struct {
  AuxSprite sprite;   // 0x00, AuxSprite_Add / AuxSprite_Remove に渡る
  AuxAnimState anim;  // 0x2C, AuxAnim_SetAnim の第1引数, _Update がコマを進める
  HitboxData hitbox;  // 0x3C, FUN_08203690 が Hitbox_Init / Hitbox_SetAttack に渡す
  Vec3 pos;           // 0x8C, Hitbox_SetPos の第2引数, FUN_08203770 が引数の Vec3 を写す
  u16 ttl;            // 0x94, 残りフレーム数, _Update が毎フレーム -1 して 0 で FUN_08203860 が解放する, 60未満でフェードに入る
  u8 unk_96[2];       // 0x96, padding?
} Entity08203ad0Slot;
static_assert(sizeof(Entity08203ad0Slot) == 152);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;             // 0x018, Video_GetAuxSprite / Video_SetAuxSpritePltt の第1引数
  u8 unk_34[4];                 // 0x034, 読み手も書き手も未発見
  u32 unk_38;                   // 0x038, _Init が 0 を入れるだけで読み手が見つからない
  u8 activeCount;               // 0x03C, 使用中の slots の数, FUN_0820372c が 8 未満か見て FUN_08203770 が +1 / FUN_08203860 が -1
  u8 unk_3d[3];                 // 0x03D, padding?
  Entity08203ad0Slot slots[8];  // 0x040, _Destroy / _Update / FUN_08203a0c が stride 0x98 で8個回す
} Entity08203ad0;
static_assert(sizeof(Entity08203ad0) == 1280);

IWRAM_DATA Entity08203ad0* gEntity08203ad0 = NULL;  // 0x0300021C

// 実体は src/code_08200ab4.s
void FUN_08203690(Entity08203ad0Slot* slot, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44);
bool8 FUN_082375c8(u32* flags, s32 t, s32 t1, s32 t2);

// 空いている枠を探す, ttl が 0 で非表示のものが空き
// 残差1命令: 原典は return slot のブロックをループの手前に置くので、ガードが bls + b の2段になる
NON_MATCH Entity08203ad0Slot* FUN_0820372c(void) {
#ifdef NONMATCHING_C
  Entity08203ad0* p = gEntity08203ad0;

  if (p->activeCount <= 7) {
    Entity08203ad0Slot* slot = p->slots;
    s32 i;

    for (i = 0; i < 8; slot++, i++) {
      if (slot->ttl == 0 && (slot->sprite.flags & SPRFLAG_HIDDEN)) {
        return slot;
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_0820372c.inc");
#endif
}

// 空き枠を1つ取ってエフェクトを出す, Y座標は足元のタイルの高さに合わせる
void FUN_08203770(Vec3* pos, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44, s32 ttl) {
  Entity08203ad0* p = gEntity08203ad0;
  Entity08203ad0Slot* slot = FUN_0820372c();

  if (slot != NULL) {
    Vec3* dst;
    s32 x, y, z;
    s32 bx, bz;
    s32 idx;
    u8* tile;

    p->activeCount++;
    slot->pos = *pos;

    x = pos->x, y = pos->y, z = pos->z;
    dst = &slot->sprite.pos;
    slot->sprite.pos.x = x - 0x80;
    dst->y = y;
    dst->z = z;

    bx = slot->sprite.pos.x >> 8;
    bz = z >> 8;
    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->rowOffsets[bz] + bx;
    }

    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }

    slot->sprite.pos.y = (*tile & 0xF) << 8;
    slot->ttl = ttl;
    slot->sprite.flags &= ~SPRFLAG_HIDDEN;
    FUN_08203690(slot, power, unk_40, attrs, unk_44);
  }
}

// 枠を解放する, ttl を 0 にしてスプライトを隠し、使用中の数を1つ減らす
void FUN_08203860(Entity08203ad0Slot* slot) {
  Entity08203ad0* p = gEntity08203ad0;

  if (slot != NULL) {
    p->activeCount--;
    slot->ttl = 0;
    slot->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 残差3命令: 原典は定数 1 をループ不変として高位レジスタに置くので、退避するレジスタが1本多い
// AuxAnimState* の局所ポインタで14命令ぶんまでは寄せた
NON_MATCH void Entity08203ad0_Update(Entity08203ad0* p) {
#ifdef NONMATCHING_C
  Entity08203ad0Slot* slot = p->slots;
  s32 i;

  for (i = 0; i < 8; slot++, i++) {
    if (slot->ttl != 0) {
      AuxAnimState* anim = &slot->anim;
      AuxAnimCmd* cmd = slot->anim.cmds + anim->cmdIdx;

      slot->sprite.metaspriteIdx = *cmd >> 6;
      if ((anim->flags & ANIM_PLAY_XFLIP) == ((*cmd & 0x30) >> 4 & ANIM_PLAY_XFLIP)) {
        slot->sprite.flags &= ~SPRFLAG_XFLIP;
      } else {
        slot->sprite.flags |= SPRFLAG_XFLIP;
      }
      if ((anim->flags & ANIM_PLAY_YFLIP) == ((*cmd & 0x30) >> 4 & ANIM_PLAY_YFLIP)) {
        slot->sprite.flags &= ~SPRFLAG_YFLIP;
      } else {
        slot->sprite.flags |= SPRFLAG_YFLIP;
      }

      anim->tick++;
      if (anim->wait <= anim->tick) {
        anim->tick = 0;
        if (!(anim->flags & ANIM_PLAY_REVERSE)) {
          anim->cmdIdx++;
          if (anim->cmdCount <= anim->cmdIdx) {
            anim->cmdIdx = 0;
          }
        } else {
          if (anim->cmdIdx == 0) {
            anim->cmdIdx = anim->cmdCount;
          }
          anim->cmdIdx--;
        }
        anim->duration = anim->cmds[anim->cmdIdx] & 0xF;
        anim->wait = (anim->duration * anim->speed) >> 6;
        if (anim->wait == 0) {
          anim->wait = 1;
        }
      }

      Hitbox_SetPos(&slot->hitbox, &slot->pos, 0);
      Hitbox_Register(&slot->hitbox);
      if (slot->ttl < 60) {
        FUN_082375c8(&slot->sprite.flags, 60 - slot->ttl, 20, 30);
      }
      slot->ttl--;
      if (slot->ttl == 0) {
        FUN_08203860(slot);
      }
    }
  }
#else
  INCFUNC("asm/func/Entity08203ad0_Update.inc");
#endif
}

s32 Entity08203ad0_Destroy(Entity08203ad0* p) {
  Entity08203ad0Slot* slot = p->slots;
  s32 i;

  for (i = 0; i < 8; slot++, i++) {
    if (slot->sprite.active) {
      AuxSprite_Remove(&slot->sprite);
    }
  }
  gEntity08203ad0 = NULL;
  return 0;
}

// 8つの枠を全部作り直す, スプライトとアニメを割り当ててヒットボックスを初期化し、全部空きにする
s32 FUN_08203a0c(Entity08203ad0* p) {
  AuxAnimFile* files;
  Entity08203ad0Slot* slot;
  s32 i;

  Video_GetAuxSprite(&p->gfx, 0xA5B3);
  Video_SetAuxSpritePltt(&p->gfx, 0x236);
  files = GetFile(DIR_ANIMATION, 0x1752);

  slot = p->slots;
  for (i = 0; i < 8; slot++, i++) {
    AuxSprite_Add(&slot->sprite, &p->gfx, 0);
    AuxAnim_SetAnim(&slot->anim, files, 1, 0, 0);
    slot->sprite.flags |= SPRFLAG_HIDDEN;
    FUN_08203690(slot, 0, 0, 0, 0);
    slot->ttl = 0;
  }
  return 0;
}

s32 Entity08203ad0_Init(Entity08203ad0* p) {
  p->activeCount = 0;
  p->unk_38 = 0;
  Video_GetAuxSprite(&p->gfx, 0xA5B3);
  if (FUN_08203a0c(p) < 0) {
    return -1;
  } else {
    return 0;
  }
}

Entity08203ad0* Entity08203ad0_Create(void) {
  Entity08203ad0* p;

  if (gEntity08203ad0 != NULL) {
    return gEntity08203ad0;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08203ad0));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08203ad0_Update, Entity08203ad0_Destroy);
    if (Entity08203ad0_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// エフェクトを出す入口, エンティティがまだなければ先に作る
s32 FUN_08203b1c(Vec3* pos, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44, s32 ttl) {
  if (gEntity08203ad0 == NULL) {
    gEntity08203ad0 = Entity08203ad0_Create();
  }
  FUN_08203770(pos, power, unk_40, attrs, unk_44, ttl);
}
