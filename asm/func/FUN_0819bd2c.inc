	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0819BD4C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BD50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BD52
	.align 2, 0
_0819BD4C: .4byte 0x0000046D
_0819BD50:
	movs r0, #0
_0819BD52:
	cmp r0, #0
	beq _0819BD72
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r2, #4
	ldr r0, _0819BD84 @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0819BD88 @ =0x0000016B
	bl PlaySound_082406e0
_0819BD72:
	ldr r2, [r5, #0x44]
	ldrb r0, [r2, #8]
	movs r1, #8
	ldrsb r1, [r2, r1]
	cmp r1, #0x20
	ble _0819BD8C
	subs r0, #4
	strb r0, [r2, #8]
	b _0819BE04
	.align 2, 0
_0819BD84: .4byte 0x00000E48
_0819BD88: .4byte 0x0000016B
_0819BD8C:
	cmp r1, #8
	ble _0819BDA8
	subs r0, #2
	strb r0, [r2, #8]
	ldr r1, [r5, #0x44]
	ldrb r0, [r1, #9]
	adds r0, #4
	strb r0, [r1, #9]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _0819BE04
_0819BDA8:
	ldrb r1, [r2, #9]
	movs r0, #9
	ldrsb r0, [r2, r0]
	cmp r0, #0x77
	bgt _0819BDC4
	adds r0, r1, #0
	adds r0, #8
	strb r0, [r2, #9]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r5, r2
	bl ParticleShadow_Hide
	b _0819BE04
_0819BDC4:
	movs r1, #1
	str r1, [r2]
	ldr r4, _0819BE0C @ =FUN_0819be1c
	movs r3, #0x23
	ldr r2, _0819BE10 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0819BE14 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r5, r2
	bl ParticleShadow_Hide
	movs r2, #0x40
	ldr r0, _0819BE18 @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0819BE04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819BE0C: .4byte FUN_0819be1c
_0819BE10: .4byte 0x0000046D
_0819BE14: .4byte 0x0000046B
_0819BE18: .4byte 0x00000E48
