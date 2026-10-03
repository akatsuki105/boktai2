	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B7FA
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B7FA
	ldr r1, [r4, #0x2c]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x30]
	movs r1, #0xf
	bl TextPanel_SetMessage
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B7FA:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B830
	ldr r0, _0804B820 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B830
	ldrb r0, [r4, #0x1e]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0804B824
	movs r0, #8
	b _0804B826
	.align 2, 0
_0804B820: .4byte 0x030044E0
_0804B824:
	movs r0, #5
_0804B826:
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B834
_0804B830:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B834:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
