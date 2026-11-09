	push {r4, r5, lr}
	ldr r5, _081957C0 @ =0x00000F94
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081957B8
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl Serpent_Init
	cmp r0, #0
	bge _081957B8
	adds r0, r4, #0
	bl Serpent_Destroy
	adds r0, r4, #0
	bl Free
_081957B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081957C0: .4byte 0x00000F94
