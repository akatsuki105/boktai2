#include "pile_driver.h"

#include "bg_pltt.h"
#include "camera.h"
#include "coffin.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "msgbus_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "time.h"
#include "video.h"
#include "vm.h"

COMMON_DATA PileDriver* gPileDriver = NULL;  // 0x03002C58

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }
static inline s32 GetSunGauge(void) { return gStat->sunGauge; }

const STRING_DATA char s_pile_driver_noon1_col_arr_08251d7c[] = "pile_driver_noon1_col_arr";
const STRING_DATA char s_pile_driver_even_col_arr_08251d98[] = "pile_driver_even_col_arr";
const STRING_DATA char s_pile_driver_night_col_arr_08251db4[] = "pile_driver_night_col_arr";
const STRING_DATA char s_ect_08251dd0[] = "ect";
const STRING_DATA char s_ect_anm_08251dd4[] = "ect_anm";
const STRING_DATA char gString_08251ddc[] = "../../skoba/enemy/system/eneinline.h";

void FUN_080df478(void);
void FUN_0822b234(AuxSpriteGfx* gfx, u32 val);
struct CuroroShotManager;  // ダーインが出す追尾弾 (技名はクロロホルルン+, エネミーのクロロホルルンとは別物) をまとめて動かす
struct CuroroShotManager* CuroroShotManager_Create(u32 param_1, u32 param_2);
s32 CuroroShotManager_VanishAll(struct CuroroShotManager* p);
s32 CuroroShotManager_Spawn(struct CuroroShotManager* p, Vec3* pos, Vec3* target, s32 angle, s32 speed, u32 hp);
void Camera_PanTo(s32 n, Vec3* pos);
void FUN_0807bcb0(Player* p, Dir8S32 dir, u32 scriptID);
void FUN_0807bbb0(Player* p, s32 param_2, u32 scriptID);
void Player_LockTurnTo(Player* p, Dir8S32 dir, u32 scriptID);
bool32 Player_LockRevertToDarkDjango(Player* p, u32 scriptID);
void FUN_0808613c(Coffin* p);
void FUN_08086590(Vec3* pos, s32 val);
s32 SporeManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos);
void Entity080df420_Spawn(WorldPos* pos, Vec3* vel, s32 kind, s32 unk_f0, s32 iframes, s32 power, s32 knockback, HitboxAttrs attrs, s32 atkIframes);
struct CrashNoiseRingManager* CrashNoiseRingManager_Create(u32 lifetime);
s32 CrashNoiseRingManager_Spawn(struct CrashNoiseRingManager* p, s32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 mosaicInterval, Vec3* pos);
struct Entity0805d79c* Entity0805d79c_Create(void);
s32 Entity0805d79c_Spawn(struct Entity0805d79c* p, s32 power, u32 angle, s32 speed, Vec3* pos);

void FUN_080ada64(PileDriver*);
void FUN_080ada9c(PileDriver*);
void FUN_080adb90(PileDriver*);
void FUN_080addac(PileDriver*);
void FUN_080add74(PileDriver*);
void FUN_080adca8(PileDriver*);
void FUN_080adc70(PileDriver*);
void FUN_080adc38(PileDriver*);
void FUN_080adc00(PileDriver*);
void FUN_080adbc8(PileDriver*);
void FUN_080adb28(PileDriver*);
void FUN_080adaf0(PileDriver*);
void FUN_080add3c(PileDriver*);

// subState を差し替えて subStateTimer を 0 に戻す
void PileDriver_SetSubState(PileDriver* p, u32 subState) {
  p->subState = subState;
  p->subStateTimer = 0;
}

// kind を引数にして eventScriptID のスクリプトを起動する
void PileDriver_RunEventScript(PileDriver* p, u32 kind) {
  ScriptArgs args;
  u32 argv[1];

  if (p->eventScriptID != 0) {
    args.argc = 1;
    argv[0] = kind;
    args.argv = argv;
    VM_ExecByID(p->eventScriptID, &args);
  }
}

void PileDriver_UpdateParticles(PileDriver* p) {
  PileDriverParticleSet* set = &p->ptclSet;

  if (set->active) {
    bool8 active = FALSE;
    s32 i;

    for (i = 0; i < 32; i++) {
      PileDriverParticle* ptcl = &set->ptcls[i];

      if (!ptcl->active) {
        continue;
      }
      if (ptcl->timer >= ptcl->lifetime) {
        ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
        ptcl->active = FALSE;
      } else {
        active = TRUE;
        ptcl->ptcl.pos.x += ptcl->vel.x;
        ptcl->ptcl.pos.y += ptcl->vel.y;
        ptcl->ptcl.pos.z += ptcl->vel.z;
        if (ptcl->timer == 6) {
          Particle_SetPose(&ptcl->ptcl, set->group, 3);
        }
        ptcl->timer++;
      }
    }
    set->active = active;
  }
}

void PileDriver_SpawnParticle(PileDriver* p, Vec3* pos, Vec3* vel, u32 lifetime, u32 priority) {
  PileDriverParticleSet* set = &p->ptclSet;
  PileDriverParticle* ptcl = &set->ptcls[set->next];

  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  ptcl->ptcl.pos = *pos;
  ptcl->ptcl.priority = priority;
  Particle_SetPose(&ptcl->ptcl, set->group, 2);
  ptcl->vel = *vel;
  ptcl->timer = 0;
  ptcl->lifetime = lifetime;
  ptcl->active = TRUE;
  set->active = TRUE;
  if (++set->next >= 32) {
    set->next = 0;
  }
}

void PileDriver_RemoveParticles(PileDriver* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    Particle_Remove(&p->ptclSet.ptcls[i].ptcl);
  }
}

void PileDriver_InitParticles(PileDriver* p) {
  PileDriverParticleSet* set = &p->ptclSet;
  s32 i;

  set->group = GetParticleGroup(PTCL_GROUP_2);
  set->active = FALSE;
  for (i = 0; i < 32; i++) {
    PileDriverParticle* ptcl = &set->ptcls[i];

    Particle_Add(&ptcl->ptcl, set->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->ptcl, -4, -4);
    Particle_SetPltt(&ptcl->ptcl, 1);
    ptcl->active = FALSE;
  }
}

// timeSpan から混ぜる元と先の時間帯 (0 昼 / 1 夕 / 2 夜) を決め, 移り変わりの時間帯なら色を混ぜ始める, 第2引数は読まず p->timeSpan を見る
void PileDriver_StartPlttFade(PileDriver* p, u32 timeSpan) {
  switch (p->timeSpan) {
    case 0: {
      p->plttFadeFrom = 2;
      p->plttFadeTo = 2;
      break;
    }
    case 1: {
      p->plttFadeFrom = 2;
      p->plttFadeTo = 0;
      p->plttFading = TRUE;
      p->plttFadeTimer = 0;
      break;
    }
    case 2: {
      p->plttFadeFrom = 0;
      p->plttFadeTo = 0;
      break;
    }
    case 3: {
      p->plttFadeFrom = 0;
      p->plttFadeTo = 1;
      p->plttFading = TRUE;
      p->plttFadeTimer = 0;
      break;
    }
    case 4: {
      p->plttFadeFrom = 1;
      p->plttFadeTo = 2;
      p->plttFading = TRUE;
      p->plttFadeTimer = 0;
      break;
    }
    case 5: {
      p->plttFadeFrom = 2;
      p->plttFadeTo = 2;
      break;
    }
  }
}

// 枠が動いていて隠れてもいないかどうか
bool32 PileDriverAnimSprite_IsVisible(PileDriverAnimSprite* p) {
  if (!p->active) {
    return FALSE;
  }
  if (p->sprite.flags & SPRFLAG_HIDDEN) {
    return FALSE;
  }
  return TRUE;
}

// 129フレーム周期のカウンタから 0, 1, 2, 3, 2, 1 と往復するポーズ番号を返す
s32 PileDriverAnimSprite_StepPose(PileDriverAnimSprite* p) {
  if (++p->animTimer > 129) {
    p->animTimer = 0;
  }

  if (p->animTimer <= 29) {
    return 0;
  }
  if (p->animTimer <= 39) {
    return 1;
  }
  if (p->animTimer <= 49) {
    return 2;
  }
  if (p->animTimer <= 109) {
    return 3;
  }
  if (p->animTimer <= 119) {
    return 2;
  }
  return 1;
}

// 昼 / 夕 / 夜の BG パレット ('.A' か "pile_driver_*_col_arr") を読み込み, 今の時間帯の色を bgPltts と BG パレットへ写し, 魔方陣の中心の色も合わせる
// 142/142 命令, 残差はパレット番号の足し算の順のみ, 原典は pose + 392 を先に作ってから plttFadeTo * 4 に足すが, こちらは 392 を先に plttFadeTo * 4 に足す (PileDriver_UpdatePlttFade に同じ式が2か所ある)
// Tier A-C 試済 (括弧, 項の順, (u32) で結合を切る)
NON_MATCH void PileDriver_InitBgPltt(PileDriver* p) {
#ifdef NONMATCHING_C
  u32 ids[3];
  rgb555* src;
  s32 i;

  if (VM_SeekToNamedArg('A')) {
    for (i = 0; i < 3; i++) {
      ids[i] = VM_GetValue();
    }
  } else {
    ids[0] = HashName(s_pile_driver_noon1_col_arr_08251d7c);
    ids[1] = HashName(s_pile_driver_even_col_arr_08251d98);
    ids[2] = HashName(s_pile_driver_night_col_arr_08251db4);
  }
  for (i = 0; i < 3; i++) {
    p->timePltts[i] = GetBgPlttFile(ids[i])->body;
  }
  p->timeSpan = Time_GetSpanOfTime();
  PileDriver_StartPlttFade(p, p->timeSpan);
  p->plttFading = FALSE;
  p->plttFadeTimer = 0;
  src = p->timePltts[p->plttFadeTo];
  for (i = 0; i < 16; i++) {
    CpuCopy32(&src[i * 16], p->bgPltts[i], 32);
  }
  for (i = 0; i < 3; i++) {
    CpuCopy32(&src[i * 16], &gBgPlttBuffer[i * 16], 32);
  }
  for (i = 0; i < 3; i++) {
    p->bgPlttIdx[i] = i;
  }
  if (PileDriverAnimSprite_IsVisible(&p->centerSprite)) {
    p->centerSprite.pose = PileDriverAnimSprite_StepPose(&p->centerSprite);
    Video_SetAuxSpritePltt(&p->centerSprite.gfx, p->plttFadeTo * 4 + p->centerSprite.pose + 392);
  }
  p->updateCallback = NULL;
#else
  INCFUNC("asm/func/PileDriver_InitBgPltt.inc");
#endif
}

// 時間帯が変わったら 64 フレームかけて BG パレット (bgPltts) と魔方陣の中心の色を次の時間帯の色へ混ぜる, 混ぜていない間は中心のポーズの色だけ合わせる
// 318/318 命令, 残差は (1) パレット番号が原典は plttFade* * 4 + (pose + 392) の組み (PileDriver_InitBgPltt と同じ, 4 か所), (2) 色を分ける 0x1F をどのレジスタで作り回すか, の2つ
// Tier A-C 試済 (MakeRgb555 inline をやめて直書き, 成分をローカルへ, inv と t の宣言順, 2つ目のループに別の添字, pose + 392 を inline で区切る (呼び出しが先に評価されて悪化))
NON_MATCH void PileDriver_UpdatePlttFade(PileDriver* p) {
#ifdef NONMATCHING_C
  u32 span = Time_GetSpanOfTime();

  if (p->timeSpan != span) {
    p->timeSpan = span;
    PileDriver_StartPlttFade(p, p->timeSpan);
  }
  if (p->plttFading) {
    p->bgPlttDirty = TRUE;
    if (++p->plttFadeTimer >= 64) {
      rgb555* src = p->timePltts[p->plttFadeTo];
      s32 i;

      for (i = 0; i < 16; i++) {
        CpuCopy32(&src[i * 16], p->bgPltts[i], 32);
      }
      p->plttFading = FALSE;
      if (PileDriverAnimSprite_IsVisible(&p->centerSprite)) {
        p->centerSprite.pose = PileDriverAnimSprite_StepPose(&p->centerSprite);
        Video_SetAuxSpritePltt(&p->centerSprite.gfx, p->plttFadeTo * 4 + p->centerSprite.pose + 392);
      }
    } else {
      s32 inv = 64 - p->plttFadeTimer;
      s32 t = p->plttFadeTimer;
      rgb555* from = p->timePltts[p->plttFadeFrom];
      rgb555* to = p->timePltts[p->plttFadeTo];
      s32 i;
      s32 j;

      for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
          s32 ar = *from & 0x1F;
          s32 ag = (*from >> 5) & 0x1F;
          s32 ab = (*from >> 10) & 0x1F;
          s32 br = *to & 0x1F;
          s32 bg = (*to >> 5) & 0x1F;
          s32 bb = (*to >> 10) & 0x1F;
          s32 r = (inv * ar + t * br) >> 6;
          s32 g = (inv * ag + t * bg) >> 6;
          s32 b = (inv * ab + t * bb) >> 6;

          p->bgPltts[i][j] = (b << 10) | (g << 5) | r;
          from++;
          to++;
        }
      }
      if (PileDriverAnimSprite_IsVisible(&p->centerSprite)) {
        s32 pose = PileDriverAnimSprite_StepPose(&p->centerSprite);
        rgb555* a = &gObjPlttData[(p->plttFadeFrom * 4 + pose + 392) * 16];
        rgb555* c = &gObjPlttData[(p->plttFadeTo * 4 + pose + 392) * 16];
        s32 k;

        for (k = 0; k < 16; k++) {
          s32 ar = *a & 0x1F;
          s32 ag = (*a >> 5) & 0x1F;
          s32 ab = (*a >> 10) & 0x1F;
          s32 br = *c & 0x1F;
          s32 bg = (*c >> 5) & 0x1F;
          s32 bb = (*c >> 10) & 0x1F;
          s32 r = (inv * ar + t * br) >> 6;
          s32 g = (inv * ag + t * bg) >> 6;
          s32 b = (inv * ab + t * bb) >> 6;

          p->centerSprite.pltt[k] = (b << 10) | (g << 5) | r;
          a++;
          c++;
        }
        p->centerSprite.gfx.pltt = p->centerSprite.pltt;
      }
    }
  } else if (PileDriverAnimSprite_IsVisible(&p->centerSprite)) {
    s32 pose = PileDriverAnimSprite_StepPose(&p->centerSprite);

    if (pose != p->centerSprite.pose) {
      p->centerSprite.pose = pose;
      Video_SetAuxSpritePltt(&p->centerSprite.gfx, p->plttFadeTo * 4 + p->centerSprite.pose + 392);
    }
  }
