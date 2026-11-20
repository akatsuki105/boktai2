#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// 足場1枚ぶん
typedef struct SolarPlant {
  AuxSprite spr;                               // 0x000
  AuxSpriteGfx gfx;                            // 0x02C, SPR_SOLAR_PLANT か SPR_LILYPAD
  Hitbox hurtbox;                              // 0x048
  Mover mover;                                 // 0x098, moverLinked が 0 以外のときだけ繋がれる
  Vec3 pos;                                    // 0x0DC, '.p', spr.pos へ複写され hurtbox の座標にもなる
  u8 unk_e4;                                   // 0x0E4, '.t', 0 なら太陽の根 (SPR_SOLAR_PLANT), それ以外はハスの葉 (SPR_LILYPAD)
  bool8 moverLinked;                           // 0x0E5, '.h'
  s16 hurtboxArg;                              // 0x0E6, '.n', Hitbox_Init の第2引数 (hurtbox.id)
  s16 scriptID;                                // 0x0E8, '.g[0]=-1', スクリプトが '.i' でこの足場を指名する
  u16 tileIdx;                                 // 0x0EA, pos が乗っているコリジョンタイルの索引
  u16 timer;                                   // 0x0EC, updateCallback が差し替わるたび 0 に戻る
  u16 unk_ee;                                  // 0x0EE, '.W', 0 以外なら上下に揺れる周期 (フレーム数)
  u16 healAmount;                              // 0x0F0, 魔法"ヒーリング"を受けた量の累計, 1回ぶんはそのときの太陽ゲージ
  u16 healToGrow;                              // 0x0F2, '.A=10', healAmount がここに達すると育つ
  u8 plttTimer;                                // 0x0F4, 0 でない間 gfx が pltt を使い, 0 になった瞬間に plttID 0x5F へ戻る
  u8 unk_f5;                                   // 0x0F5, まだ未解析
  bool8 grown;                                 // 0x0F6, '.s', 育ちきって足場として使える, 太陽ゲージが少ないとヒーリングを何回も当てないと育たない
  bool8 tileOverrideAdded;                     // 0x0F7, 0 以外なら ov が登録済み
  MapTileOverride ov;                          // 0x0F8
  void (*updateCallback)(struct SolarPlant*);  // 0x108
  u32 unk_10c;                                 // 0x10C, '.g[1]'
} SolarPlant;
static_assert(sizeof(SolarPlant) == 272);

// 魔法"ヒーリング" で足場にすることができる ハスの葉(SPR_LILYPAD) or 太陽の根(SPR_SOLAR_PLANT)
// 他の Entity と _Create, _Init, _Update, _Delete の書き方やシグネチャが異なる
typedef struct {
  Entity e;             // 0x000, ENTITY_UNK_8
  u8 count;             // 0x018, 生えている足場の数, SolarPlantManager_AddPlant が1枚生やすごとに1増やす
  bool8 healed;         // 0x019, どれかの足場がヒーリングを受けた瞬間に立つ
  u8 unk_1a;            // 0x01A, まだ未解析
  u8 unk_1b;            // 0x01B, ヒーリングを受けた瞬間に 32 が入り 0 になるまで減る, pltt のクロスフェードの重み
  rgb555 pltt[16];      // 0x01C, plttTimer が動いている間 gfx.pltt がここを指す (plttID 0x60)
  SolarPlant elems[8];  // 0x03C
} SolarPlantManager;
static_assert(sizeof(SolarPlantManager) == 2236);

COMMON_DATA SolarPlantManager* gSolarPlantManager = NULL;  // 0x03002C44

void FUN_080a46b0(SolarPlant* elem);
void FUN_080a4728(SolarPlant* elem);
void FUN_080a4854(SolarPlant* elem);
void FUN_080a47d0(SolarPlant* elem);

void SolarPlant_SetUpdateCallback(SolarPlant* elem, void* fn) {
  elem->updateCallback = fn;
  elem->timer = 0;
}

// 足場の乗れる面をコリジョンマップに差し込む, 太陽の根は向きに応じた階段タイル, ハスの葉は平らなタイルになる
void FUN_080a45a8(SolarPlant* elem) {
  s32 stairs;
  s32 height;

  if (elem->unk_e4 == 0) {
    stairs = (elem->spr.flags & SPRFLAG_XFLIP) ? STAIRS_HORIZONTAL : STAIRS_VERTICAL;
    height = FixToInt(8, elem->pos.y) + 1;
  } else {
    stairs = 0;
    height = FixToInt(8, elem->pos.y);
  }

  Map_AddTileOverride(&elem->ov, elem->tileIdx, stairs, height, 0xFF, 0);
  elem->tileOverrideAdded = TRUE;
}

