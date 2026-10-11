	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _0809FF1C
_0809FEEC:
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FF08
	adds r0, r4, r5
	adds r0, #0x64
	bl Mover_Unlink
_0809FF08:
	adds r4, #0x1c
	adds r4, r5, r4
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x8c
	adds r0, r4, #0
	bl Hitbox_Unregister
	adds r6, #1
_0809FF1C:
	ldrh r0, [r5, #0x18]
	cmp r6, r0
	blt _0809FEEC
	ldr r1, _0809FF30 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809FF30: .4byte 0x03000144
