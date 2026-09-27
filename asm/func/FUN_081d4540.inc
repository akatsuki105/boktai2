	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D458C @ =0x03002BE0
	ldr r0, [r5]
	cmp r0, #0
	beq _081D4584
	adds r0, r4, #0
	bl FUN_081d40b4
	adds r0, r4, #0
	bl FUN_081d42c4
	ldr r0, [r5]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D456A
	adds r0, r4, #0
	bl FUN_081d4590
_081D456A:
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	beq _081D457A
	adds r0, r4, #0
	bl FUN_081d4658
_081D457A:
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
_081D4584:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D458C: .4byte 0x03002BE0
