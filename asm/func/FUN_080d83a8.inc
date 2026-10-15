	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, _080D83F8 @ =0x00008639
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r5, #0x10]
	ldr r0, _080D83FC @ =0x00000113
	adds r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl Video_SetAuxSpritePltt
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r1, #1
	strb r1, [r5, #7]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D83F8: .4byte 0x00008639
_080D83FC: .4byte 0x00000113
