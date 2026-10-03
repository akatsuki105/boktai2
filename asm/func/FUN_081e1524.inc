	push {lr}
	adds r3, r1, #0
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _081E1532
	movs r0, #0
	strb r0, [r3, #4]
_081E1532:
	ldrb r0, [r3, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E1560
	strb r2, [r3, #2]
	ldrb r0, [r3, #3]
	adds r0, #1
	strb r0, [r3, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1554
	strb r2, [r3, #3]
_081E1554:
	ldrb r1, [r3, #3]
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _081E155E
	adds r1, #4
_081E155E:
	strh r1, [r3, #0x34]
_081E1560:
	ldr r2, _081E157C @ =0x085B0A08
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081E1580
	asrs r1, r0, #0xc
	b _081E1586
	.align 2, 0
_081E157C: .4byte 0x085B0A08
_081E1580:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E1586:
	ldrh r0, [r3, #0x12]
	adds r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r0, [r3, #6]
	adds r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _081E15AA
	ldr r0, _081E15B0 @ =FUN_081e15b4
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
_081E15AA:
	pop {r0}
	bx r0
	.align 2, 0
_081E15B0: .4byte FUN_081e15b4
