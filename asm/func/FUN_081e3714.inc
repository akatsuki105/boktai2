	push {lr}
	ldr r1, _081E3748 @ =0x000015E7
	adds r2, r0, r1
	movs r1, #3
	strb r1, [r2]
	ldr r2, _081E374C @ =0x000015E8
	adds r1, r0, r2
	movs r2, #9
	strb r2, [r1]
	ldr r3, _081E3750 @ =0x000015E9
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _081E3754 @ =0x000015EC
	adds r0, r0, r1
	movs r1, #4
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_081E3748: .4byte 0x000015E7
_081E374C: .4byte 0x000015E8
_081E3750: .4byte 0x000015E9
_081E3754: .4byte 0x000015EC
