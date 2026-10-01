	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Entity162E_Update
Entity162E_Update: @ 0x080899F4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08089A50 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08089A98
	ldr r0, [r0, #0x1c]
	cmp r0, #1
	bne _08089A98
	movs r7, #0
	ldr r6, _08089A54 @ =0x030046A0
	ldr r0, [r6]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _08089A58
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x1a]
	cmp r0, r2
	blo _08089A5A
	strh r7, [r5, #0x18]
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #1
	bl FUN_0809c3c0
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bgt _08089A5A
	b _08089A5E
	.align 2, 0
_08089A50: .4byte 0x03002BE0
_08089A54: .4byte 0x030046A0
_08089A58:
	movs r7, #1
_08089A5A:
	cmp r7, #0
	beq _08089A98
_08089A5E:
	ldr r4, _08089AA0 @ =0x03002BE0
	ldr r1, [r4]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _08089A98
	adds r0, r1, #0
	bl FUN_0807e854
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08089AA4 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl KillEntity
_08089A98:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08089AA0: .4byte 0x03002BE0
_08089AA4: .4byte 0x0000037D

	thumb_func_start Entity162E_Destroy
Entity162E_Destroy: @ 0x08089AA8
	movs r0, #0
	bx lr

	thumb_func_start Entity162E_Init
Entity162E_Init: @ 0x08089AAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08089AD4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	bgt _08089AC4
	movs r0, #1
	str r0, [r1]
_08089AC4:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08089AD8
	bl VM_GetValue
	b _08089ADA
	.align 2, 0
_08089AD4: .4byte 0x030046A0
_08089AD8:
	movs r0, #0x1e
_08089ADA:
	strh r0, [r4, #0x1a]
	movs r0, #0
	strh r0, [r4, #0x18]
	ldr r0, _08089B00 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_0809c3c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089B00: .4byte 0x030046A0

	thumb_func_start Entity162E_Create
Entity162E_Create: @ 0x08089B04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08089B40
	ldr r1, _08089B38 @ =Entity162E_Update
	ldr r2, _08089B3C @ =Entity162E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity162E_Init
	cmp r0, #0
	bge _08089B40
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08089B42
	.align 2, 0
_08089B38: .4byte Entity162E_Update
_08089B3C: .4byte Entity162E_Destroy
_08089B40:
	adds r0, r4, #0
_08089B42:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
