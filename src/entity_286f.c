#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"

struct Entity286F;
struct Entity286FNode;

typedef void(Entity286FNodeCb)(struct Entity286F* p, struct Entity286FNode* node);
typedef s32(Entity286FNodeFn)(struct Entity286FNode* node);
typedef void(Entity286FNodeUpdate)(struct Entity286F* p, struct Entity286FNode* node, u32 elapsed);

typedef struct Entity286FNode {
  u8 active;                  // 0x000, Entity286F_LinkNode が 1 を入れ、FUN_0804114c が 0 にして Free する
  u8 kind;                    // 0x001, Entity286FNode_Alloc の第2引数
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
  u32 unk_10;                 // 0x010, 根拠: FUN_080441a4 が +1 して元の値を unk_2cc の第3引数に渡す
  u32 timer;                  // 0x014, 多数の関数が 0 に戻し、FUN_08042414 が +1 する
  u8 unk_18[4];               // 0x018, まだ未解析
  u16 plttID;                 // 0x01C, Entity286FNode_SetPltt が書き、Entity286FNode_RefreshPltt が再適用する
  u16 curPlttID;              // 0x01E, Entity286FNode_ApplyPltt が SpriteHolder_SetPlttID へ渡した値
  u16 unk_20;                 // 0x020, FUN_08044a54 系が 0 を入れる
  u8 unk_22[0x05C - 0x022];   // 0x022, まだ未解析
  Mover mover;                // 0x05C
  u16 unk_a0;                 // 0x0A0, FUN_080412fc が mover.id を複写し、&unk_a0 を FUN_08234660 に渡す
  u8 unk_a2[2];               // 0x0A2, まだ未解析
  Vec3* unk_a4;               // 0x0A4, FUN_080412fc が &mover.pos を入れる
  u8 unk_a8[0x0D0 - 0x0A8];   // 0x0A8, まだ未解析
  SpriteHolder sprite;        // 0x0D0, 0x08055XXX のスプライト API に渡す
  MsgQueue mq;                // 0x164
  u8 unk_198[0x1EE - 0x198];  // 0x198, まだ未解析
  u8 unk_1ee;                 // 0x1EE, 根拠: Entity286FNode_RemoveMover が 0 以外のときだけ mover を切り離して 0 に戻す
  u8 unk_1ef[0x214 - 0x1EF];  // 0x1EF, まだ未解析
  u8 shadowKind;              // 0x214, 1 なら shadow.ptcl, 2 なら shadow.aux
  u8 unk_215[0x217 - 0x215];  // 0x215, まだ未解析
  u8 unk_217;                 // 0x217, 0 以外なら次の state を unk_227 から取る
  u8 unk_218[0x227 - 0x218];  // 0x218, まだ未解析
  u8 unk_227;                 // 0x227, unk_217 が立っているときの遷移先 state
  u8 unk_228[0x244 - 0x228];  // 0x228, まだ未解析
  union {
    ParticleShadow ptcl;          // shadowKind == 1
    AuxShadow aux;                // shadowKind == 2
  } shadow;                       // 0x244
  u8 unk_2b0[0x2C8 - 0x2B0];      // 0x2B0, まだ未解析
  u16 unk_2c8;                    // 0x2C8, FUN_080411d8 が unk_2ca を複写する
  u16 unk_2ca;                    // 0x2CA, FUN_080415cc が書き、FUN_080411d8 が unk_2c8 へ移す
  Entity286FNodeUpdate* unk_2cc;  // 0x2CC, 根拠: FUN_080441a4 が (p, node, unk_10) で呼ぶ
  Entity286FNodeCb* cbs[4];       // 0x2D0, FUN_080411a0 が 0 以外のものを順に呼ぶ
  Entity286FNodeCb* onDestroy;    // 0x2E0, _Destroy が呼ぶ
  Entity286FNodeFn* fn;           // 0x2E4, node だけを渡して呼ぶ
  struct Entity286FNode* prev;    // 0x2E8
  struct Entity286FNode* next;    // 0x2EC
} Entity286FNode;
static_assert(sizeof(Entity286FNode) == 752);

