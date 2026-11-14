#include "bg_pltt.h"
#include "camera.h"
#include "eff_scatter.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "item.h"
#include "menu.h"
#include "msgbus.h"
#include "player.h"
#include "puff.h"
#include "random.h"
#include "shop.h"
#include "solar.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

// 太陽鍛治

// 武器一覧の1枠, 武器データとその絵を1組で持つ
typedef struct {
  WeaponData data;    // 0x00, Forge_ShowWeaponInfo が (WeaponData*)(p + slot * 0x84 + 0x138) として引く
  MainSprite sprite;  // 0x24, Forge_AddWeaponSprites が追加し FUN_0801c4b0 が消す
} ForgeWeapon;
static_assert(sizeof(ForgeWeapon) == 132);

// スプライト1枚ぶんの表示状態 ("GREAT", "GOOD", "BAD")
typedef struct {
  u16 state;  // 0x00
  u16 timer;  // 0x02
} StrikeRating;

typedef struct Forge {
  Entity e;                               // 0x0000, ENTITY_UNK_11
  Vec3 pos;                               // 0x0018, '.p' の x, y, z, Camera_MoveTo に渡す
  Vec3 pos2;                              // 0x0020, pos の写し
  Vec3 startPos;                          // 0x0028, カメラの移動元
  Vec3 endPos;                            // 0x0030, カメラの移動先
  u8 unk_38[3];                           // 0x0038, まだ未解析
  bool8 unk_3b;                           // 0x003B
  bool8 fnChanged;                        // 0x003C, Forge_SetFn が立て Forge_TakeFnChanged が読んで落とす, updateCallback に入った最初の1フレームの目印
  u8 cursor;                              // 0x003D, 選択中の weapons の添字
  u8 unk_3e;                              // 0x003E, Forge_OpenList が 0 を入れる
  u8 unk_3f;                              // 0x003F, まだ未解析
  u8 unk_40;                              // 0x0040
  u8 slots[2];                            // 0x0041, 素材に選んだ weapons の添字
  u8 unk_43;                              // 0x0043
  u32 fnTimer;                            // 0x0044, updateCallback に入ってからのフレーム数, Forge_SetFn が 0 に戻す
  Tilemaps* tilemap;                      // 0x0048, TILEMAP_9F57
  rgb555* bgPltt;                         // 0x004C, BGP_A41A
  u32 selectable;                         // 0x0050, 選べる武器スロットのビットマスク, Forge_OpenList が作る
  Vec3 slotPos;                           // 0x0054, 素材を飛ばす先
  s16 unk_5c;                             // 0x005C
  s16 unk_5e;                             // 0x005E
  s16 unk_60;                             // 0x0060
  s16 unk_62;                             // 0x0062
  u8 unk_64;                              // 0x0064
  bool8 unk_65;                           // 0x0065, FUN_0801dfe4 が読んで落とす1フレームの目印
  u8 unk_66;                              // 0x0066, ratings の次に使う添字
  u8 unk_67;                              // 0x0067, まだ未解析
  s32 unk_68;                             // 0x0068
  s32 sunGauge;                           // 0x006C
  s32 unk_70;                             // 0x0070
  u8 unk_74[0x7C - 0x74];                 // 0x0074, まだ未解析
  s32 unk_7c;                             // 0x007C
  s32 unk_80;                             // 0x0080, FUN_0801d420 が >> 5 して sprites2[2]/[3] の x にする
  s32 unk_84;                             // 0x0084
  s32 unk_88;                             // 0x0088
  s32 unk_8c;                             // 0x008C
  u8 unk_90;                              // 0x0090
  bool8 unk_91;                           // 0x0091
  u8 unk_92;                              // 0x0092, FUN_0801e00c がスクリプトへ返す値 (既定 2)
  u8 unk_93;                              // 0x0093, sprites2[0] の表示位置 (x)
  Dir8U8 unk_94;                          // 0x0094, まだ未解析
  u8 unk_95;                              // 0x0095, Forge_OpenList が 0 を入れる
  u8 unk_96[2];                           // 0x0096, まだ未解析
  u32 unk_98;                             // 0x0098
  u8 unk_9c[4];                           // 0x009C, まだ未解析
  u32 unk_a0;                             // 0x00A0
  s32 unk_a4;                             // 0x00A4
  s32 unk_a8;                             // 0x00A8
  s32 unk_ac;                             // 0x00AC
  s32 unk_b0;                             // 0x00B0
  s32 unk_b4;                             // 0x00B4
  u16 unk_b8;                             // 0x00B8, '.c'
  u16 unk_ba;                             // 0x00BA, '.e'
  char statText[4];                       // 0x00BC, WeaponData_FormatSuffix が武器の補正値を "+12" / "SP" の形で書く
  u8 unk_c0[4];                           // 0x00C0, まだ未解析
  StrikeRating ratings[5];                // 0x00C4, sprites2[8..12] の表示状態, 鍛治の一叩きの結果を表示するためのポップアップ
  MainSpriteGfx gfx0;                     // 0x00D8, SPRITE_UI_MISC
  MainSpriteGfx gfx1;                     // 0x00F8, SPRITE_UI_START_MENU
  MainSpriteGfx iconGfx;                  // 0x0118, SPRITE_INVENTORY_ICONS
  ForgeWeapon weapons[16];                // 0x0138, 武器スロットの16個
  ForgeWeapon materials[2];               // 0x0978, 素材に選んだ2個
  ForgeWeapon result;                     // 0x0A80, 鍛治の結果
  MainSprite sprites0[3];                 // 0x0B04, [0] がカーソル
  MainSprite sprites1[4];                 // 0x0C24, Forge_ShowRegisteredMarks が gStat->registeredWeapon の位置に置く
  MainSprite iconSprite;                  // 0x0DA4, 選択中の武器の絵
  MainSprite sprites2[13];                // 0x0E04, SPRITE_UI_MISC (gfx0), [8..12] は ratings が出すポーズ (UI_FORGE_GREAT, UI_FORGE_GOOD, UI_FORGE_BAD)
  rgb555 unk_12e4[16];                    // 0x12E4, sprites2[5] が使うパレット
  void (*updateCallback)(struct Forge*);  // 0x1304
  u8* unk_1308;                           // 0x1308, '.w' の VM_GetPC_Proxy の戻り値, MessageWindow_Start に渡す
  u8* unk_130c;                           // 0x130C, '.k' の VM_GetPC_Proxy の戻り値, VM_ParseStringRef に渡す
  bool8 unk_1310;                         // 0x1310, Forge_SetSubFn が立て Forge_TakeSubFnChanged が読んで落とす1フレームの目印
  u8 unk_1311[3];                         // 0x1311, まだ未解析
  u32 unk_1314;                           // 0x1314, Forge_SetSubFn が 0 に戻す
  void (*subCallback)(struct Forge*);     // 0x1318
  s16 unk_131c;                           // 0x131C, '.n=0xB156'
  u16 unk_131e;                           // 0x131E, _Init が 5 を入れる
  MsgPacket msg;                          // 0x1320
  u8 unk_132c[0x1364 - 0x132C];           // 0x132C, msg.args の続き
} Forge;
static_assert(sizeof(Forge) == 4964);

IWRAM_DATA Forge* gForge = NULL;  // 0x03000098