#else
  INCFUNC("asm/func/PileDriver_UpdatePlttFade.inc");
#endif
}

void PileDriver_UpdateBgPltt(PileDriver* p) {
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  PileDriver_UpdatePlttFade(p);
  if (p->bgPlttDirty) {
    s32 i;

    for (i = 0; i < 3; i++) {
      CpuCopy32(p->bgPltts[p->bgPlttIdx[i]], &gBgPlttBuffer[i * 16], 32);
    }
    p->bgPlttDirty = FALSE;
  }
}

void FUN_080ad9d4(PileDriver* p, s32 idx, u16 val) {
  p->bgPlttIdx[idx] = val;
  p->bgPlttDirty = TRUE;
}

void PileDriver_SetState(PileDriver* p, PileDriverFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ada0c(PileDriver* p) {
  FUN_080ad9d4(p, 2, 2);
  PileDriver_SetState(p, NULL);
}

void FUN_080ada28(PileDriver* p) {
  FUN_080ad9d4(p, 2, 5);
  PileDriver_SetState(p, NULL);
}

void FUN_080ada44(PileDriver* p) {
  FUN_080ad9d4(p, 2, 3);
  PileDriver_SetState(p, FUN_080ada64);
}

void FUN_080ada64(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 4);
    PileDriver_SetState(p, FUN_080ada9c);
  }
}

void FUN_080ada9c(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 5);
    PileDriver_SetState(p, NULL);
  }
}

void FUN_080adad0(PileDriver* p) {
  FUN_080ad9d4(p, 2, 4);
  PileDriver_SetState(p, FUN_080adaf0);
}

void FUN_080adaf0(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 3);
    PileDriver_SetState(p, FUN_080adb28);
  }
}

void FUN_080adb28(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, NULL);
  }
}

void FUN_080adb5c(PileDriver* p) {
  FUN_080ad9d4(p, 2, 6);
  PileDriver_SetState(p, FUN_080adb90);
  p->unk_1420 = 0;
  p->stateTimer = 0;
}

void FUN_080adb90(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 7);
    PileDriver_SetState(p, FUN_080adbc8);
  }
}

void FUN_080adbc8(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 8);
    PileDriver_SetState(p, FUN_080adc00);
  }
}

void FUN_080adc00(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 9);
    PileDriver_SetState(p, FUN_080adc38);
  }
}

void FUN_080adc38(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 10);
    PileDriver_SetState(p, FUN_080adc70);
  }
}

void FUN_080adc70(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 11);
    PileDriver_SetState(p, FUN_080adca8);
  }
}

void FUN_080adca8(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, NULL);
    p->unk_1420 = 1;
  }
}

void FUN_080adce4(PileDriver* p) {
  FUN_080ad9d4(p, 2, 12);
  PileDriver_SetState(p, FUN_080add3c);
}

void FUN_080add04(PileDriver* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    PileDriver_SetState(p, FUN_080add3c);
  }
}

void FUN_080add3c(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 13);
    PileDriver_SetState(p, FUN_080add74);
  }
}

void FUN_080add74(PileDriver* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    PileDriver_SetState(p, FUN_080addac);
  }
}

void FUN_080addac(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, FUN_080add04);
  }
}

// 太陽ゲージに応じた BGP_PD のパレット行を返す
s32 FUN_080adde4(PileDriver* p) {
  switch (p->sunGauge) {
    case 0: {
      return 8;
    }
    case 1:
    case 2: {
      return 6;
    }
    case 3: {
      return 4;
    }
    case 4: {
      return 2;
    }
    case 7:
    case 8: {
      return 10;
    }
    case 9:
    case 10: {
      return 12;
    }
    default: {
      return 0;
    }
  }
}

void PileDriver_LoadBgPltt(PileDriver* p) {
  rgb555* bgp = GetBgPlttFile(BGP_PD)->body;
  CpuCopy32(&bgp[FUN_080adde4(p) * 16], gBgPlttBuffer, 32 * sizeof(rgb555));
}

// immortalIdx ごとのイモータルの姿のタイルマップ
static const FileID sImmortalTilemaps[6] = {MP_8446, MP_8546, MP_8646, MP_8746, MP_8846, MP_8946};  // 0x085AD048

// イモータルの姿のタイルマップを BG1 に読み込み, まだ隠したまま半透明で重ねる設定にする
void PileDriver_InitImmortalTilemap(PileDriver* p) {
  s32 bgIndex;

  p->immortalTilemap = GetFile(DIR_TILE_MAP, sImmortalTilemaps[p->immortalIdx]);
  bgIndex = 0;
  Video_SetupBGLayout(3, 0, p->immortalTilemap, 0, 0, 1, &bgIndex);
  Video_SetBGLayer(1, p->immortalTilemap, 0);
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  SetBGPrioDirect(1, 0);
  REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD;
  REG_BLDALPHA = BLDALPHA_BLEND(16, 8);
  REG_BLDY = 0;
  p->immortalPltt = &GetBgPlttFile(BGP_F308)->body[192];
  CpuCopy32(p->immortalPltt, &gBgPlttBuffer[192], 32);
}

void PileDriver_FlashImmortal(PileDriver* p) { p->immortalBgTimer = 48; }

void Cmd_054A(void) {
  if (gPileDriver != NULL) {
    gPileDriver->immortalBgTimer = 64;
    gPileDriver->immortalBgShakeY = 0;
    gPileDriver->immortalVanishing = TRUE;
    PlaySound_082406e0(SE_UNK_297);
  }
}

// BG1 のイモータルの姿を半透明で出す, ライフが残っている間は immortalBgTimer の間だけ光らせ, ライフが 0 になったら揺らしながら煙を出し, immortalVanishing が立つと粒子を撒いて消えていき, 消えきったらスクリプト 9 を起動する
// 418/419 命令, 原典は immortalBgTimer を HI のまま持って (ldrh のあと lsl/lsr で広げる) 比較・& 3・>> 1 に使い回す, u16 を返す inline アクセサを毎回呼ぶ形で 1 命令差まで寄るが r4/r5 の入れ替わりと immortalBgShakeY への格納の合流位置が残る
// Tier A-C 試済 (u16 ローカル, inline アクセサ, eva の宣言位置, & 7 を % 8, 三項演算子)
NON_MATCH void PileDriver_UpdateImmortalBg(PileDriver* p, s32 param_2, s32 param_3, u32 param_4, s32 param_5) {
#ifdef NONMATCHING_C
  s32 eva;

  if (gStat->bossHP > 0) {
    u16 t = p->immortalBgTimer;

    if (t == 0) {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
      return;
    }
    SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    if (t >= 32) {
      eva = 16;
      if (t >= 36) {
        p->immortalBgShakeY = (Random() >> 3) & 7;
      } else {
        p->immortalBgShakeY = 5;
      }
    } else {
      eva = t >> 1;
      if ((t & 3) == 0 && p->immortalBgShakeY > 0) {
        p->immortalBgShakeY--;
      }
    }
    REG_BLDALPHA = BLDALPHA_BLEND(eva, ((16 - eva) >> 1) + 8);
    Video_GenerateBGMap(1, param_2, param_3, param_4, param_5 + p->immortalBgShakeY);
    p->immortalBgTimer--;
    return;
  }
  CpuCopy32(&p->immortalPltt[16], &gBgPlttBuffer[192], 32);
  if (!p->immortalVanishing) {
    SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    if (++p->immortalBgTimer > 63) {
      p->immortalBgTimer = 0;
    }
    if (p->immortalBgTimer > 32) {
      eva = (64 - p->immortalBgTimer) >> 3;
    } else {
      eva = p->immortalBgTimer >> 3;
    }
    eva += 12;
    REG_BLDALPHA = BLDALPHA_BLEND(eva, ((16 - eva) >> 1) + 8);
    p->immortalBgShakeY = (Random() >> 3) & 7;
    Video_GenerateBGMap(1, param_2, param_3, param_4, param_5 + p->immortalBgShakeY);
    if ((p->immortalBgTimer & 3) == 0) {
      Vec3 pos = p->coffinPos;
      Vec3 size;

      pos.x += 64;
      pos.z += 64;
      VEC3_SET(size, 300, 300, 300);
      EmitSmoke(&pos, 1, &size, 0, 0, 48, 2, 1);
    }
  } else if (p->immortalBgTimer != 0) {
    Vec3 pos = p->coffinPos;
    Vec3 vel;

    pos.x += Mod(RandomNext(), 500) - 250;
    pos.y += Mod(RandomNext(), 500) - 250;
    pos.z += Mod(RandomNext(), 500) - 250;
    VEC3_SET(vel, 0, (RandomNext() & 31) + 16, 0);
    PileDriver_SpawnParticle(p, &pos, &vel, (RandomNext() & 7) + 8, 1);
    SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    eva = p->immortalBgTimer >> 2;
    REG_BLDALPHA = BLDALPHA_BLEND(eva, ((16 - eva) >> 1) + 8);
    if ((p->immortalBgTimer & 7) == 0 && p->immortalBgShakeY <= 6) {
      p->immortalBgShakeY++;
    }
    Video_GenerateBGMap(1, param_2, param_3, param_4, param_5 + p->immortalBgShakeY);
    if (--p->immortalBgTimer == 0) {
      PileDriver_RunEventScript(gPileDriver, 9);
    }
  } else {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  }
#else
  INCFUNC("asm/func/PileDriver_UpdateImmortalBg.inc");
#endif
}

// MP_AD57 のタイルマップと点滅用のパレットを読み込んで BG3 を出す
void PileDriver_InitTilemap(PileDriver* p) {
  TilemapFile* f = GetFile(DIR_TILE_MAP, MP_AD57);
  Tilemaps tm;
  s32 i;

  p->unk_4dc = f;
  tm = *f;
  tm.layers = (TilemapLayer*)((u32)tm.layers + (u32)f);
  tm.tiles = (u8*)((u32)tm.tiles + (u32)f);
  tm.metatiles = (BgMapEntry*)((u32)tm.metatiles + (u32)f);
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
  SetBGPrioDirect(3, 1);
  p->plttSrc = &GetBgPlttFile(BGP_E2BA)->body[128];
  for (i = 0; i < 4; i++) {
    p->drawnBeamKinds[i] = 5;
    p->beamKinds[i] = 5;
  }
}

// 2フレームごとに plttSrc の4組を順に BG パレットの11行目へ送る
void PileDriver_CyclePltt(PileDriver* p) {
  if (++p->plttTimer & 1) {
    s32 set = (p->plttTimer >> 1) & 3;

    CpuCopy32(&p->plttSrc[set * 16], &gBgPlttBuffer[176], 32);
  }
}

