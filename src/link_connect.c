#include "entity.h"
#include "global.h"

// 2人用リンクの接続待ち。0x192 を送り合い、両方が 0xE2 になったら成功として onSuccess を呼ぶ
typedef struct LinkConnect {
  Entity e;         // 0x00, ENTITY_UNK_2
  s32 timeout;      // 0x18, Create の第1引数。0 なら 300。LinkConnect_TickTimeout が timer と比べる
  s32 cancelable;   // 0x1C, Create の第2引数。0 でない間だけ B ボタンでキャンセルできる
  s32 canceled;     // 0x20, B ボタンで打ち切ったとき 1。コールバックの第3引数になる
  s32 handle;       // 0x24, FUN_08238bc0() の戻り値。負の間は張り直す。コールバックの第2引数になる
  s32 succeeded;    // 0x28, 両者が 0xE2 を返したら 1。onSuccess と onFailure の選択に使う
  s32 finished;     // 0x2C, 立つと次のフレームでコールバックを呼んで KillEntity する
  s32 linkStopped;  // 0x30, FUN_08238bf4 を呼んだら 1。_Destroy はこれが立っていれば呼ばない
  s32 timer;        // 0x34, LinkConnect_TickTimeout が +1 し、timeout 以上になったら真を返す
  s32 agreeFrames;  // 0x38, 両者が 0x192 を返し続けたフレーム数。0x77 を超えると sendVal が 0xE2 になる
  s32 unk_3c;       // 0x3C, 再試行カウンタ。0x1E で張り直して 0 に戻る
  s32 unk_40;       // 0x40, handle が負の間の再試行カウンタ。0x1E で張り直して 0 に戻る
  s32 sendResult;   // 0x44, FUN_08238e14(sendVal) の戻り値。_Init は -1
  s32 recvResult;   // 0x48, FUN_08238da8(recvBuf) の戻り値。-3 なら再試行。_Init は -1
  s32 unk_4c;       // 0x4C, recvResult が -3 になるたびに +1
  s32 unk_50;       // 0x50, recvResult が負のときの再試行カウンタ。0x1E で張り直して 0 に戻る
  s32 unk_54;       // 0x54, リンクを張り直している間 +1
  s32 unk_58;       // 0x58, 受信に成功したフレームごとに +1
  u16 sendVal;      // 0x5C, FUN_08238e14 で送る値。握手中は 0x192、agreeFrames が 0x77 を超えると 0xE2
  u16 recvBuf[4];   // 0x5E, FUN_08238da8 が埋める。-1 でないスロットを数え、0x192 と 0xE2 を探す
  u8 unk_66[2];     // 0x66, 読み書きとも無し
  void* onSuccess;  // 0x68, LinkConnect_SetCallbacks の第2引数。fn(owner, handle, canceled) で呼ぶ
  void* onFailure;  // 0x6C, 同第3引数。成功しなかったときに同じ形で呼ぶ
  void* owner;      // 0x70, 同第1引数。コールバックの第1引数になる
} LinkConnect;
static_assert(sizeof(LinkConnect) == 116);

void FUN_08238bf4(void);

extern LinkConnect* gLinkConnect;  // 0x03002C64

void LinkConnect_ClearGlobal(void) { gLinkConnect = NULL; }

// 待ち時間を1フレーム進め、timeout に達したかを返す
bool32 LinkConnect_TickTimeout(LinkConnect* p) {
  p->timer++;
  if (p->timer >= p->timeout) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 LinkConnect_Update(LinkConnect* p) { INCFUNC("asm/func/LinkConnect_Update.inc"); }

s32 LinkConnect_Destroy(LinkConnect* p) {
  if (p->linkStopped == 0) {
    FUN_08238bf4();
  }
  gLinkConnect = NULL;
  return 0;
}

NAKED s32 LinkConnect_Init(LinkConnect* p, s32 timeout, s32 cancelable) { INCFUNC("asm/func/LinkConnect_Init.inc"); }

LinkConnect* LinkConnect_Create(s32 timeout, s32 cancelable) {
  LinkConnect* p;

  if (gLinkConnect != NULL) {
    return gLinkConnect;
  }
  p = CreateEntity(ENTITY_UNK_2, sizeof(LinkConnect));
  if (p != NULL) {
    SetEntityRoutine(p, LinkConnect_Update, LinkConnect_Destroy);
    if (LinkConnect_Init(p, timeout, cancelable) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 接続の成否を知らせるコールバックを登録する
void LinkConnect_SetCallbacks(void* owner, void* onSuccess, void* onFailure) {
  if (gLinkConnect != NULL) {
    gLinkConnect->owner = owner;
    gLinkConnect->onSuccess = onSuccess;
    gLinkConnect->onFailure = onFailure;
  }
}
