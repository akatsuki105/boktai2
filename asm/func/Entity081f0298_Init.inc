	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F0288 @ =0x0000D45E
	bl Video_GetAuxSprite
	ldr r0, _081F028C @ =0x0000922E
	ldr r1, _081F0290 @ =0x00001DC3
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F0294 @ =0x030001E0
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F0288: .4byte 0x0000D45E
_081F028C: .4byte 0x0000922E
_081F0290: .4byte 0x00001DC3
_081F0294: .4byte 0x030001E0
