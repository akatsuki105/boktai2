#include "boss.h"
#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// 紅のリンゴ, ダーイン (グラフィックが同じ2つのボスが両方ともこの構造体を使うと考えられる)
// リンゴ (人名)
typedef struct {
  Boss base;                              // 0x000
  u8 unk_158[0x15C - 0x158];              // 0x158
  u16 phaseTimer;                         // 0x15C, 状態の中の段階を進めるたびに 0 に戻すカウンタ
  u16 phase;                              // 0x15E, 状態の中の段階, 状態関数が switch で振り分けて進める
  s16 spriteOffsetY;                      // 0x160, sprites[0].pos.y = mover.pos.y + spriteOffsetY
  s16 hoverHeight;                        // 0x162, Ringo_UpdateHover が 62 まで増やして sin の揺れを足し spriteOffsetY にする
  s16 unk_164;                            // 0x164
  u8 hitBySol;                            // 0x166, Ringo_OnHurt が HBATTR_SOL の攻撃で立てる
  u8 unk_167;                             // 0x167
  u8 unk_168;                             // 0x168
  u8 unk_169;                             // 0x169
  u8 unk_16a;                             // 0x16A
  u8 numPlayers;                          // 0x16B, '.P=2', base.players / playerPos を埋める数
  u8 unk_16c;                             // 0x16C, 3..6 の乱数
  u8 unk_16d;                             // 0x16D
  u8 unk_16e;                             // 0x16E, 乱数
  u8 unk_16f;                             // 0x16F, 0 になったら unk_16e / unk_16c を引き直す
  u8 unk_170;                             // 0x170
  u8 unk_171;                             // 0x171
  u8 unk_172;                             // 0x172
  s8 grabbedPlayer;                       // 0x173, base.players の添字
  s8 unk_174;                             // 0x174
  u8 unk_175;                             // 0x175
  u8 unk_176;                             // 0x176
  u8 unk_177;                             // 0x177
  u8 unk_178;                             // 0x178, hurtbox2 に当たったとき BOSSFLAG_UNK_19 が立っていれば 1
  u8 hurtAngle;                           // 0x179, Ringo_OnHurt が攻撃の向きを入れる
  u8 unk_17a;                             // 0x17A
  u8 unk_17b;                             // 0x17B
  u16 unk_17c;                            // 0x17C
  u16 unk_17e;                            // 0x17E
  s16 damage;                             // 0x180, 受けたダメージ, Ringo_HandleDamage が取り出して 0 に戻す
  s16 unk_182;                            // 0x182, FUN_08029864 が足す
  u16 unk_184;                            // 0x184, FUN_080298b8 が足す
  u16 unk_186;                            // 0x186
  u16 unk_188;                            // 0x188
  u8 unk_18a;                             // 0x18A
  u8 unk_18b;                             // 0x18B
  u16 unk_18c;                            // 0x18C
  u8 unk_18e[0x194 - 0x18E];              // 0x18E
  HitboxData hitbox;                      // 0x194
  HitboxData hurtbox;                     // 0x1E4, ハンドラは Ringo_OnHurt
  HitboxData hitbox2;                     // 0x234
  HitboxData hurtbox2;                    // 0x284, ハンドラ FUN_0802802c はダメージを 0 にする
  MainSpriteGfx gfx;                      // 0x2D4, SPRITE_RINGO
  MainSprite sprites[2];                  // 0x2F4
  AuxShadow shadow;                       // 0x3B4
  rgb555 pltt[16][16];                    // 0x420, gObjPlttData の同じ16色を16回写す
  rgb555 pltt_620[2][16];                 // 0x620
  rgb555 pltt_660[14][16];                // 0x660, BlendPltt で色を混ぜる先
  u32 unk_820;                            // 0x820, '.S=0'
  u32 unk_824;                            // 0x824, '.R=0'
  s32 unk_828;                            // 0x828, 24.8 固定小数点
  s32 unk_82c;                            // 0x82C, unk_828 の補間の終点
  s32 unk_830;                            // 0x830, unk_828 の補間の始点
  s32 unk_834;                            // 0x834, 24.8 固定小数点
  s32 unk_838;                            // 0x838, unk_834 の補間の終点
  s32 unk_83c;                            // 0x83C, unk_834 の補間の始点
  u16 unk_840;                            // 0x840, 補間の経過フレーム数
  u16 unk_842;                            // 0x842, 補間のフレーム数
  Vec3 unk_844;                           // 0x844
  Vec3 unk_84c;                           // 0x84C
  Vec3 unk_854;                           // 0x854
  Vec3 unk_85c;                           // 0x85C
  u32 unk_864;                            // 0x864
  Vec3 unk_868;                           // 0x868
  u16 unk_870;                            // 0x870
  u8 unk_872;                             // 0x872
  u8 unk_873;                             // 0x873
  s16 unk_874;                            // 0x874
  u8 unk_876;                             // 0x876
  u8 unk_877;                             // 0x877
  s16 plttFade;                           // 0x878, BlendPltt の混ぜ具合
  u16 plttFadeTo;                         // 0x87A, フェード先のパレット番号
  s8 plttFadeMode;                        // 0x87C, パレットフェードの種類, -1 で止まる
  u8 unk_87d;                             // 0x87D
  bool8 unk_87e;                          // 0x87E, 0x313 / 0x33D の効果音を鳴らしたら立つ
  u8 unk_87f;                             // 0x87F
  bool8 unk_880;                          // 0x880
  u8 unk_881[0x884 - 0x881];              // 0x881
  u16 unk_884;                            // 0x884, プレイヤーとの距離 / 32 へ毎フレーム 1 ずつ寄せる
  u16 unk_886;                            // 0x886
  u16 unk_888;                            // 0x888
  u16 unk_88a;                            // 0x88A
  u16 unk_88c;                            // 0x88C
  u8 unk_88e[0x891 - 0x88E];              // 0x88E
  u8 unk_891;                             // 0x891
  u8 unk_892;                             // 0x892
  u8 unk_893;                             // 0x893
  u16 unk_894;                            // 0x894
  u16 unk_896;                            // 0x896
  u8 unk_898;                             // 0x898
  u8 targetPlayer;                        // 0x899, 狙うプレイヤーの添字 (0/1), playerAngle / playerPos を引く
  u8 unk_89a[0x89C - 0x89A];              // 0x89A
  u16 stateDuration;                      // 0x89C, 状態を続ける最短フレーム数
  u8 unk_89e[0x8A0 - 0x89E];              // 0x89E
  u16 hurtboxPower;                       // 0x8A0, '.s[1]=999'
  u16 hurtboxPower2;                      // 0x8A2, '.s[2]=10'
  u16 hurtboxPower3;                      // 0x8A4, '.s[3]=100'
  u8 unk_8a6[0x8A8 - 0x8A6];              // 0x8A6
  s16 hitboxPower;                        // 0x8A8, '.a[0]=25'
  s16 hitboxKnockback;                    // 0x8AA, '.a[1]=50'
  s16 hitboxUnk44;                        // 0x8AC, '.a[2]=60'
  s16 hitbox2Power;                       // 0x8AE, '.a[3]=50'
  s16 hitbox2Knockback;                   // 0x8B0, '.a[4]=50'
  s16 hitbox2Unk44;                       // 0x8B2, '.a[5]=60'
  u16 unk_8b4;                            // 0x8B4, '.g[0]=70'
  u16 unk_8b6;                            // 0x8B6, '.g[1]=80'
  u16 unk_8b8;                            // 0x8B8, '.g[2]=65'
  u16 unk_8ba;                            // 0x8BA, '.U[0]=40'
  u16 unk_8bc;                            // 0x8BC, '.U[1]=80'
  u16 unk_8be;                            // 0x8BE, '.U[2]=50'
  u16 unk_8c0;                            // 0x8C0, '.U[3]=30'
  u16 unk_8c2;                            // 0x8C2
  u16 unk_8c4;                            // 0x8C4, '.a[6]=8'
  u16 unk_8c6;                            // 0x8C6, '.a[7]=16'
  u16 unk_8c8;                            // 0x8C8, '.a[8]=10'
  u16 unk_8ca;                            // 0x8CA, '.a[9]=50'
  u8 unk_8cc;                             // 0x8CC
  u8 unk_8cd;                             // 0x8CD
  u16 unk_8ce;                            // 0x8CE
  u16 unk_8d0;                            // 0x8D0
  u16 unk_8d2;                            // 0x8D2, '.s[4]=300'
  u16 unk_8d4;                            // 0x8D4
  u16 unk_8d6;                            // 0x8D6, '.s[5]=600'
  s16 unk_8d8;                            // 0x8D8
  u8 unk_8da;                             // 0x8DA
  u8 unk_8db;                             // 0x8DB
  u8 unk_8dc;                             // 0x8DC
  u8 unk_8dd;                             // 0x8DD
  u8 unk_8de[0x8E0 - 0x8DE];              // 0x8DE
  s32 weaponExp;                          // 0x8E0, '.K'
  u16 unk_8e4;                            // 0x8E4
  u16 unk_8e6;                            // 0x8E6
  u16 unk_8e8[3];                         // 0x8E8, sprites_8f4 ごとの残りフレーム, 0 になったら隠す
  u16 unk_8ee[3];                         // 0x8EE, sprites_8f4 ごと, 1 なら unk_868 へ寄せる
  MainSprite sprites_8f4[3];              // 0x8F4
  s16 unk_a14;                            // 0xA14, 前のフレームの unk_a16
  s16 unk_a16;                            // 0xA16, sprites[0].animCmdIdx の控え
  Vec3 unk_a18;                           // 0xA18
  MainSpriteGfx gfx_a20;                  // 0xA20, SPRITE_DJANGO_SABATA
  MainSprite sprite_a40;                  // 0xA40
  MainSprite sprite_aa0;                  // 0xAA0
  u8 unk_b00;                             // 0xB00
  u8 unk_b01;                             // 0xB01
  u8 unk_b02;                             // 0xB02
  s8 unk_b03;                             // 0xB03
  u16 unk_b04;                            // 0xB04
  u16 unk_b06;                            // 0xB06
  ParticleShadow ptclShadow;              // 0xB08
  AuxSpriteGfx auxGfx[2];                 // 0xB48, SPRITE_3668
  bool8 auxActive[16];                    // 0xB80, auxSprites の各枠が使用中か
  AuxSprite auxSprites[16];               // 0xB90
  AuxAnimState auxAnims[16];              // 0xE50, auxSprites と同じ添字
  Vec3 auxOffsets[16];                    // 0xF50, auxSprites の画面上の位置のずれ
  AuxAnimFile* auxAnimFile;               // 0xFD0, ANIM_78E1
  u8 unk_fd4;                             // 0xFD4
  u8 unk_fd5;                             // 0xFD5
  u8 unk_fd6;                             // 0xFD6
  u8 unk_fd7;                             // 0xFD7
  Vec3 unk_fd8;                           // 0xFD8, sprite_fe0 の位置
  MainSprite sprite_fe0;                  // 0xFE0
  u16 scriptID;                           // 0x1040, '.d[0]=0'
  u16 scriptID2;                          // 0x1042, '.d[1]=0'
  u32 unk_1044;                           // 0x1044
  u32 unk_1048;                           // 0x1048
  struct Entity0805a31c* entity0805a31c;  // 0x104C
  struct Entity0805b068* entity0805b068;  // 0x1050
  struct Entity0805b790* entity0805b790;  // 0x1054
  struct Entity0805d364* entity0805d364;  // 0x1058
} Ringo;
static_assert(sizeof(Ringo) == 4188);

void FUN_0805d5d4(struct Entity0805d364* p);
void FUN_0805b0b0(struct Entity0805b068* p, Vec3* pos, Vec3* target, s32 angle, s32 param_5, u32 param_6);
void FUN_0805d3a8(struct Entity0805d364* p, Vec3* from, Vec3* to, s32 param_4, s32 param_5);
bool32 FUN_0809df78(Vec3* pos);
void FUN_080846f8(void);
void FUN_08084734(Vec3* out);
bool32 FUN_08084710(void);
void FUN_0823b880(s32 n);
struct Entity0805a31c* Entity0805a31c_Create(u32 attackID);
struct Entity0805b068* Entity0805b068_Create(u32 param_1, u32 param_2);
struct Entity0805d364* Entity0805d364_Create(u32 count);
struct Entity0805b790* Entity0805b790_Create(u32 kind);
s32 FUN_08035a64(Ringo* p);
void FUN_0805b1a0(unknown* p);
void FUN_080846c8(void);
struct Entity080c0fa0* Entity080c0fa0_Create(Vec3* pos, SpriteID32 pltt, s32 poseIdx, s32 dir, s32 speed, s32 delay, s32 param_7);
s32 FUN_0805b7d4(struct Entity0805b790* p, Vec3* pos, Vec3* target, u32 kind, u32 angle, s32 speed, u32 param_7, u32 param_8);
s32 Entity08060470_Spawn(u8 angle, s32 speed, u16 radius, Vec3* pos);
void FUN_08015a90(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);
s32 FUN_0805a360(struct Entity0805a31c* p, Vec3* pos, u32 kind, Vec3* target, u32 param_5, u32 param_6);
s32 Player_HoldGrabbed(Player* p, Vec3* pos, Vec3* hitPos, s32 animOffset, s32 xflip, s32 flashPose, bool32 hidden, s32 power, HitboxAttributes attrs);
s32 Player_ReleaseGrabbed(Player* p, Vec3* pos, s32 knockbackPower, s32 angle, s32 invincibleTime, s32 flashPose, s32 power, HitboxAttributes attrs);
s32 FUN_080dc0a0(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority);
void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);

static inline void Ringo_StartPlttFade(Ringo* p, s32 mode, u32 plttID) {
  p->plttFadeMode = mode;
  p->plttFadeTo = plttID;
  if (p->plttFadeMode == 1) {
    p->plttFade = 31;
  } else if (p->plttFadeMode == 0) {
    p->plttFade = 0;
  } else {
    p->plttFade = 0;
  }
}

static inline u32 Ringo_SelectAnim(Ringo* p, u32 anim, u32 anim2) {
  if (p->base.isDemo) {
    return p->unk_824 == 0 ? anim : anim2;
  }
  return p->unk_820 != 0 ? anim2 : anim;
}

// hoverHeight を 62 まで増やし, それに timer の sin 揺れを足したものを spriteOffsetY にする
static inline void Ringo_UpdateHover(Ringo* p, s32 timer) {
  if (p->hoverHeight < 62) {
    p->hoverHeight += 2;
  }
  p->spriteOffsetY = p->hoverHeight + FixToInt(12, SIN(timer * 2) * 40);
  if (p->spriteOffsetY < 0) {
    p->spriteOffsetY = 0;
  }
}

static inline void Ringo_SetUnk169(Ringo* p, u32 value) { p->unk_169 = value; }

static inline void Ringo_SetSubState2Unk17b(Ringo* p, u32 subState, u32 unk_17b, u32 unk_17c) {
  Boss_SetSubState2(&p->base, subState);
  p->unk_17b = unk_17b;
  p->unk_17c = unk_17c;
}

static inline void Ringo_UpdateUnk88c(Ringo* p) {
  if (p->unk_820 != 0) {
    if (p->unk_88c > 2) {
      Ringo_SetUnk169(p, 5);
      FUN_0823585c(&p->unk_84c, &p->base.mover.pos, 3, 1, 0x100, NULL, NULL);
      p->unk_88c = 0;
      Boss_SetSubState2(&p->base, 2);
    } else {
      Boss_SetSubState2(&p->base, 3);
      p->unk_88c++;
      PlaySound_0824078c(SONG_784);
    }
  } else if (p->unk_88c > 2) {
    Ringo_SetUnk169(p, 5);
    FUN_0823585c(&p->unk_84c, &p->base.mover.pos, 3, 1, 0x100, NULL, NULL);
    p->unk_88c = 0;
    Boss_SetSubState2(&p->base, 2);
  } else {
    Ringo_SetSubState2Unk17b(p, 12, 1, 0x20);
    p->unk_88c++;
    PlaySound_0824078c(SONG_858);
  }
}

static inline void Ringo_SetUnk18a(Ringo* p, u32 value) { p->unk_18a = value; }

// 下位状態を最初に戻し, その状態を続ける最短フレーム数を決める
static inline void Ringo_ResetSubStates(Ringo* p, u32 duration) {
  Boss_SetSubStates(&p->base, 0, 0, 0);
  p->stateDuration = duration;
}

extern u16 gRisingSunCount;

const s8 s8_ARRAY_085aabbc[10][2] = {
    {9, -4},
    {9, -7},
    {7, -8},
    {7, -6},
    {7, -5},
    {7, -6},
    {7, -5},
    {7, -6},
    {7, -5},
    {7, -8}
};  // 0x085AABBC

// s8 かも?
const u8 u8_ARRAY_085aabd0[8] = {0x1, 0xE4, 0x0, 0xE0, 0x0, 0xE1, 0x2, 0xE8};  // 0x085AABD0

static const s8 s8_ARRAY_085aabd8[32][2] = {
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {2,   0 },
    {4,   2 },
    {6,   4 },
    {8,   6 },
    {9,   8 },
    {10,  10},
    {11,  12},
    {12,  14},
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   0 },
    {0,   4 },
    {0,   8 },
    {-4,  10},
    {-8,  12},
    {-10, 14},
    {-12, 16},
    {-14, 19},
    {-16, 23},
    {-18, 28},
    {-20, 32},
    {0,   0 },
    {0,   0 },
    {0,   0 },
};  // 0x085AABD8

// 本体のパレット番号を返す, パレットのフェードもこの番号へ戻す
// 残差は末尾の 0xC8 / 0xC3 の並び (25/25): 原典は unk_fd4 が立っているときの 0xC8 を最後に置く, if の向きを逆にする形, 三項演算子, 戻り値をローカルに置く形は試済
NON_MATCH u32 Ringo_GetPlttID(Ringo* p) {
#ifdef NONMATCHING_C
  if (p->base.isDemo) {
    switch (p->unk_824) {
      case 0: {
        break;
      }
      case 1: {
        return 0xC1;
      }
    }
  } else if (p->unk_fd4) {
    return 0xC8;
  }
  return 0xC3;
#else
  INCFUNC("asm/func/Ringo_GetPlttID.inc");
#endif
}

// 残差は unk_824 の 0 / 1 の比べ方と return 1 の位置 (29/31): 原典は 0 と 1 を別々に比べ, return 1 を最後に置く, case を分けた switch で比べ方は揃う
NON_MATCH s32 FUN_08027f10(Ringo* p) {
#ifdef NONMATCHING_C
  if (!p->base.isDemo) {
    if (p->unk_820 == 0) {
      return 1;
    }
    if (p->unk_fd4) {
      return 8;
    }
  } else {
    if (p->unk_824 == 0 || p->unk_824 == 1) {
      return 1;
    }
  }
  return 3;
#else
  INCFUNC("asm/func/FUN_08027f10.inc");
#endif
}

void Ringo_OnHurt(HitboxData* a, HitboxData* b, Ringo* p) {
  Boss* boss = &p->base;

  if (!TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_19)) {
    Hitbox_ApplyDamage(a, b);
    p->damage = b->damage;
    if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
      p->hurtAngle = a->angle;
    } else {
      p->hurtAngle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
    }
    Boss_SetWeaponExpMask(boss, a->weakness);
    Boss_SetHurtAttributes(boss, a->attributes);
    a->damage += boss->damageBonus;
  }
  if (TEST_FLAGS(a->attributes, HBATTR_SOL)) {
    p->hitBySol = TRUE;
  }
  if (b->hitResult & HBRESULT_BONUS) {
    p->unk_167 = TRUE;
    p->unk_177 = TRUE;
  } else {
    p->unk_177 = FALSE;
  }
}

// hurtbox2 に当たった攻撃のダメージを 0 にする
void FUN_0802802c(HitboxData* a, HitboxData* b, Ringo* p) {
  b->damage = 0;
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_19)) {
    p->unk_178 = TRUE;
  }
}

void FUN_08028050(void) {}

void Ringo_UnregisterHurtboxes(Ringo* p) {
  Hitbox_Unregister(&p->hurtbox);
  Hitbox_Unregister(&p->hurtbox2);
}

void Ringo_SetHurtboxPower(Ringo* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;

  p->base.hurtboxPower = power;
  hurtbox->power = power;
}

void FUN_08028084(Ringo* p) {
  u16* table = gRandomTable;

  p->unk_16e = _Random(table);
  p->unk_16c = (_Random(table) & 3) + 3;
}

