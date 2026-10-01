	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sl, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	rsbs r4, r3, #0
	orrs r4, r3
	asrs r4, r4, #0x1f
	movs r0, #4
	ands r4, r0
	mov r1, sl
	lsls r0, r1, #2
	movs r2, #0x9c
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r5, r7, #0
	adds r5, #0x60
	movs r1, #0xd9
	lsls r1, r1, #6
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r6, r7, #0
	adds r6, #8
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl AuxSprite_Add
	mov r1, r8
	ldrb r0, [r1]
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl Video_SetAuxSpritePltt
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r7, #0x24]
	str r1, [r7, #0x28]
	movs r0, #3
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x9d
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp]
	mov r3, sb
	bl FUN_0809e198
	adds r0, r7, #0
	bl GetMapAreaAt
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
