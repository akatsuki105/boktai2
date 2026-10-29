	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08023E04
	b _08023FDA
_08023E04:
	bl Entity08058ffc_GetActiveCount
	cmp r0, #0xb
	ble _08023E0E
	b _08023FDA
_08023E0E:
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	mov ip, r3
	ldrh r0, [r3, #4]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08023EB4 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r4
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r0, _08023EB8 @ =0x0203B400
	mov sl, r0
	ldr r1, _08023EBC @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r3, _08023EC0 @ =0x000003FF
	mov r8, r3
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	add r0, sp, #8
	ldrh r1, [r0]
	subs r1, #0x40
	movs r6, #0x7f
	ands r3, r6
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	adds r2, #1
	mov r0, r8
	ands r2, r0
	mov r1, sb
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sl
	ldrh r1, [r2]
	mov r2, ip
	ldrh r0, [r2, #4]
	subs r0, #0x40
	ands r1, r6
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r4, r5
	orrs r4, r0
	str r4, [sp, #0xc]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08023EAE
	cmp r1, #0
	blt _08023EAE
	ldr r0, _08023EC4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08023EAE
	ldr r0, _08023EC8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08023ECC
_08023EAE:
	movs r4, #0
	b _08023EDA
	.align 2, 0
_08023EB4: .4byte 0xFFFF0000
_08023EB8: .4byte 0x0203B400
_08023EBC: .4byte 0x030046B8
_08023EC0: .4byte 0x000003FF
_08023EC4: .4byte 0x030046A8
_08023EC8: .4byte 0x030046AC
_08023ECC:
	ldr r0, _08023EEC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08023EDA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08023EF0
	adds r0, #4
	b _08023EFC
	.align 2, 0
_08023EEC: .4byte 0x030046A4
_08023EF0:
	ldr r0, _08023F10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08023EFC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08023F14
	cmp r2, #2
	beq _08023F18
	b _08023F1C
	.align 2, 0
_08023F10: .4byte 0x030046A4
_08023F14:
	ldrb r0, [r5, #4]
	b _08023F1A
_08023F18:
	ldrb r0, [r5]
_08023F1A:
	subs r1, r1, r0
_08023F1C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _08023FDA
	add r1, sp, #8
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08023F4C
	cmp r1, #0
	blt _08023F4C
	ldr r0, _08023F50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08023F4C
	ldr r0, _08023F54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08023F58
_08023F4C:
	movs r4, #0
	b _08023F66
	.align 2, 0
_08023F50: .4byte 0x030046A8
_08023F54: .4byte 0x030046AC
_08023F58:
	ldr r0, _08023F78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08023F66:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08023F7C
	adds r0, #4
	b _08023F88
	.align 2, 0
_08023F78: .4byte 0x030046A4
_08023F7C:
	ldr r0, _08023FEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08023F88:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08023FDA
	ldr r2, _08023FF0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08023FF4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08023FF8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	ldr r4, _08023FFC @ =0x0000078E
	adds r0, r7, r4
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r4, #2
	adds r0, r7, r4
	movs r4, #0
	ldrsh r3, [r0, r4]
	ldr r4, _08024000 @ =0x00000792
	adds r0, r7, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	movs r0, #1
	bl FUN_08059054
	movs r2, #0xaa
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08023FDA:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023FEC: .4byte 0x030046A4
_08023FF0: .4byte 0x030046B8
_08023FF4: .4byte 0x000003FF
_08023FF8: .4byte 0x0203B400
_08023FFC: .4byte 0x0000078E
_08024000: .4byte 0x00000792