// 残差は return FALSE の位置のみ (47/47): 原典は unk_888 を減らした直後に return FALSE を置いてリセット側を最後に置く, hpRatio は Boss_GetHPRatio を通すと符号付きの比較が揃う
NON_MATCH s32 FUN_080280cc(Ringo* p) {
#ifdef NONMATCHING_C
  if ((p->unk_820 != 0 || Boss_GetHPRatio(&p->base) <= 0x40) && p->unk_8dd) {
    if (p->unk_888 != 0) {
      p->unk_888--;
    } else {
      p->unk_888 = p->unk_8d2;
      p->unk_8dd = FALSE;
      Boss_SetSubState2(&p->base, 17);
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080280cc.inc");
#endif
}

s32 FUN_08028138(Ringo* p, Vec3* out) {
  Mover* mover = &p->base.mover;
  u32 dir = ((mover->angle - 0x20) & ~0x3F) + 0x40;

  Vec3_SetPolar(out, dir, 0xA4);
  if (dir == 0) {
    out->z -= 0x20;
  } else if (dir == 0x40) {
    out->x -= 0x20;
  } else if (dir == 0x80) {
    out->z += 0x20;
  } else if (dir == 0xC0) {
    out->x += 0x20;
  }
  Vec3_Add(out, &mover->pos);
}

// 1 回目で打ち切り (237/170), 矩形判定は FUN_08028720 と同じく 1 / 0 にしてから比べる形
NON_MATCH s32 FUN_080281ec(Ringo* p) {
#ifdef NONMATCHING_C
  if (p->unk_898 != 0) {
    if (--p->unk_898 == 0) {
      Boss_SetSubState2(&p->base, 4);
      p->unk_896 = p->unk_8d4;
      return TRUE;
    }
  } else if (p->unk_896 != 0) {
    p->unk_896--;
  } else {
    Vec3 ofs, min, max;
    s32 i;

    FUN_08028138(p, &ofs);
    min.x = p->hitbox2.offset.x + ofs.x;
    min.y = ofs.y + p->hitbox2.offset.y;
    min.z = ofs.z + p->hitbox2.offset.z;
    min.x -= p->hitbox2.halfSize.x;
    min.y -= p->hitbox2.halfSize.y;
    min.z -= p->hitbox2.halfSize.z;
    max.x = p->hitbox2.offset.x + ofs.x;
    max.y = ofs.y + p->hitbox2.offset.y;
    max.z = ofs.z + p->hitbox2.offset.z;
    max.x += p->hitbox2.halfSize.x;
    max.y += p->hitbox2.halfSize.y;
    max.z += p->hitbox2.halfSize.z;
    for (i = 0; i < p->numPlayers; i++) {
      Vec3* pos = p->base.playerPos[i];

      if (pos->x >= min.x && pos->x <= max.x && pos->y >= min.y && pos->y <= max.y && pos->z >= min.z && pos->z <= max.z) {
        p->unk_898 = 30;
        break;
      }
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080281ec.inc");
#endif
}

// 残差1命令 (18/18): 原典は 0x893 をプール定数で作るが, こちらは 0x820 から add #0x73 で作る, && / ネストした if も試済
NON_MATCH s32 FUN_0802835c(Ringo* p) {
#ifdef NONMATCHING_C
  if (p->unk_820 != 0 || p->unk_893 != 1) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_0802835c.inc");
#endif
}

// 残差は 0x80 - unk_884 を入れるレジスタのみ (100/100), 掛け算の順番とローカルに分ける形は試済
NON_MATCH void FUN_08028388(Ringo* p) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3* playerPos = p->base.playerPos[0];
  s32 dist = Sqrt(p->base.playerDistSq[0]) >> 5;
  s32 t;
  Vec3 pos;

  if (p->unk_884 > dist) {
    p->unk_884--;
  } else if (p->unk_884 < dist) {
    p->unk_884++;
  }
  t = FixToInt(7, (0x80 - p->unk_884) * p->unk_886);
  pos.x = playerPos->x - FixToInt(8, (playerPos->x - mover->pos.x) * t);
  pos.y = playerPos->y + 0x78;
  pos.z = playerPos->z - FixToInt(8, (playerPos->z - mover->pos.z) * t);
  Camera_MoveTo(&pos);
#else
  INCFUNC("asm/func/FUN_08028388.inc");
#endif
}

void FUN_08028474(Vec3* from, Vec3* to, u8* angle, u16* dist) {
  s32 dx = to->x - from->x;
  s32 dz = to->z - from->z;
  u32 distSq = dx * dx + dz * dz;

  if (distSq == 0) {
    *angle = 0;
    *dist = 0;
  } else {
    *angle = ArcTan2_8(dx, dz);
    *dist = Sqrt(distSq);
  }
}

void FUN_080284bc(Vec3* dst, Vec3* src, u8 angle, u16 radius) {
  Vec3 ofs;

  Vec3_SetPolar(&ofs, angle, radius);
  dst->x = src->x + ofs.x;
  dst->y = src->y + ofs.y;
  dst->z = src->z + ofs.z;
}

void FUN_0802853c(Ringo* p, Vec3* target, u32 duration) {
  u8 angle;
  u16 dist;
  s32 d;

  p->unk_84c = *target;
  FUN_08028474(&p->unk_844, &p->unk_84c, &angle, &dist);
  p->unk_82c = angle << 8;
  p->unk_838 = dist << 8;
  p->unk_840 = 0;
  p->unk_842 = duration;
  d = p->unk_82c - p->unk_828;
  if (abs(d) > 0x8000) {
    if (d < 0) {
      d += 0x10000;
    } else {
      d -= 0x10000;
    }
    p->unk_82c = p->unk_828 + d;
  }
  p->unk_830 = p->unk_828;
  p->unk_83c = p->unk_834;
}

void FUN_08028604(Ringo* p) {
  u8 a;
  u16 b;

  FUN_08028474(&p->unk_844, &p->base.mover.pos, &a, &b);
  p->unk_828 = a << 8;
  p->unk_834 = b << 8;
}

void FUN_08028648(Ringo* p) {
  s32 rest;

  p->unk_840++;
  rest = p->unk_842 - p->unk_840;
  p->unk_828 = Div(p->unk_830 * rest + p->unk_82c * p->unk_840, p->unk_842);
  p->unk_834 = Div(p->unk_83c * rest + p->unk_838 * p->unk_840, p->unk_842);
  if (p->unk_828 < 0) {
    p->unk_828 += 0x10000;
  }
  p->unk_828 = (u16)p->unk_828;
}

void FUN_080286d8(Ringo* p) { FUN_080284bc(&p->base.mover.pos, &p->unk_844, (u8)FixToInt(8, p->unk_828), (u16)(p->unk_834 >> 8)); }

// 残差は playerPos[i] のアドレスの作り方と矩形判定 (44/55): 原典は毎回 p + 0x10C + i * 4 を作り直し, 矩形の中かを 1 / 0 の値にしてから比べる, その形の bool32 を返す static inline で 54/55 まで縮む
NON_MATCH s32 FUN_08028720(Ringo* p, s32 count, Vec3* min, Vec3* max) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < count; i++) {
    Vec3* pos = p->base.playerPos[i];

    if (pos != NULL && pos->x >= min->x && pos->x <= max->x && pos->z >= min->z && pos->z <= max->z) {
      return i;
    }
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_08028720.inc");
#endif
}

// 残差は pltt の代入で値と番地を作る順番のみ (58/58): 原典は gObjPlttData を読んでから p + 0x93C + i * 0x60 を作る
NON_MATCH void FUN_08028790(Ringo* p, Vec3* pos) {
#ifdef NONMATCHING_C
  u32 plttID = p->unk_820 != 0 ? 0xC5 : 0xC7;
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites_8f4[i], &p->gfx, 0, SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD, 2, PLAYMODE_PAUSE, 60, pos);
    p->sprites_8f4[i].plttID = 0x4100;
    p->sprites_8f4[i].pltt = &gObjPlttData[plttID * 16];
  }
#else
  INCFUNC("asm/func/FUN_08028790.inc");
#endif
}

void FUN_08028818(Ringo* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->sprites_8f4[i]);
  }
}

// 残差は plttID を受けるレジスタと gObjPlttData の読み込み位置 (126/126)
NON_MATCH void FUN_08028838(Ringo* p, s32 kind, u32 duration) {
#ifdef NONMATCHING_C
  u32 plttID;

  p->sprites_8f4[p->unk_8e6].flags &= ~SPRFLAG_HIDDEN;
  FUN_0822f588(&p->sprites_8f4[p->unk_8e6], &p->sprites[0], 9);
  if (p->unk_8e6 & 1) {
    p->sprites_8f4[p->unk_8e6].flags |= SPRFLAG_BLINK_ODD;
  } else {
    p->sprites_8f4[p->unk_8e6].flags |= SPRFLAG_BLINK_EVEN;
  }
  p->sprites_8f4[p->unk_8e6].pos = p->sprites[0].pos;
  p->unk_8ee[p->unk_8e6] = duration;
  p->unk_8e8[p->unk_8e6] = 12;
  switch (kind) {
    case 1: {
      plttID = 0xC8;
      break;
    }
    case 0:
    default: {
      plttID = Ringo_GetPlttID(p);
      break;
    }
  }
  p->sprites_8f4[p->unk_8e6].pltt = &gObjPlttData[plttID * 16];
  if (++p->unk_8e6 > 2) {
    p->unk_8e6 = 0;
  }
  p->unk_8e4 = 0;
#else
  INCFUNC("asm/func/FUN_08028838.inc");
#endif
}

// src を dy だけ上下にずらした位置を dst に入れる
void FUN_08028960(Ringo* p) {
  Vec3 target;
  s32 i;

  Vec3_CopyOffsetY(&target, &p->unk_868, -0x80);
  for (i = 0; i < 3; i++) {
    if (p->unk_8e8[i] != 0) {
      if (p->unk_8ee[i] == 1) {
        LerpVec3(&p->sprites_8f4[i].pos, &p->sprites_8f4[i].pos, &target, 16, 6);
      }
      if (--p->unk_8e8[i] == 0) {
        p->sprites_8f4[i].flags |= SPRFLAG_HIDDEN;
      }
    }
  }
  p->unk_8e4++;
}

// 1 回目で打ち切り (111/109), 原典は乱数の添字の番地をループの外に出し, 乱数表の番地は毎回読み直す
NON_MATCH void FUN_08028a04(Ringo* p) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3 ofs;
  s32 i;

  if (p->base.facing <= 1) {
    VEC3_SET(ofs, Q8(0.25), Q8(0.782), Q8(-0.5));
  } else {
    VEC3_SET(ofs, Q8(-0.5), Q8(0.782), Q8(0.25));
  }
  for (i = 0; i < 4; i++) {
    Vec3 pos;

    pos.x = ofs.x + (Random() & 0x7F) - 0x40;
    pos.y = ofs.y;
    pos.z = ofs.z + (Random() & 0x7F) - 0x40;
    FUN_080dc0a0(&mover->pos, &pos, NULL, NULL, 1, 1);
  }
#else
  INCFUNC("asm/func/FUN_08028a04.inc");
#endif
}

// 1 回目で打ち切り, 残差はスタックの退避先 (sprite と回数) とレジスタ (119/119)
NON_MATCH void FUN_08028b00(Ringo* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprites[0];
  Vec3 size;
  s32 i;

  for (i = 0; i < 3; i++) {
    u16* table;
    u32 angle;
    s32 speed;
    s32 velYMax;

    VEC3_SET(size, Q8(0.641), Q8(0.063), Q8(0.641));
    table = gRandomTable;
    angle = _Random(table) & 0xFF;
    speed = (_Random(table) & 3) + 2;
    velYMax = (_Random(table) & 3) + 20;
    EmitSmoke(&sprite->pos, 3, &size, angle, speed, velYMax, 2, 2);
    angle = _Random(table) & 0xFF;
    speed = (_Random(table) & 3) + 2;
    velYMax = (_Random(table) & 3) + 20;
    EmitSmoke(&sprite->pos, 3, &size, angle, speed, velYMax, 2, 2);
  }
#else
  INCFUNC("asm/func/FUN_08028b00.inc");
#endif
}

void FUN_08028c04(Ringo* p) {
  MainSprite* sprite = &p->sprites[0];
  Vec3 size;
  s32 i;

  for (i = 0; i < 2; i++) {
    u16* table;
    u32 angle;
    s32 speed;
    s32 velYMax;

    VEC3_SET(size, Q8(0.641), Q8(0.063), Q8(0.641));
    table = gRandomTable;
    angle = (u8)_Random(table);
    speed = (_Random(table) & 3) + 2;
    velYMax = (_Random(table) & 3) + 20;
    EmitSmoke(&sprite->pos, 3, &size, angle, speed, velYMax, 2, 2);
  }
}

// 1 回目で打ち切り (122/124), 残差は定数のレジスタ割り当て
NON_MATCH void FUN_08028cb0(Ringo* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3 size;
  s32 i;

  Vec3_CopyOffsetY(&pos, &p->sprites[0].pos, 0x40);
  for (i = 0; i < 3; i++) {
    u16* table;
    u32 angle;
    s32 speed;
    s32 velYMax;

    VEC3_SET(size, Q8(1), Q8(0.063), Q8(1));
    table = gRandomTable;
    angle = _Random(table) & 0xFF;
    speed = (_Random(table) & 3) + 2;
    velYMax = (_Random(table) & 3) + 20;
    EmitSmoke(&pos, 3, &size, angle, speed, velYMax, 2, 2);
    angle = _Random(table) & 0xFF;
    speed = (_Random(table) & 3) + 2;
    velYMax = (_Random(table) & 3) + 20;
    EmitSmoke(&pos, 3, &size, angle, speed, velYMax, 2, 2);
  }
#else
  INCFUNC("asm/func/FUN_08028cb0.inc");
#endif
}

// SPRITE_DJANGO_SABATA を開き, sprite_a40 を隠した状態で本体の位置に用意する
void FUN_08028dbc(Ringo* p) {
  MainSprite* sprite = &p->sprite_a40;
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
  Vec3 pos;
  Vec3* vp;

  p->gfx_a20 = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx_a20, f);
  pos = p->sprites[0].pos;
  vp = &p->sprite_a40.pos;
  WorldToScreen(vp, &pos);
  MainSprite_Add(sprite, &p->gfx_a20, 0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 2, PLAYMODE_PAUSE, 60, &pos);
}

void FUN_08028eb8(Ringo* p) { MainSprite_Remove(&p->sprite_a40); }

s32 FUN_08028ec8(Ringo* p) {
  s32 id;

  if (p->grabbedPlayer == 0) {
    id = p->base.players[p->grabbedPlayer]->kind == PLAYER_SOLAR_DJANGO ? 0x30 : 0xF7;
  } else {
    id = 0x1CE;
  }
  return id;
}

// 残差はスタック枠とレジスタ (262/270), 原典は pos と pos2 に別の枠を取り p の複写を playerPos の添字計算に使う
NON_MATCH void FUN_08028f08(Ringo* p) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3 pos;
  Vec3 pos2;
  s32 i;

  if (p->entity0805a31c == NULL) {
    return;
  }
  if (p->unk_174 < 0) {
    p->unk_174 = 0;
  }
  if (p->unk_174 == 0) {
    u32 idx;
    u32 delay;
    u32 angle;

    if (p->unk_864) {
      idx = 1;
    } else {
      idx = p->targetPlayer;
    }
    delay = 0;
    angle = Random() & 0xC0;
    for (i = 2; i >= 0; i--) {
      Vec3_SetPolar(&pos, angle, 400);
      Vec3_Add(&pos, p->base.playerPos[idx]);
      pos.y = mover->pos.y + 0xA4;
      ArcTan2_8(p->base.playerPos[idx]->x - pos.x, p->base.playerPos[idx]->z - pos.z);
      FUN_0805a360(p->entity0805a31c, &pos, 0, p->base.playerPos[idx], 15, delay);
      angle += 0x55;
      delay += 64;
    }
  } else {
    u32 idx = p->targetPlayer;
    u32 angle = Angle_FromDir8(p->base.dir) - 0x30;
    u32 delay = 0;

    for (i = 6; i >= 0; i--) {
      Vec3_SetPolar(&pos2, angle, 256);
      Vec3_Add(&pos2, &mover->pos);
      pos2.y += 0xA4;
      FUN_0805a360(p->entity0805a31c, &pos2, 1, p->base.playerPos[idx], 12, delay);
      delay += 24;
      angle += 16;
    }
  }
  p->unk_174 = -1;
#else
  INCFUNC("asm/func/FUN_08028f08.inc");
#endif
}

// 1 回目で打ち切り (145/152)
NON_MATCH void FUN_08029164(Ringo* p, s32 idx) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;

  if (p->entity0805b068 != NULL) {
    u32 angle = Random() & 0x1F;
    s32 i;

    for (i = 0; i < 3; i++) {
      Vec3* target = p->base.playerPos[idx];
      Vec3 pos;
      s32 dir;

      Vec3_SetPolar(&pos, angle, 0x100);
      pos.x += mover->pos.x;
      pos.z += mover->pos.z;
      pos.y = mover->pos.y + 0xA4;
      angle += 0x56;
      dir = ArcTan2_8(target->x - pos.x, target->z - pos.z) + (Random() & 0x1F) - 0x10;
      FUN_0805b0b0(p->entity0805b068, &pos, target, dir, 15, p->unk_8be);
    }
  }
#else
  INCFUNC("asm/func/FUN_08029164.inc");
#endif
}

// 1 回目で打ち切り (444/385), 原典は向きの分岐と kind の分岐の末尾を共有して短い
NON_MATCH void FUN_080292c8(Ringo* p, s32 kind) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3 pos = mover->pos;
  Vec3 smokePos = mover->pos;
  Vec3 size;
  u32 angle;

  switch (p->base.facing) {
    case 0: {
      pos.y += 0x100;
      pos.z -= 0xA0;
      smokePos.z -= 0x60;
      break;
    }
    case 1: {
      pos.y += 0xF0;
      pos.x += 0x80;
      smokePos.x += 0x40;
      break;
    }
    case 2: {
      pos.y += 0xF0;
      pos.z += 0x80;
      smokePos.z += 0x40;
      break;
    }
    case 3: {
      pos.y += 0x100;
      pos.x -= 0xA0;
      smokePos.x -= 0x60;
      break;
    }
  }
  smokePos.y = pos.y - 0x20;
  VEC3_SET(size, Q8(0.25), Q8(0.25), Q8(0.25));
  angle = mover->angle + 0x80;
  EmitSmoke(&smokePos, (Random() & 1) + 2, &size, angle + (Random() & 0x1F) - 0x10, (Random() & 3) + 4, (Random() & 1) + 1, 2, 1);
  EmitSmoke(&smokePos, (Random() & 1) + 2, &size, angle + (Random() & 0x1F) - 0x10, (Random() & 3) + 4, (Random() & 1) + 1, 2, 1);
  switch (kind) {
    case 0: {
      FUN_0805b7d4(p->entity0805b790, &pos, p->base.playerPos[p->targetPlayer], 0, p->unk_8da, 32, p->unk_8b4, 10);
      PlaySound_0824078c(SE_GUN_FIRE);
      break;
    }
    case 1: {
      FUN_0805b7d4(p->entity0805b790, &pos, p->base.playerPos[p->targetPlayer], 1, mover->angle, 24, p->unk_8b6, 10);
      PlaySound_0824078c(SE_GUN_FIRE);
      break;
    }
    case 2: {
      FUN_0805b7d4(p->entity0805b790, &pos, p->base.playerPos[p->targetPlayer], 2, p->unk_8da - 0x20, 24, p->unk_8b8, 10);
      FUN_0805b7d4(p->entity0805b790, &pos, p->base.playerPos[p->targetPlayer], 2, p->unk_8da, 24, p->unk_8b8, 10);
      FUN_0805b7d4(p->entity0805b790, &pos, p->base.playerPos[p->targetPlayer], 2, p->unk_8da + 0x20, 24, p->unk_8b8, 10);
      PlaySound_0824078c(SE_GUN_FIRE);
      break;
    }
    case 3: {
      Entity080c0fa0_Create(&pos, 0x2C, 2, Angle_ToDir8(p->unk_8da), 32, 0, p->unk_8cc);
      PlaySound_0824078c(SONG_837);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080292c8.inc");
#endif
}

// 1 回目で打ち切り (225/209)
NON_MATCH void FUN_08029628(Ringo* p) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3* playerPos = p->base.playerPos[p->targetPlayer];
  u32 angle = ArcTan2_8(p->unk_868.x - playerPos->x, p->unk_868.z - playerPos->z) & ~0x3F;
  Vec3 pos;
  s32 d;
  u8 a;

  Vec3_SetPolar(&pos, angle, 0x300);
  playerPos = p->base.playerPos[p->targetPlayer];
  pos.x = playerPos->x + pos.x;
  pos.y = pos.y + playerPos->y;
  pos.z = playerPos->z + pos.z;
  a = ArcTan2_8(p->unk_868.x - mover->pos.x, p->unk_868.z - mover->pos.z);
  d = (s8)a - (s8)ArcTan2_8(p->unk_868.x - pos.x, p->unk_868.z - pos.z);
  if (abs(d) < 32) {
    angle += 0x40;
  }
  Vec3_SetPolar(&p->unk_84c, angle, 0x300);
  playerPos = p->base.playerPos[p->targetPlayer];
  p->unk_84c.x = playerPos->x + p->unk_84c.x;
  p->unk_84c.y = playerPos->y + p->unk_84c.y;
  p->unk_84c.z = playerPos->z + p->unk_84c.z;
#else
  INCFUNC("asm/func/FUN_08029628.inc");
#endif
}

