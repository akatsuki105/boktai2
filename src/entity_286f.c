#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "sprite_common.h"

typedef struct Entity286F Entity286F;
typedef struct Entity286FNode Entity286FNode;
typedef void(Entity286FNodeCb)(Entity286F* p, Entity286FNode* node);
typedef s32(Entity286FNodeFn)(Entity286FNode* node);

// Entity286F がリストでぶら下げるノード, FUN_08040ed8 が Malloc(752) で作る
struct Entity286FNode {
  u8 active;                  // 0x000, FUN_08040e34 が 1 を入れ、FUN_0804114c が 0 にして Free する
  u8 kind;                    // 0x001, FUN_08040ed8 の第2引数
  u8 unk_02[2];               // 0x002, まだ未解析
  u8 state;                   // 0x004, FUN_08044138 / FUN_0804470c が関数テーブルの添字として使う
  u8 unk_05;                  // 0x005, コールバックが 1,2,4,6 などを入れる, FUN_080442d4 は 0
  u8 unk_06;                  // 0x006, まだ未解析
  u8 unk_07;                  // 0x007, unk_08 と一緒に 0 に戻される
  u8 unk_08;                  // 0x008, 0 以外ならコールバックが待ちを解除して 0 に戻す
  u8 unk_09;                  // 0x009, まだ未解析
  u8 unk_0a;                  // 0x00A, FUN_080411d8 が 0 以外のときだけ進み、処理後 0 に戻す
  u8 unk_0b[3];               // 0x00B, まだ未解析
  u16 flags;                  // 0x00E, 0x100 / 0x200 / 0x1000 のビットで分岐する
  u8 unk_10[4];               // 0x010, まだ未解析
  u32 timer;                  // 0x014, 多数の関数が 0 に戻し、FUN_08042414 が +1 する
  u8 unk_18[4];               // 0x018, まだ未解析
  u16 plttID;                 // 0x01C, Entity286FNode_SetPltt が書き、Entity286FNode_RefreshPltt が再適用する
  u16 curPlttID;              // 0x01E, Entity286FNode_ApplyPltt が SpriteHolder_SetPlttID へ渡した値
  u8 unk_20[0x05C - 0x020];   // 0x020, まだ未解析
  Mover mover;                // 0x05C
  u16 unk_a0;                 // 0x0A0, FUN_080412fc が mover.id を複写し、&unk_a0 を FUN_08234660 に渡す
  u8 unk_a2[2];               // 0x0A2, まだ未解析
  Vec3* unk_a4;               // 0x0A4, FUN_080412fc が &mover.pos を入れる
  u8 unk_a8[0x0D0 - 0x0A8];   // 0x0A8, まだ未解析
  SpriteHolder sprite;        // 0x0D0, 0x08055XXX のスプライト API に渡す
  EntityMsgBox msgbox;        // 0x164
  u8 unk_198[0x214 - 0x198];  // 0x198, まだ未解析
  s8 shadowKind;              // 0x214, 1 なら shadow.ptcl, 2 なら shadow.aux
  u8 unk_215[0x244 - 0x215];  // 0x215, まだ未解析
  union {
    ParticleShadow ptcl;        // shadowKind == 1
    AuxShadow aux;              // shadowKind == 2
  } shadow;                     // 0x244
  u8 unk_2b0[0x2C8 - 0x2B0];    // 0x2B0, まだ未解析
  u16 unk_2c8;                  // 0x2C8, FUN_080411d8 が unk_2ca を複写する
  u16 unk_2ca;                  // 0x2CA, FUN_080415cc が書き、FUN_080411d8 が unk_2c8 へ移す
  u8 unk_2cc[4];                // 0x2CC, まだ未解析
  Entity286FNodeCb* cbs[4];     // 0x2D0, FUN_080411a0 が 0 以外のものを順に呼ぶ
  Entity286FNodeCb* onDestroy;  // 0x2E0, _Destroy が呼ぶ
  Entity286FNodeFn* fn;         // 0x2E4, node だけを渡して呼ぶ
  Entity286FNode* prev;         // 0x2E8
  Entity286FNode* next;         // 0x2EC
};
static_assert(sizeof(Entity286FNode) == 752);

