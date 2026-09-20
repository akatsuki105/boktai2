	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _08080A40 @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Video_SetAuxSpritePltt
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080A40: .4byte 0x0000210E
