	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r4, r0, #0
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080E8630
	b _080E8A40
_080E8630:
	subs r0, #1
	strh r0, [r5]
	ldr r1, _080E869C @ =0x000001DD
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #9
	movs r2, #7
	ands r0, r2
	lsls r0, r0, #5
	mov sl, r0
	ldr r0, _080E86A0 @ =0x00000452
	adds r3, r4, r0
	ldrb r1, [r3]
	add sl, r1
	adds r0, #1
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	strb r1, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x40
	bls _080E866E
	movs r0, #0x40
	strb r0, [r3]
	movs r0, #0
	ldrsb r0, [r2, r0]
	rsbs r0, r0, #0
	strb r0, [r2]
_080E866E:
	ldrh r0, [r5]
	movs r1, #4
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	beq _080E867E
	b _080E8A40
_080E867E:
	add r7, sp, #0x1c
	adds r0, r7, #0
	movs r1, #8
	bl ClearMemory
	ldr r1, _080E86A4 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #0x3c]
	cmp r0, #2
	beq _080E86A8
	cmp r0, #0xe
	bne _080E869A
	b _080E891C
_080E869A:
	b _080E8A40
	.align 2, 0
_080E869C: .4byte 0x000001DD
_080E86A0: .4byte 0x00000452
_080E86A4: .4byte 0x000001DF
_080E86A8:
	strh r5, [r7, #2]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080E86B8
	b _080E87E8
_080E86B8:
	ldr r0, _080E87D8 @ =0x030046B8
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _080E87DC @ =0x000003FF
	ands r2, r5
	ldr r3, _080E87E0 @ =0x0000FFFF
	adds r2, #1
	ands r2, r5
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldr r4, [sp, #0x24]
	asrs r1, r4, #0x10
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ands r3, r4
	orrs r3, r0
	str r3, [sp, #0x24]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _080E87E4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, #1
	ands r2, r5
	ldr r1, _080E87D8 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r1, _080E87E4 @ =0x0203B400
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r2, #3
	ands r1, r2
	adds r1, #6
	add r7, sp, #0x24
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r1, #9
	adds r2, r7, #0
	mov r3, sl
	bl FUN_080149dc
	ldr r1, _080E87D8 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	ldr r2, _080E87E4 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	ands r3, r1
	add r3, sl
	movs r2, #0xff
	mov sb, r2
	ands r3, r2
	adds r0, #1
	ands r0, r5
	ldr r1, _080E87D8 @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _080E87E4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #6
	movs r2, #8
	str r2, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0xe
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r4, #6
	str r4, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl FUN_080149dc
	ldr r2, _080E87D8 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	ldr r2, _080E87E4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #0xf
	ands r3, r0
	add r3, sl
	mov r0, sb
	ands r3, r0
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r5
	ldr r2, _080E87D8 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080E87E4 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r1, #4
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	ldr r1, [sp, #0x3c]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #3
	str r2, [sp, #0x10]
	movs r1, #5
	str r1, [sp, #0x14]
	movs r2, #0xa
	str r2, [sp, #0x18]
	movs r1, #9
	b _080E8904
	.align 2, 0
_080E87D8: .4byte 0x030046B8
_080E87DC: .4byte 0x000003FF
_080E87E0: .4byte 0x0000FFFF
_080E87E4: .4byte 0x0203B400
_080E87E8:
	ldr r0, _080E890C @ =0x030046B8
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _080E8910 @ =0x000003FF
	ands r2, r5
	ldr r3, _080E8914 @ =0x0000FFFF
	adds r2, #1
	ands r2, r5
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	ldr r4, [sp, #0x2c]
	asrs r1, r4, #0x10
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ands r3, r4
	orrs r3, r0
	str r3, [sp, #0x2c]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _080E8918 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, #1
	ands r2, r5
	ldr r1, _080E890C @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r1, _080E8918 @ =0x0203B400
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r2, #3
	ands r1, r2
	adds r1, #6
	add r7, sp, #0x2c
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r2, r7, #0
	mov r3, sl
	bl FUN_080149dc
	ldr r1, _080E890C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	ldr r2, _080E8918 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	ands r3, r1
	add r3, sl
	movs r2, #0xff
	mov r8, r2
	ands r3, r2
	adds r0, #1
	ands r0, r5
	ldr r1, _080E890C @ =0x030046B8
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _080E8918 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #6
	movs r2, #8
	str r2, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0xe
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r4, #6
	str r4, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	movs r1, #0xa
	adds r2, r7, #0
	bl FUN_080149dc
	ldr r2, _080E890C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	ldr r2, _080E8918 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #0xf
	ands r3, r0
	add r3, sl
	mov r0, r8
	ands r3, r0
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r5
	ldr r2, _080E890C @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080E8918 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r1, #4
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	ldr r1, [sp, #0x3c]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #3
	str r2, [sp, #0x10]
	movs r1, #5
	str r1, [sp, #0x14]
	movs r2, #0xa
	str r2, [sp, #0x18]
	movs r1, #0xa
_080E8904:
	adds r2, r7, #0
	bl FUN_080149dc
	b _080E8A40
	.align 2, 0
_080E890C: .4byte 0x030046B8
_080E8910: .4byte 0x000003FF
_080E8914: .4byte 0x0000FFFF
_080E8918: .4byte 0x0203B400
_080E891C:
	movs r0, #0x28
	strh r0, [r7, #2]
	ldr r0, _080E8A50 @ =0x030046B8
	ldr r2, [r0]
	adds r2, #1
	ldr r5, _080E8A54 @ =0x000003FF
	ands r2, r5
	ldr r3, _080E8A58 @ =0x0000FFFF
	adds r2, #1
	ands r2, r5
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	ldr r4, [sp, #0x34]
	asrs r1, r4, #0x10
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ands r3, r4
	orrs r3, r0
	str r3, [sp, #0x34]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _080E8A5C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r2, #1
	ands r2, r5
	ldr r1, _080E8A50 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r1, _080E8A5C @ =0x0203B400
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r2, #3
	ands r1, r2
	adds r1, #6
	add r7, sp, #0x34
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r1, #0xb
	adds r2, r7, #0
	mov r3, sl
	bl FUN_080149dc
	ldr r1, _080E8A50 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	ldr r2, _080E8A5C @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	ands r3, r1
	add r3, sl
	movs r6, #0xff
	ands r3, r6
	adds r0, #1
	ands r0, r5
	ldr r2, _080E8A50 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080E8A5C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #6
	movs r1, #8
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	ldr r2, [sp, #0x3c]
	str r2, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r4, #6
	str r4, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	movs r1, #0xb
	adds r2, r7, #0
	bl FUN_080149dc
	ldr r2, _080E8A50 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	ldr r2, _080E8A5C @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #0xf
	ands r3, r0
	add r3, sl
	ands r3, r6
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r5
	ldr r2, _080E8A50 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080E8A5C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r1, #4
	movs r2, #8
	str r2, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #3
	str r1, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	movs r1, #0xa
	str r1, [sp, #0x18]
	movs r1, #0xb
	adds r2, r7, #0
	bl FUN_080149dc
_080E8A40:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E8A50: .4byte 0x030046B8
_080E8A54: .4byte 0x000003FF
_080E8A58: .4byte 0x0000FFFF
_080E8A5C: .4byte 0x0203B400
