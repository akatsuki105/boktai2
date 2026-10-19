#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "map_pltt.h"
#include "time.h"
#include "video.h"
#include "vm.h"

extern s32 gBgBrightnessApplied;

COMMON_DATA u16 gMapInitScriptID = 0;        // 0x03002B28, 魔物図鑑や太陽鍛治にも専用のIDがある(スタートメニューはない)ので、SceneIDとかの方が意味は近いかも？
COMMON_DATA Entity4AE5* gEntity4AE5 = NULL;  // 0x03002B2C

void FUN_08001878(void) { gEntity4AE5 = NULL; }

// src1 と src2 を (0x20-scale):scale の比で [start, end) の範囲だけ混ぜて dst に書く, scale は level/2, 0x20 以上なら src2 をそのままコピーする
NON_MATCH void BlendPltt2(rgb555* dst, const rgb555* src1, const rgb555* src2, u32 level, u32 start, u32 end) {
#ifdef NONMATCHING_C
  const rgb555* s1;
  const rgb555* s2;
  rgb555* d;
  u32 scale;
  u32 inv;
  s32 count;
  u32 rb;
  u32 g;

  scale = level >> 1;
  inv = 0x20 - scale;
  count = end - start;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src2 + start, dst + start, count * 2);
    } else {
      s1 = src1 + start;
      s2 = src2 + start;
      d = dst + start;
      while (count > 0) {
        rb = ((*s2 & 0x7C1F) * scale + (*s1 & 0x7C1F) * inv) & 0xF83E0;
        g = ((*s2 & 0x3E0) * scale + (*s1 & 0x3E0) * inv) & 0x7C00;
        *d = (rb | g) >> 5;
        s1++;
        s2++;
        d++;
        count--;
      }
    }
  }
#else
  INCFUNC("asm/func/BlendPltt2.inc");
#endif
}

// src を level/2 倍(5bit精度)して dst に書く, 等倍以上ならそのままコピーする
NON_MATCH void ScalePltt(rgb555* dst, rgb555* src, u32 level, u32 start, u32 end) {
#ifdef NONMATCHING_C
  const rgb555* s;
  rgb555* d;
  u32 scale;
  s32 count;
  u32 rb;
  u32 g;

  scale = level >> 1;
  count = end - start;
  if (count != 0) {
    if (scale > 0x1F) {
      CpuCopy32(src + start, dst + start, count * 2);
    } else {
      s = src + start;
      d = dst + start;
      while (count != 0) {
        rb = (*s & 0x7C1F) * scale & 0xF83E0;
        g = (*s & 0x3E0) * scale & 0x7C00;
        *d = (rb | g) >> 5;
        s++;
        d++;
        count--;
      }
    }
  }
#else
  INCFUNC("asm/func/ScalePltt.inc");
#endif
}

void MapPltt_BuildWeather(Entity4AE5* p) {
  FileID id = p->bgpIDs[2];
  rgb555* src = GetBgPlttFile(p->bgpIDs[2])->body;
  ScalePltt(p->plttWeather, src, 50, 0, 208);
}

void MapPltt_Fill(Entity4AE5* p, u32 rgb555val) {
  s32 i;

  rgb555* dst = p->dstPltt;
  for (i = 0; i < 208; i++) {
    *dst = rgb555val;
    dst++;
  }
  p->unk_20 = 1;
}

void MapPltt_Commit(Entity4AE5* p) {
  const rgb555* src = (p->flags & MAPPLTT_TIMEOFDAY) ? p->curPltt : p->srcPltt1;
  CpuCopy32(src, p->dstPltt, 208 * sizeof(rgb555));
  p->unk_20 = 1;
}

// 朝と日中は 0x20、それ以外は 0x40 を返す
s32 MapPltt_GetTargetLevel(void* _) {
  if (gClock.spanOfTime == TIME_MORNING || gClock.spanOfTime == TIME_DAYTIME) {
    return 0x20;
  }
  return 0x40;
}

void MapPltt_LevelReset(Entity4AE5* p) { p->weatherLevel = 0; }

void MapPltt_LevelIncrease(Entity4AE5* p) {
  if (p->weatherLevel < MapPltt_GetTargetLevel(p)) {
    p->weatherLevel += 4;
  } else {
    p->weatherLevel = MapPltt_GetTargetLevel(p);
    p->weatherState = 2;
  }
}

