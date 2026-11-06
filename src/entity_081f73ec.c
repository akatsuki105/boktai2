#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

struct Entity081f73ecElem;

// ワームの体の節1つ
typedef struct {
  AuxSprite sprite;                  // 0x000
  AuxSpriteGfx gfx;                  // 0x02C, SPRITE_WORM
  HitboxData atkHitbox;              // 0x048, 攻撃判定, 地上に出ていて flags bit2 が立っている間だけ毎フレーム登録する
  HitboxData hurtbox;                // 0x098, 食らい判定, 防御力は segs[5] だけ Spawn の defense, ほかはその2倍
  AuxAnimState anim;                 // 0x0E8, segs[0] は animIdx 6 の variant 1, segs[1]〜[4] は 6 の variant 2, segs[5] は 7
  AuxAnimFile* animFile;             // 0x0F8, ANIM_WORM
  u8 phase;                          // 0x0FC, 体をくねらせる波の位相 (256 で1周)
  u8 flags;                          // 0x0FD, bit0=被弾してパレットを白くしている, bit1=地面より下にいて隠れている, bit2=攻撃判定を有効にしてよい
  u8 unk_fe[2];                      // 0x0FE
  u16 dustCooldown;                  // 0x100, 0 のときに地面へ着くと砂煙を出して 30 に戻す
  u16 unk_102;                       // 0x102, 0 になると flags bit2 を立てて 3 に戻す, 1フレームに立てるのは2節まで
  u8 unk_104[2];                     // 0x104
  u8 unk_106;                        // 0x106, 生成時に節の番号 * 24 が入るだけ
  u8 flashTime;                      // 0x107, 被弾すると 6, 0 になるとパレットを戻して flags bit0 を落とす
  u8 unk_108[8];                     // 0x108
  Vec3 unk_110;                      // 0x110, 生成時に sprite.pos と同じ座標が入る, 読み手は未発見
  Vec3 vel;                          // 0x118, 毎フレーム sprite.pos に足してから半分にする
  struct Entity081f73ecElem* owner;  // 0x120
} Entity081f73ecSegment;
static_assert(sizeof(Entity081f73ecSegment) == 292);

// 6つの節が連なったワーム1匹, 地中から飛び出してプレイヤーの方へ進み, また潜る
typedef struct Entity081f73ecElem {
  Entity081f73ecSegment segs[6];  // 0x000
  u8 headIdx;                     // 0x6D8, 先頭の節の添字 (0 か 5), ほかの節は先頭から順に1つ前の節を追いかける
  u8 emergeDelay;                 // 0x6D9, state 1 の残りフレーム数, 10 未満になると砂を噴く間隔が 20 から 4 フレームに縮む
  u8 angle;                       // 0x6DA, state 3 に入ったときのプレイヤーへの向き (256 で1周)
  u8 landSeCooldown;              // 0x6DB, 0 のときに segs[5] が着地すると SE 0x3D9 を鳴らして 20 にする
  Vec3 vel;                       // 0x6DC, 先頭の節の速さ, state 2 は y を 124 から毎フレーム 8 ずつ, state 5 は 0 から 12 ずつ減らす
  s16 flags;                      // 0x6E4, bit0=Spawn の pattern が 0 (くねりながら進む), bit1=pattern が 0 以外 (跳ねながら進む), bit2=被弾した
  u8 state;                       // 0x6E6, PTR_ARRAY_085ae588 の添字 (0:待機 1:地中で待つ 2:飛び出す 3:進む 4:被弾 5:潜る 6:片付け)
  s8 slotIdx;                     // 0x6E7, usedMask 上の自分のビット番号, 空きは -1
  s16 timer;                      // 0x6E8, state に入ってからのフレーム数
  bool8 stateBegun;               // 0x6EA, 立っていると次の更新で state の初期化をする
  u8 moveTime;                    // 0x6EB, state 3 の残りフレーム数, 尽きると state 5 へ移る
} Entity081f73ecElem;
static_assert(sizeof(Entity081f73ecElem) == 1772);

// サンドワームが呼び出すワームを1匹だけ出すシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u8 unk_18[32];                // 0x018
  u32 usedMask;                 // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f73ecElem elems[1];  // 0x03C
} Entity081f73ec;
static_assert(sizeof(Entity081f73ec) == 1832);

static Entity081f73ec* gEntity081f73ec;  // 0x030001FC

