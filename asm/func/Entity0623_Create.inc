	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0822225C @ =0x00000C04
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08222268
	ldr r1, _08222260 @ =FUN_08221ca8
	ldr r2, _08222264 @ =FUN_08221ccc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0623_Init
	cmp r0, #0
	bge _08222268
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0822226A
	.align 2, 0
_0822225C: .4byte 0x00000C04
_08222260: .4byte FUN_08221ca8
_08222264: .4byte FUN_08221ccc
_08222268:
	adds r0, r4, #0
_0822226A:
	pop {r4, r5}
	pop {r1}
	bx r1
