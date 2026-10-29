#include "emote.h"

#include "constants/songs.h"
#include "enemy.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "mover.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// キャラクターの頭上に出るエモートアイコン(の管理構造体)
typedef struct {
  Entity e;              // 0x000, ENTITY_UNK_9
  AuxSpriteGfx gfx_18;   // 0x018, SPRITE_EMOTION_ICONS_0 (吹き出し無し)
  AuxSpriteGfx gfx_34;   // 0x034, SPRITE_EMOTION_ICONS_1 (吹き出し付き)
  AuxAnimFile* anim_50;  // 0x050, ANIM_6830
  AuxAnimFile* anim_54;  // 0x054, ANIM_D41F
  ParticleGroup* group;  // 0x058, PTCL_GROUP_1
  Emote slots[8];        // 0x05C
  u32 activeMask;        // 0x9FC, 使用中の slots のビットマスク
} EmoteManager;
static_assert(sizeof(EmoteManager) == 2560);

IWRAM_DATA EmoteManager* gEmoteManager = NULL;  // 0x0300015C

EmoteManager* EmoteManager_Create(void);

// スロットのスプライトかパーティクルを外して, スロットを空きに戻す
static inline void Emote_Free(EmoteManager* mgr, Emote* e) {
  Particle* ptcls = e->ptcls;
  AuxSprite* spr = &e->spr;

  if (e->idx >= 0) {
    CLEAR_BIT(mgr->activeMask, e->idx);
    if (e->kind == EMOTE_0 || e->kind == EMOTE_1 || e->kind == EMOTE_4 || e->kind == EMOTE_5) {
      if (e->hasSprite) {
        AuxSprite_Remove(spr);
        e->hasSprite = FALSE;
      }
    } else {
      s32 j;

      for (j = 0; j < 3; j++) {
        if (e->ptclMask & (1 << j)) {
          Particle_Remove(&ptcls[j]);
        }
      }
      e->ptclMask = 0;
    }
    ClearMemory(e, sizeof(Emote));
    e->idx = -1;
  }
}

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

static inline bool8 Emote_TestUnk32(Emote* e, u8 flag) {
  if (e->unk_32[0] & flag) return TRUE;
  return FALSE;
}

static inline bool8 EmoteManager_IsSlotUsed(EmoteManager* p, s32 i) {
  if (p->activeMask & (1 << i)) return TRUE;
  return FALSE;
}

void Emote_ClearPtclState(Emote* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    p->unk_32[i] = 0;
    p->unk_35[i] = 0;
    p->unk_4c[i] = 0;
    p->unk_3e[i] = 0;
  }
}

// 持ち主の敵が今のゾーンにいれば, 種族ごとの音を1回だけ鳴らす, unk_2e の bit0 が鳴らし済みの印
void Emote_PlayEnemySound(Emote* p) {
  Enemy* enemy = p->enemy;

  if (enemy == NULL) {
    return;
  }
  if (IsCurrentZone(enemy->zoneID) && !(p->unk_2e & 1) && enemy->state != 21) {
    SoundID32 se;

    switch (enemy->kind) {
      case ENEK_BOKU:
      case ENEK_28: {
        se = SONG_238;
        break;
      }
      case ENEK_MUMMY: {
        if (p->kind == EMOTE_3) {
          return;
        }
        se = CRY_MUMMY_255;
        break;
      }
      case ENEK_GOLEM:
      case ENEK_30: {
        FUN_080e81dc(enemy, 3);
        p->unk_2e |= 1;
        return;
      }
      case ENEK_COCKA: {
        se = SONG_463;
        break;
      }
      default: {
        return;
      }
    }
    PlaySound_082406e0(se);
    p->unk_2e |= 1;
  }
}

// sEmoteKindUpdates[1] (FUN_080d9758) の下請け, unk_3c が尽きたとき unk_32 の bit0 が立っていればエモートを片付けて TRUE を返す, 残っている間は spr を左右に揺らす
bool8 FUN_080d8788(EmoteManager* p, Emote* emote) {
  AuxSprite* spr = &emote->spr;

  if (emote->unk_3c <= 0) {
    if (Emote_TestUnk32(emote, 1)) {
      Emote_ClearPtclState(emote);
      emote->moverID = 0;
      emote->timer = NULL;
      emote->state = 0;
      spr->flags |= SPRFLAG_HIDDEN;
      CLEAR_BIT(p->activeMask, emote->idx);
      AuxSprite_Remove(spr);
      emote->hasSprite = FALSE;
      emote->idx = -1;
      return TRUE;
    }
  } else {
    if (emote->unk_3c > 10 && Emote_TestUnk32(emote, 1)) {
      spr->pos.x += Mod(Random(), 20) - 10;
    }
    Emote_PlayEnemySound(emote);
    emote->unk_3c--;
  }
  return FALSE;
}

// sEmoteKindUpdates[0] / [4] の下請け, unk_3c が残っている間は unk_32 の bit0 が立っていれば spr を左右に揺らし, 尽きたら bit0 を落とす
void FUN_080d8864(EmoteManager* p, Emote* emote) {
  AuxSprite* spr = &emote->spr;

  if (emote->unk_3c <= 0) {
    if (Emote_TestUnk32(emote, 1)) {
      CLEAR_FLAGS(emote->unk_32[0], 1);
    }
  } else {
    if (Emote_TestUnk32(emote, 1)) {
      spr->pos.x += Mod(Random(), 20) - 10;
    }
    emote->unk_3c--;
  }
}

// 以下8本は Emote_CalcPtclOffset が enemyKind (ENEK_*) で選ぶオフセット計算の変種, kind は EmoteKind, quadrant は向きを4分割したもの
// enemyKind が ENEK_BOKU か ENEK_28 のとき
void FUN_080d88ec(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      if (quadrant == 0) {
        *outX = -12, *outY = 0;
      } else {
        *outX = 0, *outY = 0;
      }
      break;
    }
    case 1: {
      switch (quadrant) {
        case 0:
        case 1:
        case 2:
        case 3: {
          *outX = -16, *outY = -8;
          break;
        }
      }
      break;
    }
    case 2: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 0;
      } else {
        *outX = -8;
      }
      *outY = -4;
      break;
    }
    case 3: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 0;
      } else {
        *outX = -8;
      }
      *outY = -4;
      break;
    }
  }
}

// 向きごとの表示オフセットを返す
// enemyKind が ENEK_MUMMY のとき, quadrant は使わない
void FUN_080d8954(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      *outX = -4, *outY = -15;
      break;
    }
    case 1: {
      *outX = -16, *outY = -8;
      break;
    }
    case 2: {
      *outX = -4, *outY = -4;
      break;
    }
    case 3: {
      *outX = -4, *outY = -4;
      break;
    }
  }
}

// 向きごとの表示オフセットを返す
// enemyKind が ENEK_GOLEM か ENEK_30 のとき, quadrant は使わない
void FUN_080d8990(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      *outX = -4, *outY = -15;
      break;
    }
    case 1: {
      *outX = -16, *outY = -8;
      break;
    }
    case 2: {
      *outX = -4, *outY = -4;
      break;
    }
    case 3: {
      *outX = -4, *outY = -4;
      break;
    }
  }
}

