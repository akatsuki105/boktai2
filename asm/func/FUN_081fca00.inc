	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCA34
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Boss_PlayAnimFacing
_081FCA34:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081FCAFC
	adds r0, r4, #0
	adds r0, #0x4d
	add r3, sp, #0xc
	ldrb r5, [r0]
	movs r6, #0x5a
	rsbs r6, r6, #0
	ldr r2, _081FCA74 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCA78
	asrs r1, r0, #0xc
	b _081FCA7E
	.align 2, 0
_081FCA74: .4byte gSineTable
_081FCA78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FCA7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCA96
	asrs r0, r0, #0xc
	b _081FCA9C
_081FCA96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FCA9C:
	strh r0, [r3, #4]
	add r3, sp, #0xc
	adds r2, r4, #0
	adds r2, #0x50
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _081FCAE8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FCAEC @ =0x000003FF
	ands r0, r1
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FCAF0 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCAF4
	adds r0, r4, #0
	movs r1, #0xb4
	bl FUN_081fad7c
	b _081FCAFC
	.align 2, 0
_081FCAE8: .4byte 0x030046B8
_081FCAEC: .4byte 0x000003FF
_081FCAF0: .4byte 0x0203B400
_081FCAF4:
	adds r0, r4, #0
	movs r1, #0x96
	bl FUN_081fabc0
_081FCAFC:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	adds r0, r4, #0
	bl Boss_AdvanceAnim
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
