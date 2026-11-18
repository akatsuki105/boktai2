	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r5, _081B199C @ =0x0000046D
	adds r2, r4, r5
	ldrb r0, [r2]
	cmp r0, #0
	beq _081B19A0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081B19A2
	.align 2, 0
_081B199C: .4byte 0x0000046D
_081B19A0:
	movs r0, #0
_081B19A2:
	cmp r0, #0
	bne _081B1A2C
	movs r2, #2
	ldr r0, _081B19BC @ =0x0000065C
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081B19C0
	movs r0, #1
	b _081B19C2
	.align 2, 0
_081B19BC: .4byte 0x0000065C
_081B19C0:
	movs r0, #0
_081B19C2:
	cmp r0, #0
	beq _081B1A24
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _081B1A18 @ =0x0000FFFF
	cmp r1, r0
	bls _081B19DC
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
_081B19DC:
	adds r0, r4, #0
	bl BokuLink_RouteAwayFromPlayer
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r0, [r5]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r5]
	movs r1, #0xf
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _081B1A1C @ =0x0000046A
	adds r0, r4, r2
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	ldr r0, _081B1A20 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _081B1A2C
	.align 2, 0
_081B1A18: .4byte 0x0000FFFF
_081B1A1C: .4byte 0x0000046A
_081B1A20: .4byte 0x0000046C
_081B1A24:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
_081B1A2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