// enemyKind が ENEK_COCKA のとき, この変種だけ enemy を受け取って heightAboveFloor を見る
void FUN_080d89cc(s32 kind, s32* outX, s32* outY, s32 quadrant, Enemy* enemy) {
  bool32 flying = FALSE;

  if (enemy != NULL && enemy->heightAboveFloor > 0) {
    flying = TRUE;
  }

  switch (kind) {
    case 0: {
      if (!flying) {
        switch (quadrant) {
          case 0: {
            *outX = 64, *outY = 0;
            break;
          }
          case 1: {
            *outX = 12, *outY = 32;
            break;
          }
          case 2: {
            *outX = -28, *outY = 0;
            break;
          }
          case 3: {
            *outX = 28, *outY = -32;
            break;
          }
        }
      } else {
        switch (quadrant) {
          case 0: {
            *outX = 192, *outY = 10;
            break;
          }
          case 1: {
            *outX = 30, *outY = 192;
            break;
          }
          case 2: {
            *outX = -26, *outY = 42;
            break;
          }
          case 3: {
            *outX = 64, *outY = -48;
            break;
          }
        }
      }
      break;
    }
    case 1: {
      *outX = -16, *outY = -8;
      break;
    }
    case 2: {
      *outX = -4, *outY = -4;
      break;
    }
    case 3: {
      *outX = -4, *outY = -4;
      break;
    }
  }
}

// enemyKind が ENEK_SKELETON / ENEK_SKELETON_F / ENEK_SKELETON_A のとき
void FUN_080d8a90(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      switch (quadrant) {
        case 0: {
          *outX = 64, *outY = -42;
          break;
        }
        case 1: {
          *outX = -36, *outY = 24;
          break;
        }
        case 2: {
          *outX = -86, *outY = -12;
          break;
        }
        case 3: {
          *outX = 32, *outY = -96;
          break;
        }
      }
      break;
    }
    case 1: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 12, *outY = -32;
      } else {
        *outX = -64, *outY = 0;
      }
      break;
    }
    case 2: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 0;
      } else {
        *outX = -8;
      }
      *outY = -4;
      break;
    }
    case 3: {
      switch (quadrant) {
        case 0: {
          *outX = 10, *outY = 0;
          break;
        }
        case 1: {
          *outX = -14, *outY = 2;
          break;
        }
        case 2: {
          *outX = -16, *outY = -2;
          break;
        }
        case 3: {
          *outX = 8, *outY = -4;
          break;
        }
      }
      break;
    }
  }
}

// enemyKind が ENEK_DOG のとき
void FUN_080d8b58(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      switch (quadrant) {
        case 0: {
          *outX = 220, *outY = 32;
          break;
        }
        case 1: {
          *outX = 64, *outY = 210;
          break;
        }
        case 2: {
          *outX = -32, *outY = 78;
          break;
        }
        case 3: {
          *outX = 64, *outY = -32;
          break;
        }
      }
      break;
    }
    case 1: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 12, *outY = -32;
      } else {
        *outX = -32, *outY = 0;
      }
      break;
    }
    case 2: {
      if (quadrant == 0 || quadrant == 3) {
        *outX = 0;
      } else {
        *outX = -8;
      }
      *outY = -4;
      break;
    }
    case 3: {
      switch (quadrant) {
        case 0: {
          *outX = 2, *outY = 10;
          break;
        }
        case 1: {
          *outX = -8, *outY = 14;
          break;
        }
        case 2: {
          *outX = -10, *outY = 8;
          break;
        }
        case 3: {
          *outX = 6, *outY = 5;
          break;
        }
      }
      break;
    }
  }
}

// enemyKind が ENEK_SHAIAN のとき
void FUN_080d8c20(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0:
    case 1:
    case 2: {
      break;
    }
    case 3: {
      switch (quadrant) {
        case 0: {
          *outX = -2, *outY = -8;
          break;
        }
        case 1: {
          *outX = -7, *outY = -10;
          break;
        }
        case 2: {
          *outX = -7, *outY = -7;
          break;
        }
        case 3: {
          *outX = -1, *outY = -8;
          break;
        }
      }
      break;
    }
  }
}

// Emote_CalcPtclOffset の既定の行き先 (上のどれにも当たらない enemyKind)
void FUN_080d8c70(s32 kind, s32* outX, s32* outY, s32 quadrant) {
  switch (kind) {
    case 0: {
      *outX = -4, *outY = -15;
      break;
    }
    case 1:
    case 4:
    case 5: {
      *outX = -16, *outY = -8;
      break;
    }
    case 2:
    case 3: {
      *outX = -4, *outY = -4;
      break;
    }
  }
}

// enemyKind ごとの表から, kind と向きに応じた表示オフセットを求める
void Emote_CalcPtclOffset(u32 kind, u32 enemyKind, s32 angle, s32* outX, s32* outY, Enemy* enemy) {
  // 角度を4方向に丸めて, 以降は quadrant として使う
  angle = ((angle + 0x20) & 0xFF) >> 6;

  switch (enemyKind) {
    case ENEK_BOKU:
    case ENEK_28: {
      FUN_080d88ec(kind, outX, outY, angle);
      break;
    }
    case ENEK_MUMMY: {
      FUN_080d8954(kind, outX, outY, angle);
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      FUN_080d8990(kind, outX, outY, angle);
      break;
    }
    case ENEK_COCKA: {
      FUN_080d89cc(kind, outX, outY, angle, enemy);
      break;
    }
    case ENEK_SKELETON:
    case ENEK_SKELETON_F:
    case ENEK_SKELETON_A: {
      FUN_080d8a90(kind, outX, outY, angle);
      break;
    }
    case ENEK_DOG: {
      FUN_080d8b58(kind, outX, outY, angle);
      break;
    }
    case ENEK_SHAIAN: {
      FUN_080d8c20(kind, outX, outY, angle);
      break;
    }
    default: {
      FUN_080d8c70(kind, outX, outY, angle);
      break;
    }
  }
}

void nop_080d8ddc(Emote* _) {}

