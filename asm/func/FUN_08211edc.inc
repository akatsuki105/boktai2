	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xca
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08211F18
	ldr r1, _08211F10 @ =FUN_08211d90
	ldr r2, _08211F14 @ =FUN_08211de8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08211dec
	cmp r0, #0
	bge _08211F18
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08211F1A
	.align 2, 0
_08211F10: .4byte FUN_08211d90
_08211F14: .4byte FUN_08211de8
_08211F18:
	adds r0, r4, #0
_08211F1A:
	pop {r4, r5}
	pop {r1}
	bx r1
