	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r4, _080C0294 @ =0x03002BE0
	ldr r3, [r4]
	ldr r0, _080C0298 @ =0x0000037D
	adds r5, r3, r0
	ldrb r2, [r5]
	cmp r2, #0
	beq _080C025E
	b _080C03F0
_080C025E:
	ldr r2, _080C029C @ =0x00000594
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080bfba4
	movs r5, #0
	ldr r2, [r4]
	ldr r1, _080C02A0 @ =0x0000042E
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r1, #3
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2, #0x2c]
	ldr r1, [r4]
	movs r4, #0x2c
	ldrsh r2, [r1, r4]
	ldr r0, _080C02A4 @ =0x0000037F
	cmp r2, r0
	bgt _080C02A8
	adds r0, #1
	strh r0, [r1, #0x2c]
	b _080C02B2
	.align 2, 0
_080C0294: .4byte 0x03002BE0
_080C0298: .4byte 0x0000037D
_080C029C: .4byte 0x00000594
_080C02A0: .4byte 0x0000042E
_080C02A4: .4byte 0x0000037F
_080C02A8:
	ldr r0, _080C030C @ =0x000003FF
	cmp r2, r0
	ble _080C02B2
	strh r0, [r1, #0x2c]
	movs r5, #1
_080C02B2:
	cmp r5, #0
	beq _080C032C
	ldr r0, _080C0310 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0314 @ =0x0000037D
	adds r0, r0, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	ldr r2, _080C0318 @ =0x0000057E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080C031C @ =0x0000023A
	bl sound_08240740
	ldr r0, _080C0320 @ =0x0000023B
	bl sound_08240740
	movs r0, #0x8f
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _080C0324 @ =0x0000023D
	bl sound_08240740
	ldr r1, _080C0328 @ =0x0000057C
	adds r0, r6, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r6, r4
	strh r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Sound_SetBGMTempo
	bl FUN_080bfa74
	b _080C03C8
	.align 2, 0
_080C030C: .4byte 0x000003FF
_080C0310: .4byte 0x03002BE0
_080C0314: .4byte 0x0000037D
_080C0318: .4byte 0x0000057E
_080C031C: .4byte 0x0000023A
_080C0320: .4byte 0x0000023B
_080C0324: .4byte 0x0000023D
_080C0328: .4byte 0x0000057C
_080C032C:
	adds r0, r6, #0
	bl FUN_080bfd24
	adds r0, r6, #0
	bl FUN_080c00d4
	adds r4, r0, #0
	ldr r0, _080C036C @ =0x0000059C
	adds r1, r6, r0
	ldr r0, [r1]
	adds r3, r0, r4
	str r3, [r1]
	ldr r0, _080C0370 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, r4
	bge _080C0378
	str r5, [r1]
	ldr r4, _080C0374 @ =0x0000057A
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C03C8
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C036C: .4byte 0x0000059C
_080C0370: .4byte 0x030046A0
_080C0374: .4byte 0x0000057A
_080C0378:
	ldr r1, _080C03A0 @ =0x00000594
	adds r0, r6, r1
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blt _080C03A4
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r3, r0
	blt _080C03A4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080c01ac
	b _080C03C8
	.align 2, 0
_080C03A0: .4byte 0x00000594
_080C03A4:
	ldr r0, _080C03E4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080C03E8 @ =0x0000042E
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	bl Sound_SetBGMTempo
	ldr r0, _080C03EC @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, r0, r4
	str r0, [r1]
_080C03C8:
	adds r0, r6, #0
	bl FUN_080bfc60
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #1
	bls _080C04AE
	lsls r0, r0, #2
	bl FUN_0823b9cc
	b _080C04AE
	.align 2, 0
_080C03E4: .4byte 0x03002BE0
_080C03E8: .4byte 0x0000042E
_080C03EC: .4byte 0x030046A0
_080C03F0:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r1, _080C0418 @ =0xFFFFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _080C0420
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C041C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	b _080C0472
	.align 2, 0
_080C0418: .4byte 0xFFFFFF00
_080C041C: .4byte 0x00001FFF
_080C0420:
	cmp r2, #3
	bne _080C048C
	ldr r2, _080C047C @ =0x0000037E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r3, #0
	movs r2, #4
	strb r2, [r5]
	ldr r0, [r4]
	ldr r1, _080C047C @ =0x0000037E
	adds r0, r0, r1
	strh r3, [r0]
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r1, #0x2c]
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #0x2e]
	ldr r1, [r4]
	movs r0, #0xb0
	lsls r0, r0, #3
	strh r0, [r1, #0x30]
	ldr r0, [r4]
	ldr r1, _080C0480 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r4]
	ldr r4, _080C0484 @ =0x000002E7
	adds r0, r0, r4
	strb r1, [r0]
	str r2, [sp]
	ldr r0, _080C0488 @ =0x00001FFF
	str r0, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	movs r1, #5
_080C0472:
	movs r3, #4
	bl FUN_0823ce68
	b _080C04AE
	.align 2, 0
_080C047C: .4byte 0x0000037E
_080C0480: .4byte 0x000002E6
_080C0484: .4byte 0x000002E7
_080C0488: .4byte 0x00001FFF
_080C048C:
	cmp r2, #4
	bne _080C04AE
	ldr r1, _080C04D0 @ =0x0000037E
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0x1f
	bls _080C04AE
	movs r0, #0
	strb r0, [r5]
	ldr r1, [r4]
	ldr r2, _080C04D0 @ =0x0000037E
	adds r1, r1, r2
	strh r0, [r1]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r1, r6, r4
	strh r0, [r1]
_080C04AE:
	adds r0, r6, #0
	bl FUN_080bff18
	adds r0, r6, #0
	bl FUN_080bfe50
	ldr r0, _080C04D4 @ =0x0000057A
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C04C8
	subs r0, #1
	strh r0, [r1]
_080C04C8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C04D0: .4byte 0x0000037E
_080C04D4: .4byte 0x0000057A