// sEmoteKindUpdates[3] (FUN_080d8e98) の下請け, timer が unk_3e[idx] 以下になった最初の1回だけ unk_4[idx] を乱数で埋めて unk_32[idx] に印を付ける, idx は ptcls の添字 0..2
// 残差は &unk_4[idx] の計算位置 (83/83), 原典は1つ目の乱数を読んだ直後に計算するが, こちらは乱数より前に計算してレジスタ割当がずれる
// Tier A-B は試済 (Random と _Random(table), VEC3_SET, Vec3* ローカル, x だけローカル (7 hunk), idx の型), 未: 乱数の値を先にまとめて作る形
NON_MATCH void FUN_080d8de0(Emote* p, u32 idx) {
#ifdef NONMATCHING_C
  if (gEmoteManager != NULL) {
    if (*(s16*)p->timer <= p->unk_3e[idx] && p->unk_32[idx] != 1) {
      u16* table = gRandomTable;

      p->unk_4[idx].x = (_Random(table) & 15) - 8;
      p->unk_4[idx].y = _Random(table) & 15;
      p->unk_4[idx].z = (_Random(table) & 15) - 8;
      p->unk_32[idx] |= 1;
      p->unk_4c[idx] = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_080d8de0.inc");
#endif
}

// 以下5本は sEmoteKindUpdates の各エントリ (kind ごとの毎フレーム更新), 各 kind の意味が未解明なので名前は据え置き
// kind 3, 3個のパーティクルを持ち主の周りで回し, timer が段階を越えるごとに1個ずつ弾けさせ, 全部消えたら片付ける
// 残差は全体のレジスタ割当とスタック配置 (493/503, 88 hunk), AuxAnim 手動送りが2か所に展開されており SpriteHolder_AdvanceAnim と同じ壁を2回含む
// Tier A は一部のみ (ptcls ローカル), 未: 手動送りの inline 化, Vec3 v の扱い
NON_MATCH void FUN_080d8e98(Emote* p) {
#ifdef NONMATCHING_C
  if (gEmoteManager != NULL) {
    EmoteManager* mgr = gEmoteManager;
    s32 doneCount = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
      Particle* ptcl = &p->ptcls[i];
      AuxAnimState* anim = &p->anim[i];
      Vec3* ofs = &p->unk_4[i];
      ParticleGroup* g;
      AuxAnimCmd* cmd;

      if (!(p->ptclMask & (1 << i))) {
        ptcl->flags |= SPRFLAG_HIDDEN;
        doneCount++;
      } else if (p->unk_32[i] & 1) {
        if (p->unk_4c[i] > 14) {
          ptcl->flags |= SPRFLAG_HIDDEN;
          doneCount++;
        } else {
          switch (p->animSet) {
            case 2: {
              g = mgr->group;
              break;
            }
            case 3: {
              g = mgr->group;
              break;
            }
            default: {
              g = NULL;
              break;
            }
          }
          cmd = &anim->cmds[anim->cmdIdx];
          ptcl->tileNum = (*cmd >> 6) * ((ptcl->spriteWidth >> 3) * (ptcl->spriteHeight >> 3)) + g->tile;
          if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
            ptcl->flags |= SPRFLAG_XFLIP;
          } else {
            ptcl->flags &= ~SPRFLAG_XFLIP;
          }
          if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
            ptcl->flags |= SPRFLAG_YFLIP;
          } else {
            ptcl->flags &= ~SPRFLAG_YFLIP;
          }
          if (++anim->tick >= anim->wait) {
            anim->tick = 0;
            if (anim->flags & ANIM_PLAY_REVERSE) {
              if (anim->cmdIdx == 0) {
                anim->cmdIdx = anim->cmdCount - 1;
              } else {
                anim->cmdIdx--;
              }
            } else {
              if (++anim->cmdIdx >= anim->cmdCount) {
                anim->cmdIdx = 0;
              }
            }
            cmd = &anim->cmds[anim->cmdIdx];
            anim->wait = ((*cmd & 0xF) * anim->speed) >> 6;
          }
          ptcl->pos.x += p->unk_1c.x + ofs->x;
          ptcl->pos.y += p->unk_1c.y + ofs->y;
          ptcl->pos.z += p->unk_1c.z + ofs->z;
          ptcl->flags &= ~SPRFLAG_HIDDEN;
          ofs->y -= p->unk_4c[i] >> 1;
          p->unk_4c[i]++;
        }
      } else if (p->unk_4c[i] > 0) {
        p->unk_4c[i]--;
      } else {
        Vec3 v;

        switch (p->animSet) {
          case 2: {
            g = mgr->group;
            break;
          }
          case 3: {
            g = mgr->group;
            break;
          }
          default: {
            g = NULL;
            break;
          }
        }
        cmd = &anim->cmds[anim->cmdIdx];
        ptcl->tileNum = (*cmd >> 6) * ((ptcl->spriteWidth >> 3) * (ptcl->spriteHeight >> 3)) + g->tile;
        if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
          ptcl->flags |= SPRFLAG_XFLIP;
        } else {
          ptcl->flags &= ~SPRFLAG_XFLIP;
        }
        if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
          ptcl->flags |= SPRFLAG_YFLIP;
        } else {
          ptcl->flags &= ~SPRFLAG_YFLIP;
        }
        if (++anim->tick >= anim->wait) {
          anim->tick = 0;
          if (anim->flags & ANIM_PLAY_REVERSE) {
            if (anim->cmdIdx == 0) {
              anim->cmdIdx = anim->cmdCount - 1;
            } else {
              anim->cmdIdx--;
            }
          } else {
            if (++anim->cmdIdx >= anim->cmdCount) {
              anim->cmdIdx = 0;
            }
          }
          cmd = &anim->cmds[anim->cmdIdx];
          anim->wait = ((*cmd & 0xF) * anim->speed) >> 6;
        }
        v.x = (COS(p->unk_35[i]) * 896) >> 16;
        v.y = (SIN(p->unk_35[i]) * 1120) >> 16;
        p->unk_35[i] += 5;
        ptcl->pos.x = v.x + p->pos->x + p->unk_1c.x;
        ptcl->pos.y = v.y + p->pos->y + p->offsetY + p->unk_1c.y;
        ptcl->pos.z = p->pos->z - v.x + p->unk_1c.z;
        ptcl->flags &= ~SPRFLAG_HIDDEN;
        FUN_080d8de0(p, i);
      }
    }

    if (doneCount > 2) {
      p->state = 0;
      CLEAR_BIT(mgr->activeMask, p->idx);
      p->moverID = 0;
      p->timer = NULL;
      for (i = 0; i < 3; i++) {
        if (p->ptclMask & (1 << i)) {
          Emote_ClearPtclState(p);
          Particle_Remove(&p->ptcls[i]);
        }
      }
      Emote_PlayEnemySound(p);
      p->ptclMask = 0;
      p->idx = -1;
    }
  }
#else
  INCFUNC("asm/func/FUN_080d8e98.inc");
#endif
}

// kind 2, Zzz のパーティクルを持ち主の上で左右に揺らしながら昇らせ, 高さ 210 を超えたら片付ける
// 残差は AuxAnim 手動送りのフリップ判定で定数 1 / 2 を使い回さない点とレジスタ割当 (242/243), SpriteHolder_AdvanceAnim と同じ壁
// Tier A-B は試済 (mgr の受け方, 逆再生の形, 前置 ++ で & 0xFFFF を再現, cmd の再利用, 加算順), 未: フリップ判定を inline にする形
NON_MATCH void FUN_080d92ac(Emote* p) {
#ifdef NONMATCHING_C
  if (gEmoteManager != NULL) {
    EmoteManager* mgr = gEmoteManager;
    Particle* ptcl = &p->ptcls[0];
    AuxAnimState* anim = &p->anim[0];
    ParticleGroup* g;
    AuxAnimCmd* cmd;

    switch (p->animSet) {
      case 2: {
        g = mgr->group;
        break;
      }
      case 3: {
        g = mgr->group;
        break;
      }
      default: {
        g = NULL;
        break;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    ptcl->tileNum = (*cmd >> 6) * ((ptcl->spriteWidth >> 3) * (ptcl->spriteHeight >> 3)) + g->tile;
    if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      ptcl->flags |= SPRFLAG_XFLIP;
    } else {
      ptcl->flags &= ~SPRFLAG_XFLIP;
    }
    if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      ptcl->flags |= SPRFLAG_YFLIP;
    } else {
      ptcl->flags &= ~SPRFLAG_YFLIP;
    }
    if (++anim->tick >= anim->wait) {
      anim->tick = 0;
      if (anim->flags & ANIM_PLAY_REVERSE) {
        if (anim->cmdIdx == 0) {
          anim->cmdIdx = anim->cmdCount - 1;
        } else {
          anim->cmdIdx--;
        }
      } else {
        if (++anim->cmdIdx >= anim->cmdCount) {
          anim->cmdIdx = 0;
        }
      }
      cmd = &anim->cmds[anim->cmdIdx];
      anim->wait = ((*cmd & 0xF) * anim->speed) >> 6;
    }

    p->unk_4[0].x = ((p->unk_4c[0] >> 1) * SIN(p->unk_35[0])) >> 12;
    p->unk_4[0].y += 2;
    p->unk_35[0] += (Random() >> 4) & 7;
    ptcl->pos.x = p->pos->x + p->unk_4[0].x;
    ptcl->pos.y = p->pos->y + p->unk_4[0].y + p->offsetY;
    ptcl->pos.z = p->pos->z - p->unk_4[0].x;
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    if (p->unk_4[0].y <= 60) {
      anim->cmdIdx = 0;
    } else if (p->unk_4[0].y <= 120) {
      anim->cmdIdx = 1;
    } else {
      anim->cmdIdx = 2;
    }
    if (p->unk_4[0].y > 210) {
      p->state = 0;
      CLEAR_BIT(mgr->activeMask, p->idx);
      ptcl->flags |= SPRFLAG_HIDDEN;
      Emote_ClearPtclState(p);
      p->moverID = 0;
      Particle_Remove(ptcl);
      p->ptclMask = 0;
      p->idx = -1;
    } else {
      p->unk_4c[0]++;
    }
  }
#else
  INCFUNC("asm/func/FUN_080d92ac.inc");
#endif
}

