#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_pltt.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

// 属性キューブ, プレイヤーがエンチャント攻撃するとエンチャント攻撃の属性に応じて性質や挙動が変化する, これを駆使したパズルがいくつか登場する
#define PROP_FLAME (1 << 0)  // フレイム, 周囲に熱を放出 (隣接する燭台を点火など)
#define PROP_FROST (1 << 1)  // フロスト, 地面に落下 (重量スイッチを押すなど), 属性キューブはもともと床タイルのすこし上で浮いているがそれを接地させる
#define PROP_CLOUD (1 << 2)  // クラウド, 移動 (WK_SPEAR で攻撃した時は2タイル移動)
#define PROP_EARTH (1 << 3)  // アース, 破壊 (属性キューブ自身を消滅させる)

#define OBP_CUBE_NONE OBP_PROPERTY_CUBE(0)
#define OBP_CUBE_FLAME OBP_PROPERTY_CUBE(1)  // PROP_FLAME
#define OBP_CUBE_FROST OBP_PROPERTY_CUBE(2)  // PROP_FROST
#define OBP_CUBE_EARTH OBP_PROPERTY_CUBE(3)  // PROP_EARTH
#define OBP_CUBE_CLOUD OBP_PROPERTY_CUBE(4)  // PROP_CLOUD

// PropertyCubeManager が count 個まとめて管理する要素
typedef struct {
  bool8 active;                  // 0x00, TRUE なら使用中, PropertyCube_Remove で 0 に戻る
  bool8 stateBegun;              // 0x01, PropertyCube_SetState で立ち, 各状態関数が入場処理をして 0 に戻す
  u8 property;                   // 0x02, unk_46 に退避される
  u8 state;                      // 0x03, sPropertyCubeUpdates の添字
  u32 timer;                     // 0x04, state を変えるたびに 0 に戻る
  u32 scriptID;                  // 0x08, 0 以外なら property が変わったとき VM_ExecByID で実行する
  u32 scriptArgs[4];             // 0x0C, スクリプトの argv[4..7]
  u32 unk_1c;                    // 0x1C, PropertyCube_OnHurt が被弾時に 1 を入れる
  u32 unk_20;                    // 0x20, 被弾させた側の HitboxData.weakness
  u32 unk_24;                    // 0x24, 被弾させた側の HitboxData.attributes
  u16 unk_28;                    // 0x28, bit0 が立っていると PropertyCube_Remove が FUN_08002a58 を飛ばす
  u16 unk_2a;                    // 0x2A, 状態関数がビットを立てる, 退避時に 0 に戻る
  u16 zone;                      // 0x2C, '.m' が 0 以外なら置いた位置の GetZoneAt
  u16 plttIdx;                   // 0x2E, OBP_PROPERTY_CUBE(0..4), property のビットで選ぶ
  s8 slideTiles;                 // 0x30, 風で押されて滑る残りタイル数, 槍で当てたなら 2タイル
  u8 slideAngle;                 // 0x31, 滑る向き (8bit 角度)
  s16 groundY;                   // 0x32, 落下先の高さ (<< 8)
  s16 unk_34;                    // 0x34, PropertyCube_UpdateState2 が毎フレーム -2 し, 0 以下で state 1 へ戻す
  s16 unk_36;                    // 0x36, unk_34 の上限 (bobOffset を足した値)
  s16 burnTimer;                 // 0x38, 炎の状態の残りフレーム, 0 になると炎の状態が消える, PropertyCube_OnFrost が 0 に戻す
  u16 shakeTimer;                // 0x3A, 0 以外の間は毎フレーム減らしながら揺らす
  u16 shakePower;                // 0x3C, 揺れ幅, shakeTimer の写し
  s16 hp;                        // 0x3E, '.l=1', 地属性で被弾するたび減り 0 以下で砕ける
  u8 unk_40;                     // 0x40, 0 以外の間は被弾を受け付けない, PropertyCube_OnHurt が 10 を入れる
  u8 flashTimer;                 // 0x41, 被弾で 10 を入れ白く光らせる, 0 になるとパレットを plttIdx に戻す
  s16 burnTime;                  // 0x42, '.F=-1', 炎属性で被弾すると burnTimer に写される, 負なら炎が消えない
  bool8 releaseReq;              // 0x44, 0 以外なら PropertyCubeManager_Update が PropertyCube_Remove で解放する
  u8 unk_45;                     // 0x45, state の退避先
  u8 unk_46;                     // 0x46, property の退避先
  u8 unk_47;                     // 0x47
  Mover obj;                     // 0x48, obj.id は PropertyCubeManager_FindCubeById の検索キー
  AuxSpriteGfx gfx;              // 0x8C, SPRITE_PROPERTY_CUBE
  AuxSprite spr_a8;              // 0xA8
  AuxSpriteGfx gfx2;             // 0xD4, SPRITE_PROPERTY_CUBE
  AuxSprite spr_f0;              // 0xF0
  MapTileOverride tileOverride;  // 0x11C
  HitboxData hurtbox;            // 0x12C
  HitboxData hitbox;             // 0x17C
  ZoneEventSource zoneSource;    // 0x1CC
} PropertyCube;
static_assert(sizeof(PropertyCube) == 508);

