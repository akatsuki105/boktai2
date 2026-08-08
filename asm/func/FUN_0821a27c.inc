	push {r4, lr}
	ldr r1, _0821A2A8 @ =0x00001FEC
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821A2B4
	ldr r1, _0821A2AC @ =FUN_08219f68
	ldr r2, _0821A2B0 @ =FUN_08219fa4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08219fe0
	cmp r0, #0
	bge _0821A2B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821A2B6
	.align 2, 0
_0821A2A8: .4byte 0x00001FEC
_0821A2AC: .4byte FUN_08219f68
_0821A2B0: .4byte FUN_08219fa4
_0821A2B4:
	adds r0, r4, #0
_0821A2B6:
	pop {r4}
	pop {r1}
	bx r1
