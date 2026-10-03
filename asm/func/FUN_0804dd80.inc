	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804DE10
	ldr r7, _0804DDC8 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0804DDD0
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DDB8
	adds r0, r4, #0
	adds r0, #0xb8
	bl _call_via_r1
_0804DDB8:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	ldrh r1, [r4, #0x22]
	ldr r0, _0804DDCC @ =0x0000FFFD
	ands r0, r1
	b _0804DE00
	.align 2, 0
_0804DDC8: .4byte 0x030057F0
_0804DDCC: .4byte 0x0000FFFD
_0804DDD0:
	cmp r0, #0x27
	bne _0804DE02
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DDE4
	bl _call_via_r0
_0804DDE4:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	movs r0, #0
_0804DE00:
	strh r0, [r4, #0x22]
_0804DE02:
	cmp r6, #0
	beq _0804DE10
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r6, r0
	strb r6, [r1]
_0804DE10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
