	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl Mover_ApplyMove
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r6, #0
	bl Boss_AdvanceAnim
	movs r5, #0xb2
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #8]
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ldrh r5, [r4, #0xa]
	adds r0, r0, r5
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r5, #0xb5
	lsls r5, r5, #1
	adds r3, r6, r5
	ldrb r0, [r3]
	cmp r0, #0
	beq _0803CFD8
	ldr r2, _0803CF78 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803CF7C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0803CF80 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _0803CF84 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r3]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0803CF88
	asrs r3, r0, #0xc
	b _0803CF8E
	.align 2, 0
_0803CF78: .4byte 0x030046B8
_0803CF7C: .4byte 0x000003FF
_0803CF80: .4byte 0x0203B400
_0803CF84: .4byte gSineTable
_0803CF88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803CF8E:
	movs r0, #0xdb
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0803CFBA
	asrs r2, r0, #0xc
	b _0803CFC0
_0803CFBA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803CFC0:
	movs r5, #0xdc
	lsls r5, r5, #2
	adds r0, r6, r5
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0803CFD8:
	adds r0, r7, #0
	bl FUN_08022e20
	adds r2, r7, #0
	adds r2, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0803D020
	movs r3, #0
	ldrsh r5, [r1, r3]
	movs r3, #8
	ldrsh r0, [r2, r3]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	adds r1, r7, #0
	adds r1, #0xc8
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0xc0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0803D020:
	movs r1, #3
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803D092
	bl FUN_08050d40
	cmp r0, #0
	beq _0803D092
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x14
	adds r4, r6, #0
	adds r4, #0x90
	movs r2, #0
	ldrsh r5, [r4, r2]
	adds r1, r5, r7
	adds r0, r6, #0
	bl Boss_SetHP
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _0803D08A
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r4, _0803D09C @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0803D0A0 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #8]
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0xc]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0805fe7c
_0803D08A:
	movs r0, #0xdd
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803D092:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D09C: .4byte 0xFFFF0000
_0803D0A0: .4byte 0x0000FFFF
