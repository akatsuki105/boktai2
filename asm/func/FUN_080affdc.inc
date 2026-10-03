	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B0060 @ =0x00000692
	adds r5, r4, r0
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_080af4a4
	cmp r0, #0
	beq _080B0086
	ldr r2, _080B0064 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0068 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B006C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r1, r0, #3
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080B0032
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r3, _080B0070 @ =0x0000069C
	adds r2, r4, r3
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
_080B0032:
	ldr r0, _080B0074 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080B0078
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af4d4
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B0094
	.align 2, 0
_080B0060: .4byte 0x00000692
_080B0064: .4byte 0x030046B8
_080B0068: .4byte 0x000003FF
_080B006C: .4byte 0x0203B400
_080B0070: .4byte 0x0000069C
_080B0074: .4byte 0x0000067A
_080B0078:
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af51c
	b _080B0094
_080B0086:
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B0094:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
