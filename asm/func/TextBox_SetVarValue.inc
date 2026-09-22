	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08047C5C @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047C60
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496c0
	movs r0, #0
	b _08047C64
	.align 2, 0
_08047C5C: .4byte 0x030000C4
_08047C60:
	movs r0, #1
	rsbs r0, r0, #0
_08047C64:
	pop {r1}
	bx r1