typedef struct Entity286F {
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
  Player* player;           // 0x438, &gPlayerPtr[0], 毎フレーム更新
} Entity286F;
static_assert(sizeof(Entity286F) == 1084);

extern void (*const PTR_ARRAY_085ab36c[3])(unknown*, unknown*);
extern void (*const PTR_ARRAY_085ab378[14])(unknown*, unknown*);
extern void (*const PTR_ARRAY_085ab3b0[10])(unknown*, unknown*);
extern void (*const PTR_ARRAY_085ab3d8[11])(unknown*, unknown*);

void FUN_08055d7c(SpriteHolder* p);

COMMON_DATA Entity286F* gEntity286F = NULL;  // 0x03002B50

const u16 u16_ARRAY_085aaff4[270] = {
    0x103, 0x0,   0x103, 0x5,   0x103, 0x0,   0x103, 0x5,   0x103, 0x19E, 0x103, 0x1A3, 0x103, 0x19E, 0x103, 0x1A3, 0x103, 0x0,   0x103, 0x1,   0x103, 0x0,   0x103, 0x1,   0x102, 0x0,   0x102, 0x6,   0x102, 0x1E,  0x102, 0x6,   0x2,   0x7,   0x2,   0x8,   0x2,   0x9,   0x2,
    0x8,   0x3,   0x0,   0x3,   0x0,   0x3,   0x0,   0x3,   0x0,   0x0,   0x1,   0x0,   0xA,   0x0,   0x3,   0x0,   0x13,  0x0,   0x0,   0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x7,   0x1,   0x9,   0x1,   0xA,   0x1,   0xB,   0x1,   0xC,   0x1,   0xD,   0x1,   0xE,
    0x1,   0xF,   0x103, 0x7,   0x102, 0xE,   0x103, 0x7,   0x102, 0xE,   0x103, 0x7,   0x102, 0xC,   0x101, 0x28,  0x101, 0x29,  0x100, 0x0,   0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x202, 0x7,   0x202, 0xB,   0x202, 0xC,   0x101, 0xF,   0x302, 0x11,  0x302,
    0x12,  0x302, 0x13,  0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x202, 0xA,   0x1,   0xE,   0x100, 0x7,   0x100, 0x8,   0x100, 0x9,   0x100, 0x11,  0x100, 0x10,  0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x5,   0x100, 0x7,   0x100, 0x8,   0x100, 0xA,
    0x100, 0x9,   0x103, 0x0,   0x102, 0x5,   0x101, 0x9,   0x102, 0x7,   0x101, 0xA,   0x101, 0xB,   0x101, 0xC,   0x101, 0xD,   0x101, 0xE,   0x101, 0xF,   0x103, 0x10,  0x102, 0x15,  0x101, 0x19,  0x102, 0x17,  0x101, 0x1A,  0x101, 0x1B,  0x101, 0x1C,  0x101, 0x1D,  0x101,
    0x1E,  0x101, 0x1F,  0x100, 0x20,  0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x7,   0x103, 0x0,   0x102, 0x5,   0x103, 0x0,   0x102, 0x7,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x103, 0x0,   0x102, 0x0,
    0x102, 0x0,   0x102, 0x0,   0x102, 0x0,   0x101, 0x3,   0x101, 0x2,   0x103, 0x10,  0x102, 0x15,  0x103, 0x10,  0x102, 0x17,  0x103, 0x5,   0x102, 0xA,   0x103, 0x5,   0x102, 0xC,   0x103, 0x7,   0x102, 0xC,   0x103, 0x7,   0x102, 0xE,   0x100, 0x0,
};  // 0x085AAFF4

typedef struct {
  SpriteID16 id;     // 0x0, NPCのスプライトIDばっかり
  u8 idx;            // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  const void* data;  // 0x4, u16_ARRAY_085aaff4 のどの要素を指しているか
} Entity286FSpriteEntry;

