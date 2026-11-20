#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

// 共闘サバタが、 ヴァンパイア,ダーイン戦で作るブラックホール (プレイヤーはサバタがこれを完成させるまで、サバタを敵の攻撃から守る)
// 完成したこれに敵を入れることで、敵にダメージが通るようになる

typedef struct BlackHoleElem {
  Particle ptcl;                                                  // 0x00
  Vec3* center;                                                   // 0x28, 吸い込まれる先, BlackHole.center を指す
  bool16 active;                                                  // 0x2C
  u16 timer;                                                      // 0x2E, 出てからのフレーム数, 16 で消える
  s16 angle;                                                      // 0x30, center から見た向き, 吸い込まれる要素だけが使う
  s16 radius;                                                     // 0x32, center からの距離, 吸い込まれる要素だけが使う
  s16 velX;                                                       // 0x34, 飛び散る要素だけが使う, 毎フレーム 7/8 倍に減る
  s16 velZ;                                                       // 0x36, 飛び散る要素だけが使う, 毎フレーム 7/8 倍に減る
  void (*updateCallback)(struct BlackHoleElem*, ParticleGroup*);  // 0x38, active != 0 のときのみ
} BlackHoleElem;
static_assert(sizeof(BlackHoleElem) == 60);

typedef struct BlackHole {
  Entity e;                                   // 0x000, ENTITY_UNK_10
  AuxSprite spr0;                             // 0x018
  AuxSpriteGfx gfx0;                          // 0x044, SPR_BLACKHOLE
  AuxSprite spr1;                             // 0x060
  AuxSpriteGfx gfx1;                          // 0x08C, SPR_BLACKHOLE
  u16 scale0;                                 // 0x0A8, 下位バイトが spr0.scaleX / scaleY へ毎フレームコピーされる
  u16 scale1;                                 // 0x0AA, 下位バイトが spr1.scaleX / scaleY へ毎フレームコピーされる
  u16 charge;                                 // 0x0AC, 溜まり具合 (0〜0x1400), BlackHole_AddCharge で増え, 0x1400 で吸い込みを始める, 大きさもこれに比例する
  u8 chargeStep;                              // 0x0AE, '.p[0]=8', BlackHole_AddCharge 1回で charge に足す量
  u8 decayStep;                               // 0x0AF, '.p[1]=12', 溜めていないフレームに charge から引く量
  u8 chargedThisFrame;                        // 0x0B0, BlackHole_AddCharge が立て _Update が毎フレーム 0 にする
  u8 state;                                   // 0x0B1, sBlackHoleUpdates の添字, updateCallback と一緒に差し替えられる
  u16 stateTimer;                             // 0x0B2, state を変えるとき 0 に戻る
  u8 scale0Ratio;                             // 0x0B4, scale0 = scale1 * scale0Ratio / 128, 開くときに 0x50 にする
  u8 swallowing;                              // 0x0B5, ボス (リンゴ/ダーイン) を吸い込み中, BlackHole_StartSwallow が立て吸い込みを止めると落とす, 立っている間 spr0 が大きくなって揺れる
  u16 shakeTimer;                             // 0x0B6, swallowing の間毎フレーム +1, 奇数フレームだけ spr0 を shakePos にずらす
  u16 decayDelay;                             // 0x0B8, 0 になるまで charge を減らさないフレーム数, BlackHole_SetDecayDelay で書き BlackHole_AddCharge で 0 に戻す
  u16 humTimer;                               // 0x0BA, 吸い込み (state 6) の間 48 フレームごとに SONG_527 を鳴らす
  u8 unk_bc[0xC0 - 0xBC];                     // 0x0BC, まだ未解析
  Vec3 center;                                // 0x0C0, '.c', 渦の中心, 要素はここへ吸い込まれ, 閉じるときこの近くのプレイヤーを吹き飛ばす
  Vec3 shakePos;                              // 0x0C8, center から x-0x2D, y-0x40, z-0x2D した位置, swallowing の間 spr1 を置き spr0 を揺らす先
  ParticleGroup* group;                       // 0x0D0, PTCL_GROUP_2
  BlackHoleElem elems[12];                    // 0x0D4
  u16 nextElem;                               // 0x3A4, 次に出す elems の添字, 12 で 0 に戻る
  u16 spawnTimer;                             // 0x3A6, 4 フレームごとに要素を1つ出す
  void (*updateCallback)(struct BlackHole*);  // 0x3A8
} BlackHole;
static_assert(sizeof(BlackHole) == 940);

