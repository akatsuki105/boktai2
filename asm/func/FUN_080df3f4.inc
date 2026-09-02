	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3e]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _080DF418 @ =0x0000F422
	bl Video_GetActorSprite
	ldr r0, _080DF41C @ =0x03000178
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DF418: .4byte 0x0000F422
_080DF41C: .4byte 0x03000178
