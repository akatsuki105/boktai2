#ifndef __INCLUDE_SPRITE_PLTT_H__
#define __INCLUDE_SPRITE_PLTT_H__

// https://boktaihacking.net/wiki/Sprite_set_file#Palettes

#define OBJ_PLTT_LENGTH 768

typedef struct {
  u16 length;                      // 0x00, OBJ_PLTT_LENGTH
  u16 unk_02;                      // 0x02, ???
  u16 body[OBJ_PLTT_LENGTH * 16];  // 0x04, RGB555 array
} ObjPlttFile;
static_assert(sizeof(ObjPlttFile) == 24580);

extern const ObjPlttFile gObjPlttFile0;  // 0x08CB9244

#endif  // __INCLUDE_SPRITE_PLTT_H__
