	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _0805D138
	b _0805D288
_0805D138:
	bl FUN_08084710
	strb r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	bl FUN_08084734
	ldr r1, [r5, #0x24]
	ldr r0, _0805D188 @ =0x00000257
	cmp r1, r0
	bls _0805D166
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	bne _0805D15E
	movs r0, #1
	strb r0, [r5, #0x1e]
	movs r0, #0xea
	bl PlaySound_082406e0
_0805D15E:
	ldr r0, _0805D18C @ =0x00001684
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
_0805D166:
	ldr r1, _0805D18C @ =0x00001684
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0805D194
	ldr r3, _0805D190 @ =0x00001685
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _0805D1CE
	movs r0, #0x3f
	b _0805D1C8
	.align 2, 0
_0805D188: .4byte 0x00000257
_0805D18C: .4byte 0x00001684
_0805D190: .4byte 0x00001685
_0805D194:
	cmp r0, #1
	bne _0805D1B0
	ldr r4, _0805D1AC @ =0x00001685
	adds r1, r5, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805D1CE
	movs r0, #0
	b _0805D1C8
	.align 2, 0
_0805D1AC: .4byte 0x00001685
_0805D1B0:
	cmp r0, #2
	bne _0805D1CE
	ldr r0, _0805D20C @ =0x00001685
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _0805D1CE
	movs r0, #0x20
_0805D1C8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_0805D1CE:
	ldr r1, _0805D210 @ =0x00001684
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0805D1FE
	ldr r0, _0805D214 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D218 @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805D21C @ =0x00004CA0
	adds r2, r2, r4
	ldr r3, _0805D220 @ =0x00001688
	adds r0, r5, r3
	ldr r4, _0805D20C @ =0x00001685
	adds r3, r5, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl BlendPltt
_0805D1FE:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805D224
	adds r0, r5, #0
	bl Entity0805d364_Finish
	b _0805D288
	.align 2, 0
_0805D20C: .4byte 0x00001685
_0805D210: .4byte 0x00001684
_0805D214: .4byte 0x03003584
_0805D218: .4byte 0x00004C60
_0805D21C: .4byte 0x00004CA0
_0805D220: .4byte 0x00001688
_0805D224:
	movs r7, #0
	movs r0, #0
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x44
	movs r6, #0
	ldr r1, _0805D298 @ =0x085ABA2C
	mov sb, r1
_0805D234:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl Entity0805d364_UpdateElemSprite
	ldrb r0, [r4, #1]
	cmp r0, #7
	bne _0805D254
	adds r7, #1
_0805D254:
	cmp r0, #0xa
	bne _0805D25C
	movs r3, #1
	add r8, r3
_0805D25C:
	adds r6, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #0xf
	ble _0805D234
	ldr r1, [r5, #0x24]
	cmp r7, #0x10
	beq _0805D27A
	mov r3, r8
	cmp r3, #0x10
	beq _0805D27A
	ldr r0, _0805D29C @ =0x000004AF
	cmp r1, r0
	bls _0805D284
_0805D27A:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _0805D284
	movs r0, #1
	strb r0, [r5, #0x1d]
_0805D284:
	adds r0, r1, #1
	str r0, [r5, #0x24]
_0805D288:
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D298: .4byte 0x085ABA2C
_0805D29C: .4byte 0x000004AF