void Forge_UpdatePlaceMaterial(Forge* p);
void Forge_UpdateFinish(Forge* p);
void Forge_UpdateList(Forge* p);
void Forge_UpdateConfirm(Forge* p);
void FUN_0801cec0(Forge* p);
void Forge_UpdateCannotForge(Forge* p);
void Forge_SubCharge(Forge* p);
void Forge_SubHammer(Forge* p);
void FUN_0801dfb0(Forge* p);
void FUN_0801d6c0(Forge* p);
void FUN_0801dc90(Forge* p);
void Forge_SubCool(Forge* p);
void Forge_UpdateAward(Forge* p);
void GetWeaponData(slot32_t n, WeaponData* data);
void Video_DrawBGNumber(s32 bg, s32 x, s32 y, u32 n, u32 baseTile, s32 digits, u32 pltt);
void FUN_0801d71c(Forge* p);
void Forge_UpdateSmithing(Forge* p);
void FUN_0801d788(Forge* p);
void FUN_0807c7c8(Player* p, s32 mode);
void Entity99CA_CreateAt(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
s32 ItemIconPopupManager_AddIcon(s32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key);
void FUN_0807bbb0(Player* p, s32 param_2, u32 scriptID);
void RemoveWeapon(slot32_t n);
bool32 AddWeapon(WeaponData* data);
const WeaponData* ReadWeaponDB(s32 idx);
void MainMenu_SetWeaponMarquee(unknown* w, u8* pc);

// 武器スキルと素材の組み合わせからRランクの武器ができるかを判定する
static inline bool8 RollRareWeapon(Forge* p, ForgeWeapon* e) {
  s32 lv = GetWeaponSkillLevel(e->data.kind);
  s32 rand = Mod(Random() + (gFrameCounter >> 2), 100);
  s32 chance = lv >> 3;
  bool8 ok;

  if (p->unk_a0 < 15) {
    chance = 0;
  } else if (p->unk_a8 == p->unk_a0) {
    chance <<= 1;
  }

  ok = FALSE;
  if (rand <= chance) {
    ok = TRUE;
  }

  return ok;
}

static inline s32 Forge_ClampTo99(s32 v) {
  if (v > 99) {
    v = 99;
  } else if (v < 0) {
    v = 0;
  }

  return v;
}

static inline void Vec3_CopyOffsetX(Vec3* src, Vec3* dst, s32 dx) {
  *dst = *src;
  dst->x += dx;
}

void Forge_ClearPtr(void) { gForge = NULL; }

// パレット番号を 735 番からの並びとして OBJ パレットの先頭を返す
rgb555* Forge_GetObjPltt(s32 plttID) { return &gObjPlttData[(plttID + 735) * 16]; }

void FUN_0801b688(Forge* p, ForgeWeapon* elem) { MainSprite_SetPose(&elem->sprite, &p->iconGfx, ICON_WEAPON(elem->data.id), PLAYMODE_PAUSE); }

// 武器スキルレベルを 6..15 の表示用の値に直す
s32 Forge_GetSkillQuality(s32 idx) {
  s32 lv = Div(GetWeaponSkillLevel(idx), 10) + 6;

  if (lv < 6) {
    lv = 6;
  } else if (lv > 15) {
    lv = 15;
  }

  return lv;
}

const WeaponData* Forge_FindWeapon(s32 kind, s32 lv) {
  const WeaponData* best = &gWeaponDB[WEAPON_GRADIUS];
  s32 bestLv = 0;
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 66; i++) {
    const WeaponData* w = &gWeaponDB[i];

    if (w->kind == kind && w->rank != 4 && w->lv <= lv && w->lv >= bestLv) {
      best = w;
      bestLv = w->lv;
      found = TRUE;
    }
  }

  if (!found) {
    switch (kind) {
      case WK_SPEAR: {
        return &gWeaponDB[WEAPON_STAFF];
      }
      case WK_HAMMER: {
        return &gWeaponDB[WEAPON_POUNDER];
      }
      case WK_SWORD:
      default: {
        return &gWeaponDB[WEAPON_DULL_BLADE];
      }
    }
  }

  return best;
}

// レジスタ割当の残差のみ (Mod の結果を r0 に残して式を r1 で組む形にならない), 185/187 命令
NON_MATCH WeaponData* Forge_ComputeResult(Forge* p) {
#ifdef NONMATCHING_C
  const WeaponData* w;
  ForgeWeapon* a = &p->materials[0];
  ForgeWeapon* b = &p->materials[1];
  ForgeWeapon* r = &p->result;
  s32 lv;
  s32 kind;
  s32 rnd;

  if (a->data.kind == b->data.kind) {
    if (a->data.id == b->data.id) {
      lv = (a->data.lv + b->data.lv) >> 1;
      if (lv > 99) {
        lv = 99;
      } else if (lv < 1) {
        lv = 1;
      }
      r->data.id = a->data.id;
      r->data.kind = a->data.kind;
      r->data.rank = a->data.rank;
      r->data.lv = lv;
      r->data.atk = a->data.atk;
      r->data.wear = gWeaponDB[r->data.id].wear;
      r->data.durability = gWeaponDB[r->data.id].durability;
      p->unk_43 = 0;
    } else {
      lv = ((a->data.lv + b->data.lv) >> 1) + 6;
      if (lv > 99) {
        lv = 99;
      } else if (lv < 1) {
        lv = 1;
      }
      w = Forge_FindWeapon(a->data.kind, lv);
      r->data.id = w->id;
      r->data.kind = w->kind;
      r->data.rank = w->rank;
      r->data.lv = lv;
      r->data.atk = w->atk;
      r->data.wear = w->wear;
      r->data.durability = gWeaponDB[w->id].durability;
      p->unk_43 = 1;
    }
  } else {
    rnd = Mod(Random(), 13);
    lv = ((a->data.lv + b->data.lv) >> 1) - 6 + rnd;
    if (lv > 99) {
      lv = 99;
    } else if (lv < 1) {
      lv = 1;
    }
    if (a->data.kind == WK_SWORD) {
      kind = b->data.kind == WK_SPEAR ? WK_HAMMER : WK_SPEAR;
    } else if (a->data.kind == WK_SPEAR) {
      kind = b->data.kind == WK_SWORD ? WK_HAMMER : WK_SWORD;
    } else if (a->data.kind == WK_HAMMER) {
      kind = WK_SPEAR;
      if (b->data.kind != WK_SWORD) {
        kind = WK_SWORD;
      }
    } else {
      kind = WK_SWORD;
    }
    w = Forge_FindWeapon(kind, lv);
    r->data.id = w->id;
    r->data.kind = w->kind;
    r->data.rank = w->rank;
    r->data.lv = lv;
    r->data.atk = w->atk;
    r->data.wear = w->wear;
    r->data.durability = gWeaponDB[w->id].durability;
    p->unk_43 = 2;
  }

  r->data.quality = (a->data.quality + b->data.quality) >> 1;
#else
  INCFUNC("asm/func/Forge_ComputeResult.inc");
#endif
}

void Forge_SetFn(Forge* p, void* fn) {
  p->fnTimer = 0;
  p->fnChanged = TRUE;
  p->updateCallback = fn;
}

// updateCallback に入った最初の1フレームかどうかを返し、目印を落とす
bool32 Forge_TakeFnChanged(Forge* p) {
  if (p->fnChanged) {
    p->fnChanged = FALSE;
    return TRUE;
  }

  return FALSE;
}

// 武器のランクを 20 刻みの値に直す, C=20 B=40 A=60 S=80 それ以外は 0
s32 Forge_GetRankPrice(Forge* p, ForgeWeapon* elem) {
  switch (elem->data.rank) {
    case 0:
      return 20;
    case 1:
      return 40;
    case 2:
      return 60;
    case 3:
      return 80;
  }

  return 0;
}

unknown* Forge_UpgradeSword(Forge* p) {
  ForgeWeapon* e = &p->result;
  ForgeWeapon* a = &p->materials[0];
  ForgeWeapon* b = &p->materials[1];

  if (p->unk_a0 == 0 || (u32)p->unk_b0 > 9) {
    p->unk_98 = 0;
    return (unknown*)&gWeaponDB[WEAPON_DULL_BLADE];
  }

  // Rランク
  if (((a->data.id == WEAPON_SOLAR_SWORD && b->data.id == WEAPON_DARK_SWORD) || (b->data.id == WEAPON_SOLAR_SWORD && a->data.id == WEAPON_DARK_SWORD)) && p->unk_60 > 9) {
    // グラム は 太陽の剣 と 暗黒の剣 からしか作れない(特殊処理)
    p->unk_98 = 200;
    return (unknown*)&gWeaponDB[WEAPON_GRAM];
  } else if (RollRareWeapon(p, e)) {  // 汎用Rランク
    switch (e->data.rank) {
      case 1: {
        p->unk_98 = 80;
        return (unknown*)&gWeaponDB[WEAPON_KATANA];
      }
      case 2: {
        p->unk_98 = 120;
        return (unknown*)&gWeaponDB[WEAPON_MURAMASA];
      }
      case 3: {
        p->unk_98 = 160;
        return (unknown*)&gWeaponDB[WEAPON_DARK_SWORD];
      }
    }
  }

  return NULL;
}

unknown* Forge_UpgradeSpear(Forge* p) {
  ForgeWeapon* e = &p->result;
  ForgeWeapon* a = &p->materials[0];
  ForgeWeapon* b = &p->materials[1];

  if (p->unk_a0 == 0 || (u32)p->unk_b0 > 9) {
    p->unk_98 = 0;
    return (unknown*)&gWeaponDB[WEAPON_STAFF];
  }

  if (((a->data.id == WEAPON_WHITE_QUEEN && b->data.id == WEAPON_BLACK_QUEEN) || (b->data.id == WEAPON_WHITE_QUEEN && a->data.id == WEAPON_BLACK_QUEEN)) && p->unk_60 > 9) {
    p->unk_98 = 200;
    return (unknown*)&gWeaponDB[WEAPON_GUNGNIR];
  } else if (RollRareWeapon(p, e)) {
    switch (e->data.rank) {
      case 1: {
        p->unk_98 = 80;
        return (unknown*)&gWeaponDB[WEAPON_RUNE_GLAIVE];
      }
      case 2: {
        p->unk_98 = 120;
        return (unknown*)&gWeaponDB[WEAPON_RUNE_SPEAR];
      }
      case 3: {
        p->unk_98 = 160;
        return (unknown*)&gWeaponDB[WEAPON_BLACK_QUEEN];
      }
    }
  }

  return NULL;
}

