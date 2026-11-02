#include "entity.h"
#include "global.h"
#include "sprite.h"

// ミニゲーム"ブラックパンサー"用の爆弾

// 爆発 1 個, 飛びながら 24 フレームで消える
typedef struct {
  bool8 active;      // 0x00, MinigameExplosionManager_Spawn が空きスロットに 1 を立て、_Update が timer > 24 で 0 に戻す
  u8 flags;          // 0x01, Spawn の第2引数の下位バイト, bit0 で sprite.flags の BLINK_ODD、bit1 で SCREEN_COORD が決まる
  u16 timer;         // 0x02, 毎フレーム +1, sprite.poseIdx = timer >> 2
  u16 dampFrom;      // 0x04, timer がこの値以上になったら vel を減衰させる, Spawn の第5引数
  u16 damping;       // 0x06, vel = vel * damping >> 8 (0 方向に丸める), Spawn の第6引数
  Vec3 vel;          // 0x08, Spawn が第4引数を 2 ワードでコピーする, _Update が sprite.pos に足す
  AuxSpriteGfx gfx;  // 0x10, SPRITE_EXPLOSION
  AuxSprite sprite;  // 0x2C
} MinigameExplosion;
static_assert(sizeof(MinigameExplosion) == 88);

// 爆発を最大16個まとめて動かすシングルトン
typedef struct {
  Entity e;                     // 0x00, ENTITY_UNK_10
  MinigameExplosion items[16];  // 0x18, _Init / _Update / _Destroy が 16 回まわす
} MinigameExplosionManager;
static_assert(sizeof(MinigameExplosionManager) == 1432);

IWRAM_DATA MinigameExplosionManager* gMinigameExplosionManager = NULL;  // 0x03000138

void MinigameExplosionManager_ClearGlobal(void) { gMinigameExplosionManager = NULL; }

NAKED s32 MinigameExplosionManager_Update(MinigameExplosionManager* p) { INCFUNC("asm/func/MinigameExplosionManager_Update.inc"); }

s32 MinigameExplosionManager_Destroy(MinigameExplosionManager* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    MinigameExplosion* e = &p->items[i];
    if (e->active) {
      AuxSprite_Remove(&e->sprite);
    }
  }
  gMinigameExplosionManager = NULL;
  return 0;
}

s32 MinigameExplosionManager_Init(MinigameExplosionManager* p, void* _) {
  Vec3 pos;
  s32 i;

  gMinigameExplosionManager = p;
  VEC3_SET(pos, 0, 0, 0);
  for (i = 0; i < 16; i++) {
    MinigameExplosion* e = &p->items[i];

    e->active = FALSE;
    if (!Video_GetAuxSprite(&e->gfx, SPRITE_EXPLOSION)) {
      return -1;
    }
    AuxSprite_Setup(&e->sprite, &e->gfx, 0);
    e->sprite.priority = 1;
    e->sprite.pos = pos;
  }
  return 0;
}

MinigameExplosionManager* MinigameExplosionManager_Create(void* _) {
  MinigameExplosionManager* p = CreateEntity(ENTITY_UNK_10, sizeof(MinigameExplosionManager));

  if (p != NULL) {
    SetEntityRoutine(p, MinigameExplosionManager_Update, MinigameExplosionManager_Destroy);
    if (MinigameExplosionManager_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 MinigameExplosionManager_Spawn(s32 plttID, u32 flags, Vec3* pos, Vec3* vel, u16 dampFrom, u16 damping) { INCFUNC("asm/func/MinigameExplosionManager_Spawn.inc"); }

// 明らかに vm_commands.s に登録される Cmd の形だが、使われていない
NAKED s32 MinigameExplosionManager_SpawnFromScript(void) { INCFUNC("asm/func/MinigameExplosionManager_SpawnFromScript.inc"); }
