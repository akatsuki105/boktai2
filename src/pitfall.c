#include "coffin.h"
#include "enemy.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "vm.h"

// Pitfall.flags (0xB8)
#define PITFLAG_UNK_0 (1 << 0)            // 0x001, 生成時に立つ
#define PITFLAG_OPENED (1 << 1)           // 0x002, 開ききって state 6 にいる, 閉じ始めると落ちる
#define PITFLAG_MOVER (1 << 3)            // 0x008, '.s', mover を登録している, Destroy で外す
#define PITFLAG_SCRIPTED (1 << 4)         // 0x010, '.m', 開閉をスクリプトに任せる, 落としても自動では閉じない
#define PITFLAG_OPEN_REQ (1 << 5)         // 0x020, 開けるように頼まれている (Cmd_779F)
#define PITFLAG_CLOSE_REQ (1 << 6)        // 0x040, 閉じるように頼まれている (Cmd_779F)
#define PITFLAG_PLAYER_FELL (1 << 7)      // 0x080, プレイヤーが落ちた, playerFallScriptID を実行する
#define PITFLAG_COFFIN_FELL (1 << 8)      // 0x100, 棺桶が落ちた, coffinFallScriptID を実行する
#define PITFLAG_DISABLED (1 << 9)         // 0x200, Update をしない (Cmd_0EE4)
#define PITFLAG_PULLING_COFFIN (1 << 10)  // 0x400, 落ちたプレイヤーが棺桶を引いていた, playerFallScriptID の最後の引数になる

// 落とし穴, 上に誰かが乗ると '.o' フレーム後に開く
typedef struct {
  AuxSprite sprite;        // 0x00
  Mover mover;             // 0x2C
  AuxAnimState anim;       // 0x70
  Vec3 pos;                // 0x80
  s16 id;                  // 0x88, '.i=0'
  u16 playerFallScriptID;  // 0x8A, '.R=0', PITFLAG_PLAYER_FELL が立つと id と scriptArgs を付けて実行し 0 に戻す
  u16 coffinFallScriptID;  // 0x8C, '.C=0', PITFLAG_COFFIN_FELL が立つと id を付けて実行し 0 に戻す
  u8 unk_8e[2];            // 0x8E, padding?
  u32 scriptArgs[6];       // 0x90, '.G', playerFallScriptID に渡す引数
  u32 unk_a8[2];           // 0xA8, '.A' の後ろから2個読む
  u16 kind;                // 0xB0, '.T=0' を4で頭打ち, アニメの variant とパレット選択に使い, 0 と 1 だけ開閉の音と土煙を出す
  u16 openDelay;           // 0xB2, '.o=60', 上に乗られてから開くまでのフレーム数
  s16 slotIdx;             // 0xB4, pits の idx
  s16 state;               // 0xB6, sPitfallUpdates の添字
  u16 flags;               // 0xB8, PITFLAG_*
  bool8 stateBegun;        // 0xBA, 立っていると次の更新で開閉のアニメを始める
  u8 stateTimer;           // 0xBB, state 2 で openDelay まで, state 4 で 30 まで数える
  s32 openTimer;           // 0xBC, state 5 と 6 で開いている間のフレーム数, state 5 は 30 を超えると閉じ始める
} Pitfall;
static_assert(sizeof(Pitfall) == 192);

// 落とし穴を12個まで抱えるエンティティ, 空きスロットは activeMask のビットで管理する
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  AuxAnimFile* anim;  // 0x18, ANIM_0AE9
  AuxSpriteGfx gfx;   // 0x1C, SPR_PITFALL_A945
  Pitfall* pits[12];  // 0x38
  u32 activeMask;     // 0x68, 1 << i で pits[i] が使用中
} PitfallManager;
static_assert(sizeof(PitfallManager) == 108);

static PitfallManager* sPitfallManager;  // 0x03000188

