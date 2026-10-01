#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "particle.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

// FUN_0801e378 が撒いてから FUN_0801e3d0 が進める、sprites[8..12] 1枚ぶんの再生状態
typedef struct {
  u16 state;  // 0x0, 0=停止, 1..3 が進行段階
  u16 timer;  // 0x2, state ごとの経過フレーム数
} EntityEF6FEffect;
static_assert(sizeof(EntityEF6FEffect) == 4);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_11
  bool8 pending;                // 0x018, FUN_0801e284 が 1 を立て、FUN_0801e26c が立っていたら 0 に戻して真を返す
  u8 unk_19;                    // 0x019, FUN_0801e284 の第2引数
  u8 unk_1a;                    // 0x01A, まだ未解析
  u8 unk_1b;                    // 0x01B, _Init が 0 を入れる
  u8 unk_1c;                    // 0x01C, FUN_0801e290 の第2引数
  u8 unk_1d;                    // 0x01D, FUN_0801e290 の第3引数
  u8 unk_1e;                    // 0x01E, FUN_0801e290 が呼ばれるたび +1, _Init が 0 を入れる
  u8 unk_1f;                    // 0x01F, FUN_0801f214 が 1 を入れる
  u8 unk_20;                    // 0x020, FUN_0801ec6c が 1 を入れる
  u8 unk_21;                    // 0x021, FUN_0801eb64 が 16 を入れて毎フレーム 1 減らすフェードの残りフレーム数
  u8 unk_22;                    // 0x022, FUN_0801eb64 が A を押したときに立てる
  u8 unk_23;                    // 0x023, まだ未解析
  u32 unk_24;                   // 0x024, FUN_0801e284 が 0 を入れる, FUN_0801ec4c / FUN_0801f308 が符号なしで閾値と比べる
  Tilemaps* tilemap;            // 0x028, FUN_0801e2a8 / FUN_0801e328 が GetFile(DIR_TILE_MAP, ...) の戻り値を入れる
  rgb555* plttSrc;              // 0x02C, BGP_A41A
  s16 unk_30;                   // 0x030, FUN_0801eaac が unk_36 の下限として比べる
  s16 unk_32;                   // 0x032, FUN_0801eaac が unk_36 の上限として比べる
  s16 unk_34;                   // 0x034, FUN_0801ea34 が ×32 して unk_58 の目標値として比べる
  s16 unk_36;                   // 0x036, FUN_0801ed18 が 0xB0 を入れる, FUN_0801f130 が unk_34 と比べる
  u8 unk_38;                    // 0x038, まだ未解析
  u8 unk_39;                    // 0x039, FUN_0801eaac が判定結果を入れ、FUN_0801c0d8 へ渡す
  u8 unk_3a;                    // 0x03A, FUN_0801e378 が使う 0..4 を回るカウンタ, effects[] と sprites[8..12] の添字
  u8 unk_3b[0x040 - 0x03B];     // 0x03B, まだ未解析
  u32 unk_40;                   // 0x040, FUN_0801ed18 が 8 フレームごとに 1 減らし、FUN_0801ec6c が 10 まで増やす, 0 でなければ unk_58 を加算する
  u8 unk_44[0x050 - 0x044];     // 0x044, まだ未解析
  s32 unk_50;                   // 0x050
  s32 unk_54;                   // 0x054, FUN_0801e9b0 が >>5 して sprites[2]/[3] の X 座標にする
  s32 unk_58;                   // 0x058, FUN_0801f1d4 が毎フレーム 24/32 倍に減衰させる
  s32 unk_5c;                   // 0x05C
  s32 unk_60;                   // 0x060
  u8 unk_64;                    // 0x064
  u8 unk_65;                    // 0x065, まだ未解析
  u8 unk_66;                    // 0x066, FUN_0801e378 が MainSprite_SetPose のポーズ番号 (+0x14) に使う
  u8 unk_67;                    // 0x067, FUN_0801e980 / FUN_0801e998 が sprites[0].pos.x へ写す
  u8 unk_68;                    // 0x068, まだ未解析
  u8 unk_69;                    // 0x069, FUN_0801f0e4 が 60 を入れる
  u8 unk_6a;                    // 0x06A, FUN_0801f0e4 が 3 を入れる
  u8 unk_6b;                    // 0x06B, FUN_0801f0a4 / FUN_0801f0e4 が使うカウンタ
  u32 unk_6c;                   // 0x06C, 状態ごとの経過フレーム数, 各状態関数が毎フレーム +1 する
  u8 unk_70[0x07C - 0x070];     // 0x070, まだ未解析
  s32 unk_7c;                   // 0x07C, FUN_0801eaac が 100 を上限に加点する
  s32 unk_80;                   // 0x080, FUN_0801eaac がぴったり合った回数を数える
  s32 unk_84;                   // 0x084, FUN_0801eaac が範囲内で外した回数を数える
  s32 unk_88;                   // 0x088, FUN_0801eaac が範囲外だった回数を数える
  s32 unk_8c;                   // 0x08C, FUN_0801e4b0 が 3600 を入れる
  s32 unk_90;                   // 0x090, _Init が書き込む
  u8 unk_94[0x09C - 0x094];     // 0x094, まだ未解析
  EntityEF6FEffect effects[5];  // 0x09C, sprites[8..12] と1対1で対応する再生状態
  MainSpriteGfx gfx0;           // 0x0B0, SPRITE_UI_MISC
  MainSpriteGfx gfx1;           // 0x0D0, SPRITE_UI_START_MENU
  MainSpriteGfx gfx2;           // 0x0F0
  MainSpriteGfx gfx3;           // 0x110
  s32 unk_130;                  // 0x130, _Init が書き込み先として使う
  Particle ptcls[4];            // 0x134, _Destroy が stride 0x28 で4個 Particle_Remove する
  WeaponData weapon;            // 0x1D4, _Init が gWeaponDB[0x0F] を丸ごとコピーする
  MainSprite sprites[13];       // 0x1F8, FUN_0801e458 が13個まとめて MainSprite_Add し、FUN_0801e960 がまとめて Remove する
  MainSprite sprite;            // 0x6D8, _Destroy が MainSprite_Remove に渡す
  rgb555 pltt[16];              // 0x738, FUN_0801e4b0 が gObjPlttData + 0x53E0 から16色コピーして sprites[5].pltt に渡す
  u8* unk_758;                  // 0x758, _Init がポインタを入れる
  u8 unk_75c[1884 - 0x75C];     // 0x75C, まだ未解析
} EntityEF6F;
static_assert(sizeof(EntityEF6F) == 1884);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void Sound_FadeOutBGMTemporarily(u32 speed);
void FUN_0801c0d8(s32 param_1, s32 param_2);

