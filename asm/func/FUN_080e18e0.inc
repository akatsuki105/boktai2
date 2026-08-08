	push {r4, lr}
	movs r0, #8
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080E1914
	ldr r1, _080E190C @ =FUN_080e17c4
	ldr r2, _080E1910 @ =FUN_080e17f8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080e17fc
	cmp r0, #0
	bge _080E1914
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080E1916
	.align 2, 0
_080E190C: .4byte FUN_080e17c4
_080E1910: .4byte FUN_080e17f8
_080E1914:
	adds r0, r4, #0
_080E1916:
	pop {r4}
	pop {r1}
	bx r1
