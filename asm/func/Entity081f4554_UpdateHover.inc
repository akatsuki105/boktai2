	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r2, r0, #0
	adds r6, r1, #0
	mov r8, r6
	adds r5, r6, #0
	adds r5, #0x48
	movs r0, #0xab
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081F3EA6
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r7]
	movs r2, #0xad
	lsls r2, r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_081F3EA6:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x48]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F3ED2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F3EDA
_081F3ED2:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F3EDA:
	str r0, [r6]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F3F00
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F3F0A
_081F3F00:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F3F0A:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F3F44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F3F8A
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3F4E
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F3F48
	ldrb r0, [r5, #5]
	subs r0, #1
	strh r0, [r5, #8]
	movs r2, #1
	b _081F3F64
	.align 2, 0
_081F3F44: .4byte 0x0000FFFF
_081F3F48:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F3F62
_081F3F4E:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F3F62
	strh r1, [r5, #8]
	movs r2, #1
	b _081F3F64
_081F3F62:
	movs r2, #0
_081F3F64:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F3F8C
	movs r0, #1
	strb r0, [r5, #7]
	b _081F3F8C
_081F3F8A:
	movs r2, #0
_081F3F8C:
	adds r3, r2, #0
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _081F3FDA
	ldr r2, _081F3FB8 @ =gSineTable
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081F3FBC
	asrs r1, r0, #0xc
	b _081F3FC2
	.align 2, 0
_081F3FB8: .4byte gSineTable
_081F3FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F3FC2:
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x1e]
	adds r2, #0x10
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_081F3FDA:
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081F3FEC
	adds r0, #1
	strh r0, [r1]
	b _081F4004
_081F3FEC:
	cmp r3, #0
	beq _081F4004
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	movs r0, #0xab
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081F4004:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