// 次の描画から BG を消す
static inline void HideBG(u32 bits) { gStagedDISPCNT &= ~bits; }

// unk_1a を次の段へ進め、段ごとの経過フレーム数を測り直す
static inline void SetSubState(EntityEF6F* p, u8 state) {
  p->unk_1a = state;
  p->unk_6c = 0;
}

bool32 FUN_0801e26c(EntityEF6F* p) {
  if (p->pending == TRUE) {
    p->pending = FALSE;
    return TRUE;
  }
  return FALSE;
}

void FUN_0801e284(EntityEF6F* p, u8 a) {
  p->unk_19 = a;
  p->unk_24 = 0;
  p->pending = TRUE;
}

void FUN_0801e290(EntityEF6F* p, u8 a, u8 b) {
  p->unk_1c = a;
  p->unk_1d = b;
  p->unk_1e++;
  FUN_0801e284(p, 0);
}

s32 FUN_0801e2a8(EntityEF6F* p, s32 bgIndex) {
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  SetBGPrioDirect(2, 2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  p->plttSrc = GetBgPlttFile(BGP_A41A)->body;
  CpuCopy32(&p->plttSrc[208], &gBgPlttBuffer[208], 96);
  return 0;
}

s32 FUN_0801e328(EntityEF6F* p) {
  s32 bgIndex;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  bgIndex = 2;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(0, 0, 0, 0, -24);
  return 0;
}

void FUN_0801e378(EntityEF6F* p) {
  EntityEF6FEffect* eff = &p->effects[p->unk_3a];
  MainSprite* spr = &p->sprites[8 + p->unk_3a];

  MainSprite_SetPose(spr, &p->gfx0, p->unk_66 + 20, 0);
  MainSprite_Show(spr);
  eff->state = 1;
  eff->timer = 0;
  p->unk_3a++;
  if (p->unk_3a > 4) {
    p->unk_3a = 0;
  }
}

// sprites[8..12] に撒いたエフェクトを1フレーム進める
// 残差1命令: switch の比較木の根が違う (原典は 1, こちらは中央値の 2) ので、ケース集合が {1,2,3} ではない可能性がある
// Tier A は試済 (空の case 0 の追加), 未: ケース集合の再検討
NON_MATCH void FUN_0801e3d0(EntityEF6F* p) {
#ifdef NONMATCHING_C
  EntityEF6FEffect* eff = p->effects;
  MainSprite* spr = &p->sprites[8];
  s32 i;

  for (i = 0; i < 5; i++, eff++, spr++) {
    switch (eff->state) {
      case 1: {
        spr->pos.x = ((8 - eff->timer) << 3) + 4;
        if (eff->timer > 7) {
          spr->pos.x = 4;
          eff->state = 2;
          eff->timer = 0;
        }
        break;
      }
      case 2: {
        if (eff->timer > 0x3F) {
          eff->state = 3;
          eff->timer = 0;
          spr->flags |= SPRFLAG_BLINK_ODD;
        }
        break;
      }
      case 3: {
        if (eff->timer > 7) {
          eff->state = 0;
          eff->timer = 0;
          spr->flags = (spr->flags & ~SPRFLAG_BLINK_ODD) | SPRFLAG_HIDDEN;
        }
        break;
      }
    }
    eff->timer++;
  }
#else
  INCFUNC("asm/func/FUN_0801e3d0.inc");
#endif
}

// 残差はレジスタの割り当てのみ (命令数 40 対 40, 命令の並びは一致)
// 原典は p=r6 / 定数0=r7 / dst=r8, こちらは dst=r6 / p=r7 / 定数0=r8 で、優先度の順が逆になっている
// dst を宣言と同時に初期化して materialize 順は合わせた, 宣言順の入れ替えとポインタ走査のループは効かず
// コンパイルフラグの線は否定済み (-fno-gcse / -fforce-addr / -fno-strict-aliasing / -fno-caller-saves で不変)
NON_MATCH void FUN_0801e458(EntityEF6F* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3* dst = &pos;
  s32 i;

  CpuFill32(0, dst, sizeof(pos));
  for (i = 0; i < 13; i++) {
    MainSprite_Add(&p->sprites[i], &p->gfx0, 0, 0x11, 0, 0, 60, dst);
  }
#else
  INCFUNC("asm/func/FUN_0801e458.inc");
#endif
}

// 残差1命令: sprites[4] の MainSprite_SetPose だけ、原典はポーズ番号 6 を r0/r1 の設定より先に materialize する
// 他の8箇所の SetPose は一致, この1箇所だけ -2 の定数を新しく作る (|= から &= ~ に変わる) 場所と重なっている
// Tier A-C は試済 (ポインタ走査ループ, y の誘導変数の明示, 宣言と同時の初期化), 未: inline 包みは sprites[1] の順序違いと両立しない
NON_MATCH s32 FUN_0801e4b0(EntityEF6F* p) {
#ifdef NONMATCHING_C
  WeaponData* w = &p->weapon;
  MainSprite* spr;
  s32 i;
  s32 y;

  p->unk_8c = 3600;
  p->unk_34 = w->durability;
  p->unk_30 = p->unk_34 - 20;
  p->unk_32 = p->unk_34 + 20;

  if (p->unk_30 < 0) {
    p->unk_30 = 0;
  } else if (p->unk_30 > 176) {
    p->unk_30 = 176;
  }

  if (p->unk_32 < 0) {
    p->unk_32 = 0;
  } else if (p->unk_32 > 176) {
    p->unk_32 = 176;
  }

  p->unk_36 = 0;

  spr = &p->sprites[0];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 4, 0);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[1];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 3, 0);
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 2;

  spr = &p->sprites[2];
  spr->pos.x = p->unk_30;
  MainSprite_SetPose(spr, &p->gfx0, 1, 0);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[3];
  spr->pos.x = p->unk_32;
  MainSprite_SetPose(spr, &p->gfx0, 2, 0);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[4];
  spr->pos.x = p->unk_34;
  MainSprite_SetPose(spr, &p->gfx0, 6, 0);
  spr->priority = 2;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[5];
  spr->pos.x = p->unk_36 - 176;
  MainSprite_SetPose(spr, &p->gfx0, 9, 0);
  spr->priority = 3;
  spr->flags &= ~SPRFLAG_HIDDEN;
  CpuCopy32(&gObjPlttData[0x29F0], p->pltt, sizeof(p->pltt));
  spr->plttID = 0x8100;
  spr->pltt = p->pltt;

  spr = &p->sprites[6];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 10, 0);
  spr->priority = 3;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[7];
  spr->pos.x = 0;
  MainSprite_SetAnim(spr, &p->gfx0, 0, 1, 0);
  spr->priority = 2;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[8];
  y = 32;
  for (i = 0; i < 5; i++, spr++, y += 8) {
    spr->pos.x = 8, spr->pos.y = y;
    MainSprite_SetPose(spr, &p->gfx0, 22, 0);
    spr->priority = 0;
    spr->flags |= SPRFLAG_HIDDEN;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_0801e4b0.inc");
#endif
}

