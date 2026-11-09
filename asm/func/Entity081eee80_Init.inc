	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081EEE78 @ =0x00008639
	bl Video_GetAuxSprite
	ldr r0, _081EEE7C @ =0x030001D8
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE78: .4byte 0x00008639
_081EEE7C: .4byte 0x030001D8