COMMON_DATA BlackHole* gBlackHole = NULL;  // 0x03002BFC

static void BlackHole_SetState(BlackHole*, u8);

static inline void Hitbox_SetIframes(Hitbox* hitbox, u16 iframes) { hitbox->iframes = iframes; }

// 溜まり具合に比例した大きさに乱数で揺らぎを足して拡大率にする
static inline void BlackHole_JitterScale(BlackHole* p) {
  u32 scale = (p->charge >> 6) + 32;
  s32 jitter;

  p->scale1 = scale;
  jitter = Mod(Random(), scale >> 3);
  p->scale1 += jitter;
  p->scale0 = ((p->scale1 * p->scale0Ratio) >> 7) + (jitter >> 1);
}

// ボス (リンゴ/ダーイン) が吸い込まれ始めたときに呼ばれる, 吸い込み中 (state 6) なら音を鳴らして揺らし始める
void BlackHole_StartSwallow(void) {
  if (gBlackHole != NULL && gBlackHole->state == 6) {
    PlaySound_082406e0(SONG_526);
    gBlackHole->swallowing = 1;
  }
}

// ブラックホールを閉じる (state 7) へ移す
void BlackHole_Close(void) {
  if (gBlackHole != NULL) {
    BlackHole_SetState(gBlackHole, 7);
  }
}

// ブラックホールが吸い込んでいる (state 6) か
bool32 BlackHole_IsActive(void) {
  if (gBlackHole == NULL) {
    return FALSE;
  }

  if (gBlackHole->state == 6) {
    return TRUE;
  }
  return FALSE;
}

// ブラックホールがいれば吸い込む中心の座標を out に写す
void BlackHole_GetCenter(Vec3* out) {
  if (gBlackHole != NULL) {
    *out = gBlackHole->center;
  }
}

// サバタが溜めている間毎フレーム呼ばれ, 溜まり具合を chargeStep だけ増やす
void BlackHole_AddCharge(void) {
  if (gBlackHole != NULL) {
    gBlackHole->charge += gBlackHole->chargeStep;
    if (gBlackHole->charge >= 0x1400) {
      gBlackHole->charge = 0x1400;
    }

    gBlackHole->chargedThisFrame = 1;
    gBlackHole->decayDelay = 0;
  }
}

void BlackHole_SetDecayDelay(s32 val) {
  if (gBlackHole != NULL) {
    gBlackHole->decayDelay = val;
  }
}

// 吸い込まれる要素, center の周りを回りながら半径を縮め, center の 128 以内に入るか 16 フレーム経ったら消える
// 残差は r = 0 の movs が timer の strh の前か後かの1命令の位置だけ (92/92), 原典は 0 を消えた側の active にも使う, r の宣言位置・timer++ の分離・r のブロック化 (r6 を使い悪化) は試済
NON_MATCH void BlackHoleElem_UpdateSuck(BlackHoleElem* p, ParticleGroup* group) {
#ifdef NONMATCHING_C
  s32 r = 0;

  if (++p->timer < 16) {
    s32 dx = abs(p->ptcl.pos.x - p->center->x);
    s32 dz = abs(p->ptcl.pos.z - p->center->z);

    if (dx > 127 || dz > 127) {
      r = (p->radius * (16 - p->timer)) >> 4;
      p->angle = (p->angle + 1) & 0xFF;
      p->ptcl.pos.x = p->center->x + POLAR_X(r, p->angle);
      p->ptcl.pos.z = p->center->z + POLAR_Z(r, p->angle);
      return;
    }
  }
  p->active = r;
  p->ptcl.flags |= SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/BlackHoleElem_UpdateSuck.inc");
#endif
}

