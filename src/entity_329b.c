#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sound.h"
#include "tilemap.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// RTC の日付と時刻を BG のタイルで表示し, スキャンライン毎の MOSAIC で演出するシングルトン
typedef struct Entity329B {
  Entity e;                                    // 0x000, ENTITY_UNK_9
  u16 unk_18;                                  // 0x018, _Create の引数
  u8 unk_1a;                                   // 0x01A, '.f'
  u8 bgNum;                                    // 0x01B, Video_SetupBG / SetBGPrioDirect に渡す BG 番号
  u16 tilemapID;                               // 0x01C, TILEMAP_596F
  s16 bgPlttID;                                // 0x01E, '.p'
  rgb555* pltt;                                // 0x020, &gBgPlttBuffer[0xD0]
  rgb555* basePltt;                            // 0x024, bgPlttID のファイルの +0x1B4, 色を混ぜるときの元の色
  u16 redrawRequest;                           // 0x028, bit0 日付, bit1 時刻, bit2 太陽時間を描き直す要求, _Redraw が処理後 0 に戻す
  u16 showDelay;                               // 0x02A, '.w', 0 まで減ると BG0 を表示して次の状態へ進む
  u16 hblankMosaic[2][160];                    // 0x02C, スキャンライン毎の MOSAIC 値, gHBlankEffectBuffer がこの片面を指す
  u16 hblankBufIdx;                            // 0x2AC, hblankMosaic のどちらを転送するか, _Update が毎フレーム反転する
  s16 mosaicAmp;                               // 0x2AE, 0..256, 各行の MOSAIC 値は乱数 * mosaicAmp >> 18
  u16 mosaicAmpStep;                           // 0x2B0, 毎フレーム mosaicAmp に足す
  u16 mosaicTop;                               // 0x2B2, 揺らす行の範囲 [mosaicTop, mosaicBottom), 外は 0
  u16 mosaicBottom;                            // 0x2B4, 初期値 0xA0 (画面の走査線数)
  u16 params[6];                               // 0x2B6, '.t[0..5]', u16_ARRAY_085aa810 の値が下限になる
  u16 fadeFirst;                               // 0x2C2, 色を混ぜるパレットの範囲 [fadeFirst, fadeEnd), 各16色の中の番号
  u16 fadeEnd;                                 // 0x2C4
  rgb555 fadeColor;                            // 0x2C6, basePltt と混ぜる色, 初期値 0x1084 = RGB(4, 4, 4)
  u16 fadeRatio;                               // 0x2C8, 0..256, 256 を超えると fadeCallback が外れる
  u16 fadeStep;                                // 0x2CA, 毎フレーム fadeRatio に足す
  void (*updateCallback)(struct Entity329B*);  // 0x2CC, 状態関数, 初期値 Entity329B_UpdateWait
  void (*fadeCallback)(struct Entity329B*);    // 0x2D0, Entity329B_FadeFromColor / Entity329B_FadeToColor
  void (*mosaicCallback)(struct Entity329B*);  // 0x2D4, Entity329B_UpdateMosaic / Entity329B_StopMosaic
  u16 stateTimer;                              // 0x2D8, updateCallback が切り替わるたびに 0 に戻る
  u8 unk_2da[2];                               // 0x2DA
  ScriptArgs sa;                               // 0x2DC, scriptID に渡す引数, argv は scriptArgsBuf, argc は積んだ '.a' の個数 (最大8)
  u32 scriptArgsBuf[8];                        // 0x2E4, '.a'
  s32 scriptID;                                // 0x304, '.e', 終わるときに VM_ExecByID する
} Entity329B;
static_assert(sizeof(Entity329B) == 776);

IWRAM_DATA Entity329B* gEntity329B = NULL;  // 0x03000048

const u16 u16_ARRAY_085aa810[6] = {0x80, 0x2, 0x50, 0x60, 0x20, 0x40};  // 0x085aa810

