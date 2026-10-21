#include "weapon.h"

#include "global.h"
#include "player.h"
#include "vm.h"

void FUN_0809c28c(void);

bool32 IsWeaponAlreadyFound(weapon32_t n) {
  if (n >= 32) {
    return (gStat->weaponDex[1]) & (1 << (n - 32));
  } else {
    return (gStat->weaponDex[0]) & (1 << n);
  }
}

void SetWeaponFoundFlag(weapon32_t n) {
  if (n >= 32) {
    (gStat->weaponDex[1]) |= (1 << (n - 32));
  } else {
    (gStat->weaponDex[0]) |= (1 << n);
  }
}

// 0x082429d8
Weapon* GetWeapon(s32 slot) { return WEAPONS(slot); }

weapon32_t GetWeaponID(s32 slot) { return GetWeapon(slot)->id; }

u32 GetWeaponKind(s32 slot) { return gWeaponDB[GetWeapon(slot)->id].kind; }

s8 GetWeaponQuality(s32 slot) { return GetWeapon(slot)->quality; }

u32 GetWeaponWear(s32 slot) { return GetWeapon(slot)->wear; }

// WeaponData から ID と動的に変わる値だけ抜き出して, セーブ用に切り詰めた Weapon に詰める
// 残差2命令 (49 対 47), BuildWeaponData と同じ詰まり方で, effects のコピーで原典は tmpl/w 自身を誘導変数にして ->effects のオフセットを畳み込むが,
// こちらは &w->effects と &tmpl->effects を PS の分岐の両腕に先出しし, 代わりにループ本体が ldm/stm で2命令短くなる
// Tier A-C は試済 (i のスコープ, i と j に分割, PS を char* で先出し (これは効いた))
NON_MATCH void BuildWeapon(WeaponData* tmpl, Weapon* w) {
#ifdef NONMATCHING_C
  s32 i;

  w->id = tmpl->id;
  w->wear = tmpl->wear;
  w->quality = tmpl->quality;

  if (tmpl->PS[0] == 0) {
    char* dst = w->PS;

    w->PS[0] = 0;
    for (i = 1; i < 12; i++) {
      dst[i] = 0;
    }
  } else {
    char* dst = w->PS;
    char* src = tmpl->PS;

    for (i = 0; i < 12; i++) {
      dst[i] = src[i];
    }
  }

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    w->effects[i] = tmpl->effects[i];
  }
#else
  INCFUNC("asm/func/BuildWeapon.inc");
#endif
}

// セーブ用に切り詰めた Weapon を, DB の雛形に動的な値を載せて WeaponData に戻す
// 残差4命令 (64 対 60), effects のコピーで原典は w/data 自身を誘導変数にして ->effects のオフセットを畳み込むが, こちらは &data->effects と &w->effects を PS の分岐より前に先出しする
// PS 側は逆に原典が先出しでこちらが base+offset だったので, char* を置いて揃えた (66 → 64 命令)
// Tier A は試済 (i のスコープを各ブロックに, effects をポインタ歩きで, DB のエントリをローカルに)
NON_MATCH void BuildWeaponData(Weapon* w, WeaponData* data) {
#ifdef NONMATCHING_C
  *data = gWeaponDB[w->id];
  data->wear = w->wear;
  data->quality = (s8)w->quality;

  if (w->PS[0] == 0) {
    char* dst = data->PS;
    s32 i;

    data->PS[0] = 0;
    for (i = 1; i < 12; i++) {
      dst[i] = 0;
    }
  } else {
    char* dst = data->PS;
    char* src = w->PS;
    s32 i;

    for (i = 0; i < 12; i++) {
      dst[i] = src[i];
    }
  }

  {
    s32 i;

    for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
      data->effects[i] = w->effects[i];
    }
  }
#else
  INCFUNC("asm/func/BuildWeaponData.inc");
#endif
}

// スロット n の武器を, DB の雛形に動的な値を載せた WeaponData として取り出す
void GetWeaponData(slot32_t n, WeaponData* data) {
  BuildWeaponData(GetWeapon(n), data);
  return;
}

// 枠 idx に登録されている武器の WeaponData を取り出す, 未登録なら gWeaponDB[0] (素手)
void GetRegisteredWeaponData(s32 idx, WeaponData* data) {
  if (REGISTERED_WEAPON(idx) < 0) {
    *data = gWeaponDB[0];
  } else {
    GetWeaponData(REGISTERED_WEAPON(idx), data);
  }
}

// スロット n に武器を書き込んで, 図鑑の発見フラグも立てる
void SetWeaponData(slot32_t n, const WeaponData* data) {
  Weapon* w = GetWeapon(n);
  BuildWeapon((WeaponData*)data, w);
  SetWeaponFoundFlag(data->id);
}

// 空いているスロットを探して武器を入れ, 枠が空いていればそこにも登録する, 満杯なら FALSE
NON_MATCH bool32 AddWeapon(WeaponData* data) {
#ifdef NONMATCHING_C
  Player* p;
  s32 slot = 0;
  while (TRUE) {
    if (slot > 15) {
      return FALSE;
    }
    if (GetWeaponID(slot) == WEAPON_NONE) {
      break;
    }
    slot++;
  }

  SetWeaponData(slot, data);
  if ((data->kind < 3) && (REGISTERED_WEAPON(data->kind) == -1)) {
    REGISTERED_WEAPON(data->kind) = slot;
    if (data->kind == 0) {
      gStat->equippedWeaponIdx = 0;
      if (gPlayerPtr[0] != NULL) {
        Weapon* w = GetWeapon(slot);
        Player_ApplyWeapon(gPlayerPtr[0], w);
      }
    }
    FUN_0809c28c();
  }
  return TRUE;
#else
  INCFUNC("asm/func/AddWeapon.inc");
#endif
}

