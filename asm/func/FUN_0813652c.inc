	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, _08136570 @ =0x00000B3A
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x10]
	cmp r2, r0
	blt _08136550
	b _0813670A
_08136550:
	movs r3, #0
	mov sl, r3
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
_08136562:
	ldrb r0, [r7, #0x15]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08136574
	movs r0, #1
	b _08136576
	.align 2, 0
_08136570: .4byte 0x00000B3A
_08136574:
	movs r0, #0
_08136576:
	cmp r0, #0
	beq _0813657C
	b _081366EC
_0813657C:
	movs r1, #4
	ldrb r0, [r7, #0x15]
	ands r0, r1
	cmp r0, #0
	beq _0813658A
	movs r0, #1
	b _0813658C
_0813658A:
	movs r0, #0
_0813658C:
	cmp r0, #0
	beq _081365C2
	ldrb r0, [r7, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	b _08136610
_081365C2:
	ldrb r0, [r7, #0x14]
	add r1, sp, #4
	add r2, sp, #8
	bl Centipede_GetAnimVariant
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #0xc]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	bl AuxAnim_SetAnim
	ldr r0, _08136644 @ =0x00000482
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl AuxAnim_SetAnimSpeed
_08136610:
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
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _08136648
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	str r0, [r6]
	b _08136654
	.align 2, 0
_08136644: .4byte 0x00000482
_08136648:
	mov r2, r8
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_08136654:
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
	beq _08136676
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0813667E
_08136676:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813667E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _081366B4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081366EC
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081366B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081366AE
	ldrb r0, [r4, #5]
_081366AE:
	subs r0, #1
	strh r0, [r4, #8]
	b _081366C8
	.align 2, 0
_081366B4: .4byte 0x0000FFFF
_081366B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081366C8
	strh r1, [r4, #8]
_081366C8:
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
	bne _081366EC
	movs r3, #1
	strb r3, [r4, #7]
_081366EC:
	movs r0, #0x90
	lsls r0, r0, #1
	add sl, r0
	adds r7, r7, r0
	add r8, r0
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r0, _0813671C @ =0x00000B3A
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0813670A
	b _08136562
_0813670A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813671C: .4byte 0x00000B3A