const Entity286FSpriteEntry sEntity286FSprites[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, data : &u16_ARRAY_085aaff4[0]  },
    {id : SPRITE_MOUSE,                idx : 0, data : &u16_ARRAY_085aaff4[16] },
    {id : SPRITE_SKELETONS,            idx : 0, data : &u16_ARRAY_085aaff4[24] },
    {id : SPRITE_BOKU,                 idx : 0, data : &u16_ARRAY_085aaff4[32] },
    {id : SPRITE_OTNK,                 idx : 0, data : &u16_ARRAY_085aaff4[40] },
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, data : &u16_ARRAY_085aaff4[58] },
    {id : SPRITE_SHAIAN,               idx : 0, data : &u16_ARRAY_085aaff4[80] },
    {id : SPRITE_RITA,                 idx : 0, data : &u16_ARRAY_085aaff4[98] },
    {id : SPRITE_ZAJI,                 idx : 0, data : &u16_ARRAY_085aaff4[120]},
    {id : SPRITE_SUMIRE,               idx : 0, data : &u16_ARRAY_085aaff4[142]},
    {id : SPRITE_KURO,                 idx : 0, data : &u16_ARRAY_085aaff4[158]},
    {id : SPRITE_KID,                  idx : 0, data : &u16_ARRAY_085aaff4[200]},
    {id : SPRITE_LADY,                 idx : 0, data : &u16_ARRAY_085aaff4[208]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, data : &u16_ARRAY_085aaff4[216]},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, data : &u16_ARRAY_085aaff4[224]},
    {id : SPRITE_DAINN,                idx : 0, data : &u16_ARRAY_085aaff4[232]},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, data : &u16_ARRAY_085aaff4[8]  },
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, data : &u16_ARRAY_085aaff4[244]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, data : &u16_ARRAY_085aaff4[252]},
    {id : SPRITE_ENNIO_LUIS,           idx : 1, data : &u16_ARRAY_085aaff4[260]},
    {id : SPRITE_MEGAMAN,              idx : 0, data : &u16_ARRAY_085aaff4[268]}
};  // 0x085AB210

// 状態を差し替えて経過フレーム数を 0 に戻す
static inline void Entity286FNode_SetState(Entity286FNode* node, u32 state) {
  node->state = state;
  node->timer = 0;
}

// id と idx の組に対応するデータを表から探す
unknown* Entity286F_FindSpriteData(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sEntity286FSprites[i].id == id && sEntity286FSprites[i].idx == idx) {
      return (void*)sEntity286FSprites[i].data;
    }
  }

  return NULL;
}

NAKED unknown* FUN_08040dc0(SpriteID32 id, s32 idx) { INCFUNC("asm/func/FUN_08040dc0.inc"); }

NAKED s32 FUN_08040df4(Entity286F* p, Entity286FNode* node, SpriteID32 id, s32 idx) { INCFUNC("asm/func/FUN_08040df4.inc"); }

// ノードをリストの先頭に繋ぐ
void Entity286F_LinkNode(Entity286F* p, Entity286FNode* node) {
  if (p->head != NULL) {
    p->head->prev = node;
  }

  node->prev = NULL;
  node->next = p->head;
  p->head = node;
  node->active = 1;
}

