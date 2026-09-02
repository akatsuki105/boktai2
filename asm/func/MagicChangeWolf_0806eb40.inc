	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _0806EBC6
	ldr r0, _0806EB8C @ =0x03002B70
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0806EB90 @ =0x03002B88
	strh r1, [r0]
	ldr r0, _0806EB94 @ =0x03002BF4
	strh r1, [r0]
	movs r1, #0
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0806ea98
	ldr r1, _0806EB98 @ =0x03002BA8
	str r0, [r1]
	cmp r0, #0
	bne _0806EB9C
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #3
	bl FUN_08060b84
	b _0806EBBA
	.align 2, 0
_0806EB8C: .4byte 0x03002B70
_0806EB90: .4byte 0x03002B88
_0806EB94: .4byte 0x03002BF4
_0806EB98: .4byte 0x03002BA8
_0806EB9C:
	ldr r3, _0806EBDC @ =0x0000095E
	adds r1, r5, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #1
	bl FUN_08060b84
_0806EBBA:
	adds r0, r5, #0
	bl Player_PayMagicCost
	ldr r0, _0806EBE0 @ =0x0000039E
	bl PlaySound_082406e0
_0806EBC6:
	ldr r1, _0806EBE4 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _0806EBD2
	b _0806F1DE
_0806EBD2:
	lsls r0, r0, #2
	ldr r1, _0806EBE8 @ =_0806EBEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806EBDC: .4byte 0x0000095E
_0806EBE0: .4byte 0x0000039E
_0806EBE4: .4byte 0x0000037D
_0806EBE8: .4byte _0806EBEC
_0806EBEC: @ jump table
	.4byte _0806EC04 @ case 0
	.4byte _0806EC7C @ case 1
	.4byte _0806EE6C @ case 2
	.4byte _0806F06C @ case 3
	.4byte _0806F0BC @ case 4
	.4byte _0806F1C4 @ case 5
_0806EC04:
	ldr r2, _0806EC34 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _0806EC38
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806EC42
	.align 2, 0
_0806EC34: .4byte 0x0000037E
_0806EC38:
	ldr r1, _0806EC70 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
_0806EC42:
	ldr r0, _0806EC74 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bhi _0806EC56
	b _0806F1DE