// 属性キューブ
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_9
  u32 unk_18;           // 0x18, PropertyCubeManager_Init で 0 を入れるだけ
  u32 count;            // 0x1C, '.m=4', キューブの数
  s16 bobOffset;        // 0x20, sin(bobAngle) * 16, 各要素の高さに加算される
  u8 bobAngle;          // 0x22, gSineTable の添字, 毎フレーム +2
  u8 fadeDir;           // 0x23, 0 なら fadeLevel を増やし 32 で 1 に, 1 なら減らし 0 で 0 に戻る
  s16 fadeLevel;        // 0x24, 0..32, BlendPltt の混合率
  u8 _[2];              // 0x26, padding
  rgb555* plttBase;     // 0x28, OBP_CUBE_NONE
  rgb555* plttBlendA;   // 0x2C, OBP_CUBE_FLAME
  rgb555* plttBlendB;   // 0x30, OBP_CUBE_FROST
  rgb555 plttBufA[16];  // 0x34, plttBase と plttBlendA の中間色, 要素のパレットが OBP_CUBE_FLAME のとき使う
  rgb555 plttBufB[16];  // 0x54, plttBase と plttBlendB の中間色
  PropertyCube* cubes;  // 0x74, Malloc で確保
} PropertyCubeManager;
static_assert(sizeof(PropertyCubeManager) == 120);

COMMON_DATA PropertyCubeManager* gPropertyCubeManager = NULL;  // 0x03002B38

void MovableBlock_SpawnDust(Vec3* pos, s32 edgeOffset);
void Entity99CA_CreateAt(Vec3* pos, s32 radius, s32 lifetime, s32 count, s32 kind);

static s32 PropertyCube_OnFlame(PropertyCubeManager*, PropertyCube*);
static s32 PropertyCube_OnFrost(PropertyCubeManager*, PropertyCube*);
static s32 PropertyCube_OnEarth(PropertyCubeManager*, PropertyCube*);
static s32 PropertyCube_OnCloud(PropertyCubeManager*, PropertyCube*);

// state を切り替えて timer を 0 に戻す
static inline void PropertyCube_SetState(PropertyCube* cube, u8 state) {
  cube->state = state;
  cube->timer = 0;
  cube->stateBegun = TRUE;
}

// property のビットから要素のパレット番号を選ぶ
static inline u16 PropertyCube_GetPlttIdx(PropertyCube* cube) {
  if (cube->property == 0) {
    return OBP_CUBE_NONE;
  }
  if (TEST_FLAGS(cube->property, PROP_EARTH)) {
    return OBP_CUBE_EARTH;
  }
  if (TEST_FLAGS(cube->property, PROP_CLOUD)) {
    return OBP_CUBE_CLOUD;
  }
  return TEST_FLAGS(cube->property, PROP_FLAME) ? OBP_CUBE_FLAME : OBP_CUBE_FROST;
}

// 要素のパレットを plttIdx に戻す, OBP_CUBE_FLAME / OBP_CUBE_FROST は点滅用のバッファを使う
static inline void PropertyCube_ApplyPltt(PropertyCubeManager* p, PropertyCube* cube) {
  Video_SetAuxSpritePltt(&cube->gfx, cube->plttIdx);
  if (cube->plttIdx == OBP_CUBE_FLAME) {
    cube->gfx.pltt = p->plttBufA;
  } else if (cube->plttIdx == OBP_CUBE_FROST) {
    cube->gfx.pltt = p->plttBufB;
  }
}

// 被弾していたら属性ごとの処理を回してパレットを選び直す, どれかが state を変えたら 1 を返す
static inline s32 PropertyCube_HandleHit(PropertyCubeManager* p, PropertyCube* cube) {
  s32 handled = 0;

  if (cube->unk_1c) {
    cube->unk_1c = 0;
    if (cube->unk_24 & HBATTR_FLAME) {
      handled = PropertyCube_OnFlame(p, cube);
    }
    if (!handled && (cube->unk_24 & HBATTR_FROST)) {
      handled = PropertyCube_OnFrost(p, cube);
    }
    if (!handled && (cube->unk_24 & HBATTR_EARTH)) {
      handled = PropertyCube_OnEarth(p, cube);
    }
    if (!handled && (cube->unk_24 & HBATTR_CLOUD)) {
      handled = PropertyCube_OnCloud(p, cube);
    }
    cube->plttIdx = PropertyCube_GetPlttIdx(cube);
  }
  return handled;
}

PropertyCubeManager* GetPropertyCubeManager(void) { return gPropertyCubeManager; }

