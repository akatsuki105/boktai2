	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08108A44
	b _08109104
_08108A44:
	movs r1, #0x10
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108A58
	movs r0, #1
	b _08108A5A
_08108A58:
	movs r0, #0
_08108A5A:
	cmp r0, #0
	beq _08108A60
	b _08109104
_08108A60:
	ldr r3, _08108AA0 @ =0x00000724
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08108A6C
	b _08109104
_08108A6C:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08108A7C
	b _08109104
_08108A7C:
	movs r4, #0x8e
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _08108AA8
	ldr r5, _08108AA4 @ =0x0000048C
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08108A94
	b _08109104
_08108A94:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08109104
	.align 2, 0
_08108AA0: .4byte 0x00000724
_08108AA4: .4byte 0x0000048C
_08108AA8:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08108AB8
	b _08109104
_08108AB8:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08108AC8
	b _08108DD4
_08108AC8:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08108ADA
	b _08109104
_08108ADA:
	ldr r2, _08108B6C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08108AEE
	b _08109104
_08108AEE:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08108AFC
	b _08109104
_08108AFC:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _08108B14
	b _08108C5C
_08108B14:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08108B7C
	ands r3, r1
	cmp r3, #0
	beq _08108B7C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08108B3A
	rsbs r1, r1, #0
_08108B3A:
	cmp r1, #0x20
	bgt _08108B7C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08108B70 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08108B74 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08108B78 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08109104
	.align 2, 0
_08108B6C: .4byte 0x0000A007
_08108B70: .4byte 0x000004BE
_08108B74: .4byte 0x0000048C
_08108B78: .4byte 0x0000044E
_08108B7C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08108BA4 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08108BAC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108BA8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BA4: .4byte 0x0000048A
_08108BA8: .4byte 0x03002BE0
_08108BAC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108BC8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108BC4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BC4: .4byte 0x03002BE0
_08108BC8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08108BE4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108BE0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BE0: .4byte 0x03002BE0
_08108BE4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108C00
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108BFC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BFC: .4byte 0x03002BE0
_08108C00:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108C12
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08108C1A
_08108C12:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108C1C
_08108C1A:
	movs r3, #1
_08108C1C:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08108C50 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08108C3E
	b _08108D94
_08108C3E:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108C54
	movs r0, #1
	b _08108C56
	.align 2, 0
_08108C50: .4byte 0x0000049C
_08108C54:
	movs r0, #0
_08108C56:
	cmp r0, #0
	bne _08108D3A
	b _08108D50
_08108C5C:
	strh r2, [r7, #0x3e]
	ldr r1, _08108C84 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08108C8C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108C88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108C84: .4byte 0x0000048A
_08108C88: .4byte 0x03002BE0
_08108C8C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108CA8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108CA4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CA4: .4byte 0x03002BE0
_08108CA8:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08108CC4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108CC0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CC0: .4byte 0x03002BE0
_08108CC4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108CE0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108CDC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CDC: .4byte 0x03002BE0
_08108CE0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108CF2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08108CFA
_08108CF2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108CFC
_08108CFA:
	movs r3, #1
_08108CFC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08108D30 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08108D94
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108D34
	movs r0, #1
	b _08108D36
	.align 2, 0
_08108D30: .4byte 0x0000049C
_08108D34:
	movs r0, #0
_08108D36:
	cmp r0, #0
	beq _08108D50
_08108D3A:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108D4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08108D5C
	.align 2, 0
_08108D4C: .4byte 0x03002BE0
_08108D50:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08108D94
_08108D5C:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08108D94:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08108DC0
	ldr r5, _08108DCC @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08108DC0
	strh r1, [r2]
_08108DC0:
	ldr r5, _08108DD0 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08109104
	.align 2, 0
_08108DCC: .4byte 0x0000024E
_08108DD0: .4byte 0x0000048C
_08108DD4:
	ldr r0, _08108DE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08108DEC
	movs r0, #1
	b _08108DEE
	.align 2, 0
_08108DE8: .4byte 0x030047A4
_08108DEC:
	movs r0, #0
_08108DEE:
	cmp r0, #0
	beq _08108DFC
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08108E04
_08108DFC:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08108E04:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08108E3C @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08108E40 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08108E32
	cmp r2, #0x17
	bne _08108E44
_08108E32:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08108E66
	.align 2, 0
_08108E3C: .4byte 0x0000048C
_08108E40: .4byte 0x000001DF
_08108E44:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08108E32
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08108E94 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08108E66
	movs r1, #0
_08108E66:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08108EA2
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08108E98
	asrs r0, r0, #1
	b _08108E9E
	.align 2, 0
_08108E94: .4byte 0x00000187
_08108E98:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08108E9E:
	mov r2, sb
	strh r0, [r2]
_08108EA2:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08108EC0
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08108EBC @ =0x000001DD
	adds r1, r6, r4
	b _08108F34
	.align 2, 0
_08108EBC: .4byte 0x000001DD
_08108EC0:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08108F20
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08108F20
	ldr r2, _08108F10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08108F14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08108F18 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08108F1C @ =0x000001DD
	adds r1, r6, r4
	b _08108F34
	.align 2, 0
_08108F10: .4byte 0x030046B8
_08108F14: .4byte 0x000003FF
_08108F18: .4byte 0x0203B400
_08108F1C: .4byte 0x000001DD
_08108F20:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08108F54 @ =0x000001DD
	adds r1, r6, r3
_08108F34:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08108F5C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108F58 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F54: .4byte 0x000001DD
_08108F58: .4byte 0x03002BE0
_08108F5C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108F78
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108F74 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F74: .4byte 0x03002BE0
_08108F78:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08108F94
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108F90 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F90: .4byte 0x03002BE0
_08108F94:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108FB0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108FAC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108FAC: .4byte 0x03002BE0
_08108FB0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108FC2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08108FCA
_08108FC2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108FCC
_08108FCA:
	movs r3, #1
_08108FCC:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _08109000 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08109068
	movs r1, #2
	ldr r2, _08109004 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08109008
	movs r0, #1
	b _0810900A
	.align 2, 0
_08109000: .4byte 0x0000049C
_08109004: .4byte 0x00000474
_08109008:
	movs r0, #0
_0810900A:
	cmp r0, #0
	beq _08109024
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08109020 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08109030
	.align 2, 0
_08109020: .4byte 0x03002BE0
_08109024:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08109068
_08109030:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08109068:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0810909C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0810909C
	ldr r0, _081090B4 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0810909C
	strh r1, [r2]
_0810909C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081090B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081090BC @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081090C0
	movs r0, #1
	b _081090C2
	.align 2, 0
_081090B4: .4byte 0x0000024E
_081090B8: .4byte 0x030046A0
_081090BC: .4byte 0x00000934
_081090C0:
	movs r0, #0
_081090C2:
	ldr r1, _08109114 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081090DA
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081090DA:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08109104:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08109114: .4byte 0x0000048A
