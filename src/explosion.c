#include "entity.h"
#include "global.h"
#include "constants/sprite.h"
#include "sprite.h"

// 爆発 1 個。飛びながら 24 フレームで消える
typedef struct {
  bool8 active;      // 0x00, ExplosionManager_Spawn が空きスロットに 1 を立て、_Update が timer > 24 で 0 に戻す
  u8 flags;          // 0x01, Spawn の第2引数の下位バイト。bit0 で sprite.flags の BLINK_ODD、bit1 で SCREEN_COORD が決まる
  u16 timer;         // 0x02, 毎フレーム +1。sprite.metaspriteIdx = timer >> 2
  u16 dampFrom;      // 0x04, timer がこの値以上になったら vel を減衰させる。Spawn の第5引数
  u16 damping;       // 0x06, vel = vel * damping >> 8 (0 方向に丸める)。Spawn の第6引数
  Vec3 vel;          // 0x08, Spawn が第4引数を 2 ワードでコピーする。_Update が sprite.pos に足す
  AuxSpriteGfx gfx;  // 0x10, _Init が Video_GetAuxSprite(&gfx, EFF_EXPLOSION) で読み込む
  AuxSprite sprite;  // 0x2C, _Init が AuxSprite_Setup(&sprite, &gfx, 0)
} Explosion;
static_assert(sizeof(Explosion) == 88);

// 爆発を最大16個まとめて動かすシングルトン
typedef struct ExplosionManager {
  Entity e;             // 0x00, ENTITY_UNK_10
  Explosion items[16];  // 0x18, _Init / _Update / _Destroy が 16 回まわす
} ExplosionManager;
static_assert(sizeof(ExplosionManager) == 1432);

extern ExplosionManager* gExplosionManager;  // 0x03000138

void ExplosionManager_ClearGlobal(void) { gExplosionManager = NULL; }

NAKED s32 ExplosionManager_Update(ExplosionManager* p) { INCFUNC("asm/func/ExplosionManager_Update.inc"); }

s32 ExplosionManager_Destroy(ExplosionManager* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    Explosion* e = &p->items[i];
    if (e->active) {
      AuxSprite_Remove(&e->sprite);
    }
  }
  gExplosionManager = NULL;
  return 0;
}

s32 ExplosionManager_Init(ExplosionManager* p, void* _) {
  Vec3 pos;
  s32 i;

  gExplosionManager = p;
  pos.x = 0, pos.y = 0, pos.z = 0;
  for (i = 0; i < 16; i++) {
    Explosion* e = &p->items[i];

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

ExplosionManager* ExplosionManager_Create(void* _) {
  ExplosionManager* p = CreateEntity(ENTITY_UNK_10, sizeof(ExplosionManager));

  if (p != NULL) {
    SetEntityRoutine(p, ExplosionManager_Update, ExplosionManager_Destroy);
    if (ExplosionManager_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 ExplosionManager_Spawn(s32 plttID, u32 flags, Vec3* pos, Vec3* vel, u16 dampFrom, u16 damping) { INCFUNC("asm/func/ExplosionManager_Spawn.inc"); }

NAKED s32 ExplosionManager_SpawnFromScript(void) { INCFUNC("asm/func/ExplosionManager_SpawnFromScript.inc"); }
