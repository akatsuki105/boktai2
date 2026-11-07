	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	bl FUN_08164780
	str r0, [sp, #0x34]
	ldr r0, _08164E4C @ =0x0203B400
	mov ip, r0
	ldr r6, _08164E50 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r4, _08164E54 @ =0x000003FF
	ands r1, r4
	str r1, [r6]
	lsls r0, r1, #1
	add r0, ip
	ldrh r5, [r0]
	movs r0, #0xf
	ands r5, r0
	add r2, sp, #0x2c
	mov sl, r2
	movs r3, #8
	add r3, sb
	mov r8, r3
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	mov r7, sb
	ldrh r2, [r7, #8]
	subs r0, r0, r2
	add r2, sp, #0x2c
	strh r0, [r2]
	ldrh r0, [r3, #2]
	mov r7, r8
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	mov r2, sl
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r7, #4]
	subs r0, r0, r2
	mov r3, sl
	strh r0, [r3, #4]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	movs r2, #0xff
	ldrb r7, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r6]
	lsls r1, r1, #1
	add r1, ip
	ldrh r1, [r1]
	movs r0, #7
	ands r1, r0
	add r6, sp, #0x2c
	adds r3, r7, r5
	adds r4, r1, #0
	adds r4, #0xc
	ldr r1, _08164E58 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164E5C
	asrs r1, r0, #0xc
	b _08164E62
	.align 2, 0
_08164E4C: .4byte 0x0203B400
_08164E50: .4byte 0x030046B8
_08164E54: .4byte 0x000003FF
_08164E58: .4byte gSineTable
_08164E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164E62:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _08164E80 @ =gSineTable
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08164E84
	asrs r0, r0, #0xc
	b _08164E8A
	.align 2, 0
_08164E80: .4byte gSineTable
_08164E84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164E8A:
	movs r4, #0
	strh r0, [r6, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	movs r2, #8
	add r2, sb
	mov r8, r2
	ldr r2, _08164F44 @ =0x0000B96C
	ldr r3, _08164F48 @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08164F4C @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _08164F50 @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08164F54 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r7, [sp, #0x34]
	orrs r0, r7
	str r0, [sp, #0x24]
	ldr r0, _08164F58 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, r8
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r4, _08164F5C @ =0x0203B400
	ldr r5, _08164F60 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08164F64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r0, #1
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	add r5, sp, #0x2c
	adds r2, r7, r3
	adds r3, r1, #0
	adds r3, #0xc
	ldr r1, _08164F68 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov sl, r8
	cmp r0, #0
	blt _08164F6C
	asrs r1, r0, #0xc
	b _08164F72
	.align 2, 0
_08164F44: .4byte 0x0000B96C
_08164F48: .4byte 0x0000A929
_08164F4C: .4byte 0x0000047A
_08164F50: .4byte 0x00000226
_08164F54: .4byte 0x0000022E
_08164F58: .4byte 0x00000236
_08164F5C: .4byte 0x0203B400
_08164F60: .4byte 0x030046B8
_08164F64: .4byte 0x000003FF
_08164F68: .4byte gSineTable
_08164F6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08164F72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08164F90 @ =gSineTable
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164F94
	asrs r0, r0, #0xc
	b _08164F9A
	.align 2, 0
_08164F90: .4byte gSineTable
_08164F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08164F9A:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _08165050 @ =0x0000B96C
	ldr r3, _08165054 @ =0x0000A929
	movs r7, #7
	mov r8, r7
	mov r0, r8
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08165058 @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _0816505C @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08165060 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r1, [sp, #0x34]
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, _08165064 @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sl
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r4, _08165068 @ =0x0203B400
	ldr r5, _0816506C @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08165070 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r0, #1
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	add r5, sp, #0x2c
	adds r2, r7, r3
	adds r3, r0, #6
	ldr r1, _08165074 @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r3, r0
	cmp r0, #0
	blt _08165078
	asrs r1, r0, #0xc
	b _0816507E
	.align 2, 0
_08165050: .4byte 0x0000B96C
_08165054: .4byte 0x0000A929
_08165058: .4byte 0x0000047A
_0816505C: .4byte 0x00000226
_08165060: .4byte 0x0000022E
_08165064: .4byte 0x00000236
_08165068: .4byte 0x0203B400
_0816506C: .4byte 0x030046B8
_08165070: .4byte 0x000003FF
_08165074: .4byte gSineTable
_08165078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816507E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _0816509C @ =gSineTable
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _081650A0
	asrs r0, r0, #0xc
	b _081650A6
	.align 2, 0
_0816509C: .4byte gSineTable
_081650A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081650A6:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08165118 @ =0x0000B96C
	ldr r3, _0816511C @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08165120 @ =0x0000047A
	add r0, sb
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	ldr r0, _08165124 @ =0x00000226
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r0, _08165128 @ =0x0000022E
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0x90
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r7, [sp, #0x34]
	orrs r0, r7
	str r0, [sp, #0x24]
	ldr r0, _0816512C @ =0x00000236
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sl
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08165118: .4byte 0x0000B96C
_0816511C: .4byte 0x0000A929
_08165120: .4byte 0x0000047A
_08165124: .4byte 0x00000226
_08165128: .4byte 0x0000022E
_0816512C: .4byte 0x00000236
