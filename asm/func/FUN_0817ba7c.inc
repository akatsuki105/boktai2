	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r1, #1
	ldr r2, _0817BA9C @ =0x00000898
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BAA0
	movs r0, #1
	b _0817BAA2
	.align 2, 0
_0817BA9C: .4byte 0x00000898
_0817BAA0:
	movs r0, #0
_0817BAA2:
	cmp r0, #0
	beq _0817BB42
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _0817BAEC @ =0x0000FFFE
	cmp r1, r0
	bhi _0817BB38
	ldr r5, _0817BAF0 @ =0x0000087C
	adds r0, r6, r5
	ldrh r5, [r0]
	cmp r5, #0
	bne _0817BAFC
	adds r0, r4, #0
	bl FUN_0817ea84
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817BAFC
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r3, _0817BAF4 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0817BAF8 @ =0x0000046A
	adds r0, r4, r1
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r1, r4, r3
	b _0817BB28
	.align 2, 0
_0817BAEC: .4byte 0x0000FFFE
_0817BAF0: .4byte 0x0000087C
_0817BAF4: .4byte 0x00000469
_0817BAF8: .4byte 0x0000046A
_0817BAFC:
	movs r5, #0x88
	lsls r5, r5, #4
	adds r0, r6, r5
	ldrh r2, [r0]
	cmp r2, #0
	bne _0817BB38
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r5, _0817BB30 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r0, _0817BB34 @ =0x0000046C
	adds r1, r4, r0
_0817BB28:
	movs r0, #1
	strb r0, [r1]
	b _0817BB72
	.align 2, 0
_0817BB30: .4byte 0x00000469
_0817BB34: .4byte 0x0000046C
_0817BB38:
	ldr r1, _0817BB48 @ =0x0000087E
	adds r0, r6, r1
	ldrh r3, [r0]
	cmp r3, #0
	beq _0817BB4C
_0817BB42:
	movs r0, #0
	b _0817BB72
	.align 2, 0
_0817BB48: .4byte 0x0000087E
_0817BB4C:
	movs r1, #2
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r3, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _0817BB78 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	adds r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_0817BB72:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0817BB78: .4byte 0x0000046A
