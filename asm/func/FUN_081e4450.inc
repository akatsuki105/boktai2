	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _081E4480 @ =0x00000E54
	adds r1, r3, r0
	movs r2, #0x11
_081E445C:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081E445C
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4480: .4byte 0x00000E54
