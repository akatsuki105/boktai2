	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819D9B8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D9BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D9BE
	.align 2, 0
_0819D9B8: .4byte 0x0000046C
_0819D9BC:
	movs r0, #0
_0819D9BE:
	cmp r0, #0
	beq _0819D9EE
	ldr r6, _0819DA3C @ =0x000005A4
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0819DA40 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DA44 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	subs r6, #0x51
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_0819D9EE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819DA10
	adds r0, r5, #0
	bl FUN_0819e620
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819DA10
	b _0819DB70
_0819DA10:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r2, _0819DA48 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819DA54
	movs r6, #8
	ldr r1, _0819DA4C @ =0x00000484
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0xc8
	lsls r0, r0, #1
	cmp r1, r0
	ble _0819DB14
	ldr r3, _0819DA50 @ =FUN_0819bd2c
	movs r1, #0x22
	subs r2, #0xd9
	b _0819DA76
	.align 2, 0
_0819DA3C: .4byte 0x000005A4
_0819DA40: .4byte 0x0000046D
_0819DA44: .4byte 0x0000046B
_0819DA48: .4byte 0x00000546
_0819DA4C: .4byte 0x00000484
_0819DA50: .4byte FUN_0819bd2c
_0819DA54:
	movs r2, #0xeb
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819DAD4
	movs r6, #6
	ldr r1, _0819DAC0 @ =0x00000484
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #1
	cmp r1, r0
	ble _0819DB14
	ldr r3, _0819DAC4 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r2, _0819DAC8 @ =0x0000046D
_0819DA76:
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0819DACC @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	movs r3, #4
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0819DAD0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	b _0819DB70
	.align 2, 0
_0819DAC0: .4byte 0x00000484
_0819DAC4: .4byte FUN_0819bd2c
_0819DAC8: .4byte 0x0000046D
_0819DACC: .4byte 0x0000046B
_0819DAD0: .4byte 0x0000046A
_0819DAD4:
	movs r6, #4
	ldr r2, _0819DB0C @ =0x00000484
	adds r0, r5, r2
	ldr r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	ble _0819DB14
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1b
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0819DB0C @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _0819DB10 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0819DB70
	.align 2, 0
_0819DB0C: .4byte 0x00000484
_0819DB10: .4byte 0x0000046C
_0819DB14:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r4, [r0]
	ldr r2, _0819DB3C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0819DB40
	asrs r1, r0, #0xc
	b _0819DB46
	.align 2, 0
_0819DB3C: .4byte gSineTable
_0819DB40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819DB46:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0819DB5E
	asrs r0, r0, #0xc
	b _0819DB64
_0819DB5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819DB64:
	strh r0, [r3, #4]
	ldr r6, _0819DB78 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0819DB70:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819DB78: .4byte 0x00000484
