#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  u8 state;            // 0x00, 下位3bitが状態関数表の添字, bit3 が立つと timer を張り直して anim を 2 番に戻す
  u8 unk_01;           // 0x01, 生成時に 0xFF
  u8 angle;            // 0x02, 8bit の向き, 上位3bitで anim の variant と hitPos のずらし方が決まる
  Vec3 pos;            // 0x04, 毎フレーム vel を足して sprite.pos に写す
  Vec3 vel;            // 0x0C
  HitboxData hitbox;   // 0x14
  AuxSprite sprite;    // 0x64
  AuxSprite sprite2;   // 0x90, 生成時は隠れている
  AuxAnimState anim;   // 0xBC, sprite のアニメ
  AuxAnimState anim2;  // 0xCC, sprite2 のアニメ
  Vec3 hitPos;         // 0xDC, sprite.pos を angle の向きにずらした hitbox の位置
  u8 idx;              // 0xE4, elems の添字, 空きは 0xFF
  s16 stateEntered;    // 0xE6, 状態 3 に入ったときに 1, 状態 3 の最初のフレームで 0 に戻る
  s16 anim2Done;       // 0xE8, anim2 が一巡すると 1
  u16 hitboxId;        // 0xEA, Hitbox_Init の id
  s16 frameCount;      // 0xEC, 0 以外の間 hitbox を登録する
  s16 timer;           // 0xEE
  s16 lifetime;        // 0xF0, 0 になると状態 3 に移る
} Entity081e9cacElem;
static_assert(sizeof(Entity081e9cacElem) == 244);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxAnimFile* animFile;         // 0x18, ANIM_D6C8
  AuxSpriteGfx gfx;              // 0x1C, SPRITE_2D41
  u32 activeMask;                // 0x38, elems の使用中ビット
  Entity081e9cacElem elems[12];  // 0x3C
} Entity081e9cac;
static_assert(sizeof(Entity081e9cac) == 2988);

IWRAM_DATA Entity081e9cac* gEntity081e9cac = NULL;  // 0x030001B4

NAKED void Entity081e9cacElem_OnHit(HitboxData* a, HitboxData* b, Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_OnHit.inc"); }

NAKED void Entity081e9cacElem_InitHitbox(Entity081e9cacElem* elem, s32 power, s32 knockbackPower, s32 invincibleTime) { INCFUNC("asm/func/Entity081e9cacElem_InitHitbox.inc"); }

NAKED void Entity081e9cacElem_UpdateState0(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_UpdateState0.inc"); }

NAKED void FUN_081e8f2c(Entity081e9cac* p, Entity081e9cacElem* elem) { INCFUNC("asm/func/FUN_081e8f2c.inc"); }

NAKED void Entity081e9cacElem_UpdateState1(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_UpdateState1.inc"); }

NAKED void Entity081e9cacElem_SetLifetime(Entity081e9cacElem* elem, s32 lifetime) { INCFUNC("asm/func/Entity081e9cacElem_SetLifetime.inc"); }

NAKED void Entity081e9cacElem_Launch(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_Launch.inc"); }

NAKED Entity081e9cacElem* Entity081e9cacElem_Remove(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_Remove.inc"); }

NAKED void Entity081e9cac_RemoveAll(void) { INCFUNC("asm/func/Entity081e9cac_RemoveAll.inc"); }

NAKED void Entity081e9cacElem_UpdateState2(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_UpdateState2.inc"); }

NAKED void Entity081e9cacElem_UpdateState3(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_UpdateState3.inc"); }

NAKED Entity081e9cacElem* Entity081e9cac_AllocElem(Entity081e9cac* p) { INCFUNC("asm/func/Entity081e9cac_AllocElem.inc"); }

NAKED void Entity081e9cac_GetAnimVariant(u32 angle, u8* variant, AuxAnimPlayFlags* flags) { INCFUNC("asm/func/Entity081e9cac_GetAnimVariant.inc"); }

NAKED void Entity081e9cacElem_UpdateHitPos(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_UpdateHitPos.inc"); }

NAKED Entity081e9cacElem* Entity081e9cac_SpawnAtAngle(Vec3* pos, u32 angle, s32 speed, s32 lifetime, s32 power, s32 knockbackPower, s32 invincibleTime) { INCFUNC("asm/func/Entity081e9cac_SpawnAtAngle.inc"); }

NAKED Entity081e9cacElem* Entity081e9cac_Spawn(Vec3* pos, Vec3* offset, Vec3* vel, u32 angle, u32 hitboxId, s32 power, s32 knockbackPower, s32 invincibleTime, s32 lifetime) { INCFUNC("asm/func/Entity081e9cac_Spawn.inc"); }

NAKED s32 Entity081e9cac_Update(Entity081e9cac* p) { INCFUNC("asm/func/Entity081e9cac_Update.inc"); }

NAKED s32 Entity081e9cac_Destroy(Entity081e9cac* p) { INCFUNC("asm/func/Entity081e9cac_Destroy.inc"); }

NAKED s32 Entity081e9cac_Init(Entity081e9cac* p) { INCFUNC("asm/func/Entity081e9cac_Init.inc"); }

NAKED Entity081e9cac* Entity081e9cac_Create(void) { INCFUNC("asm/func/Entity081e9cac_Create.inc"); }

NAKED void Entity081e9cac_ClearGlobal(void) { INCFUNC("asm/func/Entity081e9cac_ClearGlobal.inc"); }

NAKED bool32 Entity081e9cacElem_CheckFloor(Entity081e9cacElem* elem) { INCFUNC("asm/func/Entity081e9cacElem_CheckFloor.inc"); }
