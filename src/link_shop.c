#include "entity.h"
#include "global.h"
#include "link.h"
#include "tilemap.h"

typedef u32 LinkShopFlags;
#define LSFLAG_SENDING (1 << 0)            // 0x1, msg を送信待ちまたは送信中
#define LSFLAG_RECEIVED (1 << 1)           // 0x2, msg に相手からのメッセージが入っている
#define LSFLAG_PARENT (1 << 5)             // 0x20, 自分が親
#define LSFLAG_CHILD (1 << 6)              // 0x40, 自分が子
#define LSFLAG_REQ_NAME (1 << 7)           // 0x80, 名前を要求された (msg.kind 6 を受けた)
#define LSFLAG_REQ_SOLARBANK (1 << 8)      // 0x100, 太陽バンクの残高を要求された (msg.kind 7 を受けた)
#define LSFLAG_REQ_WEAPONCOUNT (1 << 9)    // 0x200, 交換に出せる武器の本数を要求された (msg.kind 8 を受けた)
#define LSFLAG_UNK_10 (1 << 10)            // 0x400, 落とす側しかおらず立てる側が未発見
#define LSFLAG_READY (1 << 11)             // 0x800, パケット層まで用意できた
#define LSFLAG_FINISHED (1 << 12)          // 0x1000, 終了処理に入った
#define LSFLAG_ID_FIXED (1 << 13)          // 0x2000, multiId を記録した
#define LSFLAG_NO_LINK_WATCH (1 << 14)     // 0x4000, リンクの生存確認をやめる
#define LSFLAG_ALLOW_SOFT_RESET (1 << 15)  // 0x8000, 立つまで gSoftResetInhibit を立て続ける

// 回線に流す1通分のメッセージ, .kind 以外の意味は kind ごとに変わる
typedef struct LinkShopMsg {
  u16 kind;     // 0x00, 0 = 太陽バンクの残高, 1 = 名前, 2 = 武器の本数, 3-5/6-8/10-12 は呼び出し側が決める
  u16 unk_02;   // 0x02, LinkShopManager_Send の第3引数をそのまま乗せる, 読むのは受け取った側の onRecv
  s32 data[3];  // 0x04, kind 1 では GameInfo.name の12バイト, kind 0 は残高, kind 2 は売れる武器の本数2種
} LinkShopMsg;
static_assert(sizeof(LinkShopMsg) == 16);

struct LinkShopManager;

typedef void (*LinkShopStateFn)(struct LinkShopManager* p);
typedef void (*LinkShopDoneFn)(void* owner);
typedef void (*LinkShopRecvFn)(void* owner, LinkShopMsg* msg);

// _Create が EntityA0A6_Create と Entity92ED_Create の 2種類ある (_Update, _Destroy は共通で _Init は別)
// "通信販売"(というアイテム交換機能) の 文字列を使っていたので、 LinkShopManager という名前にしたが、 "通信販売" のロジックではなく、"通信販売"のセッション管理だけかもしれない (もしそうなら、適切な名前に変える)
typedef struct LinkShopManager {
  Entity e;                   // 0x00, ENTITY_UNK_2
  u8 unk_18[0x3C - 0x18];     // 0x18, 読み手も書き手も未発見
  LinkShopMsg msg;            // 0x3C, 送信にも受信にも同じ領域を使う
  LinkShopStateFn stateFn;    // 0x4C
  s32 sendPacketId;           // 0x50, Sio_SendPacket が払い出した id, -1 なら送信していない
  u8* script;                 // 0x54, TextBox_Start に渡す文字列
  TilemapFile* tilemap;       // 0x58, TILEMAP_A413
  u8 unk_5c[0x60 - 0x5C];     // 0x5C, 読み手も書き手も未発見
  u8 unk_60;                  // 0x60, 外から書いて読むだけの1バイト
  u8 unk_61;                  // 0x61, 0xFF が入るだけで読み手は未発見
  u16 stateTimer;             // 0x62, 状態に入ってからのフレーム数
  LinkShopFlags flags;        // 0x64
  u8 resultLine;              // 0x68, TextBox_ShowLine に渡す行番号, 2 = エラー, 3 = キャンセル, 4 = 正常終了
  bool8 stateEnter;           // 0x69, 状態に入った最初のフレームだけ 1
  u8 state;                   // 0x6A, 0 = 受信待ち, 1 = 送信待ち, 4 = メッセージ処理, 5 = エラー, 6 = 終了, 7 = 接続待ち
  u8 idleFrames;              // 0x6B, 割り込み回数が進まないフレーム数, 11 で切断とみなす
  u8 noDataFrames;            // 0x6C, 相手のデータが来ないフレーム数, 11 で切断とみなす
  s8 multiId;                 // 0x6D, 記録した Sio_GetMultiId(), 初期値 -1
  u16 scriptID;               // 0x6E, '.e', 終了時に VM_ExecByID する
  s32 intrCount;              // 0x70, 前フレームの割り込み回数, idleFrames と組で生存確認に使う
  void* owner;                // 0x74, onSendDone と onRecv の第1引数
  LinkShopDoneFn onSendDone;  // 0x78
  LinkShopRecvFn onRecv;      // 0x7C
  LinkShopStateFn onFinish;   // 0x80, KillEntity の直前に呼ぶ
} LinkShopManager;
static_assert(sizeof(LinkShopManager) == 132);

extern LinkShopManager* gLinkShopManager;  // 0x03002C6C, 0 以外なら SoftReset_0823a928 が Sio_Stop を呼ぶ

INCASM("asm/link_shop.inc");
