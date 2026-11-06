#include "camera_inline.h"
#include "crossover.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// オジャマバット1体, 色ごとの数の表示 (counterSprite) と本体 (batSprite) を抱えて state ごとに動く
// elems[0..3] は画面下の置き場, elems[4..7] は飛んでいく演出用
typedef struct {
  u8 state;                 // 0x00, sEntity08051b70ElemStateFuncs の添字
  bool8 entered;            // 0x01, state に入った最初のフレームだけ立つ
  u8 color;                 // 0x02, 0: 赤, 1: 青, 2: 黄, 3: 緑, 添字 & 3, batSprite のポーズ番号
  u8 count;                 // 0x03, 0..10, counterSprite のポーズ番号, 0 なら両方隠す
  u8 shakeTimer;            // 0x04, 8 から毎フレーム減り, 0 でない間 batSprite を乱数で揺らす
  u8 unk_05;                // 0x05
  s16 wobble;               // 0x06, 移動中に x と y へ足す揺れの振幅, 符号は乱数で決まる
  u32 timer;                // 0x08, state に入ってからのフレーム数
  Vec3 from;                // 0x0C, 移動の始点
  Vec3 to;                  // 0x14, 移動の終点
  Vec3 vel;                 // 0x1C, 逸れていくときに毎フレーム batSprite.pos に足す
  AuxSprite counterSprite;  // 0x24, counterGfx を使う
  AuxSprite batSprite;      // 0x50, batGfx を使う
} Entity08051b70Elem;
static_assert(sizeof(Entity08051b70Elem) == 124);

// 画面下に4色のオジャマバットの数を並べ, 取得・送信・受信・ブロックを演出するエンティティ, シングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_11
  u32 timer;                    // 0x018, state に入ってからのフレーム数
  u8 state;                     // 0x01C, sEntity08051b70StateFuncs の添字
  bool8 entered;                // 0x01D, state に入った最初のフレームだけ立つ
  u16 blockFlags;               // 0x01E, bit0: 自分がブロッキング, bit1: 相手がブロッキング
  s8 myOjama[4];                // 0x020, 自分が送るオジャマバットの色ごとの数
  s8 rivalOjama[4];             // 0x024, 相手から届いたオジャマバットの色ごとの数
  s8 blockedOjama[4];           // 0x028, ブロッキングで送り返した rivalOjama の写し
  u8 nextIdx;                   // 0x02C, 次に飛ばす elems[4 + nextIdx], 8 フレームごとに進む
  u8 shakeTimer;                // 0x02D, 0 でない間 banner.pos を乱数で揺らしながら減る
  u8 unk_2e[2];                 // 0x02E
  void (*onFinish)(void);       // 0x030, 演出の最後に呼ぶ
  AuxSpriteGfx batGfx;          // 0x034, SPRITE_OJAMA_BAT
  AuxSpriteGfx counterGfx;      // 0x050, SPRITE_OJAMA_BAT_CTR
  MainSpriteGfx mainGfx;        // 0x06C, SPRITE_UI_LINK
  MainSprite banner;            // 0x08C, LINK_BLOCKING か LINK_DOUBLE_BANG
  Entity08051b70Elem elems[8];  // 0x0EC
} Entity08051b70;
static_assert(sizeof(Entity08051b70) == 1228);

IWRAM_DATA Entity08051b70* gEntity08051b70 = NULL;  // 0x03000118

// 色と数を入れる, 数は表示できる 0..10 に収める
static inline void Entity08051b70Elem_SetColorCount(Entity08051b70Elem* elem, u32 color, s32 n) {
  elem->color = color;
  if (n > 10) {
    n = 10;
  } else if (n < 0) {
    n = 0;
  }
  elem->count = n;
}

// 右上の出入口のうち idx の列を移動の始点にする
static inline void Entity08051b70Elem_SetFromTopRight(Entity08051b70Elem* elem, s32 idx) { VEC3_SET(elem->from, (idx & 3) * 24 + 272, 32, 0); }

bool32 FUN_0804e59c(void);
void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);

