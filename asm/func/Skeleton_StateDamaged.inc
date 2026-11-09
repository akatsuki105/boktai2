	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _0810CAC4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810CAC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810CACA
	.align 2, 0
_0810CAC4: .4byte 0x0000046D
_0810CAC8:
	movs r0, #0
_0810CACA:
	cmp r0, #0
	beq _0810CAD6
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0810CAD6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r3, r7, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _0810CB16
	asrs r0, r0, #2
	b _0810CB1C
_0810CB16:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0810CB1C:
	adds r4, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r7, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0810CB3A
	asrs r0, r0, #2
	b _0810CB40
_0810CB3A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0810CB40:
	adds r2, r0, #0
	cmp r4, #0xc8
	ble _0810CB4A
	movs r4, #0xc8
	b _0810CB54
_0810CB4A:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0810CB54
	adds r4, r0, #0
_0810CB54:
	cmp r2, #0xc8
	ble _0810CB5C
	movs r2, #0xc8
	b _0810CB66
_0810CB5C:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0810CB66
	adds r2, r0, #0
_0810CB66:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r4
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r4, #0
	bne _0810CB8A
	cmp r2, #0
	bne _0810CB8A
	movs r0, #1
	b _0810CB8C
_0810CB8A:
	movs r0, #0
_0810CB8C:
	cmp r0, #0
	bne _0810CB94
	bl _0810DA40
_0810CB94:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r2, _0810CBE8 @ =0x0000046B
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _0810CBEC @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	adds r5, r3, #0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r4, [r5]
	ands r4, r0
	str r4, [r5]
	ldr r1, _0810CBF0 @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0xa4]
	cmp r0, #0
	beq _0810CBF4
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0810DA40
	.align 2, 0
_0810CBE8: .4byte 0x0000046B
_0810CBEC: .4byte 0xFFFFFEDF
_0810CBF0: .4byte 0x0000049C
_0810CBF4:
	movs r1, #0x80
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0810CC06
	b _0810D318
_0810CC06:
	orrs r4, r1
	str r4, [r5]
	movs r0, #4
	ldr r4, _0810CC68 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0810CC6C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r4, r7, r6
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xb0]
	str r4, [sp, #0xa8]
	str r2, [sp, #0x80]
	cmp r5, #0
	blt _0810CC62
	cmp r1, #0
	blt _0810CC62
	ldr r0, _0810CC70 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0810CC62
	ldr r0, _0810CC74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CC78
_0810CC62:
	movs r4, #0
	b _0810CC86
	.align 2, 0
_0810CC68: .4byte 0x00000222
_0810CC6C: .4byte 0x03002BE0
_0810CC70: .4byte 0x030046A8
_0810CC74: .4byte 0x030046AC
_0810CC78:
	ldr r0, _0810CC98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810CC86:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810CC9C
	adds r0, #4
	b _0810CCA8
	.align 2, 0
_0810CC98: .4byte 0x030046A4
_0810CC9C:
	ldr r0, _0810CCBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CCA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810CCC0
	cmp r2, #2
	beq _0810CCC4
	b _0810CCC8
	.align 2, 0
_0810CCBC: .4byte 0x030046A4
_0810CCC0:
	ldrb r0, [r6, #4]
	b _0810CCC6
_0810CCC4:
	ldrb r0, [r6]
_0810CCC6:
	subs r1, r1, r0
_0810CCC8:
	strh r1, [r6, #2]
	ldr r0, _0810CCDC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810CCE0
	movs r0, #1
	b _0810CCE2
	.align 2, 0
_0810CCDC: .4byte 0x030047A4
_0810CCE0:
	movs r0, #0
_0810CCE2:
	cmp r0, #0
	beq _0810CD20
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810CD02
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810CCFE
	adds r2, r0, #0
_0810CCFE:
	cmp r2, #0
	bge _0810CD0C
_0810CD02:
	ldr r2, _0810CD08 @ =0x000005C4
	adds r0, r7, r2
	b _0810D228
	.align 2, 0
_0810CD08: .4byte 0x000005C4
_0810CD0C:
	ldr r1, _0810CD1C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810CD68
	.align 2, 0
_0810CD1C: .4byte 0x03002BE0
_0810CD20:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810CD4C
	cmp r1, #0
	blt _0810CD4C
	ldr r0, _0810CD50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810CD4C
	ldr r0, _0810CD54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CD58
_0810CD4C:
	movs r5, #0
	b _0810CD66
	.align 2, 0
_0810CD50: .4byte 0x030046A8
_0810CD54: .4byte 0x030046AC
_0810CD58:
	ldr r0, _0810CDA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810CD66:
	movs r2, #0
_0810CD68:
	ldr r4, _0810CDA4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810CD88
	ldr r1, _0810CDA8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810CD88
	b _0810D168
_0810CD88:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xa4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0810CDAC
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810CDA0: .4byte 0x030046A4
_0810CDA4: .4byte 0x00000256
_0810CDA8: .4byte 0x03002BE0
_0810CDAC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xb0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0810CE58
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _0810CE48 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x14]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _0810CE4C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x18]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0810CE50 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810CE54 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x98]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x90]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x74]
	mov r6, r8
	str r6, [sp, #0x78]
	str r5, [sp, #0xac]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	b _0810D026
	.align 2, 0
_0810CE48: .4byte 0x0000046D
_0810CE4C: .4byte 0x0000046B
_0810CE50: .4byte 0x00000469
_0810CE54: .4byte 0x00000484
_0810CE58:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0810CF18 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strb r0, [r3]
	ldr r4, _0810CF1C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0810CF20 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x28]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x2c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x34]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0810CF24 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0810CF28 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0810CF2C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa8]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x80]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x80]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	mov r0, ip
	cmp r0, #0
	blt _0810CF14
	cmp r1, #0
	blt _0810CF14
	ldr r0, _0810CF30 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810CF14
	ldr r0, _0810CF34 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CF38