void Entity081f73ec_UpdateIdle(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateRemove(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateDive(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateMove(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateHurt(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateWait(Entity081f73ec*, Entity081f73ecElem*);
void Entity081f73ec_UpdateEmerge(Entity081f73ec*, Entity081f73ecElem*);

void (*const PTR_ARRAY_085ae588[7])(Entity081f73ec*, Entity081f73ecElem*) = {
    Entity081f73ec_UpdateIdle,
    Entity081f73ec_UpdateWait,
    Entity081f73ec_UpdateEmerge,
    Entity081f73ec_UpdateMove,
    Entity081f73ec_UpdateHurt,
    Entity081f73ec_UpdateDive,
    Entity081f73ec_UpdateRemove,
};  // 0x085AE588

NAKED void Entity081f73ec_InitSegs(Entity081f73ecElem* elem, SpriteID32 spriteId, u32 animFileID, u32 phase) { INCFUNC("asm/func/Entity081f73ec_InitSegs.inc"); }

NAKED s32 Entity081f73ec_UpdateBuried(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateBuried.inc"); }

NAKED void Entity081f73ec_RemoveSprites(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_RemoveSprites.inc"); }

NAKED void Entity081f73ec_UnregisterHurtboxes(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UnregisterHurtboxes.inc"); }

NAKED void Entity081f73ec_SetSegPos(Entity081f73ecElem* elem, s32 idx, Vec3* pos) { INCFUNC("asm/func/Entity081f73ec_SetSegPos.inc"); }

NAKED void Entity081f73ec_SetSegVel(Entity081f73ecElem* elem, Vec3* vel, s32 idx) { INCFUNC("asm/func/Entity081f73ec_SetSegVel.inc"); }

NAKED void FUN_081f57fc(Entity081f73ecElem* elem, Vec3* from, Vec3* to, s32 start, s32 end) { INCFUNC("asm/func/FUN_081f57fc.inc"); }

NAKED void Entity081f73ec_FollowHead(Entity081f73ecElem* elem, s32 div, s32 distSq) { INCFUNC("asm/func/Entity081f73ec_FollowHead.inc"); }

NAKED void Entity081f73ec_SetAllSegPos(Entity081f73ecElem* elem, Vec3* pos) { INCFUNC("asm/func/Entity081f73ec_SetAllSegPos.inc"); }

NAKED void FUN_081f5b38(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f5b38.inc"); }

NAKED void Entity081f73ec_SnapToGround(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_SnapToGround.inc"); }

NAKED void Entity081f73ec_ApplySegVel(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_ApplySegVel.inc"); }

NAKED void Entity081f73ec_StartFlash(Entity081f73ecSegment* seg) { INCFUNC("asm/func/Entity081f73ec_StartFlash.inc"); }

NAKED void Entity081f73ec_UpdateFlash(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateFlash.inc"); }

NAKED void Entity081f73ec_OnHit(HitboxData* a, HitboxData* b, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_OnHit.inc"); }

NAKED void Entity081f73ec_OnHurt(HitboxData* a, HitboxData* b, Entity081f73ecSegment* seg) { INCFUNC("asm/func/Entity081f73ec_OnHurt.inc"); }

NAKED void Entity081f73ec_InitHitbox(Entity081f73ecElem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, u32 defense, HitboxAttributes hurtAttrs, u32 weakness) { INCFUNC("asm/func/Entity081f73ec_InitHitbox.inc"); }

NAKED void FUN_081f6170(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f6170.inc"); }

NAKED void Entity081f73ec_UpdateHitbox(Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateHitbox.inc"); }

NAKED void Entity081f73ec_SpawnDust(Vec3* pos, s32 count) { INCFUNC("asm/func/Entity081f73ec_SpawnDust.inc"); }

NAKED void Entity081f73ec_UpdateIdle(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateIdle.inc"); }

NAKED void Entity081f73ec_UpdateRemove(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateRemove.inc"); }

NAKED void Entity081f73ec_UpdateDive(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateDive.inc"); }

NAKED void FUN_081f6458(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f6458.inc"); }

NAKED void FUN_081f6474(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f6474.inc"); }

NAKED void FUN_081f6498(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f6498.inc"); }

NAKED void FUN_081f65f4(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f65f4.inc"); }

NAKED void FUN_081f69a0(Entity081f73ecElem* elem) { INCFUNC("asm/func/FUN_081f69a0.inc"); }

NAKED void Entity081f73ec_UpdateMove(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateMove.inc"); }

NAKED void Entity081f73ec_UpdateHurt(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateHurt.inc"); }

NAKED void Entity081f73ec_UpdateWait(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateWait.inc"); }

NAKED void Entity081f73ec_UpdateEmerge(Entity081f73ec* p, Entity081f73ecElem* elem) { INCFUNC("asm/func/Entity081f73ec_UpdateEmerge.inc"); }

NAKED Entity081f73ecElem* Entity081f73ec_AllocElem_Internal(Entity081f73ec* p) { INCFUNC("asm/func/Entity081f73ec_AllocElem_Internal.inc"); }

NAKED Entity081f73ecElem* Entity081f73ec_AllocElem(Entity081f73ec* p) { INCFUNC("asm/func/Entity081f73ec_AllocElem.inc"); }

NAKED void Entity081f73ec_Spawn(Vec3* pos, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, s32 moveTime, s32 unk_6, s32 unk_7, s32 emergeDelay, s32 pattern, u32 defense, HitboxAttributes hurtAttrs, u32 weakness) {
  INCFUNC("asm/func/Entity081f73ec_Spawn.inc");
}

NAKED s32 Entity081f73ec_Update(Entity081f73ec* p) { INCFUNC("asm/func/Entity081f73ec_Update.inc"); }

NAKED s32 Entity081f73ec_Destroy(Entity081f73ec* p) { INCFUNC("asm/func/Entity081f73ec_Destroy.inc"); }

NAKED s32 Entity081f73ec_Init(Entity081f73ec* p) { INCFUNC("asm/func/Entity081f73ec_Init.inc"); }

NAKED Entity081f73ec* Entity081f73ec_Create(void) { INCFUNC("asm/func/Entity081f73ec_Create.inc"); }

NAKED void Entity081f73ec_ClearGlobal(void) { INCFUNC("asm/func/Entity081f73ec_ClearGlobal.inc"); }

NAKED bool8 Entity081f73ec_IsIdle(void) { INCFUNC("asm/func/Entity081f73ec_IsIdle.inc"); }

NAKED void Entity081f73ec_RequestDive(void) { INCFUNC("asm/func/Entity081f73ec_RequestDive.inc"); }
