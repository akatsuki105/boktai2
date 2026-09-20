	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08052eb8
FUN_08052eb8: @ 0x08052EB8
	push {r4, r5, lr}
	sub sp, #4
	adds r2, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x14
	adds r2, #0x18
	adds r0, r5, #0
	adds r1, r2, #0
	movs r2, #3
	bl AuxSprite_Add
	movs r0, #0
	strb r0, [r5, #7]
	adds r4, #0x30
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08052EEC @ =0x05000002
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052EEC: .4byte 0x05000002

	thumb_func_start FUN_08052ef0
FUN_08052ef0: @ 0x08052EF0
	push {lr}
	adds r0, r1, #0
	adds r0, #0x14
	bl AuxSprite_Remove
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08052f00
FUN_08052f00: @ 0x08052F00
	push {r4, lr}
	sub sp, #0x1c
	adds r2, r1, #0
	adds r4, r2, #0
	adds r4, #0x14
	ldr r0, [r2, #0x10]
	cmp r0, #0
	beq _08052F18
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
_08052F18:
	ldr r0, [r2, #4]
	cmp r0, #7
	bhi _08052F2E
	lsls r0, r0, #6
	ldrh r1, [r2, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	ldr r0, [r2, #4]
	lsls r0, r0, #1
	adds r0, #1
	b _08052F30
_08052F2E:
	movs r0, #0x40
_08052F30:
	strb r0, [r4, #8]
	ldr r0, [r2, #4]
	cmp r0, #0x13
	bls _08052F70
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r3, #0
	strb r3, [r2, #1]
	ldr r0, _08052F6C @ =0x085AB73C
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0xff
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp, #0x18]
	movs r0, #7
	bl FUN_080149dc
	b _08052F74
	.align 2, 0
_08052F6C: .4byte 0x085AB73C
_08052F70:
	adds r0, #1
	str r0, [r2, #4]
_08052F74:
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Entity08052ffc_Update
Entity08052ffc_Update: @ 0x08052F7C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x34
	movs r5, #0
_08052F86:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08052F96
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08052f00
_08052F96:
	adds r5, #1
	adds r4, #0x40
	cmp r5, #3
	ble _08052F86
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08052ffc_Destroy
Entity08052ffc_Destroy: @ 0x08052FA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x34
	movs r4, #0
_08052FB2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08052ef0
	adds r4, #1
	adds r5, #0x40
	cmp r4, #3
	ble _08052FB2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity08052ffc_Init
Entity08052ffc_Init: @ 0x08052FCC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x18
	ldr r1, _08052FF8 @ =0x000018A8
	bl Video_GetAuxSprite
	adds r5, r6, #0
	adds r5, #0x34
	movs r4, #0
_08052FDE:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08052eb8
	adds r4, #1
	adds r5, #0x40
	cmp r4, #3
	ble _08052FDE
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08052FF8: .4byte 0x000018A8

	thumb_func_start Entity08052ffc_Create
Entity08052ffc_Create: @ 0x08052FFC
	push {r4, lr}
	movs r1, #0x9a
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08053034
	ldr r1, _0805302C @ =Entity08052ffc_Update
	ldr r2, _08053030 @ =Entity08052ffc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08052ffc_Init
	cmp r0, #0
	bge _08053034
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08053036
	.align 2, 0
_0805302C: .4byte Entity08052ffc_Update
_08053030: .4byte Entity08052ffc_Destroy
_08053034:
	adds r0, r4, #0
_08053036:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805303c
FUN_0805303c: @ 0x0805303C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r4, #0
	beq _08053086
	lsls r0, r1, #6
	adds r0, #0x34
	adds r2, r4, r0
	adds r4, r2, #0
	adds r4, #0x14
	movs r0, #0
	strb r5, [r2]
	str r0, [r2, #4]
	strh r1, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #8]
	ldr r0, [r2, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x14]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08053070
	str r0, [r2, #0x10]
	b _08053076
_08053070:
	cmp r0, #1
	bne _08053076
	str r3, [r2, #0x10]
_08053076:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	strb r0, [r2, #1]
_08053086:
	pop {r4, r5}
	pop {r0}
	bx r0