// BG3 に, 稼働中のジェネレーターごとに魔方陣の中心へ向かう光の柱のタイルを MP_AD57 のレイヤから写し, 止まったら消す, 新しく光ったら音を鳴らす
// 498/500 命令 (67 hunk), 原典は tilemap を sb, 区画の端を r7 / r2 / ip / r8 に置くがこちらは割当がずれ, 区画を決める switch の後半を共有する形も違う
// Tier A-C 試済 (BgState* ローカル, height16 を s16, kind の if の形, 端の宣言順, 添字を << 5 で書く (これで命令数が揃った), tilemap の宣言位置)
NON_MATCH void PileDriver_DrawBeams(PileDriver* p, s32 param_2, s32 param_3, s32 hofs, s32 vofs) {
#ifdef NONMATCHING_C
  BgState* bg = &gBgStates[3];
  Tilemaps tm;
  TilemapLayer layer;
  Vec3 vp;
  BgMapEntry* tilemap;
  s32 width;
  s32 height;
  TilemapLayer* layers;
  MetatileIdx16* mtmap;
  s32 widthBlocks;
  s32 col;
  s32 row;
  bool32 started = FALSE;
  s32 i;

  PileDriver_CyclePltt(p);
  bg->unk_10 = param_2;
  bg->unk_12 = param_3;
  bg->hofs = hofs;
  bg->vofs = vofs;
  tilemap = bg->tilemap;
  width = bg->width16 * 2;
  height = bg->height16 * 2;
  WorldToVp(&vp, &p->center);
  col = vp.x + gCameraCoords.tilemapX;
  row = vp.y + gCameraCoords.tilemapY;
  col = FixToInt(3, col);
  row = FixToInt(3, row) & ~1;
  col -= param_2;
  row -= param_3;
  tm = *p->unk_4dc;
  tm.layers = (TilemapLayer*)((u32)tm.layers + (u32)p->unk_4dc);
  layers = tm.layers;
  p->unk_132a = 0;
  for (i = 0; i < p->generatorCount; i++) {
    u32 kind;
    s32 x1, y1, x0, y0;
    s32 x, y;

    if (p->sunGauge != 0 && (p->subState == PILEDRIVER_SUB_BATTLE_DRIVE || p->subState == PILEDRIVER_SUB_END)) {
      kind = 5;
      if (p->generators[i]->state == 4) {
        kind = 0;
      }
    } else {
      kind = 5;
    }
    p->beamKinds[i] = kind;
    if (p->drawnBeamKinds[i] == kind) {
      continue;
    }
    if (kind == 0) {
      started = TRUE;
    }
    p->drawnBeamKinds[i] = kind;
    switch (i) {
      case 0: {
        x1 = col;
        y1 = row;
        x0 = x1 - 7;
        if (x0 < 0) {
          x0 = 0;
        }
        y0 = y1 - 6;
        if (y0 < 0) {
          y0 = 0;
        }
        break;
      }
      case 2: {
        x1 = col + 7;
        y1 = row;
        x0 = col;
        if (x0 < 0) {
          x0 = 0;
        }
        y0 = y1 - 6;
        if (y0 < 0) {
          y0 = 0;
        }
        break;
      }
      case 3: {
        x1 = col;
        y1 = row + 4;
        x0 = x1 - 7;
        if (x0 < 0) {
          x0 = 0;
        }
        y0 = row;
        if (y0 < 0) {
          y0 = 0;
        }
        break;
      }
      case 1: {
        x1 = col + 7;
        y1 = row + 4;
        x0 = col;
        if (x0 < 0) {
          x0 = 0;
        }
        y0 = row;
        if (y0 < 0) {
          y0 = 0;
        }
        break;
      }
      default: {
        x1 = y1 = y0 = x0 = -1;
        break;
      }
    }
    if (x1 < 0 || y1 < 0 || x0 > 31 || y0 > 31) {
      continue;
    }
    widthBlocks = bg->width16 >> 4;
    if (kind == 5) {
      for (y = y0; y < y1; y += 2) {
        for (x = x0; x < x1; x++) {
          s32 tx = (param_2 + x) & 31;
          s32 ty = (param_3 + y) & 31;

          tilemap[tx + (ty << 5)] = 0;
          tilemap[tx + ((ty + 1) << 5)] = 0;
        }
      }
    } else {
      layer = layers[kind + 1];
      layer.mtmap = (MetatileIdx16*)((u32)layer.mtmap + (u32)p->unk_4dc);
      bg->mtmap = layer.mtmap;
      mtmap = layer.mtmap;
      for (y = y0; y < y1; y += 2) {
        for (x = x0; x < x1; x++) {
          s32 tx = param_2 + x;
          s32 ty = param_3 + y;

          if (tx < 0 || ty < 0 || tx >= width || ty >= height) {
            tx &= 31;
            ty &= 31;
            tilemap[tx + (ty << 5)] = 0;
            tilemap[tx + ((ty + 1) << 5)] = 0;
          } else {
            s32 block = (FixToInt(5, tx) + FixToInt(5, ty) * widthBlocks) << 8;
            BgMapEntry* mt;

            tx &= 31;
            ty &= 31;
            mt = &bg->metatiles[mtmap[block + FixToInt(1, tx) + (FixToInt(1, ty) << 4)] * 4];
            if (!(tx & 1)) {
              tilemap[tx + (ty << 5)] = mt[0];
              tilemap[tx + ((ty + 1) << 5)] = mt[2];
            } else {
              tilemap[tx + (ty << 5)] = mt[1];
              tilemap[tx + ((ty + 1) << 5)] = mt[3];
            }
          }
        }
      }
    }
  }
  if (started) {
    PlaySound_082406e0(SONG_245);
  }
#else
  INCFUNC("asm/func/PileDriver_DrawBeams.inc");
#endif
}

// カメラの位置からタイルの座標と BG のスクロール量を出して, タイルマップを描き直す
void PileDriver_UpdateTilemap(PileDriver* p) {
  s32 x = gCameraVpCoords.x + gCameraCoords.tilemapX;
  s32 y = gCameraVpCoords.y + gCameraCoords.tilemapY;
  s32 tileX = FixToInt(3, x - 128);
  s32 tileY = FixToInt(3, y - 128) & ~1;

  PileDriver_UpdateImmortalBg(p, tileX, tileY, x - 120, y - 90);
  PileDriver_DrawBeams(p, tileX, tileY, x - 120, y - 90);
}

// ドゥネイルのバトルドライブの攻撃, 合間ごとに 1P への向きを決め, 魔方陣の中心からその向きへ遠ざかりながら 4 フレームおきに燐粉を撒く
// 175/175 命令, 残差はレジスタ割当のみ, 原典は乱数表の番地を毎回読み直すが, こちらは r4 に持ち続けるので p / dist / 乱数がそれぞれ1つずつずれる (Ectoplasm_StartOrbit と同じ壁)
// Tier A-C 試済 (- 64 の位置, RandomNext, 乱数表の直書き)
NON_MATCH void PileDriver_AttackDuneyrr(PileDriver* p) {
#ifdef NONMATCHING_C
  if (p->attackTimer < p->attackDuration) {
    if (++p->attackTimer >= p->attackDuration) {
      s32 dx = gPlayerPtr[0]->mover.pos.x - p->center.x;
      s32 dz = gPlayerPtr[0]->mover.pos.z - p->center.z;

      p->attackAngle = ArcTan2_8(dx, dz);
      p->fireTimer = 0;
    }
  } else if (++p->fireTimer <= 47) {
    if ((p->fireTimer & 3) == 0) {
      s32 dist = p->fireTimer * 16;
      Vec3 pos;

      pos.x = (Random() & 127) - 64 + p->center.x + POLAR_X(dist, p->attackAngle);
      pos.y = p->center.y;
      pos.z = (Random() & 127) - 64 + p->center.z + POLAR_Z(dist, p->attackAngle);
      SporeManager_Emit(1, 0, 256, 2, 2, 20, p->attackPower, 3, &pos);
    }
  } else {
    p->attackTimer = 0;
  }
#else
  INCFUNC("asm/func/PileDriver_AttackDuneyrr.inc");
#endif
}

// ドゥラスロールのバトルドライブの攻撃, 合間を置いて 32 フレームおきに3回, 魔方陣の中心から棘を8方向に撃つ
// 残差は Random() の gRandTableIdx の番地と値のレジスタ (r0/r1 と r2/r0) の入れ替わりのみ (76/76)
// Tier A-C 試済 (else 節の並び, angle を (u8) / & 0xFF / RandomNext, 宣言を関数先頭へ)
NON_MATCH void PileDriver_AttackDurathror(PileDriver* p) {
#ifdef NONMATCHING_C
  if (p->attackTimer < p->attackDuration) {
    if (++p->attackTimer >= p->attackDuration) {
      p->fireTimer = 0;
    }
  } else if (++p->fireTimer <= 127) {
    if ((p->fireTimer & 31) == 0) {
      s32 angle = Random() & 0xFF;
      s32 i;

      for (i = 0; i < 8; i++) {
        Entity0805d79c_Spawn(p->attackManager, p->attackPower, angle, 24, &p->center);
        angle = (angle + 32) & 0xFF;
      }
      PlaySound_082406e0(SE_378);
    }
  } else {
    p->attackTimer = 0;
  }
#else
  INCFUNC("asm/func/PileDriver_AttackDurathror.inc");
#endif
}

// ドヴァリンのバトルドライブの攻撃, 撃つ向きを 1P へ少しずつ回しながら 7 フレームおきにバブルブレスを ±24 の範囲に撃ち, 42 フレームおきに kind 8 の遅い弾にする
// 268/277 命令, 原典は乱数表の番地を毎回読み直すが, こちらは r9 に持ち続けるので高位レジスタが1本増える (Ectoplasm_StartOrbit と同じ壁)
// Tier A-C 試済 (散らす向きの足し方, RandomNext を全部 / 後の2つ)
NON_MATCH void PileDriver_AttackDvalinn(PileDriver* p) {
#ifdef NONMATCHING_C
  if (p->attackTimer < p->attackDuration) {
    if (++p->attackTimer >= p->attackDuration) {
      s32 dx = gPlayerPtr[0]->mover.pos.x - p->center.x;
      s32 dz = gPlayerPtr[0]->mover.pos.z - p->center.z;

      p->attackAngle = ArcTan2_8(dx, dz);
      p->fireTimer = 0;
    }
  } else {
    s32 dx = gPlayerPtr[0]->mover.pos.x - p->center.x;
    s32 dz = gPlayerPtr[0]->mover.pos.z - p->center.z;
    s32 target = ArcTan2_8(dx, dz);

    if (((target + 256 - p->attackAngle) & 0xFF) < 128) {
      p->attackAngle = (p->attackAngle + 1) & 0xFF;
    } else {
      p->attackAngle = (p->attackAngle + 255) & 0xFF;
    }
    if (++p->fireTimer <= 127) {
      if (Mod(p->fireTimer, 7) == 0) {
        s32 angle = Mod(Random(), 48) + 256;
        Vec3 vel;
        s32 speed;

        angle = (angle + p->attackAngle - 24) & 0xFF;

        if (Mod(p->fireTimer, 42) == 0) {
          speed = (Random() & 3) + 8;
          vel.x = POLAR_X(speed, angle);
          vel.y = 0;
          vel.z = POLAR_Z(speed, angle);
          Entity080df420_Spawn(&p->center, &vel, 8, 150, 10, p->attackPower, 5, 8, 10);
        } else {
          speed = (Random() & 3) + 12;
          vel.x = POLAR_X(speed, angle);
          vel.y = 0;
          vel.z = POLAR_Z(speed, angle);
          Entity080df420_Spawn(&p->center, &vel, 4, 150, 10, p->attackPower, 5, 8, 10);
        }
      }
    } else {
      p->attackTimer = 0;
    }
  }
#else
  INCFUNC("asm/func/PileDriver_AttackDvalinn.inc");
#endif
}

// ダーインのバトルドライブの攻撃, 撃ち始めに魔方陣の中心のまわり 3 か所からクロロホルルン+ を 1P へ撃ち, 合間の途中 (300 フレーム目) で残りを消す
// 192/193 命令, 原典はループの前に gSineTable / 0xFF / 回数を sl / r8 / sb に括り出すが, こちらは括り出す定数と順がずれ, 最初の乱数のレジスタも違う
// Tier A-C 試済 (pos の宣言位置, 向きの足し順, RandomNext, 最初の乱数を & 0xFF)
NON_MATCH void PileDriver_AttackDainn(PileDriver* p) {
#ifdef NONMATCHING_C
  if (p->attackTimer < p->attackDuration) {
    if (p->attackTimer == 300) {
      CuroroShotManager_VanishAll(p->attackManager);
    }
    if (++p->attackTimer >= p->attackDuration) {
      p->fireTimer = 0;
    }
  } else {
    if (p->fireTimer == 0) {
      s32 angle = (u8)Random();
      s32 i;

      for (i = 0; i < 3; i++) {
        Vec3 pos = p->center;

        pos.x += POLAR_X(64, angle);
        pos.y += (Random() & 31) + 128;
        pos.z += POLAR_Z(64, angle);
        CuroroShotManager_Spawn(p->attackManager, &pos, &gPlayerPtr[0]->mover.pos, angle, 10, 200);
        angle = (angle + (Random() & 15) + 78) & 0xFF;
      }
    }
    if (++p->fireTimer > 60) {
      p->attackTimer = 0;
    }
  }
#else
  INCFUNC("asm/func/PileDriver_AttackDainn.inc");
#endif
}

// シェードマンのバトルドライブの攻撃, 合間を置いて 32 フレームおきに7回, 魔方陣の中心から 1P へクラッシュノイズの輪を撃つ
void PileDriver_AttackShadeMan(PileDriver* p) {
  if (p->attackTimer < p->attackDuration) {
    if (++p->attackTimer >= p->attackDuration) {
      p->fireTimer = 0;
    }
  } else if (++p->fireTimer <= 255) {
    if ((p->fireTimer & 31) == 0) {
      s32 dx = gPlayerPtr[0]->mover.pos.x - p->center.x;
      s32 dz = gPlayerPtr[0]->mover.pos.z - p->center.z;

      CrashNoiseRingManager_Spawn(p->attackManager, ArcTan2_8(dx, dz), 15, p->attackPower, 10, 120, 90, 0, &p->center);
    }
  } else {
    p->attackTimer = 0;
  }
}