// 目標値へ1回あたり最大8ずつ近づける
void MapPltt_LevelApproach(Entity4AE5* p) {
  s32 target = MapPltt_GetTargetLevel(p);
  u8 cur = p->weatherLevel;
  s32 diff = abs(cur - target);
  if (cur < MapPltt_GetTargetLevel(p)) {
    s32 step = diff;
    if (step > 8) {
      step = 8;
    }
    p->weatherLevel += step;
  } else {
    cur = p->weatherLevel;
    if (cur > MapPltt_GetTargetLevel(p)) {
      s32 step = diff;
      if (step > 8) {
        step = 8;
      }
      p->weatherLevel -= step;
    } else {
      p->weatherLevel = MapPltt_GetTargetLevel(p);
    }
  }
}

void MapPltt_LevelDecrease(Entity4AE5* p) {
  if (p->weatherLevel > 1) {
    p->weatherLevel -= 2;
  } else {
    p->weatherLevel = 0;
    p->weatherState = 0;
  }
}

void MapPltt_Rebuild(Entity4AE5* p) {
  rgb555* dst = p->plttTimeBlend;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->timeBlendLevel, 0, 208);
  CpuCopy32(dst, p->dstPltt, 208 * sizeof(rgb555));
  MapPltt_BuildWeather(p);
  BlendPltt2(p->plttWeatherBlend, dst, p->plttWeather, p->weatherLevel, 0, 208);
  p->curPltt = dst;
  p->unk_20 = 1;
}

void MapPltt_StepBlend(Entity4AE5* p) {
  u32 zero;
  u32 count;

  rgb555* dst = p->plttTimeBlend;
  p->curPltt = dst;
  zero = 0;
  count = 208;
  BlendPltt2(dst, p->srcPltt1, p->srcPltt2, p->timeBlendLevel, zero, count);
  if (++p->timeBlendLevel >= 0x40) {
    p->timeBlendLevel = 0x40;
  }
}

static void (*const sMapPlttWeatherSteps[4])(Entity4AE5*) = {
    MapPltt_LevelReset,
    MapPltt_LevelIncrease,
    MapPltt_LevelApproach,
    MapPltt_LevelDecrease,
};  // 0x085aa624

bool32 WeatherManager_IsActive(void);

NON_MATCH void FUN_08001c10(Entity4AE5* p) {
#ifdef NONMATCHING_C
  u16* flag;
  u32 zero;
  u32 count;

  if (WeatherManager_IsActive()) {
    flag = &p->unk_64a;
    if (*flag == 0) {
      sMapPlttWeatherSteps[p->weatherState](p);
    }
    if (p->weatherLevel != p->prevWeatherLevel || p->timeBlendLevel <= 0x3F) {
      zero = 0;
      count = 0xD0;
      BlendPltt2(p->plttWeatherBlend, p->plttTimeBlend, p->plttWeather, p->weatherLevel, zero, count);
      *flag = 0;
    }
    if (p->weatherLevel != 0) {
      p->curPltt = p->plttWeatherBlend;
    }
    p->prevWeatherLevel = p->weatherLevel;
  }
#else
  INCFUNC("asm/func/FUN_08001c10.inc");
#endif
}

// oscRowMask で指定されたパレット行だけを、混合比に応じて転送または合成する
NON_MATCH void MapPltt_BlendRows(Entity4AE5* p) {
#ifdef NONMATCHING_C
  const rgb555* s1;
  const rgb555* s2;
  rgb555* d;
  s32 scale;
  s32 inv;
  s32 i;
  s32 end;
  s32 j;
  u32 rb;
  u32 g;

  scale = (s16)p->oscLevel >> 1;
  end = p->oscRow + p->oscRowStep;
  if (end > 0xC) {
    p->oscActive = 0;
    end = 0xD;
  }
  if (scale > 0x1F) {
    for (i = p->oscRow; i < end; i++) {
      if ((p->oscRowMask >> i) & 1) {
        CpuCopy32(p->srcPltt2 + i * 16, p->dstPltt + i * 16, 32);
      }
    }
  } else {
    inv = 0x20 - scale;
    for (i = p->oscRow; i < end; i++) {
      if ((p->oscRowMask >> i) & 1) {
        d = p->dstPltt + i * 16;
        s1 = p->srcPltt1 + i * 16;
        s2 = p->srcPltt2 + i * 16;
        for (j = 0; j < 16; j++) {
          rb = ((*s2 & 0x7C1F) * scale + (*s1 & 0x7C1F) * inv) & 0xF83E0;
          g = ((*s2 & 0x3E0) * scale + (*s1 & 0x3E0) * inv) & 0x7C00;
          *d = (rb | g) >> 5;
          s1++;
          s2++;
          d++;
        }
      }
    }
  }
  p->oscRow = end;
  p->unk_20 = 1;
#else
  INCFUNC("asm/func/MapPltt_BlendRows.inc");
#endif
}

