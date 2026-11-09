	push {r4, r5, lr}
	ldr r5, _0813A15C @ =0x00000B94
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0813A154
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl Centipede_Init
	cmp r0, #0
	bge _0813A154
	adds r0, r4, #0
	bl Centipede_Destroy
	adds r0, r4, #0
	bl Free
_0813A154:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813A15C: .4byte 0x00000B94
