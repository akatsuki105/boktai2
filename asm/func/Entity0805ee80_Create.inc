	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xae
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805EEBC
	ldr r1, _0805EEB4 @ =Entity0805ee80_Update
	ldr r2, _0805EEB8 @ =Entity0805ee80_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805ee80_Init
	cmp r0, #0
	bge _0805EEBC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805EEBE
	.align 2, 0
_0805EEB4: .4byte Entity0805ee80_Update
_0805EEB8: .4byte Entity0805ee80_Destroy
_0805EEBC:
	adds r0, r4, #0
_0805EEBE:
	pop {r4, r5}
	pop {r1}
	bx r1