// 枠を片付けて空きに戻す
void PropertyCube_Remove(PropertyCubeManager* p, PropertyCube* cube) {
  if (cube->active) {
    AuxSprite_Remove(&cube->spr_a8);
    AuxSprite_Remove(&cube->spr_f0);
    Map_RemoveTileOverride(&cube->tileOverride);
    Hitbox_Unregister(&cube->hurtbox);
    if (!(cube->unk_28 & 1)) {
      FUN_08002a58(&cube->obj);
    }
    Mover_Unlink(&cube->obj);
    cube->active = FALSE;
  }
}

// 残差0命令 (26/26), レジスタ名だけ違う: 原典は weakness をスクラッチ (r1) に置くが, こちらは r4 に載る
NON_MATCH void PropertyCube_OnHurt(HitboxData* a, HitboxData* b, PropertyCube* cube) {
#ifdef NONMATCHING_C
  if (a->id != b->id && (a->weakness & ((1 << WK_SWORD) | (1 << WK_SPEAR) | (1 << WK_HAMMER))) && cube->unk_40 == 0) {
    cube->unk_1c = 1;
    cube->unk_20 = a->weakness;
    cube->unk_24 = a->attributes;
    cube->unk_40 = 10;
  }
#else
  INCFUNC("asm/func/PropertyCube_OnHurt.inc");
#endif
}

void nop_0800cc04(void) {}

// slideAngle の向きの隣のタイルが, 階段でなく今より低く TATTR_UNK_3 も無ければ 1 を返す
// 残差: 命令の並びはほぼ一致しレジスタ割当が違う, 原典は r6 まで使い & 3 の定数を gCollisionMap の読み込みより前に積む
NON_MATCH s32 PropertyCube_CanSlide(PropertyCube* cube) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &cube->tileOverride.tile;
  s32 dir = Angle_ToDir4(cube->slideAngle);
  s32 step = gCollisionMap->neighborOffsets[dir];
  s32 idx = GetCollisionTileIdx(&cube->obj.pos) + step;
  CollisionMapTile* tile = TileAtIndex(idx);

  if (tile != NULL && (tile->heightStairs >> 4) == 0 && (tile->heightStairs & 0xF) < (self->heightStairs & 0xF) && !(tile->attr & TATTR_UNK_3)) {
    return 1;
  }

  return 0;
#else
  INCFUNC("asm/func/PropertyCube_CanSlide.inc");
#endif
}

// 炎属性で被弾したら炎の状態にする, state 1 なら state 3 へ移る
static s32 PropertyCube_OnFlame(PropertyCubeManager* p, PropertyCube* cube) {
  if (cube->state == 1) {
    if (cube->property == 0) {
      PlaySound_082406e0(SE_PCUBE_HEAT);
    }
    cube->property |= PROP_FLAME;
    CLEAR_FLAGS(cube->property, PROP_FROST);
    cube->burnTimer = cube->burnTime;
    PropertyCube_SetState(cube, 3);
    cube->flashTimer = 10;
    Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
    return 1;
  }

  if (!TEST_FLAGS(cube->property, PROP_FLAME)) {
    if (cube->property == 0) {
      PlaySound_082406e0(SE_PCUBE_HEAT);
    }
    cube->property |= PROP_FLAME;
    CLEAR_FLAGS(cube->property, PROP_FROST);
    cube->burnTimer = cube->burnTime;
    cube->flashTimer = 10;
    Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
  }

  return 0;
}

// 氷属性で被弾したら, state 0 のとき凍らせて沈む state 2 へ移る
static s32 PropertyCube_OnFrost(PropertyCubeManager* p, PropertyCube* cube) {
  if (cube->state == 0) {
    PropertyCube_SetState(cube, 2);
    cube->property |= PROP_FROST;
    CLEAR_FLAGS(cube->property, PROP_FLAME);
    cube->burnTimer = 0;
    cube->flashTimer = 10;
    Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
    return 1;
  }

  return 0;
}

// 地属性で被弾したら hp を減らして揺らし, 尽きたら砕ける state 6 へ移る
static s32 PropertyCube_OnEarth(PropertyCubeManager* p, PropertyCube* cube) {
  cube->hp--;
  cube->shakeTimer = 10;
  if (cube->hp <= 0) {
    cube->hp = 0;
    if (cube->state <= 1) {
      cube->property |= PROP_EARTH;
      PropertyCube_SetState(cube, 6);
      cube->flashTimer = 10;
      Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
      PlaySound_082406e0(SE_PCUBE_VANISH);
      return 1;
    }
  } else {
    cube->flashTimer = 10;
    Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
    PlaySound_082406e0(SE_PCUBE_NG);
  }

  return 0;
}

