	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r4, r2, #0
	adds r0, r4, #0
	adds r0, #0xf4
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DE4BE
	adds r0, r4, #0
	adds r0, #0xdc
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	str r0, [sp, #0x1c]
	adds r0, r4, #0
	adds r0, #0x1c
	str r0, [sp, #0x20]
	adds r1, r4, #0
	adds r1, #0xf0
	str r1, [sp, #0x24]
	adds r2, r4, #0
	adds r2, #0x78
	str r2, [sp, #0x28]
	adds r0, #0x60
	str r0, [sp, #0x2c]
	movs r1, #0x80
	adds r1, r1, r4
	mov sl, r1
	ldr r2, _080DE44C @ =0x030046B8
	mov sb, r2
	movs r7, #0xff
	add r5, sp, #0x14
	movs r0, #5
	mov r8, r0
	movs r6, #5
_080DE410:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080DE450 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080DE454 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r7
	ldr r1, [sp, #0x1c]
	adds r2, r1, r0
	ldr r1, _080DE458 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080DE45C
	asrs r1, r0, #0xc
	b _080DE462
	.align 2, 0
_080DE44C: .4byte 0x030046B8
_080DE450: .4byte 0x000003FF
_080DE454: .4byte 0x0203B400
_080DE458: .4byte 0x085B0A08
_080DE45C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DE462:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ands r2, r7
	lsls r0, r2, #1
	ldr r2, _080DE484 @ =0x085B0A08
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _080DE488
	asrs r0, r0, #0xc
	b _080DE48E
	.align 2, 0
_080DE484: .4byte 0x085B0A08
_080DE488:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DE48E:
	strh r0, [r5, #4]
	ldr r0, [sp, #0x24]
	ldrh r3, [r0]
	movs r0, #0xc
	str r0, [sp]
	ldr r1, [sp, #0x28]
	ldrh r0, [r1]
	str r0, [sp, #4]
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	str r0, [sp, #8]
	ldr r0, [r4, #0x74]
	str r0, [sp, #0xc]
	mov r1, sl
	ldrh r0, [r1]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x20]
	add r1, sp, #0x14
	movs r2, #4
	bl FUN_080df148
	subs r6, #1
	cmp r6, #0
	bge _080DE410
_080DE4BE:
	adds r0, r4, #0
	adds r0, #0xdc
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080de1cc
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x20
	ldrsh r1, [r4, r2]
	movs r2, #0x80
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08240cc4
	adds r2, r4, #0
	adds r2, #0x3c
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, #0x50
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	ldr r0, _080DE528 @ =0x000003DF
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #3
	strb r0, [r1]
	subs r1, #3
	movs r0, #1
	strb r0, [r1]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE528: .4byte 0x000003DF
