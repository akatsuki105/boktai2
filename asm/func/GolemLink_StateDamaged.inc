	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	ldr r0, _081BCB50 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BCB54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BCB56
	.align 2, 0
_081BCB50: .4byte 0x0000046D
_081BCB54:
	movs r0, #0
_081BCB56:
	cmp r0, #0
	beq _081BCB8A
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081BCB78
	ldr r0, _081BCBBC @ =0x0000018B
	bl PlaySound_082406e0
_081BCB78:
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081BCBC0 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081BCB8A:
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
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081BCBC4
	asrs r0, r0, #2
	b _081BCBCA
	.align 2, 0
_081BCBBC: .4byte 0x0000018B
_081BCBC0: .4byte 0xFFFFFEFF
_081BCBC4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BCBCA:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081BCBEA
	asrs r0, r0, #2
	b _081BCBF0
_081BCBEA:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081BCBF0:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081BCBFA
	movs r3, #0xc8
	b _081BCC04
_081BCBFA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081BCC04
	adds r3, r0, #0
_081BCC04:
	cmp r2, #0xc8
	ble _081BCC0C
	movs r2, #0xc8
	b _081BCC16
_081BCC0C:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081BCC16
	adds r2, r0, #0
_081BCC16:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081BCC3A
	cmp r2, #0
	bne _081BCC3A
	movs r0, #1
	b _081BCC3C
_081BCC3A:
	movs r0, #0
_081BCC3C:
	cmp r0, #0
	bne _081BCC44
	bl _081BDB58
_081BCC44:
	ldr r6, _081BCCD0 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BCC52
	bl _081BDB58
_081BCC52:
	ldr r1, _081BCCD4 @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	movs r4, #0
	strh r3, [r2]
	adds r1, #0x31
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x98]
	cmp r0, #0
	beq _081BCCEC
	ldr r2, _081BCCD8 @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	ldr r3, _081BCCDC @ =0x0000046D
	adds r0, r7, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081BCCE0 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081BCCE4 @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r6, [r0]
	ldr r4, _081BCCE8 @ =0x0000046C
	adds r0, r7, r4
	strb r5, [r0]
	bl _081BDB68
	.align 2, 0
_081BCCD0: .4byte 0x0000046E
_081BCCD4: .4byte 0x0000046B
_081BCCD8: .4byte 0x00000594
_081BCCDC: .4byte 0x0000046D
_081BCCE0: .4byte 0x00000469
_081BCCE4: .4byte 0x0000046A
_081BCCE8: .4byte 0x0000046C
_081BCCEC:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _081BCCFC
	b _081BD41C
