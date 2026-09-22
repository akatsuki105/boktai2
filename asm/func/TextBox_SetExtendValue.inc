	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08047C98 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	bne _08047C9C
	movs r0, #0
	b _08047CA4
	.align 2, 0
_08047C98: .4byte 0x030000C4
_08047C9C:
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496cc
_08047CA4:
	pop {r1}
	bx r1
