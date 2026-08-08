	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0821D418
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0821D41A
_0821D418:
	movs r0, #0
_0821D41A:
	cmp r0, #0
	beq _0821D478
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_0821c010
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	add r2, sp, #4
	bl FUN_0821c0c4
	ldr r2, _0821D450 @ =0x00000BF6
	adds r4, r5, r2
	ldrb r1, [r4]
	cmp r0, r1
	bne _0821D458
	ldr r0, _0821D454 @ =0x00000BCC
	adds r2, r5, r0
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_0821c044
	strb r0, [r4]
	b _0821D466
	.align 2, 0
_0821D450: .4byte 0x00000BF6
_0821D454: .4byte 0x00000BCC
_0821D458:
	strb r0, [r4]
	ldr r1, _0821D4A8 @ =0x00000BCC
	adds r2, r5, r1
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
_0821D466:
	adds r0, r5, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08221268
	ldr r2, _0821D4AC @ =0x00000804
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
_0821D478:
	movs r1, #0x10
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821D4A0
	movs r0, #0
	movs r4, #0x79
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0821d870
	ldr r1, _0821D4B0 @ =0x00000806
	adds r0, r5, r1
	strh r4, [r0]
_0821D4A0:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821D4A8: .4byte 0x00000BCC
_0821D4AC: .4byte 0x00000804
_0821D4B0: .4byte 0x00000806
