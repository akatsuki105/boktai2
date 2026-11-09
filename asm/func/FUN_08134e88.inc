	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08134EA0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134EA4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134EA6
	.align 2, 0
_08134EA0: .4byte 0x0000046C
_08134EA4:
	movs r0, #0
_08134EA6:
	cmp r0, #0
	beq _08134EEA
	ldr r4, _08134F30 @ =FUN_081331b4
	movs r3, #0x25
	ldr r2, _08134F34 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08134F38 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08134F3C @ =0x0000019B
	bl PlaySound_082406e0
_08134EEA:
	ldr r1, _08134F40 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _08134F4C
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134F4C
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08134F44 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _08134F48 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08134FAA
	.align 2, 0
_08134F30: .4byte FUN_081331b4
_08134F34: .4byte 0x0000046D
_08134F38: .4byte 0x0000046B
_08134F3C: .4byte 0x0000019B
_08134F40: .4byte 0x00000553
_08134F44: .4byte 0x0000046A
_08134F48: .4byte 0x0000046C
_08134F4C:
	ldr r1, _08134F94 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08134FA0
	adds r0, r5, #0
	bl FUN_081355f0
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08134F98 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _08134F9C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08134FAA
	.align 2, 0
_08134F94: .4byte 0x0000046B
_08134F98: .4byte 0x00000484
_08134F9C: .4byte 0xFFEFFFFF
_08134FA0:
	ldr r2, _08134FB0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08134FAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08134FB0: .4byte 0x00000484
