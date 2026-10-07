#include "link_connect.h"

#include "entity.h"
#include "global.h"
#include "link.h"

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
