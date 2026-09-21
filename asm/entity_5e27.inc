	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08018f30
FUN_08018f30: @ 0x08018F30
	ldrh r0, [r0, #0x18]
	movs r2, #1
	lsls r2, r1
	ands r0, r2
	bx lr
	.align 2, 0

	thumb_func_start FUN_08018f3c
FUN_08018f3c: @ 0x08018F3C
	push {r4, lr}
	ldr r4, _08018F64 @ =0x03004250
	movs r2, #0
	ldr r3, _08018F68 @ =0x085AA964
	adds r1, r0, #0
	adds r1, #0x1c
_08018F48:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #8
	ble _08018F48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08018F64: .4byte 0x03004250
_08018F68: .4byte 0x085AA964

	thumb_func_start FUN_08018f6c
FUN_08018f6c: @ 0x08018F6C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08018F94 @ =0x03004250
	movs r4, #0
	ldr r5, _08018F98 @ =0x085AA964
_08018F76:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08018f30
	cmp r0, #0
	beq _08018F9C
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r1, r7, #0
	adds r1, #0xd0
	ldrh r1, [r1]
	strh r1, [r0]
	b _08018FAE
	.align 2, 0
_08018F94: .4byte 0x03004250
_08018F98: .4byte 0x085AA964
_08018F9C:
	ldrb r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r2, r4, #1
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
_08018FAE:
	adds r5, #1
	adds r4, #1
	cmp r4, #8
	ble _08018F76
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity5E27_Update
Entity5E27_Update: @ 0x08018FBC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018FE4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08018FD8
	cmp r1, #0
	bne _08018FE4
_08018FD8:
	adds r0, r4, #0
	bl FUN_08018f3c
	adds r0, r4, #0
	bl FUN_08018f6c
_08018FE4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity5E27_Destroy
Entity5E27_Destroy: @ 0x08018FEC
	movs r0, #0
	bx lr

	thumb_func_start Entity5E27_Init
Entity5E27_Init: @ 0x08018FF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801900C @ =0x0000FFFF
	movs r0, #0x66
	bl VM_GetKeywordValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_08018f3c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801900C: .4byte 0x0000FFFF

	thumb_func_start Entity5E27_Create
Entity5E27_Create: @ 0x08019010
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019044
	ldr r1, _0801903C @ =Entity5E27_Update
	ldr r2, _08019040 @ =Entity5E27_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity5E27_Init
	cmp r0, #0
	bge _08019044
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019046
	.align 2, 0
_0801903C: .4byte Entity5E27_Update
_08019040: .4byte Entity5E27_Destroy
_08019044:
	adds r0, r4, #0
_08019046:
	pop {r4}
	pop {r1}
	bx r1
