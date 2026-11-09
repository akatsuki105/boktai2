	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _082034B0 @ =0x00002E78
	bl Video_GetAuxSprite
	adds r0, r4, #0
	bl InkBallShotManager_InitShots
	cmp r0, #0
	blt _082034B4
	movs r0, #0
	b _082034B8
	.align 2, 0
_082034B0: .4byte 0x00002E78
_082034B4:
	movs r0, #1
	rsbs r0, r0, #0
_082034B8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