extern u16 gStagedDISPCNT;

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_080100f4(Entity329B* p);
void FUN_0801019c(Entity329B* p);
void FUN_08010230(Entity329B* p);
void FUN_08010350(Entity329B* p);
void FUN_080103ac(Entity329B* p);
void FUN_0801046c(Entity329B* p);
void Entity329B_UpdateFadeOut(Entity329B* p);
void Entity329B_FadeFromColor(Entity329B* p);
void Entity329B_FadeToColor(Entity329B* p);
void Entity329B_UpdateMosaic(Entity329B* p);
void Entity329B_StopMosaic(Entity329B* p);

// 状態関数を差し替えて stateTimer を 0 に戻す
static inline void Entity329B_SetState(Entity329B* p, void (*fn)(Entity329B*)) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void Entity329B_ClearGlobal(void) { gEntity329B = NULL; }

// BG bgNum のタイルマップバッファで (x, y) のタイルを指す
// 残差は ldr tilemap と x * 2 の順の入れ替えだけ (18/18), 原典は tilemap を先に読む
// Tier A は試済 (y * (width16 * 2), &tilemap[x] + ..., x + tilemap + ..., << 1)
NON_MATCH BgMapEntry* Entity329B_GetTilePtr(s32 bgNum, s32 x, s32 y) {
#ifdef NONMATCHING_C
  BgState* bg = &gBgStates[bgNum];

  return bg->tilemap + x + bg->width16 * 2 * y;
#else
  INCFUNC("asm/func/Entity329B_GetTilePtr.inc");
#endif
}

// 月と日を2桁ずつ, 上下2段のタイルで (6, 11) と (10, 11) に描く
void Entity329B_DrawDate(Entity329B* p, s32 month, s32 day) {
  s32 digits[2];
  BgMapEntry* dst;
  s32 x, y;

  digits[0] = month > 9 ? 1 : 0;
  digits[1] = month - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 6, 11);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x20 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }

  digits[0] = Div(day, 10);
  digits[1] = day - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 10, 11);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x20 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }
}

// 時と分を2桁ずつ, 上下2段のタイルで (16, 11) と (20, 11) に描く
void Entity329B_DrawClock(Entity329B* p) {
  s32 digits[2];
  BgMapEntry* dst;
  s32 x, y;
  s32 hour = Time_GetHour();
  s32 minute = Time_GetMinute();

  digits[0] = Div(hour, 10);
  digits[1] = hour - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 16, 11);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x20 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }

  digits[0] = Div(minute, 10);
  digits[1] = minute - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 20, 11);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x20 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }
}

// 夜なら日の出まで, 昼なら日の入りまでの残り時間を, ラベルと時分2桁ずつのタイルで (4, 15) から描く
// 形は揃った (202/206), 残差は割り当て, 原典は &gClock をレジスタに置かず使うたびに読み直し, hour / minute を r8 / sl, 0xD000 を ip に持つ
// Tier A-C は試済 (gClock の直接参照, ラベルのタイル番号を y から作る, u8 の hour, 宣言順, struct Time*, GetTilePtr を分岐の外へ)
NON_MATCH void Entity329B_DrawSunTime(Entity329B* p) {
#ifdef NONMATCHING_C
  BgMapEntry* dst;
  s32 digits[2];
  s32 hour, minute;
  s32 tile, width;
  s32 x, y;

  if (&gClock == NULL) {
    return;
  }

  if (gClock.spanOfTime == TIME_NIGHT || gClock.spanOfTime == TIME_UNK4 || gClock.spanOfTime == TIME_UNK5) {
    dst = Entity329B_GetTilePtr(0, 4, 15);
    hour = gClock.untilSunrise.hour;
    minute = gClock.untilSunrise.minute;
  } else {
    dst = Entity329B_GetTilePtr(0, 4, 15);
    hour = gClock.untilSunset.hour;
    minute = gClock.untilSunset.minute;
  }
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 4; x++) {
      dst[x] = (0x6A + y * 16 + x) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }

  dst = Entity329B_GetTilePtr(0, 8, 15);
  if (gClock.spanOfTime == TIME_NIGHT || gClock.spanOfTime == TIME_UNK4 || gClock.spanOfTime == TIME_UNK5) {
    width = 2;
    tile = 0x6E;
  } else {
    width = 2;
    tile = 0x4E;
  }
  for (y = 0; y < 2; y++) {
    for (x = 0; x < width; x++) {
      dst[x] = (tile + y * 16 + x) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }

  digits[0] = Div(hour, 10);
  digits[1] = hour - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 16, 15);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x60 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }

  digits[0] = Div(minute, 10);
  digits[1] = minute - digits[0] * 10;
  dst = Entity329B_GetTilePtr(0, 22, 15);
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {
      dst[x] = (y * 16 + 0x60 + digits[x]) | 0xD000;
    }
    dst += gBgStates[0].width16 * 2;
  }