// kind 0, アニメを進めながら持ち主の上まで浮き上がらせ, アニメが一周したら片付ける
// 残差は AuxAnim 手動送りのフリップ判定の定数の使い回し, duration を読む幅 (原典は ldrh), ended のレジスタ (253/249), SpriteHolder_AdvanceAnim と同じ壁
// Tier A-B は試済 (前置 ++, 加算順, duration の読み方), 未: フリップ判定と長さ取得を inline にする形
NON_MATCH void FUN_080d94b4(Emote* p) {
#ifdef NONMATCHING_C
  if (gEmoteManager != NULL) {
    EmoteManager* mgr = gEmoteManager;
    AuxSprite* spr = &p->spr;
    AuxAnimState* anim = &p->anim[0];
    AuxAnimCmd* cmd;
    bool32 ended;

    cmd = &anim->cmds[anim->cmdIdx];
    AuxSprite_SetPoseIdx(spr, *cmd >> 6);
    if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      p->spr.flags |= SPRFLAG_XFLIP;
    } else {
      p->spr.flags &= ~SPRFLAG_XFLIP;
    }
    if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      spr->flags |= SPRFLAG_YFLIP;
    } else {
      spr->flags &= ~SPRFLAG_YFLIP;
    }
    if (++anim->tick >= anim->wait) {
      anim->tick = 0;
      if (anim->flags & ANIM_PLAY_REVERSE) {
        if (anim->cmdIdx == 0) {
          anim->cmdIdx = anim->cmdCount - 1;
          ended = TRUE;
        } else {
          anim->cmdIdx--;
          ended = FALSE;
        }
      } else {
        if (++anim->cmdIdx >= anim->cmdCount) {
          anim->cmdIdx = 0;
          ended = TRUE;
        } else {
          ended = FALSE;
        }
      }
      cmd = &anim->cmds[anim->cmdIdx];
      anim->duration = *cmd & 0xF;
      anim->wait = (anim->duration * anim->speed) >> 6;
      if (anim->wait == 0) {
        anim->wait = 1;
      }
    } else {
      ended = FALSE;
    }

    if (p->animID <= 1) {
      p->unk_30 += 25;
      p->unk_2a = p->pos->y + p->offsetY + p->unk_30;
    } else {
      p->unk_30 += 10;
      p->unk_2a = p->pos->y + p->offsetY + p->unk_30;
    }
    if (p->unk_2a > p->offsetX + p->pos->y) {
      p->unk_2a = p->offsetX + p->pos->y;
    }
    if (p->unk_2a < p->offsetX + p->pos->y || p->unk_3c > 0) {
      anim->cmdIdx = 0;
      anim->tick = 0;
    }
    if (p->unk_4c[0] <= 29) {
      anim->cmdIdx = 0;
      anim->tick = 0;
    }

    if (ended) {
      p->state = 0;
      CLEAR_BIT(mgr->activeMask, p->idx);
      spr->flags |= SPRFLAG_HIDDEN;
      p->unk_32[0] = 0;
      p->moverID = 0;
      p->unk_4c[0] = 0;
      AuxSprite_Remove(spr);
      p->hasSprite = FALSE;
      p->idx = -1;
    } else {
      spr->flags &= ~SPRFLAG_HIDDEN;
      if (p->pos != NULL) {
        spr->pos = *p->pos;
        spr->pos.x += p->unk_1c.x;
        spr->pos.y = p->unk_2a + p->unk_1c.y;
        spr->pos.z += p->unk_1c.z;
      }
      FUN_080d8864(mgr, p);
      p->unk_4c[0]++;
    }
  }
#else
  INCFUNC("asm/func/FUN_080d94b4.inc");
#endif
}

// FUN_080d9758 の下請け, timer の残りに応じて animID を 0..3 から選び直し, 残りが尽きたら animID を 4 にして unk_3c に 20 を入れる, unk_32 の bit2 が立っていれば何もしない
void FUN_080d96b8(Emote* p) {
  if (!Emote_TestUnk32(p, 4)) {
    if (*(s16*)p->timer <= 0) {
      p->unk_3c = 20;
      p->unk_32[0] |= 5;
      p->animID = 4;
    } else {
      s32 i;

      for (i = 4; i > 0; i--) {
        if (*(s16*)p->timer >= p->unk_3e[0] * i) {
          p->animID = 4 - i;
          break;
        }
      }
      p->unk_3c = 0;
      CLEAR_FLAGS(p->unk_32[0], 5);
      p->unk_2e &= ~1;
    }
  }
}

// kind 1, 吹き出しを持ち主の上に置き直し, timer に応じて絵を切り替えて上下に揺らす
void FUN_080d9758(Emote* p) {
  if (gEmoteManager != NULL) {
    EmoteManager* mgr = gEmoteManager;
    AuxSprite* spr = &p->spr;

    p->spr.flags &= ~SPRFLAG_HIDDEN;
    FUN_080d96b8(p);
    AuxSprite_SetPoseIdx(spr, p->animID);
    if (p->pos != NULL) {
      s32 y;

      spr->pos = *p->pos;
      y = p->unk_2a;
      if (!Emote_TestUnk32(p, 1)) {
        s32 wave = SIN(p->unk_35[0]);

        y += wave >> 8;
      }
      spr->pos.x += p->unk_1c.x;
      spr->pos.y += p->unk_1c.y + y;
      spr->pos.z += p->unk_1c.z;
    }
    if (!FUN_080d8788(mgr, p)) {
      p->unk_35[0] += 4;
    }
  }
}