_0810CF14:
	movs r4, #0
	b _0810CF48
	.align 2, 0
_0810CF18: .4byte 0x0000046D
_0810CF1C: .4byte 0x0000046B
_0810CF20: .4byte 0x00000553
_0810CF24: .4byte 0x00000469
_0810CF28: .4byte 0x0000046A
_0810CF2C: .4byte 0x00000484
_0810CF30: .4byte 0x030046A8
_0810CF34: .4byte 0x030046AC
_0810CF38:
	ldr r0, _0810CF58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0810CF48:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810CF5C
	adds r0, #4
	b _0810CF68
	.align 2, 0
_0810CF58: .4byte 0x030046A4
_0810CF5C:
	ldr r0, _0810CF7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CF68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810CF80
	cmp r2, #2
	beq _0810CF86
	b _0810CF8C
	.align 2, 0
_0810CF7C: .4byte 0x030046A4
_0810CF80:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _0810CF8A
_0810CF86:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_0810CF8A:
	subs r1, r1, r0
_0810CF8C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810CFB8
	cmp r1, #0
	blt _0810CFB8
	ldr r0, _0810CFBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810CFB8
	ldr r0, _0810CFC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CFC4
_0810CFB8:
	movs r4, #0
	b _0810CFD2
	.align 2, 0
