	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800b064
FUN_0800b064: @ 0x0800B064
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800b068
FUN_0800b068: @ 0x0800B068
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	mov sb, r1
	ldr r0, [sp, #0x34]
	mov sl, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x10
	adds r7, r5, #0
	adds r7, #0x28
	adds r6, r5, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800B180
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r2, [r5, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0800B104
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B0C4
	rsbs r0, r1, #0
_0800B0C4:
	cmp r0, #4
	bgt _0800B0CC
	adds r0, r2, r1
	b _0800B0CE
_0800B0CC:
	adds r0, r2, #4
_0800B0CE:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B142
	ldr r2, _0800B0F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B0FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800B100 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800B140
	.align 2, 0
_0800B0F8: .4byte 0x030046B8
_0800B0FC: .4byte 0x000003FF
_0800B100: .4byte 0x0203B400
_0800B104:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B10C
	rsbs r0, r1, #0
_0800B10C:
	cmp r0, #4
	bgt _0800B114
	subs r0, r2, r1
	b _0800B116
_0800B114:
	subs r0, r2, #4
_0800B116:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	subs r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B142
	ldr r2, _0800B170 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B174 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800B178 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800B140:
	strb r0, [r5, #3]
_0800B142:
	ldr r2, _0800B17C @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	b _0800B2A4
	.align 2, 0
_0800B170: .4byte 0x030046B8
_0800B174: .4byte 0x000003FF
_0800B178: .4byte 0x0203B400
_0800B17C: .4byte 0x085B0A08
_0800B180:
	mov r3, sb
	ldrh r0, [r3, #6]
	cmp r0, #0
	beq _0800B18A
	b _0800B2A4
_0800B18A:
	add r6, sp, #4
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B1AC
	asrs r0, r0, #8
	b _0800B1B2
_0800B1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B1B2:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B1C4
	asrs r0, r0, #8
	b _0800B1CA
_0800B1C4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B1CA:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800B1DE
	asrs r1, r0, #8
	b _0800B1E4
_0800B1DE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800B1E4:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	movs r1, #4
	mov r8, r1
	ldr r2, _0800B294 @ =0x03002BC0
	ldr r6, [r2]
	ands r6, r1
	cmp r6, #0
	bne _0800B2A4
	add r0, sp, #4
	mov r3, sl
	movs r2, #0x18
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r1, r2
	bgt _0800B2A4
	mov r1, sl
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800B2A4
	add r0, sp, #4
	ldrh r0, [r0, #2]
	movs r2, #0x1a
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0800B2A4
	mov r3, sl
	movs r1, #0x22
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _0800B2A4
	mov r2, r8
	strb r2, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	ldr r3, [sp, #0xc]
	ldr r1, [r3, #0x24]
	ldr r4, _0800B298 @ =0x085AA6E8
	ldr r3, [r3, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r5, sb
	ldrb r5, [r5, #2]
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800B294 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0800B264
	b _0800B3F2
_0800B264:
	ldr r1, _0800B29C @ =0x085AA718
	mov r3, sb
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800B2A0 @ =0x085AA70C
	mov r5, sb
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r1, [sp, #0xc]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800B3F2
	.align 2, 0
_0800B294: .4byte 0x03002BC0
_0800B298: .4byte 0x085AA6E8
_0800B29C: .4byte 0x085AA718
_0800B2A0: .4byte 0x085AA70C
_0800B2A4:
	ldrh r0, [r5, #8]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	mov r2, sl
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800B2C2
	ldrh r0, [r7, #0x1a]
	adds r0, #0x10
	b _0800B2D4
_0800B2C2:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800B2D0
	ldrh r0, [r7, #0x1a]
	subs r0, #0x10
	b _0800B2D4
_0800B2D0:
	mov r3, sl
	ldrh r0, [r3, #2]
_0800B2D4:
	strh r0, [r7, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	ldr r2, [sp, #0xc]
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _0800B326
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800B32E
_0800B326:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800B32E:
	str r0, [r5, #0x28]
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
	beq _0800B352
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800B35A
_0800B352:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800B35A:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800B390 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800B3BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800B394
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800B38A
	ldrb r0, [r4, #5]
_0800B38A:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800B3A4
	.align 2, 0
_0800B390: .4byte 0x0000FFFF
_0800B394:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800B3A4
	strh r1, [r4, #8]
_0800B3A4:
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
_0800B3BA:
	mov r3, sb
	ldrh r0, [r3, #6]
	cmp r0, #0
	bne _0800B3DE
	ldr r1, [sp, #0xc]
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #0x80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0800B3DE
	movs r0, #2
	strb r0, [r5]
	movs r0, #0x12
	strb r0, [r5, #1]
_0800B3DE:
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800B3F2
	movs r0, #3
	strb r0, [r5]
	movs r0, #0xa
	strh r0, [r5, #6]
_0800B3F2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800b404
FUN_0800b404: @ 0x0800B404
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	mov r8, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x10
	adds r7, r5, #0
	adds r7, #0x28
	adds r6, r5, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800B518
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r2, [r5, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0800B49C
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B45C
	rsbs r0, r1, #0
_0800B45C:
	cmp r0, #4
	bgt _0800B464
	adds r0, r2, r1
	b _0800B466
_0800B464:
	adds r0, r2, #4
_0800B466:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B4DA
	ldr r2, _0800B490 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B494 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800B498 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800B4D8
	.align 2, 0
_0800B490: .4byte 0x030046B8
_0800B494: .4byte 0x000003FF
_0800B498: .4byte 0x0203B400
_0800B49C:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800B4A4
	rsbs r0, r1, #0
_0800B4A4:
	cmp r0, #4
	bgt _0800B4AC
	subs r0, r2, r1
	b _0800B4AE
_0800B4AC:
	subs r0, r2, #4
_0800B4AE:
	strb r0, [r6]
	ldrb r0, [r5, #3]
	subs r0, #1
	strb r0, [r5, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800B4DA
	ldr r2, _0800B508 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B50C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800B510 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800B4D8:
	strb r0, [r5, #3]
_0800B4DA:
	ldr r2, _0800B514 @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	b _0800B638
	.align 2, 0
_0800B508: .4byte 0x030046B8
_0800B50C: .4byte 0x000003FF
_0800B510: .4byte 0x0203B400
_0800B514: .4byte 0x085B0A08
_0800B518:
	mov r3, r8
	ldrh r0, [r3, #6]
	cmp r0, #0
	beq _0800B522
	b _0800B638
_0800B522:
	add r6, sp, #4
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B544
	asrs r0, r0, #8
	b _0800B54A
_0800B544:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B54A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800B55C
	asrs r0, r0, #8
	b _0800B562
_0800B55C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800B562:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800B576
	asrs r1, r0, #8
	b _0800B57C
_0800B576:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800B57C:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	movs r1, #4
	mov sb, r1
	ldr r2, _0800B628 @ =0x03002BC0
	ldr r6, [r2]
	ands r6, r1
	cmp r6, #0
	bne _0800B638
	add r0, sp, #4
	ldr r3, [sp, #0x30]
	movs r2, #8
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r1, r2
	bgt _0800B638
	ldr r1, [sp, #0x30]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _0800B638
	add r0, sp, #4
	ldrh r0, [r0, #2]
	movs r2, #0xa
	ldrsh r1, [r1, r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0800B638
	ldr r3, [sp, #0x30]
	movs r1, #0x12
	ldrsh r0, [r3, r1]
	cmp r0, r2
	blt _0800B638
	mov r2, sb
	strb r2, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	mov r3, sl
	ldr r1, [r3, #0x24]
	ldr r4, _0800B62C @ =0x085AA6E8
	ldr r3, [r3, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r5, r8
	ldrb r5, [r5, #2]
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800B628 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0800B5FC
	b _0800B790
_0800B5FC:
	ldr r1, _0800B630 @ =0x085AA718
	mov r3, r8
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800B634 @ =0x085AA70C
	mov r5, r8
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800B790
	.align 2, 0
_0800B628: .4byte 0x03002BC0
_0800B62C: .4byte 0x085AA6E8
_0800B630: .4byte 0x085AA718
_0800B634: .4byte 0x085AA70C
_0800B638:
	ldrh r0, [r5, #8]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldr r2, [sp, #0x30]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800B656
	ldrh r0, [r7, #0x1a]
	adds r0, #0x10
	b _0800B668
_0800B656:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800B664
	ldrh r0, [r7, #0x1a]
	subs r0, #0x10
	b _0800B668
_0800B664:
	ldr r3, [sp, #0x30]
	ldrh r0, [r3, #2]
_0800B668:
	strh r0, [r7, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	mov r2, sl
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _0800B6BA
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800B6C2
_0800B6BA:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800B6C2:
	str r0, [r5, #0x28]
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
	beq _0800B6E6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800B6EE
_0800B6E6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800B6EE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800B724 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800B74E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800B728
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800B71E
	ldrb r0, [r4, #5]
_0800B71E:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800B738
	.align 2, 0
_0800B724: .4byte 0x0000FFFF
_0800B728:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800B738
	strh r1, [r4, #8]
_0800B738:
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
_0800B74E:
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _0800B78C
	movs r0, #2
	strb r0, [r5]
	movs r0, #0xf
	strb r0, [r5, #1]
	movs r0, #0xa
	strh r0, [r5, #6]
	ldr r2, _0800B780 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800B784 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0800B788 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x3c
	strh r0, [r5, #4]
	b _0800B790
	.align 2, 0
_0800B780: .4byte 0x030046B8
_0800B784: .4byte 0x000003FF
_0800B788: .4byte 0x0203B400
_0800B78C:
	subs r0, #1
	strh r0, [r5, #6]
_0800B790:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800b7a0
FUN_0800b7a0: @ 0x0800B7A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #4]
	mov r8, r1
	ldr r0, [sp, #0x30]
	mov sl, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x28
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	beq _0800B7CC
	b _0800B8DC
_0800B7CC:
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	subs r7, r1, r0
	mov r3, sl
	movs r1, #2
	ldrsh r0, [r3, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	adds r0, #0xa4
	str r0, [sp, #8]
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0823785c
	strb r0, [r5, #2]
	ldr r2, _0800B8C4 @ =0x085B0A08
	ldrb r0, [r5, #2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r5, #2]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	movs r3, #4
	mov sb, r3
	ldr r1, _0800B8C8 @ =0x03002BC0
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0800B8DC
	mov r2, r8
	ldrh r2, [r2, #6]
	mov ip, r2
	cmp r2, #0
	bne _0800B8DC
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _0800B848
	rsbs r0, r0, #0
_0800B848:
	cmp r0, #0xb3
	bgt _0800B8DC
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r1, _0800B8CC @ =0x0000018F
	cmp r0, r1
	bgt _0800B8DC
	mov r3, sb
	strb r3, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	ldr r5, [sp, #4]
	ldr r1, [r5, #0x24]
	ldr r4, _0800B8D0 @ =0x085AA6E8
	ldr r3, [r5, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r3, r8
	ldrb r3, [r3, #2]
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	mov r5, ip
	str r5, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800B8C8 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0800B894
	b _0800BA56
_0800B894:
	ldr r1, _0800B8D4 @ =0x085AA718
	mov r3, r8
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800B8D8 @ =0x085AA70C
	mov r5, r8
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r1, [sp, #4]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800BA56
	.align 2, 0
_0800B8C4: .4byte 0x085B0A08
_0800B8C8: .4byte 0x03002BC0
_0800B8CC: .4byte 0x0000018F
_0800B8D0: .4byte 0x085AA6E8
_0800B8D4: .4byte 0x085AA718
_0800B8D8: .4byte 0x085AA70C
_0800B8DC:
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	mov r2, sl
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800B8FA
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _0800B90C
_0800B8FA:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800B908
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
	b _0800B90C
_0800B908:
	mov r3, sl
	ldrh r0, [r3, #2]
_0800B90C:
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	ldr r2, [sp, #4]
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _0800B95E
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800B966
_0800B95E:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800B966:
	str r0, [r5, #0x28]
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
	beq _0800B98A
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800B992
_0800B98A:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800B992:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800B9C8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800B9F2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800B9CC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800B9C2
	ldrb r0, [r4, #5]
_0800B9C2:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800B9DC
	.align 2, 0
_0800B9C8: .4byte 0x0000FFFF
_0800B9CC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800B9DC
	strh r1, [r4, #8]
_0800B9DC:
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
_0800B9F2:
	ldr r3, [sp, #4]
	movs r1, #0xfb
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0800BA12
	movs r1, #4
	ldr r0, _0800BA68 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0800BA42
_0800BA12:
	movs r0, #1
	strb r0, [r5]
	ldr r4, _0800BA6C @ =0x0203B400
	ldr r2, _0800BA70 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0800BA74 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r5, #1]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r5, #2]
_0800BA42:
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BA56
	movs r0, #3
	strb r0, [r5]
	movs r0, #0xa
	strh r0, [r5, #6]
_0800BA56:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800BA68: .4byte 0x03002BC0
_0800BA6C: .4byte 0x0203B400
_0800BA70: .4byte 0x030046B8
_0800BA74: .4byte 0x000003FF

	thumb_func_start FUN_0800ba78
FUN_0800ba78: @ 0x0800BA78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #4]
	mov r8, r1
	ldr r0, [sp, #0x30]
	mov sl, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x28
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	beq _0800BAA4
	b _0800BBB4
_0800BAA4:
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	subs r7, r1, r0
	mov r3, sl
	movs r1, #2
	ldrsh r0, [r3, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	adds r0, #0x80
	str r0, [sp, #8]
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0823785c
	strb r0, [r5, #2]
	ldr r2, _0800BB9C @ =0x085B0A08
	ldrb r0, [r5, #2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #8]
	ldrb r0, [r5, #2]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r5, #0xc]
	movs r3, #4
	mov sb, r3
	ldr r1, _0800BBA0 @ =0x03002BC0
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0800BBB4
	mov r2, r8
	ldrh r2, [r2, #6]
	mov ip, r2
	cmp r2, #0
	bne _0800BBB4
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _0800BB20
	rsbs r0, r0, #0
_0800BB20:
	cmp r0, #0x81
	bgt _0800BBB4
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r6, #0
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r1, _0800BBA4 @ =0x0000018F
	cmp r0, r1
	bgt _0800BBB4
	mov r3, sb
	strb r3, [r5]
	adds r0, r5, #0
	adds r0, #0x18
	ldr r5, [sp, #4]
	ldr r1, [r5, #0x24]
	ldr r4, _0800BBA8 @ =0x085AA6E8
	ldr r3, [r5, #0x18]
	lsls r2, r3, #1
	adds r2, r2, r3
	mov r3, r8
	ldrb r3, [r3, #2]
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2]
	mov r5, ip
	str r5, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _0800BBA0 @ =0x03002BC0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0800BB6C
	b _0800BCDE
_0800BB6C:
	ldr r1, _0800BBAC @ =0x085AA718
	mov r3, r8
	ldrb r0, [r3, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
	ldr r0, _0800BBB0 @ =0x085AA70C
	mov r5, r8
	ldrb r2, [r5, #2]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r1, [sp, #4]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r1, r3
	ldr r0, [r0]
	ldrb r1, [r5, #3]
	ldr r2, [r2]
	bl _call_via_r2
	b _0800BCDE
	.align 2, 0
_0800BB9C: .4byte 0x085B0A08
_0800BBA0: .4byte 0x03002BC0
_0800BBA4: .4byte 0x0000018F
_0800BBA8: .4byte 0x085AA6E8
_0800BBAC: .4byte 0x085AA718
_0800BBB0: .4byte 0x085AA70C
_0800BBB4:
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	mov r2, sl
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r2, #0x1a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0x10
	ble _0800BBD2
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _0800BBE4
_0800BBD2:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800BBE0
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
	b _0800BBE4
_0800BBE0:
	mov r3, sl
	ldrh r0, [r3, #2]
_0800BBE4:
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r6, r5, #0
	adds r6, #0x28
	ldr r2, [sp, #4]
	ldr r3, [r2, #0x20]
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _0800BC36
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BC3E
_0800BC36:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BC3E:
	str r0, [r5, #0x28]
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
	beq _0800BC62
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BC6A
_0800BC62:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BC6A:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0800BCA0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800BCCA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800BCA4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800BC9A
	ldrb r0, [r4, #5]
_0800BC9A:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800BCB4
	.align 2, 0
_0800BCA0: .4byte 0x0000FFFF
_0800BCA4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800BCB4
	strh r1, [r4, #8]
_0800BCB4:
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
_0800BCCA:
	ldrh r0, [r5, #4]
	subs r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800BCDE
	movs r0, #3
	strb r0, [r5]
	movs r0, #0xf
	strh r0, [r5, #6]
_0800BCDE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800bcf0
FUN_0800bcf0: @ 0x0800BCF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	add r0, r8
	mov ip, r0
	mov r7, ip
	adds r7, #0x28
	adds r6, r7, #0
	mov r0, sb
	ldr r3, [r0, #0x20]
	mov r4, ip
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x18]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BD56
	mov r1, ip
	ldr r0, [r1, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BD60
_0800BD56:
	mov r1, ip
	ldr r0, [r1, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BD60:
	mov r2, ip
	str r0, [r2, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BD86
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BD8E
_0800BD86:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BD8E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0800BDC8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800BE00
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800BDD2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800BDCC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0800BDE8
	.align 2, 0
_0800BDC8: .4byte 0x0000FFFF
_0800BDCC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800BDE6
_0800BDD2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800BDE6
	strh r1, [r4, #8]
	movs r2, #1
	b _0800BDE8
_0800BDE6:
	movs r2, #0
_0800BDE8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _0800BE02
_0800BE00:
	movs r2, #0
_0800BE02:
	cmp r2, #0
	beq _0800BE2A
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, r8
	ldrb r0, [r2, #1]
	subs r0, #1
	strb r0, [r2, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BE2A
	mov r0, sb
	mov r1, r8
	bl FUN_0800a494
_0800BE2A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800be38
FUN_0800be38: @ 0x0800BE38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	adds r4, r1, r0
	adds r5, r4, #0
	adds r5, #0x10
	movs r0, #0x28
	adds r0, r0, r4
	mov r8, r0
	adds r6, r4, #2
	movs r0, #1
	ands r0, r2
	cmp r0, r3
	bne _0800BF3E
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	mov r3, r8
	movs r5, #0x1c
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r2, [r4, #2]
	subs r1, r0, r2
	movs r0, #3
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _0800BED4
	adds r0, r1, #0
	cmp r1, #0
	bge _0800BE94
	rsbs r0, r1, #0
_0800BE94:
	cmp r0, #4
	bgt _0800BE9C
	adds r0, r2, r1
	b _0800BE9E
_0800BE9C:
	adds r0, r2, #4
_0800BE9E:
	strb r0, [r6]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BF12
	ldr r2, _0800BEC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800BECC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800BED0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	b _0800BF10
	.align 2, 0
_0800BEC8: .4byte 0x030046B8
_0800BECC: .4byte 0x000003FF
_0800BED0: .4byte 0x0203B400
_0800BED4:
	adds r0, r1, #0
	cmp r1, #0
	bge _0800BEDC
	rsbs r0, r1, #0
_0800BEDC:
	cmp r0, #4
	bgt _0800BEE4
	subs r0, r2, r1
	b _0800BEE6
_0800BEE4:
	subs r0, r2, #4
_0800BEE6:
	strb r0, [r6]
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BF12
	ldr r2, _0800BF9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800BFA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0800BFA4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	subs r0, #0x40
_0800BF10:
	strb r0, [r4, #3]
_0800BF12:
	ldr r2, _0800BFA8 @ =0x085B0A08
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrb r0, [r4, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r4, #8]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r4, #1]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r4, #0xc]
_0800BF3E:
	ldrh r0, [r4, #8]
	mov r1, r8
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #0x18]
	ldrh r0, [r4, #0xc]
	ldrh r3, [r2, #0x1c]
	adds r0, r0, r3
	strh r0, [r2, #0x1c]
	adds r6, r4, #0
	adds r6, #0x28
	mov r5, sl
	ldr r3, [r5, #0x20]
	adds r5, r4, #0
	adds r5, #0x18
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x18]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BFAC
	ldr r0, [r4, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BFB4
	.align 2, 0
_0800BF9C: .4byte 0x030046B8
_0800BFA0: .4byte 0x000003FF
_0800BFA4: .4byte 0x0203B400
_0800BFA8: .4byte 0x085B0A08
_0800BFAC:
	ldr r0, [r4, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BFB4:
	str r0, [r4, #0x28]
	ldrb r0, [r5, #4]
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
	beq _0800BFD8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BFE0
_0800BFD8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BFE0:
	str r0, [r6]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _0800C018 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _0800C042
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800C01C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _0800C010
	ldrb r0, [r5, #5]
_0800C010:
	subs r0, #1
	strh r0, [r5, #8]
	b _0800C02C
	.align 2, 0
_0800C018: .4byte 0x0000FFFF
_0800C01C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _0800C02C
	strh r1, [r5, #8]
_0800C02C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_0800C042:
	ldrb r0, [r4, #1]
	cmp r0, #5
	bls _0800C04C
	subs r0, #1
	strb r0, [r4, #1]
_0800C04C:
	ldrh r2, [r4, #6]
	ldrh r0, [r4, #4]
	cmp r0, r2
	blo _0800C066
	ldr r0, [r4, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x28]
	subs r0, r2, #1
	movs r1, #0
	strh r0, [r4, #6]
	strh r1, [r4, #4]
	b _0800C070
_0800C066:
	ldr r0, [r4, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x28]
_0800C070:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0800C0A0
	movs r0, #0
	strb r0, [r4]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r5, sb
	ldrb r0, [r5, #1]
	subs r0, #1
	strb r0, [r5, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800C0A0
	mov r0, sl
	mov r1, sb
	bl FUN_0800a494
_0800C0A0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800c0b0
FUN_0800c0b0: @ 0x0800C0B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r2, #0
	ldrh r6, [r0, #0x3e]
	cmp r6, #0
	bne _0800C0CA
	movs r1, #0x40
	ldr r0, [r0, #0x38]
	ands r0, r1
	movs r6, #0x1e
	cmp r0, #0
	beq _0800C0CA
	movs r6, #0x32
_0800C0CA:
	ldrh r7, [r5, #0x28]
	cmp r7, #0
	bne _0800C126
	cmp r6, #0
	ble _0800C126
	movs r4, #8
	strh r4, [r5, #0x28]
	adds r0, r5, #0
	adds r0, #0x3c
	movs r1, #0xb5
	lsls r1, r1, #1
	bl FUN_0822b20c
	strh r4, [r5, #0x2e]
	ldrh r0, [r5, #0x24]
	subs r0, r0, r6
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800C126
	ldrh r0, [r5, #0x26]
	strh r0, [r5, #0x24]
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0800C130 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r0, [r5, #0x36]
	ldrh r2, [r5, #0x38]
	str r7, [sp]
	movs r1, #0x96
	lsls r1, r1, #2
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #1
	add r3, sp, #0xc
	bl FUN_0800ac80
_0800C126:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C130: .4byte 0x0000FFFF

	thumb_func_start Entity95A8_Update
Entity95A8_Update: @ 0x0800C134
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x20]
	ldr r0, _0800C150 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _0800C154
	movs r0, #1
	b _0800C156
	.align 2, 0
_0800C150: .4byte 0x030046A0
_0800C154:
	movs r0, #0
_0800C156:
	cmp r0, #0
	bne _0800C178
	ldr r0, [r4, #0x58]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0xca
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_080136b4
	b _0800C240
_0800C178:
	ldr r0, [r4, #0x58]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x58]
	adds r2, r4, #0
	adds r2, #0xca
	ldrh r1, [r2]
	ldr r0, _0800C210 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_08013698
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _0800C1A0
	subs r0, #1
	strh r0, [r4, #0x28]
_0800C1A0:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _0800C1BA
	subs r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800C1BA
	adds r0, r4, #0
	adds r0, #0x3c
	ldr r1, _0800C214 @ =0x00000169
	bl FUN_0822b20c
_0800C1BA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	ldr r2, _0800C218 @ =0x085AA76C
	ldrh r1, [r4, #0x2a]
	lsls r1, r1, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _0800C1EE
	strh r3, [r4, #0x2c]
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0800C1E6
	strh r3, [r4, #0x2a]
_0800C1E6:
	ldrh r1, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0, #0x10]
_0800C1EE:
	adds r2, r4, #0
	adds r2, #0x30
	ldrb r0, [r2]
	cmp r0, #0
	beq _0800C21C
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble _0800C234
	movs r0, #0x32
	strh r0, [r4, #0x34]
	movs r0, #0
	b _0800C232
	.align 2, 0
_0800C210: .4byte 0x0000FFFB
_0800C214: .4byte 0x00000169
_0800C218: .4byte 0x085AA76C
_0800C21C:
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x32
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0800C234
	strh r1, [r4, #0x34]
	movs r0, #1
_0800C232:
	strb r0, [r2]
_0800C234:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x76
	strh r0, [r1]
_0800C240:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity95A8_Destroy
Entity95A8_Destroy: @ 0x0800C248
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_080138fc
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity95A8_Init
Entity95A8_Init: @ 0x0800C26C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r7, r0, #0
	movs r4, #0
	strh r1, [r7, #0x18]
	movs r0, #0x6c
	movs r1, #0xc8
	bl VM_GetKeywordValue
	strh r0, [r7, #0x26]
	movs r0, #1
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x28]
	movs r0, #0x6e
	movs r1, #4
	bl VM_GetKeywordValue
	strh r0, [r7, #0x36]
	movs r0, #0x65
	movs r1, #0x32
	bl VM_GetKeywordValue
	strh r0, [r7, #0x38]
	strh r4, [r7, #0x2a]
	strh r4, [r7, #0x2c]
	strh r4, [r7, #0x2e]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800C2E8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800C2E0 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	adds r0, #0x64
	lsls r0, r0, #0x10
	ldr r2, _0800C2E4 @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800C2F2
	.align 2, 0
_0800C2E0: .4byte 0xFFFF0000
_0800C2E4: .4byte 0x0000FFFF
_0800C2E8:
	ldr r1, _0800C3AC @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800C2F2:
	add r4, sp, #0xc
	adds r0, r4, #0
	bl FUN_08241574
	str r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x30
	movs r6, #0
	strb r6, [r0]
	ldrh r0, [r4, #2]
	strh r0, [r7, #0x32]
	strh r6, [r7, #0x34]
	ldr r2, _0800C3AC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r4, #0x1e
	orrs r0, r4
	ldr r1, _0800C3B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	movs r0, #0xa0
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r7, #0
	adds r4, #0xc4
	ldr r2, _0800C3B4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0800C3B8 @ =FUN_0800c0b0
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	subs r4, #0x88
	ldr r1, _0800C3BC @ =0x0000066A
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r5, r7, #0
	adds r5, #0x58
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r5, #0x10]
	ldr r1, _0800C3C0 @ =0x00000169
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r7, #0x74]
	str r1, [r7, #0x78]
	adds r0, r7, #0
	adds r0, #0x84
	adds r1, r7, #0
	adds r1, #0x74
	movs r2, #0
	bl FUN_0801385c
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800C3AC: .4byte 0xFFFF0000
_0800C3B0: .4byte 0x0000FFFF
_0800C3B4: .4byte 0x00004001
_0800C3B8: .4byte FUN_0800c0b0
_0800C3BC: .4byte 0x0000066A
_0800C3C0: .4byte 0x00000169

	thumb_func_start Entity95A8_Create
Entity95A8_Create: @ 0x0800C3C4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x8a
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800C404
	ldr r1, _0800C3FC @ =Entity95A8_Update
	ldr r2, _0800C400 @ =Entity95A8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity95A8_Init
	cmp r0, #0
	bge _0800C404
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800C406
	.align 2, 0
_0800C3FC: .4byte Entity95A8_Update
_0800C400: .4byte Entity95A8_Destroy
_0800C404:
	adds r0, r4, #0
_0800C406:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