// 食らい判定のコールバック, 魔法"ヒーリング" (攻撃元の種別マスク 0x8000) を受けたらそのときの太陽ゲージぶん育てて光らせる
// 残差1命令 (32/33), 原典は &elem->plttTimer を r4 に置くため push/pop {r4} が増えるが, こちらは r3 で済ませてしまう
// Tier A-B 試済 (sunGauge を s32 ローカルに受けると ldrsh と評価順は一致した)
NON_MATCH void SolarPlant_OnHealed(Hitbox* a, Hitbox* b, SolarPlant* elem) {
#ifdef NONMATCHING_C
  if (elem->plttTimer == 0 && (a->typeMask & HBSRC_MHEALING)) {
    s32 gauge = gStat->sunGauge;

    elem->healAmount += gauge;
    elem->plttTimer = 32;
    gSolarPlantManager->healed = TRUE;
  }
#else
  INCFUNC("asm/func/SolarPlant_OnHealed.inc");
#endif
}

// ヒーリングを十分に受けていれば育ちきった状態にして乗れる面を差し込む
void SolarPlant_TryGrow(SolarPlant* elem) {
  if (elem->healAmount >= elem->healToGrow) {
    elem->grown = TRUE;
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBF_HIDDEN;
    SolarPlant_SetUpdateCallback(elem, FUN_080a46b0);
  }
}

void FUN_080a46b0(SolarPlant* elem) {
  elem->spr.priority = 2;
  if (elem->timer == 0) {
    PlaySound_082406e0(SE_M_HEALING_GROW);
  }

  elem->timer++;
  if (elem->timer <= 7) {
    elem->spr.poseIdx = 1;
  } else {
    elem->spr.poseIdx = 2;
    SolarPlant_SetUpdateCallback(elem, FUN_080a4728);
    if (elem->unk_10c != 0) {
      ScriptArgs sa;
      u32 arg;

      sa.argc = 1, sa.argv = &arg;
      arg = elem->scriptID;
      VM_ExecByID(elem->unk_10c, &sa);
    }
  }
}

void FUN_080a4728(SolarPlant* elem) {}

// unk_ee の周期で上下に揺れながら, ヒーリングを十分に受けたら乗れる状態へ移る
void FUN_080a472c(SolarPlant* elem) {
  if (elem->unk_ee != 0) {
    elem->spr.pos.y = elem->pos.y + FixToInt(12, 12 * SIN(Div(elem->timer * 255, elem->unk_ee)));
    elem->timer++;
    if (elem->timer >= elem->unk_ee) {
      elem->timer = 0;
    }
  }

  if (elem->healAmount >= elem->healToGrow) {
    elem->grown = TRUE;
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBF_HIDDEN;
    SolarPlant_SetUpdateCallback(elem, FUN_080a47d0);
  }
}

// 最初のフレームで成長の効果音を鳴らし, 7 フレームはコマ 1 で pos に置き, 過ぎたらコマ 2 にして次の更新へ移り unk_10c のスクリプトを実行する
void FUN_080a47d0(SolarPlant* elem) {
  if (elem->timer == 0) {
    PlaySound_082406e0(SE_M_HEALING_GROW);
  }
  if (++elem->timer <= 7) {
    elem->spr.pos = elem->pos;
    elem->spr.poseIdx = 1;
  } else {
    elem->spr.poseIdx = 2;
    SolarPlant_SetUpdateCallback(elem, FUN_080a4854);
    if (elem->unk_10c != 0) {
      ScriptArgs sa;
      u32 arg;

      sa.argc = 1, sa.argv = &arg;
      arg = elem->scriptID;
      VM_ExecByID(elem->unk_10c, &sa);
    }
  }
}

// プレイヤーが同じタイルに乗っている間は沈み, 離れると元の高さまで浮き上がる
void FUN_080a4854(SolarPlant* elem) {
  if (gPlayerPtr[0]->tile.tileIdx[1] == elem->tileIdx) {
    if (elem->spr.pos.y == elem->pos.y) {
      PlaySound_082406e0(SONG_691);
    }
    if (elem->spr.pos.y > elem->pos.y - 16) {
      elem->spr.pos.y -= 2;
    }
  } else if (elem->spr.pos.y < elem->pos.y) {
    elem->spr.pos.y += 2;
  }
}

