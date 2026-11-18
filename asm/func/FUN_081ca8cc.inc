	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _081CAA30 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA8E8
	movs r0, #0
	strb r0, [r1]
_081CA8E8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CA900
	bl _081CB128
_081CA900:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081CA912
	bl _081CB128
_081CA912:
	ldr r2, _081CAA34 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081CA920
	bl _081CB124
_081CA920:
	ldr r3, _081CAA38 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081CAA3C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081CAA40 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081CAA34 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081CAA30 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _081CAA44 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _081CAA48 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _081CAA4C @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _081CAA50 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x44]
	ldr r0, [sp, #8]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x40]
	str r5, [sp, #0x24]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x28]
	mov sl, r2
	cmp r1, #0
	bne _081CA9BE
	b _081CAF58
_081CA9BE:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CAA54 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
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
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081CAA2A
	cmp r1, #0
	blt _081CAA2A
	ldr r0, _081CAA58 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CAA2A
	ldr r0, _081CAA5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAA60
_081CAA2A:
	movs r4, #0
	b _081CAA6E
	.align 2, 0
_081CAA30: .4byte 0x0000046C
_081CAA34: .4byte 0x00000484
_081CAA38: .4byte 0x000001DF
_081CAA3C: .4byte 0x00000469
_081CAA40: .4byte 0x0000046A
_081CAA44: .4byte Enemy_WaitPendingState
_081CAA48: .4byte 0x0000046D
_081CAA4C: .4byte 0x0000046B
_081CAA50: .4byte 0x00000553
_081CAA54: .4byte 0x00000551
_081CAA58: .4byte 0x030046A8
_081CAA5C: .4byte 0x030046AC
_081CAA60:
	ldr r0, _081CAA80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CAA6E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CAA84
	adds r0, #4
	b _081CAA90
	.align 2, 0
_081CAA80: .4byte 0x030046A4
_081CAA84:
	ldr r0, _081CAAA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAA90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CAAA8
	cmp r2, #2
	beq _081CAAAC
	b _081CAAB0
	.align 2, 0
_081CAAA4: .4byte 0x030046A4
_081CAAA8:
	ldrb r0, [r5, #4]
	b _081CAAAE
_081CAAAC:
	ldrb r0, [r5]
_081CAAAE:
	subs r1, r1, r0
_081CAAB0:
	strh r1, [r5, #2]
	ldr r0, _081CAAC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CAAC8
	movs r0, #1
	b _081CAACA
	.align 2, 0
_081CAAC4: .4byte 0x030047A4
_081CAAC8:
	movs r0, #0
_081CAACA:
	cmp r0, #0
	beq _081CAB08
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CAAEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CAAE6
	adds r2, r0, #0
_081CAAE6:
	cmp r2, #0
	bge _081CAAF4
_081CAAEA:
	ldr r2, _081CAAF0 @ =0x000005C4
	adds r0, r7, r2
	b _081CAF46
	.align 2, 0
_081CAAF0: .4byte 0x000005C4
_081CAAF4:
	ldr r1, _081CAB04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CAB50
	.align 2, 0
_081CAB04: .4byte 0x03002BE0
_081CAB08:
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
	blt _081CAB34
	cmp r1, #0
	blt _081CAB34
	ldr r0, _081CAB38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAB34
	ldr r0, _081CAB3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAB40
_081CAB34:
	movs r5, #0
	b _081CAB4E
	.align 2, 0
_081CAB38: .4byte 0x030046A8
_081CAB3C: .4byte 0x030046AC
_081CAB40:
	ldr r0, _081CABE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CAB4E:
	movs r2, #0
_081CAB50:
	ldr r4, _081CABE4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CAB70
	ldr r1, _081CABE8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CAB70
	b _081CAE84
_081CAB70:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081CAB84
	b _081CB128
_081CAB84:
	ldr r0, _081CABEC @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081CABF0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	ldr r0, [sp, #0x2c]
	str r1, [r0]
	ldr r1, [sp, #0x28]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r1, [sp, #0x38]
	strb r5, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r5, [sp, #0x50]
	str r4, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081CAD3E
	.align 2, 0
_081CABE0: .4byte 0x030046A4
_081CABE4: .4byte 0x00000256
_081CABE8: .4byte 0x03002BE0
_081CABEC: .4byte 0x00000222
_081CABF0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r5, [r4]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	str r1, [r4]
	ldr r1, [sp, #0x28]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CAC54
	cmp r1, #0
	blt _081CAC54
	ldr r0, _081CAC58 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAC54
	ldr r0, _081CAC5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAC60
_081CAC54:
	movs r4, #0
	b _081CAC6E
	.align 2, 0
_081CAC58: .4byte 0x030046A8
_081CAC5C: .4byte 0x030046AC
_081CAC60:
	ldr r0, _081CAC80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CAC6E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CAC84
	adds r0, #4
	b _081CAC90
	.align 2, 0
_081CAC80: .4byte 0x030046A4
_081CAC84:
	ldr r0, _081CACA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAC90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CACA8
	cmp r2, #2
	beq _081CACAC
	b _081CACB0
	.align 2, 0
_081CACA4: .4byte 0x030046A4
_081CACA8:
	ldrb r0, [r5, #4]
	b _081CACAE
_081CACAC:
	ldrb r0, [r5]
_081CACAE:
	subs r1, r1, r0
_081CACB0:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CACD8
	cmp r1, #0
	blt _081CACD8
	ldr r0, _081CACDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CACD8
	ldr r0, _081CACE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CACE4
_081CACD8:
	movs r4, #0
	b _081CACF2
	.align 2, 0
_081CACDC: .4byte 0x030046A8
_081CACE0: .4byte 0x030046AC
_081CACE4:
	ldr r0, _081CAD04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CACF2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CAD08
	adds r0, #4
	b _081CAD14
	.align 2, 0
_081CAD04: .4byte 0x030046A4
_081CAD08:
	ldr r0, _081CAD28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAD14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CAD2C
	cmp r3, #2
	beq _081CAD30
	b _081CAD34
	.align 2, 0
_081CAD28: .4byte 0x030046A4
_081CAD2C:
	ldrb r0, [r5, #4]
	b _081CAD32
_081CAD30:
	ldrb r0, [r5]
_081CAD32:
	subs r2, r2, r0
_081CAD34:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081CAD3E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _081CAE48
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CAD68
	movs r0, #1
	b _081CAD6A
_081CAD68:
	movs r0, #0
_081CAD6A:
	ldr r3, _081CAE58 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _081CAE48
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081CAE5C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CAE60 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x18]
	ldr r2, _081CAE64 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _081CAE68 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _081CAE6C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r0, _081CAE70 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _081CAE74 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _081CAE78 @ =0x0203B400
	ldr r1, _081CAE7C @ =0x030046B8
	ldr r5, _081CAE80 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081CADBA:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081CADD8
	adds r3, #1
	cmp r3, #3
	ble _081CADBA
	mov r0, r8
_081CADD8:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x24]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r4, [sp, #0x30]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r0, [r5]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r2, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x58]
	strb r0, [r1]
_081CAE48:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x4c]
	strh r0, [r2]
	b _081CB128
	.align 2, 0
_081CAE58: .4byte 0x00000482
_081CAE5C: .4byte 0x0000054F
_081CAE60: .4byte 0x0000054C
_081CAE64: .4byte 0x0000054D
_081CAE68: .4byte 0x0000054E
_081CAE6C: .4byte 0x00000541
_081CAE70: .4byte 0x000005BC
_081CAE74: .4byte 0x00000542
_081CAE78: .4byte 0x0203B400
_081CAE7C: .4byte 0x030046B8
_081CAE80: .4byte 0x000003FF
_081CAE84:
	mov sb, sp
	ldr r6, _081CAEC0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _081CAEC4
	adds r0, #4
	b _081CAECE
	.align 2, 0
_081CAEC0: .4byte 0x030046A4
_081CAEC4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CAECE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081CAF08 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CAF10
	ldr r0, _081CAF0C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CAF3A
	.align 2, 0
_081CAF08: .4byte 0x000004A4
_081CAF0C: .4byte 0xFFFFFDFF
_081CAF10:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CAF30
	cmp r0, #2
	beq _081CAF2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CAF2C:
	movs r0, #1
	b _081CAF3C
_081CAF30:
	ldr r0, _081CAF50 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CAF3A:
	movs r0, #0
_081CAF3C:
	cmp r0, #0
	beq _081CAF42
	b _081CB128
_081CAF42:
	ldr r4, _081CAF54 @ =0x000005C4
	adds r0, r7, r4
_081CAF46:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CB128
	.align 2, 0
_081CAF50: .4byte 0xFFFFFDFF
_081CAF54: .4byte 0x000005C4
_081CAF58:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CAF6A
	b _081CB0E6
_081CAF6A:
	ldr r3, _081CAFD0 @ =FUN_081c7fb4
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081CAFD4 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CAFD8 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CAFCA
	cmp r1, #0
	blt _081CAFCA
	ldr r0, _081CAFDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAFCA
	ldr r0, _081CAFE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAFE4
_081CAFCA:
	movs r4, #0
	b _081CAFF2
	.align 2, 0
_081CAFD0: .4byte FUN_081c7fb4
_081CAFD4: .4byte 0x00000554
_081CAFD8: .4byte 0x00000551
_081CAFDC: .4byte 0x030046A8
_081CAFE0: .4byte 0x030046AC
_081CAFE4:
	ldr r0, _081CB004 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CAFF2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081CB008
	adds r0, #4
	b _081CB014
	.align 2, 0
_081CB004: .4byte 0x030046A4
_081CB008:
	ldr r0, _081CB028 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB014:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CB02C
	cmp r2, #2
	beq _081CB030
	b _081CB034
	.align 2, 0
_081CB028: .4byte 0x030046A4
_081CB02C:
	ldrb r0, [r5, #4]
	b _081CB032
_081CB030:
	ldrb r0, [r5]
_081CB032:
	subs r1, r1, r0
_081CB034:
	strh r1, [r5, #2]
	ldr r2, _081CB064 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081CB06C
	ldr r0, _081CB068 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081CB096
	.align 2, 0
_081CB064: .4byte 0x000004A4
_081CB068: .4byte 0xFFFFFDFF
_081CB06C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081CB08C
	cmp r0, #2
	beq _081CB088
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB088:
	movs r0, #1
	b _081CB098
_081CB08C:
	ldr r0, _081CB0D0 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081CB096:
	movs r0, #0
_081CB098:
	adds r3, r0, #0
	cmp r3, #0
	bne _081CB0D8
	ldr r0, _081CB0D4 @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r1, [sp, #0x48]
	strb r2, [r1]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r1, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081CB128
	.align 2, 0
_081CB0D0: .4byte 0xFFFFFDFF
_081CB0D4: .4byte Enemy_ClearStateBegun
_081CB0D8:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081CB128
_081CB0E6:
	ldr r3, _081CB11C @ =FUN_081c7fb4
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CB120 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081CB128
	.align 2, 0
_081CB11C: .4byte FUN_081c7fb4
_081CB120: .4byte 0x00000551

_081CB124:
	adds r0, #1
	str r0, [r1]
_081CB128:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
