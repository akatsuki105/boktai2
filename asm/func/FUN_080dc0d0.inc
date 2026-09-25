	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov sb, r2
	mov r8, r3
	cmp r0, #0
	beq _080DC0F2
	ldr r0, _080DC0F8 @ =0x03000168
	ldr r0, [r0]
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _080DC0FC
_080DC0F2:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DC340
	.align 2, 0
_080DC0F8: .4byte 0x03000168
_080DC0FC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x38]
	cmp r0, r1
	blt _080DC108
	b _080DC33E
_080DC108:
	ldr r2, _080DC144 @ =0x030046B8
	mov sl, r2
_080DC10C:
	ldr r0, [sp, #0xc]
	bl FUN_080dc050
	adds r7, r0, #0
	cmp r7, #0
	beq _080DC0F2
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r0, [r7]
	ldr r1, [sp, #8]
	cmp r1, #0
	bne _080DC148
	strh r1, [r7, #4]
	mov r3, sp
	ldrh r3, [r3, #8]
	strh r3, [r7, #6]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r7, #8]
	b _080DC152
	.align 2, 0
_080DC144: .4byte 0x030046B8
_080DC148:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #4]
	str r1, [r7, #8]
_080DC152:
	mov r3, r8
	cmp r3, #0
	beq _080DC1F8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DC18C
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _080DC208 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080DC20C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
_080DC18C:
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DC1C2
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC208 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC20C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	bl Mod
	mov r3, r8
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	ldrh r1, [r7, #6]
	adds r0, r0, r1
	strh r0, [r7, #6]
_080DC1C2:
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _080DC1F8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC208 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC20C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
_080DC1F8:
	mov r0, sb
	cmp r0, #0
	bne _080DC210
	strh r0, [r7, #0xc]
	mov r1, sb
	strh r1, [r7, #0xe]
	strh r1, [r7, #0x10]
	b _080DC2E6
	.align 2, 0
_080DC208: .4byte 0x000003FF
_080DC20C: .4byte 0x0203B400
_080DC210:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DC224
	ldr r0, _080DC220 @ =0xFFFF0000
	ands r5, r0
	b _080DC24E
	.align 2, 0
_080DC220: .4byte 0xFFFF0000
_080DC224:
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC260 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC264 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC268 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC24E:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DC270
	ldr r0, _080DC26C @ =0x0000FFFF
	ands r5, r0
	b _080DC298
	.align 2, 0
_080DC260: .4byte 0x000003FF
_080DC264: .4byte 0x0203B400
_080DC268: .4byte 0xFFFF0000
_080DC26C: .4byte 0x0000FFFF
_080DC270:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC2A8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC2AC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DC2B0 @ =0x0000FFFF
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC298:
	mov r3, sb
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DC2B8
	ldr r2, _080DC2B4 @ =0xFFFF0000
	ands r6, r2
	b _080DC2E2
	.align 2, 0
_080DC2A8: .4byte 0x000003FF
_080DC2AC: .4byte 0x0203B400
_080DC2B0: .4byte 0x0000FFFF
_080DC2B4: .4byte 0xFFFF0000
_080DC2B8:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC350 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC354 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC358 @ =0xFFFF0000
	ands r1, r6
	adds r6, r1, #0
	orrs r6, r0
_080DC2E2:
	str r5, [r7, #0xc]
	str r6, [r7, #0x10]
_080DC2E6:
	movs r4, #0
	strh r4, [r7, #0x1a]
	ldr r3, [sp, #0xc]
	ldr r1, [r3, #0x1c]
	ldr r0, [sp, #0x10]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0x10]
	adds r1, r2, #0
	bl Particle_SetOffset
	movs r0, #0x17
	ldrsb r0, [r7, r0]
	lsls r0, r0, #4
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldr r1, [r2, #0x18]
	str r4, [sp]
	movs r2, #0xc
	movs r3, #0
	bl FUN_08236fac
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r3, #0xf]
	strb r1, [r7, #0x16]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x38]
	cmp r1, r2
	bge _080DC33E
	b _080DC10C
_080DC33E:
	movs r0, #0
_080DC340:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC350: .4byte 0x000003FF
_080DC354: .4byte 0x0203B400
_080DC358: .4byte 0xFFFF0000