// 風属性で被弾したら, プレイヤーから見て向こう側へ滑らせる, 滑れなければ揺らすだけ
// 残差: 命令列は一致, 原典は state 用の 4 と timer 用の 0 を r5/r4 に置き, フラグの 4 を積み直す
NON_MATCH static s32 PropertyCube_OnCloud(PropertyCubeManager* p, PropertyCube* cube) {
#ifdef NONMATCHING_C
  if (cube->state == 0) {
    MapTileOverride* self = &cube->tileOverride;
    s32 angle = Map_FindDirToTile(GetCollisionTileIdx(&gPlayerPtr[0]->mover.pos), self->tileIdx, 2);

    if (angle >= 0) {
      cube->slideAngle = angle;
      if (cube->unk_20 & (1 << WK_SPEAR)) {  // 槍の場合、2タイル移動
        cube->slideTiles = 2;
      } else {
        cube->slideTiles = 1;
      }
      if (PropertyCube_CanSlide(cube)) {
        SET_FLAGS(cube->property, PROP_CLOUD);
        cube->flashTimer = 10;
        Video_SetAuxSpritePltt(&cube->gfx, OBP_WHITE_306);
        PropertyCube_SetState(cube, 4);
        if (cube->slideTiles == 2) {
          PlaySound_082406e0(SE_PCUBE_SLIDE2);
        } else {
          PlaySound_082406e0(SE_PCUBE_SLIDE1);
        }
        return 1;
      }
    }
    cube->shakeTimer = 10;
    PlaySound_082406e0(SE_PCUBE_NG);
  } else if (cube->state == 1) {
    cube->shakeTimer = 10;
    PlaySound_082406e0(SE_PCUBE_NG);
  }

  return 0;
#else
  INCFUNC("asm/func/PropertyCube_OnCloud.inc");
#endif
}

// 足元のタイルより 1 段以上浮いていたら, そこへ落ちる state 5 へ移る, (PROP_FROST の処理とは別物)
// 残差: 原典は足元タイルが浮いていない側 (return 0) を成功側より前に置く, 戻り値ブロックの並びが再現できない
NON_MATCH s32 PropertyCube_TryFall(PropertyCubeManager* p, PropertyCube* cube, s32 idx) {
#ifdef NONMATCHING_C
  if (idx < 0 || (idx & 1) == (cube->timer & 1)) {
    Mover* obj = &cube->obj;
    MapTileOverride* self = &cube->tileOverride;
    u16 tileIdx = self->tileIdx;
    MapTileOverride* ov = Map_FindTileOverride(tileIdx, 3);
    CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
    s32 height = (tile->heightStairs & 0xF) << 8;

    if (obj->pos.y - height > 0xFF) {
      cube->groundY = height;
      PropertyCube_SetState(cube, 5);
      return 1;
    }
  }

  return 0;
#else
  INCFUNC("asm/func/PropertyCube_TryFall.inc");
#endif
}

// 止まっている間は被弾した属性ごとの処理を回し, 何も起きなければ足元が抜けていないか見る
// 残差1命令: パレット番号を選ぶ所で, 原典は property == 0 の判定の後に property を読み直すが, こちらは同じレジスタを使い回す
NON_MATCH void PropertyCube_UpdateState0(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
#ifdef NONMATCHING_C
  MapTileOverride* self = &cube->tileOverride;

  if (cube->stateBegun) {
    cube->stateBegun = FALSE;
    SET_FLAGS(self->tile.attr, TATTR_UNK_9);
  }

  cube->unk_2a |= 1;
  if (!PropertyCube_HandleHit(p, cube)) {
    PropertyCube_TryFall(p, cube, idx);
  }
#else
  INCFUNC("asm/func/PropertyCube_UpdateState0.inc");
#endif
}

// 沈んだ状態で被弾した属性ごとの処理を回し, 何も起きなければ足元が抜けていないか見る
// 残差1命令: パレット番号を選ぶ所で, 原典は property == 0 の判定の後に property を読み直すが, こちらは同じレジスタを使い回す
NON_MATCH void PropertyCube_UpdateState1(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
#ifdef NONMATCHING_C
  if (cube->stateBegun) {
    cube->stateBegun = FALSE;
  }

  if (!PropertyCube_HandleHit(p, cube)) {
    PropertyCube_TryFall(p, cube, idx);
  }
#else
  INCFUNC("asm/func/PropertyCube_UpdateState1.inc");
#endif
}

void PropertyCube_UpdateState2(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
  if (cube->stateBegun != 0) {
    cube->stateBegun = FALSE;
    PlaySound_082406e0(SE_PCUBE_FALL);
  }
  cube->unk_2a |= 0x10;
  cube->unk_34 -= 2;
  if (cube->unk_34 > 0) {
    return;
  }
  cube->unk_34 = 0;
  PropertyCube_SetState(cube, 1);
  MovableBlock_SpawnDust(&cube->obj.pos, 0x80);
}

// unk_34 を上限まで毎フレーム +2 で戻し, 届いたら state 0 へ
void PropertyCube_UpdateState3(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
  s32 target;

  if (cube->stateBegun) {
    cube->stateBegun = FALSE;
    PlaySound_082406e0(SE_PCUBE_538);
  }

  cube->unk_2a |= 0x10;
  target = cube->unk_36 + p->bobOffset;
  cube->unk_34 += 2;
  if (cube->unk_34 >= target) {
    cube->unk_34 = target;
    PropertyCube_SetState(cube, 0);
  }
}

