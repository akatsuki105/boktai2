#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_aux.h"
#include "vm.h"

// 足場1枚ぶん
typedef struct Entity1E98Elem {
  AuxSprite spr;                                   // 0x000
  AuxSpriteGfx gfx;                                // 0x02C, unk_e4 が 0 なら SPRITE_C3C3, それ以外は SPRITE_D166
  HitboxData hitbox;                               // 0x048
  Mover mover;                                     // 0x098, moverLinked が 0 以外のときだけ繋がれる
  Vec3 pos;                                        // 0x0DC, '.p', spr.pos へ複写され hitbox の座標にもなる
  s8 unk_e4;                                       // 0x0E4, '.t'
  bool8 moverLinked;                               // 0x0E5, '.h'
  s16 hitboxArg;                                   // 0x0E6, '.n', Hitbox_Init の第2引数
  s16 scriptID;                                    // 0x0E8, '.g[0]=-1', スクリプトが '.i' でこの足場を指名する
  u16 tileIdx;                                     // 0x0EA, pos が乗っているコリジョンタイルの索引
  u16 timer;                                       // 0x0EC, updateCallback が差し替わるたび 0 に戻る
  s16 unk_ee;                                      // 0x0EE, '.W'
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
  u8 unk_1a[2];             // 0x01A, まだ未解析
  rgb555 pltt[16];          // 0x01C, plttTimer が動いている間 gfx.pltt がここを指す (plttID 0x60)
  Entity1E98Elem elems[8];  // 0x03C
} Entity1E98;
static_assert(sizeof(Entity1E98) == 2236);

COMMON_DATA Entity1E98* gEntity1E98 = NULL;  // 0x03002C44

void FUN_080a46b0(Entity1E98Elem* elem);
void FUN_080a4728(Entity1E98Elem* elem);

void Entity1E98_SetUpdateCallback(Entity1E98Elem* elem, void* fn) {
  elem->updateCallback = fn;
  elem->timer = 0;
}

NAKED void FUN_080a45a8(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a45a8.inc"); }

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
    elem->hitbox.flags |= HBFLAG_UNK_2;
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

NAKED void FUN_080a472c(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a472c.inc"); }

NAKED void FUN_080a47d0(Entity1E98Elem* elem) { INCFUNC("asm/func/FUN_080a47d0.inc"); }

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

NAKED void FUN_080a48bc(void) { INCFUNC("asm/func/FUN_080a48bc.inc"); }

s32 Entity1E98_Update(Entity1E98* p) {
  s32 i;

  FUN_080a48bc();

  for (i = 0; i < p->count; i++) {
    Entity1E98Elem* elem = &p->elems[i];

    elem->updateCallback(elem);
    if (elem->plttTimer != 0) {
      elem->plttTimer--;
      if (elem->plttTimer != 0) {
        elem->gfx.plttID = 0x60;
        elem->gfx.pltt = p->pltt;
      } else {
        Video_SetAuxSpritePltt(&elem->gfx, 0x5F);
      }
    }
  }

  return 0;
}

NAKED s32 Entity1E98_Destroy(Entity1E98* p) { INCFUNC("asm/func/Entity1E98_Destroy.inc"); }

NAKED void Entity1E98_InitHitbox(Entity1E98Elem* elem) { INCFUNC("asm/func/Entity1E98_InitHitbox.inc"); }

NAKED void Entity1E98_Init(Entity1E98* p) { INCFUNC("asm/func/Entity1E98_Init.inc"); }

Entity1E98* Entity1E98_Create_Internal(void) {
  Entity1E98* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity1E98));

  if (p != NULL) {
    SetEntityRoutine(p, Entity1E98_Update, Entity1E98_Destroy);
    p->count = 0;
  }

  gEntity1E98 = p;
  return p;
}

s32 FUN_080a4e1c(void) {
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
