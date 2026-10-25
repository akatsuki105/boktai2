#include "boss.h"
#include "camera.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "menu.h"
#include "msgbus.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// 0x300 から 0x98 刻みで10個並ぶパーツ
typedef struct {
  SpriteHolder holder;  // 0x00
  bool8 visible;        // 0x94, 0 なら作った時に隠し、アニメも進めない
  u8 variant;           // 0x95
  u8 pose;              // 0x96
  u8 shakeTimer;        // 0x97, 0 でない間ぶるぶる震える
} JormungandrSprite;
static_assert(sizeof(JormungandrSprite) == 152);

// 0x23DC から 0x38 刻みで8個並ぶ要素
typedef struct {
  bool8 active;   // 0x00
  u8 frameTimer;  // 0x01, 3 を過ぎるとコマを 3 にする
  u8 unk_02[4];   // 0x02
  u16 speed;      // 0x06, 中心へ吸い寄せられる速さ
  Vec3 ofs;       // 0x08, Jormungandr.pos からのずれ, y は使わない
  Particle ptcl;  // 0x10
} JormungandrParticle;
static_assert(sizeof(JormungandrParticle) == 56);

// 0x23D4, 周りから中心へ吸い込まれる粒 8 個
typedef struct {
  bool8 alive;                   // 0x00
  u8 idx;                        // 0x01, 次に使う ptcls
  u8 timer;                      // 0x02, 30 たまるごとに1個出す
  bool8 active;                  // 0x03, 動いている ptcls が1つでもあれば 1
  ParticleGroup* group;          // 0x04, PTCL_GROUP_2
  JormungandrParticle ptcls[8];  // 0x08
} JormungandrParticleSet;
static_assert(sizeof(JormungandrParticleSet) == 456);

// 0x1934 から 0x2A8 刻みで4個並ぶ胴体の節, 8枚の AuxSprite を follow の位置から ofs の位置まで並べる
typedef struct JormungandrSegment {
  bool8 active;                            // 0x000
  u8 idx;                                  // 0x001
  u8 mode;                                 // 0x002, 0 なら PLTT 0x165, それ以外は別の色
  u8 flashTimer;                           // 0x003, 0 になると色を 0x166 に戻す
  u16 timer;                               // 0x004, fn を差し替えると 0 に戻る
  u8 unk_06[2];                            // 0x006
  Vec3 ofs;                                // 0x008
  Vec3 unk_10;                             // 0x010
  Vec3* follow;                            // 0x018
  Vec3 prevPos;                            // 0x01C, follow の前のフレームの値
  AuxSprite sprites[8];                    // 0x024
  AuxSpriteGfx gfx[8];                     // 0x184
  Vec3 vels[8];                            // 0x264
  void (*fn)(struct JormungandrSegment*);  // 0x2A4
} JormungandrSegment;
static_assert(sizeof(JormungandrSegment) == 680);

// 0x1930, 4 本の首
typedef struct {
  bool8 active;                    // 0x00
  u8 unk_01[3];                    // 0x01
  JormungandrSegment segments[4];  // 0x04
} JormungandrSegmentSet;
static_assert(sizeof(JormungandrSegmentSet) == 2724);

// 0x1844 に1個ある投げ刃 (SPRITE_SWORD_AX), 自分の状態関数と攻撃判定を持つ
typedef struct JormungandrBlade {
  bool8 alive;                           // 0x00
  bool8 active;                          // 0x01, 立っている間 fn を呼ぶ
  u8 kind;                               // 0x02
  u8 angle;                              // 0x03
  u8 turnSpeed;                          // 0x04
  u8 unk_05;                             // 0x05
  u16 speed;                             // 0x06
  u16 timer;                             // 0x08, fn を差し替えると 0 に戻る
  u16 power;                             // 0x0A
  u16 knockback;                         // 0x0C
  u16 unk44;                             // 0x0E
  AuxSprite sprite;                      // 0x10
  AuxSpriteGfx gfx;                      // 0x3C, SPRITE_SWORD_AX
  HitboxData hitbox;                     // 0x58
  Vec3 vel;                              // 0xA8
  Vec3 target;                           // 0xB0
  void (*fn)(struct JormungandrBlade*);  // 0xB8
} JormungandrBlade;
static_assert(sizeof(JormungandrBlade) == 188);

// タコ足の1節, 根元から dist 離れた位置に置かれる
typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C, SPRITE_JORMUNGANDR_LEG か 0x8207
  u16 dist;          // 0x48, 根元からの距離
  u8 bendBase;       // 0x4A, u16_ARRAY_085ad0de の値
  u8 size;           // 0x4B, 2 か 3, poseIdx は size + 2
  u8 amp;            // 0x4C, 揺れ幅
  u8 unk_4d;         // 0x4D
  s16 bend;          // 0x4E
} JormungandrLegJoint;
static_assert(sizeof(JormungandrLegJoint) == 80);

// 0x8F8 に1本あるタコ足, 14 節と自分の状態関数と攻撃判定を持つ
typedef struct JormungandrLeg {
  bool8 alive;                         // 0x000
  bool8 active;                        // 0x001, 立っている間 fn を呼ぶ
  u8 flip;                             // 0x002, プレイヤーが根元より左なら 1
  u8 angle;                            // 0x003
  u16 timer;                           // 0x004, fn を差し替えると 0 に戻る
  u8 unk_06;                           // 0x006
  u8 unk_07;                           // 0x007
  JormungandrLegJoint joints[14];      // 0x008
  HitboxData hitbox;                   // 0x468
  Vec3* origin;                        // 0x4B8, 根元, Jormungandr.pos_2f8
  void (*fn)(struct JormungandrLeg*);  // 0x4BC
} JormungandrLeg;
static_assert(sizeof(JormungandrLeg) == 1216);

// 飛び散る破片 ("ect"), 32 個を順番に使い回す
typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C, HashName("ect")
  Vec3 vel;          // 0x48
  bool8 active;      // 0x50
  u8 timer;          // 0x51
  u8 duration;       // 0x52
  bool8 hurts;       // 0x53, 立っているとプレイヤーに当たる
} JormungandrDebris;
static_assert(sizeof(JormungandrDebris) == 84);

// ヨルムンガンド, "Typo Beast"
typedef struct {
  Boss base;                          // 0x000
  HitboxData hitbox;                  // 0x158
  HitboxData hurtbox;                 // 0x1A8, ハンドラは Jormungandr_OnHurt
  HitboxData hurtbox2;                // 0x1F8, ハンドラは Jormungandr_OnHurt2
  HitboxData hurtbox3;                // 0x248, HBFLAG_HIDDEN 付き, ハンドラは Jormungandr_OnHurt3
  HitboxData hitbox2;                 // 0x298
  Vec3 pos;                           // 0x2E8, Boss_Init に渡す初期位置, hitbox / hurtbox / hurtbox3 / hitbox2 の位置
  Vec3 pos_2f0;                       // 0x2F0
  Vec3 pos_2f8;                       // 0x2F8, hurtbox2 の位置
  JormungandrSprite sprites[10];      // 0x300, 0..4 は首, 5 と 6 は BOSSFLAG_VISIBLE / BOSSFLAG_UNK_31 で出る飾り, 7..9 は sprites[2] に付く
  u16 swayTimer;                      // 0x8F0, 0..63
  u8 moveAngle;                       // 0x8F2
  u8 unk_8f3;                         // 0x8F3
  bool8 swayUp;                       // 0x8F4, 立っていると swayAmp を 8 まで上げる, 落ちていると 0 まで下げる
  u8 swayAmp;                         // 0x8F5
  u8 swayTick;                        // 0x8F6
  u8 unk_8f7;                         // 0x8F7
  JormungandrLeg leg;                 // 0x8F8
  bool8 debrisAlive;                  // 0xDB8
  bool8 debrisActive;                 // 0xDB9, 動いている破片が1つでもあれば 1
  u8 debrisIdx;                       // 0xDBA, 次に投げる破片
  u8 debrisTimer;                     // 0xDBB
  u8 debrisSpawn;                     // 0xDBC, 0 以外なら破片を投げる, 1 と 2 で飛び方が違う
  u8 unk_dbd;                         // 0xDBD
  u16 debrisPower;                    // 0xDBE
  u8 unk_dc0[4];                      // 0xDC0
  JormungandrDebris debris[32];       // 0xDC4
  JormungandrBlade blade;             // 0x1844
  struct HomingLaserManager* lasers;  // 0x1900
  rgb555* bgPltt;                     // 0x1904, BGP_5ABD
  u8 slamCount;                       // 0x1908, 叩きつけの残り回数
  u8 slamCountMax;                    // 0x1909
  u8 slamRound;                       // 0x190A
  u8 slamRounds;                      // 0x190B, 叩きつけをこの回数くり返すと別の攻撃に移る
  u8 unk_190c[2];                     // 0x190C
  u16 damageTaken[4];                 // 0x190E, 右側 / 左側 / hurtbox3 / hurtbox2 で受けたダメージ, hitMask の bit と対応
  u16 unk_1916;                       // 0x1916
  u16 sideDamage[2];                  // 0x1918, 右側 / 左側, 120 以上になるとその側は食らわない
  u16 hitMask;                        // 0x191C, 食らった部位の bit
  u8 unk_191e[0x192A - 0x191E];       // 0x191E
  u16 grabDamage;                     // 0x192A, 噛みついている間 16 フレームごとに与えるダメージ
  u8 grabAngle;                       // 0x192C, 噛みついたときの Player.angle_400
  u8 grabTurns;                       // 0x192D
  u8 grabShake;                       // 0x192E
  u8 roarTimer;                       // 0x192F, 0 のとき吠える声を鳴らす, 40 で 0 に戻る
  JormungandrSegmentSet segSet;       // 0x1930
  JormungandrParticleSet ptclSet;     // 0x23D4
  rgb555 pltt[16];                    // 0x259C, bgPltt の色を明るさを変えて写す
  u8 unk_25bc;                        // 0x25BC
  u8 plttIdx;                         // 0x25BD, 太陽ゲージが 0 なら 1, base.unk_ab が立っていれば 2
  u8 plttFrom;                        // 0x25BE, u16_ARRAY_085ad0d8 と bgPltt の添字
  u8 plttTo;                          // 0x25BF
  bool8 plttFading;                   // 0x25C0
  u8 plttFade;                        // 0x25C1, 0..16, plttFrom から plttTo への混ぜ具合
  u8 flashTimers[3];                  // 0x25C2, sprites[0], sprites[5], sprites[4] を白く光らせる残りフレーム
  bool8 brightFading;                 // 0x25C5
  bool8 brightUp;                     // 0x25C6, 立っていると brightness を 32 まで上げる
  u8 brightness;                      // 0x25C7, 0..32
  bool8 invincible;                   // 0x25C8, 立っている間は食らってもダメージを受けない
  bool8 altAttack;                    // 0x25C9, phase 1 で FUN_080c81e0 と FUN_080c7e54 を交互に出す
  u16 unk_25ca;                       // 0x25CA
  s16 damageBonus;                    // 0x25CC, '.x=2', 受けたダメージに足す
  u16 weaponExp;                      // 0x25CE, '.K=2'
  u32 lastWeakness;                   // 0x25D0, 最後に食らった攻撃の weakness
  u8 unk_25d4;                        // 0x25D4
  u8 hurtAngle;                       // 0x25D5
  u16 hurtKnockback;                  // 0x25D6
  Vec3* hurtBase;                     // 0x25D8, hurtOfs の基準
  Vec3 hurtOfs;                       // 0x25DC, 食らった位置
  u16 hurtTimer;                      // 0x25E4
  u8 unk_25e6[2];                     // 0x25E6
  u16 hurtAnimTimer;                  // 0x25E8, 怯みアニメの経過フレーム, 0 なら怯んでいない
  u8 unk_25ea[2];                     // 0x25EA
  u16 unk_25ec;                       // 0x25EC
  u16 bladeAngle;                     // 0x25EE, FUN_080c35f0 に渡す投げ刃の向き
  u8 unk_25f0[0x25F9 - 0x25F0];       // 0x25F0
  u8 coreHits;                        // 0x25F9, hurtbox3 に当たった回数
  u8 unk_25fa;                        // 0x25FA
  u8 laserSide;                       // 0x25FB, 怪光線を撃つたびに 0 と 1 を入れ替える
  u8 unk_25fc;                        // 0x25FC
  bool8 unk_25fd;                     // 0x25FD
  u8 chargeLevel;                     // 0x25FE, 0..6, 6 で溜めきり
  bool8 chargeNoise;                  // 0x25FF, 溜めている音を鳴らしている
  bool8 chargeVoice;                  // 0x2600
  u8 smokeTimer;                      // 0x2601, chargeLevel ずつ足して 16 たまるごとに煙を出す
  u16 charge;                         // 0x2602, 溜めた太陽の量 (ヨルムンガンド撃破後のイベントで、10秒以内に太陽チャージをしないとゲームオーバーになるイベントで使う)
  u16 chargeMax;                      // 0x2604, ヨルムンガンド撃破後のイベントで、10秒以内に太陽チャージをしないとゲームオーバーになるイベントで使う
  u16 chargeTimeLeft;                 // 0x2606, ヨルムンガンド撃破後のイベントで、10秒以内に太陽チャージをしないとゲームオーバーになるイベントで使うタイマー
  s32 scriptID;                       // 0x2608
  u8 phase;                           // 0x260C, 2 のとき怯みが長引くと FUN_080c718c へ
  u8 turnSpeed;                       // 0x260D
  u16 moveSpeed;                      // 0x260E
} Jormungandr;
static_assert(sizeof(Jormungandr) == 9744);

const u16 u16_ARRAY_085ad0d8[3] = {341, 345, 349};  // 0x085AD0D8

const u16 u16_ARRAY_085ad0de[14] = {0, 2, 5, 9, 13, 17, 21, 24, 27, 29, 31, 33, 35, 37};  // 0x085AD0DE

const SoundID16 u16_ARRAY_085ad0fa[3] = {VO_TAIYO_763, VO_TAIYO_765, SONG_767};  // 0x085AD0FA

const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_ect_08251e04[] = "ect";

s32 Entity080146e0_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask);

