#ifndef __INCLUDE_MSGBUS_INLINE_H__
#define __INCLUDE_MSGBUS_INLINE_H__

#include "gba/gba.h"
#include "msgbus.h"
#include "types.h"

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// これらはグローバル変数を参照するため、 必要のない include は決してしないこと

static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

#endif  // __INCLUDE_MSGBUS_INLINE_H__