void FUN_080297fc(Vec3* pos) {
  Ringo* p = Boss_Get(BOSS_RINGO);

  if (p != NULL) {
    Boss_SetSubStates(&p->base, 0, 0, 29);
    p->base.mover.pos = *pos;
    PlaySound_0824078c(SONG_839);
  }
}

void FUN_08029840(void) {
  Ringo* p = Boss_Get(BOSS_RINGO);

  if (p != NULL && p->entity0805d364 != NULL) {
    FUN_0805d5d4(p->entity0805d364);
  }
}

void FUN_08029864(s32 n) {
  if (n > 0) {
    Ringo* p = Boss_Get(BOSS_RINGO);

    if (p != NULL) {
      s32 d;

      p->unk_182 += n;
      d = p->base.hp - p->unk_182;
      if (d <= 1 || abs(d - p->unk_8d8) < 50) {
        FUN_08029840();
      }
    }
  }
}

void FUN_080298b8(s32 n) {
  if (n > 0) {
    Ringo* p = Boss_Get(BOSS_RINGO);

    if (p != NULL) {
      p->unk_184 += n;
    }
  }
}

u32 FUN_080298dc(void) {
  Ringo* p = Boss_Get(BOSS_DAINN);

  return p != NULL ? TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_22) : 0;
}

void FUN_080298fc(Ringo* p) {
  p->unk_fd4 = TRUE;
  Ringo_SetHurtboxPower(p, p->hurtboxPower3);
}

// 残差は乱数オフセットの足し方 (89/87): 原典は pos.x を符号なしで読んで - 0x80 してから乱数を足す, (u16)pos.x にすると命令数は揃う, duneyrr.c の同形と同じ壁
NON_MATCH void FUN_0802991c(Ringo* p) {
#ifdef NONMATCHING_C
  Vec3 pos = p->sprites[0].pos;
  u16* table = gRandomTable;

  pos.x = pos.x - 0x80 + (u8)_Random(table);
  pos.y = pos.y + (_Random(table) & 0x3F);
  pos.z = pos.z - 0x80 + (u8)_Random(table);
  FUN_08015d3c(&pos, 2, 0x3000, 0x40, 12, 4, 0, 3);
#else
  INCFUNC("asm/func/FUN_0802991c.inc");
#endif
}

s32 FUN_080299e0(Ringo* p) {
  if (gRisingSunCount != 0) {
    return 4;
  }
  if (FUN_0809df78(&p->base.mover.pos)) {
    return gStat->sunGauge;
  }
  return 0;
}

// 残差は unk_ab が立っているときの分岐の向きのみ (60/60): 原典は unk_824 != 2 で末尾へ飛び, そうでなければ鳴らす側へ b で飛ぶ, if をネストして return する形, bool を返す static inline は試済
NON_MATCH void FUN_08029a1c(Ringo* p, s32 n) {
#ifdef NONMATCHING_C
  if (n > 0x5F) {
    if (p->base.isDemo ? p->unk_824 == 2 : (p->unk_820 != 0 && p->unk_fd4)) {
      PlaySound_0824078c(SONG_840);
    }
  } else if (n > 0x3F) {
    if (p->base.isDemo ? p->unk_824 == 2 : (p->unk_820 != 0 && p->unk_fd4)) {
      PlaySound_0824078c(SONG_841);
    }
  } else {
    PlaySound_0824078c(SE_842);
  }
#else
  INCFUNC("asm/func/FUN_08029a1c.inc");
#endif
}

void FUN_08029ab8(Ringo* p) {
  MainSprite* sprite = &p->sprite_fe0;
  Vec3 pos;

  Vec3_Clear(&pos);
  MainSprite_Add(sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(sprite, &p->gfx, 22, PLAYMODE_ONCE_AND_STOP, 0);
  p->unk_fd5 = FALSE;
  p->unk_fd6 = FALSE;
}

void FUN_08029b30(Ringo* p) { MainSprite_Remove(&p->sprite_fe0); }

void FUN_08029b40(Ringo* p) {
  MainSprite* sprite = &p->sprite_fe0;

  if (p->unk_fd4) {
    p->sprite_fe0.pos = p->unk_fd8;
    MainSprite_Show(sprite);
    MainSprite_AdvanceAnim(sprite, &p->gfx);
    if (p->unk_fd6) {
      u32 angle = Random();

      sprite->pos.x += POLAR_X(12, angle);
      sprite->pos.z += POLAR_Z(12, angle);
    }
    if (p->unk_fd5 && sprite->animCmdIdx == 10) {
      sprite->animCmdIdx = 2;
    }
  } else {
    MainSprite_Hide(sprite);
  }
}

// 残差1命令 (31/30): 原典は plttID に入れた 0xC1 のレジスタを lsls #5 して gObjPlttData の添字に使い回すが, こちらは作り直す, static inline の引数にしても変わらない
NON_MATCH void FUN_08029c2c(Ringo* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprite_fe0;

  MainSprite_SetAnim(sprite, &p->gfx, 22, PLAYMODE_LOOP, 0);
  sprite->plttID = 0xC1;
  sprite->pltt = &gObjPlttData[0xC1 * 16];
  p->unk_fd4 = TRUE;
#else
  INCFUNC("asm/func/FUN_08029c2c.inc");
#endif
}

void FUN_08029c74(Ringo* p) {
  MainSprite* sprite = &p->sprite_fe0;

  MainSprite_SetAnim(sprite, &p->gfx, 72, PLAYMODE_LOOP, 0);
  sprite->plttID = 0xC3;
  sprite->pltt = &gObjPlttData[0xC3 * 16];
  p->unk_fd5 = TRUE;
  p->unk_fd6 = FALSE;
}

// 残差は FUN_08029c2c と同じ (35/34): 原典は plttID に入れた 0xC1 のレジスタを lsls #5 して使い回す
NON_MATCH void FUN_08029cc8(Ringo* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprite_fe0;

  MainSprite_SetAnim(sprite, &p->gfx, 22, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  sprite->plttID = 0xC1;
  sprite->pltt = &gObjPlttData[0xC1 * 16];
  p->unk_fd5 = FALSE;
  p->unk_fd6 = TRUE;
#else
  INCFUNC("asm/func/FUN_08029cc8.inc");
#endif
}

void Ringo_InitAuxSprites(Ringo* p) {
  AuxSprite* sprite;
  s32 i;

  for (i = 0; i < 2; i++) {
    Video_GetAuxSprite(&p->auxGfx[i], SPRITE_3668);
  }
  Video_SetAuxSpritePltt(&p->auxGfx[0], 196);
  Video_SetAuxSpritePltt(&p->auxGfx[1], 200);
  p->auxAnimFile = GetFile(DIR_ANIMATION, ANIM_78E1);
  for (i = 0, sprite = p->auxSprites; i < 16; i++, sprite++) {
    AuxSprite_Add(sprite, &p->auxGfx[0], SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    AuxAnim_SetAnim(&p->auxAnims[i], p->auxAnimFile, 2, 0, 0);
    AuxAnim_SetAnimSpeed(&p->auxAnims[i], 32);
    sprite->priority = 1;
    Vec3_Clear(&sprite->pos);
  }
}

void Ringo_RemoveAuxSprites(Ringo* p) {
  s32 i;

  AuxSprite* sprite = p->auxSprites;

  for (i = 0; i < 16; i++, sprite++) {
    AuxSprite_Remove(sprite);
  }
}

// 253/253命令 (12 hunk), 手動送りは AuxSprite_AdvanceAnim で揃い vp / pos の初期化順も合わせた, 残差はループ前の i = 0 と sp 複写の置き場所, ldrb の base を r4 か r3 に置くかのレジスタ割当だけ
// 試済: sprite の初期化を for に入れる, anim / active を歩くポインタにする (悪化), 画面座標を vp-> で読む (悪化), i と sprite の宣言順
NON_MATCH void Ringo_UpdateAuxSprites(Ringo* p) {
#ifdef NONMATCHING_C
  Vec3 screen;
  Vec3* vp = &screen;
  Vec3* pos = &p->base.mover.pos;
  AuxSprite* sprite;
  s32 i;

  WorldToScreen(vp, pos);
  sprite = p->auxSprites;
  for (i = 0; i < 16; i++, sprite++) {
    if (p->auxActive[i]) {
      Vec3* ofs = &p->auxOffsets[i];

      if (p->auxAnims[i].tick & 1) {
        ofs->y--;
      }
      sprite->pos.x = screen.x + ofs->x;
      sprite->pos.y = screen.y + ofs->y;
      sprite->pos.z = screen.z + ofs->z;
      if (AuxSprite_AdvanceAnim(sprite, &p->auxAnims[i])) {
        sprite->flags |= SPRFLAG_HIDDEN;
        p->auxActive[i] = FALSE;
      }
    }
  }
#else
  INCFUNC("asm/func/Ringo_UpdateAuxSprites.inc");
#endif
}

// 1 回目で打ち切り (222/226), idx と p のレジスタ割り当てと退避枠が 1 つ少ない
NON_MATCH void Ringo_AddAuxSprite(Ringo* p, s32 kind, s32 idx, s32 param_4, s32 param_5) {
#ifdef NONMATCHING_C
  s32 i;

  if (idx > 12) {
    return;
  }
  if (param_5) {
    idx += 16;
  }
  for (i = 0; i < 16; i++) {
    if (!p->auxActive[i]) {
      AuxSprite* sprite = &p->auxSprites[i];
      Vec3* ofs = &p->auxOffsets[i];

      if (param_4 == 2 || param_4 == 3) {
        ofs->x = (Random() & 7) - s8_ARRAY_085aabd8[idx][0] - 14;
      } else {
        ofs->x = (Random() & 7) + s8_ARRAY_085aabd8[idx][0] + 6;
      }
      if (param_5) {
        if (param_4 == 0 || param_4 == 3) {
          ofs->y = (Random() & 7) + s8_ARRAY_085aabd8[idx - 16][1] - 40;
        } else {
          ofs->y = (Random() & 7) + s8_ARRAY_085aabd8[idx][1] - 40;
        }
      } else {
        if (param_4 == 0 || param_4 == 3) {
          ofs->y = (Random() & 7) + s8_ARRAY_085aabd8[idx + 16][1] - 40;
        } else {
          ofs->y = (Random() & 7) + s8_ARRAY_085aabd8[idx][1] - 40;
        }
      }
      ofs->z = 0;
      if (kind == 0) {
        AuxSprite_SetGfx(sprite, &p->auxGfx[0]);
        AuxAnim_SetAnim(&p->auxAnims[i], p->auxAnimFile, 3, 0, 0);
      } else {
        AuxSprite_SetGfx(sprite, &p->auxGfx[1]);
        AuxAnim_SetAnim(&p->auxAnims[i], p->auxAnimFile, 2, 0, 0);
      }
      AuxAnim_SetAnimSpeed(&p->auxAnims[i], 32);
      sprite->flags &= ~SPRFLAG_HIDDEN;
      p->auxActive[i] = TRUE;
      return;
    }
  }
#else
  INCFUNC("asm/func/Ringo_AddAuxSprite.inc");
#endif
}

// 残差は乱数表のプール定数を載せるレジスタのみ (87/87, r1 と r2), 足し算の順番, table ローカルは試済
NON_MATCH void FUN_0802a208(Ringo* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprite_aa0;

  MainSprite_Add(sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, PLAYMODE_PAUSE, 60, &p->sprites[0].pos);
  MainSprite_SetAnim(sprite, &p->gfx, 78, PLAYMODE_ONCE_AND_STOP, 0);
  p->unk_b00 = 0;
  p->unk_b01 = (Random() & 0x1F) + 0x70;
  p->unk_b02 = 4;
  p->unk_b03 = 1;
  p->unk_b04 = 0;
  p->unk_b06 = p->unk_164;
  ParticleShadow_Init(&p->ptclShadow, &p->sprite_aa0.pos, 1);
  ParticleShadow_Hide(&p->ptclShadow);
#else
  INCFUNC("asm/func/FUN_0802a208.inc");
#endif
}

void FUN_0802a2e0(Ringo* p) {
  MainSprite* sprite = &p->sprite_aa0;

  ParticleShadow_Remove(&p->ptclShadow);
  MainSprite_Remove(sprite);
}

void FUN_0802a2fc(Ringo* p) {
  MainSprite* sprite = &p->sprite_aa0;
  Vec3 v;

  switch (p->unk_b00) {
    case 0: {
      break;
    }
    case 1: {
      Vec3_SetPolar(&v, p->unk_b01, p->unk_b02);
      v.y = FixToInt(12, SIN(p->unk_b04 * 2) * 8);
      Vec3_Add(&sprite->pos, &v);
      if (p->unk_b04 > 65) {
        p->unk_b00++;
        p->unk_b04 = 0;
        MainSprite_SetAnim(sprite, &p->gfx, 79, PLAYMODE_LOOP, 0);
      }
      break;
    }
    case 2: {
      if ((p->unk_b04 & 7) == 7) {
        if (p->unk_b02 > 2) {
          p->unk_b02--;
        }
        if (p->unk_b03 < 8) {
          p->unk_b03++;
        }
      }
      Vec3_SetPolar(&v, p->unk_b01, p->unk_b02);
      v.y = -p->unk_b03;
      Vec3_Add(&sprite->pos, &v);
      if (sprite->pos.y < p->unk_b06) {
        sprite->pos.y = p->unk_b06;
        p->unk_b00++;
        p->unk_b04 = 0;
        MainSprite_SetAnim(sprite, &p->gfx, 80, PLAYMODE_ONCE_AND_STOP, 0);
        ParticleShadow_Hide(&p->ptclShadow);
        PlaySound_082406e0(SONG_679);
      }
      break;
    }
  }
  if (p->unk_b00) {
    MainSprite_AdvanceAnim(sprite, &p->gfx);
  }
  p->unk_b04++;
}

void FUN_0802a538(Ringo* p) {
  MainSprite* sprite = &p->sprite_aa0;

  p->sprite_aa0.pos = p->sprites[0].pos;
  MainSprite_Show(sprite);
  sprite->pos.y += 300;
  p->unk_b00 = 1;
  p->unk_b01 = 0x60;
  p->unk_b02 = 4;
  p->unk_b03 = 1;
  p->unk_b04 = 0;
  p->unk_b06 = p->unk_164;
  MainSprite_SetAnim(sprite, &p->gfx, 78, PLAYMODE_LOOP, 0);
  ParticleShadow_Show(&p->ptclShadow);
}

// 残差は gMsgBus の読み直し (558/556), 原典はループの先頭で毎回プールから読む, Duneyrr_PollMessages と同じ壁
NON_MATCH void Ringo_PollMessages(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  MsgQueue* queue = &boss->msgQueue;
  s32 i;

  for (i = 0; i < queue->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = queue->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(queue, msg);
    switch (msg->cmd) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        break;
      }
      case 2: {
        boss->destAngle = Angle_FromDir8((u8)msg->args[0]);
        Boss_SetSubStates(boss, 2, 0, 1);
        break;
      }
      case 1: {
        boss->mover.pos.x = msg->args[0];
        boss->mover.pos.y = msg->args[1];
        boss->mover.pos.z = msg->args[2];
        p->sprites[0].pos.x = boss->mover.pos.x;
        p->sprites[0].pos.y = p->spriteOffsetY + boss->mover.pos.y;
        p->sprites[0].pos.z = boss->mover.pos.z;
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 3: {
        boss->destAngle = Angle_FromDir8((u8)msg->args[0]);
        Boss_SetSubStates(boss, 2, 0, 2);
        break;
      }
      case 4: {
        p->unk_84c.x = msg->args[0];
        p->unk_84c.y = msg->args[1];
        p->unk_84c.z = msg->args[2];
        Boss_SetSubStates(boss, 2, 0, 3);
        break;
      }
      case 5: {
        boss->destAngle = Angle_FromDir8((u8)msg->args[0]);
        Boss_SetSubStates(boss, 2, 0, 4);
        break;
      }
      case 6: {
        boss->destAngle = Angle_FromDir8((u8)msg->args[0]);
        Boss_SetSubStates(boss, 2, 0, 5);
        break;
      }
      case 7: {
        Boss_SetSubStates(boss, 2, 0, 6);
        break;
      }
      case 8: {
        Boss_SetSubStates(boss, 2, 0, 7);
        break;
      }
      case 9: {
        Boss_ShowEmote(boss, msg->args[0], 180, 180);
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 11: {
        Boss_SetSubStates(boss, 2, 0, 8);
        break;
      }
      case 12: {
        p->unk_84c.x = msg->args[0];
        p->unk_84c.y = msg->args[1];
        p->unk_84c.z = msg->args[2];
        p->unk_171 = TRUE;
        Boss_SetSubStates(boss, 2, 0, 9);
        break;
      }
      case 13: {
        p->unk_84c.x = msg->args[0];
        p->unk_84c.y = msg->args[1];
        p->unk_84c.z = msg->args[2];
        {
          Vec3* target = &p->unk_84c;
          Vec3* pos = &boss->mover.pos;

          boss->destAngle = ArcTan2_8(target->x - pos->x, target->z - pos->z);
        }
        Boss_SetAngle(boss, boss->destAngle);
        p->unk_171 = FALSE;
        Boss_SetSubStates(boss, 2, 0, 9);
        break;
      }
      case 14: {
        Boss_SetSubStates(boss, 2, 0, 10);
        break;
      }
      case 15: {
        p->unk_84c.x = msg->args[0];
        p->unk_84c.y = msg->args[1];
        p->unk_84c.z = msg->args[2];
        Boss_SetSubStates(boss, 2, 0, 11);
        break;
      }
      case 16: {
        Boss_SetSubStates(boss, 2, 0, 12);
        break;
      }
      case 17: {
        p->unk_8cc = msg->args[0];
        Boss_SetSubStates(boss, 2, 0, 13);
        break;
      }
      case 18: {
        Boss_SetSubStates(boss, 2, 0, 14);
        break;
      }
      case 19: {
        p->unk_18b = msg->args[0];
        Boss_SetSubStates(boss, 2, 0, 15);
        break;
      }
      case 20: {
        Boss_SetSubStates(boss, 2, 0, 16);
        break;
      }
      case 21: {
        Boss_SetSubStates(boss, 2, 0, 17);
        break;
      }
      case 23: {
        Boss_SetSubStates(boss, 2, 0, 18);
        break;
      }
      case 24: {
        Boss_SetSubStates(boss, 2, 0, 19);
        break;
      }
      case 25: {
        Boss_SetSubStates(boss, 2, 0, 20);
        break;
      }
      case 26: {
        Boss_SetSubStates(boss, 2, 0, 21);
        break;
      }
      case 27: {
        Boss_SetSubStates(boss, 2, 0, 22);
        break;
      }
      case 28: {
        Boss_SetSubStates(boss, 2, 0, 23);
        break;
      }
      case 29: {
        Boss_SetSubStates(boss, 2, 0, 24);
        break;
      }
      case 31: {
        Boss_SetSubStates(boss, 2, 0, 25);
        break;
      }
      case 32: {
        p->unk_18b = msg->args[0];
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 30: {
        if (msg->args[0] == 0) {
          u32 plttID;

          p->plttFade = 0;
          p->plttFadeMode = -1;
          p->plttFadeTo = Ringo_GetPlttID(p);
          plttID = Ringo_GetPlttID(p);
          if (plttID == 0) {
            p->sprites[0].pltt = p->pltt[0];
          } else {
            p->sprites[0].pltt = &gObjPlttData[plttID * 16];
          }
          p->sprites[1].pltt = p->sprites[0].pltt;
        } else {
          Ringo_StartPlttFade(p, 5, 206);
        }
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Ringo_PollMessages.inc");
#endif
}

void Ringo_InitHitbox(Ringo* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hitbox, FUN_08028050, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
}

void Ringo_InitHitbox2(Ringo* p) {
  HitboxData* hitbox = &p->hitbox2;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.563), Q8(0.5), Q8(0.563));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hitbox, FUN_08028050, p);
  Hitbox_SetAttack(hitbox, p->hitbox2Power, p->hitbox2Knockback, 0, HBATTR_17 | HBATTR_18, p->hitbox2Unk44);
}

void Ringo_InitHurtbox(Ringo* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.375), Q8(0.5), Q8(0.375));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hurtbox, Ringo_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_DARK, HBATTR_SOL);
  Hitbox_Register(hurtbox);
}

void Ringo_InitHurtbox2(Ringo* p) {
  HitboxData* hurtbox = &p->hurtbox2;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(1), Q8(0.5), Q8(1));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hurtbox, FUN_0802802c, p);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_Register(hurtbox);
}