unknown* Forge_UpgradeHammer(Forge* p) {
  ForgeWeapon* e = &p->result;
  ForgeWeapon* a = &p->materials[0];
  ForgeWeapon* b = &p->materials[1];

  if (p->unk_a0 == 0 || (u32)p->unk_b0 > 9) {
    p->unk_98 = 0;
    return (unknown*)&gWeaponDB[WEAPON_POUNDER];
  }

  if (((a->data.id == WEAPON_DAYBREAK && b->data.id == WEAPON_TWILIGHT) || (b->data.id == WEAPON_DAYBREAK && a->data.id == WEAPON_TWILIGHT)) && p->unk_60 > 9) {
    p->unk_98 = 200;
    return (unknown*)&gWeaponDB[WEAPON_MJOLLNIR];
  } else if (RollRareWeapon(p, e)) {
    switch (e->data.rank) {
      case 1: {
        p->unk_98 = 80;
        return (unknown*)&gWeaponDB[WEAPON_HEAVY_MACE];
      }
      case 2: {
        p->unk_98 = 120;
        return (unknown*)&gWeaponDB[WEAPON_HEAVY_AXE];
      }
      case 3: {
        p->unk_98 = 160;
        return (unknown*)&gWeaponDB[WEAPON_TWILIGHT];
      }
    }
  }

  return NULL;
}

unknown* Forge_UpgradeResult(Forge* p) {
  ForgeWeapon* e = &p->result;

  switch (e->data.kind) {
    case WK_SWORD: {
      return Forge_UpgradeSword(p);
    }
    case WK_SPEAR: {
      return Forge_UpgradeSpear(p);
    }
    case WK_HAMMER: {
      return Forge_UpgradeHammer(p);
    }
  }

  return NULL;
}

// 306/305 命令, inherited と count をスタックに置く形が合わない
NON_MATCH void Forge_Finish(Forge* p) {
#ifdef NONMATCHING_C
  WeaponData* data = &p->result.data;
  bool32 inherited = FALSE;
  WeaponData w1;
  WeaponData w2;
  u32* count;
  WeaponData* w;

  p->unk_98 = Forge_GetRankPrice(p, &p->result);
  w = Forge_UpgradeResult(p);
  if (w != NULL) {
    *data = *w;
  }

  count = &p->unk_a0;
  if (*count >= 5 && p->unk_a8 != 0) {
    s32 rate = (GetWeaponSkillLevel(p->result.data.kind) >> 2) + p->unk_a8 * 3 - p->unk_b0 * 5;

    if (rate > 100) {
      rate = 100;
    } else if (rate < 0) {
      rate = 0;
    }

    if (rate < Mod(RandomNext(), 100)) {
      *(u8*)&data->effects[0] = 0;
    } else {
      const WeaponData* base = ReadWeaponDB(data->id);

      if ((base->effects[0] & 0xFF) == 0) {
        *(u8*)&data->effects[0] = 0;
      } else {
        inherited = TRUE;
        data->effects[0] = base->effects[0];
      }
    }

    if (rate < Mod(RandomNext(), 100)) {
      *(u8*)&data->effects[1] = 0;
    } else {
      GetWeaponData(p->slots[0], &w1);
      if ((w1.effects[0] & 0xFF) == 0 || (w1.effects[0] & 0xFF) == (u8)data->effects[0]) {
        *(u8*)&data->effects[1] = 0;
      } else {
        data->effects[1] = w1.effects[0];
        inherited = TRUE;
      }
    }

    if (rate < Mod(RandomNext(), 100)) {
      *(u8*)&data->effects[2] = 0;
    } else {
      GetWeaponData(p->slots[1], &w2);
      if ((w2.effects[0] & 0xFF) == 0 || (w2.effects[0] & 0xFF) == (u8)data->effects[0] || (w2.effects[0] & 0xFF) == (u8)data->effects[1]) {
        *(u8*)&data->effects[2] = 0;
      } else {
        data->effects[2] = w2.effects[0];
        inherited = TRUE;
      }
    }
  }

  if (inherited) {
    data->quality = 0;
  } else {
    s32 div;
    s32 quality;
    s32 i;

    if (*count < 10) {
      div = 2;
    } else if (*count < 15) {
      div = 3;
    } else if (*count < 20) {
      div = 8;
    } else if (*count < 25) {
      div = 15;
    } else if (*count < 30) {
      div = 25;
    } else {
      div = 40;
    }

    quality = Forge_GetSkillQuality(data->kind);
    quality = (quality - Div(*count * 100 - p->unk_a4, div) + data->quality) >> 1;
    if (*count < 5) {
      quality = -10;
    } else if (*count < 10 && quality > 0) {
      quality = 0;
    }

    if (quality < -10) {
      data->quality = -10;
    } else if (quality > 10) {
      data->quality = 10;
    } else {
      data->quality = quality;
    }

    for (i = 0; i < 3; i++) {
      *(u8*)&data->effects[i] = 0;
    }
  }

  RemoveWeapon(p->slots[0]);
  RemoveWeapon(p->slots[1]);
  CopyMemory(data->PS, gStat->name, 10);
  data->PS[10] = 0;
  AddWeapon(data);
  gStat->forge++;
  if ((s16)gStat->forge > 9999) {
    gStat->forge = 9999;
  }
  FUN_0801b688(p, &p->result);
#else
  INCFUNC("asm/func/Forge_Finish.inc");
#endif
}

void Forge_ShowWeaponInfo(Forge* p, char* text) {
  ForgeWeapon* w = &p->weapons[p->cursor];

  MessageWindow_Start(p->unk_1308);
  WeaponData_ShowNameInWindow((u8*)w, (s8*)p->statText);
  if (w->data.id != WEAPON_NONE) {
    s32 pose;

    MainMenu_SetWeaponMarquee(w, p->unk_1308);
    pose = GetWeaponWearPose(&w->data);
    MainSprite_Show(&p->iconSprite);
    MainSprite_SetPose(&p->iconSprite, &p->iconGfx, pose, PLAYMODE_PAUSE);
  } else {
    if (text == NULL) {
      Marquee_Clear();
    } else {
      Marquee_SetText(text);
    }
    MainSprite_Hide(&p->iconSprite);
  }
}

void Forge_RunResultScript(Forge* p) {
  u32 argv[10];
  ScriptArgs sa;
  ForgeWeapon* e = &p->result;
  s32 i;

  argv[0] = e->data.id;
  argv[1] = e->data.kind;
  argv[2] = e->data.rank;
  argv[3] = e->data.lv;
  argv[4] = e->data.quality;
  argv[5] = 0;
  for (i = 0; i < 3; i++) {
    if (*(u8*)&p->result.data.effects[i] != 0) {
      argv[5]++;
    }
  }
  argv[6] = Forge_ClampTo99(p->unk_a8);
  argv[7] = Forge_ClampTo99(p->unk_ac);
  argv[8] = Forge_ClampTo99(p->unk_b0);
  argv[9] = p->unk_98;
  sa.argc = 10, sa.argv = argv;
  VM_ExecByID(p->unk_ba, &sa);
}

void PlayForgeStrikeSE(u32 _, s32 kind) {
  switch (kind) {
    case 0: {
      PlaySound_082406e0(SE_FORGE_STRIKE_GREAT);
      break;
    }
    case 1: {
      PlaySound_082406e0(SE_FORGE_STRIKE_GOOD);
      break;
    }
    case 2: {
      PlaySound_082406e0(SE_FORGE_STRIKE_BAD);
      break;
    }
  }
}

