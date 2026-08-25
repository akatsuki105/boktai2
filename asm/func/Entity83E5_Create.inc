	push {r4, lr}
	movs r1, #0xe0
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08222CCC
	ldr r1, _08222CC4 @ =Entity83E5_Update
	ldr r2, _08222CC8 @ =Entity83E5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity83E5_Init
	cmp r0, #0
	bge _08222CCC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08222CCE
	.align 2, 0
_08222CC4: .4byte Entity83E5_Update
_08222CC8: .4byte Entity83E5_Destroy
_08222CCC:
	adds r0, r4, #0
_08222CCE:
	pop {r4}
	pop {r1}
	bx r1
