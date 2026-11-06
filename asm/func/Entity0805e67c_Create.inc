	push {r4, lr}
	ldr r1, _0805E6A8 @ =0x00001510
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805E6B4
	ldr r1, _0805E6AC @ =Entity0805e67c_Update
	ldr r2, _0805E6B0 @ =Entity0805e67c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0805e67c_Init
	cmp r0, #0
	bge _0805E6B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805E6B6
	.align 2, 0
_0805E6A8: .4byte 0x00001510
_0805E6AC: .4byte Entity0805e67c_Update
_0805E6B0: .4byte Entity0805e67c_Destroy
_0805E6B4:
	adds r0, r4, #0
_0805E6B6:
	pop {r4}
	pop {r1}
	bx r1
