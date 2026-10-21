#include "entity.h"
#include "global.h"
#include "solar.h"
#include "sprite.h"
#include "video.h"
#include "vm.h"

struct Entity8B8E;

typedef void(Entity8B8EFunc)(struct Entity8B8E* p);

// 売り物1件ぶんの枠
typedef struct {
  bool8 active;   // 0x00, 立っている枠だけ sprites2 を見せる
  u8 unk_01[35];  // 0x01, まだ未解析
} Entity8B8EItem;
static_assert(sizeof(Entity8B8EItem) == 36);

// 通信ショップの画面, LinkShopManager に自分を owner として登録する
typedef struct Entity8B8E {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  Entity8B8EFunc* updateCallback;  // 0x0018, Init は FUN_081e80ac を入れる
  u8 unk_1c[0x28 - 0x1C];          // 0x001C, まだ未解析
  MainSprite sprites[28];          // 0x0028
  u8 unk_aa8[0xBC4 - 0xAA8];       // 0x0AA8, まだ未解析
  Entity8B8EItem items[16];        // 0x0BC4
  u8 unk_e04[0xE4C - 0xE04];       // 0x0E04, まだ未解析
  MainSprite sprites2[18];         // 0x0E4C
  MainSprite sprite_150c;          // 0x150C
  MainSpriteGfx gfx_156c;          // 0x156C
  u8 unk_158c[0x1598 - 0x158C];    // 0x158C, まだ未解析
  u8 spriteCount;                  // 0x1598, FUN_081e3fe0 が隠す sprites の個数
  s8 selectedSlot;                 // 0x1599, 選んでいる武器の枠
  u8 unk_159a[0x15BC - 0x159A];    // 0x159A, まだ未解析
  u8 unk_15bc[0x24];               // 0x15BC, FUN_081e36e8 が ClearMemory でまとめて消す
  u8 unk_15e0[0x15E2 - 0x15E0];    // 0x15E0, まだ未解析
  u16 unk_15e2;                    // 0x15E2, FUN_081e36e8 が 0 を書く
  u8 unk_15e4[0x15E7 - 0x15E4];    // 0x15E4, まだ未解析
  u8 unk_15e7;                     // 0x15E7, FUN_081e3714 が 3 を書く
  u8 unk_15e8[4];                  // 0x15E8, FUN_081e3714 が全部 9 にする
  u8 unk_15ec[4];                  // 0x15EC, FUN_081e3714 が ClearMemory で消す
  u8 unk_15f0[0x1610 - 0x15F0];    // 0x15F0, まだ未解析
  u32 unk_1610;                    // 0x1610, Init が 0 を書く
  u8 unk_1614;                     // 0x1614, Init が 1 を書く
  u8 unk_1615;                     // 0x1615, Init が 0 を書く
  u8 unk_1616;                     // 0x1616, Init が 0x14 を書く
  u8 unk_1617;                     // 0x1617, Init が 0xFF を書く
  u8 unk_1618[0x161A - 0x1618];    // 0x1618, まだ未解析
  u8 unk_161a;                     // 0x161A, selectedSlot と比べる枠番号
  u8 unk_161b;                     // 0x161B, まだ未解析
  u32 sendTag;                     // 0x161C, LinkShopManager_Send に渡す識別子
  u8 unk_1620[0x1626 - 0x1620];    // 0x1620, まだ未解析
  u16 exitScriptID;                // 0x1626, .e=0, 通信が中断されたときに実行する
  u16 unk_1628;                    // 0x1628, .l=0, FUN_081e5290 が 0 でなければ実行する
  u8 unk_162a[0x162C - 0x162A];    // 0x162A, まだ未解析
  u16 unk_162c;                    // 0x162C, FUN_081e4b68 が引数と比べるセーブ枠番号
  u8 unk_162e[5680 - 0x162E];      // 0x162E, まだ未解析
} Entity8B8E;
static_assert(sizeof(Entity8B8E) == 5680);

