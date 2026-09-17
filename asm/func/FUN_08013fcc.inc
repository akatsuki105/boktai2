	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08013f84
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