// unk_60 の進み具合に応じて、pltt[15] を (31, 4, 0) から元の色へ 1/32 刻みで寄せていく
void FUN_0801e6a0(EntityEF6F* p) {
  rgb555* pal = &gObjPlttData[0x29F0];
  s32 t = Div(p->unk_60 * 32, 5);
  s32 u = 32 - t;
  s32 r = ((u * 31) + (pal[15] & 0x1F) * t) >> 5;
  s32 g = ((u * 4) + ((pal[15] >> 5) & 0x1F) * t) >> 5;
  s32 b = (((pal[15] >> 10) & 0x1F) * t) >> 5;

  p->pltt[15] = (r & 0x1F) + ((g & 0x1F) << 5) + ((b & 0x1F) << 10);
}

void FUN_0801e708(EntityEF6F* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

NAKED s32 FUN_0801e728(EntityEF6F* p) { INCFUNC("asm/func/FUN_0801e728.inc"); }

void FUN_0801e960(EntityEF6F* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 13; spr++, i++) {
    MainSprite_Remove(spr);
  }
}

void FUN_0801e980(EntityEF6F* p) {
  MainSprite* spr = &p->sprites[0];

  spr->pos.x = p->unk_67;
  MainSprite_Show(spr);
}

void FUN_0801e998(EntityEF6F* p) {
  MainSprite* spr = &p->sprites[0];

  spr->pos.x = p->unk_67;
  MainSprite_Hide(spr);
}

