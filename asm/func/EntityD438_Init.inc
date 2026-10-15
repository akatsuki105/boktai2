	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08055AFC @ =0x03000124
	str r7, [r0]
	adds r4, r7, #0
	adds r4, #0x1c
	adds r5, r7, #0
	adds r5, #0x38
	adds r6, r7, #0
	adds r6, #0x64
	ldr r0, _08055B00 @ =0x0000922E
	ldr r1, _08055B04 @ =0x00005BB7
	bl GetFile
	str r0, [r7, #0x74]
	ldr r1, _08055B08 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [r7, #0x74]
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	str r4, [r7, #0x18]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08055AFC: .4byte 0x03000124
_08055B00: .4byte 0x0000922E
_08055B04: .4byte 0x00005BB7
_08055B08: .4byte 0x0000DA6D