void FUN_0802adb8(Ringo* p) {
  p->unk_16a = 0;
  p->unk_175 = 0;
  p->unk_176 = 0;
  p->unk_178 = 0;
  p->unk_17a = 0;
  p->unk_17b = 3;
  p->unk_17c = 0x40;
  p->unk_182 = 0;
  p->unk_893 = 0;
  p->unk_8d4 = 240;
  p->unk_896 = 240;
  p->targetPlayer = 0;
  p->unk_fd4 = FALSE;
  p->unk_1048 = 0x40;
  p->unk_1044 = 0;
  p->unk_8dd = TRUE;
}

// 残差はレジスタ割り当てとプレイヤーのループの形 (249/253), 原典は p を r7 と r9 に二重に持ちループは先頭で条件を見る
NON_MATCH void FUN_0802ae4c(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &p->base.mover;
  s32 i;

  Ringo_PollMessages(p);
  p->unk_864 = FUN_08084710();
  if (!p->unk_864) {
    p->unk_87e = FALSE;
  }
  Mover_ApplyMove(mover);
  Boss_AdvanceAnim(&p->base, &p->sprites[0], &p->gfx);
  mover->pos.y = p->unk_164;
  p->sprites[0].pos.x = mover->pos.x;
  p->sprites[0].pos.y = p->spriteOffsetY + mover->pos.y;
  p->sprites[0].pos.z = mover->pos.z;
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_18)) {
    p->sprites[0].pos.x += FixToInt(12, COS(p->unk_16e) * (p->unk_16c * 4));
    p->sprites[0].pos.z += FixToInt(12, SIN(p->unk_16e) * (p->unk_16c * 4));
  }
  if (p->unk_18a) {
    u16 angle = Random();

    p->sprites[0].pos.x += FixToInt(12, COS(angle) * (p->unk_18a * 4));
    p->sprites[0].pos.z += FixToInt(12, SIN(angle) * (p->unk_18a * 4));
    p->unk_18a--;
  }
  FUN_08022e20(boss);
  for (i = 0; i < p->numPlayers; i++) {
    Vec3* playerPos = boss->playerPos[i];

    if (playerPos != NULL) {
      s32 dx = playerPos->x - boss->mover.pos.x;
      s32 dz = playerPos->z - boss->mover.pos.z;

      boss->playerAngle[i] = ArcTan2_8(dx, dz);
      boss->playerDistSq[i] = dx * dx + dz * dz;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802ae4c.inc");
#endif
}

static const rgb555 rgb555_ARRAY_085aac18[16] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};  // 0x085AAC18

// 1 回目で打ち切り (1367/1361, 投影は WorldToScreen), レジスタと退避枠の割り当てが大きくずれ pltt の差し替えは FUN_080353ac と同じ壁
NON_MATCH void FUN_0802b074(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  MainSprite* sprite;

  if (p->unk_184 > 0) {
    s32 heal = p->unk_184;
    s32 hp = boss->hp;

    Boss_SetHP(boss, hp + heal);
    if (hp != boss->hp) {
      Vec3 ofs;

      VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
      CreateDamageNumber(&p->hurtbox, heal, 1, &boss->mover.pos, &ofs, 1);
    }
    p->unk_184 = 0;
  }
  if (p->unk_182 > 0) {
    boss->hp -= p->unk_182;
    if (boss->hp <= 0) {
      boss->hp = 1;
    }
    p->unk_182 = 0;
  }
  FUN_08022ec0(boss);
  FUN_08028960(p);
  if (p->unk_188) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    p->unk_188--;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
    p->hurtbox2.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->sprites[0].pos, 0);
    p->hurtbox.angle = mover->angle;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_19)) {
    p->hurtbox2.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox2, &p->sprites[0].pos, 0);
  } else {
    p->hurtbox2.flags |= HBFLAG_HIDDEN;
  }
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX)) {
    Hitbox_SetPos(&p->hitbox, &p->sprites[0].pos, 0);
    p->hitbox.angle = mover->angle;
    Hitbox_Register(&p->hitbox);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HITBOX2)) {
    Vec3 pos;

    FUN_08028138(p, &pos);
    Hitbox_SetPos(&p->hitbox2, &pos, 0);
    p->hitbox2.angle = ((mover->angle - 0x20) & ~0x3F) + 0x40;
    Hitbox_Register(&p->hitbox2);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    MainSprite_Hide(&p->sprites[0]);
    AuxShadow_Hide(&p->shadow);
    CLEAR_FLAGS(boss->flags, BOSSFLAG_VISIBLE);
  } else {
    MainSprite_Show(&p->sprites[0]);
    if (boss->isDemo) {
      if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW)) {
        AuxShadow_Hide(&p->shadow);
      } else {
        AuxShadow_Show(&p->shadow);
      }
      CLEAR_FLAGS(boss->flags, BOSSFLAG_VISIBLE);
    } else {
      if (p->unk_fd4 || TEST_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW)) {
        AuxShadow_Hide(&p->shadow);
      } else {
        AuxShadow_Show(&p->shadow);
      }
      SET_FLAGS(boss->flags, BOSSFLAG_VISIBLE);
    }
  }
  if (p->unk_16c) {
    p->unk_16c--;
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_18);
  }
  if (p->unk_186 > 0) {
    if (--p->unk_186 == 0) {
      u32 plttID = Ringo_GetPlttID(p);

      if (plttID == 0) {
        p->sprites[0].pltt = p->pltt[0];
      } else {
        p->sprites[0].pltt = &gObjPlttData[plttID * 16];
      }
      p->sprites[1].pltt = p->sprites[0].pltt;
    }
  } else {
    s32 dst = FUN_08027f10(p) + 2;
    s32 src = FUN_08027f10(p) + 0xC3;
    s32 cur = Ringo_GetPlttID(p) - 0xC1;

    if (p->plttFadeMode == 0) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (++p->plttFade > 31) {
        p->plttFade = 32;
      }
    } else if (p->plttFadeMode == 1) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (--p->plttFade <= 0) {
        u32 plttID;

        p->plttFade = 0;
        p->plttFadeMode = -1;
        p->plttFadeTo = Ringo_GetPlttID(p);
        plttID = Ringo_GetPlttID(p);
        if (plttID == 0) {
          p->sprites[0].pltt = p->pltt[0];
        } else {
          p->sprites[0].pltt = &gObjPlttData[plttID * 16];
        }
        p->sprites[1].pltt = p->sprites[0].pltt;
      }
    } else if (p->plttFadeMode == 2) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], (rgb555*)rgb555_ARRAY_085aac18, abs(32 - p->plttFade), 5);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (++p->plttFade > 63) {
        p->plttFade = 0;
      }
    } else if (p->plttFadeMode == 3) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[203 * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 6);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (++p->plttFade > 63) {
        p->plttFade = 64;
      }
    } else if (p->plttFadeMode == 4) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 7);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (++p->plttFade > 127) {
        p->plttFade = 128;
      }
    } else if (p->plttFadeMode == 5) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (!p->unk_87d) {
        if (++p->plttFade > 31) {
          p->plttFade = 32;
          p->unk_87d = 1;
        }
      } else if (--p->plttFade <= 0) {
        p->plttFade = 0;
        p->unk_87d = 0;
      }
    } else if (p->plttFadeMode == 6) {
      BlendPltt(p->pltt_620[dst], &gObjPlttData[src * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 6);
      p->sprites[0].pltt = p->sprites[1].pltt = p->pltt_620[cur];
      if (++p->plttFade > 63) {
        p->plttFade = 64;
      }
    }
  }
  if (!boss->isDemo) {
    if (TEST_FLAGS(boss->flags, BOSSFLAG_VISIBLE) && !TEST_FLAGS(boss->flags, BOSSFLAG_UNK_24) && !(gPlayerStates[0] & FLAG03002BC0_UNK_2)) {
      if (!p->unk_880) {
        p->unk_880 = TRUE;
        p->unk_884 = 0;
        p->unk_886 = 0;
      }
      FUN_08028388(p);
      if (++p->unk_886 > 128) {
        p->unk_886 = 128;
      }
    } else {
      p->unk_880 = FALSE;
      FUN_0823b880(32);
    }
  }
  sprite = &p->sprite_a40;
  if (boss->curState == 10 || boss->curState == 54) {
    if (!(sprite->flags & SPRFLAG_HIDDEN)) {
      Vec3 pos;
      Vec3* vp;
      s32 x, z, a, b;

      pos = p->sprites[0].pos;
      vp = &sprite->pos;
      WorldToScreen(vp, &pos);
      if (!boss->xflip) {
        sprite->pos.x += s8_ARRAY_085aabbc[p->unk_a16][0];
        sprite->pos.y += s8_ARRAY_085aabbc[p->unk_a16][1];
      } else {
        sprite->pos.x -= s8_ARRAY_085aabbc[p->unk_a16][0];
        sprite->pos.y += s8_ARRAY_085aabbc[p->unk_a16][1];
      }
      if (p->unk_a14 != p->unk_a16 && p->sprites[0].animCmdTimer == 1) {
        u32 anim;

        if (p->unk_a16 == 2 || p->unk_a16 == 5 || p->unk_a16 == 8) {
          Vec3 ofs;
          s32 d = !boss->xflip ? 32 : -32;

          ofs.x = d;
          ofs.z = d;
          ofs.y = 160;
          if (!boss->isDemo) {
            s32 dmg = Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, &ofs, 0, 0, 0, 1, p->unk_8c4, 2);
            s32 hp = boss->hp;

            Boss_SetHP(boss, hp + dmg);
            if (hp != boss->hp) {
              Vec3 ofs2;

              VEC3_SET(ofs2, Q8(0.063), 0, Q8(0.063));
              CreateDamageNumber(&p->hurtbox, dmg, 1, &boss->mover.pos, &ofs2, 1);
            }
          }
          FUN_08028a04(p);
          PlaySound_0824078c(SONG_844);
        }
        anim = FUN_08028ec8(p);
        if (p->unk_a16 > 1) {
          anim += 2;
        } else if (p->unk_a16 == 1) {
          anim += 1;
        }
        MainSprite_SetAnim(sprite, &p->gfx_a20, anim, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
      MainSprite_AdvanceAnim(sprite, &p->gfx_a20);
      p->unk_a14 = p->unk_a16;
      p->unk_a16 = p->sprites[0].animCmdIdx;
    }
  } else if (boss->curState == 25) {
    if (!(sprite->flags & SPRFLAG_HIDDEN)) {
      Vec3 pos;
      Vec3* vp;
      s32 x, z, a, b;

      pos = p->sprites[0].pos;
      vp = &sprite->pos;
      WorldToScreen(vp, &pos);
      sprite->pos.x += (s8)u8_ARRAY_085aabd0[p->unk_a16 * 2];
      sprite->pos.y = (s8)u8_ARRAY_085aabd0[p->unk_a16 * 2 + 1] + (sprite->pos.y + 0x24);
      if (p->phaseTimer == 1) {
        u32 anim = FUN_08028ec8(p);

        switch (p->phase) {
          case 0: {
            break;
          }
          case 1:
          case 3: {
            anim += 1;
            break;
          }
          default: {
            anim += 2;
            break;
          }
        }
        MainSprite_SetAnim(sprite, &p->gfx_a20, anim, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
      MainSprite_AdvanceAnim(sprite, &p->gfx_a20);
    } else if (p->phaseTimer == 1 && p->phase == 4) {
      if (!boss->isDemo) {
        Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, NULL, 0, 0, 0, 1, p->unk_8c6, 0);
      }
      PlaySound_0824078c(SONG_478);
    }
  }
  Ringo_UpdateAuxSprites(p);
  FUN_0802a2fc(p);
  FUN_08029b40(p);
  if (p->unk_1044) {
    s32 target;

    p->unk_1044--;
    target = gStat->sunGauge * 4 + 16;
    if (target > 63) {
      target = 64;
    }
    if (p->unk_1048 > target) {
      p->unk_1048--;
    } else if (p->unk_1048 < target) {
      p->unk_1048++;
    }
  } else if (p->unk_1048 < 64) {
    p->unk_1048++;
  } else {
    p->unk_1048 = 64;
  }
  gBgBrightness2 = p->unk_1048;
  p->unk_178 = 0;
  if (boss->isDemo && p->unk_18b && (boss->frameCount & 15) == 0) {
    FUN_08028c04(p);
  }
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
  boss->frameCount++;
#else
  INCFUNC("asm/func/FUN_0802b074.inc");
#endif
}

s32 FUN_0802bc7c(Ringo* p) {
  if (p->unk_864 != 0) {
    Boss_SetSubState2(&p->base, 15);
    p->unk_894 = 0;
    p->unk_888 = p->unk_8d2;
    return TRUE;
  }
  return FALSE;
}

void FUN_0802bccc(Ringo* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  s32 ratio = Boss_GetHPRatio(boss);
  s32 n;

  Random();
  n = p->unk_88a & 7;
  p->unk_88a++;
  if (n == 3 || n == 7) {
    p->targetPlayer = 1;
    p->unk_17e = p->unk_8dc;
  } else {
    p->targetPlayer = 0;
    p->unk_17e = p->unk_8db;
  }
  if (p->targetPlayer == 0) {
    if (ratio < 0x40) {
      if (n <= 2) {
        Ringo_SetUnk169(p, 5);
        FUN_0823585c(&p->unk_84c, &mover->pos, 3, 4, 0x100, NULL, NULL);
      } else if (n == 4) {
        Ringo_SetSubState2Unk17b(p, 14, 3, 0x40);
        return;
      } else {
        Ringo_SetUnk169(p, 9);
        FUN_0823585c(&p->unk_84c, &mover->pos, 1, 1, 0x100, NULL, NULL);
      }
    } else if (n <= 2) {
      Ringo_SetUnk169(p, 5);
      FUN_0823585c(&p->unk_84c, &mover->pos, 3, 4, 0x100, NULL, NULL);
    } else if (n == 4) {
      Ringo_SetSubState2Unk17b(p, 12, 3, 0x40);
      return;
    } else {
      Ringo_SetUnk169(p, 8);
      FUN_0823585c(&p->unk_84c, &mover->pos, 3, 1, 0x100, NULL, NULL);
    }
    Boss_SetSubState2(boss, 1);
  } else {
    Ringo_SetUnk169(p, 6);
    FUN_0823585c(&p->unk_84c, &mover->pos, 2, 6, 0x100, NULL, NULL);
    Boss_SetSubState2(boss, 1);
    if (p->unk_820 != 0) {
      PlaySound_0824078c(SONG_778);
    } else {
      PlaySound_0824078c(SONG_859);
    }
  }
}

void FUN_0802be88(Ringo* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  s32 ratio = Boss_GetHPRatio(boss);
  s32 n;

  Random();
  n = p->unk_88a & 7;
  p->unk_88a++;
  if (n == 3 || n == 7) {
    p->targetPlayer = 1;
    p->unk_17e = p->unk_8dc;
  } else {
    p->targetPlayer = 0;
    p->unk_17e = p->unk_8db;
  }
  if (p->targetPlayer == 0) {
    if (ratio < 0x40) {
      Ringo_SetUnk169(p, 7);
      FUN_0823585c(&p->unk_84c, &mover->pos, 2, 5, 0x100, NULL, NULL);
      Boss_SetSubState2(boss, 1);
    } else if (n <= 2) {
      Ringo_SetUnk169(p, 5);
      FUN_0823585c(&p->unk_84c, &mover->pos, 3, 4, 0x100, NULL, NULL);
    } else {
      Ringo_SetUnk169(p, 8);
      FUN_0823585c(&p->unk_84c, &mover->pos, 3, 1, 0x100, NULL, NULL);
    }
    Boss_SetSubState2(boss, 1);
  } else {
    Ringo_SetUnk169(p, 7);
    FUN_0823585c(&p->unk_84c, &mover->pos, 2, 5, 0x100, NULL, NULL);
    Boss_SetSubState2(boss, 1);
    if (p->unk_820 != 0) {
      PlaySound_0824078c(SONG_778);
    } else {
      PlaySound_0824078c(SONG_859);
    }
  }
}

void FUN_0802c024(Ringo* p) {
  Boss* boss = &p->base;
  u32 n;

  Random();
  n = p->unk_88a & 7;
  p->unk_88a++;
  p->targetPlayer = 0;
  p->unk_17e = p->unk_8db;
  if (n == 0 || n == 4) {
    Ringo_SetUnk169(p, 11);
    FUN_0823585c(&p->unk_84c, &boss->mover.pos, 2, 8, 0x100, NULL, NULL);
  } else if (n == 1 || n == 5) {
    Ringo_SetUnk169(p, 7);
    FUN_0823585c(&p->unk_84c, &boss->mover.pos, 3, 8, 0x100, NULL, NULL);
  } else if (n == 2 || n == 6) {
    Boss_SetSubState2(boss, 20);
    return;
  } else {
    Ringo_SetUnk169(p, 8);
    FUN_0823585c(&p->unk_84c, &boss->mover.pos, 3, 4, 0x100, NULL, NULL);
  }
  Boss_SetSubState2(boss, 1);
}

void FUN_0802c130(Ringo* p) {
  Boss* boss = &p->base;

  switch (p->unk_169) {
    case 1: {
      Ringo_ResetSubStates(p, 90);
      break;
    }
    case 2: {
      Ringo_SetSubState2Unk17b(p, 12, 3, 0x40);
      break;
    }
    case 3: {
      Ringo_SetSubState2Unk17b(p, 13, 3, 0x40);
      break;
    }
    case 4: {
      Ringo_SetSubState2Unk17b(p, 14, 3, 0x40);
      break;
    }
    case 5: {
      p->unk_174 = 1;
      Boss_SetSubState2(boss, 10);
      break;
    }
    case 6: {
      p->unk_174 = 0;
      Boss_SetSubState2(boss, 10);
      break;
    }
    case 7: {
      p->unk_892 = p->targetPlayer;
      Boss_SetSubState2(boss, 11);
      break;
    }
    case 8: {
      p->unk_172 = 0;
      Boss_SetSubState2(boss, 5);
      break;
    }
    case 9: {
      p->unk_172 = 1;
      Boss_SetSubState2(boss, 5);
      break;
    }
    case 10: {
      Boss_SetSubState2(boss, 20);
      break;
    }
    case 11: {
      Boss_SetSubState2(boss, 27);
      break;
    }
    default: {
      if (p->unk_820 != 0) {
        if (p->unk_fd4) {
          FUN_0802c024(p);
        } else {
          FUN_0802be88(p);
        }
      } else {
        FUN_0802bccc(p);
      }
      break;
    }
  }
  p->unk_169 = 0;
}

void dainn_08032f18(Boss* boss, s32 timer);
void FUN_08032e1c(Boss* boss, s32 timer);

bool32 FUN_0802c2d4(Ringo* p) {
  Boss* boss = &p->base;

  if (boss->hp <= 0 && boss->canDie) {
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_1);
    if (p->unk_820 != 0) {
      Boss_SetState(boss, dainn_08032f18, 34);
    } else {
      Boss_SetState(boss, FUN_08032e1c, 33);
    }
  }
  boss->canDie = FALSE;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_1)) {
    Boss_SetSubStates(boss, 1, 0, 1);
    return TRUE;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(boss, 1, 0, 0);
    return TRUE;
  }
  return FALSE;
}