// slideAngle の向きへ 16 フレームで 1 タイル滑らせ, slideTiles を使い切るか進めなくなったら止める
// 残差: cube と &delta のレジスタが r4/r5 で入れ替わる, 加えてパレット番号を選ぶ所で原典は property を読み直す
NON_MATCH void PropertyCube_UpdateState4(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
#ifdef NONMATCHING_C
  Vec3 delta;
  Mover* obj = &cube->obj;

  if (cube->stateBegun) {
    cube->stateBegun = FALSE;
  }

  cube->unk_2a |= 0x10;
  Vec3_SetPolar(&delta, cube->slideAngle, 16);
  Vec3_Add(&obj->pos, &delta);
  cube->tileOverride.tileIdx = GetCollisionTileIdx(&obj->pos);
  if (cube->timer >= 16) {
    obj->pos.x = (obj->pos.x & ~0xFF) + 0x80;
    obj->pos.z = (obj->pos.z & ~0xFF) + 0x80;
    if (--cube->slideTiles <= 0) {
      PropertyCube_SetState(cube, 0);
      CLEAR_FLAGS(cube->property, PROP_CLOUD);
    } else if (PropertyCube_CanSlide(cube)) {
      PropertyCube_SetState(cube, 4);
    } else {
      cube->slideTiles = 0;
      CLEAR_FLAGS(cube->property, PROP_CLOUD);
      if (!PropertyCube_TryFall(p, cube, -1)) {
        PropertyCube_SetState(cube, 0);
      }
    }
    cube->plttIdx = PropertyCube_GetPlttIdx(cube);
  }
#else
  INCFUNC("asm/func/PropertyCube_UpdateState4.inc");
#endif
}

// groundY まで毎フレーム 16 ずつ落とし, 着地したらタイルの高さを積み直す
// 残差は movs r0, #2 の位置1か所 (64/64), 原典は定数 2 を property の ldrb より先に作る
// PropertyCube_SetState と property を u32 に広げる形で切り詰めは消えた, TEST_FLAGS は u8 のままだと切り詰め, u32 ローカルに使うと 2 か所ずれる
NON_MATCH void PropertyCube_UpdateState5(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
#ifdef NONMATCHING_C
  MapTileOverride* ov = &cube->tileOverride;
  Mover* obj = &cube->obj;
  s16 groundY;

  if (cube->stateBegun) {
    cube->stateBegun = FALSE;
  }

  cube->unk_2a |= 0x10;
  obj->pos.y -= 16;
  groundY = cube->groundY;
  if (obj->pos.y < groundY) {
    s32 height;
    u32 property;

    obj->pos.y = groundY;
    height = ((groundY >> 8) & 0xF) + 1;
    if (height > 15) {
      height = 15;
    }
    ov->tile.heightStairs = (0xF0 & ov->tile.heightStairs) | height;
    property = cube->property;
    if (property & PROP_FROST) {
      PropertyCube_SetState(cube, 1);
      MovableBlock_SpawnDust(&cube->obj.pos, 0x80);
      PlaySound_082406e0(SE_BLOCK_COLLISION);
    } else {
      PropertyCube_SetState(cube, 0);
      PlaySound_082406e0(SE_PCUBE_539);
    }
  }
#else
  INCFUNC("asm/func/PropertyCube_UpdateState5.inc");
#endif
}

// 砕けて破片を散らし, 点滅させてから 32 フレームで解放を求める
void PropertyCube_UpdateState6(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
  if (cube->stateBegun) {
    Vec3 pos;
    Vec3* v;

    cube->stateBegun = FALSE;
    v = &pos;
    *v = cube->obj.pos;
    v->x += 0x40;
    v->z += 0x40;
    Entity99CA_CreateAt(v, 144, 40, 8, 7);
  }

  cube->unk_2a |= 0x10;
  if (cube->timer < 16) {
    if ((cube->timer & 7) == 4) {
      cube->unk_2a |= 0xC;
    }
  } else if ((cube->timer & 3) == 2) {
    cube->unk_2a |= 0xC;
  }

  if (cube->timer >= 32) {
    cube->releaseReq = TRUE;
  }
}

// 要素の state と property を退避して unk_2a を空にする
void PropertyCube_SaveState(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
  cube->unk_2a = 0;
  cube->unk_45 = cube->state;
  cube->unk_46 = cube->property;
}

