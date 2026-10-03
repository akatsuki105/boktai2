	ldr r1, _08090030 @ =0x00002CAC
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090034 @ =0x00002D0C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090038 @ =0x00002D6C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _0809003C @ =0x00002DCC
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr
	.align 2, 0
_08090030: .4byte 0x00002CAC
_08090034: .4byte 0x00002D0C
_08090038: .4byte 0x00002D6C
_0809003C: .4byte 0x00002DCC