NAKED void FUN_08040e68(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08040e68.inc"); }

// mover.id が id のノードを探す
Entity286FNode* Entity286F_FindNodeByMoverID(Entity286F* p, u32 id) {
  Entity286FNode* node = p->head;

  while (node != NULL) {
    if (node->mover.id == id) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

// ノードを1つ確保して種類だけ入れる
Entity286FNode* Entity286FNode_Alloc(Entity286F* p, u32 kind) {
  Entity286FNode* node;

  if (gEntity286F == NULL) {
    return NULL;
  }

  node = Malloc(sizeof(Entity286FNode));
  if (node == NULL) {
    return NULL;
  }

  ClearMemory(node, sizeof(Entity286FNode));
  node->kind = kind;
  return node;
}

NAKED s32 FUN_08040f0c(Entity286FNode* node, u16 param_2, u32* param_3, u8 param_4) { INCFUNC("asm/func/FUN_08040f0c.inc"); }

NAKED s32 FUN_08040f48(Entity286FNode* node, s32 assetType, u32 fileID, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_08040f48.inc"); }

NAKED s32 FUN_08040fc0(Entity286FNode* node, Vec3* pos, s8 param_3, u32 param_4, s8 param_5) { INCFUNC("asm/func/FUN_08040fc0.inc"); }

// 影を描画リストから外す
s32 Entity286FNode_RemoveShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Remove(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Remove(&node->shadow.aux);
  }

  return 0;
}

// 影を隠す
s32 Entity286FNode_HideShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Hide(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Hide(&node->shadow.aux);
  }

  return 0;
}

// 影を表示する
s32 Entity286FNode_ShowShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Show(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Show(&node->shadow.aux);
  }

  return 0;
}

s32 FUN_08002a48(Mover*);

s32 FUN_080410cc(Entity286FNode* node) {
  if (FUN_08002a48(&node->mover) < 0) {
    return -1;
  }
  node->unk_1ee = 1;
  return 0;
}

// 登録済みなら mover をリストから外す
s32 Entity286FNode_RemoveMover(Entity286FNode* node) {
  if (node->unk_1ee == 0) {
    return -1;
  }

  FUN_08002a58(&node->mover);
  node->unk_1ee = 0;
  return 0;
}

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

// ノードを表から外して Free する
s32 FUN_0804114c(Entity286FNode* node) {
  Entity286F* p = gEntity286F;

  if (p != NULL && node->active) {
    FUN_08040e68(p, node);
    Entity286FNode_RemoveMover(node);
    Mover_Unlink(&node->mover);
    FUN_08055d7c(&node->sprite);
    Entity286FNode_RemoveShadow(node);
    node->active = 0;
    Free(node);
    return 0;
  }
  return -1;
}

// 登録済みのコールバックを順に呼ぶ
s32 FUN_080411a0(Entity286F* p, Entity286FNode* node) {
  s32 i;

  if (!node->active) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if (node->cbs[i] != NULL) {
      node->cbs[i](p, node);
    }
  }
  return 0;
}

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

// 0xDDD0
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

