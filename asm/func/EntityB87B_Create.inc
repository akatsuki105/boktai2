	push {r4, lr}
	movs r1, #0x8e
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2678
	ldr r1, _080C2670 @ =EntityB87B_Update
	ldr r2, _080C2674 @ =EntityB87B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB87B_Init
	cmp r0, #0
	bge _080C2678
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C267A
	.align 2, 0
_080C2670: .4byte EntityB87B_Update
_080C2674: .4byte EntityB87B_Destroy
_080C2678:
	adds r0, r4, #0
_080C267A:
	pop {r4}
	pop {r1}
	bx r1
