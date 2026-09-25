#include "entity.h"
#include "global.h"

// スクリプトのキーワード 'm' が並べるマップエリアの一覧を持つだけのエンティティ
typedef struct {
  Entity e;       // 0x0, ENTITY_UNK_4
  s32 areas[16];  // 0x18, エリアIDの一覧。GetMapAreaAt が先頭から走査し 0 以下で打ち切る。下位16bitが矩形リストのファイルID
} MapAreaManager;
static_assert(sizeof(MapAreaManager) == 88);

IWRAM_DATA MapAreaManager* gMapAreaManager = NULL;  // 0x03001704
COMMON_DATA u32 u32_03004860 = 0;                   // 0x03004860

NAKED s32 GetMapAreaAt(Vec3* pos) { INCFUNC("asm/func/GetMapAreaAt.inc"); }

s32 MapAreaManager_Update(MapAreaManager* p) { return 0; }

s32 MapAreaManager_Destroy(MapAreaManager* p) {
  gMapAreaManager = NULL;
  u32_03004860 = 0;
  return 0;
}

NAKED s32 MapAreaManager_Init(MapAreaManager* p, u32 unused1, void* unused2) { INCFUNC("asm/func/MapAreaManager_Init.inc"); }

NAKED MapAreaManager* MapAreaManager_Create(u32 unused1, void* unused2) { INCFUNC("asm/func/MapAreaManager_Create.inc"); }
