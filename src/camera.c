#include "camera.h"

#include "global.h"

NAKED void Camera_SetTilemapOffset(void) { INCFUNC("asm/func/Camera_SetTilemapOffset.inc"); }

s32 FUN_0823b740(void) { return 0; }

void Camera_0823b744(void) { gCamera = NULL; }

NAKED void Camera_ApplyBounds1(Camera* cam, s16* pos) { INCFUNC("asm/func/Camera_ApplyBounds1.inc"); }

NAKED void Camera_ApplyBounds2(Camera* cam, s16* pos) { INCFUNC("asm/func/Camera_ApplyBounds2.inc"); }

NAKED void Camera_ApplyBounds(Camera* cam, s16* pos) { INCFUNC("asm/func/Camera_ApplyBounds.inc"); }

NAKED void FUN_0823b864(void) { INCFUNC("asm/func/FUN_0823b864.inc"); }

NAKED void FUN_0823b880(s32 n) { INCFUNC("asm/func/FUN_0823b880.inc"); }

NAKED void FUN_0823b8ac(s16* pos) { INCFUNC("asm/func/FUN_0823b8ac.inc"); }

NAKED void FUN_0823b980(s32 n, s16* pos) { INCFUNC("asm/func/FUN_0823b980.inc"); }

NAKED void FUN_0823b9cc(s32 n) { INCFUNC("asm/func/FUN_0823b9cc.inc"); }

NAKED void Camera_Translate(void) { INCFUNC("asm/func/Camera_Translate.inc"); }

NAKED void FUN_0823baa8(void) { INCFUNC("asm/func/FUN_0823baa8.inc"); }

NAKED void FUN_0823bac8(s16* pos) { INCFUNC("asm/func/FUN_0823bac8.inc"); }

NAKED void FUN_0823bb7c(s32 n, s16* pos) { INCFUNC("asm/func/FUN_0823bb7c.inc"); }

NAKED void FUN_0823bbd4(u16 n, s32* pos) { INCFUNC("asm/func/FUN_0823bbd4.inc"); }

INCASM("asm/camera.inc");

NAKED void Camera_SetBoundsType2Scripted(void) { INCFUNC("asm/func/Camera_SetBoundsType2Scripted.inc"); }

NAKED void FUN_0823c450(Camera* cam) { INCFUNC("asm/func/FUN_0823c450.inc"); }

NAKED void FUN_0823c620(Camera* cam) { INCFUNC("asm/func/FUN_0823c620.inc"); }

NAKED UNK_PTR FUN_0823c928(Camera* cam) { INCFUNC("asm/func/FUN_0823c928.inc"); }

NAKED s32 Camera_Update(Camera* cam) { INCFUNC("asm/func/Camera_Update.inc"); }

NAKED s32 Camera_Destroy(Camera* cam) { INCFUNC("asm/func/Camera_Destroy.inc"); }

NAKED s32 Camera_Init(Camera* cam, UNK_PTR* param) { INCFUNC("asm/func/Camera_Init.inc"); }

NAKED Camera* Camera_Create(UNK_PTR* param) { INCFUNC("asm/func/Camera_Create.inc"); }
