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
typedef struct Entity1E98Elem {
  AuxSprite spr;                                   // 0x000
  AuxSpriteGfx gfx;                                // 0x02C, SPRITE_SOLAR_PLANT か SPRITE_LILYPAD
  HitboxData hurtbox;                              // 0x048
  Mover mover;                                     // 0x098, moverLinked が 0 以外のときだけ繋がれる
  Vec3 pos;                                        // 0x0DC, '.p', spr.pos へ複写され hurtbox の座標にもなる
  u8 unk_e4;                                       // 0x0E4, '.t', 0 なら太陽の根 (SPRITE_SOLAR_PLANT), それ以外はハスの葉 (SPRITE_LILYPAD)
  bool8 moverLinked;                               // 0x0E5, '.h'
  s16 hurtboxArg;                                  // 0x0E6, '.n', Hitbox_Init の第2引数 (hurtbox.id)
  s16 scriptID;                                    // 0x0E8, '.g[0]=-1', スクリプトが '.i' でこの足場を指名する
  u16 tileIdx;                                     // 0x0EA, pos が乗っているコリジョンタイルの索引
  u16 timer;                                       // 0x0EC, updateCallback が差し替わるたび 0 に戻る
  u16 unk_ee;                                      // 0x0EE, '.W', 0 以外なら上下に揺れる周期 (フレーム数)
  u16 unk_f0;                                      // 0x0F0, unk_f2 に達すると FUN_080a4670 が次の段階へ進める
  u16 unk_f2;                                      // 0x0F2, '.A=10', unk_f0 がここに達したら次の段階へ
  u8 plttTimer;                                    // 0x0F4, 0 でない間 gfx が pltt を使い, 0 になった瞬間に plttID 0x5F へ戻る
  u8 unk_f5;                                       // 0x0F5, まだ未解析
  u8 unk_f6;                                       // 0x0F6, '.s'
  bool8 tileOverrideAdded;                         // 0x0F7, 0 以外なら ov が登録済み
  MapTileOverride ov;                              // 0x0F8
  void (*updateCallback)(struct Entity1E98Elem*);  // 0x108
  u32 unk_10c;                                     // 0x10C, '.g[1]'
} Entity1E98Elem;
static_assert(sizeof(Entity1E98Elem) == 272);

// 魔法"ヒーリング" で足場にすることができる ハスの葉(SPRITE_LILYPAD) or 太陽の根(SPRITE_SOLAR_PLANT)
// 他の Entity と _Create, _Init, _Update, _Delete の書き方やシグネチャが異なる
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_8
  u8 count;                 // 0x018, 生えている足場の数, _Init が1枚生やすごとに1増やす
  bool8 unk_19;             // 0x019, 足場が太陽ゲージを吸った瞬間に立つ
  u8 unk_1a;                // 0x01A, まだ未解析
  u8 unk_1b;                // 0x01B, 吸った瞬間に 32 が入り 0 になるまで減る, pltt のクロスフェードの重み
  rgb555 pltt[16];          // 0x01C, plttTimer が動いている間 gfx.pltt がここを指す (plttID 0x60)
  Entity1E98Elem elems[8];  // 0x03C
} Entity1E98;
static_assert(sizeof(Entity1E98) == 2236);

COMMON_DATA Entity1E98* gEntity1E98 = NULL;  // 0x03002C44

void FUN_080a46b0(Entity1E98Elem* elem);
void FUN_080a4728(Entity1E98Elem* elem);
void FUN_080a4854(Entity1E98Elem* elem);
void FUN_080a47d0(Entity1E98Elem* elem);

void Entity1E98_SetUpdateCallback(Entity1E98Elem* elem, void* fn) {
  elem->updateCallback = fn;
  elem->timer = 0;
}

