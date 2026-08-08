	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _0806B774 @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806B76A
	b _0806B924
_0806B76A:
	lsls r0, r0, #2
	ldr r1, _0806B778 @ =_0806B77C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B774: .4byte 0x0000037D
_0806B778: .4byte _0806B77C
_0806B77C: @ jump table
	.4byte _0806B794 @ case 0
	.4byte _0806B86C @ case 1
	.4byte _0806B894 @ case 2
	.4byte _0806B924 @ case 3
	.4byte _0806B8E0 @ case 4
	.4byte _0806B91C @ case 5
_0806B794:
	ldr r2, _0806B85C @ =0x0000037E
	adds r0, r6, r2
	ldrh r5, [r0]
	cmp r5, #0
	bne _0806B81E
	movs r0, #0xe7
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r2, r6, r3
	strb r5, [r2]
	ldr r1, _0806B860 @ =0x00000992
	adds r0, r6, r1
	strh r5, [r0]
	subs r3, #4
	adds r4, r6, r3
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r5, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0806B864 @ =0x000001B1
	bl PlaySound_082406e0
	ldr r0, _0806B868 @ =0x03002C00
	ldr r2, [r0]
	cmp r2, #0
	beq _0806B81E
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0x2c
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x4c
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0x30
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_080609dc
_0806B81E:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0806B85C @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _0806B924
	movs r0, #0xd0
	bl PlaySound_082406e0
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #1
	bl FUN_08060b84
	b _0806B924
	.align 2, 0
_0806B85C: .4byte 0x0000037E
_0806B860: .4byte 0x00000992
_0806B864: .4byte 0x000001B1
_0806B868: .4byte 0x03002C00
_0806B86C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x30
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #2
	bl FUN_08060b84
	b _0806B924
_0806B894:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0x31
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r3, _0806B8D8 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #3
	bl FUN_08060b84
	ldr r0, _0806B8DC @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0]
	b _0806B924
	.align 2, 0
_0806B8D8: .4byte 0x0000037E
_0806B8DC: .4byte 0x030047A4
_0806B8E0:
	ldr r0, _0806B918 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _0806B8FC
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_0806B8FC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _0806B924
	adds r0, r6, #0
	movs r1, #0x1f
	movs r2, #5
	bl FUN_08060b84
	b _0806B924
	.align 2, 0
_0806B918: .4byte 0x0000037E
_0806B91C:
	adds r0, r6, #0
	movs r1, #5
	bl FUN_08060c40
_0806B924:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