// パレットを 13 段階ずつ送りながら合成する, 1周したら送り元を切り替えて終了する
void MapPltt_StepCrossfade(Entity4AE5* p) {
  const rgb555* src;
  u32 step;
  u32 rest;

  step = p->crossfadeRow << 4;
  if (p->flags & MAPPLTT_TIMEOFDAY) {
    src = p->curPltt + (p->crossfadeRow << 4);
  } else {
    src = p->srcPltt1 + (p->crossfadeRow << 4);
  }
  if (p->crossfadeRow + p->crossfadeRowStep <= 0xD) {
    rest = p->crossfadeRowStep << 4;
  } else {
    rest = (0xD - p->crossfadeRow) << 4;
  }
  BlendPltt2(p->dstPltt, src, p->srcPltt2, (s8)p->crossfadeLevel, step, rest);
  p->crossfadeRow += p->crossfadeRowStep;
  if (p->crossfadeRow > 0xC) {
    p->crossfadeRow = 0;
    p->crossfadeLevel += p->crossfadeLevelStep;
    if ((s8)p->crossfadeLevel > 0x40) {
      p->crossfadeLevel = 0;
      p->srcPltt1 = p->srcPltt2;
      p->state = 0;
    }
  }
  p->unk_20 = 1;
}

// 暗→明のフェード: 進捗に応じて明るさを 0 に近づけ、終わったら次の処理へ移る
void MapPltt_FadeIn(Entity4AE5* p) {
  gBgBrightness = 0x40 - ((p->fadeTimer << 6) >> p->fadeShift);
  if ((p->fadeTimer = p->fadeTimer + 1) >= (1 << p->fadeShift)) {
    gBgBrightness = 0;
    if (p->state == 3) {
      p->state = 0;
    } else {
      p->state = 6;
    }
  }
}

// 明→暗のフェード: 進捗に応じて明るさを 0x40 に近づけ、終わったら暗転状態で止める
void MapPltt_FadeOut(Entity4AE5* p) {
  rgb555* pltt;

  gBgBrightness = (p->fadeTimer << 6) >> p->fadeShift;
  if ((p->fadeTimer = p->fadeTimer + 1) >= (1 << p->fadeShift)) {
    pltt = GetBgPlttBlendBuffer();
    gBgBrightness = 0x40;
    gBgPlttBlendColor = RGB(4, 4, 4);
    *pltt = RGB(4, 4, 4);
    p->state = 0;
  }
}

s32 FUN_0823ce10(u16* a, u16* b);

// スクリプトから指定されたPLTTファイルを登録し、時間帯に応じた2枚を読み直す
NON_MATCH void MapPltt_SetFile(s32 idx, FileID plttFileID, u32 kw_f) {
#ifdef NONMATCHING_C
  Entity4AE5* p = gEntity4AE5;
  if (p != NULL) {
    p->bgpIDs[idx] = plttFileID;
    if (kw_f & 1) {
      if (p->flags & MAPPLTT_TIMEOFDAY) {
        u16 id0, id1;
        FUN_0823ce10(&id0, &id1);
        p->srcPltt1 = GetBgPlttFile(p->bgpIDs[id0])->body;
        p->srcPltt2 = GetBgPlttFile(p->bgpIDs[id1])->body;
        if (id0 == 2 || id1 == 2) {
          MapPltt_BuildWeather(p);
        }
        MapPltt_Rebuild(p);
        p->crossfadeRow = 0;
        p->crossfadeLevel = 64;
      } else {
        p->srcPltt1 = GetBgPlttFile(p->bgpIDs[idx])->body;
        CpuCopy32(p->srcPltt1, p->dstPltt, 416);
        p->crossfadeRow = 0;
        p->crossfadeLevel = 0;
      }
      p->crossfadeLevelStep = 7;
      p->crossfadeRowStep = 4;
    }
    p->unk_20 = 1;
  }
#else
  INCFUNC("asm/func/MapPltt_SetFile.inc");
#endif
}