void FUN_0801e9b0(EntityEF6F* p) {
  s32 x = p->unk_54 >> 5;
  MainSprite* spr;

  spr = &p->sprites[2];
  spr->pos.x = x - 24;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }
  MainSprite_Show(spr);
  spr = &p->sprites[3];
  spr->pos.x = x + 24;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }
  MainSprite_Show(spr);
}

void FUN_0801ea14(EntityEF6F* p) {
  MainSprite* spr = &p->sprites[2];

  MainSprite_Hide(spr);
  spr = &p->sprites[3];
  MainSprite_Hide(spr);
}

// unk_50 を往復させながら unk_58 (= unk_54 + unk_50) を更新し、目標の unk_34 に届いていたら真を返す
s32 FUN_0801ea34(EntityEF6F* p) {
  s32 reached = FALSE;

  if (p->unk_5c != 0) {
    p->unk_50 += (p->unk_40 + 2) * 4;
    if (p->unk_50 > 0x2FF) {
      p->unk_50 = 0x300;
      p->unk_5c = 0;
    }
  } else {
    p->unk_50 -= (p->unk_40 + 2) * 4;
    if (p->unk_50 <= -0x300) {
      p->unk_50 = -0x300;
      p->unk_5c = 1;
    }
  }
  p->unk_58 = p->unk_54 + p->unk_50;
  if (p->unk_58 < 0) {
    p->unk_58 = 0;
  } else if (p->unk_58 > 0xB0 * 32) {
    p->unk_58 = 0xB0 * 32;
  }
  if (p->unk_58 == p->unk_34 * 32) {
    reached = TRUE;
  }
  return reached;
}

