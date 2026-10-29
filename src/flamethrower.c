#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_aux.h"

typedef struct Entity081eaf6cItem {
  MainSprite sprite;  // 0x000, Entity081eaf6c_Destroy が要素そのものを MainSprite_Remove に渡す
  Mover unk_60;       // 0x060, flags の bit0 が立っていれば _Destroy が FUN_08002a58 に、その後 Mover_Unlink に渡す
  AuxSprite unk_a4;   // 0x0A4, unk_60 に Mover_SetAuxSprite で繋ぐ
  Vec3 hitboxPos;     // 0x0D0, Hitbox_SetPos に渡す位置
  HitboxData hitbox;  // 0x0D8, FUN_081eaa10 が unk_128 が 1 のときだけ登録する
  s16 unk_128;        // 0x128, 1 のときだけヒットボックスを登録する
  s16 unk_12a;        // 0x12A
  s16 unk_12c;        // 0x12C
  s16 unk_12e;        // 0x12E
  s16 unk_130;        // 0x130
  s16 unk_132;        // 0x132, _Update が s16 として読む
  u16 unk_134;        // 0x134, FUN_081eaa10 が毎フレーム +1 する
  u16 unk_136;        // 0x136, _Init が全要素に 0xFFFF を入れる
  u16 flags;          // 0x138, bit0 が立っていると _Destroy が FUN_08002a58 を呼ぶ
  u8 unk_13a[2];      // 0x13A, padding?
} Entity081eaf6cItem;
static_assert(sizeof(Entity081eaf6cItem) == 316);

// 火炎放射のスプライトを最大4個、ビットマスクで管理するシングルトン
// ゲーム中に火炎放射のギミックが登場するところは色々あるが、これが 汎用の火炎放射管理構造体 なのか 特定のギミック専用のもの なのかはまだ不明
typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  MainSpriteGfx gfx;              // 0x018, SPRITE_FLAMETHROWER
  MainSpriteGfxFile* spriteFile;  // 0x038, SPRITE_FLAMETHROWER
  Entity081eaf6cItem items[4];    // 0x03C, _Init と _Destroy が 0x13C 刻みで4個走査する
  u32 activeMask;                 // 0x52C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081eaf6c;
static_assert(sizeof(Entity081eaf6c) == 1328);

static inline bool8 Entity081eaf6c_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

static Entity081eaf6c* gEntity081eaf6c;  // 0x030001C0

const u8 u8_ARRAY_085ae478[18] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // 0x085AE478

void FUN_081ea878(Entity081eaf6cItem* p) {}

// 火炎のアニメを段階ごとに進め, 消え終わったらスロットを空けて TRUE を返す
bool8 FUN_081ea87c(Entity081eaf6cItem* item) {
  Entity081eaf6c* mgr = gEntity081eaf6c;

  if (item->sprite.animEvents & 1) {
    s32 anim;

    if (item->unk_128 == -1 && item->unk_12e > (s16)item->unk_134) {
      MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[18], PLAYMODE_ONCE_AND_STOP, 0);
      return FALSE;
    }

    if (item->unk_128 == 0 && !(gGameFlags & FLAG030047A4_LINK)) {
      PlaySound_082406e0(SONG_424);
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

void FUN_081eaa10(Entity081eaf6cItem* item) {
  if (!FUN_081ea87c(item)) {
    if (item->unk_128 == 1) {
      Hitbox_SetPos(&item->hitbox, &item->hitboxPos, 0);
      Hitbox_Register(&item->hitbox);
    }
    item->unk_134++;
  }
}

void FUN_081eaa54(Entity081eaf6cItem* p) {}

// 使用中のスロットのスプライトと Mover を片付けてシングルトンを手放す
s32 Entity081eaf6c_Destroy(Entity081eaf6c* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (Entity081eaf6c_IsActive(&p->activeMask, i)) {
      MainSprite_Remove(&p->items[i].sprite);
      if (p->items[i].flags & 1) {
        FUN_08002a58(&p->items[i].unk_60);
      }
      Mover_Unlink(&p->items[i].unk_60);
    }
  }

  gEntity081eaf6c = NULL;
  return 0;
}

void (*const PTR_ARRAY_085ae48c[3])(Entity081eaf6cItem*) = {
    FUN_081ea878,
    FUN_081eaa10,
    FUN_081eaa54,
};  // 0x085AE48C

// 使用中のスロットごとに unk_132 の状態ハンドラを呼ぶ
s32 Entity081eaf6c_Update(Entity081eaf6c* p) {
  Entity081eaf6cItem* items = p->items;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return 0;
  }

  for (i = 0; i < 4; i++) {
    if (Entity081eaf6c_IsActive(&p->activeMask, i)) {
      Entity081eaf6cItem* item = &items[i];

      PTR_ARRAY_085ae48c[item->unk_132](item);
    }
  }

  return 0;
}

