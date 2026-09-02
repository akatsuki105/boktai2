	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #4
	movs r1, #0x58
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08241648
	ldr r1, _08241640 @ =EntityB639_Update
	ldr r2, _08241644 @ =EntityB639_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityB639_Init
	cmp r0, #0
	bge _08241648
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0824164A
	.align 2, 0
_08241640: .4byte EntityB639_Update
_08241644: .4byte EntityB639_Destroy
_08241648:
	adds r0, r4, #0
_0824164A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
