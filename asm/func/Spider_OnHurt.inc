	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812DD46
	bl _0812EA56
_0812DD46:
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, sb
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	bne _0812DD56
	b _0812E300
_0812DD56:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0812DD68
	bl _0812EA56
_0812DD68:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812DD76
	b _0812E39E
_0812DD76:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r7, #4
	ldrh r0, [r0, #6]
	ands r0, r7
	cmp r0, #0
	beq _0812DD88
	bl _0812EA56
_0812DD88:
	movs r4, #1
	mov r0, sb
	ldrh r1, [r0, #6]
	adds r0, r1, #0
	ands r0, r4
	adds r3, r1, #0
	cmp r0, #0
	beq _0812DD9A
	b _0812E01E
_0812DD9A:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, sb
	ldr r1, [r2, #0x34]
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	bne _0812DDAE
	bl _0812EA56
_0812DDAE:
	ldr r2, _0812DE44 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812DDC4
	bl _0812EA56
_0812DDC4:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812DDD4
	bl _0812EA56
_0812DDD4:
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
	bne _0812DDEC
	b _0812DF36
_0812DDEC:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0812DE1A
	ands r3, r1
	cmp r3, #0
	beq _0812DE1A
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812DE14
	rsbs r1, r1, #0
_0812DE14:
	cmp r1, #0x20
	bgt _0812DE1A
	b _0812E45A
_0812DE1A:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0812DE48 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812DE50
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DE4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE44: .4byte 0x0000A007
_0812DE48: .4byte 0x0000048A
_0812DE4C: .4byte 0x03002BE0
_0812DE50:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812DE6C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DE68 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE68: .4byte 0x03002BE0
_0812DE6C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812DE88
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812DE84 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE84: .4byte 0x03002BE0
_0812DE88:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812DEA4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DEA0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DEA0: .4byte 0x03002BE0
_0812DEA4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812DEB6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0812DEBE
_0812DEB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812DEC0
_0812DEBE:
	movs r3, #1
_0812DEC0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r0, sb
	ldr r1, [r0, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0812DEE2
	bl _0812E6E8
_0812DEE2:
	movs r1, #2
	ldr r5, _0812DEF4 @ =0x00000474
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812DEF8
	movs r0, #1
	b _0812DEFA
	.align 2, 0
_0812DEF4: .4byte 0x00000474
_0812DEF8:
	movs r0, #0
_0812DEFA:
	cmp r0, #0
	beq _0812DF14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DF10 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812DF24
	.align 2, 0
_0812DF10: .4byte 0x03002BE0
_0812DF14:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812DF24
	bl _0812E6E8
_0812DF24:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	b _0812E6C0
_0812DF36:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0812DF60 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, sb
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0812DF68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DF64 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF60: .4byte 0x0000048A
_0812DF64: .4byte 0x03002BE0
_0812DF68:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812DF84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812DF80 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF80: .4byte 0x03002BE0
_0812DF84:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _0812DFA0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DF9C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF9C: .4byte 0x03002BE0
_0812DFA0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812DFBC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DFB8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DFB8: .4byte 0x03002BE0
_0812DFBC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812DFCE
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0812DFD6
_0812DFCE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812DFD8
_0812DFD6:
	movs r3, #1
_0812DFD8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0812E00C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0812DFF8
	b _0812E6E8
_0812DFF8:
	movs r1, #2
	ldr r2, _0812E010 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E014
	movs r0, #1
	b _0812E016
	.align 2, 0
_0812E00C: .4byte 0x0000049C
_0812E010: .4byte 0x00000474
_0812E014:
	movs r0, #0
_0812E016:
	cmp r0, #0
	beq _0812E01C
	b _0812E68E
_0812E01C:
	b _0812E6A4
_0812E01E:
	ldr r0, _0812E030 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812E034
	movs r0, #1
	b _0812E036
	.align 2, 0
_0812E030: .4byte 0x030047A4
_0812E034:
	movs r0, #0
_0812E036:
	cmp r0, #0
	beq _0812E044
	mov r0, sb
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0812E04C
_0812E044:
	mov r0, sb
	mov r1, r8
	bl Hitbox_ApplyDamage
_0812E04C:
	mov r0, sb
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0812E084 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0812E088 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x10]
	cmp r0, #2
	bls _0812E07A
	cmp r2, #0x17
	bne _0812E08C
_0812E07A:
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812E0AE
	.align 2, 0
_0812E084: .4byte 0x0000048C
_0812E088: .4byte 0x000001DF
_0812E08C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, sb
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0812E07A
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0812E0DC @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E0AE
	movs r1, #0
_0812E0AE:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r7, r0, #0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E0E8
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	ldrh r0, [r7]
	cmp r0, #0
	blt _0812E0E0
	asrs r0, r0, #1
	b _0812E0E6
	.align 2, 0
_0812E0DC: .4byte 0x00000187
_0812E0E0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0812E0E6:
	strh r0, [r7]
_0812E0E8:
	mov r2, sb
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0812E0FE
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	b _0812E170
_0812E0FE:
	mov r4, sp
	mov r3, sb
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r5, r8
	ldrh r0, [r5, #0xc]
	mov r5, sb
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
	bne _0812E160
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0812E160
	ldr r2, _0812E150 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812E154 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0812E158 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0812E15C @ =0x000001DD
	adds r1, r6, r4
	b _0812E174
	.align 2, 0
_0812E150: .4byte 0x030046B8
_0812E154: .4byte 0x000003FF
_0812E158: .4byte 0x0203B400
_0812E15C: .4byte 0x000001DD
_0812E160:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
_0812E170:
	ldr r3, _0812E194 @ =0x000001DD
	adds r1, r6, r3
_0812E174:
	strb r0, [r1]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E19C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812E198 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E194: .4byte 0x000001DD
_0812E198: .4byte 0x03002BE0
_0812E19C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E1B8
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E1B4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1B4: .4byte 0x03002BE0
_0812E1B8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E1D4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E1D0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1D0: .4byte 0x03002BE0
_0812E1D4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E1F0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E1EC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1EC: .4byte 0x03002BE0
_0812E1F0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E202
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812E20A
_0812E202:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E20C
_0812E20A:
	movs r3, #1
_0812E20C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0812E240 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812E2A8
	movs r1, #2
	ldr r2, _0812E244 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E248
	movs r0, #1
	b _0812E24A
	.align 2, 0
_0812E240: .4byte 0x0000049C
_0812E244: .4byte 0x00000474
_0812E248:
	movs r0, #0
_0812E24A:
	cmp r0, #0
	beq _0812E264
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E260 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E270
	.align 2, 0
_0812E260: .4byte 0x03002BE0
_0812E264:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E2A8
_0812E270:
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
_0812E2A8:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0812E2DC
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812E2DC
	ldr r0, _0812E2F4 @ =0x0000024E
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
	bls _0812E2DC
	strh r1, [r2]
_0812E2DC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812E2F8 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0812E2FC @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E2F2
	b _0812EA00
_0812E2F2:
	b _0812EA10
	.align 2, 0
_0812E2F4: .4byte 0x0000024E
_0812E2F8: .4byte 0x030046A0
_0812E2FC: .4byte 0x00000934
_0812E300:
	mov r0, sb
	movs r1, #0xe
	ldrsh r3, [r0, r1]
	mov r2, r8
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	subs r3, r3, r0
	asrs r3, r3, #1
	mov r2, sb
	ldrh r1, [r2, #0xc]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0812E3B8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	mov r1, sb
	ldrh r0, [r1, #0x10]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r5
	adds r5, r2, #0
	orrs r5, r0
	mov r2, r8
	movs r3, #0xc
	ldrsh r7, [r2, r3]
	movs r0, #0x1c
	ldrsh r3, [r2, r0]
	adds r1, r7, r3
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0812E34A
	b _0812EA56
_0812E34A:
	subs r0, r7, r3
	cmp r0, r2
	blt _0812E352
	b _0812EA56
_0812E352:
	mov r1, r8
	movs r2, #0x10
	ldrsh r7, [r1, r2]
	movs r0, #0x20
	ldrsh r3, [r1, r0]
	adds r1, r7, r3
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0812E368
	b _0812EA56
_0812E368:
	subs r0, r7, r3
	cmp r0, r2
	blt _0812E370
	b _0812EA56
_0812E370:
	mov r1, sb
	ldr r3, [r1, #0x48]
	cmp r3, #0
	beq _0812E382
	ldr r2, [r1, #0x4c]
	mov r0, sb
	mov r1, r8
	bl _call_via_r3
_0812E382:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0812E392
	b _0812EA56
_0812E392:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812E3C0
_0812E39E:
	ldr r4, _0812E3BC @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812E3AA
	b _0812EA56
_0812E3AA:
	movs r1, #0
	mov r5, r8
	strh r2, [r5, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0812EA56
	.align 2, 0
_0812E3B8: .4byte 0xFFFF0000
_0812E3BC: .4byte 0x0000048C
_0812E3C0:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r7, #4
	ldrh r0, [r0, #6]
	ands r0, r7
	cmp r0, #0
	beq _0812E3D0
	b _0812EA56
_0812E3D0:
	movs r4, #1
	mov r0, sb
	ldrh r1, [r0, #6]
	adds r0, r1, #0
	ands r0, r4
	adds r3, r1, #0
	cmp r0, #0
	beq _0812E3E2
	b _0812E728
_0812E3E2:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, sb
	ldr r1, [r2, #0x34]
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	bne _0812E3F4
	b _0812EA56
_0812E3F4:
	ldr r2, _0812E488 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E408
	b _0812EA56
_0812E408:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812E416
	b _0812EA56
_0812E416:
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
	bne _0812E42E
	b _0812E5B0
_0812E42E:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0812E498
	ands r3, r1
	cmp r3, #0
	beq _0812E498
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E456
	rsbs r1, r1, #0
_0812E456:
	cmp r1, #0x20
	bgt _0812E498
_0812E45A:
	mov r3, sb
	ldrh r0, [r3, #0x3c]
	ldr r5, _0812E48C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0812E490 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0812E494 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0812EA56
	.align 2, 0
_0812E488: .4byte 0x0000A007
_0812E48C: .4byte 0x000004BE
_0812E490: .4byte 0x0000048C
_0812E494: .4byte 0x0000044E
_0812E498:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0812E4C4 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E4CC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E4C8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E4C4: .4byte 0x0000048A
_0812E4C8: .4byte 0x03002BE0
_0812E4CC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E4E8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E4E4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E4E4: .4byte 0x03002BE0
_0812E4E8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E504
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E500 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E500: .4byte 0x03002BE0
_0812E504:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E520
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E51C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E51C: .4byte 0x03002BE0
_0812E520:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E532
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0812E53A
_0812E532:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E53C
_0812E53A:
	movs r3, #1
_0812E53C:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r0, sb
	ldr r1, [r0, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0812E55C
	b _0812E6E8
_0812E55C:
	movs r1, #2
	ldr r5, _0812E570 @ =0x00000474
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E574
	movs r0, #1
	b _0812E576
	.align 2, 0
_0812E570: .4byte 0x00000474
_0812E574:
	movs r0, #0
_0812E576:
	cmp r0, #0
	beq _0812E590
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E58C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E59E
	.align 2, 0
_0812E58C: .4byte 0x03002BE0
_0812E590:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812E59E
	b _0812E6E8
_0812E59E:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	b _0812E6C0
_0812E5B0:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0812E5D8 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, sb
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0812E5E0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E5DC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E5D8: .4byte 0x0000048A
_0812E5DC: .4byte 0x03002BE0
_0812E5E0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E5FC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E5F8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E5F8: .4byte 0x03002BE0
_0812E5FC:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _0812E618
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E614 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E614: .4byte 0x03002BE0
_0812E618:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E634
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E630 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E630: .4byte 0x03002BE0
_0812E634:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E646
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0812E64E
_0812E646:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E650
_0812E64E:
	movs r3, #1
_0812E650:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0812E680 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0812E6E8
	movs r1, #2
	ldr r2, _0812E684 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E688
	movs r0, #1
	b _0812E68A
	.align 2, 0
_0812E680: .4byte 0x0000049C
_0812E684: .4byte 0x00000474
_0812E688:
	movs r0, #0
_0812E68A:
	cmp r0, #0
	beq _0812E6A4
_0812E68E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E6A0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E6B0
	.align 2, 0
_0812E6A0: .4byte 0x03002BE0
_0812E6A4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E6E8
_0812E6B0:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
_0812E6C0:
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
_0812E6E8:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0812E714
	ldr r5, _0812E720 @ =0x0000024E
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
	bls _0812E714
	strh r1, [r2]
_0812E714:
	ldr r5, _0812E724 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0812EA56
	.align 2, 0
_0812E720: .4byte 0x0000024E
_0812E724: .4byte 0x0000048C
_0812E728:
	ldr r0, _0812E73C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812E740
	movs r0, #1
	b _0812E742
	.align 2, 0
_0812E73C: .4byte 0x030047A4
_0812E740:
	movs r0, #0
_0812E742:
	cmp r0, #0
	beq _0812E750
	mov r0, sb
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0812E758
_0812E750:
	mov r0, sb
	mov r1, r8
	bl Hitbox_ApplyDamage
_0812E758:
	mov r0, sb
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0812E790 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0812E794 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x10]
	cmp r0, #2
	bls _0812E786
	cmp r2, #0x17
	bne _0812E798
_0812E786:
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812E7BA
	.align 2, 0
_0812E790: .4byte 0x0000048C
_0812E794: .4byte 0x000001DF
_0812E798:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, sb
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0812E786
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0812E7E8 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E7BA
	movs r1, #0
_0812E7BA:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r7, r0, #0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E7F4
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	ldrh r0, [r7]
	cmp r0, #0
	blt _0812E7EC
	asrs r0, r0, #1
	b _0812E7F2
	.align 2, 0
_0812E7E8: .4byte 0x00000187
_0812E7EC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0812E7F2:
	strh r0, [r7]
_0812E7F4:
	mov r2, sb
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0812E814
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r3, _0812E810 @ =0x000001DD
	adds r1, r6, r3
	b _0812E882
	.align 2, 0
_0812E810: .4byte 0x000001DD
_0812E814:
	add r3, sp, #8
	mov r5, sb
	adds r5, #0xc
	mov r4, r8
	adds r4, #0xc
	mov r0, r8
	ldrh r2, [r0, #0xc]
	mov r1, sb
	ldrh r0, [r1, #0xc]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r0, r1, r0
	strh r0, [r3, #4]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne _0812E870
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0812E870
	ldr r2, _0812E860 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812E864 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0812E868 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _0812E86C @ =0x000001DD
	adds r1, r6, r3
	b _0812E882
	.align 2, 0
_0812E860: .4byte 0x030046B8
_0812E864: .4byte 0x000003FF
_0812E868: .4byte 0x0203B400
_0812E86C: .4byte 0x000001DD
_0812E870:
	movs r4, #0
	ldrsh r0, [r3, r4]
	add r1, sp, #8
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl ArcTan2_8
	ldr r2, _0812E8A4 @ =0x000001DD
	adds r1, r6, r2
_0812E882:
	strb r0, [r1]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E8AC
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812E8A8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8A4: .4byte 0x000001DD
_0812E8A8: .4byte 0x03002BE0
_0812E8AC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E8C8
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E8C4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8C4: .4byte 0x03002BE0
_0812E8C8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E8E4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E8E0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8E0: .4byte 0x03002BE0
_0812E8E4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E900
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E8FC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8FC: .4byte 0x03002BE0
_0812E900:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E912
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812E91A
_0812E912:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E91C
_0812E91A:
	movs r3, #1
_0812E91C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0812E950 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812E9B8
	movs r1, #2
	ldr r2, _0812E954 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E958
	movs r0, #1
	b _0812E95A
	.align 2, 0
_0812E950: .4byte 0x0000049C
_0812E954: .4byte 0x00000474
_0812E958:
	movs r0, #0
_0812E95A:
	cmp r0, #0
	beq _0812E974
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E970 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E980
	.align 2, 0
_0812E970: .4byte 0x03002BE0
_0812E974:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E9B8
_0812E980:
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
_0812E9B8:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0812E9EC
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812E9EC
	ldr r0, _0812EA04 @ =0x0000024E
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
	bls _0812E9EC
	strh r1, [r2]
_0812E9EC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812EA08 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0812EA0C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812EA10
_0812EA00:
	movs r0, #1
	b _0812EA12
	.align 2, 0
_0812EA04: .4byte 0x0000024E
_0812EA08: .4byte 0x030046A0
_0812EA0C: .4byte 0x00000934
_0812EA10:
	movs r0, #0
_0812EA12:
	ldr r1, _0812EA68 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0812EA2A
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	strh r0, [r7]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #0x10]
	strb r0, [r3]
_0812EA2A:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	strh r0, [r4]
	movs r0, #0xc4
	lsls r0, r0, #1
	adds r1, r6, r0
	mov r2, sb
	ldrh r0, [r2, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812EA56:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EA68: .4byte 0x0000048A
