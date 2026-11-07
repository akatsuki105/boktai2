#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "link.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "vec3.h"
#include "video.h"

// 通信対戦のスコア精算画面, 稼いだ点を1フレームずつ所持スコアへ移していく
typedef struct Entity501B {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  MainSprite digits[8];                        // 0x018, [0..3] が上段 (y=0x40), [4..7] が下段 (y=0x78), 各段とも [0] が1の位
  MainSpriteGfx gfx;                           // 0x318, SPRITE_UI_LINK
  u8 unk_338[0x358 - 0x338];                   // 0x338, まだ未解析
  MainSpriteGfxFile* file;                     // 0x358, SPRITE_SOLAR_STATION
  u8 unk_35c[4];                               // 0x35C, まだ未解析
  u16 poses[8];                                // 0x360, digits ごとの MainSprite_Add のポーズ番号
  AuxSprite solarStandSpr;                     // 0x370
  AuxSpriteGfx solarStandGfx;                  // 0x39C, SPRITE_SOLAR_STATION
  u8 unk_3b8[2];                               // 0x3B8, まだ未解析
  u16 timer;                                   // 0x3BA, 90 から毎フレーム減り, 0 で次の状態へ, ボタンで 1 に飛ばせる
  u16 score;                                   // 0x3BC, gEntity9A9F->unk_138[playerIdx] (9999 で頭打ち), 精算で減っていく
  s16 step;                                    // 0x3BE, 1フレームに score から gStat->field_0x912 へ移す量, 初期 2, ボタンで <<3
  s32 unk_3c0;                                 // 0x3C0, gEntity9A9F->unk_144[playerIdx] (±9999 で頭打ち)
  Tilemaps* tilemap0;                          // 0x3C4, TILEMAP_CD91 を BG2 に敷く
  Tilemaps* tilemap1;                          // 0x3C8, TILEMAP_A413 を BG0 に敷く
  rgb555* bgPltt;                              // 0x3CC, bg_link_col_arr
  void (*updateCallback)(struct Entity501B*);  // 0x3D0
  u8* unk_3d4;                                 // 0x3D4, '.s', TextPanel_SetScript に渡す
  u8* unk_3d8;                                 // 0x3D8, '.e'
  u32 flags;                                   // 0x3DC, bit0 を立てて step の <<3 を一度だけにする
  s32 textPanels[2];                           // 0x3E0, TextPanel_Create の戻り値
  u8 phase;                                    // 0x3E8, 状態を切り替えるたびに 0/1/2/3 が入る
  bool8 entered;                               // 0x3E9, 状態に入った最初のフレームだけ立つ, 各状態が初期化を済ませて 0 に戻す
  u16 stateTimer;                              // 0x3EA, 状態に入ってからのフレーム数
} Entity501B;
static_assert(sizeof(Entity501B) == 1004);

u8 Save_SwitchSlot(void);
s32 FUN_081dfa04(void);
void FUN_081e0588(Entity501B* p);
void Entity501B_StateSaveDone(Entity501B* p);
void Entity501B_StateSaveFailed(Entity501B* p);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_081df940(void);
bool32 Save_WriteExtraToNextSlot(void);
void FUN_081df924(void);
void FUN_081e0544(Entity501B* p);
void FUN_081e084c(Entity501B* p);

// セッションの状態を返す, セッションが無ければ -1
static inline s32 Entity9A9F_GetState(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->state;
}

// 自分が何番目の参加者かを返す, セッションが無ければ -1
static inline s32 Entity9A9F_GetPlayerIdx(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

static inline s32 Entity9A9F_GetUnk138(s32 idx) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return 0;
  }
  return p->unk_138[idx];
}

static inline s32 Entity9A9F_GetUnk144(s32 idx) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return 0;
  }
  return p->unk_144[idx];
}

// 状態関数を差し替えて, 切り替え直後の1フレームだけ立つフラグを付ける
static inline void Entity501B_SetState(Entity501B* p, void* fn, u8 phase) {
  p->updateCallback = fn;
  p->entered = TRUE;
  p->phase = phase;
}

// BG2 と BG0 にタイルマップを敷き, 背景パレットを作業用バッファへ流す
void Entity501B_InitBg(Entity501B* p) {
  s32 bgIndices[1];

  p->tilemap0 = GetFile(DIR_TILE_MAP, TILEMAP_CD91);
  p->tilemap1 = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  bgIndices[0] = 10;
  Video_SetupBGLayout(2, 0, p->tilemap0, 0, 0, 1, bgIndices);
  bgIndices[0] = 12;
  Video_SetupBGLayout(0, 0, p->tilemap1, 0, 0, 1, bgIndices);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgPltt = GetBgPlttFile(BOKHASH("bg_link_col_arr"))->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 512);
}