_081BCCFC:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r6, _081BCD64 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081BCD68 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r4, r7, r1
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
	str r3, [sp, #0xac]
	str r4, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _081BCD60
	cmp r1, #0
	blt _081BCD60
	ldr r0, _081BCD6C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081BCD60
	ldr r0, _081BCD70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCD74
_081BCD60:
	movs r4, #0
	b _081BCD82
	.align 2, 0
_081BCD64: .4byte 0x00000222
_081BCD68: .4byte 0x03002BE0
_081BCD6C: .4byte 0x030046A8
_081BCD70: .4byte 0x030046AC
_081BCD74:
	ldr r0, _081BCD94 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081BCD82:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BCD98
	adds r0, #4
	b _081BCDA4
	.align 2, 0
_081BCD94: .4byte 0x030046A4
_081BCD98:
	ldr r0, _081BCDB8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BCDA4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BCDBC
	cmp r2, #2
	beq _081BCDC0
	b _081BCDC4
	.align 2, 0
_081BCDB8: .4byte 0x030046A4
_081BCDBC:
	ldrb r0, [r6, #4]
	b _081BCDC2
_081BCDC0:
	ldrb r0, [r6]
_081BCDC2:
	subs r1, r1, r0
_081BCDC4:
	strh r1, [r6, #2]
	ldr r0, _081BCDD8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BCDDC
	movs r0, #1
	b _081BCDDE
	.align 2, 0
_081BCDD8: .4byte 0x030047A4
_081BCDDC:
	movs r0, #0
_081BCDDE:
	cmp r0, #0
	beq _081BCE1C
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BCDFE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BCDFA
	adds r2, r0, #0
_081BCDFA:
	cmp r2, #0
	bge _081BCE08
_081BCDFE:
	ldr r3, _081BCE04 @ =0x000005C4
	adds r0, r7, r3
	b _081BD32C
	.align 2, 0
_081BCE04: .4byte 0x000005C4
_081BCE08:
	ldr r1, _081BCE18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BCE64
	.align 2, 0
_081BCE18: .4byte 0x03002BE0
_081BCE1C:
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
	blt _081BCE48
	cmp r1, #0
	blt _081BCE48
	ldr r0, _081BCE4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BCE48
	ldr r0, _081BCE50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BCE54
_081BCE48:
	movs r5, #0
	b _081BCE62
	.align 2, 0
_081BCE4C: .4byte 0x030046A8
_081BCE50: .4byte 0x030046AC
_081BCE54:
	ldr r0, _081BCE9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BCE62:
	movs r2, #0
_081BCE64:
	ldr r6, _081BCEA0 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BCE84
	ldr r1, _081BCEA4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BCE84
	b _081BD26C
_081BCE84:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _081BCEA8
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BCE9C: .4byte 0x030046A4
_081BCEA0: .4byte 0x00000256
_081BCEA4: .4byte 0x03002BE0
_081BCEA8:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r3, [sp, #0xac]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081BCF5C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081BCF48 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081BCF4C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sb
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081BCF50 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081BCF54 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _081BCF58 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xa8]
	mov r6, r8
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _081BD12A
	.align 2, 0
_081BCF48: .4byte 0x0000046D
_081BCF4C: .4byte 0x0000046B
_081BCF50: .4byte 0x00000469
_081BCF54: .4byte 0x00000484
_081BCF58: .4byte 0x0000046C
_081BCF5C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _081BD01C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _081BD020 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081BD024 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _081BD028 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _081BD02C @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081BD030 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _081BD018
	cmp r1, #0
	blt _081BD018
	ldr r0, _081BD034 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081BD018
	ldr r0, _081BD038 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD03C
_081BD018:
	movs r4, #0
	b _081BD04C
	.align 2, 0
_081BD01C: .4byte 0x0000046D
_081BD020: .4byte 0x0000046B
_081BD024: .4byte 0x00000553
_081BD028: .4byte 0x00000469
_081BD02C: .4byte 0x0000046A
_081BD030: .4byte 0x00000484
_081BD034: .4byte 0x030046A8
_081BD038: .4byte 0x030046AC
_081BD03C:
	ldr r0, _081BD05C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081BD04C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BD060
	adds r0, #4
	b _081BD06C
	.align 2, 0
_081BD05C: .4byte 0x030046A4
_081BD060:
	ldr r0, _081BD080 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD06C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD084
	cmp r2, #2
	beq _081BD08A
	b _081BD090
	.align 2, 0
_081BD080: .4byte 0x030046A4
_081BD084:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _081BD08E
_081BD08A:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_081BD08E:
	subs r1, r1, r0
_081BD090:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BD0BC
	cmp r1, #0
	blt _081BD0BC
	ldr r0, _081BD0C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD0BC
	ldr r0, _081BD0C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD0C8
_081BD0BC:
	movs r4, #0
	b _081BD0D6
	.align 2, 0
_081BD0C0: .4byte 0x030046A8
_081BD0C4: .4byte 0x030046AC
_081BD0C8:
	ldr r0, _081BD0EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BD0D6:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BD0F0
	adds r0, #4
	b _081BD0FC
	.align 2, 0
_081BD0EC: .4byte 0x030046A4
_081BD0F0:
	ldr r0, _081BD110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD0FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BD114
	cmp r3, #2
	beq _081BD118
	b _081BD11C
	.align 2, 0
_081BD110: .4byte 0x030046A4
_081BD114:
	ldrb r0, [r5, #4]
	b _081BD11A
_081BD118:
	ldrb r0, [r5]
_081BD11A:
	subs r2, r2, r0
_081BD11C:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081BD12A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081BD154 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081BD234
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081BD158
	movs r0, #1
	b _081BD15A
	.align 2, 0
_081BD154: .4byte 0x00000482
_081BD158:
	movs r0, #0
_081BD15A:
	ldr r1, _081BD244 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081BD234
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081BD248 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081BD24C @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081BD250 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _081BD254 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BD258 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _081BD25C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _081BD260 @ =0x030046B8
	adds r2, r4, #0
_081BD1A2:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081BD264 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081BD268 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081BD1C6
	adds r3, #1
	cmp r3, #3
	ble _081BD1A2
	adds r0, r4, #0
_081BD1C6:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_081BD234:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BD244: .4byte 0x00000482
_081BD248: .4byte 0x0000054F
_081BD24C: .4byte 0x0000054C
_081BD250: .4byte 0x0000054E
_081BD254: .4byte 0x00000541
_081BD258: .4byte 0x000005BC
_081BD25C: .4byte 0x00000542
_081BD260: .4byte 0x030046B8
_081BD264: .4byte 0x000003FF
_081BD268: .4byte 0x0203B400
_081BD26C:
	mov sb, sp
	ldr r6, _081BD2A8 @ =0x030046A4
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
	beq _081BD2AC
	adds r0, #4
	b _081BD2B6
	.align 2, 0
_081BD2A8: .4byte 0x030046A4
_081BD2AC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BD2B6:
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
	ldr r6, _081BD2F0 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BD2F8
	ldr r0, _081BD2F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BD322
	.align 2, 0
_081BD2F0: .4byte 0x000004A4
_081BD2F4: .4byte 0xFFFFFDFF
_081BD2F8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BD318
	cmp r0, #2
	beq _081BD314
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BD314:
	movs r0, #1
	b _081BD324
_081BD318:
	ldr r0, _081BD338 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BD322:
	movs r0, #0
_081BD324:
	cmp r0, #0
	bne _081BD340
	ldr r4, _081BD33C @ =0x000005C4
	adds r0, r7, r4
_081BD32C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BD342
	.align 2, 0
_081BD338: .4byte 0xFFFFFDFF
_081BD33C: .4byte 0x000005C4
_081BD340:
	movs r0, #1
_081BD342:
	cmp r0, #0
	bne _081BD3B2
	ldr r5, _081BD378 @ =0x000004A4
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
	bne _081BD380
	ldr r0, _081BD37C @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BD3AA
	.align 2, 0
_081BD378: .4byte 0x000004A4
_081BD37C: .4byte 0xFFFFFDFF
_081BD380:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BD3A0
	cmp r0, #2
	beq _081BD39C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BD39C:
	movs r0, #1
	b _081BD3AC
_081BD3A0:
	ldr r0, _081BD408 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BD3AA:
	movs r0, #0
_081BD3AC:
	cmp r0, #0
	bne _081BD3B2
	b _081BDAD0
_081BD3B2:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081BD40C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081BD410 @ =0x0000046B
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
	ldr r1, _081BD414 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081BD418 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _081BDB68
	.align 2, 0
_081BD408: .4byte 0xFFFFFDFF
_081BD40C: .4byte 0x0000046D
_081BD410: .4byte 0x0000046B
_081BD414: .4byte 0x0000046A
_081BD418: .4byte 0x00000484
_081BD41C:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081BD480 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x90
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r3, [r0, #6]
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
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r5, #0
	blt _081BD47A
	cmp r1, #0
	blt _081BD47A
	ldr r0, _081BD484 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081BD47A
	ldr r0, _081BD488 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD48C
_081BD47A:
	movs r4, #0
	b _081BD49A
	.align 2, 0
_081BD480: .4byte 0x03002BE0
_081BD484: .4byte 0x030046A8
_081BD488: .4byte 0x030046AC
_081BD48C:
	ldr r0, _081BD4AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_081BD49A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BD4B0
	adds r0, #4
	b _081BD4BC
	.align 2, 0
_081BD4AC: .4byte 0x030046A4
_081BD4B0:
	ldr r0, _081BD4D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD4BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD4D4
	cmp r2, #2
	beq _081BD4D8
	b _081BD4DC
	.align 2, 0
_081BD4D0: .4byte 0x030046A4
_081BD4D4:
	ldrb r0, [r6, #4]
	b _081BD4DA
_081BD4D8:
	ldrb r0, [r6]
_081BD4DA:
	subs r1, r1, r0
_081BD4DC:
	strh r1, [r6, #2]
	ldr r0, _081BD4F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BD4F4
	movs r0, #1
	b _081BD4F6
	.align 2, 0
_081BD4F0: .4byte 0x030047A4
_081BD4F4:
	movs r0, #0
_081BD4F6:
	cmp r0, #0
	beq _081BD52C
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _081BD508
	b _081BDA48
_081BD508:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BD514
	adds r2, r0, #0
_081BD514:
	cmp r2, #0
	bge _081BD51A
	b _081BDA48
_081BD51A:
	ldr r1, _081BD528 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BD574
	.align 2, 0
_081BD528: .4byte 0x03002BE0
_081BD52C:
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
	blt _081BD558
	cmp r1, #0
	blt _081BD558
	ldr r0, _081BD55C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD558
	ldr r0, _081BD560 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD564
_081BD558:
	movs r5, #0
	b _081BD572
	.align 2, 0
_081BD55C: .4byte 0x030046A8
_081BD560: .4byte 0x030046AC
_081BD564:
	ldr r0, _081BD5AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BD572:
	movs r2, #0
_081BD574:
	ldr r6, _081BD5B0 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BD594
	ldr r1, _081BD5B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BD594
	b _081BD988
_081BD594:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x3c]
	cmp r0, #0
	beq _081BD5B8
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BD5AC: .4byte 0x030046A4
_081BD5B0: .4byte 0x00000256
_081BD5B4: .4byte 0x03002BE0
_081BD5B8:
	ldr r3, _081BD65C @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _081BD674
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081BD660 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x40]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081BD664 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x44]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x48]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x3c]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081BD668 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081BD66C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _081BD670 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xa8]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _081BD846
	.align 2, 0
_081BD65C: .4byte 0x00000222
_081BD660: .4byte 0x0000046D
_081BD664: .4byte 0x0000046B
_081BD668: .4byte 0x00000469
_081BD66C: .4byte 0x00000484
_081BD670: .4byte 0x0000046C
_081BD674:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081BD738 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _081BD73C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081BD740 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081BD744 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081BD748 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081BD74C @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xa8]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _081BD732
	cmp r1, #0
	blt _081BD732
	ldr r0, _081BD750 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081BD732
	ldr r0, _081BD754 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD758
