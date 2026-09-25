#include "solar_sensor.h"

#include "file.h"
#include "global.h"
#include "interrupts.h"
#include "player.h"

s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
void Sensor_Tick(void);

// 0x030026B0 から 0x030026C4 までの6つ。以前は SolarSensorInterface という1つの構造体として書いていたが、
// Sensor_GetState が =0x030026B4 を直接読む (構造体なら =gSSI + [r0,#4] になる) ので、原典では個別のグローバルだった
// ゲームが太陽センサーとやり取りするための(高レベルな)インターフェース。SolarSensorManager との違いはまだ不明
// agbrtc と IWRAM が隣接していて、 agbrtc が 0x030026c8 から始まる、つまり16バイトアラインされていないので、 GBA SDKのライブラリ由来の可能性もある (わからん)
IWRAM_DATA SolarSensorEntity* gSensorEntity = NULL;  // .bss, 0x030026B0
IWRAM_DATA s32 gSensorState = 0;                     // 0x030026B4, Sensor_Tick の状態。0: リセット中, 1: 計測中, 2: 待機
IWRAM_DATA s32 gSensorCounter = 0;                   // 0x030026B8, 0-511, counts half-cycles of the 74LV4040 counter chip
IWRAM_DATA s32 gSensorUnk0c = 0;                     // 0x030026BC, 計測中のセンサー出力の最後の値。ROM 内に読む箇所なし
IWRAM_DATA s32 gSensorNextWrite = 0;                 // 0x030026C0, next value to be written to GPIO_DATA
IWRAM_DATA bool32 gSensorIoEnabled = FALSE;          // 0x030026C4
// 0x030057B0 から 0x030057CC までの8つ。上のグローバル群が高レベルなら、こちらは低レベルなドライバ側だと思われる
// これも以前は SolarSensorManager という1つの構造体だったが、Sensor_Disable が 0x030057B8 と 0x030057C8 を
// 別々のプール定数として読む (構造体なら1回のロード + オフセットになる) ので、原典では個別のグローバル
COMMON_DATA u32 gSensorDrvUnk00 = 0;        // 0x030057B0, Sensor_DoEnableIO が 0xFF を書くだけで読む箇所なし
COMMON_DATA u32 gSensorDrvUnk04 = 0;        // 0x030057B4, 有効化時の GPIO_PORT_DATA の控え。読む箇所なし
COMMON_DATA bool32 gSensorEnabled = FALSE;  // 0x030057B8
COMMON_DATA u32 gSensorGpioData = 0;        // 0x030057BC, last read GPIO data (GPIO_DATA & 8)
COMMON_DATA s32 gSensorDrvUnk10 = 0;        // 0x030057C0, Sensor_DoEnableIO が 1 を書くだけで読む箇所なし
COMMON_DATA s32 gSensorDrvUnk14 = 0;        // 0x030057C4, Sensor_DoEnableIO が 4 を書くだけで読む箇所なし
COMMON_DATA s32 gSensorRawLevel = 0;        // 0x030057C8, light level (0: Max brightness, 0xFF: Dark)
COMMON_DATA s32 gSensorTickPeriod = 0;      // 0x030057CC, Sensor_Tick の周期。タイマー3 に -gSensorTickPeriod を再装填する

const u16 u16_ARRAY_08dbd810[4] = {3, 3, 1, 2};  // 0x08DBD810

// エンティティを消さずにシングルトンの参照だけ手放す
void SSE_ClearGlobal(void) { gSensorEntity = NULL; }

// kind 0 の更新。何もしない
void SSEEmitter_UpdateIdle(SolarSensorEntity* e, SSEEmitter* p) {}

// エミッタをリストの先頭に繋ぐ。既に繋がっていれば -1
s32 SSEEmitter_Register(SolarSensorEntity* e, SSEEmitter* p) {
  if (p->isRegistered != 0) {
    return -1;
  }
  p->prev = NULL;
  p->next = e->emitters;
  if (p->next != NULL) {
    p->next->prev = p;
  }
  e->emitters = p;
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
    e->emitters = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  p->isRegistered = 0;
  return 0;
}

