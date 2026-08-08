#include "entity.h"
#include "global.h"

void* FUN_0807f20c(Player* p);
void* FUN_0807f330(Player* p);
void FUN_08065200(Player* p);
void* FUN_08065270(Player* p);
void* FUN_08065744(Player* p, u32 n);
void FUN_080659e8(Player* p);
void FUN_08065164(Player* p);
void weapon_08065924(Player* p);
void armor_08065988(Player* p);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void FUN_08063b6c(Player* p);
void FUN_0807ddbc(Player* p);
void FUN_08065240(Player* p);
void FUN_0807ed04(Player* p);

static s32 FUN_0807f3ac(Player* p, u32 n, void* _) {
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
  u16_03002b98++;
  if (p->unk_28 == 0) {
    FUN_0807ed04(p);
    FUN_0809c464();
  }
  return 0;
}

Player* CreatePlayer_0807f430(u32 n, void* _) {
  s32 ok;
  Player* p = (Player*)CreateEntity(ENTITY_PLAYER, sizeof(Player));
  if (p != NULL) {
    SetEntityRoutine((Entity*)p, (EntityFunc)FUN_0807f20c, (EntityFunc)FUN_0807f330);
    ok = (s32)FUN_0807f3ac(p, n, _);
    if (ok < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
