	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E48
	ldr r0, [r0, #0x64]
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl Entity08052ffc_Spawn
_08050E48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
