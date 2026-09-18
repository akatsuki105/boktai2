	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FB20 @ =gClock
	ldrh r0, [r5, #0x26]
	ldrb r1, [r1, #0xe]
	cmp r0, r1
	beq _0800FA98
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0x1e
	bl FUN_0823ce10
	movs r0, #0
	strh r0, [r5, #0x20]
_0800FA98:
	ldrh r0, [r5, #0x20]
	cmp r0, #0x3f
	bhi _0800FACE
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FABC
	adds r4, r5, #0
	adds r4, #0x28
_0800FAAA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAAA
_0800FABC:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0800FACE
	movs r0, #0x40
	strh r0, [r5, #0x20]
_0800FACE:
	ldr r1, _0800FB24 @ =0x03004044
	ldr r0, _0800FB28 @ =0x03004458
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800FB2C @ =0x03004450
	movs r0, #0
	str r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FB0C
	adds r2, r1, #0
	adds r7, r5, #0
	adds r7, #0x2c
	adds r4, r5, #0
	adds r4, #0x28
_0800FAEE:
	ldrh r0, [r4, #2]
	adds r1, r7, #0
	str r2, [sp]
	bl FUN_0822d190
	ldr r2, [sp]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	adds r7, #0x30
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAEE
_0800FB0C:
	ldr r0, _0800FB20 @ =gClock
	ldrb r1, [r0, #0xf]
	strh r1, [r5, #0x24]
	ldrb r0, [r0, #0xe]
	strh r0, [r5, #0x26]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FB20: .4byte gClock
_0800FB24: .4byte 0x03004044
_0800FB28: .4byte 0x03004458
_0800FB2C: .4byte 0x03004450