// 上下2枚のテキストパネルを作ってメッセージを流し始める
void Entity501B_InitTextPanels(Entity501B* p) {
  s32 i;

  p->textPanels[0] = TextPanel_Create(2, 5, 26, 2);
  p->textPanels[1] = TextPanel_Create(2, 12, 26, 2);
  for (i = 0; i < 2; i++) {
    TextPanel_SetScript(p->textPanels[i], p->unk_3d4);
    TextPanel_SetMessage(p->textPanels[i], i);
    TextPanel_Start(p->textPanels[i]);
  }
}

void Entity501B_HideTextPanels(Entity501B* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    TextPanel_Hide(p->textPanels[i]);
  }
}

// BG のタイルマップから (x, y) のエントリのアドレスを得る
BgMapEntry* Entity501B_GetBgMapAddr(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  BgMapEntry* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

// value を divisor の桁から1の位まで BG0 の (x, y) から右へ数字タイルで描く
// 32/34命令, 原典は d + 0x91 を u16 に切り詰めてから 0xF000 を OR し, 0xF000 も一度別レジスタへ写す, 試済: 0x91 をローカルに (ループ外に出るのは揃う), u16 引数の inline に通す (37)
NON_MATCH void Entity501B_DrawBgNumber(s32 value, s32 divisor, s32 x, s32 y) {
#ifdef NONMATCHING_C
  u16 tile = 0x91;
  BgMapEntry* map = Entity501B_GetBgMapAddr(0, x, y);

  while (divisor > 0) {
    s32 d = Div(value, divisor);

    *map++ = (u16)(d + tile) | 0xF000;
    value -= d * divisor;
    divisor = Div(divisor, 10);
  }
#else
  INCFUNC("asm/func/Entity501B_DrawBgNumber.inc");
#endif
}

// 太陽スタンドのスプライトを隠した状態で置く
// 44/44命令, 原典は &solarStandSpr を Video_GetAuxSprite の後に作って r4 に置く (こちらは先に作って r5), p と gfx のレジスタも逆, 次に試すなら spr の代入を Video_GetAuxSprite の後へ
NON_MATCH void Entity501B_InitAuxSprite(Entity501B* p) {
#ifdef NONMATCHING_C
  AuxSpriteGfx* gfx = &p->solarStandGfx;
  AuxSprite* spr = &p->solarStandSpr;

  Video_GetAuxSprite(gfx, SPRITE_SOLAR_STATION);
  AuxSprite_Add(spr, gfx, 0);
  AuxSprite_SetPoseIdx(spr, 0);
  AuxSprite_SetFlags(spr, SPRFLAG_HIDDEN | 0x10);
  p->solarStandSpr.priority = 0;
  Vec3_Clear(&p->solarStandSpr.pos);
  p->solarStandSpr.pos.x = 121;
  p->solarStandSpr.pos.y = 64;
#else
  INCFUNC("asm/func/Entity501B_InitAuxSprite.inc");
#endif
}

void Entity501B_RemoveAuxSprite(Entity501B* p) { AuxSprite_Remove(&p->solarStandSpr); }

// 数字のスプライトを8枚並べる
void Entity501B_InitSprites(Entity501B* p) {
  s32 i;

  p->file = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  OpenMainSpriteFile(&p->gfx, p->file);
  for (i = 0; i < 8; i++) {
    p->poses[i] = 0;
    if (MainSprite_Add(&p->digits[i], &p->gfx, p->poses[i], 16, 0, 0, 0, 0)) {
      break;
    }
  }
}

// 上段と下段に4桁ずつ右から左へ並べる
void Entity501B_InitSpritePos(Entity501B* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->digits[i].pos.x = 128 - i * 8;
    p->digits[i].pos.y = 64;
  }
  for (i = 0; i < 4; i++) {
    p->digits[i + 4].pos.x = 128 - i * 8;
    p->digits[i + 4].pos.y = 120;
  }
}

void Entity501B_HideSprites(Entity501B* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    p->digits[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Entity501B_RemoveSprites(Entity501B* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->digits[i]);
  }
}

// value を4桁に分解して row 段のスプライトに並べる
void Entity501B_SetNumber(Entity501B* p, s32 row, s32 value) {
  s32 n = row * 4;
  s32 d;

  d = 0;
  while (value > 999) {
    d++;
    value -= 1000;
  }
  MainSprite_LoadPose(&p->digits[n + 3], &p->gfx, d);
  d = 0;
  while (value > 99) {
    d++;
    value -= 100;
  }
  MainSprite_LoadPose(&p->digits[n + 2], &p->gfx, d);
  d = 0;
  while (value > 9) {
    d++;
    value -= 10;
  }
  MainSprite_LoadPose(&p->digits[n + 1], &p->gfx, d);
  d = 0;
  while (value > 0) {
    d++;
    value -= 1;
  }
  MainSprite_LoadPose(&p->digits[n], &p->gfx, d);
}

