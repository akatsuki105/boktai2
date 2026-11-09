	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0811EE14 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811EE18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811EE1A
	.align 2, 0
_0811EE14: .4byte 0x0000046C
_0811EE18:
	movs r0, #0
_0811EE1A:
	cmp r0, #0
	beq _0811EE26
	ldr r3, _0811EE54 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_0811EE26:
	adds r0, r6, #0
	bl Golem_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811EE34
	b _0811F042
_0811EE34:
	ldr r5, _0811EE54 @ =0x0000046B
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811EE40
	b _0811F038
_0811EE40:
	adds r3, r4, #0
	ldr r0, _0811EE58 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811EE5C
	movs r0, #1
	b _0811EE5E
	.align 2, 0
_0811EE54: .4byte 0x0000046B
_0811EE58: .4byte 0x030047A4
_0811EE5C:
	movs r0, #0
_0811EE5E:
	cmp r0, #0
	beq _0811EE8C
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r1, [r0]
	cmp r1, #0
	beq _0811EE9C
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811EE7A
	adds r2, r0, #0
_0811EE7A:
	cmp r2, #0
	blt _0811EE9C
	ldr r1, _0811EE88 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _0811EE8E
	.align 2, 0
_0811EE88: .4byte 0x03002BE0
_0811EE8C:
	ldr r0, _0811EF04 @ =0x03002BE0
_0811EE8E:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811EEDA
_0811EE9C:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811EEDA
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _0811EEC0
	movs r0, #0
_0811EEC0:
	ldr r7, _0811EF08 @ =0x000006BC
	adds r1, r4, r7
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _0811EEDA
	strh r2, [r1]
_0811EEDA:
	adds r3, r4, #0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _0811EFCC
	movs r2, #0
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811EF10
	ldr r1, _0811EF08 @ =0x000006BC
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _0811EF0C @ =0x0000018F
	cmp r1, r0
	bls _0811EF1C
	b _0811EF20
	.align 2, 0
_0811EF04: .4byte 0x03002BE0
_0811EF08: .4byte 0x000006BC
_0811EF0C: .4byte 0x0000018F
_0811EF10:
	ldr r5, _0811EFAC @ =0x000006BC
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811EF1C
	movs r2, #1
_0811EF1C:
	cmp r2, #0
	beq _0811EF54
_0811EF20:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r3, r7
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811EF54
	adds r0, r4, #0
	adds r0, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811EF56
_0811EF54:
	movs r1, #0
_0811EF56:
	cmp r1, #0
	beq _0811EFCC
	ldr r2, _0811EFB0 @ =Golem_StateCharge
	movs r1, #0x27
	ldr r5, _0811EFB4 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _0811EFB8 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _0811EFBC @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811EFC0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811EFC4 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811EFC8 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0811F042
	.align 2, 0
_0811EFAC: .4byte 0x000006BC
_0811EFB0: .4byte Golem_StateCharge
_0811EFB4: .4byte 0x0000046D
_0811EFB8: .4byte 0x0000046B
_0811EFBC: .4byte 0x00000553
_0811EFC0: .4byte 0x00000469
_0811EFC4: .4byte 0x0000046A
_0811EFC8: .4byte 0x00000484
_0811EFCC:
	ldr r2, _0811F01C @ =Golem_StateRoll
	movs r1, #0x22
	ldr r3, _0811F020 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0811F024 @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _0811F028 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0811F02C @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0811F030 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	ldr r3, _0811F034 @ =0x0000046C
	adds r0, r6, r3
	strb r4, [r0]
	b _0811F042
	.align 2, 0
_0811F01C: .4byte Golem_StateRoll
_0811F020: .4byte 0x0000046D
_0811F024: .4byte 0x0000046B
_0811F028: .4byte 0x00000553
_0811F02C: .4byte 0x0000046A
_0811F030: .4byte 0x00000484
_0811F034: .4byte 0x0000046C
_0811F038:
	ldr r4, _0811F048 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811F042:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F048: .4byte 0x00000484
