	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl MainSprite_Remove
	ldr r1, _08048550 @ =0x030000C4
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08048550: .4byte 0x030000C4