// 4 フレームごとに, 中心から 0x300〜0x4FF 離れた乱数の向きに吸い込まれる要素を1つ出す
void BlackHole_SpawnSuckElem(BlackHole* p) {
  if ((++p->spawnTimer & 3) == 0) {
    BlackHoleElem* elem = &p->elems[p->nextElem];

    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    elem->ptcl.flags &= ~SPRFLAG_BLINK_ODD;
    elem->center = &p->center;
    elem->radius = (RandomNext() & 0x1FF) + 0x300;
    elem->angle = (RandomNext() >> 4) & 0xFF;
    Particle_SetPose(&elem->ptcl, p->group, PTCL2_1);
    elem->ptcl.pos.x = elem->center->x + FixToInt(12, COS(elem->angle) * elem->radius);
    elem->ptcl.pos.y = elem->center->y;
    elem->ptcl.pos.z = elem->center->z + FixToInt(12, SIN(elem->angle) * elem->radius);
    elem->updateCallback = BlackHoleElem_UpdateSuck;
    elem->active = TRUE;
    elem->timer = 0;
    if (++p->nextElem >= 12) {
      p->nextElem = 0;
    }
  }
}

// 飛び散る要素, 速度を 7/8 倍ずつ落としながら進み, 8 フレームでダーク (大) の絵に変え 10 フレームから点滅し, 16 フレームで消える
void BlackHoleElem_UpdateBurst(BlackHoleElem* p, ParticleGroup* group) {
  if (++p->timer < 16) {
    p->ptcl.pos.x += p->velX;
    p->ptcl.pos.z += p->velZ;
    p->velX = (p->velX * 7) >> 3;
    p->velZ = (p->velZ * 7) >> 3;
    if (p->timer == 8) {
      Particle_SetPose(&p->ptcl, group, PTCL2_DARK_L);
    }
    if (p->timer == 10) {
      p->ptcl.flags |= SPRFLAG_BLINK_ODD;
    }
  } else {
    p->active = FALSE;
    p->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

// 閉じるときに要素 12 個を中心から角度 20 ずつずらした向きへ飛び散らせる
// 残差はレジスタ割当とループ前の並びのみ (144/144), 原典は &gRandTableIdx を r7, SetPose に渡す粒子の誘導変数を r6 (先に作る), 要素を r4 に置く
// Tier A-C は試済 (RandomNext で命令数一致, 添字だけ/ポインタだけの形, 宣言での初期化, for の更新式, 粒子ポインタを別に進める形)
NON_MATCH void BlackHole_BurstElems(BlackHole* p) {
#ifdef NONMATCHING_C
  BlackHoleElem* elem;
  s32 baseAngle;
  s32 i;

  PlaySound_082406e0(SONG_525);
  baseAngle = 0;
  elem = p->elems;
  for (i = 0; i < 12; i++) {
    s32 speed;
    s32 angle;

    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    elem->ptcl.flags &= ~SPRFLAG_BLINK_ODD;
    Particle_SetPose(&p->elems[i].ptcl, p->group, (RandomNext() & 1) + PTCL2_DARK_L);
    elem->ptcl.pos.x = p->center.x;
    elem->ptcl.pos.y = p->center.y;
    elem->ptcl.pos.z = p->center.z;
    speed = Mod(RandomNext(), 96) + 48;
    angle = (baseAngle + (RandomNext() & 0xF)) & 0xFF;
    elem->velX = FixToInt(12, speed * COS(angle));
    elem->velZ = FixToInt(12, speed * SIN(angle));
    elem->updateCallback = BlackHoleElem_UpdateBurst;
    elem->active = TRUE;
    elem->timer = 0;
    baseAngle += 20;
    elem++;
  }
#else
  INCFUNC("asm/func/BlackHole_BurstElems.inc");
#endif
}

// 生きている要素の updateCallback を順に呼ぶ
void BlackHole_UpdateElems(BlackHole* p) {
  BlackHoleElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (elem->active) {
      p->elems[i].updateCallback(elem, p->group);
    }
    elem++;
  }
}

void BlackHole_RemoveElems(BlackHole* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->elems[i].ptcl);
  }
}

