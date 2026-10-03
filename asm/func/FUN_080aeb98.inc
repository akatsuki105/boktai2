	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _080AEBF8 @ =0x00001348
	adds r1, r4, r0
	ldr r3, _080AEBFC @ =0x0000134A
	adds r2, r4, r3
	ldrh r0, [r1]
	ldrh r5, [r2]
	cmp r0, r5
	bhs _080AEC10
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r2]
	cmp r0, r2
	bhs _080AEBC4
	b _080AEE04
_080AEBC4:
	ldr r0, _080AEC00 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC04 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r5, _080AEC08 @ =0x00001352
	adds r1, r4, r5
	strh r0, [r1]
	ldr r0, _080AEC0C @ =0x0000134C
	adds r1, r4, r0
	b _080AEE00
	.align 2, 0
_080AEBF8: .4byte 0x00001348
_080AEBFC: .4byte 0x0000134A
_080AEC00: .4byte 0x03002BE0
_080AEC04: .4byte 0x00000504
_080AEC08: .4byte 0x00001352
_080AEC0C: .4byte 0x0000134C
_080AEC10:
	ldr r0, _080AEC50 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC54 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r5, _080AEC58 @ =0x00001352
	adds r3, r4, r5
	ldrh r2, [r3]
	ldr r5, _080AEC5C @ =0xFFFFFF00
	adds r1, r2, r5
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080AEC60
	adds r0, r2, #1
	b _080AEC66
	.align 2, 0
_080AEC50: .4byte 0x03002BE0
_080AEC54: .4byte 0x00000504
_080AEC58: .4byte 0x00001352
_080AEC5C: .4byte 0xFFFFFF00
_080AEC60:
	adds r0, r2, #0
	adds r0, #0xff
	movs r1, #0xff
_080AEC66:
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080AED04 @ =0x0000134C
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _080AEC7E
	b _080AEDFC
_080AEC7E:
	ldrh r0, [r5]
	movs r1, #7
	bl Mod
	cmp r0, #0
	beq _080AEC8C
	b _080AEE04
_080AEC8C:
	ldr r7, _080AED08 @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AED0C @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AED10 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x30
	bl Mod
	ldr r3, _080AED14 @ =0x00001352
	adds r1, r4, r3
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r6, r0, #0
	subs r6, #0x18
	movs r3, #0xff
	mov sb, r3
	ands r6, r3
	ldrh r0, [r5]
	movs r1, #0x2a
	bl Mod
	cmp r0, #0
	bne _080AED68
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AED10 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #8
	ldr r1, _080AED18 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED1C
	asrs r2, r0, #0xc
	b _080AED22
	.align 2, 0
_080AED04: .4byte 0x0000134C
_080AED08: .4byte 0x030046B8
_080AED0C: .4byte 0x000003FF
_080AED10: .4byte 0x0203B400
_080AED14: .4byte 0x00001352
_080AED18: .4byte 0x085B0A08
_080AED1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AED22:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED3A
	asrs r0, r0, #0xc
	b _080AED40
_080AED3A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AED40:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AED64 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #8
	b _080AEDEE
	.align 2, 0
_080AED64: .4byte 0x0000134E
_080AED68:
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEDA0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #0xc
	ldr r1, _080AEDA4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDA8
	asrs r2, r0, #0xc
	b _080AEDAE
	.align 2, 0
_080AEDA0: .4byte 0x0203B400
_080AEDA4: .4byte 0x085B0A08
_080AEDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEDAE:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDC6
	asrs r0, r0, #0xc
	b _080AEDCC
_080AEDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEDCC:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AEDF8 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #4
_080AEDEE:
	movs r3, #0x96
	bl FUN_080df148
	b _080AEE04
	.align 2, 0
_080AEDF8: .4byte 0x0000134E
_080AEDFC:
	ldr r5, _080AEE14 @ =0x00001348
	adds r1, r4, r5
_080AEE00:
	movs r0, #0
	strh r0, [r1]
_080AEE04:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEE14: .4byte 0x00001348