void Cmd_CA7D(void) {
  if (gEntity4AE5 != NULL) {
    s32 kw_i = VM_GetNamedArgValue('i', 0);
    FileID plttFileID = VM_GetNamedArgValue('n', 0);
    u32 kw_f = VM_GetNamedArgValue('f', 0);
    MapPltt_SetFile(kw_i, plttFileID, kw_f);
  }
}

NON_MATCH void MapPltt_PushCommand(s32 val, s32 count, u32* args) {
#ifdef NONMATCHING_C
  Entity4AE5* p;
  s32 i;
  u16* dst;

  p = gEntity4AE5;
  if (p != NULL) {
    if ((u32)p->cmdCount <= 7) {
      p->cmds[p->cmdCount] = val;
      dst = p->cmdArgs[p->cmdCount];
      for (i = 0; i < count; i++) {
        dst[i] = *args++;
      }
      p->cmdCount++;
    }
  }
#else
  INCFUNC("asm/func/MapPltt_PushCommand.inc");
#endif
}

void FUN_080020bc(void) {
  u32 args[8];

  s32 kw_r = VM_GetNamedArgValue('r', 0);
  s32 count = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL && count < 8) {
      args[count] = VM_GetValue();
      count++;
    }
  }
  MapPltt_PushCommand(kw_r, count, args);
}

static void (*const sMapPlttStates[7])(Entity4AE5*) = {
    NULL,
    MapPltt_StepCrossfade,
    MapPltt_FadeOut,
    MapPltt_FadeIn,
    MapPltt_FadeOut,
    MapPltt_FadeIn,
    NULL,
};  // 0x085aa634

// cmds に積まれたコマンドを順に処理し、時間帯の変化やフェードの進行を反映する
NON_MATCH s32 Entity4AE5_Update(Entity4AE5* p) {
#ifdef NONMATCHING_C
  void (*fn)(Entity4AE5*);
  u16* args;
  u16 cmd;
  s32 i;
  u16 id0;
  u16 id1;

  p->unk_20 = 0;
  for (i = 0; i < p->cmdCount; i++) {
    cmd = p->cmds[i];
    args = p->cmdArgs[i];
    p->cmds[i] = 0;
    if (p->state > 3) {
      if (cmd == 4 || cmd == 5) {
        p->state = cmd;
        p->fadeTimer = 0;
        p->fadeShift = args[0];
        gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
        gBgPlttFadeRowMask = args[4];
      }
    } else {
      switch (cmd) {
        case 1: {
          p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[(s16)args[0]])->body;
          p->state = 1;
          p->crossfadeRow = 0;
          p->crossfadeLevel = args[1];
          p->crossfadeLevelStep = args[2];
          p->crossfadeRowStep = args[3];
          break;
        }
        case 2:
        case 4: {
          if (cmd == 2) {
            p->state = 2;
          } else {
            p->state = 4;
          }
          p->fadeTimer = 0;
          p->fadeShift = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 3:
        case 5: {
          if (cmd == 3) {
            p->state = 3;
          } else {
            p->state = 5;
          }
          p->fadeTimer = 0;
          p->fadeShift = args[0];
          gBgPlttBlendColor = (args[3] << 10) | (args[2] << 5) | args[1];
          gBgPlttFadeRowMask = args[4];
          break;
        }
        case 6: {
          MapPltt_Fill(p, (s16)args[0] | ((s16)args[1] << 5) | ((s16)args[2] << 10));
          break;
        }
      }
    }
  }
  p->cmdCount = 0;
  if (p->flags & MAPPLTT_TIMEOFDAY) {
    if (p->spanOfTime != gClock.spanOfTime) {
      FUN_0823ce10(&id0, &id1);
      p->timeBlendLevel = 0;
      p->unk_648 = 0;
      p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
      p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    }
    p->spanOfTime = gClock.spanOfTime;
    p->unk_64e = gClock.unk_0f;
    p->curPltt = p->plttTimeBlend;
    if (p->timeBlendLevel <= 0x3F) {
      MapPltt_StepBlend(p);
    }
    FUN_08001c10(p);
    MapPltt_Commit(p);
    p->prevTimeBlendLevel = p->timeBlendLevel;
  } else if (p->flags & MAPPLTT_OSCILLATE) {
    if (p->oscWait == 0) {
      if (++p->oscTimer >= p->oscPeriod) {
        p->oscTimer = 0;
        p->oscLevel += p->oscStep;
        if ((s16)p->oscLevel <= 0) {
          p->oscLevel = 0;
          p->oscStep = -p->oscStep;
          p->oscWait = p->oscStep;
        } else if ((s16)p->oscLevel > 0x3F) {
          p->oscLevel = 0x40;
          p->oscStep = -p->oscStep;
          p->oscWait = p->oscWaitLength;
        }
        p->oscActive = 1;
        p->oscRow = 0;
      }
    } else {
      p->oscWait--;
    }
    if (p->oscActive != 0) {
      MapPltt_BlendRows(p);
    }
  }
  fn = sMapPlttStates[p->state];
  if (fn != NULL) {
    fn(p);
  }
#else
  INCFUNC("asm/func/Entity4AE5_Update.inc");
#endif
}

