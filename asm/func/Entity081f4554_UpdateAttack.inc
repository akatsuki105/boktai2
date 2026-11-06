	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r2, r0, #0
	adds r7, r1, #0
	mov sb, r7
	adds r6, r7, #0
	adds r6, #0x48
	movs r0, #0xab
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081F404C
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r5]
_081F404C:
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r3, r3, r7
	mov ip, r3
	ldrh r0, [r3]
	cmp r0, #9
	bhi _081F40A6
	ldr r4, _081F4134 @ =0x0203B400
	mov r8, r4
	ldr r3, _081F4138 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _081F413C @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r5]
	subs r0, #0x30
	movs r5, #0x3f
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, #0x30
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r7, #0x20]
_081F40A6:
	mov r3, ip
	ldrh r0, [r3]
	cmp r0, #4
	bne _081F4108
	ldr r0, [r7, #0xc]
	movs r1, #0xfe
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	ldr r4, _081F4140 @ =0xFFFFFEAC
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _081F4144 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _081F4148 @ =0x0000015D
	adds r0, r7, r2
	ldrb r2, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r4, #0x14
	adds r0, r7, r4
	ldrh r0, [r0]
	str r0, [sp, #8]
	add r0, sp, #0xc
	bl Entity081f0b90_Spawn
	adds r0, r7, #0
	bl Entity081f4554_ExecScript
_081F4108:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x48]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F414C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F4154
	.align 2, 0
_081F4134: .4byte 0x0203B400
_081F4138: .4byte 0x030046B8
_081F413C: .4byte 0x000003FF
_081F4140: .4byte 0xFFFFFEAC
_081F4144: .4byte 0x0000FFFF
_081F4148: .4byte 0x0000015D
_081F414C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F4154:
	str r0, [r7]
	ldrb r0, [r6, #4]
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
	beq _081F417E
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	b _081F418A
_081F417E:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F418A:
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r4, _081F41C0 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081F4206
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F41CA
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081F41C4
	ldrb r0, [r6, #5]
	subs r0, #1
	strh r0, [r6, #8]
	movs r2, #1
	b _081F41E0
	.align 2, 0
_081F41C0: .4byte 0x0000FFFF
_081F41C4:
	subs r0, #1
	strh r0, [r6, #8]
	b _081F41DE
_081F41CA:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081F41DE
	strh r1, [r6, #8]
	movs r2, #1
	b _081F41E0
_081F41DE:
	movs r2, #0
_081F41E0:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F4208
	movs r0, #1
	strb r0, [r6, #7]
	b _081F4208
_081F4206:
	movs r2, #0
_081F4208:
	cmp r2, #0
	beq _081F4248
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	mov r1, sb
	ldr r0, [r1, #0xc]
	movs r1, #0xfb
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4]
	cmp r0, #0
	beq _081F4232
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #2
	b _081F423A
_081F4232:
	movs r3, #0xa9
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #5
_081F423A:
	strb r0, [r1]
	movs r4, #0xab
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	b _081F4254
_081F4248:
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F4254:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
