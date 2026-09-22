	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080452cc
FUN_080452cc: @ 0x080452CC
	push {lr}
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0xc0
	lsls r3, r3, #1
_080452DA:
	ldrb r0, [r1, #9]
	cmp r0, #0
	bne _080452E4
	adds r0, r1, #0
	b _080452EE
_080452E4:
	adds r2, #1
	adds r1, r1, r3
	cmp r2, #0xf
	ble _080452DA
	movs r0, #0
_080452EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080452f4
FUN_080452f4: @ 0x080452F4
	push {r4, r5, lr}
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	bne _08045304
	movs r0, #1
	rsbs r0, r0, #0
	b _0804532A
_08045304:
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	bl ParticleShadow_Remove
	adds r0, r5, #0
	adds r0, #0xa4
	bl MainSprite_Remove
	movs r1, #0
	strb r1, [r5, #9]
_0804532A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08045330
FUN_08045330: @ 0x08045330
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldrb r0, [r1, #6]
	lsrs r3, r0, #4
	ldrh r1, [r1, #4]
	ldr r0, _08045354 @ =0x00000FFF
	ands r0, r1
	movs r5, #0
	movs r4, #0
	strh r0, [r2, #0x20]
	cmp r3, #1
	beq _08045362
	cmp r3, #1
	bgt _08045358
	cmp r3, #0
	beq _0804535E
	b _080453A0
	.align 2, 0
_08045354: .4byte 0x00000FFF
_08045358:
	cmp r3, #2
	beq _08045396
	b _080453A0
_0804535E:
	strb r5, [r2, #4]
	b _08045398
_08045362:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x1c
	movs r1, #0x23
	adds r1, r1, r2
	mov ip, r1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	mov r6, ip
	ldrb r6, [r6]
	cmp r0, r6
	bne _0804538E
	strb r5, [r2, #4]
	b _08045390
_0804538E:
	strb r3, [r2, #4]
_08045390:
	strb r3, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_08045396:
	strb r3, [r2, #4]
_08045398:
	movs r0, #1
	strb r0, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_080453A0:
	movs r1, #0
	strb r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_080453AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080453b0
FUN_080453b0: @ 0x080453B0
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0, #8]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080453CE
	rsbs r1, r1, #0
_080453CE:
	ldr r4, [r2, #0x38]
	cmp r1, r4
	bhi _080453F4
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x6c
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _080453E6
	rsbs r0, r0, #0
_080453E6:
	cmp r0, r4
	bhi _080453F4
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08045330
	b _08045400
_080453F4:
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_08045400:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08045408
FUN_08045408: @ 0x08045408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	ldr r1, _08045514 @ =0x000F4240
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r7, #0
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r6, #0xf
_08045426:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08045440
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045440
	ldr r0, [r4, #0x44]
	cmp r0, r1
	bhs _08045440
	adds r1, r0, #0
	adds r7, r4, #0
_08045440:
	subs r6, #1
	adds r4, r4, r2
	cmp r6, #0
	bge _08045426
	cmp r7, #0
	beq _0804551C
	mov r1, sb
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	beq _0804551C
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r2, #0xc4
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0xc6
	str r3, [sp, #0x40]
	adds r0, r7, #0
	adds r0, #0xc8
	str r0, [sp, #0x44]
	adds r1, r7, #0
	adds r1, #0x48
	str r1, [sp, #0x38]
	mov r2, sp
	adds r2, #0x30
	str r2, [sp, #0x3c]
	movs r3, #0
	mov r8, r3
	movs r6, #0xf
	movs r5, #0xa8
	lsls r5, r5, #2
	add r5, sb
_08045484:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _080454B8
	ldr r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x60
	ldrb r2, [r5, #2]
	str r2, [sp, #0x48]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r4
	str r3, [sp]
	movs r3, #6
	ldrsh r2, [r5, r3]
	str r2, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	movs r3, #0x64
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x48]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r5, #8]
	mov r3, r8
	strh r3, [r5]
_080454B8:
	subs r6, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r6, #0
	bge _08045484
	ldrh r0, [r7]
	str r0, [sp, #0x10]
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x14]
	ldr r3, [sp, #0x40]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x18]
	ldr r2, [sp, #0x44]
	movs r3, #0
	ldrsh r0, [r2, r3]
	str r0, [sp, #0x1c]
	mov r0, sb
	ldrh r3, [r0, #0x1c]
	ldr r2, [sp, #0x38]
	add r1, sp, #0x20
	movs r6, #3
_080454EC:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r6, #1
	cmp r6, #0
	bge _080454EC
	ldr r0, _08045518 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	add r1, sp, #0x10
	ldr r2, [sp, #0x3c]
	str r1, [r2, #4]
	adds r0, r3, #0
	ldr r1, [sp, #0x3c]
	bl Script_ExecById
	movs r0, #1
	b _0804551E
	.align 2, 0
_08045514: .4byte 0x000F4240
_08045518: .4byte 0xFFFF0000
_0804551C:
	movs r0, #0
_0804551E:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045530
FUN_08045530: @ 0x08045530
	push {lr}
	adds r3, r1, #0
	cmp r2, #8
	bhi _080455F4
	lsls r0, r2, #2
	ldr r1, _08045544 @ =_08045548
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08045544: .4byte _08045548
_08045548: @ jump table
	.4byte _0804556C @ case 0
	.4byte _080455F4 @ case 1
	.4byte _08045584 @ case 2
	.4byte _08045598 @ case 3
	.4byte _080455B0 @ case 4
	.4byte _080455BC @ case 5
	.4byte _080455C8 @ case 6
	.4byte _080455D4 @ case 7
	.4byte _080455EC @ case 8
_0804556C:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045580 @ =0x00000177
	adds r1, r3, r2
	movs r0, #1
	b _080455F2
	.align 2, 0
_08045580: .4byte 0x00000177
_08045584:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045594 @ =0x00000177
	adds r1, r3, r2
	b _080455F2
	.align 2, 0
_08045594: .4byte 0x00000177
_08045598:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _080455AC @ =0x00000177
	adds r1, r3, r2
	movs r0, #2
	b _080455F2
	.align 2, 0
_080455AC: .4byte 0x00000177
_080455B0:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #1
	b _080455DE
_080455BC:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #3
	b _080455DE
_080455C8:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #5
	b _080455DE
_080455D4:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #4
_080455DE:
	strb r0, [r2]
	ldr r2, _080455E8 @ =0x00000177
	adds r0, r3, r2
	strb r1, [r0]
	b _080455F4
	.align 2, 0
_080455E8: .4byte 0x00000177
_080455EC:
	ldr r0, _080455F8 @ =0x00000177
	adds r1, r3, r0
	movs r0, #0x7f
_080455F2:
	strb r0, [r1]
_080455F4:
	pop {r0}
	bx r0
	.align 2, 0
_080455F8: .4byte 0x00000177

	thumb_func_start FUN_080455fc
FUN_080455fc: @ 0x080455FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r0, r4, r0
	str r0, [sp, #8]
	movs r1, #0xc4
	adds r1, r1, r4
	mov sl, r1
	ldrb r3, [r4, #5]
	cmp r3, #0
	beq _080456C6
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804567C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045680 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045684
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _08045690
	.align 2, 0
_0804567C: .4byte 0x085AB404
_08045680: .4byte 0x0000192C
_08045684:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045690:
	adds r5, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _080456B6
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _080456BE
_080456B6:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080456BE:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	b _08045760
_080456C6:
	ldrb r0, [r4, #7]
	ldr r2, _0804571C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r0, _08045720 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045724
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
	b _08045730
	.align 2, 0
_0804571C: .4byte 0x085AB404
_08045720: .4byte 0x0000192C
_08045724:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r3, [r0]
_08045730:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sb
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045756
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804575E
_08045756:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804575E:
	str r1, [r6, #8]
_08045760:
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r3, [sp, #4]
	cmp r1, r3
	bne _080457F4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804579C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804579C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _0804587E
_0804579C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _080457F4
	mov r6, r8
	ldrb r1, [r6, #0x1e]
	cmp r1, #0
	beq _080457F4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r7, [r5]
	cmp r1, r7
	bne _080457CA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080457E4
_080457CA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _080457F4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080457F4
_080457E4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _0804587E
_080457F4:
	mov r1, r8
	ldr r3, [r1, #0x18]
	ldr r5, [r4, #0x3c]
	movs r6, #0
	ldrsh r2, [r3, r6]
	mov r7, sl
	movs r6, #0
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804580C
	rsbs r2, r2, #0
_0804580C:
	cmp r2, r5
	bge _0804583E
	movs r7, #2
	ldrsh r2, [r3, r7]
	mov r6, sl
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045822
	rsbs r2, r2, #0
_08045822:
	cmp r2, #0xff
	bgt _0804583E
	movs r1, #4
	ldrsh r2, [r3, r1]
	mov r3, sl
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045838
	rsbs r2, r2, #0
_08045838:
	movs r1, #1
	cmp r2, r5
	blt _08045840
_0804583E:
	movs r1, #0
_08045840:
	cmp r1, #0
	beq _08045858
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _0804587E
_08045858:
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804587E
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _0804587A
	ldr r0, [sp, #8]
	bl FUN_08234e3c
	adds r0, r4, #0
	bl FUN_080453b0
	b _0804587E
_0804587A:
	subs r1, #1
	strh r1, [r4, #0x20]
_0804587E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045890
FUN_08045890: @ 0x08045890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	adds r0, r4, #0
	adds r0, #0xc4
	str r0, [sp, #8]
	ldrb r5, [r4, #5]
	cmp r5, #0
	beq _08045968
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804590C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045910 @ =0x0000192C
	adds r7, r7, r3
	ldrh r1, [r1]
	mov ip, r1
	movs r0, #1
	mov sl, r0
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _08045914
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _08045920
	.align 2, 0
_0804590C: .4byte 0x085AB404
_08045910: .4byte 0x0000192C
_08045914:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045920:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045946
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804594E
_08045946:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804594E:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x23
	ldrb r1, [r1]
	adds r1, #5
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	adds r1, r2, #0
	b _08045A08
_08045968:
	ldrb r0, [r4, #7]
	ldr r2, _080459C0 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r3, r8
	adds r7, r0, r3
	ldr r0, _080459C4 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sl, r1
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _080459C8
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _080459D4
	.align 2, 0
_080459C0: .4byte 0x085AB404
_080459C4: .4byte 0x0000192C
_080459C8:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_080459D4:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sl
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _080459FA
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045A02
_080459FA:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045A02:
	str r1, [r6, #8]
	adds r1, r4, #0
	adds r1, #0x22
_08045A08:
	ldrb r1, [r1]
	mov r3, sb
	ldrb r2, [r3]
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r1, #0
	lsls r1, r5, #0x18
	asrs r3, r1, #0x18
	cmp r3, #8
	ble _08045A28
	adds r1, r2, #0
	adds r1, #8
	mov r6, sb
	strb r1, [r6]
	b _08045A40
_08045A28:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r3, r1
	bge _08045A3A
	adds r1, r2, #0
	subs r1, #8
	mov r7, sb
	strb r1, [r7]
	b _08045A40
_08045A3A:
	adds r1, r2, r5
	mov r2, sb
	strb r1, [r2]
_08045A40:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r6, [sp, #4]
	cmp r1, r6
	bne _08045AD4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08045A7C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08045A7C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045B5A
_08045A7C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _08045AD4
	mov r7, r8
	ldrb r1, [r7, #0x1e]
	cmp r1, #0
	beq _08045AD4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r2, [r5]
	cmp r1, r2
	bne _08045AAA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08045AC4
_08045AAA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _08045AD4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _08045AD4
_08045AC4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045AD4:
	mov r6, r8
	ldr r3, [r6, #0x18]
	ldr r5, [r4, #0x3c]
	movs r7, #0
	ldrsh r2, [r3, r7]
	ldr r6, [sp, #8]
	movs r7, #0
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045AEC
	rsbs r2, r2, #0
_08045AEC:
	cmp r2, r5
	bge _08045B1E
	movs r1, #2
	ldrsh r2, [r3, r1]
	ldr r6, [sp, #8]
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B02
	rsbs r2, r2, #0
_08045B02:
	cmp r2, #0xff
	bgt _08045B1E
	movs r1, #4
	ldrsh r2, [r3, r1]
	ldr r3, [sp, #8]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B18
	rsbs r2, r2, #0
_08045B18:
	movs r3, #1
	cmp r2, r5
	blt _08045B20
_08045B1E:
	movs r3, #0
_08045B20:
	cmp r3, #0
	beq _08045B34
	movs r0, #0
	strb r0, [r4, #0xc]
	movs r1, #3
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045B34:
	mov r7, sb
	ldrb r1, [r7]
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r1, r2
	adds r2, r4, #0
	adds r2, #0x23
	ldrb r2, [r2]
	cmp r1, r2
	bne _08045B5A
	strb r3, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r3, [r4, #0x10]
	movs r0, #0
_08045B5A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045b6c
FUN_08045b6c: @ 0x08045B6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #0xc]
	movs r0, #0x60
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r4, r1
	str r1, [sp, #0x10]
	movs r2, #0x68
	adds r2, r2, r4
	mov sb, r2
	adds r3, r4, #0
	adds r3, #0xa4
	str r3, [sp, #0x14]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08045C64
	movs r5, #0
	strb r5, [r4, #5]
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	mov r6, sb
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	ldrh r1, [r2, #2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	mov r6, sl
	strb r0, [r6, #5]
	ldrb r0, [r4, #7]
	ldr r2, _08045C04 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	ldr r6, [sp, #0x14]
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045C08 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045C0C
	adds r0, r4, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _08045C12
	.align 2, 0
_08045C04: .4byte 0x085AB414
_08045C08: .4byte 0x0000192C
_08045C0C:
	adds r0, r4, #0
	adds r0, #0x2c
	strb r5, [r0]
_08045C12:
	adds r2, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045C22
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045C28
_08045C22:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045C28:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r5]
	cmp r0, #0
	beq _08045C50
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08045C58
_08045C50:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08045C58:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x36
	strb r0, [r1]
_08045C64:
	mov r2, r8
	ldr r0, [r2, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp, #0xc]
	cmp r0, r3
	bne _08045CF8
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08045CA0
	mov r0, r8
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045CA0
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045E58
_08045CA0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08045CF8
	mov r5, r8
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08045CF8
	mov r2, r8
	adds r2, #0x20
	adds r3, r4, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r6, [r3]
	cmp r0, r6
	bne _08045CCE
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08045CE8
_08045CCE:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08045CF8
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08045CF8
_08045CE8:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045E58
_08045CF8:
	mov r0, r8
	ldr r2, [r0, #0x18]
	ldr r3, [r4, #0x3c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov r6, sb
	movs r5, #0
	ldrsh r0, [r6, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D10
	rsbs r1, r1, #0
_08045D10:
	cmp r1, r3
	bge _08045D42
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r5, sb
	movs r6, #2
	ldrsh r0, [r5, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D26
	rsbs r1, r1, #0
_08045D26:
	cmp r1, #0xff
	bgt _08045D42
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, sb
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D3C
	rsbs r1, r1, #0
_08045D3C:
	movs r0, #1
	cmp r1, r3
	blt _08045D44
_08045D42:
	movs r0, #0
_08045D44:
	cmp r0, #0
	beq _08045D54
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	b _08045DAE
_08045D54:
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08045D9E
	ldr r0, [sp, #0x14]
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08045D98
	ldr r2, [sp, #0x14]
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r5, #0x20
	cmp r0, #0
	beq _08045D7C
	movs r5, #0x10
_08045D7C:
	mov r1, sl
	adds r1, #8
	mov r2, sl
	adds r2, #0x10
	mov r3, sl
	adds r3, #5
	movs r0, #0x28
	str r0, [sp]
	str r0, [sp, #4]
	str r5, [sp, #8]
	ldr r0, [sp, #0x10]
	bl FUN_08234e78
	strb r0, [r6]
_08045D98:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08045DB8
_08045D9E:
	ldr r3, [sp, #0x14]
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08045DB8
	movs r1, #0
	strb r1, [r4, #4]
_08045DAE:
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08045E58
_08045DB8:
	ldrb r0, [r4, #7]
	ldr r2, _08045E00 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r5, r8
	adds r7, r0, r5
	ldr r0, _08045E04 @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r1, #1
	mov r8, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045E08
	adds r0, r4, #0
	adds r0, #0x2c
	mov r2, r8
	strb r2, [r0]
	adds r2, r0, #0
	b _08045E12
	.align 2, 0
_08045E00: .4byte 0x085AB414
_08045E04: .4byte 0x0000192C
_08045E08:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08045E12:
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045E20
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045E26
_08045E20:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045E26:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045E4E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045E56
_08045E4E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045E56:
	str r1, [r6, #8]
_08045E58:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08045e68
FUN_08045e68: @ 0x08045E68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r6, r1, #0
	str r2, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xc4
	ldr r0, _08045EE4 @ =0x00001A2C
	add r0, r8
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	str r0, [sp, #8]
	mov r0, r8
	ldr r3, [r0, #0x18]
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r7, r4]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r5, r1, #0
	muls r5, r1, r5
	adds r1, r5, #0
	adds r0, r0, r1
	str r0, [r6, #0x14]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r5, #4
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	lsls r0, r4, #0x18
	asrs r3, r0, #0x18
	cmp r3, #8
	ble _08045EE8
	adds r0, r1, #0
	adds r0, #8
	b _08045EF8
	.align 2, 0
_08045EE4: .4byte 0x00001A2C
_08045EE8:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08045EF6
	adds r0, r1, #0
	subs r0, #8
	b _08045EF8
_08045EF6:
	adds r0, r1, r4
_08045EF8:
	strb r0, [r2]
	ldrb r4, [r6, #5]
	cmp r4, #0
	beq _08045FAE
	movs r0, #0
	mov sb, r0
	mov r1, sb
	strb r1, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _08045F5C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r2, _08045F60 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r4, r1, #0
	ands r4, r0
	adds r1, r4, #0
	strb r4, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _08045F64
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	b _08045F72
	.align 2, 0
_08045F5C: .4byte 0x085AB404
_08045F60: .4byte 0x0000192C
_08045F64:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r4, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
_08045F72:
	adds r4, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08045F98
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08045FA0
_08045F98:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045FA0:
	str r1, [r5, #8]
	movs r1, #1
	strb r1, [r6, #8]
	mov r3, sl
	ldrb r1, [r3]
	strb r1, [r6, #0xb]
	b _08046046
_08045FAE:
	ldrb r0, [r6, #7]
	ldr r2, _08046004 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r0, _08046008 @ =0x0000192C
	add ip, r0
	ldrh r1, [r1]
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _0804600C
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r2, #1
	strb r2, [r0]
	b _08046018
	.align 2, 0
_08046004: .4byte 0x085AB404
_08046008: .4byte 0x0000192C
_0804600C:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r4, [r0]
_08046018:
	adds r4, r0, #0
	ldrb r0, [r1]
	add r0, sb
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	str r3, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _0804603C
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08046044
_0804603C:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046044:
	str r1, [r5, #8]
_08046046:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r4, [sp, #4]
	cmp r1, r4
	bne _080460DA
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046082
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08046082
	movs r0, #5
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	movs r0, #0
	str r0, [r6, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x1c]
	movs r0, #0
	b _08046244
_08046082:
	ldrb r1, [r6, #0x1f]
	cmp r1, #0
	beq _080460DA
	mov r5, r8
	ldrb r1, [r5, #0x1e]
	cmp r1, #0
	beq _080460DA
	mov r3, r8
	adds r3, #0x20
	adds r4, r6, #0
	adds r4, #0x26
	ldrb r1, [r3]
	ldrb r2, [r4]
	cmp r1, r2
	bne _080460B0
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080460CA
_080460B0:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r4, [r4]
	cmp r1, r4
	bne _080460DA
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080460DA
_080460CA:
	movs r0, #0
	strb r0, [r6, #0x1e]
	movs r1, #6
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r0, [r6, #0x10]
	b _08046244
_080460DA:
	mov r4, r8
	ldr r3, [r4, #0x18]
	ldr r4, [r6, #0x3c]
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080460F0
	rsbs r2, r2, #0
_080460F0:
	cmp r2, r4
	bge _0804611E
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046104
	rsbs r2, r2, #0
_08046104:
	cmp r2, #0xff
	bgt _0804611E
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r5, #4
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046118
	rsbs r2, r2, #0
_08046118:
	movs r1, #1
	cmp r2, r4
	blt _08046120
_0804611E:
	movs r1, #0
_08046120:
	cmp r1, #0
	beq _08046196
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	ldrsh r2, [r1, r3]
	mov ip, r2
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r3, r2, r0
	movs r5, #4
	ldrsh r4, [r1, r5]
	movs r2, #4
	ldrsh r1, [r7, r2]
	subs r2, r4, r1
	adds r5, r3, #0
	muls r5, r3, r5
	mov sb, r5
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	add sb, r2
	mov r5, ip
	subs r0, r0, r5
	subs r1, r1, r4
	bl ArcTan2_8
	adds r2, r0, #0
	ldr r1, [sp, #8]
	subs r2, r1, r2
	mov r3, sl
	ldrb r1, [r3]
	adds r1, #0x80
	ldr r4, [sp, #8]
	subs r1, r4, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #0
	bge _08046174
	rsbs r2, r2, #0
_08046174:
	mov r5, r8
	ldr r3, [r5, #0x18]
	cmp r2, #0x3f
	bgt _08046196
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	bge _08046186
	rsbs r1, r1, #0
_08046186:
	cmp r1, #0x1f
	bgt _08046196
	adds r2, r6, #0
	adds r2, #0x37
	movs r1, #1
	strb r1, [r2]
	mov r1, sb
	str r1, [r6, #0x44]
_08046196:
	ldrb r2, [r6, #0xb]
	mov r4, sl
	ldrb r1, [r4]
	subs r1, r2, r1
	cmp r1, #0
	bge _080461A4
	rsbs r1, r1, #0
_080461A4:
	cmp r1, #0x3f
	ble _080461EC
	ldr r1, [r6, #0x40]
	lsrs r4, r1, #1
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461BC
	rsbs r2, r2, #0
_080461BC:
	cmp r2, r4
	bge _08046234
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461D0
	rsbs r2, r2, #0
_080461D0:
	cmp r2, #0xff
	bgt _08046234
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461E4
	rsbs r2, r2, #0
_080461E4:
	movs r3, #1
	cmp r2, r4
	blt _08046236
	b _08046234
_080461EC:
	adds r4, r3, #0
	ldr r5, [r6, #0x40]
	mov sb, r5
	movs r2, #0
	ldrsh r1, [r4, r2]
	mov r8, r1
	movs r5, #0
	ldrsh r1, [r7, r5]
	mov r5, r8
	subs r2, r5, r1
	cmp r2, #0
	bge _08046206
	rsbs r2, r2, #0
_08046206:
	cmp r2, sb
	bge _08046234
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r4, #2
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804621A
	rsbs r2, r2, #0
_0804621A:
	cmp r2, #0xff
	bgt _08046234
	movs r5, #4
	ldrsh r2, [r3, r5]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804622E
	rsbs r2, r2, #0
_0804622E:
	movs r3, #1
	cmp r2, sb
	blt _08046236
_08046234:
	movs r3, #0
_08046236:
	cmp r3, #0
	bne _08046244
	ldrb r1, [r6, #0xc]
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r3, [r6, #0x10]
_08046244:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046254
FUN_08046254: @ 0x08046254
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r1, [r5, #5]
	cmp r1, #0
	beq _08046324
	movs r6, #0
	strb r6, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080462B8 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r4, r5, #0
	adds r4, #0xa4
	lsls r0, r0, #5
	adds r7, r0, r3
	ldr r0, _080462BC @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r2, #1
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r5, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080462C0
	movs r0, #8
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _080462CC
	.align 2, 0
_080462B8: .4byte 0x085AB404
_080462BC: .4byte 0x0000192C
_080462C0:
	adds r1, r5, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r6, [r0]
_080462CC:
	adds r6, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r6]
	cmp r0, #0
	beq _080462F2
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _080462FA
_080462F2:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080462FA:
	str r0, [r4, #8]
	movs r2, #0
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x60
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	adds r1, r0, #0
	str r1, [r4]
_08046324:
	ldr r1, [r5, #0x10]
	cmp r1, #7
	bls _08046336
	movs r1, #5
	movs r2, #0
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r2, [r5, #0x10]
_08046336:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08046340
FUN_08046340: @ 0x08046340
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #5]
	cmp r0, #0
	beq _0804642C
	movs r4, #0
	strb r4, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _080463AC @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080463B0 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	movs r0, #1
	mov sl, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080463B4
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, sl
	strb r1, [r0]
	b _080463BA
	.align 2, 0
_080463AC: .4byte 0x085AB424
_080463B0: .4byte 0x0000192C
_080463B4:
	adds r0, r6, #0
	adds r0, #0x2c
	strb r4, [r0]
_080463BA:
	adds r2, r0, #0
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _080463CA
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _080463D0
_080463CA:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_080463D0:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _080463F8
	ldr r0, [r5, #8]
	movs r1, #4
	orrs r0, r1
	b _08046400
_080463F8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046400:
	str r0, [r5, #8]
	movs r5, #0
	movs r0, #1
	strb r0, [r6, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, r8
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r6, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08235f40
	strb r5, [r6, #0xa]
_0804642C:
	adds r2, r7, #0
	adds r2, #8
	mov r3, r8
	movs r0, #0x1c
	ldrsh r1, [r3, r0]
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r4, r1, r0
	mov r0, r8
	movs r3, #0x20
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046480 @ =0x000003FF
	adds r5, r2, #0
	cmp r1, r0
	bgt _08046484
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r7, #8]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	str r1, [r6, #0x10]
	movs r0, #0
	b _080465A0
	.align 2, 0
_08046480: .4byte 0x000003FF
_08046484:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _080464B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080464B4
	asrs r1, r0, #0xc
	b _080464BA
	.align 2, 0
_080464B0: .4byte 0x085B0A08
_080464B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080464BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080464D8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _080464DC
	asrs r0, r0, #0xc
	b _080464E2
	.align 2, 0
_080464D8: .4byte 0x085B0A08
_080464DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080464E2:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08236268
	ldrb r0, [r6, #7]
	ldr r2, _08046548 @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _0804654C @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046550
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804655A
	.align 2, 0
_08046548: .4byte 0x085AB424
_0804654C: .4byte 0x0000192C
_08046550:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804655A:
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _08046568
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804656E
_08046568:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_0804656E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046596
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _0804659E
_08046596:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804659E:
	str r1, [r5, #8]
_080465A0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080465b0
FUN_080465b0: @ 0x080465B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x60
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x18]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x1c]
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp, #0x20]
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080466D8
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _08046630 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, sl
	adds r7, r0, r2
	ldr r3, _08046634 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r6
	cmp r0, #1
	bhi _08046638
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _0804663E
	.align 2, 0
_08046630: .4byte 0x085AB414
_08046634: .4byte 0x0000192C
_08046638:
	adds r0, r5, #0
	adds r0, #0x2c
	strb r4, [r0]
_0804663E:
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _0804664E
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046654
_0804664E:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046654:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804667C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046684
_0804667C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046684:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	mov r2, sb
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r5, r3
	bl ParticleShadow_Show
	mov r4, r8
	adds r4, #8
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r5, #0
	adds r0, #0x28
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x30]
	ldrh r3, [r5, #0x32]
	ldr r0, [sp, #0x18]
	bl FUN_08234de8
	movs r6, #0xa6
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
_080466D8:
	ldr r0, [r5, #0x10]
	cmp r0, #0x77
	bls _08046772
	mov r1, sl
	ldr r0, [r1, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne _08046772
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0804671A
	mov r0, sl
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804671A
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046960
_0804671A:
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _08046772
	mov r3, sl
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08046772
	mov r2, sl
	adds r2, #0x20
	adds r3, r5, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r4, [r3]
	cmp r0, r4
	bne _08046748
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08046762
_08046748:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08046772
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08046772
_08046762:
	movs r0, #0
	strb r0, [r5, #0x1e]
	movs r1, #6
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r0, [r5, #0x10]
	b _08046960
_08046772:
	mov r6, sl
	ldr r2, [r6, #0x18]
	ldr r3, [r5, #0x3c]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804678A
	rsbs r1, r1, #0
_0804678A:
	cmp r1, r3
	bge _080467BC
	movs r0, #2
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467A0
	rsbs r1, r1, #0
_080467A0:
	cmp r1, #0xff
	bgt _080467BC
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r2, [sp, #0x20]
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467B6
	rsbs r1, r1, #0
_080467B6:
	movs r0, #1
	cmp r1, r3
	blt _080467BE
_080467BC:
	movs r0, #0
_080467BE:
	cmp r0, #0
	beq _080467D6
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046960
_080467D6:
	mov r2, r8
	adds r2, #8
	ldr r6, [sp, #0x1c]
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	mov r3, r8
	movs r4, #8
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x20
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046824 @ =0x000003FF
	adds r7, r2, #0
	cmp r1, r0
	bgt _08046828
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	mov r6, r8
	strh r0, [r6, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	adds r0, r5, #0
	bl FUN_080453b0
	movs r0, #0
	b _08046960
	.align 2, 0
_08046824: .4byte 0x000003FF
_08046828:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _080468BA
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046846
	movs r6, #0x10
_08046846:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	mov r2, r8
	strb r0, [r2, #5]
	add r3, sp, #0xc
	ldrb r4, [r2, #5]
	ldr r2, _08046874 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r2, r3, #0
	cmp r0, #0
	blt _08046878
	asrs r1, r0, #0xc
	b _0804687E
	.align 2, 0
_08046874: .4byte 0x085B0A08
_08046878:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804687E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046898 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _0804689C
	asrs r0, r0, #0xc
	b _080468A2
	.align 2, 0
_08046898: .4byte 0x085B0A08
_0804689C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080468A2:
	strh r0, [r3, #4]
	ldrh r0, [r2]
	mov r6, r8
	ldrh r6, [r6, #8]
	adds r0, r0, r6
	mov r1, r8
	strh r0, [r1, #8]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r2, [r1, #0xc]
	adds r0, r0, r2
	strh r0, [r1, #0xc]
_080468BA:
	ldr r0, [sp, #0x1c]
	adds r1, r7, #0
	bl FUN_08236268
	ldrb r0, [r5, #7]
	ldr r2, _08046908 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, sb
	lsls r0, r0, #5
	mov r3, sl
	adds r7, r0, r3
	ldr r4, _0804690C @ =0x0000192C
	adds r7, r7, r4
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046910
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804691A
	.align 2, 0
_08046908: .4byte 0x085AB414
_0804690C: .4byte 0x0000192C
_08046910:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804691A:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046928
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804692E
_08046928:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_0804692E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046956
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804695E
_08046956:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804695E:
	str r1, [r6, #8]
_08046960:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046970
FUN_08046970: @ 0x08046970
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	adds r5, r1, #0
	str r2, [sp, #0xc]
	adds r7, r5, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x68
	adds r1, r1, r5
	mov r8, r1
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _08046A60
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080469E0 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080469E4 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080469E8
	adds r0, r5, #0
	adds r0, #0x2c
	movs r4, #1
	b _080469EC
	.align 2, 0
_080469E0: .4byte 0x085AB414
_080469E4: .4byte 0x0000192C
_080469E8:
	adds r0, r5, #0
	adds r0, #0x2c
_080469EC:
	strb r4, [r0]
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _080469FE
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046A04
_080469FE:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046A04:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046A2C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046A34
_08046A2C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046A34:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, sl
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r5, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08235f40
	movs r0, #1
	strb r0, [r5, #0xa]
_08046A60:
	mov r6, sb
	ldr r0, [r6, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bne _08046A9C
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08046A9C
	mov r0, sb
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08046A9C
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046C88
_08046A9C:
	mov r3, sb
	ldr r2, [r3, #0x18]
	ldr r3, [r5, #0x3c]
	movs r4, #0
	ldrsh r1, [r2, r4]
	mov r6, r8
	movs r4, #0
	ldrsh r0, [r6, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AB4
	rsbs r1, r1, #0
_08046AB4:
	cmp r1, r3
	bge _08046AE6
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046ACA
	rsbs r1, r1, #0
_08046ACA:
	cmp r1, #0xff
	bgt _08046AE6
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, r8
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AE0
	rsbs r1, r1, #0
_08046AE0:
	movs r6, #1
	cmp r1, r3
	blt _08046AE8
_08046AE6:
	movs r6, #0
_08046AE8:
	cmp r6, #0
	beq _08046B00
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046C88
_08046B00:
	adds r2, r7, #0
	adds r2, #8
	mov r0, sl
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r4, r1, r0
	mov r0, sl
	movs r3, #0x20
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046B50 @ =0x000003FF
	str r2, [sp, #0x10]
	cmp r1, r0
	bgt _08046B54
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r7, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r6, [r5, #0x10]
	movs r0, #0
	b _08046C88
	.align 2, 0
_08046B50: .4byte 0x000003FF
_08046B54:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _08046BE0
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046B72
	movs r6, #0x10
_08046B72:
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _08046B9C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BA0
	asrs r1, r0, #0xc
	b _08046BA6
	.align 2, 0
_08046B9C: .4byte 0x085B0A08
_08046BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08046BA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046BC0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BC4
	asrs r0, r0, #0xc
	b _08046BCA
	.align 2, 0
_08046BC0: .4byte 0x085B0A08
_08046BC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08046BCA:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r6, [r7, #8]
	adds r0, r0, r6
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
_08046BE0:
	mov r0, sl
	ldr r1, [sp, #0x10]
	bl FUN_08236268
	ldrb r0, [r5, #7]
	ldr r2, _08046C30 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, r8
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _08046C34 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r4, #1
	mov r8, r4
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046C38
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _08046C42
	.align 2, 0
_08046C30: .4byte 0x085AB414
_08046C34: .4byte 0x0000192C
_08046C38:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08046C42:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046C50
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046C56
_08046C50:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046C56:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046C7E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08046C86
_08046C7E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046C86:
	str r1, [r6, #8]
_08046C88:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046c98
FUN_08046c98: @ 0x08046C98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08046CC0
	movs r0, #0
	strb r0, [r4, #5]
	strb r0, [r4, #8]
	adds r2, r4, #0
	adds r2, #0xa4
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Hide
_08046CC0:
	ldrh r1, [r4, #0x1c]
	cmp r1, #0
	bne _08046D6A
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	bne _08046D6E
	ldrb r1, [r5, #0x1e]
	adds r3, r5, #0
	adds r3, #0x20
	adds r6, r4, #0
	adds r6, #0x24
	cmp r1, #0
	beq _08046D1E
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046D1E
	ldrb r1, [r3]
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D04
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D04:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D1E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bls _08046D5A
_08046D1E:
	ldrb r3, [r3]
	ldrb r6, [r6]
	cmp r3, r6
	bne _08046D36
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D36:
	adds r1, r4, #0
	adds r1, #0x26
	cmp r3, r6
	bls _08046D44
	ldrb r2, [r1]
	cmp r3, r2
	blo _08046D5A
_08046D44:
	ldrb r1, [r1]
	cmp r3, r1
	bne _08046D6E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D6E
_08046D5A:
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08046D6E
_08046D6A:
	subs r1, #1
	strh r1, [r4, #0x1c]
_08046D6E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start EntityAB4E_Update
EntityAB4E_Update: @ 0x08046D74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	bl FUN_08018a08
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl GetHour
	adds r1, r7, #0
	adds r1, #0x20
	strb r0, [r1]
	bl GetMinute
	adds r1, r7, #0
	adds r1, #0x21
	strb r0, [r1]
	ldrb r1, [r7, #0x1f]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _08046DAE
	movs r0, #1
	b _08046DB0
_08046DAE:
	movs r0, #0
_08046DB0:
	strb r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r7, #0x1f]
	ldr r0, _08046E64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08046DCA
	b _08046FA8
_08046DCA:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r6, r7, r0
	movs r1, #0
	str r1, [sp, #0x10]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sl, r2
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r4, r7, r3
	adds r0, #0x37
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
_08046DF0:
	ldrb r0, [r6, #9]
	cmp r0, #0
	bne _08046DF8
	b _08046F76
_08046DF8:
	mov r2, r8
	str r2, [sp, #0x14]
	adds r3, r6, #0
	adds r3, #0xa4
	str r3, [sp, #0x18]
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	ldr r1, _08046E68 @ =0x085AB434
	ldrb r0, [r6, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x10]
	bl _call_via_r3
	ldrb r0, [r6, #4]
	mov r2, r8
	str r2, [sp, #0x20]
	mov r1, sb
	adds r3, r1, #0
	str r3, [sp, #0x1c]
	cmp r0, #8
	bne _08046E2E
	b _08046F70
_08046E2E:
	mov r0, r8
	bl FUN_0823b4b8
	adds r3, r6, #0
	adds r3, #0x68
	mov r2, r8
	ldrh r0, [r2, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08046E60
	cmp r1, #0
	blt _08046E60
	ldr r0, _08046E6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08046E60
	ldr r0, _08046E70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08046E74
_08046E60:
	movs r5, #0
	b _08046E82
	.align 2, 0
_08046E64: .4byte 0x030047A4
_08046E68: .4byte 0x085AB434
_08046E6C: .4byte 0x030046A8
_08046E70: .4byte 0x030046AC
_08046E74:
	ldr r0, _08046E98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08046E82:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x24]
	bl FUN_08234224
	ldr r3, [sp, #0x24]
	cmp r0, #0
	beq _08046E9C
	adds r0, #4
	b _08046EA8
	.align 2, 0
_08046E98: .4byte 0x030046A4
_08046E9C:
	ldr r0, _08046EBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08046EA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08046EC0
	cmp r2, #2
	beq _08046EC4
	b _08046EC8
	.align 2, 0
_08046EBC: .4byte 0x030046A4
_08046EC0:
	ldrb r0, [r3, #4]
	b _08046EC6
_08046EC4:
	ldrb r0, [r3]
_08046EC6:
	subs r1, r1, r0
_08046EC8:
	ldr r2, [sp, #0x14]
	strh r1, [r2, #0xa]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x20]
	str r1, [r3, #0x24]
	ldrb r1, [r6, #7]
	lsls r1, r1, #5
	ldr r0, _08046F30 @ =0x0000192C
	adds r1, r1, r0
	adds r1, r7, r1
	ldr r0, [sp, #0x18]
	bl MainSprite_AdvanceAnim
	ldr r0, _08046F34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08046F70
	ldr r1, [sp, #0x1c]
	ldrb r5, [r1]
	cmp r5, #0
	beq _08046F4A
	ldrh r5, [r4]
	cmp r5, #0
	bne _08046F38
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	mov ip, r3
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	mov r3, ip
	bl FUN_080da9c4
	str r0, [r4, #8]
	movs r0, #1
	strh r0, [r4]
	b _08046F70
	.align 2, 0
_08046F30: .4byte 0x0000192C
_08046F34: .4byte 0x030047A4
_08046F38:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046F70
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	b _08046F70
_08046F4A:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08046F70
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4, #8]
	strh r5, [r4]
_08046F70:
	ldr r0, [r6, #0x10]
	adds r0, #1
	str r0, [r6, #0x10]
_08046F76:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	add sl, r1
	adds r4, r4, r1
	add sb, r1
	add r8, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _08046F90
	b _08046DF0
_08046F90:
	ldr r0, _08046FBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08046FA2
	adds r0, r7, #0
	bl FUN_08045408
_08046FA2:
	ldr r0, [r7, #0x28]
	adds r0, #1
	str r0, [r7, #0x28]
_08046FA8:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08046FBC: .4byte 0x030044E0

	thumb_func_start EntityAB4E_Destroy
EntityAB4E_Destroy: @ 0x08046FC0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0
_08046FCC:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08046FDC
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080452f4
_08046FDC:
	adds r5, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _08046FCC
	ldr r1, _08046FF4 @ =0x030000C0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08046FF4: .4byte 0x030000C0

	thumb_func_start EntityAB4E_Init
EntityAB4E_Init: @ 0x08046FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0804703C @ =0x030000C0
	str r7, [r0]
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047054
	movs r0, #0x23
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x24
	adds r1, r1, r7
	mov sl, r1
	adds r2, r7, #0
	adds r2, #0x20
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x21
	str r3, [sp, #0x14]
	mov r4, sp
_0804702E:
	bl VM_GetPC
	cmp r0, #0
	beq _08047040
	bl Script_GetValue
	b _08047042
	.align 2, 0
_0804703C: .4byte 0x030000C0
_08047040:
	ldr r0, _08047050 @ =0x0000FFFF
_08047042:
	strh r0, [r4]
	adds r4, #2
	mov r0, sp
	adds r0, #0xe
	cmp r4, r0
	ble _0804702E
	b _08047082
	.align 2, 0
_08047050: .4byte 0x0000FFFF
_08047054:
	movs r4, #0x23
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x24
	adds r5, r5, r7
	mov sl, r5
	adds r0, r7, #0
	adds r0, #0x20
	str r0, [sp, #0x10]
	adds r1, r7, #0
	adds r1, #0x21
	str r1, [sp, #0x14]
	ldr r3, _080470D8 @ =0x0000FFFF
	adds r2, r3, #0
	mov r1, sp
	movs r6, #7
_08047074:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bge _08047074
_08047082:
	movs r0, #0
	mov r4, sb
	strb r0, [r4]
	movs r0, #0x68
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047158
	adds r5, r7, #0
	movs r0, #0x2c
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0xf
_0804709C:
	bl VM_GetPC
	cmp r0, #0
	beq _08047144
	bl Script_GetValue
	strh r0, [r5, #0x2c]
	bl Script_GetValue
	strh r0, [r5, #0x30]
	mov r3, r8
	ldrh r1, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080470D4
	cmp r1, #0
	blt _080470D4
	ldr r0, _080470DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080470D4
	ldr r0, _080470E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080470E4
_080470D4:
	movs r4, #0
	b _080470F2
	.align 2, 0
_080470D8: .4byte 0x0000FFFF
_080470DC: .4byte 0x030046A8
_080470E0: .4byte 0x030046AC
_080470E4:
	ldr r0, _08047108 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080470F2:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _0804710C
	adds r0, #4
	b _08047118
	.align 2, 0
_08047108: .4byte 0x030046A4
_0804710C:
	ldr r0, _0804712C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047118:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047130
	cmp r2, #2
	beq _08047134
	b _08047138
	.align 2, 0
_0804712C: .4byte 0x030046A4
_08047130:
	ldrb r0, [r3, #4]
	b _08047136
_08047134:
	ldrb r0, [r3]
_08047136:
	subs r1, r1, r0
_08047138:
	strh r1, [r5, #0x2e]
	mov r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804714A
_08047144:
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r0, [r5, #0x30]
_0804714A:
	adds r5, #8
	movs r2, #8
	add r8, r2
	subs r6, #1
	cmp r6, #0
	bge _0804709C
	b _0804716E
_08047158:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x2c
	movs r6, #0xf
_08047160:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047160
_0804716E:
	movs r0, #0
	mov r3, sl
	strb r0, [r3]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804723E
	adds r5, r7, #0
	adds r5, #0xac
	movs r6, #0xf
_08047184:
	bl VM_GetPC
	cmp r0, #0
	beq _08047228
	bl Script_GetValue
	strh r0, [r5]
	bl Script_GetValue
	strh r0, [r5, #4]
	adds r3, r5, #0
	ldrh r1, [r5]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080471BC
	cmp r1, #0
	blt _080471BC
	ldr r0, _080471C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080471BC
	ldr r0, _080471C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080471C8
_080471BC:
	movs r4, #0
	b _080471D6
	.align 2, 0
_080471C0: .4byte 0x030046A8
_080471C4: .4byte 0x030046AC
_080471C8:
	ldr r0, _080471EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080471D6:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _080471F0
	adds r0, #4
	b _080471FC
	.align 2, 0
_080471EC: .4byte 0x030046A4
_080471F0:
	ldr r0, _08047210 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080471FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047214
	cmp r2, #2
	beq _08047218
	b _0804721C
	.align 2, 0
_08047210: .4byte 0x030046A4
_08047214:
	ldrb r0, [r3, #4]
	b _0804721A
_08047218:
	ldrb r0, [r3]
_0804721A:
	subs r1, r1, r0
_0804721C:
	strh r1, [r5, #2]
	mov r4, sl
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804722E
_08047228:
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
_0804722E:
	adds r5, #8
	subs r6, #1
	cmp r6, #0
	bge _08047184
	b _08047254
_08047238:
	movs r0, #1
	rsbs r0, r0, #0
	b _080472BE
_0804723E:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0xac
	movs r6, #0xf
_08047246:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047246
_08047254:
	movs r4, #0
	strb r4, [r7, #0x1e]
	bl GetHour
	ldr r5, [sp, #0x10]
	strb r0, [r5]
	bl GetMinute
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	strb r0, [r7, #0x1f]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #0x1c]
	str r4, [r7, #0x28]
	movs r6, #0
	ldr r2, _080472D0 @ =0x0000192C
	adds r2, r2, r7
	mov r8, r2
_0804727E:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080472D4 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08047238
	mov r1, r8
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r5, #0x20
	add r8, r5
	adds r6, #1
	cmp r6, #7
	ble _0804727E
	ldr r0, _080472D8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080472DC @ =0x00001A2C
	adds r1, r7, r2
	str r0, [r1]
	adds r0, #0x2c
	str r0, [r7, #0x18]
	movs r0, #0
_080472BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080472D0: .4byte 0x0000192C
_080472D4: .4byte 0x0000CB05
_080472D8: .4byte 0x03002BE0
_080472DC: .4byte 0x00001A2C

	thumb_func_start EntityAB4E_Create
EntityAB4E_Create: @ 0x080472E0
	push {r4, lr}
	ldr r0, _08047314 @ =0x030000C0
	ldr r0, [r0]
	cmp r0, #0
	bne _08047326
	ldr r1, _08047318 @ =0x00001A30
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08047324
	ldr r1, _0804731C @ =EntityAB4E_Update
	ldr r2, _08047320 @ =EntityAB4E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityAB4E_Init
	cmp r0, #0
	bge _08047324
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08047326
	.align 2, 0
_08047314: .4byte 0x030000C0
_08047318: .4byte 0x00001A30
_0804731C: .4byte EntityAB4E_Update
_08047320: .4byte EntityAB4E_Destroy
_08047324:
	adds r0, r4, #0
_08047326:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804732c
FUN_0804732c: @ 0x0804732C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _08047354 @ =0x030000C0
	ldr r0, [r0]
	str r0, [sp, #0x20]
	cmp r0, #0
	beq _0804734E
	ldr r0, [sp, #0x20]
	bl FUN_080452cc
	adds r7, r0, #0
	cmp r7, #0
	bne _08047358
_0804734E:
	movs r0, #1
	rsbs r0, r0, #0
	b _080476F6
	.align 2, 0
_08047354: .4byte 0x030000C0
_08047358:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r7]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #2]
	movs r0, #0x6d
	movs r1, #2
	bl VM_GetKeywordValue
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r4, [r7, #0x10]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r7, #7]
	movs r0, #0x68
	movs r1, #4
	bl VM_GetKeywordValue
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	bl FUN_08045530
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0xb4
	strh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080473F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080473F0 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080473F4 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	adds r6, r0, #0
	b _08047420
	.align 2, 0
_080473F0: .4byte 0xFFFF0000
_080473F4: .4byte 0x0000FFFF
_080473F8:
	ldr r0, _0804745C @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08047460 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08047464 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r6, #0
_08047420:
	movs r0, #0x74
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047468
	movs r0, #1
	strb r0, [r7, #0x1f]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x26
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x27
	strb r0, [r1]
	b _08047484
	.align 2, 0
_0804745C: .4byte 0x030046A0
_08047460: .4byte 0xFFFF0000
_08047464: .4byte 0x0000FFFF
_08047468:
	strb r2, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #9
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x26
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x27
	strb r2, [r0]
_08047484:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804749A
	bl Script_GetValue
	str r0, [r7, #0x3c]
	bl Script_GetValue
	b _080474A4
_0804749A:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x3c]
	movs r0, #0x80
	lsls r0, r0, #2
_080474A4:
	str r0, [r7, #0x40]
	movs r0, #0x72
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _080474D8
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x28
	strb r0, [r4]
	bl Script_GetValue
	strh r0, [r7, #0x30]
	bl Script_GetValue
	strh r0, [r7, #0x32]
	bl Script_GetValue
	strh r0, [r7, #0x34]
	bl Script_GetValue
	str r0, [r7, #0x38]
	mov sb, r4
	b _080474EE
_080474D8:
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #0xff
	strb r0, [r1]
	strh r2, [r7, #0x30]
	strh r2, [r7, #0x32]
	movs r0, #8
	strh r0, [r7, #0x34]
	movs r0, #0xc
	str r0, [r7, #0x38]
	mov sb, r1
_080474EE:
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047516
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x29
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x2a
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x2b
	b _08047528
_08047516:
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #1
_08047528:
	strb r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047572
	movs r5, #0
	movs r0, #0x60
	adds r0, r0, r7
	mov sl, r0
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r1, #0x68
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x6a
	str r2, [sp, #0x24]
	adds r0, r7, #0
	adds r0, #0xa4
	str r0, [sp, #0x28]
	b _08047564
_08047554:
	bl Script_GetValue
	lsls r2, r5, #2
	adds r1, r7, #0
	adds r1, #0x48
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_08047564:
	cmp r5, #3
	bgt _080475A4
	bl VM_GetPC
	cmp r0, #0
	bne _08047554
	b _08047590
_08047572:
	movs r5, #0
	movs r1, #0x60
	adds r1, r1, r7
	mov sl, r1
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r2, #0x68
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x6a
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0xa4
	str r1, [sp, #0x28]
_08047590:
	cmp r5, #3
	bgt _080475A4
	movs r1, #0
	lsls r0, r5, #2
	adds r0, #0x48
	adds r0, r0, r7
_0804759C:
	stm r0!, {r1}
	adds r5, #1
	cmp r5, #3
	ble _0804759C
_080475A4:
	ldrh r1, [r7]
	lsrs r3, r4, #0x18
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, sl
	add r2, sp, #0x10
	bl FUN_0823b400
	ldr r1, _08047638 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x12
	str r0, [sp, #0x18]
	ldr r0, [r6, #4]
	ands r0, r1
	str r0, [r6, #4]
	mov r0, sl
	adds r1, r6, #0
	bl FUN_0823b47c
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08047608
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r2, [r2]
	ldrh r3, [r7, #0x30]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrh r0, [r7, #0x32]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	mov r0, sl
	bl FUN_0823b490
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	mov r0, r8
	movs r2, #0
	bl FUN_08234f80
	adds r0, r7, #0
	bl FUN_080453b0
_08047608:
	movs r0, #0
	strb r0, [r7, #0xc]
	mov r5, r8
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08047632
	cmp r1, #0
	blt _08047632
	ldr r0, _0804763C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08047632
	ldr r0, _08047640 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08047644
_08047632:
	movs r4, #0
	b _08047652
	.align 2, 0
_08047638: .4byte 0xFFFF0000
_0804763C: .4byte 0x030046A8
_08047640: .4byte 0x030046AC
_08047644:
	ldr r0, _08047664 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08047652:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08047668
	adds r0, #4
	b _08047674
	.align 2, 0
_08047664: .4byte 0x030046A4
_08047668:
	ldr r0, _08047688 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047674:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0804768C
	cmp r2, #2
	beq _08047690
	b _08047694
	.align 2, 0
_08047688: .4byte 0x030046A4
_0804768C:
	ldrb r0, [r5, #4]
	b _08047692
_08047690:
	ldrb r0, [r5]
_08047692:
	subs r1, r1, r0
_08047694:
	movs r6, #0
	movs r5, #0
	ldr r2, [sp, #0x24]
	strh r1, [r2]
	strb r6, [r7, #0x1b]
	ldr r0, [sp, #0x20]
	ldr r1, _08047708 @ =0x0000192C
	adds r4, r0, r1
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl MainSprite_Add
	ldr r1, _0804770C @ =0x085AB404
	ldrb r0, [r7, #7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	str r5, [sp]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	mov r0, sl
	bl FUN_08002a48
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Show
	strb r6, [r7, #8]
	movs r1, #1
	strb r1, [r7, #9]
_080476F6:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047708: .4byte 0x0000192C
_0804770C: .4byte 0x085AB404
