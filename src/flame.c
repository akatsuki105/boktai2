#include "entity.h"
#include "file.h"
#include "flamethrower.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_aux.h"

// 噴出火炎口 (flamethrower.c) が出す炎を最大4個、ビットマスクで管理するシングルトン, 使い手は噴出火炎口だけ
typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  MainSpriteGfx gfx;              // 0x018, SPR_FLAMETHROWER
  MainSpriteGfxFile* spriteFile;  // 0x038, SPR_FLAMETHROWER
  Flame items[4];                 // 0x03C, _Init と _Destroy が 0x13C 刻みで4個走査する
  u32 activeMask;                 // 0x52C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} FlameManager;
static_assert(sizeof(FlameManager) == 1328);

static FlameManager* gFlameManager;  // 0x030001C0

static inline bool8 FlameManager_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

const u8 u8_ARRAY_085ae478[19] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};  // 0x085AE478

void FUN_081ea878(Flame* p) {}

// 火炎のアニメを段階ごとに進め, 消え終わったらスロットを空けて TRUE を返す
bool8 FUN_081ea87c(Flame* item) {
  FlameManager* mgr = gFlameManager;

  if (item->sprite.animEvents & 1) {
    s32 anim;

    if (item->unk_128 == -1 && item->unk_12e > (s16)item->unk_134) {
      MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[18], PLAYMODE_ONCE_AND_STOP, 0);
      return FALSE;
    }

    if (item->unk_128 == 0 && !(gGameFlags & GAMEFLAG_LINK)) {
      PlaySound_082406e0(SE_FLAMETHROWER_424);
    }
    if (item->unk_128 == 1 && item->unk_130 > 0) {
      MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[item->unk_12a + item->unk_128], PLAYMODE_ONCE_AND_STOP, 0);
      return FALSE;
    }
    item->unk_128 += item->unk_12c;
    anim = item->unk_12a + item->unk_128;
    if (item->unk_128 == 3) {
      CLEAR_BIT(mgr->activeMask, (s16)item->unk_136);
      MainSprite_Remove(&item->sprite);
      if (item->flags & 1) {
        FUN_08002a58(&item->unk_60);
      }
      Mover_Unlink(&item->unk_60);
      item->unk_136 = 0xFFFF;
      item->unk_132 = 2;
      return TRUE;
    }
    MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[anim], PLAYMODE_ONCE_AND_STOP, 0);
  } else {
    MainSprite_AdvanceAnim(&item->sprite, &mgr->gfx);
  }

  if (item->unk_128 == 1) {
    item->unk_130--;
  }
  return FALSE;
}

void FUN_081eaa10(Flame* item) {
  if (!FUN_081ea87c(item)) {
    if (item->unk_128 == 1) {
      Hitbox_SetPos(&item->hitbox, &item->hitboxPos, 0);
      Hitbox_Register(&item->hitbox);
    }
    item->unk_134++;
  }
}

void FUN_081eaa54(Flame* p) {}

// 使用中のスロットのスプライトと Mover を片付けてシングルトンを手放す
s32 FlameManager_Destroy(FlameManager* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (FlameManager_IsActive(&p->activeMask, i)) {
      MainSprite_Remove(&p->items[i].sprite);
      if (p->items[i].flags & 1) {
        FUN_08002a58(&p->items[i].unk_60);
      }
      Mover_Unlink(&p->items[i].unk_60);
    }
  }

  gFlameManager = NULL;
  return 0;
}

s32 FlameManager_Update(FlameManager* p) {
  static void (*const PTR_ARRAY_085ae48c[3])(Flame*) = {
      FUN_081ea878,
      FUN_081eaa10,
      FUN_081eaa54,
  };  // 0x085AE48C

  Flame* items = p->items;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return 0;
  }

  for (i = 0; i < 4; i++) {
    if (FlameManager_IsActive(&p->activeMask, i)) {
      Flame* item = &items[i];

      PTR_ARRAY_085ae48c[item->unk_132](item);
    }
  }

  return 0;
}

// 空いているスロットを1つ確保して返す, 空きがなければ NULL
Flame* FUN_081eab78(FlameManager* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!FlameManager_IsActive(&p->activeMask, i)) {
      Flame* item = &p->items[i];

      p->activeMask |= 1 << i;
      item->unk_136 = i;
      return item;
    }
  }

  return NULL;
}

void FUN_081eabcc(Hitbox* a, Hitbox* b, void* p) {}

const Vec3 vec3_ARRAY_085ae498[3] = {
    {Q8(0.19), Q8(0.125), Q8(0.86)},
    {Q8(0.19), Q8(0.125), Q8(1.08)},
    {Q8(0.19), Q8(0.125), Q8(1.50)}
};  // 0x085AE498

