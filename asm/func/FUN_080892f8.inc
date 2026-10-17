	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089340 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _0808930E
	adds r0, r4, #0
	movs r1, #0xd
	bl Coffin_SetState
_0808930E:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08086024
	cmp r0, #0
	beq _08089338
	adds r0, r4, #0
	movs r1, #0xc
	bl Coffin_SetState
_08089338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089340: .4byte 0x000001F5
