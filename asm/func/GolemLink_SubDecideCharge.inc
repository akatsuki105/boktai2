	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081BFCEC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BFCF0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BFCF2
	.align 2, 0
_081BFCEC: .4byte 0x0000046C
_081BFCF0:
	movs r0, #0
_081BFCF2:
	cmp r0, #0
	beq _081BFCFE
	ldr r3, _081BFD2C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_081BFCFE:
	adds r0, r6, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BFD0C
	b _081BFF1A
_081BFD0C:
	ldr r5, _081BFD2C @ =0x0000046B
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BFD18
	b _081BFF10
_081BFD18:
	adds r3, r4, #0
	ldr r0, _081BFD30 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BFD34
	movs r0, #1
	b _081BFD36
	.align 2, 0
_081BFD2C: .4byte 0x0000046B
_081BFD30: .4byte 0x030047A4
_081BFD34:
	movs r0, #0
_081BFD36:
	cmp r0, #0
	beq _081BFD64
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldr r1, [r0]
	cmp r1, #0
	beq _081BFD74
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BFD52
	adds r2, r0, #0
_081BFD52:
	cmp r2, #0
	blt _081BFD74
	ldr r1, _081BFD60 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081BFD66
	.align 2, 0
_081BFD60: .4byte 0x03002BE0
_081BFD64:
	ldr r0, _081BFDDC @ =0x03002BE0
_081BFD66:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BFDB2
_081BFD74:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BFDB2
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _081BFD98
	movs r0, #0
_081BFD98:
	ldr r7, _081BFDE0 @ =0x000006BC
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
	bls _081BFDB2
	strh r2, [r1]
_081BFDB2:
	adds r3, r4, #0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r3, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _081BFEA4
	movs r2, #0
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r3, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _081BFDE8
	ldr r1, _081BFDE0 @ =0x000006BC
	adds r0, r3, r1
	ldrh r1, [r0]
	ldr r0, _081BFDE4 @ =0x0000018F
	cmp r1, r0
	bls _081BFDF4
	b _081BFDF8
	.align 2, 0
_081BFDDC: .4byte 0x03002BE0
_081BFDE0: .4byte 0x000006BC
_081BFDE4: .4byte 0x0000018F
_081BFDE8:
	ldr r5, _081BFE84 @ =0x000006BC
	adds r0, r3, r5
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _081BFDF4
	movs r2, #1
_081BFDF4:
	cmp r2, #0
	beq _081BFE2C
_081BFDF8:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r3, r7
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081BFE2C
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
	bne _081BFE2E
_081BFE2C:
	movs r1, #0
_081BFE2E:
	cmp r1, #0
	beq _081BFEA4
	ldr r2, _081BFE88 @ =GolemLink_StateCharge
	movs r1, #0x27
	ldr r5, _081BFE8C @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081BFE90 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _081BFE94 @ =0x00000553
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
	ldr r1, _081BFE98 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081BFE9C @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081BFEA0 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081BFF1A
	.align 2, 0
_081BFE84: .4byte 0x000006BC
_081BFE88: .4byte GolemLink_StateCharge
_081BFE8C: .4byte 0x0000046D
_081BFE90: .4byte 0x0000046B
_081BFE94: .4byte 0x00000553
_081BFE98: .4byte 0x00000469
_081BFE9C: .4byte 0x0000046A
_081BFEA0: .4byte 0x00000484
_081BFEA4:
	ldr r2, _081BFEF4 @ =GolemLink_StateRoll
	movs r1, #0x22
	ldr r3, _081BFEF8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081BFEFC @ =0x0000046B
	adds r0, r6, r5
	strb r3, [r0]
	ldr r7, _081BFF00 @ =0x00000553
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
	ldr r1, _081BFF04 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081BFF08 @ =0x00000484
	adds r0, r6, r2
	str r3, [r0]
	ldr r3, _081BFF0C @ =0x0000046C
	adds r0, r6, r3
	strb r4, [r0]
	b _081BFF1A
	.align 2, 0
_081BFEF4: .4byte GolemLink_StateRoll
_081BFEF8: .4byte 0x0000046D
_081BFEFC: .4byte 0x0000046B
_081BFF00: .4byte 0x00000553
_081BFF04: .4byte 0x0000046A
_081BFF08: .4byte 0x00000484
_081BFF0C: .4byte 0x0000046C
_081BFF10:
	ldr r4, _081BFF20 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BFF1A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BFF20: .4byte 0x00000484
