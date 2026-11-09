	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0811FBF8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811FBFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811FBFE
	.align 2, 0
_0811FBF8: .4byte 0x0000046C
_0811FBFC:
	movs r0, #0
_0811FBFE:
	cmp r0, #0
	beq _0811FC0A
	ldr r3, _0811FC3C @ =0x0000046B
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_0811FC0A:
	adds r0, r6, #0
	bl Golem_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FC18
	b _08120186
_0811FC18:
	ldr r4, _0811FC3C @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811FC24
	b _0812017C
_0811FC24:
	adds r3, r7, #0
	ldr r0, _0811FC40 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #7
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _0811FC44
	movs r0, #1
	b _0811FC46
	.align 2, 0
_0811FC3C: .4byte 0x0000046B
_0811FC40: .4byte 0x030047A4
_0811FC44:
	movs r0, #0
_0811FC46:
	cmp r0, #0
	beq _0811FC74
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811FC84
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811FC62
	adds r2, r0, #0
_0811FC62:
	cmp r2, #0
	blt _0811FC84
	ldr r1, _0811FC70 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _0811FC76
	.align 2, 0
_0811FC70: .4byte 0x03002BE0
_0811FC74:
	ldr r0, _0811FCDC @ =0x03002BE0
_0811FC76:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811FCC2
_0811FC84:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811FCC2
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	subs r0, r0, r1
	cmp r0, #0
	bge _0811FCA8
	movs r0, #0
_0811FCA8:
	ldr r2, _0811FCE0 @ =0x000006BC
	adds r1, r7, r2
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _0811FCC2
	strh r2, [r1]
_0811FCC2:
	ldr r0, _0811FCE4 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811FCE8
	movs r0, #1
	b _0811FCEA
	.align 2, 0
_0811FCDC: .4byte 0x03002BE0
_0811FCE0: .4byte 0x000006BC
_0811FCE4: .4byte 0x000006B4
_0811FCE8:
	movs r0, #0
_0811FCEA:
	adds r5, r0, #0
	cmp r5, #0
	beq _0811FD68
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811FDE4
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811FD08
	adds r2, r0, #0
_0811FD08:
	cmp r2, #0
	blt _0811FDE4
	ldr r1, _0811FD54 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811FDE4
	ldr r2, _0811FD58 @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811FD5C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FD60 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FD64 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _0811FF90
	.align 2, 0
_0811FD54: .4byte 0x03002BE0
_0811FD58: .4byte Golem_StateUncurl
_0811FD5C: .4byte 0x0000046D
_0811FD60: .4byte 0x0000046B
_0811FD64: .4byte 0x00000553
_0811FD68:
	ldr r0, _0811FDC8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0811FDE4
	ldr r2, _0811FDCC @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811FDD0 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0811FDD4 @ =0x0000046B
	adds r0, r6, r7
	strb r5, [r0]
	adds r3, #0xe6
	adds r0, r6, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #2
	movs r3, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FDD8 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FDDC @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0811FDE0 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r4, [r0]
	b _08120186
	.align 2, 0
_0811FDC8: .4byte 0x03002BE0
_0811FDCC: .4byte Golem_StateUncurl
_0811FDD0: .4byte 0x0000046D
_0811FDD4: .4byte 0x0000046B
_0811FDD8: .4byte 0x00000469
_0811FDDC: .4byte 0x0000046A
_0811FDE0: .4byte 0x00000484
_0811FDE4:
	ldr r1, _0811FE1C @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0811FEE4
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811FEA0
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811FE28
	ldr r1, _0811FE20 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _0811FE24 @ =0x0000018F
	cmp r1, r0
	bls _0811FE34
	b _0811FE38
	.align 2, 0
_0811FE1C: .4byte 0x000006B4
_0811FE20: .4byte 0x000006BC
_0811FE24: .4byte 0x0000018F
_0811FE28:
	ldr r1, _0811FE8C @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811FE34
	movs r2, #1
_0811FE34:
	cmp r2, #0
	beq _0811FE6C
_0811FE38:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r1, r3, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811FE6C
	adds r0, r4, #0
	adds r0, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811FE6E
_0811FE6C:
	movs r1, #0
_0811FE6E:
	cmp r1, #0
	beq _0811FEA0
	ldr r2, _0811FE90 @ =Golem_StateCharge
	movs r1, #0x27
	ldr r3, _0811FE94 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FE98 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FE9C @ =0x00000553
	b _0811FF76
	.align 2, 0
_0811FE8C: .4byte 0x000006BC
_0811FE90: .4byte Golem_StateCharge
_0811FE94: .4byte 0x0000046D
_0811FE98: .4byte 0x0000046B
_0811FE9C: .4byte 0x00000553
_0811FEA0:
	ldr r2, _0811FED4 @ =Golem_StateUncurl
	movs r1, #0x26
	ldr r3, _0811FED8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FEDC @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _0811FEE0 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	b _0811FF90
	.align 2, 0
