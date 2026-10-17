	push {lr}
	adds r2, r0, #0
	ldr r0, _081DAE90 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAE8A
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r1, r0, r3
	cmp r1, #0
	bne _081DAE94
_081DAE8A:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAEAE
	.align 2, 0
_081DAE90: .4byte 0x03002C68
_081DAE94:
	ldr r3, _081DAEB4 @ =0x00000322
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0
_081DAEAE:
	pop {r1}
	bx r1
	.align 2, 0
_081DAEB4: .4byte 0x00000322