struct PitfallWarning* PitfallWarning_Spawn(Vec3* pos);
struct Player* FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx);
struct Enemy* FUN_080e1100(Vec3* pos, Vec3* size, u32* id);
PitfallManager* PitfallManager_Create(void);
s32 Pitfall_IsCoffinOnTop(Pitfall* p);
bool32 Coffin_IsState(s32 state);
bool32 FUN_0807a570(struct Player* p, s32 param_2);
void FUN_080868b8(bool32 param_1);
void Entity081ee7a8_SpawnDefaultNow(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 prio, s32 plttOffset, SpriteFlags flags);

static inline bool8 PitfallManager_IsPitUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Pitfall_RunFallScripts(Pitfall* p) {
  u32 args[8];
  ScriptArgs sa;

  if (p->flags & PITFLAG_COFFIN_FELL) {
    ClearMemory(args, sizeof(args));
    if (p->coffinFallScriptID != 0) {
      args[0] = p->id;
      sa.argc = 1;
      sa.argv = args;
      VM_ExecByID(p->coffinFallScriptID, &sa);
      p->coffinFallScriptID = 0;
    }
  }
  if (p->flags & PITFLAG_PLAYER_FELL) {
    ClearMemory(args, sizeof(args));
    if (p->playerFallScriptID != 0) {
      args[0] = p->id;
      args[1] = p->scriptArgs[0];
      args[2] = p->scriptArgs[1];
      args[3] = p->scriptArgs[2];
      args[4] = p->scriptArgs[3];
      args[5] = p->scriptArgs[4];
      args[6] = p->scriptArgs[5];
      args[7] = (p->flags >> 10) & 1;
      sa.argc = 8;
      sa.argv = args;
      VM_ExecByID(p->playerFallScriptID, &sa);
      p->playerFallScriptID = 0;
    }
  }
  p->flags &= ~(PITFLAG_PLAYER_FELL | PITFLAG_COFFIN_FELL | PITFLAG_PULLING_COFFIN);
}

// 穴の上に乗っているプレイヤー, 棺桶, 敵を落とす
// 残差はループ外に出す定数の違い (262/263), 原典は 0/1/3 を出し 22 を毎回作る
// enemy_manager.c の Enemy_RequestState / RequestSubState inline を通すと 263 命令で揃うが 22 を出してしまう, state の型を s32, 条件を != の && に, while(TRUE)+break は試済
NON_MATCH void Pitfall_DropOccupants(Pitfall* p) {
#ifdef NONMATCHING_C
  struct Player* players[4];
  u8 onPit[4];
  Vec3 size;
  u32 id;
  bool32 coffinOn;
  bool32 enemyFell;
  Enemy* e;
  s32 i;

  id = 0;
  size.z = Q8(0.5), size.x = Q8(0.5), size.y = Q8(0.063);
  for (i = 0; i < 4; i++) {
    onPit[i] = FALSE;
  }
  enemyFell = FALSE;
  coffinOn = FALSE;
  for (i = 0; i < 4; i++) {
    players[i] = FUN_080e11a8(&p->pos, &size, i);
    if (players[i] != NULL) {
      onPit[i] = TRUE;
      p->flags |= PITFLAG_PLAYER_FELL;
    }
  }
  if ((u8)Pitfall_IsCoffinOnTop(p)) {
    coffinOn = TRUE;
    p->flags |= PITFLAG_COFFIN_FELL;
  }
  while ((e = FUN_080e1100(&p->pos, &size, &id)) != NULL) {
    if (!(e->state == ES_UNK_22 || e->state == ES_DEFEATED)) {
      e->stateBegun = TRUE;
      e->subStateDone = FALSE;
      e->state = ES_UNK_22;
      e->handlerState = Enemy_StateFallDeath;
      e->stateTimer = 0;
      e->subState0 = 3;
      e->subState1 = 0;
      e->subState2 = 0;
      e->subStateTimer = 0;
      e->subStateBegun = TRUE;
      e->unk_4be = 0;
      Enemy_BurstEmitterParticles(e);
      enemyFell = TRUE;
    }
  }
  if (onPit[0] || onPit[1] || onPit[2] || onPit[3]) {
    if (gGameFlags & GAMEFLAG_LINK) {
      if (!(p->flags & PITFLAG_SCRIPTED)) {
        p->state = 5;
        p->stateBegun = 1;
      }
    } else {
      p->state = 7;
    }
    if (coffinOn) {
      for (i = 0; i < 4; i++) {
        if (onPit[i] && FUN_0807a570(players[i], 1)) {
          p->flags |= PITFLAG_PULLING_COFFIN;
        }
      }
      FUN_080868b8(TRUE);
    } else {
      for (i = 0; i < 4; i++) {
        if (onPit[i] && FUN_0807a570(players[i], 0)) {
          p->flags |= PITFLAG_PULLING_COFFIN;
        }
      }
    }
  } else if (coffinOn) {
    Pitfall_RunFallScripts(p);
    FUN_080868b8(FALSE);
    p->state = 5;
    p->stateBegun = 1;
  } else if (enemyFell && !(p->flags & PITFLAG_SCRIPTED)) {
    p->state = 5;
    p->stateBegun = 1;
  }
#else
  INCFUNC("asm/func/Pitfall_DropOccupants.inc");
#endif
}

