	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F3314 @ =0x0000A5B3
	bl Video_GetAuxSprite
	ldr r0, _081F3318 @ =0x0000922E
	ldr r1, _081F331C @ =0x00001752
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F3320 @ =0x030001F0
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F3314: .4byte 0x0000A5B3
_081F3318: .4byte 0x0000922E
_081F331C: .4byte 0x00001752
_081F3320: .4byte 0x030001F0