void FUN_0802c3a0(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 1);
  }
  if (FUN_0802bc7c(p)) {
    return;
  }
  if (p->unk_178 && p->targetPlayer != 1 && !p->unk_fd4) {
    Ringo_UpdateUnk88c(p);
  } else if (boss->subStateTimer > p->stateDuration) {
    if (p->unk_820 != 0) {
      if (p->unk_fd4) {
        FUN_0802c024(p);
      } else {
        FUN_0802be88(p);
      }
    } else {
      FUN_0802bccc(p);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802c564(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
  }
  if (p->unk_178 && p->targetPlayer != 1 && !p->unk_fd4) {
    Ringo_UpdateUnk88c(p);
  } else if (boss->subStateDone) {
    FUN_0802c130(p);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802c6e8(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
    p->unk_17e = 0x40;
  }
  if (boss->subStateDone) {
    FUN_0802c130(p);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802c73c(Ringo* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 4);
    FUN_08029628(p);
    FUN_0823585c(&p->unk_85c, &mover->pos, 3, 4, 0x100, NULL, NULL);
  }
  if (boss->subStateDone) {
    p->unk_172 = 0;
    Boss_SetSubState2(boss, 5);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802c7e0(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 6);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    p->unk_176 = 8;
  }
  if (boss->subStateDone) {
    if (!FUN_0802bc7c(p)) {
      Ringo_ResetSubStates(p, 90);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802c87c(Ringo* p) {
  p->base.canDie = TRUE;
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 7);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 6);
  } else {
    p->base.subStateTimer++;
  }
}

// 残差は PFLAG20_UNK_18 の判定 (437/438), 原典はフラグを 1 / 0 の値にしてから比べ, その 0 を subStateTimer に書く
NON_MATCH void FUN_0802c8e0(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &p->base.mover;
  s32 n;
  Vec3 v;
  bool32 blocked;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 8);
  }
  if (!p->unk_172) {
    Vec3 front, min, max;

    Vec3_SetPolar(&front, mover->angle, 200);
    Vec3_Add(&front, &mover->pos);
    min.x = -200;
    min.z = -200;
    Vec3_Add(&min, &front);
    max.x = 200;
    max.z = 200;
    Vec3_Add(&max, &front);
    n = FUN_08028720(p, p->numPlayers, &min, &max);
    if (n >= 0) {
      Boss_SetSubState2(boss, 7);
      return;
    }
  } else {
    Vec3 front, min, max;

    Vec3_SetPolar(&front, mover->angle, 128);
    Vec3_Add(&front, &mover->pos);
    min.x = -128;
    min.z = -128;
    Vec3_Add(&min, &front);
    max.x = 128;
    max.z = 128;
    Vec3_Add(&max, &front);
    n = FUN_08028720(p, p->numPlayers, &min, &max);
    if (n >= 0 && !Player_TestFlag20(gPlayerPtr[n], PFLAG20_UNK_18)) {
      p->grabbedPlayer = n;
      Boss_SetSubState2(boss, 8);
      return;
    }
  }
  mover = &p->base.mover;
  Vec3_SetPolar(&v, mover->angle, 400);
  Vec3_Add(&v, &mover->pos);
  blocked = (u32)(TileHeightAt(&v) - p->unk_164 + 511) > 766;
  if (blocked || boss->subStateDone) {
    Boss_SetSubState2(boss, 9);
  } else {
    boss->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0802c8e0.inc");
#endif
}

void FUN_0802cca0(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 9);
  }
  if (boss->subStateDone) {
    if (p->unk_fd4) {
      Ringo_ResetSubStates(p, 10);
    } else {
      Ringo_ResetSubStates(p, 90);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802cd2c(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 10);
  }
  if (boss->subStateDone) {
    Ringo_ResetSubStates(p, 90);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802cda4(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 11);
  }
  if (boss->subStateDone) {
    if (p->unk_fd4) {
      Ringo_ResetSubStates(p, 30);
    } else {
      Ringo_ResetSubStates(p, 30);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802ce30(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 12);
  }
  if (boss->subStateDone) {
    Ringo_ResetSubStates(p, 180);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802cea8(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 13);
  }
  if (boss->subStateDone) {
    if (p->unk_fd4) {
      Ringo_ResetSubStates(p, 5);
    } else {
      Ringo_ResetSubStates(p, 150);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802cf34(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    FUN_08029628(p);
    Boss_RequestState(boss, 14);
    p->unk_17a = 0;
  }
  if (!FUN_0802bc7c(p)) {
    if (boss->subStateDone) {
      if (++p->unk_17a >= p->unk_17b) {
        Ringo_ResetSubStates(p, 90);
        return;
      }
      FUN_08029628(p);
      Boss_RequestState(boss, 14);
    }
    boss->subStateTimer++;
  }
}

void FUN_0802cff4(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 15);
  }
  if (!FUN_0802bc7c(p)) {
    if (boss->subStateDone) {
      Ringo_ResetSubStates(p, 90);
    } else {
      boss->subStateTimer++;
    }
  }
}

void FUN_0802d074(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    FUN_08029628(p);
    Boss_RequestState(boss, 16);
    p->unk_17a = 0;
  }
  if (!FUN_0802bc7c(p)) {
    if (boss->subStateDone) {
      if (++p->unk_17a >= p->unk_17b) {
        Ringo_ResetSubStates(p, 90);
        return;
      }
      FUN_08029628(p);
      Boss_RequestState(boss, 16);
    }
    boss->subStateTimer++;
  }
}

// 1 回目で打ち切り (147/162), 原典は SetSubState2 の後半を分岐ごとに別々に持つ (既知のゼロのレジスタを使い分ける)
NON_MATCH void FUN_0802d134(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 17);
    p->unk_898 = 0;
    p->unk_896 = p->unk_8d4;
  }
  if (p->unk_864 == 0) {
    Ringo_ResetSubStates(p, 90);
  } else if (boss->subStateDone) {
    Boss_SetSubState2(boss, 18);
  } else if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    Boss_SetSubState2(boss, 16);
  } else if (++p->unk_894 >= p->unk_8d6) {
    if (p->unk_820 != 0) {
      p->targetPlayer = 1;
      p->unk_172 = 0;
    } else {
      p->targetPlayer = 1;
      p->unk_172 = 1;
    }
    Boss_SetSubState2(boss, 5);
  } else if (!FUN_080280cc(p) && !FUN_080281ec(p)) {
    boss->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0802d134.inc");
#endif
}

void FUN_0802d294(Ringo* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 18);
  }
  if (p->unk_864 == 0) {
    Ringo_ResetSubStates(p, 90);
  } else if (boss->subStateDone) {
    Vec3* target = &p->unk_868;
    s32 dx = target->x - mover->pos.x;
    s32 dz = target->z - mover->pos.z;

    if (dx * dx + dz * dz < 0x2400) {
      Boss_SetSubState2(boss, 18);
    } else {
      Boss_SetSubState2(boss, 15);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d36c(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss) == TRUE) {
    if (p->unk_820 == 0) {
      Boss_RequestState(boss, 12);
      p->unk_174 = 0;
    } else {
      p->unk_892 = TRUE;
      Boss_RequestState(boss, 13);
    }
    p->unk_176 = 0;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    p->unk_176 = 8;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 15);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d420(Ringo* p) {
  Boss* boss = &p->base;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 19);
  }
  if (p->unk_864 == 0) {
    Ringo_ResetSubStates(p, 90);
  } else if (boss->subStateDone) {
    Boss_SetSubState2(boss, 19);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d4bc(Ringo* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;

  boss->canDie = TRUE;
  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 20);
    if (Boss_GetHPRatio(boss) < 0x40) {
      p->unk_893 = TRUE;
    }
    p->unk_8dd = TRUE;
  }
  if (boss->subStateDone) {
    if (FUN_0802835c(p)) {
      Vec3 from;
      Vec3 to;

      Vec3_CopyOffsetY(&from, &mover->pos, 200);
      FUN_0823585c(&to, &mover->pos, 0, 1, 0x100, NULL, NULL);
      if (p->entity0805d364 != NULL) {
        FUN_0805d3a8(p->entity0805d364, &from, &to, 10, 10);
      }
      Boss_SetSubState2(boss, 28);
      p->unk_893 = FALSE;
      PlaySound_082406e0(SE_838);
    } else {
      Ringo_ResetSubStates(p, 90);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d5dc(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 21);
    p->unk_891 = 0;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 21);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d648(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 22);
  }
  if (boss->subStateDone) {
    if (p->unk_891 > 2) {
      Boss_SetSubState2(boss, 22);
    } else {
      Boss_SetSubState2(boss, 23);
    }
    p->unk_891++;
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d6c8(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 23);
  }
  if (boss->subStateDone) {
    Ringo_ResetSubStates(p, 30);
  } else {
    boss->subStateTimer++;
  }
}

// 残差は flag20 の判定 (132/134): 原典は PFLAG20_UNK_18 が立っているかを 1 / 0 にしてから比べる, != 0 を返す static inline でも揃わない
NON_MATCH void FUN_0802d738(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 24);
  }
  if (boss->subStateDone) {
    Vec3 min, max;
    s32 i;

    min.x = -0xA4;
    min.z = -0xA4;
    Vec3_Add(&min, &mover->pos);
    max.x = 0xA4;
    max.z = 0xA4;
    Vec3_Add(&max, &mover->pos);
    i = FUN_08028720(p, p->numPlayers, &min, &max);
    if (i >= 0 && !Player_TestFlag20(gPlayerPtr[i], PFLAG20_UNK_18)) {
      p->grabbedPlayer = i;
      Boss_SetSubState2(boss, 24);
    } else {
      Boss_SetSubState2(boss, 25);
    }
  } else {
    boss->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0802d738.inc");
#endif
}

void FUN_0802d85c(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 25);
  }
  if (boss->subStateDone) {
    if (p->grabbedPlayer < 0) {
      Boss_SetSubState2(boss, 21);
    } else {
      Boss_SetSubState2(boss, 26);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d8d0(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 26);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 21);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802d92c(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 27);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 21);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802d988(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 28);
  }
  if (boss->subStateDone) {
    Ringo_ResetSubStates(p, 5);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802d9f8(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 29);
  }
  p->base.subStateTimer++;
}

void FUN_0802da30(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 30);
  }
  if (boss->subStateDone) {
    Ringo_ResetSubStates(p, 90);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802daa0(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 31);
    p->unk_88a = 0;
  }
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0)) {
    Ringo_ResetSubStates(p, 60);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802db18(Ringo* p) {
  Boss_EnterSubState(&p->base);
  p->base.subStateTimer++;
}

void FUN_0802db3c(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 35);
  }
  p->base.subStateTimer++;
}

void FUN_0802db74(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 36);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_0802dbb8(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 37);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_0802dbfc(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 38);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dc5c(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 39);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dcbc(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 40);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 2);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dd24(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 41);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dd84(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 42);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 0);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dde8(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 43);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_0802de2c(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    if (p->unk_171) {
      Boss_RequestState(boss, 44);
    } else {
      Boss_RequestState(boss, 45);
    }
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 1);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802dea4(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 46);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802df04(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 47);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802df64(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 48);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802dfb4(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 49);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e004(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 50);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e054(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 51);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e0a4(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 52);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_0802e0e8(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 53);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e138(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 54);
    p->grabbedPlayer = 0;
  }
  if (boss->subStateDone) {
    MsgQueue_EndWait(&boss->msgQueue, 1);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802e198(Ringo* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 55);
    p->grabbedPlayer = 0;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 2);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802e210(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 56);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 0);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e274(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 57);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 0);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e2d8(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 58);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 2);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e340(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 59);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_0802e384(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 60);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0802e3e4(Ringo* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 61);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

// clang-format off
static void (*const PTR_ARRAY_085aac38[30])(Ringo*) = {
    FUN_0802c3a0,
    FUN_0802c564,
    FUN_0802c6e8,
    FUN_0802c73c,
    FUN_0802c7e0,
    FUN_0802c87c,
    FUN_0802c8e0,
    FUN_0802cca0,
    FUN_0802cd2c,
    FUN_0802cda4,
    FUN_0802ce30,
    FUN_0802cea8,
    FUN_0802cf34,
    FUN_0802cff4,
    FUN_0802d074,
    FUN_0802d134,
    FUN_0802d294,
    FUN_0802d36c,
    FUN_0802d420,
    FUN_0802d4bc,
    FUN_0802d5dc,
    FUN_0802d648,
    FUN_0802d6c8,
    FUN_0802d738,
    FUN_0802d85c,
    FUN_0802d8d0,
    FUN_0802d92c,
    FUN_0802d988,
    FUN_0802d9f8,
    FUN_0802da30,
};  // 0x085AAC38
// clang-format on

void FUN_0802e434(Ringo* p) { PTR_ARRAY_085aac38[p->base.subState2](p); }

void FUN_0802e450(Ringo* p) {
  static void (*const PTR_ARRAY_085aacb0[2])(Ringo*) = {
      FUN_0802daa0,
      FUN_0802db18,
  };  // 0x085AACB0
  PTR_ARRAY_085aacb0[p->base.subState2](p);
}

void FUN_0802e46c(Ringo* p) {
  // clang-format off
  static void (*const PTR_ARRAY_085aacb8[26])(Ringo*) = {
      FUN_0802db3c,
      FUN_0802db74,
      FUN_0802dbb8,
      FUN_0802dbfc,
      FUN_0802dc5c,
      FUN_0802dcbc,
      FUN_0802dd24,
      FUN_0802dd84,
      FUN_0802dde8,
      FUN_0802de2c,
      FUN_0802dea4,
      FUN_0802df04,
      FUN_0802df64,
      FUN_0802dfb4,
      FUN_0802e004,
      FUN_0802e054,
      FUN_0802e0a4,
      FUN_0802e0e8,
      FUN_0802e138,
      FUN_0802e198,
      FUN_0802e210,
      FUN_0802e274,
      FUN_0802e2d8,
      FUN_0802e340,
      FUN_0802e384,
      FUN_0802e3e4,
  };  // 0x085AACB8
  // clang-format on
  PTR_ARRAY_085aacb8[p->base.subState2](p);
}

void FUN_0802e488(Ringo* p) {
  static void (*const PTR_ARRAY_085aad20[1])(Ringo*) = {
      FUN_0802e434,
  };  // 0x085AAD20
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2) && !FUN_0802c2d4(p)) {
    PTR_ARRAY_085aad20[p->base.subState1](p);
  }
}

void FUN_0802e4c4(Ringo* p) {
  static void (*const PTR_ARRAY_085aad24[1])(Ringo*) = {
      FUN_0802e450,
  };  // 0x085AAD24
  PTR_ARRAY_085aad24[p->base.subState1](p);
}

void FUN_0802e4e0(Ringo* p) {
  static void (*const PTR_ARRAY_085aad28[1])(Ringo*) = {
      FUN_0802e46c,
  };  // 0x085AAD28
  PTR_ARRAY_085aad28[p->base.subState1](p);
}

void FUN_0802e4fc(Ringo* p) {
  static void (*const PTR_ARRAY_085aad2c[3])(Ringo*) = {
      FUN_0802e488,
      FUN_0802e4c4,
      FUN_0802e4e0,
  };  // 0x085AAD2C
  p->base.unk_9d = 0;
  PTR_ARRAY_085aad2c[p->base.subState0](p);
}

void FUN_0802e520(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (!p->unk_fd4) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_19);
    }
    Ringo_UpdateHover(p, timer);
  }
}

void FUN_0802e6ac(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    p->unk_844 = p->unk_868;
    FUN_08028604(p);
    FUN_0802853c(p, &p->unk_84c, p->unk_17e);
    FUN_08029a1c(p, p->unk_17e);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  if (p->unk_17e >= 64) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (!p->unk_fd4) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_19);
    }
    Ringo_UpdateHover(p, timer);
    if (p->unk_8e4 > 3) {
      FUN_08028838(p, 0, 0);
    }
    if (p->unk_840 < p->unk_842) {
      FUN_08028648(p);
      FUN_080286d8(p);
    } else {
      boss->subStateDone = TRUE;
    }
  }
}

// 残差は unk_175 の乱数の足し方 (223/220), 原典は playerAngle を先に読み (Random() & 0x7F) + 0x40 を後から足し, &targetPlayer と &playerAngle をレジスタに残して Boss_SetAngle でも使う
NON_MATCH void FUN_0802e8d0(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->unk_175 = boss->playerAngle[p->targetPlayer] + (Random() & 0x7F) + 0x40;
    Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    p->unk_854 = mover->pos;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (timer < 7) {
      Vec3 ofs;

      Vec3_SetPolar(&ofs, p->unk_175, timer * 32);
      mover->pos.x = ofs.x + p->unk_854.x;
      mover->pos.y = ofs.y + p->unk_854.y;
      mover->pos.z = ofs.z + p->unk_854.z;
      if (p->unk_8e4 > 3) {
        FUN_08028838(p, 0, 0);
      }
    }
    if (timer > 15) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802e8d0.inc");
#endif
}

// 残差は p と &boss->flags の r4 / r5 が入れ替わるだけ (239/239)
NON_MATCH void FUN_0802eac0(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    p->unk_844 = p->unk_868;
    FUN_08028604(p);
    FUN_0802853c(p, &p->unk_84c, 32);
    FUN_08029a1c(p, p->unk_17e);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (!p->unk_fd4) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_19);
    }
    Ringo_UpdateHover(p, timer);
    if (p->unk_8e4 > 3) {
      FUN_08028838(p, 0, 0);
    }
    if (p->unk_840 < p->unk_842) {
      FUN_08028648(p);
      FUN_080286d8(p);
    } else {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802eac0.inc");
#endif
}

// 残差は p の複写と &unk_854 のレジスタ (302/299), 原典は &unk_854 を 1 本のレジスタに置いて x / y / z を読む
NON_MATCH void FUN_0802ece0(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    Vec3* pos;
    Vec3* target;

    boss->stateEntered = FALSE;
    pos = &mover->pos;
    p->unk_854 = mover->pos = p->unk_85c;
    target = boss->playerPos[p->targetPlayer];
    Boss_SetAngle(boss, ArcTan2_8(target->x - mover->pos.x, target->z - pos->z));
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer <= 1) {
    SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  }
  if (!boss->stateRequestCallback(boss)) {
    if (timer <= 8) {
      u32 angle = Angle_FromDir8(boss->dir) + 0x60;
      Vec3* pos;
      Vec3 ofs;

      if (timer & 1) {
        angle -= 0xC0;
      }
      Vec3_SetPolar(&ofs, angle, (8 - timer) * 16);
      pos = &mover->pos;
      mover->pos.x = ofs.x + p->unk_854.x;
      pos->y = ofs.y + p->unk_854.y;
      pos->z = ofs.z + p->unk_854.z;
    }
    if (timer > 15) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802ece0.inc");
#endif
}

void FUN_0802ef68(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 37, 41), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_843);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->unk_864 != 0) {
      FUN_08028084(p);
      if (p->unk_176 != 0) {
        Vec3* target;
        s32 dx, dz;

        p->unk_176--;
        target = &p->unk_868;
        dx = target->x - mover->pos.x;
        dz = target->z - mover->pos.z;
        if ((u32)(dx * dx + dz * dz) > 0x4000) {
          if (p->unk_177) {
            Vec3_SetPolar(&mover->delta, mover->angle, 24);
          } else {
            Vec3_SetPolar(&mover->delta, mover->angle, 10);
          }
        }
      }
    }
    if (p->sprites[0].animCmdIdx == 3 || p->sprites[0].animCmdIdx == 4) {
      SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
}

// 1 回目で打ち切り (253/262), 原典は Ringo_SelectAnim の両分岐で &unk_820 を作ってレジスタに残し, 効果音の条件で読み直す
NON_MATCH void dainn_0802f134(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    if (p->unk_820 == 0 && p->unk_172 == 1) {
      PlaySound_0824078c(VO_RINGO_LAUGH);
    }
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->unk_820) {
      if (timer < 32) {
        Vec3_SetPolar(&mover->delta, mover->angle, -((32 - timer) >> 2));
      }
      if (timer >= 32) {
        boss->subStateDone = TRUE;
      }
    } else {
      if (timer < 64) {
        Vec3_SetPolar(&mover->delta, mover->angle, -((64 - timer) >> 3));
      }
      if (timer >= 64) {
        boss->subStateDone = TRUE;
      }
    }
  }
#else
  INCFUNC("asm/func/dainn_0802f134.inc");
#endif
}

void FUN_0802f368(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 36, 40), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_842);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    Vec3_SetPolar(&mover->delta, mover->angle, 40);
    if (p->unk_8e4 > 3) {
      if (p->unk_172 == 0) {
        FUN_08028838(p, 0, 0);
      } else {
        FUN_08028838(p, 1, 0);
      }
    }
    if (timer > 159) {
      boss->subStateDone = TRUE;
    }
  }
}