void PileDriver_RunAttack(PileDriver* p) {
  if (p->attackCallback != NULL) {
    p->attackCallback(p);
  }
}

void PileDriver_VanishAttackShots(PileDriver* p) {
  switch (p->immortalIdx) {
    case 3: {
      FUN_080df478();
      break;
    }
    case 4: {
      CuroroShotManager_VanishAll(p->attackManager);
      break;
    }
  }
}

// immortalIdx でバトルドライブの攻撃と攻撃の合間を決め, 弾をまとめるエンティティを作る
void PileDriver_InitAttack(PileDriver* p) {
  switch (p->immortalIdx) {
    case 0: {
      p->attackCallback = PileDriver_AttackDuneyrr;
      p->attackDuration = 360;
      break;
    }
    case 1: {
      p->attackCallback = NULL;
      break;
    }
    case 2: {
      p->attackManager = Entity0805d79c_Create();
      p->attackCallback = PileDriver_AttackDurathror;
      p->attackDuration = 360;
      break;
    }
    case 3: {
      p->attackCallback = PileDriver_AttackDvalinn;
      p->attackDuration = 600;
      break;
    }
    case 4: {
      p->attackManager = CuroroShotManager_Create(p->attackPower, 50);
      p->attackCallback = PileDriver_AttackDainn;
      p->attackDuration = 600;
      break;
    }
    case 5: {
      p->attackManager = CrashNoiseRingManager_Create(90);
      p->attackCallback = PileDriver_AttackShadeMan;
      p->attackDuration = 600;
      break;
    }
    default: {
      p->attackCallback = NULL;
      break;
    }
  }
}

// 属性のある攻撃 (エンチャント) を受けたときだけ, 武器の種類と攻撃力の差で吹き飛ぶ速さと止まる時間を決める
void Ectoplasm_OnHurt(Hitbox* a, Hitbox* b, void* owner) {
  if (Hitbox_TestAttr(a, HBATTR_ELEMENT_MASK)) {
    Ectoplasm* p = owner;
    s32 diff;

    p->knockbackAngle = a->angle;
    PlaySound_082406e0(SONG_243);
    diff = a->power - b->power;
    if (diff < 0) {
      diff = 0;
    }
    if (Hitbox_HasSource(a, HBSRC_SWORD)) {
      p->knockbackSpeed = diff + 20;
      p->duration = 32;
    } else if (Hitbox_HasSource(a, HBSRC_SPEAR)) {
      p->knockbackSpeed = diff + 100;
      p->duration = 24;
    } else if (Hitbox_HasSource(a, HBSRC_HAMMER)) {
      p->knockbackSpeed = diff + 50;
      p->duration = 128;
    } else if (Hitbox_HasSource(a, HBSRC_GUN)) {
      p->knockbackSpeed = diff + 100;
      p->duration = 128;
    } else if (Hitbox_HasSource(a, HBSRC_NON_WEAPON)) {
      p->knockbackSpeed = 0;
      p->duration = 128;
    }
    if (p->state == ECTOPLASM_STATE_DRAIN_GENERATOR) {
      p->duration = 0;
    }
    if (p->knockbackSpeed > 200) {
      p->knockbackSpeed = 200;
    }
  }
}

