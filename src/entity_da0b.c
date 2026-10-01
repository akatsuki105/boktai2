#include "camera.h"
#include "entity.h"
#include "global.h"
#include "sound.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "struct.h"
#include "vm.h"
#include "weapon.h"

s32 FUN_0824175c(void);
s32 GetWeaponSkillLevel(s32 idx);
s32 FUN_08049f84(void);

typedef struct EntityDA0B EntityDA0B;
typedef void(EntityDA0BFunc)(EntityDA0B* p);

// 武器一覧の1枠, 武器データとその絵を1組で持つ
typedef struct {
  WeaponData data;    // 0x00, FUN_0801bf88 が (WeaponData*)(p + slot * 0x84 + 0x138) として引く
  MainSprite sprite;  // 0x24, FUN_0801c4bc が追加し FUN_0801c4b0 が消す
} EntityDA0BElem;
static_assert(sizeof(EntityDA0BElem) == 132);

// 武器の付け替えメニュー
struct EntityDA0B {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  Vec3 pos;                      // 0x0018, '.p' の x, y, z, FUN_0823b8ac に渡す
  Vec3 pos2;                     // 0x0020, pos の写し
  u8 unk_28[0x3C - 0x28];        // 0x0028, まだ未解析
  bool8 fnChanged;               // 0x003C, EntityDA0B_SetFn が立て EntityDA0B_TakeFnChanged が読んで落とす, fn に入った最初の1フレームの目印
  u8 cursor;                     // 0x003D, 選択中の weapons の添字
  u8 unk_3e;                     // 0x003E, FUN_0801c910 が 0 を入れる
  u8 unk_3f[0x44 - 0x3F];        // 0x003F, まだ未解析
  u32 fnTimer;                   // 0x0044, fn に入ってからのフレーム数, EntityDA0B_SetFn が 0 に戻す
  u32* tilemap;                  // 0x0048, TILEMAP_9F57
  rgb555* bgPltt;                // 0x004C, BGP_A41A
  u32 selectable;                // 0x0050, 選べる武器スロットのビットマスク, FUN_0801c910 が作る
  u8 unk_54[0x65 - 0x54];        // 0x0054, まだ未解析
  bool8 unk_65;                  // 0x0065, FUN_0801dfe4 が読んで落とす1フレームの目印
  u8 unk_66[0x6C - 0x66];        // 0x0066, まだ未解析
  s32 unk_6c;                    // 0x006C, _Update が毎フレーム FUN_0824175c の戻り値を入れる
  u8 unk_70[0x80 - 0x70];        // 0x0070, まだ未解析
  s32 unk_80;                    // 0x0080, FUN_0801d420 が >> 5 して sprites2[2]/[3] の x にする
  u8 unk_84[0x92 - 0x84];        // 0x0084, まだ未解析
  u8 unk_92;                     // 0x0092, FUN_0801e00c がスクリプトへ返す値 (既定 2)
  u8 unk_93;                     // 0x0093, sprites2[0] の表示位置 (x)
  u8 unk_94;                     // 0x0094, まだ未解析
  u8 unk_95;                     // 0x0095, FUN_0801c910 が 0 を入れる
  u8 unk_96[0xB8 - 0x96];        // 0x0096, まだ未解析
  u16 unk_b8;                    // 0x00B8, '.c' の値
  u16 unk_ba;                    // 0x00BA, '.e' の値
  char statText[4];              // 0x00BC, FUN_08094c6c が武器の補正値を "+12" / "SP" の形で書く
  u8 unk_c0[0xD8 - 0xC0];        // 0x00C0, まだ未解析
  MainSpriteGfx gfx0;            // 0x00D8, SPRITE_UI_MISC
  MainSpriteGfx gfx1;            // 0x00F8, SPRITE_UI_START_MENU
  MainSpriteGfx gfx2;            // 0x0118, SPRITE_INVENTORY_ICONS
  EntityDA0BElem weapons[19];    // 0x0138, FUN_0801c5d0 が stride 0x84 で19個まわす, 前の16個が武器スロット
  MainSprite sprites0[3];        // 0x0B04, [0] がカーソル
  MainSprite sprites1[4];        // 0x0C24, FUN_0801c3a8 が gStat->registeredWeapon の位置に置く
  MainSprite iconSprite;         // 0x0DA4, 選択中の武器の絵
  MainSprite sprites2[13];       // 0x0E04, FUN_0801d084 が追加し FUN_0801d6a0 が消す
  u8 unk_12e4[0x1304 - 0x12E4];  // 0x12E4, まだ未解析
  EntityDA0BFunc* fn;            // 0x1304, _Update が毎フレーム呼ぶ, EntityDA0B_SetFn が差し替える
  u8* unk_1308;                  // 0x1308, '.w' の FUN_0823d340 の戻り値, TextBox_Start に渡す
  u8* unk_130c;                  // 0x130C, '.k' の FUN_0823d340 の戻り値, VM_ParseStringRef に渡す
  bool8 unk_1310;                // 0x1310, FUN_0801d7f8 が立て FUN_0801d7d8 が読んで落とす1フレームの目印
  u8 unk_1311[3];                // 0x1311, まだ未解析
  u32 unk_1314;                  // 0x1314, FUN_0801d7f8 が 0 に戻す
  s32 unk_1318;                  // 0x1318, FUN_0801d7f8 が受け取った値
  s16 unk_131c;                  // 0x131C, '.n' の値 (既定 0xB156)
  u16 unk_131e;                  // 0x131E, _Init が 5 を入れる
  u8 unk_1320[0x1364 - 0x1320];  // 0x1320, まだ未解析
};
static_assert(sizeof(EntityDA0B) == 4964);

