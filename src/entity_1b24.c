#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

// 通信販売(相手と武器の売り買いをする, 実質的なアイテム交換機能) or 通信対戦の武器選択 の画面?
// gEntity9A9F の記録から相手の武器を読み、36枚のスプライトで並べる
typedef struct Entity1B24 {
  Entity e;                                    // 0x000, ENTITY_UNK_8
  u8* record;                                  // 0x018, &gEntity9A9F->unk_15c, セッションが無ければ NULL で _Init は失敗する
  Tilemaps* tilemap;                           // 0x01C, TILEMAP_CD91, BG2 に敷く
  rgb555* pltt;                                // 0x020, GetBgPlttFile("bg_link_col_arr")
  void* unk_24;                                // 0x024, ワードとして読まれるが用途不明
  MainSpriteGfx gfx[4];                        // 0x028
  MainSprite sprites[36];                      // 0x0A8, Entity1B24_Destroy がまとめて外す
  ShopCursor cursor;                           // 0xE28
  ShopFlyingPair flying;                       // 0xE58, 選んだ武器を飛ばす表示部品
  WeaponData weaponData;                       // 0xF4C, record[0x40] が 2 なら GUN_DEL_HELL を直接書き、そうでなければ GetWeaponData(slot, &weaponData)
  s8 slot;                                     // 0xF70, record[0x17], 負なら武器を読まない
  u8 weaponKindMask;                           // 0xF71, GetWeaponKind(slot) を16スロット分見て bit0..3 を立てる, record[0x40] が 2 なら 0xF
  u16 unk_f72;                                 // 0xF72, FUN_0809ce90 が状態遷移のたびに 0 を入れる
  u32 unk_f74;                                 // 0xF74, _Init が 0x1E を入れる
  s8 unk_f78[8];                               // 0xF78
  s32 unk_f80;                                 // 0xF80
  void* unk_f84;                               // 0xF84, FUN_0809ce90 が GetFile の戻り値か 0 を入れる
  void* unk_f88;                               // 0xF88, 同上
  void (*updateCallback)(struct Entity1B24*);  // 0xF8C
} Entity1B24;
static_assert(sizeof(Entity1B24) == 3984);

bool32 FUN_081dfa04(void);
void FUN_081dfa20(u32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility);
void GetWeaponData(slot32_t n, WeaponData* data);
void FUN_08094d1c(u8* param_1, s8* param_2);
void MainMenu_SetWeaponMarquee(unknown* w, u8* pc);
s32 GetWeaponWearPose(WeaponData* w);

// gEntity9A9F の記録を返す, セッションが無ければ NULL
static inline u8* Entity9A9F_GetRecord(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return NULL;
  }
  return p->unk_15c;
}

// 状態関数を差し替える
void FUN_0809ce90(Entity1B24* p, void* fn) {
  p->updateCallback = fn;
  p->unk_f72 = 0;
}

// カーソルが指す武器の見た目と説明を出す, 空欄なら消す
void FUN_0809cea8(Entity1B24* p) {
  WeaponData w;

  if (p->record[0x40] == 2) {
    if ((u8)p->cursor.slot == 0) {
      MessageWindow_SetInstant(1);
      MessageWindow_Start(p->unk_24);
      MessageWindow_SetRect(2, 16, 28, 2);
      FUN_08094d1c((u8*)&p->weaponData, p->unk_f78);
      MainMenu_SetWeaponMarquee(&p->weaponData, p->unk_24);
    } else {
      p->sprites[17].flags |= SPRFLAG_HIDDEN;
      MessageWindow_Close();
      Marquee_Clear();
    }
  } else if (GetWeaponID((u8)p->cursor.slot) == WEAPON_NONE) {
    p->sprites[17].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    GetWeaponData((u8)p->cursor.slot, &w);
    p->sprites[17].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[17], &p->gfx[1], GetWeaponWearPose(&w), 1);
    MessageWindow_SetInstant(1);
    MessageWindow_Start(p->unk_24);
    MessageWindow_SetRect(2, 16, 28, 2);
    FUN_08094d1c((u8*)&w, p->unk_f78);
    MainMenu_SetWeaponMarquee(&w, p->unk_24);
  }
}

