	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0801C724 @ =0x00000B64
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801C728
	movs r0, #0x40
	b _0801C72A
	.align 2, 0
_0801C724: .4byte 0x00000B64
_0801C728:
	movs r0, #0x68
_0801C72A:
	strh r0, [r1, #0x20]
	movs r0, #0x28
	strh r0, [r1, #0x22]
	adds r1, r4, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801C74C
	ldr r1, _0801C748 @ =FUN_0801c9e4
	b _0801C79A
	.align 2, 0
_0801C748: .4byte FUN_0801c9e4
_0801C74C:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r4, r0
	adds r0, r4, #0
	bl FUN_0801b730
	adds r0, r4, #0
	adds r0, #0x3b
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r6, #2]
	adds r5, r0, #0
	cmp r1, #3
	bne _0801C792
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _0801C782
	cmp r0, #1
	bgt _0801C778
	cmp r0, #0
	beq _0801C77E
	b _0801C792
_0801C778:
	cmp r0, #2
	beq _0801C786
	b _0801C792
_0801C77E:
	movs r0, #0x33
	b _0801C788
_0801C782:
	movs r0, #0x35
	b _0801C788
_0801C786:
	movs r0, #0x36
_0801C788:
	bl CheckItemOwn
	cmp r0, #0
	bne _0801C792
	strb r0, [r5]
_0801C792:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801C7A8
	ldr r1, _0801C7A4 @ =FUN_0801ccd4
_0801C79A:
	adds r0, r4, #0
	bl EntityDA0B_SetFn
	b _0801C7B0
	.align 2, 0
_0801C7A4: .4byte FUN_0801ccd4
_0801C7A8:
	ldr r1, _0801C7B8 @ =FUN_0801cf18
	adds r0, r4, #0
	bl EntityDA0B_SetFn
_0801C7B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7B8: .4byte FUN_0801cf18