// 吸い込まれる / 飛び散る粒子 12 個を隠した状態で登録する
void BlackHole_InitElems(BlackHole* p) {
  s32 i;

  p->nextElem = 0;
  p->spawnTimer = 0;
  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 12; i++) {
    Particle* pt = &p->elems[i].ptcl;

    Particle_Add(pt, p->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(pt, -4, -4);
    Particle_SetPose(pt, p->group, PTCL2_1);
    Particle_SetPltt(pt, 1);
    pt->priority = 1;
    pt->offsetZ = 20;
    p->elems[i].active = FALSE;
    p->elems[i].timer = 0;
  }
}

void BlackHole_UpdateState0(BlackHole*);
void BlackHole_UpdateState1(BlackHole*);
void BlackHole_UpdateState2(BlackHole*);
void BlackHole_UpdateState3(BlackHole*);
void BlackHole_UpdateState4(BlackHole*);
void BlackHole_UpdateState5(BlackHole*);
void BlackHole_UpdateState6(BlackHole*);
void BlackHole_UpdateState7(BlackHole*);

// 状態を差し替える
static void BlackHole_SetState(BlackHole* p, u8 state) {
  static void (*const sBlackHoleUpdates[8])(BlackHole*) = {
      BlackHole_UpdateState0,
      BlackHole_UpdateState1,
      BlackHole_UpdateState2,
      BlackHole_UpdateState3,
      BlackHole_UpdateState4,
      BlackHole_UpdateState5,
      BlackHole_UpdateState6,
      BlackHole_UpdateState7,
  };  // 0x085ABFC8

  p->state = state;
  p->updateCallback = sBlackHoleUpdates[p->state];
  p->stateTimer = 0;
}

void BlackHole_UpdateState0(BlackHole* p) {
  if (p->charge != 0) {
    p->spr0.flags &= ~SPRFLAG_HIDDEN;
    p->spr1.flags &= ~SPRFLAG_HIDDEN;
    p->scale0 = 1, p->scale1 = 1;
    p->scale0Ratio = 0x50, p->swallowing = 0;
    BlackHole_SetState(p, 1);
  }
}

// 開くアニメの拡大率を進め, 上限に達したら次の状態へ移る
// 残差1命令, 原典は 0xFFFF のプールロードを最初の if より前に置いて r6 に残す (最初の比較は lsls/lsrs のまま), こちらは使う場所で読み込む
// 試済: u16 ローカル, 最初の比較にも & 0xFFFF, s32 ローカルで増やす形 (定数は前に出るが最初の比較も ands になる)
NON_MATCH void BlackHole_UpdateState1(BlackHole* p) {
#ifdef NONMATCHING_C
  s32 scale;

  p->scale1 += 4;
  if (p->scale1 > 0x1F) {
    p->scale1 = 0x20;
    BlackHole_SetState(p, 3);
  }

  scale = (p->scale1 * p->scale0Ratio) >> 7;
  p->scale0 = scale;
  if ((scale & 0xFFFF) == 0) {
    p->scale0 = 1;
  }
#else
  INCFUNC("asm/func/BlackHole_UpdateState1.inc");
#endif
}

void BlackHole_UpdateState2(BlackHole* p) {
  if (p->scale1 <= 4) {
    BlackHole_BurstElems(p);
    p->charge = 0;
    p->spr0.flags |= SPRFLAG_HIDDEN;
    p->spr1.flags |= SPRFLAG_HIDDEN;
    BlackHole_SetState(p, 0);
  } else {
    p->scale1 -= 4;
    p->scale0 = (p->scale1 * p->scale0Ratio) >> 7;
    if (p->scale0 == 0) {
      p->scale0 = 1;
    }
  }
}