void Entity08051b70Elem_StateHidden(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateStock(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateFlyToStock(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateFlyOut(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateFlyIn(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateDeflect(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);
void Entity08051b70Elem_StateShow(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx);

void (*const sEntity08051b70ElemStateFuncs[7])(Entity08051b70*, Entity08051b70Elem*, s32) = {
    Entity08051b70Elem_StateHidden,
    Entity08051b70Elem_StateStock,
    Entity08051b70Elem_StateFlyToStock,
    Entity08051b70Elem_StateFlyOut,
    Entity08051b70Elem_StateFlyIn,
    Entity08051b70Elem_StateDeflect,
    Entity08051b70Elem_StateShow,
};  // 0x085AB6D4

void Entity08051b70_StateHidden(Entity08051b70*);
void Entity08051b70_StateSend(Entity08051b70*);
void Entity08051b70_StateReceive(Entity08051b70*);
void Entity08051b70_StateBlock(Entity08051b70*);
void Entity08051b70_StateRivalBlock(Entity08051b70*);
void Entity08051b70_StateReturn(Entity08051b70*);
void Entity08051b70_StateResult(Entity08051b70*);

void (*const sEntity08051b70StateFuncs[7])(Entity08051b70*) = {
    Entity08051b70_StateHidden,
    Entity08051b70_StateSend,
    Entity08051b70_StateReceive,
    Entity08051b70_StateBlock,
    Entity08051b70_StateRivalBlock,
    Entity08051b70_StateReturn,
    Entity08051b70_StateResult,
};  // 0x085AB6F0

void Entity08051b70_NextBlockStep(Entity08051b70* p, s32 param_2) {
  if (p->blockFlags & 1) {
    p->blockFlags &= ~1;
    p->state = 3;
    p->entered = TRUE;
    p->timer = 0;
  } else if (p->blockFlags & 2) {
    p->blockFlags &= ~2;
    p->state = 4;
    p->entered = TRUE;
    p->timer = 0;
  } else if (param_2) {
    p->state = 5;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->state = 6;
    p->entered = TRUE;
    p->timer = 0;
  }
}

void Entity08051b70Elem_SetRandomWobble(Entity08051b70Elem* elem, s32 base, u32 mask) {
  u16* table = gRandomTable;
  s32 wobble = base + (_Random(table) & mask);

  if ((u8)_Random(table) < 128) {
    elem->wobble = wobble;
  } else {
    elem->wobble = -wobble;
  }
}

// 残差は t * 4 の lsls と gSineTable のプール読みの順序だけ (27/27), 原典は添字を先に作る, Tier A-B (POLAR_Z / SIN * amp, d の型) は試済
NON_MATCH void Entity08051b70_ApplyWobble(Vec3* pos, u32 t, s32 amp) {
#ifdef NONMATCHING_C
  s32 d = FixToInt(12, SIN(t * 4) * amp);

  pos->x += d;
  pos->y += d;
#else
  INCFUNC("asm/func/Entity08051b70_ApplyWobble.inc");
#endif
}

void Entity08051b70Elem_StateHidden(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  if (elem->entered) {
    elem->entered = FALSE;
    AuxSprite_Hide(&elem->counterSprite);
    AuxSprite_Hide(&elem->batSprite);
  }
}

// 置き場で数を出し, shakeTimer の間は揺らす, 0 匹なら隠す
// 残差: 置き場へ置いて揺らす塊が2回あり inline らしい, inline (VEC3_SET は &elem->batSprite.pos, 揺らしは AuxSprite* bat 経由) で 158 対 153 命令まで, 揺らしの x/y を ldrh で読み乱数を先に引く形が未解決
// 試済: 揺らしを AuxSprite* 引数の別 inline, 乱数を先に書く式, bat ローカルだけ
NON_MATCH void Entity08051b70Elem_StateStock(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  if (elem->entered) {
    elem->entered = FALSE;
    elem->shakeTimer = 0;
    VEC3_SET(elem->batSprite.pos, (idx & 3) * 24 + 80, 144, 0);
    if (elem->shakeTimer != 0) {
      u16* table = gRandomTable;

      elem->batSprite.pos.x += (_Random(table) & 3) - 1;
      elem->batSprite.pos.y += (_Random(table) & 3) - 1;
    }
    elem->counterSprite.pos = elem->batSprite.pos;
  }
  if (elem->count != 0) {
    elem->counterSprite.poseIdx = elem->count;
    elem->batSprite.poseIdx = elem->color;
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
    if (elem->shakeTimer != 0) {
      elem->shakeTimer--;
      VEC3_SET(elem->batSprite.pos, (idx & 3) * 24 + 80, 144, 0);
      if (elem->shakeTimer != 0) {
        u16* table = gRandomTable;

        elem->batSprite.pos.x += (_Random(table) & 3) - 1;
        elem->batSprite.pos.y += (_Random(table) & 3) - 1;
      }
      elem->counterSprite.pos = elem->batSprite.pos;
    }
  } else {
    AuxSprite_Hide(&elem->counterSprite);
    AuxSprite_Hide(&elem->batSprite);
  }
  elem->timer++;
#else
  INCFUNC("asm/func/Entity08051b70Elem_StateStock.inc");
#endif
}

void Entity08051b70Elem_StateFlyToStock(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite* counterSprite = &elem->counterSprite;
  AuxSprite* batSprite = &elem->batSprite;

  if (elem->entered) {
    Vec3* to;

    elem->entered = FALSE;
    counterSprite->poseIdx = elem->count;
    batSprite->poseIdx = elem->color;
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
    to = &elem->to;
    VEC3_SET(*to, (idx & 3) * 24 + 80, 144, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
  }
  LerpVec3(&batSprite->pos, &elem->from, &elem->to, elem->timer, 5);
  Entity08051b70_ApplyWobble(&batSprite->pos, elem->timer, elem->wobble);
  counterSprite->pos = batSprite->pos;
  if (elem->timer >= 32) {
    p->elems[idx & 3].count += elem->count;
    p->elems[idx & 3].shakeTimer = 8;
    elem->count = 0;
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

void Entity08051b70Elem_StateFlyOut(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite* counterSprite = &elem->counterSprite;
  AuxSprite* batSprite = &elem->batSprite;

  if (elem->entered) {
    Vec3* v;
    s16 x;

    elem->entered = FALSE;
    counterSprite->poseIdx = elem->count;
    batSprite->poseIdx = elem->color;
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
    v = &elem->from;
    x = (idx & 3) * 24;
    VEC3_SET(*v, x + 80, 144, 0);
    v = &elem->to;
    VEC3_SET(*v, x + 272, 32, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
    p->elems[idx & 3].count = 0;
  }
  LerpVec3(&batSprite->pos, &elem->from, &elem->to, elem->timer, 5);
  Entity08051b70_ApplyWobble(&batSprite->pos, elem->timer, elem->wobble);
  counterSprite->pos = batSprite->pos;
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

// 残差は entered を落とす 0 と from/to を指すポインタの r2/r3 入れ替えだけ (109/109), Tier A-C (Vec3 ポインタの使い回し, inline setter, counterSprite/2 の宣言順) は試済
NON_MATCH void Entity08051b70Elem_StateFlyIn(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* batSprite = &elem->batSprite;
  AuxSprite* counterSprite = &elem->counterSprite;

  if (elem->entered) {
    Vec3* v;
    s16 x;

    elem->entered = FALSE;
    counterSprite->poseIdx = elem->count;
    batSprite->poseIdx = elem->color;
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
    v = &elem->from;
    x = (idx & 3) * 24;
    VEC3_SET(*v, x + 272, 32, 0);
    v = &elem->to;
    VEC3_SET(*v, x + 80, 144, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
  }
  LerpVec3(&batSprite->pos, &elem->from, &elem->to, elem->timer, 5);
  Entity08051b70_ApplyWobble(&batSprite->pos, elem->timer, elem->wobble);
  counterSprite->pos = batSprite->pos;
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
    p->elems[idx & 3].count += elem->count;
    p->elems[idx & 3].shakeTimer = 8;
    elem->count = 0;
  }
  elem->timer++;
#else
  INCFUNC("asm/func/Entity08051b70Elem_StateFlyIn.inc");
#endif
}

// 右上から置き場へ近づき, 28 フレームで乱数で少しずらした逆向きへ逸れていく
// 残差 176 対 178 命令: 原典は from と to の番地を別レジスタに残して ArcTan2_8 の y 差分に使い vel は to+8 で作る, 乱数は ArcTan2_8 の後, vel.y は 8 を muls で掛ける
// 試済: from/to/vel を別ポインタ, from だけ別で v を to/vel に使い回し, 角度を2文に分ける, SetFromTopRight inline
NON_MATCH void Entity08051b70Elem_StateDeflect(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* batSprite = &elem->batSprite;
  AuxSprite* counterSprite = &elem->counterSprite;

  if (elem->entered) {
    Vec3* v;
    s32 x;
    s8 angle;
    u16* table;

    elem->entered = FALSE;
    counterSprite->poseIdx = elem->count;
    batSprite->poseIdx = elem->color;
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
    v = &elem->from;
    x = (idx & 3) * 24;
    VEC3_SET(*v, x + 272, 32, 0);
    v = &elem->to;
    VEC3_SET(*v, x + 80, 144, 0);
    Entity08051b70Elem_SetRandomWobble(elem, 32, 15);
    table = gRandomTable;
    angle = (s8)ArcTan2_8(elem->from.x - elem->to.x, elem->from.y - elem->to.y) - 16 + (_Random(table) & 31);
    v = &elem->vel;
    VEC3_SET(*v, POLAR_X(8, angle), POLAR_Z(8, angle), 0);
  }
  if (elem->timer < 28) {
    LerpVec3(&batSprite->pos, &elem->from, &elem->to, elem->timer, 5);
    Entity08051b70_ApplyWobble(&batSprite->pos, elem->timer, elem->wobble);
  } else {
    Vec3_Add(&batSprite->pos, &elem->vel);
  }
  counterSprite->pos = batSprite->pos;
  if (elem->timer >= 44) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
#else
  INCFUNC("asm/func/Entity08051b70Elem_StateDeflect.inc");
#endif
}

void Entity08051b70Elem_StateShow(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  if (elem->entered) {
    elem->entered = FALSE;
    AuxSprite_SetPoseIdx(&elem->counterSprite, elem->count);
    AuxSprite_SetPoseIdx(&elem->batSprite, elem->color);
    AuxSprite_Show(&elem->counterSprite);
    AuxSprite_Show(&elem->batSprite);
  }
  if (elem->timer >= 32) {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
  elem->timer++;
}

void Entity08051b70Elem_Init(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  u32 color = idx & 3;

  elem->color = color;
  elem->count = 0;
  AuxSprite_Add(&elem->counterSprite, &p->counterGfx, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&elem->counterSprite, 0);
  elem->counterSprite.priority = 0;
  AuxSprite_Add(&elem->batSprite, &p->batGfx, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&elem->batSprite, color);
  elem->batSprite.priority = 0;
  if (idx < 4) {
    elem->state = 1;
    elem->entered = TRUE;
    elem->timer = 0;
  } else {
    elem->state = 0;
    elem->entered = TRUE;
    elem->timer = 0;
  }
}

void Entity08051b70Elem_Destroy(Entity08051b70* p, Entity08051b70Elem* elem, s32 idx) {
  AuxSprite_Remove(&elem->counterSprite);
  AuxSprite_Remove(&elem->batSprite);
}

void Entity08051b70_LaunchNext(Entity08051b70* p, u32 state) {
  if (p->nextIdx < 4 && (p->timer & 7) == 0) {
    Entity08051b70Elem* elem = &p->elems[p->nextIdx + 4];

    if (elem->count != 0) {
      elem->state = state;
      elem->entered = TRUE;
      elem->timer = 0;
    }
    p->nextIdx++;
  }
}

void Entity08051b70_HideAllElems(Entity08051b70* p) {
  Entity08051b70Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    elem->count = 0;
    AuxSprite_Hide(&elem->counterSprite);
    AuxSprite_Hide(&elem->batSprite);
  }
}

void Entity08051b70_StateHidden(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    Entity08051b70_HideAllElems(p);
  }
}

void Entity08051b70_StateSend(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    p->nextIdx = 0;
  }
  Entity08051b70_LaunchNext(p, 3);
  if (p->timer >= 80) {
    if (p->onFinish != NULL) {
      p->onFinish();
    }
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  }
  p->timer++;
}

// 相手から届いたオジャマバットを右上から順に置き場へ飛び込ませる
void Entity08051b70_StateReceive(Entity08051b70* p) {
  if (p->entered) {
    s32 i;

    p->entered = FALSE;
    p->nextIdx = 0;
    for (i = 0; i < 8; i++) {
      u32 color = i & 3;

      if (i < 4) {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, 0);
      } else {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->rivalOjama[color]);
      }
    }
  }
  Entity08051b70_LaunchNext(p, 4);
  if (p->timer >= 80) {
    Entity08051b70_NextBlockStep(p, 0);
  }
  p->timer++;
}

// 自分のブロッキング, 届いたオジャマバットを置き場から右上へ送り返し BLOCKING を出す
// 残差: 最初のループで 0 の定数2つをループ外へ出して r9/ip に持つぶん, &p->mainGfx がスタックへ逃げ sp が 4 バイト多い (141 対 138 命令)
// 試済: i を関数スコープで共有, 前半の枝を SetColorCount でなく直接代入
NON_MATCH void Entity08051b70_StateBlock(Entity08051b70* p) {
#ifdef NONMATCHING_C
  if (p->entered) {
    s32 i;

    p->entered = FALSE;
    p->nextIdx = 0;
    for (i = 0; i < 8; i++) {
      u32 color = i & 3;

      if (i < 4) {
        p->blockedOjama[color] = p->rivalOjama[color];
        p->rivalOjama[color] = 0;
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, 0);
      } else {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->blockedOjama[color]);
        if (p->elems[i].count != 0) {
          p->elems[i].state = 3;
          p->elems[i].entered = TRUE;
          p->elems[i].timer = 0;
        }
      }
    }
    MainSprite_SetPose(&p->banner, &p->mainGfx, LINK_BLOCKING, 0);
    MainSprite_Show(&p->banner);
    p->shakeTimer = 8;
    PlaySound_082406e0(SONG_883);
  }
  if (p->timer == 40) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
      sum += p->blockedOjama[i];
    }
    if (sum == 0) {
      PlaySound_082406e0(SE_NG);
    }
  }
  if (p->timer >= 80) {
    MainSprite_Hide(&p->banner);
    Entity08051b70_NextBlockStep(p, 0);
  }
  p->timer++;
#else
  INCFUNC("asm/func/Entity08051b70_StateBlock.inc");
#endif
}

void Entity08051b70_StateRivalBlock(Entity08051b70* p) {
  if (p->entered) {
    p->entered = FALSE;
    p->nextIdx = 0;
    MainSprite_SetPose(&p->banner, &p->mainGfx, LINK_DOUBLE_BANG, 0);
    MainSprite_Show(&p->banner);
    p->shakeTimer = 8;
    PlaySound_082406e0(SONG_492);
  }
  if (p->timer >= 80) {
    MainSprite_Hide(&p->banner);
    Entity08051b70_NextBlockStep(p, 1);
  }
  p->timer++;
}

// 相手にブロックされた自分のオジャマバットが右上から置き場へ戻ってくる
void Entity08051b70_StateReturn(Entity08051b70* p) {
  if (p->entered) {
    s32 i;

    p->entered = FALSE;
    p->nextIdx = 0;
    for (i = 0; i < 8; i++) {
      u32 color = i & 3;

      if (i < 4) {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->rivalOjama[color]);
      } else {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->myOjama[color]);
        Entity08051b70Elem_SetFromTopRight(&p->elems[i], color);
      }
    }
  }
  Entity08051b70_LaunchNext(p, 2);
  if (p->timer >= 90) {
    if (p->onFinish != NULL) {
      p->onFinish();
    }
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  }
  p->timer++;
}

