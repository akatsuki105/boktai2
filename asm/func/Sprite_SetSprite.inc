	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	bl Sprite_LoadSprite
	cmp r0, #0
	blt _0822F3F0
	ldr r0, _0822F3EC @ =0x030044B8
	ldrh r0, [r0]
	strh r0, [r4, #2]
	strb r5, [r4, #0x1b]
	movs r0, #0
	b _0822F3F4
	.align 2, 0
_0822F3EC: .4byte 0x030044B8
_0822F3F0:
	movs r0, #1
	rsbs r0, r0, #0
_0822F3F4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
