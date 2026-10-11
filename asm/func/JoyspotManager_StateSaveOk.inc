	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B79C
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B79C
	ldr r1, [r4, #0x2c]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x30]
	movs r1, #0xe
	bl TextPanel_SetMessage
	ldr r0, _0804B7BC @ =0x000002AE
	bl PlaySound_082406e0
_0804B79C:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B7C4
	ldr r0, _0804B7C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B7C4
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B7C8
	.align 2, 0
_0804B7BC: .4byte 0x000002AE
_0804B7C0: .4byte 0x030044E0
_0804B7C4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B7C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