// 残差1命令 (126/125), 原典はスタックに2語 (u と &p->pltt) 退避するがこちらは1語で足りてしまう
// Tier A-C 試済 (ローカルの宣言順, dst ローカル, lit/dark の歩進ポインタ化 はいずれも2語にならない. 歩進形だと124命令で今度は1命令足りない)
NON_MATCH void FUN_080a48bc(SolarPlantManager* p) {
#ifdef NONMATCHING_C
  if (p->healed) {
    PlaySound_082406e0(SONG_425);
    p->unk_1b = 32;
    p->healed = FALSE;
  }

  if (p->unk_1b != 0) {
    p->unk_1b--;
    if (p->unk_1b == 0) {
      CpuCopy32(&gObjPlttData[95 * 16], p->pltt, sizeof(p->pltt));
    } else if (p->unk_1b > 15) {
      CpuCopy32(&gObjPlttData[96 * 16], p->pltt, sizeof(p->pltt));
    } else {
      s32 t = p->unk_1b;
      s32 u = 16 - t;
      rgb555* lit = &gObjPlttData[96 * 16];
      rgb555* dark = &gObjPlttData[95 * 16];
      rgb555* dst = p->pltt;
      s32 i;

      for (i = 0; i < 16; i++) {
        s32 r = ((lit[i] & 0x1F) * t + (dark[i] & 0x1F) * u) >> 4;
        s32 g = (((lit[i] >> 5) & 0x1F) * t + ((dark[i] >> 5) & 0x1F) * u) >> 4;
        s32 b = (((lit[i] >> 10) & 0x1F) * t + ((dark[i] >> 10) & 0x1F) * u) >> 4;

        dst[i] = RGB(r, g, b);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080a48bc.inc");
#endif
}

s32 SolarPlantManager_Update(SolarPlantManager* p) {
  s32 i;

  FUN_080a48bc(p);

  for (i = 0; i < p->count; i++) {
    SolarPlant* elem = &p->elems[i];

    elem->updateCallback(elem);
    if (elem->plttTimer != 0) {
      elem->plttTimer--;
      if (elem->plttTimer != 0) {
        elem->gfx.plttID = 0x60;
        elem->gfx.pltt = p->pltt;
      } else {
        Video_SetAuxSpritePltt(&elem->gfx, 95);
      }
    }
  }

  return 0;
}

// 全ての足場のスプライト, 判定, コリジョンの差し込みを畳んで登録枠を空ける
s32 SolarPlantManager_Destroy(SolarPlantManager* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    SolarPlant* elem = &p->elems[i];

    if (elem->moverLinked) {
      Mover_Unlink(&elem->mover);
    }
    AuxSprite_Remove(&elem->spr);
    Hitbox_Unregister(&elem->hurtbox);
    if (elem->tileOverrideAdded) {
      Map_RemoveTileOverride(&elem->ov);
    }
  }

  gSolarPlantManager = NULL;
  return 0;
}

void SolarPlant_InitHurtbox(SolarPlant* elem) {
  Hitbox* hurtbox = &elem->hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(0.5), Q8(0.196), Q8(0.5));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hurtbox, elem->hurtboxArg, HBF_HURTBOX | HBF_SENSOR, 0, 0x20, &halfSize, &offset);
  Hitbox_SetHandler(hurtbox, SolarPlant_OnHealed, elem);
  Hitbox_SetPos(hurtbox, &elem->pos, 0);
  Hitbox_Register(hurtbox);
}

