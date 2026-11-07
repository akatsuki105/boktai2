	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _0814CD1C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CD20
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CD22
	.align 2, 0
_0814CD1C: .4byte 0x0000046D
_0814CD20:
	movs r0, #0
_0814CD22:
	cmp r0, #0
	beq _0814CD80
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0814CD38
	asrs r1, r0, #2
	b _0814CD3E
_0814CD38:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0814CD3E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0814CD58
	asrs r1, r0, #2
	b _0814CD5E
_0814CD58:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0814CD5E:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _0814CDB0 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_0814CD80:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814CDB4
	asrs r0, r0, #2
	b _0814CDBA
	.align 2, 0
_0814CDB0: .4byte 0xFFFFFEFF
_0814CDB4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0814CDBA:
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
	blt _0814CDDA
	asrs r0, r0, #2
	b _0814CDE0
_0814CDDA:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0814CDE0:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0814CDEA
	movs r3, #0xc8
	b _0814CDF4
_0814CDEA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0814CDF4
	adds r3, r0, #0
_0814CDF4:
	cmp r2, #0xc8
	ble _0814CDFC
	movs r2, #0xc8
	b _0814CE06
_0814CDFC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0814CE06
	adds r2, r0, #0
_0814CE06:
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
	bne _0814CE2A
	cmp r2, #0
	bne _0814CE2A
	movs r0, #1
	b _0814CE2C
_0814CE2A:
	movs r0, #0
_0814CE2C:
	cmp r0, #0
	bne _0814CE34
	bl _0814DD18
_0814CE34:
	ldr r6, _0814CE80 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CE42
	bl _0814DD18
_0814CE42:
	ldr r0, _0814CE84 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _0814CE88 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _0814CE8C
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0814DD28
	.align 2, 0
_0814CE80: .4byte 0x0000046E
_0814CE84: .4byte 0x0000046B
_0814CE88: .4byte 0x0000049C
_0814CE8C:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0814CE9C
	b _0814D5CC
_0814CE9C:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0814CEF8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _0814CEF2
	cmp r1, #0
	blt _0814CEF2
	ldr r0, _0814CEFC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814CEF2
	ldr r0, _0814CF00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814CF04
_0814CEF2:
	movs r4, #0
	b _0814CF12
	.align 2, 0
_0814CEF8: .4byte 0x03002BE0
_0814CEFC: .4byte 0x030046A8
_0814CF00: .4byte 0x030046AC
_0814CF04:
	ldr r0, _0814CF24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814CF12:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814CF28
	adds r0, #4
	b _0814CF34
	.align 2, 0
_0814CF24: .4byte 0x030046A4
_0814CF28:
	ldr r0, _0814CF48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814CF34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814CF4C
	cmp r2, #2
	beq _0814CF50
	b _0814CF54
	.align 2, 0
_0814CF48: .4byte 0x030046A4
_0814CF4C:
	ldrb r0, [r5, #4]
	b _0814CF52
_0814CF50:
	ldrb r0, [r5]
_0814CF52:
	subs r1, r1, r0
_0814CF54:
	strh r1, [r5, #2]
	ldr r0, _0814CF68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814CF6C
	movs r0, #1
	b _0814CF6E
	.align 2, 0
_0814CF68: .4byte 0x030047A4
_0814CF6C:
	movs r0, #0
_0814CF6E:
	cmp r0, #0
	beq _0814CFAC
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0814CF8E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814CF8A
	adds r2, r0, #0
_0814CF8A:
	cmp r2, #0
	bge _0814CF98
_0814CF8E:
	ldr r3, _0814CF94 @ =0x000005C4
	adds r0, r7, r3
	b _0814D4C8
	.align 2, 0
_0814CF94: .4byte 0x000005C4
_0814CF98:
	ldr r1, _0814CFA8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814CFF4
	.align 2, 0
_0814CFA8: .4byte 0x03002BE0
_0814CFAC:
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
	blt _0814CFD8
	cmp r1, #0
	blt _0814CFD8
	ldr r0, _0814CFDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814CFD8
	ldr r0, _0814CFE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814CFE4
_0814CFD8:
	movs r5, #0
	b _0814CFF2
	.align 2, 0
_0814CFDC: .4byte 0x030046A8
_0814CFE0: .4byte 0x030046AC
_0814CFE4:
	ldr r0, _0814D02C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814CFF2:
	movs r2, #0
_0814CFF4:
	ldr r6, _0814D030 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814D014
	ldr r1, _0814D034 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814D014
	b _0814D408
_0814D014:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x9c]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _0814D038
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D02C: .4byte 0x030046A4
_0814D030: .4byte 0x00000256
_0814D034: .4byte 0x03002BE0
_0814D038:
	ldr r3, _0814D0DC @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _0814D0F4
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0814D0E0 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0814D0E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x18]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0814D0E8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0814D0EC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x10]
	str r6, [r1]
	ldr r6, _0814D0F0 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _0814D2C6
	.align 2, 0
