	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	mov sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016894
	b _08016A3E
_08016894:
	adds r2, r7, #5
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #6
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #8
_080168A6:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080168B0
	b _08016A1C
_080168B0:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r2, [sp, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168CA
	asrs r1, r0, #0xc
	b _080168D0
_080168CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168D0:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	movs r2, #4
	ldrsh r1, [r4, r2]
	ldr r3, [sp, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168F2
	asrs r1, r0, #0xc
	b _080168F8
_080168F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168F8:
	ldrh r0, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #2]
	subs r0, #2
	strh r0, [r4, #2]
	mov r0, r8
	movs r1, #0x10
	bl AuxAnim_SetAnimSpeed
	ldr r0, _08016950 @ =0x03000064
	ldr r0, [r0]
	ldr r3, [r0, #0x1c]
	mov r5, r8
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #1
	ldr r1, [r4, #0x30]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x13]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08016954
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _0801695C
	.align 2, 0
_08016950: .4byte 0x03000064
_08016954:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801695C:
	str r0, [r4, #8]
	ldrb r0, [r5, #4]
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
	beq _08016980
	ldr r0, [r4, #8]
	movs r1, #8
	orrs r0, r1
	b _08016988
_08016980:
	ldr r0, [r4, #8]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016988:
	str r0, [r4, #8]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0xe]
	ldr r3, _080169C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _080169EA
	strh r1, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080169C4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080169B8
	ldrb r0, [r5, #5]
_080169B8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080169D4
	.align 2, 0
_080169C0: .4byte 0x0000FFFF
_080169C4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080169D4
	strh r1, [r5, #8]
_080169D4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_080169EA:
	mov r3, sb
	ldrb r0, [r3]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #8
	bls _080169FE
	ldrh r0, [r4, #0x38]
	cmp r0, #5
	bne _08016A06
	b _08016A02
_080169FE:
	cmp r1, #8
	bne _08016A06
_08016A02:
	movs r0, #0
	strh r0, [r4, #0x38]
_08016A06:
	subs r0, r2, #1
	mov r1, sb
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08016A24
	ldr r0, [r4, #8]
	movs r2, #1
	orrs r0, r2
	b _08016A22
_08016A1C:
	ldr r0, [r4, #8]
	movs r3, #1
	orrs r0, r3
_08016A22:
	str r0, [r4, #8]
_08016A24:
	movs r0, #0x44
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	adds r1, #0x44
	str r1, [sp, #4]
	adds r4, #0x44
	movs r2, #1
	add sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A3E
	b _080168A6
_08016A3E:
	ldr r0, [sp]
	cmp r0, #0
	bne _08016A6A
	strb r0, [r7]
	movs r2, #0
	mov sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A66
	adds r4, r7, #0
	adds r4, #0x10
_08016A54:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016A54
_08016A66:
	movs r0, #0
	strb r0, [r7, #1]
_08016A6A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
