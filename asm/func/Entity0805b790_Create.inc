	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B7CC
	ldr r1, _0805B7C4 @ =Entity0805b790_Update
	ldr r2, _0805B7C8 @ =Entity0805b790_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805b790_Init
	cmp r0, #0
	bge _0805B7CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B7CE
	.align 2, 0
_0805B7C4: .4byte Entity0805b790_Update
_0805B7C8: .4byte Entity0805b790_Destroy
_0805B7CC:
	adds r0, r4, #0
_0805B7CE:
	pop {r4, r5}
	pop {r1}
	bx r1