// 15枚をまとめて隠す
void Ectoplasm_HideParts(EctoplasmPart* parts) {
  s32 i;

  parts[0].sprite.flags |= SPRFLAG_HIDDEN;
  for (i = 0; i < 8; i++) {
    parts[1 + i].sprite.flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 6; i++) {
    parts[9 + i].sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 15枚をまとめて出す
void Ectoplasm_ShowParts(EctoplasmPart* parts) {
  s32 i;

  parts[0].sprite.flags &= ~SPRFLAG_HIDDEN;
  for (i = 0; i < 8; i++) {
    parts[1 + i].sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 6; i++) {
    parts[9 + i].sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

void Ectoplasm_SetState(Ectoplasm* p, u32 state) {
  if (p->state == ECTOPLASM_STATE_HIDDEN) {
    p->pos = p->home;
    p->pos.y += 128;
  }
  if (state == ECTOPLASM_STATE_IN_COFFIN && p->state != ECTOPLASM_STATE_IN_COFFIN) {
    PileDriver_FlashImmortal(p->owner);
    gPileDriver->voicePending = TRUE;
  }
  p->state = state;
  p->timer = 0;
  if (p->state == ECTOPLASM_STATE_HIDDEN) {
    Ectoplasm_HideParts(p->parts);
  } else {
    Ectoplasm_ShowParts(p->parts);
  }
}

// 今の pos から home を中心に回る角度と半径を求め直し, 回る速さを 0 にする
void Ectoplasm_SetOrbitFromPos(Ectoplasm* p) {
  s32 dx = p->pos.x - p->home.x;
  s32 dz = p->pos.z - p->home.z;
  s32 angle = ArcTan2_8(dx, dz);

  p->orbitAngle = angle << 4;
  p->orbitSpeed = 0;
  if ((angle >= 32 && angle < 96) || (angle >= 160 && angle < 224)) {
    p->orbitRadius = Div(dz << 12, SIN(angle));
  } else {
    p->orbitRadius = Div(dx << 12, COS(angle));
  }
}

s32 Ectoplasm_IsGeneratorState(Ectoplasm* p, s32 idx, u32 state) {
  if (p->owner->generators[idx]->state == state) {
    return 1;
  }
  return 0;
}

void Ectoplasm_SetGeneratorState(Ectoplasm* p, s32 idx, s32 state) { Generator_SetState(p->owner->generators[idx], state); }

u32 Ectoplasm_GetActiveGeneratorCount(Ectoplasm* p) { return p->owner->activeGeneratorCount; }

s32 Ectoplasm_GetSunGauge(Ectoplasm* p) { return p->owner->sunGauge; }

// 第3引数は読まない, 呼び出し側は 5 を渡している
void Ectoplasm_FlashGenerator(Ectoplasm* p, s32 idx, s32 unused) { p->owner->generators[idx]->unk_e2 = 1; }

// 稼働中のジェネレーターから1つを乱数で選んで添字を返す, なければ -1
s32 Ectoplasm_PickTargetGenerator(Ectoplasm* p) {
  PileDriver* owner = p->owner;
  s32 count = Ectoplasm_GetActiveGeneratorCount(p);
  s32 n;
  s32 i;

  if (count == 0) {
    return -1;
  }
  n = Mod(Random() >> 4, count);
  for (i = 0; i < owner->generatorCount; i++) {
    if (owner->generators[i]->state == 4) {
      if (n == 0) {
        return i;
      }
      n--;
    }
  }
  return -1;
}

// 今の位置から home の周りを回り始める, 半径の目標を選び直し, 1P のいる向きで回る向きを決めて速さを選ぶ
// 101/102 命令, 原典は乱数表の番地を毎回プールから読むが, こちらは r7 に持ち続ける (gcse の巻き上げ), 以降はその余波
// Tier A-C 試済 (1回目を & 0xFF, 速さをローカル経由 / 三項演算子, 2回目以降を RandomNext)
NON_MATCH void Ectoplasm_StartOrbit(Ectoplasm* p) {
#ifdef NONMATCHING_C
  s32 angle;

  Ectoplasm_SetOrbitFromPos(p);
  p->orbitRadiusTarget = (u8)Random() + 192;
  angle = ArcTan2_8(gPlayerPtr[0]->mover.pos.x - p->home.x, gPlayerPtr[0]->mover.pos.z - p->home.z);
  if ((((p->orbitAngle >> 4) + 256 - angle) & 0xFF) < 128) {
    p->orbitSpeedTarget = (Random() & 7) + 12;
  } else {
    p->orbitSpeedTarget = -((Random() & 7) + 12);
  }
  p->orbitSpeed = 0;
  p->orbitSpeedTimer = (Random() & 63) + 64;
  p->wobblePhase = 0;
#else
  INCFUNC("asm/func/Ectoplasm_StartOrbit.inc");
#endif
}

// 稼働中のジェネレーターの数 × 太陽ゲージ (棺桶の中では 4 倍) に damageRate を掛けた分だけイモータルのライフを削って煙を出し, 1/4 を切ったら声とフラッシュを出してスクリプト 4 を起動する
// 189/189 命令, 残差は1回目の乱数で乱数表の番地を入れるレジスタ (原典 r4, こちら r1) と, その余波で煙の番地を作るレジスタ3か所のみ
// Tier A-C 試済 (bossHP の if/else と比較の向き, RandomNext を両方 / 片方)
NON_MATCH void Ectoplasm_DrainBossHP(Ectoplasm* p) {
#ifdef NONMATCHING_C
  PileDriver* owner = p->owner;
  s32 count = Ectoplasm_GetActiveGeneratorCount(p);
  s32 sun = Ectoplasm_GetSunGauge(p);

  if (count > 0 && sun > 0) {
    s32 drain = 0;
    s32 damage = 0;

    if (p->state == ECTOPLASM_STATE_IN_COFFIN) {
      drain = count * sun * 4;
      if (((Random() >> 3) & 1) == 0) {
        EmitSmoke(&p->pos, 1, &p->smokeSize, 0, 0, 0, 2, 1);
      }
    } else if (p->state == ECTOPLASM_STATE_ORBIT || p->state == ECTOPLASM_STATE_GO_TO_GENERATOR || p->state == ECTOPLASM_STATE_DRAIN_GENERATOR || p->state == ECTOPLASM_STATE_KNOCKBACK) {
      drain = count * sun;
      if (((Random() >> 3) & 7) == 0) {
        EmitSmoke(&p->home, 1, &p->homeSmokeSize, 0, 0, 0, 2, 1);
      }
    }
    if (drain > 0) {
      drain = Div(owner->damageRate * drain, 100);
      if (drain <= 0) {
        drain = 1;
      }
    }
    p->drainFrac += drain;
    if (p->drainFrac > 40) {
      damage += Div(p->drainFrac, 40);
      p->drainFrac -= damage * 40;
    }
    if (gStat->bossHP <= damage) {
      gStat->bossHP = 0;
    } else {
      gStat->bossHP -= damage;
    }
    if (gPileDriver->voiceIdx == 0 && gStat->bossHP <= gStat->bossHPMax >> 2) {
      gPileDriver->voiceIdx = 1;
      PlaySound_082406e0(gPileDriver->voices[gPileDriver->voiceIdx]);
      StartBgObjPlttFade(0, 4, 31, 31, 31, 0x1FFF, 0);
      PileDriver_RunEventScript(gPileDriver, 4);
    }
  }
#else
  INCFUNC("asm/func/Ectoplasm_DrainBossHP.inc");
#endif
}

void FUN_080af890(Ectoplasm* p) { p->hurtboxDelay = 0x10; }

// state 1, home (棺桶) から 16 フレームかけて浮かび上がり, 太陽と稼働中のジェネレーターがあれば state 2, なければ state 3 へ進む
void Ectoplasm_StateAppear(Ectoplasm* p) {
  PileDriver* owner = p->owner;

  p->hurtboxDelay = 16;
  p->pos = p->home;
  if (++p->timer >= 16) {
    p->pos.y += 128;
    if (owner->sunGauge != 0 && owner->activeGeneratorCount != 0) {
      Ectoplasm_SetState(p, ECTOPLASM_STATE_IN_COFFIN);
    } else {
      Ectoplasm_StartOrbit(p);
      p->orbitRadiusTarget = 448;
      p->orbitRadiusTimer = 96;
      Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
    }
  } else if (p->timer >= 8) {
    p->pos.y += 256 - (p->timer - 8) * 16;
  } else {
    p->pos.y += (p->timer + 1) * 32;
  }
}

// state 6, 16 フレームかけて home (棺桶) へ吸い込まれて消える
void Ectoplasm_StateReturnHome(Ectoplasm* p) {
  p->hurtboxDelay = 16;
  if (++p->timer >= 16) {
    Ectoplasm_SetState(p, ECTOPLASM_STATE_HIDDEN);
  } else {
    s32 n = 16 - p->timer;
    s32 d = n + 1;

    p->pos.x = Div(p->pos.x * n + p->home.x, d);
    p->pos.y = Div(p->pos.y * n + p->home.y, d);
    p->pos.z = Div(p->pos.z * n + p->home.z, d);
  }
}

// state 2, 棺桶の上で揺れながら留まり, 60 フレーム後から targetTimer が尽きるたびに稼働中のジェネレーターを狙って state 4 へ, 300 フレームで state 3 へ出る
// 168/169 命令, 原典は乱数を引いたあと home.y の番地を先に作ってから (乱数 & 63) + 128 を足すが, 1つの式で書くと + 128 が外へ組み替えられる, 一時置き場のレジスタ (r4/r6) も違う
// Tier A-C 試済 (足す順, dy をローカルへ, (u16) で区切る)
NON_MATCH void Ectoplasm_StateInCoffin(Ectoplasm* p) {
#ifdef NONMATCHING_C
  s32 dy;

  p->hurtboxDelay = 16;
  p->pos.x = FixToInt(2, p->pos.x * 3 + p->home.x);
  dy = (Random() & 63) + 128;
  p->pos.y = p->home.y + dy;
  p->pos.z = FixToInt(2, p->pos.z * 3 + p->home.z);
  if (p->timer < 300) {
    p->timer++;
  }
  if (p->timer >= 60) {
    if (--p->targetTimer == 0) {
      p->targetTimer = Mod(Random(), 300) + 300;
      p->targetGenerator = Ectoplasm_PickTargetGenerator(p);
      if (p->targetGenerator >= 0) {
        Ectoplasm_SetOrbitFromPos(p);
        if (p->targetGenerator == 0) {
          p->orbitAngle = 1920;
        } else if (p->targetGenerator == 1) {
          p->orbitAngle = 3968;
        } else if (p->targetGenerator == 2) {
          p->orbitAngle = 3200;
        } else {
          p->orbitAngle = 1152;
        }
        Ectoplasm_SetState(p, ECTOPLASM_STATE_GO_TO_GENERATOR);
      }
    } else if (p->timer >= 300) {
      Ectoplasm_StartOrbit(p);
      p->orbitRadiusTarget = 448;
      p->orbitRadiusTimer = 96;
      Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
    }
  }
#else
  INCFUNC("asm/func/Ectoplasm_StateInCoffin.inc");
#endif
}

// state 3, 速さと半径を乱数で選び直しながら home の周りを漂い, targetTimer が尽きたら稼働中のジェネレーターを狙って state 4 へ
void Ectoplasm_StateOrbit(Ectoplasm* p) {
  s32 angle;

  if (p->orbitSpeed < p->orbitSpeedTarget) {
    p->orbitSpeed++;
  } else if (p->orbitSpeed > p->orbitSpeedTarget) {
    p->orbitSpeed--;
  }
  if (--p->orbitSpeedTimer == 0) {
    s32 speed = (RandomNext() & 7) + 12;

    p->orbitSpeedTarget = speed;
    if (RandomNext() & 1) {
      p->orbitSpeedTarget = -speed;
    }
    p->orbitSpeedTimer = (RandomNext() & 63) + 32;
  }
  p->orbitAngle = (p->orbitAngle + 0xFFF + p->orbitSpeed) & 0xFFF;
  angle = p->orbitAngle >> 4;
  if (--p->orbitRadiusTimer == 0) {
    p->orbitRadiusTarget = (u8)RandomNext() + 192;
    p->orbitRadiusTimer = (RandomNext() & 63) + 64;
  }
  p->orbitRadius = (p->orbitRadius * 15 + p->orbitRadiusTarget) >> 4;
  p->pos.x = p->home.x + POLAR_X(p->orbitRadius, angle) + FixToInt(24, SIN(p->wobblePhase) * (COS(angle) << 5));
  p->pos.z = p->home.z + POLAR_Z(p->orbitRadius, angle) + FixToInt(24, SIN(p->wobblePhase) * (SIN(angle) << 5));
  if (p->targetTimer <= 2) {
    p->targetTimer = 600;
    p->targetGenerator = Ectoplasm_PickTargetGenerator(p);
    if (p->targetGenerator >= 0) {
      Ectoplasm_SetState(p, ECTOPLASM_STATE_GO_TO_GENERATOR);
    }
  } else {
    p->targetTimer -= 2;
  }
}

// state 4, targetGenerator の方角と距離へ回り込み, 着いたら state 5 で取りつく
void Ectoplasm_StateGoToGenerator(Ectoplasm* p) {
  s32 targetAngle;
  s32 targetRadius;
  s32 diff;
  s32 dr;
  s32 angle;

  if (p->targetGenerator == 0) {
    targetAngle = 1920;
    targetRadius = 480;
  } else if (p->targetGenerator == 1) {
    targetAngle = 3968;
    targetRadius = 400;
  } else if (p->targetGenerator == 2) {
    targetAngle = 3200;
    targetRadius = 480;
  } else {
    targetAngle = 1152;
    targetRadius = 400;
  }
  diff = (targetAngle + 4096 - p->orbitAngle) & 0xFFF;
  if (diff < 2048) {
    if (diff < 48) {
      p->orbitAngle = targetAngle;
    } else {
      p->orbitAngle = (p->orbitAngle + 48) & 0xFFF;
    }
  } else if (diff > 4048) {
    p->orbitAngle = targetAngle;
  } else {
    p->orbitAngle = (p->orbitAngle + 4048) & 0xFFF;
  }
  angle = p->orbitAngle >> 4;
  dr = targetRadius - p->orbitRadius;
  p->orbitRadius = (p->orbitRadius * 7 + targetRadius) >> 3;
  p->pos.x = p->home.x + POLAR_X(p->orbitRadius, angle) + FixToInt(24, COS(p->wobblePhase) * (COS(angle) << 5));
  p->pos.z = p->home.z + POLAR_Z(p->orbitRadius, angle) + FixToInt(24, COS(p->wobblePhase) * (SIN(angle) << 5));
  if (diff == 0 && abs(dr) < 32) {
    PlaySound_082406e0(SONG_244);
    Ectoplasm_SetState(p, ECTOPLASM_STATE_DRAIN_GENERATOR);
  }
}

// state 5, 取りついたジェネレーターを点滅させながら煙を出し, 90 フレームで止めて state 3 に戻る, 先に止まっていたらすぐ戻る
void Ectoplasm_StateDrainGenerator(Ectoplasm* p) {
  if (Ectoplasm_IsGeneratorState(p, p->targetGenerator, 4)) {
    if (((Random() >> 3) & 3) == 0) {
      EmitSmoke(&p->pos, 1, &p->smokeSize, 0, 0, 0, 1, 2);
    }
    if (++p->timer >= 90) {
      Ectoplasm_SetGeneratorState(p, p->targetGenerator, 5);
      Ectoplasm_StartOrbit(p);
      Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
    } else {
      Ectoplasm_FlashGenerator(p, p->targetGenerator, 5);
    }
  } else {
    Ectoplasm_StartOrbit(p);
    Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
  }
}

// state 7, knockbackAngle へ吹き飛びながら 3/4 ずつ減速し, home から 700 離れると跳ね返る, 止まったら state 8
void Ectoplasm_StateKnockback(Ectoplasm* p) {
  s32 dx, dz;

  p->hurtboxDelay = 6;
  p->pos.x += POLAR_X(p->knockbackSpeed, p->knockbackAngle);
  p->pos.z += POLAR_Z(p->knockbackSpeed, p->knockbackAngle);
  dx = p->pos.x - p->home.x;
  dz = p->pos.z - p->home.z;
  if (dx * dx + dz * dz >= 700 * 700) {
    if (p->knockbackSpeed < 30) {
      p->knockbackSpeed = 30;
    }
    p->knockbackAngle += 128;
  } else {
    p->knockbackSpeed = p->knockbackSpeed * 3 >> 2;
  }
  if (p->knockbackSpeed == 0) {
    Ectoplasm_SetState(p, ECTOPLASM_STATE_RECOVER);
  }
}

// duration フレーム経ったら次へ進む
void FUN_080b01b4(Ectoplasm* p) {
  p->timer++;

  if (p->timer >= p->duration) {
    Ectoplasm_StartOrbit(p);
    Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
  }
}

// state 9, 体を隠して 64 フレームの間煙を出しながら消え, 終わったら state 0 にする
void Ectoplasm_StateVanish(Ectoplasm* p) {
  p->hurtboxDelay = 16;
  if (p->timer < 64) {
    u32 timer;

    if (p->timer == 0) {
      Ectoplasm_HideParts(p->parts);
      gPileDriver->voicePending = TRUE;
    }
    timer = p->timer;
    if (timer < 32 || !(timer & 1)) {
      Vec3 size;

      size.x = (64 - timer) * 2;
      size.y = size.x;
      size.z = size.x;
      EmitSmoke(&p->pos, 1, &size, 0, 0, 0, 2, 2);
      if (p->timer < 32) {
        PileDriver_FlashImmortal(p->owner);
        EmitSmoke(&p->parts[9 + Mod(p->timer, 5)].sprite.pos, 1, &size, 0, 0, 0, 2, 2);
      }
    }
    p->timer++;
  } else {
    Ectoplasm_SetState(p, ECTOPLASM_STATE_HIDDEN);
  }
}

// 吹き飛ばされたら state 7 にし, 吹き飛んで home (棺桶) の近くまで来たとき太陽があれば state 2 (棺桶の中) に入れ, 太陽が切れたら state 2 から出す
void Ectoplasm_CheckTransitions(Ectoplasm* p) {
  if (p->state == ECTOPLASM_STATE_VANISH || p->state == ECTOPLASM_STATE_HIDDEN || p->state == ECTOPLASM_STATE_APPEAR || p->state == ECTOPLASM_STATE_RETURN_HOME) {
    return;
  }
  if (p->state == ECTOPLASM_STATE_IN_COFFIN) {
    if (Ectoplasm_GetSunGauge(p) == 0) {
      Ectoplasm_StartOrbit(p);
      Ectoplasm_SetState(p, ECTOPLASM_STATE_ORBIT);
      return;
    }
  } else if (p->state == ECTOPLASM_STATE_KNOCKBACK) {
    if (Ectoplasm_GetSunGauge(p) > 0) {
      s32 dx = p->pos.x - p->home.x - 64;
      s32 dz = p->pos.z - p->home.z - 64;

      if (abs(dx) < 128 && abs(dz) < 128) {
        Ectoplasm_SetState(p, ECTOPLASM_STATE_IN_COFFIN);
        p->knockbackSpeed = 0;
        return;
      }
    }
  }
  if (p->knockbackSpeed != 0) {
    Ectoplasm_SetState(p, ECTOPLASM_STATE_KNOCKBACK);
  }
}

// parts[1..8] を pos の周りに回し, 半径を pulsePhase で 60〜100 に脈打たせる (棺桶の中では倍の速さ), 偶数番目と奇数番目で回る向きが逆
// 255/255 命令, 残差は AuxSprite_AdvanceAnim の wait == 0 の判定1命令のみ, 原典はループの外に出した 0xFF との ands, こちらは lsls #24
// Tier A-C 試済 (sprite のローカル, inline に sprite を渡す, angle の -1)
NON_MATCH void Ectoplasm_UpdateParts1To8(Ectoplasm* p, s32 plttID) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    EctoplasmPart* part = &p->parts[1 + i];
    AuxSprite* sprite = &part->sprite;
    s32 radius = FixToInt(12, abs(COS(part->pulsePhase & 0xFF)) * 40) + 60;

    sprite->pos.x = p->pos.x + POLAR_X(radius, part->angle);
    sprite->pos.y = p->pos.y;
    sprite->pos.z = p->pos.z + POLAR_Z(radius, part->angle);
    if (p->state == ECTOPLASM_STATE_IN_COFFIN) {
      part->pulsePhase += 4;
    } else {
      part->pulsePhase += 2;
    }
    if (i & 1) {
      part->angle = (part->angle + 1) & 0xFF;
    } else {
      part->angle = (part->angle + 255) & 0xFF;
    }
    AuxSprite_AdvanceAnim(&part->sprite, &part->anim);
    Video_SetAuxSpritePltt(&part->gfx, plttID);
  }
#else
  INCFUNC("asm/func/Ectoplasm_UpdateParts1To8.inc");
#endif
}

// parts[9..14] を home (棺桶) から pos へ伸びる尾のように並べ, それぞれをその点の周りに回す
// 331/332 命令, 原典は amp (24 + 4i) をループの強度削減で作るらしく 0xFF の巻き上げより後に初期化し, AuxSprite_AdvanceAnim の wait == 0 を 0xFF との ands で判定する (Ectoplasm_UpdateParts1To8 と同じ残差)
// Tier A-C 試済 (i * 4 + 24 / (i + 6) * 4 / (a + 4) * 4, amp を for の2変数 / 本体末尾で加算, angle の (u8))
NON_MATCH void Ectoplasm_UpdateParts9To14(Ectoplasm* p, s32 plttID) {
#ifdef NONMATCHING_C
  s32 i;
  s32 amp;

  for (i = 0, amp = 24; i < 6; amp += 4, i++) {
    EctoplasmPart* part = &p->parts[9 + i];
    AuxSprite* sprite = &part->sprite;
    s32 a = i + 2;
    s32 b = 8 - a;
    s32 lift = FixToInt(5, (p->pos.y - p->home.y) * b * 3);
    Vec3 pos;
    s32 radius;

    pos.x = FixToInt(3, p->pos.x * a + p->home.x * b) + lift;
    pos.y = FixToInt(3, p->pos.y * a + p->home.y * b);
    pos.z = FixToInt(3, p->pos.z * a + p->home.z * b) + lift;
    radius = FixToInt(12, COS(part->pulsePhase & 0xFF) * amp);
    sprite->pos.x = pos.x + POLAR_X(radius, part->angle);
    sprite->pos.y = pos.y;
    sprite->pos.z = pos.z + POLAR_Z(radius, part->angle);
    part->angle = (part->angle + 3) & 0xFF;
    part->pulsePhase += 5;
    AuxSprite_AdvanceAnim(&part->sprite, &part->anim);
    Video_SetAuxSpritePltt(&part->gfx, plttID);
  }
#else
  INCFUNC("asm/func/Ectoplasm_UpdateParts9To14.inc");
#endif
}

// parts[0] を pos に置いてアニメを進め (state 8 の間は震わせる), 残りの parts も plttID の色で動かす
void Ectoplasm_UpdateParts(Ectoplasm* p, s32 plttID) {
  p->parts[0].sprite.pos = p->pos;
  p->parts[0].sprite.pos.x += 44;
  p->parts[0].sprite.pos.y += 64;
  p->parts[0].sprite.pos.z += 44;
  if (p->state == ECTOPLASM_STATE_RECOVER) {
    s32 shake = (Random() & 15) - 8;

    p->parts[0].sprite.pos.x += shake;
    p->parts[0].sprite.pos.z -= shake;
  }
  AuxSprite_AdvanceAnim(&p->parts[0].sprite, &p->parts[0].anim);
  Video_SetAuxSpritePltt(&p->parts[0].gfx, plttID);
  Ectoplasm_UpdateParts1To8(p, plttID);
  Ectoplasm_UpdateParts9To14(p, plttID);
}

static void (*const sEctoplasmStates[10])(Ectoplasm*) = {
    FUN_080af890,
    Ectoplasm_StateAppear,
    Ectoplasm_StateInCoffin,
    Ectoplasm_StateOrbit,
    Ectoplasm_StateGoToGenerator,
    Ectoplasm_StateDrainGenerator,
    Ectoplasm_StateReturnHome,
    Ectoplasm_StateKnockback,
    FUN_080b01b4,
    Ectoplasm_StateVanish,
};  // 0x085AD054

// エクトプラズムを動かし, 攻撃中と攻撃の前の 90 フレームはパレット 63 で点滅させる
// 残差は e (r5) と plttID (r6) のレジスタの入れ替わりのみ (80/80)
// Tier A-C 試済 (Hitbox_Hide / SET_FLAGS / 直書き, 宣言順, e を使わず &p->ectoplasm), Hitbox_Hide 版はレジスタが合うがフラグの番地が hurtbox+6 になる
NON_MATCH void PileDriver_UpdateEctoplasm(PileDriver* p) {
#ifdef NONMATCHING_C
  Ectoplasm* e = &p->ectoplasm;
  s32 plttID;

  Ectoplasm_CheckTransitions(e);
  sEctoplasmStates[p->ectoplasm.state](e);
  if (p->ectoplasm.hurtboxDelay != 0) {
    p->ectoplasm.hurtbox.flags |= HBF_HIDDEN;
    p->ectoplasm.hurtboxDelay--;
  } else {
    p->ectoplasm.hurtbox.flags &= ~HBF_HIDDEN;
    Hitbox_SetPos(&p->ectoplasm.hurtbox, &p->ectoplasm.pos, 0);
  }
  if (!p->sunOverride) {
    Ectoplasm_DrainBossHP(e);
  }
  plttID = 62;
  if (p->attackCallback != NULL) {
    if (p->attackTimer >= p->attackDuration) {
      plttID = 63;
    } else if (p->attackTimer >= p->attackDuration - 90 && (p->attackTimer >> 2) & 1) {
      plttID = 63;
    }
  }
  Ectoplasm_UpdateParts(e, plttID);
#else
  INCFUNC("asm/func/PileDriver_UpdateEctoplasm.inc");
#endif
}

void Ectoplasm_RemoveParts(EctoplasmPart* parts) {
  EctoplasmPart* part;
  s32 i;

  AuxSprite_Remove(&parts->sprite);

  part = &parts[1];
  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&part->sprite);
    part++;
  }

  part = &parts[9];
  for (i = 0; i < 6; i++) {
    AuxSprite_Remove(&part->sprite);
    part++;
  }
}