// 生きている枠をひとつだけ消えかけ (state 2) にする
s32 SSEEmitter_FadeParticle(SSEEmitter* p) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    SSEEmitterParticle* ptcl = &p->ptcls[i];
    if (ptcl->unk_0 == 1) {
      ptcl->unk_0 = 2;
      ptcl->unk_1 = 10;
      ptcl->unk_2 = 0;
      found = TRUE;
      break;
    }
  }
  if (found) {
    p->unk_3--;
  }
  return 0;
}

// 生きている枠をひとつ解放して、その場に粒子を撒き散らす
s32 SSEEmitter_BurstParticle(SSEEmitter* p, s32 count, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].unk_0 == 1) {
      Particle_Hide(&p->ptcls[i].ptcl);
      p->ptcls[i].unk_0 = 0;
      p->ptcls[i].unk_1 = 10;
      p->ptcls[i].unk_2 = 0;
      found = TRUE;
      FUN_08014730(count, p->kind, pos, vel, velRange, lifeBase, lifeRandMask);
      break;
    }
  }
  if (found) {
    p->unk_3--;
    p->activeCount--;
  }
  return 0;
}

// エミッタを待機状態に戻す。枠は全部空きにして粒子も隠す
void* SSEEmitter_Reset(SSEEmitter* p) {
  s32 i;

  p->activeCount = 0;
  p->unk_3 = 0;
  p->kind = 0;
  p->fn_12c = SSEEmitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    p->ptcls[i].unk_0 = 0;
    p->ptcls[i].unk_2 = 0;
    p->ptcls[i].unk_1 = 10;
    Particle_Hide(&p->ptcls[i].ptcl);
  }
}

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
  SSEEmitter* e = p->emitters;

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

s32 SSE_Init(SolarSensorEntity* p, u32 _) {
  gSensorEntity = p;
  p->emitters = NULL;
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
  return 0;
}

