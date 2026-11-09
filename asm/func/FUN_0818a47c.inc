	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, _0818A4A4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A4A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A4AA
	.align 2, 0
_0818A4A4: .4byte 0x0000046D
_0818A4A8:
	movs r0, #0
_0818A4AA:
	cmp r0, #0
	beq _0818A4BC
	ldr r0, _0818A508 @ =0x00000F36
	add r0, r8
	ldrh r0, [r0]
	subs r0, #1
	ldr r1, _0818A50C @ =0x00000ECA
	add r1, r8
	strh r0, [r1]
_0818A4BC:
	ldr r1, _0818A510 @ =0x00000C2A
	add r1, r8
	ldrh r0, [r1]
	subs r0, #0x80
	strh r0, [r1]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Serpent_GetAnimVariant
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0818A514 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818A520
	ldr r1, _0818A518 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r0, _0818A51C @ =0x0000046E
	adds r7, r5, r0
	b _0818A5A2
	.align 2, 0
_0818A508: .4byte 0x00000F36
_0818A50C: .4byte 0x00000ECA
_0818A510: .4byte 0x00000C2A
_0818A514: .4byte 0x0000025D
_0818A518: .4byte 0x000004B7
_0818A51C: .4byte 0x0000046E
_0818A520:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0818A590 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0818A594 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0818A55A
	ldrb r0, [r7]
	cmp r0, #0
	bne _0818A55A
	cmp r4, #1
	bne _0818A54C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0818A5A6
_0818A54C:
	cmp r4, #0
	bne _0818A55A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0818A5A6
_0818A55A:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0818A56C
	movs r3, #6
_0818A56C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0818A598
	ldr r0, [r6, #8]
	mov r1, sb
	orrs r0, r1
	b _0818A5A0
	.align 2, 0
_0818A590: .4byte 0x000004B7
_0818A594: .4byte 0x0000046E
_0818A598:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0818A5A0:
	str r0, [r6, #8]
_0818A5A2:
	movs r0, #0
	strb r0, [r7]
_0818A5A6:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	bl FUN_0818f1e4
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0818A5E4
	ldr r2, _0818A5F4 @ =0x00000F2C
	add r2, r8
	ldr r0, _0818A5F8 @ =0xFFFFDFFF
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r0, _0818A5FC @ =0x00000ECA
	add r0, r8
	strh r1, [r0]
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r5, r1
	bl AuxShadow_Hide
	ldr r1, _0818A600 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
_0818A5E4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818A5F4: .4byte 0x00000F2C
_0818A5F8: .4byte 0xFFFFDFFF
_0818A5FC: .4byte 0x00000ECA
_0818A600: .4byte 0x0000046B
