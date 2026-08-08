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
	ldr r1, _0823B3DC @ =FUN_0823b378
	ldr r2, _0823B3E0 @ =FUN_0823b37c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823b388
	cmp r0, #0
	bge _0823B3E4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0823B3E6
	.align 2, 0
_0823B3D8: .4byte 0x030016F8
_0823B3DC: .4byte FUN_0823b378
_0823B3E0: .4byte FUN_0823b37c
_0823B3E4:
	adds r0, r4, #0
_0823B3E6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
