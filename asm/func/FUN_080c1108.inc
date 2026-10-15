	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0x7c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1144
	ldr r1, _080C113C @ =Entity080c0fa0_Update
	ldr r2, _080C1140 @ =Entity080c0fa0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080c1008
	cmp r0, #0
	bge _080C1144
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1146
	.align 2, 0
_080C113C: .4byte Entity080c0fa0_Update
_080C1140: .4byte Entity080c0fa0_Destroy
_080C1144:
	adds r0, r4, #0
_080C1146:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
