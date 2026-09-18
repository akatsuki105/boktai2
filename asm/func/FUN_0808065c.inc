	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _0808069C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08080688
	adds r0, r2, #0
	adds r0, #0xc4
	ldrh r3, [r0]
	ldr r0, _080806A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _08080688
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r0, r4
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_08080688:
	ldr r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r1, [r1]
	bl Player_ReduceENE_0807aa60
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808069C: .4byte 0x030047A4
_080806A0: .4byte 0x03002C68
