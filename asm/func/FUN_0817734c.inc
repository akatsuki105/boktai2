	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldr r0, _08177390 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #8]
	cmp r2, r0
	blt _08177370
	b _08177532
_08177370:
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r3, #0xcb
	lsls r3, r3, #3
	add r3, sb
	mov r8, r3
	movs r0, #0
	mov sl, r0
_08177382:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08177394
	movs r0, #1
	b _08177396
	.align 2, 0
_08177390: .4byte 0x00001012
_08177394:
	movs r0, #0
_08177396:
	cmp r0, #0
	beq _0817739C
	b _08177514
_0817739C:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773AA
	movs r0, #1
	b _081773AC
_081773AA:
	movs r0, #0
_081773AC:
	cmp r0, #0
	beq _081773CA
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_RestartAnim
	b _08177434
_081773CA:
	movs r1, #0x20
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773D8
	movs r0, #1
	b _081773DA
_081773D8:
	movs r0, #0
_081773DA:
	cmp r0, #0
	beq _081773E2
	movs r3, #0
	b _081773FA
_081773E2:
	movs r1, #0x10
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _081773F0
	movs r0, #1
	b _081773F2
_081773F0:
	movs r0, #0
_081773F2:
	movs r3, #2
	cmp r0, #0
	beq _081773FA
	movs r3, #1
_081773FA:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	bl AuxAnim_RestartAnim
	ldr r0, _08177468 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl AuxAnim_SetAnimSpeed
_08177434:
	mov r6, r8
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0817746C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _0817747A
	.align 2, 0
_08177468: .4byte 0x00000482
_0817746C:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_0817747A:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0817749C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081774A4
_0817749C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081774A4:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081774DC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08177514
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081774E0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081774D4
	ldrb r0, [r4, #5]
_081774D4:
	subs r0, #1
	strh r0, [r4, #8]
	b _081774F0
	.align 2, 0
_081774DC: .4byte 0x0000FFFF
_081774E0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081774F0
	strh r1, [r4, #8]
_081774F0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08177514
	movs r3, #1
	strb r3, [r4, #7]
_08177514:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	add r8, r0
	add sl, r0
	ldr r1, [sp, #8]
	adds r1, #1
	str r1, [sp, #8]
	ldr r0, _08177544 @ =0x00001012
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08177532
	b _08177382
_08177532:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177544: .4byte 0x00001012
