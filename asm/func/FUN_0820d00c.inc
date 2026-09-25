	push {lr}
	adds r1, r0, #0
	ldr r0, _0820D024 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r0, r3
	cmp r1, #0
	blt _0820D028
	asrs r0, r1, #5
	b _0820D02E
	.align 2, 0
_0820D024: .4byte 0x030046A0
_0820D028:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0820D02E:
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0820D046
	movs r0, #0
	b _0820D048
_0820D046:
	movs r0, #1
_0820D048:
	pop {r1}
	bx r1
