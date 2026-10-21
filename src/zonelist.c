#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "vm.h"

// '.m' が並べるマップエリアの一覧を持つだけのエンティティ
typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_4
  ZoneID32 zones[16];  // 0x18, 今いるマップの ZoneData のID全部が入るわけではない (例えば、サンミゲル(HP_8F62)では 0xA679 しか入らない)
} ZoneList;
static_assert(sizeof(ZoneList) == 88);

static ZoneList* sZoneList;  // 0x03001704

COMMON_DATA u32 u32_03004860 = 0;  // 0x03004860

// pos がどのマップエリアの矩形群に入っているかを調べ、その ZoneID32 を返す (見つからなかったら -1)
ZoneID32 GetZoneAt(Vec3* pos) {
  ZoneList* p = sZoneList;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  for (i = 0; i < 16; i++) {
    if (p->zones[i] <= 0) {
      return -1;
    }
    if (Map_IsPosInZoneByID(p->zones[i], pos)) {
      return p->zones[i];
    }
  }
  return -1;
}

s32 ZoneList_Update(ZoneList* p) { return 0; }

s32 ZoneList_Destroy(ZoneList* p) {
  sZoneList = NULL;
  u32_03004860 = 0;
  return 0;
}

// '.m' が並べるエリアIDを zones に詰める, 要素数の上限は見ていない
s32 ZoneList_Init(ZoneList* p, u32 unused1, u32 unused2) {
  if (VM_SeekToNamedArg('m')) {
    s32* zones = p->zones;

    while (VM_GetPC() != NULL) {
      *zones++ = VM_GetValue();
    }
  }
  sZoneList = p;
  return 0;
}

// 0xB639
ZoneList* ZoneList_Create(u32 unused1, u32 unused2) {
  ZoneList* p = CreateEntity(ENTITY_UNK_4, sizeof(ZoneList));

  if (p != NULL) {
    SetEntityRoutine(p, ZoneList_Update, ZoneList_Destroy);
    if (ZoneList_Init(p, unused1, unused2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
