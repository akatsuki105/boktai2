	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #7
_082033A0:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _082033AC
	adds r0, r4, #0
	bl AuxSprite_Remove
_082033AC:
	adds r0, r4, #0
	adds r0, #0x3c
	bl Hitbox_Unregister
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _082033A0
	ldr r1, _082033CC @ =0x03000218
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082033CC: .4byte 0x03000218
