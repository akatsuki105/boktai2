#include "entity.h"
#include "global.h"

void FUN_08065200(Player* p);
void* FUN_08065270(Player* p);
void* FUN_08065744(Player* p, u32 n);
void FUN_08065164(Player* p);
void weapon_08065924(Player* p);
void armor_08065988(Player* p);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void FUN_08063b6c(Player* p);
void FUN_0807ddbc(Player* p);
void FUN_08065240(Player* p);

NAKED void FUN_080659e8(Player* p) { INCFUNC("asm/func/FUN_080659e8.inc"); }

NAKED bool32 FUN_08065a98(u32 val) { INCFUNC("asm/func/FUN_08065a98.inc"); }

NAKED bool32 FUN_08065ad0(u32 val) { INCFUNC("asm/func/FUN_08065ad0.inc"); }

NAKED bool32 FUN_08065b08(u32 val) { INCFUNC("asm/func/FUN_08065b08.inc"); }

NAKED bool32 FUN_08065b44(u32 val) { INCFUNC("asm/func/FUN_08065b44.inc"); }

NAKED void FUN_08065b7c(Player* p) { INCFUNC("asm/func/FUN_08065b7c.inc"); }

NAKED s32 FUN_08065cb8(Player* p) { INCFUNC("asm/func/FUN_08065cb8.inc"); }

NAKED void FUN_08065dac(Player* p) { INCFUNC("asm/func/FUN_08065dac.inc"); }

NAKED s32 FUN_08065e24(Player* p) { INCFUNC("asm/func/FUN_08065e24.inc"); }

INCASM("asm/player_08065988.inc");

NAKED void FUN_0807e854(Player* p) { INCFUNC("asm/func/FUN_0807e854.inc"); }

NAKED bool32 FUN_0807e968(Player* p) { INCFUNC("asm/func/FUN_0807e968.inc"); }

NAKED void FUN_0807eca8(Player* p) { INCFUNC("asm/func/FUN_0807eca8.inc"); }

NAKED void FUN_0807ed04(Player* p) { INCFUNC("asm/func/FUN_0807ed04.inc"); }

NAKED void FUN_0807ee58(Player* p) { INCFUNC("asm/func/FUN_0807ee58.inc"); }

NAKED void FUN_0807f0bc(Player* p) { INCFUNC("asm/func/FUN_0807f0bc.inc"); }

NAKED void dark_django_0807f13c(Player* p) { INCFUNC("asm/func/dark_django_0807f13c.inc"); }

NAKED static s32 Player_Update(Player* p) { INCFUNC("asm/func/Player_Update.inc"); }

NAKED static s32 Player_Destroy(Player* p) { INCFUNC("asm/func/Player_Destroy.inc"); }

static s32 Player_Init(Player* p, u32 n, void* _) {
  FUN_08065200(p);
  FUN_08065270(p);
  FUN_08065744(p, n);
  FUN_080659e8(p);
  FUN_08065164(p);
  weapon_08065924(p);
  armor_08065988(p);
  CheckHeartJokerEmblem(p);
  FUN_08061294(p);
  FUN_08063b6c(p);
  FUN_0807ddbc(p);
  FUN_08065240(p);
  gPlayerPtr[p->unk_28] = p;
  gPlayerCount++;
  if (p->unk_28 == 0) {
    FUN_0807ed04(p);
    FUN_0809c464();
  }
  return 0;
}

// エリア移動などでも呼ばれる
Player* CreatePlayer(u32 n, void* _) {
  s32 ok;
  Player* p = (Player*)CreateEntity(ENTITY_PLAYER, sizeof(Player));
  if (p != NULL) {
    SetEntityRoutine(p, Player_Update, Player_Destroy);
    ok = Player_Init(p, n, _);
    if (ok < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
