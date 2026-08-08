	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r2, #0
	ldr r0, _0822D178 @ =0x03004458
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r2, r1
	bge _0822D150
	adds r3, r1, #0
	ldr r1, _0822D17C @ =0x03004470
_0822D142:
	ldrh r0, [r1]
	cmp r0, r4
	beq _0822D184
	adds r1, #2
	adds r2, #1
	cmp r2, r3
	blt _0822D142
_0822D150:
	ldr r2, [r5]
	cmp r2, #1
	bgt _0822D188
	ldr r1, _0822D17C @ =0x03004470
	lsls r0, r2, #1
	adds r0, r0, r1
	strh r4, [r0]
	lsls r1, r2, #5
	ldr r0, _0822D180 @ =gObjectPlttBuffer
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, [r5]
	adds r0, r1, #0
	adds r1, #1
	str r1, [r5]
	b _0822D18A
	.align 2, 0
_0822D178: .4byte 0x03004458
_0822D17C: .4byte 0x03004470
_0822D180: .4byte gObjectPlttBuffer
_0822D184:
	adds r0, r2, #0
	b _0822D18A
_0822D188:
	movs r0, #0
_0822D18A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
