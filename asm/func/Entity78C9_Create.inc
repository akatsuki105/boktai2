	push {r4, lr}
	movs r1, #0xd7
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AD64
	ldr r1, _0801AD5C @ =Entity78C9_Update
	ldr r2, _0801AD60 @ =Entity78C9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity78C9_Init
	cmp r0, #0
	bge _0801AD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AD66
	.align 2, 0
_0801AD5C: .4byte Entity78C9_Update
_0801AD60: .4byte Entity78C9_Destroy
_0801AD64:
	adds r0, r4, #0
_0801AD66:
	pop {r4}
	pop {r1}
	bx r1
