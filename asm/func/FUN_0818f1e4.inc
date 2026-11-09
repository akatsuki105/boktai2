	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _0818F228 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _0818F208
	b _0818F396
_0818F208:
	movs r3, #0
	mov sl, r3
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_0818F21A:
	ldrh r0, [r7, #0x3a]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F22C
	movs r0, #1
	b _0818F22E
	.align 2, 0
_0818F228: .4byte 0x00000F36
_0818F22C:
	movs r0, #0
_0818F22E:
	cmp r0, #0
	beq _0818F234
	b _0818F378
_0818F234:
	ldrb r0, [r7, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Serpent_GetAnimVariant
	ldrh r0, [r7, #0x3a]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _0818F24C
	movs r0, #1
	b _0818F24E
_0818F24C:
	movs r0, #0
_0818F24E:
	cmp r0, #0
	beq _0818F274
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0xb
	bl AuxAnim_SetAnim
	b _0818F2A0
_0818F274:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #0xc]
	lsls r0, r3, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	bl AuxAnim_SetAnim
_0818F2A0:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0818F2D2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _0818F2DE
_0818F2D2:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_0818F2DE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0818F300
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0818F308
_0818F300:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0818F308:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0818F340 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0818F378
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818F344
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818F338
	ldrb r0, [r4, #5]
_0818F338:
	subs r0, #1
	strh r0, [r4, #8]
	b _0818F354
	.align 2, 0
_0818F340: .4byte 0x0000FFFF
_0818F344:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0818F354
	strh r1, [r4, #8]
_0818F354:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0818F378
	movs r3, #1
	strb r3, [r4, #7]
_0818F378:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _0818F3A8 @ =0x00000F36
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0818F396
	b _0818F21A
_0818F396:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F3A8: .4byte 0x00000F36