void FUN_080c5458(JormungandrLeg*);
void FUN_080c5e8c(Jormungandr*, s32);
void FUN_080c5fd8(Jormungandr*);
void FUN_080c6170(Jormungandr*, s32);
void FUN_080c6248(Jormungandr*, s32);
void FUN_080c62cc(Jormungandr*, s32);
void FUN_080c6354(Jormungandr*, s32);
void FUN_080c6850(Boss*, s32);
void FUN_080c6a5c(Jormungandr*, s32);
void FUN_080c718c(Jormungandr*, s32);
void FUN_080c72f4(Jormungandr*);
void FUN_080c73c0(Jormungandr*, s32);
void FUN_080c74b4(Jormungandr*, s32);
void FUN_080c7518(Jormungandr*, s32);
void FUN_080c75f8(Jormungandr*, s32);
void FUN_080c7b84(Jormungandr*, s32);
void FUN_080c7e54(Jormungandr*, s32);
void FUN_080c81e0(Jormungandr*, s32);
void FUN_080c86ac(Jormungandr*, s32);
void FUN_080c898c(Jormungandr*, s32);
void FUN_080c8cc8(Jormungandr*, s32);
void FUN_080c7f34(Jormungandr*, s32);
void FUN_080c800c(Jormungandr*, s32);
void FUN_080c819c(Jormungandr*, s32);
void FUN_080c8358(Jormungandr*, s32);
void FUN_080c8434(Jormungandr*, s32);
void FUN_080c852c(Jormungandr*, s32);
void FUN_080c8644(Jormungandr*, s32);
void FUN_080c87c8(Jormungandr*, s32);
void FUN_080c8848(Jormungandr*, s32);
void FUN_080c8aa8(Jormungandr*, s32);
s32 FUN_0807ab64(Player*, Vec3*, Vec3* param_3, s32 param_4, u8 param_5, s32 param_6, s32 param_7, s32 param_8, u32 param_9);
u32 FUN_0807ac74(Player*, unknown* param_2, u16 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, u32 param_8);
s32 CreateHomingLaser(struct HomingLaserManager* p, Vec3* pos, Vec3* target, u32 angle, u32 speed, u32 kind);

void FUN_080c2680(JormungandrSegment* part, void (*fn)(JormungandrSegment*)) {
  part->fn = fn;
  part->timer = 0;
  part->active = TRUE;
}

void FUN_080c2694(JormungandrSegment* part, u32 plttIdx) {
  s32 i;

  if (plttIdx == 0x165) {
    part->mode = 0;
  } else {
    part->mode = 1;
  }
  for (i = 0; i < 8; i++) {
    Video_SetAuxSpritePltt(&part->gfx[i], plttIdx);
  }
}

// 残差は idx を読むのと sprites の番地を作る順だけ (162/162)
NON_MATCH void FUN_080c26cc(JormungandrSegment* part) {
#ifdef NONMATCHING_C
  if (part->timer == 0) {
    AuxSprite* sprites = part->sprites;
    s32 i;

    sprites[0].poseIdx = part->idx + 13;
    for (i = 0; i < 8; i++) {
      sprites[i].flags &= ~SPRFLAG_HIDDEN;
    }
    if (part->mode == 1) {
      FUN_080c2694(part, 0x167);
      part->flashTimer = 6;
    }
    part->prevPos.x = 0;
    part->prevPos.y = 0;
    part->prevPos.z = 0;
    part->timer++;
  }
  if (part->follow->x != part->prevPos.x || part->follow->y != part->prevPos.y || part->follow->z != part->prevPos.z) {
    Vec3 head = *part->follow;
    s32 i;

    head.x += part->ofs.x;
    head.y += part->ofs.y;
    head.z += part->ofs.z;
    for (i = 0; i < 8; i++) {
      s32 w = 8 - i;

      part->sprites[i].pos.x = FixToInt(3, part->unk_10.x * i + head.x * w);
      part->sprites[i].pos.y = FixToInt(3, part->unk_10.y * i + head.y * w);
      part->sprites[i].pos.z = FixToInt(3, part->unk_10.z * i + head.z * w);
    }
    if (part->flashTimer != 0 && --part->flashTimer == 0) {
      FUN_080c2694(part, 0x166);
    }
    part->prevPos = *part->follow;
  }
#else
  INCFUNC("asm/func/FUN_080c26cc.inc");
#endif
}

// 一通り書けたが並びと一時レジスタがずれる
NON_MATCH void FUN_080c2824(JormungandrSegment* part) {
#ifdef NONMATCHING_C
  if (part->timer == 0) {
    u16* table = gRandomTable;
    s32 i;

    part->sprites[0].poseIdx = part->idx;
    for (i = 0; i < 8; i++) {
      part->vels[i].x = (_Random(table) & 0x1F) - 16;
      part->vels[i].y = (_Random(table) & 0x1F) - 24;
      part->vels[i].z = (_Random(table) & 0x1F) - 16;
    }
  }
  if (++part->timer < 90) {
    bool32 blink = part->timer > 60 ? (part->timer >> 2) & 1 : 0;
    s32 i;

    for (i = 0; i < 8; i++) {
      AuxSprite* sprite = &part->sprites[i];
      Vec3* vel = &part->vels[i];

      if (!blink) {
        sprite->flags &= ~SPRFLAG_HIDDEN;
      } else {
        sprite->flags |= SPRFLAG_HIDDEN;
      }
      sprite->pos.x += vel->x;
      sprite->pos.y += vel->y;
      sprite->pos.z += vel->z;
      vel->y--;
      if (sprite->pos.y < 0x100) {
        sprite->pos.y = 0x100;
        vel->y = -vel->y / 2;
      }
    }
  } else {
    s32 i;

    part->active = FALSE;
    for (i = 0; i < 8; i++) {
      part->sprites[i].flags |= SPRFLAG_HIDDEN;
    }
  }
#else
  INCFUNC("asm/func/FUN_080c2824.inc");
#endif
}

// 一通り書けたが並びと一時レジスタがずれる
NON_MATCH void FUN_080c2978(JormungandrSegment* part) {
#ifdef NONMATCHING_C
  Vec3 head;
  s32 t;
  s32 i;

  if (part->timer == 0) {
    AuxSprite* sprites = part->sprites;

    sprites[0].poseIdx = part->idx;
    for (i = 0; i < 8; i++) {
      sprites[i].flags &= ~SPRFLAG_HIDDEN;
    }
    FUN_080c2694(part, 0x166);
  }
  head = *part->follow;
  head.x += part->ofs.x;
  head.y += part->ofs.y;
  head.z += part->ofs.z;
  t = part->timer;
  head.x = FixToInt(2, (4 - t) * part->unk_10.x + t * head.x);
  head.y = FixToInt(2, (4 - t) * part->unk_10.y + t * head.y);
  head.z = FixToInt(2, (4 - t) * part->unk_10.z + t * head.z);
  for (i = 0; i < 8; i++) {
    s32 w = 8 - i;

    part->sprites[i].pos.x = FixToInt(3, part->unk_10.x * i + head.x * w);
    part->sprites[i].pos.y = FixToInt(3, part->unk_10.y * i + head.y * w);
    part->sprites[i].pos.z = FixToInt(3, part->unk_10.z * i + head.z * w);
  }
  if (++part->timer > 3) {
    PlaySound_082406e0(SONG_563);
    FUN_080c2680(part, FUN_080c26cc);
  }
#else
  INCFUNC("asm/func/FUN_080c2978.inc");
#endif
}

void FUN_080c2b24(Jormungandr* p) {
  JormungandrSegment* part = p->segSet.segments;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (part->active) {
      p->segSet.segments[i].fn(part);
    }
    part++;
  }
}

void FUN_080c2b60(Jormungandr* p) {
  if (p->segSet.active) {
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 j;

      for (j = 0; j < 8; j++) {
        AuxSprite_Remove(&p->segSet.segments[i].sprites[j]);
      }
    }
  }
}

// 4 本の首の節を作る
// i が高位レジスタに置かれる割り当ての違いだけ残る
NON_MATCH void FUN_080c2ba8(Jormungandr* p) {
#ifdef NONMATCHING_C
  JormungandrSegmentSet* set = &p->segSet;
  s32 i;

  set->active = TRUE;
  for (i = 0; i < 4; i++) {
    JormungandrSegment* part = &set->segments[i];
    s32 j;

    part->active = FALSE;
    part->idx = i;
    part->mode = 0;
    part->unk_10.x = 0x500;
    part->unk_10.y = 0x700;
    part->unk_10.z = 0x344;
    switch (i) {
      case 0: {
        part->ofs.x = -0x38;
        part->ofs.y = 0xC0;
        part->ofs.z = -0x48;
        break;
      }
      case 1: {
        part->ofs.x = -0x68;
        part->ofs.y = 0xC0;
        part->ofs.z = 0x58;
        break;
      }
      case 2: {
        part->ofs.x = 0x68;
        part->ofs.y = 0xC0;
        part->ofs.z = -0x60;
        break;
      }
      case 3: {
        part->ofs.x = 0x38;
        part->ofs.y = 0xC0;
        part->ofs.z = 0x48;
        break;
      }
    }
    if (part->ofs.x > 0 && part->ofs.z > 0) {
      part->unk_10.x += part->ofs.x + 0x60;
      part->unk_10.z += part->ofs.z - 0x60;
    } else if (part->ofs.x < 0 && part->ofs.z < 0) {
      part->unk_10.x += part->ofs.x - 0x30;
      part->unk_10.z += part->ofs.z + 0x30;
    } else {
      part->unk_10.x += part->ofs.x * 4;
      part->unk_10.z += part->ofs.z * 4;
    }
    for (j = 0; j < 8; j++) {
      AuxSprite* sprite = &part->sprites[j];
      SpriteID32 id;
      s16 pose;

      if (j == 0) {
        id = SPRITE_WEDGE_8205;
        pose = i + 13;
      } else {
        id = 0x8207;
        pose = 6;
      }
      Video_GetAuxSprite(&part->gfx[j], id);
      AuxSprite_Add(sprite, &part->gfx[j], 0);
      sprite->poseIdx = pose;
      sprite->priority = 1;
    }
    FUN_080c2694(part, 0x165);
    part->follow = p->sprites[1].holder.pos;
  }
#else
  INCFUNC("asm/func/FUN_080c2ba8.inc");
#endif
}

// 飛び散る破片を動かし、debrisSpawn が立っていれば次の破片を投げる
// 破片の更新部は一致, 投げる側の乱数3回の取り方と sin 添字の先行計算が違う
NON_MATCH void FUN_080c2d38(Jormungandr* p) {
#ifdef NONMATCHING_C
  if (p->debrisActive) {
    bool8 active = FALSE;
    bool32 hit = gPlayerPtr[0]->kind != PLAYER_SOLAR_DJANGO;
    s32 i;

    for (i = 0; i < 32; i++) {
      JormungandrDebris* debris;

      if (!p->debris[i].active) {
        continue;
      }
      debris = &p->debris[i];
      if (++debris->timer >= debris->duration) {
        debris->sprite.flags |= SPRFLAG_HIDDEN;
        debris->active = FALSE;
        continue;
      }
      active = TRUE;
      debris->sprite.pos.x += debris->vel.x;
      debris->sprite.pos.y += debris->vel.y;
      debris->sprite.pos.z += debris->vel.z;
      if (debris->hurts && !hit) {
        s32 d = gPlayerPtr[0]->mover.pos.x - debris->sprite.pos.x;

        if (d < 0) {
          d = -d;
        }
        if (d < 0x40) {
          d = gPlayerPtr[0]->mover.pos.z - debris->sprite.pos.z;
          if (d < 0) {
            d = -d;
          }
          if (d < 0x40) {
            FUN_0807e7fc(gPlayerPtr[0], p->debrisPower, 0, 0, 4, HBATTR_DARK);
            hit = TRUE;
          }
        }
      }
      if (debris->timer < 45) {
        debris->sprite.poseIdx = Div(debris->timer, 4);
      } else if (debris->timer == 71) {
        debris->sprite.poseIdx = 14;
      } else if (debris->timer == 74) {
        debris->sprite.poseIdx = 5;
      } else if (debris->timer == 77) {
        debris->sprite.poseIdx = 2;
      }
    }
    p->debrisActive = active;
  }
  if (p->debrisSpawn) {
    if (++p->debrisTimer > 2) {
      JormungandrDebris* debris = &p->debris[p->debrisIdx];
      s32 height;
      s32 angle;
      s32 speed;

      debris->sprite.flags &= ~SPRFLAG_HIDDEN;
      debris->sprite.poseIdx = 0;
      if (p->debrisSpawn == 1) {
        angle = Mod(Random() >> 3, 48);
        height = (Random() & 0x7F) + 320;
        speed = (Random() & 3) + 3;
        debris->vel.x = Trig_Fix12ToInt(speed * SIN(angle + 0x68));
        debris->vel.y = 3;
        debris->vel.z = Trig_Fix12ToInt(speed * SIN(angle + 0x28));
        debris->hurts = FALSE;
      } else {
        angle = (Random() >> 3) & 0x1F;
        height = 384;
        speed = (Random() & 7) + 10;
        debris->vel.x = Trig_Fix12ToInt(speed * gSineTable[angle + 0x70]);
        debris->vel.y = 0;
        debris->vel.z = Trig_Fix12ToInt(speed * gSineTable[angle + 0x30]);
        debris->hurts = TRUE;
      }
      debris->sprite.pos = p->pos;
      debris->sprite.pos.z += debris->vel.x;
      debris->sprite.pos.z += debris->vel.z + height;
      if ((Random() >> 3) & 1) {
        debris->sprite.flags |= SPRFLAG_XFLIP;
      } else {
        debris->sprite.flags &= ~SPRFLAG_XFLIP;
      }
      if ((Random() >> 3) & 1) {
        debris->sprite.flags |= SPRFLAG_YFLIP;
      } else {
        debris->sprite.flags &= ~SPRFLAG_YFLIP;
      }
      debris->timer = 0;
      debris->duration = 80;
      debris->active = TRUE;
      p->debrisActive = TRUE;
      if (++p->debrisIdx >= 32) {
        p->debrisIdx = 0;
      }
      p->debrisTimer = 0;
    }
    p->debrisSpawn = 0;
  }
#else
  INCFUNC("asm/func/FUN_080c2d38.inc");
#endif
}

void FUN_080c311c(Jormungandr* p) {
  s32 i;

  if (p->debrisAlive) {
    for (i = 0; i < 32; i++) {
      AuxSprite_Remove(&p->debris[i].sprite);
    }
  }
}

// 破片 32 個を作る
// 0 を r8 に置いて poseIdx にも使い回す形が出ない, レジスタ割当のみ (10 hunk)
NON_MATCH void FUN_080c314c(Jormungandr* p, u32 power) {
#ifdef NONMATCHING_C
  s32 i;

  p->debrisAlive = TRUE;
  p->debrisIdx = 0;
  p->debrisTimer = 0;
  p->debrisPower = power;
  for (i = 0; i < 32; i++) {
    JormungandrDebris* debris = &p->debris[i];
    AuxSprite* sprite = &debris->sprite;
    AuxSpriteGfx* gfx = &debris->gfx;

    Video_GetAuxSprite(gfx, HashName(s_ect_08251e04));
    if (i & 1) {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN);
    } else {
      AuxSprite_Add(sprite, gfx, SPRFLAG_BLINK_EVEN | SPRFLAG_HIDDEN);
    }
    sprite->poseIdx = 0;
    Video_SetAuxSpritePltt(gfx, 360);
    sprite->priority = 1;
    debris->active = FALSE;
    debris->timer = 0;
    debris->duration = 0;
  }
