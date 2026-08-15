#ifndef GUARD_ZOKTAI_TYPES_H
#define GUARD_ZOKTAI_TYPES_H

#include "gba/types.h"

// include/constants/item.h
typedef s16 item16_t;
typedef s32 item32_t;

// include/constants/armor.h
typedef s16 armor16_t;
typedef s32 armor32_t;

// include/constants/coffin.h
typedef s16 coffin_t;

typedef u16 SoundID16;
typedef u32 SoundID32;

// include/constants/weapon.h
typedef u8 weapon8_t;
typedef s32 weapon32_t;

// include/constants/magic.h
typedef s16 magic16_t;
typedef s32 magic32_t;

typedef s16 slot16_t;
typedef s32 slot32_t;

typedef s8_8 vec3[3];

// Placeholder for a NAKED-stub parameter whose real type isn't known yet.
// Never used for existing plain `void*` params — only for new decomp-naked
// promotions. Grep for this to find every not-yet-typed parameter.
typedef void* UNK_PTR;

typedef s32 Sunlevel;  // 0..10, (digital) sunlight level

#endif  // GUARD_ZOKTAI_TYPES_H