// 溜まり具合が 0xC00 を超えたら state 4 へ, 0 になったら閉じる (state 2) へ移る
// 残差は p と &scale1 の r4/r5 の入れ替えのみ (56/56), State4/5 は同じ inline で一致, 分岐の向き・charge のローカル化・p の写しは試済
NON_MATCH void BlackHole_UpdateState3(BlackHole* p) {
#ifdef NONMATCHING_C
  if (p->charge > 0xC00) {
    p->charge = 0xC00;
    BlackHole_SetState(p, 4);
  } else if (p->charge == 0) {
    BlackHole_SetState(p, 2);
  }
  BlackHole_JitterScale(p);
#else
  INCFUNC("asm/func/BlackHole_UpdateState3.inc");
#endif
}

// 溜まり具合を最大まで増やしながら要素を吸い込ませ, 満タンになったら「今だ」の声を出して吸い込み (state 6) へ移る
void BlackHole_UpdateState4(BlackHole* p) {
  p->charge += 0x60;
  if (p->charge >= 0x1400) {
    PlaySound_082406e0(VO_SABATA_IMADA);
    p->charge = 0x1400;
    BlackHole_SetState(p, 6);
  }
  BlackHole_SpawnSuckElem(p);
  BlackHole_JitterScale(p);
}

// 溜まり具合を 0xC00 まで減らし, 届いたら待機 (state 3) へ戻る
void BlackHole_UpdateState5(BlackHole* p) {
  p->charge -= 0x60;
  if (p->charge <= 0xC00) {
    p->charge = 0xC00;
    BlackHole_SetState(p, 3);
  }
  BlackHole_JitterScale(p);
}

// 吸い込み中, 粒子を吸い込ませながら唸り音を鳴らし, 溜まり具合が減ったら state 5 へ移る
void BlackHole_UpdateState6(BlackHole* p) {
  if (p->charge >= 0x1400) {
    BlackHole_SpawnSuckElem(p);
  } else {
    p->swallowing = 0;
    BlackHole_SetState(p, 5);
  }
  if (++p->humTimer >= 48) {
    PlaySound_082406e0(SONG_527);
    p->humTimer = 0;
  }
  BlackHole_JitterScale(p);
  if (p->scale0 > 120) {
    p->scale0 = 120;
  }
}

// 閉じていき, 閉じきったら中心の近く (256 以内) にいるプレイヤーを吹き飛ばして消える
void BlackHole_UpdateState7(BlackHole* p) {
  if (p->scale1 <= 12) {
    s32 i;

    for (i = 0; i < 2; i++) {
      s32 dx = p->center.x - gPlayerPtr[i]->mover.pos.x;
      s32 dz = p->center.z - gPlayerPtr[i]->mover.pos.z;

      if (abs(dx) <= 256 && abs(dz) <= 256 && dx * dx + dz * dz <= 0x10000) {
        s32 dir;

        gPlayerPtr[i]->hurtbox.knockback = 100;
        gPlayerPtr[i]->blownAway = 1;
        dir = ((ArcTan2_8(dx, dz) + 0x20) & 0xFF) >> 6;
        gPlayerPtr[i]->facing = (((dir + 1) & 3) << 1) + 1;
        Hitbox_SetIframes(&gPlayerPtr[i]->hurtbox, 30);
      }
    }
    BlackHole_BurstElems(p);
    p->charge = 0;
    p->spr0.flags |= SPRFLAG_HIDDEN;
    p->spr1.flags |= SPRFLAG_HIDDEN;
    BlackHole_SetState(p, 0);
  } else {
    p->scale1 -= 12;
    p->scale0 = (p->scale1 * p->scale0Ratio) >> 7;
    if (p->scale0 == 0) {
      p->scale0 = 1;
    }
  }
}

