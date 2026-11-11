#ifndef __INCLUDE_MACRO_H__
#define __INCLUDE_MACRO_H__

// vx, vy, vz の順に評価
#define VEC3_SET(v, vx, vy, vz) ((v).x = (vx), (v).y = (vy), (v).z = (vz))

#define ANGLE_TO_DIR8(angle) (((((angle) & 0xFF) >> 5) + 3) & 7)

// DIR8_DOWN_LEFT or DIR8_LEFT or DIR8_UP_LEFT
#define IS_8DIR_LEFT(dir8) ((dir8) > 4)

#define SET_FLAGS(target, flags)     \
  {                                  \
    typeof(target) _flags = (flags); \
    (target) |= _flags;              \
  }

#define CLEAR_FLAGS(target, flags)   \
  {                                  \
    typeof(target) _flags = (flags); \
    (target) &= ~_flags;             \
  }

#define TEST_FLAGS(target, flags)    \
  ({                                 \
    typeof(target) _flags = (flags); \
    (target) & _flags;               \
  })

#define SET_BIT(target, bitidx)        \
  {                                    \
    typeof(target) _bitidx = (bitidx); \
    (target) |= (1 << _bitidx);        \
  }

#define CLEAR_BIT(target, bitidx)      \
  {                                    \
    typeof(target) _bitidx = (bitidx); \
    (target) &= ~(1 << _bitidx);       \
  }

#endif  // __INCLUDE_MACRO_H__
