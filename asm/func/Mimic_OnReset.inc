	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _08147A64 @ =0x0000068E
	adds r0, r3, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	ldr r0, _08147A68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08147A6C
	movs r0, #1
	b _08147A6E
	.align 2, 0
_08147A64: .4byte 0x0000068E
_08147A68: .4byte 0x030047A4
_08147A6C:
	movs r0, #0
_08147A6E:
	cmp r0, #0
	beq _08147AC8
	ldr r0, _08147AA8 @ =0x00000684
	adds r2, r3, r0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08147AA2
	cmp r1, #0
	blt _08147AA2
	ldr r0, _08147AAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08147AA2
	ldr r0, _08147AB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08147AB4
_08147AA2:
	movs r1, #0
	b _08147AC2
	.align 2, 0
_08147AA8: .4byte 0x00000684
_08147AAC: .4byte 0x030046A8
_08147AB0: .4byte 0x030046AC
_08147AB4:
	ldr r0, _08147B0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08147AC2:
	ldr r2, _08147B10 @ =0x0000068C
	adds r0, r3, r2
	strh r1, [r0]
_08147AC8:
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnimNoFacingFlags
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08147B14
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08147B1C
	.align 2, 0
_08147B0C: .4byte 0x030046A4
_08147B10: .4byte 0x0000068C
_08147B14:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08147B1C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08147B40
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08147B48
_08147B40:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08147B48:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08147B80 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08147BB8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08147B84
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08147B78
	ldrb r0, [r4, #5]
_08147B78:
	subs r0, #1
	strh r0, [r4, #8]
	b _08147B94
	.align 2, 0
_08147B80: .4byte 0x0000FFFF
_08147B84:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08147B94
	strh r1, [r4, #8]
_08147B94:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147BB8
	movs r0, #1
	strb r0, [r4, #7]
_08147BB8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