void Ectoplasm_InitHurtbox(Ectoplasm* p, u32 power) {
  Hitbox* hurtbox = &p->hurtbox;
  Vec3 size, offset;

  VEC3_SET(size, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hurtbox, 0, HBF_HURTBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, 0, 0);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_SetHandler(hurtbox, Ectoplasm_OnHurt, p);
  Hitbox_Register(hurtbox);
}

void Ectoplasm_InitPart0(Ectoplasm* p) {
  EctoplasmPart* part = &p->parts[0];
  AuxSpriteGfx* gfx = &part->gfx;

  Video_GetAuxSprite(gfx, HashName(s_ect_08251dd0));
  AuxSprite_Add(&part->sprite, gfx, 0);
  part->sprite.poseIdx = 0;
  part->sprite.priority = 1;
  part->sprite.pos = p->pos;
  part->animFile = GetFile(DIR_ANIMATION, HashName(s_ect_anm_08251dd4));
  AuxAnim_SetAnim(&part->anim, part->animFile, 0, 0, 0);
}

// parts[1..8] を出す, 交互に点滅させ, アニメと左右反転は乱数で選ぶ
void Ectoplasm_InitParts1To8(Ectoplasm* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    EctoplasmPart* part = &p->parts[1 + i];
    AuxSprite* sprite = &part->sprite;
    AuxSpriteGfx* gfx = &part->gfx;

    Video_GetAuxSprite(gfx, HashName(s_ect_08251dd0));
    if (i & 1) {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_ODD);
    } else {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_EVEN);
    }
    sprite->poseIdx = 0;
    sprite->priority = 1;
    sprite->pos = p->pos;
    part->angle = i * 32;
    part->pulsePhase = (u8)RandomNext();
    part->animFile = GetFile(DIR_ANIMATION, HashName(s_ect_anm_08251dd4));
    AuxAnim_SetAnim(&part->anim, part->animFile, Mod(RandomNext(), 3) + 1, 0, 0);
    if (RandomNext() & 1) {
      sprite->flags |= SPRFLAG_XFLIP;
    }
  }
}

// parts[9..14] を出す, 奇数番目は左右反転して交互に点滅させ, 2枚ずつ同じアニメを割り当てる
void Ectoplasm_InitParts9To14(Ectoplasm* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    EctoplasmPart* part = &p->parts[9 + i];
    AuxSprite* sprite = &part->sprite;
    AuxSpriteGfx* gfx = &part->gfx;

    Video_GetAuxSprite(gfx, HashName(s_ect_08251dd0));
    if (i & 1) {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_ODD);
    } else {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_EVEN);
    }
    sprite->poseIdx = 0;
    if (i == 0) {
      sprite->priority = 2;
    } else {
      sprite->priority = 1;
    }
    sprite->pos = p->pos;
    part->angle = i * 32;
    part->pulsePhase = (u8)RandomNext();
    part->animFile = GetFile(DIR_ANIMATION, HashName(s_ect_anm_08251dd4));
    AuxAnim_SetAnim(&part->anim, part->animFile, 5 - ((i + 1) >> 1), 0, 0);
    if (i & 1) {
      sprite->flags |= SPRFLAG_XFLIP;
    }
  }
}

void Ectoplasm_InitParts(Ectoplasm* p) {
  Ectoplasm_InitPart0(p);
  Ectoplasm_InitParts1To8(p);
  Ectoplasm_InitParts9To14(p);
}

void Ectoplasm_InitSmokeSize(Ectoplasm* p) {
  VEC3_SET(p->smokeSize, Q8(0.625), Q8(0.625), Q8(0.625));
  VEC3_SET(p->homeSmokeSize, Q8(0.25), Q8(0.125), Q8(0.25));
}

// エクトプラズムを棺桶の位置に用意する, 体と食らい判定 ('.L' が防御力) を作って隠し, 漂い方を乱数で決める
// 166/166 命令, 残差は orbitAngle の番地を作るプールのレジスタと 0 を r8 へ写す中継レジスタ (r2/r0) の入れ替わりのみ
// Tier A-C 試済 (宣言順, speed をブロック内へ, '.L' の値をローカルへ, 捨てる乱数をローカルへ), 原典は捨てる Mod(Random(), 600) と Random() を持つ
NON_MATCH void PileDriver_InitEctoplasm(PileDriver* p) {
#ifdef NONMATCHING_C
  Ectoplasm* e = &p->ectoplasm;
  s32 speed;

  p->ectoplasm.home = p->coffinPos;
  p->ectoplasm.home.x -= 32;
  p->ectoplasm.home.z -= 32;
  p->ectoplasm.pos = p->ectoplasm.home;
  p->ectoplasm.pos.y += 128;
  Mod(Random(), 600);
  Random();
  Ectoplasm_InitParts(e);
  Ectoplasm_InitHurtbox(e, VM_SeekToNamedArg('L') ? VM_GetValue() : 5);
  Ectoplasm_SetState(e, ECTOPLASM_STATE_HIDDEN);
  e->orbitAngle = 160;
  e->orbitSpeed = 0;
  speed = (RandomNext() & 15) + 8;
  e->orbitSpeedTarget = speed;
  if (RandomNext() & 1) {
    e->orbitSpeedTarget = -speed;
  }
  e->orbitSpeedTimer = (RandomNext() & 63) + 192;
  e->wobblePhase = 0;
  e->orbitRadius = 0;
  e->orbitRadiusTarget = (u8)RandomNext() + 192;
  e->orbitRadiusTimer = (RandomNext() & 63) + 64;
  e->targetTimer = 600;
  Ectoplasm_InitSmokeSize(e);
  e->owner = p;
#else
  INCFUNC("asm/func/PileDriver_InitEctoplasm.inc");
#endif
}

// a と b の水平距離が radius 以内かどうか
bool32 FUN_080b1038(Vec3* a, Vec3* b, s32 radius) {
  s32 dx = a->x - b->x;
  s32 dz = a->z - b->z;

  if (dx > radius || dz > radius) {
    return FALSE;
  }
  if (dx * dx + dz * dz <= radius * radius) {
    return TRUE;
  }
  return FALSE;
}

// 1P が棺桶を引いて魔方陣の中心まで持ってきたかどうか
bool32 PileDriver_IsCoffinPulledToCenter(PileDriver* p) {
  if (gCoffin != NULL && gPlayerPtr[0]->mode == PMODE_ACTIVE && gPlayerPtr[0]->action == PACT_PULL_COFFIN && FUN_080b1038(&gCoffin->mover.pos, &p->coffinPos, Q8(0.274))) {
    return TRUE;
  }
  return FALSE;
}

s32 FUN_080b10c4(PileDriver* p) {
  s32 i;

  for (i = 0; i < p->generatorCount; i++) {
    if (p->generators[i]->state != 2) {
      return 0;
    }
  }
  return 1;
}

s32 FUN_080b10f8(PileDriver* p) {
  Player* player = gPlayerPtr[0];

  if (player->mode != PMODE_ACTIVE) {
    return 0;
  }
  if (player->kind >= PLAYER_BAT && player->kind <= PLAYER_SLEEPING) {
    return 0;
  }
  if (player->action != PACT_PALM_UP) {
    return 0;
  }
  if (!FUN_080b1038(&player->mover.pos, &p->unk_508, Q8(0.391))) {
    return 0;
  }
  return 1;
}

// 棺桶が魔方陣の中心から 3.125 タイルより遠ければ 1
s32 PileDriver_IsCoffinAway(PileDriver* p) {
  if (FUN_080b1038(&gCoffin->mover.pos, &p->coffinPos, Q8(3.125))) {
    return 0;
  }
  return 1;
}

void FUN_080b1174(PileDriver* p) {
  if (PileDriver_IsCoffinPulledToCenter(p)) {
    Player_LockPullCoffinTo(gPlayerPtr[0], NULL, -1, 0, 0);
    p->placeKind = 0;
    PileDriver_SetSubState(p, PILEDRIVER_SUB_PLACE_COFFIN);
  }
}

// subState 1, 棺桶を魔方陣の中心へ寄せて据え, 画面を揺らしたあと placeKind に応じてジェネレーターを出す (2) / 戻る (3, 4) / エクトプラズムを出してバトルドライブへ (10)
void PileDriver_PlaceCoffin(PileDriver* p) {
  u32 timer = ++p->subStateTimer;

  if (timer <= 5) {
    Vec3 pos;
    s32 n = 6 - p->subStateTimer;
    u32 dir;

    pos.x = Div(gCoffin->mover.pos.x * (n - 1) + p->coffinPos.x, n);
    pos.z = Div(gCoffin->mover.pos.z * (n - 1) + p->coffinPos.z, n);
    dir = gCoffin->facing;
    if ((p->subStateTimer & 1) && gCoffin->facing != 0) {
      if (gCoffin->facing > 4) {
        dir++;
      } else {
        dir--;
      }
      dir &= 7;
    }
    FUN_08086590(&pos, dir);
  } else if (timer == 6) {
    gCoffin->state = 11;
    gCoffin->mover.pos = p->coffinPos;
    gCoffin->facing = 0;
    p->centerSprite.sprite.flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SONG_249);
  } else if (timer <= 69) {
    if (p->placeKind != 2 && timer == 20) {
      PileDriver_SetState(p, FUN_080adb5c);
      PlaySound_082406e0(SE_UNK_294);
    }
    Camera_Shake((70 - p->subStateTimer) >> 1);
  } else if (p->placeKind == 0) {
    s32 i;

    for (i = 0; i < p->generatorCount; i++) {
      Generator_SetState(p->generators[i], 1);
    }
    Player_Lock(gPlayerPtr[0], -1);
    PlaySound_082406e0(SONG_250);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATORS);
  } else if (p->placeKind == 1) {
    bool32 lit;
    s32 i;

    Player_Lock(gPlayerPtr[0], -1);
    Player_Unlock(gPlayerPtr[0]);
    lit = FALSE;
    for (i = 0; i < p->generatorCount; i++) {
      if (p->generators[i]->state == 4) {
        lit = TRUE;
      }
    }
    if (lit) {
      PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_ACTIVATION);
    } else {
      PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATOR_LIT);
    }
  } else {
    Player_Lock(gPlayerPtr[0], -1);
    Player_Unlock(gPlayerPtr[0]);
    PlaySound_082406e0(SE_COFFIN_OPEN);
    gCoffin->state = 13;
    Ectoplasm_SetState(&p->ectoplasm, ECTOPLASM_STATE_APPEAR);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_BATTLE_DRIVE);
  }
}

