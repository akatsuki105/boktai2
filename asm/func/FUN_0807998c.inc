	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080799CC
	ldr r2, _08079A00 @ =0x000003FF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080799CC
	movs r3, #0xf5
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #0x22
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_080799CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r5, r4, r3
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080799F0
	adds r0, r4, #0
	bl FUN_08064db0
	adds r2, r0, #0
_080799F0:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08079A04
	movs r2, #0x18
	b _08079A5C
	.align 2, 0
_08079A00: .4byte 0x000003FF
_08079A04:
	cmp r2, #0x18
	beq _08079A5C
	cmp r2, #0x14
	beq _08079A5C
	cmp r2, #0x13
	beq _08079A5C
	cmp r2, #0x17
	beq _08079A5C
	cmp r2, #4
	beq _08079A5C
	cmp r2, #0xd
	beq _08079A5C
	ldr r2, [r5]
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079A3C
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r2, #4
	cmp r0, #0
	beq _08079A5C
_08079A38:
	movs r2, #0
	b _08079A5C
_08079A3C:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08079A38
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08079A38
	movs r2, #1
_08079A5C:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
