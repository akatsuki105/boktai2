#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_aux.h"

// コウモリ1匹
typedef struct {
  bool8 stateEntered;     // 0x000, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u8 state;               // 0x001, PTR_ARRAY_085aba2c の添字 (0: 散開, 1: target の近くへ寄る, 2: target を狙う, 3: うろつく, 4: 突進, 5: ブラックホールへ寄る, 6: 被弾してブラックホールへ飛ぶ, 7: ブラックホールの中を漂う, 8: 被弾, 9: goal へ戻る, 10: goal で待つ, 11: 止まる)
  bool8 animLooped;       // 0x002, anim が先頭のコマへ戻ったフレームだけ 1, 読み手は見つかっていない
  u8 bobAngle;            // 0x003, 毎フレーム 4 進む, sprite.pos.y を gSineTable で上下に揺らす
  u16 timer;              // 0x004, state に入ってからのフレーム数
  u8 angle;               // 0x006, 進む向き, gSineTable の添字
  u8 turnTimer;           // 0x007, 0 になると angle を選び直し, 乱数で入れ直す
  s8 targetIdx;           // 0x008, Entity0805d364.targets の添字, -1 なら追わない
  u8 retargetTimer;       // 0x009, 0 になると targetIdx を targetCount から決め直す, 被弾すると 250 にして targetIdx を 0 にする (-1 のときを除く)
  u8 unk_a[4];            // 0x00A
  u16 baseY;              // 0x00E, 開始時の pos.y, state 7 以外では pos.y が毎フレーム 1 ずつここへ寄る
  u16 speed;              // 0x010, 1フレームの移動量, gSineTable との積を 12bit 右シフトして足す, state 9 では 16
  u16 unk_12;             // 0x012, 10 が入るだけ
  Vec3 pos;               // 0x014, sprite.pos へ写す
  Vec3 dest;              // 0x01C, state 1, 5, 6, 7, 9 で向かう点
  Vec3 lungeOrigin;       // 0x024, state 4 の突進の起点, ここから angle の向きへ最大 256 出て戻る
  HitboxData hitbox;      // 0x02C, state 4 の間だけ登録する, 攻撃力は power
  HitboxData hurtbox;     // 0x07C, 防御力は defense, 当たると state 6 か 8 へ移る
  AuxAnimState anim;      // 0x0CC, コマ送りは自前で行う
  AuxSprite sprite;       // 0x0DC
  AuxSpriteGfx gfx;       // 0x108, SPRITE_BAT, パレット 611 (被弾直後の 6 フレームは 306), pltt は Entity0805d364.pltt を指す
  ParticleShadow shadow;  // 0x124
} Entity0805d364Elem;
static_assert(sizeof(Entity0805d364Elem) == 356);

// Ringo が出すコウモリ16匹の群れ, 散開して targets を狙い, 600 フレームで goal へ集まり, 終わると Ringo を goal に戻す
typedef struct Entity0805d364 {
  Entity e;                      // 0x000, ENTITY_UNK_8
  bool32 active;                 // 0x018, 0 の間は何も更新しない
  bool8 blackHoleActive;         // 0x01C, gBlackHole が state 6 の間 1, 立つと要素はブラックホールへ吸われる
  bool8 finished;                // 0x01D, 全要素が state 7 か 10 に揃うか timer が 1200 に達すると 1, 立つと全要素を隠して Ringo を goal に戻す
  bool8 returning;               // 0x01E, timer が 600 に達すると 1, 立つと要素は goal へ戻る
  u8 targetCount;                // 0x01F, targets の数, 2 なら前半8匹が targets[1] を, 後半8匹が targets[0] を追い, 0 なら全員 targets[0], それ以外は追わない
  u16 power;                     // 0x020, 10
  u16 defense;                   // 0x022, 100
  u32 timer;                     // 0x024, 開始からのフレーム数
  WorldPos* targets[2];          // 0x028, &gPlayerPtr[i]->mover.pos (0: ジャンゴ, 1: 共闘サバタ)
  Vec3 blackHolePos;             // 0x030, ブラックホールがいなければ前の値のまま
  Vec3 goal;                     // 0x038
  AuxAnimFile* anim;             // 0x040, ANIM_BAT
  Entity0805d364Elem elems[16];  // 0x044
  s8 fadeMode;                   // 0x1684, -1: 止める, 0: fadeLevel を 63 まで上げる, 1: 0 まで下げる, 2: 32 まで上げる
  s8 fadeLevel;                  // 0x1685, pltt をパレット 611 から 612 へ寄せる度合い, 64 で 612 そのもの
  u8 unk_1686[2];                // 0x1686
  rgb555 pltt[16];               // 0x1688, elems[i].gfx.pltt がここを指す
} Entity0805d364;
static_assert(sizeof(Entity0805d364) == 5800);

