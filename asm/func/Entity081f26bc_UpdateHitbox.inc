	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x6c
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081F1880
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081F1880
	adds r4, r3, #0
	adds r4, #0x1c
	cmp r1, #0
	beq _081F187A
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_081F187A:
	adds r0, r4, #0
	bl Hitbox_Register
_081F1880:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
