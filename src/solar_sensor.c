#include "solar_sensor.h"

#include "global.h"
#include "player.h"

// 0x030026B0 から 0x030026C4 までの6つ。以前は SolarSensorInterface という1つの構造体として書いていたが、
// Sensor_GetState が =0x030026B4 を直接読む (構造体なら =gSSI + [r0,#4] になる) ので、原典では個別のグローバルだった
// ゲームが太陽センサーとやり取りするための(高レベルな)インターフェース。SolarSensorManager との違いはまだ不明
// agbrtc と IWRAM が隣接していて、 agbrtc が 0x030026c8 から始まる、つまり16バイトアラインされていないので、 GBA SDKのライブラリ由来の可能性もある (わからん)
IWRAM_DATA SolarSensorEntity* gSensorEntity = NULL;  // .bss, 0x030026B0
IWRAM_DATA s32 gSensorState = 0;                     // 0x030026B4, 0: measuring, 1: resetting, 2: idle
IWRAM_DATA s32 gSensorCounter = 0;                   // 0x030026B8, 0-511, counts half-cycles of the 74LV4040 counter chip
IWRAM_DATA s32 gSensorUnk0c = 0;                     // 0x030026BC
IWRAM_DATA s32 gSensorNextWrite = 0;                 // 0x030026C0, next value to be written to GPIO_DATA
IWRAM_DATA bool32 gSensorUnk14 = 0;                  // 0x030026C4
// 0x030057B0 から 0x030057CC までの8つ。上のグローバル群が高レベルなら、こちらは低レベルなドライバ側だと思われる
// これも以前は SolarSensorManager という1つの構造体だったが、Sensor_Disable が 0x030057B8 と 0x030057C8 を
// 別々のプール定数として読む (構造体なら1回のロード + オフセットになる) ので、原典では個別のグローバル
COMMON_DATA u32 gSensorDrvUnk00 = 0;    // 0x030057B0
COMMON_DATA u32 gSensorDrvUnk04 = 0;    // 0x030057B4
COMMON_DATA bool32 gSensorEnabled = 0;  // 0x030057B8
COMMON_DATA u32 gSensorGpioData = 0;    // 0x030057BC, last read GPIO data (GPIO_DATA & 8)
COMMON_DATA s32 gSensorDrvUnk10 = 0;    // 0x030057C0
COMMON_DATA s32 gSensorDrvUnk14 = 0;    // 0x030057C4
COMMON_DATA s32 gSensorRawLevel = 0;    // 0x030057C8, light level (0: Max brightness, 0xFF: Dark)
COMMON_DATA s32 gSensorDrvUnk1c = 0;    // 0x030057CC, おそらく Sensor_Tick の周期

const u16 u16_ARRAY_08dbd810[4] = {3, 3, 1, 2};  // 0x08DBD810

NAKED void FUN_08246660(void) { INCFUNC("asm/func/FUN_08246660.inc"); }

// kind 0 の更新。何もしない
void SSEEmitter_UpdateIdle(SolarSensorEntity* e, SSEEmitter* p) {}

// エミッタをリストの先頭に繋ぐ。既に繋がっていれば -1
s32 SSEEmitter_Register(SolarSensorEntity* e, SSEEmitter* p) {
  if (p->isRegistered != 0) {
    return -1;
  }
  p->prev = NULL;
  p->next = e->unk_20;
  if (p->next != NULL) {
    p->next->prev = p;
  }
  e->unk_20 = p;
  p->isRegistered = 1;
  return 0;
}

// エミッタをリストから外す。繋がっていなければ -1
s32 SSEEmitter_Unregister(SolarSensorEntity* e, SSEEmitter* p) {
  SSEEmitter* prev = p->prev;
  SSEEmitter* next = p->next;

  if (p->isRegistered == 0) {
    return -1;
  }
  if (prev != NULL) {
    prev->next = next;
  } else {
    e->unk_20 = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  p->isRegistered = 0;
  return 0;
}

NAKED s32 FUN_082466ec(SSEEmitter* p) { INCFUNC("asm/func/FUN_082466ec.inc"); }

NAKED s32 FUN_08246728(SSEEmitter* p, s32 param_2, Vec3* param_3, Vec3* param_4, Vec3* param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_08246728.inc"); }

NAKED void* FUN_08246790(SSEEmitter* e) { INCFUNC("asm/func/FUN_08246790.inc"); }

NAKED s32 FUN_082467d0(SSEEmitter* e, u32 unk_1, u32 param_3, u32* param_4) { INCFUNC("asm/func/FUN_082467d0.inc"); }

// 枠を空きに戻して粒子を隠す
void SSEEmitterParticle_Clear(SSEEmitterParticle* ptcl) {
  ptcl->unk_0 = 0;
  ptcl->unk_2 = 0;
  ptcl->unk_1 = 10;
  ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
}

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

s32 SSE_Update(SolarSensorEntity* p) {
  SSEEmitter* e = p->unk_20;

  while (e != NULL) {
    e->fn_12c(p, e);
    e = e->next;
  }
  return 0;
}

s32 SSE_Destroy(SolarSensorEntity* _) {
  gSensorEntity = NULL;
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

void Sensor_Disable(void) {
  if (gSensorUnk14 == 1) {
    Sensor_DisableIO();
  }
  gSensorEnabled = FALSE;
  gSensorRawLevel = -1;
}

NAKED s32 Sensor_GetRawLevel(void) { INCFUNC("asm/func/Sensor_GetRawLevel.inc"); }

NAKED bool32 FUN_08247800(void) { INCFUNC("asm/func/FUN_08247800.inc"); }

s32 Sensor_GetState(void) { return gSensorState; }

NAKED s32 FUN_08247818(void) { INCFUNC("asm/func/FUN_08247818.inc"); }