_0810CFBC: .4byte 0x030046A8
_0810CFC0: .4byte 0x030046AC
_0810CFC4:
	ldr r0, _0810CFE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810CFD2:
	ldr r6, [sp, #0xa8]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810CFEC
	adds r0, #4
	b _0810CFF8
	.align 2, 0
_0810CFE8: .4byte 0x030046A4
_0810CFEC:
	ldr r0, _0810D00C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CFF8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810D010
	cmp r3, #2
	beq _0810D014
	b _0810D018
	.align 2, 0
_0810D00C: .4byte 0x030046A4
_0810D010:
	ldrb r0, [r5, #4]
	b _0810D016
_0810D014:
	ldrb r0, [r5]
_0810D016:
	subs r2, r2, r0
_0810D018:
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa8]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0810D026:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0810D050 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	cmp r0, #0
	bne _0810D130
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0810D054
	movs r0, #1
	b _0810D056
	.align 2, 0
_0810D050: .4byte 0x00000482
_0810D054:
	movs r0, #0
_0810D056:
	ldr r1, _0810D140 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	cmp r0, #0
	bne _0810D130
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0810D144 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0810D148 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0810D14C @ =0x0000054E
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0810D150 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _0810D154 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _0810D158 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	ldr r1, _0810D15C @ =0x030046B8
	adds r2, r4, #0
_0810D09E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0810D160 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0810D164 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810D0C2
	adds r3, #1
	cmp r3, #3
	ble _0810D09E
	adds r0, r4, #0
_0810D0C2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0x78]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0x74]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	ldr r0, [sp, #0xb4]
	strb r1, [r0]
	ldr r1, [sp, #0x7c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r0, [sp, #0x78]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
_0810D130:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810D140: .4byte 0x00000482
_0810D144: .4byte 0x0000054F
_0810D148: .4byte 0x0000054C
_0810D14C: .4byte 0x0000054E
_0810D150: .4byte 0x00000541
_0810D154: .4byte 0x000005BC
_0810D158: .4byte 0x00000542
_0810D15C: .4byte 0x030046B8
_0810D160: .4byte 0x000003FF
_0810D164: .4byte 0x0203B400
_0810D168:
	mov sb, sp
	ldr r6, _0810D1A4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810D1A8
	adds r0, #4
	b _0810D1B2
	.align 2, 0
_0810D1A4: .4byte 0x030046A4
_0810D1A8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810D1B2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0810D1EC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810D1F4
	ldr r0, _0810D1F0 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D21E
	.align 2, 0
_0810D1EC: .4byte 0x000004A4
_0810D1F0: .4byte 0xFFFFFDFF
_0810D1F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810D214
	cmp r0, #2
	beq _0810D210
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D210:
	movs r0, #1
	b _0810D220
_0810D214:
	ldr r0, _0810D234 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D21E:
	movs r0, #0
_0810D220:
	cmp r0, #0
	bne _0810D23C
	ldr r4, _0810D238 @ =0x000005C4
	adds r0, r7, r4
_0810D228:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810D234: .4byte 0xFFFFFDFF
_0810D238: .4byte 0x000005C4
_0810D23C:
	movs r0, #1
_0810D23E:
	cmp r0, #0
	bne _0810D2AE
	ldr r5, _0810D274 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810D27C
	ldr r0, _0810D278 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D2A6
	.align 2, 0
_0810D274: .4byte 0x000004A4
_0810D278: .4byte 0xFFFFFDFF
_0810D27C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810D29C
	cmp r0, #2
	beq _0810D298
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D298:
	movs r0, #1
	b _0810D2A8
_0810D29C:
	ldr r0, _0810D304 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D2A6:
	movs r0, #0
_0810D2A8:
	cmp r0, #0
	bne _0810D2AE
	b _0810D9D0
_0810D2AE:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0810D308 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0810D30C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0810D310 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0810D314 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0810DA40
	.align 2, 0
_0810D304: .4byte 0xFFFFFDFF
_0810D308: .4byte 0x0000046D
_0810D30C: .4byte 0x0000046B
_0810D310: .4byte 0x0000046A
_0810D314: .4byte 0x00000484
_0810D318:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0810D374 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #0x10
	orrs r4, r0
	str r4, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r2, [r0, #6]
	adds r3, r7, r1
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xa8]
	str r2, [sp, #0x80]
	cmp r5, #0
	blt _0810D36E
	cmp r1, #0
	blt _0810D36E
	ldr r0, _0810D378 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0810D36E
	ldr r0, _0810D37C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D380
_0810D36E:
	movs r4, #0
	b _0810D38E
	.align 2, 0
_0810D374: .4byte 0x03002BE0
_0810D378: .4byte 0x030046A8
_0810D37C: .4byte 0x030046AC
_0810D380:
	ldr r0, _0810D3A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810D38E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810D3A4
	adds r0, #4
	b _0810D3B0
	.align 2, 0
_0810D3A0: .4byte 0x030046A4
_0810D3A4:
	ldr r0, _0810D3C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D3B0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810D3C8
	cmp r2, #2
	beq _0810D3CC
	b _0810D3D0
	.align 2, 0
_0810D3C4: .4byte 0x030046A4
_0810D3C8:
	ldrb r0, [r6, #4]
	b _0810D3CE
_0810D3CC:
	ldrb r0, [r6]
_0810D3CE:
	subs r1, r1, r0
_0810D3D0:
	strh r1, [r6, #2]
	ldr r0, _0810D3E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810D3E8
	movs r0, #1
	b _0810D3EA
	.align 2, 0
_0810D3E4: .4byte 0x030047A4
_0810D3E8:
	movs r0, #0
_0810D3EA:
	cmp r0, #0
	beq _0810D420
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _0810D3FC
	b _0810D93C
_0810D3FC:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810D408
	adds r2, r0, #0
_0810D408:
	cmp r2, #0
	bge _0810D40E
	b _0810D93C
_0810D40E:
	ldr r1, _0810D41C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810D468
	.align 2, 0
_0810D41C: .4byte 0x03002BE0
_0810D420:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810D44C
	cmp r1, #0
	blt _0810D44C
	ldr r0, _0810D450 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810D44C
	ldr r0, _0810D454 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D458
_0810D44C:
	movs r5, #0
	b _0810D466
	.align 2, 0
_0810D450: .4byte 0x030046A8
_0810D454: .4byte 0x030046AC
_0810D458:
	ldr r0, _0810D4A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810D466:
	movs r2, #0
_0810D468:
	ldr r6, _0810D4A4 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810D488
	ldr r1, _0810D4A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810D488
	b _0810D87C
_0810D488:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _0810D4AC
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D4A0: .4byte 0x030046A4
_0810D4A4: .4byte 0x00000256
_0810D4A8: .4byte 0x03002BE0
_0810D4AC:
	ldr r3, _0810D550 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _0810D568
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0810D554 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0810D558 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x48]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x50]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0810D55C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0810D560 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _0810D564 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x90]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0x74]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0x78]
	str r5, [sp, #0xac]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	b _0810D73A
	.align 2, 0
_0810D550: .4byte 0x00000222
_0810D554: .4byte 0x0000046D
_0810D558: .4byte 0x0000046B
_0810D55C: .4byte 0x00000469
_0810D560: .4byte 0x00000484
_0810D564: .4byte 0x0000046C
_0810D568:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0810D62C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _0810D630 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0810D634 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x60]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x64]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0810D638 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0810D63C @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0810D640 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa8]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x80]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x80]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	mov r0, sl
	cmp r0, #0
	blt _0810D626
	cmp r1, #0
	blt _0810D626
	ldr r0, _0810D644 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0810D626
	ldr r0, _0810D648 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D64C