NAKED void Entity0805d364_OnHurt(HitboxData* a, HitboxData* b, Entity0805d364Elem* elem) { INCFUNC("asm/func/Entity0805d364_OnHurt.inc"); }

NAKED void Entity0805d364_OnHit(HitboxData* a, HitboxData* b, Entity0805d364Elem* elem) { INCFUNC("asm/func/Entity0805d364_OnHit.inc"); }

NAKED s32 Entity0805d364_InitElem(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_InitElem.inc"); }

NAKED s32 Entity0805d364_DestroyElem(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_DestroyElem.inc"); }

NAKED s32 Entity0805d364_HideElem(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_HideElem.inc"); }

NAKED void Entity0805d364_Finish(Entity0805d364* p) { INCFUNC("asm/func/Entity0805d364_Finish.inc"); }

NAKED void Entity0805d364_SetElemAnim(Entity0805d364* p, Entity0805d364Elem* elem, u32 animIdx) { INCFUNC("asm/func/Entity0805d364_SetElemAnim.inc"); }

NAKED void Entity0805d364_UpdateElemSprite(Entity0805d364Elem* elem) { INCFUNC("asm/func/Entity0805d364_UpdateElemSprite.inc"); }

NAKED void Entity0805d364_UpdateSpread(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateSpread.inc"); }

NAKED void Entity0805d364_UpdateAim(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateAim.inc"); }

NAKED void Entity0805d364_UpdateApproach(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateApproach.inc"); }

NAKED void Entity0805d364_UpdateWander(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateWander.inc"); }

NAKED void Entity0805d364_UpdateLunge(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateLunge.inc"); }

NAKED void Entity0805d364_UpdateToBlackHole(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateToBlackHole.inc"); }

NAKED void Entity0805d364_UpdateHurtToBlackHole(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateHurtToBlackHole.inc"); }

NAKED void Entity0805d364_UpdateInBlackHole(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateInBlackHole.inc"); }

NAKED void Entity0805d364_UpdateHurt(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateHurt.inc"); }

NAKED void Entity0805d364_UpdateReturn(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateReturn.inc"); }

NAKED void Entity0805d364_UpdateArrived(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateArrived.inc"); }

NAKED void Entity0805d364_UpdateIdle(Entity0805d364* p, Entity0805d364Elem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d364_UpdateIdle.inc"); }

void (*const PTR_ARRAY_085aba2c[12])(Entity0805d364*, Entity0805d364Elem*, s32) = {
    Entity0805d364_UpdateSpread,
    Entity0805d364_UpdateApproach,
    Entity0805d364_UpdateAim,
    Entity0805d364_UpdateWander,
    Entity0805d364_UpdateLunge,
    Entity0805d364_UpdateToBlackHole,
    Entity0805d364_UpdateHurtToBlackHole,
    Entity0805d364_UpdateInBlackHole,
    Entity0805d364_UpdateHurt,
    Entity0805d364_UpdateReturn,
    Entity0805d364_UpdateArrived,
    Entity0805d364_UpdateIdle,
};  // 0x085ABA2C

NAKED s32 Entity0805d364_Update(Entity0805d364* p) { INCFUNC("asm/func/Entity0805d364_Update.inc"); }

NAKED s32 Entity0805d364_Destroy(Entity0805d364* p) { INCFUNC("asm/func/Entity0805d364_Destroy.inc"); }

NAKED s32 Entity0805d364_Init(Entity0805d364* p, u32 targetCount) { INCFUNC("asm/func/Entity0805d364_Init.inc"); }

NAKED Entity0805d364* Entity0805d364_Create(u32 targetCount) { INCFUNC("asm/func/Entity0805d364_Create.inc"); }

NAKED s32 Entity0805d364_Start(Entity0805d364* p, Vec3* from, Vec3* to, s32 speed, s32 param_5) { INCFUNC("asm/func/Entity0805d364_Start.inc"); }

NAKED void Entity0805d364_StartReturn(Entity0805d364* p) { INCFUNC("asm/func/Entity0805d364_StartReturn.inc"); }