// unk_36 が unk_30..unk_32 の範囲にどれだけ近く止まったかを採点し、成否に応じた効果音とポーズを選ぶ
void FUN_0801eaac(EntityEF6F* p, s32 param_2) {
  s32 diff = p->unk_34 - p->unk_36;

  if (diff < 0) {
    diff = -diff;
  }

  p->unk_67 = p->unk_36;
  FUN_0801e980(p);

  if (p->unk_36 >= p->unk_30 && p->unk_36 <= p->unk_32) {
    if (diff <= 1) {
      p->unk_39 = 1;
      p->unk_80++;
      p->unk_7c += 100;
      p->unk_66 = 0;
    } else {
      p->unk_39 = 0;
      if (diff <= 99) {
        p->unk_7c += 100 - diff;
      }
      p->unk_84++;
      p->unk_66 = 1;
    }
  } else {
    p->unk_88++;
    p->unk_66 = 2;
  }

  FUN_0801c0d8(p->unk_39, param_2);
  FUN_0801e378(p);
  p->unk_60++;
}

// 残差4命令: FUN_0822f178 の2箇所の呼び出しで、原典は読んだ値を r1 に置いて第2/第3引数を別レジスタ経由で渡す (こちらは値が r2 に乗り引数を直接作る)
// Tier A-B は試済 (ローカル変数の有無/スコープ, インライン包み), 未: Tier C
NON_MATCH void FUN_0801eb64(EntityEF6F* p) {
#ifdef NONMATCHING_C
  if (FUN_0801e26c(p)) {
    TextBox_ShowLine(p->unk_1e);
    p->unk_22 = 0;
  }

  if (p->unk_1c != 0 && p->unk_24 <= 15) {
    u32 n = p->unk_24 >> 1;
    FUN_0822f178(0, 8 - n, n + 8);
  }

  if (p->unk_24 > 31 && p->unk_22 == 0 && (gInput[0].pressed & A_BUTTON)) {
    p->unk_21 = 16;
    p->unk_22 = 1;
    PlaySound_082406e0(0x107);
    MainSprite_SetFlags(&p->sprite, SPRFLAG_HIDDEN);
  }

  if (p->unk_22 != 0) {
    if (p->unk_21 == 0) {
      p->unk_1b++;
      FUN_0801e284(p, p->unk_1b);
    } else {
      p->unk_21--;
      if (p->unk_1d != 0) {
        u32 n = p->unk_21;
        FUN_0822f178(0, 16 - n, (n >> 1) + 8);
      }
    }
  } else {
    if (p->unk_24 == 32) {
      MainSprite_ClearFlags(&p->sprite, SPRFLAG_HIDDEN);
    }
    MainSprite_AdvanceAnim(&p->sprite, &p->gfx3);
  }
#else
  INCFUNC("asm/func/FUN_0801eb64.inc");
#endif
}

void FUN_0801ec4c(EntityEF6F* p) {
  FUN_0801e26c(p);
  if (p->unk_24 > 59) {
    FUN_0801e290(p, 0, 1);
  }
}

