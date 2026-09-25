	push {r4, lr}
	movs r4, #1
	ldr r1, _0820ED30 @ =0x00000E54
	adds r2, r0, r1
	ldr r3, _0820ED34 @ =0x00000D94
	adds r1, r0, r3
	movs r3, #1
_0820ED12:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ED12
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820ED30: .4byte 0x00000E54
_0820ED34: .4byte 0x00000D94
