	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7E00 @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7DCE
	ldr r1, _081E7E04 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7DCE:
	adds r0, r5, #0
	bl FUN_081e32d8
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	ldr r2, _081E7E04 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E7E08
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	beq _081E7DFE
	b _081E7FAE
_081E7DFE:
	b _081E7E26
	.align 2, 0
_081E7E00: .4byte 0x00001614
_081E7E04: .4byte 0x0000162A
_081E7E08:
	ldr r0, _081E7E44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081E7E26
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7E54
_081E7E26:
	ldr r0, _081E7E48 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7E4C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7E50 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7E44: .4byte 0x030044E0
_081E7E48: .4byte FUN_081e78d0
_081E7E4C: .4byte 0x00001614
_081E7E50: .4byte 0x00001616
_081E7E54:
	ldr r2, _081E7E88 @ =0x00001615
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081E7EF8
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7E8C
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	strb r3, [r4]
	b _081E7F20
	.align 2, 0
_081E7E88: .4byte 0x00001615
_081E7E8C:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081E7E96
	b _081E7FAE
_081E7E96:
	ldr r2, _081E7EE0 @ =0x00000BB5
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08243104
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08049e5c
	ldr r1, _081E7EE4 @ =0x00001618
	adds r0, r5, r1
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	ldr r0, _081E7EE8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7EEC @ =FUN_081e7ac4
	movs r2, #5
	str r0, [r5, #0x18]
	ldr r0, _081E7EF0 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7EF4 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	b _081E7FAE
	.align 2, 0
_081E7EE0: .4byte 0x00000BB5
_081E7EE4: .4byte 0x00001618
_081E7EE8: .4byte 0x00001610
_081E7EEC: .4byte FUN_081e7ac4
_081E7EF0: .4byte 0x00001614
_081E7EF4: .4byte 0x00001616
_081E7EF8:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7F28
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strb r6, [r4]
_081E7F20:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7FAE
_081E7F28:
	movs r6, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E7FAE
	bl FUN_08243140
	adds r4, r0, #0
	bl FUN_08243104
	subs r4, r4, r0
	cmp r4, #0
	ble _081E7F4C
	ldr r2, _081E7F58 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E7F5C
_081E7F4C:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7F58: .4byte 0x00000BB4
_081E7F5C:
	bl FUN_08049e5c
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, _081E7FB4 @ =0x00000BB8
	adds r2, r5, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r2, _081E7FB8 @ =0x00001604
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, _081E7FBC @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r2, _081E7FC0 @ =0x00001618
	adds r0, r5, r2
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r0, _081E7FC4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7FC8 @ =FUN_081e7ac4
	movs r1, #5
	str r0, [r5, #0x18]
	ldr r2, _081E7FCC @ =0x00001614
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_081E7FAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7FB4: .4byte 0x00000BB8
_081E7FB8: .4byte 0x00001604
_081E7FBC: .4byte 0x030046A0
_081E7FC0: .4byte 0x00001618
_081E7FC4: .4byte 0x00001610
_081E7FC8: .4byte FUN_081e7ac4
_081E7FCC: .4byte 0x00001614
