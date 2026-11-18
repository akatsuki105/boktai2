	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	mov r1, sb
	ldr r0, [r1, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r1, _081AECC4 @ =0x0000046D
	add r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AECC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AECCA
	.align 2, 0
_081AECC4: .4byte 0x0000046D
_081AECC8:
	movs r0, #0
_081AECCA:
	cmp r0, #0
	beq _081AED82
	movs r0, #0xfe
	lsls r0, r0, #1
	add r0, sb
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	mov r2, sb
	strb r0, [r2, #5]
	mov r0, sb
	movs r1, #5
	bl Enemy_PlayAnim
	movs r2, #4
	ldr r1, _081AED00 @ =0x0000065C
	add r1, sl
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081AED04
	movs r0, #1
	b _081AED06
	.align 2, 0
_081AED00: .4byte 0x0000065C
_081AED04:
	movs r0, #0
_081AED06:
	cmp r0, #0
	beq _081AED1A
	movs r1, #0
	movs r0, #2
	strh r0, [r4, #8]
	strh r1, [r4, #0xe]
	subs r0, #7
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081AED1A:
	ldr r0, _081AED2C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AED30
	movs r0, #1
	b _081AED32
	.align 2, 0
_081AED2C: .4byte 0x030047A4
_081AED30:
	movs r0, #0
_081AED32:
	cmp r0, #0
	beq _081AED6C
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	beq _081AED82
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081AED4E
	adds r3, r0, #0
_081AED4E:
	cmp r3, #0
	blt _081AED82
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _081AED68 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	b _081AED7E
	.align 2, 0
_081AED68: .4byte 0x03002BE0
_081AED6C:
	movs r2, #0xcc
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
_081AED7E:
	str r0, [r2]
	str r1, [r2, #4]
_081AED82:
	ldrh r0, [r4, #8]
	cmp r0, #5
	beq _081AED8A
	b _081AF1A4
_081AED8A:
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _081AED92
	b _081AF1A4
_081AED92:
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	adds r1, #0xfd
	add r1, sb
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081AEDB8
	ldr r2, _081AEDB4 @ =0xFFFFFF00
	adds r1, r1, r2
	b _081AEDC6
	.align 2, 0
_081AEDB4: .4byte 0xFFFFFF00
_081AEDB8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081AEDC6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081AEDC6:
	adds r0, r1, #0
	cmp r1, #0
	bge _081AEDCE
	rsbs r0, r1, #0
_081AEDCE:
	cmp r0, #0x1f
	bgt _081AEE44
	ldr r0, _081AEDE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AEDE8
	movs r0, #1
	b _081AEDEA
	.align 2, 0
_081AEDE4: .4byte 0x030047A4
_081AEDE8:
	movs r0, #0
_081AEDEA:
	cmp r0, #0
	beq _081AEE2C
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	cmp r1, #0
	bne _081AEDFC
	b _081AF14A
_081AEDFC:
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081AEE08
	adds r3, r0, #0
_081AEE08:
	cmp r3, #0
	bge _081AEE0E
	b _081AF14A
_081AEE0E:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _081AEE28 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	b _081AF14A
	.align 2, 0
_081AEE28: .4byte 0x03002BE0
_081AEE2C:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, sl
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	b _081AF14A
_081AEE44:
	ldr r4, _081AEE60 @ =0x00000256
	add r4, sb
	ldrh r6, [r4]
	mov r5, sb
	adds r5, #8
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AEE64
	adds r0, #4
	b _081AEE70
	.align 2, 0
_081AEE60: .4byte 0x00000256
_081AEE64:
	ldr r0, _081AEE84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AEE70:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081AEE88
	cmp r3, #2
	beq _081AEE8C
	b _081AEE90
	.align 2, 0
_081AEE84: .4byte 0x030046A4
_081AEE88:
	ldrb r0, [r5, #4]
	b _081AEE8E
_081AEE8C:
	ldrb r0, [r5]
_081AEE8E:
	subs r2, r2, r0
_081AEE90:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AEEA2
	adds r0, #4
	b _081AEEAE
_081AEEA2:
	ldr r0, _081AEEC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AEEAE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081AEEC4
	asrs r0, r0, #6
	b _081AEECA
	.align 2, 0
_081AEEC0: .4byte 0x030046A4
_081AEEC4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081AEECA:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081AEF08
	cmp r1, #1
	bgt _081AEEDC
	cmp r1, #0
	beq _081AEEE6
	b _081AEFC8
_081AEEDC:
	cmp r1, #2
	beq _081AEF44
	cmp r1, #3
	beq _081AEF66
	b _081AEFC8
_081AEEE6:
	adds r4, r6, #1
	movs r5, #0
_081AEEEA:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEF04
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081AEEEA
_081AEF04:
	subs r5, r4, #1
	b _081AEFCA
_081AEF08:
	ldr r1, _081AEF40 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_081AEF16:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEFA0
	ldr r0, _081AEF40 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081AEF16
	subs r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEF40: .4byte 0x030046A4
_081AEF44:
	subs r4, r6, #1
	movs r5, #0
_081AEF48:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEF62
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081AEF48
_081AEF62:
	adds r5, r4, #1
	b _081AEFCA
_081AEF66:
	ldr r1, _081AEF9C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
_081AEF74:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AEFB4
	ldr r0, _081AEF9C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081AEF74
	adds r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEF9C: .4byte 0x030046A4
_081AEFA0:
	ldr r1, _081AEFB0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEFB0: .4byte 0x030046A4
_081AEFB4:
	ldr r1, _081AEFC4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _081AEFCA
	.align 2, 0
_081AEFC4: .4byte 0x030046A4
_081AEFC8:
	ldrh r5, [r4]
_081AEFCA:
	movs r6, #0xcd
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _081AF00C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _081AF00C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AF010
	adds r0, #4
	b _081AF01C
	.align 2, 0
_081AF00C: .4byte 0x030046A4
_081AF010:
	ldr r1, _081AF03C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AF01C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r2, sb
	ldrb r0, [r2, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081AF040
	asrs r0, r0, #6
	b _081AF046
	.align 2, 0
_081AF03C: .4byte 0x030046A4
_081AF040:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081AF046:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081AF06E
	cmp r1, #1
	bgt _081AF058
	cmp r1, #0
	beq _081AF062
	b _081AF0BA
_081AF058:
	cmp r1, #2
	beq _081AF088
	cmp r1, #3
	beq _081AF0A4
	b _081AF0BA
_081AF062:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _081AF092
_081AF06E:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _081AF084 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0x7f
	b _081AF0B8
	.align 2, 0
_081AF084: .4byte 0x0000066C
_081AF088:
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_081AF092:
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0, #0xc]
	ldr r0, _081AF0A0 @ =0x0000066C
	add r0, sl
	strh r1, [r0]
	b _081AF0BA
	.align 2, 0
_081AF0A0: .4byte 0x0000066C
_081AF0A4:
	mov r2, sb
	ldrh r1, [r2, #8]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
	ldr r1, _081AF0E8 @ =0x0000066C
	add r1, sl
	ldrh r0, [r1]
	subs r0, #0x7f
_081AF0B8:
	strh r0, [r1]
_081AF0BA:
	movs r5, #0xcd
	lsls r5, r5, #3
	add r5, sl
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AF0E4
	cmp r1, #0
	blt _081AF0E4
	ldr r0, _081AF0EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AF0E4
	ldr r0, _081AF0F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AF0F4
_081AF0E4:
	movs r4, #0
	b _081AF102
	.align 2, 0
_081AF0E8: .4byte 0x0000066C
_081AF0EC: .4byte 0x030046A8
_081AF0F0: .4byte 0x030046AC
_081AF0F4:
	ldr r0, _081AF114 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AF102:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081AF118
	adds r0, #4
	b _081AF124
	.align 2, 0
_081AF114: .4byte 0x030046A4
_081AF118:
	ldr r0, _081AF138 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AF124:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AF13C
	cmp r2, #2
	beq _081AF140
	b _081AF144
	.align 2, 0
_081AF138: .4byte 0x030046A4
_081AF13C:
	ldrb r0, [r5, #4]
	b _081AF142
_081AF140:
	ldrb r0, [r5]
_081AF142:
	subs r1, r1, r0
_081AF144:
	ldr r0, _081AF1C8 @ =0x0000066A
	add r0, sl
	strh r1, [r0]
_081AF14A:
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _081AF1CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xcd
	lsls r1, r1, #3
	add r1, sl
	ldr r0, _081AF1D0 @ =0x00000226
	add r0, sb
	ldrh r2, [r0]
	ldr r0, _081AF1D4 @ =0x0000022E
	add r0, sb
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _081AF1D8 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r0, _081AF1DC @ =0x00000674
	add r0, sl
	ldrb r0, [r0]
	str r0, [sp, #8]
	movs r0, #0x1e
	str r0, [sp, #0xc]
	subs r0, #0x32
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	bl Entity081f3324_Spawn
	movs r0, #0xd6
	bl PlaySound_082406e0
_081AF1A4:
	ldr r0, _081AF1E0 @ =0x0000046E
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _081AF1B6
	ldr r1, _081AF1E4 @ =0x0000046B
	add r1, sb
	movs r0, #1
	strb r0, [r1]
_081AF1B6:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AF1C8: .4byte 0x0000066A
_081AF1CC: .4byte 0x0000FFFF
_081AF1D0: .4byte 0x00000226
_081AF1D4: .4byte 0x0000022E
_081AF1D8: .4byte 0x00000236
_081AF1DC: .4byte 0x00000674
_081AF1E0: .4byte 0x0000046E
_081AF1E4: .4byte 0x0000046B
