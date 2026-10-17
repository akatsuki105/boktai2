	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r2, r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #4
	bls _08085F16
	adds r1, r0, #0
	movs r0, #8
	subs r3, r0, r1
	movs r6, #1
	b _08085F1A
_08085F16:
	ldrb r3, [r3]
	movs r6, #0
_08085F1A:
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, #0x10
	adds r0, r5, r1
	ldr r1, [r0]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
	adds r5, #0x84
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08085F64
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08085F6C
_08085F64:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08085F6C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08085F90
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08085F98
_08085F90:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08085F98:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08085FD0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08086016
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08085FDA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08085FD4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08085FF0
	.align 2, 0
_08085FD0: .4byte 0x0000FFFF
_08085FD4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08085FEE
_08085FDA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08085FEE
	strh r1, [r4, #8]
	movs r2, #1
	b _08085FF0
_08085FEE:
	movs r2, #0
_08085FF0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08086018
	movs r0, #1
	strb r0, [r4, #7]
	b _08086018
_08086016:
	movs r2, #0
_08086018:
	adds r0, r2, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
