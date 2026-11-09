	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r2, _0817C060 @ =0x00000864
	adds r0, r1, r2
	movs r2, #0xc8
	lsls r2, r2, #9
	str r2, [r0]
	movs r4, #0x8a
	lsls r4, r4, #4
	adds r0, r1, r4
	str r2, [r0]
	ldr r0, _0817C064 @ =0x000008A4
	adds r1, r1, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0817C060: .4byte 0x00000864
_0817C064: .4byte 0x000008A4
