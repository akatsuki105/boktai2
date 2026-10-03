	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080AFA50 @ =0x0000068A
	adds r1, r5, r0
	movs r0, #0x10
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFA54
	asrs r1, r0, #2
	b _080AFA5A
	.align 2, 0
_080AFA50: .4byte 0x0000068A
_080AFA54:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFA5A:
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080AFAA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFAAC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _080AFAB0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r0, _080AFAB4 @ =0x00000672
	adds r2, r5, r0
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x80
	ldrh r0, [r2]
	adds r0, r0, r1
	ldr r2, _080AFAB8 @ =0x0000061A
	adds r1, r5, r2
	strh r0, [r1]
	ldr r4, _080AFABC @ =0x0000061C
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #0x58
	adds r0, r5, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFAC0
	asrs r1, r0, #2
	b _080AFAC6
	.align 2, 0
_080AFAA8: .4byte 0x030046B8
_080AFAAC: .4byte 0x000003FF
_080AFAB0: .4byte 0x0203B400
_080AFAB4: .4byte 0x00000672
_080AFAB8: .4byte 0x0000061A
_080AFABC: .4byte 0x0000061C
_080AFAC0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFAC6:
	ldr r2, _080AFB40 @ =0x0000061C
	adds r0, r5, r2
	strh r1, [r0]
	ldr r4, _080AFB44 @ =0x0000067A
	adds r1, r5, r4
	ldrh r0, [r1]
	ldr r2, _080AFB48 @ =0x0000012B
	cmp r0, r2
	bhi _080AFADC
	adds r0, #1
	strh r0, [r1]
_080AFADC:
	ldrh r0, [r1]
	cmp r0, #0x3b
	bls _080AFBC4
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFB9C
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFB4C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080AFB50 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0x96
	lsls r4, r4, #1
	adds r1, r4, #0
	bl Mod
	adds r0, r0, r4
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_080af53c
	ldr r2, _080AFB54 @ =0x00000692
	adds r4, r5, r2
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFBC4
	adds r0, r5, #0
	bl FUN_080af400
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080AFB5C
	ldr r3, _080AFB58 @ =0x0000067C
	adds r1, r5, r3
	movs r0, #0xf0
	lsls r0, r0, #3
	b _080AFB8C
	.align 2, 0
_080AFB40: .4byte 0x0000061C
_080AFB44: .4byte 0x0000067A
_080AFB48: .4byte 0x0000012B
_080AFB4C: .4byte 0x000003FF
_080AFB50: .4byte 0x0203B400
_080AFB54: .4byte 0x00000692
_080AFB58: .4byte 0x0000067C
_080AFB5C:
	cmp r0, #1
	bne _080AFB70
	ldr r4, _080AFB6C @ =0x0000067C
	adds r1, r5, r4
	movs r0, #0xf8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB6C: .4byte 0x0000067C
_080AFB70:
	cmp r0, #2
	bne _080AFB84
	ldr r0, _080AFB80 @ =0x0000067C
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB80: .4byte 0x0000067C
_080AFB84:
	ldr r2, _080AFB98 @ =0x0000067C
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #3
_080AFB8C:
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFBC4
	.align 2, 0
_080AFB98: .4byte 0x0000067C
_080AFB9C:
	ldrh r0, [r1]
	cmp r0, r2
	bls _080AFBC4
	adds r0, r5, #0
	bl FUN_080af5b8
	ldr r3, _080AFBCC @ =0x00000686
	adds r1, r5, r3
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r4, #0xd1
	lsls r4, r4, #3
	adds r1, r5, r4
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080af374
_080AFBC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBCC: .4byte 0x00000686
