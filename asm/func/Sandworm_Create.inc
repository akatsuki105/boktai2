	push {r4, r5, lr}
	ldr r5, _0817B844 @ =0x00001068
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0817B83C
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl Sandworm_Init
	cmp r0, #0
	bge _0817B83C
	adds r0, r4, #0
	bl Sandworm_Destroy
	adds r0, r4, #0
	bl Free
_0817B83C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0817B844: .4byte 0x00001068
