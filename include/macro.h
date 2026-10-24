#ifndef __INCLUDE_MACRO_H__
#define __INCLUDE_MACRO_H__

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

#endif  // __INCLUDE_MACRO_H__
