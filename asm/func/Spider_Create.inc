	push {r4, r5, lr}
	movs r5, #0xd2
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0813230E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl Spider_Init
	cmp r0, #0
	bge _0813230E
	adds r0, r4, #0
	bl Spider_Destroy
	adds r0, r4, #0
	bl Free
_0813230E:
	pop {r4, r5}
	pop {r0}
	bx r0
