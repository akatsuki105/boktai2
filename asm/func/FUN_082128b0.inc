	push {lr}
	adds r3, r0, #0
	adds r3, #0xf4
	adds r1, r0, #0
	adds r1, #0x18
	ldr r2, _082128D4 @ =0x0000041C
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r0}
	bx r0
	.align 2, 0
_082128D4: .4byte 0x0000041C
