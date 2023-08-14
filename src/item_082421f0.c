#include "global.h"
#include "item.h"
#include "weapon.h"

s32 GetRotCount(s32 slot) { return ROTCOUNT(slot); }

void SetRotCount(s32 slot, u32 value) {
  ROTCOUNT(slot) = value;
  return;
}

s32 GetRotCount2(s32 slot) { return ROTCOUNT(slot) & 0x7FFF; }

void SetRotCount2(s32 slot, u32 value) {
  ROTCOUNT(slot) = (value & 0x7FFF) | (ROTCOUNT(slot) & 0x8000);
  return;
}

void CoverChocolate(s32 slot) {
  ROTCOUNT(slot) |= 0x8000;  // GAME->rotTimer[slot] |= 0x8000
  return;
}

void UncoverChocolate(s32 slot) {
  ROTCOUNT(slot) &= 0x7FFF;  // GAME->rotTimer[slot] &= 0x7FFF
  return;
}

s32 IsChocolateCovered(u32 slot) { return *(GAME->rotTimer + slot) & 0x8000; }

item32_t GetNormalItemID(s32 slot) {
  if (IsChocolateCovered(slot)) {
    return ITEM_CHOCOLATE_COVERED;
  }
  return ITEM(slot);
}

item32_t GetValuableItemID(s32 slot) { return VALUABLES(slot); }

void SetItem(s32 slot, item32_t id) {
  ITEM(slot) = id;
  return;
}

void SetValuable(s32 slot, item32_t id) {
  VALUABLES(slot) = id;
  return;
}

void RemoveItem(s32 slot) {
  SetItem(slot, ITEM_NONE);
  SetRotCount(slot, 0);
}

void RemoveValuable(s32 slot) {
  SetValuable(slot, ITEM_NONE);
  return;
}

bool32 IsValuable(item32_t id) {
  if (ITEM_JUDGEMENT >= id) {
    return FALSE;
  }
  return TRUE;
}

static bool32 tryAddItem(item32_t n, s32 rotCount) {
  s32 slot;
  for (slot = 0; slot < 16; slot++) {
    if (GetNormalItemID(slot) < 0) {
      SetItem(slot, n);
      SetRotCount(slot, rotCount);
      return TRUE;
    }
  }
  return FALSE;
}

static bool32 tryAddValuable(item32_t n) {
  s32 slot = 0;
  u32 flagHeart = (1 << 28);
  u32 flagJoker = (1 << 29);

  for (; slot < 16; slot++) {
    if (GetValuableItemID(slot) < 0) {
      SetValuable(slot, n);
      if (gPlayerPtr[0] != NULL) {
        if (n == ITEM_HEART_EMBLEM) {
          gPlayerPtr[0]->unk_378 |= flagHeart;
        } else if (n == ITEM_JOKER_EMBLEM) {
          gPlayerPtr[0]->unk_378 |= flagJoker;
        }
      }
      return TRUE;
    }
  }
  return FALSE;
}

bool32 TryAddItem(item32_t n, s32 rotCount) {
  if (!IsValuable(n)) {
    return tryAddItem(n, rotCount);
  }
  return tryAddValuable(n);
}

INCASM("asm/code_082422f0.inc");

static bool32 checkInventoryItemOwn(item32_t id) {
  s32 slot;
  for (slot = 0; slot < 16; slot++) {
    if (GetNormalItemID(slot) == id) {
      return TRUE;
    }
  }
  return FALSE;
}

