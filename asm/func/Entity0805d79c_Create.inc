	push {r4, lr}
	ldr r1, _0805D7C8 @ =0x00001138
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D7D4
	ldr r1, _0805D7CC @ =Entity0805d79c_Update
	ldr r2, _0805D7D0 @ =Entity0805d79c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0805d79c_Init
	cmp r0, #0
	bge _0805D7D4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D7D6
	.align 2, 0
_0805D7C8: .4byte 0x00001138
_0805D7CC: .4byte Entity0805d79c_Update
_0805D7D0: .4byte Entity0805d79c_Destroy
_0805D7D4:
	adds r0, r4, #0
_0805D7D6:
	pop {r4}
	pop {r1}
	bx r1
