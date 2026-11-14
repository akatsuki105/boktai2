#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_11
  u32 timer;                 // 0x018, 毎フレーム +1
  u16 unk_1c;                // 0x01C
  u16 unk_1e;                // 0x01E
  u8 key;                    // 0x020, PasswordScreen_EncodeBits が乱数で 0..7 を入れる, 文字を混ぜる乱数をこの回数 + 4 だけ空回しする
  u8 unk_21[3];              // 0x021
  u32 rngState;              // 0x024, PasswordScreen_NextRandom が回す線形合同法の状態
  u16 scriptID;              // 0x028, START を押したときに VM_ExecByID する, 実行したら 0 に戻す
  u8 chars[24];              // 0x02A, パスワードの文字 (6 ビット値), 先頭 4 文字の後ろ 20 文字は乱数で混ぜる
  u8 unk_42[0x44C - 0x042];  // 0x042
  s32 windowIDs[3];          // 0x44C, TextPanel_Create の戻り値, _Destroy が TextPanel_Destroy に渡す
  TilemapFile* tilemap;      // 0x458, TILEMAP_33B2
  rgb555* pltt;              // 0x45C, BGP_E9C3 の本体, gBgPlttBuffer へ写す
} PasswordScreen;
static_assert(sizeof(PasswordScreen) == 1120);

const ALIGNED(4) char sChar_085aa838[] = "<WEIGHT>";   // 0x085aa838
const ALIGNED(4) char sChar_085aa844[] = "</WEIGHT>";  // 0x085aa844

// パスワード画面の BG1 と BG パレットを読み込む
void PasswordScreen_SetupBG(PasswordScreen* p, s32 bgIndex) {
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_33B2);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  p->pltt = GetBgPlttFile(BGP_E9C3)->body;
  CpuCopy16(p->pltt, gBgPlttBuffer, 256 * sizeof(rgb555));
}

// 線形合同法を1回まわして次の値を返す
s32 PasswordScreen_NextRandom(PasswordScreen* p) {
  p->rngState = p->rngState * 0x6262C05D + 1;
  return p->rngState;
}

// value を width ビットに収め, 下位ビットから順に chars の *bitPos ビット目 (1 文字 6 ビット) へ詰めて *bitPos を進める
s32 PasswordScreen_PutBits(PasswordScreen* p, u32 value, s32* bitPos, s32 width) {
  s32 i;

  if (value > (1 << width) - 1) {
    value = (1 << width) - 1;
  }
  for (i = 0; i < width; i++) {
    s32 idx = Div(*bitPos, 6);
    s32 shift = Mod(*bitPos, 6);
    u32 bit = (value >> i) & 1;

    p->chars[idx] |= bit << shift;
    (*bitPos)++;
  }
}

// key + 4 回空回しした乱数で, chars の 5 文字目以降の 20 文字を xor して混ぜる
// 残差: 原典は 2 つ目のループの & 63 の定数をループ内で作るが, こちらはループ外に出して r8 に置く (45/39 命令), 試済: xor の被演算子の順, 文字のポインタ, mask を u32
NON_MATCH s32 PasswordScreen_ScrambleChars(PasswordScreen* p) {
#ifdef NONMATCHING_C
  s32 mask = 0xFFFF;
  s32 i;

  for (i = 0; i < p->key + 4; i++) {
    mask ^= PasswordScreen_NextRandom(p);
  }
  for (i = 0; i < 20; i++) {
    p->chars[4 + i] = (p->chars[4 + i] ^ mask) & 63;
    mask ^= PasswordScreen_NextRandom(p);
  }
  return 0;
#else
  INCFUNC("asm/func/PasswordScreen_ScrambleChars.inc");
#endif
}

NAKED s32 PasswordScreen_EncodeBits(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_EncodeBits.inc"); }

// 最初の40フレームは2フレームおきに文字送りの音を鳴らし, 60フレーム目以降は START でスクリプトへ戻る
s32 PasswordScreen_Update(PasswordScreen* p) {
  if (p->timer <= 40 && !(p->timer & 1)) {
    PlaySound_082406e0(SONG_628);
  }

  if (p->timer > 59 && (gInput[0].pressed & START_BUTTON)) {
    PlaySound_082406e0(SE_SELECT);
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
      p->scriptID = 0;
    }
  }

  p->timer++;
  return 0;
}

s32 PasswordScreen_Destroy(PasswordScreen* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    TextPanel_Destroy(p->windowIDs[i]);
  }

  return 0;
}

NAKED s32 PasswordScreen_Init(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Init.inc"); }

PasswordScreen* PasswordScreen_Create(void) {
  PasswordScreen* p = CreateEntity(ENTITY_UNK_11, sizeof(PasswordScreen));

  if (p != NULL) {
    SetEntityRoutine(p, PasswordScreen_Update, PasswordScreen_Destroy);
    if (PasswordScreen_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