// 最終的に受けるオジャマバットの数を置き場に出し, 少し待って onFinish を呼ぶ
void Entity08051b70_StateResult(Entity08051b70* p) {
  if (p->entered) {
    s32 i;

    p->entered = FALSE;
    p->nextIdx = 0;
    for (i = 0; i < 8; i++) {
      u32 color = i & 3;

      if (i < 4) {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->rivalOjama[color]);
      } else {
        Entity08051b70Elem_SetColorCount(&p->elems[i], color, 0);
      }
    }
  }
  if (p->timer >= 90) {
    if (p->onFinish != NULL) {
      p->onFinish();
    }
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  }
  p->timer++;
}

s32 Entity08051b70_Update(Entity08051b70* p) {
  if (FUN_0804e59c() == FALSE) {
    Entity08051b70Elem* elem;
    s32 i;

    sEntity08051b70StateFuncs[p->state](p);
    elem = p->elems;
    for (i = 0; i < 8; i++, elem++) {
      sEntity08051b70ElemStateFuncs[elem->state](p, elem, i);
    }
    if (p->shakeTimer != 0) {
      Vec3* pos = &p->banner.pos;

      p->shakeTimer--;
      pos->x = 0;
      pos->y = 64;
      if (p->shakeTimer != 0) {
        u16* table = gRandomTable;

        pos->x = (_Random(table) & 3) - 2;
        pos->y = (_Random(table) & 3) + 62;
      }
    }
  }
  return 0;
}