IWRAM_DATA EntityDA0B* gEntityDA0B = NULL;  // 0x03000098

void FUN_0801cbc4(EntityDA0B* p);
void FUN_0801dcdc(EntityDA0B* p);
void FUN_0801d71c(EntityDA0B* p);
void FUN_0801db1c(EntityDA0B* p);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);

void EntityDA0B_ClearPtr(void) { gEntityDA0B = NULL; }

// パレット番号を 0x2DF 番からの並びとして OBJ パレットの先頭を返す
rgb555* FUN_0801b670(s32 plttID) { return &gObjPlttData[(plttID + 0x2DF) * 16]; }

void FUN_0801b688(EntityDA0B* p, EntityDA0BElem* elem) { MainSprite_SetPose(&elem->sprite, &p->gfx2, elem->data.id, 0); }

// 武器スキルレベルを 6..15 の表示用の値に直す
s32 FUN_0801b6a4(s32 idx) {
  s32 lv = Div(GetWeaponSkillLevel(idx), 10) + 6;

  if (lv < 6) {
    lv = 6;
  } else if (lv > 15) {
    lv = 15;
  }

  return lv;
}

NAKED WeaponData* weapon_0801b6c4(u32 kind, u32 lv) { INCFUNC("asm/func/weapon_0801b6c4.inc"); }

NAKED WeaponData* FUN_0801b730(s32 param_1) { INCFUNC("asm/func/FUN_0801b730.inc"); }

void EntityDA0B_SetFn(EntityDA0B* p, EntityDA0BFunc* fn) {
  p->fnTimer = 0;
  p->fnChanged = TRUE;
  p->fn = fn;
}

// fn に入った最初の1フレームかどうかを返し、目印を落とす
bool32 EntityDA0B_TakeFnChanged(EntityDA0B* p) {
  if (p->fnChanged) {
    p->fnChanged = FALSE;
    return TRUE;
  }

  return FALSE;
}

// 武器のランクを 20 刻みの値に直す, C=20 B=40 A=60 S=80 それ以外は 0
s32 FUN_0801b904(EntityDA0B* p, EntityDA0BElem* elem) {
  switch (elem->data.rank) {
    case 0: {
      return 20;
    }
    case 1: {
      return 40;
    }
    case 2: {
      return 60;
    }
    case 3: {
      return 80;
    }
  }

  return 0;
}

