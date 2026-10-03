	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B6E4
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B6D6
	movs r1, #7
	bl TextPanel_SetMessage
_0804B6D6:
	adds r0, r4, #0
	bl EntityFB53_Disconnect
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B6E4:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B710
	ldr r0, _0804B70C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B710
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B714
	.align 2, 0
_0804B70C: .4byte 0x030044E0
_0804B710:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B714:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
