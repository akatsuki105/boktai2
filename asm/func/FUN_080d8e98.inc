	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _080D8EF4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D8EB0
	b _080D928C
_080D8EB0:
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x88
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #0x10]
	mov sb, r1
	adds r2, r7, #0
	adds r2, #0x38
	str r2, [sp, #0x14]
	movs r3, #0
	str r3, [sp, #0x1c]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	adds r5, r7, #4
	mov sl, r5
	adds r6, r0, #0
_080D8ED6:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	bne _080D8EF8
	ldr r0, [r6]
	orrs r0, r3
	str r0, [r6]
	ldr r4, [sp, #0x10]
	adds r4, #1
	str r4, [sp, #0x10]
	b _080D9208
	.align 2, 0
_080D8EF4: .4byte 0x0300015C
_080D8EF8:
	adds r0, r7, #0
	adds r0, #0x32
	add r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D8F0A
	b _080D9070
_080D8F0A:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r5, [sp, #0x1c]
	adds r1, r0, r5
	ldr r1, [r1]
	str r0, [sp, #0x18]
	cmp r1, #0xe
	ble _080D8F2A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	b _080D9208
_080D8F2A:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D8F3E
	cmp r0, #3
	beq _080D8F46
	movs r3, #0
	mov ip, r3
	b _080D8F4C
_080D8F3E:
	ldr r4, [sp]
	ldr r4, [r4, #0x58]
	mov ip, r4
	b _080D8F4C
_080D8F46:
	ldr r5, [sp]
	ldr r5, [r5, #0x58]
	mov ip, r5
_080D8F4C:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D8F8E
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D8F96
_080D8F8E:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D8F96:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D8FBA
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D8FC2
_080D8FBA:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D8FC2:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D8FF8 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D9022
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D8FFC
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D8FF2
	ldrb r0, [r3, #5]
_080D8FF2:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D900C
	.align 2, 0
_080D8FF8: .4byte 0x0000FFFF
_080D8FFC:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D900C
	strh r1, [r3, #8]
_080D900C:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D9022:
	ldrh r1, [r7, #0x1c]
	mov r3, sl
	ldrh r3, [r3]
	adds r1, r1, r3
	ldrh r0, [r6, #0x18]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r1, [r7, #0x1e]
	mov r4, sl
	ldrh r4, [r4, #2]
	adds r1, r1, r4
	ldrh r0, [r6, #0x1a]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
	ldrh r1, [r7, #0x20]
	mov r5, sl
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	ldrh r0, [r6, #0x1c]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r2, r0, r1
	ldr r1, [r2]
	asrs r1, r1, #1
	mov r3, sl
	ldrh r0, [r3, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _080D9208
_080D9070:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r4, [sp, #0x1c]
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _080D9084
	subs r0, #1
	str r0, [r1]
	b _080D9208
_080D9084:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D9098
	cmp r0, #3
	beq _080D90A0
	movs r5, #0
	mov ip, r5
	b _080D90A6
_080D9098:
	ldr r0, [sp]
	ldr r0, [r0, #0x58]
	mov ip, r0
	b _080D90A6
_080D90A0:
	ldr r1, [sp]
	ldr r1, [r1, #0x58]
	mov ip, r1
_080D90A6:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r2, ip
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D90E8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D90F0
_080D90E8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D90F0:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D9114
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D911C
_080D9114:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D911C:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D9154 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D917E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9158
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D914C
	ldrb r0, [r3, #5]
_080D914C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D9168
	.align 2, 0
_080D9154: .4byte 0x0000FFFF
_080D9158:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D9168
	strh r1, [r3, #8]
_080D9168:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D917E:
	ldr r5, _080D929C @ =0x085B0A08
	adds r4, r7, #0
	adds r4, #0x35
	add r4, sb
	ldrb r3, [r4]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	lsrs r0, r0, #0x10
	ldr r2, _080D92A0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080D92A4 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r3, #5
	strb r3, [r4]
	ldr r0, [r7]
	mov r2, sp
	ldrh r3, [r2, #8]
	ldrh r0, [r0]
	adds r2, r3, r0
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x18]
	ldr r0, [r7]
	asrs r1, r1, #0x10
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r7, #0x28]
	adds r0, r0, r1
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r6, #0x1a]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	subs r0, r0, r3
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080d8de0
_080D9208:
	ldr r0, [sp, #0x1c]
	adds r0, #4
	str r0, [sp, #0x1c]
	movs r1, #0x10
	add r8, r1
	movs r2, #8
	add sl, r2
	adds r6, #0x28
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #2
	bgt _080D9224
	b _080D8ED6
_080D9224:
	ldr r5, [sp, #0x10]
	cmp r5, #2
	ble _080D928C
	adds r0, r7, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x39
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, [sp]
	ldr r5, _080D92A8 @ =0x000009FC
	adds r3, r1, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	strh r2, [r7, #0x24]
	str r2, [r7, #0x48]
	mov sb, r2
	adds r5, r4, #0
	ldr r4, [sp, #4]
_080D9254:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9270
	adds r0, r7, #0
	bl FUN_080d8644
	adds r0, r4, #0
	bl Particle_Remove
_080D9270:
	adds r4, #0x28
	movs r3, #1
	add sb, r3
	mov r0, sb
	cmp r0, #2
	ble _080D9254
	movs r4, #0
	adds r0, r7, #0
	bl FUN_080d866c
	ldr r1, [sp, #0x14]
	strb r4, [r1]
	movs r0, #0xff
	strb r0, [r5]
_080D928C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D929C: .4byte 0x085B0A08
_080D92A0: .4byte 0xFFFF0000
_080D92A4: .4byte 0x0000FFFF
_080D92A8: .4byte 0x000009FC