#else
  INCFUNC("asm/func/FUN_080c314c.inc");
#endif
}

void FUN_080c3218(JormungandrBlade* part, void (*fn)(JormungandrBlade*)) {
  part->fn = fn;
  part->timer = 0;
}

// まっすぐ飛ばし、90 フレームで消す
void FUN_080c3224(JormungandrBlade* part) {
  if (++part->timer >= 90) {
    part->sprite.flags |= SPRFLAG_HIDDEN;
    part->active = FALSE;
  } else {
    part->sprite.pos.x += part->vel.x;
    part->sprite.pos.z += part->vel.z;
    Hitbox_SetPos(&part->hitbox, &part->sprite.pos, 0);
    Hitbox_Register(&part->hitbox);
  }
}

// プレイヤーへ曲がりながら回転して飛ぶ, 120 フレームで消す
void FUN_080c3278(JormungandrBlade* part) {
  s32 diff;
  s32 rotation;

  if (++part->timer >= 120) {
    part->sprite.flags |= SPRFLAG_HIDDEN;
    part->active = FALSE;
    return;
  }
  if (part->timer > 24 && part->turnSpeed < 20) {
    part->turnSpeed++;
  }
  if (part->timer < 24) {
    part->target = gPlayerPtr[0]->mover.pos;
  }
  if (part->timer >= 16 && part->timer < 60) {
    diff = (ArcTan2_8(part->target.x - part->sprite.pos.x, part->target.z - part->sprite.pos.z) - part->angle + 0x100) & 0xFF;
    if (diff > 0x80) {
      part->angle += 0xFD;
    } else {
      part->angle += 3;
    }
    if (diff >= 24 && diff <= 232) {
      if (part->speed > 15) {
        part->speed--;
      }
    } else if (part->speed < 25) {
      part->speed++;
    }
  } else if (part->timer >= 60 && part->speed < 25) {
    part->speed++;
  }
  part->vel.x = Trig_Fix12ToInt(part->speed * COS(part->angle));
  part->vel.z = Trig_Fix12ToInt(part->speed * SIN(part->angle));
  rotation = (part->sprite.rotation - part->turnSpeed + 0x100) & 0xFF;
  if (part->sprite.rotation >= 0x60 && rotation < 0x60) {
    PlaySound_082406e0(SONG_361);
  }
  part->sprite.rotation = rotation;
  part->sprite.pos.x += part->vel.x;
  part->sprite.pos.z += part->vel.z;
  Hitbox_SetPos(&part->hitbox, &part->sprite.pos, 0);
  Hitbox_Register(&part->hitbox);
}

void FUN_080c33d8(JormungandrBlade* part, u32 id) {
  HitboxData* hitbox = &part->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x30, 0x40, 0x30);
  VEC3_SET(offset, part->vel.x * 4, 0, part->vel.z * 4);
  Hitbox_Init(hitbox, id, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, part->power, part->knockback, 0, HBATTR_17 | HBATTR_18, part->unk44);
  hitbox->angle = part->angle;
  Hitbox_SetHandler(hitbox, NULL, part);
  Hitbox_SetPos(hitbox, &part->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

void FUN_080c3494(JormungandrBlade* part, u32 id) {
  HitboxData* hitbox = &part->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x80, 0x40, 0x80);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, id, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, part->power, part->knockback, 0, HBATTR_17 | HBATTR_18, part->unk44);
  Hitbox_SetHandler(hitbox, NULL, part);
  Hitbox_SetPos(hitbox, &part->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

// hitbox->angle = 0x40 の定数ロードとアドレス計算の順が逆 (2 hunk)
NON_MATCH void FUN_080c3528(JormungandrBlade* part, u32 id) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = &part->hitbox;
  Vec3 pos, halfSize, offset;

  VEC3_SET(pos, 0x5AA, 0x100, 0x3A5);
  VEC3_SET(halfSize, 0x80, 0x40, 0x80);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, id, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, part->power, part->knockback, 0, HBATTR_17 | HBATTR_18, part->unk44);
  part->hitbox.angle = 0x40;
  Hitbox_SetHandler(hitbox, NULL, part);
  Hitbox_SetPos(hitbox, &pos, 0);
  Hitbox_Register(hitbox);
#else
  INCFUNC("asm/func/FUN_080c3528.inc");
#endif
}

// 投げ刃を kind の飛び方で angle へ放つ
void FUN_080c35f0(Jormungandr* p, u32 kind, u32 angle) {
  JormungandrBlade* part = &p->blade;
  AuxSprite* sprite;

  part->kind = kind;
  part->active = TRUE;
  part->angle = angle;
  sprite = &part->sprite;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  sprite->pos.x = 0x514;
  sprite->pos.y = 0x200;
  sprite->pos.z = 0x300;
  if (part->kind == 0) {
    sprite->poseIdx = 0;
    sprite->rotation = ~(part->angle + 0x60);
    part->vel.x = Trig_Fix12ToInt(40 * COS(part->angle));
    part->vel.z = Trig_Fix12ToInt(40 * SIN(part->angle));
    FUN_080c33d8(part, p->base.mover.id);
    PlaySound_082406e0(SONG_399);
    FUN_080c3218(part, FUN_080c3224);
  } else {
    sprite->poseIdx = 1;
    sprite->rotation = 0x60;
    part->speed = 25;
    part->turnSpeed = 10;
    part->vel.x = Trig_Fix12ToInt(part->speed * COS(part->angle));
    part->vel.z = Trig_Fix12ToInt(part->speed * SIN(part->angle));
    FUN_080c3494(part, p->base.mover.id);
    PlaySound_082406e0(SONG_361);
    FUN_080c3218(part, FUN_080c3278);
  }
}

void FUN_080c373c(Jormungandr* p) {
  if (p->blade.active) {
    p->blade.fn(&p->blade);
  }
}

void FUN_080c3764(Jormungandr* p) {
  if (p->blade.alive) {
    AuxSprite_Remove(&p->blade.sprite);
  }
}

void FUN_080c3784(Jormungandr* p, u32 power, u32 knockback, u32 unk44) {
  JormungandrBlade* part = &p->blade;
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;

  part->alive = TRUE;
  part->active = FALSE;
  part->timer = 0;
  sprite = &part->sprite;
  gfx = &part->gfx;
  Video_GetAuxSprite(gfx, SPRITE_SWORD_AX);
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
  sprite->poseIdx = 1;
  Video_SetAuxSpritePltt(gfx, 342);
  part->power = power;
  part->knockback = knockback;
  part->unk44 = unk44;
}

// 投げ刃のパレットを t/32 の明るさにする, 32 以上ならそのまま写す
// t の退避レジスタと src 計算の位置、色の合成順が違う
NON_MATCH void FUN_080c37f8(Jormungandr* p, s32 t) {
#ifdef NONMATCHING_C
  rgb555* src = &gObjPlttData[0x15D * 16];

  if (t >= 32) {
    CpuCopy32(src, p->pltt, sizeof(p->pltt));
  } else {
    rgb555* dst = p->pltt;
    s32 i;

    for (i = 0; i < 16; i++) {
      s32 r = (*src & 0x1F) * t >> 5;
      s32 g = ((*src >> 5) & 0x1F) * t >> 5;
      s32 b = ((*src >> 10) & 0x1F) * t >> 5;

      *dst = (b << 10) | (g << 5) | r;
      src++;
      dst++;
    }
  }
#else
  INCFUNC("asm/func/FUN_080c37f8.inc");
#endif
}

