#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite.h"
#include "sprite_aux.h"
#include "vm.h"

// 足場1枚ぶん
typedef struct Entity1E98Elem {
  AuxSprite spr;                                   // 0x000
  AuxSpriteGfx gfx;                                // 0x02C, unk_e4 が 0 なら SPRITE_C3C3, それ以外は SPRITE_D166
  HitboxData hitbox;                               // 0x048
  Mover mover;                                     // 0x098, moverLinked が 0 以外のときだけ繋がれる
  Vec3 pos;                                        // 0x0DC, '.p', spr.pos へ複写され hitbox の座標にもなる
  s8 unk_e4;                                       // 0x0E4, '.t'
  bool8 moverLinked;                               // 0x0E5, '.h'
  s16 hitboxArg;                                   // 0x0E6, '.n', Hitbox_Init の第2引数
  s16 scriptID;                                    // 0x0E8, '.g[0]=-1', スクリプトが '.i' でこの足場を指名する
  s16 tileIdx;                                     // 0x0EA, pos が乗っているコリジョンタイルの索引
  u16 timer;                                       // 0x0EC, updateCallback が差し替わるたび 0 に戻る
  s16 unk_ee;                                      // 0x0EE, '.W'
  u8 unk_f0;                                       // 0x0F0, まだ未解析
  u8 unk_f1;                                       // 0x0F1, まだ未解析
  s16 unk_f2;                                      // 0x0F2, '.A=10'
  u8 plttTimer;                                    // 0x0F4, 0 でない間 gfx が pltt を使い, 0 になった瞬間に plttID 0x5F へ戻る
  u8 unk_f5;                                       // 0x0F5, まだ未解析
  u8 unk_f6;                                       // 0x0F6, '.s'
  bool8 tileOverrideAdded;                         // 0x0F7, 0 以外なら ov が登録済み
  MapTileOverride ov;                              // 0x0F8
  void (*updateCallback)(struct Entity1E98Elem*);  // 0x108
  u32 unk_10c;                                     // 0x10C, '.g[1]'
} Entity1E98Elem;
static_assert(sizeof(Entity1E98Elem) == 272);

// 魔法"ヒーリング" で足場にすることができる ハスの葉(SPRITE_LILYPAD) or 太陽の根(SPRITE_SOLAR_PLANT)
// 他の Entity と _Create, _Init, _Update, _Delete の書き方やシグネチャが異なる
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_8
  u8 count;                 // 0x018, 生えている足場の数, _Init が1枚生やすごとに1増やす
  u8 unk_19[3];             // 0x019, まだ未解析
  rgb555 pltt[16];          // 0x01C, plttTimer が動いている間 gfx.pltt がここを指す (plttID 0x60)
  Entity1E98Elem elems[8];  // 0x03C
} Entity1E98;
static_assert(sizeof(Entity1E98) == 2236);

COMMON_DATA Entity1E98* gEntity1E98 = NULL;  // 0x03002C44

NAKED void Entity1E98_SetUpdateCallback(Entity1E98Elem* elem, void* fn) { INCFUNC("asm/func/Entity1E98_SetUpdateCallback.inc"); }

NAKED void FUN_080a45a8(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a45a8.inc"); }

NAKED void FUN_080a4620(HitboxData* a, HitboxData* b, Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a4620.inc"); }

NAKED void FUN_080a4670(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a4670.inc"); }

NAKED void FUN_080a46b0(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a46b0.inc"); }

NAKED void FUN_080a4728(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a4728.inc"); }

NAKED void FUN_080a472c(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a472c.inc"); }

NAKED void FUN_080a47d0(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a47d0.inc"); }

NAKED void FUN_080a4854(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a4854.inc"); }

NAKED void FUN_080a48bc(void) { INCFUNC("asm/func/FUN_080a48bc.inc"); }

NAKED s32 Entity1E98_Update(Entity1E98* p) { INCFUNC("asm/func/Entity1E98_Update.inc"); }

NAKED s32 Entity1E98_Destroy(Entity1E98* p) { INCFUNC("asm/func/Entity1E98_Destroy.inc"); }

NAKED void Entity1E98_InitHitbox(Entity1E98Elem* elem) { INCFUNC("asm/func/Entity1E98_InitHitbox.inc"); }

NAKED void Entity1E98_Init(Entity1E98* p) { INCFUNC("asm/func/Entity1E98_Init.inc"); }

NAKED Entity1E98* Entity1E98_Create_Internal(void) { INCFUNC("asm/func/Entity1E98_Create_Internal.inc"); }

NAKED s32 FUN_080a4e1c(void) { INCFUNC("asm/func/FUN_080a4e1c.inc"); }

NAKED void Entity1E98_Create(void) { INCFUNC("asm/func/Entity1E98_Create.inc"); }
