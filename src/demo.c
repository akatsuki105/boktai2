#include "global.h"
#include "msgbus.h"

// デモ(イベント/カットシーン)スクリプトの構成 (内部的には EntityMsg をまとめただけ)
//
//   gDemoTable[125]      デモIDで引く表 (このファイルの末尾)
//     |
//     +- sDemo_N[]            1つのデモ, ステップへのポインタを並べて NULL 終端 (data/demo/demos.h)
//          |                  添字がそのまま進行順で、EntityMsgBus が step を1つずつ上げていく
//          +- sStep_dN_sM[]        1ステップ, メッセージへのポインタを並べて NULL 終端 (data/demo/step_*.h)
//               |                 同じステップのメッセージは同じフレームにまとめて配られる
//               +- sMsg_dN_sM_K       1件のメッセージ, 宛先 (targetID/targetClass) と cmd と引数 (data/demo/msg_*.h)
//                                     waitFlag が WAIT のものは、受け手が処理し終えるまで次のステップに進まない
//
// DemoTable_GetMsg がこの3段を引いて1件を返し、EntityMsgBus がそれを宛先のエンティティに配る

// ---- メッセージの実体 ----
// 可変長で、実体サイズは 8 + ceil(argc/2)*4, argc を偶数に丸めた6種を使い分ける
// 実行時に見るときは EntityMsg* にキャストする, 余りスロットは常に 0,

// clang-format off
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; }                DemoMsg0;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[2]; }   DemoMsg2;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[4]; }   DemoMsg4;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[6]; }   DemoMsg6;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[8]; }   DemoMsg8;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[10]; }  DemoMsg10;
// clang-format on

// waitFlag: WAIT なら受け手が処理し終えるまで次のステップに進まない
#define NOWAIT 0
#define WAIT 1

// targetClass: 宛先の種別, EntityMsgBus_Register の第3引数と照合される
#define CLS_BUS 1
#define CLS_PLAYER 2
#define CLS_ENEMY 3
#define CLS_BOSS 4
#define CLS_ACTOR 5
#define CLS_CAMERA 6
#define CLS_FADE 7
#define CLS_SOUND 8
#define CLS_CBB0 9
#define CLS_ETC 10

// cmd の意味は targetClass ごとに別物, ハンドラを読んで確定したものだけ名前を付けてある
#define BUS_EXEC_SCRIPT 0  // Demo_CmdExecScript
#define BUS_WAIT 1         // Demo_CmdWait
#define BUS_WAIT_EXT 2     // Demo_CmdWaitExternal

#define M(x) (const EntityMsg*)&x

// clang-format off
// メッセージ本体 (ファイル分割はキリの良い単位でやっただけで、意味は特にない)
#include "data/demo/msg_000.h"
#include "data/demo/msg_025.h"
#include "data/demo/msg_050.h"
#include "data/demo/msg_075.h"
#include "data/demo/msg_100.h"

// ステップ (ファイル分割はキリの良い単位でやっただけで、意味は特にない)
#include "data/demo/step_000.h"
#include "data/demo/step_025.h"
#include "data/demo/step_050.h"
#include "data/demo/step_075.h"
#include "data/demo/step_100.h"

#include "data/demo/demos.h"
// clang-format on

const EntityMsg* const* const* const gDemoTable[125] = {
    sDemo_0,  sDemo_1,  sDemo_2,  sDemo_3,  sDemo_4,  sDemo_5,  sDemo_6,  sDemo_7,  sDemo_8,  sDemo_9,  sDemo_10, sDemo_11, sDemo_12, sDemo_13, sDemo_14, sDemo_15, sDemo_16, sDemo_17, sDemo_18, sDemo_19, sDemo_20, sDemo_21, sDemo_22, sDemo_23, sDemo_24, sDemo_25, sDemo_26, sDemo_27, sDemo_28, sDemo_29, sDemo_30, sDemo_31, sDemo_32, sDemo_33, sDemo_34, sDemo_35, sDemo_36, sDemo_37,  sDemo_38,  sDemo_39,  sDemo_40,  sDemo_41,  sDemo_42,  sDemo_43,  sDemo_44,  sDemo_45,  sDemo_46,  sDemo_47,  sDemo_48,  sDemo_49,  sDemo_50,  sDemo_51,  sDemo_52,  sDemo_53,  sDemo_54,  sDemo_55,  sDemo_56,  sDemo_57,  sDemo_58,  sDemo_59,  sDemo_60,  sDemo_61,  sDemo_62,
    sDemo_63, sDemo_64, sDemo_65, sDemo_66, sDemo_67, sDemo_68, sDemo_69, sDemo_70, sDemo_71, sDemo_72, sDemo_73, sDemo_74, sDemo_75, sDemo_76, sDemo_77, sDemo_78, sDemo_79, sDemo_80, sDemo_81, sDemo_82, sDemo_83, sDemo_84, sDemo_85, sDemo_86, sDemo_87, sDemo_88, sDemo_89, sDemo_90, sDemo_91, sDemo_92, sDemo_93, sDemo_94, sDemo_95, sDemo_96, sDemo_97, sDemo_98, sDemo_99, sDemo_100, sDemo_101, sDemo_102, sDemo_103, sDemo_104, sDemo_105, sDemo_106, sDemo_107, sDemo_108, sDemo_109, sDemo_110, sDemo_111, sDemo_112, sDemo_113, sDemo_114, sDemo_115, sDemo_116, sDemo_117, sDemo_118, sDemo_119, sDemo_120, sDemo_121, sDemo_122, sDemo_123, sDemo_124,
};

// デモ表から demoID/step/idx のメッセージを1件引く (どの段でも NULL に当たったら終端)
EntityMsg* DemoTable_GetMsg(s32 demoID, s32 step, s32 idx) {
  const EntityMsg* const* const* demo;
  const EntityMsg* const* stp;

  demo = gDemoTable[demoID];
  if (demo != NULL) {
    stp = demo[step];
    if (stp != NULL) {
      return (EntityMsg*)stp[idx];
    }
  }
  return NULL;
}