// kind 4 と kind 5, 出てから4フレームは unk_30 ずつ浮き上がり, 10フレーム目までは FUN_080d8864 で左右に揺らし, その後はサインで上下に揺らす
void FUN_080d9800(Emote* p) {
  EmoteManager* mgr = gEmoteManager;

  if (mgr != NULL) {
    AuxSprite* spr = &p->spr;

    p->spr.flags &= ~SPRFLAG_HIDDEN;
    AuxSprite_SetPoseIdx(spr, p->animID);
    if (p->pos != NULL) {
      spr->pos = *p->pos;
      if (p->unk_4c[0] <= 3) {
        p->unk_30 += 20;
        spr->pos.y = p->unk_2a = p->pos->y + p->offsetY + p->unk_30;
      } else if (p->unk_4c[0] <= 9) {
        p->unk_3c = 1;
        spr->pos.y = p->pos->y + p->offsetY + p->unk_30;
        p->unk_32[0] |= 1;
        FUN_080d8864(mgr, p);
      } else {
        s32 y = p->pos->y + p->offsetY + p->unk_30;
        s32 wave = SIN(p->unk_35[0]);

        spr->pos.y = y + (wave >> 8);
        p->unk_35[0] += 4;
      }
      spr->pos.x += p->unk_1c.x;
      spr->pos.y += p->unk_1c.y;
      spr->pos.z += p->unk_1c.z;
      if (p->unk_4c[0] <= 9) {
        p->unk_4c[0]++;
      }
    }
  }
}

// 持ち主に合わせて表示オフセットを取り直してから, kind ごとの更新を呼ぶ
void Emote_Update(Emote* p) {
  static void (*const sEmoteKindUpdates[6])(Emote*) = {
      [EMOTE_0] = FUN_080d94b4,
      [EMOTE_1] = FUN_080d9758,
      [EMOTE_2] = FUN_080d92ac,
      [EMOTE_3] = FUN_080d8e98,
      [EMOTE_4] = FUN_080d9800,
      [EMOTE_5] = FUN_080d9800,
  };  // 0x085AD2EC

  Mover* mover = p->mover;
  if (mover != NULL) {
    if (p->enemyKind == 0xFF) {
      p->unk_1c = mover->unk_30;
    } else {
      s32 x, y;

      Emote_CalcPtclOffset(p->kind, p->enemyKind, mover->angle, &x, &y, p->enemy);
      if (p->kind == EMOTE_2 || p->kind == EMOTE_3) {
        s32 i;

        for (i = 0; i < 3; i++) {
          if (p->ptclMask & (1 << i)) {
            Particle_SetOffset(&p->ptcls[i], x, y);
          }
        }
      } else {
        VEC3_SET(p->unk_1c, x, 0, y);
      }
    }
  }
  sEmoteKindUpdates[p->kind](p);
}

// 空いているスロットを1つ使用中にして, 添字を idx に入れて返す
static Emote* EmoteManager_AllocSlot_Internal(EmoteManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!EmoteManager_IsSlotUsed(p, i)) {
      Emote* e = &p->slots[i];

      p->activeMask |= 1 << i;
      e->idx = i;
      return e;
    }
  }
  return NULL;
}

// EmoteManager_AllocSlot_Internal を呼んで NULL ならそのまま返すだけのラッパ, 挟まっている理由は不明
Emote* EmoteManager_AllocSlot(EmoteManager* p) {
  Emote* e = EmoteManager_AllocSlot_Internal(p);

  if (e == NULL) {
    return NULL;
  }

  return e;
}

/**
 * @brief emote が moverID の kind のエモートなら片付けて NULL を返す, kind が違えば emote をそのまま返す
 * @param kind エモートの種類 (see EmoteKind)
 */
Emote* Emote_Remove(Emote* emote, u32 kind, u32 moverID) {
  EmoteManager* mgr;
  Particle* ptcls;
  AuxSprite* spr;

  if (emote == NULL) {
    return NULL;
  }
  mgr = gEmoteManager;
  if (mgr == NULL) {
    return NULL;
  }
  if (emote->idx < 0 || emote->moverID != moverID) {
    return NULL;
  }
  ptcls = emote->ptcls;
  spr = &emote->spr;

  if (emote->kind == kind) {
    CLEAR_BIT(mgr->activeMask, emote->idx);
    if (emote->kind == EMOTE_0 || emote->kind == EMOTE_1 || emote->kind == EMOTE_4 || emote->kind == EMOTE_5) {
      if (emote->hasSprite) {
        AuxSprite_Remove(spr);
        emote->hasSprite = FALSE;
      }
    } else {
      s32 i;

      for (i = 0; i < 3; i++) {
        if (emote->ptclMask & (1 << i)) {
          Particle_Remove(&ptcls[i]);
        }
      }
      emote->ptclMask = 0;
    }
    ClearMemory(emote, sizeof(Emote));
    emote->idx = -1;
    return NULL;
  }
  return emote;
}

/**
 * @brief Emote_Remove のパーティクル版, emote が moverID の kind のエモートならパーティクルを外して NULL を返す, kind が違えば emote をそのまま返す
 * @param kind エモートの種類 (see EmoteKind)
 */
Emote* Emote_RemovePtcl(Emote* emote, u32 kind, u32 moverID) {
  EmoteManager* mgr;
  Particle* ptcls;

  if (emote == NULL) {
    return NULL;
  }
  mgr = gEmoteManager;
  if (mgr == NULL) {
    return NULL;
  }
  ptcls = emote->ptcls;
  if (emote->idx < 0 || emote->moverID != moverID) {
    return NULL;
  }

  if (emote->kind == kind) {
    s32 i;

    CLEAR_BIT(mgr->activeMask, emote->idx);
    for (i = 0; i < 3; i++) {
      if (emote->ptclMask & (1 << i)) {
        Particle_Remove(&ptcls[i]);
      }
    }
    emote->ptclMask = 0;
    ClearMemory(emote, sizeof(Emote));
    emote->idx = -1;
    return NULL;
  }
  return emote;
}

// 以下7本は Emote_Show が kind で選ぶ生成の入口
// "!" や "?" のエモート (kind 0) を出す, 出てから10フレームは左右に揺れる
// 残差はレジスタ割当 (191/193), 原典は spr を2本の擬似レジスタに持ち (途中の AuxSprite_Add 等と末尾の pos 複写で別), hasSprite のアドレスもスタックへ逃がす, FUN_080da358 と同じ型の残差
// Tier A-C は試済 (e->spr.pos 直書き, TRUE, 途中と末尾で別変数にすると 7 hunk まで寄るが不自然なので不採用), 未: 写し直しを生む元の構造の特定
NON_MATCH Emote* FUN_080d9b3c(u8 animID, WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, Enemy* enemy, Mover* mover) {
#ifdef NONMATCHING_C
  EmoteManager* mgr;
  Emote* e;
  s32 x, y;
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  AuxAnimFile* files;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  e = EmoteManager_AllocSlot(mgr);
  if (e == NULL) {
    return NULL;
  }

  e->mover = mover;
  e->animID = animID;
  e->state = 1;
  e->animSet = 0;
  e->enemyKind = enemyKind;
  e->unk_30 = 0;
  e->moverID = moverID;
  e->offsetX = offsetX;
  e->offsetY = offsetY;
  e->unk_32[0] = 1;
  e->unk_3c = 10;
  e->kind = 0;
  e->hasSprite = 1;
  e->pos = pos;
  e->enemy = enemy;
  x = y = 0;
  spr = &e->spr;
  switch (e->animSet) {
    case 0: {
      gfx = &mgr->gfx_18;
      break;
    }
    case 1:
    case 4:
    case 5: {
      gfx = &mgr->gfx_34;
      break;
    }
    default: {
      gfx = NULL;
      break;
    }
  }
  AuxSprite_Add(spr, gfx, 0);
  if (e->enemyKind == 0xFF) {
    e->unk_1c = e->mover->unk_30;
  } else {
    Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
    VEC3_SET(e->unk_1c, x, 0, y);
  }
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 1;
  e->anim[0].animIdx = 0xFF;
  switch (e->animSet) {
    case 0: {
      files = mgr->anim_50;
      break;
    }
    case 2:
    case 3: {
      files = mgr->anim_54;
      break;
    }
    case 1:
    case 4:
    case 5:
    default: {
      files = NULL;
      break;
    }
  }
  AuxAnim_SetAnim(&e->anim[0], files, e->animID, 0, 0);
  spr->pos = *pos;
  e->hasSprite = 1;
  return e;
#else
  INCFUNC("asm/func/FUN_080d9b3c.inc");
#endif
}