// 経過時間と乱数からでたらめな数を作って row 段に出す
void Entity501B_SpinNumber(Entity501B* p, s32 row) {
  s32 v = p->stateTimer * p->stateTimer >> 2;

  v += (Random2() % 8) * 10;
  v += (Random2() % 8) * 100;
  v += (Random2() % 8) * 1000;
  if (v > 9999) {
    v = 9999;
  }
  Entity501B_SetNumber(p, row, v);
}

// 1フレームおきにカウントアップの音を鳴らし, 待ちが残っていれば上段の数字を回す
void FUN_081e02ac(Entity501B* p) {
  if (Mod(p->stateTimer, 2) == 0) {
    PlaySound_082406e0(SE_COUNT_UP);
  }
  if (p->timer != 0) {
    Entity501B_SpinNumber(p, 0);
  }
}

// 待ちを減らし, 切れたら上段に score を出して効果音を鳴らす
void FUN_081e02ec(Entity501B* p) {
  if (p->timer != 0) {
    if (--p->timer == 0) {
      Entity501B_SetNumber(p, 0, p->score);
      PlaySound_082406e0(SE_LINK_359);
    }
  }
}

NAKED void Entity501B_LoadScore(Entity501B* p) { INCFUNC("asm/func/Entity501B_LoadScore.inc"); }

NAKED void FUN_081e03d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e03d8.inc"); }

NAKED void FUN_081e04a8(Entity501B* p) { INCFUNC("asm/func/FUN_081e04a8.inc"); }

// セッションが状態 24 になったらセーブへ移る
void FUN_081e0544(Entity501B* p) {
  if (Entity9A9F_GetState() == 24) {
    Entity501B_SetState(p, FUN_081e0588, 6);
  }
}

// セーブの書き込みを試し, 結果に応じた状態へ移る
void FUN_081e0588(Entity501B* p) {
  if (Save_SwitchSlot()) {
    Entity501B_SetState(p, Entity501B_StateSaveDone, 7);
  } else {
    Entity501B_SetState(p, Entity501B_StateSaveFailed, 8);
  }
}

// セーブできたと伝え, 120 フレームで画面を閉じ始め, 140 フレームを過ぎたらセッションを終える
void Entity501B_StateSaveDone(Entity501B* p) {
  if (p->entered) {
    TextPanel_SetScript(p->textPanels[0], p->unk_3d8);
    TextPanel_SetMessage(p->textPanels[0], 7);
    PlaySound_082406e0(686);
    p->stateTimer = 0;
    p->entered = FALSE;
  }
  if (p->stateTimer == 120) {
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
  } else if (p->stateTimer > 140) {
    FUN_081df940();
    return;
  }
  p->stateTimer++;
}

// セーブに失敗したと伝え, 60 フレーム後からボタンでソフトリセットする
void Entity501B_StateSaveFailed(Entity501B* p) {
  if (p->entered) {
    Sio_Disconnect();
    TextPanel_SetScript(p->textPanels[0], p->unk_3d8);
    TextPanel_SetMessage(p->textPanels[0], 5);
    PlaySound_082406e0(402);
    p->stateTimer = 0;
    p->entered = FALSE;
  }
  if (p->stateTimer < 60) {
    p->stateTimer++;
  } else if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    SoftReset_0823a928();
  }
}

NAKED void FUN_081e06d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e06d8.inc"); }

NAKED void FUN_081e084c(Entity501B* p) { INCFUNC("asm/func/FUN_081e084c.inc"); }

NAKED void FUN_081e0a18(Entity501B* p) { INCFUNC("asm/func/FUN_081e0a18.inc"); }

s32 Entity501B_Update(Entity501B* p) {
  if (!FUN_081dfa04()) {
    KillEntity((Entity*)p);
    return -1;
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 Entity501B_Destroy(Entity501B* p) {
  Entity501B_HideTextPanels(p);
  Entity501B_RemoveSprites(p);
  Entity501B_RemoveAuxSprite(p);
  return 1;
}

NAKED s32 Entity501B_Init(Entity501B* p) { INCFUNC("asm/func/Entity501B_Init.inc"); }

Entity501B* Entity501B_Create(void) {
  Entity501B* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity501B));

  if (p != NULL) {
    SetEntityRoutine(p, Entity501B_Update, Entity501B_Destroy);
    if (Entity501B_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