// 火炎の当たり判定を作る, a が 0 なら vec3_ARRAY_085ae498[b] をそのまま, それ以外は x と z を入れ替えて半サイズにする
// 残差は a != 0 側の halfSize の x/y を原典は1語にまとめて書くのに, こちらは2回の読み書きになること (116/111命令)
NON_MATCH void FUN_081eabd0(Flame* item, s32 a, s32 b, s32 power, s32 knockback, s32 iframes) {
#ifdef NONMATCHING_C
  Vec3 halfSize;
  Vec3 offset;
  u8 angle;
  const Vec3* v;

  if (a == 0) {
    switch (b) {
      case 0: {
        v = &vec3_ARRAY_085ae498[0];
        halfSize = *v;
        break;
      }
      case 1: {
        v = &vec3_ARRAY_085ae498[1];
        halfSize = *v;
        break;
      }
      case 2: {
        v = &vec3_ARRAY_085ae498[2];
        halfSize = *v;
        break;
      }
    }
    offset.x = 0, offset.y = 0, offset.z = halfSize.z;
    angle = 0x40;
  } else {
    switch (b) {
      case 0: {
        v = &vec3_ARRAY_085ae498[0];
        halfSize.x = v->z, halfSize.y = v->y, halfSize.z = v->x;
        break;
      }
      case 1: {
        v = &vec3_ARRAY_085ae498[1];
        halfSize.x = v->z, halfSize.y = v->y, halfSize.z = v->x;
        break;
      }
      case 2: {
        v = &vec3_ARRAY_085ae498[2];
        halfSize.x = v->z, halfSize.y = v->y, halfSize.z = v->x;
        break;
      }
    }
    offset.x = halfSize.x, offset.y = 0, offset.z = 0;
    angle = 0;
  }

  Hitbox_Init(&item->hitbox, 0, HBF_HITBOX | HBF_ANGLE | HBF_DAMAGE, 0, HIM_5, &halfSize, &offset);
  Hitbox_SetAttack(&item->hitbox, power, knockback, HBSRC_NON_WEAPON, HBATTR_INKA | HBATTR_FLAME, iframes);
  Hitbox_SetPos(&item->hitbox, &item->hitboxPos, 0);
  Hitbox_SetHandler(&item->hitbox, FUN_081eabcc, item);
  item->hitbox.angle = angle;
#else
  INCFUNC("asm/func/FUN_081eabd0.inc");
#endif
}

// 火炎のスプライトを登録してアニメを始める
void FUN_081eace8(Flame* item, s32 a, s32 b, s32 c) {
  FlameManager* mgr = gFlameManager;

  item->unk_12a = b * 3 + a * 9;
  item->unk_128 = c;
  item->unk_12c = 1;
  MainSprite_Add(&item->sprite, &mgr->gfx, 13, 0, 1, PLAYMODE_ONCE_AND_STOP, 120, &item->hitboxPos);
  MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[18], PLAYMODE_ONCE_AND_STOP, 0);
}

// 空きスロットに火炎を1つ出す, flags の bit0 が立っていれば Mover を伸びる向きへずらして登録する
// 残差は各 case で v の定数ロードが pos の読み込みより先に出る順序だけ (176/176命令)
NON_MATCH Flame* Flame_Spawn(Vec3* pos, u32 id, s32 unk_12e, s32 a, s32 b, s32 c, s32 power, s32 knockback, s32 iframes, s32 unk_130, u32 flags) {
#ifdef NONMATCHING_C
  Flame* item;
  Mover* mover;
  const Vec3* v;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return NULL;
  }
  if (gFlameManager == NULL) {
    return NULL;
  }
  item = FUN_081eab78(gFlameManager);
  if (item == NULL) {
    return NULL;
  }

  item->hitboxPos = *pos;
  item->unk_12e = unk_12e;
  item->unk_134 = 0;
  item->unk_130 = unk_130;
  item->unk_132 = 1;
  mover = &item->unk_60;
  Mover_Init(mover, id, &item->hitboxPos, 0, MOVER_OBJECT, item);
  Mover_SetAuxSprite(mover, &item->unk_a4);
  item->unk_a4.flags &= ~SPRFLAG_HIDDEN;
  item->flags = flags;
  if (flags & 1) {
    if (a == 0) {
      switch (b) {
        case 0: {
          v = &vec3_ARRAY_085ae498[0];
          mover->pos.z += v->z + 32;
          break;
        }
        case 1: {
          v = &vec3_ARRAY_085ae498[1];
          mover->pos.z += v->z + 100;
          break;
        }
        case 2: {
          v = &vec3_ARRAY_085ae498[2];
          mover->pos.z += v->z + 200;
          break;
        }
      }
    } else {
      switch (b) {
        case 0: {
          v = &vec3_ARRAY_085ae498[0];
          mover->pos.x += v->z + 32;
          break;
        }
        case 1: {
          v = &vec3_ARRAY_085ae498[1];
          mover->pos.x += v->z + 100;
          break;
        }
        case 2: {
          v = &vec3_ARRAY_085ae498[2];
          mover->pos.x += v->z + 200;
          break;
        }
      }
    }
    FUN_08002a48(mover);
  }

  FUN_081eabd0(item, a, b, power, knockback, iframes);
  FUN_081eace8(item, a, b, c);
  return item;
#else
  INCFUNC("asm/func/Flame_Spawn.inc");
#endif
}

void FUN_081eaeec(FlameManager* p) {
  p->spriteFile = GetFile(DIR_MAIN_SPRITE, SPR_FLAMETHROWER);
  p->gfx = *(MainSpriteGfx*)p->spriteFile;
  OpenMainSpriteFile(&p->gfx, p->spriteFile);
}

s32 FlameManager_Init(FlameManager* p) {
  s32 i;

  gFlameManager = p;
  FUN_081eaeec(p);
  for (i = 0; i < 4; i++) {
    p->items[i].unk_136 |= 0xFFFF;
  }
  p->activeMask = 0;
  return 0;
}

void FlameManager_Create(void) {
  if (gFlameManager == NULL) {
    FlameManager* p = CreateEntity(ENTITY_UNK_10, sizeof(FlameManager));
    if (p != NULL) {
      SetEntityRoutine(p, FlameManager_Update, FlameManager_Destroy);
      if (FlameManager_Init(p) < 0) {
        KillEntity((Entity*)p);
      }
    }
  }
}

void FlameManager_ClearGlobal(void) { gFlameManager = NULL; }
