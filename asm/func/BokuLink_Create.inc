	push {r4, r5, lr}
	ldr r5, _081B8434 @ =0x000006AC
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081B842C
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl BokuLink_Init
	cmp r0, #0
	bge _081B842C
	adds r0, r4, #0
	bl BokuLink_Destroy
	adds r0, r4, #0
	bl Free
_081B842C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B8434: .4byte 0x000006AC
