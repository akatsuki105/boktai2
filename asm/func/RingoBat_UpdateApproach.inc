	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov sl, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _0805BF7A
	b _0805C084
_0805BF7A:
	movs r0, #0
	strb r0, [r5]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C026
	ldr r2, _0805BFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805BFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805BFC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r6, [r0]
	ldr r1, _0805BFC8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805BFCC
	asrs r3, r0, #0xc
	b _0805BFD2
	.align 2, 0
_0805BFBC: .4byte 0x030046B8
_0805BFC0: .4byte 0x000003FF
_0805BFC4: .4byte 0x0203B400
_0805BFC8: .4byte gSineTable
_0805BFCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805BFD2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805BFEE
	asrs r0, r0, #0xc
	b _0805BFF4
_0805BFEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BFF4:
	strh r0, [r4, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C026:
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #0x18
	ldrsh r2, [r5, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r4, _0805C094 @ =0x0203B400
	ldr r2, _0805C098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C09C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r1, [r5, #6]
	adds r0, r0, r1
	strb r0, [r5, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	adds r2, r5, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C084:
	mov r2, sb
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	beq _0805C0A0
	movs r0, #5
	movs r1, #0
	b _0805C0AA
	.align 2, 0
_0805C094: .4byte 0x0203B400
_0805C098: .4byte 0x030046B8
_0805C09C: .4byte 0x000003FF
_0805C0A0:
	mov r3, sb
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _0805C0B4
	movs r0, #9
_0805C0AA:
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #4]
	b _0805C320
_0805C0B4:
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _0805C0BC
	b _0805C210
_0805C0BC:
	ldr r6, _0805C110 @ =0x0203B400
	ldr r2, _0805C114 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0805C118 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r6
	movs r4, #0xff
	ldrb r0, [r0]
	cmp r0, #0xbf
	ble _0805C0D8
	b _0805C1CC
_0805C0D8:
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C180
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r3, sp
	ands r2, r4
	ldr r1, _0805C11C @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805C120
	asrs r1, r0, #0xc
	b _0805C126
	.align 2, 0
_0805C110: .4byte 0x0203B400
_0805C114: .4byte 0x030046B8
_0805C118: .4byte 0x000003FF
_0805C11C: .4byte gSineTable
_0805C120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C126:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805C144 @ =gSineTable
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C148
	asrs r0, r0, #0xc
	b _0805C14E
	.align 2, 0
_0805C144: .4byte gSineTable
_0805C148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C14E:
	strh r0, [r3, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C180:
	adds r4, r5, #0
	adds r4, #0x14
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r2, _0805C1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C1C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C1C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r2, [r5, #6]
	adds r0, r0, r2
	strb r0, [r5, #6]
	b _0805C1E4
	.align 2, 0
_0805C1C0: .4byte 0x030046B8
_0805C1C4: .4byte 0x000003FF
_0805C1C8: .4byte 0x0203B400
_0805C1CC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805C204 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r5, #6]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C1E4:
	ldr r2, _0805C208 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C20C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C204 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	b _0805C21C
	.align 2, 0
_0805C204: .4byte 0x0203B400
_0805C208: .4byte 0x030046B8
_0805C20C: .4byte 0x000003FF
_0805C210:
	subs r0, #1
	strb r0, [r5, #7]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C21C:
	mov r6, sp
	ldrb r2, [r5, #6]
	mov ip, r2
	ldrh r3, [r5, #0x10]
	mov r8, r3
	ldr r2, _0805C248 @ =gSineTable
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805C24C
	asrs r3, r0, #0xc
	b _0805C252
	.align 2, 0
_0805C248: .4byte gSineTable
_0805C24C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C252:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C270
	asrs r0, r0, #0xc
	b _0805C276
_0805C270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C276:
	movs r2, #0
	mov r8, r2
	strh r0, [r6, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl RingoBat_SetAnim
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r7, r3]
	movs r3, #4
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C2E0 @ =0x00003FFF
	cmp r1, r0
	bgt _0805C2E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _0805C31E
	.align 2, 0
_0805C2E0: .4byte 0x00003FFF
_0805C2E4:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0805C31A
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C31A
	mov r1, sb
	ldrb r0, [r1, #0x1f]
	cmp r0, #2
	bne _0805C30C
	mov r2, sl
	cmp r2, #7
	bgt _0805C306
	movs r0, #1
	b _0805C318
_0805C306:
	mov r3, r8
	strb r3, [r5, #8]
	b _0805C31A
_0805C30C:
	cmp r0, #0
	bne _0805C316
	mov r4, r8
	strb r4, [r5, #8]
	b _0805C31A
_0805C316:
	movs r0, #0xff
_0805C318:
	strb r0, [r5, #8]
_0805C31A:
	ldrh r0, [r5, #4]
	adds r0, #1
_0805C31E:
	strh r0, [r5, #4]
_0805C320:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
