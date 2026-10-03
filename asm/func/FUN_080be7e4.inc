	push {lr}
	adds r2, r0, #0
	ldr r0, _080BE808 @ =0x0000168E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BE802
	ldr r1, _080BE80C @ =FUN_080be810
	adds r0, r2, #0
	bl Entity744F_SetState
_080BE802:
	pop {r0}
	bx r0
	.align 2, 0
_080BE808: .4byte 0x0000168E
_080BE80C: .4byte FUN_080be810