// 背景パレット 2 本を t/32 の明るさにする, 32 以上ならそのまま写す
// 原典は j を上向きに数えて i * 32 バイトを先に作る添字形
NON_MATCH void FUN_080c386c(Jormungandr* p, s32 t) {
#ifdef NONMATCHING_C
  rgb555* src = &p->bgPltt[p->plttFrom * 32];

  if (t >= 32) {
    CpuCopy32(src, gBgPlttBuffer, 64);
  } else {
    s32 i;

    for (i = 0; i < 2; i++) {
      rgb555* dst = &gBgPlttBuffer[i * 16];
      s32 j;

      for (j = 0; j < 16; j++) {
        u16 c = *src;

        dst[j] = ((((c >> 10) & 0x1F) * t >> 5) << 10) | ((((c >> 5) & 0x1F) * t >> 5) << 5) | ((c & 0x1F) * t >> 5);
        src++;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c386c.inc");
#endif
}

// 本体のパレットを plttFrom から plttTo へ t/16 だけ混ぜる
// 色の合成で 14 命令少ない, 3 本の式の評価順が違う
NON_MATCH void FUN_080c390c(Jormungandr* p, s32 t) {
#ifdef NONMATCHING_C
  rgb555* from = &gObjPlttData[u16_ARRAY_085ad0d8[p->plttFrom] * 16];
  rgb555* to = &gObjPlttData[u16_ARRAY_085ad0d8[p->plttTo] * 16];

  if (t >= 16) {
    CpuCopy32(to, p->pltt, sizeof(p->pltt));
  } else {
    s32 u = 16 - t;
    rgb555* dst = p->pltt;
    s32 i;

    for (i = 0; i < 16; i++) {
      u16 a = *from;
      u16 b = *to;

      *dst = (((((a >> 10) & 0x1F) * u + ((b >> 10) & 0x1F) * t) >> 4) << 10) | (((((a >> 5) & 0x1F) * u + ((b >> 5) & 0x1F) * t) >> 4) << 5) | (((a & 0x1F) * u + (b & 0x1F) * t) >> 4);
      from++;
      to++;
      dst++;
    }
  }
#else
  INCFUNC("asm/func/FUN_080c390c.inc");
#endif
}

// 背景パレット 2 本を plttFrom から plttTo へ t/16 だけ混ぜる
// FUN_080c386c と同じく添字の形が違う
NON_MATCH void FUN_080c3a08(Jormungandr* p, s32 t) {
#ifdef NONMATCHING_C
  rgb555* from = &p->bgPltt[p->plttFrom * 32];
  rgb555* to = &p->bgPltt[p->plttTo * 32];

  if (t >= 16) {
    CpuCopy32(to, gBgPlttBuffer, 64);
  } else {
    s32 u = 16 - t;
    s32 i;

    for (i = 0; i < 2; i++) {
      s32 j;

      for (j = 0; j < 16; j++) {
        u16 a = *from;
        u16 b = *to;

        gBgPlttBuffer[i * 16 + j] = (((((a >> 10) & 0x1F) * u + t * ((b >> 10) & 0x1F)) >> 4) << 10) | (((((a >> 5) & 0x1F) * u + t * ((b >> 5) & 0x1F)) >> 4) << 5) | (((a & 0x1F) * u + t * (b & 0x1F)) >> 4);
        from++;
        to++;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c3a08.inc");
#endif
}

// パレットの明るさと切り替えを1フレーム進める
void FUN_080c3af4(Jormungandr* p) {
  if (p->brightFading) {
    if (p->brightUp && ++p->brightness >= 32) {
      p->brightFading = FALSE;
    }
    FUN_080c37f8(p, p->brightness);
    FUN_080c386c(p, p->brightness);
  } else if (p->plttFading) {
    if (++p->plttFade >= 16) {
      p->plttFading = FALSE;
    }
    FUN_080c390c(p, p->plttFade);
    FUN_080c3a08(p, p->plttFade);
  }
}

// 太陽ゲージに合わせたパレットにすぐ切り替える
// sunGauge == 0 の 0 を先に置く位置と plttFading のアドレス計算が違う (4 hunk)
NON_MATCH void FUN_080c3b80(Jormungandr* p) {
#ifdef NONMATCHING_C
  if (p->base.unk_ab) {
    p->plttIdx = p->plttTo = p->plttFrom = 2;
  } else {
    p->plttIdx = p->plttTo = p->plttFrom = gStat->sunGauge == 0;
  }
  p->plttFade = 16;
  p->plttFading = TRUE;
  FUN_080c3af4(p);
#else
  INCFUNC("asm/func/FUN_080c3b80.inc");
#endif
}

// 被弾で白くしたパーツを時間が来たら元のパレットに戻す
void FUN_080c3bf0(Jormungandr* p) {
  if (p->flashTimers[0]) {
    if (--p->flashTimers[0] == 0) {
      p->sprites[0].holder.u.main.sprite.plttID = 0x155;
      p->sprites[0].holder.u.main.sprite.pltt = p->pltt;
    } else {
      p->sprites[0].holder.u.main.sprite.plttID = 0x132;
      p->sprites[0].holder.u.main.sprite.pltt = &gObjPlttData[0x132 * 16];
    }
  }
  if (p->flashTimers[1]) {
    if (--p->flashTimers[1] == 0) {
      p->sprites[5].holder.u.main.sprite.plttID = 0x155;
      p->sprites[5].holder.u.main.sprite.pltt = p->pltt;
    } else {
      p->sprites[5].holder.u.main.sprite.plttID = 0x132;
      p->sprites[5].holder.u.main.sprite.pltt = &gObjPlttData[0x132 * 16];
    }
  }
  if (p->flashTimers[2]) {
    if (--p->flashTimers[2] == 0) {
      p->sprites[4].holder.u.aux.gfx.plttID = 0x155;
      p->sprites[4].holder.u.aux.gfx.pltt = p->pltt;
    } else {
      p->sprites[4].holder.u.aux.gfx.plttID = 0x132;
      p->sprites[4].holder.u.aux.gfx.pltt = &gObjPlttData[0x132 * 16];
    }
  }
}

// hurtbox3 の中心に煙を 5 つ出す
// r - 0x80 の subs の位置がずれる (2 hunk)
NON_MATCH void FUN_080c3d14(Jormungandr* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 5; i++) {
    s32 r = ((Random() >> 3) & 0xFF) - 0x80;
    WorldPos pos;

    pos.x = p->hurtbox3.center.x;
    pos.y = p->hurtbox3.center.y + r;
    pos.z = p->hurtbox3.center.z - r;
    EmitSmoke(&pos, 1, NULL, 0, 0, 24, 2, 1);
  }
#else
  INCFUNC("asm/func/FUN_080c3d14.inc");
#endif
}

// base + ofs の位置から angle の向きへ破片を3回に分けて飛ばす
// 乱数 2 回分の添字をまとめて進める形が出ない
NON_MATCH void FUN_080c3db4(Jormungandr* p, Vec3* base, Vec3* ofs, s32 angle) {
#ifdef NONMATCHING_C
  Vec3 pos = *base;
  s32 count;
  s32 speed;

  Vec3_Add(&pos, ofs);
  count = (Random() & 3) + 2;
  speed = (Random() & 3) + 8;
  Entity080146e0_SpawnAtAngle(count, 0x109, &pos, angle, 8, speed, 4, 10, 8, 5, 10);
  angle = (angle + (Random() & 7)) & 0xFF;
  speed = (Random() & 7) + 6;
  Entity080146e0_SpawnAtAngle(3, 0x109, &pos, angle, 8, speed, 4, 14, 4, 6, 10);
  angle = (angle + (Random() & 0xF)) & 0xFF;
  count = (Random() & 3) + 1;
  speed = (Random() & 7) + 4;
  Entity080146e0_SpawnAtAngle(count, 0x109, &pos, angle, 8, speed, 2, 6, 3, 5, 10);
#else
  INCFUNC("asm/func/FUN_080c3db4.inc");
#endif
}

void FUN_080c3f30(Jormungandr* p) {
  JormungandrParticleSet* set = &p->ptclSet;
  s32 i;

  set->alive = TRUE;
  set->active = FALSE;
  set->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    set->ptcls[i].active = FALSE;
    Particle_Add(&set->ptcls[i].ptcl, set->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&set->ptcls[i].ptcl, -4, -4);
    Particle_SetPltt(&set->ptcls[i].ptcl, 1);
    set->ptcls[i].ptcl.priority = 1;
  }
}

void FUN_080c3fa0(Jormungandr* p) {
  s32 i;

  if (p->ptclSet.alive) {
    for (i = 0; i < 8; i++) {
      Particle_Remove(&p->ptclSet.ptcls[i].ptcl);
    }
  }
}

// rate ずつためて、30 たまるごとに周りから中心へ吸い込まれる粒を1つ出す
// 1 回目の乱数で添字だけ進めて書き戻しを 2 回目にまとめる形が出ない
NON_MATCH void FUN_080c3fd0(Jormungandr* p, u32 rate) {
#ifdef NONMATCHING_C
  JormungandrParticleSet* set = &p->ptclSet;

  set->timer += rate + 2;
  if (set->timer >= 30) {
    JormungandrParticle* ptcl = &set->ptcls[set->idx];
    const u16* table = gRandomTable;
    u8 angle;
    s32 dist;

    ptcl->frameTimer = 0;
    ptcl->active = TRUE;
    angle = _Random(table);
    dist = (_Random(table) & 0x7F) + 320;
    ptcl->ofs.x = Trig_Fix12ToInt(dist * COS(angle));
    ptcl->ofs.z = Trig_Fix12ToInt(dist * SIN(angle));
    ptcl->speed = (_Random(table) & 7) + 28;
    ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
    Particle_SetFrame(&ptcl->ptcl, set->group, 2);
    ptcl->ptcl.pos.x = ptcl->ofs.x + p->pos.x;
    ptcl->ptcl.pos.y = p->pos.y;
    ptcl->ptcl.pos.z = p->pos.z + ptcl->ofs.z + 0x180;
    if (++set->idx >= 8) {
      set->idx = 0;
    }
    set->timer -= 30;
    set->active = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_080c3fd0.inc");
#endif
}

// 粒を中心へ吸い寄せ、着いたものは消す
// pos.x/z の退避とループの形が違う (22 hunk)
NON_MATCH void FUN_080c4114(Jormungandr* p) {
#ifdef NONMATCHING_C
  JormungandrParticleSet* set = &p->ptclSet;

  if (set->active) {
    s16 x = p->pos.x;
    s16 z = p->pos.z;
    bool8 active = FALSE;
    s32 i;

    for (i = 0; i < 8; i++) {
      JormungandrParticle* ptcl = &set->ptcls[i];
      s32 d;
      u8 angle;

      if (!ptcl->active) {
        continue;
      }
      d = ptcl->ofs.x;
      if (d < 0) {
        d = -d;
      }
      if (d < 0x40) {
        d = ptcl->ofs.z;
        if (d < 0) {
          d = -d;
        }
        if (d < 0x40) {
          ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
          ptcl->active = FALSE;
          continue;
        }
      }
      angle = ArcTan2_8(ptcl->ofs.x, ptcl->ofs.z);
      ptcl->ofs.x -= Trig_Fix12ToInt(ptcl->speed * COS(angle));
      ptcl->ofs.z -= Trig_Fix12ToInt(ptcl->speed * SIN(angle));
      ptcl->ptcl.pos.x = x + ptcl->ofs.x;
      ptcl->ptcl.pos.z = z + 0x180 + ptcl->ofs.z;
      if (ptcl->frameTimer++ == 3) {
        Particle_SetFrame(&ptcl->ptcl, set->group, 3);
      }
      active = TRUE;
    }
    set->active = active;
  }
#else
  INCFUNC("asm/func/FUN_080c4114.inc");
#endif
}

void FUN_080c4254(Jormungandr* p) {
  s32 i;

  p->ptclSet.active = FALSE;
  for (i = 0; i < 8; i++) {
    p->ptclSet.ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
    p->ptclSet.ptcls[i].active = FALSE;
  }
}

// 本体の左右どちら側を叩かれたかで別々にダメージを数える
// 原典は左右の分岐の後半が共通化されずに2本とも残る, こちらは末尾がまとめられて 44 命令少ない
NON_MATCH void Jormungandr_OnHurt(HitboxData* a, HitboxData* b, Jormungandr* p) {
#ifdef NONMATCHING_C
  s32 side;

  if (b->unk_44 != 0) {
    return;
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_18)) {
    return;
  }
  if (Hitbox_HasWeakness(a, HBATTR_SOL | HBATTR_DARK | HBATTR_FLAME | HBATTR_FROST)) {
    side = b->center.x > gPlayerPtr[0]->mover.pos.x ? 1 : 2;
  } else if (Hitbox_HasWeakness(a, HBATTR_CLOUD)) {
    side = b->center.x > a->center.x ? 1 : 2;
  } else {
    side = b->center.x > a->center.x ? 1 : 2;
  }
  if (side == 1) {
    if (p->sideDamage[1] >= 120) {
      return;
    }
    if (!p->invincible) {
      Hitbox_ApplyDamage(a, b);
      p->damageTaken[1] += b->damage;
      p->sideDamage[1] += b->damage;
      p->hitMask |= 2;
      p->flashTimers[0] = 6;
      p->hurtBase = &p->pos;
      p->hurtOfs.x = a->pos.x - p->pos.x;
      if (p->hurtOfs.x > 100) {
        p->hurtOfs.x = 100;
      }
      p->hurtOfs.y = a->pos.y - p->hurtBase->y;
      p->hurtOfs.z = a->pos.z - p->hurtBase->z;
      if (p->hurtOfs.z > 350) {
        p->hurtOfs.z = 350;
      }
      p->hurtTimer = 16;
      a->damage = p->damageBonus + a->damage;
      p->lastWeakness = a->weakness;
    }
    b->unk_44 = 20;
  } else if (side == 2) {
    if (p->sideDamage[0] >= 120) {
      return;
    }
    if (!p->invincible) {
      Hitbox_ApplyDamage(a, b);
      p->damageTaken[0] += b->damage;
      p->sideDamage[0] += b->damage;
      p->hitMask |= 1;
      p->flashTimers[0] = 6;
      p->hurtBase = &p->pos;
      p->hurtOfs.x = a->pos.x - p->pos.x;
      if (p->hurtOfs.x < -100) {
        p->hurtOfs.x = -100;
      }
      p->hurtOfs.y = a->pos.y - p->hurtBase->y;
      p->hurtOfs.z = a->pos.z - p->hurtBase->z;
      if (p->hurtOfs.z > 350) {
        p->hurtOfs.z = 350;
      }
      p->hurtTimer = 16;
      a->damage = p->damageBonus + a->damage;
      p->lastWeakness = a->weakness;
    }
    b->unk_44 = 20;
  } else {
    return;
  }
  if (Hitbox_TestAttr(a, HBATTR_18)) {
    p->hurtKnockback = a->knockbackPower;
  } else {
    p->hurtKnockback = a->knockbackPower >> 1;
  }
  p->hurtAngle = a->angle;
#else
  INCFUNC("asm/func/Jormungandr_OnHurt.inc");
#endif
}

void Jormungandr_InitHurtbox(Jormungandr* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x80, 0x80, 0x96);
  VEC3_SET(offset, 0, 0, 0x100);
  Hitbox_Init(hurtbox, p->base.mover.id, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL, 0);
  Hitbox_SetHandler(hurtbox, Jormungandr_OnHurt, p);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_Register(hurtbox);
}

// タコ足の根元を叩かれた
// lastWeakness のアドレスを damageBonus の定数 +4 で作る形が出ない (1 hunk)
NON_MATCH void Jormungandr_OnHurt2(HitboxData* a, HitboxData* b, Jormungandr* p) {
#ifdef NONMATCHING_C
  if (b->unk_44 == 0 && !TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_19)) {
    if (!p->invincible) {
      Hitbox_ApplyDamage(a, b);
      p->damageTaken[3] += b->damage;
      p->hitMask |= 8;
      p->flashTimers[2] = 8;
      p->hurtBase = &p->pos_2f8;
      p->hurtOfs.x = a->pos.x - p->pos_2f8.x;
      p->hurtOfs.y = a->pos.y - p->hurtBase->y;
      p->hurtOfs.z = a->pos.z - p->hurtBase->z;
      p->hurtTimer = 16;
      p->hurtAngle = a->angle;
      a->damage = p->damageBonus + a->damage;
      p->lastWeakness = a->weakness;
    }
    b->unk_44 = 15;
  }
#else
  INCFUNC("asm/func/Jormungandr_OnHurt2.inc");
#endif
}

void Jormungandr_InitHurtbox2(Jormungandr* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox2;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x80, 0x80, 0x80);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hurtbox, p->base.mover.id, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL, 0);
  Hitbox_SetHandler(hurtbox, Jormungandr_OnHurt2, p);
  Hitbox_SetPos(hurtbox, &p->pos_2f8, 0);
  Hitbox_Register(hurtbox);
}

// 弱点を叩かれた
// lastWeakness のアドレスを damageBonus の定数 +4 で作る形が出ない (1 hunk)
NON_MATCH void Jormungandr_OnHurt3(HitboxData* a, HitboxData* b, Jormungandr* p) {
#ifdef NONMATCHING_C
  if (b->unk_44 == 0) {
    Hitbox_ApplyDamage(a, b);
    p->damageTaken[2] += b->damage;
    p->hitMask |= 4;
    b->unk_44 = 15;
    p->flashTimers[1] = 8;
    p->coreHits++;
    FUN_080c3d14(p);
    a->damage = p->damageBonus + a->damage;
    p->lastWeakness = a->weakness;
  }
#else
  INCFUNC("asm/func/Jormungandr_OnHurt3.inc");
#endif
}

void Jormungandr_InitHurtbox3(Jormungandr* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox3;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x40, 0x80, 0x80);
  VEC3_SET(offset, 0, 0, 0x240);
  Hitbox_Init(hurtbox, p->base.mover.id, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_HIDDEN | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL, 0);
  Hitbox_SetHandler(hurtbox, Jormungandr_OnHurt3, p);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_Register(hurtbox);
}

void Jormungandr_InitHitbox(Jormungandr* p, s32 power, s32 knockback, s32 unk44) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x80, 0x80, 0x80);
  VEC3_SET(offset, 0, -0x20, 0x100);
  Hitbox_Init(hitbox, p->base.mover.id, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, 0, unk44);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_Register(hitbox);
}

void Jormungandr_InitHitbox2(Jormungandr* p, s32 power, s32 knockback, s32 unk44) {
  HitboxData* hitbox = &p->hitbox2;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x80, 0x80, 0x80);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, p->base.mover.id, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, 0, unk44);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_Register(hitbox);
}

// pos を pos_2f0 へ 1/8 ずつ近づける
void FUN_080c4990(Jormungandr* p) {
  p->pos.x = FixToInt(3, p->pos.x * 7 + p->pos_2f0.x);
  p->pos.y = FixToInt(3, p->pos.y * 7 + p->pos_2f0.y);
  p->pos.z = FixToInt(3, p->pos.z * 7 + p->pos_2f0.z);
}

void FUN_080c4a2c(Jormungandr* p) { p->pos = p->pos_2f0; }

void FUN_080c4a40(Jormungandr* p, s32 idx, u32 time) { p->sprites[idx].shakeTimer = time; }

void FUN_080c4a54(Jormungandr* p, u32 time) {
  s32 i;

  for (i = 0; i < 5; i++) {
    FUN_080c4a40(p, i, time);
  }
}

