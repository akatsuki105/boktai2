	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r3, r0, #0
	adds r4, r2, #0
	adds r1, #0x44
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DE546
	b _080DE69A
_080DE546:
	adds r0, r4, #0
	adds r0, #0xf4
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r3, #0x42
	str r3, [sp, #0x3c]
	adds r1, r4, #0
	adds r1, #0x3c
	str r1, [sp, #0x38]
	adds r2, #0x8c
	str r2, [sp, #0x40]
	adds r1, #0xba
	str r1, [sp, #0x2c]
	adds r2, #0x67
	str r2, [sp, #0x28]
	cmp r0, #0
	beq _080DE656
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
	str r2, [sp, #0x30]
	adds r0, #0x60
	str r0, [sp, #0x34]
	movs r1, #0x80
	adds r1, r1, r4
	mov sl, r1
	ldr r2, _080DE5E4 @ =0x030046B8
	mov sb, r2
	movs r7, #0xff
	add r5, sp, #0x14
	movs r0, #5
	mov r8, r0
	movs r6, #5
_080DE5AA:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080DE5E8 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080DE5EC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r7
	ldr r1, [sp, #0x1c]
	adds r2, r1, r0
	ldr r1, _080DE5F0 @ =0x085B0A08
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
	blt _080DE5F4
	asrs r1, r0, #0xc
	b _080DE5FA
	.align 2, 0
_080DE5E4: .4byte 0x030046B8
_080DE5E8: .4byte 0x000003FF
_080DE5EC: .4byte 0x0203B400
_080DE5F0: .4byte 0x085B0A08
_080DE5F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DE5FA:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ands r2, r7
	lsls r0, r2, #1
	ldr r2, _080DE61C @ =0x085B0A08
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _080DE620
	asrs r0, r0, #0xc
	b _080DE626
	.align 2, 0
_080DE61C: .4byte 0x085B0A08
_080DE620:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DE626:
	strh r0, [r5, #4]
	ldr r0, [sp, #0x24]
	ldrh r3, [r0]
	movs r0, #0xc
	str r0, [sp]
	ldr r1, [sp, #0x30]
	ldrh r0, [r1]
	str r0, [sp, #4]
	ldr r2, [sp, #0x34]
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
	bge _080DE5AA
_080DE656:
	ldr r2, [sp, #0x3c]
	ldrb r1, [r2]
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
	ldr r0, [sp, #0x38]
	ldrh r1, [r0, #6]
	movs r0, #4
	orrs r1, r0
	ldr r2, [sp, #0x38]
	strh r1, [r2, #6]
	ldr r2, [sp, #0x40]
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r0, _080DE6AC @ =0x000003DF
	bl PlaySound_082406e0
	movs r0, #3
	ldr r1, [sp, #0x2c]
	strb r0, [r1]
	movs r0, #1
	ldr r2, [sp, #0x28]
	strb r0, [r2]
_080DE69A:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE6AC: .4byte 0x000003DF