void FUN_080b1404(PileDriver* p) {
  if (FUN_080b10c4(p)) {
    Player_Unlock(gPlayerPtr[0]);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATOR_LIT);
    PileDriver_RunEventScript(p, 0);
  }
}

// subState 3, 棺桶を魔方陣の中心へ引き直されたら 1 に戻り, ジェネレーターのどれかが稼働したら 4 へ進む
void PileDriver_WaitGeneratorLit(PileDriver* p) {
  s32 i;

  if (gCoffin->state != 11 && PileDriver_IsCoffinPulledToCenter(p)) {
    Player_LockPullCoffinTo(gPlayerPtr[0], NULL, -1, 0, 0);
    p->placeKind = 1;
    PileDriver_SetSubState(p, PILEDRIVER_SUB_PLACE_COFFIN);
  }
  for (i = 0; i < p->generatorCount; i++) {
    if (p->generators[i]->state == 4) {
      PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_ACTIVATION);
      break;
    }
  }
}

// subState 4, 起動したジェネレーターごとに音と BG パレットの演出を出し, 全部そろったらスクリプトを1度起動し, 1P が unk_508 の近くで PACT_PALM_UP になったらそこへ歩かせて 5 へ進む
void PileDriver_WaitActivation(PileDriver* p) {
  s32 count = 0;
  s32 i;

  for (i = 0; i < p->generatorCount; i++) {
    if (p->generators[i]->state == 4) {
      count++;
      if (p->generators[i]->justStarted) {
        PlaySound_082406e0(SE_UNK_294);
        PileDriver_SetState(p, FUN_080adb5c);
        p->generators[i]->justStarted = FALSE;
      }
    }
  }
  if (!p->unk_1332 && count >= p->generatorCount) {
    p->unk_1332 = 1;
    PileDriver_RunEventScript(p, 1);
  }
  if (p->updateCallback == NULL) {
    PileDriver_SetState(p, FUN_080adce4);
  }
  if (FUN_080b10f8(p)) {
    Player_MoveTo(gPlayerPtr[0], &p->unk_508, 0, 4);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_ACTIVATE);
  }
}

// subState 5, 1P が止まったらカメラを魔方陣へ寄せ, 太陽があれば起動 (7), なければ起動に失敗して 6 へ進む
void PileDriver_Activate(PileDriver* p) {
  Player* player = gPlayerPtr[0];

  if (player->action == PACT_IDLE) {
    Vec3 pos;

    pos.x = (p->center.x * 3 + player->mover.pos.x) >> 2;
    pos.y = (p->center.y * 3 + player->mover.pos.y) >> 2;
    pos.z = (p->center.z * 3 + player->mover.pos.z) >> 2;
    Camera_PanTo(16, &pos);
    if (p->sunGauge != 0) {
      FUN_0807bbb0(gPlayerPtr[0], 1, 0);
      PlaySound_082406e0(SE_PILEDRIVER_05);
      PileDriver_SetState(p, FUN_080ada44);
      PileDriver_SetSubState(p, PILEDRIVER_SUB_POWER_UP);
    } else {
      FUN_0807bbb0(gPlayerPtr[0], 0, 0);
      PlaySound_082406e0(SONG_407);
      PileDriver_SetSubState(p, PILEDRIVER_SUB_SHUTDOWN);
    }
  }
}

void FUN_080b165c(PileDriver* p) {
  p->subStateTimer++;
  if (p->subStateTimer == 30) {
    s32 i;

    for (i = 0; i < p->generatorCount; i++) {
      if (p->generators[i]->state == 4) {
        Generator_SetState(p->generators[i], 5);
      }
    }
    PileDriver_SetState(p, FUN_080adb5c);
    Sound_FadeOutBGM(4);
  } else if (p->subStateTimer == 90) {
    Camera_ReleaseLook(16);
    FUN_0807bc64(gPlayerPtr[0], 0);
  } else if (p->subStateTimer > 105) {
    if (gPlayerPtr[0]->action == PACT_IDLE) {
      Player_Unlock(gPlayerPtr[0]);
      PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATOR_LIT);
      p->unk_1332 = 0;
      PileDriver_RunEventScript(p, 2);
    }
  }
}

void FUN_080b1718(PileDriver* p) {
  if (p->subStateTimer <= 69) {
    p->subStateTimer++;
    if (p->subStateTimer == 70) {
      PileDriver_RunEventScript(p, 3);
    }
  }
  if (p->unk_1333) {
    if (p->unk_1334 <= 59) {
      p->unk_1334++;
    }
    Camera_Shake(p->unk_1334 >> 1);
  }
}

void FUN_080b176c(PileDriver* p) {
  if (p->subStateTimer <= 29) {
    p->subStateTimer++;
  } else if (!p->unk_c12) {
    PlaySound_082406e0(SE_COFFIN_OPEN);
    gCoffin->state = 13;
    PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_COFFIN_OPEN);
  }
}

void FUN_080b17bc(PileDriver* p) {
  if (gCoffin->state == 12) {
    Ectoplasm_SetState(&p->ectoplasm, ECTOPLASM_STATE_APPEAR);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_BATTLE_DRIVE);
  }
}

// subState 10, イモータルが生きていれば攻撃させ, 稼働中のジェネレーターが 120 フレーム途切れるとエクトプラズムが逃げ出す (state 6) ので 11 へ進む
void PileDriver_UpdateBattleDrive(PileDriver* p) {
  bool32 lit = FALSE;
  s32 i;

  if (p->sunGauge != 0) {
    for (i = 0; i < p->generatorCount; i++) {
      if (p->generators[i]->state == 4) {
        lit = TRUE;
      }
    }
  }
  if (gStat->bossHP > 0) {
    PileDriver_RunAttack(p);
  }
  if (lit) {
    p->subStateTimer = 0;
  } else if (++p->subStateTimer >= 120) {
    Ectoplasm_SetState(&p->ectoplasm, ECTOPLASM_STATE_RETURN_HOME);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_CLOSE_COFFIN);
  }
}

void FUN_080b1888(PileDriver* p) {
  if (p->ectoplasm.state == ECTOPLASM_STATE_HIDDEN) {
    PlaySound_082406e0(SE_COFFIN_CLOSE);
    FUN_08086b18(&p->coffinPos);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_RETRY);
    PileDriver_RunEventScript(p, 5);
  }
}

// subState 12, 棺桶を閉じたあと, 魔方陣の中心へ引き直されたら 1 からやり直し, 遠くへ運び出されたら 1P を棺桶へ向けて 13 へ進む
void PileDriver_WaitRetry(PileDriver* p) {
  if (PileDriver_IsCoffinPulledToCenter(p)) {
    Player_LockPullCoffinTo(gPlayerPtr[0], NULL, -1, 0, 0);
    p->placeKind = 2;
    PileDriver_SetSubState(p, PILEDRIVER_SUB_PLACE_COFFIN);
  } else if (PileDriver_IsCoffinAway(p)) {
    s32 dx = gCoffin->mover.pos.x - gPlayerPtr[0]->mover.pos.x;
    s32 dz = gCoffin->mover.pos.z - gPlayerPtr[0]->mover.pos.z;

    if (gPlayerPtr[0]->kind == PLAYER_RDJANGO || gPlayerPtr[0]->kind == PLAYER_BDJANGO || gPlayerPtr[0]->kind == PLAYER_SABATA) {
      Player_LockTurnTo(gPlayerPtr[0], Angle_ToDir8(ArcTan2_8(dx, dz)), 0);
    } else {
      Player_Lock(gPlayerPtr[0], Angle_ToDir8(ArcTan2_8(dx, dz)));
      Player_LockRevertToDarkDjango(gPlayerPtr[0], 0);
    }
    FUN_0808613c(gCoffin);
    Camera_PanTo(16, &gCoffin->mover.pos);
    PileDriver_SetSubState(p, PILEDRIVER_SUB_LEAVE);
    PileDriver_RunEventScript(p, 6);
  }
}

// subState 13, 1P を棺桶へ向けて止め, 音・カメラ・イモータルの声 (voices[3]) を順に出し, 300 フレームでスクリプト 7 を起動する
void FUN_080b19c0(PileDriver* p) {
  if (++p->subStateTimer == 33) {
    s32 dx = gCoffin->mover.pos.x - gPlayerPtr[0]->mover.pos.x;
    s32 dz = gCoffin->mover.pos.z - gPlayerPtr[0]->mover.pos.z;

    Player_Lock(gPlayerPtr[0], Angle_ToDir8(ArcTan2_8(dx, dz)));
  }
  if (p->subStateTimer == 64) {
    PlaySound_082406e0(SONG_453);
  }
  if (p->subStateTimer == 240) {
    Camera_PanTo(16, &gPlayerPtr[0]->mover.pos);
  }
  if (p->subStateTimer == 256) {
    PlaySound_082406e0(p->voices[3]);
    FUN_0807bcb0(gPlayerPtr[0], -1, 0);
  }
  if (p->subStateTimer == 300) {
    PileDriver_RunEventScript(p, 7);
  }
}

void FUN_080b1a84(PileDriver* p) {}

// 魔方陣の中心のスプライトを出し, パレットを手元に写して色を混ぜられるようにする
void PileDriver_InitCenterSprite(PileDriver* p) {
  if (!p->sunOverride) {
    PileDriverAnimSprite* s = &p->centerSprite;
    AuxSprite* sprite = &s->sprite;
    AuxSpriteGfx* gfx = &s->gfx;
    rgb555* src;
    rgb555* dst;
    s32 i;

    Video_GetAuxSprite(gfx, SPR_C039);
    AuxSprite_Add(sprite, gfx, 0);
    sprite->priority = 3;
    FUN_0822b234(gfx, 0);
    src = gfx->pltt;
    dst = s->pltt;
    for (i = 0; i < 16; i++) {
      dst[i] = src[i];
    }
    gfx->pltt = dst;
    s->pose = 0;
    s->unk_6c = 0;
    s->animTimer = 0;
    sprite->pos = p->center;
    s->active = TRUE;
  }
}

void PileDriver_InitBlackhole(PileDriver* p) {
  AuxSprite* sprite = &p->blackhole;
  AuxSpriteGfx* gfx = &p->blackholeGfx;

  Video_GetAuxSprite(gfx, SPR_BLACKHOLE);
  AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_ODD);
  sprite->poseIdx = 0;
  sprite->flags |= SPRFLAG_AFFINE;
  sprite->scaleX = sprite->scaleY = 0x60;
  sprite->priority = 1;
  sprite->pos = p->coffinPos;
  sprite->pos.y += 72;
}

// 魔方陣の中心の四方にジェネレーターを作る, '.a' で各ジェネレーターの最初の state, '.g' で 2 つの引数を受け取る
void PileDriver_CreateGenerators(PileDriver* p) {
  s32 states[4];
  Vec3 pos;
  s32 param_6;
  u32 power;
  s32 inCoffinScene;
  s32 i;

  if (p->mode == 1) {
    inCoffinScene = 1;
  } else {
    inCoffinScene = 0;
  }
  if (!VM_SeekToNamedArg('g')) {
    param_6 = 100;
    power = 0;
  } else {
    param_6 = VM_GetValue();
    power = VM_GetValue();
  }
  if (!VM_SeekToNamedArg('a')) {
    for (i = 0; i < p->generatorCount; i++) {
      p->generators[i] = NULL;
      states[i] = 0;
    }
  } else {
    for (i = 0; i < p->generatorCount; i++) {
      p->generators[i] = NULL;
      states[i] = VM_GetValue();
    }
  }
  for (i = 0; i < p->generatorCount; i++) {
    s32 param_2;
    s32 param_3;
    s32 param_8;

    pos = p->center;
    switch (i) {
      case 0: {
        pos.x -= 514;
        pos.z += 76;
        param_2 = 1;
        param_3 = 0;
        param_8 = 6;
        break;
      }
      case 2: {
        pos.x += 76;
        pos.z -= 514;
        param_2 = 1;
        param_3 = 1;
        param_8 = 3;
        break;
      }
      case 3: {
        pos.x -= 76;
        pos.z += 514;
        param_2 = 0;
        param_3 = 0;
        param_8 = 0;
        break;
      }
      case 1: {
        pos.x += 514;
        pos.z -= 76;
        param_2 = 0;
        param_3 = 1;
        param_8 = 9;
        break;
      }
      default: {
        param_2 = 0;
        param_3 = 0;
        param_8 = 0;
        break;
      }
    }
    p->generators[i] = Generator_Create(&pos, param_2, param_3, states[i], inCoffinScene, param_6, power, param_8);
  }
}

