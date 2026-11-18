	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r5, [r7, #0x44]
	ldr r0, _0819CC24 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CC28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CC2A
	.align 2, 0
_0819CC24: .4byte 0x0000046D
_0819CC28:
	movs r0, #0
_0819CC2A:
	cmp r0, #0
	beq _0819CC3E
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldr r0, _0819CC4C @ =0x00000EAB
	adds r1, r6, r0
	movs r0, #0x1e
	strb r0, [r1]
_0819CC3E:
	ldrb r2, [r5, #6]
	cmp r2, #0x80
	ble _0819CC54
	ldr r1, _0819CC50 @ =0xFFFFFF00
	adds r2, r2, r1
	b _0819CC62
	.align 2, 0
_0819CC4C: .4byte 0x00000EAB
_0819CC50: .4byte 0xFFFFFF00
_0819CC54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0819CC62
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
_0819CC62:
	cmp r2, #0
	ble _0819CC7C
	ldr r1, _0819CC78 @ =0x00000EAB
	adds r4, r6, r1
	ldrb r1, [r4]
	adds r0, r2, #0
	bl Div
	ldrb r1, [r5, #6]
	subs r1, r1, r0
	b _0819CC92
	.align 2, 0
_0819CC78: .4byte 0x00000EAB
_0819CC7C:
	adds r0, r2, #0
	cmp r0, #0
	bge _0819CC84
	rsbs r0, r0, #0
_0819CC84:
	ldr r1, _0819CCC0 @ =0x00000EAB
	adds r4, r6, r1
	ldrb r1, [r4]
	bl Div
	ldrb r1, [r5, #6]
	adds r1, r1, r0
_0819CC92:
	strb r1, [r5, #6]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldr r1, _0819CCC0 @ =0x00000EAB
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819CCB8
	ldr r0, _0819CCC4 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r7, #0
	movs r2, #0xf7
	bl FUN_0819ee40
	ldr r0, _0819CCC8 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0819CCB8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819CCC0: .4byte 0x00000EAB
_0819CCC4: .4byte 0x000008BC
_0819CCC8: .4byte 0x0000046B
