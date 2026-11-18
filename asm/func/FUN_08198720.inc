	adds r3, r0, #0
	ldr r2, _08198750 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198754 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08198758 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r3, r1
	movs r1, #0x40
	ands r0, r1
	adds r0, #0x1e
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0819875C @ =FUN_08198760
	str r0, [r1]
	bx lr
	.align 2, 0
_08198750: .4byte 0x030046B8
_08198754: .4byte 0x000003FF
_08198758: .4byte 0x0203B400
_0819875C: .4byte FUN_08198760