// 首のパーツを pos と pos_2f8 の間に並べて揺らす
// 命令数はほぼ同じ (685/681) だが、ローカル Vec3 の組み立てとレジスタ割当が大きく違う
NON_MATCH void FUN_080c4a74(Jormungandr* p) {
#ifdef NONMATCHING_C
  s32 dx = p->pos.x - p->pos_2f8.x;
  s32 dy = p->pos.y - p->pos_2f8.y;
  s32 dz = p->pos.z - p->pos_2f8.z;
  u32 angle = ArcTan2_8(dx, dz);
  s32 len;
  s32 bend;
  s32 i;

  if (dx == 0 && dz == 0) {
    len = 0x300;
  } else {
    s32 ax = dx;
    s32 az = dz;

    if (ax < 0) {
      ax = -ax;
    }
    if (az < 0) {
      az = -az;
    }
    if (az < ax) {
      len = Div(dx * 0x1000, COS(angle));
    } else {
      len = Div(dz * 0x1000, SIN(angle));
    }
  }
  if (dy > 0x280) {
    len += (dy - 0x280) * 2;
    if (len > 0x300) {
      len = 0x300;
    }
  }
  if (len < 0x300) {
    bend = Div((0x300 - len) * 0x100, 0x300);
  } else {
    bend = 0;
  }
  if (!p->swayUp) {
    if (p->swayAmp != 0 && ++p->swayTick > 3) {
      p->swayAmp--;
      p->swayTick = 0;
    }
  } else if (p->swayAmp < 8 && ++p->swayTick > 3) {
    p->swayAmp++;
    p->swayTick = 0;
  }
  for (i = 0; i < 5; i++) {
    JormungandrSprite* part = &p->sprites[i];
    Vec3 pos;

    if (i == 0) {
      pos = p->pos;
    } else if (i == 4) {
      pos = p->pos_2f8;
    } else {
      pos.x = (i * p->pos_2f8.x + p->pos.x * (4 - i)) / 4;
      pos.y = (i * p->pos_2f8.y + p->pos.y * (4 - i)) / 4;
      pos.z = (i * p->pos_2f8.z + p->pos.z * (4 - i)) / 4 - Trig_Fix12ToInt(bend * SIN(i * 32));
    }
    if (part->shakeTimer) {
      s32 r = Mod(Random(), 20) - 10;

      pos.x += r;
      pos.z -= r;
      part->shakeTimer--;
    }
    pos.x += Trig_Fix12ToInt(p->swayAmp * SIN(p->swayTimer * 4 + i * 0x40));
    *part->holder.pos = pos;
    if (i > 1) {
      Vec3* prev = p->sprites[i - 1].holder.pos;
      s32 slope = prev->y - pos.y;

      if (slope == 0) {
        slope = 0x40;
      } else {
        slope = Div((prev->z - pos.z) * 0x40, slope);
      }
      if (slope < 24) {
        if (part->variant == 0) {
          part->variant = 1;
          SpriteHolder_SetAnim(&part->holder, part->pose, 1, 0, 1, 0, 4);
        }
      } else if (part->variant == 1) {
        part->variant = 0;
        SpriteHolder_SetAnim(&part->holder, part->pose, 0, 0, 1, 0, 4);
      }
    }
    if (part->visible) {
      SpriteHolder_AdvanceAnim(&part->holder);
    }
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_22)) {
    SpriteHolder_SetPriority(&p->sprites[0].holder, 2);
    SpriteHolder_SetPriority(&p->sprites[1].holder, 2);
  } else {
    SpriteHolder_SetPriority(&p->sprites[0].holder, 1);
    SpriteHolder_SetPriority(&p->sprites[1].holder, 1);
  }
  for (i = 0; i < 3; i++) {
    JormungandrSprite* part = &p->sprites[i + 7];
    Vec3 pos = *p->sprites[2].holder.pos;

    if (i == 2) {
      pos.x += 8;
      pos.y += 16;
      pos.z += 8;
    } else {
      pos.x -= 8;
      pos.y -= 16;
      pos.z -= 8;
    }
    *part->holder.pos = pos;
    if (p->sprites[2].variant == 1) {
      if (part->variant != 1) {
        part->variant = 1;
        SpriteHolder_SetAnim(&part->holder, part->pose + part->variant, 0, 0, 1, 0, 4);
      }
    } else if (part->variant != 0) {
      part->variant = 0;
      SpriteHolder_SetAnim(&part->holder, part->pose + part->variant, 0, 0, 1, 0, 4);
    }
    if (p->swayUp) {
      SpriteHolder_AdvanceAnim(&part->holder);
    }
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_31)) {
    SpriteHolder_ClearFlags(&p->sprites[6].holder, SPRFLAG_HIDDEN);
    *p->sprites[6].holder.pos = *p->sprites[3].holder.pos;
    p->sprites[6].holder.pos->x += 0x80;
    p->sprites[6].holder.pos->y += 0x100;
    p->sprites[6].holder.pos->z += 0x80;
    SpriteHolder_AdvanceAnim(&p->sprites[6].holder);
  } else {
    SpriteHolder_SetFlags(&p->sprites[6].holder, SPRFLAG_HIDDEN);
  }
  if (!TEST_FLAGS(p->base.flags, BOSSFLAG_VISIBLE)) {
    SpriteHolder_SetFlags(&p->sprites[5].holder, SPRFLAG_HIDDEN);
  } else {
    SpriteHolder_ClearFlags(&p->sprites[5].holder, SPRFLAG_HIDDEN);
    *p->sprites[5].holder.pos = *p->sprites[0].holder.pos;
    p->sprites[5].holder.pos->x += 0x10;
    p->sprites[5].holder.pos->y += 0x20;
    p->sprites[5].holder.pos->z += 0x10;
    SpriteHolder_AdvanceAnim(&p->sprites[5].holder);
  }
  if (++p->swayTimer >= 64) {
    p->swayTimer = 0;
  }
#else
  INCFUNC("asm/func/FUN_080c4a74.inc");
#endif
}

// パーツのスプライトを作る, isMain なら MainSprite にする
// part と holder のレジスタ (r6/r10) が入れ替わる, &pos の計算位置が違う
NON_MATCH void FUN_080c5058(JormungandrSprite* part, bool32 isMain, u32 pose, u32 variant, s32 priority, bool32 visible) {
#ifdef NONMATCHING_C
  SpriteHolder* holder = &part->holder;
  Vec3 pos;

  part->variant = variant;
  part->pose = pose;
  part->visible = visible;
  CpuFill32(0, &pos, sizeof(pos));
  if (!isMain) {
    SpriteHolder_InitAux(holder, SPRITE_JORMUNGANDR_8203, ANIM_5C4D, 0, &pos);
    SpriteHolder_SetAnim(holder, part->pose, part->variant, 0, 1, 0, 4);
  } else {
    SpriteHolder_InitMain(holder, SPRITE_JORMUNGANDR, 0, &pos);
    SpriteHolder_SetAnim(holder, part->pose, part->variant, 0, 1, 0, 4);
  }
  SpriteHolder_SetPriority(holder, priority);
  if (!part->visible) {
    SpriteHolder_SetFlags(holder, SPRFLAG_HIDDEN);
  }
#else
  INCFUNC("asm/func/FUN_080c5058.inc");
#endif
}

// パーツのスプライトを全部作り、首の位置を決める
// case 4 を明示すると原典と同じジャンプテーブルになるが、各 case の定数の置き方が違う
NON_MATCH void FUN_080c5124(Jormungandr* p) {
#ifdef NONMATCHING_C
  s32 i;

  p->plttIdx = 0;
  CpuCopy32(&gObjPlttData[0x155 * 16], p->pltt, sizeof(p->pltt));
  for (i = 0; i < 5; i++) {
    bool32 isMain;
    u32 pose;
    u32 variant;
    s32 priority;

    switch (i) {
      case 0: {
        pose = 0;
        isMain = TRUE;
        variant = 0;
        priority = 1;
        break;
      }
      case 1: {
        pose = 0x18;
        isMain = TRUE;
        variant = 0;
        priority = 1;
        break;
      }
      case 2: {
        isMain = FALSE;
        pose = 0;
        variant = 0;
        priority = 2;
        break;
      }
      case 3: {
        variant = 0;
        isMain = FALSE;
        pose = 0;
        priority = 3;
        break;
      }
      case 4: {
        variant = 1;
        isMain = FALSE;
        pose = 0;
        priority = 3;
        break;
      }
    }
    FUN_080c5058(&p->sprites[i], isMain, pose, variant, priority, TRUE);
    if (isMain) {
      p->sprites[i].holder.u.main.sprite.pltt = p->pltt;
    } else {
      p->sprites[i].holder.u.aux.gfx.pltt = p->pltt;
    }
  }
  FUN_080c5058(&p->sprites[6], TRUE, 0x2A, 0, 2, FALSE);
  FUN_080c5058(&p->sprites[5], TRUE, 0x2E, 0, 2, FALSE);
  for (i = 0; i < 3; i++) {
    u32 pose;

    switch (i) {
      case 0: {
        pose = 0x21;
        break;
      }
      case 1: {
        pose = 0x1E;
        break;
      }
      case 2: {
        pose = 0x1B;
        break;
      }
      default: {
        pose = 0;
        break;
      }
    }
    FUN_080c5058(&p->sprites[i + 7], TRUE, pose, 0, 2, TRUE);
    p->sprites[i + 7].holder.u.main.sprite.pltt = p->pltt;
  }
  p->pos_2f8.x = 0x500;
  p->pos_2f8.y = 0x180;
  p->pos_2f8.z = 0x200;
  p->pos = p->pos_2f8;
  p->pos.y += 0x280;
  p->pos.z += 0x100;
  p->pos_2f0 = p->pos;
#else
  INCFUNC("asm/func/FUN_080c5124.inc");
#endif
}

void FUN_080c52e0(JormungandrLeg* part, void (*fn)(JormungandrLeg*)) {
  part->fn = fn;
  part->timer = 0;
}

// タコ足を伸ばしながら揺らす
// ループ先頭で sin の添字を先に計算する形とレジスタ割当が違う (29 hunk)
NON_MATCH void FUN_080c52f0(JormungandrLeg* part) {
#ifdef NONMATCHING_C
  s32 i;

  if (part->timer == 0) {
    PlaySound_082406e0(SONG_556);
  }
  if (++part->timer >= 32) {
    for (i = 0; i < 14; i++) {
      JormungandrLegJoint* joint = &part->joints[i];

      joint->sprite.flags &= ~SPRFLAG_HIDDEN;
      joint->sprite.pos.x = part->flip == 0 ? joint->dist + part->origin->x : part->origin->x - joint->dist;
      joint->sprite.pos.z = part->origin->z + Trig_Fix12ToInt(SIN(part->timer * 16 + i * 12) * joint->amp);
    }
    if (part->timer >= 40) {
      FUN_080c52e0(part, FUN_080c5458);
    }
  } else {
    for (i = 0; i < 14; i++) {
      JormungandrLegJoint* joint = &part->joints[i];
      s32 dist = part->timer * 22 + joint->dist - 0x25C;

      if (dist < 0x60) {
        joint->sprite.flags |= SPRFLAG_HIDDEN;
      } else {
        joint->sprite.flags &= ~SPRFLAG_HIDDEN;
        joint->sprite.pos.x = part->flip == 0 ? part->origin->x + dist : part->origin->x - dist;
        joint->sprite.pos.z = part->origin->z + Trig_Fix12ToInt(joint->amp * SIN(part->timer * 16 + i * 12));
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c52f0.inc");
#endif
}

void FUN_080c5678(JormungandrLeg*);

// タコ足で薙ぎ払う, 足に触れたプレイヤーに攻撃判定を当てる
// angle -= 4 が原典では add #0xFC, 引数の spill 位置と bend 計算の分岐形が違う
NON_MATCH void FUN_080c5458(JormungandrLeg* part) {
#ifdef NONMATCHING_C
  bool32 hit;
  bool32 dir;
  bool32 again;
  s32 i;

  if (part->timer == 0) {
    PlaySound_082406e0(SONG_557);
  }
  hit = FALSE;
  if (part->timer >= 28 && part->timer < 70) {
    if (part->flip == 0) {
      dir = FALSE;
      if (part->timer >= 36) {
        part->angle -= 4;
      }
    } else {
      dir = TRUE;
      if (part->timer >= 36) {
        part->angle += 4;
      }
    }
  } else if (part->flip == 0) {
    dir = TRUE;
    if (part->timer < 28 || part->timer >= 78) {
      part->angle += 4;
    }
  } else {
    dir = FALSE;
    if (part->timer < 28 || part->timer >= 78) {
      part->angle -= 4;
    }
  }
  for (i = 0; i < 14; i++) {
    JormungandrLegJoint* joint = &part->joints[i];
    s32 angle;

    if (dir) {
      joint->bend = (joint->bend * 3 - joint->bendBase) / 4;
    } else {
      joint->bend = (joint->bend * 3 + joint->bendBase) / 4;
    }
    angle = (joint->bend + 0x100 + part->angle) & 0xFF;
    joint->sprite.pos.x = part->origin->x + Trig_Fix12ToInt(joint->dist * COS(angle));
    joint->sprite.pos.z = part->origin->z + Trig_Fix12ToInt(joint->dist * SIN(angle));
    if (!hit) {
      s32 d = gPlayerPtr[0]->mover.pos.x - joint->sprite.pos.x;

      if (d < 0) {
        d = -d;
      }
      if (d < 0x60) {
        d = gPlayerPtr[0]->mover.pos.z - joint->sprite.pos.z;
        if (d < 0) {
          d = -d;
        }
        if (d < 0x60) {
          Hitbox_SetPos(&part->hitbox, &joint->sprite.pos, 0);
          Hitbox_Register(&part->hitbox);
          hit = TRUE;
        }
      }
    }
  }
  if (++part->timer < 82) {
    return;
  }
  again = FALSE;
  if (part->unk_06 == 0 && gPlayerPtr[0]->mover.pos.z < part->origin->z + 0x300) {
    if (part->flip == 0) {
      if (part->origin->x < gPlayerPtr[0]->mover.pos.x) {
        again = TRUE;
      }
    } else if (gPlayerPtr[0]->mover.pos.x < part->origin->x) {
      again = TRUE;
    }
  }
  if (again) {
    part->timer = 0;
  } else {
    FUN_080c52e0(part, FUN_080c5678);
  }
#else
  INCFUNC("asm/func/FUN_080c5458.inc");
#endif
}

// タコ足を引っ込める
// len の +0x60 と joint->dist - 0x2BC が原典では畳まれず別々に残る, スタック 8 バイト差
NON_MATCH void FUN_080c5678(JormungandrLeg* part) {
#ifdef NONMATCHING_C
  bool32 found;
  s32 base;
  s32 len;
  s32 i;

  if (part->timer == 0) {
    PlaySound_082406e0(SONG_556);
  }
  found = FALSE;
  base = 0;
  len = (32 - part->timer) * 22 + 96;
  if (++part->timer >= 32) {
    for (i = 0; i < 14; i++) {
      part->joints[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
    part->active = FALSE;
  } else {
    for (i = 0; i < 14; i++) {
      JormungandrLegJoint* joint = &part->joints[i];
      s32 dist = len + (joint->dist - 700);

      if (dist < 0x60) {
        joint->sprite.flags |= SPRFLAG_HIDDEN;
      } else {
        s32 angle;

        joint->sprite.flags &= ~SPRFLAG_HIDDEN;
        if ((part->timer >> 3) & 1) {
          joint->bend = (joint->bend * 3 - joint->bendBase) / 4;
        } else {
          joint->bend = (joint->bend * 3 + joint->bendBase) / 4;
        }
        if (found) {
          angle = (joint->bend - base + 0x100) & 0xFF;
        } else {
          base = joint->bend;
          angle = 0;
          found = TRUE;
        }
        angle = (part->angle + angle + 0x100) & 0xFF;
        joint->sprite.pos.x = part->origin->x + Trig_Fix12ToInt(dist * COS(angle));
        joint->sprite.pos.z = part->origin->z + Trig_Fix12ToInt(dist * SIN(angle));
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c5678.inc");
#endif
}

void FUN_080c5828(Jormungandr* p) {
  if (p->leg.active) {
    p->leg.fn(&p->leg);
  }
}

// プレイヤーのいる側へタコ足を出す
// ループ内のアドレス計算 (flags はベース+添字, bend/poseIdx はポインタ送り) の形が違う
NON_MATCH void FUN_080c5854(Jormungandr* p) {
#ifdef NONMATCHING_C
  s32 poseOfs;
  s32 i;

  if (!p->leg.active) {
    if (gPlayerPtr[0]->mover.pos.x >= p->pos_2f8.x) {
      p->leg.flip = 0;
    } else {
      p->leg.flip = 1;
    }
    p->leg.active = TRUE;
    p->leg.angle = p->leg.flip << 7;
    poseOfs = (1 - p->leg.flip) * 2;
    for (i = 0; i < 14; i++) {
      p->leg.joints[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      p->leg.joints[i].bend = 0;
      p->leg.joints[i].sprite.poseIdx = p->leg.joints[i].size + poseOfs;
    }
    FUN_080c52e0(&p->leg, FUN_080c52f0);
  }
#else
  INCFUNC("asm/func/FUN_080c5854.inc");
#endif
}

void FUN_080c592c(Jormungandr* p) {
  s32 i;

  if (p->leg.alive) {
    for (i = 0; i < 14; i++) {
      AuxSprite_Remove(&p->leg.joints[i].sprite);
    }
  }
}

void FUN_080c595c(Jormungandr* p, HitboxData* hitbox, s32 power, s32 knockback, s32 unk44) {
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x40, 0x40, 0x40);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, p->base.mover.id, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, HBATTR_18, unk44);
  hitbox->angle = 0x40;
  Hitbox_SetHandler(hitbox, NULL, p);
}

// タコ足の 14 節を作る
// poseIdx = size + 2 が原典では movs #2; add r8 の順 (1 hunk)
NON_MATCH void FUN_080c59f4(Jormungandr* p, s32 power, s32 knockback, s32 unk44) {
#ifdef NONMATCHING_C
  JormungandrLeg* part = &p->leg;
  s32 dist;
  s32 i;

  part->alive = TRUE;
  part->flip = 0;
  part->angle = 0;
  part->active = FALSE;
  part->origin = &p->pos_2f8;
  FUN_080c52e0(part, FUN_080c52f0);
  dist = 0x60;
  for (i = 0; i < 14; i++) {
    JormungandrLegJoint* joint;
    AuxSpriteGfx* gfx;
    SpriteID32 id;
    u8 size;
    u8 amp;

    switch (i) {
      case 0:
      case 1:
      case 2:
      case 3: {
        id = SPRITE_JORMUNGANDR_LEG;
        size = 2;
        dist += 0x50;
        amp = 0x20;
        break;
      }
      case 4:
      case 5:
      case 6:
      case 7: {
        id = SPRITE_JORMUNGANDR_LEG;
        size = 3;
        dist += 0x40;
        amp = 0x28;
        break;
      }
      case 8:
      case 9:
      case 10: {
        id = 0x8207;
        size = 2;
        dist += 0x20;
        amp = 0x30;
        break;
      }
      default: {
        id = 0x8207;
        size = 3;
        dist += 0x14;
        amp = 0x38;
        break;
      }
    }
    joint = &part->joints[i];
    joint->dist = dist;
    joint->size = size;
    joint->amp = amp;
    joint->bendBase = u16_ARRAY_085ad0de[i];
    joint->bend = joint->bendBase;
    gfx = &joint->gfx;
    Video_GetAuxSprite(gfx, id);
    AuxSprite_Add(&joint->sprite, gfx, SPRFLAG_HIDDEN);
    joint->sprite.poseIdx = size + 2;
    joint->sprite.priority = 3;
    gfx->pltt = p->pltt;
    joint->sprite.pos = p->pos_2f8;
    joint->sprite.pos.x += part->flip * joint->dist;
  }
  FUN_080c595c(p, &part->hitbox, power, knockback, unk44);
#else
  INCFUNC("asm/func/FUN_080c59f4.inc");
#endif
}

void FUN_080c5b6c(Jormungandr* p) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x38, 0, 0, 1, 0, 4);
    p->pos.x = p->pos_2f8.x;
    p->pos.y = p->pos_2f8.y + 0x200;
    p->pos.z = p->pos_2f8.z + 0x200;
    p->swayUp = FALSE;
    p->swayAmp = 0;
    p->swayTick = 0;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
}

void FUN_080c5c04(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x39, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer == 10) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
}

// 登場, 首を持ち上げながら 4 本の首の節を順に出す
// pos_2f0 の足し引きの順とレジスタ割当が違う (5 hunk)
NON_MATCH void FUN_080c5c58(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer < 3) {
    p->pos_2f0.y -= 0x10;
    p->pos_2f0.z += 0x10;
    FUN_080c4a2c(p);
  } else if (timer == 3) {
    FUN_080c4a54(p, 4);
  } else if (timer >= 27 && timer < 30) {
    if (timer == 27) {
      p->pos_2f0.y -= 0x20;
      p->pos_2f0.z += 0x20;
    }
    FUN_080c4990(p);
  } else if (timer >= 30 && timer <= 32) {
    p->pos_2f0.y -= 0x30;
    p->pos_2f0.z += 0x30;
    FUN_080c4a2c(p);
  } else if (timer == 33) {
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x280;
    p->pos_2f0.z = p->pos_2f8.z + 0x100;
  } else if (timer > 33) {
    FUN_080c4990(p);
  }
  if (timer == 26) {
    PlaySound_082406e0(SONG_562);
    FUN_080c2680(&p->segSet.segments[0], FUN_080c2824);
  }
  if (timer == 28) {
    FUN_080c2680(&p->segSet.segments[2], FUN_080c2824);
  }
  if (timer == 30) {
    FUN_080c2680(&p->segSet.segments[3], FUN_080c2824);
  }
  if (timer == 32) {
    FUN_080c2680(&p->segSet.segments[1], FUN_080c2824);
  }
  if (timer == 40) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
#else
  INCFUNC("asm/func/FUN_080c5c58.inc");
#endif
}

void FUN_080c5dd0(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x200;
    p->pos_2f0.z = p->pos_2f8.z + 0x200;
    PlaySound_082406e0(SONG_561);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  FUN_080c4990(p);
  if (timer < 84) {
    FUN_080c4a54(p, 16);
  }
  if (timer >= 100) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c5e8c, 46);
  }
}

void FUN_080c5e8c(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x280;
    p->pos_2f0.z = p->pos_2f8.z + 0x100;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 3, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  FUN_080c4990(p);
  if (timer >= 10) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c5fd8, 48);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
}

