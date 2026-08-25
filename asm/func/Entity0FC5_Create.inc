	push {r4, lr}
	movs r1, #0xc4
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821B214
	ldr r1, _0821B20C @ =FUN_0821b09c
	ldr r2, _0821B210 @ =FUN_0821b0e4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0FC5_Init
	cmp r0, #0
	bge _0821B214
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821B216
	.align 2, 0
_0821B20C: .4byte FUN_0821b09c
_0821B210: .4byte FUN_0821b0e4
_0821B214:
	adds r0, r4, #0
_0821B216:
	pop {r4}
	pop {r1}
	bx r1