_0810D626:
	movs r4, #0
	b _0810D65C
	.align 2, 0
_0810D62C: .4byte 0x0000046D
_0810D630: .4byte 0x0000046B
_0810D634: .4byte 0x00000553
_0810D638: .4byte 0x00000469
_0810D63C: .4byte 0x00000484
_0810D640: .4byte 0x0000046C
_0810D644: .4byte 0x030046A8
_0810D648: .4byte 0x030046AC
_0810D64C:
	ldr r0, _0810D66C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0810D65C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810D670
	adds r0, #4
	b _0810D67C
	.align 2, 0
_0810D66C: .4byte 0x030046A4
_0810D670:
	ldr r0, _0810D690 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D67C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810D694
	cmp r2, #2
	beq _0810D69A
	b _0810D6A0
	.align 2, 0
_0810D690: .4byte 0x030046A4
_0810D694:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0810D69E
_0810D69A:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0810D69E:
	subs r1, r1, r0
_0810D6A0:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810D6CC
	cmp r1, #0
	blt _0810D6CC
	ldr r0, _0810D6D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810D6CC
	ldr r0, _0810D6D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D6D8
_0810D6CC:
	movs r4, #0
	b _0810D6E6
	.align 2, 0
_0810D6D0: .4byte 0x030046A8
_0810D6D4: .4byte 0x030046AC
_0810D6D8:
	ldr r0, _0810D6FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810D6E6:
	ldr r6, [sp, #0xa8]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0810D700
	adds r0, #4
	b _0810D70C
	.align 2, 0
_0810D6FC: .4byte 0x030046A4
_0810D700:
	ldr r0, _0810D720 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D70C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810D724
	cmp r3, #2
	beq _0810D728
	b _0810D72C
	.align 2, 0
_0810D720: .4byte 0x030046A4
_0810D724:
	ldrb r0, [r5, #4]
	b _0810D72A
_0810D728:
	ldrb r0, [r5]
_0810D72A:
	subs r2, r2, r0
_0810D72C:
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa8]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0810D73A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0810D764 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	cmp r0, #0
	bne _0810D844
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0810D768
	movs r0, #1
	b _0810D76A
	.align 2, 0
_0810D764: .4byte 0x00000482
_0810D768:
	movs r0, #0
_0810D76A:
	ldr r1, _0810D854 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	cmp r0, #0
	bne _0810D844
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0810D858 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0810D85C @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0810D860 @ =0x0000054E
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0810D864 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _0810D868 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _0810D86C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	ldr r1, _0810D870 @ =0x030046B8
	adds r2, r4, #0
_0810D7B2:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0810D874 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0810D878 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810D7D6
	adds r3, #1
	cmp r3, #3
	ble _0810D7B2
	adds r0, r4, #0
_0810D7D6:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0x78]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0x74]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	ldr r0, [sp, #0xb4]
	strb r1, [r0]
	ldr r1, [sp, #0x7c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r0, [sp, #0x78]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
_0810D844:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D854: .4byte 0x00000482
_0810D858: .4byte 0x0000054F
_0810D85C: .4byte 0x0000054C
_0810D860: .4byte 0x0000054E
_0810D864: .4byte 0x00000541
_0810D868: .4byte 0x000005BC
_0810D86C: .4byte 0x00000542
_0810D870: .4byte 0x030046B8
_0810D874: .4byte 0x000003FF
_0810D878: .4byte 0x0203B400
_0810D87C:
	add r6, sp, #8
	ldr r0, _0810D8BC @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _0810D8C0
	adds r0, #4
	b _0810D8CC
	.align 2, 0
_0810D8BC: .4byte 0x030046A4
_0810D8C0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810D8CC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0810D904 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810D90C
	ldr r0, _0810D908 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0810D936
	.align 2, 0
_0810D904: .4byte 0x000004A4
_0810D908: .4byte 0xFFFFFDFF
_0810D90C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810D92C
	cmp r0, #2
	beq _0810D928
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D928:
	movs r0, #1
	b _0810D938
_0810D92C:
	ldr r0, _0810D94C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0810D936:
	movs r0, #0
_0810D938:
	cmp r0, #0
	bne _0810D954
_0810D93C:
	ldr r3, _0810D950 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D94C: .4byte 0xFFFFFDFF
_0810D950: .4byte 0x000005C4
_0810D954:
	movs r0, #1
_0810D956:
	adds r1, r0, #0
	cmp r1, #0
	bne _0810D9E8
	ldr r4, [sp, #0x10]
	ldr r5, _0810D994 @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _0810D998 @ =0x000004A4
	adds r0, r7, r6
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0810D9A0
	ldr r0, _0810D99C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D9CA
	.align 2, 0
_0810D994: .4byte 0x00000744
_0810D998: .4byte 0x000004A4
_0810D99C: .4byte 0xFFFFFDFF
_0810D9A0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0810D9C0
	cmp r0, #2
	beq _0810D9BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D9BC:
	movs r0, #1
	b _0810D9CC
_0810D9C0:
	ldr r0, _0810D9E0 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D9CA:
	movs r0, #0
_0810D9CC:
	cmp r0, #0
	bne _0810D9E8
_0810D9D0:
	ldr r4, _0810D9E4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810DA40
	.align 2, 0
_0810D9E0: .4byte 0xFFFFFDFF
_0810D9E4: .4byte 0x000005C4
_0810D9E8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0810DA50 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0810DA54 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0810DA58 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0810DA5C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0810DA60 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_0810DA40:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810DA50: .4byte 0x0000046D
_0810DA54: .4byte 0x0000046B
_0810DA58: .4byte 0x00000469
_0810DA5C: .4byte 0x0000046A
_0810DA60: .4byte 0x00000484
