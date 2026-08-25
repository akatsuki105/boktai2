	push {r4, lr}
	ldr r0, _080A87F0 @ =0x03000154
	ldr r0, [r0]
	cmp r0, #0
	bne _080A87FE
	movs r1, #0x98
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A87FC
	ldr r1, _080A87F4 @ =LevelUpper_Update
	ldr r2, _080A87F8 @ =LevelUpper_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl LevelUpper_Init
	cmp r0, #0
	bge _080A87FC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A87FE
	.align 2, 0
_080A87F0: .4byte 0x03000154
_080A87F4: .4byte LevelUpper_Update
_080A87F8: .4byte LevelUpper_Destroy
_080A87FC:
	adds r0, r4, #0
_080A87FE:
	pop {r4}
	pop {r1}
	bx r1
