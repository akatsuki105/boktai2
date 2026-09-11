	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009EA2
	movs r5, #0
	strb r5, [r6, #7]
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x24]
	str r5, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08009EA2:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #1
	bne _08009EC0
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EC0
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_08009EC0:
	ldrh r0, [r2]
	cmp r0, #2
	bne _08009EDA
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EDA
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
_08009EDA:
	ldrh r0, [r2]
	cmp r0, #4
	bne _08009F46
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009F46
	ldr r3, _08009F38 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0xa
	orrs r0, r2
	ldr r1, _08009F3C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrb r0, [r6, #4]
	ldrb r2, [r6, #3]
	movs r1, #0x10
	orrs r1, r2
	ldrh r2, [r6, #0xe]
	adds r3, r6, #0
	adds r3, #0x7c
	add r4, sp, #0xc
	str r4, [sp]
	ldrh r4, [r6, #0x10]
	str r4, [sp, #4]
	ldrh r4, [r6, #0x12]
	str r4, [sp, #8]
	bl FUN_0800a8e0
	ldrb r0, [r6, #3]
	cmp r0, #2
	bne _08009F40
	movs r0, #0xae
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08009F46
	.align 2, 0
_08009F38: .4byte 0xFFFF0000
_08009F3C: .4byte 0x0000FFFF
_08009F40:
	ldr r0, _08009F8C @ =0x0000011D
	bl PlaySound_0824078c
_08009F46:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x1c]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08009F90
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009F98
	.align 2, 0
_08009F8C: .4byte 0x0000011D
_08009F90:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009F98:
	str r0, [r6, #0x64]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08009FBC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009FC4
_08009FBC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009FC4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009FFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800A034
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800A006
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800A000
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0800A01C
	.align 2, 0
_08009FFC: .4byte 0x0000FFFF
_0800A000:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800A01A
_0800A006:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800A01A
	strh r1, [r4, #8]
	movs r2, #1
	b _0800A01C
_0800A01A:
	movs r2, #0
_0800A01C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _0800A036
_0800A034:
	movs r2, #0
_0800A036:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _0800A046
	movs r1, #1
	strb r1, [r6, #6]
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_0800A046:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
