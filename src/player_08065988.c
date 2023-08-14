#include "armor.h"
#include "global.h"
#include "player.h"
#include "weapon.h"

void FUN_08064a64(struct Player *p, const struct ArmorData *a);

void FUN_08065240(struct Player *p) {
  if (prepare_08231510(0x52) != 0) {
    p->unk_9c4 = fetch_082316e4();
  } else {
    p->unk_9c4 = 0;
  }
}

NAKED void *FUN_08065270(struct Player *p) { INCCODE("asm/todo/FUN_08065270.inc"); }

NAKED void FUN_0806540c(struct Player *p) { INCCODE("asm/todo/FUN_0806540c.inc"); }
NAKED void FUN_08065514(struct Player *p) { INCCODE("asm/todo/FUN_08065514.inc"); }

NAKED bool32 FUN_08065744(struct Player *p, u32 n) { INCCODE("asm/todo/FUN_08065744.inc"); }

void weapon_08065924(struct Player *p) {
  struct Weapon *w;

  if (p->kind != PLAYER_SABATA) {
    if (REGISTERED_WEAPON(GAME->equippedWeaponIdx) >= 0) {
      weapon_08064664(p, GetWeapon(REGISTERED_WEAPON(GAME->equippedWeaponIdx)));
    } else {
      weapon_08064664(p, NULL);
    }
  } else {
    weapon_08064664(p, NULL);
    if (p->unk_18 == NULL) {
      SetWeaponFoundFlag(WEAPON_GUN_DEL_HELL);
    }
  }
}

void armor_08065988(struct Player *p) {
  const struct ArmorData *a;

  if (p->kind != PLAYER_SABATA) {
    if (GAME->armor < 0) {
      a = NULL;
    } else {
      a = &gArmorDB[ARMORS(GAME->armor)];
    }
  } else {
    SetArmorFoundFlag(ARMOR_MAIL_OF_LUNA);
    a = &gArmorDB[ARMOR_MAIL_OF_LUNA];
  }

  FUN_08064a64(p, a);
}