// スロット n を空 (gWeaponDB[0]) に戻し, そこを指していた登録枠も外す
void RemoveWeapon(slot32_t n) {
  s32 i;

  SetWeaponData(n, gWeaponDB);
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
}

void SwapWeaponSlot(slot32_t slot1, slot32_t slot2) {
  Weapon tmp;
  Weapon *w1, *w2;
  s32 i;

  w1 = GetWeapon(slot1);
  w2 = GetWeapon(slot2);

  tmp = *w1;
  *w1 = *w2;
  *w2 = tmp;

  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == slot1) {
      REGISTERED_WEAPON(i) = slot2;
      FUN_08064658(gPlayerPtr[0], w2);
    } else if (REGISTERED_WEAPON(i) == slot2) {
      REGISTERED_WEAPON(i) = slot1;
      FUN_08064658(gPlayerPtr[0], w1);
    }
  }
}

NAKED void SortWeapons(slot32_t from) { INCFUNC("asm/func/SortWeapons.inc"); }

bool32 IsSpecialWeapon(weapon32_t w) {
  if (w >= WEAPON_BROKEN_GUN && w <= WEAPON_ASTRO_HAMMER) {
    return TRUE;
  }
  return FALSE;
}

// 0x3757, '.w' の武器を DB から作って渡す, '.q' で品質, '.o' で特殊効果, '.n' で PS を上書きできる
NAKED bool32 Cmd_GiveWeapon(void) { INCFUNC("asm/func/Cmd_GiveWeapon.inc"); }

// 0xD916, '.f' の武器を持っているスロットを探して '.t' の武器に差し替える
bool32 Cmd_ReplaceWeapon(void) {
  s32 i, slot;

  if (VM_SeekToNamedArg('f')) {
    weapon32_t w = VM_GetValue();
    if (!VM_SeekToNamedArg('t')) {
      return FALSE;
    }

    slot = (s32)VM_GetValue();
    for (i = 0; i < 16; i++) {
      if (GetWeaponID(i) == w) {
        SetWeaponData(i, &gWeaponDB[slot]);
        return TRUE;
      }
    }
  }
  return FALSE;
}

// 0x7D90, いま装備している枠の武器を消して素手に戻す, ゲーム序盤のイベントで太陽銃を奪われるときに使う
void Cmd_TakeEquippedWeapon(void) {
  RemoveWeapon(REGISTERED_WEAPON(gStat->equippedWeaponIdx));
  if (gPlayerPtr[0] != NULL) {
    Player_ApplyWeapon(gPlayerPtr[0], NULL);
    FUN_0809c464();
  }
}

// スロット n を指している登録枠を全部外してから, 枠 slot に登録し直す
void RegisterWeapon(slot32_t n, s32 slot) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
  REGISTERED_WEAPON(slot) = n;
}

// 枠 n の登録を外す
void UnregisterWeapon(s32 n) {
  REGISTERED_WEAPON(n) = -1;
  return;
}

// 0xF11C, '.w' の武器を持っているかを返す, '.d' が非0なら倉庫も含めて探す
bool32 Cmd_HasWeapon(void) {
  if (VM_SeekToNamedArg('w')) {
    s32 len, i;
    weapon32_t w = VM_GetValue();
    if (VM_SeekToNamedArg('d')) {
      len = VM_GetValue() ? 48 : 16;
    } else {
      len = 16;
    }
    for (i = 0; i < len; i++) {
      if (GetWeaponID(i) == w) {
        return TRUE;
      }
    }
  }

  return FALSE;
}

// 0x65E2, 図鑑と48スロットと登録枠を全部白紙に戻してから, '.n' 個ぶん '.w' の武器を入れ直す
NAKED void Cmd_ResetWeapons(void) { INCFUNC("asm/func/Cmd_ResetWeapons.inc"); }

// スロット n の武器が剣槍槌銃のどれかの枠に登録されているかを返す
bool32 IsWeaponRegistered(slot32_t n) {
  s32 i;
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      return TRUE;
    }
  }
  return FALSE;
}

// 売れる武器 (値段が付いていて, どの枠にも登録されていない) の数を数える, IsWeaponSellable と同じ条件
s32 CountSellableWeapons(void) {
  slot32_t i;
  weapon32_t id;
  s32 retval;

  retval = 0;
  for (i = 0; i < 16; i++) {
    id = GetWeaponID(i);
    if ((gWeaponDB[id].price != 0) && (IsWeaponRegistered(i) == 0)) {
      retval++;
    }
  }
  return retval;
}

// 売れる武器の数に空きスロットも足して数える, CountSellableWeapons に id == WEAPON_NONE を加えた条件
s32 CountSellableOrEmptySlots(void) {
  slot32_t i;
  weapon32_t id;
  s32 retval;

  retval = 0;
  for (i = 0; i < 16; i++) {
    id = GetWeaponID(i);
    if (((id == WEAPON_NONE) || (gWeaponDB[id].price != 0)) && (IsWeaponRegistered(i) == 0)) {
      retval++;
    }
  }
  return retval;
}

// スロット n の武器を売れるか, 値段が付いていて, どの枠にも登録されていなければ売れる
bool32 IsWeaponSellable(slot32_t n) {
  weapon32_t id;

  id = GetWeaponID(n);
  if (id == WEAPON_NONE) return FALSE;
  if (gWeaponDB[id].price == 0) return FALSE;
  if (IsWeaponRegistered(n)) return FALSE;
  return TRUE;
}
