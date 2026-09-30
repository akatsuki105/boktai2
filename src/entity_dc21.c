#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Entity e;                    // 0x000, ENTITY_UNK_8
  AuxSprite sprite;            // 0x018, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx solarStandGfx;  // 0x044, SPRITE_SOLAR_STATION
  MainSpriteGfx mainGfx;       // 0x060, SPRITE_UI_START_MENU
  MainSprite mainSprites[4];   // 0x080, _Destroy が MainSprite_Remove に渡す4枚
  HitboxData hitbox;           // 0x200, _Destroy が Hitbox_Unregister に渡す
  Vec3 unk_250;                // 0x250, FUN_0809f4b0 が sprite.pos を写して補正する
  Player* player;              // 0x258, _Init が gPlayerPtr[0] を入れる, NULL なら _Init が失敗する
  u16 id;                      // 0x25C, _Create / _Init の第2引数, Hitbox_Init の第2引数にもなる
  u8 unk_25e;                  // 0x25E, _Init が 0 を入れる
  u8 unk_25f;                  // 0x25F, _Init が 0 を入れる
  u8 unk_260;                  // 0x260, _Init が 0 を入れる
  bool8 unk_261;               // 0x261, _Init が 0 を入れる, FUN_0809f30c がスクリプトのレコードから立て直す
  u16 unk_262;                 // 0x262, _Init が sprite.flags bit2 のとき 7、そうでなければ 1 を入れる
} EntityDC21;
static_assert(sizeof(EntityDC21) == 612);

NAKED void FUN_0809ef38(EntityDC21* p) { INCFUNC("asm/func/FUN_0809ef38.inc"); }

NAKED void FUN_0809f034(EntityDC21* p) { INCFUNC("asm/func/FUN_0809f034.inc"); }

NAKED void FUN_0809f0bc(EntityDC21* p) { INCFUNC("asm/func/FUN_0809f0bc.inc"); }

NAKED void FUN_0809f17c(EntityDC21* p) { INCFUNC("asm/func/FUN_0809f17c.inc"); }

// 自分の id で登録されたスクリプトのレコードを全部見て、unk_261 を最後の指示どおりに設定する
void FUN_0809f30c(EntityDC21* p) {
  ScriptRecord* rec;
  s32 n = FUN_08230f94(p->id, &rec);

  while (n-- > 0) {
    switch (rec->values[0]) {
      case 0: {
        p->unk_261 = TRUE;
        break;
      }
      case 1: {
        p->unk_261 = FALSE;
        break;
      }
    }
    rec++;
  }
}

s32 EntityDC21_Update(EntityDC21* p) {
  FUN_0809f30c(p);

  switch (p->unk_25e) {
    case 0: {
      FUN_0809ef38(p);
      break;
    }
    case 1: {
      FUN_0809f034(p);
      break;
    }
  }

  FUN_0809f0bc(p);
  FUN_0809f17c(p);
  return 0;
}

s32 EntityDC21_Destroy(EntityDC21* p) {
  MainSprite* spr;
  s32 i;

  AuxSprite_Remove(&p->sprite);
  spr = p->mainSprites;
  for (i = 0; i < 4; spr++, i++) {
    MainSprite_Remove(spr);
  }
  Hitbox_Unregister(&p->hitbox);
  return 0;
}

// 太陽スタンドの絵を用意し、 '.p' で座標、'.f' で左右反転を決める
void EntityDC21_InitSprite(EntityDC21* p) {
  AuxSprite* sprite = &p->sprite;
  AuxSpriteGfx* gfx = &p->solarStandGfx;
  SpriteFlags flags;

  Video_GetAuxSprite(gfx, SPRITE_SOLAR_STATION);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->metaspriteIdx = 0;

  if (VM_SeekToKeyword('p')) {
    sprite->pos.x = VM_GetValue();
    sprite->pos.y = VM_GetValue();
    sprite->pos.z = VM_GetValue();
  } else {
    sprite->pos.x = 0, sprite->pos.y = 0, sprite->pos.z = 0;
  }

  flags = VM_SeekToKeyword('f');
  if (flags) {
    flags = VM_GetValue();
    if (flags) {
      flags = SPRFLAG_XFLIP;
    }
  }
  sprite->flags = flags;
}

NAKED void EntityDC21_InitMainSprites(EntityDC21* p) { INCFUNC("asm/func/EntityDC21_InitMainSprites.inc"); }

// ヒットボックスの基準点を sprite の座標から作る, 左右反転の向きに合わせて1タイルぶんずらす
void FUN_0809f4b0(EntityDC21* p) {
  p->unk_250 = p->sprite.pos;
  if (p->sprite.flags & SPRFLAG_XFLIP) {
    p->unk_250.x += 0x100;
  } else {
    p->unk_250.z += 0x100;
  }
}

NAKED s32 EntityDC21_InitHitbox(EntityDC21* p) { INCFUNC("asm/func/EntityDC21_InitHitbox.inc"); }

NAKED s32 EntityDC21_Init(EntityDC21* p, u32 id, u32 param_3) { INCFUNC("asm/func/EntityDC21_Init.inc"); }

EntityDC21* EntityDC21_Create(u32 id, u32 param_2) {
  EntityDC21* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityDC21));
  if (p != NULL) {
    SetEntityRoutine(p, EntityDC21_Update, EntityDC21_Destroy);
    if (EntityDC21_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
