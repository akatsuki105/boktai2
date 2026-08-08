	push {r4, lr}
	movs r1, #0xe0
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08222CCC
	ldr r1, _08222CC4 @ =FUN_08222a88
	ldr r2, _08222CC8 @ =0x08222AC1
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08222acc
	cmp r0, #0
	bge _08222CCC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08222CCE
	.align 2, 0
_08222CC4: .4byte FUN_08222a88
_08222CC8: .4byte 0x08222AC1
_08222CCC:
	adds r0, r4, #0
_08222CCE:
	pop {r4}
	pop {r1}
	bx r1