// ノードをまとめて動かす管理エンティティ
struct Entity286F {
  Entity e;                 // 0x000, ENTITY_UNK_9
  u32 frameCount;           // 0x018, _Update が毎フレーム +1
  Entity286FNode* head;     // 0x01C, リストの先頭, 解放は FUN_0804114c
  bool8 minuteChanged;      // 0x020, prevMinute != minute
  u8 prevMinute;            // 0x021, 1フレーム前の minute
  u8 hour;                  // 0x022, Time_GetHour
  u8 minute;                // 0x023, Time_GetMinute
  s8 unk_24;                // 0x024, FUN_08018a08 の戻り値
  u8 unk_25[3];             // 0x025, padding?
  s32 unk_28;               // 0x028, _Update が毎フレーム 1 - x で 0/1 を往復させる, unk_2c の添字
  u32 unk_2c[2];            // 0x02C, _Update が unk_28 の側だけ 0 にする
  u8 unk_34[0x434 - 0x34];  // 0x034, まだ未解析, C/I/U/D のどれからも触らない
  Vec3* playerPos;          // 0x434, gPlayerPtr[0] があれば &gPlayerPtr[0]->mover.pos
  Player* player;           // 0x438, gPlayerPtr[0] の写し, 毎フレーム更新
};
static_assert(sizeof(Entity286F) == 1084);

extern void (*const PTR_ARRAY_085ab36c[3])(unknown*, unknown*);
extern void (*const PTR_ARRAY_085ab3b0[10])(unknown*, unknown*);

COMMON_DATA Entity286F* gEntity286F = NULL;  // 0x03002B50

NAKED unknown* FUN_08040d94(SpriteID32 id, s32 idx) { INCFUNC("asm/func/FUN_08040d94.inc"); }

NAKED unknown* FUN_08040dc0(SpriteID32 id, s32 idx) { INCFUNC("asm/func/FUN_08040dc0.inc"); }

NAKED s32 FUN_08040df4(Entity286F* p, Entity286FNode* node, SpriteID32 id, s32 idx) { INCFUNC("asm/func/FUN_08040df4.inc"); }

