#include "global.h"
#include "msgbus.h"

// カットシーンスクリプトの構成 (内部的には MsgPacket をまとめただけ)
//
//   gCutsceneTable[125]      カットシーンIDで引く表 (このファイルの末尾)
//     |
//     +- sCutscene_N[]            1つのカットシーン, ステップへのポインタを並べて NULL 終端 (data/cutscene/cutscenes.h)
//          |                  添字がそのまま進行順で、MsgBus が step を1つずつ上げていく
//          +- sStep_cN_sM[]        1ステップ, メッセージへのポインタを並べて NULL 終端 (data/cutscene/step_*.h)
//               |                 同じステップのメッセージは同じフレームにまとめて配られる
//               +- sMsg_cN_sM_K       1件のメッセージ, 宛先 (targetID/targetClass) と cmd と引数 (data/cutscene/msg_*.h)
//                                     waitFlag が WAIT のものは、受け手が処理し終えるまで次のステップに進まない
//
// CutsceneTable_GetMsg がこの3段を引いて1件を返し、MsgBus がそれを宛先のエンティティに配る

// ---- メッセージの実体 ----
// 可変長で、実体サイズは 8 + ceil(argc/2)*4, argc を偶数に丸めた6種を使い分ける
// 実行時に見るときは MsgPacket* にキャストする, 余りスロットは常に 0,

// clang-format off
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; }                CutsceneMsg0;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[2]; }   CutsceneMsg2;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[4]; }   CutsceneMsg4;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[6]; }   CutsceneMsg6;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[8]; }   CutsceneMsg8;
typedef struct { u16 targetID; u8 targetClass; u8 waitFlag; u16 unk_4; u8 cmd; u8 argc; s16 args[10]; }  CutsceneMsg10;
// clang-format on

// waitFlag: WAIT なら受け手が処理し終えるまで次のステップに進まない
#define NOWAIT 0
#define WAIT 1

// cmd の意味は targetClass ごとに別物, ハンドラを読んで確定したものだけ名前を付けてある
#define BUS_EXEC_SCRIPT 0  // Cutscene_CmdExecScript
#define BUS_WAIT 1         // Cutscene_CmdWait
#define BUS_WAIT_EXT 2     // Cutscene_CmdWaitExternal

#define TGT_BUS 0x4E69        // hash元見特定, gMsgBus
#define TGT_PLAYER 0xF5EB     // BOKHASH("プレイヤー")
#define TGT_DJANGO 0xBF31     // BOKHASH("ジャンゴ")
#define TGT_SABATA 0x2B06     // BOKHASH("サバタ")
#define TGT_OTNK 0x9CFE       // BOKHASH("おてんこさま")
#define TGT_DUNEYRR 0x2B18    // BOKHASH("ドゥネイル")
#define TGT_DURATHROR 0x9386  // BOKHASH("ドゥラスロール")
#define TGT_DVALINN 0x0074    // BOKHASH("ドヴァリン")
#define TGT_DAIIN 0x7901      // BOKHASH("ダーイン")
#define TGT_SMITH 0x6740      // BOKHASH("スミス")
#define TGT_RITA 0x3DB5       // BOKHASH("リタ")
#define TGT_ZAJI 0x6DAD       // BOKHASH("ザジ")
#define TGT_SUMIRE 0x6773     // BOKHASH("スミレ")
#define TGT_KURO 0x51E2       // BOKHASH("クロ")
#define TGT_KID 0xF68F        // BOKHASH("キッド")
#define TGT_MARCELLO 0xCB6B   // BOKHASH("マルチェロ")
#define TGT_LUIS 0x7E5F       // BOKHASH("ルイス")
#define TGT_LADY 0x0A5A       // BOKHASH("レディ")
#define TGT_MEGAMAN 0xB548    // BOKHASH("ロックマン")
#define TGT_SHADEMAN 0x0623   // BOKHASH("シェードマン")
#define TGT_HATENA 0x04B1     // BOKHASH("ハテナ")

#define M(x) (const MsgPacket*)&x

