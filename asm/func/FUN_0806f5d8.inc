	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0806F626
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #1
	bls _0806F614
	ldr r0, _0806F610 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080a8ff8
	ldrh r0, [r5]
	subs r0, #2
	strh r0, [r5]
	b _0806F61C
	.align 2, 0
_0806F610: .4byte 0x000003FA
_0806F614:
	ldr r0, _0806F63C @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0806F61C:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_08060b84
_0806F626:
	ldr r1, _0806F640 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0806F6A4
	cmp r0, #1
	bgt _0806F644
	cmp r0, #0
	beq _0806F64E
	b _0806F730
	.align 2, 0
_0806F63C: .4byte 0x000003FA
_0806F640: .4byte 0x0000037D
_0806F644:
	cmp r0, #2
	beq _0806F6DC
	cmp r0, #3
	beq _0806F718
	b _0806F730
_0806F64E:
	ldr r0, _0806F68C @ =0x000003FA
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F66A
	ldr r0, _0806F690 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F694 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F66A:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F730
	ldrb r0, [r5]
	cmp r0, #0
	beq _0806F698
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_08060b84
	b _0806F730
	.align 2, 0
_0806F68C: .4byte 0x000003FA
_0806F690: .4byte 0x0000095E
_0806F694: .4byte 0x00000123
_0806F698:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_08060b84
	b _0806F730
_0806F6A4:
	ldr r1, _0806F6CC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806F6C0
	ldr r0, _0806F6D0 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _0806F6D4 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_0806F6C0:
	ldr r0, _0806F6D8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806F6FE
	.align 2, 0
_0806F6CC: .4byte 0x000003FA
_0806F6D0: .4byte 0x0000095E
_0806F6D4: .4byte 0x00000123
_0806F6D8: .4byte 0x0000037E
_0806F6DC:
	ldr r1, _0806F714 @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806F6EE
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806F6EE:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_08060a24
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0806F6FE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0806F730
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_08060b84
	b _0806F730
	.align 2, 0
_0806F714: .4byte 0x0000037E
_0806F718:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F730
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_0806F730:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
