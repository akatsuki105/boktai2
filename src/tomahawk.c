#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "vm.h"

// トマホークの残像1枚, 本体の位置と回転を写して数フレームだけ出す
typedef struct {
  AuxSprite sprite;        // 0x00
  AuxSpriteGfx gfx;        // 0x2C, SPR_EFF_SHAIAN_SPIN
  AuxAnimState anim;       // 0x48, animFile のアニメ 1 を流す
  u16 timer;               // 0x58, 0 でない間は毎フレーム減り, 0 になった瞬間に sprite を隠す
  u8 unk_5a[0x5C - 0x5A];  // 0x5A, まだ未解析
} TomahawkAfterimage;
static_assert(sizeof(TomahawkAfterimage) == 92);

// シャイアンが投げるトマホーク1本, 回転しながらプレイヤーを追尾して飛び, 壁か攻撃に当たると跳ね返って落ち, 点滅して消える
typedef struct {
  AuxSprite sprite;               // 0x000, pos は Tomahawk_Spawn の第1引数の写し
  AuxAnimState anim;              // 0x02C
  TomahawkAfterimage sprites[2];  // 0x03C
  Hitbox hitbox;                  // 0x0F4, 攻撃判定, 当たると Tomahawk_OnHit で state 2 へ移る
  Hitbox hurtbox;                 // 0x144, 食らい判定, 当たると Tomahawk_OnHurt で state 2 へ移る
  Vec3 vel;                       // 0x194, 毎フレーム sprite.pos に足す
  u8 unk_19c;                     // 0x19C, 生成時の angle, 読み手は未発見
  u8 angle;                       // 0x19D, 進む向き (256 で1周)
  u8 homingTime;                  // 0x19E, 0 になるまでプレイヤーへ向きを変え続ける, ほぼ向くと半分になる
  u8 turnSpeed;                   // 0x19F, 1回に曲がる角度, ほぼ向くと半分になり 4 フレームごとに 1 減る
  u16 speed;                      // 0x1A0, 進む速さ, Tomahawk_UpdateFly が 4 フレームごとに 1 上げる
  u8 afterimageIdx;               // 0x1A2, 次に使う残像 (sprites[]) の番号, 0 と 1 を交互に使う
  u8 afterimageInterval;          // 0x1A3, 残像を出す間隔のフレーム数, 初期値 2
  AuxAnimFile* animFile;          // 0x1A4, ANIM_8DC7
  s32 lifetime;                   // 0x1A8, 初期値 120, 尽きると state 3 へ移る
  u16 unk_1ac;                    // 0x1AC, 生成時に 0 が入るだけ
  u8 state;                       // 0x1AE, sTomahawkUpdates の添字 (0:待機 1:飛行 2:跳ね返り 3:消える)
  s8 slotIdx;                     // 0x1AF, activeMask 上の自分のビット番号
  u16 timer;                      // 0x1B0, stateBegun が立っていると 0 に戻る
  bool8 stateBegun;               // 0x1B2
  u8 homingDelay;                 // 0x1B3, 0 になるまで向きを変えない
} Tomahawk;
static_assert(sizeof(Tomahawk) == 436);

// トマホークを8本まで同時に飛ばすシングルトン, シャイアン戦 (Shaian_StateTomahawk) と初対面のカットシーン (Cmd_AddTomahawk) で使う
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;        // 0x018, SPR_EFF_SHAIAN_SPIN
  u8 unk_34[0x38 - 0x34];  // 0x034, まだ未解析
  u32 activeMask;          // 0x038, elems のどのスロットが使用中かのビットマスク
  Tomahawk elems[8];       // 0x03C
} TomahawkManager;
static_assert(sizeof(TomahawkManager) == 3548);

IWRAM_DATA TomahawkManager* gTomahawkManager = NULL;  // 0x0300017C

