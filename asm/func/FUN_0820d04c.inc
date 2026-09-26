	push {lr}
	ldr r2, _0820D078 @ =0x030046A0
	ldr r2, [r2]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r2, r2, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	lsrs r1, r0, #5
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0820D07C
	movs r0, #0
	b _0820D07E
	.align 2, 0
_0820D078: .4byte 0x030046A0
_0820D07C:
	movs r0, #1
_0820D07E:
	pop {r1}
	bx r1
	.align 2, 0