static bool32 checkValuableOwn(item32_t id) {
  s32 slot;
  for (slot = 0; slot < 16; slot++) {
    if (GetValuableItemID(slot) == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// 0x082424b4
bool32 CheckItemOwn(item32_t id) {
  if (!IsValuable(id)) {
    return checkInventoryItemOwn(id);
  }
  return checkValuableOwn(id);
}

bool32 FUN_082424d4(void) {
  if (prepare_08231510(0x69) != 0) {
    return CheckItemOwn(fetch_082316e4());
  }
  return FALSE;
}

NAKED void SwapNormalItem(s32 slot1, s32 slot2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r1, #0\n\
	ldr r0, _08242534 @ =0x030046A0\n\
	ldr r1, [r0]\n\
	lsls r2, r4, #1\n\
	adds r2, r2, r1\n\
	adds r2, #0x70\n\
	movs r0, #0\n\
	ldrsh r6, [r2, r0]\n\
	lsls r0, r5, #1\n\
	adds r0, r0, r1\n\
	adds r0, #0x70\n\
	ldrh r1, [r0]\n\
	strh r1, [r2]\n\
	strh r6, [r0]\n\
	adds r0, r4, #0\n\
	bl GetRotCount\n\
	adds r6, r0, #0\n\
	adds r0, r5, #0\n\
	bl GetRotCount\n\
	adds r1, r0, #0\n\
	adds r0, r4, #0\n\
	bl SetRotCount\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl SetRotCount\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08242534: .4byte 0x030046A0\n\
 .syntax divided\n");
}

void SwapValuable(s32 slot1, s32 slot2) {
  item32_t a = GetValuableItemID(slot1);
  item32_t b = GetValuableItemID(slot2);
  SetValuable(slot1, b);
  SetValuable(slot2, a);
}

NAKED void SortInventory(s32 slot) { INCCODE("asm/todo/SortInventory.inc"); }
NAKED void SortValuable(s32 slot) { INCCODE("asm/todo/SortValuable.inc"); }

item32_t GetRottenItemID(item32_t n) {
  switch (n) {
    case ITEM_EARTHLY_NUT:
    case ITEM_SOLAR_NUT:
    case ITEM_SPEED_NUT:
    case ITEM_TIPTOE_NUT:
    case ITEM_POWER_NUT:
    case ITEM_BEARNUT:
    case ITEM_SEE_ALL_NUT: {
      return ITEM_ROTTEN_NUT;
    }

    case ITEM_TASTY_MEAT: {
      return ITEM_ROTTEN_MEAT;
    }

    case ITEM_DROP_OF_SUN:
    case ITEM_TOMATO_JUICE: {
      return ITEM_ROTTEN_WATER;
    }

    case ITEM_RED_MUSHROOM:
    case ITEM_BLUE_MUSHROOM: {
      return ITEM_BAD_MUSHROOM;
    }

    default: {
      return ITEM_NONE;
    }
  }
}

NAKED void RotItem(s32 rotDelta) { INCCODE("asm/todo/RotItem.inc"); }

WIP void item_082427e0(void) {
#if MODERN
  s32 i;
  s32 val;
  for (i = 0; i < 48; i++) {
    SetItem(i, ITEM_NONE);
    SetRotCount(i, 0);
    UncoverChocolate(i);
  }
  for (i = 0; i < VALUABLE_CAP; i++) {
    SetValuable(i, ITEM_NONE);
  }

  val = prepare_08231510(0x6e) ? fetch_082316e4() : 0;
  if (val > 0) {
    if (prepare_08231510(0x69)) {
      for (; val != 0; val--) {
        TryAddItem(fetch_082316e4(), 0);
      }
    }
  }
#else
  INCCODE("asm/wip/item_082427e0.inc");
#endif
}

bool32 CheckEmptySlotExist(s32 category, item32_t n) {
  s32 i;
  switch (category) {
    case 0: {
      if (!IsValuable(n)) {
        for (i = 0; i < 16; i++) {
          if (GetNormalItemID(i) < 0) {
            return TRUE;
          }
        }
      } else {
        for (i = 0; i < VALUABLE_CAP; i++) {
          if (GetValuableItemID(i) < 0) {
            return TRUE;
          }
        }
      }
      break;
    }

    case 1: {
      if (GAME->unk_250 != 5) {
        for (i = 0; i < 16; i++) {
          if (GetWeaponID(i) == WEAPON_NONE) {
            return TRUE;
          }
        }
      }
      break;
    }

    case 2: {
      if (GAME->unk_250 != 5) {
        for (i = 0; i < 16; i++) {
          if (GAME->armors[i] < 0) {
            return TRUE;
          }
        }
      }
      break;
    }

    case 3:
    case 4: {
      if (GAME->unk_250 != 5) {
        return TRUE;
      }
      break;
    }
  }

  return FALSE;
}

bool32 item_0824292c(void) {
  if (prepare_08231510(0x6b) == 0) {
    return FALSE;
  } else {
    u32 category = fetch_082316e4();
    if (prepare_08231510(0x69)) {
      item32_t n = fetch_082316e4();
      return CheckEmptySlotExist(category, n);
    }
  }
  return FALSE;
}