// 溜めていなければ溜まり具合を減らし, ボスを吸い込んでいる間は内側を大きくして揺らす
void BlackHole_UpdateChargeAndShake(BlackHole* p) {
  if (!p->chargedThisFrame) {
    if (p->decayDelay != 0) {
      p->decayDelay--;
    } else if (p->charge < p->decayStep) {
      p->charge = 0;
    } else {
      p->charge -= p->decayStep;
    }
  }
  if (p->swallowing) {
    p->scale0Ratio += 6;
    if (p->scale0Ratio > 127) {
      p->scale0Ratio = 127;
    }
    if (++p->shakeTimer & 1) {
      p->spr0.pos = p->shakePos;
    } else {
      p->spr0.pos = p->center;
    }
    p->spr1.pos = p->shakePos;
  } else {
    p->scale0Ratio -= 6;
    if (p->scale0Ratio < 0x50) {
      p->scale0Ratio = 0x50;
    }
    p->spr0.pos = p->center;
    p->spr1.pos = p->center;
  }
}

s32 BlackHole_Update(BlackHole* p) {
  if (!TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    u16 scale;
    BlackHole_UpdateElems(p);
    BlackHole_UpdateChargeAndShake(p);
    p->updateCallback(p);
    scale = p->scale0;
    p->spr0.scaleY = scale;
    p->spr0.scaleX = scale;
    scale = p->scale1;
    p->spr1.scaleY = scale;
    p->spr1.scaleX = scale;
    p->chargedThisFrame = 0;
  }

  return 0;
}

s32 BlackHole_Destroy(BlackHole* p) {
  AuxSprite_Remove(&p->spr0);
  AuxSprite_Remove(&p->spr1);
  BlackHole_RemoveElems(p);
  gBlackHole = NULL;
  return 0;
}

// 177/170 命令, 原典は pos を r6:r7 のレジスタに置き p を r8, &scale0 / &scale1 をスタックに退避して後で拡大率を読む, こちらは pos がスタックに落ちる
// spr1 / gfx1 の番地を spr0 / gfx0 + 0x48 で作るので, スプライトと gfx の組を配列にした構造かもしれない, VEC3_SET・拡大率の書き分けは試済
NON_MATCH s32 BlackHole_Init(BlackHole* p) {
#ifdef NONMATCHING_C
  Vec3 pos;

  if (VM_SeekToNamedArg('c')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  p->scale0 = 1, p->scale1 = 1;
  p->scale0Ratio = 0x50, p->swallowing = 0;
  p->charge = 0;
  if (VM_SeekToNamedArg('p')) {
    p->chargeStep = VM_GetValue();
    p->decayStep = VM_GetValue();
  } else {
    p->chargeStep = 8;
    p->decayStep = 12;
  }

  Video_GetAuxSprite(&p->gfx0, SPR_BLACKHOLE);
  AuxSprite_Add(&p->spr0, &p->gfx0, SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
  Video_SetAuxSpritePltt(&p->gfx0, 50);
  AuxSprite_SetPoseIdx(&p->spr0, 0);
  p->spr0.scaleY = p->spr0.scaleX = p->scale0;
  p->spr0.priority = 2;
  p->spr0.pos = pos;

  Video_GetAuxSprite(&p->gfx1, SPR_BLACKHOLE);
  AuxSprite_Add(&p->spr1, &p->gfx1, SPRFLAG_BLINK_ODD | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
  Video_SetAuxSpritePltt(&p->gfx1, 50);
  AuxSprite_SetPoseIdx(&p->spr1, 1);
  p->spr1.scaleY = p->spr1.scaleX = p->scale1;
  p->spr1.priority = 2;
  p->spr1.pos = pos;

  p->center = pos;
  p->shakePos = pos;
  p->shakePos.y -= 0x40;
  p->shakePos.x -= 0x2D;
  p->shakePos.z -= 0x2D;
  BlackHole_InitElems(p);
  BlackHole_SetState(p, 0);
  gBlackHole = p;
  return 0;
#else
  INCFUNC("asm/func/BlackHole_Init.inc");
#endif
}

// 0xBD74, HashName("ブラックホール"), リンゴ,ダーイン戦でサバタが作るブラックホール
BlackHole* BlackHole_Create(void) {
  BlackHole* p;

  if (gBlackHole != NULL) {
    return gBlackHole;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(BlackHole));
  if (p != NULL) {
    SetEntityRoutine(p, BlackHole_Update, BlackHole_Destroy);
    if (BlackHole_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
