	push {r4, r5, lr}
	ldr r5, _0816A9B0 @ =0x00000714
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0816A9A8
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyBee_Init
	cmp r0, #0
	bge _0816A9A8
	adds r0, r4, #0
	bl FUN_08169688
	adds r0, r4, #0
	bl Free
_0816A9A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816A9B0: .4byte 0x00000714
