	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a6f54
FUN_080a6f54: @ 0x080A6F54
	push {lr}
	adds r3, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #5
	bhi _080A6F90
	ldr r2, _080A6F84 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A6F88 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A6F8C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xf
	ands r0, r1
	subs r0, #7
	adds r1, r3, #0
	adds r1, #0x58
	strh r0, [r1]
	b _080A6F9C
	.align 2, 0
_080A6F84: .4byte 0x030046B8
_080A6F88: .4byte 0x000003FF
_080A6F8C: .4byte 0x0203B400
_080A6F90:
	adds r0, r3, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A6F9C:
	pop {r0}
	bx r0

	thumb_func_start Entity92BE_Update
Entity92BE_Update: @ 0x080A6FA0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r2, r4, #0
	adds r2, #0x9a
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r2, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080A6FDA
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6FD4
	movs r1, #0
	bl Script_ExecById
_080A6FD4:
	adds r0, r4, #0
	bl KillEntity
_080A6FDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity92BE_Destroy
Entity92BE_Destroy: @ 0x080A6FE0
	push {lr}
	adds r0, #0x38
	bl FUN_0822f1c0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity92BE_Init
Entity92BE_Init: @ 0x080A6FF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080A700C @ =0x0000CB05
	ldr r1, _080A7010 @ =0x000082F1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080A7014
	movs r0, #1
	rsbs r0, r0, #0
	b _080A70C0
	.align 2, 0
_080A700C: .4byte 0x0000CB05
_080A7010: .4byte 0x000082F1
_080A7014:
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0x74
	bl VM_SeekToKeyword
	adds r7, r4, #0
	cmp r0, #0
	beq _080A7046
	bl Script_GetValue
	adds r6, r0, #0
	b _080A7048
_080A7046:
	movs r6, #0
_080A7048:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A705C
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	b _080A7062
_080A705C:
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x3c
_080A7062:
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0xac
	ldr r0, _080A70B4 @ =0x080A6F55
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0xa0
	movs r3, #0
	strh r3, [r4]
	adds r0, r5, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	subs r0, #0x6c
	adds r2, r6, #0
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	str r1, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r7, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080A70B8
	bl Script_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A70BE
	.align 2, 0
_080A70B4: .4byte 0x080A6F55
_080A70B8:
	adds r0, r5, #0
	adds r0, #0xa8
	str r1, [r0]
_080A70BE:
	movs r0, #0
_080A70C0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity92BE_Create
Entity92BE_Create: @ 0x080A70C8
	push {r4, lr}
	movs r0, #9
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A70FC
	ldr r1, _080A70F4 @ =Entity92BE_Update
	ldr r2, _080A70F8 @ =Entity92BE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity92BE_Init
	cmp r0, #0
	beq _080A70FC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A70FE
	.align 2, 0
_080A70F4: .4byte Entity92BE_Update
_080A70F8: .4byte Entity92BE_Destroy
_080A70FC:
	adds r0, r4, #0
_080A70FE:
	pop {r4}
	pop {r1}
	bx r1