// 吹き出し付きのエモート (kind 1) を出す, timer が duration の何割残っているかで animID を 0..3 から選ぶ
// 残差は命令数 270/280, 原典はゲージのループ前に &e->mover / &e->anim[0].animIdx / &e->anim[0] も巻き上げてスタックに置くが, こちらは定数ロード+加算の2命令になるアドレスを巻き上げない
// Tier A-B は試済 (for/while/break なし, 昇順ループ, found の型と宣言順, spr ローカル有無), 未: 巻き上げ範囲を決める loop.c の条件の特定
NON_MATCH Emote* FUN_080d9cec(u8 animID, WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, u16* timer, s16 duration, u32 param_9, Enemy* enemy, Mover* mover) {
#ifdef NONMATCHING_C
  EmoteManager* mgr;
  Emote* e;
  s32 i;
  bool32 found;
  s32 x, y;
  AuxSpriteGfx* gfx;
  AuxAnimFile* files;
  AuxSprite* spr;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  e = EmoteManager_AllocSlot(mgr);
  if (e == NULL) {
    return NULL;
  }

  e->animID = animID;
  e->state = 1;
  e->offsetX = offsetX;
  e->enemyKind = enemyKind;
  e->offsetY = offsetY;
  e->unk_2a = offsetY;
  e->unk_3e[0] = Div(duration, 5);
  e->hasSprite = 1;
  e->mover = mover;
  e->timer = timer;

  found = FALSE;
  for (i = 4; i > 0; i--) {
    if (*(s16*)e->timer >= e->unk_3e[0] * i) {
      e->animID = 4 - i;
      found = TRUE;
      break;
    }
  }
  if (!found) {
    e->animID = 3;
  }

  e->moverID = moverID;
  e->kind = 1;
  e->animSet = 1;
  e->pos = pos;
  e->enemy = enemy;
  x = y = 0;
  spr = &e->spr;
  switch (e->animSet) {
    case 0: {
      gfx = &mgr->gfx_18;
      break;
    }
    case 1:
    case 4:
    case 5: {
      gfx = &mgr->gfx_34;
      break;
    }
    default: {
      gfx = NULL;
      break;
    }
  }
  AuxSprite_Add(spr, gfx, 0);
  if (e->enemyKind == 0xFF) {
    e->unk_1c = e->mover->unk_30;
  } else {
    Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
    VEC3_SET(e->unk_1c, x, 0, y);
  }
  SET_FLAGS(spr->flags, SPRFLAG_HIDDEN);
  spr->priority = 1;
  e->anim[0].animIdx = 0xFF;
  switch (e->animSet) {
    case 0: {
      files = mgr->anim_50;
      break;
    }
    case 2:
    case 3: {
      files = mgr->anim_54;
      break;
    }
    case 1:
    case 4:
    case 5:
    default: {
      files = NULL;
      break;
    }
  }
  AuxAnim_SetAnim(&e->anim[0], files, e->animID, 0, 0);
  spr->pos = *pos;
  e->hasSprite = 1;

  if (!(gGameFlags & FLAG030047A4_UNK_8) && param_9 == 1) {
    Vec3 v[3];

    Mod(Random(), 3);
    for (i = 0; i < 3; i++) {
      v[i].x = e->pos->x;
      v[i].y = e->pos->y + offsetY;
      v[i].z = e->pos->z;
    }
  }
  return e;
#else
  INCFUNC("asm/func/FUN_080d9cec.inc");
#endif
}

// パーティクル1個のエモート (kind 2) を出す
Emote* FUN_080d9f5c(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, Mover* mover) {
  EmoteManager* mgr;
  Particle* ptcls;
  Emote* e;
  s32 x, y;
  Particle* ptcl;
  ParticleGroup* g;
  AuxAnimFile* files;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  e = EmoteManager_AllocSlot(mgr);
  ptcls = e->ptcls;
  if (e == NULL) {
    return NULL;
  }

  e->animID = animID;
  e->enemyKind = enemyKind;
  e->state = 1;
  e->animSet = 2;
  e->unk_30 = 0;
  e->moverID = moverID;
  e->offsetX = 0;
  e->offsetY = offsetY;
  Emote_ClearPtclState(e);
  e->unk_3c = 0;
  e->unk_4[0].x = e->unk_4[0].y = e->unk_4[0].z = 0;
  e->kind = 2;
  e->enemy = NULL;
  e->mover = mover;
  x = y = 0;
  ptcl = ptcls;
  switch (e->animSet) {
    case 2: {
      g = mgr->group;
      break;
    }
    case 3: {
      g = mgr->group;
      break;
    }
    default: {
      g = NULL;
      break;
    }
  }
  Particle_Add(ptcl, g, 0);
  Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
  Particle_SetOffset(ptcl, x, y);
  if (e->enemyKind == 0xFF) {
    e->unk_1c = e->mover->unk_30;
  } else {
    Vec3_Clear(&e->unk_1c);
  }
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->offsetZ = 127;
  ptcl->priority = 1;
  e->anim[0].animIdx = 0xFF;
  switch (e->animSet) {
    case 0: {
      files = mgr->anim_50;
      break;
    }
    case 2:
    case 3: {
      files = mgr->anim_54;
      break;
    }
    case 1:
    case 4:
    case 5:
    default: {
      files = NULL;
      break;
    }
  }
  AuxAnim_SetAnim(&e->anim[0], files, e->animID, 0, 0);
  e->pos = pos;
  ptcls[0].pos = *pos;
  e->ptclMask = 1;
  e->hasSprite = 0;
  return e;
}

