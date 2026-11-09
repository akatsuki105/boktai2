	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r2, #0
	str r2, [sp, #4]
	ldr r4, _081927D0 @ =0x00000F36
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	blt _0819279C
	b _081928C6
_0819279C:
	ldr r2, _081927D4 @ =0x00000676
	adds r2, r2, r6
	mov r8, r2
	str r6, [sp, #8]
	movs r3, #0
	ldr r4, _081927D8 @ =0x00000734
	adds r5, r6, r4
	ldr r0, _081927DC @ =0x0000075B
	adds r7, r6, r0
	str r7, [sp, #0xc]
	ldr r1, _081927E0 @ =0x0000077A
	adds r1, r1, r6
	mov sl, r1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
_081927BE:
	mov r4, sl
	ldrh r0, [r4]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081927E4
	movs r0, #1
	b _081927E6
	.align 2, 0
_081927D0: .4byte 0x00000F36
_081927D4: .4byte 0x00000676
_081927D8: .4byte 0x00000734
_081927DC: .4byte 0x0000075B
_081927E0: .4byte 0x0000077A
_081927E4:
	movs r0, #0
_081927E6:
	cmp r0, #0
	beq _0819281C
	ldrb r0, [r7]
	adds r4, r0, #0
	cmp r4, #0
	beq _081927F8
	subs r0, #1
	strb r0, [r7]
	b _0819281C
_081927F8:
	adds r0, r3, r6
	ldr r2, _08192850 @ =0x00000684
	adds r0, r0, r2
	ldr r1, _08192854 @ =0x000001A3
	str r3, [sp, #0x10]
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r1, [sp, #8]
	ldr r4, _08192858 @ =0x0000077A
	adds r2, r1, r4
	ldrh r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
	ldr r3, [sp, #0x10]
_0819281C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08192898
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08192860
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, [sp]
	ldr r2, _0819285C @ =0x00000472
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _0819286C
	mov r4, sb
	adds r0, r4, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0819286A
	.align 2, 0
_08192850: .4byte 0x00000684
_08192854: .4byte 0x000001A3
_08192858: .4byte 0x0000077A
_0819285C: .4byte 0x00000472
_08192860:
	mov r1, sb
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0819286A:
	str r1, [r0]
_0819286C:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08192898
	mov r2, r8
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r2, [sp]
	ldr r4, _081928D8 @ =0x00000472
	adds r0, r2, r4
	ldrh r0, [r0]
	cmp r1, r0
	blt _08192898
	mov r1, sb
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_08192898:
	movs r2, #0x92
	lsls r2, r2, #1
	add r8, r2
	ldr r4, [sp, #8]
	adds r4, r4, r2
	str r4, [sp, #8]
	adds r3, r3, r2
	adds r5, r5, r2
	adds r7, r7, r2
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	add sl, r2
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	ldr r2, _081928DC @ =0x00000F36
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081928C6
	b _081927BE
_081928C6:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081928D8: .4byte 0x00000472
_081928DC: .4byte 0x00000F36