_0811FED4: .4byte Golem_StateUncurl
_0811FED8: .4byte 0x0000046D
_0811FEDC: .4byte 0x0000046B
_0811FEE0: .4byte 0x00000553
_0811FEE4:
	adds r3, r7, #0
	adds r4, r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811FFCC
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811FF18
	ldr r1, _0811FF10 @ =0x000006BC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r0, _0811FF14 @ =0x0000018F
	cmp r1, r0
	bls _0811FF24
	b _0811FF28
	.align 2, 0
_0811FF10: .4byte 0x000006BC
_0811FF14: .4byte 0x0000018F
_0811FF18:
	ldr r1, _0811FFB0 @ =0x000006BC
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0811FF24
	movs r2, #1
_0811FF24:
	cmp r2, #0
	beq _0811FF5A
_0811FF28:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	adds r2, #8
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0811FF5A
	adds r0, r4, #0
	adds r0, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r1, [r1]
	adds r1, #8
	movs r2, #0xa
	movs r3, #0x80
	lsls r3, r3, #1
	bl Map_HasLineOfSight
	lsls r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	bne _0811FF5C
_0811FF5A:
	movs r1, #0
_0811FF5C:
	cmp r1, #0
	beq _0811FFCC
	ldr r2, _0811FFB4 @ =Golem_StateCharge
	movs r1, #0x27
	ldr r7, _0811FFB8 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _0811FFBC @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r7, #0xe6
_0811FF76:
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
_0811FF90:
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0811FFC0 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0811FFC4 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _0811FFC8 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _08120186
	.align 2, 0
_0811FFB0: .4byte 0x000006BC
_0811FFB4: .4byte Golem_StateCharge
_0811FFB8: .4byte 0x0000046D
_0811FFBC: .4byte 0x0000046B
_0811FFC0: .4byte 0x00000469
_0811FFC4: .4byte 0x0000046A
_0811FFC8: .4byte 0x00000484
_0811FFCC:
	ldr r1, _08120014 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	mov sl, sp
	ldr r2, _08120018 @ =0x030046A4
	mov r8, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812001C
	adds r0, #4
	b _08120028
	.align 2, 0
_08120014: .4byte 0x00000256
_08120018: .4byte 0x030046A4
_0812001C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08120028:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r4, #0
	mov r8, r4
	mov r1, sl
	strh r0, [r1, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	mov r5, sp
	mov r0, sp
	bl Golem_SnapToTileCenter
	add r3, sp, #8
	adds r4, r6, #0
	adds r4, #8
	ldrh r0, [r6, #8]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081200B4 @ =0x00000FFF
	cmp r1, r0
	bgt _081200C8
	adds r0, r7, #0
	bl Golem_RouteTo
	movs r1, #2
	movs r2, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	ldr r7, _081200B8 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081200BC @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081200C0 @ =0x00000484
	adds r0, r6, r2
	movs r3, #0
	str r3, [r0]
	ldr r4, _081200C4 @ =0x0000046C
	adds r1, r6, r4
	movs r0, #1
	strb r0, [r1]
	b _08120186
	.align 2, 0
_081200B4: .4byte 0x00000FFF
_081200B8: .4byte 0x00000469
_081200BC: .4byte 0x0000046A
_081200C0: .4byte 0x00000484
_081200C4: .4byte 0x0000046C
_081200C8:
	ldr r1, _08120160 @ =0x000004A4
	adds r0, r6, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r5, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	movs r4, #4
	ldrsh r1, [r3, r4]
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r2, _08120164 @ =0x000006C2
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _08120168 @ =Golem_StateRoll
	movs r1, #0x22
	ldr r4, _0812016C @ =0x0000046D
	adds r0, r6, r4
	movs r2, #1
	strb r2, [r0]
	ldr r7, _08120170 @ =0x0000046B
	adds r0, r6, r7
	mov r4, r8
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	strh r4, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	mov r3, r8
	strb r3, [r0]
	ldr r4, _08120174 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08120178 @ =0x00000484
	adds r0, r6, r1
	movs r3, #0
	str r3, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	b _08120186
	.align 2, 0
_08120160: .4byte 0x000004A4
_08120164: .4byte 0x000006C2
_08120168: .4byte Golem_StateRoll
_0812016C: .4byte 0x0000046D
_08120170: .4byte 0x0000046B
_08120174: .4byte 0x00000469
_08120178: .4byte 0x00000484
_0812017C:
	ldr r7, _08120198 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08120186:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08120198: .4byte 0x00000484
