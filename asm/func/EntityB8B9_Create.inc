	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0823B3D8 @ =0x030016F8
	ldr r0, [r0]
	cmp r0, #0
	bne _0823B3E6
	movs r0, #2
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823B3E4
	ldr r1, _0823B3DC @ =EntityB8B9_Update
	ldr r2, _0823B3E0 @ =EntityB8B9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityB8B9_Init
	cmp r0, #0
	bge _0823B3E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0823B3E6
	.align 2, 0
_0823B3D8: .4byte 0x030016F8
_0823B3DC: .4byte EntityB8B9_Update
_0823B3E0: .4byte EntityB8B9_Destroy
_0823B3E4:
	adds r0, r4, #0
_0823B3E6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