NAKED void FUN_08040e34(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08040e34.inc"); }

NAKED void FUN_08040e68(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08040e68.inc"); }

NAKED s32 FUN_08040eb0(Entity286F* p, u32 param_2) { INCFUNC("asm/func/FUN_08040eb0.inc"); }

NAKED Entity286FNode* FUN_08040ed8(Entity286F* p, u8 param_2) { INCFUNC("asm/func/FUN_08040ed8.inc"); }

NAKED s32 FUN_08040f0c(Entity286FNode* node, u16 param_2, u32* param_3, u8 param_4) { INCFUNC("asm/func/FUN_08040f0c.inc"); }

NAKED s32 FUN_08040f48(Entity286FNode* node, s32 assetType, u32 fileID, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_08040f48.inc"); }

NAKED s32 FUN_08040fc0(Entity286FNode* node, Vec3* pos, s8 param_3, u32 param_4, s8 param_5) { INCFUNC("asm/func/FUN_08040fc0.inc"); }

NAKED s32 FUN_0804103c(Entity286FNode* node) { INCFUNC("asm/func/FUN_0804103c.inc"); }

NAKED s32 FUN_0804106c(Entity286FNode* node) { INCFUNC("asm/func/FUN_0804106c.inc"); }

NAKED s32 FUN_0804109c(Entity286FNode* node) { INCFUNC("asm/func/FUN_0804109c.inc"); }

NAKED s32 FUN_080410cc(Entity286FNode* node) { INCFUNC("asm/func/FUN_080410cc.inc"); }

NAKED s32 FUN_080410f4(Entity286FNode* node) { INCFUNC("asm/func/FUN_080410f4.inc"); }

s32 Entity286FNode_ApplyPltt(Entity286FNode* node, u16 plttID) {
  SpriteHolder* sprite = &node->sprite;

  node->curPlttID = plttID;
  return SpriteHolder_SetPlttID(sprite, node->curPlttID);
}

s32 Entity286FNode_SetPltt(Entity286FNode* node, u16 param_2) {
  node->plttID = param_2;
  return Entity286FNode_ApplyPltt(node, node->plttID);
}

s32 Entity286FNode_RefreshPltt(Entity286FNode* node) { return Entity286FNode_ApplyPltt(node, node->plttID); }

NAKED s32 FUN_0804114c(Entity286FNode* node) { INCFUNC("asm/func/FUN_0804114c.inc"); }

NAKED s32 FUN_080411a0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080411a0.inc"); }

NAKED s32 FUN_080411d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080411d8.inc"); }

void FUN_080412f4(void) {}

void FUN_080412f8(void) {}

NAKED s32 FUN_080412fc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080412fc.inc"); }

NAKED s32 FUN_0804135c(Entity286FNode* node, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_0804135c.inc"); }

NAKED s32 FUN_080413b8(Entity286FNode* node, s32 param_2, u16 param_3, s32 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_080413b8.inc"); }

NAKED s32 FUN_080413fc(Entity286FNode* node, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_080413fc.inc"); }

NAKED s32 FUN_08041460(Entity286FNode* node, s32 param_2, u16 param_3, s32 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_08041460.inc"); }

NAKED s32 FUN_08041480(Entity286FNode* node, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08041480.inc"); }

NAKED void FUN_080414fc(Entity286FNode* node, s32 param_2) { INCFUNC("asm/func/FUN_080414fc.inc"); }

NAKED s32 FUN_0804157c(s16* param_1, s16* param_2, s32 param_3) { INCFUNC("asm/func/FUN_0804157c.inc"); }

NAKED void FUN_080415cc(Entity286FNode* node, s32 param_2, u16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_080415cc.inc"); }

NAKED void FUN_080417dc(Mover* mover) { INCFUNC("asm/func/FUN_080417dc.inc"); }

NAKED void FUN_08041918(Entity286F* p) { INCFUNC("asm/func/FUN_08041918.inc"); }

NAKED s32 FUN_08041b28(void) { INCFUNC("asm/func/FUN_08041b28.inc"); }

NAKED s32 FUN_08041bd4(void) { INCFUNC("asm/func/FUN_08041bd4.inc"); }

NAKED s32 FUN_08041d60(void) { INCFUNC("asm/func/FUN_08041d60.inc"); }

NAKED s32 FUN_08041dcc(void) { INCFUNC("asm/func/FUN_08041dcc.inc"); }

NAKED s32 FUN_08041e10(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08041e10.inc"); }

NAKED void FUN_08042178(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042178.inc"); }

NAKED void FUN_080421bc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080421bc.inc"); }

NAKED void FUN_08042200(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042200.inc"); }

NAKED void FUN_0804234c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804234c.inc"); }

NAKED void FUN_08042414(Entity286F* p, Entity286FNode* node, s32 param_3) { INCFUNC("asm/func/FUN_08042414.inc"); }

NAKED void FUN_08042638(Entity286F* p, Entity286FNode* node, s32 param_3) { INCFUNC("asm/func/FUN_08042638.inc"); }

NAKED void FUN_08042868(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042868.inc"); }

NAKED void FUN_080428b8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080428b8.inc"); }

NAKED void FUN_08042a48(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042a48.inc"); }

NAKED void FUN_08042cf0(Entity286F* p, Entity286FNode* node, s32 param_3) { INCFUNC("asm/func/FUN_08042cf0.inc"); }

NAKED void FUN_08042d50(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042d50.inc"); }

NAKED void FUN_08042f34(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08042f34.inc"); }

NAKED void FUN_08043108(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043108.inc"); }

NAKED void FUN_08043360(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043360.inc"); }

NAKED s32 FUN_080434ac(Entity286FNode* node, s32 param_2) { INCFUNC("asm/func/FUN_080434ac.inc"); }

NAKED s32 FUN_08043510(Entity286FNode* node) { INCFUNC("asm/func/FUN_08043510.inc"); }

NAKED void FUN_0804355c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804355c.inc"); }

NAKED void FUN_08043588(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043588.inc"); }

NAKED void FUN_080435b4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080435b4.inc"); }

NAKED void FUN_080435f0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080435f0.inc"); }

NAKED void FUN_0804364c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804364c.inc"); }

NAKED void FUN_08043688(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043688.inc"); }

NAKED void FUN_080436c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080436c4.inc"); }

NAKED void FUN_08043774(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043774.inc"); }

NAKED void FUN_08043960(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043960.inc"); }

NAKED void FUN_08043a24(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043a24.inc"); }

NAKED void FUN_08043bcc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043bcc.inc"); }

NAKED void FUN_08043c94(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043c94.inc"); }

NAKED void FUN_08043cc4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043cc4.inc"); }

NAKED void FUN_08043cf4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043cf4.inc"); }

NAKED void FUN_08043da8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043da8.inc"); }

NAKED void FUN_08043e54(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043e54.inc"); }

NAKED s32 Entity286F_Update(Entity286F* p) { INCFUNC("asm/func/Entity286F_Update.inc"); }

NAKED s32 Entity286F_Destroy(Entity286F* p) { INCFUNC("asm/func/Entity286F_Destroy.inc"); }

NAKED s32 Entity286F_Init(Entity286F* p) { INCFUNC("asm/func/Entity286F_Init.inc"); }

NAKED Entity286F* Entity286F_Create(void) { INCFUNC("asm/func/Entity286F_Create.inc"); }

void FUN_080440ac(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
    EntityMsgBox_EndWait(&node->msgbox, 1);
  }
}

NAKED void FUN_080440d0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080440d0.inc"); }

NAKED void FUN_08044104(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044104.inc"); }

void FUN_08044138(Entity286F* p, Entity286FNode* node) { PTR_ARRAY_085ab36c[node->state](p, node); }

void FUN_08044150(Entity286F* p, Entity286FNode* node) { FUN_08044138(p, node); }

s32 FUN_0804415c(Entity286F* p, Entity286FNode* node) {
  FUN_08044150(p, node);
  return 0;
}

NAKED s32 FUN_08044168(Entity286FNode* node) { INCFUNC("asm/func/FUN_08044168.inc"); }

NAKED s32 FUN_080441a4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080441a4.inc"); }

NAKED void FUN_080441d8(Entity286FNode* node) { INCFUNC("asm/func/FUN_080441d8.inc"); }

s32 FUN_080442d4(Entity286F* p, Entity286FNode* node) {
  FUN_080441d8(node);
  FUN_080411d8(p, node);
  node->unk_05 = 0;
  return 0;
}

s32 FUN_080442f4(Entity286F* p, Entity286FNode* node) {
  FUN_080412fc(p, node);
  return 0;
}

s32 FUN_08044300(Entity286F* p, Entity286FNode* node) { return EntityMsgBus_Unregister(&node->msgbox); }

NAKED void FUN_08044310(void) { INCFUNC("asm/func/FUN_08044310.inc"); }

void FUN_0804454c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 1;
    EntityMsgBox_EndWait(&node->msgbox, 1);
  }
}

NAKED void FUN_08044570(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044570.inc"); }

NAKED void FUN_080445a4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080445a4.inc"); }

void FUN_080445d8(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
    EntityMsgBox_EndWait(&node->msgbox, 1);
  }
}

NAKED void FUN_080445fc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080445fc.inc"); }

void FUN_08044634(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 6;
    EntityMsgBox_EndWait(&node->msgbox, 1);
  }
}

NAKED void FUN_08044658(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044658.inc"); }

NAKED void FUN_08044690(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044690.inc"); }

NAKED void FUN_080446b4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080446b4.inc"); }

NAKED void FUN_080446d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080446d8.inc"); }

void FUN_0804470c(Entity286F* p, Entity286FNode* node) { PTR_ARRAY_085ab3b0[node->state](p, node); }

void FUN_08044724(Entity286F* p, Entity286FNode* node) { FUN_0804470c(p, node); }

s32 FUN_08044730(Entity286F* p, Entity286FNode* node) {
  FUN_08044724(p, node);
  return 0;
}

NAKED void FUN_0804473c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804473c.inc"); }

NAKED void FUN_0804478c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804478c.inc"); }

NAKED void FUN_080448c8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080448c8.inc"); }

NAKED void FUN_0804494c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0804494c.inc"); }

NAKED void FUN_080449c0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080449c0.inc"); }

NAKED void FUN_08044a54(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044a54.inc"); }

NAKED void FUN_08044a90(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044a90.inc"); }

NAKED void FUN_08044d9c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044d9c.inc"); }

NAKED void FUN_08044dd8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044dd8.inc"); }

NAKED void FUN_08044e6c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044e6c.inc"); }

NAKED s32 FUN_08044ee0(Entity286FNode* node) { INCFUNC("asm/func/FUN_08044ee0.inc"); }

NAKED s32 FUN_08044f1c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044f1c.inc"); }

NAKED void FUN_08044f50(Entity286FNode* node) { INCFUNC("asm/func/FUN_08044f50.inc"); }

s32 FUN_08045088(Entity286F* p, Entity286FNode* node) {
  FUN_08044f50(node);
  FUN_080411d8(p, node);
  node->unk_05 = 0;
  return 0;
}

s32 FUN_080450a8(Entity286F* p, Entity286FNode* node) {
  FUN_080412fc(p, node);
  return 0;
}

s32 FUN_080450b4(Entity286F* p, Entity286FNode* node) { return EntityMsgBus_Unregister(&node->msgbox); }

NAKED void FUN_080450c4(void) { INCFUNC("asm/func/FUN_080450c4.inc"); }
