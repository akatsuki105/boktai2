	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804AB5C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _0804AB64
	ldr r1, _0804AB60 @ =0x030000D4
	adds r2, r3, #0
	adds r2, #0x2a
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [r1]
	ldrb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2f
	movs r2, #0
	b _0804AB76
	.align 2, 0
_0804AB5C: .4byte 0x030044E0
_0804AB60: .4byte 0x030000D4
_0804AB64:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804AB70
	movs r0, #0
	b _0804AB88
_0804AB70:
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #3
_0804AB76:
	strb r0, [r1]
	movs r1, #4
	adds r0, r3, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	str r2, [r3, #0x34]
	movs r0, #1
_0804AB88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
