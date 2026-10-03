	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r4, r5, r0
	adds r0, #0x2c
	adds r6, r5, r0
	ldr r1, _080B1B70 @ =0x00003641
	adds r0, r6, #0
	bl Video_GetAuxSprite
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r6, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, #0x48
	strh r0, [r4, #0x1e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B70: .4byte 0x00003641