_081BD732:
	movs r4, #0
	b _081BD768
	.align 2, 0
_081BD738: .4byte 0x0000046D
_081BD73C: .4byte 0x0000046B
_081BD740: .4byte 0x00000553
_081BD744: .4byte 0x00000469
_081BD748: .4byte 0x00000484
_081BD74C: .4byte 0x0000046C
_081BD750: .4byte 0x030046A8
_081BD754: .4byte 0x030046AC
_081BD758:
	ldr r0, _081BD778 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081BD768:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BD77C
	adds r0, #4
	b _081BD788
	.align 2, 0
_081BD778: .4byte 0x030046A4
_081BD77C:
	ldr r0, _081BD79C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD788:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BD7A0
	cmp r2, #2
	beq _081BD7A6
	b _081BD7AC
	.align 2, 0
_081BD79C: .4byte 0x030046A4
_081BD7A0:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _081BD7AA
_081BD7A6:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_081BD7AA:
	subs r1, r1, r0
_081BD7AC:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BD7D8
	cmp r1, #0
	blt _081BD7D8
	ldr r0, _081BD7DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BD7D8
	ldr r0, _081BD7E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BD7E4
_081BD7D8:
	movs r4, #0
	b _081BD7F2
	.align 2, 0
_081BD7DC: .4byte 0x030046A8
_081BD7E0: .4byte 0x030046AC
_081BD7E4:
	ldr r0, _081BD808 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BD7F2:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BD80C
	adds r0, #4
	b _081BD818
	.align 2, 0
