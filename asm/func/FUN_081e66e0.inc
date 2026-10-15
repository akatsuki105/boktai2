	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E670C @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E66FA
	ldr r1, _081E6710 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E66FA:
	ldr r0, _081E6710 @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6714
	adds r0, #1
	strh r0, [r1]
	b _081E674C
	.align 2, 0
_081E670C: .4byte 0x00001614
_081E6710: .4byte 0x0000162A
_081E6714:
	ldr r0, _081E6754 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E6758 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E674C
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	ldr r1, _081E675C @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E6760 @ =FUN_081e676c
	movs r2, #0x13
	str r0, [r4, #0x18]
	ldr r0, _081E6764 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6768 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E674C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E6754: .4byte 0x030044E0
_081E6758: .4byte 0x0000030F
_081E675C: .4byte 0x00001608
_081E6760: .4byte FUN_081e676c
_081E6764: .4byte 0x00001614
_081E6768: .4byte 0x00001616
