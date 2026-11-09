	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r6, _0818E178 @ =0x0000046C
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818E17C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818E17E
	.align 2, 0
_0818E178: .4byte 0x0000046C
_0818E17C:
	movs r0, #0
_0818E17E:
	cmp r0, #0
	beq _0818E1BC
	ldr r0, _0818E1B0 @ =0x00000F2C
	adds r2, r2, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0818E1B4 @ =0x00000474
	adds r2, r5, r1
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0818E1B8 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0818E29C
	.align 2, 0
_0818E1B0: .4byte 0x00000F2C
_0818E1B4: .4byte 0x00000474
_0818E1B8: .4byte 0xFFEFFFFF
_0818E1BC:
	ldr r1, _0818E1D8 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x46
	beq _0818E200
	cmp r0, #0x46
	bgt _0818E1E2
	cmp r0, #0x1e
	beq _0818E200
	cmp r0, #0x1e
	bgt _0818E1DC
	cmp r0, #0xa
	beq _0818E1FA
	b _0818E206
	.align 2, 0
_0818E1D8: .4byte 0x00000484
_0818E1DC:
	cmp r0, #0x32
	beq _0818E200
	b _0818E206
_0818E1E2:
	cmp r0, #0x5a
	beq _0818E200
	cmp r0, #0x5a
	bgt _0818E1F0
	cmp r0, #0x50
	beq _0818E200
	b _0818E206
_0818E1F0:
	cmp r0, #0x5f
	beq _0818E200
	cmp r0, #0x64
	beq _0818E200
	b _0818E206
_0818E1FA:
	ldr r0, _0818E278 @ =0x000001A7
	bl PlaySound_082406e0
_0818E200:
	adds r0, r5, #0
	bl FUN_08190634
_0818E206:
	ldr r2, _0818E27C @ =0x00000484
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0x19
	bne _0818E216
	ldr r0, _0818E280 @ =0x00000143
	bl PlaySound_082406e0
_0818E216:
	ldr r3, _0818E284 @ =0x00002EE0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	ldr r0, [r4]
	cmp r0, #0x64
	ble _0818E298
	ldr r3, _0818E288 @ =Serpent_StateDying
	movs r1, #0x11
	ldr r6, _0818E28C @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818E290 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0818E294 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _0818E29C
	.align 2, 0
_0818E278: .4byte 0x000001A7
_0818E27C: .4byte 0x00000484
_0818E280: .4byte 0x00000143
_0818E284: .4byte 0x00002EE0
_0818E288: .4byte Serpent_StateDying
_0818E28C: .4byte 0x0000046D
_0818E290: .4byte 0x00000469
_0818E294: .4byte 0x0000046C
_0818E298:
	adds r0, #1
	str r0, [r4]
_0818E29C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
