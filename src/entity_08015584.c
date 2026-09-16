#include "animation.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"

// パーティクル1個分, FUN_080155e4 で発生させる
typedef struct {
  u8 active;                // 0x00, 0 でなければ Update/Destroy が処理する, アニメが終わると 0
  u8 kind;                  // 0x01, 5/6/7 は別スプライト (0x61F9) と animFiles[1], それ以外はパレット kind + 0x7D
  u16 timer;                // 0x02, 発生からのフレーム数
  s16 speedY;               // 0x04, q_decayStartY に達したら *= q_decayY / 256
  s16 speedXZ;              // 0x06, q_decayStartXZ に達したら *= q_decayXZ / 256
  u16 q_decayStartY;        // 0x08
  u16 q_decayY;             // 0x0A, 8.8 固定小数の倍率, どこでも書き込まれないので常に 0 (q_decayStartY で止まる)
  u16 q_decayStartXZ;       // 0x0C
  u16 q_decayXZ;            // 0x0E, 同上
  s16 dirX;                 // 0x10, 4.12 固定小数, gSineTable[(angleXZ + 0x40) & 0xFF]
  s16 dirY;                 // 0x12, 4.12 固定小数, gSineTable[angleY & 0xFF]
  s16 dirZ;                 // 0x14, 4.12 固定小数, gSineTable[angleXZ & 0xFF]
  u8 unk_16[2];             // 0x16
  u16 velX;                 // 0x18, dirX * speedXZ >> 12, 毎フレーム node.q_pos.x に加算
  u16 velY;                 // 0x1A, dirY * speedY >> 12, 毎フレーム node.q_pos.y に加算
  u16 velZ;                 // 0x1C, dirZ * speedXZ >> 12, SCREEN_COORD でなければ node.q_pos.z に加算
  u8 unk_1e[2];             // 0x1E
  ActorSpriteState sprite;  // 0x20
  q_SpriteNode44 node;      // 0x3C
  AnimState anim;           // 0x68
} q_Entity08015584Elem;
static_assert(sizeof(q_Entity08015584Elem) == 120);

typedef struct Entity08015584 {
  Entity e;                        // 0x00, ENTITY_UNK_9
  AnimationFile* animFiles[2];     // 0x18, GetFile(ANIMATION, FileID_ARRAY_085aa914[i])
  u32 q_counter;                   // 0x20, Init で 0, Update で毎フレーム +1
  q_Entity08015584Elem elems[32];  // 0x24
} Entity08015584;
static_assert(sizeof(Entity08015584) == 3876);

extern Entity08015584* gEntity08015584;  // 0x03000060

const FileID FileID_ARRAY_085aa914[2] = {
    0xF62B,
    0x31F4,
};  // 0x085AA914

void FUN_08015264(void) { gEntity08015584 = NULL; }

NAKED s32 Entity08015584_Update(Entity08015584* p) { INCFUNC("asm/func/Entity08015584_Update.inc"); }

NAKED s32 Entity08015584_Destroy(Entity08015584* p) { INCFUNC("asm/func/Entity08015584_Destroy.inc"); }

NAKED s32 Entity08015584_Init(Entity08015584* p, u32 _) { INCFUNC("asm/func/Entity08015584_Init.inc"); }

Entity08015584* Entity08015584_Create(u32 val, u32 _) {
  Entity08015584* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity08015584));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08015584_Update, Entity08015584_Destroy);
    if (Entity08015584_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED u32 FUN_080155c8(u32 flags) { INCFUNC("asm/func/FUN_080155c8.inc"); }

INCASM("asm/entity_08015584.inc");

NAKED void FUN_08015d3c(unknown* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_08015d3c.inc"); }

NAKED void UNUSED FUN_08015d9c(void* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { INCFUNC("asm/func/FUN_08015d9c.inc"); }

NAKED void UNUSED FUN_08015dfc(void* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_08015dfc.inc"); }

NAKED void VM_Sub4383(void) { INCFUNC("asm/func/VM_Sub4383.inc"); }
