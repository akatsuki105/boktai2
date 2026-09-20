	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08215898 @ =0x00000DBC
	adds r0, r4, r1
	bl MainSprite_Remove
	ldr r0, _0821589C @ =0x00000E1C
	adds r4, r4, r0
	adds r0, r4, #0
	bl MainSprite_Remove
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08215898: .4byte 0x00000DBC
_0821589C: .4byte 0x00000E1C