// 待ちが解除されたら unk_05 を 1 にしてメッセージの待ちを終える
void FUN_0804355c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える
void FUN_08043588(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_080435b4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 1);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state を移してメッセージの待ちを終える
void FUN_080435f0(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
  }

  if (node->unk_07) {
    if (node->unk_217) {
      Entity286FNode_SetState(node, node->unk_227);
      node->unk_08 = 1;
    } else {
      Entity286FNode_SetState(node, 1);
      node->unk_08 = 1;
    }
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_0804364c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 5;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 1);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 6 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08043688(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 6;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

NAKED void FUN_080436c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080436c4.inc"); }

NAKED void FUN_08043774(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043774.inc"); }

NAKED void FUN_08043960(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043960.inc"); }

NAKED void FUN_08043a24(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043a24.inc"); }

NAKED void FUN_08043bcc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043bcc.inc"); }

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 12 へ進む
void FUN_08043c94(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 10;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 12);
    node->unk_08 = 1;
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 11 にして, unk_07 が立っていたら state 14 へ進む
void FUN_08043cc4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 11;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 14);
    node->unk_08 = 1;
  }

  node->timer++;
}

NAKED void FUN_08043cf4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043cf4.inc"); }

NAKED void FUN_08043da8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043da8.inc"); }

NAKED void FUN_08043e54(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043e54.inc"); }

NAKED s32 Entity286F_Update(Entity286F* p) { INCFUNC("asm/func/Entity286F_Update.inc"); }

s32 Entity286F_Destroy(Entity286F* p) {
  Entity286FNode* node = p->head;

  while (node != NULL) {
    Entity286FNode* next = node->next;

    if (node->onDestroy != NULL) {
      node->onDestroy(p, node);
    }
    FUN_0804114c(node);
    node = next;
  }

  gEntity286F = NULL;
  return 0;
}

NAKED s32 Entity286F_Init(Entity286F* p) { INCFUNC("asm/func/Entity286F_Init.inc"); }

Entity286F* Entity286F_Create(void) {
  if (gEntity286F == NULL) {
    Entity286F* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity286F));

    if (p != NULL) {
      SetEntityRoutine(p, Entity286F_Update, Entity286F_Destroy);
      if (Entity286F_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity286F;
}

void FUN_080440ac(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080440d0(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044104(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_08044138(Entity286F* p, Entity286FNode* node) { PTR_ARRAY_085ab36c[node->state](p, node); }

void FUN_08044150(Entity286F* p, Entity286FNode* node) { FUN_08044138(p, node); }

s32 FUN_0804415c(Entity286F* p, Entity286FNode* node) {
  FUN_08044150(p, node);
  return 0;
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044168(Entity286FNode* node) {
  Entity286FNodeUpdate* fn;

  if ((u8)(node->unk_05 - 1) > 13) {
    return 0;
  }

  fn = (Entity286FNodeUpdate*)PTR_ARRAY_085ab378[node->unk_05];
  node->unk_06 = node->unk_05;
  node->unk_2cc = fn;
  node->unk_10 = 0;
  node->unk_09 = 1;
  node->unk_18[0] = 0;
  return 1;
}

// ノードの待ちを解除して unk_2cc を呼ぶ
s32 FUN_080441a4(Entity286F* p, Entity286FNode* node) {
  u32 elapsed;

  node->flags = 0;
  node->unk_07 = 0;
  elapsed = node->unk_10++;

  if (node->unk_2cc != NULL) {
    node->unk_2cc(p, node, elapsed);
  }

  return 0;
}

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

s32 FUN_08044300(Entity286F* p, Entity286FNode* node) { return MsgQueue_Unregister(&node->mq); }

NAKED void FUN_08044310(void) { INCFUNC("asm/func/FUN_08044310.inc"); }

void FUN_0804454c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 2 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044570(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080445a4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_080445d8(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 5 に移してメッセージの待ちを終える
void FUN_080445fc(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 5;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 5);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_08044634(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 6;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 7 にして, unk_07 が立っていたら state 7 に移してメッセージの待ちを終える
void FUN_08044658(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 7;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 7);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 8 にしてメッセージの待ちを終える
void FUN_08044690(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 8;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 9 にしてメッセージの待ちを終える
void FUN_080446b4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 9;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080446d8(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 10;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

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

void FUN_08044a54(Entity286F* p, Entity286FNode* node) {
  if (node->unk_09) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 7, 2, 0, 1);
    node->unk_20 = 0;
  }

  node->fn(node);
}

NAKED void FUN_08044a90(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044a90.inc"); }

void FUN_08044d9c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_09) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 7, 2, 0, 4);
    node->unk_20 = 0;
  }

  node->fn(node);
}

NAKED void FUN_08044dd8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044dd8.inc"); }

NAKED void FUN_08044e6c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08044e6c.inc"); }

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044ee0(Entity286FNode* node) {
  Entity286FNodeUpdate* fn;

  if ((u8)(node->unk_05 - 1) > 10) {
    return 0;
  }

  fn = (Entity286FNodeUpdate*)PTR_ARRAY_085ab3d8[node->unk_05];
  node->unk_06 = node->unk_05;
  node->unk_2cc = fn;
  node->unk_10 = 0;
  node->unk_09 = 1;
  node->unk_18[0] = 0;
  return 1;
}

// ノードの待ちを解除して unk_2cc を呼ぶ
s32 FUN_08044f1c(Entity286F* p, Entity286FNode* node) {
  Entity286FNodeUpdate* fn;
  u32 elapsed;

  node->flags = 0;
  node->unk_07 = 0;
  elapsed = node->unk_10++;

  fn = node->unk_2cc;
  if (fn != NULL) {
    fn(p, node, elapsed);
  }

  return 0;
}

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

s32 FUN_080450b4(Entity286F* p, Entity286FNode* node) { return MsgQueue_Unregister(&node->mq); }

NAKED void FUN_080450c4(void) { INCFUNC("asm/func/FUN_080450c4.inc"); }
