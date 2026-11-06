	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	mov sl, r1
	ldr r0, _081F7C48 @ =0x03000204
	ldr r5, [r0]
	cmp r5, #0
	bne _081F7BB0
	bl Entity081f7de4_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _081F7BB0
	b _081F7D10
_081F7BB0:
	adds r0, r5, #0
	bl Entity081f7de4_AllocElem
	mov sb, r0
	cmp r0, #0
	bne _081F7BBE
	b _081F7D10
_081F7BBE:
	adds r0, #0x96
	movs r1, #0
	mov r8, r1
	movs r6, #1
	strb r6, [r0]
	mov r1, sb
	adds r1, #0x90
	movs r0, #0x78
	str r0, [r1]
	mov r0, sb
	adds r0, #0x94
	mov r2, r8
	strh r2, [r0]
	adds r0, #6
	strb r6, [r0]
	mov r7, sb
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _081F7C4C @ =0x0000922E
	ldr r1, _081F7C50 @ =0x00008DC7
	bl GetFile
	adds r4, r7, #0
	adds r4, #0x8c
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
	ldr r1, _081F7C54 @ =0x00000275
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	adds r1, r6, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r6
	cmp r1, r0
	beq _081F7C58
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F7C60
	.align 2, 0
_081F7C48: .4byte 0x03000204
_081F7C4C: .4byte 0x0000922E
_081F7C50: .4byte 0x00008DC7
_081F7C54: .4byte 0x00000275
_081F7C58:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F7C60:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F7C86
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F7C90
_081F7C86:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7C90:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F7CC8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F7D00
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7CCC
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F7CC2
	ldrb r0, [r5, #5]
_081F7CC2:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F7CDC
	.align 2, 0
_081F7CC8: .4byte 0x0000FFFF
_081F7CCC:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F7CDC
	strh r1, [r5, #8]
_081F7CDC:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F7D00
	movs r0, #1
	strb r0, [r5, #7]
_081F7D00:
	movs r0, #1
	strb r0, [r7, #7]
	ldr r0, [r7]
	ldr r1, _081F7D20 @ =0x00000202
	orrs r0, r1
	str r0, [r7]
	mov r0, sl
	strb r0, [r7, #6]
_081F7D10:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F7D20: .4byte 0x00000202
