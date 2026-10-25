	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x4c
	adds r7, r0, #0
	mov r8, r1
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FAC10 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0x44
	ldrb r5, [r0]
	movs r0, #0x5a
	rsbs r0, r0, #0
	mov ip, r0
	ldr r2, _081FAC14 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sb, r4
	adds r6, r3, #0
	cmp r0, #0
	blt _081FAC18
	asrs r1, r0, #0xc
	b _081FAC1E
	.align 2, 0
_081FAC10: .4byte 0x05000002
_081FAC14: .4byte gSineTable
_081FAC18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAC1E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081FAC40 @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r1, #0
	cmp r0, #0
	blt _081FAC44
	asrs r0, r0, #0xc
	b _081FAC4A
	.align 2, 0
_081FAC40: .4byte gSineTable
_081FAC44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAC4A:
	strh r0, [r3, #4]
	adds r2, r7, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _081FAC94 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FAC98 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FAC9C @ =0x0203B400
	adds r0, r0, r2
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FACA0
	asrs r1, r0, #0xc
	b _081FACA6
	.align 2, 0
_081FAC94: .4byte 0x030046B8
_081FAC98: .4byte 0x000003FF
_081FAC9C: .4byte 0x0203B400
_081FACA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FACA6:
	ldrh r0, [r6]
	adds r0, r0, r1
	add r1, sp, #0x44
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081FACCC
	asrs r1, r0, #0xc
	b _081FACD2
_081FACCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FACD2:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #4]
	ldr r0, _081FAD1C @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081FAD2C
	ldr r2, _081FAD20 @ =0x00002E78
	ldr r3, _081FAD24 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAD28 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	mov r1, sb
	bl FUN_081f22c0
	b _081FAD60
	.align 2, 0
_081FAD1C: .4byte 0x03002CF0
_081FAD20: .4byte 0x00002E78
_081FAD24: .4byte 0x000038E2
_081FAD28: .4byte 0x00000232
_081FAD2C:
	ldr r2, _081FAD70 @ =0x00002E78
	ldr r3, _081FAD74 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAD78 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	mov r1, sb
	bl FUN_081f22c0
_081FAD60:
	add sp, #0x4c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FAD70: .4byte 0x00002E78
_081FAD74: .4byte 0x000038E2
_081FAD78: .4byte 0x00000232
