	push {r4, r5, r6, r7, lr}
	ldr r2, _08237F18 @ =0x03000788
	ldr r0, _08237F1C @ =0x0300078C
	movs r1, #0
	str r1, [r0]
	str r1, [r2]
	ldr r2, _08237F20 @ =0x03000794
	ldr r0, _08237F24 @ =0x03000798
	str r1, [r0]
	str r1, [r2]
	ldr r0, _08237F28 @ =0x03000790
	str r1, [r0]
	ldr r0, _08237F2C @ =0x0300079C
	str r1, [r0]
	ldr r5, _08237F30 @ =0x030046D4
	ldr r6, _08237F34 @ =0x030046CC
	ldr r0, _08237F38 @ =0x030046C0
	mov ip, r0
	ldr r7, _08237F3C @ =0x030046C8
	ldr r4, _08237F40 @ =0x030007A0
	movs r2, #0
	ldr r3, _08237F44 @ =0x030007E0
_08237EE0:
	adds r0, r1, r4
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x3f
	ble _08237EE0
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r6]
	str r1, [r7]
	mov r0, ip
	str r1, [r0]
	bl FUN_08237e24
	ldr r0, [r5]
	cmp r0, #0
	blt _08237F4E
	ldr r0, [r6]
	cmp r0, #0
	beq _08237F48
	bl FUN_08237be0
	movs r0, #1
	b _08237F4E
	.align 2, 0
_08237F18: .4byte 0x03000788
_08237F1C: .4byte 0x0300078C
_08237F20: .4byte 0x03000794
_08237F24: .4byte 0x03000798
_08237F28: .4byte 0x03000790
_08237F2C: .4byte 0x0300079C
_08237F30: .4byte 0x030046D4
_08237F34: .4byte 0x030046CC
_08237F38: .4byte 0x030046C0
_08237F3C: .4byte 0x030046C8
_08237F40: .4byte 0x030007A0
_08237F44: .4byte 0x030007E0
_08237F48:
	bl FUN_08237a04
	movs r0, #0
_08237F4E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