// Entity8B8E.unk_1610
#define E8B8E1610_UNK_18 (1 << 18)  // 0x00040000, 送信に失敗している間だけ立つ
#define E8B8E1610_UNK_19 (1 << 19)  // 0x00080000, 同上, FUN_081e4cb4 の送信ぶん
#define E8B8E1610_UNK_22 (1 << 22)  // 0x00400000, FUN_081e3cc0 が立てる

extern u32 u32_0300481c;  // src/time.c

bool8 LinkShopManager_IsFinished(void);                    // src/link_shop.c
bool32 IsWeaponSellable(slot32_t n);                       // src/weapon.c
u8 Save_SwitchSlot(void);                                  // src/savedata.c
bool8 LinkShopManager_Send(s32* args, s32 kind, u32 tag);  // src/link_shop.c
void LinkShopManager_SetOwner(void* owner);
void LinkShopManager_SetCallbacks(void (*onRecv)(s32, unknown*), void (*onFinish)(void), void (*onSendDone)(Entity8B8E*));
extern u32 gFrameCounter;
void FUN_081e6388(Entity8B8E* p);
void FUN_081e4484(Entity8B8E* p);
void FUN_081e44b4(Entity8B8E* p);
void FUN_081e44d0(Entity8B8E* p);
void FUN_081e6458(Entity8B8E* p);
void FUN_081e64cc(Entity8B8E* p);
void FUN_081e5290(Entity8B8E* p);
void FUN_081e4d04(Entity8B8E* p);

static inline void Entity8B8E_SetFlags1610(Entity8B8E* p, u32 bits) { p->unk_1610 |= bits; }

// 更新関数を差し替えて状態番号を入れる
static inline void Entity8B8E_SetState(Entity8B8E* p, Entity8B8EFunc* fn, u8 state) {
  p->updateCallback = fn;
  p->unk_1614 = 1;
  p->unk_1616 = state;
}

// 推測: u8[18][4]
const u8 u8_ARRAY_085ae404[72] = {
    0x0C, 0x04, 0x10, 0x01, 0x0D, 0x05, 0x00, 0x02, 0x0E, 0x06, 0x01, 0x03, 0x0F, 0x07, 0x02, 0x10, 0x00, 0x08, 0x10, 0x05, 0x01, 0x09, 0x04, 0x06, 0x02, 0x0A, 0x05, 0x07, 0x03, 0x0B, 0x06, 0x10, 0x04, 0x0C, 0x10, 0x09,
    0x05, 0x0D, 0x08, 0x0A, 0x06, 0x0E, 0x09, 0x0B, 0x07, 0x0F, 0x0A, 0x10, 0x08, 0x00, 0x11, 0x0D, 0x09, 0x01, 0x0C, 0x0E, 0x0A, 0x02, 0x0D, 0x0F, 0x0B, 0x03, 0x0E, 0x11, 0x11, 0x11, 0x03, 0x00, 0x10, 0x10, 0x0F, 0x0C,
};  // 0x085AE404

NAKED void FUN_081e2628(s32 param_1) { INCFUNC("asm/func/FUN_081e2628.inc"); }

NAKED void FUN_081e275c(s32 param_1) { INCFUNC("asm/func/FUN_081e275c.inc"); }

NAKED void FUN_081e27f0(s32 param_1) { INCFUNC("asm/func/FUN_081e27f0.inc"); }

NAKED void FUN_081e2960(s32 param_1) { INCFUNC("asm/func/FUN_081e2960.inc"); }

NAKED void FUN_081e2b08(s32 param_1) { INCFUNC("asm/func/FUN_081e2b08.inc"); }

NAKED void FUN_081e2c14(s32 param_1) { INCFUNC("asm/func/FUN_081e2c14.inc"); }

NAKED void FUN_081e2cdc(s32 param_1) { INCFUNC("asm/func/FUN_081e2cdc.inc"); }

