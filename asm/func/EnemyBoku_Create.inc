	push {r4, r5, lr}
	ldr r5, _08102E1C @ =0x000006AC
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08102E14
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyBoku_Init
	cmp r0, #0
	bge _08102E14
	adds r0, r4, #0
	bl FUN_08101c28
	adds r0, r4, #0
	bl Free
_08102E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08102E1C: .4byte 0x000006AC
