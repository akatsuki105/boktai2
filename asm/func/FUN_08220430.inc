	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r4, r0, #0
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r7, r4, r0
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r5, r4, r1
	ldr r1, [r5]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _08220466
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08220466:
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r6, [r0]
	cmp r6, #1
	bne _08220474
	b _08220626
_08220474:
	cmp r6, #1
	bgt _0822047E
	cmp r6, #0
	beq _08220486
	b _08220698
_0822047E:
	cmp r6, #0x63
	bne _08220484
	b _0822067C
_08220484:
	b _08220698
_08220486:
	movs r0, #2
	ldr r1, [r5]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r5]
	cmp r0, #0
	beq _082204CE
	ldr r2, _0822050C @ =0x00000BCC
	adds r0, r4, r2
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r2, #4
	adds r0, r4, r2
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #0xaf
	lsls r0, r0, #4
	ldr r1, _08220510 @ =0x0000076C
	subs r0, r0, r3
	subs r1, r1, r2
	bl FUN_0823785c
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #1
	bl FUN_0821c400
_082204CE:
	ldrh r0, [r7, #0x14]
	cmp r0, #4
	bne _082204DC
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_082204DC:
	ldr r2, _08220514 @ =0x000003BA
	adds r5, r4, r2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0x12
	bne _082204EE
	ldr r0, _08220518 @ =0x0000035E
	bl PlaySound_082406e0
_082204EE:
	ldrh r0, [r5]
	subs r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08220522
	adds r0, r4, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0822051C
	ldrh r0, [r7, #0x20]
	subs r0, #0xa
	strh r0, [r7, #0x20]
	b _08220522
	.align 2, 0
_0822050C: .4byte 0x00000BCC
_08220510: .4byte 0x0000076C
_08220514: .4byte 0x000003BA
_08220518: .4byte 0x0000035E
_0822051C:
	ldrh r0, [r7, #0x24]
	subs r0, #0xa
	strh r0, [r7, #0x24]
_08220522:
	movs r2, #0xe9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0x1e
	bne _082205FE
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08220546
	movs r2, #2
	mov r8, r2
	mov sl, r2
	movs r0, #1
	mov sb, r0
	b _08220550
_08220546:
	movs r1, #3
	mov r8, r1
	movs r2, #1
	mov sl, r2
	mov sb, r1
_08220550:
	ldr r1, _082205D8 @ =0x00000BF6
	adds r0, r4, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	movs r6, #0
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r2, r4, r2
	str r2, [sp, #0x24]
	ldr r0, _082205DC @ =0x000003DB
	adds r0, r4, r0
	str r0, [sp, #0x20]
	cmp r6, r8
	bge _082205BE
	add r7, sp, #0x18
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r5, r0, #0x18
_08220578:
	lsrs r2, r5, #0x18
	add r0, sp, #0x18
	movs r1, #9
	bl FUN_08234f90
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r7, #2]
	ldr r1, _082205E0 @ =0x00000BFC
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _082205E4 @ =0x000003D6
	adds r1, r4, r2
	movs r2, #0
	ldrsh r3, [r1, r2]
	movs r1, #0x3c
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x1e
	str r1, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	mov r2, sb
	str r2, [sp, #0x10]
	str r7, [sp, #0x14]
	movs r1, #0xa
	movs r2, #0x10
	bl FUN_0805eee4
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r6, #1
	cmp r6, r8
	blt _08220578
_082205BE:
	movs r0, #0x20
	ldr r2, [sp, #0x24]
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _082205EC
	ldr r0, _082205E8 @ =0x00000809
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _082205F6
	.align 2, 0
_082205D8: .4byte 0x00000BF6
_082205DC: .4byte 0x000003DB
_082205E0: .4byte 0x00000BFC
_082205E4: .4byte 0x000003D6
_082205E8: .4byte 0x00000809
_082205EC:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	ldr r2, [sp, #0x24]
	str r1, [r2]
_082205F6:
	movs r0, #0
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	b _08220698
_082205FE:
	cmp r0, #0x50
	ble _08220698
	movs r1, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08220698
_08220626:
	movs r7, #2
	ldr r0, [r5]
	adds r2, r0, #0
	ands r2, r7
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	cmp r2, #0
	beq _0822064C
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	movs r3, #0
	bl FUN_0821c400
_0822064C:
	ldr r1, _08220678 @ =0x000002D9
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08220698
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r7
	str r0, [r5]
	b _08220698
	.align 2, 0
_08220678: .4byte 0x000002D9
_0822067C:
	ldr r2, [r5]
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _08220698
	movs r0, #0x10
	orrs r2, r0
	str r2, [r5]
_08220698:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
