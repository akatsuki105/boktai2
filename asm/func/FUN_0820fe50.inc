	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xdd
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0820FE8C
	ldr r1, _0820FE84 @ =FUN_0820fba4
	ldr r2, _0820FE88 @ =FUN_0820fd60
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0820fd9c
	cmp r0, #0
	bge _0820FE8C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0820FE8E
	.align 2, 0
_0820FE84: .4byte FUN_0820fba4
_0820FE88: .4byte FUN_0820fd60
_0820FE8C:
	adds r0, r4, #0
_0820FE8E:
	pop {r4, r5}
	pop {r1}
	bx r1