void FUN_080c5f44(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.z = p->pos_2f8.z + 0x200;
    p->moveAngle = 0xC0;
    PlaySound_082406e0(SONG_549);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 3, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer >= 10) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c5fd8, 48);
  }
}

void FUN_080c5fd8(Jormungandr* p) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x280;
    p->pos_2f0.z = p->pos_2f8.z + 0x100;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  FUN_080c4990(p);
}

void FUN_080c6060(Jormungandr* p) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos.x = p->pos_2f8.x;
    p->pos.y = p->pos_2f8.y;
    p->pos.z = p->pos_2f8.z + 0x200;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x36, 0, 0, 1, 0, 4);
    p->swayUp = FALSE;
    p->swayAmp = 0;
    p->swayTick = 0;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2 | BOSSFLAG_UNK_22);
}

void FUN_080c60f4(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x37, 0, 0, 2, 0, 4);
    p->swayUp = TRUE;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2 | BOSSFLAG_UNK_22);
  if (timer >= 66) {
    p->unk_25fd = TRUE;
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6170, 51);
  }
}

// p を高位レジスタに置く割当の違いだけ (12 hunk)
NON_MATCH void FUN_080c6170(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.z = p->pos_2f8.z + 0x20;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    PlaySound_082406e0(SONG_548);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  FUN_080c4990(p);
  if (timer >= 60) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6248, 52);
  }
#else
  INCFUNC("asm/func/FUN_080c6170.inc");
#endif
}

void FUN_080c6248(Jormungandr* p, s32 timer) {
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  p->pos_2f0.z += 0x60;
  FUN_080c4a2c(p);
  if (p->unk_25fd) {
    if (timer >= 8) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c62cc, 53);
    }
  } else if (timer >= 10) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c5f44, 47);
  }
}

// timer を高位レジスタに置いて p を 3 本持つ形が出ない
NON_MATCH void FUN_080c62cc(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    MsgQueue_EndWait(&p->base.msgQueue, 1);
    PlaySound_082406e0(SONG_549);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 4, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer >= 4) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6354, 54);
  }
#else
  INCFUNC("asm/func/FUN_080c62cc.inc");
#endif
}

// p の写しをもう1本持つ形が出ない (5 hunk)
NON_MATCH void FUN_080c6354(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->roarTimer = 0;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 5, 0, 0, 1, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (p->roarTimer == 0) {
    PlaySound_082406e0(SONG_550);
  }
  if (++p->roarTimer >= 40) {
    p->roarTimer = 0;
  }
  if (timer == 32) {
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x200;
    p->pos_2f0.z = p->pos_2f8.z + 0x200;
  } else if (timer > 32) {
    FUN_080c4990(p);
  }
#else
  INCFUNC("asm/func/FUN_080c6354.inc");
#endif
}

// 倒れる, 首の節を順に崩す
void FUN_080c6414(Boss* boss, s32 timer) {
  Jormungandr* p = (Jormungandr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->sprites[0].visible = FALSE;
    p->pos_2f0 = p->pos;
    p->swayUp = FALSE;
    p->swayAmp = 0;
    p->swayTick = 0;
    FUN_080c4a54(p, 16);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer == 40) {
    FUN_080c2680(&p->segSet.segments[0], FUN_080c2978);
  }
  if (timer == 60) {
    FUN_080c2680(&p->segSet.segments[3], FUN_080c2978);
  }
  if (timer == 80) {
    FUN_080c2680(&p->segSet.segments[2], FUN_080c2978);
  }
  if (timer == 100) {
    FUN_080c2680(&p->segSet.segments[1], FUN_080c2978);
  }
  FUN_080c4990(p);
  if (timer == 44 || timer == 64 || timer == 84 || timer == 104) {
    FUN_080c4a54(p, 4);
    p->pos.y -= 0x20;
  }
  if (timer == 120) {
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
}

// args.argv の書き込みを argc の後に回す形が出ない
NON_MATCH void FUN_080c6500(Jormungandr* p, s32 arg) {
#ifdef NONMATCHING_C
  ScriptArgs args;
  u32 argv[1];

  args.argv = argv;
  if (p->scriptID != 0) {
    args.argc = 1;
    argv[0] = arg;
    VM_ExecByID(p->scriptID, &args);
  }
#else
  INCFUNC("asm/func/FUN_080c6500.inc");
#endif
}

// A ボタンを押している間、太陽ゲージぶん力を溜める, 6 段階溜めきると FUN_080c6a5c へ, 時間切れなら FUN_080c6850 へ
// 溜め処理の分岐とレジスタ割当が大きく違う (59 hunk)
NON_MATCH void FUN_080c6538(Jormungandr* p) {
#ifdef NONMATCHING_C
  bool32 levelUp;
  s32 sun;

  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->chargeLevel = 0;
    p->charge = 0;
    p->chargeNoise = FALSE;
    p->chargeVoice = FALSE;
    HUD_StartCountdown(&p->chargeTimeLeft);
    p->base.hp = p->chargeMax;
    gStat->gaugeValue = p->base.hp;
    gStat->gaugeMax = p->base.hp;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  levelUp = FALSE;
  FUN_080c4114(p);
  sun = gStat->sunGauge;
  if (!(gInput[0].down & A_BUTTON) || sun <= 0) {
    sound_08240740(SONG_217);
    p->chargeNoise = FALSE;
  } else {
    if (!p->chargeVoice) {
      PlaySound_082406e0(u16_ARRAY_085ad0fa[p->chargeLevel]);
      p->chargeVoice = TRUE;
    }
    p->charge += sun;
    p->base.hp = gStat->gaugeMax - p->charge;
    if (p->base.hp < 0) {
      p->base.hp = 0;
    }
    if (p->charge >= Div(p->chargeMax * (p->chargeLevel + 1), 6)) {
      levelUp = TRUE;
      if ((p->chargeLevel & 1) && p->chargeLevel != 5) {
        PlaySound_082406e0(u16_ARRAY_085ad0fa[(p->chargeLevel + 1) >> 1]);
      }
      p->chargeLevel = Div(p->charge * 6, p->chargeMax);
    }
    FUN_080c3fd0(p, sun);
    if (!p->chargeNoise) {
      PlaySound_082406e0(SONG_217);
      p->chargeNoise = TRUE;
    }
  }
  p->smokeTimer += p->chargeLevel;
  if (p->smokeTimer >= 16) {
    Vec3 size;
    WorldPos pos;
    s32 r;

    VEC3_SET(size, 0, 0, 0);
    r = (Random() >> 3) & 0x7F;
    pos.x = p->pos.x + 0x40;
    pos.y = p->pos.y + r;
    pos.z = p->pos.z - (r - 0x200) - 0x40;
    EmitSmoke(&pos, 1, &size, 0, 0, 16, 2, 1);
    FUN_080c4a54(p, 3);
    p->smokeTimer -= 16;
  }
  p->chargeTimeLeft--;
  if (p->chargeLevel == 6) {
    HUD_RemoveCountdown();
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6a5c, 58);
    FUN_080c4254(p);
    sound_08240740(SONG_217);
    FUN_080c6500(p, p->chargeLevel);
  } else if (p->chargeTimeLeft == 0) {
    HUD_RemoveCountdown();
    FUN_080c4254(p);
    sound_08240740(SONG_217);
    Boss_SetState(&p->base, FUN_080c6850, 57);
  } else if (levelUp) {
    FUN_080c6500(p, p->chargeLevel);
  }
#else
  INCFUNC("asm/func/FUN_080c6538.inc");
#endif
}

// 溜め失敗, 首を順に振って起き上がる
void FUN_080c6850(Boss* boss, s32 timer) {
  Jormungandr* p = (Jormungandr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    p->sprites[0].visible = TRUE;
    p->swayUp = TRUE;
    PlaySound_082406e0(SONG_551);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 7, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  if (timer == 16) {
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x1A, 0, 0, 2, 0, 4);
  } else if (timer == 20) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 2, 0, 4);
  } else if (timer == 24) {
    SpriteHolder_SetAnim(&p->sprites[2].holder, 1, p->sprites[2].variant, 0, 2, 0, 4);
  } else if (timer == 28) {
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 2, 0, 4);
  } else if (timer == 32) {
    SpriteHolder_SetAnim(&p->sprites[3].holder, 1, p->sprites[3].variant, 0, 2, 0, 4);
  } else if (timer == 36) {
    SpriteHolder_SetAnim(&p->sprites[2].holder, 0, p->sprites[2].variant, 0, 2, 0, 4);
    PlaySound_082406e0(SONG_231);
  } else if (timer == 40) {
    SpriteHolder_SetAnim(&p->sprites[4].holder, 1, p->sprites[4].variant, 0, 2, 0, 4);
  } else if (timer == 44) {
    SpriteHolder_SetAnim(&p->sprites[3].holder, 0, p->sprites[3].variant, 0, 2, 0, 4);
  } else if (timer == 52) {
    SpriteHolder_SetAnim(&p->sprites[4].holder, 0, p->sprites[4].variant, 0, 2, 0, 4);
  } else if (timer == 70) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x16, 0, 0, 2, 0, 4);
  } else if (timer == 158) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 1, 0, 0, 2, 0, 4);
  } else if (timer == 168) {
    PlaySound_082406e0(SONG_561);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
  } else if (timer > 168) {
    FUN_080c4a54(p, 16);
  }
  if (timer == 170) {
    FUN_080c6500(p, -1);
  }
}

