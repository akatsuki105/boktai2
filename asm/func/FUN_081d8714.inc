	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _081D8768 @ =0x030001A0
	ldr r5, [r0]
	cmp r5, #0
	beq _081D8760
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _081D876C @ =0x00005290
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, _081D8770 @ =0x0000922E
	ldr r1, _081D8774 @ =0x00001E38
	bl GetFile
	adds r1, r0, #0
	str r1, [r5, #0x34]
	adds r0, r6, #0
	adds r0, #0x2c
	movs r2, #1
	str r2, [sp]
	movs r2, #8
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r0, _081D8778 @ =0x00000201
	adds r1, r7, r0
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D8760:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8768: .4byte 0x030001A0
_081D876C: .4byte 0x00005290
_081D8770: .4byte 0x0000922E
_081D8774: .4byte 0x00001E38
_081D8778: .4byte 0x00000201
