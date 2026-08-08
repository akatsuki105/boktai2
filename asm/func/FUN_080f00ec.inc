	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #0x13
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r7, r5, r1
	ldr r6, [r7]
	ands r6, r0
	cmp r6, #0
	beq _080F010A
	b _080F030E
_080F010A:
	movs r2, #0x80
	lsls r2, r2, #5
	mov sb, r2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r5
	mov r8, r3
	ldrh r0, [r3]
	ands r0, r2
	cmp r0, #0
	beq _080F0138
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_080f8e3c
	mov r1, r8
	ldrh r0, [r1]
	mov r2, sb
	bics r0, r2
	strh r0, [r1]
	str r6, [r4]
_080F0138:
	ldr r1, _080F01F4 @ =0xFFFEBE3F
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r3, _080F01F8 @ =0x0000021E
	adds r0, r5, r3
	movs r4, #0
	strh r6, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r6, [r0]
	ldr r2, _080F01FC @ =0x00000202
	adds r0, r5, r2
	strh r6, [r0]
	ldr r1, _080F0200 @ =0x08251F80
	subs r2, #0xf2
	adds r0, r5, #0
	bl FUN_080e6768
	ldr r3, _080F0204 @ =FUN_080e48d0
	mov sb, r3
	movs r1, #0x10
	ldr r2, _080F0208 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _080F020C @ =0x0000046B
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r3, sb
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _080F0210 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _080F0214 @ =0xFFFFFBFF
	ands r0, r1
	strh r0, [r2]
	adds r3, #0xd6
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080F0218 @ =0x000001DF
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	ldr r0, _080F021C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F0220
	movs r0, #1
	b _080F0222
	.align 2, 0
_080F01F4: .4byte 0xFFFEBE3F
_080F01F8: .4byte 0x0000021E
_080F01FC: .4byte 0x00000202
_080F0200: .4byte 0x08251F80
_080F0204: .4byte FUN_080e48d0
_080F0208: .4byte 0x0000046D
_080F020C: .4byte 0x0000046B
_080F0210: .4byte 0x00000469
_080F0214: .4byte 0xFFFFFBFF
_080F0218: .4byte 0x000001DF
_080F021C: .4byte 0x030047A4
_080F0220:
	movs r0, #0
_080F0222:
	cmp r0, #0
	bne _080F030E
	movs r1, #0x80
	lsls r1, r1, #8
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080F030E
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _080F0290
	ldr r2, _080F0260 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #4
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080F0264 @ =0x0000270E
	cmp r1, r0
	bgt _080F0268
	adds r0, r4, #1
	b _080F026C
	.align 2, 0
_080F0260: .4byte 0x030046A0
_080F0264: .4byte 0x0000270E
_080F0268:
	ldr r1, _080F0288 @ =0x0000270F
	adds r0, r1, #0
_080F026C:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080F028C @ =0x0000270E
	cmp r1, r0
	bgt _080F0308
	adds r0, r3, #1
	b _080F030C
	.align 2, 0
_080F0288: .4byte 0x0000270F
_080F028C: .4byte 0x0000270E
_080F0290:
	cmp r0, #1
	bne _080F02B8
	ldr r0, _080F02AC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F02B0 @ =0x00000952
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080F02B4 @ =0x0000270E
	cmp r1, r0
	bgt _080F0308
	adds r0, r3, #1
	b _080F030C
	.align 2, 0
_080F02AC: .4byte 0x030046A0
_080F02B0: .4byte 0x00000952
_080F02B4: .4byte 0x0000270E
_080F02B8:
	cmp r0, #2
	bne _080F02E0
	ldr r0, _080F02D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F02D8 @ =0x00000954
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080F02DC @ =0x0000270E
	cmp r1, r0
	bgt _080F0308
	adds r0, r3, #1
	b _080F030C
	.align 2, 0
_080F02D4: .4byte 0x030046A0
_080F02D8: .4byte 0x00000954
_080F02DC: .4byte 0x0000270E
_080F02E0:
	cmp r0, #3
	bne _080F030E
	ldr r0, _080F02FC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F0300 @ =0x00000956
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080F0304 @ =0x0000270E
	cmp r1, r0
	bgt _080F0308
	adds r0, r3, #1
	b _080F030C
	.align 2, 0
_080F02FC: .4byte 0x030046A0
_080F0300: .4byte 0x00000956
_080F0304: .4byte 0x0000270E
_080F0308:
	ldr r1, _080F031C @ =0x0000270F
	adds r0, r1, #0
_080F030C:
	strh r0, [r2]
_080F030E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F031C: .4byte 0x0000270F
