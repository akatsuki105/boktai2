	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049EC4 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049EC8
	movs r0, #1
	rsbs r0, r0, #0
	b _08049ED0
	.align 2, 0
_08049EC4: .4byte 0x030000C8
_08049EC8:
	adds r0, #0x18
	adds r1, r3, #0
	bl TextRenderer_SetExtend
_08049ED0:
	pop {r1}
	bx r1
