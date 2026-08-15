	ldr r2, _082318A0 @ =0x7FFFFFFF
	ands r2, r0
	subs r2, #1
	ldr r3, _082318A4 @ =0x03000748
	lsls r2, r2, #2
	ldr r0, [r3]
	adds r0, r0, r2
	ldrb r2, [r0, #3]
	str r2, [r1]
	ldr r1, [r0]
	ldr r0, _082318A8 @ =0x00FFFFFF
	ands r1, r0
	ldr r0, [r3, #8]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_082318A0: .4byte 0x7FFFFFFF
_082318A4: .4byte 0x03000748
_082318A8: .4byte 0x00FFFFFF
