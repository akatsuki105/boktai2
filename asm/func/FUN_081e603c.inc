	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E6068 @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E6056
	ldr r1, _081E606C @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E6056:
	ldr r0, _081E606C @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6070
	adds r0, #1
	strh r0, [r1]
	b _081E60A8
	.align 2, 0
_081E6068: .4byte 0x00001614
_081E606C: .4byte 0x0000162A
_081E6070:
	ldr r0, _081E60B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E60B4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E60A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	ldr r1, _081E60B8 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E60BC @ =FUN_081e60c8
	movs r2, #0x16
	str r0, [r4, #0x18]
	ldr r0, _081E60C0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E60C4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E60A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E60B0: .4byte 0x030044E0
_081E60B4: .4byte 0x0000030F
_081E60B8: .4byte 0x00001608
_081E60BC: .4byte FUN_081e60c8
_081E60C0: .4byte 0x00001614
_081E60C4: .4byte 0x00001616
