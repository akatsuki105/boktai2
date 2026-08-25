	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xfe
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821B838
	ldr r1, _0821B830 @ =Entity0821b7fc_Update
	ldr r2, _0821B834 @ =FUN_0821b73c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0821b760
	cmp r0, #0
	bge _0821B838
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821B83A
	.align 2, 0
_0821B830: .4byte Entity0821b7fc_Update
_0821B834: .4byte FUN_0821b73c
_0821B838:
	adds r0, r4, #0
_0821B83A:
	pop {r4, r5}
	pop {r1}
	bx r1