// '.c' で魔方陣の中心を受け取り, そこから unk_508 と棺桶を置く位置を決める
void PileDriver_InitCenter(PileDriver* p) {
  if (VM_SeekToNamedArg('c')) {
    p->center.x = VM_GetValue();
    p->center.y = VM_GetValue();
    p->center.z = VM_GetValue();
  }
  p->unk_508 = p->center;
  p->unk_508.x += 324;
  p->unk_508.z += 324;
  p->coffinPos = p->center;
  p->coffinPos.x -= 20;
  p->coffinPos.z -= 20;
}

void PileDriver_InitEventScript(PileDriver* p) {
  if (VM_SeekToNamedArg('p')) {
    p->eventScriptID = VM_GetValue();
  } else {
    p->eventScriptID = 0;
  }
}

// '.b' でイモータル (immortalIdx) とライフを受け取り, 声とバトルドライブの攻撃 ('.T' が攻撃力) を決める
void PileDriver_InitImmortal(PileDriver* p) {
  if (VM_SeekToNamedArg('b')) {
    p->immortalIdx = VM_GetValue();
    BOSS_HP = VM_GetValue();
    BOSS_HP_MAX = VM_GetValue();
  } else {
    p->immortalIdx = 0;
    BOSS_HP = 6000;
    BOSS_HP_MAX = 6000;
  }
  if (gStat->bossHP > gStat->bossHPMax >> 2) {
    p->voiceIdx = 0;
  } else {
    p->voiceIdx = 1;
  }
  switch (p->immortalIdx) {
    case 0: {
      p->voices[0] = SONG_575;
      p->voices[1] = SONG_581;
      p->voices[2] = VO_DUNEYRR_PURIFY;
      p->voices[3] = VO_DUNEYRR_LAUGH;
      break;
    }
    case 1: {
      p->voices[0] = VO_BDJANGO_BURN;
      p->voices[1] = VO_BDJANGO_MAD;
      p->voices[2] = VO_DJANGO_595;
      p->voices[3] = VO_DJANGO_588;
      break;
    }
    case 2: {
      p->voices[0] = VO_DURATHROR_BURN;
      p->voices[1] = VO_DURATHROR_583;
      p->voices[2] = VO_DURATHROR_PURIFY;
      p->voices[3] = VO_DURATHROR_LAUGH_589;
      break;
    }
    case 3: {
      p->voices[0] = SONG_578;
      p->voices[1] = SONG_584;
      p->voices[2] = VO_DVALINN_PURIFY;
      p->voices[3] = VO_DVALINN_LAUGH;
      break;
    }
    case 4: {
      p->voices[0] = VO_DAINN_BURN;
      p->voices[1] = VO_DAINN_585;
      p->voices[2] = VO_DAINN_598;
      p->voices[3] = VO_DAINN_LAUGH_591;
      break;
    }
    case 5: {
      p->voices[0] = SONG_580;
      p->voices[1] = SONG_580;
      p->voices[2] = SONG_599;
      p->voices[3] = SONG_592;
      break;
    }
  }
  if (VM_SeekToNamedArg('T')) {
    p->attackPower = VM_GetValue();
  } else {
    p->attackPower = 10;
  }
  PileDriver_InitAttack(p);
}

s32 FUN_080b2060(PileDriver* p) {
  s32 i;

  for (i = 0; i < p->generatorCount; i++) {
    if (p->generators[i]->state != 0) {
      return 0;
    }
  }
  return 1;
}

// mode 0 はジェネレーターの状態と '.O' (棺桶が置いてあるか) から始める subState を選び, mode 1 は棺桶を魔方陣に据えて浄化の場面を用意する
void PileDriver_InitByMode(PileDriver* p) {
  switch (p->mode) {
    case 0: {
      if (FUN_080b2060(p)) {
        PileDriver_InitCenterSprite(p);
        PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_COFFIN);
      } else {
        s32 placed = VM_SeekToNamedArg('O') ? VM_GetValue() : 0;

        if (placed && gCoffin != NULL) {
          bool32 lit;
          s32 i;

          gCoffin->state = 11;
          gCoffin->mover.pos = p->coffinPos;
          gCoffin->facing = 0;
          lit = FALSE;
          for (i = 0; i < p->generatorCount; i++) {
            if (p->generators[i]->state == 4) {
              lit = TRUE;
            }
          }
          if (lit) {
            PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_ACTIVATION);
          } else {
            PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATOR_LIT);
          }
        } else {
          PileDriver_InitCenterSprite(p);
          PileDriver_SetSubState(p, PILEDRIVER_SUB_WAIT_GENERATOR_LIT);
        }
      }
      break;
    }
    case 1: {
      PileDriver_InitEctoplasm(p);
      PileDriver_InitImmortal(p);
      gCoffin->state = 11;
      gCoffin->mover.pos = p->coffinPos;
      gCoffin->facing = 0;
      gCoffin->unk_1b = 1;
      if (gCoffin->coffinID == COFFIN_VAMPIRE) {
        p->damageRate = 80;
      } else if (gCoffin->coffinID == COFFIN_IRON_MAIDEN) {
        p->damageRate = 120;
      } else {
        p->damageRate = 100;
      }
      PileDriver_InitImmortalTilemap(p);
      PileDriver_InitTilemap(p);
      PileDriver_InitBlackhole(p);
      PileDriver_SetSubState(p, PILEDRIVER_SUB_OPEN_COFFIN);
      break;
    }
  }
}

void PileDriver_InitMode(PileDriver* p) {
  u32 val = VM_SeekToNamedArg('m');

  if (val) {
    val = VM_GetValue();
  }
  p->mode = val;
}

void Cmd_6414(void) {
  if (gPileDriver != NULL) {
    gPileDriver->sunOverride = 1;
    gPileDriver->sunOverrideValue = gPileDriver->sunGauge;
  }
}

// 0x8400, mode と棺桶が state 11 かどうかとジェネレーター4つの状態 (なし 0 / 稼働中 4 / それ以外 2) をスクリプトの変数へ書き出す
void Cmd_8400(void) {
  u8 desc[8];
  s32 i;

  if (gPileDriver != NULL) {
    VM_GetMemoryRef(desc);
    VM_StoreMemoryRef(desc, 0, gPileDriver->mode);

    VM_GetMemoryRef(desc);
    if (gCoffin != NULL) {
      if (gCoffin->state == 11) {
        VM_StoreMemoryRef(desc, 0, 1);
      } else {
        VM_StoreMemoryRef(desc, 0, 0);
      }
    } else {
      VM_StoreMemoryRef(desc, 0, 0);
    }

    for (i = 0; i < 4; i++) {
      Generator* gen;

      VM_GetMemoryRef(desc);
      gen = gPileDriver->generators[i];
      if (gen == NULL || gen->state <= 1) {
        VM_StoreMemoryRef(desc, 0, 0);
      } else if (gen->state == 4) {
        VM_StoreMemoryRef(desc, 0, 4);
      } else {
        VM_StoreMemoryRef(desc, 0, 2);
      }
    }
  }
}

void Cmd_29F1(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_1333 = TRUE;
    gPileDriver->unk_1334 = 0;
  }
}

void Cmd_F993(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_c12 = TRUE;
  }
}

void Cmd_44BF(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_c12 = FALSE;
  }
}

// 溜まったメッセージを受け取り, 0 は sunOverrideValue の差し替え, 1 は BG パレットのアニメの開始
void PileDriver_PollMessages(PileDriver* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        p->sunOverrideValue = msg->args[0];
        MsgQueue_EndWait(mq, 1);
        break;
      }
      case 1: {
        PileDriver_SetState(p, FUN_080ada44);
        MsgQueue_EndWait(mq, 1);
        break;
      }
    }
  }
}

void PileDriver_UnregisterMsgQueue(PileDriver* p) { MsgQueue_Unregister(&p->mq); }

void PileDriver_RegisterMsgQueue(PileDriver* p) { MsgQueue_Register(&p->mq, p->id, CLS_CBB0); }

s32 FUN_080b2428(void) {
  gPileDriver = NULL;
  return 0;
}

void FUN_080b2434(PileDriver* p) {
  s32 val;

  if (p->sunOverride == 0) {
    val = gStat->sunGauge;
  } else {
    val = p->sunOverrideValue;
  }
  p->sunGauge = val;
}

u32 PileDriver_CountActiveGenerators(PileDriver* p) {
  s32 i;
  u32 count = 0;

  for (i = 0; i < p->generatorCount; i++) {
    if (p->generators[i]->state == 4) {
      count++;
    }
  }
  return count;
}

// 太陽ゲージがあり稼働中のジェネレーターがあって subState が 10 か 14 の間だけ, ブラックホールを大きさを揺らしながら出す
void PileDriver_UpdateBlackhole(PileDriver* p) {
  if (p->sunGauge != 0 && p->activeGeneratorCount != 0 && (p->subState == PILEDRIVER_SUB_BATTLE_DRIVE || p->subState == PILEDRIVER_SUB_END)) {
    AuxSprite_Show(&p->blackhole);
    AuxSprite_SetPoseIdx(&p->blackhole, 1);
    p->blackhole.scaleX = p->blackhole.scaleY = (Random() & 15) + 72;
  } else {
    AuxSprite_Hide(&p->blackhole);
  }
}

// カメラを 1P と魔方陣の中心の中間に置く
void PileDriver_UpdateCamera(PileDriver* p) {
  Player* player = gPlayerPtr[0];
  Vec3 pos;

  pos.x = (player->mover.pos.x + p->center.x) >> 1;
  pos.y = player->mover.pos.y + 150;
  pos.z = (player->mover.pos.z + p->center.z) >> 1;
  Camera_MoveTo(&pos);
}

static void (*const sSubStates[15])(PileDriver*) = {
    FUN_080b1174,
    PileDriver_PlaceCoffin,
    FUN_080b1404,
    PileDriver_WaitGeneratorLit,
    PileDriver_WaitActivation,
    PileDriver_Activate,
    FUN_080b165c,
    FUN_080b1718,
    FUN_080b176c,
    FUN_080b17bc,
    PileDriver_UpdateBattleDrive,
    FUN_080b1888,
    PileDriver_WaitRetry,
    FUN_080b19c0,
    FUN_080b1a84,
};  // 0x085AD07C

s32 PileDriver_Update(PileDriver* p) {
  PileDriver_PollMessages(p);
  FUN_080b2434(p);
  p->activeGeneratorCount = PileDriver_CountActiveGenerators(p);
  if (gPlayerPtr[0]->mode == PMODE_DEAD) {
    return 0;
  }
  if (p->mode == 1 && p->subState != PILEDRIVER_SUB_END && gPlayerPtr[0]->mode == PMODE_ACTIVE && gStat->bossHP == 0) {
    PileDriver_SetSubState(p, PILEDRIVER_SUB_END);
    Ectoplasm_SetState(&p->ectoplasm, ECTOPLASM_STATE_VANISH);
    PileDriver_VanishAttackShots(p);
    PileDriver_RunEventScript(p, 8);
  }
  sSubStates[p->subState](p);
  if (p->mode == 0) {
    PileDriver_UpdateBgPltt(p);
  } else {
    PileDriver_UpdateEctoplasm(p);
    PileDriver_UpdateCamera(p);
    PileDriver_UpdateTilemap(p);
    PileDriver_LoadBgPltt(p);
    PileDriver_UpdateBlackhole(p);
    if (p->voicePending) {
      if (!p->sunOverride) {
        if (gStat->bossHP == 0) {
          PlaySound_082406e0(p->voices[2]);
        } else {
          PlaySound_082406e0(p->voices[p->voiceIdx]);
        }
        PlaySound_082406e0(SE_667);
      }
      p->voicePending = FALSE;
    }
  }
  PileDriver_UpdateParticles(p);
  // 原典は末尾で値を返していない
}

s32 PileDriver_Destroy(PileDriver* p) {
  if (p->mode == 0) {
    if (p->centerSprite.active) {
      AuxSprite_Remove(&p->centerSprite.sprite);
    }
  } else {
    Ectoplasm_RemoveParts(p->ectoplasm.parts);
    AuxSprite_Remove(&p->blackhole);
    SetBGPrioDirect(1, 1);
  }

  PileDriver_RemoveParticles(p);
  PileDriver_UnregisterMsgQueue(p);
  gPileDriver = NULL;
  return 0;
}

s32 PileDriver_Init(PileDriver* p) {
  if (VM_SeekToNamedArg('d')) {
    p->sunOverride = VM_GetValue();
  } else {
    p->sunOverride = FALSE;
  }
  p->player = GetPlayer(0);
  p->coffin = gCoffin;
  PileDriver_InitCenter(p);
  PileDriver_InitMode(p);
  p->generatorCount = VM_SeekToNamedArg('n') ? VM_GetValue() : 4;
  PileDriver_CreateGenerators(p);
  PileDriver_InitByMode(p);
  PileDriver_InitParticles(p);
  PileDriver_InitBgPltt(p);
  PileDriver_InitEventScript(p);
  PileDriver_RegisterMsgQueue(p);
  p->sunGauge = GetSunGauge();
  gPileDriver = p;
  return 0;
}

// 0xCBB0, HashName("パイルドライバー")
PileDriver* PileDriver_Create(u32 id) {
  PileDriver* p;

  if (gPileDriver != NULL) {
    return gPileDriver;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(PileDriver));
  if (p != NULL) {
    SetEntityRoutine(p, PileDriver_Update, PileDriver_Destroy);
    p->id = id;
    if (PileDriver_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