// 90フレーム点滅させてから unk_40 を溜めて unk_58 を 0x1600 まで引き上げる2段の演出
void FUN_0801ec6c(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_36 = 0;
    SetSubState(p, 0);
  }

  switch (p->unk_1a) {
    case 0: {
      if ((p->unk_24 & 0x1F) <= 15) {
        p->unk_20 = 1;
      }
      if ((p->unk_24 & 0x1F) == 16) {
        PlaySound_082406e0(0x2B0);
      }
      if (p->unk_6c > 89) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if ((p->unk_24 & 7) == 0 && p->unk_40 <= 9) {
        p->unk_40++;
      }
      if (p->unk_40 != 0) {
        p->unk_58 += p->unk_40 * 8;
        if (p->unk_58 > 0x15FF) {
          p->unk_58 = 0x1600;
        }
      } else {
        p->unk_58 = (p->unk_58 * 60) >> 6;
      }
      if (p->unk_6c > 139) {
        FUN_0801e290(p, 1, 1);
      }
      break;
    }
  }

  p->unk_6c++;
}

// unk_40 を 8 フレームごとに 1 減らし、残っている間は unk_58 を加算、尽きたら 60/64 倍に減衰させる
void FUN_0801ed18(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_36 = 0xB0;
  }

  if ((p->unk_24 & 7) == 0 && p->unk_40 != 0) {
    p->unk_40--;
  }

  if (p->unk_40 != 0) {
    p->unk_58 += p->unk_40 * 8;
    if (p->unk_58 > 0x15FF) {
      p->unk_58 = 0x1600;
    }
  } else {
    p->unk_58 = (p->unk_58 * 60) >> 6;
  }

  if (p->unk_24 > 139) {
    FUN_0801e290(p, 1, 1);
  }
}

// unk_36 が目標の手前に届くまで unk_58 を加速させ、届いたら sprites[5] を3回点滅させる
void FUN_0801ed7c(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_36 = 0;
    p->unk_69 = 60;
    p->unk_6a = 3;
  }

  if ((p->unk_24 & 7) == 0 && p->unk_40 <= 3) {
    p->unk_40++;
  }

  if (p->unk_36 < p->unk_34 - 40) {
    if (p->unk_40 != 0) {
      p->unk_58 += p->unk_40 * 8;
      if (p->unk_58 > 0x15FF) {
        p->unk_58 = 0x1600;
      }
    } else {
      p->unk_58 = (p->unk_58 * 60) >> 6;
    }
  } else {
    p->unk_58 = (p->unk_34 - 40) * 32;
    if (p->unk_6a != 0) {
      if (p->unk_69 != 0) {
        p->unk_69--;
        if (p->unk_69 == 10) {
          MainSprite* spr = &p->sprites[5];

          spr->flags |= SPRFLAG_HIDDEN;
        } else if (p->unk_69 == 0) {
          MainSprite* spr = &p->sprites[5];

          spr->flags &= ~SPRFLAG_HIDDEN;
          p->unk_69 = 30;
          p->unk_6a--;
          PlaySound_082406e0(0x2B0);
        }
      }
    }
  }

  if (p->unk_6a == 0 && p->unk_24 > 0xEF) {
    FUN_0801e290(p, 1, 1);
  }
}

void FUN_0801ee6c(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_69 = 60;
    p->unk_6a = 3;
  }
  if (p->unk_6a != 0) {
    if (p->unk_69 != 0) {
      p->unk_69--;
      if (p->unk_69 == 10) {
        MainSprite_Hide(&p->sprites[4]);
      } else if (p->unk_69 == 0) {
        MainSprite_Show(&p->sprites[4]);
        p->unk_69 = 30;
        p->unk_6a--;
        PlaySound_082406e0(0x2B0);
      }
    }
  }
  if (p->unk_6a == 0 && p->unk_24 > 0xEF) {
    FUN_0801e290(p, 1, 1);
  }
}

