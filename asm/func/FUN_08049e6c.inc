	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049E88 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049E8C
	adds r0, #0x18
	adds r1, r3, #0
	bl TextRenderer_SetVar
	movs r0, #0
	b _08049E90
	.align 2, 0
_08049E88: .4byte 0x030000C8
_08049E8C:
	movs r0, #1
	rsbs r0, r0, #0
_08049E90:
	pop {r1}
	bx r1