s32 Entity08051b70_Destroy(Entity08051b70* p) {
  Entity08051b70Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    Entity08051b70Elem_Destroy(p, elem, i);
  }
  MainSprite_Remove(&p->banner);
  gEntity08051b70 = NULL;
  return 0;
}

s32 Entity08051b70_Init(Entity08051b70* p) {
  MainSpriteGfxFile* f;
  Vec3 pos;
  Entity08051b70Elem* elem;
  s32 i;

  gEntity08051b70 = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  if (f == NULL) {
    return -1;
  }
  p->mainGfx = *f;
  OpenMainSpriteFile(&p->mainGfx, f);
  if (!Video_GetAuxSprite(&p->batGfx, SPRITE_OJAMA_BAT) || !Video_GetAuxSprite(&p->counterGfx, SPRITE_OJAMA_BAT_CTR)) {
    return -1;
  }

  VEC3_SET(pos, 0, 64, 0);
  MainSprite_Add(&p->banner, &p->mainGfx, LINK_BLOCKING, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, &pos);
  p->state = 0;
  p->entered = TRUE;
  p->timer = 0;
  elem = p->elems;
  for (i = 0; i < 8; i++, elem++) {
    Entity08051b70Elem_Init(p, elem, i);
  }
  return 0;
}

Entity08051b70* Entity08051b70_Create(u32 id, u32 unused) {
  Entity08051b70* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity08051b70));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08051b70_Update, Entity08051b70_Destroy);
    if (Entity08051b70_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 自分のオジャマバットの数を受け取り, 置き場から右上へ送り出す演出を始める
s32 Entity08051b70_StartSend(void (*onFinish)(void), CrossoverBattleSide* mine) {
  Entity08051b70* p = gEntity08051b70;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  p->onFinish = onFinish;
  p->blockFlags = 0;
  for (i = 0; i < 4; i++) {
    p->myOjama[i] = mine->ojama[i];
    p->rivalOjama[i] = 0;
    p->blockedOjama[i] = 0;
  }
  for (i = 4; i < 8; i++) {
    u32 color = i & 3;

    Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->myOjama[color]);
  }
  p->state = 1;
  p->entered = TRUE;
  p->timer = 0;
  return 0;
}