_0806EC56:
	adds r0, r5, #0
	bl FUN_0806ea98
	ldr r1, _0806EC78 @ =0x03002BA8
	str r0, [r1]
	cmp r0, #0
	beq _0806ED0C
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #1
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806EC70: .4byte 0x00000193
_0806EC74: .4byte 0x0000037E
_0806EC78: .4byte 0x03002BA8
_0806EC7C:
	ldr r1, _0806ECEC @ =0x03002BA8
	mov r8, r1
	ldr r0, [r1]
	ldr r2, [r0]
	movs r3, #8
	ldrsh r1, [r2, r3]
	movs r3, #0x2c
	ldrsh r0, [r5, r3]
	subs r6, r1, r0
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r7, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	subs r0, r7, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0xff
	mov sb, r2
	ands r0, r2
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0806ECC6
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
_0806ECC6:
	adds r0, r6, #0
	muls r0, r6, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r1, _0806ECF0 @ =0x000008FF
	cmp r0, r1
	bgt _0806ED9C
	mov r3, r8
	ldr r1, [r3]
	ldr r4, [r1, #4]
	movs r6, #1
	ands r4, r6
	cmp r4, #0
	beq _0806ECF4
	movs r0, #0
	str r0, [r3]
	b _0806ED0C
	.align 2, 0
_0806ECEC: .4byte 0x03002BA8
_0806ECF0: .4byte 0x000008FF
_0806ECF4:
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #0
	movs r2, #0
	bl _call_via_r3
	ldr r1, _0806ED18 @ =0x03002BF4
	strh r6, [r1]
	cmp r0, #0
	bne _0806ED1C
	mov r0, r8
	str r4, [r0]
_0806ED0C:
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #3
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806ED18: .4byte 0x03002BF4
_0806ED1C:
	adds r0, r7, #0
	adds r0, #0x20
	mov r1, sb
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r0, #3
	movs r2, #7
	ands r0, r2
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1]
	adds r0, #5
	ands r0, r2
	lsls r0, r0, #5
	strb r0, [r1, #5]
	adds r0, r7, #0
	adds r0, #0x60
	mov r1, sb
	ands r0, r1
	asrs r1, r0, #6
	cmp r1, #1
	ble _0806ED70
	movs r0, #3
	subs r0, r0, r1
	ldr r2, _0806ED68 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806ED6C @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0806ED7C
	.align 2, 0
_0806ED68: .4byte 0x000002E6
_0806ED6C: .4byte 0x000002E7
_0806ED70:
	ldr r2, _0806ED94 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806ED98 @ =0x000002E7
	adds r0, r5, r3
	strb r4, [r0]
_0806ED7C:
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #2
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806ED94: .4byte 0x000002E6
_0806ED98: .4byte 0x000002E7
_0806ED9C:
	ldr r2, _0806EDBC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0806EDC0
	asrs r0, r0, #0xc
	b _0806EDC6
	.align 2, 0
_0806EDBC: .4byte 0x085B0A08
_0806EDC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EDC6:
	strh r0, [r5, #0x34]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0806EDE2
	asrs r0, r0, #0xc
	b _0806EDE8
_0806EDE2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EDE8:
	strh r0, [r5, #0x38]
	adds r0, r7, #0
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r0, r0, #1
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r5, r3
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x60
	ands r0, r2
	asrs r1, r0, #6
	cmp r1, #1
	ble _0806EE28
	movs r0, #3
	subs r0, r0, r1
	ldr r2, _0806EE24 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	movs r0, #1
	b _0806EE34
	.align 2, 0
_0806EE24: .4byte 0x000002E6
_0806EE28:
	ldr r2, _0806EE60 @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806EE64 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #0
_0806EE34:
	strb r0, [r1]
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080670fc
	ldr r0, _0806EE68 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _0806EE5E
	b _0806F1DE
_0806EE5E:
	b _0806EF18
	.align 2, 0
_0806EE60: .4byte 0x000002E6
_0806EE64: .4byte 0x000002E7
_0806EE68: .4byte 0x0000037E
_0806EE6C:
	ldr r1, _0806EE90 @ =0x03002BA8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0806EE98
	movs r0, #0
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806EE94 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806EF18
	.align 2, 0
_0806EE90: .4byte 0x03002BA8
_0806EE94: .4byte 0x00000193
_0806EE98:
	ldr r0, _0806EF24 @ =0x03002B70
	ldrh r0, [r0]
	cmp r0, #3
	bhi _0806EEC2
	adds r0, r5, #0
	bl Player_CheckMagicCost
	cmp r0, #0
	beq _0806EEC2
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0806EEC2
	ldr r0, _0806EF28 @ =0x03002B88
	strh r4, [r0]
_0806EEC2:
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	beq _0806EEDC
	b _0806F018
_0806EEDC:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806EEE8
	b _0806F018
_0806EEE8:
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	adds r0, r0, r1
	asrs r6, r0, #1
	ldr r4, _0806EF2C @ =0x03002BA8
	ldr r1, [r4]
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #0
	adds r2, r6, #0
	bl _call_via_r3
	cmp r0, #0
	bne _0806EF30
	str r0, [r4]
	adds r0, r5, #0
	bl FUN_080609dc
_0806EF18:
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #4
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806EF24: .4byte 0x03002B70
_0806EF28: .4byte 0x03002B88
_0806EF2C: .4byte 0x03002BA8
_0806EF30:
	ldr r0, _0806EF64 @ =0x0000039F
	bl PlaySound_082406e0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806EF68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806EF6C
	asrs r0, r0, #0xc
	b _0806EF72
	.align 2, 0
_0806EF64: .4byte 0x0000039F
_0806EF68: .4byte 0x085B0A08
_0806EF6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EF72:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xe6
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _0806EF94 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806EF98
	asrs r0, r0, #0xc
	b _0806EF9E
	.align 2, 0
_0806EF94: .4byte 0x085B0A08
_0806EF98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806EF9E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806F00C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r4, r5, #0
	adds r4, #0x2c
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	ldr r3, _0806F010 @ =0x00000366
	adds r1, r5, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r3, [r1]
	cmp r0, r3
	blo _0806EFE2
	ldrh r1, [r1]
	ldrh r0, [r2]
	subs r6, r1, r0
	strh r1, [r2]
_0806EFE2:
	cmp r6, #0
	ble _0806F002
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x97
	lsls r2, r2, #4
	adds r1, r5, r2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl FUN_0805fe7c
_0806F002:
	ldr r1, _0806F014 @ =0x03002B70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0806F1DE
	.align 2, 0
_0806F00C: .4byte 0xFFFF0000
_0806F010: .4byte 0x00000366
_0806F014: .4byte 0x03002B70
_0806F018:
	cmp r1, #0
	bne _0806F01E
	b _0806F1DE
_0806F01E:
	ldr r0, _0806F034 @ =0x03002B88
	ldrh r6, [r0]
	cmp r6, #0
	beq _0806F038
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #2
	bl FUN_08060b84
	b _0806F05C
	.align 2, 0
_0806F034: .4byte 0x03002B88
_0806F038:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r4, _0806F064 @ =0x03002BA8
	ldr r1, [r4]
	ldr r0, [r1]
	ldr r3, [r1, #8]
	movs r1, #1
	movs r2, #0x3c
	bl _call_via_r3
	str r6, [r4]
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #4
	bl FUN_08060b84
_0806F05C:
	ldr r1, _0806F068 @ =0x03002B88
	movs r0, #0
	strh r0, [r1]
	b _0806F1DE
	.align 2, 0
_0806F064: .4byte 0x03002BA8
_0806F068: .4byte 0x03002B88
_0806F06C:
	ldr r3, _0806F0B0 @ =0x0000095E
	adds r1, r5, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806F0B4 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806F0B8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bhi _0806F0A4
	b _0806F1DE
_0806F0A4:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806F0B0: .4byte 0x0000095E
_0806F0B4: .4byte 0x00000193
_0806F0B8: .4byte 0x0000037E
_0806F0BC:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r3, _0806F120 @ =0x0000037E
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806F0E2
	ldr r0, _0806F124 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
_0806F0E2:
	adds r0, r5, #0
	bl FUN_080609dc
	ldr r1, _0806F128 @ =0x00000193
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806F12C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0806F130
	asrs r0, r0, #0xc
	b _0806F136
	.align 2, 0
_0806F120: .4byte 0x0000037E
_0806F124: .4byte 0x0000095E
_0806F128: .4byte 0x00000193
_0806F12C: .4byte 0x085B0A08
_0806F130:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F136:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _0806F150 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	adds r2, r1, #0
	cmp r0, #0
	blt _0806F154
	asrs r0, r0, #0xc
	b _0806F15A
	.align 2, 0
_0806F150: .4byte 0x085B0A08
_0806F154:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F15A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r3, _0806F180 @ =0x0000037E
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, #4
	lsls r0, r0, #3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806F184
	asrs r0, r0, #0xc
	b _0806F18A
	.align 2, 0
_0806F180: .4byte 0x0000037E
_0806F184:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806F18A:
	ldr r3, _0806F1BC @ =0x000003F6
	adds r2, r5, r3
	strh r0, [r2]
	ldr r0, _0806F1C0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0806F1DE
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #5
	bl FUN_08060b84
	b _0806F1DE
	.align 2, 0
_0806F1BC: .4byte 0x000003F6
_0806F1C0: .4byte 0x0000037E
_0806F1C4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806F1DE
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806F1DE:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
