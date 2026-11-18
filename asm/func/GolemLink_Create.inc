	push {r4, r5, lr}
	ldr r5, _081C5C90 @ =0x000006E4
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081C5C88
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl GolemLink_Init
	cmp r0, #0
	bge _081C5C88
	adds r0, r4, #0
	bl GolemLink_Destroy
	adds r0, r4, #0
	bl Free
_081C5C88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C5C90: .4byte 0x000006E4