// パーティクルを count 個並べるエモート (kind 3) を出す, FUN_080da698 / FUN_080da6c4 の本体
// 残差3 hunk (263/263), 原典はループ内の ptcl を e + (i * 40 + 0x88) で作るが, こちらは ptcls + i * 40 になり case ブロックの一時レジスタがずれる, &e->ptcls[i] にするとループ前に写し直すアドレス5本のスタック位置の順が崩れる
// Tier A-C は試済 (Vec3_Clear で CpuSet の順は解決, SET_BIT, if 連鎖, ptcl の作り方), 未: e 基点のまま写し直しの順を保つ形
NON_MATCH Emote* FUN_080da110(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, u16* timer, s32 duration, s32 count, Mover* mover, Enemy* enemy) {
#ifdef NONMATCHING_C
  EmoteManager* mgr;
  Particle* ptcls;
  s32 interval;
  Emote* e;
  s32 i;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  interval = Div(duration, 3);
  e = EmoteManager_AllocSlot(mgr);
  ptcls = e->ptcls;
  if (e == NULL) {
    return NULL;
  }

  e->animID = animID;
  e->enemyKind = enemyKind;
  e->timer = timer;
  e->state = 1;
  e->animSet = 3;
  e->unk_30 = 0;
  e->moverID = moverID;
  e->offsetX = 0;
  e->offsetY = offsetY;
  Emote_ClearPtclState(e);
  e->unk_3c = 0;
  e->unk_4[0].x = e->unk_4[0].y = e->unk_4[0].z = 0;
  e->kind = 3;
  e->pos = pos;
  e->ptclMask = 0;
  e->hasSprite = 0;
  e->enemy = enemy;
  e->mover = mover;

  for (i = 0; i < count; i++) {
    s32 x, y;
    Particle* ptcl;
    ParticleGroup* g;
    AuxAnimFile* files;

    e->unk_4c[i] = i * 17;
    e->unk_35[i] = 0;
    e->unk_3e[i] = interval * i;
    x = y = 0;
    ptcl = &ptcls[i];
    switch (e->animSet) {
      case 2: {
        g = mgr->group;
        break;
      }
      case 3: {
        g = mgr->group;
        break;
      }
      default: {
        g = NULL;
        break;
      }
    }
    Particle_Add(ptcl, g, 0);
    Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
    Particle_SetOffset(ptcl, x, y);
    if (e->enemyKind == 0xFF) {
      e->unk_1c = e->mover->unk_30;
    } else {
      Vec3_Clear(&e->unk_1c);
    }
    ptcl->flags |= SPRFLAG_HIDDEN;
    ptcl->offsetZ = 127;
    ptcl->priority = 1;
    e->anim[i].animIdx = 0xFF;
    switch (e->animSet) {
      case 0: {
        files = mgr->anim_50;
        break;
      }
      case 2:
      case 3: {
        files = mgr->anim_54;
        break;
      }
      case 1:
      case 4:
      case 5:
      default: {
        files = NULL;
        break;
      }
    }
    AuxAnim_SetAnim(&e->anim[i], files, e->animID, 0, 0);
    ptcls[i].pos = *pos;
    e->ptclMask |= 1 << i;
  }
  return e;
#else
  INCFUNC("asm/func/FUN_080da110.inc");
#endif
}

// 吹き出し (kind 4) のエモートを出す
// 残差はレジスタ割当 (185/185), 原典は gfx の switch の直前で &e->animID / &e->hasSprite / &e->kind / &e->animSet / spr を別の擬似レジスタへ写し直し, spr をスタックに置く (FUN_080d9cec の巻き上げと同じ形)
// Tier A-C は試済 (spr ローカルの位置, AuxSprite_Hide, x/y のスコープ, 1回だけのループ, do-while(0), 後半の inline 化), 未: 写し直しを生むパスの特定 (loop.c 由来に見える)
NON_MATCH Emote* FUN_080da358(WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, Enemy* enemy, Mover* mover) {
#ifdef NONMATCHING_C
  EmoteManager* mgr;
  Emote* e;
  s32 x, y;
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  AuxAnimFile* files;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  e = EmoteManager_AllocSlot(mgr);
  if (e == NULL) {
    return NULL;
  }

  e->animID = 5;
  e->state = 1;
  e->offsetX = offsetX;
  e->enemyKind = enemyKind;
  e->offsetY = offsetY;
  e->unk_2a = offsetY;
  e->hasSprite = 1;
  e->unk_30 = 0;
  e->moverID = moverID;
  e->kind = 4;
  e->animSet = 4;
  e->pos = pos;
  e->enemy = enemy;
  e->mover = mover;
  x = y = 0;
  spr = &e->spr;
  switch (e->animSet) {
    case 0: {
      gfx = &mgr->gfx_18;
      break;
    }
    case 1:
    case 4:
    case 5: {
      gfx = &mgr->gfx_34;
      break;
    }
    default: {
      gfx = NULL;
      break;
    }
  }
  AuxSprite_Add(spr, gfx, 0);
  if (e->enemyKind == 0xFF) {
    e->unk_1c = e->mover->unk_30;
  } else {
    Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
    VEC3_SET(e->unk_1c, x, 0, y);
  }
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 1;
  e->anim[0].animIdx = 0xFF;
  switch (e->animSet) {
    case 0: {
      files = mgr->anim_50;
      break;
    }
    case 2:
    case 3: {
      files = mgr->anim_54;
      break;
    }
    case 1:
    case 4:
    case 5:
    default: {
      files = NULL;
      break;
    }
  }
  AuxAnim_SetAnim(&e->anim[0], files, e->animID, 0, 0);
  spr->pos = *pos;
  e->hasSprite = 1;
  return e;
#else
  INCFUNC("asm/func/FUN_080da358.inc");
#endif
}

// kind 5 のエモートを出す, FUN_080da358 とは animID / kind / animSet の値だけが違う
// 残差は FUN_080da358 と同じレジスタ割当 (185/185), 原典は gfx の switch の直前でアドレスを別の擬似レジスタへ写し直す
// Tier A-C は FUN_080da358 側で試済, 未: 写し直しを生むパスの特定
NON_MATCH Emote* FUN_080da4f8(WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, Enemy* enemy, Mover* mover) {
#ifdef NONMATCHING_C
  EmoteManager* mgr;
  Emote* e;
  s32 x, y;
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  AuxAnimFile* files;

  if (gEmoteManager == NULL) {
    mgr = EmoteManager_Create();
    if (mgr == NULL) {
      return NULL;
    }
  } else {
    mgr = gEmoteManager;
  }

  if (mover == NULL) {
    return NULL;
  }

  e = EmoteManager_AllocSlot(mgr);
  if (e == NULL) {
    return NULL;
  }

  e->animID = 6;
  e->state = 1;
  e->offsetX = offsetX;
  e->enemyKind = enemyKind;
  e->offsetY = offsetY;
  e->unk_2a = offsetY;
  e->hasSprite = 1;
  e->unk_30 = 0;
  e->moverID = moverID;
  e->kind = 5;
  e->animSet = 5;
  e->pos = pos;
  e->enemy = enemy;
  e->mover = mover;
  x = y = 0;
  spr = &e->spr;
  switch (e->animSet) {
    case 0: {
      gfx = &mgr->gfx_18;
      break;
    }
    case 1:
    case 4:
    case 5: {
      gfx = &mgr->gfx_34;
      break;
    }
    default: {
      gfx = NULL;
      break;
    }
  }
  AuxSprite_Add(spr, gfx, 0);
  if (e->enemyKind == 0xFF) {
    e->unk_1c = e->mover->unk_30;
  } else {
    Emote_CalcPtclOffset(e->kind, e->enemyKind, e->mover->angle, &x, &y, e->enemy);
    VEC3_SET(e->unk_1c, x, 0, y);
  }
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 1;
  e->anim[0].animIdx = 0xFF;
  switch (e->animSet) {
    case 0: {
      files = mgr->anim_50;
      break;
    }
    case 2:
    case 3: {
      files = mgr->anim_54;
      break;
    }
    case 1:
    case 4:
    case 5:
    default: {
      files = NULL;
      break;
    }
  }
  AuxAnim_SetAnim(&e->anim[0], files, e->animID, 0, 0);
  spr->pos = *pos;
  e->hasSprite = 1;
  return e;
#else
  INCFUNC("asm/func/FUN_080da4f8.inc");
#endif
}