_0814D0DC: .4byte 0x00000222
_0814D0E0: .4byte 0x0000046D
_0814D0E4: .4byte 0x0000046B
_0814D0E8: .4byte 0x00000469
_0814D0EC: .4byte 0x00000484
_0814D0F0: .4byte 0x0000046C
_0814D0F4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814D1B8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _0814D1BC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814D1C0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0814D1C4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0814D1C8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0814D1CC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _0814D1B2
	cmp r1, #0
	blt _0814D1B2
	ldr r0, _0814D1D0 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0814D1B2
	ldr r0, _0814D1D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D1D8
_0814D1B2:
	movs r4, #0
	b _0814D1E8
	.align 2, 0
_0814D1B8: .4byte 0x0000046D
_0814D1BC: .4byte 0x0000046B
_0814D1C0: .4byte 0x00000553
_0814D1C4: .4byte 0x00000469
_0814D1C8: .4byte 0x00000484
_0814D1CC: .4byte 0x0000046C
_0814D1D0: .4byte 0x030046A8
_0814D1D4: .4byte 0x030046AC
_0814D1D8:
	ldr r0, _0814D1F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0814D1E8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814D1FC
	adds r0, #4
	b _0814D208
	.align 2, 0
_0814D1F8: .4byte 0x030046A4
_0814D1FC:
	ldr r0, _0814D21C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D208:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D220
	cmp r2, #2
	beq _0814D226
	b _0814D22C
	.align 2, 0
_0814D21C: .4byte 0x030046A4
_0814D220:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _0814D22A
_0814D226:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_0814D22A:
	subs r1, r1, r0
_0814D22C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D258
	cmp r1, #0
	blt _0814D258
	ldr r0, _0814D25C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D258
	ldr r0, _0814D260 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D264
_0814D258:
	movs r4, #0
	b _0814D272
	.align 2, 0
_0814D25C: .4byte 0x030046A8
_0814D260: .4byte 0x030046AC
_0814D264:
	ldr r0, _0814D288 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814D272:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814D28C
	adds r0, #4
	b _0814D298
	.align 2, 0
_0814D288: .4byte 0x030046A4
_0814D28C:
	ldr r0, _0814D2AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814D2B0
	cmp r3, #2
	beq _0814D2B4
	b _0814D2B8
	.align 2, 0