// 空きスロットを1つ確保して要素を作る
Pitfall* PitfallManager_AllocPit(PitfallManager* p) {
  Pitfall* pit;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!PitfallManager_IsPitUsed(&p->activeMask, i)) {
      pit = Malloc(sizeof(Pitfall));
      ClearMemory(pit, sizeof(Pitfall));
      p->activeMask |= 1 << i;
      pit->slotIdx = i;
      p->pits[i] = pit;
      return pit;
    }
  }
  return NULL;
}

// 棺桶が xz とも 128 以内にあれば TRUE, 通信中と棺桶が state 6, 7 のときは FALSE
s32 Pitfall_IsCoffinOnTop(Pitfall* p) {
  WorldPos* coffinPos;
  Vec3 d;

  if (gGameFlags & GAMEFLAG_LINK) {
    return FALSE;
  }
  if (Coffin_IsState(6)) {
    return FALSE;
  }
  if (Coffin_IsState(7)) {
    return FALSE;
  }
  coffinPos = Coffin_GetPos();
  if (coffinPos == NULL) {
    return FALSE;
  }
  Vec3_Diff(&d, coffinPos, &p->pos);
  if (abs(d.x) > 128) {
    return FALSE;
  }
  if (abs(d.z) > 128) {
    return FALSE;
  }
  return TRUE;
}

void Pitfall_UpdateState0(Pitfall* _) {}

void Pitfall_UpdateState1(Pitfall* p) {
  Vec3 size;
  u32 hit;
  s32 i;

  p->sprite.flags |= SPRFLAG_HIDDEN;
  size.z = Q8(0.5), size.x = Q8(0.5), size.y = Q8(0.063);  // なぜか z, x, y の順番
  for (i = 0; i < 4; i++) {
    if (FUN_080e11a8(&p->pos, &size, i) != 0) {
      goto blocked;
    }
  }
  if ((u8)Pitfall_IsCoffinOnTop(p) == 0) {
    hit = 0;
    if (FUN_080e1100(&p->pos, &size, &hit) == 0) {
      return;
    }
  }
blocked:
  p->state = 2;
  p->stateTimer = 0;
}