static inline bool8 TomahawkManager_IsActive(TomahawkManager* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

void Tomahawk_UpdateIdle(TomahawkManager*, Tomahawk*);
void Tomahawk_UpdateFly(TomahawkManager*, Tomahawk*);
void Tomahawk_UpdateBounce(TomahawkManager*, Tomahawk*);
void Tomahawk_UpdateVanish(TomahawkManager*, Tomahawk*);
TomahawkManager* TomahawkManager_Create(void);

void (*const sTomahawkUpdates[4])(TomahawkManager*, Tomahawk*) = {
    Tomahawk_UpdateIdle,
    Tomahawk_UpdateFly,
    Tomahawk_UpdateBounce,
    Tomahawk_UpdateVanish,
};  // 0x085AD364

// 残像用のスプライト2枚を, 隠した状態で用意する
void Tomahawk_InitSprites(Tomahawk* elem) {
  s32 i;

  for (i = 0; i < 2; i++) {
    Video_GetAuxSprite(&elem->sprites[i].gfx, SPR_EFF_SHAIAN_SPIN);
    AuxSprite_Add(&elem->sprites[i].sprite, &elem->sprites[i].gfx, 0);
    Video_SetAuxSpritePltt(&elem->sprites[i].gfx, 626);
    elem->sprites[i].sprite.flags = SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    elem->sprites[i].timer = 0;
  }
  elem->afterimageIdx = 0;
  elem->afterimageInterval = 2;
}

void Tomahawk_SpawnAfterimage(Tomahawk* elem) {
  if (Mod(elem->timer, elem->afterimageInterval) == 0) {
    AuxAnim_SetAnim(&elem->sprites[elem->afterimageIdx].anim, elem->animFile, 1, 0, 0);
    AuxSprite_AdvanceAnim(&elem->sprites[elem->afterimageIdx].sprite, &elem->sprites[elem->afterimageIdx].anim);
    elem->sprites[elem->afterimageIdx].sprite.pos = elem->sprite.pos;
    elem->sprites[elem->afterimageIdx].sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->sprites[elem->afterimageIdx].sprite.flags |= SPRFLAG_AFFINE;
    elem->sprites[elem->afterimageIdx].sprite.rotation = elem->sprite.rotation;
    elem->sprites[elem->afterimageIdx].timer = 4;
    elem->afterimageIdx++;
    if (elem->afterimageIdx > 1) {
      elem->afterimageIdx = 0;
    }
  }
}

void Tomahawk_UpdateAfterimages(Tomahawk* elem) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (elem->sprites[i].timer != 0) {
      elem->sprites[i].timer--;
      if (elem->sprites[i].timer == 0) {
        elem->sprites[i].sprite.flags |= SPRFLAG_HIDDEN;
        elem->sprites[i].sprite.flags &= ~SPRFLAG_AFFINE;
      }
    }
  }
}

void Tomahawk_RemoveAfterimages(Tomahawk* elem) {
  s32 i;

  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&elem->sprites[i].sprite);
  }
}

void Tomahawk_OnHit(Hitbox* a, Hitbox* b, Tomahawk* elem) {
  Hitbox* hb;

  elem->state = 2;
  elem->stateBegun = 1;

  hb = &elem->hitbox;
  hb->flags |= HBF_HIDDEN;
  hb = &elem->hurtbox;
  hb->flags |= HBF_HIDDEN;
}

void Tomahawk_OnHurt(Hitbox* a, Hitbox* b, Tomahawk* elem) {
  Hitbox* hb;

  elem->state = 2;
  elem->stateBegun = 1;

  hb = &elem->hitbox;
  hb->flags |= HBF_HIDDEN;
  hb = &elem->hurtbox;
  hb->flags |= HBF_HIDDEN;
}

