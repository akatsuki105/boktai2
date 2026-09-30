	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801aaf4
FUN_0801aaf4: @ 0x0801AAF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	movs r0, #8
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r1, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #1
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0801ABA4 @ =0x0203B400
	ldr r3, _0801ABA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801ABAC @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r2, r6
	adds r2, #3
	ands r0, r6
	adds r2, r2, r0
	strb r2, [r1, #1]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #5
	ldrb r2, [r1, #1]
	subs r0, r0, r2
	asrs r0, r0, #2
	strb r0, [r1, #2]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #1
	strb r0, [r1, #3]
	mov r2, r8
	strb r2, [r1, #4]
	mov r0, r8
	strh r0, [r1, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	subs r1, #0x10
	mov r2, sb
	strh r1, [r2, #0x1c]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0xa0
	strh r0, [r2, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABA4: .4byte 0x0203B400
_0801ABA8: .4byte 0x030046B8
_0801ABAC: .4byte 0x000003FF

	thumb_func_start FUN_0801abb0
FUN_0801abb0: @ 0x0801ABB0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r6, #0
	adds r4, #8
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0x11
	bl AuxSprite_Add
	ldr r1, _0801ABF0 @ =0x085AA988
	movs r0, #3
	mov r2, r8
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0801aaf4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABF0: .4byte 0x085AA988

	thumb_func_start FUN_0801abf4
FUN_0801abf4: @ 0x0801ABF4
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl AuxSprite_Remove
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity78C9_Update
Entity78C9_Update: @ 0x0801AC04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x38
	movs r6, #0
	ldr r0, _0801ACC8 @ =0x030046B8
	mov sl, r0
	ldr r1, _0801ACCC @ =0x085B0A08
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
_0801AC22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801ACB0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0801ACD0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801ACD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	ldrb r1, [r4, #3]
	adds r1, r1, r2
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r4, #4]
	movs r3, #4
	ldrsb r3, [r4, r3]
	cmp r3, #0
	bge _0801AC5A
	rsbs r3, r3, #0
_0801AC5A:
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r2, r1, #0
	muls r2, r0, r2
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r4, #1]
	muls r1, r0, r1
	asrs r1, r1, #0xc
	asrs r2, r2, #0xc
	ldrh r0, [r5, #0x1c]
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0801ACB0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0801aaf4
_0801ACB0:
	adds r6, #1
	adds r4, #0x34
	cmp r6, #0x1f
	ble _0801AC22
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801ACC8: .4byte 0x030046B8
_0801ACCC: .4byte 0x085B0A08
_0801ACD0: .4byte 0x000003FF
_0801ACD4: .4byte 0x0203B400

	thumb_func_start Entity78C9_Destroy
Entity78C9_Destroy: @ 0x0801ACD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0801ACE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abf4
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801ACE2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity78C9_Init
Entity78C9_Init: @ 0x0801ACFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, #0x1c
	ldr r1, _0801AD28 @ =0x00002E7B
	bl Video_GetAuxSprite
	movs r4, #0
_0801AD0E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abb0
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801AD0E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801AD28: .4byte 0x00002E7B

	thumb_func_start Entity78C9_Create
Entity78C9_Create: @ 0x0801AD2C
	push {r4, lr}
	movs r1, #0xd7
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AD64
	ldr r1, _0801AD5C @ =Entity78C9_Update
	ldr r2, _0801AD60 @ =Entity78C9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity78C9_Init
	cmp r0, #0
	bge _0801AD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AD66
	.align 2, 0
_0801AD5C: .4byte Entity78C9_Update
_0801AD60: .4byte Entity78C9_Destroy
_0801AD64:
	adds r0, r4, #0
_0801AD66:
	pop {r4}
	pop {r1}
	bx r1