// 要素の毎フレームの共通処理: 移動とゾーンイベント, 炎の残り時間, スプライトと当たり判定の更新, パレットの戻し, property が変わったらスクリプトを呼ぶ
// 下書き (503/501命令): 原典は obj を sl に置き size をスタックに置くが, こちらは逆になる, ほかにパレット番号を選ぶ所の property の読み直しと定数 -2 の作り方が違う
NON_MATCH void PropertyCube_UpdateCommon(PropertyCubeManager* p, PropertyCube* cube, u32 idx) {
#ifdef NONMATCHING_C
  Mover* obj = &cube->obj;
  MapTileOverride* self = &cube->tileOverride;
  AuxSprite* spr;
  HitboxData* hb;
  u32 argv[8];
  Vec3 ofs;
  Vec3 size;
  ScriptArgs args;

  GetTileAt(&cube->obj.pos);
  Mover_ApplyMove(&cube->obj);
  if (cube->unk_28 & 2) {
    Map_UpdateZoneEvents(&cube->zoneSource);
  } else if (cube->state == 1) {
    cube->obj.flags &= ~2;
    Map_UpdateZoneEvents(&cube->zoneSource);
  } else {
    cube->obj.flags |= 2;
  }

  if (cube->property & PROP_FLAME) {
    if (p->fadeLevel > 15) {
      cube->unk_2a |= 0x20;
    }
    if (cube->burnTimer > 0 && cube->burnTime >= 0) {
      if (--cube->burnTimer == 0) {
        CLEAR_FLAGS(cube->property, PROP_FLAME);
        cube->plttIdx = PropertyCube_GetPlttIdx(cube);
      }
    }
  }

  spr = &cube->spr_a8;
  if (cube->unk_2a & 0xC) {
    spr->flags |= SPRFLAG_HIDDEN;
  } else {
    spr->flags &= ~SPRFLAG_HIDDEN;
    cube->spr_a8.pos = obj->pos;
    spr->pos.y += cube->unk_34;
    if (cube->unk_2a & 1) {
      cube->unk_34 = p->bobOffset + cube->unk_36;
    }
  }

  spr = &cube->spr_f0;
  if (cube->unk_2a & 4) {
    spr->flags |= SPRFLAG_HIDDEN;
  } else {
    u16 tileIdx;
    MapTileOverride* ov;
    CollisionMapTile* tile;

    spr->flags &= ~SPRFLAG_HIDDEN;
    cube->spr_f0.pos = obj->pos;
    tileIdx = self->tileIdx;
    ov = Map_FindTileOverride(tileIdx, 3);
    tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
    spr->pos.y = (tile->heightStairs & 0xF) << 8;
  }

  if (cube->shakeTimer != 0) {
    cube->shakePower = --cube->shakeTimer;
    cube->unk_2a |= 2;
  }
  if (cube->unk_2a & 2) {
    Vec3_SetPolar(&ofs, Random(), cube->shakePower);
    Vec3_Add(&cube->spr_a8.pos, &ofs);
    Vec3_Add(&cube->spr_f0.pos, &ofs);
  }

  hb = &cube->hurtbox;
  if (cube->unk_2a & 0x10) {
    SET_FLAGS(hb->flags, HBFLAG_HIDDEN);
  } else {
    Hitbox_SetPos(hb, &cube->obj.pos, 0);
    if (cube->unk_40 != 0) {
      cube->unk_40--;
      SET_FLAGS(hb->flags, HBFLAG_HIDDEN);
    } else {
      CLEAR_FLAGS(hb->flags, HBFLAG_HIDDEN);
    }
  }

  hb = &cube->hitbox;
  if (cube->unk_2a & 0x20) {
    if (!(cube->timer & 1)) {
      size.x = Q8(0.563), size.y = Q8(0.5), size.z = Q8(0.250);
    } else {
      size.x = Q8(0.250), size.y = Q8(0.5), size.z = Q8(0.563);
    }
    hb->halfSize = size;
    Hitbox_SetPos(hb, &cube->obj.pos, 0);
    Hitbox_Register(hb);
  }

  if (cube->unk_45 != cube->state && cube->state != 0) {
    CLEAR_FLAGS(self->tile.attr, TATTR_UNK_9);
  }

  if (cube->flashTimer != 0) {
    if (--cube->flashTimer == 0) {
      PropertyCube_ApplyPltt(p, cube);
    }
  } else {
    PropertyCube_ApplyPltt(p, cube);
  }

  if (cube->property != cube->unk_46 && cube->scriptID != 0) {
    s32 i;

    argv[0] = obj->id;
    argv[1] = cube->property;
    argv[2] = cube->property & ~cube->unk_46;
    argv[3] = cube->unk_46 & ~cube->property;
    for (i = 0; i < 4; i++) {
      argv[4 + i] = cube->scriptArgs[i];
    }
    args.argc = 8, args.argv = argv;
    VM_ExecByID(cube->scriptID, &args);
  }

  cube->timer++;
#else
  INCFUNC("asm/func/PropertyCube_UpdateCommon.inc");
#endif
}

