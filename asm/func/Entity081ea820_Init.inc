	push {lr}
	movs r1, #0
	str r1, [r0, #0x34]
	ldr r1, _081EA818 @ =0x030001BC
	str r0, [r1]
	adds r0, #0x18
	ldr r1, _081EA81C @ =0x000084EE
	bl Video_GetAuxSprite
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EA818: .4byte 0x030001BC
_081EA81C: .4byte 0x000084EE
