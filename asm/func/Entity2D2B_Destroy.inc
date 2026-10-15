	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _080084DC
_080084C2:
	ldrb r1, [r4]
	cmp r1, #0
	beq _080084D8
	adds r0, r4, #0
	adds r0, #0x94
	bl Hitbox_Unregister
	adds r0, r4, #0
	adds r0, #0x34
	bl MainSprite_Remove
_080084D8:
	adds r5, #1
	adds r4, #0xe8
_080084DC:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _080084C2
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _080084F2
	adds r0, r1, #0
	bl Free
	movs r1, #0
	str r1, [r6, #0x1c]
_080084F2:
	ldr r2, _08008500 @ =0x03000034
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08008500: .4byte 0x03000034