s32 Entity4AE5_Destroy(Entity4AE5* p) { gEntity4AE5 = NULL; }

// パレット処理の初期化, flags のビットで、時間帯連動・往復混合・単純転送のどれかを選ぶ
NON_MATCH s32 Entity4AE5_Init(Entity4AE5* p, u16 id) {
#ifdef NONMATCHING_C
  const rgb555* src;
  u16 id0;
  u16 id1;
  s32 i;

  gEntity4AE5 = p;
  p->id = id;
  p->dstPltt = gBgPlttBuffer;
  gBgBrightness = 0x40;
  gBgBrightnessApplied = 0x40;
  gBgPlttBlendColor = RGB(4, 4, 4);
  gBgPlttFadeRowMask = 0;
  p->flags = VM_GetNamedArgValue('f', 0);
  p->crossfadeRow = 0;
  p->unk_648 = 0;
  p->state = 0;
  p->crossfadeLevelStep = 7;
  p->crossfadeRowStep = 4;
  i = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL && i <= 3) {
      p->bgpIDs[i] = VM_GetValue();
      i++;
    }
  }
  p->fadeTimer = 0;
  p->fadeShift = 0;
  p->crossfadeLevel = 0;
  p->unk_64e = 0;
  p->timeBlendLevel = 0;
  if (p->flags & MAPPLTT_TIMEOFDAY) {
    FUN_0823ce10(&id0, &id1);
    p->timeBlendLevel = 0x40;
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    MapPltt_Rebuild(p);
    p->unk_64e = gClock.unk_0f;
    p->spanOfTime = gClock.spanOfTime;
    src = p->plttWeatherBlend;
  } else if (p->flags & MAPPLTT_OSCILLATE) {
    id0 = VM_GetNamedArgValue('c', 0);
    id1 = VM_GetNamedArgValue('m', 0);
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    if (VM_SeekToNamedArg('a')) {
      p->unk_652 = VM_GetValue();
      p->oscPeriod = VM_GetValue();
      p->oscRowStep = VM_GetValue();
      p->oscRowMask = VM_GetValue();
      p->oscStep = VM_GetValue();
      p->oscWaitLength = VM_GetValue();
    } else {
      p->unk_652 = 4;
      p->oscPeriod = 2;
      p->oscRowStep = 8;
      p->oscRowMask = 0xFFFF;
      p->oscStep = 0x20;
      p->oscWaitLength = 0;
    }
    p->oscTimer = 0;
    p->oscLevel = 0;
    p->oscRow = 0;
    p->oscActive = 0;
    src = p->srcPltt1;
  } else {
    id0 = VM_GetNamedArgValue('c', 0);
    id1 = VM_GetNamedArgValue('m', 0);
    p->srcPltt1 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id0])->body;
    p->srcPltt2 = (const rgb555*)GetBgPlttFile(p->bgpIDs[id1])->body;
    src = p->srcPltt1;
  }
  CpuCopy32(src, p->dstPltt, 208 * sizeof(rgb555));
  p->weatherState = 0;
  p->unk_20 = 1;
  return 0;
#else
  INCFUNC("asm/func/Entity4AE5_Init.inc");
#endif
}

Entity4AE5* Entity4AE5_Create(u32 id) {
  if (gEntity4AE5 == NULL) {
    Entity4AE5* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity4AE5));
    if (p != NULL) {
      SetEntityRoutine(p, Entity4AE5_Update, Entity4AE5_Destroy);
      if (Entity4AE5_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity4AE5;
}
