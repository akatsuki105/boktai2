	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B48A
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B48A:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B4B4
	ldr r0, _0804B4B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B4B4
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B4B8
	.align 2, 0
_0804B4B0: .4byte 0x030044E0
_0804B4B4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B4B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