// 1 回目で打ち切り, 残差は timer と mover のレジスタ (148/148)
NON_MATCH void FUN_0802f4a8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 37, 41), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_843);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->sprites[0].animCmdIdx == 3 || p->sprites[0].animCmdIdx == 4) {
      SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
    }
    if (timer < 10) {
      Vec3_SetPolar(&mover->delta, mover->angle, (10 - timer) * 4);
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802f4a8.inc");
#endif
}

// 1 回目で打ち切り (536/542, 投影は WorldToScreen), 前半は FUN_08034b18 と同じでスタック枠とレジスタの割り当てが大きくずれる
NON_MATCH void FUN_0802f5e8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Player* player;

  if (boss->stateEntered) {
    MainSprite* sprite;
    Vec3 pos;
    Vec3* vp;
    Vec3 ofs;
    s32 d;

    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 44, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    sprite = &p->sprite_a40;
    MainSprite_SetAnim(sprite, &p->gfx_a20, FUN_08028ec8(p), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    if (!boss->xflip) {
      sprite->flags |= SPRFLAG_XFLIP;
    } else {
      sprite->flags &= ~SPRFLAG_XFLIP;
    }
    p->unk_a18 = *boss->playerPos[p->grabbedPlayer];
    pos = p->sprites[0].pos;
    vp = &sprite->pos;
    WorldToScreen(vp, &pos);
    if (!boss->xflip) {
      sprite->pos.x += s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    } else {
      sprite->pos.x -= s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    }
    MainSprite_Show(sprite);
    p->unk_a14 = -1;
    p->unk_a16 = p->sprites[0].animCmdIdx;
    d = !boss->xflip ? 32 : -32;
    ofs.x = d;
    ofs.z = d;
    ofs.y = 160;
    if (!boss->isDemo) {
      Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, &ofs, 0, 0, 0, 1, 0, 2);
    }
    sprite->plttID = 0x4200;
    player = gPlayerPtr[p->grabbedPlayer];
    sprite->pltt = player->useAuxSprite == 0 ? player->human.pltt : player->beastGfx->pltt;
    p->phaseTimer = 0;
    p->unk_874 = 120;
    if (p->grabbedPlayer >= 0) {
      p->unk_876 = p->unk_877 = boss->players[p->grabbedPlayer]->mashCount;
    }
    p->unk_16c = 0;
    p->unk_16d = 0;
  }
  if (boss->damageCallback(boss)) {
    MainSprite_Hide(&p->sprite_a40);
    if (!boss->isDemo && p->grabbedPlayer >= 0) {
      Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->mover.angle, 50, 0, 0, 0);
    }
    p->grabbedPlayer = -1;
    return;
  }
  if (boss->stateRequestCallback(boss)) {
    MainSprite_Hide(&p->sprite_a40);
    if (!boss->isDemo && p->grabbedPlayer >= 0) {
      Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->mover.angle, 50, 0, 0, 0);
    }
    p->grabbedPlayer = -1;
    return;
  }
  player = boss->players[p->grabbedPlayer];
  if (p->unk_877 != player->mashCount) {
    p->unk_877 = player->mashCount;
    p->unk_16d++;
  }
  if (p->unk_16d > 3) {
    p->unk_16e = Angle_FromDir8(Player_GetDpadFacing(player));
    p->unk_16c = 16;
    p->unk_16d = 0;
  }
  if ((u8)(boss->players[p->grabbedPlayer]->mashCount - (p->unk_876 - 0x100)) > 15) {
    p->unk_874 = 0;
  }
  if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_WILL_END) && !(gPlayerStates[0] & FLAG03002BC0_UNK_2) && p->unk_874 > 0 && p->phaseTimer <= 3) {
    p->sprites[0].animCmdIdx = 2;
    p->phaseTimer++;
  }
  if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) && ((gPlayerStates[0] & FLAG03002BC0_UNK_2) || p->unk_874 == 0 || p->phaseTimer > 3)) {
    boss->subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_0802f5e8.inc");
#endif
}

// 残差は dir の計算 (156/155): 原典は 4 方向に丸めた角度を符号なしで >> 5 し, & 7 の結果を定数側のレジスタに置く (FUN_0803446c と同じ壁)
NON_MATCH void FUN_0802fabc(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    boss->dir = ((((((mover->angle + 0x20) & 0xFF) >> 6 << 6) & 0xFF) >> 5) + 3) & 7;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (timer < 20) {
      Vec3_SetPolar(&mover->delta, mover->angle, 20 - timer);
    }
    if (p->unk_8e4 > 3) {
      if (p->unk_172 == 0) {
        FUN_08028838(p, 0, 0);
      } else {
        FUN_08028838(p, 1, 0);
      }
    }
    if (timer > 59) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802fabc.inc");
#endif
}

void dainn_0802fc08(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 68, 70), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if (p->unk_864) {
    FUN_08028084(p);
    if (p->unk_176) {
      Vec3* target;
      s32 dx, dz;

      p->unk_176--;
      target = &p->unk_868;
      dx = target->x - mover->pos.x;
      dz = target->z - mover->pos.z;
      if ((u32)(dx * dx + dz * dz) > 0x4000) {
        if (p->unk_177) {
          Vec3_SetPolar(&mover->delta, mover->angle, 24);
        } else {
          Vec3_SetPolar(&mover->delta, mover->angle, 10);
        }
      }
    }
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  if (p->sprites[0].animCmdIdx <= 11 || (p->sprites[0].animCmdIdx == 13 && timer <= 19)) {
    s32 mask = p->sprites[0].animCmdIdx <= 5 ? 7 : 1;
    s32 n = mask & timer;

    if (n == 0) {
      Ringo_AddAuxSprite(p, 0, p->sprites[0].animCmdIdx, boss->facing, 0);
    } else if (n == mask) {
      Ringo_AddAuxSprite(p, 0, p->sprites[0].animCmdIdx, boss->facing, 1);
    }
  }
  if (p->sprites[0].animCmdIdx == 8 && p->sprites[0].animCmdTimer == 0) {
    FUN_08028f08(p);
    if (p->unk_820) {
      PlaySound_0824078c(VO_DAINN_779);
    } else {
      PlaySound_0824078c(VO_RINGO_860);
    }
  }
  if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ADVANCED) && p->sprites[0].animCmdIdx == 12) {
    PlaySound_0824078c(SE_846);
  }
  if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
    boss->subStateDone = TRUE;
  }
}

void dainn_0802fea0(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 68, 70), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  if (p->sprites[0].animCmdIdx <= 11 || (p->sprites[0].animCmdIdx == 13 && timer <= 19)) {
    s32 mask = p->sprites[0].animCmdIdx <= 5 ? 7 : 1;
    s32 n = mask & timer;

    if (n == 0) {
      Ringo_AddAuxSprite(p, 1, p->sprites[0].animCmdIdx, boss->facing, 0);
    } else if (n == mask) {
      Ringo_AddAuxSprite(p, 1, p->sprites[0].animCmdIdx, boss->facing, 1);
    }
  }
  if (p->unk_864) {
    FUN_08028084(p);
    if (p->unk_176) {
      Vec3* target;
      s32 dx, dz;

      p->unk_176--;
      target = &p->unk_868;
      dx = target->x - mover->pos.x;
      dz = target->z - mover->pos.z;
      if ((u32)(dx * dx + dz * dz) > 0x4000) {
        if (p->unk_177) {
          Vec3_SetPolar(&mover->delta, mover->angle, 24);
        } else {
          Vec3_SetPolar(&mover->delta, mover->angle, 10);
        }
      }
    }
  }
  if (p->sprites[0].animCmdIdx == 8 && p->sprites[0].animCmdTimer == 0) {
    FUN_08029164(p, p->unk_892);
    if (p->unk_820) {
      PlaySound_0824078c(VO_DAINN_779);
    } else {
      PlaySound_0824078c(VO_RINGO_860);
    }
  }
  if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ADVANCED) && p->sprites[0].animCmdIdx == 12) {
    PlaySound_0824078c(SE_846);
  }
  if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
    boss->subStateDone = TRUE;
  }
}

// 残差は unk_8da を作る ~0x3F の定数のレジスタ (407/405), FUN_08030680 と同じ壁
NON_MATCH void FUN_08030148(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    Vec3* target;

    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
    target = boss->playerPos[p->targetPlayer];
    p->unk_844 = *target;
    FUN_08028604(p);
    FUN_0802853c(p, &p->unk_84c, p->unk_17c);
    FUN_08029a1c(p, p->unk_17c);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  switch (p->phase) {
    case 0: {
      Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
      if (p->unk_840 < p->unk_842) {
        FUN_08028648(p);
        FUN_080286d8(p);
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_KEEP_FRAME);
        if (p->unk_8e4 > 3) {
          FUN_08028838(p, 0, 0);
        }
      } else {
        p->phaseTimer = 0;
        p->phase++;
      }
      break;
    }
    case 1: {
      Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
      if (++p->phaseTimer > 9) {
        Mover* mover = &p->base.mover;

        p->unk_8da = ((mover->angle - 0x20) & ~0x3F) + 0x40;
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
        p->phaseTimer = 0;
        p->phase++;
      } else {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_KEEP_FRAME);
      }
      break;
    }
    case 2: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        if (++p->phaseTimer >= p->unk_17b) {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 60, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
          p->phase++;
        } else {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
        }
      }
      break;
    }
    case 3: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
        p->phase++;
      }
      break;
    }
  }
  if (p->phase == 2 && p->sprites[0].animCmdIdx == 1 && p->sprites[0].animCmdTimer == 0) {
    FUN_080292c8(p, 0);
  }
#else
  INCFUNC("asm/func/FUN_08030148.inc");
#endif
}

void FUN_080304c0(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, Angle_FromDir4(boss->facing));
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    if (p->phase == 1 && p->sprites[0].animCmdIdx == 1 && p->sprites[0].animCmdTimer == 0) {
      FUN_080292c8(p, 1);
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      switch (p->phase) {
        case 0: {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
          p->phase++;
          break;
        }
        case 1: {
          if (p->phaseTimer == 5) {
            Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 60, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
            p->phase++;
          } else {
            Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
            p->phaseTimer++;
          }
          break;
        }
        case 2: {
          boss->subStateDone = TRUE;
          break;
        }
      }
    }
  }
}

// 残差は unk_8da を作る ~0x3F の定数のレジスタ (335/334), 原典は定数を作ったレジスタでそのまま & する
NON_MATCH void FUN_08030680(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    Vec3* target;

    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
    target = boss->playerPos[p->targetPlayer];
    p->unk_844 = *target;
    FUN_08028604(p);
    FUN_0802853c(p, &p->unk_84c, 64);
    FUN_08029a1c(p, p->unk_17e);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  switch (p->phase) {
    case 0: {
      Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
      if (p->unk_840 < p->unk_842) {
        FUN_08028648(p);
        FUN_080286d8(p);
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_KEEP_FRAME);
        if (p->unk_8e4 > 3) {
          FUN_08028838(p, 0, 0);
        }
      } else {
        Mover* mover = &p->base.mover;

        p->unk_8da = ((mover->angle - 0x20) & ~0x3F) + 0x40;
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
        p->phase++;
      }
      break;
    }
    case 1: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        if (p->phaseTimer) {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 60, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
          p->phase++;
        } else {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
          p->phaseTimer++;
        }
      }
      break;
    }
    case 2: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
        p->phase = 3;
      }
      break;
    }
  }
  if (p->phase == 1 && p->sprites[0].animCmdIdx == 1 && p->sprites[0].animCmdTimer == 0) {
    FUN_080292c8(p, 2);
  }
#else
  INCFUNC("asm/func/FUN_08030680.inc");
#endif
}

void dainn_08030960(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    Vec3* target;
    Vec3* pos;

    boss->stateEntered = FALSE;
    target = &p->unk_868;
    FUN_08084734(target);
    pos = &mover->pos;
    Boss_SetAngle(boss, ArcTan2_8(target->x - mover->pos.x, target->z - pos->z));
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    if (!p->unk_87e) {
      if (p->unk_820) {
        PlaySound_082406e0(VO_DAINN_787);
      } else {
        PlaySound_082406e0(VO_RINGO_829);
      }
      p->unk_87e = TRUE;
    }
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    Vec3* target;
    s32 dx, dz;
    u32 distSq;

    FUN_08028084(p);
    target = &p->unk_868;
    dx = target->x - mover->pos.x;
    dz = target->z - mover->pos.z;
    distSq = DistSq(dx, dz);
    if (distSq < 0x2400) {
      mover->pos = *target;
      boss->subStateDone = TRUE;
    } else if (distSq < 0x4000) {
      Vec3_SetPolar(&mover->delta, mover->angle, 15);
    } else if (distSq > 0x100000) {
      Vec3_SetPolar(&mover->delta, mover->angle, 8);
    }
  }
}

void FUN_08030b80(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    Vec3* target;
    Vec3* pos;

    boss->stateEntered = FALSE;
    FUN_08084734(&p->unk_868);
    pos = &mover->pos;
    target = &p->unk_868;
    Boss_SetAngle(boss, ArcTan2_8(target->x - mover->pos.x, target->z - pos->z));
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    Vec3* target = &p->unk_868;
    s32 dx = target->x - mover->pos.x;
    s32 dz = target->z - mover->pos.z;

    if ((u32)(dx * dx + dz * dz) < 0x2400) {
      mover->pos = *target;
      boss->subStateDone = TRUE;
    } else {
      if (p->unk_177) {
        Vec3_SetPolar(&mover->delta, mover->angle, 32);
      } else {
        Vec3_SetPolar(&mover->delta, mover->angle, 12);
      }
      FUN_08028084(p);
      if (timer > 9) {
        boss->subStateDone = TRUE;
      }
    }
  }
}

// 残差は Ringo_SelectAnim の両分岐で &unk_820 をレジスタに残す形 (415/415), dainn_0802f134 と同じ壁
NON_MATCH void dainn_08030d6c(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 18, 22), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->unk_870 = 0;
    p->unk_168 = 0;
    if (p->unk_820) {
      PlaySound_082406e0(VO_DAINN_787);
    } else {
      PlaySound_082406e0(VO_RINGO_829);
    }
    FUN_080846c8();
    p->unk_16f = (Random() & 15) + 60;
    p->unk_170 = 0;
    Ringo_SetHurtboxPower(p, p->hurtboxPower2);
    p->hurtbox.flags &= ~HBFLAG_ANGLE;
  }
  if (boss->damageCallback(boss)) {
    Ringo_SetHurtboxPower(p, p->hurtboxPower);
    p->hurtbox.flags |= HBFLAG_ANGLE;
    return;
  }
  if (boss->stateRequestCallback(boss)) {
    Ringo_SetHurtboxPower(p, p->hurtboxPower);
    p->hurtbox.flags |= HBFLAG_ANGLE;
    return;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    p->unk_16e = Random();
    p->unk_16f = (Random() & 31) + 30;
    p->unk_16c = 12;
    if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_23)) {
      FUN_08028b00(p);
    }
    p->unk_168 = 60;
  }
  if (p->unk_16f) {
    if (--p->unk_16f == 0) {
      p->unk_170 = (p->unk_170 + 1) & 3;
      p->unk_16e = Random();
      if (p->unk_870 <= 300) {
        p->unk_16c = 8;
        if (p->unk_170 == 3) {
          p->unk_16f = (Random() & 31) + 60;
        } else {
          p->unk_16f = (Random() & 15) + 10;
        }
      } else if (p->unk_870 <= 450) {
        p->unk_16c = 8;
        if (p->unk_170 == 3) {
          p->unk_16f = (Random() & 15) + 30;
        } else {
          p->unk_16f = (Random() & 7) + 8;
        }
      } else {
        p->unk_16c = 6;
        if (p->unk_170 == 3) {
          p->unk_16f = (Random() & 15) + 15;
        } else {
          p->unk_16f = (Random() & 7) + 8;
        }
      }
    } else if (p->unk_168 == 0) {
      p->unk_16e = Random();
      p->unk_16c = 4;
    } else {
      p->unk_168--;
    }
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) && (p->unk_820 || Boss_GetHPRatio(boss) > 7) && p->unk_870 > 599) {
    boss->subStateDone = TRUE;
  }
  p->unk_870++;
#else
  INCFUNC("asm/func/dainn_08030d6c.inc");
#endif
}

// 1 回目で打ち切り (344/350), 原典は乱数表のアドレスを毎回プールから読み直し, &unk_820 を Ringo_SelectAnim からレジスタに残す
NON_MATCH void dainn_0803110c(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 19, 23), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if (p->phase <= 1 && p->unk_16f && --p->unk_16f == 0) {
    p->unk_16e = Random();
    p->unk_170 = (p->unk_170 + 1) & 3;
    p->unk_16c = 8;
    if (p->unk_170 == 3) {
      p->unk_16f = (Random() & 3) + 8;
    } else {
      p->unk_16f = (Random() & 3) + 8;
    }
  }
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 9) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 20, 24), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
        if (p->unk_820) {
          PlaySound_082406e0(VO_DAINN_779);
        } else {
          PlaySound_082406e0(VO_RINGO_860);
        }
        if (FUN_0802835c(p)) {
          Ringo_StartPlttFade(p, 0, 202);
        }
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 29) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 21, 25), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        FUN_080846f8();
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (FUN_0802835c(p) && p->sprites[0].animCmdIdx == 2) {
        boss->subStateDone = TRUE;
      }
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/dainn_0803110c.inc");
#endif
}

void dainn_0803141c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, 0x20);
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 45, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->phase = 1;
    p->phaseTimer = 0;
    p->unk_872 = 0;
    PlaySound_0824078c(VO_DAINN_LAUGH);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    switch (p->phase) {
      case 0: {
        if (++p->phaseTimer > 5) {
          Boss_SetAngle(boss, (mover->angle + 0x20) & ~0x1F);
          Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, 5, PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
          if (++p->unk_872 > 7 && boss->dir == 3) {
            Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 45, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
            p->phase++;
          }
          p->phaseTimer = 0;
        }
        break;
      }
      case 1: {
        if (timer == 20) {
          PlaySound_0824078c(SE_UNK_852);
        }
        if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
          boss->subStateDone = TRUE;
        }
        break;
      }
    }
  }
}

void FUN_080315e0(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_24);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  if (!boss->stateRequestCallback(boss)) {
    if (timer == 60) {
      mover->pos = *boss->playerPos[p->targetPlayer];
    }
    if (timer > 79) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803166c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    p->unk_872 = 0;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 45, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_UNK_851);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss) && p->phase == 0 && (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
    p->phase++;
  }
}

void FUN_08031734(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    p->unk_872 = 0;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 46, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_UNK_850);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_24);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss) && (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
  }
}

// 1 回目で打ち切り (816/816, 投影は WorldToScreen), 前半は FUN_08034b18 と同じ掴みの処理でスタック枠とレジスタがずれる
NON_MATCH void FUN_080317f0(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Player* player;

  if (boss->stateEntered) {
    MainSprite* sprite;
    Vec3 pos;
    Vec3* vp;

    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    p->unk_873 = 0;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 47, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    MainSprite_Show(&p->sprites[1]);
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 48, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    sprite = &p->sprite_a40;
    MainSprite_SetAnim(sprite, &p->gfx_a20, FUN_08028ec8(p), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    if (!boss->xflip) {
      sprite->flags |= SPRFLAG_XFLIP;
    } else {
      sprite->flags &= ~SPRFLAG_XFLIP;
    }
    p->unk_a18 = *boss->playerPos[p->grabbedPlayer];
    pos = p->sprites[0].pos;
    vp = &sprite->pos;
    WorldToScreen(vp, &pos);
    if (!boss->xflip) {
      sprite->pos.x += s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    } else {
      sprite->pos.x -= s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    }
    MainSprite_Show(sprite);
    p->unk_a14 = -1;
    p->unk_a16 = p->sprites[0].animCmdIdx;
    if (!boss->isDemo) {
      Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, NULL, 0, 0, 0, 1, 0, 2);
    }
    sprite->plttID = 0x4200;
    player = gPlayerPtr[p->grabbedPlayer];
    sprite->pltt = player->useAuxSprite == 0 ? player->human.pltt : player->beastGfx->pltt;
    p->unk_874 = 120;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_24);
  if (p->phase == 0 || p->phase == 5) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
    p->damage = 0;
    p->hitBySol = 0;
    p->unk_167 = 0;
  } else if (boss->damageCallback(boss)) {
    return;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW);
  if (boss->stateRequestCallback(boss)) {
    MainSprite_Hide(&p->sprites[1]);
    return;
  }
  if (p->phase >= 2 && p->phase <= 4) {
    player = boss->players[p->grabbedPlayer];
    if (p->unk_877 != player->mashCount) {
      p->unk_877 = player->mashCount;
      p->unk_16d++;
    }
    if (p->unk_16d > 3) {
      p->unk_16e = Angle_FromDir8(Player_GetDpadFacing(player));
      p->unk_16c = 16;
      p->unk_16d = 0;
    }
  }
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 49, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 50, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 51, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 52, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
        if (p->grabbedPlayer >= 0) {
          p->unk_876 = p->unk_877 = boss->players[p->grabbedPlayer]->mashCount;
        }
        p->unk_16c = 0;
        p->unk_16d = 0;
      }
      break;
    }
    case 2: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 53, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 54, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 3: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 55, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_Hide(&p->sprites[1]);
        MainSprite_Hide(&p->sprite_a40);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 4: {
      if (++p->phaseTimer > 4) {
        if ((gPlayerStates[0] & FLAG03002BC0_UNK_2) || (u8)(boss->players[p->grabbedPlayer]->mashCount - (p->unk_876 - 0x100)) > 15) {
          p->unk_874 = 0;
        }
        if (p->unk_874 <= 0) {
          Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 56, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          MainSprite_Hide(&p->sprite_a40);
          if (!boss->isDemo && p->grabbedPlayer >= 0) {
            Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->playerAngle[p->grabbedPlayer], 50, 0, 0, 0);
          }
          p->grabbedPlayer = -1;
          p->phase++;
        } else if (++p->unk_873 > 7) {
          Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 56, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          p->phase++;
        } else {
          Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 53, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          MainSprite_SetAnim(&p->sprites[1], &p->gfx, 54, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          MainSprite_Show(&p->sprites[1]);
          MainSprite_Show(&p->sprite_a40);
          p->phase = 2;
        }
        p->phaseTimer = 0;
      }
      break;
    }
    case 5: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  p->sprites[1].pos = p->sprites[0].pos;
