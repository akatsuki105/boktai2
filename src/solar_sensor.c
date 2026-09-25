#include "solar_sensor.h"

#include "global.h"
#include "player.h"

// SolarSensorManager との違いはまだ不明
// Entityを持っているのでゲームが太陽センサーとやり取りするための(高レベルな)インターフェースの可能性が高い
// ただ、 agbrtc と IWRAM が隣接していて、 agbrtc が 0x030026c8 から始まる、つまり16バイトアラインされていないので、 GBA SDKのライブラリ由来の可能性もある (わからん)
typedef struct {
  SolarSensorEntity* e;  // 0x00
  s32 state;             // 0x04, 0: measuring, 1: resetting, 2: idle
  s32 counter;           // 0x08, 0-511, counts half-cycles of the 74LV4040 counter chip
  s32 unk_0c;            // 0x0C
  s32 nextWrite;         // 0x10, next value to be written to GPIO_DATA
  bool32 unk_14;         // 0x14
} SolarSensorInterface;
static_assert(sizeof(SolarSensorInterface) == 24);

// SolarSensorInterface が高レベルなインターフェースだったなら、こっちは低レベルなインターフェース(ドライバ)だと思われる (まだ調査が不十分なので間違ってる可能性もある)
typedef struct {
  u32 unk_00;        // 0x00
  u32 unk_04;        // 0x04
  bool32 isEnabled;  // 0x08
  u32 gpiodata;      // 0x0C, last read GPIO data (GPIO_DATA & 8)
  s32 unk_10;        // 0x10
  s32 unk_14;        // 0x14
  s32 rawLevel;      // 0x18, light level (0: Max brightness, 0xFF: Dark)
  s32 unk_1c;        // 0x1C, おそらく Sensor_Tick の周期
} SolarSensorManager;
static_assert(sizeof(SolarSensorManager) == 32);

IWRAM_DATA SolarSensorInterface gSSI = {};                // .bss, 0x030026B0
COMMON_DATA SolarSensorManager gSolarSensorManager = {};  // 0x030057B0

const u16 u16_ARRAY_08dbd810[4] = {3, 3, 1, 2};  // 0x08DBD810

NAKED void FUN_08246660(void) { INCFUNC("asm/func/FUN_08246660.inc"); }

NAKED void SSEEmitter_UpdateIdle(SolarSensorEntity* e, SSEEmitter* p) { INCFUNC("asm/func/SSEEmitter_UpdateIdle.inc"); }

NAKED s32 SSEEmitter_Register(SolarSensorEntity* e, SSEEmitter* p) { INCFUNC("asm/func/SSEEmitter_Register.inc"); }

NAKED s32 SSEEmitter_Unregister(SolarSensorEntity* e, SSEEmitter* p) { INCFUNC("asm/func/SSEEmitter_Unregister.inc"); }

NAKED s32 FUN_082466ec(SSEEmitter* p) { INCFUNC("asm/func/FUN_082466ec.inc"); }

NAKED s32 FUN_08246728(SSEEmitter* p, s32 param_2, Vec3* param_3, Vec3* param_4, Vec3* param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_08246728.inc"); }

NAKED void* FUN_08246790(SSEEmitter* e) { INCFUNC("asm/func/FUN_08246790.inc"); }

NAKED s32 FUN_082467d0(SSEEmitter* e, u32 unk_1, u32 param_3, u32* param_4) { INCFUNC("asm/func/FUN_082467d0.inc"); }

NAKED void FUN_082469bc(SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_082469bc.inc"); }

void FUN_082469d0(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) {}

NAKED void FUN_082469d4(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_082469d4.inc"); }

NAKED void FUN_08246afc(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_08246afc.inc"); }

void FUN_08246c10(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) {}

NAKED void FUN_08246c14(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_08246c14.inc"); }

NAKED void FUN_08246d2c(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_08246d2c.inc"); }

void FUN_08246e5c(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) {}

NAKED void FUN_08246e60(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_08246e60.inc"); }

NAKED void FUN_08246f78(SolarSensorEntity* p, SSEEmitter* e, SSEEmitterParticle* ptcl) { INCFUNC("asm/func/FUN_08246f78.inc"); }

void (*const PTR_ARRAY_08dbd818[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_082469d0,
    FUN_082469d4,
    FUN_08246afc,
};  // 0x08DBD818

NAKED void FUN_082470a8(SolarSensorEntity* p, SSEEmitter* e) { INCFUNC("asm/func/FUN_082470a8.inc"); }

void (*const PTR_ARRAY_08dbd824[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_08246c10,
    FUN_08246c14,
    FUN_08246d2c,
};  // 0x08DBD824

NAKED void FUN_08247194(SolarSensorEntity* p, SSEEmitter* e) { INCFUNC("asm/func/FUN_08247194.inc"); }

void (*const PTR_ARRAY_08dbd830[3])(SolarSensorEntity*, SSEEmitter*, SSEEmitterParticle*) = {
    FUN_08246e5c,
    FUN_08246e60,
    FUN_08246f78,
};  // 0x08DBD830

NAKED void FUN_08247280(SolarSensorEntity* p, SSEEmitter* e) { INCFUNC("asm/func/FUN_08247280.inc"); }

NAKED s32 SSE_Update(SolarSensorEntity* p) { INCFUNC("asm/func/SSE_Update.inc"); }

s32 SSE_Destroy(SolarSensorEntity* _) {
  gSSI.e = NULL;
  return 0;
}

NAKED s32 SSE_Init(SolarSensorEntity* p, u32 _) { INCFUNC("asm/func/SSE_Init.inc"); }

NAKED SolarSensorEntity* SSE_Create(u32 _) { INCFUNC("asm/func/SSE_Create.inc"); }

NAKED s32 FUN_0824742c(SSEEmitter* e, u32 unk_8, s32 unk_1, s32 unk_4, s32 unk_5) { INCFUNC("asm/func/FUN_0824742c.inc"); }

NAKED s32 FUN_08247504(unknown* p) { INCFUNC("asm/func/FUN_08247504.inc"); }

NAKED void Sensor_DoEnableIO(void) { INCFUNC("asm/func/Sensor_DoEnableIO.inc"); }

NAKED void Sensor_DoDisableIO(void) { INCFUNC("asm/func/Sensor_DoDisableIO.inc"); }

NAKED void Sensor_Tick(void) { INCFUNC("asm/func/Sensor_Tick.inc"); }

NAKED void Sensor_EnableIO(void) { INCFUNC("asm/func/Sensor_EnableIO.inc"); }

NAKED void Sensor_DisableIO(void) { INCFUNC("asm/func/Sensor_DisableIO.inc"); }

NAKED void Sensor_Enable(void) { INCFUNC("asm/func/Sensor_Enable.inc"); }

NAKED void Sensor_Disable(void) { INCFUNC("asm/func/Sensor_Disable.inc"); }

NAKED s32 Sensor_GetRawLevel(void) { INCFUNC("asm/func/Sensor_GetRawLevel.inc"); }

NAKED bool32 FUN_08247800(void) { INCFUNC("asm/func/FUN_08247800.inc"); }

NAKED s32 Sensor_GetState(void) { INCFUNC("asm/func/Sensor_GetState.inc"); }

NAKED s32 FUN_08247818(void) { INCFUNC("asm/func/FUN_08247818.inc"); }
