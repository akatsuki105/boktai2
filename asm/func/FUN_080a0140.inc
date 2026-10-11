	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A017C @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A0184
	ldr r1, _080A0180 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A016A
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
_080A016A:
	cmp r2, #7
	bne _080A01D0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
	b _080A01D0
	.align 2, 0
_080A017C: .4byte 0x03002BE0
_080A0180: .4byte 0x000003BD
_080A0184:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A01C2
	ldr r0, _080A01C8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A01A4
	ldr r0, _080A01CC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A01A4
	movs r1, #1
_080A01A4:
	cmp r1, #0
	bne _080A01B6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A01D0
_080A01B6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A01D0
_080A01C2:
	movs r0, #1
	b _080A01D2
	.align 2, 0
_080A01C8: .4byte 0x03002B8C
_080A01CC: .4byte 0x03002B60
_080A01D0:
	movs r0, #0
_080A01D2:
	pop {r4}
	pop {r1}
	bx r1
