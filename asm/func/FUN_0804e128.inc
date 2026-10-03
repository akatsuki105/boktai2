	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804dc90
	adds r0, r4, #0
	bl FUN_0804dd80
	ldr r1, _0804E160 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804E160: .4byte 0x085AB5E0