// 足場の乗れる面をコリジョンマップに差し込む, 太陽の根は向きに応じた階段タイル, ハスの葉は平らなタイルになる
void FUN_080a45a8(Entity1E98Elem* elem) {
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

// 残差1命令 (32/33), 原典は &elem->plttTimer を r4 に置くため push/pop {r4} が増えるが, こちらは r3 で済ませてしまう
// Tier A-B 試済 (sunGauge を s32 ローカルに受けると ldrsh と評価順は一致した)
NON_MATCH void FUN_080a4620(HitboxData* a, HitboxData* b, Entity1E98Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->plttTimer == 0 && (a->weakness & 0x8000)) {
    s32 gauge = gStat->sunGauge;

    elem->unk_f0 += gauge;
    elem->plttTimer = 32;
    gEntity1E98->unk_19 = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_080a4620.inc");
#endif
}

void FUN_080a4670(Entity1E98Elem* elem) {
  if (elem->unk_f0 >= elem->unk_f2) {
    elem->unk_f6 = 1;
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBFLAG_HIDDEN;
    Entity1E98_SetUpdateCallback(elem, FUN_080a46b0);
  }
}

void FUN_080a46b0(Entity1E98Elem* elem) {
  elem->spr.priority = 2;
  if (elem->timer == 0) {
    PlaySound_082406e0(SONG_426);
  }

  elem->timer++;
  if (elem->timer <= 7) {
    elem->spr.poseIdx = 1;
  } else {
    elem->spr.poseIdx = 2;
    Entity1E98_SetUpdateCallback(elem, FUN_080a4728);
    if (elem->unk_10c != 0) {
      ScriptArgs sa;
      u32 arg;

      sa.argc = 1, sa.argv = &arg;
      arg = elem->scriptID;
      VM_ExecByID(elem->unk_10c, &sa);
    }
  }
}

void FUN_080a4728(Entity1E98Elem* elem) {}

// unk_ee の周期で上下に揺れながら, 太陽ゲージが溜まったら乗れる状態へ移る
void FUN_080a472c(Entity1E98Elem* elem) {
  if (elem->unk_ee != 0) {
    elem->spr.pos.y = elem->pos.y + FixToInt(12, 12 * SIN(Div(elem->timer * 255, elem->unk_ee)));
    elem->timer++;
    if (elem->timer >= elem->unk_ee) {
      elem->timer = 0;
    }
  }

  if (elem->unk_f0 >= elem->unk_f2) {
    elem->unk_f6 = 1;
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBFLAG_HIDDEN;
    Entity1E98_SetUpdateCallback(elem, FUN_080a47d0);
  }
}

// 残差は elem と &elem->timer のレジスタ入れ替えだけ (58/58 同数同順), 原典は elem が r5 で timer が r4
// Tier A-C 試済 (ローカルの宣言位置を動かしても入れ替わらない)
NON_MATCH void FUN_080a47d0(Entity1E98Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->timer == 0) {
    PlaySound_082406e0(SONG_426);
  }

  elem->timer++;
  if (elem->timer <= 7) {
    elem->spr.pos = elem->pos;
    elem->spr.poseIdx = 1;
  } else {
    elem->spr.poseIdx = 2;
    Entity1E98_SetUpdateCallback(elem, FUN_080a4854);
    if (elem->unk_10c != 0) {
      ScriptArgs sa;
      u32 arg;

      sa.argc = 1, sa.argv = &arg;
      arg = elem->scriptID;
      VM_ExecByID(elem->unk_10c, &sa);
    }
  }
#else
  INCFUNC("asm/func/FUN_080a47d0.inc");
#endif
}

