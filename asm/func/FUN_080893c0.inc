	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808940C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _080893D6
	adds r0, r4, #0
	movs r1, #0xe
	bl Coffin_SetState
_080893D6:
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
	movs r1, #0x10
	bl FUN_08086024
	cmp r0, #0
	beq _08089406
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Coffin_SetState
_08089406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808940C: .4byte 0x000001F5
