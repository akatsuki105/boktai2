#include "entity.h"
#include "global.h"

// RTC の日付と時刻を BG のタイルで表示し, スキャンライン毎の MOSAIC で演出するシングルトン
typedef struct Entity329B {
  Entity e;                                     // 0x000, ENTITY_UNK_9
  u16 unk_18;                                   // 0x018, _Create の引数
  u8 unk_1a;                                    // 0x01A, '.f'
  u8 bgNum;                                     // 0x01B, Video_SetupBG / SetBGPrioDirect に渡す BG 番号
  u16 tilemapID;                                // 0x01C, TILEMAP_596F
  s16 bgPlttID;                                 // 0x01E, '.p'
  rgb555* pltt;                                 // 0x020, &gBgPlttBuffer[0xD0]
  void* unk_24;                                 // 0x024, bgPlttID のファイルの +0x1B4
  u16 redrawRequest;                            // 0x028, bit0 日付, bit1 時刻, bit2 太陽時間を描き直す要求, _Redraw が処理後 0 に戻す
  s16 showDelay;                                // 0x02A, '.w', 0 まで減ると BG0 を表示して次の状態へ進む
  u16 hblankMosaic[2][160];                     // 0x02C, スキャンライン毎の MOSAIC 値, gHBlankEffectBuffer がこの片面を指す
  u16 hblankBufIdx;                             // 0x2AC, hblankMosaic のどちらを転送するか, _Update が毎フレーム反転する
  u16 unk_2ae;                                  // 0x2AE, 初期値 0x400
  u16 unk_2b0;                                  // 0x2B0, 初期値 1
  u16 unk_2b2;                                  // 0x2B2, 初期値 0
  u16 unk_2b4;                                  // 0x2B4, 初期値 0xA0 (画面の走査線数)
  u16 params[6];                                // 0x2B6, '.t[0..5]', u16_ARRAY_085aa810 の値が下限になる
  u16 unk_2c2;                                  // 0x2C2, 初期値 0
  u16 unk_2c4;                                  // 0x2C4, 初期値 0x10
  u16 unk_2c6;                                  // 0x2C6, 初期値 0x1084
  u16 unk_2c8;                                  // 0x2C8, 初期値 0
  u16 unk_2ca;                                  // 0x2CA, 初期値 1
  void (*updateCallback)(struct Entity329B*);   // 0x2CC, 状態関数, 初期値 Entity329B_UpdateWait
  void (*updateCallback2)(struct Entity329B*);  // 0x2D0
  void (*updateCallback3)(struct Entity329B*);  // 0x2D4
  u16 stateTimer;                               // 0x2D8, updateCallback が切り替わるたびに 0 に戻る
  u8 unk_2da[2];                                // 0x2DA
  s16 scriptArgCount;                           // 0x2DC, scriptArgsBuf に積んだ '.a' の個数 (最大8)
  u8 unk_2de[2];                                // 0x2DE
  u32* scriptArgs;                              // 0x2E0, scriptArgsBuf を指す
  u32 scriptArgsBuf[8];                         // 0x2E4, '.a'
  s32 unk_304;                                  // 0x304, '.e'
} Entity329B;
static_assert(sizeof(Entity329B) == 776);

IWRAM_DATA Entity329B* gEntity329B = NULL;  // 0x03000048

const u16 u16_ARRAY_085aa810[6] = {0x80, 0x2, 0x50, 0x60, 0x20, 0x40};  // 0x085aa810

INCASM("asm/entity_329b.inc");
