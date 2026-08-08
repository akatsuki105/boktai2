	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	adds r3, r5, #0
	adds r3, #0x9c
	ldr r0, _080FBA88 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FBA8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FBA8E
	.align 2, 0
_080FBA88: .4byte 0x0000046D
_080FBA8C:
	movs r0, #0
_080FBA8E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _080FBA9C
	b _080FBECE
_080FBA9C:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r4, _080FBAEC @ =0x0000046A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #6
	beq _080FBAF0
	cmp r0, #0x11
	beq _080FBAF0
	movs r1, #0x89
	lsls r1, r1, #7
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _080FBAF0
	ldr r0, [r3, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _080FBAF8
	.align 2, 0
_080FBAEC: .4byte 0x0000046A
_080FBAF0:
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r1, [r0]
_080FBAF8:
	asrs r0, r1, #1
	cmp r2, r0
	bne _080FBB3E
	ldr r1, _080FBB2C @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	subs r1, #0x6b
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FBB34
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _080FBB30 @ =0x00000469
	b _080FC01C
	.align 2, 0
_080FBB2C: .4byte 0x0000046B
_080FBB30: .4byte 0x00000469
_080FBB34:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _080FC0A0
_080FBB3E:
	cmp r2, #1
	beq _080FBC14
	cmp r2, #1
	bgt _080FBB4C
	cmp r2, #0
	beq _080FBB5A
	b _080FBEC6
_080FBB4C:
	cmp r2, #2
	bne _080FBB52
	b _080FBCB8
_080FBB52:
	cmp r2, #3
	bne _080FBB58
	b _080FBDA4
_080FBB58:
	b _080FBEC6
_080FBB5A:
	subs r0, r1, #2
	cmp r0, #3
	bhi _080FBBAC
	movs r2, #9
	ldr r3, _080FBB80 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _080FBB88
	ldr r4, _080FBB84 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _080FBDC6
	.align 2, 0
_080FBB80: .4byte 0x0000025D
_080FBB84: .4byte 0x000004B7
_080FBB88:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xa
	ldr r1, _080FBBA4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080FBBA8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xa
	beq _080FBBA2
	b _080FBE02
_080FBBA2:
	b _080FBDF2
	.align 2, 0
_080FBBA4: .4byte 0x000004B7
_080FBBA8: .4byte 0x0000046E
_080FBBAC:
	movs r1, #9
	ldr r4, _080FBBD4 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBBDC
	ldr r2, _080FBBD8 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #0
	bl FUN_08236fac
	b _080FBC02
	.align 2, 0
_080FBBD4: .4byte 0x0000025D
_080FBBD8: .4byte 0x000004B7
_080FBBDC:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r3, _080FBC0C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #9
_080FBBF2:
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_080FBC02:
	ldr r4, _080FBC10 @ =0x0000046E
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	b _080FBEB8
	.align 2, 0
_080FBC0C: .4byte 0x000004B7
_080FBC10: .4byte 0x0000046E
_080FBC14:
	subs r0, r1, #4
	cmp r0, #3
	bhi _080FBC68
	movs r2, #9
	ldr r1, _080FBC3C @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080FBC44
	ldr r4, _080FBC40 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _080FBDC6
	.align 2, 0
_080FBC3C: .4byte 0x0000025D
_080FBC40: .4byte 0x000004B7
_080FBC44:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xb
	ldr r1, _080FBC60 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080FBC64 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xb
	beq _080FBC5E
	b _080FBE02
_080FBC5E:
	b _080FBDF2
	.align 2, 0
_080FBC60: .4byte 0x000004B7
_080FBC64: .4byte 0x0000046E
_080FBC68:
	movs r1, #9
	ldr r4, _080FBC90 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBC98
	ldr r2, _080FBC94 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	b _080FBC02
	.align 2, 0
_080FBC90: .4byte 0x0000025D
_080FBC94: .4byte 0x000004B7
_080FBC98:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r3, _080FBCB4 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	b _080FBBF2
	.align 2, 0
_080FBCB4: .4byte 0x000004B7
_080FBCB8:
	subs r0, r1, #1
	cmp r0, #4
	bls _080FBD34
	movs r1, #9
	ldr r2, _080FBCE8 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBCF0
	ldr r3, _080FBCEC @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	b _080FBD16
	.align 2, 0
_080FBCE8: .4byte 0x0000025D
_080FBCEC: .4byte 0x000004B7
_080FBCF0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xa
	ldr r2, _080FBD2C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xa
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_080FBD16:
	ldr r3, _080FBD30 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r5, r4
	b _080FBE2C
	.align 2, 0
_080FBD2C: .4byte 0x000004B7
_080FBD30: .4byte 0x0000046E
_080FBD34:
	movs r1, #9
	ldr r2, _080FBD5C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBD64
	ldr r3, _080FBD60 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #9
	movs r3, #2
	bl FUN_08236fac
	b _080FBD8C
	.align 2, 0
_080FBD5C: .4byte 0x0000025D
_080FBD60: .4byte 0x000004B7
_080FBD64:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #0xb
	ldr r2, _080FBD9C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #0xb
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_080FBD8C:
	ldr r3, _080FBDA0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r5, r4
	b _080FBEBE
	.align 2, 0
_080FBD9C: .4byte 0x000004B7
_080FBDA0: .4byte 0x0000046E
_080FBDA4:
	cmp r1, #3
	bhi _080FBE3C
	movs r2, #9
	ldr r1, _080FBDD0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080FBDDC
	ldr r4, _080FBDD4 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_080FBDC6:
	bl FUN_08236fac
	ldr r0, _080FBDD8 @ =0x0000046E
	adds r6, r5, r0
	b _080FBE1E
	.align 2, 0
_080FBDD0: .4byte 0x0000025D
_080FBDD4: .4byte 0x000004B7
_080FBDD8: .4byte 0x0000046E
_080FBDDC:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _080FBE34 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080FBE38 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #9
	bne _080FBE02
_080FBDF2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _080FBE02
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080FBE22
_080FBE02:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_080FBE1E:
	movs r0, #0
	strb r0, [r6]
_080FBE22:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
_080FBE2C:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080FBEC6
	.align 2, 0
_080FBE34: .4byte 0x000004B7
_080FBE38: .4byte 0x0000046E
_080FBE3C:
	movs r2, #9
	ldr r4, _080FBE68 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBE74
	ldr r1, _080FBE6C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #9
	movs r3, #1
	bl FUN_08236fac
	ldr r2, _080FBE70 @ =0x0000046E
	adds r6, r5, r2
	b _080FBEB4
	.align 2, 0
_080FBE68: .4byte 0x0000025D
_080FBE6C: .4byte 0x000004B7
_080FBE70: .4byte 0x0000046E
_080FBE74:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xa
	ldr r3, _080FBF0C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r4, _080FBF10 @ =0x0000046E
	adds r6, r5, r4
	cmp r1, #0xa
	bne _080FBE9C
	ldrb r0, [r6]
	cmp r0, #0
	bne _080FBE9C
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080FBEB8
_080FBE9C:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_080FBEB4:
	movs r0, #0
	strb r0, [r6]
_080FBEB8:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
_080FBEBE:
	ldr r1, _080FBF14 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_080FBEC6:
	ldr r2, _080FBF10 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_080FBECE:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _080FBF3C
	ldrh r0, [r1, #8]
	cmp r0, #1
	beq _080FBEE4
	cmp r0, #3
	bne _080FBF3C
_080FBEE4:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r4, r8
	ldrb r2, [r4, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _080FBF02
	rsbs r0, r0, #0
_080FBF02:
	cmp r0, #0x20
	bgt _080FBF18
	mov r0, r8
	strb r1, [r0, #5]
	b _080FBF3C
	.align 2, 0
_080FBF0C: .4byte 0x000004B7
_080FBF10: .4byte 0x0000046E
_080FBF14: .4byte 0xFFFEFFFF
_080FBF18:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FBF34
	adds r0, r2, #0
	adds r0, #0x20
	mov r4, r8
	strb r0, [r4, #5]
	b _080FBF3C
_080FBF34:
	adds r0, r2, #0
	subs r0, #0x20
	mov r1, r8
	strb r0, [r1, #5]
_080FBF3C:
	ldr r1, _080FBF54 @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FBF5C
	ldr r3, _080FBF58 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _080FBF6C
	.align 2, 0
_080FBF54: .4byte 0x0000A02F
_080FBF58: .4byte 0x00000482
_080FBF5C:
	ldr r4, _080FBF90 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _080FBF6C
	movs r0, #1
	strh r0, [r2]
_080FBF6C:
	ldr r1, _080FBF94 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FBF98
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _080FBFB0
	.align 2, 0
_080FBF90: .4byte 0x00000482
_080FBF94: .4byte 0x0000025D
_080FBF98:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_080FBFB0:
	ldr r2, _080FC060 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080FC0A0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _080FBFDA
	rsbs r1, r1, #0
_080FBFDA:
	cmp r1, #0
	bgt _080FC070
	ldr r4, _080FC064 @ =0x0000046B
	adds r0, r5, r4
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080FC0A0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
_080FC01C:
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080FC068 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080FC06C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _080FC064 @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r6, [r0]
	b _080FC0A0
	.align 2, 0
_080FC060: .4byte 0x0000046E
_080FC064: .4byte 0x0000046B
_080FC068: .4byte 0x0000046A
_080FC06C: .4byte 0x000005BC
_080FC070:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _080FC0B0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FC0B4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_080FC0A0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FC0B0: .4byte 0x0000046D
_080FC0B4: .4byte 0x0000046B
