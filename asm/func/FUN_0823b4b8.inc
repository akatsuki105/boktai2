	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0823B508
	ldr r0, _0823B4D4 @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0823B4D8
	cmp r0, #1
	beq _0823B4F2
	b _0823B520
	.align 2, 0
_0823B4D4: .4byte 0x03003540
_0823B4D8:
	adds r1, r4, #0
	adds r1, #8
	adds r2, r4, #0
	adds r2, #0x10
	ldrh r3, [r4, #0x1c]
	ldrh r0, [r4, #0x1e]
	str r0, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_0823349c
	b _0823B520
_0823B4F2:
	ldrh r0, [r4, #0x10]
	ldrh r2, [r4, #8]
	adds r0, r0, r2
	movs r1, #0
	strh r0, [r4, #8]
	ldrh r0, [r4, #0x14]
	ldrh r2, [r4, #0xa]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	strh r1, [r4, #0xc]
	b _0823B520
_0823B508:
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r4, #8]
	ldrh r0, [r4, #0x12]
	ldrh r2, [r4, #0xa]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0x14]
	ldrh r1, [r4, #0xc]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
_0823B520:
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0823B52E
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_0823B52E:
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