_081BD808: .4byte 0x030046A4
_081BD80C:
	ldr r0, _081BD82C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BD818:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BD830
	cmp r3, #2
	beq _081BD834
	b _081BD838
	.align 2, 0
_081BD82C: .4byte 0x030046A4
_081BD830:
	ldrb r0, [r5, #4]
	b _081BD836
_081BD834:
	ldrb r0, [r5]
_081BD836:
	subs r2, r2, r0
_081BD838:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081BD846:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081BD870 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081BD950
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081BD874
	movs r0, #1
	b _081BD876
	.align 2, 0
_081BD870: .4byte 0x00000482
_081BD874:
	movs r0, #0
_081BD876:
	ldr r1, _081BD960 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081BD950
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081BD964 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081BD968 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081BD96C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r0, _081BD970 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081BD974 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb4]
	ldr r2, _081BD978 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	ldr r1, _081BD97C @ =0x030046B8
	adds r2, r4, #0
_081BD8BE:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081BD980 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081BD984 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081BD8E2
	adds r3, #1
	cmp r3, #3
	ble _081BD8BE
	adds r0, r4, #0
_081BD8E2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xa8]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa0]
	strb r0, [r4]
_081BD950:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BD960: .4byte 0x00000482
_081BD964: .4byte 0x0000054F
_081BD968: .4byte 0x0000054C
_081BD96C: .4byte 0x0000054E
_081BD970: .4byte 0x00000541
_081BD974: .4byte 0x000005BC
_081BD978: .4byte 0x00000542
_081BD97C: .4byte 0x030046B8
_081BD980: .4byte 0x000003FF
_081BD984: .4byte 0x0203B400
_081BD988:
	add r6, sp, #8
	ldr r0, _081BD9C8 @ =0x030046A4
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
	beq _081BD9CC
	adds r0, #4
	b _081BD9D8
	.align 2, 0