_0814D2AC: .4byte 0x030046A4
_0814D2B0:
	ldrb r0, [r5, #4]
	b _0814D2B6
_0814D2B4:
	ldrb r0, [r5]
_0814D2B6:
	subs r2, r2, r0
_0814D2B8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814D2C6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814D2F0 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _0814D3D0
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814D2F4
	movs r0, #1
	b _0814D2F6
	.align 2, 0
_0814D2F0: .4byte 0x00000482
_0814D2F4:
	movs r0, #0
_0814D2F6:
	ldr r1, _0814D3E0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _0814D3D0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0814D3E4 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814D3E8 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814D3EC @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814D3F0 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0814D3F4 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0814D3F8 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814D3FC @ =0x030046B8
	adds r2, r4, #0
_0814D33E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814D400 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814D404 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814D362
	adds r3, #1
	cmp r3, #3
	ble _0814D33E
	adds r0, r4, #0
_0814D362:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814D3D0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D3E0: .4byte 0x00000482
_0814D3E4: .4byte 0x0000054F
_0814D3E8: .4byte 0x0000054C
_0814D3EC: .4byte 0x0000054E
_0814D3F0: .4byte 0x00000541
_0814D3F4: .4byte 0x000005BC
_0814D3F8: .4byte 0x00000542
_0814D3FC: .4byte 0x030046B8
_0814D400: .4byte 0x000003FF
_0814D404: .4byte 0x0203B400
_0814D408:
	mov sb, sp
	ldr r6, _0814D444 @ =0x030046A4
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
	beq _0814D448
	adds r0, #4
	b _0814D452
	.align 2, 0
_0814D444: .4byte 0x030046A4
_0814D448:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814D452:
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
	ldr r6, _0814D48C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0814D494
	ldr r0, _0814D490 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814D4BE
	.align 2, 0
_0814D48C: .4byte 0x000004A4
_0814D490: .4byte 0xFFFFFDFF
_0814D494:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814D4B4
	cmp r0, #2
	beq _0814D4B0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814D4B0:
	movs r0, #1
	b _0814D4C0
_0814D4B4:
	ldr r0, _0814D4D4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814D4BE:
	movs r0, #0
_0814D4C0:
	cmp r0, #0
	bne _0814D4DC
	ldr r4, _0814D4D8 @ =0x000005C4
	adds r0, r7, r4
_0814D4C8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D4D4: .4byte 0xFFFFFDFF
_0814D4D8: .4byte 0x000005C4
_0814D4DC:
	movs r0, #1
_0814D4DE:
	cmp r0, #0
	bne _0814D54E
	ldr r5, _0814D514 @ =0x000004A4
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
	bne _0814D51C
	ldr r0, _0814D518 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814D546
	.align 2, 0
_0814D514: .4byte 0x000004A4
_0814D518: .4byte 0xFFFFFDFF
_0814D51C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814D53C
	cmp r0, #2
	beq _0814D538
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814D538:
	movs r0, #1
	b _0814D548
_0814D53C:
	ldr r0, _0814D5B0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814D546:
	movs r0, #0
_0814D548:
	cmp r0, #0
	bne _0814D54E
	b _0814DC90
_0814D54E:
	movs r0, #4
	ldr r5, _0814D5B4 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _0814D5B8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0814D5BC @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _0814D5C0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0814D5C4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _0814D5C8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _0814DD28
	.align 2, 0
_0814D5B0: .4byte 0xFFFFFDFF
_0814D5B4: .4byte 0x00000222
_0814D5B8: .4byte 0x0000046D
_0814D5BC: .4byte 0x0000046B
_0814D5C0: .4byte 0x00000469
_0814D5C4: .4byte 0x0000046A
_0814D5C8: .4byte 0x0000046C
_0814D5CC:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _0814D630 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _0814D62A
	cmp r1, #0
	blt _0814D62A
	ldr r0, _0814D634 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814D62A
	ldr r0, _0814D638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D63C
_0814D62A:
	movs r4, #0
	b _0814D64A
	.align 2, 0
_0814D630: .4byte 0x03002BE0
_0814D634: .4byte 0x030046A8
_0814D638: .4byte 0x030046AC
_0814D63C:
	ldr r0, _0814D65C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814D64A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814D660
	adds r0, #4
	b _0814D66C
	.align 2, 0
_0814D65C: .4byte 0x030046A4
_0814D660:
	ldr r0, _0814D680 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D66C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D684
	cmp r2, #2
	beq _0814D688
	b _0814D68C
	.align 2, 0
_0814D680: .4byte 0x030046A4
_0814D684:
	ldrb r0, [r5, #4]
	b _0814D68A
_0814D688:
	ldrb r0, [r5]
_0814D68A:
	subs r1, r1, r0
_0814D68C:
	strh r1, [r5, #2]
	ldr r0, _0814D6A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814D6A4
	movs r0, #1
	b _0814D6A6
	.align 2, 0
_0814D6A0: .4byte 0x030047A4
_0814D6A4:
	movs r0, #0
_0814D6A6:
	cmp r0, #0
	beq _0814D6E4
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0814D6C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814D6C2
	adds r2, r0, #0
_0814D6C2:
	cmp r2, #0
	bge _0814D6D0
_0814D6C6:
	ldr r1, _0814D6CC @ =0x000005C4
	adds r0, r7, r1
	b _0814DC0C
	.align 2, 0
_0814D6CC: .4byte 0x000005C4
_0814D6D0:
	ldr r1, _0814D6E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814D72C
	.align 2, 0
_0814D6E0: .4byte 0x03002BE0
_0814D6E4:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D710
	cmp r1, #0
	blt _0814D710
	ldr r0, _0814D714 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D710
	ldr r0, _0814D718 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D71C
_0814D710:
	movs r5, #0
	b _0814D72A
	.align 2, 0
_0814D714: .4byte 0x030046A8
_0814D718: .4byte 0x030046AC
_0814D71C:
	ldr r0, _0814D764 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814D72A:
	movs r2, #0
_0814D72C:
	ldr r3, _0814D768 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814D74C
	ldr r1, _0814D76C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814D74C
	b _0814DB48
_0814D74C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _0814D770
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814D764: .4byte 0x030046A4
_0814D768: .4byte 0x00000256
_0814D76C: .4byte 0x03002BE0
_0814D770:
	ldr r5, _0814D814 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _0814D834
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0814D818 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0814D81C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0814D820 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0814D824 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0814D828 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0814D82C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _0814D830 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _0814DA06
	.align 2, 0
_0814D814: .4byte 0x00000222
_0814D818: .4byte 0x0000046D
_0814D81C: .4byte 0x0000046B
_0814D820: .4byte 0x00000553
_0814D824: .4byte 0x00000469
_0814D828: .4byte 0x0000046A
_0814D82C: .4byte 0x00000484
_0814D830: .4byte 0x0000046C
_0814D834:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814D8F8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _0814D8FC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814D900 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _0814D904 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0814D908 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0814D90C @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _0814D8F4
	cmp r1, #0
	blt _0814D8F4
	ldr r0, _0814D910 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0814D8F4
	ldr r0, _0814D914 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D918
_0814D8F4:
	movs r4, #0
	b _0814D928
	.align 2, 0
_0814D8F8: .4byte 0x0000046D
_0814D8FC: .4byte 0x0000046B
_0814D900: .4byte 0x00000553
_0814D904: .4byte 0x00000469
_0814D908: .4byte 0x0000046A
_0814D90C: .4byte 0x00000484
_0814D910: .4byte 0x030046A8
_0814D914: .4byte 0x030046AC
_0814D918:
	ldr r0, _0814D938 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0814D928:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814D93C
	adds r0, #4
	b _0814D948
	.align 2, 0
_0814D938: .4byte 0x030046A4
_0814D93C:
	ldr r0, _0814D95C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D948:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D960
	cmp r2, #2
	beq _0814D966
	b _0814D96C
	.align 2, 0
_0814D95C: .4byte 0x030046A4
_0814D960:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0814D96A
_0814D966:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0814D96A:
	subs r1, r1, r0
_0814D96C:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D998
	cmp r1, #0
	blt _0814D998
	ldr r0, _0814D99C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D998
	ldr r0, _0814D9A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D9A4
_0814D998:
	movs r4, #0
	b _0814D9B2
	.align 2, 0
_0814D99C: .4byte 0x030046A8
_0814D9A0: .4byte 0x030046AC
_0814D9A4:
	ldr r0, _0814D9C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814D9B2:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814D9CC
	adds r0, #4
	b _0814D9D8
	.align 2, 0
_0814D9C8: .4byte 0x030046A4
_0814D9CC:
	ldr r0, _0814D9EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D9D8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814D9F0
	cmp r3, #2
	beq _0814D9F4
	b _0814D9F8
	.align 2, 0
_0814D9EC: .4byte 0x030046A4
_0814D9F0:
	ldrb r0, [r5, #4]
	b _0814D9F6
_0814D9F4:
	ldrb r0, [r5]
_0814D9F6:
	subs r2, r2, r0
_0814D9F8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814DA06:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814DA30 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _0814DB10
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814DA34
	movs r0, #1
	b _0814DA36
	.align 2, 0
_0814DA30: .4byte 0x00000482
_0814DA34:
	movs r0, #0
_0814DA36:
	ldr r1, _0814DB20 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _0814DB10
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0814DB24 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814DB28 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814DB2C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814DB30 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0814DB34 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0814DB38 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814DB3C @ =0x030046B8
	adds r2, r4, #0
_0814DA7E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814DB40 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814DB44 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814DAA2
	adds r3, #1
	cmp r3, #3
	ble _0814DA7E
	adds r0, r4, #0
_0814DAA2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814DB10:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814DB20: .4byte 0x00000482
_0814DB24: .4byte 0x0000054F
_0814DB28: .4byte 0x0000054C
_0814DB2C: .4byte 0x0000054E
_0814DB30: .4byte 0x00000541
_0814DB34: .4byte 0x000005BC
_0814DB38: .4byte 0x00000542
_0814DB3C: .4byte 0x030046B8
_0814DB40: .4byte 0x000003FF
_0814DB44: .4byte 0x0203B400
_0814DB48:
	add r6, sp, #8
	ldr r0, _0814DB88 @ =0x030046A4
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
	beq _0814DB8C
	adds r0, #4
	b _0814DB98
	.align 2, 0
_0814DB88: .4byte 0x030046A4
_0814DB8C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814DB98:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0814DBD0 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0814DBD8
	ldr r0, _0814DBD4 @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0814DC02
	.align 2, 0
_0814DBD0: .4byte 0x000004A4
_0814DBD4: .4byte 0xFFFFFDFF
_0814DBD8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814DBF8
	cmp r0, #2
	beq _0814DBF4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814DBF4:
	movs r0, #1
	b _0814DC04
_0814DBF8:
	ldr r0, _0814DC18 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0814DC02:
	movs r0, #0
_0814DC04:
	cmp r0, #0
	bne _0814DC20
	ldr r3, _0814DC1C @ =0x000005C4
	adds r0, r7, r3
_0814DC0C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814DC18: .4byte 0xFFFFFDFF
_0814DC1C: .4byte 0x000005C4
_0814DC20:
	movs r0, #1
_0814DC22:
	cmp r0, #0
	bne _0814DCA8
	ldr r4, _0814DC58 @ =0x000004A4
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
	bne _0814DC60
	ldr r0, _0814DC5C @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814DC8A
	.align 2, 0
_0814DC58: .4byte 0x000004A4
_0814DC5C: .4byte 0xFFFFFDFF
_0814DC60:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0814DC80
	cmp r0, #2
	beq _0814DC7C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814DC7C:
	movs r0, #1
	b _0814DC8C
_0814DC80:
	ldr r0, _0814DCA0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814DC8A:
	movs r0, #0
_0814DC8C:
	cmp r0, #0
	bne _0814DCA8
_0814DC90:
	ldr r4, _0814DCA4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0814DD28
	.align 2, 0
_0814DCA0: .4byte 0xFFFFFDFF
_0814DCA4: .4byte 0x000005C4
_0814DCA8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0814DD04 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0814DD08 @ =0x0000046B
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
	ldr r6, _0814DD0C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0814DD10 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0814DD14 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _0814DD28
	.align 2, 0
_0814DD04: .4byte 0x0000046D
_0814DD08: .4byte 0x0000046B
_0814DD0C: .4byte 0x00000469
_0814DD10: .4byte 0x0000046A
_0814DD14: .4byte 0x00000484

_0814DD18:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0814DD28:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
