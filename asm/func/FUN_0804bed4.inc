	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804BF8A
	ldr r1, _0804BF3C @ =0x030057F0
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	cmp r0, #0x26
	bne _0804BF48
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r0, [r4, #0x22]
	ldr r2, _0804BF40 @ =0x0000FFFD
	ands r2, r0
	strh r2, [r4, #0x22]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0804BF24
	movs r1, #0x80
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804BF24:
	ldrh r1, [r4, #0x22]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0804BF7C
	ldr r0, _0804BF44 @ =0x0000FFF7
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4, #0x22]
	b _0804BF7C
	.align 2, 0
_0804BF3C: .4byte 0x030057F0
_0804BF40: .4byte 0x0000FFFD
_0804BF44: .4byte 0x0000FFF7
_0804BF48:
	cmp r0, #0x27
	bne _0804BF7C
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r2, #0
	strh r2, [r4, #0x22]
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BF7C
	movs r0, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r2, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804BF7C:
	cmp r5, #0
	beq _0804BF8A
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r5, r0
	strb r5, [r1]
_0804BF8A:
	pop {r4, r5}
	pop {r0}
	bx r0