void Tomahawk_InitHitboxes(Tomahawk* elem, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 unk_6, s32 unk_7, s32 unk_8) {
  Hitbox* hitbox;
  Hitbox* hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 64, 32);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Tomahawk_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  hurtbox = &elem->hurtbox;
  Hitbox_Init(hurtbox, 0, HBF_HURTBOX | HBF_ACTOR, 0, 16, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_SetHandler(hurtbox, Tomahawk_OnHurt, elem);
  Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
  Hitbox_Register(hurtbox);
}

void Tomahawk_UpdateHitboxes(Tomahawk* elem) {
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
}

// 空いている枠を1つ確保して返す, 空きが無ければ NULL
Tomahawk* TomahawkManager_Alloc(TomahawkManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!TomahawkManager_IsActive(p, i)) {
      Tomahawk* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

void Tomahawk_TurnToPlayer(Tomahawk* elem) {
  if (elem->homingDelay != 0) {
    elem->homingDelay--;
  } else if (elem->homingTime != 0) {
    Vec3 diff;
    s32 d;

    Vec3_Delta(&diff, &elem->sprite.pos, &gPlayerPtr[0]->mover.pos);
    d = ArcTan2_8(diff.x, diff.z) - elem->angle;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) > 8) {
      if (d > 0) {
        elem->angle += elem->turnSpeed;
      } else {
        elem->angle -= elem->turnSpeed;
      }
    } else {
      elem->homingTime /= 2;
      elem->turnSpeed /= 2;
    }
    if (elem->homingTime != 0) {
      elem->homingTime--;
    }
    if (Mod(elem->timer, 4) == 0 && elem->turnSpeed != 0) {
      elem->turnSpeed--;
    }
  }
}

void Tomahawk_UpdateIdle(TomahawkManager* p, Tomahawk* elem) {}

