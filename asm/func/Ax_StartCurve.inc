	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	ldr r2, _0819DFF0 @ =0x00000EFC
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	ldr r3, _0819DFF4 @ =0x00000F04
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _0819DFF8 @ =0x00000EA4
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819DFF0: .4byte 0x00000EFC
_0819DFF4: .4byte 0x00000F04
_0819DFF8: .4byte 0x00000EA4
