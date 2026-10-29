	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080CC870
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	bne _080CC7A2
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CC7B6
_080CC7A2:
	movs r4, #0xd0
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _080CC8CC
_080CC7B6:
	ldr r1, _080CC7E4 @ =0x000006A9
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	ldr r2, _080CC7E8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC7EC
	asrs r1, r0, #0xc
	b _080CC7F2
	.align 2, 0
_080CC7E4: .4byte 0x000006A9
_080CC7E8: .4byte gSineTable
_080CC7EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CC7F2:
	ldrh r0, [r5, #0x2c]
	adds r0, r0, r1
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r1, r5, r4
	strh r0, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC812
	asrs r0, r0, #0xc
	b _080CC818
_080CC812:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC818:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r4, [r5, #0x2e]
	adds r0, r0, r4
	ldr r4, _080CC848 @ =0x0000069A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC84C
	asrs r2, r0, #0xc
	b _080CC852
	.align 2, 0
_080CC848: .4byte 0x0000069A
_080CC84C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CC852:
	ldrh r0, [r5, #0x30]
	subs r0, r0, r2
	ldr r4, _080CC868 @ =0x0000069C
	adds r1, r5, r4
	strh r0, [r1]
	ldr r0, _080CC86C @ =0x000006A9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080CC8CC
	.align 2, 0
_080CC868: .4byte 0x0000069C
_080CC86C: .4byte 0x000006A9
_080CC870:
	ldr r7, [r5, #0x1c]
	cmp r7, #1
	bne _080CC8CC
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080CC8CC
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x38
	movs r4, #0
	strh r0, [r2]
	ldr r0, _080CC8D4 @ =0x0000069A
	adds r1, r5, r0
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r2, _080CC8D8 @ =0x0000067C
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0x10
	bl Particle_SetPose
	ldr r1, _080CC8DC @ =0x000006A9
	adds r0, r5, r1
	strb r4, [r0]
	strb r7, [r6]
_080CC8CC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC8D4: .4byte 0x0000069A
_080CC8D8: .4byte 0x0000067C
_080CC8DC: .4byte 0x000006A9