s32 PropertyCubeManager_Update(PropertyCubeManager* p) {
  static void (*const sPropertyCubeUpdates[7])(PropertyCubeManager*, PropertyCube*, u32) = {
      PropertyCube_UpdateState0,
      PropertyCube_UpdateState1,
      PropertyCube_UpdateState2,
      PropertyCube_UpdateState3,
      PropertyCube_UpdateState4,
      PropertyCube_UpdateState5,
      PropertyCube_UpdateState6,
  };  // 0x085AA774

  PropertyCube* cube;
  u32 i;

  p->bobOffset = FixToInt(12, SIN(p->bobAngle) * 16);
  p->bobAngle += 2;

  cube = p->cubes;
  for (i = 0; i < p->count; i++, cube++) {
    if (cube->active) {
      PropertyCube_SaveState(p, cube, i);
      sPropertyCubeUpdates[cube->state](p, cube, i);
      PropertyCube_UpdateCommon(p, cube, i);
      if (cube->releaseReq) {
        PropertyCube_Remove(p, cube);
        cube->releaseReq = FALSE;
      }
    }
  }

  BlendPltt(p->plttBufA, p->plttBase, p->plttBlendA, p->fadeLevel, 5);
  BlendPltt(p->plttBufB, p->plttBase, p->plttBlendB, p->fadeLevel, 5);
  if (p->fadeDir == 0) {
    p->fadeLevel++;
    if (p->fadeLevel > 31) {
      p->fadeLevel = 32;
      p->fadeDir = 1;
    }
  } else {
    p->fadeLevel--;
    if (p->fadeLevel <= 0) {
      p->fadeLevel = 0;
      p->fadeDir = 0;
    }
  }

  return 0;
}

s32 PropertyCubeManager_Destroy(PropertyCubeManager* p) {
  PropertyCube* cube = p->cubes;
  u32 i;

  for (i = 0; i < p->count; i++, cube++) {
    PropertyCube_Remove(p, cube);
  }

  if (p->cubes != NULL) {
    Free(p->cubes);
    p->cubes = NULL;
  }

  gPropertyCubeManager = NULL;
  return 0;
}

s32 PropertyCubeManager_Init(PropertyCubeManager* p, u32 _) {
  PropertyCube* cube;
  u32 i;

  gPropertyCubeManager = p;
  p->unk_18 = 0;
  p->cubes = Malloc(p->count * sizeof(PropertyCube));
  if (p->cubes == NULL) {
    return -1;
  }

  ClearMemory(p->cubes, p->count * sizeof(PropertyCube));
  p->fadeDir = 0;
  p->fadeLevel = 0;
  p->plttBase = &gObjPlttData[OBP_CUBE_NONE * 16];
  p->plttBlendA = &gObjPlttData[OBP_CUBE_FLAME * 16];
  p->plttBlendB = &gObjPlttData[OBP_CUBE_FROST * 16];
  CpuCopy32(p->plttBase, p->plttBufA, sizeof(p->plttBufA));
  CpuCopy32(p->plttBase, p->plttBufB, sizeof(p->plttBufB));

  cube = p->cubes;
  for (i = 0; i < p->count; i++, cube++) {
    cube->active = FALSE;
  }

  return 0;
}

