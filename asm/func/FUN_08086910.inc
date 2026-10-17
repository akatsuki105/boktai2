	push {r4, lr}
	ldr r0, _08086950 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808694A
	adds r0, r4, #0
	movs r1, #8
	bl Coffin_SetState
	adds r0, r4, #0
	bl FUN_0808567c
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08086954 @ =0x000005DC
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808694A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086950: .4byte 0x03002C00
_08086954: .4byte 0x000005DC
