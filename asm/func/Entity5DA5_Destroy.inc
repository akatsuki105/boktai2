	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x6c
	bl MainSprite_Remove
	adds r4, #0xcc
	movs r5, #3
_08008E4E:
	adds r0, r4, #0
	adds r0, #8
	bl Hitbox_Unregister
	adds r0, r4, #0
	adds r0, #0x58
	bl MainSprite_Remove
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008E4E
	ldr r2, _08008E74 @ =0x03000038
	movs r1, #0
	str r1, [r2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008E74: .4byte 0x03000038
