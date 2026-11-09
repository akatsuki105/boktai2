	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08204C70 @ =0x00002E78
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _08204C74 @ =0x00000235
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, _08204C78 @ =0x0000922E
	ldr r1, _08204C7C @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov r8, r0
	adds r4, #0x28
	movs r6, #0
	movs r5, #0xf
_08204C28:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r4, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r6, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x40
	strb r6, [r0]
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204C28
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08204C70: .4byte 0x00002E78
_08204C74: .4byte 0x00000235
_08204C78: .4byte 0x0000922E
_08204C7C: .4byte 0x000038E2