// 穴の四隅と左右の6か所に土煙を出す, 通信中と kind が 2 以上のときは出さない
// 残差はレジスタ割当のみ (329/329), 原典は &gRandTableIdx を r4 に持ち続け定数 1 を毎回作るが, こちらは 1 を r4 に持ち &gRandTableIdx を毎回プールから読む
// Random / RandomNext (表を先に作る形はこちら), gRandomTable 直書き (348 で悪化), 土煙を出す inline, &p->pos のローカル化は試済
NON_MATCH void Pitfall_SpawnDust(Pitfall* p) {
#ifdef NONMATCHING_C
  Vec3 pos;

  if (gGameFlags & GAMEFLAG_LINK) {
    return;
  }
  switch (p->kind) {
    case 0:
    case 1: {
      pos = p->pos;
      pos.x += 92 - (RandomNext() & 63);
      pos.z += 92 - (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 4, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      pos = p->pos;
      pos.x -= 92 + (RandomNext() & 63);
      pos.z -= 92 + (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 4, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      pos = p->pos;
      pos.x -= 92 + (RandomNext() & 63);
      pos.z += 92 - (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 4, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      pos = p->pos;
      pos.x += 92 - (RandomNext() & 63);
      pos.z -= 92 + (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 2, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      pos = p->pos;
      pos.x -= 92 + (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 2, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      pos = p->pos;
      pos.x += 92 - (RandomNext() & 63);
      Entity081ee7a8_SpawnDefaultNow(&pos, 8, 8, 4, 4, 0, 0, 32, 64, 1, 1, SPRFLAG_BLINK_ODD);
      break;
    }
  }
#else
  INCFUNC("asm/func/Pitfall_SpawnDust.inc");
#endif
}

void Pitfall_UpdateState2(Pitfall* p) {
  PitfallManager* mgr = sPitfallManager;

  if (p->stateTimer >= p->openDelay) {
    Pitfall_SpawnDust(p);
    AuxAnim_SetAnim(&p->anim, mgr->anim, 0, p->kind, 0);
    p->state = 4;
    p->stateTimer = 0;
    switch (p->kind) {
      case 0:
      case 1: {
        if (gGameFlags & GAMEFLAG_LINK) {
          PlaySound_082406e0(SE_WOOD_DOOR_621);
        } else {
          PlaySound_082406e0(SE_OPEN_427);
        }
        break;
      }
    }
  } else {
    p->stateTimer++;
  }
}

// PITFLAG_OPEN_REQ が立っている間, 穴を開くアニメを流して上に乗ったものを落とし, 開ききったら state 6 へ移る
void Pitfall_UpdateState3(Pitfall* p) {
  PitfallManager* mgr = sPitfallManager;
  AuxSprite* sprite = &p->sprite;

  if (!(p->flags & PITFLAG_OPEN_REQ)) {
    return;
  }
  AuxSprite_Show(&p->sprite);
  if (p->stateBegun) {
    Pitfall_SpawnDust(p);
    AuxAnim_SetAnim(&p->anim, mgr->anim, 0, p->kind, 0);
    p->stateBegun = 0;
    switch (p->kind) {
      case 0:
      case 1: {
        if (gGameFlags & GAMEFLAG_LINK) {
          PlaySound_082406e0(SE_WOOD_DOOR_621);
        } else {
          PlaySound_082406e0(SE_OPEN_427);
        }
        break;
      }
    }
  }
  if ((p->anim.cmdIdx == 0 && p->anim.tick > 2) || (p->anim.cmdIdx == 1 && p->anim.tick != 0)) {
    Pitfall_DropOccupants(p);
  }
  if (AuxSprite_AdvanceAnim(sprite, &p->anim)) {
    p->state = 6;
    p->flags = (p->flags & ~PITFLAG_OPEN_REQ) | PITFLAG_OPENED;
  }
}

// 開くアニメを流し, 開ききった2コマ目の間は上に乗っているものを落とし続け, 30 フレームを超えたら state 5 へ移る
void Pitfall_UpdateState4(Pitfall* p) {
  AuxSprite* sprite = &p->sprite;

  AuxSprite_Show(&p->sprite);
  if (p->anim.cmdIdx == 1 && p->anim.tick != 0) {
    Pitfall_DropOccupants(p);
    p->stateTimer++;
  } else {
    AuxSprite_AdvanceAnim(sprite, &p->anim);
  }
  if (p->stateTimer > 30) {
    p->state = 5;
    p->stateBegun = 1;
    p->stateTimer = 0;
  }
}

// 30 フレーム待つ間は開いた穴に乗ったものを落とし続け, その後は閉じるアニメを逆再生して, 終わったら隠して state 1 へ戻る
void Pitfall_UpdateState5(Pitfall* p) {
  AuxSprite* sprite = &p->sprite;
  PitfallManager* mgr = sPitfallManager;

  if (p->openTimer > 30) {
    if (p->stateBegun) {
      AuxAnim_RestartAnim(&p->anim, mgr->anim, 0, p->kind, ANIM_PLAY_REVERSE);
      p->stateBegun = 0;
      switch (p->kind) {
        case 0:
        case 1: {
          PlaySound_082406e0(SE_OPEN_428);
          break;
        }
      }
    }
    if (AuxSprite_AdvanceAnim(sprite, &p->anim)) {
      AuxSprite_Hide(sprite);
      p->state = 1;
      p->openTimer = 0;
      return;
    }
  } else if (p->anim.cmdIdx == 1) {
    Pitfall_DropOccupants(p);
  }
  p->openTimer++;
}

// 開いたまま上に乗ったものを落とし続け, PITFLAG_CLOSE_REQ が立つと閉じるアニメを逆再生して, 終わったら隠して state 3 へ移る
void Pitfall_UpdateState6(Pitfall* p) {
  AuxSprite* sprite = &p->sprite;
  PitfallManager* mgr = sPitfallManager;

  AuxSprite_Show(&p->sprite);
  if (p->flags & PITFLAG_CLOSE_REQ) {
    if (p->stateBegun) {
      AuxAnim_RestartAnim(&p->anim, mgr->anim, 0, p->kind, ANIM_PLAY_REVERSE);
      p->stateBegun = 0;
      switch (p->kind) {
        case 0:
        case 1: {
          PlaySound_082406e0(SE_OPEN_428);
          break;
        }
      }
    }
    if (AuxSprite_AdvanceAnim(sprite, &p->anim)) {
      AuxSprite_Hide(sprite);
      p->state = 3;
      p->openTimer = 0;
      p->flags &= ~(PITFLAG_CLOSE_REQ | PITFLAG_OPENED);
      return;
    }
  } else {
    Pitfall_DropOccupants(p);
  }
  p->openTimer++;
}

void Pitfall_UpdateState7(Pitfall* p) { Pitfall_RunFallScripts(p); }

// アニメ 0 の2コマ目から再生を始めて1コマ進め, state 6 へ移る
void Pitfall_SetOpened(PitfallManager* p, Pitfall* pit) {
  AuxAnimState* anim;

  pit->sprite.flags &= ~SPRFLAG_HIDDEN;
  anim = &pit->anim;
  AuxAnim_SetAnim(anim, p->anim, 0, pit->kind, 0);
  pit->anim.cmdIdx = 1;
  AuxSprite_AdvanceAnim(&pit->sprite, anim);
  pit->state = 6;
  pit->flags = (pit->flags & ~PITFLAG_OPEN_REQ) | PITFLAG_OPENED;
}

void Pitfall_SetClosed(PitfallManager* p, Pitfall* pit) {
  pit->sprite.flags |= SPRFLAG_HIDDEN;
  pit->state = 3;
  pit->openTimer = 0;
  pit->flags &= ~(PITFLAG_CLOSE_REQ | PITFLAG_OPENED);
}

// 0x2FA5, HashName("落とし穴追加"), スクリプトの引数から落とし穴を1つ生成する
// 残差はレジスタ割当のみ (354/354, ハンク46), 原典は pit を r5, dst を r6 に置き, 先読みしたメンバのアドレスをスタックに作った順に並べるが, こちらは pit と dst が入れ替わりスタックの並びも逆になる
// アニメ送りを AuxSprite_AdvanceAnim inline に, T の上限を三項演算子にして命令数は揃った, dst のスコープ, 早期 return か if で包むかは試済
NON_MATCH void Cmd_AddPitfall(void) {
#ifdef NONMATCHING_C
  PitfallManager* p = sPitfallManager;
  Pitfall* pit;
  AuxSprite* sprite;
  u32* dst;
  Vec3 pos;
  s32 i;

  if (p == NULL) {
    p = PitfallManager_Create();
    if (p == NULL) {
      return;
    }
  }
  pit = PitfallManager_AllocPit(p);
  if (pit == NULL) {
    return;
  }
  pit->state = 1;
  if (VM_SeekToNamedArg('p')) {
    pit->pos.x = VM_GetValue();
    pit->pos.y = VM_GetValue();
    pit->pos.z = VM_GetValue();
  }
  pit->id = VM_GetNamedArgValue('i', 0);
  pit->playerFallScriptID = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('G')) {
    dst = pit->scriptArgs;
    for (i = 0; i < 6; i++) {
      *dst = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
      dst++;
    }
  }
  pit->coffinFallScriptID = VM_GetNamedArgValue('C', 0);
  if (VM_SeekToNamedArg('A')) {
    dst = pit->unk_a8;
    for (i = 0; i < 2; i++) {
      *dst = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
      dst++;
    }
  }
  pit->kind = VM_GetNamedArgValue('T', 0);
  pit->kind = pit->kind > 4 ? 4 : pit->kind;
  sprite = &pit->sprite;
  sprite->pos = pit->pos;
  sprite->pos.x -= 256;
  switch (pit->kind) {
    case 0: {
      Video_SetAuxSpritePltt(&p->gfx, 642);
      break;
    }
    case 1: {
      Video_SetAuxSpritePltt(&p->gfx, 643);
      break;
    }
  }
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&pit->anim, p->anim, 0, pit->kind, 0);
  AuxSprite_AdvanceAnim(sprite, &pit->anim);
  AuxSprite_Hide(sprite);
  sprite->priority = 2;
  pit->stateTimer = 0;
  pit->stateBegun = 0;
  pit->flags = PITFLAG_UNK_0;
  pit->openDelay = VM_GetNamedArgValue('o', 60);
  if (VM_GetNamedArgValue('m', 0) != 0) {
    pit->flags |= PITFLAG_SCRIPTED;
    switch (VM_GetNamedArgValue('S', 0)) {
      case 0: {
        Pitfall_SetClosed(p, pit);
        break;
      }
      case 1: {
        Pitfall_SetOpened(p, pit);
        break;
      }
    }
  }
  pos = pit->pos;
  PitfallWarning_Spawn(&pos);
  if (VM_GetNamedArgValue('s', 0) != 0) {
    pit->flags |= PITFLAG_MOVER;
    Mover_Init(&pit->mover, pit->id, &pit->pos, 0, MOVER_OBJECT, pit);
    Mover_SetAuxSprite(&pit->mover, &pit->sprite);
    FUN_08002a48(&pit->mover);
  }
#else
  INCFUNC("asm/func/Cmd_AddPitfall.inc");
#endif
}

// id が一致する使用中の落とし穴を探す, 無ければ NULL
Pitfall* PitfallManager_FindPitById(s32 id) {
  PitfallManager* p = sPitfallManager;
  Pitfall** pits = p->pits;
  u32 mask = p->activeMask;
  s32 i;

  if (mask == 0) {
    return NULL;
  }
  for (i = 0; i < 12; i++) {
    if (PitfallManager_IsPitUsed(&mask, i) && pits[i]->id == id) {
      return pits[i];
    }
  }
  return NULL;
}

void Cmd_0EE4(void) {
  s32 id = VM_GetNamedArgValue('i', -1);
  if (id >= 0) {
    s32 val = VM_GetNamedArgValue('s', 0);
    Pitfall* pit = PitfallManager_FindPitById(id);
    if (pit != NULL) {
      if (val == 1) {
        pit->flags |= PITFLAG_DISABLED;
        pit->sprite.flags |= SPRFLAG_HIDDEN;
      } else {
        pit->flags &= ~PITFLAG_DISABLED;
        pit->state = 1;
      }
    }
  }
}

// 0x3215
s32 Cmd_3215(void) {
  s32 key = VM_GetNamedArgValue('i', -1);
  Pitfall* pit;

  if (key < 0 || (pit = PitfallManager_FindPitById(key)) == NULL || (pit->flags & (PITFLAG_PLAYER_FELL | PITFLAG_COFFIN_FELL)) != (PITFLAG_PLAYER_FELL | PITFLAG_COFFIN_FELL)) {
    return 0;
  }
  return 1;
}

// 0x779F, '.i', '.s'
void Cmd_779F(void) {
  s32 val = VM_GetNamedArgValue('s', 0);
  Pitfall* pit = PitfallManager_FindPitById(VM_GetNamedArgValue('i', 0));

  if (pit != NULL) {
    switch (val) {
      case 0: {
        if (!(pit->flags & PITFLAG_CLOSE_REQ)) {
          pit->flags |= PITFLAG_CLOSE_REQ;
          pit->flags &= ~PITFLAG_OPEN_REQ;
          pit->state = 6;
          pit->stateBegun = 1;
        }
        break;
      }
      case 1: {
        if (!(pit->flags & PITFLAG_OPEN_REQ)) {
          pit->flags |= PITFLAG_OPEN_REQ;
          pit->flags &= ~PITFLAG_CLOSE_REQ;
          pit->state = 3;
          pit->stateBegun = 1;
        }
        break;
      }
    }
  }
}

void (*const sPitfallUpdates[8])(Pitfall*) = {
    Pitfall_UpdateState0,
    Pitfall_UpdateState1,
    Pitfall_UpdateState2,
    Pitfall_UpdateState3,
    Pitfall_UpdateState4,
    Pitfall_UpdateState5,
    Pitfall_UpdateState6,
    Pitfall_UpdateState7,
};  // 0x085AE098

// 使用中の落とし穴を state ごとに動かす, ゲームオーバー中と自分が倒れている間は止める
s32 PitfallManager_Update(PitfallManager* p) {
  Pitfall** pits = p->pits;
  s32 i;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return 0;
  }
  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (PitfallManager_IsPitUsed(&p->activeMask, i)) {
      Pitfall* pit = pits[i];

      if (!(pit->flags & PITFLAG_DISABLED)) {
        sPitfallUpdates[pit->state](pit);
      }
    }
  }
  return 0;
}

s32 PitfallManager_Destroy(PitfallManager* p) {
  Pitfall* pit;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (PitfallManager_IsPitUsed(&p->activeMask, i)) {
      pit = p->pits[i];
      AuxSprite_Remove(&pit->sprite);
      if (pit->flags & PITFLAG_MOVER) {
        Mover* mover = &pit->mover;
        FUN_08002a58(mover);
        Mover_Unlink(mover);
      }
      Free(pit);
    }
  }
  sPitfallManager = NULL;
  return 0;
}

s32 PitfallManager_Init(PitfallManager* p) {
  Video_GetAuxSprite(&p->gfx, SPR_PITFALL_A945);
  p->anim = GetFile(DIR_ANIMATION, ANIM_0AE9);
  sPitfallManager = p;
  p->activeMask = 0;
  return 0;
}

// 0xC419, HashName("落とし穴マネージャ")
PitfallManager* PitfallManager_Create(void) {
  if (sPitfallManager == NULL) {
    PitfallManager* p = CreateEntity(ENTITY_UNK_8, sizeof(PitfallManager));
    if (p != NULL) {
      SetEntityRoutine(p, PitfallManager_Update, PitfallManager_Destroy);
      if (PitfallManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sPitfallManager;
}

void PitfallManager_ClearGlobal(void) { sPitfallManager = NULL; }