// プレイヤーが同じタイルに乗っている間は沈み, 離れると元の高さまで浮き上がる
void FUN_080a4854(Entity1E98Elem* elem) {
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
NON_MATCH void FUN_080a48bc(Entity1E98* p) {
#ifdef NONMATCHING_C
  if (p->unk_19) {
    PlaySound_082406e0(SONG_425);
    p->unk_1b = 32;
    p->unk_19 = FALSE;
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

s32 Entity1E98_Update(Entity1E98* p) {
  s32 i;

  FUN_080a48bc(p);

  for (i = 0; i < p->count; i++) {
    Entity1E98Elem* elem = &p->elems[i];

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
s32 Entity1E98_Destroy(Entity1E98* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    Entity1E98Elem* elem = &p->elems[i];

    if (elem->moverLinked) {
      Mover_Unlink(&elem->mover);
    }
    AuxSprite_Remove(&elem->spr);
    Hitbox_Unregister(&elem->hurtbox);
    if (elem->tileOverrideAdded) {
      Map_RemoveTileOverride(&elem->ov);
    }
  }

  gEntity1E98 = NULL;
  return 0;
}

void Entity1E98_InitHurtbox(Entity1E98Elem* elem) {
  HitboxData* hurtbox = &elem->hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(0.5), Q8(0.196), Q8(0.5));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hurtbox, elem->hurtboxArg, HBFLAG_HURTBOX | HBFLAG_UNK_1, 0, 0x20, &halfSize, &offset);
  Hitbox_SetHandler(hurtbox, FUN_080a4620, elem);
  Hitbox_SetPos(hurtbox, &elem->pos, 0);
  Hitbox_Register(hurtbox);
}

// VM の名前付き引数から足場1枚を生やす, '.s' が立っていれば最初から乗れる状態で置く
// 残差2命令 (278/280), 原典はレジスタに余裕がなく '.t' の格納先アドレスを分岐ごとに作り直し, elem のコピーを r7 にもう1つ持つ
// Tier A-C 試済 (VM 引数の if/else 化で 267→278 まで詰めた. spr/pos のローカル化は 270 で悪化)
NON_MATCH void Entity1E98_Init(Entity1E98* p) {
#ifdef NONMATCHING_C
  Entity1E98Elem* elem = &p->elems[p->count];
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
  id = (elem->unk_e4 == 0) ? SPRITE_SOLAR_PLANT : SPRITE_LILYPAD;
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
      Mover_Init(&elem->mover, elem->hurtboxArg, &elem->spr.pos, 0, 7, elem);
      FUN_08002a48(&elem->mover);
    }
  } else {
    elem->moverLinked = FALSE;
  }

  elem->unk_f0 = 0;
  if (VM_SeekToNamedArg('A')) {
    elem->unk_f2 = VM_GetValue();
  } else {
    elem->unk_f2 = 10;
  }
  elem->unk_ee = VM_SeekToNamedArg('W') ? VM_GetValue() : 0;
  Entity1E98_InitHurtbox(elem);
  elem->plttTimer = 0;
  if (VM_SeekToNamedArg('s')) {
    elem->unk_f6 = VM_GetValue();
  } else {
    elem->unk_f6 = 0;
  }

  if (elem->unk_f6 != 0) {
    FUN_080a45a8(elem);
    elem->hurtbox.flags |= HBFLAG_HIDDEN;
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
      cb = FUN_080a4670;
    } else {
      cb = FUN_080a472c;
    }
  }
  Entity1E98_SetUpdateCallback(elem, cb);

  if (VM_SeekToNamedArg('g')) {
    elem->scriptID = VM_GetValue();
    elem->unk_10c = VM_GetValue();
  } else {
    elem->scriptID = -1;
    elem->unk_10c = 0;
  }

  p->count++;
#else
  INCFUNC("asm/func/Entity1E98_Init.inc");
#endif
}

Entity1E98* Entity1E98_Create_Internal(void) {
  Entity1E98* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity1E98));

  if (p != NULL) {
    SetEntityRoutine(p, Entity1E98_Update, Entity1E98_Destroy);
    p->count = 0;
  }

  gEntity1E98 = p;
  return p;
}

s32 Cmd_C46E(void) {
  Entity1E98* p = gEntity1E98;
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
      return p->elems[i].unk_f6;
    }
  }

  return 0;
}

s32 Entity1E98_Create(void) {
  Entity1E98* p = gEntity1E98;

  if (p == NULL) {
    p = Entity1E98_Create_Internal();
  }
  Entity1E98_Init(p);
}
