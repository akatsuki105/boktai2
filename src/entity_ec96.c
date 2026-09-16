#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_actor.h"

typedef struct {
  Entity e;                 // 0x00, ENTITY_UNK_8
  u16 subroutineID;         // 0x18, 常に 0xEC96
  u8 q_breakable;           // 0x1A, script keyword 0x74, 1 なら q_hp を消費して破壊できる (パレットも別)
  u8 q_broken;              // 0x1B, 1 になると消滅処理に入る
  u16 q_hp;                 // 0x1C, script keyword 0x6C (既定 0x32), 被弾で HitboxData.wear の分だけ減る
  u8 q_damageTimer;         // 0x1E, 被弾時に 10 がセットされ毎フレーム減る (この間だけ点滅と振動をする)
  u8 unk_1f;                // 0x1F
  u32 q_timer;              // 0x20, 毎フレーム +1, 被弾して unk_1b が立つときに 0 に戻る
  s32 scriptID;             // 0x24, script keyword 0x65, 消滅時に Script_ExecById に渡す
  Vec3 pos;                 // 0x28, script keyword 0x70 で読む
  HitboxData hitbox;        // 0x30
  q_MapNode q_mapNode;      // 0x80
  ActorSpriteState sprite;  // 0x90
  q_SpriteNode44 node;      // 0xAC
} EntityEC96;
static_assert(sizeof(EntityEC96) == 216);

NAKED void FUN_08013288(HitboxData* a, HitboxData* b, EntityEC96* p) { INCFUNC("asm/func/FUN_08013288.inc"); }

NAKED s32 EntityEC96_Update(EntityEC96* p) { INCFUNC("asm/func/EntityEC96_Update.inc"); }

NAKED s32 EntityEC96_Destroy(EntityEC96* p) { INCFUNC("asm/func/EntityEC96_Destroy.inc"); }

NAKED s32 EntityEC96_Init(EntityEC96* p, u32 id) { INCFUNC("asm/func/EntityEC96_Init.inc"); }

NAKED EntityEC96* EntityEC96_Create(u32 id) { INCFUNC("asm/func/EntityEC96_Create.inc"); }
