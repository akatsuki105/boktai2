	push {lr}
	adds r2, r0, #0
	ldr r0, _080BCA74 @ =0x000012F0
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BCA6E
	ldr r1, _080BCA78 @ =FUN_080bca7c
	adds r0, r2, #0
	bl Entity3019_SetState
_080BCA6E:
	pop {r0}
	bx r0
	.align 2, 0
_080BCA74: .4byte 0x000012F0
_080BCA78: .4byte FUN_080bca7c