// 溜めきり, 首をのけぞらせてスクリプトに 1 を渡す
// p を 2 本持つ割当と timer の高位レジスタ退避が出ない
NON_MATCH void FUN_080c6a5c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->sprites[0].visible = TRUE;
    p->pos_2f0.x = p->pos_2f8.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x200;
    p->pos_2f0.z = p->pos_2f8.z + 0x200;
    PlaySound_082406e0(SONG_564);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0xF, 0, 0, 1, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_UNK_17 | BOSSFLAG_UNK_19 | BOSSFLAG_HITBOX2);
  FUN_080c4990(p);
  FUN_080c4a54(p, 16);
  SET_FLAGS(p->base.flags, BOSSFLAG_VISIBLE);
  SET_FLAGS(p->base.flags, BOSSFLAG_UNK_22);
  if (timer == 60 && p->scriptID != 0) {
    ScriptArgs args;
    u32 argv[1];

    args.argc = 1;
    argv[0] = 1;
    args.argv = argv;
    VM_ExecByID(p->scriptID, &args);
  }
#else
  INCFUNC("asm/func/FUN_080c6a5c.inc");
#endif
}

// 背中から怪光線を撃つ, 左右交互
// pos の組み立てと乱数の取り方が違う (17 hunk)
NON_MATCH void FUN_080c6b44(Jormungandr* p) {
#ifdef NONMATCHING_C
  if (p->lasers != NULL) {
    Vec3 pos;
    u32 angle;

    if (p->laserSide == 0) {
      pos.x = p->pos.x - 0xD0;
      pos.y = 0x180;
      pos.z = p->pos.z + 0x1B0;
      angle = Mod(Random(), 24) + 0x54;
    } else {
      pos.x = p->pos.x + 0x90;
      pos.y = 0x180;
      pos.z = p->pos.z + 0x1B0;
      angle = Mod(Random(), 24) + 0x14;
    }
    PlaySound_082406e0(SONG_552);
    CreateHomingLaser(p->lasers, &pos, p->base.playerPos[0], angle, 20, Mod(Random(), 6));
    p->laserSide = 1 - p->laserSide;
  }
#else
  INCFUNC("asm/func/FUN_080c6b44.inc");
#endif
}

// 通常の移動, 時々プレイヤーの近くを狙って首を寄せる
// 命令数は同じ, p の写しと分岐のレジスタ割当が違う (36 hunk)
NON_MATCH void FUN_080c6c8c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    p->pos_2f0.z += 0x180;
    p->unk_25fa = 0;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (p->base.damageCallback(&p->base)) {
    return;
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_UNK_22);
  if (p->hitMask & 2) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 8, 0, 0, 1, 0, 4);
    p->hurtAnimTimer = 1;
  } else if (p->hitMask & 1) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0xB, 0, 0, 1, 1, 4);
    p->hurtAnimTimer = 1;
  }
  if (p->hurtAnimTimer == 0) {
    if (p->phase == 2) {
      p->unk_25fa++;
    }
  } else if (++p->hurtAnimTimer >= 24) {
    p->hurtAnimTimer = 0;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    if (p->phase == 2) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c718c, 1);
      p->unk_25fa = 0;
    } else {
      p->slamCount = p->slamCountMax;
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c73c0, 3);
    }
  }
  if (p->unk_25fa >= 150) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c718c, 1);
    p->unk_25fa = 0;
    return;
  }
  if (timer >= 90) {
    s32 d = p->pos.x - gPlayerPtr[0]->mover.pos.x;

    if (d < 0) {
      d = -d;
    }
    if (d < 0x40) {
      p->slamCount = p->slamCountMax;
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c73c0, 3);
      return;
    }
  }
  if (p->leg.active) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c72f4, 2);
    return;
  }
  if (p->hurtKnockback != 0) {
    p->pos.x += Trig_Fix12ToInt(p->hurtKnockback * COS(p->hurtAngle));
    p->pos.y = FixToInt(3, p->pos.y * 7 + p->pos_2f0.y);
    p->pos.z += Trig_Fix12ToInt(p->hurtKnockback * SIN(p->hurtAngle));
    p->hurtKnockback = p->hurtKnockback * 3 >> 2;
    return;
  }
  {
    s32 dx = p->pos_2f0.x - p->pos.x;
    s32 dz = p->pos_2f0.z - p->pos.z;

    if (dx != 0 || dz != 0) {
      s32 angle = ArcTan2_8(dx, dz);

      if (((angle - p->moveAngle + 0x100) & 0xFF) < 0x80) {
        p->moveAngle += p->turnSpeed;
      } else {
        p->moveAngle -= p->turnSpeed;
      }
    }
  }
  p->pos.x += Trig_Fix12ToInt(p->moveSpeed * COS(p->moveAngle));
  p->pos.y = FixToInt(3, p->pos.y * 7 + p->pos_2f0.y);
  p->pos.z += Trig_Fix12ToInt(p->moveSpeed * SIN(p->moveAngle));
  if ((timer & 0x3F) == 0) {
    p->pos_2f0.x = gPlayerPtr[0]->mover.pos.x + (u8)Random() - 0x7F;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    p->pos_2f0.z = (Random() & 0x1FF) + p->pos_2f8.z;
  }
#else
  INCFUNC("asm/func/FUN_080c6c8c.inc");
#endif
}

// 首を後ろに引いて怪光線を 3 回撃つ
// SetAnim 呼び出しが原典では1か所にまとめられる
NON_MATCH void FUN_080c718c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = p->pos.x;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    p->pos_2f0.z = p->pos_2f8.z + 0x60;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    p->unk_25fa = 0;
  }
  if (p->base.damageCallback(&p->base)) {
    return;
  }
  FUN_080c4990(p);
  FUN_080c4a40(p, 0, 1);
  if (timer == 35) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x13, 0, 0, 2, 0, 4);
  } else if (timer == 60) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x14, 0, 0, 1, 0, 4);
    FUN_080c6b44(p);
    p->pos.z -= 0x60;
  } else if (timer == 110) {
    FUN_080c6b44(p);
    p->pos.z -= 0x60;
  } else if (timer == 160) {
    FUN_080c6b44(p);
    p->pos.z -= 0x60;
  } else if (timer == 173) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x15, 0, 0, 2, 0, 4);
  } else if (timer == 210) {
    p->slamCount = p->slamCountMax;
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c73c0, 3);
  }
#else
  INCFUNC("asm/func/FUN_080c718c.inc");
#endif
}

// タコ足を出している間は首を上げて待つ
void FUN_080c72f4(Jormungandr* p) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 800;
    p->pos_2f0.z += 0x80;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x12, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    if (!p->leg.active) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6c8c, 0);
    }
    FUN_080c4990(p);
  }
}

// 叩きつけの構え, プレイヤーの真上へ首を持ち上げる
// p を 2 本持ち timer を高位レジスタに置く割当が出ない
NON_MATCH void FUN_080c73c0(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.x = gPlayerPtr[0]->mover.pos.x;
    p->pos_2f0.z = p->pos_2f8.z + 0x20;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    PlaySound_082406e0(SONG_548);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW);
    FUN_080c4990(p);
    if (timer >= 38) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c74b4, 4);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c73c0.inc");
#endif
}

void FUN_080c74b4(Jormungandr* p, s32 timer) {
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW);
  p->pos_2f0.z += 0x60;
  FUN_080c4a2c(p);
  if (!p->base.damageCallback(&p->base) && timer >= 10) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c7518, 5);
  }
}

// 叩きつけ, slamCount が尽きたら FUN_080c75f8 へ
// 同上, slamCount の減算後の分岐形も違う
NON_MATCH void FUN_080c7518(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.z = p->pos_2f8.z + 0x200;
    p->moveAngle = 0xC0;
    PlaySound_082406e0(SONG_549);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 3, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    if (timer >= 10) {
      FUN_080c4990(p);
    }
    if (timer >= 16) {
      if (--p->slamCount == 0) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c75f8, 6);
      } else {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c73c0, 3);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c7518.inc");
#endif
}

// 叩きつけ後の休み, 30 フレーム目に次の行動を決める
// 分岐の並びとレジスタ割当が違う (17 hunk)
NON_MATCH void FUN_080c75f8(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0.z = p->pos.z - 0x80;
    p->moveAngle = 0xC0;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
    p->unk_25ca = 0;
  }
  if (p->base.damageCallback(&p->base)) {
    return;
  }
  if (p->hitMask & 2) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 8, 0, 0, 1, 0, 4);
    p->hurtAnimTimer = 1;
  } else if (p->hitMask & 1) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0xB, 0, 0, 1, 1, 4);
    p->hurtAnimTimer = 1;
  }
  if (p->hurtAnimTimer != 0 && ++p->hurtAnimTimer >= 24) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    p->hurtAnimTimer = 0;
  }
  FUN_080c4990(p);
  if (timer != 30) {
    return;
  }
  if (++p->slamRound < p->slamRounds) {
    if (p->phase == 2) {
      if ((Random() >> 3) & 1) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c718c, 1);
        p->unk_25fa = 0;
        return;
      }
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6c8c, 0);
      return;
    }
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6c8c, 0);
  } else {
    p->slamRound = 0;
    p->hurtAnimTimer = 0;
    if (p->phase == 0) {
      p->unk_25ec = 0;
      if (Random() & 1) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c86ac, 20);
      } else {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c898c, 23);
      }
    } else if (p->phase == 1) {
      if (!p->altAttack) {
        p->altAttack = TRUE;
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c81e0, 15);
      } else {
        p->altAttack = FALSE;
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c7e54, 11);
      }
    } else {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8cc8, 27);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c75f8.inc");
#endif
}

void FUN_080c797c(Jormungandr*, s32);

// プレイヤーに噛みつく
// 原典は stateEntered の if の中だけ p の写しを別レジスタで使う, その形が出ない
NON_MATCH void FUN_080c789c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  Vec3 pos;

  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->slamCount = 0;
    PlaySound_082406e0(SONG_549);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 4, 0, 0, 2, 0, 4);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_UNK_18);
  pos.x = p->pos.x;
  pos.y = p->pos.y - 0x80;
  pos.z = p->pos.z + 0x1AA;
  FUN_0807ab64(gPlayerPtr[0], &pos, NULL, 2, 1, 0, 0, 0, 0);
  if (timer >= 4) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c797c, 8);
  }
#else
  INCFUNC("asm/func/FUN_080c789c.inc");
#endif
}

void FUN_080c7c20(Boss*, s32);

// 噛みついたまま振り回す, プレイヤーがもがいて 20 回たまると放り投げ、180 フレームで次へ
// 同上, もがき判定の分岐形も違う
NON_MATCH void FUN_080c797c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  Vec3 pos;
  u8 turns;

  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->grabAngle = gPlayerPtr[0]->angle_400;
    p->grabShake = 0;
    p->roarTimer = 0;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 5, 0, 0, 1, 0, 4);
  }
  if (p->grabShake == 0) {
    if (p->roarTimer == 0) {
      PlaySound_082406e0(SONG_550);
    }
    if (++p->roarTimer >= 40) {
      p->roarTimer = 0;
    }
  } else {
    if (p->grabShake == 1) {
      PlaySound_082406e0(SONG_550);
    }
    if (++p->grabShake >= 24) {
      SpriteHolder_SetAnim(&p->sprites[0].holder, 5, 0, 0, 1, 0, 4);
      p->grabShake = 0;
      p->roarTimer = 0;
    }
  }
  pos.x = p->pos.x;
  pos.y = p->pos.y - 0x80;
  pos.z = p->pos.z + 0x1AA;
  FUN_0807ab64(gPlayerPtr[0], &pos, NULL, 2, 1, 0, 1, (timer & 0xF) == 0 ? p->grabDamage : 0, 0);
  turns = gPlayerPtr[0]->angle_400 - p->grabAngle;
  if (turns != p->grabTurns) {
    if (turns == 8 || turns == 16) {
      p->grabShake = 1;
      SpriteHolder_SetAnim(&p->sprites[0].holder, 6, 0, 0, 1, 0, 4);
    }
    p->grabTurns = turns;
  }
  if ((u8)(gPlayerPtr[0]->angle_400 - p->grabAngle) >= 20) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c7b84, 9);
  } else if (timer >= 180) {
    Boss_SetState(&p->base, FUN_080c7c20, 10);
  }
#else
  INCFUNC("asm/func/FUN_080c797c.inc");
#endif
}

// 噛んでいたプレイヤーを放り投げる
void FUN_080c7b84(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    Vec3 pos;

    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x2D, 0, 0, 2, 0, 4);
    pos = gPlayerPtr[0]->mover.pos;
    pos.x = p->pos.x;
    pos.z = p->pos.z + 0x1AA;
    FUN_0807ac74(gPlayerPtr[0], &pos, 100, 0x40, 0x20, 0, 0, 0);
  }
  if (timer >= 44) {
    p->base.subStateDone = TRUE;
  }
}

// ヨルムンガンド撃破後にプレイヤーが噛みつかれるイベント、時間内に太陽チャージしないとゲームオーバーになる
void FUN_080c7c20(Boss* boss, s32 timer) {
  Jormungandr* p = (Jormungandr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    PlaySound_082406e0(SONG_551);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 7, 0, 0, 2, 0, 4);
  }
  if (timer == 16) {
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x1A, 0, 0, 2, 0, 4);
  } else if (timer == 20) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 2, 0, 4);
  } else if (timer == 24) {
    SpriteHolder_SetAnim(&p->sprites[2].holder, 1, p->sprites[2].variant, 0, 2, 0, 4);
  } else if (timer == 28) {
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x17, 0, 0, 2, 0, 4);
  } else if (timer == 32) {
    SpriteHolder_SetAnim(&p->sprites[3].holder, 1, p->sprites[3].variant, 0, 2, 0, 4);
  } else if (timer == 36) {
    SpriteHolder_SetAnim(&p->sprites[2].holder, 0, p->sprites[2].variant, 0, 2, 0, 4);
    gPlayerPtr[0]->hp = 0;
    PlaySound_082406e0(SONG_231);
  } else if (timer == 40) {
    SpriteHolder_SetAnim(&p->sprites[4].holder, 1, p->sprites[4].variant, 0, 2, 0, 4);
  } else if (timer == 44) {
    SpriteHolder_SetAnim(&p->sprites[3].holder, 0, p->sprites[3].variant, 0, 2, 0, 4);
  } else if (timer == 52) {
    SpriteHolder_SetAnim(&p->sprites[4].holder, 0, p->sprites[4].variant, 0, 2, 0, 4);
  } else if (timer == 70) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x16, 0, 0, 2, 0, 4);
  } else if (timer == 158) {
    SpriteHolder_SetAnim(&p->sprites[0].holder, 1, 0, 0, 2, 0, 4);
  } else if (timer == 168) {
    PlaySound_082406e0(SONG_561);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
  } else if (timer > 168) {
    FUN_080c4a54(p, 16);
  }
  if (timer == 190) {
    FUN_0807e854(gPlayerPtr[0]);
    gPlayerPtr[0]->action = 0x1A;
    gPlayerPtr[0]->state = 5;
    gPlayerPtr[0]->stateTimer = 0;
    gPlayerPtr[0]->hp = 0;
    gFlag030047a4 |= FLAG030047A4_GAMEOVER;
  }
}