#else
  INCFUNC("asm/func/Entity329B_DrawSunTime.inc");
#endif
}

// redrawRequest で頼まれた日付, 時刻, 太陽時間を描き直す
void Entity329B_Redraw(Entity329B* p) {
  s32 year, month, day;

  Time_ParseBCDDate(&year, &month, &day, (BCDDate)Time_GetDate());
  if (p->redrawRequest & 1) {
    Entity329B_DrawDate(p, month, day);
  }
  if (p->redrawRequest & 2) {
    Entity329B_DrawClock(p);
  }
  if (p->redrawRequest & 4) {
    Entity329B_DrawSunTime(p);
  }
  p->redrawRequest = 0;
}

// START か A が押されたら画面を閉じる演出を始めて TRUE を返す
bool32 Entity329B_HandleSkipInput(Entity329B* p) {
  if ((gInput[0].pressed & START_BUTTON) || (gInput[0].pressed & A_BUTTON)) {
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
    Entity329B_SetState(p, Entity329B_UpdateFadeOut);
    return TRUE;
  }
  return FALSE;
}

void FUN_080100f4(Entity329B* p) {
  if (p->stateTimer == 0) {
    p->fadeFirst = 12;
    p->fadeEnd = 16;
    p->fadeColor = 0x1084;
    p->fadeRatio = 0;
    p->fadeStep = 2;
    p->fadeCallback = Entity329B_FadeToColor;
  }
  if (p->stateTimer == p->params[5]) {
    VM_ExecByID(p->scriptID, &p->sa);
    KillEntity((Entity*)p);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  }
  p->redrawRequest |= 4;
  p->redrawRequest &= ~3;
  p->stateTimer++;
}

void FUN_0801019c(Entity329B* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_227);
    p->mosaicTop = 0x74;
    p->mosaicBottom = 0xA0;
    p->mosaicAmp = 0;
    p->mosaicAmpStep = 4;
    p->mosaicCallback = Entity329B_UpdateMosaic;
  }
  if (p->stateTimer++ >= p->params[4]) {
    p->redrawRequest &= ~3;
    Entity329B_SetState(p, FUN_080100f4);
  }
  p->redrawRequest |= 4;
}

// 残差は 48 フレーム目に BG0 を埋める二重ループの割り当てだけ (114/123), 原典は &gBgStates を r8 に置いて ip と r3 に写し, y+1 を先に作る
// Tier A-C は試済 (tile のローカル, 13 << 12, bg のポインタ, while, 宣言位置, 埋める処理の inline)
NON_MATCH void FUN_08010230(Entity329B* p) {
#ifdef NONMATCHING_C
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_225);
    p->fadeFirst = 1;
    p->fadeEnd = 5;
    p->fadeColor = 0x1084;
    p->fadeRatio = 0;
    p->fadeStep = 4;
    p->fadeCallback = Entity329B_FadeToColor;
    p->mosaicTop = 0;
    p->mosaicBottom = 0x74;
    p->mosaicAmp = 0;
    p->mosaicAmpStep = 4;
    p->mosaicCallback = Entity329B_UpdateMosaic;
  }
  if (p->stateTimer == 48) {
    BgMapEntry* dst = Entity329B_GetTilePtr(0, 0, 0);
    s32 x, y;

    for (y = 0; y < 15; y++) {
      for (x = 0; x < gBgStates[0].width16 * 2; x++) {
        *dst++ = 0xD000;
      }
    }
  }
  if (p->stateTimer++ >= p->params[3]) {
    Entity329B_SetState(p, FUN_0801019c);
  }
  p->redrawRequest |= 0xF;
