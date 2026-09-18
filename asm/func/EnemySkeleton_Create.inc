	push {r4, r5, lr}
	movs r5, #0xf5
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0811531E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySkeleton_Init
	cmp r0, #0
	bge _0811531E
	adds r0, r4, #0
	bl EnemySkeleton_Destroy
	adds r0, r4, #0
	bl Free
_0811531E:
	pop {r4, r5}
	pop {r0}
	bx r0