// 空いているスロットを1つ確保して返す, 空きがなければ NULL
Entity081eaf6cItem* FUN_081eab78(Entity081eaf6c* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!Entity081eaf6c_IsActive(&p->activeMask, i)) {
      Entity081eaf6cItem* item = &p->items[i];

      p->activeMask |= 1 << i;
      item->unk_136 = i;
      return item;
    }
  }

  return NULL;
}

void FUN_081eabcc(HitboxData* a, HitboxData* b, void* p) {}

const Vec3 vec3_ARRAY_085ae498[3] = {
    {48, 32, 220},
    {48, 32, 276},
    {48, 32, 384}
};  // 0x085AE498

// 火炎の当たり判定を作る, a が 0 なら vec3_ARRAY_085ae498[b] をそのまま, それ以外は x と z を入れ替えて半サイズにする
// 残差は a != 0 側の halfSize の x/y を原典は1語にまとめて書くのに, こちらは2回の読み書きになること (116/111命令)
NON_MATCH void FUN_081eabd0(Entity081eaf6cItem* item, s32 a, s32 b, s32 power, s32 knockback, s32 invincibleTime) {
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

  Hitbox_Init(&item->hitbox, 0, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 32, &halfSize, &offset);
  Hitbox_SetAttack(&item->hitbox, power, knockback, HBATTR_ALL, HBATTR_INKA | HBATTR_FLAME, invincibleTime);
  Hitbox_SetPos(&item->hitbox, &item->hitboxPos, 0);
  Hitbox_SetHandler(&item->hitbox, FUN_081eabcc, item);
  item->hitbox.angle = angle;
#else
  INCFUNC("asm/func/FUN_081eabd0.inc");
#endif
}

// 火炎のスプライトを登録してアニメを始める
void FUN_081eace8(Entity081eaf6cItem* item, s32 a, s32 b, s32 c) {
  Entity081eaf6c* mgr = gEntity081eaf6c;

  item->unk_12a = b * 3 + a * 9;
  item->unk_128 = c;
  item->unk_12c = 1;
  MainSprite_Add(&item->sprite, &mgr->gfx, 13, 0, 1, PLAYMODE_ONCE_AND_STOP, 120, &item->hitboxPos);
  MainSprite_SetAnim(&item->sprite, &mgr->gfx, u8_ARRAY_085ae478[18], PLAYMODE_ONCE_AND_STOP, 0);
}

// 空きスロットに火炎を1つ出す, flags の bit0 が立っていれば Mover を伸びる向きへずらして登録する
// 残差は各 case で v の定数ロードが pos の読み込みより先に出る順序だけ (176/176命令)
NON_MATCH Entity081eaf6cItem* FUN_081ead54(Vec3* pos, u32 id, s32 unk_12e, s32 a, s32 b, s32 c, s32 power, s32 knockback, s32 invincibleTime, s32 unk_130, u32 flags) {
#ifdef NONMATCHING_C
  Entity081eaf6cItem* item;
  Mover* mover;
  const Vec3* v;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return NULL;
  }
  if (gEntity081eaf6c == NULL) {
    return NULL;
  }
  item = FUN_081eab78(gEntity081eaf6c);
  if (item == NULL) {
    return NULL;
  }

  item->hitboxPos = *pos;
  item->unk_12e = unk_12e;
  item->unk_134 = 0;
  item->unk_130 = unk_130;
  item->unk_132 = 1;
  mover = &item->unk_60;
  Mover_Init(mover, id, &item->hitboxPos, 0, 7, item);
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

  FUN_081eabd0(item, a, b, power, knockback, invincibleTime);
  FUN_081eace8(item, a, b, c);
  return item;
#else
  INCFUNC("asm/func/FUN_081ead54.inc");
#endif
}

void FUN_081eaeec(Entity081eaf6c* p) {
  p->spriteFile = GetFile(DIR_MAIN_SPRITE, SPRITE_FLAMETHROWER);
  p->gfx = *(MainSpriteGfx*)p->spriteFile;
  OpenMainSpriteFile(&p->gfx, p->spriteFile);
}

s32 Entity081eaf6c_Init(Entity081eaf6c* p) {
  s32 i;

  gEntity081eaf6c = p;
  FUN_081eaeec(p);
  for (i = 0; i < 4; i++) {
    p->items[i].unk_136 |= 0xFFFF;
  }
  p->activeMask = 0;
  return 0;
}

void Entity081eaf6c_Create(void) {
  if (gEntity081eaf6c == NULL) {
    Entity081eaf6c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081eaf6c));
    if (p != NULL) {
      SetEntityRoutine(p, Entity081eaf6c_Update, Entity081eaf6c_Destroy);
      if (Entity081eaf6c_Init(p) < 0) {
        KillEntity((Entity*)p);
      }
    }
  }
}

void FUN_081eafb0(void) { gEntity081eaf6c = NULL; }