#else
  INCFUNC("asm/func/FUN_08010230.inc");
#endif
}

void FUN_08010350(Entity329B* p) {
  if (Entity329B_HandleSkipInput(p)) {
    return;
  }
  if (p->stateTimer++ >= p->params[2]) {
    Entity329B_SetState(p, FUN_08010230);
    p->mosaicCallback = Entity329B_StopMosaic;
  }
  p->redrawRequest |= 0xF;
}

void FUN_080103ac(Entity329B* p) {
  if (Entity329B_HandleSkipInput(p)) {
    return;
  }
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_225);
    p->mosaicTop = 0;
    p->mosaicBottom = 0xA0;
    p->mosaicAmp = 0x100;
    p->mosaicAmpStep = -2;
    p->mosaicCallback = Entity329B_UpdateMosaic;
    p->fadeColor = 0x1084;
    p->fadeRatio = 0;
    p->fadeStep = 4;
    p->fadeCallback = Entity329B_FadeFromColor;
  }
  if (p->stateTimer++ >= p->params[1]) {
    Entity329B_SetState(p, FUN_0801046c);
  }
  p->redrawRequest |= 0xF;
}

void FUN_0801046c(Entity329B* p) {
  if (Entity329B_HandleSkipInput(p)) {
    return;
  }
  if (p->stateTimer++ >= p->params[0]) {
    p->mosaicCallback = Entity329B_StopMosaic;
    Entity329B_SetState(p, FUN_08010350);
  }
  p->redrawRequest |= 0xF;
}

// BG のパレット32色を stateTimer に合わせて暗くしていき, 32フレームで消し終えたら scriptID のスクリプトを呼んで終わる
void Entity329B_UpdateFadeOut(Entity329B* p) {
  s32 k = 32 - p->stateTimer;
  s32 i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 16; j++) {
      rgb555* c = &p->pltt[i * 16 + j];
      s32 r = (*c & 0x1F) * k & 0x7C0;
      s32 g = (*c & 0x3E0) * k & 0xF800;
      s32 b = (*c & 0x7C00) * k & 0x1F0000;

      *c = (r | g | b) >> 6;
    }
  }
  if (++p->stateTimer > 31) {
    ClearBGTilemapBuffer(0);
    VM_ExecByID(p->scriptID, &p->sa);
    KillEntity((Entity*)p);
  } else {
    p->redrawRequest |= 0xF;
  }
}

// BG0 を隠したまま showDelay を数え, 尽きたら BG0 を出して FUN_080103ac へ進む
void Entity329B_UpdateWait(Entity329B* p) {
  u16 delay;

  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  if (Entity329B_HandleSkipInput(p)) {
    return;
  }
  delay = p->showDelay--;
  if (delay == 0) {
    SET_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
    Entity329B_SetState(gEntity329B, FUN_080103ac);
  }
}

// pltt の各16色のうち [fadeFirst, fadeEnd) を, basePltt と fadeColor の色を fadeRatio / 256 の割合で混ぜた色にする
// 残差は base + 16 と i + 1 を退避するスタック位置 (sp+0x14 / sp+0x18) の入れ替わりだけ (143/143)
// Tier A-C は試済 (宣言順, base の更新を本体の最後へ, base = i * 16)
NON_MATCH void Entity329B_FadeFromColor(Entity329B* p) {
#ifdef NONMATCHING_C
  s32 t = p->fadeRatio;
  s32 inv;
  s32 tr, tg, tb;
  s32 i, j, base;

  if (t > 256) {
    t = 256;
  }
  inv = 256 - t;
  tr = p->fadeColor & 0x1F;
  tg = p->fadeColor & 0x3E0;
  tb = p->fadeColor & 0x7C00;
  for (base = 0, i = 0; i < 2; base += 16, i++) {
    for (j = p->fadeFirst; j < p->fadeEnd; j++) {
      rgb555* src = &p->basePltt[base + j];
      rgb555* dst = &p->pltt[base + j];
      s32 r = ((*src & 0x1F) * t + tr * inv) & 0x1F00;
      s32 g = ((*src & 0x3E0) * t + tg * inv) & 0x3E000;
      s32 b = ((*src & 0x7C00) * t + tb * inv) & 0x7C0000;

      *dst = (r | g | b) >> 8;
    }
  }
  if (p->fadeRatio > 256) {
    p->fadeCallback = NULL;
    p->fadeRatio = 0;
  }
  p->fadeRatio += p->fadeStep;
#else
  INCFUNC("asm/func/Entity329B_FadeFromColor.inc");
#endif
}

