#include "solar_sensor.h"

#include "global.h"
#include "player.h"

IWRAM_DATA SolarSensorInterface gSSI = {};                // .bss, 0x030026B0
COMMON_DATA SolarSensorManager gSolarSensorManager = {};  // 0x030057B0

NAKED void FUN_08246660(void) { INCFUNC("asm/func/FUN_08246660.inc"); }

INCASM("asm/solar_sensor1.inc");

NAKED void* FUN_08246790(Player4c4* p) { INCFUNC("asm/func/FUN_08246790.inc"); }

NAKED s32 FUN_082467d0(Player4c4* p, u32 unk_1, u32 param_3, u32* param_4) { INCFUNC("asm/func/FUN_082467d0.inc"); }

NAKED void FUN_082469bc(Player4c4_0c* p) { INCFUNC("asm/func/FUN_082469bc.inc"); }

void FUN_082469d0(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) {}

NAKED void FUN_082469d4(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_082469d4.inc"); }

NAKED void FUN_08246afc(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_08246afc.inc"); }

void FUN_08246c10(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) {}

NAKED void FUN_08246c14(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_08246c14.inc"); }

NAKED void FUN_08246d2c(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_08246d2c.inc"); }

void FUN_08246e5c(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) {}

NAKED void FUN_08246e60(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_08246e60.inc"); }

NAKED void FUN_08246f78(SolarSensorEntity* a, Player4c4* b, Player4c4_0c* c) { INCFUNC("asm/func/FUN_08246f78.inc"); }

NAKED void FUN_082470a8(SolarSensorEntity* a, Player4c4* b) { INCFUNC("asm/func/FUN_082470a8.inc"); }

NAKED void FUN_08247194(SolarSensorEntity* a, Player4c4* b) { INCFUNC("asm/func/FUN_08247194.inc"); }

NAKED void FUN_08247280(SolarSensorEntity* a, Player4c4* b) { INCFUNC("asm/func/FUN_08247280.inc"); }

NAKED s32 SSE_Update(SolarSensorEntity* p) { INCFUNC("asm/func/SSE_Update.inc"); }

s32 SSE_Destroy(SolarSensorEntity* _) {
  gSSI.e = NULL;
  return 0;
}

NAKED s32 SSE_Init(SolarSensorEntity* p, u32 _) { INCFUNC("asm/func/SSE_Init.inc"); }

NAKED SolarSensorEntity* SSE_Create(u32 _) { INCFUNC("asm/func/SSE_Create.inc"); }

NAKED s32 FUN_0824742c(Player4c4* p, u32 unk_8, s32 unk_1, s32 unk_4, s32 unk_5) { INCFUNC("asm/func/FUN_0824742c.inc"); }

NAKED s32 FUN_08247504(unknown* p) { INCFUNC("asm/func/FUN_08247504.inc"); }

NAKED void Sensor_DoEnableIO(void) { INCFUNC("asm/func/Sensor_DoEnableIO.inc"); }

INCASM("asm/solar_sensor.inc");

NAKED s32 FUN_08247818(void) { INCFUNC("asm/func/FUN_08247818.inc"); }
