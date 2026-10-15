	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x98
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xf8
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _080C1B40 @ =0x0000021E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B40: .4byte 0x0000021E
