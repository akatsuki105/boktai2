	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0804DEFE
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
_0804DEFE:
	ldr r0, _0804DF14 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804DF14: .4byte 0x085AB5E0
