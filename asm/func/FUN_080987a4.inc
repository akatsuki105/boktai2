	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080987E8
	ldr r0, _080987E0 @ =0x00003FF0
	adds r2, r6, r0
	movs r0, #8
	strb r0, [r2]
	ldr r0, _080987E4 @ =0x00003FF1
	adds r1, r6, r0
	movs r0, #9
	strb r0, [r1]
	movs r4, #2
	movs r3, #0xff
_080987D0:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xf
	ble _080987D0
	b _08098892
	.align 2, 0
_080987E0: .4byte 0x00003FF0
_080987E4: .4byte 0x00003FF1
_080987E8:
	movs r5, #0
	movs r4, #0
_080987EC:
	adds r0, r4, #0
	subs r0, #8
	cmp r0, #1
	bls _08098808
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _08098808
	ldr r1, _08098898 @ =0x00003FF0
	adds r0, r6, r1
	adds r0, r0, r5
	strb r4, [r0]
	adds r5, #1
_08098808:
	adds r4, #1
	cmp r4, #9
	ble _080987EC
	cmp r5, #7
	bgt _08098826
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_08098818:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #7
	ble _08098818
_08098826:
	movs r5, #8
	movs r4, #0xa
	ldr r1, _08098898 @ =0x00003FF0
	adds r7, r6, r1
_0809882E:
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _0809883E
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
_0809883E:
	adds r4, #1
	cmp r4, #0xd
	ble _0809882E
	cmp r5, #0xb
	bgt _0809885C
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_0809884E:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #0xb
	ble _0809884E
_0809885C:
	movs r5, #0xc
	movs r4, #0xe
	ldr r1, _08098898 @ =0x00003FF0
	adds r7, r6, r1
_08098864:
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _08098874
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
_08098874:
	adds r4, #1
	cmp r4, #0x11
	ble _08098864
	cmp r5, #0xf
	bgt _08098892
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_08098884:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #0xf
	ble _08098884
_08098892:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098898: .4byte 0x00003FF0