void FUN_081e2d98(Entity8B8E* p) {
  p->sprites[17].flags |= SPRFLAG_HIDDEN;
  p->sprites[18].flags |= SPRFLAG_HIDDEN;
  p->sprites[19].flags |= SPRFLAG_HIDDEN;
  p->sprites[20].flags |= SPRFLAG_HIDDEN;
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

void FUN_081e2dd8(Entity8B8E* p) {
  p->sprites[17].flags |= SPRFLAG_HIDDEN;
  p->sprites[16].flags |= SPRFLAG_HIDDEN;
  p->sprites[18].flags |= SPRFLAG_HIDDEN;
  p->sprites[19].flags |= SPRFLAG_HIDDEN;
  p->sprites[20].flags |= SPRFLAG_HIDDEN;
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_081e2e24(s32 param_1) { INCFUNC("asm/func/FUN_081e2e24.inc"); }

NAKED s32 FUN_081e2e84(s32 param_1) { INCFUNC("asm/func/FUN_081e2e84.inc"); }

NAKED void FUN_081e2ee8(s32 param_1) { INCFUNC("asm/func/FUN_081e2ee8.inc"); }

NAKED void FUN_081e32d8(s32 param_1) { INCFUNC("asm/func/FUN_081e32d8.inc"); }

NAKED void FUN_081e3444(s32 param_1) { INCFUNC("asm/func/FUN_081e3444.inc"); }

NAKED void FUN_081e3594(s32 param_1) { INCFUNC("asm/func/FUN_081e3594.inc"); }

NAKED void FUN_081e3680(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e3680.inc"); }

void FUN_081e36e8(Entity8B8E* p) {
  FUN_081e3680(p);
  p->unk_15e2 = 0;
  ClearMemory(p->unk_15bc, sizeof(p->unk_15bc));
}

void FUN_081e3714(Entity8B8E* p) {
  p->unk_15e7 = 3;
  p->unk_15e8[0] = 9;
  p->unk_15e8[1] = 9;
  p->unk_15e8[2] = 9;
  p->unk_15e8[3] = 9;
  ClearMemory(p->unk_15ec, sizeof(p->unk_15ec));
}

// 4桁ぶんの数字を10進の値に組み直す
s32 FUN_081e3758(Entity8B8E* p) { return p->unk_15ec[0] + p->unk_15ec[1] * 10 + p->unk_15ec[2] * 100 + p->unk_15ec[3] * 1000; }

NAKED void FUN_081e37a0(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_081e37a0.inc"); }

NAKED void FUN_081e3958(s32 param_1, unknown* param_2) { INCFUNC("asm/func/FUN_081e3958.inc"); }

void FUN_081e3cc0(Entity8B8E* p) { Entity8B8E_SetFlags1610(p, E8B8E1610_UNK_22); }

void FUN_081e3cd4(void) {
  Taiyo_Enable();
  u32_0300481c = 0;
}

NAKED void FUN_081e3ce8(s32 param_1) { INCFUNC("asm/func/FUN_081e3ce8.inc"); }

NAKED void FUN_081e3d78(s32 param_1) { INCFUNC("asm/func/FUN_081e3d78.inc"); }

NAKED void FUN_081e3dec(s32 param_1) { INCFUNC("asm/func/FUN_081e3dec.inc"); }

// 選んでいる枠と違う枠に中身があるかを返す
// 命令数は一致 (20/20) だが, 原典は return 0 のブロックを先に置いて return 1 へ飛ばす
// agbcc は return 1 を先に置く (FUN_080ce4f0 と同じ)
NON_MATCH s32 FUN_081e3e78(Entity8B8E* p) {
#ifdef NONMATCHING_C
  if (p->unk_161a != p->selectedSlot && IsWeaponSellable(p->unk_161a)) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081e3e78.inc");
#endif
}

NAKED void FUN_081e3ea8(s32 param_1) { INCFUNC("asm/func/FUN_081e3ea8.inc"); }

NAKED void FUN_081e3f0c(s32 param_1) { INCFUNC("asm/func/FUN_081e3f0c.inc"); }

void FUN_081e3fac(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < p->spriteCount; i++) {
    p->sprites[i + 22].flags &= ~SPRFLAG_HIDDEN;
  }
}

void FUN_081e3fe0(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < p->spriteCount; i++) {
    p->sprites[i + 22].flags |= SPRFLAG_HIDDEN;
  }
}

s32 FUN_081e4014(Entity8B8E* p) {
  Vec3 pos;

  pos.x = 0, pos.y = 0x80, pos.z = 0;
  return MainSprite_Add(&p->sprite_150c, &p->gfx_156c, 0xD0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 0, &pos);
}

NAKED void FUN_081e4054(s32 param_1) { INCFUNC("asm/func/FUN_081e4054.inc"); }

NAKED void FUN_081e41e4(s32 param_1) { INCFUNC("asm/func/FUN_081e41e4.inc"); }

// 立っている枠のスプライトだけ見せる
void FUN_081e4354(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->items[i].active) {
      p->sprites2[i].flags &= ~SPRFLAG_HIDDEN;
    }
  }
}