// state 1, angle と speed で進みながらプレイヤーへ向きを変える, 壁に当たると state 2, lifetime が尽きると state 3 へ移る
void Tomahawk_UpdateFly(TomahawkManager* p, Tomahawk* elem) {
  Vec3 v;
  s32 height;

  if (elem->stateBegun) {
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  Tomahawk_SpawnAfterimage(elem);
  Tomahawk_UpdateAfterimages(elem);
  Vec3_SetPolar(&elem->vel, elem->angle, elem->speed);
  Vec3_Sum(&v, &elem->sprite.pos, &elem->vel);
  height = (TileAtIndex(GetCollisionTileIdx(&v))->heightStairs & 0xF) << 8;
  if (height > elem->sprite.pos.y) {
    elem->state = 2;
    elem->stateBegun = TRUE;
    return;
  }
  Vec3_Sum(&elem->sprite.pos, &elem->vel, &elem->sprite.pos);
  Tomahawk_TurnToPlayer(elem);
  Tomahawk_UpdateHitboxes(elem);
  elem->sprite.rotation += 8;
  elem->timer++;
  if (Mod(elem->timer, 4) == 0) {
    elem->speed++;
  }
  if (elem->lifetime > 0) {
    elem->lifetime--;
  } else {
    elem->state = 3;
    elem->stateBegun = TRUE;
  }
}

// state 2, 壁か攻撃に当たったら向きを反転して跳ね返り, 落ちて床で止まったあと点滅して消えきったらスロットを空ける
// 228/228命令, 残差はレジスタ割当だけ: z の SIN の前の & 0xFF を原典は r0 に作るがこちらは angle の r3 に上書きし, 以降の乱数表のポインタと当たり判定のポインタ (原典 r1, こちら r2) がずれる
// 試済: (u8) キャスト, & 0xFF を引数の式に書く (226), u8/s32 のローカル, 判定2つを外す static inline (変化なし), POLAR_X/POLAR_Z の直書き (239 に悪化)
NON_MATCH void Tomahawk_UpdateBounce(TomahawkManager* p, Tomahawk* elem) {
#ifdef NONMATCHING_C
  s32 height;

  if (elem->stateBegun) {
    Hitbox* hb;
    u32 angle;

    elem->timer = 0;
    angle = ArcTan2_8(elem->vel.x, elem->vel.z) + 128;
    angle &= 0xFF;
    Vec3_SetPolar(&elem->vel, angle, 12);
    elem->vel.y = (Random() & 0xF) + 8;
    hb = &elem->hitbox;
    hb->flags |= HBF_HIDDEN;
    hb = &elem->hurtbox;
    hb->flags |= HBF_HIDDEN;
    PlaySound_082406e0(SONG_484);
    elem->stateBegun = FALSE;
  }
  Tomahawk_UpdateAfterimages(elem);
  Vec3_Sum(&elem->sprite.pos, &elem->vel, &elem->sprite.pos);
  elem->vel.y -= 2;
  height = (TileAtIndex(GetCollisionTileIdx(&elem->sprite.pos))->heightStairs & 0xF) << 8;
  if (elem->sprite.pos.y < height) {
    VEC3_SET(elem->vel, 0, 0, 0);
    elem->sprite.pos.y = height;
  }
  if (Sprite_UpdateVanishBlink(&elem->sprite.flags, elem->timer, 10, 30)) {
    Hitbox_Unregister(&elem->hurtbox);
    Tomahawk_RemoveAfterimages(elem);
    AuxSprite_Remove(&elem->sprite);
    p->activeMask &= ~(1 << elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/Tomahawk_UpdateBounce.inc");
#endif
}

// state 3, 判定を外して vel で流れながら回転し, 点滅して消えきったらスロットを空ける
// 93/92命令, 残差はレジスタ割当だけ: 原典は引数の elem のレジスタ (r1) をそのまま hitbox のポインタに作り替え, 0 の定数を r4/r3 に置く (こちらは hb が r4)
// 試済: Hitbox* hb の宣言をブロック先頭/関数先頭, Vec3_Sum(&pos, &pos, &vel), 判定2つを外す static inline (elem が r4 に移って悪化)
// 未: Vec3_Sum(&pos, &vel, &pos), Tomahawk_UpdateFly ではこの形で pos が先に読まれて一致した
NON_MATCH void Tomahawk_UpdateVanish(TomahawkManager* p, Tomahawk* elem) {
#ifdef NONMATCHING_C
  if (elem->stateBegun) {
    Hitbox* hb;

    hb = &elem->hitbox;
    hb->flags |= HBF_HIDDEN;
    hb = &elem->hurtbox;
    hb->flags |= HBF_HIDDEN;
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  Vec3_Add(&elem->sprite.pos, &elem->vel);
  Tomahawk_UpdateAfterimages(elem);
  elem->sprite.rotation += 8;
  if (Sprite_UpdateVanishBlink(&elem->sprite.flags, elem->timer, 10, 30)) {
    Hitbox_Unregister(&elem->hurtbox);
    Tomahawk_RemoveAfterimages(elem);
    AuxSprite_Remove(&elem->sprite);
    p->activeMask &= ~(1 << elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/Tomahawk_UpdateVanish.inc");
#endif
}

// pos から angle の向きへ飛ばし, プレイヤーを追尾させる
void Tomahawk_Spawn(Vec3* pos, s32 angle, s32 homingTime, s32 turnSpeed, s32 homingDelay, s32 speed, s32 rotation, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes) {
  TomahawkManager* p = gTomahawkManager;
  Tomahawk* elem;
  AuxSprite* sprite;

  if (p == NULL) {
    p = TomahawkManager_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = TomahawkManager_Alloc(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->lifetime = 120;
  elem->unk_1ac = 0;
  elem->unk_19c = angle;
  elem->angle = angle;
  elem->homingTime = homingTime;
  elem->turnSpeed = turnSpeed;
  elem->homingDelay = homingDelay;
  elem->speed = speed;
  elem->stateBegun = TRUE;
  sprite = &elem->sprite;
  elem->sprite.pos = *pos;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_8DC7);
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, 1, 0, 0);
  Video_SetAuxSpritePltt(sprite->gfx, 626);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  sprite->priority = 1;
  sprite->flags |= SPRFLAG_AFFINE;
  AuxSprite_Show(sprite);
  sprite->rotation = rotation;
  Tomahawk_InitSprites(elem);
  Tomahawk_InitHitboxes(elem, power, knockback, attrs, iframes, 0, 0, 0);
}

s32 TomahawkManager_Update(TomahawkManager* p) {
  Tomahawk* elems = p->elems;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (TomahawkManager_IsActive(p, i)) {
        sTomahawkUpdates[elems[i].state](p, &elems[i]);
      }
    }
  }

  return 0;
}

s32 TomahawkManager_Destroy(TomahawkManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (TomahawkManager_IsActive(p, i)) {
      s32 j;

      Hitbox_Unregister(&p->elems[i].hurtbox);
      AuxSprite_Remove(&p->elems[i].sprite);
      for (j = 0; j < 2; j++) {
        if (p->elems[i].sprites[j].sprite.active) {
          AuxSprite_Remove(&p->elems[i].sprites[j].sprite);
        }
      }
    }
  }
  gTomahawkManager = NULL;
  return 0;
}

s32 TomahawkManager_Init(TomahawkManager* p) {
  p->activeMask = 0;
  Video_GetAuxSprite(&p->gfx, SPR_EFF_SHAIAN_SPIN);
  gTomahawkManager = p;
  return 0;
}

TomahawkManager* TomahawkManager_Create(void) {
  if (gTomahawkManager == NULL) {
    TomahawkManager* p = CreateEntity(ENTITY_UNK_10, sizeof(TomahawkManager));

    if (p != NULL) {
      SetEntityRoutine(p, TomahawkManager_Update, TomahawkManager_Destroy);
      if (TomahawkManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gTomahawkManager;
}

void TomahawkManager_ClearGlobal(void) { gTomahawkManager = NULL; }

// 飛んでいるもの (state 1) をすべて消える状態 (state 3) へ移す
void TomahawkManager_VanishAll(void) {
  TomahawkManager* p = gTomahawkManager;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1) {
      p->elems[i].state = 3;
    }
  }
}

// 0xE0E1, 飛んでいるもの (state 1) をすべて跳ね返る状態 (state 2) へ移す
void Cmd_BounceTomahawks(void) {
  TomahawkManager* p = gTomahawkManager;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1) {
      p->elems[i].state = 2;
      p->elems[i].stateBegun = 1;
    }
  }
}

// 0x983A, スクリプトから要素を1つ出す, '.p' が位置, '.d' が向き, '.h' が追尾時間・旋回量・追尾までの遅延, '.P' が威力・ノックバック・属性・無敵フレーム
void Cmd_AddTomahawk(void) {
  Vec3 pos;
  s32 angle;
  s32 s;
  s32 a;
  s32 homingTime;
  s32 turnSpeed;
  s32 homingDelay;
  s32 power;
  s32 knockback;
  s32 attrs;
  s32 iframes;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  s = VM_GetNamedArgValue('s', 20);
  a = VM_GetNamedArgValue('a', 0);
  if (VM_SeekToNamedArg('h')) {
    homingTime = VM_GetPC() != NULL ? VM_GetValue() : 0;
    turnSpeed = VM_GetPC() != NULL ? VM_GetValue() : 0;
    homingDelay = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    homingTime = 0;
    turnSpeed = 0;
    homingDelay = 0;
  }
  if (VM_SeekToNamedArg('P')) {
    power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    knockback = VM_GetPC() != NULL ? VM_GetValue() : 0;
    attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    iframes = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    power = 0;
    knockback = 0;
    attrs = 0;
    iframes = 0;
  }
  Tomahawk_Spawn(&pos, angle, homingTime, turnSpeed, homingDelay, s, a, power, knockback, attrs, iframes);
}
