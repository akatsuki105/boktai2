#include "entity.h"
#include "file.h"
#include "gba/m4a.h"
#include "global.h"
#include "link.h"
#include "particle.h"
#include "sprite.h"
#include "time.h"

EWRAM_DATA u32 gSentinel02020400 = 0;  // AgbMainでEWRAMをクリアする前に退避されるのでソフトリセットを検知するためのセンチネル？
EWRAM_DATA u32 u32_02020404 = 0;       // gSentinel02020400と同様にAgbMainでEWRAMをクリアする前に退避されるが、用途は不明
EWRAM_DATA u8 u8_02020408[4088] = {};  // 0x02020408, Unused?

void InitIntrHandlers(void);
void Time_InitFromRtc(void);
void FUN_08229d80(void);
void Map_InitCollisionMap(void);
void LoadAuxSpriteFile(AuxSpriteFile* f);
void FUN_08231bec(void);
void FUN_0823acbc(void);
void UpdateAllEntities(void);
void FUN_0823a870(void);
void RandomizeGameStateAddr(void);
void InitSystemManager(void);
void InitPltt(void);

void AgbMain(void) {
  u32 sentinel;
  u32 saved;

  REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;
  sentinel = gSentinel02020400;
  saved = u32_02020404;
  RegisterRamReset(RESET_EWRAM);
  gSentinel02020400 = sentinel;
  u32_02020404 = saved;
  DmaFill32(3, 0, (void*)IWRAM, 0x7D00);  // IWRAM の先頭 32000 バイトだけ消す, 残りの 768 バイトはスタックと IRQ ハンドラのポインタなので触らない
  RtcIoEnable();
  Time_Reset();
  Time_InitFromRtc();
  m4aSoundInit();
  InitIntrHandlers();
  IdentifyEeprom(0x40);  // 8192 Byte
  FUN_0823a870();
  RandomizeGameStateAddr();
  InitSystemManager();
  FUN_08229d80();
  Map_InitCollisionMap();
  InitPltt();
  LoadParticleFile(GetFile(DIR_PARTICLE, 0x3002));
  LoadAuxSpriteFile(GetFile(DIR_AUX_SPRITE, 0xFF54));

  {
    Keys16 ie;

    REG_IME = 0;
    ie = REG_IE;
    REG_IE = 0;
    REG_IE = ie | INTR_FLAG_VCOUNT;
    REG_IME = 1;
  }

  Sio_Reset();
  Time_SetLocation(0x0023A666, 0x008BC000, 0);
  FUN_08231bec();
  FUN_0823acbc();
  while (TRUE) {
    UpdateAllEntities();
  }
}
