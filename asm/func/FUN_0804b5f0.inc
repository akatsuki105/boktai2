	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B626
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r2, [r4, #0x30]
	movs r0, #7
_0804B602:
	subs r0, #1
	cmp r0, #0
	bge _0804B602
	cmp r2, #0
	blt _0804B61A
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r1, [r0]
	adds r1, #3
	adds r0, r2, #0
	bl TextPanel_SetMessage
_0804B61A:
	ldr r0, _0804B648 @ =0x00000123
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl EntityFB53_Disconnect
_0804B626:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B650
	ldr r0, _0804B64C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B650
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #5
	strb r1, [r4, #0x18]
	movs r1, #1
	strb r1, [r4, #0x19]
	b _0804B652
	.align 2, 0
_0804B648: .4byte 0x00000123
_0804B64C: .4byte 0x030044E0
_0804B650:
	adds r0, r2, #1
_0804B652:
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
