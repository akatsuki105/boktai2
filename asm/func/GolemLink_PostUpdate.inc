	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c2374
	adds r0, r4, #0
	bl GolemLink_ReleaseFixedTarget
	adds r0, r4, #0
	bl GolemLink_UpdateAtkHitbox
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
