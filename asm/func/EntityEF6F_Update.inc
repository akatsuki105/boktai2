	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801F470 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801F438
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_0801e284
_0801F438:
	ldr r1, _0801F474 @ =0x085AA98C
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0801F45C
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r0, [r1]
	cmp r0, #0
	beq _0801F45C
	subs r0, #1
	str r0, [r1]
_0801F45C:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x58]
	movs r1, #0xb0
	lsls r1, r1, #5
	cmp r0, r1
	ble _0801F478
	str r1, [r4, #0x58]
	b _0801F480
	.align 2, 0
_0801F470: .4byte 0x030044E0
_0801F474: .4byte 0x085AA98C
_0801F478:
	cmp r0, #0
	bge _0801F480
	movs r0, #0
	str r0, [r4, #0x58]
_0801F480:
	ldr r0, [r4, #0x58]
	asrs r0, r0, #5
	strh r0, [r4, #0x36]
	ldrb r0, [r4, #0x19]
	cmp r0, #0xc
	bhi _0801F492
	adds r0, r4, #0
	bl FUN_0801e728
_0801F492:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
