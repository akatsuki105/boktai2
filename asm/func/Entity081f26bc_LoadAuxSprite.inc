	push {r4, lr}
	adds r4, r2, #0
	ldr r0, [r0]
	adds r0, #0x2c
	bl Video_GetAuxSprite
	ldr r0, _081F22BC @ =0x0000922E
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl GetFile
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F22BC: .4byte 0x0000922E