s32 Forge_SetupBg(Forge* p, s32 param_2) {
  Tilemaps* tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  BgPlttFile* pltt;

  p->tilemap = tilemap;
  Video_SetupBGLayout(0, 0, tilemap, 0, 0, 1, &param_2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  pltt = GetBgPlttFile(BGP_A41A);
  p->bgPltt = pltt->body;
  CpuCopy16(&pltt->body[208], &gBgPlttBuffer[208], 48 * sizeof(rgb555));
  return 0;
}

void Forge_MoveConfirmCursor(Forge* p) {
  if ((gInput[0].pressed & DPAD_LEFT) && p->unk_40 == 1) {
    p->unk_40 = 0;
    MainSprite_SetAnim(&p->sprites0[2], &p->gfx1, 4, PLAYMODE_LOOP, 0);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }

  if ((gInput[0].pressed & DPAD_RIGHT) && p->unk_40 == 0) {
    p->unk_40 = 1;
    MainSprite_SetAnim(&p->sprites0[2], &p->gfx1, 5, PLAYMODE_LOOP, 0);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }
}

s32 Forge_AddCursors(Forge* p) {
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites0[i], &p->gfx1, 60, SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

s32 Forge_AddRegisteredMarks(Forge* p) {
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites1[i], &p->gfx1, 65, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

s32 FUN_0801c2bc(Forge* p) {
  Vec3 pos;
  VEC3_SET(pos, 0, 128, 0);
  MainSprite_Add(&p->iconSprite, &p->iconGfx, ICON_TIMER_100, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
}

s32 Forge_ShowCursors(Forge* p) {
  MainSprite* sprite;
  MainSpriteGfx* gfx;

  sprite = &p->sprites0[0];
  sprite->pos.x = (p->cursor & 3) * 24 + 144;
  sprite->pos.y = (p->cursor >> 2) * 24 + 32;
  MainSprite_Show(sprite);
  gfx = &p->gfx1;
  MainSprite_SetAnim(sprite, gfx, 0, PLAYMODE_LOOP, 0);

  sprite = &p->sprites0[1];
  sprite->pos.x = 16;
  sprite->pos.y = 40;
  MainSprite_Show(sprite);
  MainSprite_SetPose(sprite, gfx, 60, PLAYMODE_PAUSE);

  sprite = &p->sprites0[2];
  sprite->pos.x = 0;
  sprite->pos.y = 0;
  MainSprite_Hide(sprite);
  MainSprite_SetAnim(sprite, gfx, 4, PLAYMODE_LOOP, 0);
}

s32 Forge_ShowRegisteredMarks(Forge* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite* sprite = &p->sprites1[i];
    s32 slot = gStat->registeredWeapon[i];

    if (slot >= 0) {
      sprite->pos.x = (slot & 3) * 24 + 144;
      sprite->pos.y = (slot >> 2) * 24 + 32;
      MainSprite_Show(sprite);
    } else {
      MainSprite_Hide(sprite);
    }
  }
}

s32 FUN_0801c40c(Forge* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_AdvanceAnim(&p->sprites0[i], &p->gfx1);
  }
}

s32 FUN_0801c434(Forge* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->sprites0[i]);
  }
}

s32 FUN_0801c454(Forge* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->sprites1[i]);
  }
}

s32 FUN_0801c474(Forge* p) { MainSprite_Remove(&p->iconSprite); }

s32 FUN_0801c488(Forge* p, ForgeWeapon* elem, WeaponData* data, Vec3* pos) {
  elem->data = *data;
  FUN_0801b688(p, elem);
  elem->sprite.pos = *pos;
}

s32 FUN_0801c4b0(ForgeWeapon* elem) { MainSprite_Remove(&elem->sprite); }