// clang-format off
// メッセージ本体 (ファイル分割はキリの良い単位でやっただけで、意味は特にない)
#include "data/cutscene/msg_000.h"
#include "data/cutscene/msg_025.h"
#include "data/cutscene/msg_050.h"
#include "data/cutscene/msg_075.h"
#include "data/cutscene/msg_100.h"

// ステップ (ファイル分割はキリの良い単位でやっただけで、意味は特にない)
#include "data/cutscene/step_000.h"
#include "data/cutscene/step_025.h"
#include "data/cutscene/step_050.h"
#include "data/cutscene/step_075.h"
#include "data/cutscene/step_100.h"

#include "data/cutscene/cutscenes.h"
// clang-format on

// clang-format off
const MsgPacket* const* const* const gCutsceneTable[125] = {
    sCutscene_0,   sCutscene_1,   sCutscene_2,   sCutscene_3,   sCutscene_4,   sCutscene_5,   sCutscene_6,
    sCutscene_7,   sCutscene_8,   sCutscene_9,   sCutscene_10,  sCutscene_11,  sCutscene_12,  sCutscene_13,
    sCutscene_14,  sCutscene_15,  sCutscene_16,  sCutscene_17,  sCutscene_18,  sCutscene_19,  sCutscene_20,
    sCutscene_21,  sCutscene_22,  sCutscene_23,  sCutscene_24,  sCutscene_25,  sCutscene_26,  sCutscene_27,
    sCutscene_28,  sCutscene_29,  sCutscene_30,  sCutscene_31,  sCutscene_32,  sCutscene_33,  sCutscene_34,
    sCutscene_35,  sCutscene_36,  sCutscene_37,  sCutscene_38,  sCutscene_39,  sCutscene_40,  sCutscene_41,
    sCutscene_42,  sCutscene_43,  sCutscene_44,  sCutscene_45,  sCutscene_46,  sCutscene_47,  sCutscene_48,
    sCutscene_49,  sCutscene_50,  sCutscene_51,  sCutscene_52,  sCutscene_53,  sCutscene_54,  sCutscene_55,
    sCutscene_56,  sCutscene_57,  sCutscene_58,  sCutscene_59,  sCutscene_60,  sCutscene_61,  sCutscene_62,
    sCutscene_63,  sCutscene_64,  sCutscene_65,  sCutscene_66,  sCutscene_67,  sCutscene_68,  sCutscene_69,
    sCutscene_70,  sCutscene_71,  sCutscene_72,  sCutscene_73,  sCutscene_74,  sCutscene_75,  sCutscene_76,
    sCutscene_77,  sCutscene_78,  sCutscene_79,  sCutscene_80,  sCutscene_81,  sCutscene_82,  sCutscene_83,
    sCutscene_84,  sCutscene_85,  sCutscene_86,  sCutscene_87,  sCutscene_88,  sCutscene_89,  sCutscene_90,
    sCutscene_91,  sCutscene_92,  sCutscene_93,  sCutscene_94,  sCutscene_95,  sCutscene_96,  sCutscene_97,
    sCutscene_98,  sCutscene_99,  sCutscene_100, sCutscene_101, sCutscene_102, sCutscene_103, sCutscene_104,
    sCutscene_105, sCutscene_106, sCutscene_107, sCutscene_108, sCutscene_109, sCutscene_110, sCutscene_111,
    sCutscene_112, sCutscene_113, sCutscene_114, sCutscene_115, sCutscene_116, sCutscene_117, sCutscene_118,
    sCutscene_119, sCutscene_120, sCutscene_121, sCutscene_122, sCutscene_123, sCutscene_124,
}; // 0x08DBD564
// clang-format on

// カットシーン表から cutsceneID/step/idx のメッセージを1件引く (どの段でも NULL に当たったら終端)
MsgPacket* CutsceneTable_GetMsg(s32 cutsceneID, s32 step, s32 idx) {
  const MsgPacket* const* const* cutscene;
  const MsgPacket* const* stp;

  cutscene = gCutsceneTable[cutsceneID];
  if (cutscene != NULL) {
    stp = cutscene[step];
    if (stp != NULL) {
      return (MsgPacket*)stp[idx];
    }
  }
  return NULL;
}