SolarSensorEntity* SSE_Create(u32 unused1, u32 unused2) {
  if (gSensorEntity == NULL) {
    SolarSensorEntity* p = CreateEntity(ENTITY_UNK_9, sizeof(SolarSensorEntity));
    if (p != NULL) {
      SetEntityRoutine(p, SSE_Update, SSE_Destroy);
      if (SSE_Init(p, unused1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gSensorEntity;
}

// エミッタを初期化して SolarSensorEntity に登録する。エンティティがまだ無ければ先に作る
s32 SSEEmitter_Init(SSEEmitter* e, Vec3* pos, s32 kind, s32 unk_4, s32 unk_5) {
  SolarSensorEntity* p = gSensorEntity;
  s32 i;

  if (p == NULL) {
    p = SSE_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  e->isRegistered = 0;
  e->pos = pos;
  e->activeCount = 0;
  e->unk_3 = 0;
  e->kind = kind;
  e->unk_4 = unk_4;
  e->unk_5 = unk_5;
  e->fn_12c = SSEEmitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    e->ptcls[i].unk_0 = 0;
    e->ptcls[i].unk_2 = 0;
    e->ptcls[i].pos.x = 0, e->ptcls[i].pos.y = 0, e->ptcls[i].pos.z = 0;
    FUN_0822d9f0(&e->ptcls[i].ptcl, gSensorEntity->group, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    Particle_SetOffset(&e->ptcls[i].ptcl, -8, -8);
    e->ptcls[i].ptcl.priority = 2;
    FUN_08236fac(&e->ptcls[i].anim, gSensorEntity->anim, 0, 0, 0);
  }
  SSEEmitter_Register(p, e);
  return 0;
}

// エミッタの後始末。粒子を消してリストから外す
s32 SSEEmitter_Destroy(SSEEmitter* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  if (gSensorEntity != NULL) {
    SSEEmitter_Unregister(gSensorEntity, p);
  }
  return 0;
}

// GPIO をセンサー読み出し用に開き、タイマー3 の割り込みで Sensor_Tick を回し始める
void Sensor_DoEnableIO(void) {
  u16 ie;

  gSensorNextWrite = (gSensorNextWrite & ~2) | 1;
  gSensorState = 0;
  gSensorCounter = 0;
  gSensorEnabled = FALSE;
  gSensorTickPeriod = 0x3128;
  gSensorDrvUnk10 = 1;
  gSensorDrvUnk00 = 0xFF;
  gSensorDrvUnk14 = 4;
  gSensorRawLevel = -1;
  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_L = 0;
  REG_TM3CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE;
  gIntrTable[2] = Sensor_Tick;
  gSensorDrvUnk04 = GPIO_PORT_DATA;
  GPIO_PORT_DIRECTION = 7;
  GPIO_PORT_READ_ENABLE = 1;
  ie |= INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
}

// センサー用のタイマー3割り込みを止め、GPIO の読み出しを無効に戻す
void Sensor_DoDisableIO(void) {
  u16 ie;

  REG_IME = 0;
  ie = REG_IE;
  REG_IE = 0;
  REG_TM3CNT_H = 0;
  REG_TM3CNT_L = 0;
  gIntrTable[2] = IntrDummy;
  GPIO_PORT_READ_ENABLE = 0;
  ie &= ~INTR_FLAG_TIMER3;
  REG_IE = ie;
  REG_IME = 1;
}

// タイマー3 割り込み。GPIO を1段進めて、リセット -> 計測 -> 待機 を回しながら明るさを読む
void Sensor_Tick(void) {
  u32 data = GPIO_PORT_DATA;
  u32 gpio;

  GPIO_PORT_DATA = gSensorNextWrite;
  REG_TM3CNT_L = -gSensorTickPeriod;
  gpio = data & 8;
  gSensorGpioData = gpio;
  if (gSensorEnabled) {
    switch (gSensorState) {
      case 0: {
        if (gSensorCounter <= 9) {
          gSensorNextWrite |= 2;
        } else {
          gSensorNextWrite &= ~2;
        }
        if (gSensorCounter > 20 && gpio == 0) {
          gSensorState++;
          gSensorCounter = 0;
          gSensorUnk0c = 0;
        }
        break;
      }
      case 1: {
        if (gpio != 0) {
          gSensorRawLevel = gSensorCounter >> 1;
          gSensorState = 2;
        }
        gSensorUnk0c = gpio;
      }
      case 2: {
        gSensorNextWrite ^= 1;
        if (gSensorCounter > 511) {
          gSensorState = 0;
          gSensorCounter = 0;
        }
        break;
      }
    }
    gSensorCounter++;
  }
}

void Sensor_EnableIO(void) {
  gSensorDrvUnk04 = 0;
  gSensorIoEnabled = TRUE;
  Sensor_DoEnableIO();
}

void Sensor_DisableIO(void) {
  if (gSensorIoEnabled) {
    gSensorIoEnabled = FALSE;
    Sensor_DoDisableIO();
  }
}

void Sensor_Enable(void) {
  if (!gSensorIoEnabled) Sensor_EnableIO();
  gSensorEnabled = TRUE;
  gSensorState = 0;
  gSensorCounter = 0;
  gSensorRawLevel = -1;
}

void Sensor_Disable(void) {
  if (gSensorIoEnabled == TRUE) Sensor_DisableIO();
  gSensorEnabled = FALSE;
  gSensorRawLevel = -1;
}

s32 Sensor_GetRawLevel(void) {
  if (!gSensorEnabled) return -1;
  return gSensorRawLevel;
}

bool32 Sensor_IsIoEnabled(void) { return gSensorIoEnabled; }

s32 Sensor_GetState(void) { return gSensorState; }

s32 Sensor_GetCounter(void) { return gSensorCounter; }
