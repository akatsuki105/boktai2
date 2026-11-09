	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0818F640 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r3, [sp, #0xc]
	cmp r3, r0
	blt _0818F61A
	b _0818F7A0
_0818F61A:
	movs r4, #0
	mov sl, r4
	movs r7, #0xe8
	lsls r7, r7, #3
	add r7, sb
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, sb
	mov r8, r0
	lsls r2, r2, #0x18
	str r2, [sp, #0x10]
_0818F630:
	ldrh r0, [r7, #0x3a]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F644
	movs r0, #1
	b _0818F646
	.align 2, 0
_0818F640: .4byte 0x00000F36
_0818F644:
	movs r0, #0
_0818F646:
	cmp r0, #0
	beq _0818F64C
	b _0818F780
_0818F64C:
	ldrh r0, [r7, #0x3a]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _0818F65A
	movs r0, #1
	b _0818F65C
_0818F65A:
	movs r0, #0
_0818F65C:
	cmp r0, #0
	beq _0818F680
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r3, [sp, #8]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0xb
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl AuxAnim_RestartAnim
	b _0818F6AA
_0818F680:
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, sb
	add r0, sl
	ldr r1, [r0]
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	add r0, sb
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r2, [r0]
	ldr r4, [sp, #8]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	ldr r4, [sp, #0x10]
	lsrs r3, r4, #0x18
	bl AuxAnim_RestartAnim
_0818F6AA:
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
	beq _0818F6DC
	ldr r0, [r6]
	movs r2, #4
	orrs r0, r2
	str r0, [r6]
	b _0818F6E8
_0818F6DC:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_0818F6E8:
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
	beq _0818F70A
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0818F712
_0818F70A:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0818F712:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0818F748 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0818F780
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0818F74C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0818F742
	ldrb r0, [r4, #5]
_0818F742:
	subs r0, #1
	strh r0, [r4, #8]
	b _0818F75C
	.align 2, 0
_0818F748: .4byte 0x0000FFFF
_0818F74C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0818F75C
	strh r1, [r4, #8]
_0818F75C:
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
	bne _0818F780
	movs r3, #1
	strb r3, [r4, #7]
_0818F780:
	movs r4, #0x92
	lsls r4, r4, #1
	add sl, r4
	adds r7, r7, r4
	add r8, r4
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	ldr r0, _0818F7B0 @ =0x00000F36
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0xc]
	cmp r2, r0
	bge _0818F7A0
	b _0818F630
_0818F7A0:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F7B0: .4byte 0x00000F36
