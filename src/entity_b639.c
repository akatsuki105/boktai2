#include "entity.h"
#include "global.h"
#include "vm.h"

// '.m' が並べるマップエリアの一覧を持つだけのエンティティ
typedef struct {
  Entity e;       // 0x0, ENTITY_UNK_4
  s32 areas[16];  // 0x18, エリアIDの一覧。GetMapAreaAt が先頭から走査し 0 以下で打ち切る。下位16bitがZoneID
} MapAreaManager;
static_assert(sizeof(MapAreaManager) == 88);

bool8 FUN_08234d50(u16 zoneID, Vec3* pos);

IWRAM_DATA MapAreaManager* gMapAreaManager = NULL;  // 0x03001704
COMMON_DATA u32 u32_03004860 = 0;                   // 0x03004860

// pos がどのマップエリアの矩形群に入っているかを調べ、そのエリアIDを返す
s32 GetMapAreaAt(Vec3* pos) {
  MapAreaManager* p = gMapAreaManager;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  for (i = 0; i < 16; i++) {
    if (p->areas[i] <= 0) {
      return -1;
    }
    if (FUN_08234d50(p->areas[i], pos)) {
      return p->areas[i];
    }
  }
  return -1;
}

s32 MapAreaManager_Update(MapAreaManager* p) { return 0; }

s32 MapAreaManager_Destroy(MapAreaManager* p) {
  gMapAreaManager = NULL;
  u32_03004860 = 0;
  return 0;
}

// スクリプトのキーワード 'm' が並べるエリアIDを areas に詰める。要素数の上限は見ていない
s32 MapAreaManager_Init(MapAreaManager* p, u32 unused1, u32 unused2) {
  if (VM_SeekToKeyword('m')) {
    s32* area = p->areas;

    while (VM_GetPC() != NULL) {
      *area++ = Script_GetValue();
    }
  }
  gMapAreaManager = p;
  return 0;
}

MapAreaManager* MapAreaManager_Create(u32 unused1, u32 unused2) {
  MapAreaManager* p = CreateEntity(ENTITY_UNK_4, sizeof(MapAreaManager));

  if (p != NULL) {
    SetEntityRoutine(p, MapAreaManager_Update, MapAreaManager_Destroy);
    if (MapAreaManager_Init(p, unused1, unused2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