_081BD9C8: .4byte 0x030046A4
_081BD9CC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BD9D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081BDA10 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BDA18
	ldr r0, _081BDA14 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081BDA42
	.align 2, 0
_081BDA10: .4byte 0x000004A4
_081BDA14: .4byte 0xFFFFFDFF
_081BDA18:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BDA38
	cmp r0, #2
	beq _081BDA34
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BDA34:
	movs r0, #1
	b _081BDA44
_081BDA38:
	ldr r0, _081BDA58 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081BDA42:
	movs r0, #0
_081BDA44:
	cmp r0, #0
	bne _081BDA60
_081BDA48:
	ldr r3, _081BDA5C @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081BDA62
	.align 2, 0
_081BDA58: .4byte 0xFFFFFDFF
_081BDA5C: .4byte 0x000005C4
_081BDA60:
	movs r0, #1
_081BDA62:
	cmp r0, #0
	bne _081BDAE8
	ldr r4, _081BDA98 @ =0x000004A4
	adds r0, r7, r4
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
	bne _081BDAA0
	ldr r0, _081BDA9C @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BDACA
	.align 2, 0
_081BDA98: .4byte 0x000004A4
_081BDA9C: .4byte 0xFFFFFDFF
_081BDAA0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BDAC0
	cmp r0, #2
	beq _081BDABC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BDABC:
	movs r0, #1
	b _081BDACC
_081BDAC0:
	ldr r0, _081BDAE0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BDACA:
	movs r0, #0
_081BDACC:
	cmp r0, #0
	bne _081BDAE8
_081BDAD0:
	ldr r4, _081BDAE4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081BDB68
	.align 2, 0
_081BDAE0: .4byte 0xFFFFFDFF
_081BDAE4: .4byte 0x000005C4
_081BDAE8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081BDB44 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081BDB48 @ =0x0000046B
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
	ldr r6, _081BDB4C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BDB50 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081BDB54 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	b _081BDB68
	.align 2, 0
_081BDB44: .4byte 0x0000046D
_081BDB48: .4byte 0x0000046B
_081BDB4C: .4byte 0x00000469
_081BDB50: .4byte 0x0000046A
_081BDB54: .4byte 0x00000484

_081BDB58:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081BDB68:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
