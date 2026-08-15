#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"

#define ACTOR_SPRITE_COUNT 253
#define ACTOR_SPRITES_TILECOUNT 42418
#define ACTOR_SPRITE_SPRITE_COUNT 3246

typedef struct {
  u8 shape;   // 0x00
  u8 unk_01;  // 0x01
  s8 x;       // 0x02
  s8 y;       // 0x03
} ActorObject;
static_assert(sizeof(ActorObject) == 4);

typedef struct {
  u16 id;             // 0x00
  u16 unk_02;         // 0x02
  u8 w;               // 0x04
  u8 h;               // 0x05
  s8 x;               // 0x06
  s8 y;               // 0x07
  u32 spritesOffset;  // 0x08
} ActorSpritesActor;
static_assert(sizeof(ActorSpritesActor) == 12);

typedef struct {
  u8 objectCount;    // 0x00
  u8 unk_01;         // 0x01
  u16 plttID;        // 0x02
  u16 tileOffset;    // 0x04
  u16 objectOffset;  // 0x06
} ActorSprite;
static_assert(sizeof(ActorSprite) == 8);

typedef struct {
  u32 unk_00;                                      // 0x00
  u32 actorCount;                                  // 0x04, ACTOR_SPRITE_COUNT
  u32 unk_08;                                      // 0x08
  u32 offsetToTiles;                               // 0x0C
  u32 offsetToSprites;                             // 0x10
  u32 offsetToObjects;                             // 0x14
  ActorSpritesActor actors[ACTOR_SPRITE_COUNT];    // 0x18
  u8 tiles[ACTOR_SPRITES_TILECOUNT * 32];          // 0xBF4, GBA tiles
  ActorSprite sprites[ACTOR_SPRITE_SPRITE_COUNT];  // 0x14C234
  ActorObject objects[4641];                       // 0x1527A4
} ActorSpritesFile;
static_assert(sizeof(ActorSpritesFile) == 1404968);

extern const ActorSpritesFile gActorSpritesFile0;  // 0x08A2291C

// --------------------------------------------

#define OBJ_PLTT_LENGTH 768

typedef struct {
  u16 length;                      // 0x00, OBJ_PLTT_LENGTH
  u16 unk_02;                      // 0x02, ???
  u16 body[OBJ_PLTT_LENGTH * 16];  // 0x04, RGB555 array
} ObjPlttFile;
static_assert(sizeof(ObjPlttFile) == 24580);

extern const ObjPlttFile gObjPlttFile0;  // 0x08A2291C

// --------------------------------------------

typedef struct {
  u8 variantCount;  // 0x00
  u8 frameCount;    // 0x01
  u16 frameOffset;  // 0x02, Byte offset from start of the file to the 1st frame of the 1st variant for this animation. There are variantCount*frameCount frames in this animation.
} Animation;

// bit0-3: duration
// bit4: xflip
// bit5: yflip
// bit6-15: sprite index
typedef u16 AnimFrameCmd;

// ActorSprite's animation
typedef struct {
  u16 animationCount;  // 0x00
  u16 frameCount;      // 0x02
  // body:
  //   Animation animations[animationCount];
  //   AnimFrameCmd frames[frameCount];
  u8 body[0];
} AnimationFile;

// --------------------------------------------

#endif  // __INCLUDE_SPRITE_H__
