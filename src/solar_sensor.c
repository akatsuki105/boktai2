#include "solar_sensor.h"

#include "global.h"
#include "player.h"

IWRAM_DATA SolarSensorInterface gSSI = {};                // .bss, 0x030026B0
COMMON_DATA SolarSensorManager gSolarSensorManager = {};  // 0x030057B0

const u16 u16_ARRAY_08dbd810[4] = {3, 3, 1, 2};  // 0x08DBD810

NAKED void FUN_08246660(void) { INCFUNC("asm/func/FUN_08246660.inc"); }

INCASM("asm/solar_sensor1.inc");

NAKED void* FUN_08246790(SSEEmitter* p) { INCFUNC("asm/func/FUN_08246790.inc"); }

NAKED s32 FUN_082467d0(SSEEmitter* p, u32 unk_1, u32 param_3, u32* param_4) { INCFUNC("asm/func/FUN_082467d0.inc"); }

NAKED void FUN_082469bc(SSEEmitterParticle* p) { INCFUNC("asm/func/FUN_082469bc.inc"); }

void FUN_082469d0(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) {}

NAKED void FUN_082469d4(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_082469d4.inc"); }

NAKED void FUN_08246afc(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_08246afc.inc"); }

void FUN_08246c10(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) {}

NAKED void FUN_08246c14(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_08246c14.inc"); }

NAKED void FUN_08246d2c(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_08246d2c.inc"); }

void FUN_08246e5c(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) {}

NAKED void FUN_08246e60(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_08246e60.inc"); }

NAKED void FUN_08246f78(SolarSensorEntity* a, SSEEmitter* b, SSEEmitterParticle* c) { INCFUNC("asm/func/FUN_08246f78.inc"); }

void (*const PTR_ARRAY_08dbd818[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_082469d0,
    FUN_082469d4,
    FUN_08246afc,
};  // 0x08DBD818

NAKED void FUN_082470a8(SolarSensorEntity* a, SSEEmitter* b) { INCFUNC("asm/func/FUN_082470a8.inc"); }

void (*const PTR_ARRAY_08dbd824[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_08246c10,
    FUN_08246c14,
    FUN_08246d2c,
};  // 0x08DBD824

NAKED void FUN_08247194(SolarSensorEntity* a, SSEEmitter* b) { INCFUNC("asm/func/FUN_08247194.inc"); }

void (*const PTR_ARRAY_08dbd830[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_08246e5c,
    FUN_08246e60,
    FUN_08246f78,
};  // 0x08DBD830

NAKED void FUN_08247280(SolarSensorEntity* a, SSEEmitter* b) { INCFUNC("asm/func/FUN_08247280.inc"); }

NAKED s32 SSE_Update(SolarSensorEntity* p) { INCFUNC("asm/func/SSE_Update.inc"); }

s32 SSE_Destroy(SolarSensorEntity* _) {
  gSSI.e = NULL;
  return 0;
}

NAKED s32 SSE_Init(SolarSensorEntity* p, u32 _) { INCFUNC("asm/func/SSE_Init.inc"); }

NAKED SolarSensorEntity* SSE_Create(u32 _) { INCFUNC("asm/func/SSE_Create.inc"); }

NAKED s32 FUN_0824742c(SSEEmitter* p, u32 unk_8, s32 unk_1, s32 unk_4, s32 unk_5) { INCFUNC("asm/func/FUN_0824742c.inc"); }

NAKED s32 FUN_08247504(unknown* p) { INCFUNC("asm/func/FUN_08247504.inc"); }

NAKED void Sensor_DoEnableIO(void) { INCFUNC("asm/func/Sensor_DoEnableIO.inc"); }

INCASM("asm/solar_sensor.inc");

NAKED s32 FUN_08247818(void) { INCFUNC("asm/func/FUN_08247818.inc"); }
