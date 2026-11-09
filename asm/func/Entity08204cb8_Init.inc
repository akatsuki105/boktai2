	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _08204CA8 @ =0x00002E78
	bl Video_GetAuxSprite
	adds r0, r4, #0
	bl Entity08204cb8_InitElems
	cmp r0, #0
	blt _08204CAC
	movs r0, #0
	b _08204CB0
	.align 2, 0
_08204CA8: .4byte 0x00002E78
_08204CAC:
	movs r0, #1
	rsbs r0, r0, #0
_08204CB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
