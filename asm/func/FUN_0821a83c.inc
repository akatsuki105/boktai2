	push {r4, lr}
	movs r1, #0xca
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821A874
	ldr r1, _0821A86C @ =FUN_0821a764
	ldr r2, _0821A870 @ =FUN_0821a7b0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0821a7bc
	cmp r0, #0
	bge _0821A874
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821A876
	.align 2, 0
_0821A86C: .4byte FUN_0821a764
_0821A870: .4byte FUN_0821a7b0
_0821A874:
	adds r0, r4, #0
_0821A876:
	pop {r4}
	pop {r1}
	bx r1
