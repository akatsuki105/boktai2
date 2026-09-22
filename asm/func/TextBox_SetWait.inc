	push {lr}
	adds r2, r0, #0
	ldr r0, _08047FA0 @ =0x030000C4
	ldr r1, [r0]
	cmp r1, #0
	beq _08047FA4
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
	b _08047FA8
	.align 2, 0
_08047FA0: .4byte 0x030000C4
_08047FA4:
	movs r0, #1
	rsbs r0, r0, #0
_08047FA8:
	pop {r1}
	bx r1
