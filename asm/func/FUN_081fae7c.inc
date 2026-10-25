	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x5c
	adds r5, r0, #0
	add r1, sp, #0x38
	ldr r0, _081FAEF8 @ =0x082526A4
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, #0x48
	add r1, sp, #0x4c
	mov r8, r1
	movs r1, #0
	str r1, [sp, #0x48]
	mov r1, r8
	ldr r2, _081FAEFC @ =0x05000002
	bl CpuSet
	ldr r0, _081FAF00 @ =0x03002CF0
	ldr r7, [r0]
	movs r0, #1
	ands r7, r0
	ldr r4, _081FAF04 @ =0x0203B400
	ldr r3, _081FAF08 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081FAF0C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrb r4, [r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r1, #4
	ldrsh r3, [r5, r1]
	add r1, sp, #0x54
	strh r0, [r1]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	ldr r2, _081FAF10 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov r5, r8
	adds r3, r1, #0
	cmp r0, #0
	blt _081FAF14
	asrs r1, r0, #0xc
	b _081FAF1A
	.align 2, 0
_081FAEF8: .4byte 0x082526A4
_081FAEFC: .4byte 0x05000002
_081FAF00: .4byte 0x03002CF0
_081FAF04: .4byte 0x0203B400
_081FAF08: .4byte 0x030046B8
_081FAF0C: .4byte 0x000003FF
_081FAF10: .4byte gSineTable
_081FAF14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAF1A:
	ldrh r0, [r3]
	adds r0, r0, r1
	add r1, sp, #0x54
	strh r0, [r1]
	ldr r2, _081FAF40 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081FAF44
	asrs r1, r0, #0xc
	b _081FAF4A
	.align 2, 0
_081FAF40: .4byte gSineTable
_081FAF44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAF4A:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _081FAF80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FAF84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FAF88 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #0x38
	adds r2, r3, #0
	adds r1, r5, #0
	ldr r0, [r0]
	str r0, [sp]
	cmp r7, #0
	bne _081FAF8C
	movs r0, #0x80
	lsls r0, r0, #2
	b _081FAF90
	.align 2, 0
_081FAF80: .4byte 0x030046B8
_081FAF84: .4byte 0x000003FF
_081FAF88: .4byte 0x0203B400
_081FAF8C:
	movs r0, #0x80
	lsls r0, r0, #3
_081FAF90:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAFC8 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r2, #0
	ldr r2, _081FAFCC @ =0x00002E78
	ldr r3, _081FAFD0 @ =0x000038E2
	bl FUN_081f22c0
	add sp, #0x5c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FAFC8: .4byte 0x00000232
_081FAFCC: .4byte 0x00002E78
_081FAFD0: .4byte 0x000038E2