Emote* FUN_080da698(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, u16* timer, s32 duration, Mover* mover, Enemy* enemy) { return FUN_080da110(animID, pos, moverID, offsetY, enemyKind, timer, duration, 3, mover, enemy); }

Emote* FUN_080da6c4(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, u16* timer, s32 duration, s32 count, Mover* mover, Enemy* enemy) { return FUN_080da110(animID, pos, moverID, offsetY, enemyKind, timer, duration, count, mover, enemy); }

void (*const sEmoteStateUpdates[3])(Emote*) = {
    nop_080d8ddc,
    Emote_Update,
    NULL,
};  // 0x085AD304

// 全スロットのエモートを state ごとの処理で更新する
s32 EmoteManager_Update(EmoteManager* p) {
  Emote* e = p->slots;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 8; i++) {
      sEmoteStateUpdates[e[i].state](&e[i]);
    }
  }
  return 0;
}

// 残差は定数 1 とマスクのアドレスのどちらをループ外へ出すか (66/66), 原典はマスクのアドレスを sb に出して 1 は毎回作るが, こちらは 1 を r9 に出してアドレスを毎回作る
// Tier A-B は試済 (EmoteManager_IsSlotUsed, 内側の bool8 inline, 片付けの inline, 1 << j と >> j & 1), 未: ループ外へ出す順を決める loop.c の条件の特定
NON_MATCH s32 EmoteManager_Destroy(EmoteManager* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (EmoteManager_IsSlotUsed(p, i)) {
      Emote* e = &p->slots[i];
      s32 j;

      for (j = 0; j < 3; j++) {
        if (e->ptclMask & (1 << j)) {
          Particle_Remove(&e->ptcls[j]);
        }
      }
      if (e->hasSprite) {
        AuxSprite_Remove(&e->spr);
      }
    }
  }
  gEmoteManager = NULL;
  return 0;
#else
  INCFUNC("asm/func/EmoteManager_Destroy.inc");
#endif
}

// スプライト2種とアニメ2本、粒子グループを読み込む
void EmoteManager_LoadResources(EmoteManager* p) {
  Video_GetAuxSprite(&p->gfx_18, SPRITE_EMOTION_ICONS_0);
  Video_GetAuxSprite(&p->gfx_34, SPRITE_EMOTION_ICONS_1);
  p->group = GetParticleGroup(PTCL_GROUP_1);
  p->anim_50 = GetFile(DIR_ANIMATION, ANIM_6830);
  p->anim_54 = GetFile(DIR_ANIMATION, ANIM_D41F);
}

s32 EmoteManager_Init(EmoteManager* p) {
  p->activeMask = 0;
  EmoteManager_LoadResources(p);
  gEmoteManager = p;
  return 0;
}

EmoteManager* EmoteManager_Create(void) {
  if (gEmoteManager == NULL) {
    EmoteManager* p = CreateEntity(ENTITY_UNK_9, sizeof(EmoteManager));
    if (p != NULL) {
      SetEntityRoutine(p, EmoteManager_Update, EmoteManager_Destroy);
      if (EmoteManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEmoteManager;
}

void EmoteManager_Clear(void) { gEmoteManager = NULL; }

bool8 Emote_IsInactive(Emote* elem) {
  if (gEmoteManager == NULL) {
    return TRUE;
  }
  if (elem == NULL) {
    return TRUE;
  }
  if (elem->state == 0) {
    return TRUE;
  }
  return FALSE;
}

// gEmoteManager の activeMask が立っているスロットを走査する, リポジトリ中からも asm からも呼ばれていない
// 使用中のスロットのエモートをすべて片付ける, 呼び出し元は見つかっていない
void EmoteManager_RemoveAll(void) {
  if (gEmoteManager != NULL) {
    EmoteManager* mgr = gEmoteManager;

    if (mgr->activeMask != 0) {
      s32 i;

      for (i = 0; i < 8; i++) {
        if (EmoteManager_IsSlotUsed(mgr, i)) {
          Emote* e = &mgr->slots[i];

          Emote_Free(mgr, e);
        }
      }
    }
  }
}

/**
 * @brief mover の既存エモートを消してから kind のエモートを出す, variant が 0x7F なら kind のエモートを消すだけ
 * @param kind エモートの種類 (see EmoteKind)
 * @param variant 0x7F なら kind のエモートを消す, それ以外は kind のサブ種類
 */
Emote* Emote_Show(Emote* emote, Mover* mover, u8 kind, u8 variant, u16* timer, s16 duration, s32 offsetY, s32 offsetX) {
  u32 flag;

  if (mover == NULL) {
    return NULL;
  }

  if (variant == 0x7F) {
    // kind のエモートを消すだけ
    if (emote == NULL) {
      return NULL;
    }
    switch (kind) {
      case EMOTE_0: {
        return Emote_Remove(emote, EMOTE_0, mover->id);
      }
      case EMOTE_1: {
        return Emote_Remove(emote, EMOTE_1, mover->id);
      }
      case EMOTE_3: {
        return Emote_RemovePtcl(emote, EMOTE_3, mover->id);
      }
      case EMOTE_2: {
        return Emote_Remove(emote, EMOTE_2, mover->id);
      }
      case EMOTE_4: {
        return Emote_Remove(emote, EMOTE_4, mover->id);
      }
      case EMOTE_5: {
        return Emote_Remove(emote, EMOTE_5, mover->id);
      }
    }
  } else {
    // 既存のエモートを消して、 kind のエモートを出す
    emote = Emote_Remove(emote, EMOTE_0, mover->id);
    emote = Emote_Remove(emote, EMOTE_1, mover->id);
    emote = Emote_Remove(emote, EMOTE_2, mover->id);
    emote = Emote_Remove(emote, EMOTE_4, mover->id);
    emote = Emote_Remove(emote, EMOTE_5, mover->id);
    Emote_RemovePtcl(emote, EMOTE_3, mover->id);
    if (TEST_FLAGS(mover->flags, MOVER_FLAG_2)) {
      flag = 0xFF;
    } else {
      flag = 0;
    }
    switch (kind) {
      case EMOTE_0: {
        return FUN_080d9b3c(variant, &mover->pos, mover->id, offsetX, offsetY, flag, NULL, mover);
      }
      case EMOTE_1: {
        return FUN_080d9cec(variant, &mover->pos, mover->id, offsetX, offsetY, flag, timer, duration, 0, NULL, mover);
      }
      case EMOTE_2: {
        return FUN_080d9f5c(1, &mover->pos, mover->id, offsetY, flag, mover);
      }
      case EMOTE_3: {
        return FUN_080da698(7, &mover->pos, mover->id, offsetY, flag, timer, duration, mover, NULL);
      }
      case EMOTE_4: {
        return FUN_080da358(&mover->pos, mover->id, offsetX, offsetY, flag, NULL, mover);
      }
      case EMOTE_5: {
        return FUN_080da4f8(&mover->pos, mover->id, offsetX, offsetY, flag, NULL, mover);
      }
    }
  }
}