// 怪光線を撃つ構え
// boss と p を別々の高位レジスタに置く割当が出ない
NON_MATCH void FUN_080c7e54(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 0x80;
    p->pos_2f0.z += 0x60;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    FUN_080c4990(p);
    if (timer > 60) {
      FUN_080c4a40(p, 0, 1);
    }
    if (timer >= 90) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c7f34, 12);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c7e54.inc");
#endif
}

// 同上
NON_MATCH void FUN_080c7f34(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 0x80;
    p->pos_2f0.z += 0x60;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x13, 0, 0, 2, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    FUN_080c4990(p);
    FUN_080c4a40(p, 0, 1);
    if (timer >= 25) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c800c, 13);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c7f34.inc");
#endif
}

// 50 フレームごとに怪光線を撃つ, プレイヤーが近づくと叩きつけへ
// 引数の退避順が逆なだけ (2 hunk)
NON_MATCH void FUN_080c800c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 0x80;
    p->pos_2f0.z += 0x60;
    p->unk_25fc = Mod(Random(), 6);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x14, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    s32 d;

    if (Mod(timer, 50) == 0) {
      FUN_080c6b44(p);
      p->pos.z -= 0x60;
    }
    FUN_080c4990(p);
    d = gPlayerPtr[0]->mover.pos.x - p->pos.x;
    if (d < 0) {
      d = -d;
    }
    if (d < 0x80 && gPlayerPtr[0]->mover.pos.z - p->pos.z < 800) {
      p->slamCount = p->slamCountMax;
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c73c0, 3);
    } else if (timer >= 450) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c819c, 14);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c800c.inc");
#endif
}

void FUN_080c819c(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x15, 0, 0, 2, 0, 4);
  }
  if (timer > 36) {
    p->base.subStateDone = TRUE;
  }
}

// 首を高く上げて左右に振りながら破片を降らせる
// boss と p を別レジスタに置く割当が出ない (15 hunk)
NON_MATCH void FUN_080c81e0(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 0x280;
    p->pos_2f0.z += 0x180;
    PlaySound_082406e0(SONG_560);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.x += Trig_Fix12ToInt(SIN((timer & 0x7F) * 2) * 300);
    p->pos_2f0.y += 0x280 + Trig_Fix12ToInt(SIN((timer & 0x3F) * 4) * 0x40);
    p->pos_2f0.z += 0x180;
    FUN_080c4990(p);
    p->debrisSpawn = 1;
    if (timer >= 128) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8358, 16);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c81e0.inc");
#endif
}

// 同上
NON_MATCH void FUN_080c8358(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 800;
    p->pos_2f0.z += 0x80;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x11, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    FUN_080c4990(p);
    if (timer >= 60) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8434, 17);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8358.inc");
#endif
}

// プレイヤーの手前へ首を寄せる
// 同上
NON_MATCH void FUN_080c8434(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = gPlayerPtr[0]->mover.pos;
    p->pos_2f0.y = p->pos_2f8.y + 0x80;
    p->pos_2f0.z -= 0x400;
    if (p->pos_2f0.z < p->pos_2f8.z) {
      p->pos_2f0.z = p->pos_2f8.z;
    }
    SpriteHolder_SetAnim(&p->sprites[0].holder, 1, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    FUN_080c4990(p);
    if (timer >= 18) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c852c, 18);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8434.inc");
#endif
}

// プレイヤーを追いながら破片を吐き続ける
// 同上, target の組み立ても違う
NON_MATCH void FUN_080c852c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    PlaySound_082406e0(SONG_548);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 2, 0, 0, 1, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[1].holder, 0x18, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    Vec3 target = gPlayerPtr[0]->mover.pos;

    target.y = p->pos_2f8.y + 0x80;
    target.z -= 0x400;
    if (target.z < p->pos_2f8.z) {
      target.z = p->pos_2f8.z;
    }
    p->pos_2f0 = target;
    p->debrisSpawn = 2;
    if (timer >= 300) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8644, 19);
    }
    FUN_080c4990(p);
  }
#else
  INCFUNC("asm/func/FUN_080c852c.inc");
#endif
}

// 原典は p を boss の写しとして r1 に置く (2 hunk)
NON_MATCH void FUN_080c8644(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 3, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base) && timer >= 16) {
    Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6c8c, 0);
  }
#else
  INCFUNC("asm/func/FUN_080c8644.inc");
#endif
}

// 首を上げてタコ足の飾り (sprites[6]) を出す
// boss と p を別レジスタに置く割当が出ない
NON_MATCH void FUN_080c86ac(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 800;
    p->pos_2f0.z += 0x80;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x2F, 0, 0, 2, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x11, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer > 5) {
      SpriteHolder_SetAnim(&p->sprites[0].holder, 0x12, 0, 0, 1, 0, 4);
      SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
    }
    FUN_080c4990(p);
    if (timer >= 42) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c87c8, 21);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c86ac.inc");
#endif
}

// 原典は p を boss の写しとして r1 に置く (2 hunk)
NON_MATCH void FUN_080c87c8(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x30, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    FUN_080c4990(p);
    if (timer > 100) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8848, 22);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c87c8.inc");
#endif
}

void FUN_080c8c4c(Jormungandr*, s32);

// プレイヤーの方へ投げ刃をまっすぐ投げる, 4 回投げたら FUN_080c8c4c へ
// 原典は3つの Boss_SetState がまとめられず別々に残る, timer を高位レジスタに置く割当も違う
NON_MATCH void FUN_080c8848(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->bladeAngle = ArcTan2_8(gPlayerPtr[0]->mover.pos.x - 0x514, gPlayerPtr[0]->mover.pos.z - 0x200);
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x32, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer == 5) {
      FUN_080c35f0(p, 0, p->bladeAngle);
    }
    if (timer >= 90) {
      if (++p->unk_25ec >= 4) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8c4c, 26);
      } else if (!((Random() >> 3) & 1)) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8aa8, 24);
      } else {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c87c8, 21);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8848.inc");
#endif
}

// 首を上げてタコ足の飾り (sprites[6]) を出す
// boss と p を別レジスタに置く割当が出ない
NON_MATCH void FUN_080c898c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 800;
    p->pos_2f0.z += 0x80;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x2F, 0, 0, 2, 0, 4);
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x11, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer > 5) {
      SpriteHolder_SetAnim(&p->sprites[0].holder, 0x12, 0, 0, 1, 0, 4);
      SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
    }
    FUN_080c4990(p);
    if (timer >= 42) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8aa8, 24);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c898c.inc");
#endif
}

void FUN_080c8b28(Jormungandr*, s32);

// 原典は p を boss の写しとして r1 に置く (2 hunk)
NON_MATCH void FUN_080c8aa8(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x31, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    FUN_080c4990(p);
    if (timer > 100) {
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8b28, 25);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8aa8.inc");
#endif
}

// 投げ刃を曲がりながら飛ばす, 4 回投げたら FUN_080c8c4c へ
// 3つの Boss_SetState がまとめられず別々に残る
NON_MATCH void FUN_080c8b28(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->bladeAngle = 8;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x33, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer == 5) {
      FUN_080c35f0(p, 1, p->bladeAngle);
    }
    if (timer >= 90) {
      if (++p->unk_25ec >= 4) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8c4c, 26);
      } else if (!((Random() >> 3) & 1)) {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c8aa8, 24);
      } else {
        Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c87c8, 21);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8b28.inc");
#endif
}

// 原典は p を boss の写しとして r1 に置く (2 hunk)
NON_MATCH void FUN_080c8c4c(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x34, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer >= 48) {
      p->base.flags &= ~BOSSFLAG_UNK_31;
      Boss_SetState(&p->base, (BossUpdateFunc)FUN_080c6c8c, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_080c8c4c.inc");
#endif
}

// boss と p のレジスタ割当が違う (6 hunk)
NON_MATCH void FUN_080c8cc8(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->pos_2f0 = p->pos_2f8;
    p->pos_2f0.y += 800;
    p->pos_2f0.z += 0x80;
    SpriteHolder_SetAnim(&p->sprites[0].holder, 0x11, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer > 5) {
      SpriteHolder_SetAnim(&p->sprites[0].holder, 0x12, 0, 0, 1, 0, 4);
      SpriteHolder_SetAnim(&p->sprites[1].holder, 0x19, 0, 0, 1, 0, 4);
    }
    if (timer >= 20) {
      p->base.subStateDone = TRUE;
    }
    FUN_080c4990(p);
  }
#else
  INCFUNC("asm/func/FUN_080c8cc8.inc");
#endif
}

// 同上 (5 hunk)
NON_MATCH void FUN_080c8dac(Jormungandr* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x2A, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer > 131) {
      p->base.subStateDone = TRUE;
    }
    FUN_080c4990(p);
  }
#else
  INCFUNC("asm/func/FUN_080c8dac.inc");
#endif
}

// プレイヤーを捕まえ、決まった位置に投げ刃の判定を置いて画面を揺らす
void FUN_080c8e14(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    FUN_0807ad60(gPlayerPtr[0], 240);
    FUN_080c3528(&p->blade, p->base.mover.id);
    PlaySound_082406e0(SONG_555);
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x2B, 0, 0, 1, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer < 48) {
      FUN_0823b9cc(0x40);
    } else {
      FUN_0823b9cc(0x70 - timer);
    }
    if (timer > 78) {
      p->base.subStateDone = TRUE;
    }
  }
}

void FUN_080c8eb8(Jormungandr* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    SpriteHolder_SetAnim(&p->sprites[6].holder, 0x2C, 0, 0, 2, 0, 4);
  }
  if (!p->base.damageCallback(&p->base)) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_31);
    if (timer > 144) {
      p->base.flags &= ~BOSSFLAG_UNK_31;
      p->base.subStateDone = TRUE;
    }
  }
}

NAKED void FUN_080c8f20(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c8f20.inc"); }

NAKED void FUN_080c8fe0(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c8fe0.inc"); }

NAKED void FUN_080c9278(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c9278.inc"); }

NAKED void FUN_080c9338(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c9338.inc"); }

NAKED void FUN_080c95cc(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c95cc.inc"); }

NAKED void FUN_080c9648(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c9648.inc"); }

NAKED void FUN_080c96c4(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c96c4.inc"); }

NAKED void FUN_080c9774(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c9774.inc"); }

NAKED void FUN_080c9824(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c9824.inc"); }

NAKED void FUN_080c994c(Jormungandr* p, s32 timer) { INCFUNC("asm/func/FUN_080c994c.inc"); }

NAKED void FUN_080c9aec(Jormungandr* p, u32 param_2) { INCFUNC("asm/func/FUN_080c9aec.inc"); }

NAKED void FUN_080c9cd0(Jormungandr* p) { INCFUNC("asm/func/FUN_080c9cd0.inc"); }

NAKED s32 FUN_080c9d00(Jormungandr* p) { INCFUNC("asm/func/FUN_080c9d00.inc"); }

NAKED s32 FUN_080c9fd4(Jormungandr* p) { INCFUNC("asm/func/FUN_080c9fd4.inc"); }

void FUN_080ca004(Jormungandr* p) {}

void FUN_080ca008(Jormungandr* p) {}

void FUN_080ca00c(Jormungandr* p) {}

void FUN_080ca010(Jormungandr* p) {}

void FUN_080ca014(Jormungandr* p) {}

void FUN_080ca018(Jormungandr* p) {}

void FUN_080ca01c(Jormungandr* p) {}

void FUN_080ca020(Jormungandr* p) {}

void FUN_080ca024(Jormungandr* p) {}

void FUN_080ca028(Jormungandr* p) {}

void FUN_080ca02c(Jormungandr* p) {}

void FUN_080ca030(Jormungandr* p) {}

void FUN_080ca034(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad100[9])(Jormungandr*) = {
      FUN_080ca004,
      FUN_080ca008,
      FUN_080ca00c,
      FUN_080ca010,
      FUN_080ca014,
      FUN_080ca018,
      FUN_080ca01c,
      FUN_080ca020,
      FUN_080ca024,
  };  // 0x085AD100
  PTR_ARRAY_085ad100[p->base.subState2](p);
}

void FUN_080ca050(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad124[2])(Jormungandr*) = {
      FUN_080ca028,
      FUN_080ca02c,
  };  // 0x085AD124
  PTR_ARRAY_085ad124[p->base.subState2](p);
}

void FUN_080ca06c(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad12c[1])(Jormungandr*) = {
      FUN_080ca030,
  };  // 0x085AD12C
  PTR_ARRAY_085ad12c[p->base.subState2](p);
}

void FUN_080ca088(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad130[1])(Jormungandr*) = {
      FUN_080ca034,
  };  // 0x085AD130
  if (!TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2) && !FUN_080c9fd4(p)) {
    PTR_ARRAY_085ad130[p->base.subState1](p);
  }
}

void FUN_080ca0c4(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad134[1])(Jormungandr*) = {
      FUN_080ca050,
  };  // 0x085AD134
  PTR_ARRAY_085ad134[p->base.subState1](p);
}

void FUN_080ca0e0(Jormungandr* p) {
  static void (*const PTR_ARRAY_085ad138[4])(Jormungandr*) = {
      FUN_080ca06c,
      FUN_080ca088,
      FUN_080ca0c4,
      FUN_080ca0e0,
  };  // 0x085AD138
  PTR_ARRAY_085ad138[p->base.subState1](p);
}

NAKED void FUN_080ca0fc(Jormungandr* p) { INCFUNC("asm/func/FUN_080ca0fc.inc"); }

NAKED void FUN_080ca430(void) { INCFUNC("asm/func/FUN_080ca430.inc"); }

NAKED void FUN_080ca4dc(Jormungandr* p) { INCFUNC("asm/func/FUN_080ca4dc.inc"); }

NAKED void FUN_080ca69c(Jormungandr* p) { INCFUNC("asm/func/FUN_080ca69c.inc"); }

NAKED void FUN_080ca760(Jormungandr* p) { INCFUNC("asm/func/FUN_080ca760.inc"); }

NAKED s32 Jormungandr_Update(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Update.inc"); }

NAKED s32 Jormungandr_Destroy(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Destroy.inc"); }

NAKED s32 Jormungandr_Init(Jormungandr* p, unknown* param) { INCFUNC("asm/func/Jormungandr_Init.inc"); }

Jormungandr* Jormungandr_Create(unknown* param) {
  Jormungandr* p = Boss_Get(BOSS_JORMUNGANDR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Jormungandr));
  if (p != NULL) {
    SetEntityRoutine(p, Jormungandr_Update, Jormungandr_Destroy);
    if (Jormungandr_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
