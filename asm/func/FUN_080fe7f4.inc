	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _080FE958 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FE810
	movs r0, #0
	strb r0, [r1]
_080FE810:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080FE828
	bl _080FF04C
_080FE828:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _080FE83A
	bl _080FF04C
_080FE83A:
	ldr r2, _080FE95C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _080FE848
	bl FUN_080ff048
_080FE848:
	ldr r3, _080FE960 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _080FE964 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _080FE968 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _080FE95C @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _080FE958 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _080FE96C @ =0x080E6795
	movs r0, #0xe
	ldr r4, _080FE970 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _080FE974 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _080FE978 @ =0x00000553
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
	str r0, [sp, #0x50]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x5c]
	mov r0, sb
	str r0, [sp, #0x54]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x34]
	str r3, [sp, #0x30]
	mov sl, r2
	cmp r1, #0
	bne _080FE8E6
	b _080FEE80
_080FE8E6:
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
	ldr r3, _080FE97C @ =0x00000551
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
	blt _080FE952
	cmp r1, #0
	blt _080FE952
	ldr r0, _080FE980 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080FE952
	ldr r0, _080FE984 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FE988
_080FE952:
	movs r4, #0
	b _080FE996
	.align 2, 0
_080FE958: .4byte 0x0000046C
_080FE95C: .4byte 0x00000484
_080FE960: .4byte 0x000001DF
_080FE964: .4byte 0x00000469
_080FE968: .4byte 0x0000046A
_080FE96C: .4byte 0x080E6795
_080FE970: .4byte 0x0000046D
_080FE974: .4byte 0x0000046B
_080FE978: .4byte 0x00000553
_080FE97C: .4byte 0x00000551
_080FE980: .4byte 0x030046A8
_080FE984: .4byte 0x030046AC
_080FE988:
	ldr r0, _080FE9A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080FE996:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FE9AC
	adds r0, #4
	b _080FE9B8
	.align 2, 0
_080FE9A8: .4byte 0x030046A4
_080FE9AC:
	ldr r0, _080FE9CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FE9B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FE9D0
	cmp r2, #2
	beq _080FE9D4
	b _080FE9D8
	.align 2, 0
_080FE9CC: .4byte 0x030046A4
_080FE9D0:
	ldrb r0, [r5, #4]
	b _080FE9D6
_080FE9D4:
	ldrb r0, [r5]
_080FE9D6:
	subs r1, r1, r0
_080FE9D8:
	strh r1, [r5, #2]
	ldr r0, _080FE9EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080FE9F0
	movs r0, #1
	b _080FE9F2
	.align 2, 0
_080FE9EC: .4byte 0x030047A4
_080FE9F0:
	movs r0, #0
_080FE9F2:
	cmp r0, #0
	beq _080FEA30
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080FEA12
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080FEA0E
	adds r2, r0, #0
_080FEA0E:
	cmp r2, #0
	bge _080FEA1C
_080FEA12:
	ldr r2, _080FEA18 @ =0x000005C4
	adds r0, r7, r2
	b _080FEE6E
	.align 2, 0
_080FEA18: .4byte 0x000005C4
_080FEA1C:
	ldr r1, _080FEA2C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080FEA78
	.align 2, 0
_080FEA2C: .4byte 0x03002BE0
_080FEA30:
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
	blt _080FEA5C
	cmp r1, #0
	blt _080FEA5C
	ldr r0, _080FEA60 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FEA5C
	ldr r0, _080FEA64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FEA68
_080FEA5C:
	movs r5, #0
	b _080FEA76
	.align 2, 0
_080FEA60: .4byte 0x030046A8
_080FEA64: .4byte 0x030046AC
_080FEA68:
	ldr r0, _080FEB08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080FEA76:
	movs r2, #0
_080FEA78:
	ldr r4, _080FEB0C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _080FEA98
	ldr r1, _080FEB10 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080FEA98
	b _080FEDAC
_080FEA98:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080FEAAC
	b _080FF04C
_080FEAAC:
	ldr r0, _080FEB14 @ =0x00000222
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
	str r2, [sp, #0x38]
	cmp r3, #0
	beq _080FEB18
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r1, [r0]
	ldr r1, [sp, #0x30]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _080FEC66
	.align 2, 0
_080FEB08: .4byte 0x030046A4
_080FEB0C: .4byte 0x00000256
_080FEB10: .4byte 0x03002BE0
_080FEB14: .4byte 0x00000222
_080FEB18:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	str r1, [r4]
	ldr r1, [sp, #0x30]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
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
	blt _080FEB7C
	cmp r1, #0
	blt _080FEB7C
	ldr r0, _080FEB80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FEB7C
	ldr r0, _080FEB84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FEB88
_080FEB7C:
	movs r4, #0
	b _080FEB96
	.align 2, 0
_080FEB80: .4byte 0x030046A8
_080FEB84: .4byte 0x030046AC
_080FEB88:
	ldr r0, _080FEBA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FEB96:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FEBAC
	adds r0, #4
	b _080FEBB8
	.align 2, 0
_080FEBA8: .4byte 0x030046A4
_080FEBAC:
	ldr r0, _080FEBCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FEBB8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FEBD0
	cmp r2, #2
	beq _080FEBD4
	b _080FEBD8
	.align 2, 0
_080FEBCC: .4byte 0x030046A4
_080FEBD0:
	ldrb r0, [r5, #4]
	b _080FEBD6
_080FEBD4:
	ldrb r0, [r5]
_080FEBD6:
	subs r1, r1, r0
_080FEBD8:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080FEC00
	cmp r1, #0
	blt _080FEC00
	ldr r0, _080FEC04 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FEC00
	ldr r0, _080FEC08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FEC0C
_080FEC00:
	movs r4, #0
	b _080FEC1A
	.align 2, 0
_080FEC04: .4byte 0x030046A8
_080FEC08: .4byte 0x030046AC
_080FEC0C:
	ldr r0, _080FEC2C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FEC1A:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FEC30
	adds r0, #4
	b _080FEC3C
	.align 2, 0
_080FEC2C: .4byte 0x030046A4
_080FEC30:
	ldr r0, _080FEC50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FEC3C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080FEC54
	cmp r3, #2
	beq _080FEC58
	b _080FEC5C
	.align 2, 0
_080FEC50: .4byte 0x030046A4
_080FEC54:
	ldrb r0, [r5, #4]
	b _080FEC5A
_080FEC58:
	ldrb r0, [r5]
_080FEC5A:
	subs r2, r2, r0
_080FEC5C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_080FEC66:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _080FED70
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FEC90
	movs r0, #1
	b _080FEC92
_080FEC90:
	movs r0, #0
_080FEC92:
	ldr r3, _080FED80 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _080FED70
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _080FED84 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _080FED88 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _080FED8C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _080FED90 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _080FED94 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x18]
	ldr r0, _080FED98 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _080FED9C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x1c]
	ldr r6, _080FEDA0 @ =0x0203B400
	ldr r1, _080FEDA4 @ =0x030046B8
	ldr r5, _080FEDA8 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_080FECE2:
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
	bne _080FED00
	adds r3, #1
	cmp r3, #3
	ble _080FECE2
	mov r0, sb
_080FED00:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x18]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r2, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_080FED70:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x58]
	strh r0, [r2]
	b _080FF04C
	.align 2, 0
_080FED80: .4byte 0x00000482
_080FED84: .4byte 0x0000054F
_080FED88: .4byte 0x0000054C
_080FED8C: .4byte 0x0000054D
_080FED90: .4byte 0x0000054E
_080FED94: .4byte 0x00000541
_080FED98: .4byte 0x000005BC
_080FED9C: .4byte 0x00000542
_080FEDA0: .4byte 0x0203B400
_080FEDA4: .4byte 0x030046B8
_080FEDA8: .4byte 0x000003FF
_080FEDAC:
	mov sb, sp
	ldr r6, _080FEDE8 @ =0x030046A4
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
	bl FUN_08234224
	cmp r0, #0
	beq _080FEDEC
	adds r0, #4
	b _080FEDF6
	.align 2, 0
_080FEDE8: .4byte 0x030046A4
_080FEDEC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080FEDF6:
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
	ldr r5, _080FEE30 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080FEE38
	ldr r0, _080FEE34 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080FEE62
	.align 2, 0
_080FEE30: .4byte 0x000004A4
_080FEE34: .4byte 0xFFFFFDFF
_080FEE38:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080FEE58
	cmp r0, #2
	beq _080FEE54
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FEE54:
	movs r0, #1
	b _080FEE64
_080FEE58:
	ldr r0, _080FEE78 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_080FEE62:
	movs r0, #0
_080FEE64:
	cmp r0, #0
	beq _080FEE6A
	b _080FF04C
_080FEE6A:
	ldr r4, _080FEE7C @ =0x000005C4
	adds r0, r7, r4
_080FEE6E:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080FF04C
	.align 2, 0
_080FEE78: .4byte 0xFFFFFDFF
_080FEE7C: .4byte 0x000005C4
_080FEE80:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080FEE92
	b _080FF00A
_080FEE92:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
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
	ldr r3, _080FEEFC @ =0x00000551
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
	blt _080FEEF8
	cmp r1, #0
	blt _080FEEF8
	ldr r0, _080FEF00 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080FEEF8
	ldr r0, _080FEF04 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080FEF08
_080FEEF8:
	movs r4, #0
	b _080FEF16
	.align 2, 0
_080FEEFC: .4byte 0x00000551
_080FEF00: .4byte 0x030046A8
_080FEF04: .4byte 0x030046AC
_080FEF08:
	ldr r0, _080FEF28 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080FEF16:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080FEF2C
	adds r0, #4
	b _080FEF38
	.align 2, 0
_080FEF28: .4byte 0x030046A4
_080FEF2C:
	ldr r0, _080FEF4C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080FEF38:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080FEF50
	cmp r2, #2
	beq _080FEF54
	b _080FEF58
	.align 2, 0
_080FEF4C: .4byte 0x030046A4
_080FEF50:
	ldrb r0, [r5, #4]
	b _080FEF56
_080FEF54:
	ldrb r0, [r5]
_080FEF56:
	subs r1, r1, r0
_080FEF58:
	strh r1, [r5, #2]
	ldr r2, _080FEF88 @ =0x000004A4
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
	bl FUN_0823599c
	cmp r0, #0
	bne _080FEF90
	ldr r0, _080FEF8C @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _080FEFBA
	.align 2, 0
_080FEF88: .4byte 0x000004A4
_080FEF8C: .4byte 0xFFFFFDFF
_080FEF90:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FEFB0
	cmp r0, #2
	beq _080FEFAC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FEFAC:
	movs r0, #1
	b _080FEFBC
_080FEFB0:
	ldr r0, _080FEFF4 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_080FEFBA:
	movs r0, #0
_080FEFBC:
	adds r3, r0, #0
	cmp r3, #0
	bne _080FEFFC
	ldr r0, _080FEFF8 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x54]
	strb r2, [r1]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r3, [r5]
	ldr r1, [sp, #0x34]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _080FF04C
	.align 2, 0
_080FEFF4: .4byte 0xFFFFFDFF
_080FEFF8: .4byte FUN_080e48d0
_080FEFFC:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _080FF04C
_080FF00A:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
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
	ldr r3, _080FF044 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _080FF04C
	.align 2, 0
_080FF044: .4byte 0x00000551
