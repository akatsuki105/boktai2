	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xca
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08211F18
	ldr r1, _08211F10 @ =Entity4DDF_Update
	ldr r2, _08211F14 @ =Entity4DDF_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity4DDF_Init
	cmp r0, #0
	bge _08211F18
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08211F1A
	.align 2, 0
_08211F10: .4byte Entity4DDF_Update
_08211F14: .4byte Entity4DDF_Destroy
_08211F18:
	adds r0, r4, #0
_08211F1A:
	pop {r4, r5}
	pop {r1}
	bx r1