#else
  INCFUNC("asm/func/FUN_080317f0.inc");
#endif
}

void FUN_08031f14(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 47, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    MainSprite_Show(&p->sprites[1]);
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 48, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_24);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW);
  if (boss->stateRequestCallback(boss)) {
    MainSprite_Hide(&p->sprites[1]);
    return;
  }
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 49, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 50, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 51, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 52, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 53, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 54, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 3: {
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_22);
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 56, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_Hide(&p->sprites[1]);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 4: {
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_22);
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  p->sprites[1].pos = p->sprites[0].pos;
}

// 残差は grabbedPlayer まわりのレジスタ (269/268), 原典は &grabbedPlayer を r5 に残し playerAngle を boss の複写から読む
NON_MATCH void FUN_08032180(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_24);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW);
  if (boss->stateRequestCallback(boss)) {
    return;
  }
  switch (p->phase) {
    case 0: {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_22);
      SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
      if (++p->phaseTimer > 29) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_22);
      SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
      if (p->phaseTimer <= 60 && (p->phaseTimer & 15) == 0) {
        s32 damage;
        s32 hp;

        FUN_08022c24(boss, 4, 20);
        damage = Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, 0, 0, 0, 0, 1, p->unk_8c8, 2);
        hp = boss->hp;
        Boss_SetHP(boss, hp + damage);
        if (hp != boss->hp) {
          HitboxData* hurtbox = &p->hurtbox;
          Vec3 ofs;

          VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
          CreateDamageNumber(hurtbox, damage, 1, &boss->mover.pos, &ofs, 1);
        }
        PlaySound_0824078c(SE_DAMAGE);
      }
      if (++p->phaseTimer > 79 || (gPlayerStates[0] & FLAG03002BC0_UNK_2)) {
        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 57, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_Hide(&p->sprite_a40);
        if (!boss->isDemo && p->grabbedPlayer >= 0) {
          Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->playerAngle[p->grabbedPlayer], 50, 0, 0, 0);
        }
        p->grabbedPlayer = -1;
      }
      break;
    }
    case 2: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08032180.inc");
#endif
}

// 残差は pltt の差し替え (611/608), FUN_080353ac と同じ壁
NON_MATCH void dainn_080323c8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  Boss_SetAngle(boss, boss->playerAngle[p->targetPlayer]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 19, 23), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
    gBgPlttBlendColor = RGB(4, 4, 4);
    gBgPlttFadeRowMask = 0x1FFF;
    p->unk_1044 = 900;
    PlaySound_0824078c(SE_UNK_849);
    PlaySound_0824078c(VO_DAINN_780);
  }
  if (boss->damageCallback(boss)) {
    u32 plttID;

    p->plttFade = 0;
    p->plttFadeMode = -1;
    p->plttFadeTo = Ringo_GetPlttID(p);
    plttID = Ringo_GetPlttID(p);
    if (plttID == 0) {
      p->sprites[0].pltt = p->pltt[0];
    } else {
      p->sprites[0].pltt = &gObjPlttData[plttID * 16];
    }
    p->sprites[1].pltt = p->sprites[0].pltt;
    return;
  }
  if (boss->stateRequestCallback(boss)) {
    u32 plttID;

    p->plttFade = 0;
    p->plttFadeMode = -1;
    p->plttFadeTo = Ringo_GetPlttID(p);
    plttID = Ringo_GetPlttID(p);
    if (plttID == 0) {
      p->sprites[0].pltt = p->pltt[0];
    } else {
      p->sprites[0].pltt = &gObjPlttData[plttID * 16];
    }
    p->sprites[1].pltt = p->sprites[0].pltt;
    return;
  }
  Ringo_UpdateHover(p, timer);
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 7) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 20, 24), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
        p->plttFadeMode = 2;
        p->plttFade = 32;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 23) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 21, 25), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (timer > 127) {
        u32 plttID;

        Boss_SetAngle(boss, 0x20);
        Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
        p->plttFade = 0;
        p->plttFadeMode = -1;
        p->plttFadeTo = Ringo_GetPlttID(p);
        plttID = Ringo_GetPlttID(p);
        if (plttID == 0) {
          p->sprites[0].pltt = p->pltt[0];
        } else {
          p->sprites[0].pltt = &gObjPlttData[plttID * 16];
        }
        p->sprites[1].pltt = p->sprites[0].pltt;
      } else if ((timer & 3) == 0) {
        u32 angle = boss->playerAngle[p->targetPlayer] + (Random() & 0x1F) - 0x10;
        Vec3 pos;

        Vec3_SetPolar(&pos, angle, 256);
        Vec3_Add(&pos, &boss->mover.pos);
        pos.y += 0xA4;
        FUN_0805b7d4(p->entity0805b790, &pos, boss->playerPos[p->targetPlayer], 0, angle, 20, p->unk_8ca, 50);
      }
      break;
    }
    case 3: {
      if (++p->phaseTimer > 9) {
        p->phase++;
        p->phaseTimer = 0;
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/dainn_080323c8.inc");
#endif
}

void FUN_08032934(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN | BOSSFLAG_NO_SHADOW);
  boss->stateRequestCallback(boss);
}

// 残差はゼロ定数の持ち方 (140/149), 原典は stateEntered と Ringo_StartPlttFade の else 側, phase と == 0 側でそれぞれ 0 のレジスタを共有して r7 / r8 に置く
NON_MATCH void FUN_08032988(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, 0x40);
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 65, PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    Ringo_StartPlttFade(p, 1, 202);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss) && (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED)) {
    if (p->phase == 0) {
      Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 64, PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
      p->phase++;
    } else {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_08032988.inc");
#endif
}

void FUN_08032bac(Boss* boss, s32 timer);

void FUN_08032acc(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 18, 22), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    FUN_080846f8();
    FUN_08029c2c(p);
    PlaySound_0824078c(SONG_453);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  Ringo_SetUnk18a(p, 8);
  if ((timer & 3) == 0) {
    FUN_0802991c(p);
  }
  if (timer > 119) {
    Boss_SetState(boss, FUN_08032bac, 32);
  }
}

// 残差は pltt の差し替え (288/285), FUN_080353ac と同じ壁
NON_MATCH void FUN_08032bac(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    u32 plttID;

    boss->stateEntered = FALSE;
    FUN_080298fc(p);
    Boss_SetAngle(boss, 0x80);
    boss->dir = Angle_ToDir8(Angle_FromDir4(Angle_ToDir4(mover->angle + 0x80)));
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    plttID = Ringo_GetPlttID(p);
    if (plttID == 0) {
      p->sprites[0].pltt = p->pltt[0];
    } else {
      p->sprites[0].pltt = &gObjPlttData[plttID * 16];
    }
    p->sprites[1].pltt = p->sprites[0].pltt;
    FUN_08029c74(p);
    p->numPlayers = 1;
    if (p->scriptID && !(gPlayerStates[0] & FLAG03002BC0_UNK_2)) {
      VM_ExecByID(p->scriptID, NULL);
    }
    FUN_08015a90(&mover->pos, 3, 2, 0x3000, 0x40, 8, 0x100, 0x100);
    FUN_08015a90(&mover->pos, 5, 2, 0x3000, 0x40, 10, 0x100, 0x100);
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if ((timer & 3) == 0) {
    FUN_0802991c(p);
  }
  if (timer < 16) {
    Vec3_SetPolar(&mover->delta, mover->angle, 42 - timer * 2);
  }
  if (timer == 30) {
    Boss_SetState(boss, FUN_0802e520, 1);
    if (p->scriptID2 && !(gPlayerStates[0] & FLAG03002BC0_UNK_2)) {
      VM_ExecByID(p->scriptID2, NULL);
    }
  }
#else
  INCFUNC("asm/func/FUN_08032bac.inc");
#endif
}

// 1 回目で打ち切り (110/114), 原典は timer を r8 に持ち &unk_820 を PlayAnim の後まで使い回す
NON_MATCH void FUN_08032e1c(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 72, 73), PLAYMODE_ONCE_AND_STOP, 0);
    if (p->unk_820 == 0) {
      FUN_0802a538(p);
    }
    Boss_GiveWeaponExp(boss, p->weaponExp);
    FUN_08022fb8(boss, &p->sprites[0].pos);
    FUN_080846f8();
    p->unk_1044 = 0;
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer == 256) {
    FUN_08023024(boss, &p->sprites[0].pos);
  }
#else
  INCFUNC("asm/func/FUN_08032e1c.inc");
#endif
}

// 残差は case 3 の pltt の差し替え (433/430), FUN_080353ac と同じ壁
NON_MATCH void dainn_08032f18(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 10, 14), PLAYMODE_LOOP, 2, MAIN_ANIM_FORCE_POSE);
    Boss_GiveWeaponExp(boss, p->weaponExp);
    FUN_08022fb8(boss, &p->sprites[0].pos);
    p->unk_1044 = 0;
    p->unk_854 = mover->pos;
    p->phase = 0;
    p->phaseTimer = 0;
    PlaySound_0824078c(VO_DAINN_DEATH);
    PlaySound_0824078c(SONG_453);
    if (p->entity0805b068 != NULL) {
      FUN_0805b1a0(p->entity0805b068);
    }
  }
  if (p->hoverHeight > 3) {
    p->hoverHeight -= 4;
  } else {
    p->hoverHeight = 0;
  }
  if (p->spriteOffsetY > 3) {
    p->spriteOffsetY -= 4;
  } else {
    p->spriteOffsetY = 0;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  switch (p->phase) {
    case 0: {
      Ringo_SetUnk18a(p, 8);
      if ((timer & 3) == 0) {
        FUN_0802991c(p);
      }
      if (++p->phaseTimer > 119) {
        p->phase++;
        p->phaseTimer = 0;
        FUN_08029cc8(p);
        PlaySound_0824078c(VO_RINGO_DEFEATED);
        PlaySound_0824078c(SONG_453);
      }
      break;
    }
    case 1: {
      Ringo_SetUnk18a(p, 8);
      if ((timer & 3) == 0) {
        FUN_0802991c(p);
      }
      if (++p->phaseTimer > 59) {
        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 22, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
      break;
    }
    case 2: {
      LerpVec3(&mover->pos, &p->unk_854, &p->unk_fd8, p->phaseTimer, 7);
      if ((timer & 3) == 0) {
        FUN_0802991c(p);
      }
      if (++p->phaseTimer > 128) {
        rgb555* pltt;

        p->phase++;
        p->phaseTimer = 0;
        p->unk_fd4 = 0;
        p->plttFade = 0;
        p->plttFadeMode = -1;
        p->plttFadeTo = 193;
        pltt = &gObjPlttData[p->plttFadeTo * 16];
        p->sprites[0].pltt = pltt;
        p->sprites[1].pltt = pltt;
        PlaySound_082406e0(SONG_827);
      } else {
        Ringo_SetUnk18a(p, 8);
      }
      break;
    }
    case 3: {
      if (p->phaseTimer < 32) {
        Ringo_SetUnk18a(p, 4);
      }
      if (p->phaseTimer == 32) {
        Ringo_StartPlttFade(p, 3, 198);
      }
      if (++p->phaseTimer > 96) {
        u32 plttID;

        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 72, 73), PLAYMODE_ONCE_AND_STOP, 0);
        plttID = Ringo_GetPlttID(p);
        if (plttID == 0) {
          p->sprites[0].pltt = p->pltt[0];
        } else {
          p->sprites[0].pltt = &gObjPlttData[plttID * 16];
        }
        p->sprites[1].pltt = p->sprites[0].pltt;
      }
      break;
    }
    case 4: {
      if (p->phaseTimer == 16) {
        PlaySound_082406e0(SE_826);
      }
      if (++p->phaseTimer > 128) {
        p->phase++;
        p->phaseTimer = 0;
        FUN_08023024(boss, &p->sprites[0].pos);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/dainn_08032f18.inc");
#endif
}

void FUN_0803331c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

void FUN_080333a4(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 74, 76), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

void FUN_080334b4(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Ringo_UpdateHover(p, timer);
  }
}

void FUN_080335e8(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    FUN_08029a1c(p, p->unk_17e);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Vec3* target;
    s32 dx, dz, distSq;
    u32 angle;

    Ringo_UpdateHover(p, timer);
    if (p->unk_8e4 > 3) {
      FUN_08028838(p, 0, 0);
    }
    target = &p->unk_84c;
    dx = target->x - mover->pos.x;
    dz = target->z - mover->pos.z;
    distSq = dx * dx + dz * dz;
    angle = ArcTan2_8(dx, dz);
    if (distSq <= 900) {
      boss->subStateDone = TRUE;
      mover->pos = *target;
    } else {
      Vec3_SetPolar(&mover->delta, angle, 20);
    }
  }
}

void FUN_080337b8(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 74, 76), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 74, 76), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    s8 d = mover->angle - boss->destAngle;

    if (abs(d) <= 7) {
      Boss_SetAngle(boss, boss->destAngle);
      boss->subStateDone = TRUE;
    } else {
      Boss_SetAngle(boss, d < 0 ? mover->angle + 8 : mover->angle - 8);
    }
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

void FUN_08033970(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    s8 d = mover->angle - boss->destAngle;

    if (abs(d) <= 7) {
      Boss_SetAngle(boss, boss->destAngle);
      boss->subStateDone = TRUE;
    } else {
      Boss_SetAngle(boss, d < 0 ? mover->angle + 8 : mover->angle - 8);
    }
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

// 1 回目で打ち切り (139/145), FUN_08033c60 と同じ 0 : 5 の三項演算子の畳み込みが主
NON_MATCH void FUN_08033b28(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
    boss->targetPos = mover->pos;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_NO_SHADOW);
  if (!boss->stateRequestCallback(boss)) {
    mover->pos = boss->targetPos;
    if (timer > 31) {
      boss->subStateDone = TRUE;
    } else {
      Vec3_SetPolar(&mover->delta, (3 & ~timer) << 6, (32 - timer) * 8);
    }
  }
#else
  INCFUNC("asm/func/FUN_08033b28.inc");
#endif
}

void FUN_08033c60(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 0, 5), PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    boss->targetPos = mover->pos;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_NO_SHADOW);
  if (!boss->stateRequestCallback(boss)) {
    mover->pos = boss->targetPos;
    Vec3_SetPolar(&mover->delta, (timer & 3) << 6, timer * 8);
    if (timer > 31) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_08033d84(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 10, 14), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    boss->targetPos = mover->pos;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Ringo_SetUnk18a(p, 4);
  }
}

void FUN_08034014(Boss* boss, s32 timer);

void FUN_08033e3c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    Vec3* target;
    Vec3* pos;

    boss->stateEntered = FALSE;
    pos = &mover->pos;
    target = &p->unk_84c;
    boss->destAngle = ArcTan2_8(target->x - mover->pos.x, target->z - pos->z);
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (timer < 64) {
      Vec3_SetPolar(&mover->delta, mover->angle, -((64 - timer) >> 3));
    }
    if (timer >= 64) {
      Boss_SetState(boss, FUN_08034014, 45);
    }
  }
}

void FUN_08034014(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 36, 40), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_842);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Vec3* target;
    s32 dx, dz;

    if (p->unk_8e4 > 3) {
      if (p->unk_172 == 0) {
        FUN_08028838(p, 0, 0);
      } else {
        FUN_08028838(p, 1, 0);
      }
    }
    target = &p->unk_84c;
    dx = target->x - mover->pos.x;
    dz = target->z - mover->pos.z;
    if (dx * dx + dz * dz < 0x640) {
      mover->pos = *target;
      boss->subStateDone = TRUE;
    } else {
      Vec3_SetPolar(&mover->delta, mover->angle, 40);
    }
    if (timer == 300) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803419c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 37, 41), PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_843);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->sprites[0].animCmdIdx == 3 || p->sprites[0].animCmdIdx == 4) {
      SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803427c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    Vec3* target;
    Vec3* pos;

    boss->stateEntered = FALSE;
    pos = &mover->pos;
    target = &p->unk_84c;
    boss->destAngle = ArcTan2_8(target->x - mover->pos.x, target->z - pos->z);
    Boss_SetAngle(boss, boss->destAngle + 0x80);
    Boss_PlayAnimDir8(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 26, 31), PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Vec3* target;
    s32 dx, dz;

    if (p->unk_8e4 > 3) {
      if (p->unk_172 == 0) {
        FUN_08028838(p, 0, 0);
      } else {
        FUN_08028838(p, 1, 0);
      }
    }
    target = &p->unk_84c;
    dx = target->x - mover->pos.x;
    dz = target->z - mover->pos.z;
    if (dx * dx + dz * dz < 0x640) {
      mover->pos = *target;
      boss->subStateDone = TRUE;
    } else {
      Vec3_SetPolar(&mover->delta, mover->angle, -40);
    }
    if (timer == 300) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803446c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 58, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_WILL_END) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_08034570(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 59, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    switch (p->phase) {
      case 0: {
        if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
          Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 60, PLAYMODE_ONCE_AND_STOP, 3, MAIN_ANIM_FORCE_POSE);
          p->phase++;
        }
        break;
      }
      case 1: {
        if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
          boss->subStateDone = TRUE;
          p->phase++;
        }
        break;
      }
    }
    if (p->phase == 0 && p->sprites[0].animCmdIdx == 1 && p->sprites[0].animCmdTimer == 0) {
      p->unk_8da = mover->angle;
      FUN_080292c8(p, 3);
    }
  }
}

void FUN_080346cc(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, 0x20);
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 18, 22), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(VO_RINGO_DEFEATED);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    Ringo_SetUnk18a(p, 8);
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
      p->phase++;
    }
  }
}

void FUN_08034804(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 72, 73), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) && p->phase == 0) {
      Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 81, 82), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      boss->subStateDone = TRUE;
      p->phase++;
    }
  }
}

void FUN_0803495c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 81, 82), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

void FUN_08034a2c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 82, 84), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
}

// 1 回目で打ち切り (313/313, 投影は WorldToScreen), スタック枠とレジスタの割り当てが大きくずれる
NON_MATCH void FUN_08034b18(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    MainSprite* sprite;
    Vec3 pos;
    Vec3* vp;
    Vec3 ofs;
    s32 d;
    Player* player;

    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 87, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    sprite = &p->sprite_a40;
    MainSprite_SetAnim(sprite, &p->gfx_a20, FUN_08028ec8(p), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    if (!boss->xflip) {
      sprite->flags |= SPRFLAG_XFLIP;
    } else {
      sprite->flags &= ~SPRFLAG_XFLIP;
    }
    p->unk_a18 = *boss->playerPos[p->grabbedPlayer];
    pos = p->sprites[0].pos;
    vp = &sprite->pos;
    WorldToScreen(vp, &pos);
    if (!boss->xflip) {
      sprite->pos.x += s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    } else {
      sprite->pos.x -= s8_ARRAY_085aabbc[0][0];
      sprite->pos.y += s8_ARRAY_085aabbc[0][1];
    }
    MainSprite_Show(sprite);
    p->unk_a14 = -1;
    p->unk_a16 = p->sprites[0].animCmdIdx;
    d = !boss->xflip ? 32 : -32;
    ofs.x = d;
    ofs.z = d;
    ofs.y = 160;
    if (!boss->isDemo) {
      Player_HoldGrabbed(gPlayerPtr[p->grabbedPlayer], &p->sprites[0].pos, &ofs, 0, 0, 0, 1, 0, 2);
    }
    sprite->plttID = 0x4200;
    player = gPlayerPtr[p->grabbedPlayer];
    sprite->pltt = player->useAuxSprite == 0 ? player->human.pltt : player->beastGfx->pltt;
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss) && (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08034b18.inc");
#endif
}

// 残差は p のレジスタの持ち方と &grabbedPlayer を作る位置 (105/103)
NON_MATCH void FUN_08034dd8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 88, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (timer == 5) {
      MainSprite_Hide(&p->sprite_a40);
      if (!boss->isDemo && p->grabbedPlayer >= 0) {
        Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->mover.angle, 50, 0, 0, 0);
      }
      p->grabbedPlayer = -1;
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_08034dd8.inc");
#endif
}

