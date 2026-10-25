	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _081E7C54 @ =0x00001614
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7C22
	ldr r2, _081E7C58 @ =0x0000162A
	adds r1, r6, r2
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7C5C @ =0x00001618
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	strb r4, [r5]
_081E7C22:
	adds r0, r6, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7C68
	ldr r0, _081E7C60 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r6, #0x18]
	ldr r3, _081E7C54 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7C64 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7C54: .4byte 0x00001614
_081E7C58: .4byte 0x0000162A
_081E7C5C: .4byte 0x00001618
_081E7C60: .4byte FUN_081e78d0
_081E7C64: .4byte 0x00001616
_081E7C68:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E7C80 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7C84
	movs r0, #1
	b _081E7C86
	.align 2, 0
_081E7C80: .4byte 0x00001610
_081E7C84:
	movs r0, #0
_081E7C86:
	cmp r0, #0
	beq _081E7C9C
	ldr r1, _081E7C98 @ =0x00001618
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	b _081E7D9E
	.align 2, 0
_081E7C98: .4byte 0x00001618
_081E7C9C:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081E7CAC
	movs r0, #1
	b _081E7CAE
_081E7CAC:
	movs r0, #0
_081E7CAE:
	cmp r0, #0
	beq _081E7D9E
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7D9E
	ldr r2, _081E7D34 @ =0x0000162E
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	bne _081E7D50
	ldr r0, _081E7D38 @ =FUN_081e7414
	movs r2, #4
	str r0, [r6, #0x18]
	ldr r0, _081E7D3C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7D40 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	bl Marquee_Clear
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r6, r2
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r3, _081E7D44 @ =0x00001604
	adds r5, r6, r3
	ldr r0, [r5]
	bl TextPanel_Hide
	ldr r0, [r4]
	ldr r1, _081E7D48 @ =0x00000BB8
	adds r2, r6, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r5]
	ldr r1, _081E7D4C @ =0x030046A0
	ldr r2, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r1, #2
	bl FUN_0804a40c
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7D34: .4byte 0x0000162E
_081E7D38: .4byte FUN_081e7414
_081E7D3C: .4byte 0x00001614
_081E7D40: .4byte 0x00001616
_081E7D44: .4byte 0x00001604
_081E7D48: .4byte 0x00000BB8
_081E7D4C: .4byte 0x030046A0
_081E7D50:
	cmp r2, #1
	bne _081E7D9E
	ldr r0, _081E7DA4 @ =FUN_081e6f28
	movs r1, #3
	str r0, [r6, #0x18]
	ldr r3, _081E7DA8 @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r2, _081E7DAC @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	bl Marquee_Clear
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r6, r3
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E7DB0 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7D9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7DA4: .4byte FUN_081e6f28
_081E7DA8: .4byte 0x00001614
_081E7DAC: .4byte 0x00001616
_081E7DB0: .4byte 0x00001604
