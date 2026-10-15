	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r1, _081E4AD0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081E4AD4
	movs r4, #1
	b _081E4AF6
	.align 2, 0
_081E4AD0: .4byte 0x030044E0
_081E4AD4:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081E4AE0
	movs r4, #2
	b _081E4AF6
_081E4AE0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081E4AEC
	movs r4, #4
	b _081E4AF6
_081E4AEC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081E4AF6
	movs r4, #8
_081E4AF6:
	ldrh r3, [r1]
	movs r2, #0xf0
	ands r2, r3
	cmp r2, #0
	beq _081E4B56
	ldr r0, _081E4B18 @ =0x00001619
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0xb
	bls _081E4B50
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _081E4B1C
	movs r0, #1
	b _081E4B26
	.align 2, 0
_081E4B18: .4byte 0x00001619
_081E4B1C:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _081E4B28
	movs r0, #2
_081E4B26:
	orrs r4, r0
_081E4B28:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081E4B36
	movs r0, #4
	b _081E4B40
_081E4B36:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E4B42
	movs r0, #8
_081E4B40:
	orrs r4, r0
_081E4B42:
	ldr r0, _081E4B4C @ =0x00001619
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _081E4B5C
	.align 2, 0
_081E4B4C: .4byte 0x00001619
_081E4B50:
	adds r0, #1
	strb r0, [r2]
	b _081E4B5C
_081E4B56:
	ldr r1, _081E4B64 @ =0x00001619
	adds r0, r5, r1
	strb r2, [r0]
_081E4B5C:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E4B64: .4byte 0x00001619
