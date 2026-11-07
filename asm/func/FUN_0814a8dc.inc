	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	mov ip, r0
	ldr r0, [r0, #0x44]
	adds r0, #0x48
	mov sb, r0
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq _0814A8F8
	b _0814AAC0
_0814A8F8:
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	mov sl, r0
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, #0xfc
	add r1, ip
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #2
	beq _0814A92A
	b _0814AA86
_0814A92A:
	mov r1, sb
	ldrh r0, [r1, #8]
	cmp r0, #7
	beq _0814A93C
	cmp r0, #5
	beq _0814A93C
	cmp r0, #1
	beq _0814A93C
	b _0814AA86
_0814A93C:
	ldr r2, _0814A9D0 @ =0x0203B400
	mov r8, r2
	ldr r6, _0814A9D4 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r3, _0814A9D8 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, r8
	ldrh r1, [r0]
	movs r4, #0x3f
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0814A9DC @ =0xFFFF0000
	ldr r0, [sp, #0x3c]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x3c]
	adds r2, #1
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x3c
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, ip
	adds r1, #8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #8]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #5]
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #0xff
	add r6, sp, #0x44
	ands r4, r1
	movs r5, #0x50
	ldr r3, _0814A9E0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r7, r2, #0
	mov r8, r6
	cmp r0, #0
	blt _0814A9E4
	asrs r1, r0, #0xc
	b _0814A9EA
	.align 2, 0
_0814A9D0: .4byte 0x0203B400
_0814A9D4: .4byte 0x030046B8
_0814A9D8: .4byte 0x000003FF
_0814A9DC: .4byte 0xFFFF0000
_0814A9E0: .4byte gSineTable
_0814A9E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814A9EA:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r4, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0814AA02
	asrs r0, r0, #0xc
	b _0814AA08
_0814AA02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814AA08:
	movs r5, #0
	strh r0, [r6, #4]
	add r2, sp, #0x44
	add r1, sp, #0x3c
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r7, #4]
	mov r3, r8
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	mov r4, ip
	ldrh r0, [r4, #0xa]
	strh r0, [r7, #2]
	add r6, sp, #0x4c
	str r5, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _0814AAA0 @ =0x05000002
	bl CpuSet
	ldr r2, _0814AAA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814AAA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0814AAAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _0814AAB0 @ =0x00001C1A
	ldr r3, _0814AAB4 @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r4, #1
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	ldr r0, _0814AAB8 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r7, #0
	adds r1, r6, #0
	bl Entity081f26bc_Spawn
_0814AA86:
	ldr r2, _0814AABC @ =0x085AD8C0
	mov r3, sb
	ldrh r1, [r3, #8]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	mov r4, sl
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _0814AAC2
	.align 2, 0
_0814AAA0: .4byte 0x05000002
_0814AAA4: .4byte 0x030046B8
_0814AAA8: .4byte 0x000003FF
_0814AAAC: .4byte 0x0203B400
_0814AAB0: .4byte 0x00001C1A
_0814AAB4: .4byte 0x0000D1B8
_0814AAB8: .4byte 0x00200004
_0814AABC: .4byte 0x085AD8C0
_0814AAC0:
	movs r0, #0
_0814AAC2:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
