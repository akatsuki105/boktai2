	ldr r1, _08217BF0 @ =0x00001674
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08217BF4 @ =0x000016D4
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08217BF8 @ =0x00001734
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr
	.align 2, 0
_08217BF0: .4byte 0x00001674
_08217BF4: .4byte 0x000016D4
_08217BF8: .4byte 0x00001734