// Entity329B_FadeFromColor の逆向き, pltt の各16色のうち [fadeFirst, fadeEnd) を, fadeColor の色から basePltt へ fadeRatio / 256 の割合で戻す
void Entity329B_FadeToColor(Entity329B* p) {
  s32 t = p->fadeRatio;
  s32 inv;
  s32 tr, tg, tb;
  s32 i, j, base;

  if (t > 256) {
    t = 256;
  }
  inv = 256 - t;
  tr = p->fadeColor & 0x1F;
  tg = p->fadeColor & 0x3E0;
  tb = p->fadeColor & 0x7C00;
  for (base = 0, i = 0; i < 2; base += 16, i++) {
    for (j = p->fadeFirst; j < p->fadeEnd; j++) {
      rgb555* src = &p->basePltt[base + j];
      rgb555* dst = &p->pltt[base + j];
      s32 r = (tr * t + (*src & 0x1F) * inv) & 0x1F00;
      s32 g = (tg * t + (*src & 0x3E0) * inv) & 0x3E000;
      s32 b = (tb * t + (*src & 0x7C00) * inv) & 0x7C0000;

      *dst = (r | g | b) >> 8;
    }
  }
  if (p->fadeRatio > 256) {
    p->fadeCallback = NULL;
    p->fadeRatio = 0;
  }
  p->fadeRatio += p->fadeStep;
}

// 送る面の hblankMosaic を作る, [mosaicTop, mosaicBottom) の行は乱数 * mosaicAmp の揺れ, ほかの行は 0 にする
// 命令数は一致 (157/157), 残差はレジスタ割り当てとループ前の準備の並び, 原典は p を ip に置き 3 つのループそれぞれの前で番地を作り直す
// Tier A-C は試済 (_Random(table), i を u32 / s16, while)
NON_MATCH void Entity329B_UpdateMosaic(Entity329B* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->mosaicTop; i++) {
    p->hblankMosaic[p->hblankBufIdx][i] = 0;
  }
  for (i = p->mosaicTop; i < p->mosaicBottom; i++) {
    p->hblankMosaic[p->hblankBufIdx][i] = (Random() * p->mosaicAmp) >> 18;
  }
  for (i = p->mosaicBottom; i < 160; i++) {
    p->hblankMosaic[p->hblankBufIdx][i] = 0;
  }
  gHBlankEffectBuffer = p->hblankMosaic[p->hblankBufIdx];
  gHBlankEffectReg = &REG_MOSAIC;
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 1;
  p->mosaicAmp += p->mosaicAmpStep;
  if (p->mosaicAmp < 0) {
    p->mosaicAmp = 0;
  } else if (p->mosaicAmp > 256) {
    p->mosaicAmp = 256;
  }
#else
  INCFUNC("asm/func/Entity329B_UpdateMosaic.inc");
#endif
}

// hblankMosaic を 0 で埋めて HBlank DMA を MOSAIC への1行だけの転送に戻し, 自分を mosaicCallback から外す
void Entity329B_StopMosaic(Entity329B* p) {
  CpuFill32(0, p->hblankMosaic, 580);
  gHBlankEffectBuffer = p->hblankMosaic[p->hblankBufIdx];
  gHBlankEffectReg = &REG_MOSAIC;
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 0;
  p->mosaicCallback = NULL;
}

