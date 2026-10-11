	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A02A4 @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A02AC
	ldr r1, _080A02A8 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A0292
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
_080A0292:
	cmp r2, #7
	bne _080A02F0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
	b _080A02F0
	.align 2, 0
_080A02A4: .4byte 0x03002BE0
_080A02A8: .4byte 0x000003BD
_080A02AC:
	ldr r0, _080A02E8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A02C0
	ldr r0, _080A02EC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A02C0
	movs r1, #1
_080A02C0:
	cmp r1, #0
	bne _080A02D6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A02D6
	cmp r0, #3
	bne _080A02F0
_080A02D6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A02F0
_080A02E2:
	movs r0, #1
	b _080A02F2
	.align 2, 0
_080A02E8: .4byte 0x03002B8C
_080A02EC: .4byte 0x03002B60
_080A02F0:
	movs r0, #0
_080A02F2:
	pop {r4}
	pop {r1}
	bx r1
