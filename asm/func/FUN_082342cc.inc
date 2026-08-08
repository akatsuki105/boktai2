	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r0, r1
	adds r0, #0x80
	mov sb, r0
	movs r2, #2
	ldrsh r6, [r4, r2]
	ands r6, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	ands r0, r1
	adds r0, #0x80
	mov r8, r0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823431E
	cmp r1, #0
	blt _0823431E
	ldr r0, _08234324 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823431E
	ldr r0, _08234328 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823432C
_0823431E:
	movs r5, #0
	b _0823433A
	.align 2, 0
_08234324: .4byte 0x030046A8
_08234328: .4byte 0x030046AC
_0823432C:
	ldr r0, _0823434C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0823433A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08234350
	adds r0, #4
	b _0823435C
	.align 2, 0
_0823434C: .4byte 0x030046A4
_08234350:
	ldr r0, _082343CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823435C:
	cmp r0, #0
	bne _08234362
	b _082345D8
_08234362:
	ldrb r0, [r0]
	movs r1, #0xf
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	movs r1, #0xff
	ldrb r0, [r4]
	cmp r0, r7
	bge _08234400
	ldrh r0, [r4, #4]
	ands r1, r0
	cmp r1, r7
	bge _08234380
	b _082345D8
_08234380:
	mov r1, sb
	lsls r0, r1, #0x10
	ldr r3, _082343D0 @ =0xFFFF0000
	lsls r1, r6, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	mov r1, r8
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _082343C6
	cmp r1, #0
	blt _082343C6
	ldr r0, _082343D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082343C6
	ldr r0, _082343D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082343DC
_082343C6:
	movs r4, #0
	b _082343EA
	.align 2, 0
_082343CC: .4byte 0x030046A4
_082343D0: .4byte 0xFFFF0000
_082343D4: .4byte 0x030046A8
_082343D8: .4byte 0x030046AC
_082343DC:
	ldr r0, _082343FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082343EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082343F8
	b _082345AE
_082343F8:
	b _082345B8
	.align 2, 0
_082343FC: .4byte 0x030046A4
_08234400:
	ldrh r0, [r4, #4]
	ands r1, r0
	cmp r1, r7
	bge _0823440A
	b _08234554
_0823440A:
	mov r1, sb
	adds r1, #0xff
	mov r0, sp
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r2, r8
	strh r2, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _0823443E
	cmp r2, #0
	blt _0823443E
	ldr r0, _08234444 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823443E
	ldr r0, _08234448 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _0823444C
_0823443E:
	movs r4, #0
	b _0823445A
	.align 2, 0
_08234444: .4byte 0x030046A8
_08234448: .4byte 0x030046AC
_0823444C:
	ldr r0, _0823446C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823445A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08234470
	adds r0, #4
	b _0823447C
	.align 2, 0
_0823446C: .4byte 0x030046A4
_08234470:
	ldr r0, _082344C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823447C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	bge _08234488
	b _082345CE
_08234488:
	mov r0, sp
	mov r1, sb
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r1, r8
	adds r1, #0xff
	strh r1, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r0, r1, #0x10
	asrs r2, r0, #0x18
	adds r5, r1, #0
	cmp r3, #0
	blt _082344BA
	cmp r2, #0
	blt _082344BA
	ldr r0, _082344C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082344BA
	ldr r0, _082344C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _082344CC
_082344BA:
	movs r4, #0
	b _082344DA
	.align 2, 0
_082344C0: .4byte 0x030046A4
_082344C4: .4byte 0x030046A8
_082344C8: .4byte 0x030046AC
_082344CC:
	ldr r0, _082344EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082344DA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082344F0
	adds r0, #4
	b _082344FC
	.align 2, 0
_082344EC: .4byte 0x030046A4
_082344F0:
	ldr r0, _08234548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082344FC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	blt _082345CE
	mov r0, sp
	strh r7, [r0]
	strh r6, [r0, #2]
	strh r5, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r0, r5, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	bge _0823451E
	b _082343C6
_0823451E:
	cmp r1, #0
	bge _08234524
	b _082343C6
_08234524:
	ldr r0, _0823454C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	blo _0823452E
	b _082343C6
_0823452E:
	ldr r0, _08234550 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234538
	b _082343C6
_08234538:
	ldr r0, _08234548 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
	b _082343EA
	.align 2, 0
_08234548: .4byte 0x030046A4
_0823454C: .4byte 0x030046A8
_08234550: .4byte 0x030046AC
_08234554:
	mov r1, sb
	adds r1, #0xff
	mov r0, sp
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r2, r8
	strh r2, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08234586
	cmp r1, #0
	blt _08234586
	ldr r0, _0823458C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08234586
	ldr r0, _08234590 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234594
_08234586:
	movs r4, #0
	b _082345A2
	.align 2, 0
_0823458C: .4byte 0x030046A8
_08234590: .4byte 0x030046AC
_08234594:
	ldr r0, _082345B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082345A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082345B8
_082345AE:
	adds r0, #4
	b _082345C4
	.align 2, 0
_082345B4: .4byte 0x030046A4
_082345B8:
	ldr r0, _082345D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082345C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	bge _082345D8
_082345CE:
	movs r0, #1
	b _082345DA
	.align 2, 0
_082345D4: .4byte 0x030046A4
_082345D8:
	movs r0, #0
_082345DA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
