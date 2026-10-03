	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x19]
	cmp r0, #0
	beq _0804B540
	movs r0, #0
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1b]
_0804B540:
	bl rfu_REQ_pollSearchParent
	bl rfu_waitREQComplete
	adds r4, r5, #0
	adds r4, #0x3c
	adds r2, r5, #0
	adds r2, #0x44
	movs r0, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Rfu_FindPartnerRecord
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _0804B58C
	adds r0, r4, #0
	bl EntityFB53_FindGameIdx
	adds r1, r0, #0
	cmp r1, #0
	blt _0804B588
	adds r0, r5, #0
	adds r0, #0x20
	movs r4, #0
	strb r1, [r0]
	adds r0, r1, #0
	bl FUN_0804b500
	movs r0, #2
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r4, [r5, #0x24]
	b _0804B5E8
_0804B588:
	movs r0, #3
	b _0804B5D2
_0804B58C:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0804B598
	movs r0, #1
	strb r0, [r5, #0x1b]
_0804B598:
	ldr r0, _0804B5AC @ =0x00000257
	ldr r2, [r5, #0x24]
	cmp r2, r0
	bls _0804B5B4
	ldrb r1, [r5, #0x1b]
	cmp r1, #0
	beq _0804B5B0
	movs r0, #3
	b _0804B5D2
	.align 2, 0
_0804B5AC: .4byte 0x00000257
_0804B5B0:
	movs r0, #4
	b _0804B5D4
_0804B5B4:
	cmp r2, #9
	bls _0804B5E4
	ldr r0, _0804B5E0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804B5E4
	adds r0, r5, #0
	bl EntityFB53_Disconnect
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
_0804B5D2:
	movs r1, #0
_0804B5D4:
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r1, [r5, #0x24]
	b _0804B5E8
	.align 2, 0
_0804B5E0: .4byte 0x030044E0
_0804B5E4:
	adds r0, r2, #1
	str r0, [r5, #0x24]
_0804B5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