// 0xC9BC
PropertyCubeManager* PropertyCubeManager_Create(u32 val) {
  PropertyCubeManager* p = GetPropertyCubeManager();

  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(PropertyCubeManager));
  if (p != NULL) {
    SetEntityRoutine(p, PropertyCubeManager_Update, PropertyCubeManager_Destroy);
    p->count = VM_GetNamedArgValue('m', 4);
    if (PropertyCubeManager_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 空いている要素を1つ返す, 全部使用中なら NULL
PropertyCube* PropertyCubeManager_FindFreeCube(PropertyCubeManager* p) {
  PropertyCube* cube = p->cubes;
  u32 i;

  for (i = 0; i < p->count; i++, cube++) {
    if (!cube->active) {
      return cube;
    }
  }

  return NULL;
}

// 使用中の要素から obj.id が一致するものを返す, 無ければ NULL
PropertyCube* PropertyCubeManager_FindCubeById(PropertyCubeManager* p, u32 id) {
  PropertyCube* cube = p->cubes;
  u32 i;

  for (i = 0; i < p->count; i++, cube++) {
    if (cube->active && cube->obj.id == id) {
      return cube;
    }
  }

  return NULL;
}

// 0xA062
// 空いている要素に属性キューブを1つ置く, PropertyCubeManager が無い, 空きが無い, '.n' の id が使用中ならどれも -1
// 下書き (633/615命令): 呼び出しの並びは一致, 'R' の読み込みループを原典はポインタ比較で回し, こちらは逆向きのカウンタになる, 要素のフィールドのアドレスの退避先も違う
NON_MATCH s32 Cmd_A062(void) {
#ifdef NONMATCHING_C
  PropertyCubeManager* p = GetPropertyCubeManager();
  PropertyCube* cube;
  u32 id;
  u8 state;
  WorldPos pos;
  Vec3 halfSize;
  Vec3 offset;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  cube = PropertyCubeManager_FindFreeCube(p);
  if (cube == NULL) {
    return -1;
  }
  id = VM_GetNamedArgValue('n', 0);
  if (PropertyCubeManager_FindCubeById(p, id) != NULL) {
    return -1;
  }

  cube->property = VM_GetNamedArgValue('a', 0);
  if (cube->property == 0 || TEST_FLAGS(cube->property, PROP_FLAME)) {
    state = 0;
  } else if (TEST_FLAGS(cube->property, PROP_FROST)) {
    state = 1;
  } else {
    state = TEST_FLAGS(cube->property, PROP_CLOUD) ? 0 : 6;
  }
  PropertyCube_SetState(cube, state);

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue(), pos.y = VM_GetValue(), pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  pos.x = (pos.x & ~0xFF) | 0x80;
  pos.z = (pos.z & ~0xFF) | 0x80;
  pos.y = TileHeightAt(&pos);

  cube->scriptID = VM_GetNamedArgValue('P', 0);
  if (VM_SeekToNamedArg('R')) {
    for (i = 0; i < 4; i++) {
      cube->scriptArgs[i] = VM_GetPC() ? VM_GetValue() : 0;
    }
  } else {
    for (i = 0; i < 4; i++) {
      cube->scriptArgs[i] = 0;
    }
  }

  cube->unk_1c = 0;
  cube->unk_20 = 0;
  cube->unk_24 = 0;
  cube->unk_28 = VM_GetNamedArgValue('f', 0);
  cube->unk_2a = 0;
  cube->zone = VM_GetNamedArgValue('m', 0) ? GetZoneAt(&pos) : 0;
  cube->plttIdx = PropertyCube_GetPlttIdx(cube);
  cube->burnTime = VM_GetNamedArgValue('F', -1);
  if (TEST_FLAGS(cube->property, PROP_FLAME)) {
    cube->burnTimer = cube->burnTime;
  } else {
    cube->burnTimer = 0;
  }
  cube->shakeTimer = 0;
  cube->slideTiles = 0;
  cube->slideAngle = 0;
  cube->groundY = pos.y;
  cube->unk_36 = 40;
  if (cube->state == 1 || cube->state == 3) {
    cube->unk_34 = 0;
  } else {
    cube->unk_34 = 40;
  }
  cube->hp = VM_GetNamedArgValue('l', 1);
  cube->unk_40 = 0;
  cube->flashTimer = 0;

  Video_GetAuxSprite(&cube->gfx, SPRITE_PROPERTY_CUBE);
  PropertyCube_ApplyPltt(p, cube);
  AuxSprite_Add(&cube->spr_a8, &cube->gfx, 0);
  cube->spr_a8.poseIdx = 0;
  cube->spr_a8.pos = pos;
  cube->spr_a8.pos.y += cube->unk_34;
  Video_GetAuxSprite(&cube->gfx2, SPRITE_PROPERTY_CUBE);
  AuxSprite_Add(&cube->spr_f0, &cube->gfx2, SPRFLAG_BLINK_ODD);
  cube->spr_f0.poseIdx = 1;
  cube->spr_f0.pos = pos;

  {
    s32 idx = GetCollisionTileIdx(&pos);
    s32 height = TileAtIndex(idx)->heightStairs & 0xF;

    if (height < 15) {
      height++;
    }
    Map_AddTileOverride(&cube->tileOverride, idx, 0, height, 0xFF, TATTR_UNK_0 | TATTR_UNK_3);
  }
  cube->tileOverride.flags |= 2;

  Mover_Init(&cube->obj, id, &pos, 0, 7, cube);
  Mover_SetAuxSprite(&cube->obj, &cube->spr_a8);
  if (cube->state != 1) {
    cube->obj.flags |= 2;
  }
  cube->zoneSource.id = cube->obj.id;
  cube->zoneSource.pos = &cube->obj.pos;

  halfSize.x = 0x82, halfSize.y = 0x80, halfSize.z = 0x82;
  offset.x = 0, offset.y = 0x80, offset.z = 0;
  Hitbox_Init(&cube->hurtbox, cube->obj.id, HBFLAG_HURTBOX | HBFLAG_UNK_6 | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(&cube->hurtbox, &cube->obj.pos, 0);
  Hitbox_SetHandler(&cube->hurtbox, PropertyCube_OnHurt, cube);
  Hitbox_Register(&cube->hurtbox);

  halfSize.x = 0x90, halfSize.y = 0x80, halfSize.z = 0x90;
  Hitbox_Init(&cube->hitbox, cube->obj.id, HBFLAG_HITBOX | HBFLAG_UNK_11 | HBFLAG_UNK_0, 0, HIM_0, &halfSize, &offset);
  Hitbox_SetPos(&cube->hitbox, &cube->obj.pos, 0);
  Hitbox_SetHandler(&cube->hitbox, nop_0800cc04, cube);
  Hitbox_SetPower(&cube->hitbox, 50, 0);
  cube->hitbox.weakness = 0x10100;
  cube->hitbox.attributes = HBATTR_FLAME;

  if (!TEST_FLAGS(cube->unk_28, 1)) {
    if (FUN_08002a48(&cube->obj) < 0) {
      cube->unk_28 |= 1;
    }
  }

  cube->active = TRUE;
  return 0;
#else
  INCFUNC("asm/func/Cmd_A062.inc");
#endif
}