NAKED unknown* FUN_0801b938(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801b938.inc"); }

NAKED unknown* FUN_0801ba58(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801ba58.inc"); }

NAKED unknown* FUN_0801bb78(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801bb78.inc"); }

unknown* FUN_0801bc98(EntityDA0B* p) {
  EntityDA0BElem* e = &p->weapons[18];

  switch (e->data.kind) {
    case 0: {
      return FUN_0801b938(p);
    }
    case 1: {
      return FUN_0801ba58(p);
    }
    case 2: {
      return FUN_0801bb78(p);
    }
  }

  return NULL;
}

NAKED void FUN_0801bcd8(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801bcd8.inc"); }

NAKED void FUN_0801bf88(EntityDA0B* p, char* text) { INCFUNC("asm/func/FUN_0801bf88.inc"); }

NAKED void FUN_0801c01c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c01c.inc"); }

void FUN_0801c0d8(bool32 param_1, s32 kind) {
  switch (kind) {
    case 0: {
      PlaySound_082406e0(0x394);
      break;
    }
    case 1: {
      PlaySound_082406e0(0x395);
      break;
    }
    case 2: {
      PlaySound_082406e0(0x396);
      break;
    }
  }
}

NAKED s32 FUN_0801c114(EntityDA0B* p, s32 param_2) { INCFUNC("asm/func/FUN_0801c114.inc"); }

NAKED void FUN_0801c188(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c188.inc"); }

NAKED s32 FUN_0801c204(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c204.inc"); }

NAKED s32 FUN_0801c260(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c260.inc"); }

s32 FUN_0801c2bc(EntityDA0B* p) {
  Vec3 pos;

  pos.x = 0, pos.y = 0x80, pos.z = 0;
  MainSprite_Add(&p->iconSprite, &p->gfx2, 0xD0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
}

NAKED s32 FUN_0801c300(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c300.inc"); }

NAKED s32 FUN_0801c3a8(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c3a8.inc"); }

s32 FUN_0801c40c(EntityDA0B* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_AdvanceAnim(&p->sprites0[i], &p->gfx1);
  }
}

s32 FUN_0801c434(EntityDA0B* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->sprites0[i]);
  }
}

s32 FUN_0801c454(EntityDA0B* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->sprites1[i]);
  }
}

s32 FUN_0801c474(EntityDA0B* p) { MainSprite_Remove(&p->iconSprite); }

s32 FUN_0801c488(EntityDA0B* p, EntityDA0BElem* elem, WeaponData* data, Vec3* pos) {
  elem->data = *data;
  FUN_0801b688(p, elem);
  elem->sprite.pos = *pos;
}

s32 FUN_0801c4b0(EntityDA0BElem* elem) { MainSprite_Remove(&elem->sprite); }

NAKED s32 FUN_0801c4bc(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c4bc.inc"); }

NAKED s32 FUN_0801c518(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c518.inc"); }

s32 FUN_0801c5d0(EntityDA0B* p) {
  s32 i;

  for (i = 0; i < 19; i++) {
    FUN_0801c4b0(&p->weapons[i]);
  }
}

void FUN_0801c5f0(EntityDA0B* p) {
  if (p->unk_3e <= 1) {
    PlaySound_082406e0(0xDD);
    EntityDA0B_SetFn(p, FUN_0801cbc4);
  }
}

NAKED void FUN_0801c614(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c614.inc"); }

NAKED void FUN_0801c70c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c70c.inc"); }

void FUN_0801c7bc(EntityDA0BElem* dst, EntityDA0BElem* src, u32 val) {
  dst->data = src->data;
  FUN_0822f588(&dst->sprite, &src->sprite, val);
}

NAKED s32 FUN_0801c7dc(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c7dc.inc"); }

NAKED s32 FUN_0801c910(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c910.inc"); }

NAKED void FUN_0801c9e4(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801c9e4.inc"); }

NAKED void FUN_0801cbc4(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801cbc4.inc"); }

NAKED void FUN_0801ccd4(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801ccd4.inc"); }

void FUN_0801cec0(EntityDA0B* p) {
  if (EntityDA0B_TakeFnChanged(p)) {
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
  }

  if (p->fnTimer == 20) {
    if (p->unk_b8 != 0) {
      VM_ExecByID(p->unk_b8, NULL);
    }
  } else {
    FUN_0801c7dc(p);
    p->fnTimer++;
  }
}

NAKED void FUN_0801cf18(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801cf18.inc"); }

NON_MATCH void FUN_0801d01c(EntityDA0B* p) {
#ifdef NONMATCHING_C
  EntityDA0BElem* e = p->weapons;
  s32 i;

  for (i = 0; i < 19; i++) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
    e++;
  }

  for (i = 0; i < 3; i++) {
    p->sprites0[i].flags |= SPRFLAG_HIDDEN;
  }

  for (i = 0; i < 4; i++) {
    p->sprites1[i].flags |= SPRFLAG_HIDDEN;
  }

  MainSprite_Hide(&p->iconSprite);
#else
  INCFUNC("asm/func/FUN_0801d01c.inc");
#endif
}

NAKED s32 FUN_0801d084(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d084.inc"); }

NAKED s32 FUN_0801d0e0(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d0e0.inc"); }

NAKED void FUN_0801d338(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d338.inc"); }

NAKED void FUN_0801d394(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d394.inc"); }

// 2枚のスプライトを unk_80 を挟むように左右へ置き, 画面内 (0..0xB0) に丸めてから表示する
void FUN_0801d420(EntityDA0B* p) {
  s32 x = p->unk_80 >> 5;
  MainSprite* spr = &p->sprites2[2];

  spr->pos.x = x - 0x18;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }

  MainSprite_Show(spr);

  spr = &p->sprites2[3];
  spr->pos.x = x + 0x18;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }

  MainSprite_Show(spr);
}

NON_MATCH void FUN_0801d488(EntityDA0B* p) {
#ifdef NONMATCHING_C
  MainSprite_Hide(&p->sprites2[2]);
  MainSprite_Hide(&p->sprites2[3]);
#else
  INCFUNC("asm/func/FUN_0801d488.inc");
#endif
}

void FUN_0801d4a8(EntityDA0B* p) {
  MainSprite* spr = &p->sprites2[0];

  spr->pos.x = p->unk_93;
  MainSprite_Show(spr);
}

void FUN_0801d4c4(EntityDA0B* p) {
  MainSprite* spr = &p->sprites2[0];

  spr->pos.x = p->unk_93;
  MainSprite_Hide(spr);
}

NAKED s32 FUN_0801d4dc(EntityDA0B* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0801d4dc.inc"); }

NAKED s32 FUN_0801d540(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d540.inc"); }

s32 FUN_0801d6a0(EntityDA0B* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    MainSprite_Remove(&p->sprites2[i]);
  }
}

void FUN_0801d6c0(EntityDA0B* p) {
  if (EntityDA0B_TakeFnChanged(p)) {
    FUN_0823ce68(1, 5, 4, 4, 4, 0xFFFF, 0);
  }

  if (p->fnTimer > 31) {
    FUN_0801d01c(p);
    FUN_08049f84();
    EntityDA0B_SetFn(p, FUN_0801d71c);
  } else {
    FUN_0801c7dc(p);
    p->fnTimer++;
  }
}

NAKED void FUN_0801d71c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d71c.inc"); }

void FUN_0801d788(EntityDA0B* p) {
  if (EntityDA0B_TakeFnChanged(p)) {
    FUN_0801d4dc(p, 3, 0, 0);
  }

  if (p->fnTimer > 239) {
    EntityDA0B_SetFn(p, FUN_0801db1c);
  } else {
    if (Mod(p->fnTimer, 61) == 60) {
      PlaySound_082406e0(0x21C);
    }

    FUN_0801d540(p);
    p->fnTimer++;
  }
}

bool32 FUN_0801d7d8(EntityDA0B* p) {
  if (p->unk_1310) {
    p->unk_1310 = FALSE;
    return TRUE;
  }

  return FALSE;
}

void FUN_0801d7f8(EntityDA0B* p, s32 param_2) {
  p->unk_1318 = param_2;
  p->unk_1310 = TRUE;
  p->unk_1314 = 0;
}

NAKED void FUN_0801d81c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d81c.inc"); }

NAKED void FUN_0801d8cc(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801d8cc.inc"); }

NAKED void FUN_0801da7c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801da7c.inc"); }

NAKED void FUN_0801db1c(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801db1c.inc"); }

void FUN_0801dc90(EntityDA0B* p) {
  if (EntityDA0B_TakeFnChanged(p)) {
    FUN_0801d4dc(p, 9, 0, 0);
    sound_08240264(0xA9);
  }

  FUN_0801d540(p);
  FUN_0823b8ac(&p->pos);
  if (p->fnTimer > 29) {
    EntityDA0B_SetFn(p, FUN_0801dcdc);
  } else {
    p->fnTimer++;
  }
}

NAKED void FUN_0801dcdc(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801dcdc.inc"); }

NAKED void FUN_0801dd84(EntityDA0B* p) { INCFUNC("asm/func/FUN_0801dd84.inc"); }

void FUN_0801dfb0(EntityDA0B* p) {
  p->fnTimer++;
  if (p->fnTimer == 60 && p->unk_ba != 0) {
    FUN_0801c01c(p);
  } else {
    FUN_0801d540(p);
    FUN_0823b8ac(&p->pos);
  }
}

// 目印が立っていれば落として TRUE を返す, Entity が無ければ FALSE
bool32 FUN_0801dfe4(void) {
  if (gEntityDA0B == NULL) return FALSE;

  if (gEntityDA0B->unk_65) {
    gEntityDA0B->unk_65 = FALSE;
    return TRUE;
  }

  return FALSE;
}

s32 FUN_0801e00c(void) {
  if (gEntityDA0B == NULL) return 2;
  return gEntityDA0B->unk_92;
}

s32 EntityDA0B_Update(EntityDA0B* p) {
  p->unk_6c = FUN_0824175c();
  p->fn(p);
  return 0;
}

s32 EntityDA0B_Destroy(EntityDA0B* p) {
  FUN_0801c5d0(p);
  FUN_0801c434(p);
  FUN_0801c454(p);
  FUN_0801c474(p);
  FUN_0801d6a0(p);
  FUN_08049f84();
  gEntityDA0B = NULL;
  return 0;
}

NAKED s32 EntityDA0B_Init(EntityDA0B* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/EntityDA0B_Init.inc"); }

EntityDA0B* EntityDA0B_Create(s32 param_1, s32 param_2) {
  EntityDA0B* p;

  if (gEntityDA0B != NULL) {
    return gEntityDA0B;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(EntityDA0B));
  if (p != NULL) {
    SetEntityRoutine(p, EntityDA0B_Update, EntityDA0B_Destroy);
    if (EntityDA0B_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