s32 Forge_AddWeaponSprites(Forge* p) {
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  for (i = 18; i >= 0; i--) {
    MainSprite_Add(&p->weapons[i].sprite, &p->iconGfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

// pos の x, y は1語に詰めて str している, 2要素の struct を値で返す inline にすると命令数は 84/84 に揃うが r10 を余計に使う
NON_MATCH s32 Forge_ShowWeapons(Forge* p) {
#ifdef NONMATCHING_C
  ForgeWeapon* e = p->weapons;
  WeaponData data;
  Vec3 pos;
  s32 i;

  for (i = 0; i < 16; i++) {
    pos.x = (i & 3) * 24 + 144;
    pos.y = (i >> 2) * 24 + 32;
    GetWeaponData(i, &data);
    FUN_0801c488(p, e, &data, &pos);
    if (p->selectable & (1 << i)) {
      e->sprite.plttID = 735;
      e->sprite.pltt = Forge_GetObjPltt(0);
      e->sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      e->sprite.plttID = 736;
      e->sprite.pltt = Forge_GetObjPltt(1);
      if (e->data.id != WEAPON_NONE) {
        e->sprite.flags &= ~SPRFLAG_HIDDEN;
      }
    }
    e++;
  }
#else
  INCFUNC("asm/func/Forge_ShowWeapons.inc");
#endif
}

s32 Forge_RemoveWeaponSprites(Forge* p) {
  s32 i;

  for (i = 0; i < 19; i++) {
    FUN_0801c4b0(&p->weapons[i]);
  }
}

void Forge_SelectWeapon(Forge* p) {
  if (p->unk_3e <= 1) {
    PlaySound_082406e0(SE_SELECT);
    Forge_SetFn(p, Forge_UpdatePlaceMaterial);
  }
}

void Forge_Cancel(Forge* p) {
  MainSprite* sprite = &p->sprites0[1];
  ForgeWeapon* e;

  if (p->unk_3e != 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainSprite_SetAnim(&p->sprites0[0], &p->gfx1, 0, PLAYMODE_LOOP, 0);
    p->unk_3e--;
    e = &p->materials[p->unk_3e];
    e->sprite.flags |= SPRFLAG_HIDDEN;
    if (p->unk_3e == 0) {
      sprite->pos.x = 16;
    } else {
      sprite->pos.x = 64;
    }
    sprite->pos.y = 40;
    p->selectable |= 1 << p->slots[p->unk_3e];
    p->weapons[p->slots[p->unk_3e]].sprite.plttID = 735;
    p->weapons[p->slots[p->unk_3e]].sprite.pltt = Forge_GetObjPltt(0);
    MessageWindow_SetRect(2, 16, 30, 2);
    Forge_ShowWeaponInfo(p, NULL);
    Forge_SetFn(p, Forge_UpdateList);
  } else {
    PlaySound_082406e0(SE_CANCEL);
    Forge_SetFn(p, FUN_0801cec0);
  }
}

// レジスタ割当だけの残差 (&p->result が r6, &p->unk_3b が r5 になるべきところが逆), 72/72 命令
NON_MATCH void Forge_OnMaterialPlaced(Forge* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprites0[1];
  ForgeWeapon* e;
  item32_t id;

  if (p->unk_3e == 0) {
    sprite->pos.x = 64;
  } else {
    sprite->pos.x = 104;
  }
  sprite->pos.y = 40;
  if (++p->unk_3e < 2) {
    Forge_SetFn(p, Forge_UpdateList);
    return;
  }

  e = &p->result;
  Forge_ComputeResult(p);
  p->unk_3b = TRUE;
  if (e->data.rank == 3) {
    switch (e->data.kind) {
      case WK_SWORD: {
        id = ITEM_SPADE_EMBLEM;
        break;
      }
      case WK_SPEAR: {
        id = ITEM_DIAMOND_EMBLEM;
        break;
      }
      case WK_HAMMER: {
        id = ITEM_CLUB_EMBLEM;
        break;
      }
      default: {
        goto check;
      }
    }
    if (!CheckItemOwn(id)) {
      p->unk_3b = FALSE;
    }
  }

check:
  if (!p->unk_3b) {
    Forge_SetFn(p, Forge_UpdateCannotForge);
  } else {
    Forge_SetFn(p, Forge_UpdateConfirm);
  }
#else
  INCFUNC("asm/func/Forge_OnMaterialPlaced.inc");
#endif
}

void FUN_0801c7bc(ForgeWeapon* dst, ForgeWeapon* src, u32 val) {
  dst->data = src->data;
  FUN_0822f588(&dst->sprite, &src->sprite, val);
}

s32 Forge_DrawStats(Forge* p) {
  FUN_080b9400(p->unk_95);
  FUN_080b94cc(p->unk_95);
  Video_DrawBGNumber(0, 4, 9, Forge_ClampTo99(gStat->lv), 33, 2, 15);
  Video_DrawBGNumber(0, 3, 11, Forge_ClampTo99(GetWeaponSkillLevel(WK_SWORD)), 33, 2, 15);
  Video_DrawBGNumber(0, 8, 11, Forge_ClampTo99(GetWeaponSkillLevel(WK_SPEAR)), 33, 2, 15);
  Video_DrawBGNumber(0, 3, 12, Forge_ClampTo99(GetWeaponSkillLevel(WK_HAMMER)), 33, 2, 15);
  Video_DrawBGNumber(0, 8, 12, Forge_ClampTo99(GetWeaponSkillLevel(WK_OTHERS)), 33, 2, 15);
  Video_DrawBGNumber(0, 3, 13, Forge_ClampTo99(GetWeaponSkillLevel(WK_GUN)), 33, 2, 15);
  FUN_0801c40c(p);
}

// 2つ目のループの前で &p->unk_3e と &p->unk_95 を計算している, 局所変数に受けると 85/84 命令まで寄るが movs r6, #1 の位置が合わない
NON_MATCH s32 Forge_OpenList(Forge* p) {
#ifdef NONMATCHING_C
  slot16_t* registered;
  u8* m;
  u8* n;
  s32 i;

  p->selectable = 0;
  for (i = 0; i < 16; i++) {
    s32 id = GetWeaponID(i);

    if (id >= WEAPON_GRADIUS && id <= WEAPON_MJOLLNIR) {
      s32 kind = GetWeaponKind(i);

      if (kind <= WK_HAMMER) {
        p->selectable |= 1 << i;
      }
    }
  }

  n = &p->unk_3e;
  m = &p->unk_95;
  registered = gStat->registeredWeapon;
  for (i = 0; i < 4; i++) {
    if (*registered >= 0) {
      p->selectable &= ~(1 << *registered);
    }
    registered++;
  }

  *n = 0;
  *m = 0;
  ClearBGTilemapBuffer(0);
  Forge_SetupBg(p, 0);
  Forge_ShowCursors(p);
  Forge_ShowRegisteredMarks(p);
  Forge_ShowWeapons(p);
  MessageWindow_Start(p->unk_1308);
  MessageWindow_SetRect(2, 16, 30, 2);
  MessageWindow_SetInstant(TRUE);
  MessageWindow_SetBgPltt(BGP_EFDA);
  Forge_ShowWeaponInfo(p, GetStringByID(VM_ParseStringRef(p->unk_130c)));
#else
  INCFUNC("asm/func/Forge_OpenList.inc");
#endif
}

// r8 までで足りるところ r10 まで使う, 227/223 命令, 方向フラグの持ち方が違う
NON_MATCH void Forge_UpdateList(Forge* p) {
#ifdef NONMATCHING_C
  bool32 up, down, left, right;
  u8* cursorPtr;
  s32 cursor;

  Forge_TakeFnChanged(p);
  if (gInput[0].down & SELECT_BUTTON) {
    if (gInput[0].pressed & A_BUTTON) {
      if (++p->unk_95 > 2) {
        p->unk_95 = 0;
      }
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
    Forge_DrawStats(p);
    p->fnTimer++;
    return;
  }

  cursorPtr = &p->cursor;
  cursor = *cursorPtr;
  up = FALSE;
  down = FALSE;
  left = FALSE;
  right = FALSE;
  if (gInput[0].pressed & DPAD_UP) {
    up = TRUE;
  } else if (gInput[0].pressed & DPAD_DOWN) {
    down = TRUE;
  } else if (gInput[0].pressed & DPAD_LEFT) {
    left = TRUE;
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    right = TRUE;
  } else if (p->unk_3f >= 8) {
    if (gInput[0].down & DPAD_UP) {
      up = TRUE;
    } else if (gInput[0].down & DPAD_DOWN) {
      down = TRUE;
    }
    if (gInput[0].down & DPAD_LEFT) {
      left = TRUE;
    } else if (gInput[0].down & DPAD_RIGHT) {
      right = TRUE;
    }
  } else if (gInput[0].down & (DPAD_UP | DPAD_DOWN | DPAD_LEFT | DPAD_RIGHT)) {
    p->unk_3f++;
  }

  if (up) {
    if (cursor >> 2 == 0) {
      cursor = (cursor & 3) + 12;
    } else {
      cursor -= 4;
    }
    p->unk_3f = 0;
  } else if (down) {
    if (cursor >> 2 == 3) {
      cursor &= 3;
    } else {
      cursor += 4;
    }
    p->unk_3f = 0;
  } else if (left) {
    if ((*cursorPtr & 3) == 0) {
      cursor = (cursor & 0xFC) + 3;
    } else {
      cursor--;
    }
    p->unk_3f = 0;
  } else if (right) {
    if ((cursor & 3) == 3) {
      cursor &= 0xFC;
    } else {
      cursor++;
    }
    p->unk_3f = 0;
  }

  if (cursor != *cursorPtr) {
    p->sprites0[0].pos.x = (cursor & 3) * 24 + 144;
    p->sprites0[0].pos.y = (cursor >> 2) * 24 + 32;
    *cursorPtr = cursor;
    PlaySound_082406e0(SE_CURSOR_MOVE);
    Forge_ShowWeaponInfo(p, NULL);
  }

  if (gInput[0].pressed & A_BUTTON) {
    if (p->selectable & (1 << *cursorPtr)) {
      Forge_SelectWeapon(p);
    } else {
      PlaySound_082406e0(SE_NG);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    Forge_Cancel(p);
  } else {
    Forge_DrawStats(p);
    p->fnTimer++;
  }
#else
  INCFUNC("asm/func/Forge_UpdateList.inc");
#endif
}

void Forge_UpdatePlaceMaterial(Forge* p) {
  ForgeWeapon* e = &p->materials[p->unk_3e];

  if (Forge_TakeFnChanged(p)) {
    FUN_0801c7bc(e, &p->weapons[p->cursor], 13);
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->slots[p->unk_3e] = p->cursor;
    p->selectable &= ~(1 << p->slots[p->unk_3e]);
    p->weapons[p->slots[p->unk_3e]].sprite.plttID = 736;
    p->weapons[p->slots[p->unk_3e]].sprite.pltt = Forge_GetObjPltt(1);
    if (p->unk_3e == 0) {
      p->slotPos.x = 16;
      p->slotPos.y = 40;
    } else {
      p->slotPos.x = 64;
      p->slotPos.y = 40;
    }
  }

  LerpVec3(&e->sprite.pos, &p->weapons[p->cursor].sprite.pos, &p->slotPos, p->fnTimer, 3);
  if (p->fnTimer > 7) {
    Forge_OnMaterialPlaced(p);
  } else {
    Forge_DrawStats(p);
    p->fnTimer++;
  }
}

// 局所ポインタのレジスタ割当の差, 197/198 命令
NON_MATCH void Forge_UpdateConfirm(Forge* p) {
#ifdef NONMATCHING_C
  if (Forge_TakeFnChanged(p)) {
    MainSprite* sprite = &p->result.sprite;
    ForgeWeapon* m0 = &p->materials[0];
    ForgeWeapon* m1 = &p->materials[1];
    ForgeWeapon* e = &p->result;
    MainSpriteGfx* gfx = &p->gfx1;
    bool32 differ;
    bool32 failed;

    MainSprite_SetPose(&p->sprites0[0], gfx, 57, PLAYMODE_PAUSE);
    Marquee_Clear();
    FUN_0801b688(p, e);
    MainSprite_Show(sprite);
    sprite->pos.x = 104;
    sprite->pos.y = 40;
    differ = FALSE;
    if (m0->data.kind != m1->data.kind) {
      MainSprite_SetPose(sprite, &p->iconGfx, ICON_QUESTION1, PLAYMODE_PAUSE);
      differ = TRUE;
    }
    failed = !p->unk_3b;
    if (failed) {
      sprite->plttID = 736;
    } else {
      sprite->plttID = 735;
    }
    sprite->pltt = Forge_GetObjPltt(failed);
    p->unk_40 = 0;
    MainSprite_SetAnim(&p->sprites0[2], gfx, 4, PLAYMODE_LOOP, 0);
    MainSprite_Show(&p->sprites0[2]);
    MessageWindow_SetRect(0, 16, 30, 2);
    MessageWindow_Start(p->unk_130c);
    if (differ || e->data.lv <= gStat->lv) {
      MessageWindow_ShowLine(1);
    } else {
      MessageWindow_ShowLine(2);
    }
    MainSprite_Hide(&p->iconSprite);
    Marquee_Clear();
  }

  if (gInput[0].down & SELECT_BUTTON) {
    if (gInput[0].pressed & A_BUTTON) {
      if (++p->unk_95 > 2) {
        p->unk_95 = 0;
      }
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
  } else {
    Forge_MoveConfirmCursor(p);
    if (gInput[0].pressed & A_BUTTON) {
      if (p->unk_40 == 0) {
        PlaySound_082406e0(SE_SELECT);
        Forge_SetFn(p, FUN_0801d6c0);
        return;
      }
    } else if (!(gInput[0].pressed & B_BUTTON)) {
      Forge_DrawStats(p);
      p->fnTimer++;
      return;
    }
    MainSprite_Hide(&p->result.sprite);
    MainSprite_Hide(&p->sprites0[2]);
    Forge_Cancel(p);
    return;
  }

  Forge_DrawStats(p);
  p->fnTimer++;
#else
  INCFUNC("asm/func/Forge_UpdateConfirm.inc");
#endif
}

void FUN_0801cec0(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
  }

  if (p->fnTimer == 20) {
    if (p->unk_b8 != 0) {
      VM_ExecByID(p->unk_b8, NULL);
    }
  } else {
    Forge_DrawStats(p);
    p->fnTimer++;
  }
}

void Forge_UpdateCannotForge(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    MainSprite* sprite = &p->result.sprite;
    ForgeWeapon* e = &p->result;
    ForgeWeapon* a;
    ForgeWeapon* b;

    MainSprite_SetPose(&p->sprites0[0], &p->gfx1, 57, PLAYMODE_PAUSE);
    MessageWindow_SetRect(0, 16, 30, 2);
    MessageWindow_Start(p->unk_130c);
    MessageWindow_ShowLine(3);
    Marquee_Clear();
    MainSprite_Hide(&p->iconSprite);
    FUN_0801b688(p, e);
    a = &p->weapons[16];
    b = &p->weapons[17];
    if (a->data.kind != b->data.kind) {
      MainSprite_SetPose(sprite, &p->iconGfx, ICON_QUESTION1, PLAYMODE_PAUSE);
    }
    MainSprite_Show(sprite);
    sprite->pos.x = 104;
    sprite->pos.y = 40;
    sprite->plttID = 736;
    sprite->pltt = Forge_GetObjPltt(1);
  }

  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_NG);
  } else if (gInput[0].pressed & B_BUTTON) {
    MainSprite_Hide(&p->result.sprite);
    Forge_Cancel(p);
  } else {
    Forge_DrawStats(p);
    p->fnTimer++;
  }
}

NON_MATCH void FUN_0801d01c(Forge* p) {
#ifdef NONMATCHING_C
  ForgeWeapon* e = p->weapons;
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

s32 FUN_0801d084(Forge* p) {
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  for (i = 0; i < 13; i++) {
    MainSprite_Add(&p->sprites2[i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

// 283/262 命令, sprites2 の添字を毎回計算している, 局所ポインタの持ち方が未解決
NON_MATCH s32 Forge_SetupHUD(Forge* p) {
#ifdef NONMATCHING_C
  MainSpriteGfx* gfx;
  MainSprite* sprite;
  s16 range;
  s32 pose;
  s32 y;
  s32 i;

  switch (p->result.data.rank) {
    case 0: {
      range = 40;
      pose = 8;
      break;
    }
    case 1: {
      range = 30;
      pose = 7;
      break;
    }
    case 2: {
      range = 20;
      pose = 6;
      break;
    }
    case 3: {
      range = 10;
      pose = 5;
      break;
    }
    case 4: {
      range = 10;
      pose = 5;
      break;
    }
    default: {
      range = 40;
      pose = 8;
      break;
    }
  }

  p->unk_b4 = 1800;
  p->unk_60 = p->result.data.durability;
  p->unk_5c = p->result.data.durability - range;
  p->unk_5e = p->unk_60 + range;
  if (p->unk_5c < 0) {
    p->unk_5c = 0;
  } else if (p->unk_5c > 176) {
    p->unk_5c = 176;
  }
  if (p->unk_5e < 0) {
    p->unk_5e = 0;
  } else if (p->unk_5e > 176) {
    p->unk_5e = 176;
  }

  p->unk_62 = 0;
  p->sprites2[0].pos.x = 0;
  gfx = &p->gfx0;
  MainSprite_SetPose(&p->sprites2[0], gfx, 4, PLAYMODE_PAUSE);
  p->sprites2[0].priority = 0;
  MainSprite_Hide(&p->sprites2[0]);

  p->sprites2[1].pos.x = 0;
  MainSprite_SetPose(&p->sprites2[1], gfx, 3, PLAYMODE_PAUSE);
  MainSprite_Hide(&p->sprites2[1]);
  p->sprites2[1].priority = 0;

  p->sprites2[2].pos.x = p->unk_5c;
  MainSprite_SetPose(&p->sprites2[2], gfx, 1, PLAYMODE_PAUSE);
  MainSprite_Hide(&p->sprites2[2]);

  p->sprites2[3].pos.x = p->unk_5e;
  MainSprite_SetPose(&p->sprites2[3], gfx, 2, PLAYMODE_PAUSE);
  MainSprite_Hide(&p->sprites2[3]);

  p->sprites2[4].pos.x = p->unk_60;
  MainSprite_SetPose(&p->sprites2[4], gfx, pose, PLAYMODE_PAUSE);
  MainSprite_Show(&p->sprites2[4]);

  p->sprites2[5].pos.x = p->unk_62 - 176;
  MainSprite_SetPose(&p->sprites2[5], gfx, 9, PLAYMODE_PAUSE);
  p->sprites2[5].priority = 1;
  MainSprite_Show(&p->sprites2[5]);

  CpuCopy16(&gObjPlttData[671 * 16], p->unk_12e4, 16 * sizeof(rgb555));
  p->sprites2[5].plttID = 0x8100;
  p->sprites2[5].pltt = p->unk_12e4;

  p->sprites2[6].pos.x = 0;
  MainSprite_SetPose(&p->sprites2[6], gfx, 10, PLAYMODE_PAUSE);
  p->sprites2[6].priority = 1;
  MainSprite_Show(&p->sprites2[6]);

  p->sprites2[7].pos.x = 0;
  MainSprite_SetAnim(&p->sprites2[7], gfx, 0, PLAYMODE_LOOP, 0);
  MainSprite_Show(&p->sprites2[7]);

  sprite = &p->sprites2[8];
  y = 32;
  for (i = 0; i < 5; i++) {
    sprite->pos.x = 8;
    sprite->pos.y = y;
    MainSprite_SetPose(sprite, gfx, 22, PLAYMODE_PAUSE);
    sprite->priority = 0;
    MainSprite_Hide(sprite);
    sprite++;
    y += 8;
  }

  p->pos = p->pos2;
  return 0;
#else
  INCFUNC("asm/func/Forge_SetupHUD.inc");
#endif
}

void FUN_0801d338(Forge* p) {
  StrikeRating* rating = &p->ratings[p->unk_66];
  MainSprite* sprite = &p->sprites2[8 + p->unk_66];

  MainSprite_SetPose(sprite, &p->gfx0, p->unk_92 + 20, PLAYMODE_PAUSE);
  sprite->flags &= ~SPRFLAG_HIDDEN;
  rating->state = 1;
  rating->timer = 0;
  if (++p->unk_66 >= 5) {
    p->unk_66 = 0;
  }
}

void FUN_0801d394(Forge* p) {
  StrikeRating* rating = p->ratings;
  MainSprite* sprite = &p->sprites2[8];
  s32 i;

  for (i = 0; i < 5; i++, rating++, sprite++) {
    switch (rating->state) {
      case 0: {
        break;
      }
      case 1: {
        sprite->pos.x = (8 - rating->timer) * 8 + 4;
        if (rating->timer >= 8) {
          sprite->pos.x = 4;
          rating->state = 2;
          rating->timer = 0;
        }
        break;
      }
      case 2: {
        if (rating->timer >= 64) {
          rating->state = 3;
          rating->timer = 0;
          sprite->flags |= SPRFLAG_BLINK_ODD;
        }
        break;
      }
      case 3: {
        if (rating->timer >= 8) {
          rating->state = 0;
          rating->timer = 0;
          sprite->flags = (sprite->flags & ~SPRFLAG_BLINK_ODD) | SPRFLAG_HIDDEN;
        }
        break;
      }
    }
    rating->timer++;
  }
}

// 2枚のスプライトを unk_80 を挟むように左右へ置き, 画面内 (0..0xB0) に丸めてから表示する
void FUN_0801d420(Forge* p) {
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

void FUN_0801d488(Forge* p) {
  MainSprite* spr;

  spr = &p->sprites2[2];
  spr->flags |= SPRFLAG_HIDDEN;
  spr = &p->sprites2[3];
  spr->flags |= SPRFLAG_HIDDEN;
}

void FUN_0801d4a8(Forge* p) {
  MainSprite* spr = &p->sprites2[0];

  spr->pos.x = p->unk_93;
  spr->flags &= ~SPRFLAG_HIDDEN;
}

void FUN_0801d4c4(Forge* p) {
  MainSprite* spr = &p->sprites2[0];

  spr->pos.x = p->unk_93;
  spr->flags |= SPRFLAG_HIDDEN;
}

s32 Forge_SendMsg(Forge* p, s32 cmd, s32 argc, s16* args) {
  MsgPacket* msg = &p->msg;

  msg->targetID = p->unk_131c;
  msg->targetClass = p->unk_131e;
  msg->waitFlag = FALSE;
  msg->unk_4 = 0;
  msg->cmd = cmd;
  msg->argc = argc;
  if (args != NULL) {
    s32 i;

    for (i = 0; i < argc; i++) {
      msg->args[i] = args[i];
    }
  }
  MsgPacket_Send(msg);
  return 0;
}

// レジスタ割当の残差のみ (sprite と &p->unk_62 が逆), 159/158 命令
NON_MATCH s32 Forge_UpdateHUD(Forge* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprites2[5];
  s32 i;
  s32 frac;
  s32 sec;

  sprite->pos.x = p->unk_62 - 176;
  if (p->unk_62 < p->unk_5c) {
    if (p->unk_64 != 1) {
      p->unk_64 = 1;
      MainSprite_SetAnim(&p->sprites2[7], &p->gfx0, 0, PLAYMODE_LOOP, 0);
    }
  } else if (p->unk_62 < p->unk_5e) {
    if (p->unk_64 != 2) {
      p->unk_64 = 2;
      MainSprite_SetAnim(&p->sprites2[7], &p->gfx0, 1, PLAYMODE_LOOP, 0);
    }
  } else {
    if (p->unk_64 != 3) {
      p->unk_64 = 3;
      MainSprite_SetAnim(&p->sprites2[7], &p->gfx0, 2, PLAYMODE_LOOP, 0);
    }
  }

  for (i = 0; i < 13; i++) {
    MainSprite_AdvanceAnim(&p->sprites2[i], &p->gfx0);
  }

  for (i = 0; i < p->sunGauge; i++) {
    Video_SetBGTile(0, i + 6, 16, 5, 0, 13);
  }
  for (; i < 10; i++) {
    Video_SetBGTile(0, i + 6, 16, 6, 0, 13);
  }

  frac = Div(Mod(p->unk_b4, 60) * 100, 60);
  sec = Div(p->unk_b4, 60);
  Video_DrawBGNumber(0, 21, 16, sec, 17, 2, 13);
  Video_DrawBGNumber(0, 24, 16, frac, 17, 2, 13);
  FUN_0801d394(p);
#else
  INCFUNC("asm/func/Forge_UpdateHUD.inc");
#endif
}

s32 FUN_0801d6a0(Forge* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    MainSprite_Remove(&p->sprites2[i]);
  }
}

void FUN_0801d6c0(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    StartBgObjPlttFade(1, 5, 4, 4, 4, 0xFFFF, 0);
  }

  if (p->fnTimer > 31) {
    FUN_0801d01c(p);
    Marquee_RequestClose();
    Forge_SetFn(p, FUN_0801d71c);
  } else {
    Forge_DrawStats(p);
    p->fnTimer++;
  }
}

void FUN_0801d71c(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    Forge_SetupBg(p, 1);
    Forge_SetupHUD(p);
    StartBgObjPlttFade(0, 5, 4, 4, 4, 0xFFFF, 0);
    FUN_0807c7c8(gPlayerPtr[0], 0);
  }

  if (p->fnTimer > 31) {
    Forge_SetFn(p, FUN_0801d788);
  } else {
    Forge_UpdateHUD(p);
    p->fnTimer++;
  }
}

void FUN_0801d788(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    Forge_SendMsg(p, 3, 0, 0);
  }

  if (p->fnTimer >= 240) {
    Forge_SetFn(p, Forge_UpdateSmithing);
  } else {
    if (Mod(p->fnTimer, 61) == 60) {
      PlaySound_082406e0(SE_COUNTDOWN);
    }

    Forge_UpdateHUD(p);
    p->fnTimer++;
  }
}

bool32 Forge_TakeSubFnChanged(Forge* p) {
  if (p->unk_1310) {
    p->unk_1310 = FALSE;
    return TRUE;
  }

  return FALSE;
}

void Forge_SetSubFn(Forge* p, void* fn) {
  p->subCallback = fn;
  p->unk_1310 = TRUE;
  p->unk_1314 = 0;
}

void Forge_SubCharge(Forge* p) {
  if (Forge_TakeSubFnChanged(p)) {
    p->unk_12e4[15] = 159;
  }

  if (p->sunGauge != 0) {
    p->unk_84 += (p->sunGauge + 3) * 6;
    if (p->unk_84 >= 5632) {
      p->unk_84 = 5632;
    }
  } else {
    p->unk_84 = (p->unk_84 * 60) >> 6;
  }

  if (gInput[0].pressed & A_BUTTON) {
    MainSprite* sprite = &p->sprites2[1];

    p->unk_80 = p->unk_84;
    sprite->pos.x = p->unk_80 >> 5;
    Forge_SetSubFn(p, Forge_SubHammer);
    Forge_SendMsg(p, 4, 0, NULL);
    FUN_0801d420(p);
  } else {
    p->unk_1314++;
  }
}

// r9 を余計に使う, 192/184 命令, t と press の持ち方が違う
NON_MATCH void Forge_SubHammer(Forge* p) {
#ifdef NONMATCHING_C
  s32 speed;
  s32 t;
  s32 press;
  u16 color;

  if (Forge_TakeSubFnChanged(p)) {
    p->unk_88 = 0;
    p->unk_7c = 0;
    p->unk_8c = 0;
    p->unk_90 = 0;
    p->unk_66 = 0;
    p->unk_92 = 0;
    p->unk_93 = 0;
    FUN_0807c7c8(gPlayerPtr[0], 1);
  }

  speed = 3;
  if ((u32)p->sunGauge != 0) {
    speed = 6;
  }
  speed += (u32)p->sunGauge >> 1;
  if (p->unk_88 != 0) {
    p->unk_7c += speed * 4;
    if (p->unk_7c > 767) {
      p->unk_7c = 768;
      p->unk_88 = 0;
    }
  } else {
    p->unk_7c -= speed * 4;
    if (p->unk_7c < -767) {
      p->unk_7c = -768;
      p->unk_88 = 1;
    }
  }

  p->unk_84 = p->unk_80 + p->unk_7c;
  if (p->unk_84 < 0) {
    p->unk_84 = 0;
  } else if (p->unk_84 > 5632) {
    p->unk_84 = 5632;
  }

  t = Div(p->unk_1314, 16);
  press = Div(p->unk_8c << 5, 5);
  if (t < press) {
    t = press;
  }
  color = gObjPlttData[10751];
  p->unk_12e4[15] = ((((32 - t) * 31 + t * (color & 0x1F)) >> 5) & 0x1F) + ((((32 - t) * 4 + t * ((color >> 5) & 0x1F)) >> 5) & 0x1F) * 32 + (((t * ((color >> 10) & 0x1F)) >> 5) & 0x1F) * 1024;

  if (p->unk_90 == 0) {
    if (p->unk_8c < 5) {
      if (gInput[0].pressed & A_BUTTON) {
        p->unk_91 = TRUE;
        p->unk_90 = 13;
        p->unk_8c++;
        Forge_SendMsg(p, 6, 0, NULL);
      }
      if (p->unk_1314 < 512) {
        p->unk_1314++;
        return;
      }
    }
    Forge_SetSubFn(p, Forge_SubCool);
  } else {
    if (p->unk_90-- == 10) {
      FUN_0801d338(p);
    }
    p->unk_1314++;
  }
#else
  INCFUNC("asm/func/Forge_SubHammer.inc");
#endif
}

void Forge_SubCool(Forge* p) {
  if (Forge_TakeSubFnChanged(p)) {
    MainSprite* sprite = &p->sprites2[1];
    rgb555* pltt = &gObjPlttData[671 * 16];

    MainSprite_Hide(sprite);
    p->unk_12e4[15] = pltt[15];
    p->unk_88 = 0;
    p->unk_7c = 0;
    Forge_SendMsg(p, 8, 0, NULL);
    FUN_0801d488(p);
    FUN_0801d4c4(p);
    FUN_0807c7c8(gPlayerPtr[0], 0);
  }

  p->unk_84 = (p->unk_84 * 24) >> 5;
  if (p->unk_1314 > 31) {
    Forge_SetSubFn(p, Forge_SubCharge);
  } else {
    p->unk_1314++;
  }
}

// *value >> 5 の r2 への複写と movs r7, #0 の位置だけの差, 172/173 命令
NON_MATCH void Forge_UpdateSmithing(Forge* p) {
#ifdef NONMATCHING_C
  s32* value;
  s16* x;
  s32 shifted;

  if (Forge_TakeFnChanged(p)) {
    Forge_SetSubFn(p, Forge_SubCharge);
    p->unk_84 = 0;
    p->unk_7c = 0;
    p->unk_80 = 32;
    p->sunGauge = p->unk_68 >> 5;
    p->unk_66 = 0;
    p->unk_a4 = 0;
    p->unk_a8 = 0;
    p->unk_ac = 0;
    p->unk_b0 = 0;
    p->unk_88 = 2;
    if ((u32)p->sunGauge > 10) {
      p->sunGauge = 10;
    }
    p->unk_70 = p->sunGauge;
  }

  p->unk_91 = FALSE;
  p->subCallback(p);
  value = &p->unk_84;
  if (*value > 5632) {
    *value = 5632;
  } else if (*value < 0) {
    *value = 0;
  }
  x = &p->unk_62;
  shifted = *value >> 5;
  *x = shifted;

  if (p->unk_91) {
    s32 diff = abs(p->unk_60 - *x);

    p->unk_93 = shifted;
    FUN_0801d4a8(p);
    p->unk_a0++;
    if (*x >= p->unk_5c && *x <= p->unk_5e) {
      if (diff < 2) {
        p->unk_65 = TRUE;
        p->unk_a8++;
        p->unk_a4 += 100;
        p->unk_92 = 0;
      } else {
        p->unk_65 = FALSE;
        if (diff < 100) {
          p->unk_a4 += 100 - diff;
        }
        p->unk_ac++;
        p->unk_92 = 1;
      }
    } else {
      p->unk_b0++;
      p->unk_92 = 2;
    }
  }

  Forge_UpdateHUD(p);
  if (p->unk_b4 == 0) {
    Forge_SetFn(p, FUN_0801dc90);
  } else {
    p->unk_b4--;
    p->fnTimer++;
  }
#else
  INCFUNC("asm/func/Forge_UpdateSmithing.inc");
#endif
}

void FUN_0801dc90(Forge* p) {
  if (Forge_TakeFnChanged(p)) {
    Forge_SendMsg(p, 9, 0, 0);
    sound_08240264(BGM_END);
  }

  Forge_UpdateHUD(p);
  Camera_MoveTo(&p->pos);
  if (p->fnTimer >= 30) {
    Forge_SetFn(p, Forge_UpdateFinish);
  } else {
    p->fnTimer++;
  }
}

void Forge_UpdateFinish(Forge* p) {
  s16 args[2];
  Vec3 pos;

  if (Forge_TakeFnChanged(p)) {
    s16 arg = 2;

    args[0] = arg;
    Forge_SendMsg(p, 1, 1, args);
    FUN_0807c7c8(gPlayerPtr[0], 3);
    PlaySound_082406e0(VO_SMITH_FORGE4);
  }

  Forge_UpdateHUD(p);
  Camera_MoveTo(&p->pos);
  if (p->fnTimer - 30 < 70 && (p->fnTimer & 3) == 0) {
    Vec3_CopyOffsetX(&gPlayerPtr[0]->mover.pos, &pos, 200);
    Puff_SpawnSpray(2, 0, 0x2000, Q6(1), &pos);
    PlaySound_082406e0(SONG_453);
  }

  if (p->fnTimer > 99) {
    Forge_SetFn(p, Forge_UpdateAward);
  } else {
    p->fnTimer++;
  }
}

// 253/245 命令, gPlayerPtr[0] の読み方が合わない
NON_MATCH void Forge_UpdateAward(Forge* p) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];
  Vec3 pos;
  Vec3 pos2;
  Vec3 pos3;
  s32 i;
  s32 angle;

  if (Forge_TakeFnChanged(p)) {
    Forge_Finish(p);
    p->startPos = p->pos;
    p->endPos = player->mover.pos;
    p->unk_94 = DIR8_DOWN;
    Player_Lock(gPlayerPtr[0], DIR8_DOWN);
  }

  Forge_UpdateHUD(p);
  if (p->fnTimer <= 32) {
    LerpVec3(&p->pos, &p->startPos, &p->endPos, p->fnTimer, 5);
  }
  Camera_MoveTo(&p->pos);

  if (p->fnTimer == 30) {
    pos = player->mover.pos;
    Entity99CA_CreateAt(&pos, 64, 60, 8, 0);
    PlaySound_082406e0(SONG_668);
  }

  if (p->fnTimer == 90) {
    pos2 = gPlayerPtr[0]->mover.pos;
    pos2.x -= 32;
    pos2.y += 128;
    pos2.z += 32;
    ItemIconPopupManager_AddIcon(1, p->result.data.id, 0, 0, &pos2, &gPlayerPtr[0]->mover.pos, 60, (u32)p);
    FUN_0807bbb0(gPlayerPtr[0], 0, 0);
    PlaySound_082406e0(SE_PICKUP);
  }

  if (p->fnTimer == 96 && gPlayerPtr[0] != NULL && p->result.data.rank == 4) {
    u32 id;

    pos3.x = gPlayerPtr[0]->mover.pos.x;
    pos3.y = gPlayerPtr[0]->mover.pos.y + 378;
    pos3.z = gPlayerPtr[0]->mover.pos.z;
    id = p->result.data.id;
    if (id != WEAPON_DULL_BLADE && id != WEAPON_STAFF && id != WEAPON_POUNDER) {
      if (id == WEAPON_GRAM || id == WEAPON_GUNGNIR || id == WEAPON_MJOLLNIR) {
        StartBgObjPlttFade(0, 3, 31, 31, 31, 0xFFF, 0);
        angle = 0;
        for (i = 0; i < 3; i++) {
          ScatterEffect_SpawnAtAngle(4, SCATTER_SOL_S | SCATTER_PRIORITY(1), &pos3, angle, 88, 8, 8, 8, 1, 12, 8);
          angle += 88;
        }
      } else {
        StartBgObjPlttFade(0, 3, 31, 23, 7, 0xFFF, 0);
        angle = 0;
        for (i = 0; i < 3; i++) {
          ScatterEffect_SpawnAtAngle(4, SCATTER_SOL_S | SCATTER_PRIORITY(1), &pos3, angle, 88, 8, 8, 8, 1, 12, 8);
          angle += 88;
        }
      }
    }
  }

  if (p->fnTimer > 163) {
    Forge_SetFn(p, FUN_0801dfb0);
    Player_Lock(gPlayerPtr[0], p->unk_94);
  } else {
    p->fnTimer++;
  }
#else
  INCFUNC("asm/func/Forge_UpdateAward.inc");
#endif
}

void FUN_0801dfb0(Forge* p) {
  p->fnTimer++;
  if (p->fnTimer == 60 && p->unk_ba != 0) {
    Forge_RunResultScript(p);
  } else {
    Forge_UpdateHUD(p);
    Camera_MoveTo(&p->pos);
  }
}

// 目印が立っていれば落として TRUE を返す, Entity が無ければ FALSE
bool32 FUN_0801dfe4(void) {
  if (gForge == NULL) return FALSE;

  if (gForge->unk_65) {
    gForge->unk_65 = FALSE;
    return TRUE;
  }

  return FALSE;
}

s32 FUN_0801e00c(void) {
  if (gForge == NULL) return 2;
  return gForge->unk_92;
}

s32 Forge_Update(Forge* p) {
  p->sunGauge = Cmd_GetSolarGauge();
  p->updateCallback(p);
  return 0;
}

s32 Forge_Destroy(Forge* p) {
  Forge_RemoveWeaponSprites(p);
  FUN_0801c434(p);
  FUN_0801c454(p);
  FUN_0801c474(p);
  FUN_0801d6a0(p);
  Marquee_RequestClose();
  gForge = NULL;
  return 0;
}

s32 Forge_Init(Forge* p, s32 param_2, s32 param_3) {
  MainSpriteGfxFile* f;
  Vec3* pos;

  gForge = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_MISC);
  if (f != NULL) {
    p->gfx0 = *f;
    OpenMainSpriteFile(&p->gfx0, f);
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
    if (f != NULL) {
      p->gfx1 = *f;
      OpenMainSpriteFile(&p->gfx1, f);
      f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
      if (f != NULL) {
        p->iconGfx = *f;
        OpenMainSpriteFile(&p->iconGfx, f);
        p->unk_131c = VM_GetNamedArgValue('n', 0xB156);
        p->unk_131e = 5;
        if (VM_SeekToNamedArg('p')) {
          VEC3_SET(p->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
        } else {
          VEC3_SET(p->pos, 0, 0, 0);
        }
        pos = &p->pos;
        p->pos2 = *pos;
        Camera_MoveTo(pos);
        p->unk_b8 = VM_GetNamedArgValue('c', 0);
        p->unk_ba = VM_GetNamedArgValue('e', 0);
        if (!VM_SeekToNamedArg('w')) {
          goto fail;
        }
        p->unk_1308 = VM_GetPC_Proxy();
        if (p->unk_1308 != NULL) {
          goto next;
        }
      }
    }
  }

fail:
  return -1;

next:
  if (!VM_SeekToNamedArg('k')) {
    goto fail;
  }
  p->unk_130c = VM_GetPC_Proxy();
  if (p->unk_130c == NULL) {
    goto fail;
  }

  Forge_AddRegisteredMarks(p);
  Forge_AddWeaponSprites(p);
  Forge_AddCursors(p);
  FUN_0801c2bc(p);
  MessageWindow_SetRect(0, 16, 30, 2);
  Forge_OpenList(p);
  FUN_0801d084(p);
  Forge_SetFn(p, Forge_UpdateList);
  FUN_08049f5c();
  return 0;
}

// 0xDA0B
Forge* Forge_Create(s32 param_1, s32 param_2) {
  Forge* p;

  if (gForge != NULL) {
    return gForge;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(Forge));
  if (p != NULL) {
    SetEntityRoutine(p, Forge_Update, Forge_Destroy);
    if (Forge_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