NAKED void FUN_081e4388(s32 param_1) { INCFUNC("asm/func/FUN_081e4388.inc"); }

void FUN_081e4450(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < 18; i++) {
    p->sprites2[i].flags |= SPRFLAG_HIDDEN;
  }
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

void FUN_081e4484(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites2); i++) {
    MainSprite_Remove(&p->sprites2[i]);
  }
  MainSprite_Remove(&p->sprite_150c);
}

void FUN_081e44b4(Entity8B8E* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites); i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

NAKED void FUN_081e44d0(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e44d0.inc"); }

NAKED void FUN_081e4544(s32 param_1) { INCFUNC("asm/func/FUN_081e4544.inc"); }

// BG の (x, y) にあたるタイルマップのエントリを返す
BgMapEntry* FUN_081e45e4(s32 bg, u32 x, u32 y) {
  BgState* st = &gBgStates[bg];
  BgMapEntry* map = st->tilemap;

  return map + (x & 0x1F) + (y & 0x1F) * 32;
}

// value を divisor から順に10進の桁へ分解して BG3 の (x, y) から書き出す
// 命令数は一致 (28/28) だが value と divisor に割り当たるレジスタが入れ替わる
NON_MATCH void FUN_081e4604(s32 value, s32 divisor, u32 x, u32 y) {
#ifdef NONMATCHING_C
  s32 base = 3;
  BgMapEntry* entry = FUN_081e45e4(base, x, y);

  while (divisor > 0) {
    s32 digit = Div(value, divisor);

    *entry = digit + base;
    entry++;
    value -= divisor * digit;
    divisor = Div(divisor, 10);
  }
#else
  INCFUNC("asm/func/FUN_081e4604.inc");
#endif
}

// 指定BGのタイルマップの (x, y) から width × height を value で塗る
void FUN_081e4644(u32 x, s32 y, s32 width, s32 height, s32 value, u32 bgIdx) {
  s32 i;

  for (i = 0; i < height; i++) {
    BgMapEntry* dst = FUN_081e45e4(bgIdx, x, y + i);
    s32 j;

    for (j = 0; j < width; j++) {
      *dst = value;
      dst++;
    }
  }
}

NAKED s32 FUN_081e468c(s32 param_1, unknown* param_2, u32 param_3) { INCFUNC("asm/func/FUN_081e468c.inc"); }

NAKED void FUN_081e47c4(s32 param_1) { INCFUNC("asm/func/FUN_081e47c4.inc"); }

NAKED void FUN_081e4838(s32 param_1) { INCFUNC("asm/func/FUN_081e4838.inc"); }

NAKED void FUN_081e4948(s32 param_1) { INCFUNC("asm/func/FUN_081e4948.inc"); }

NAKED void FUN_081e49a8(s32 param_1) { INCFUNC("asm/func/FUN_081e49a8.inc"); }

NAKED void FUN_081e4a60(s32 param_1) { INCFUNC("asm/func/FUN_081e4a60.inc"); }

NAKED s32 FUN_081e4ab8(s32 param_1) { INCFUNC("asm/func/FUN_081e4ab8.inc"); }

// 命令数は一致 (27/27) だが, unk_1614 への 1 を置くレジスタとアドレスのレジスタが入れ替わる
// Tier C 試済: fn/state の宣言順の入れ替え / Entity8B8E_SetState を使わず直書き
NON_MATCH void FUN_081e4b68(Entity8B8E* p, u32 slot) {
#ifdef NONMATCHING_C
  Entity8B8EFunc* fn;
  u8 state;

  if (p->unk_162c == slot && Save_SwitchSlot()) {
    fn = FUN_081e6388;
    state = 0x18;
  } else {
    fn = FUN_081e6458;
    state = 0x19;
  }
  Entity8B8E_SetState(p, fn, state);
#else
  INCFUNC("asm/func/FUN_081e4b68.inc");
#endif
}

void FUN_081e4bb8(Entity8B8E* p) { Entity8B8E_SetState(p, FUN_081e6458, 0x19); }

// セーブ枠が一致していれば通信ショップの受け手を自分に向ける, 違っていれば状態 0x1C へ飛ばす
void FUN_081e4bdc(Entity8B8E* p, u32 slot) {
  if (p->unk_162c != slot) {
    Entity8B8E_SetState(p, FUN_081e64cc, 0x1C);
  } else {
    FUN_081e5290(p);
    LinkShopManager_SetOwner(p);
    LinkShopManager_SetCallbacks(FUN_081e3958, FUN_081e3cd4, FUN_081e3cc0);
    FUN_081e4d04(p);
  }
}

void FUN_081e4c40(Entity8B8E* p) { Entity8B8E_SetState(p, FUN_081e64cc, 0x1C); }

// 命令数は一致 (30/30) だが, unk_1610 のロードとプール定数の置き場所が1命令ずれる
NON_MATCH void FUN_081e4c64(Entity8B8E* p, s32 param_2) {
#ifdef NONMATCHING_C
  s32 payload = param_2;

  p->unk_1610 &= ~E8B8E1610_UNK_22;
  if (!LinkShopManager_Send(&payload, 10, gFrameCounter)) {
    p->unk_1610 |= E8B8E1610_UNK_18;
  } else {
    p->unk_1610 &= ~E8B8E1610_UNK_18;
  }
#else
  INCFUNC("asm/func/FUN_081e4c64.inc");
#endif
}

// 命令数は一致 (29/29) だが, unk_1610 のロードとプール定数の置き場所が1命令ずれる (FUN_081e4c64 と同じ)
NON_MATCH void FUN_081e4cb4(Entity8B8E* p, s32* args, s32 kind) {
#ifdef NONMATCHING_C
  p->unk_1610 &= ~E8B8E1610_UNK_22;
  if (!LinkShopManager_Send(args, kind, p->sendTag)) {
    p->unk_1610 |= E8B8E1610_UNK_19;
  } else {
    p->unk_1610 &= ~E8B8E1610_UNK_19;
  }
#else
  INCFUNC("asm/func/FUN_081e4cb4.inc");
#endif
}

NAKED void FUN_081e4d04(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e4d04.inc"); }

NAKED void FUN_081e4de0(s32 param_1) { INCFUNC("asm/func/FUN_081e4de0.inc"); }

NAKED void FUN_081e4edc(s32 param_1) { INCFUNC("asm/func/FUN_081e4edc.inc"); }

void FUN_081e5290(Entity8B8E* p) {
  if (p->unk_1628 != 0) {
    VM_ExecByID(p->unk_1628, NULL);
  }
}

NAKED void FUN_081e52ac(s32 param_1) { INCFUNC("asm/func/FUN_081e52ac.inc"); }

NAKED void FUN_081e53e8(s32 param_1) { INCFUNC("asm/func/FUN_081e53e8.inc"); }

NAKED void FUN_081e564c(s32 param_1) { INCFUNC("asm/func/FUN_081e564c.inc"); }

NAKED void FUN_081e57f4(s32 param_1) { INCFUNC("asm/func/FUN_081e57f4.inc"); }

NAKED void FUN_081e58dc(s32 param_1) { INCFUNC("asm/func/FUN_081e58dc.inc"); }

NAKED void FUN_081e5c40(s32 param_1) { INCFUNC("asm/func/FUN_081e5c40.inc"); }

NAKED void FUN_081e5d14(s32 param_1) { INCFUNC("asm/func/FUN_081e5d14.inc"); }

NAKED void FUN_081e5dc8(s32 param_1) { INCFUNC("asm/func/FUN_081e5dc8.inc"); }

NAKED void FUN_081e603c(s32 param_1) { INCFUNC("asm/func/FUN_081e603c.inc"); }

NAKED void FUN_081e60c8(s32 param_1) { INCFUNC("asm/func/FUN_081e60c8.inc"); }

NAKED void FUN_081e617c(unknown* param_1) { INCFUNC("asm/func/FUN_081e617c.inc"); }

NAKED void FUN_081e6388(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e6388.inc"); }

NAKED void FUN_081e6458(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e6458.inc"); }

NAKED void FUN_081e64cc(Entity8B8E* p) { INCFUNC("asm/func/FUN_081e64cc.inc"); }

NAKED void FUN_081e653c(s32 param_1) { INCFUNC("asm/func/FUN_081e653c.inc"); }

NAKED void FUN_081e66e0(s32 param_1) { INCFUNC("asm/func/FUN_081e66e0.inc"); }

NAKED void FUN_081e676c(s32 param_1) { INCFUNC("asm/func/FUN_081e676c.inc"); }

NAKED void FUN_081e6810(s32 param_1) { INCFUNC("asm/func/FUN_081e6810.inc"); }

NAKED void FUN_081e6a2c(s32 param_1) { INCFUNC("asm/func/FUN_081e6a2c.inc"); }

NAKED void FUN_081e6b5c(s32 param_1) { INCFUNC("asm/func/FUN_081e6b5c.inc"); }

NAKED void FUN_081e6f28(s32 param_1) { INCFUNC("asm/func/FUN_081e6f28.inc"); }

NAKED void FUN_081e7414(s32 param_1) { INCFUNC("asm/func/FUN_081e7414.inc"); }

NAKED void FUN_081e78d0(s32 param_1) { INCFUNC("asm/func/FUN_081e78d0.inc"); }

NAKED void FUN_081e7a38(unknown* param_1) { INCFUNC("asm/func/FUN_081e7a38.inc"); }

NAKED void FUN_081e7ac4(s32 param_1) { INCFUNC("asm/func/FUN_081e7ac4.inc"); }

NAKED void FUN_081e7bfc(s32 param_1) { INCFUNC("asm/func/FUN_081e7bfc.inc"); }

NAKED void FUN_081e7db4(s32 param_1) { INCFUNC("asm/func/FUN_081e7db4.inc"); }

NAKED void FUN_081e7fd0(s32 param_1) { INCFUNC("asm/func/FUN_081e7fd0.inc"); }

NAKED void FUN_081e80ac(s32 param_1) { INCFUNC("asm/func/FUN_081e80ac.inc"); }

NAKED void FUN_081e8110(unknown* param_1) { INCFUNC("asm/func/FUN_081e8110.inc"); }

NAKED s32 Entity8B8E_Update(Entity8B8E* p) { INCFUNC("asm/func/Entity8B8E_Update.inc"); }

s32 Entity8B8E_Destroy(Entity8B8E* p) {
  bool8 finished;

  FUN_081e44d0(p);
  FUN_081e44b4(p);
  FUN_081e4484(p);
  finished = LinkShopManager_IsFinished();
  if (finished == 0) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Taiyo_Enable();
    u32_0300481c = 0;
    if (p->exitScriptID != 0) {
      VM_ExecByID(p->exitScriptID, NULL);
    }
  }
  return 1;
}

NAKED s32 Entity8B8E_Init(Entity8B8E* p) { INCFUNC("asm/func/Entity8B8E_Init.inc"); }

Entity8B8E* Entity8B8E_Create(void) {
  Entity8B8E* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity8B8E));

  if (p != NULL) {
    SetEntityRoutine(p, Entity8B8E_Update, Entity8B8E_Destroy);
    if (Entity8B8E_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