// ptcls[0] を点滅させながら unk_58 を目標まで上げ、sprites[1] に位置を渡すまでの5段の演出
void FUN_0801eefc(EntityEF6F* p) {
  Particle* ptcl = p->ptcls;

  if (FUN_0801e26c(p)) {
    ptcl->pos.x = 129, ptcl->pos.y = 120;
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    SetSubState(p, 0);
    p->unk_6a = 3;
  }

  if (p->unk_1a <= 3) {
    if (p->unk_6a != 0) {
      if ((p->unk_24 & 0x1F) <= 15) {
        ptcl->flags |= SPRFLAG_HIDDEN;
      } else {
        ptcl->flags &= ~SPRFLAG_HIDDEN;
      }
      if ((p->unk_6c & 0x1F) == 16) {
        p->unk_6a--;
        PlaySound_082406e0(0x2B0);
      }
    } else {
      ptcl->flags &= ~SPRFLAG_HIDDEN;
    }
  }

  switch (p->unk_1a) {
    case 0: {
      if (p->unk_6c > 120) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if (p->unk_36 < p->unk_34) {
        if (p->unk_40 != 0) {
          p->unk_58 += p->unk_40 * 8;
          if (p->unk_58 > 0x15FF) {
            p->unk_58 = 0x1600;
          }
        } else {
          p->unk_58 = (p->unk_58 * 60) >> 6;
        }
      } else {
        p->unk_58 = p->unk_34 * 32;
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 2: {
      if (p->unk_6c > 60) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 3: {
      if (p->unk_6c > 8) {
        MainSprite* spr = &p->sprites[1];

        SetSubState(p, p->unk_1a + 1);
        ptcl->flags |= SPRFLAG_HIDDEN;
        p->unk_54 = p->unk_58;
        spr->pos.x = p->unk_54 >> 5;
        FUN_0801e9b0(p);
      }
      break;
    }
    case 4: {
      if (p->unk_6c > 60) {
        FUN_0801e290(p, 1, 1);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
  }

  p->unk_6c++;
}

void FUN_0801f054(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_5c = 0;
    p->unk_50 = 0;
    p->unk_60 = 0;
    p->unk_64 = 0;
    p->unk_3a = 0;
    p->unk_6b = 0;
  }
  if (FUN_0801ea34(p)) {
    p->unk_6b++;
    if (p->unk_6b == 3) {
      FUN_0801e290(p, 1, 1);
    }
  }
}

void FUN_0801f0a4(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_6b = 0;
  }
  if (FUN_0801ea34(p)) {
    p->unk_6b++;
    if (p->unk_6b == 3) {
      FUN_0801e290(p, 1, 1);
    }
  }
}

void FUN_0801f0e4(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    p->unk_69 = 60;
    p->unk_6a = 3;
    p->unk_6b = 0;
    FUN_0801eaac(p, 0);
  }
  if (p->unk_6c == 60) {
    FUN_0801e290(p, 1, 1);
  }
  FUN_0801ea34(p);
  p->unk_6c++;
}

// unk_1a を 0→1→2→3→4 と進める4段の演出, 各段は経過フレーム数か unk_36 が unk_34 に届くまで待つ
void FUN_0801f130(EntityEF6F* p) {
  u8 state;

  if (FUN_0801e26c(p)) {
    SetSubState(p, 0);
    FUN_0801eaac(p, 1);
  }

  state = p->unk_1a;
  switch (state) {
    case 0: {
      if (p->unk_6c == 40) {
        FUN_0801eaac(p, 2);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if (p->unk_6c == 40) {
        FUN_0801eaac(p, 1);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 2: {
      if (p->unk_36 == p->unk_34) {
        FUN_0801eaac(p, 0);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 3: {
      if (p->unk_6c == 20) {
        SetSubState(p, 4);
        FUN_0801e290(p, 1, 0);
      }
      break;
    }
  }

  FUN_0801ea34(p);
  p->unk_6c++;
}

void FUN_0801f1d4(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    FUN_0801ea14(p);
    FUN_0801e998(p);
  }
  p->unk_58 = (p->unk_58 * 24) >> 5;
  if (p->unk_6c == 120) {
    FUN_0801e290(p, 0, 1);
  }
  p->unk_6c++;
}

// 120フレーム点滅させたあと BG1-BG3 を消して背景を組み直す2段の演出
void FUN_0801f214(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    SetSubState(p, 0);
  }

  switch (p->unk_1a) {
    case 0: {
      if (p->unk_6c <= 89) {
        if ((p->unk_6c & 0x1F) <= 15) {
          p->unk_1f = 1;
        }
        if ((p->unk_6c & 0x1F) == 16) {
          PlaySound_082406e0(0x2B0);
        }
      }
      if (p->unk_6c == 120) {
        SetSubState(p, p->unk_1a + 1);
        FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
      }
      break;
    }
    case 1: {
      if (p->unk_6c == 32) {
        SetSubState(p, 2);
        Video_GenerateBGMap(0, 0, 0, 0, -96);
        HideBG(DISPCNT_BG1_ON);
        HideBG(DISPCNT_BG2_ON);
        HideBG(DISPCNT_BG3_ON);
        FUN_0801e708(p);
        FUN_0823ce68(2, 4, 4, 4, 4, 0xFFFF, 0);
        FUN_0801e290(p, 1, 0);
        p->sprite.pos.y = 140;
      }
      break;
    }
  }

  p->unk_6c++;
}

void FUN_0801f308(EntityEF6F* p) {
  FUN_0801e26c(p);
  if (p->unk_24 > 63) {
    FUN_0801e290(p, 0, 0);
  }
}

// BGM をフェードアウトさせ、32フレーム後に BG0 を消して unk_90 のスクリプトを起動する
void FUN_0801f328(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
    Sound_FadeOutBGMTemporarily(5);
  }
  if (p->unk_24 > 31 && p->unk_90 != 0) {
    HideBG(DISPCNT_BG0_ON);
    VM_ExecByID(p->unk_90, NULL);
    p->unk_90 = 0;
  }
}

// FUN_0801f328 と同じ流れだが、スプライトと BG を全部消してからスクリプトを起動する
void FUN_0801f38c(EntityEF6F* p) {
  if (FUN_0801e26c(p)) {
    MainSprite_Hide(&p->sprite);
    FUN_0823ce68(3, 4, 4, 4, 4, 0xFFFF, 0);
    Sound_FadeOutBGMTemporarily(5);
  }
  if (p->unk_24 > 31 && p->unk_90 != 0) {
    HideBG(DISPCNT_BG3_ON);
    HideBG(DISPCNT_BG2_ON);
    HideBG(DISPCNT_BG1_ON);
    HideBG(DISPCNT_BG0_ON);
    FUN_0801e708(p);
    VM_ExecByID(p->unk_90, NULL);
    p->unk_90 = 0;
  }
}

void (*const PTR_ARRAY_085aa98c[16])(EntityEF6F*) = {
    FUN_0801eb64, FUN_0801ec4c, FUN_0801ec6c, FUN_0801ed18, FUN_0801ed7c, FUN_0801ee6c, FUN_0801eefc, FUN_0801f054, FUN_0801f0a4, FUN_0801f0e4, FUN_0801f130, FUN_0801f1d4, FUN_0801f214, FUN_0801f308, FUN_0801f328, FUN_0801f38c,
};  // 0x085AA98C

NAKED s32 EntityEF6F_Update(EntityEF6F* p) { INCFUNC("asm/func/EntityEF6F_Update.inc"); }

s32 EntityEF6F_Destroy(EntityEF6F* p) {
  Particle* ptcl;
  s32 i;

  FUN_0801e960(p);
  ptcl = p->ptcls;
  for (i = 0; i < 4; ptcl++, i++) {
    Particle_Remove(ptcl);
  }
  MainSprite_Remove(&p->sprite);
  return 0;
}

NAKED s32 EntityEF6F_Init(EntityEF6F* p) { INCFUNC("asm/func/EntityEF6F_Init.inc"); }

EntityEF6F* EntityEF6F_Create(void) {
  EntityEF6F* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityEF6F));

  if (p != NULL) {
    SetEntityRoutine(p, EntityEF6F_Update, EntityEF6F_Destroy);
    if (EntityEF6F_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
