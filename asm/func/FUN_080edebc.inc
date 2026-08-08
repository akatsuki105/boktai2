	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	ldr r0, _080EDEF4 @ =0x03002C60
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _080EDED6
	b _080EE208
_080EDED6:
	ldr r5, [r0, #4]
_080EDED8:
	cmp r5, #0
	bne _080EDEDE
	b _080EE208
_080EDEDE:
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EDEF8
	movs r0, #1
	b _080EDEFA
	.align 2, 0
_080EDEF4: .4byte 0x03002C60
_080EDEF8:
	movs r0, #0
_080EDEFA:
	cmp r0, #0
	beq _080EDF26
	mov r3, sb
	ldr r3, [r3]
	mov sb, r3
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r4, [r0]
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Free
	mov r2, sb
	ldr r5, [r2, #4]
	b _080EDED8
_080EDF26:
	ldr r3, _080EDF4C @ =0x0000061C
	adds r1, r5, r3
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	ldr r0, _080EDF50 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080EDF54
	movs r0, #1
	b _080EDF56
	.align 2, 0
_080EDF4C: .4byte 0x0000061C
_080EDF50: .4byte 0x030047A4
_080EDF54:
	movs r0, #0
_080EDF56:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r4, r5, r1
	cmp r0, #0
	beq _080EDF62
	b _080EE070
_080EDF62:
	movs r1, #0x80
	lsls r1, r1, #7
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080EDF70
	b _080EE070
_080EDF70:
	movs r1, #8
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080EE070
	ldr r3, _080EDFC8 @ =0x0000046F
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080EE070
	movs r3, #2
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r3
	adds r6, r1, #0
	cmp r0, #0
	bne _080EE070
	ldr r0, _080EDFCC @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _080EDFD0 @ =0x00000934
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080EE070
	movs r3, #0x92
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080EDFD4
	movs r0, #1
	b _080EDFD6
	.align 2, 0
_080EDFC8: .4byte 0x0000046F
_080EDFCC: .4byte 0x030046A0
_080EDFD0: .4byte 0x00000934
_080EDFD4:
	movs r0, #0
_080EDFD6:
	cmp r0, #0
	beq _080EE070
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EE070
	ldr r0, _080EE02C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080EE030 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _080EE070
	ldr r0, _080EE034 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080EE002
	movs r1, #1
_080EE002:
	cmp r1, #0
	bne _080EE070
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	ldr r2, _080EE038 @ =0x000004BE
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080EE03C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EE040
	ldr r2, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080EE04E
	.align 2, 0
_080EE02C: .4byte 0x030046A0
_080EE030: .4byte 0x00000942
_080EE034: .4byte 0x03002B80
_080EE038: .4byte 0x000004BE
_080EE03C: .4byte 0x0000025D
_080EE040:
	ldr r0, [r5, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080EE04E:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080e64e4
	ldr r0, _080EE090 @ =0xFFFFDFFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_080EE070:
	movs r1, #0x80
	lsls r1, r1, #7
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080EE07E
	b _080EE1F8
_080EE07E:
	movs r1, #0x80
	lsls r1, r1, #6
	mov r2, sl
	ldr r0, [r2, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080EE094
	movs r0, #1
	b _080EE096
	.align 2, 0
_080EE090: .4byte 0xFFFFDFFF
_080EE094:
	movs r0, #0
_080EE096:
	cmp r0, #0
	bne _080EE09C
	b _080EE1F8
_080EE09C:
	ldr r3, _080EE0B4 @ =0x000001DF
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0x17
	beq _080EE0BE
	cmp r1, #0x17
	bgt _080EE0B8
	cmp r1, #0xb
	beq _080EE0BE
	b _080EE1F8
	.align 2, 0
_080EE0B4: .4byte 0x000001DF
_080EE0B8:
	cmp r1, #0x1b
	beq _080EE0BE
	b _080EE1F8
_080EE0BE:
	ldr r1, _080EE0E8 @ =0x02008000
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080EE0FE
	ldr r1, _080EE0EC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EE0F0
	ldr r0, [r5, #0x44]
	movs r2, #0x8f
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	strh r1, [r0, #0x32]
	b _080EE0FE
	.align 2, 0
_080EE0E8: .4byte 0x02008000
_080EE0EC: .4byte 0x0000025D
_080EE0F0:
	ldr r0, [r5, #0x44]
	adds r0, #0x20
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r1, r5, r4
	ldrh r1, [r1]
	strh r1, [r0, #0x3a]
_080EE0FE:
	mov r0, sl
	adds r1, r5, #0
	str r3, [sp, #4]
	bl FUN_080eec74
	lsls r0, r0, #0x18
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _080EE1F8
	movs r0, #0x80
	lsls r0, r0, #0xa
	mov r2, sl
	ldr r1, [r2, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080EE122
	movs r0, #1
	b _080EE124
_080EE122:
	movs r0, #0
_080EE124:
	adds r7, r0, #0
	cmp r7, #0
	beq _080EE188
	ldr r0, _080EE164 @ =0xFFFDDFFF
	ands r0, r1
	mov r3, sl
	str r0, [r3, #0x2c]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r5, r4
	ldr r1, _080EE168 @ =0xFFDFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _080EE16C @ =0x0000047A
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r3, _080EE170 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EE174
	ldr r0, [r5, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _080EE1F8
	.align 2, 0
_080EE164: .4byte 0xFFFDDFFF
_080EE168: .4byte 0xFFDFFFFF
_080EE16C: .4byte 0x0000047A
_080EE170: .4byte 0x0000025D
_080EE174:
	ldr r2, [r5, #0x44]
	ldr r0, _080EE184 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
	b _080EE1F8
	.align 2, 0
_080EE184: .4byte 0x03003584
_080EE188:
	movs r4, #0x80
	lsls r4, r4, #0xe
	mov r8, r4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r4, [r6]
	mov r1, r8
	ands r4, r1
	cmp r4, #0
	beq _080EE1D0
	movs r2, #0x8f
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r4, _080EE1C8 @ =0x0000047A
	adds r1, r5, r4
	ldrh r1, [r1]
	adds r4, #6
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r1, r1, r2
	ldrb r3, [r3]
	str r7, [sp]
	movs r2, #0
	bl FUN_080eeb14
	ldr r1, _080EE1CC @ =0xFFDFFFFF
	ldr r0, [r6]
	ands r0, r1
	b _080EE1F6
	.align 2, 0
_080EE1C8: .4byte 0x0000047A
_080EE1CC: .4byte 0xFFDFFFFF
_080EE1D0:
	ldr r1, _080EE204 @ =0x0000047A
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r5, r2
	ldrh r1, [r1]
	ldrb r3, [r3]
	str r4, [sp]
	movs r2, #0
	bl FUN_080eeb14
	ldr r0, [r6]
	mov r3, r8
	orrs r0, r3
_080EE1F6:
	str r0, [r6]
_080EE1F8:
	mov r4, sb
	ldr r4, [r4]
	mov sb, r4
	ldr r5, [r4, #4]
	b _080EDED8
	.align 2, 0
_080EE204: .4byte 0x0000047A
_080EE208:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