// 1 回目で打ち切り (431/422), 定数の作り直しとレジスタの割り当てがずれる, FUN_08031f14 と同形
NON_MATCH void FUN_08034ebc(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    p->unk_874 = 1;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 47, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    MainSprite_Show(&p->sprites[1]);
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 48, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  if (boss->stateRequestCallback(boss)) {
    MainSprite_Hide(&p->sprites[1]);
    return;
  }
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 49, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 50, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 51, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 52, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
        if (p->grabbedPlayer >= 0) {
          p->unk_876 = p->unk_877 = boss->players[p->grabbedPlayer]->mashCount;
        }
        p->unk_16c = 0;
        p->unk_16d = 0;
      }
      break;
    }
    case 2: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 53, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprites[1], &p->gfx, 54, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 3: {
      if (++p->phaseTimer > 4) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 55, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_Hide(&p->sprites[1]);
        MainSprite_Hide(&p->sprite_a40);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 4: {
      if (++p->phaseTimer > 4) {
        if (p->unk_874 <= 0) {
          Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 56, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          MainSprite_Hide(&p->sprite_a40);
          if (!boss->isDemo && p->grabbedPlayer >= 0) {
            Player_ReleaseGrabbed(gPlayerPtr[p->grabbedPlayer], &p->unk_a18, 50, boss->playerAngle[p->grabbedPlayer], 50, 0, 0, 0);
          }
          p->grabbedPlayer = -1;
        } else {
          Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 56, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        }
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 5: {
      if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  p->sprites[1].pos = p->sprites[0].pos;
#else
  INCFUNC("asm/func/FUN_08034ebc.inc");
#endif
}

void FUN_08035268(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 18, 22), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    Ringo_StartPlttFade(p, 0, 202);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    Ringo_SetUnk18a(p, 8);
    if ((p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) && timer > 31) {
      boss->subStateDone = TRUE;
    }
  }
}

// 残差は末尾の pltt の差し替え (216/213), 原典は両分岐で &sprites[0].pltt を作って合流後もそのアドレスから読み直す, 三項演算子と両分岐に複製する形は試済
NON_MATCH void FUN_080353ac(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    boss->destAngle = 0x20;
    Boss_SetAngle(boss, 0x20);
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 18, 22), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    Ringo_StartPlttFade(p, 4, 198);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Ringo_UpdateHover(p, timer);
    if (timer < 64) {
      Ringo_SetUnk18a(p, 4);
    } else if (timer < 128) {
      Ringo_SetUnk18a(p, 2);
    }
    if (timer == 164) {
      u32 plttID;

      boss->subStateDone = TRUE;
      p->unk_824 = 2;
      plttID = Ringo_GetPlttID(p);
      if (plttID == 0) {
        p->sprites[0].pltt = p->pltt[0];
      } else {
        p->sprites[0].pltt = &gObjPlttData[plttID * 16];
      }
      p->sprites[1].pltt = p->sprites[0].pltt;
    }
  }
#else
  INCFUNC("asm/func/FUN_080353ac.inc");
#endif
}

void FUN_0803558c(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 85, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
  }
}

void FUN_08035634(Boss* boss, s32 timer) {
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 86, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (p->hoverHeight > 3) {
      p->hoverHeight -= 4;
    } else {
      p->hoverHeight = 0;
    }
    if (p->spriteOffsetY > 3) {
      p->spriteOffsetY -= 4;
    } else {
      p->spriteOffsetY = 0;
    }
    if (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
}

// 1 回目で打ち切り (374/375), p と boss のレジスタが入れ替わり退避レジスタが 1 本多い
NON_MATCH void FUN_080356f8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Ringo* p = (Ringo*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->phase = 0;
    p->phaseTimer = 0;
    Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 20, 24), PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    Ringo_StartPlttFade(p, 6, 206);
  }
  p->damage = 0;
  p->hitBySol = 0;
  p->unk_167 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (boss->stateRequestCallback(boss)) {
    return;
  }
  Ringo_UpdateHover(p, timer);
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer > 29) {
        Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, Ringo_SelectAnim(p, 21, 25), PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      Ringo_SetUnk18a(p, 4);
      break;
    }
    case 1: {
      if (++p->phaseTimer > 179 && (p->sprites[0].animEvents & MAIN_ANIM_EVENT_ENDED)) {
        boss->subStateDone = TRUE;
        p->phase++;
        p->phaseTimer = 0;
      }
      Ringo_SetUnk18a(p, 4);
      break;
    }
    case 2: {
      Ringo_SetUnk18a(p, 4);
      break;
    }
  }
  if (p->phase == 0) {
    if ((boss->frameCount & 15) == 0) {
      FUN_08028cb0(p);
    }
  } else if (!(boss->frameCount & 1)) {
    Vec3 pos;
    u8 angle = Random();
    u32 radius = Random() & 0x3F;

    Vec3_SetPolar(&pos, angle, radius);
    Vec3_Add(&pos, &p->sprites[0].pos);
    pos.y += 0x100;
    Entity08060470_Spawn(Random(), (Random() & 0xF) + 0x10, 0x10, &pos);
  }
#else
  INCFUNC("asm/func/FUN_080356f8.inc");
#endif
}

void FUN_08035a3c(Ringo* p) {
  u32 mask;

  p->base.subStateDone = FALSE;
  mask = FLAG03002BC0_UNK_2;
  if (!(gPlayerStates[0] & mask)) {
    Boss_UpdateState(&p->base);
  }
}

// clang-format off
void (*const PTR_ARRAY_085aad38[62])(Boss*, s32) = {
    NULL,
    FUN_0802e520,
    FUN_0802e6ac,
    FUN_0802e8d0,
    FUN_0802eac0,
    FUN_0802ece0,
    FUN_0802ef68,
    dainn_0802f134,
    FUN_0802f368,
    FUN_0802f4a8,
    FUN_0802f5e8,
    FUN_0802fabc,
    dainn_0802fc08,
    dainn_0802fea0,
    FUN_08030148,
    FUN_080304c0,
    FUN_08030680,
    dainn_08030960,
    FUN_08030b80,
    dainn_08030d6c,
    dainn_0803110c,
    dainn_0803141c,
    FUN_080315e0,
    FUN_0803166c,
    FUN_08031734,
    FUN_080317f0,
    FUN_08031f14,
    FUN_08032180,
    dainn_080323c8,
    FUN_08032934,
    FUN_08032988,
    FUN_08032acc,
    FUN_08032bac,
    FUN_08032e1c,
    dainn_08032f18,
    FUN_0803331c,
    FUN_080333a4,
    FUN_080334b4,
    FUN_080335e8,
    FUN_080337b8,
    FUN_08033970,
    FUN_08033b28,
    FUN_08033c60,
    FUN_08033d84,
    FUN_08033e3c,
    FUN_08034014,
    FUN_0803419c,
    FUN_0803427c,
    FUN_0803446c,
    FUN_08034570,
    FUN_080346cc,
    FUN_08034804,
    FUN_0803495c,
    FUN_08034a2c,
    FUN_08034b18,
    FUN_08034dd8,
    FUN_08034ebc,
    FUN_08035268,
    FUN_080353ac,
    FUN_0803558c,
    FUN_08035634,
    FUN_080356f8,
};  // 0x085AAD38
// clang-format on

s32 FUN_08035a64(Ringo* p) {
  if (p->base.state == 0 || p->base.state > 62) {
    return FALSE;
  } else {
    Boss_SetState(&p->base, PTR_ARRAY_085aad38[p->base.state], p->base.state);
    return TRUE;
  }
}

// 1 回目で打ち切り (419/416), 退避枠の並びとレジスタの割り当てがずれる
NON_MATCH s32 Ringo_HandleDamage(Ringo* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &p->base.mover;
  HitboxData* hurtbox = &p->hurtbox;
  s32 damage = p->damage;
  u8 attr = p->hitBySol;
  bool32 chained;

  p->damage = 0;
  p->unk_167 = 0;
  p->hitBySol = 0;
  if (p->unk_18c == 0) {
    if (p->unk_188 == 0 && FUN_080299e0(p)) {
      Vec3 size;

      damage = (gStat->sunGauge * boss->maxHP) >> 5;
      VEC3_SET(size, Q8(0.641), Q8(1), Q8(0.641));
      EmitSmoke(&p->sprites[0].pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
      EmitSmoke(&p->sprites[0].pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
      p->unk_18c = 60;
    }
  } else {
    p->unk_18c--;
  }
  if (damage > 0) {
    Vec3 ofs;

    boss->hp -= damage;
    chained = FALSE;
    if (p->unk_820) {
      if (boss->hp <= boss->maxHP / 2 && !p->unk_fd4) {
        boss->hp = boss->maxHP / 2;
        if (boss->curState == 19) {
          p->unk_fd8 = p->sprites[0].pos;
          p->unk_fd7 = 16;
          chained = TRUE;
        }
      }
    } else if (boss->curState != 19 && boss->hp <= 0) {
      boss->hp = 1;
    }
    p->unk_188 = 15;
    p->unk_186 = 10;
    p->sprites[0].pltt = p->pltt[0];
    p->sprites[1].pltt = p->pltt[0];
    VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
    CreateDamageNumber(hurtbox, damage, 0, &mover->pos, &ofs, 1);
    if (boss->hp <= 0) {
      boss->hp = 0;
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_1);
      if (p->unk_820) {
        Boss_SetState(boss, dainn_08032f18, 34);
        PlaySound_0824078c(SONG_973);
      } else {
        Boss_SetState(boss, FUN_08032e1c, 33);
        PlaySound_0824078c(SONG_848);
      }
      return TRUE;
    }
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_17);
    if (attr) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_23);
    }
    p->unk_874 -= 40;
    if (p->unk_874 < 0) {
      p->unk_874 = 0;
    }
    p->unk_870 += 100;
    if (p->unk_870 > 599) {
      p->unk_870 = 600;
    }
    Ringo_SetUnk18a(p, 8);
    if (p->unk_fd4) {
      PlaySound_0824078c(SE_ENEMY_DAMAGED);
    } else if (boss->curState == 19) {
      if (p->unk_820) {
        PlaySound_0824078c(SE_DAINN_STUN_BY_RINGO_BAT);
      } else {
        PlaySound_0824078c(SONG_847);
      }
    } else {
      PlaySound_0824078c(SE_ENEMY_DAMAGED);
    }
    if (chained) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_0);
      Boss_SetState(boss, FUN_08032acc, 31);
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Ringo_HandleDamage.inc");
#endif
}

s32 Ringo_Update(Ringo* p) {
  FUN_0802ae4c(p);
  FUN_0802e4fc(p);
  FUN_08035a3c(p);
  FUN_0802b074(p);
  return 0;
}

s32 Ringo_Destroy(Ringo* p) {
  AuxShadow_Remove(&p->shadow);
  Ringo_UnregisterHurtboxes(p);
  FUN_08028818(p);
  FUN_08028eb8(p);
  Ringo_RemoveAuxSprites(p);
  FUN_0802a2e0(p);
  FUN_08029b30(p);
  MainSprite_Remove(&p->sprites[0]);
  MainSprite_Remove(&p->sprites[1]);
  Boss_Destroy(&p->base);
  return 0;
}

// 1 回目で打ち切り (878/868), 退避枠が 1 つ多く pltt の差し替えは FUN_080353ac と同じ壁
NON_MATCH s32 Ringo_Init(Ringo* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', 0);
  MainSpriteGfxFile* f;
  Vec3 pos;
  u32 angle;
  s32 hp;
  s32 i;
  u32 plttID;
  rgb555* src;
  rgb555* dst;

  Boss_Register(boss, bossID);
  p->unk_820 = VM_GetNamedArgValue('S', 0);
  p->unk_824 = VM_GetNamedArgValue('R', 0);
  p->numPlayers = VM_GetNamedArgValue('P', 2);
  for (i = 0; i < p->numPlayers; i++) {
    if (gPlayerPtr[i] != NULL) {
      boss->players[i] = gPlayerPtr[i];
      boss->playerPos[i] = &gPlayerPtr[i]->mover.pos;
    } else {
      boss->players[i] = NULL;
      boss->playerPos[i] = NULL;
    }
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_RINGO);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
    angle = 0x40;
  }
  p->unk_164 = pos.y;
  FUN_08084734(&p->unk_868);
  p->unk_844 = p->unk_868;
  FUN_08028604(p);
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    p->hurtboxPower = VM_GetValue();
    p->hurtboxPower2 = VM_GetValue();
    p->hurtboxPower3 = VM_GetValue();
    p->unk_8d2 = VM_GetValue();
    p->unk_8d6 = VM_GetValue();
  } else {
    hp = 1000;
    p->hurtboxPower = 999;
    p->hurtboxPower2 = 10;
    p->hurtboxPower3 = 100;
    p->unk_8d2 = 300;
    p->unk_8d6 = 600;
  }
  p->unk_8db = 0x60;
  p->unk_8dc = 0x30;
  p->unk_17e = p->unk_8db;
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    p->hitbox2Power = VM_GetValue();
    p->hitbox2Knockback = VM_GetValue();
    p->hitbox2Unk44 = VM_GetValue();
    p->unk_8c4 = VM_GetValue();
    p->unk_8c6 = VM_GetValue();
    p->unk_8c8 = VM_GetValue();
    p->unk_8ca = VM_GetValue();
  } else {
    p->hitboxPower = 25;
    p->hitboxKnockback = 50;
    p->hitboxUnk44 = 60;
    p->hitbox2Power = 50;
    p->hitbox2Knockback = 50;
    p->hitbox2Unk44 = 60;
    p->unk_8c4 = 8;
    p->unk_8c6 = 16;
    p->unk_8c8 = 10;
    p->unk_8ca = 50;
  }
  if (VM_SeekToNamedArg('g')) {
    p->unk_8b4 = VM_GetValue();
    p->unk_8b6 = VM_GetValue();
    p->unk_8b8 = VM_GetValue();
  } else {
    p->unk_8b4 = 70;
    p->unk_8b6 = 80;
    p->unk_8b8 = 65;
  }
  if (VM_SeekToNamedArg('U')) {
    p->unk_8ba = VM_GetValue();
    p->unk_8bc = VM_GetValue();
    p->unk_8be = VM_GetValue();
    p->unk_8c0 = VM_GetValue();
  } else {
    p->unk_8ba = 40;
    p->unk_8bc = 80;
    p->unk_8be = 50;
    p->unk_8c0 = 30;
  }
  p->unk_8ce = 0x200;
  p->unk_8d0 = 0x400;
  Boss_Init(boss, id, bossID, &pos, angle);
  boss->destAngle = angle;
  boss->isDemo = VM_GetNamedArgValue('i', 0);
  if (boss->isDemo) {
    p->spriteOffsetY = 0;
  } else {
    p->spriteOffsetY = 64;
  }
  MainSprite_Add(&p->sprites[0], &p->gfx, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx, 0, SPRFLAG_HIDDEN, 3, PLAYMODE_PAUSE, 60, &pos);
  Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 0, PLAYMODE_LOOP, 0);
  plttID = Ringo_GetPlttID(p);
  if (plttID == 0) {
    p->sprites[0].pltt = p->pltt[0];
  } else {
    p->sprites[0].pltt = &gObjPlttData[plttID * 16];
  }
  p->sprites[1].pltt = p->sprites[0].pltt;
  FUN_0802a208(p);
  FUN_08029ab8(p);
  if (boss->isDemo) {
    switch (VM_GetNamedArgValue('D', 1)) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        Boss_SetState(boss, FUN_0803331c, 35);
        break;
      }
      case 1: {
        Boss_SetSubStates(boss, 2, 0, 1);
        Boss_SetState(boss, FUN_080333a4, 36);
        break;
      }
      case 2: {
        Boss_SetSubStates(boss, 2, 0, 16);
        Boss_SetState(boss, FUN_080333a4, 52);
        break;
      }
    }
  } else {
    Ringo_ResetSubStates(p, 120);
    Boss_SetState(boss, FUN_0802e520, 1);
  }
  boss->damageCallback = (BossCheckFunc)Ringo_HandleDamage;
  boss->stateRequestCallback = (BossCheckFunc)FUN_08035a64;
  Boss_InitHP(boss, hp, hp, p->hurtboxPower);
  Ringo_InitHitbox(p);
  Ringo_InitHurtbox(p, p->hurtboxPower);
  Ringo_InitHitbox2(p);
  Ringo_InitHurtbox2(p);
  if (VM_SeekToNamedArg('d')) {
    p->scriptID = VM_GetValue();
    p->scriptID2 = VM_GetValue();
  } else {
    p->scriptID = 0;
    p->scriptID2 = 0;
  }
  if (VM_SeekToNamedArg('c')) {
    u32 scriptA = VM_GetValue();
    u32 scriptB = VM_GetValue();

    FUN_08022fac(boss, scriptA, scriptB);
  } else {
    FUN_08022fac(boss, 0, 0);
  }
  if (VM_SeekToNamedArg('A')) {
    for (i = 0; i < 4 && VM_GetPC() != NULL; i++) {
      boss->unk_e8[i] = VM_GetValue();
    }
  }
  p->unk_8c2 = 500;
  p->weaponExp = VM_GetNamedArgValue('K', 0);
  boss->damageBonus = VM_GetNamedArgValue('x', 2);
  p->grabbedPlayer = -1;
  FUN_0802adb8(p);
  AuxShadow_Init(&p->shadow, &p->sprites[0].pos, 0x40, 0x40, 0x40, 0x40, 0x1900, 1, 6, 1, 0);
  AuxShadow_SetSprite(&p->shadow, SPRITE_EFF_1C1B, 7);
  src = &gObjPlttData[306 * 16];
  dst = p->pltt[0];
  for (i = 0; i < 16; i++, dst += 16) {
    CpuCopy32(src, dst, 32);
  }
  src = &gObjPlttData[195 * 16];
  dst = p->pltt_620[0];
  for (i = 0; i < 2; i++, dst += 16) {
    CpuCopy32(src, dst, 32);
  }
  dst = p->pltt_660[0];
  for (i = 0; i < 14; i++, src += 16, dst += 16) {
    CpuCopy32(src, dst, 32);
  }
  FUN_08028790(p, &p->sprites[0].pos);
  FUN_08028dbc(p);
  Ringo_InitAuxSprites(p);
  p->plttFadeMode = -1;
  p->plttFadeTo = Ringo_GetPlttID(p);
  boss->mover.unk_30.x = 0;
  boss->mover.unk_30.y = 400;
  boss->mover.unk_30.z = 0;
  if (boss->isDemo) {
    p->entity0805a31c = NULL;
    p->entity0805b068 = NULL;
    p->entity0805d364 = NULL;
  } else {
    p->entity0805a31c = Entity0805a31c_Create(p->unk_8ba);
    if (p->entity0805a31c == NULL) {
      return -1;
    }
    p->entity0805b068 = Entity0805b068_Create(p->unk_8bc, p->unk_8c0);
    if (p->entity0805b068 == NULL) {
      return -1;
    }
    p->entity0805d364 = Entity0805d364_Create(p->numPlayers);
    if (p->entity0805d364 == NULL) {
      return -1;
    }
  }
  p->entity0805b790 = Entity0805b790_Create(p->unk_820);
  if (p->entity0805b790 == NULL) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Ringo_Init.inc");
#endif
}

// 0xBA4B, HashName("リンゴ")
Ringo* Ringo_Create(u32 id) {
  Ringo* p = Boss_Get(VM_GetNamedArgValue('t', 1));
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Ringo));
  if (p != NULL) {
    SetEntityRoutine(p, Ringo_Update, Ringo_Destroy);
    if (Ringo_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