// VM の名前付き引数から足場1枚を生やす, '.s' が立っていれば最初から乗れる状態で置く
// 名前付き引数を読んで空き枠に足場を1枚足す
// 残差2命令 (278/280), 原典はレジスタに余裕がなく '.t' の格納先アドレスを分岐ごとに作り直し, elem のコピーを r7 にもう1つ持つ
// Tier A-C 試済 (VM 引数の if/else 化で 267→278 まで詰めた. spr/pos のローカル化は 270 で悪化)
NON_MATCH void SolarPlantManager_AddPlant(SolarPlantManager* p) {
#ifdef NONMATCHING_C
  SolarPlant* elem = &p->elems[p->count];
  SpriteID32 id;
  void* cb;
  s32 bx;
  s32 bz;

  if (VM_SeekToNamedArg('n')) {
    elem->hurtboxArg = VM_GetValue();
  } else {
    elem->hurtboxArg = 0;
  }

  if (VM_SeekToNamedArg('p')) {
    elem->pos.x = VM_GetValue();
    elem->pos.y = VM_GetValue();
    elem->pos.z = VM_GetValue();
  } else {
    elem->pos.x = 0, elem->pos.y = 0, elem->pos.z = 0;
  }

  bx = (s8)(elem->pos.x >> 8);
  bz = (s8)(elem->pos.z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    elem->tileIdx = 0;
  } else {
    elem->tileIdx = gCollisionMap->rowOffsets[bz] + bx;
  }

  if (VM_SeekToNamedArg('t')) {
    elem->unk_e4 = VM_GetValue();
  } else {
    elem->unk_e4 = 0;
  }
  id = (elem->unk_e4 == 0) ? SPR_SOLAR_PLANT : SPR_LILYPAD;
  Video_GetAuxSprite(&elem->gfx, id);
  AuxSprite_Add(&elem->spr, &elem->gfx, 0);
  elem->spr.priority = 3;

  if (VM_SeekToNamedArg('r') && VM_GetValue() != 0) {
    elem->spr.flags |= SPRFLAG_XFLIP;
  }
  elem->spr.pos = elem->pos;

  if (VM_SeekToNamedArg('h')) {
    elem->moverLinked = VM_GetValue();
    if (elem->moverLinked) {
      Mover_Init(&elem->mover, elem->hurtboxArg, &elem->spr.pos, 0, MOVER_OBJECT, elem);
      FUN_08002a48(&elem->mover);
    }
  } else {
    elem->moverLinked = FALSE;
  }

  elem->healAmount = 0;
  if (VM_SeekToNamedArg('A')) {
    elem->healToGrow = VM_GetValue();
  } else {
    elem->healToGrow = 10;
  }
  elem->unk_ee = VM_SeekToNamedArg('W') ? VM_GetValue() : 0;
  SolarPlant_InitHurtbox(elem);
  elem->plttTimer = 0;
  if (VM_SeekToNamedArg('s')) {
    elem->grown = VM_GetValue();
  } else {
    elem->grown = FALSE;
  }

  if (elem->grown != 0) {
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBF_HIDDEN;
    elem->spr.poseIdx = 2;
    if (elem->unk_e4 == 0) {
      elem->spr.priority = 2;
      cb = FUN_080a4728;
    } else {
      cb = FUN_080a4854;
    }
  } else {
    elem->tileOverrideAdded = FALSE;
    elem->spr.poseIdx = 0;
    elem->spr.priority = 3;
    if (elem->unk_e4 == 0) {
      cb = SolarPlant_TryGrow;
    } else {
      cb = FUN_080a472c;
    }
  }
  SolarPlant_SetUpdateCallback(elem, cb);

  if (VM_SeekToNamedArg('g')) {
    elem->scriptID = VM_GetValue();
    elem->unk_10c = VM_GetValue();
  } else {
    elem->scriptID = -1;
    elem->unk_10c = 0;
  }

  p->count++;
#else
  INCFUNC("asm/func/SolarPlantManager_AddPlant.inc");
#endif
}

SolarPlantManager* SolarPlantManager_Create(void) {
  SolarPlantManager* p = CreateEntity(ENTITY_UNK_8, sizeof(SolarPlantManager));

  if (p != NULL) {
    SetEntityRoutine(p, SolarPlantManager_Update, SolarPlantManager_Destroy);
    p->count = 0;
  }

  gSolarPlantManager = p;
  return p;
}

// 0xC46E, HashName("太陽の根状態取得"), '.i' の足場が育ちきったかを返す
s32 Cmd_GetSolarPlantState(void) {
  SolarPlantManager* p = gSolarPlantManager;
  s32 id;
  s32 i;

  if (p == NULL) {
    return 0;
  }

  if (VM_SeekToNamedArg('i')) {
    id = VM_GetValue();
  } else {
    id = 0;
  }

  for (i = 0; i < p->count; i++) {
    if (p->elems[i].scriptID == id) {
      return p->elems[i].grown;
    }
  }

  return 0;
}

// 0x1E98, HashName("太陽の根追加"), 足場を1枚足す, 管理役 (gSolarPlantManager) が無ければ先に作る
s32 Cmd_AddSolarPlant(void) {
  SolarPlantManager* p = gSolarPlantManager;

  if (p == NULL) {
    p = SolarPlantManager_Create();
  }
  SolarPlantManager_AddPlant(p);
}