// 3本の状態関数を回し, HBlank DMA で送る hblankMosaic の面を入れ替えて, 頼まれた表示を描き直す
s32 Entity329B_Update(Entity329B* p) {
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  if (p->fadeCallback != NULL) {
    p->fadeCallback(p);
  }
  if (p->mosaicCallback != NULL) {
    p->mosaicCallback(p);
  }
  p->hblankBufIdx = 1 - p->hblankBufIdx;
  Entity329B_Redraw(p);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

// hblankMosaic を 0 で埋め, HBlank DMA を MOSAIC への1行だけの転送に戻してシングルトンを手放す, 戻り値は書かれていない
s32 Entity329B_Destroy(Entity329B* p) {
  CpuFill32(0, p->hblankMosaic, 580);
  gHBlankEffectBuffer = p->hblankMosaic[p->hblankBufIdx];
  gHBlankEffectReg = &REG_MOSAIC;
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 0;
  gEntity329B = NULL;
}

s32 Entity329B_Init(Entity329B* p, u16 id) {
  Tilemaps* tilemap;
  BgPlttFile* plttFile;
  s32 i;

  gEntity329B = p;
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  p->unk_18 = id;
  p->unk_1a = VM_GetNamedArgValue('f', 0);
  p->tilemapID = TILEMAP_596F;
  p->bgPlttID = VM_GetNamedArgValue('p', 0);
  p->pltt = &gBgPlttBuffer[208];
  p->scriptID = VM_GetNamedArgValue('e', 0);

  if (VM_SeekToNamedArg('a')) {
    p->sa.argv = p->scriptArgsBuf;
    for (i = 0; i < 8 && VM_GetPC() != NULL; i++) {
      p->sa.argv[i] = VM_GetValue();
    }
    p->sa.argc = i;
  } else {
    p->sa.argc = 0;
  }

  if (VM_SeekToNamedArg('t')) {
    for (i = 0; i < 6 && VM_GetPC() != NULL; i++) {
      p->params[i] = VM_GetValue();
      if (p->params[i] < u16_ARRAY_085aa810[i]) {
        p->params[i] = u16_ARRAY_085aa810[i];
      }
    }
    for (; i < 6; i++) {
      p->params[i] = u16_ARRAY_085aa810[i];
    }
  } else {
    for (i = 0; i < 6; i++) {
      p->params[i] = u16_ARRAY_085aa810[i];
    }
  }

  p->bgNum = 0;
  tilemap = GetFile(DIR_TILE_MAP, p->tilemapID);
  if (tilemap == NULL) {
    return -1;
  }
  plttFile = GetBgPlttFile(p->bgPlttID);
  if (plttFile == NULL) {
    return -1;
  }
  if (*tilemap->magic == 'M' && *(tilemap->magic + 1) == 'P') {
    SetBGPrioDirect(p->bgNum, 0);
  } else {
    Video_SetupBG(p->bgNum, 0, tilemap, 0, 0, 0, 0, GetTilemapBuffer(0));
  }
  p->basePltt = &plttFile->body[208];
  CpuFill32(0, p->pltt, 96);
  REG_BG0CNT |= BGCNT_MOSAIC;
  p->showDelay = VM_GetNamedArgValue('w', 0);
  Entity329B_SetState(p, Entity329B_UpdateWait);
  p->fadeFirst = 0;
  p->fadeEnd = 16;
  p->fadeColor = 0x1084;
  p->fadeRatio = 0;
  p->fadeStep = 1;
  p->fadeCallback = NULL;
  CpuFill32(0, p->hblankMosaic, 580);
  p->hblankBufIdx = 0;
  p->mosaicAmp = 0x400;
  p->mosaicAmpStep = 1;
  p->mosaicTop = 0;
  p->mosaicBottom = 0xA0;
  p->mosaicCallback = NULL;
  p->redrawRequest = 0xF;
  return 0;
}

Entity329B* Entity329B_Create(u32 id) {
  Entity329B* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity329B));

  if (p != NULL) {
    SetEntityRoutine(p, Entity329B_Update, Entity329B_Destroy);
    if (Entity329B_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