// そのスロットの武器が一覧に並べられるものかを返す
bool32 FUN_0809cf98(s32 slot) {
  weapon32_t id = GetWeaponID(slot);

  if (id == WEAPON_NONE || id == WEAPON_BROKEN_GUN || id == WEAPON_STAR_PIECE || id == WEAPON_ASTRO_SWORD || id == WEAPON_ASTRO_SPEAR || id == WEAPON_ASTRO_HAMMER) {
    return FALSE;
  }
  return TRUE;
}

// 武器種ごとの表示用の値を作る
s32 FUN_0809cfc0(Entity1B24* p, WeaponData* w) {
  switch (w->kind) {
    case WK_SWORD:
    case WK_SPEAR:
    case WK_HAMMER: {
      return ((p->unk_f80 + 0x63) >> 1) + w->atk + w->quality;
    }
    case WK_GUN: {
      return ((Div(0x28, 10) - 8) * 5 + w->atk) * 2;
    }
  }
  return 0;
}

NAKED void FUN_0809d00c(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d00c.inc"); }

void FUN_0809d230(Entity1B24* p) {
  MessageWindow_Close();
  Marquee_Clear();
}

// 一覧の n 番目のセルの画面座標を求める
void FUN_0809d240(s16* pos, s32 n) {
  if (n <= 15) {
    pos[0] = (n & 3) * 24 + 144;
    pos[1] = (n >> 2) * 24 + 32;
  } else {
    pos[0] = 64;
    pos[1] = 76;
  }
}

// カーソルの武器を一覧の外の枠へ飛ばすアニメを仕込む
void FUN_0809d270(Entity1B24* p) {
  WorldPos from[2];
  WorldPos to[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  anims[0] = GetWeaponID((u8)p->cursor.slot);
  strIDs[0] = 0x2DF;
  FUN_0809d240(&from[0].x, p->slot);
  FUN_0809d240(&to[0].x, 16);
  unk1[1] = 0;
  anims[1] = 0;
  strIDs[1] = 0x2DF;
  VEC3_SET(from[1], 0, 0, 0);
  VEC3_SET(to[1], 0, 0, 0);
  FUN_080b9a28(&p->flying, unk1, from, to, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 交換に出す自分の武器 (slot) の欄を描き直す, 選んでいなければ消す
void FUN_0809d300(Entity1B24* p) {
  if (p->slot < 0) {
    p->sprites[16].flags |= SPRFLAG_HIDDEN;
    p->sprites[20].flags |= SPRFLAG_HIDDEN;
    p->sprites[19].flags |= SPRFLAG_HIDDEN;
    return;
  }

  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
  if (p->record[0x40] == 2) {
    MainSprite_SetPose(&p->sprites[16], &p->gfx[1], WEAPON_GUN_DEL_HELL, 1);
  } else {
    MainSprite_SetPose(&p->sprites[16], &p->gfx[1], GetWeaponID(p->slot), 1);
  }
  p->sprites[20].flags &= ~SPRFLAG_HIDDEN;
  FUN_0809d240(&p->sprites[20].pos.x, p->slot);
  p->sprites[19].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
}

NAKED void FUN_0809d3d0(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d3d0.inc"); }

void FUN_0809d7a4(Entity1B24* p) {
  if (FUN_080b9adc(&p->flying)) {
    PlaySound_082406e0(SE_EQUIP);
    FUN_0809d300(p);
    FUN_0809d00c(p);
    FUN_0809ce90(p, FUN_0809d3d0);
  }
}

s32 Entity1B24_Update(Entity1B24* p) {
  if (!FUN_081dfa04()) {
    s32 i;

    Marquee_CloseGlobal();
    for (i = 0; i < 36; i++) {
      p->sprites[i].flags |= SPRFLAG_HIDDEN;
    }
    KillEntity((Entity*)p);
    return -1;
  }
  p->updateCallback(p);
  return 0;
}

s32 Entity1B24_Destroy(Entity1B24* p) {
  s32 i;

  for (i = 0; i < 36; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  FUN_080b9a0c(&p->flying.pair);
  return 0;
}

// タイルマップ上の (x, y) のセルを指す
u16* FUN_0809d858(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  u16* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

const char s_bg_link_col_arr_08251d6c[] = "bg_link_col_arr";

// BG2 にタイルマップを敷き, 相手が持っていない武器種の欄を塗りつぶして, 背景パレットを作業用バッファへ流す
void FUN_0809d878(Entity1B24* p) {
  s32 bgIndices[1];
  s32 i;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  bgIndices[0] = 6;
  Video_SetupBGLayout(2, 0, p->tilemap, 0, 0, 1, bgIndices);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  for (i = 0; i < 4; i++) {
    if (!((p->weaponKindMask >> i) & 1)) {
      u16* cell = FUN_0809d858(3, (i & 1) * 6 + 2, (i >> 1) + 4);
      s32 j;

      for (j = 0; j < 2; j++) {
        *cell++ = 1;
      }
    }
  }
  p->pltt = GetBgPlttFile(HashName(s_bg_link_col_arr_08251d6c))->body;
  CpuCopy32(p->pltt, gBgPlttBuffer, 96);
}

NAKED void FUN_0809d934(Entity1B24* p) { INCFUNC("asm/func/FUN_0809d934.inc"); }

void FUN_0809dd34(Entity1B24* p) {
  ShopCursor_Init(&p->cursor, 0, 0, 0, 30);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[18]);
}

void FUN_0809dd68(Entity1B24* p) {
  if (VM_SeekToNamedArg('w')) {
    p->unk_24 = VM_GetPC_Proxy();
  }
  FUN_0809cea8(p);
}

void FUN_0809dd88(Entity1B24* p) {
  if (VM_SeekToNamedArg('p')) {
    p->unk_f84 = (void*)VM_GetValue();
  } else {
    p->unk_f84 = NULL;
  }
  if (VM_SeekToNamedArg('n')) {
    p->unk_f88 = (void*)VM_GetValue();
  } else {
    p->unk_f88 = NULL;
  }
}

// 相手が持っている武器の種別ビットを集める
void FUN_0809dde0(Entity1B24* p) {
  if (p->record[0x40] == 2) {
    p->weaponKindMask = 0xF;
  } else {
    s32 i;

    p->weaponKindMask = 0;
    for (i = 0; i < 16; i++) {
      s32 kind = GetWeaponKind(i);

      if (kind == WK_SWORD) {
        p->weaponKindMask |= 1;
      } else if (kind == WK_SPEAR) {
        p->weaponKindMask |= 2;
      } else if (kind == WK_HAMMER) {
        p->weaponKindMask |= 4;
      } else if (kind == WK_GUN) {
        p->weaponKindMask |= 8;
      }
    }
  }
}

s32 Entity1B24_Init(Entity1B24* p) {
  s32 vitality;
  s32 spirit;
  s32 agility;

  p->record = Entity9A9F_GetRecord();
  if (p->record == NULL) {
    return -1;
  }

  if (p->record[0x40] == 2) {
    p->slot = 0;
    p->weaponData = gWeaponDB[WEAPON_GUN_DEL_HELL];
  } else {
    p->slot = p->record[0x17];
    if (p->slot >= 0) {
      GetWeaponData(p->slot, &p->weaponData);
    }
  }

  FUN_081dfa20(p->record[0x41], &p->unk_f80, &vitality, &spirit, &agility);
  FUN_0809dde0(p);
  FUN_0809d878(p);
  FUN_0809d934(p);
  FUN_0809dd34(p);
  FUN_0809dd68(p);
  FUN_0809dd88(p);
  p->unk_f74 = 30;
  FUN_0809ce90(p, FUN_0809d3d0);
  return 0;
}

// 0x1B24
Entity1B24* Entity1B24_Create(u32 subroutineID) {
  Entity1B24* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity1B24));

  if (p != NULL) {
    SetEntityRoutine(p, Entity1B24_Update, Entity1B24_Destroy);
    if (Entity1B24_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
