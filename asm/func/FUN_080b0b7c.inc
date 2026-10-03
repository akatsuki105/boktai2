	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080B0BE8 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r5, _080B0BEC @ =0x0000922E
	ldr r0, _080B0BF0 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x58]
	adds r4, #0x48
	str r6, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0BE8: .4byte 0x08251DD0
_080B0BEC: .4byte 0x0000922E
_080B0BF0: .4byte 0x08251DD4
