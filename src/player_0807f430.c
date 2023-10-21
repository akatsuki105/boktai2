#include "entity.h"
#include "global.h"

void *FUN_0807f20c(struct Player *p);
void *FUN_0807f330(struct Player *p);
void FUN_08065200(struct Player *p);
void *FUN_08065270(struct Player *p);
void *FUN_08065744(struct Player *p, u32 n);
void FUN_080659e8(struct Player *p);
void FUN_08065164(struct Player *p);
void weapon_08065924(struct Player *p);
void armor_08065988(struct Player *p);
void CheckHeartJokerEmblem(struct Player *p);
void FUN_08061294(struct Player *p);
void FUN_08063b6c(struct Player *p);
void FUN_0807ddbc(struct Player *p);
void FUN_08065240(struct Player *p);
void FUN_0807ed04(struct Player *p);

static s32 FUN_0807f3ac(struct Player *p, u32 n, void *_) {
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

struct Player *CreatePlayer_0807f430(u32 n, void *_) {
  s32 ok;
  struct Player *p = (struct Player *)CreateEntity(ENTITY_PLAYER, 0xAC4);
  if (p != NULL) {
    SetEntityRoutine((struct Entity *)p, (EntityFunc)FUN_0807f20c, (EntityFunc)FUN_0807f330);
    ok = (s32)FUN_0807f3ac(p, n, _);
    if (ok < 0) {
      KillEntity((struct Entity *)p);
      return NULL;
    }
  }
  return p;
}