// 双方のオジャマバットの数とブロッキングを受け取り, 相手のバットが飛び込んでくる演出を始める, incoming は読まない
s32 Entity08051b70_StartExchange(void (*onFinish)(void), CrossoverBattleSide* mine, CrossoverBattleSide* rival, u8* incoming) {
  Entity08051b70* p = gEntity08051b70;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  p->onFinish = onFinish;
  p->blockFlags = 0;
  if (mine->blocking) {
    p->blockFlags = 1;
  }
  if (rival->blocking) {
    p->blockFlags |= 2;
  }
  for (i = 0; i < 4; i++) {
    p->myOjama[i] = mine->ojama[i];
    p->rivalOjama[i] = rival->ojama[i];
    p->blockedOjama[i] = 0;
  }
  for (i = 4; i < 8; i++) {
    u32 color = i & 3;

    Entity08051b70Elem_SetColorCount(&p->elems[i], color, p->myOjama[color]);
  }
  p->state = 2;
  p->entered = TRUE;
  p->timer = 0;
  return 0;
}

// 拾ったオジャマバットを pos の画面位置から置き場へ飛ばす, 飛んでいる途中の同じ色は先に置き場へ足す
s32 Entity08051b70_SpawnCollected(Vec3* pos, s32 color, s32 count) {
  Entity08051b70* p = gEntity08051b70;
  Entity08051b70Elem* elem;

  if (p == NULL) {
    return -1;
  }
  elem = &p->elems[color + 4];
  if (elem->count != 0) {
    p->elems[color].count += elem->count;
    elem->count = 0;
  }
  Entity08051b70Elem_SetColorCount(elem, color, count);
  elem->state = 2;
  elem->entered = TRUE;
  elem->timer = 0;
  WorldToScreen(&elem->from, pos);
  return 0;
}
