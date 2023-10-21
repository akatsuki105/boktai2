	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080612d8
FUN_080612d8: @ 0x080612D8
	push {r4, lr}
	sub sp, #0x20
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08061324
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _0806131C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08061320 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _08061356
	.align 2, 0
_0806131C: .4byte 0xFFFF0000
_08061320: .4byte 0x0000FFFF
_08061324:
	ldr r0, [r1, #0x2c]
	ldr r1, [r1, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _0806137C @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08061380 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_08061356:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r1, #0
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806137C: .4byte 0x0000FFFF
_08061380: .4byte 0xFFFF0000

	thumb_func_start FUN_08061384
FUN_08061384: @ 0x08061384
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080613DC
	ldr r5, _080613BC @ =0x00000679
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r4, r0, #1
	strb r4, [r1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080613C0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080613DC
	.align 2, 0
_080613BC: .4byte 0x00000679
_080613C0:
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080613E4 @ =0x0000064C
	adds r1, r2, r3
	ldr r1, [r1]
	ldr r5, _080613E8 @ =0x0000067A
	adds r3, r2, r5
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1a
	ldrb r3, [r3]
	adds r2, r2, r3
	bl FUN_0822dafc
_080613DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080613E4: .4byte 0x0000064C
_080613E8: .4byte 0x0000067A

	thumb_func_start FUN_080613ec
FUN_080613ec: @ 0x080613EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r5, r4, r0
	cmp r2, #0
	beq _08061408
	ldr r2, _08061404 @ =0x0000067A
	adds r1, r4, r2
	movs r0, #0x48
	b _0806140E
	.align 2, 0
_08061404: .4byte 0x0000067A
_08061408:
	ldr r0, _0806144C @ =0x0000067A
	adds r1, r4, r0
	movs r0, #4
_0806140E:
	strb r0, [r1]
	ldr r1, _08061450 @ =0x0000064C
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0806144C @ =0x0000067A
	adds r0, r4, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08061454 @ =0x00000679
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806144C: .4byte 0x0000067A
_08061450: .4byte 0x0000064C
_08061454: .4byte 0x00000679

	thumb_func_start FUN_08061458
FUN_08061458: @ 0x08061458
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080614B0 @ =0x00001C1C
	bl FUN_0822b10c
	adds r1, r0, #0
	ldr r0, _080614B4 @ =0x0000064C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080614B8 @ =0x00000679
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080614B0: .4byte 0x00001C1C
_080614B4: .4byte 0x0000064C
_080614B8: .4byte 0x00000679

	thumb_func_start FUN_080614bc
FUN_080614bc: @ 0x080614BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080615AC
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	bne _080614DE
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080614F2
_080614DE:
	movs r4, #0xd0
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _08061608
_080614F2:
	ldr r1, _08061520 @ =0x000006A9
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	ldr r2, _08061524 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08061528
	asrs r1, r0, #0xc
	b _0806152E
	.align 2, 0
_08061520: .4byte 0x000006A9
_08061524: .4byte 0x085B0A08
_08061528:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806152E:
	ldrh r0, [r5, #0x2c]
	adds r0, r0, r1
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r1, r5, r4
	strh r0, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _0806154E
	asrs r0, r0, #0xc
	b _08061554
_0806154E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08061554:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r4, [r5, #0x2e]
	adds r0, r0, r4
	ldr r4, _08061584 @ =0x0000069A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08061588
	asrs r2, r0, #0xc
	b _0806158E
	.align 2, 0
_08061584: .4byte 0x0000069A
_08061588:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806158E:
	ldrh r0, [r5, #0x30]
	subs r0, r0, r2
	ldr r4, _080615A4 @ =0x0000069C
	adds r1, r5, r4
	strh r0, [r1]
	ldr r0, _080615A8 @ =0x000006A9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08061608
	.align 2, 0
_080615A4: .4byte 0x0000069C
_080615A8: .4byte 0x000006A9
_080615AC:
	ldr r7, [r5, #0x1c]
	cmp r7, #1
	bne _08061608
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08061608
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x38
	movs r4, #0
	strh r0, [r2]
	ldr r0, _08061610 @ =0x0000069A
	adds r1, r5, r0
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r2, _08061614 @ =0x0000067C
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r1, _08061618 @ =0x000006A9
	adds r0, r5, r1
	strb r4, [r0]
	strb r7, [r6]
_08061608:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061610: .4byte 0x0000069A
_08061614: .4byte 0x0000067C
_08061618: .4byte 0x000006A9

	thumb_func_start FUN_0806161c
FUN_0806161c: @ 0x0806161C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08061674 @ =0x00001C1C
	bl FUN_0822b10c
	adds r1, r0, #0
	ldr r0, _08061678 @ =0x0000067C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _0806167C @ =0x000006A9
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061674: .4byte 0x00001C1C
_08061678: .4byte 0x0000067C
_0806167C: .4byte 0x000006A9

	thumb_func_start FUN_08061680
FUN_08061680: @ 0x08061680
	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806168E
	b _080617B6
_0806168E:
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
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
	beq _080616C2
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	b _080616CC
_080616C2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080616CC:
	mov r2, ip
	str r0, [r2]
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
	beq _080616F4
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080616FE
_080616F4:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080616FE:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08061738 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806177E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08061742
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806173C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08061758
	.align 2, 0
_08061738: .4byte 0x0000FFFF
_0806173C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08061756
_08061742:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08061756
	strh r1, [r4, #8]
	movs r2, #1
	b _08061758
_08061756:
	movs r2, #0
_08061758:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08061780
	movs r0, #1
	strb r0, [r4, #7]
	b _08061780
_0806177E:
	movs r2, #0
_08061780:
	cmp r2, #0
	beq _0806179A
	mov r1, ip
	adds r1, #0x64
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080617B6
_0806179A:
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	mov r1, ip
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x1c]
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
_080617B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080617bc
FUN_080617bc: @ 0x080617BC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrb r0, [r1]
	cmp r0, #0
	beq _080617D0
	movs r0, #0
	strb r0, [r1]
	b _080617D8
_080617D0:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080617D8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080617dc
FUN_080617dc: @ 0x080617DC
	push {lr}
	adds r3, r0, #0
	movs r0, #3
	ands r0, r3
	cmp r0, #1
	beq _080617F8
	cmp r0, #1
	bgt _080617F2
	cmp r0, #0
	beq _080617F8
	b _080617F6
_080617F2:
	cmp r0, #2
	beq _080617F8
_080617F6:
	movs r0, #1
_080617F8:
	str r0, [r1]
	cmp r3, #2
	bhi _08061802
	movs r0, #0
	b _08061816
_08061802:
	subs r0, r3, #3
	cmp r0, #1
	bhi _0806180C
	movs r0, #2
	b _08061816
_0806180C:
	cmp r3, #5
	bne _08061814
	movs r0, #3
	b _08061816
_08061814:
	movs r0, #1
_08061816:
	str r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_0806181c
FUN_0806181c: @ 0x0806181C
	adds r1, r0, #0
	adds r1, #0xc2
	ldrh r2, [r1]
	ldr r3, _08061850 @ =0x000006DE
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _08061854 @ =0x000006E4
	adds r2, r0, r1
	adds r1, r0, #0
	adds r1, #0xd0
	ldr r1, [r1]
	str r1, [r2]
	ldr r1, _08061858 @ =0x000006AC
	adds r3, r0, r1
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08061850: .4byte 0x000006DE
_08061854: .4byte 0x000006E4
_08061858: .4byte 0x000006AC

	thumb_func_start FUN_0806185c
FUN_0806185c: @ 0x0806185C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _080618A8 @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r3, #0x1e]
	adds r0, #0xbe
	strh r0, [r3, #0x1e]
	ldr r2, _080618AC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080618B0
	asrs r1, r0, #0xc
	b _080618B6
	.align 2, 0
_080618A8: .4byte 0x000006AC
_080618AC: .4byte 0x085B0A08
_080618B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080618B6:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080618D2
	asrs r1, r0, #0xc
	b _080618D8
_080618D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080618D8:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080618FC
	asrs r1, r0, #0xc
	b _08061902
_080618FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061902:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061920
	asrs r2, r0, #0xc
	b _08061926
_08061920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061926:
	ldr r3, _08061964 @ =0x0000070C
	adds r0, r4, r3
	strh r2, [r0]
	add r2, sp, #8
	adds r0, r6, #0
	add r1, sp, #4
	bl FUN_080617dc
	ldr r7, _08061968 @ =0x000006F4
	adds r0, r4, r7
	ldr r2, _0806196C @ =0x00000704
	adds r1, r4, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_0806181c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061964: .4byte 0x0000070C
_08061968: .4byte 0x000006F4
_0806196C: .4byte 0x00000704

	thumb_func_start FUN_08061970
FUN_08061970: @ 0x08061970
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r1
	ldr r0, _08061988 @ =0x000006AC
	adds r4, r5, r0
	cmp r3, #0
	bne _0806198C
	movs r3, #0xa0
	movs r7, #0xe1
	lsls r7, r7, #1
	b _0806199C
	.align 2, 0
_08061988: .4byte 0x000006AC
_0806198C:
	cmp r3, #1
	bne _08061998
	movs r3, #0x8c
	movs r7, #0xa9
	lsls r7, r7, #1
	b _0806199C
_08061998:
	movs r3, #0x78
	movs r7, #0xe0
_0806199C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r6, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r3
	strh r0, [r4, #0x1e]
	ldr r2, _080619D8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _080619DC
	asrs r1, r0, #0xc
	b _080619E2
	.align 2, 0
_080619D8: .4byte 0x085B0A08
_080619DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080619E2:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080619FA
	asrs r1, r0, #0xc
	b _08061A00
_080619FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061A00:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061A24
	asrs r1, r0, #0xc
	b _08061A2A
_08061A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061A2A:
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061A48
	asrs r2, r0, #0xc
	b _08061A4E
_08061A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061A4E:
	ldr r3, _08061A8C @ =0x0000070C
	adds r0, r5, r3
	strh r2, [r0]
	add r2, sp, #8
	mov r0, ip
	add r1, sp, #4
	bl FUN_080617dc
	ldr r1, _08061A90 @ =0x000006F4
	adds r0, r5, r1
	ldr r2, _08061A94 @ =0x00000704
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #1
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0806181c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061A8C: .4byte 0x0000070C
_08061A90: .4byte 0x000006F4
_08061A94: .4byte 0x00000704

	thumb_func_start FUN_08061a98
FUN_08061a98: @ 0x08061A98
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08061AD8 @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r2, _08061ADC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _08061AE0
	asrs r1, r0, #0xc
	b _08061AE6
	.align 2, 0
_08061AD8: .4byte 0x000006AC
_08061ADC: .4byte 0x085B0A08
_08061AE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061AE6:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _08061B00
	asrs r1, r0, #0xc
	b _08061B06
_08061B00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061B06:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r2, [r0]
	ldr r6, _08061B40 @ =0x0000070C
	adds r0, r4, r6
	strh r2, [r0]
	ldr r1, _08061B44 @ =0x000006F4
	adds r0, r4, r1
	subs r3, #4
	adds r1, r4, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_0806181c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061B40: .4byte 0x0000070C
_08061B44: .4byte 0x000006F4

	thumb_func_start FUN_08061b48
FUN_08061b48: @ 0x08061B48
	push {r4, lr}
	ldr r1, _08061B8C @ =0x000006AC
	adds r4, r0, r1
	ldr r1, [r4]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r4]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r3, _08061B90 @ =0x000006CA
	adds r2, r0, r3
	ldrh r1, [r2]
	adds r1, #0xe6
	strh r1, [r2]
	ldr r2, _08061B94 @ =0x00000A8A
	adds r1, r0, r2
	ldrh r2, [r1]
	subs r3, #0x18
	adds r1, r0, r3
	strb r2, [r1]
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061B8C: .4byte 0x000006AC
_08061B90: .4byte 0x000006CA
_08061B94: .4byte 0x00000A8A

	thumb_func_start FUN_08061b98
FUN_08061b98: @ 0x08061B98
	push {lr}
	ldr r1, _08061BA8 @ =0x000006AC
	adds r0, r0, r1
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0
_08061BA8: .4byte 0x000006AC

	thumb_func_start FUN_08061bac
FUN_08061bac: @ 0x08061BAC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08061C00 @ =0x000006AC
	adds r4, r6, r0
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08061C10
	ldr r1, _08061C04 @ =0x00002110
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x7f
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, _08061C08 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _08061C0C @ =FUN_080617bc
	b _08061C3E
	.align 2, 0
_08061C00: .4byte 0x000006AC
_08061C04: .4byte 0x00002110
_08061C08: .4byte 0x00000714
_08061C0C: .4byte FUN_080617bc
_08061C10:
	ldr r1, _08061C50 @ =0x00008F5D
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x1d
	bl FUN_0822b20c
	ldr r0, _08061C54 @ =0x0000922E
	ldr r1, _08061C58 @ =0x00000837
	bl FUN_082310cc
	ldr r2, _08061C5C @ =0x00000704
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, _08061C60 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _08061C64 @ =FUN_08061680
_08061C3E:
	str r0, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061C50: .4byte 0x00008F5D
_08061C54: .4byte 0x0000922E
_08061C58: .4byte 0x00000837
_08061C5C: .4byte 0x00000704
_08061C60: .4byte 0x00000714
_08061C64: .4byte FUN_08061680

	thumb_func_start FUN_08061c68
FUN_08061c68: @ 0x08061C68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _08061CC0 @ =0x0000071C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061D10
	movs r2, #0
	mov r8, r2
	movs r7, #0
_08061C80:
	movs r0, #0x34
	adds r1, r7, #0
	muls r1, r0, r1
	adds r0, r5, r1
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061CFE
	subs r2, #0x30
	adds r0, r1, r2
	adds r3, r5, r0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strb r2, [r1]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _08061CC4
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x30
	strb r6, [r0]
	b _08061CFE
	.align 2, 0
_08061CC0: .4byte 0x0000071C
_08061CC4:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08061CE2
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_08061CE2:
	ldrh r0, [r4, #0x28]
	ldrh r2, [r4, #0x18]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r0, #1
	add r8, r0
_08061CFE:
	adds r7, #1
	cmp r7, #5
	ble _08061C80
	mov r1, r8
	cmp r1, #0
	bne _08061D10
	ldr r2, _08061D1C @ =0x0000071C
	adds r0, r5, r2
	strb r1, [r0]
_08061D10:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061D1C: .4byte 0x0000071C

	thumb_func_start FUN_08061d20
FUN_08061d20: @ 0x08061D20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, _08061DAC @ =0x0000071D
	adds r7, r5, r0
	ldrb r1, [r7]
	movs r0, #0x34
	adds r4, r1, #0
	muls r4, r0, r4
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r3, r3, #1
	adds r3, #2
	adds r2, r4, #0
	adds r2, #0x32
	movs r0, #0
	mov sb, r0
	strb r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sb
	strb r1, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r2, _08061DB0 @ =0x0000071C
	adds r5, r5, r2
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08061DA0
	strb r1, [r7]
_08061DA0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061DAC: .4byte 0x0000071D
_08061DB0: .4byte 0x0000071C

	thumb_func_start FUN_08061db4
FUN_08061db4: @ 0x08061DB4
	push {r4, r5, lr}
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_08061DBE:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _08061DBE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08061dd4
FUN_08061dd4: @ 0x08061DD4
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r5, r0, r1
	ldr r0, _08061E28 @ =0x00001C1E
	bl FUN_0822b10c
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_08061DEA:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #5
	ble _08061DEA
	movs r0, #0
	strb r0, [r5, #4]
	strb r0, [r5, #5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061E28: .4byte 0x00001C1E

	thumb_func_start FUN_08061e2c
FUN_08061e2c: @ 0x08061E2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _08061E94 @ =0x0000085C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08061E44
	b _08061F56
_08061E44:
	movs r2, #0
	mov sb, r2
	movs r7, #0
	ldr r0, _08061E98 @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
_08061E52:
	movs r0, #0x34
	muls r0, r7, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r4, r6, r0
	adds r2, r4, #0
	adds r2, #0x28
	ldrb r0, [r2]
	cmp r0, #0
	beq _08061F44
	adds r5, r4, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08061E74
	rsbs r0, r0, #0
_08061E74:
	cmp r0, #0xf
	bgt _08061E9C
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _08061E82
	rsbs r0, r0, #0
_08061E82:
	cmp r0, #0xf
	bgt _08061E9C
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
	b _08061F44
	.align 2, 0
_08061E94: .4byte 0x0000085C
_08061E98: .4byte 0x085B0A08
_08061E9C:
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r3, r0, #0
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	mov ip, r0
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08061ED0
	asrs r2, r0, #0xc
	b _08061ED6
_08061ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061ED6:
	ldrh r0, [r4, #0x2c]
	subs r0, r0, r2
	strh r0, [r4, #0x2c]
	ldrb r1, [r1]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08061EF4
	asrs r1, r0, #0xc
	b _08061EFA
_08061EF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061EFA:
	ldrh r0, [r4, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldr r2, _08061F64 @ =0x00000934
	adds r1, r6, r2
	ldrh r0, [r4, #0x30]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r1, r8
	ands r0, r1
	cmp r0, #4
	bne _08061F40
	subs r2, #0xdc
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_08061F40:
	movs r0, #1
	add sb, r0
_08061F44:
	adds r7, #1
	cmp r7, #3
	ble _08061E52
	mov r1, sb
	cmp r1, #0
	bne _08061F56
	ldr r2, _08061F68 @ =0x0000085C
	adds r0, r6, r2
	strb r1, [r0]
_08061F56:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061F64: .4byte 0x00000934
_08061F68: .4byte 0x0000085C

	thumb_func_start FUN_08061f6c
FUN_08061f6c: @ 0x08061F6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	ldr r0, _08062014 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08062018 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _0806201C @ =0x0000085E
	adds r1, r7, r3
	adds r0, #2
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _08061F9A
	b _080620CC
_08061F9A:
	subs r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r6, r7, r0
	mov r8, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08062020 @ =0x00000858
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r3, _08062024 @ =0x0203B400
	mov ip, r3
	ldr r3, _08062028 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0806202C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x80
	ldr r1, _08062030 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08062034
	asrs r0, r0, #0xc
	b _0806203A
	.align 2, 0
_08062014: .4byte 0x030046A0
_08062018: .4byte 0x00000942
_0806201C: .4byte 0x0000085E
_08062020: .4byte 0x00000858
_08062024: .4byte 0x0203B400
_08062028: .4byte 0x030046B8
_0806202C: .4byte 0x000003FF
_08062030: .4byte 0x085B0A08
_08062034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806203A:
	strh r0, [r6, #0x2c]
	ldr r0, _08062050 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08062054
	asrs r0, r0, #0xc
	b _0806205A
	.align 2, 0
_08062050: .4byte 0x085B0A08
_08062054:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806205A:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, _080620D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080620DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080620E0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #0xe
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080620E4 @ =0x0000085D
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080620BC
	strb r3, [r1]
_080620BC:
	ldr r1, _080620E8 @ =0x0000085E
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r1, #0x28
	strb r1, [r0]
	ldr r3, _080620EC @ =0x0000085C
	adds r0, r7, r3
	strb r2, [r0]
_080620CC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080620D8: .4byte 0x030046B8
_080620DC: .4byte 0x000003FF
_080620E0: .4byte 0x0203B400
_080620E4: .4byte 0x0000085D
_080620E8: .4byte 0x0000085E
_080620EC: .4byte 0x0000085C

	thumb_func_start FUN_080620f0
FUN_080620f0: @ 0x080620F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r1, _08062190 @ =0x0000085E
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08062114
	b _08062236
_08062114:
	ldr r0, _08062194 @ =0x0000085D
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r2, r8
	adds r6, r2, r0
	adds r7, r6, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08062198 @ =0x00000858
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r3, _0806219C @ =0x0203B400
	mov ip, r3
	ldr r3, _080621A0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080621A4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r1, #0x81
	adds r2, r0, r1
	ldr r1, _080621A8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080621AC
	asrs r0, r0, #0xc
	b _080621B2
	.align 2, 0
_08062190: .4byte 0x0000085E
_08062194: .4byte 0x0000085D
_08062198: .4byte 0x00000858
_0806219C: .4byte 0x0203B400
_080621A0: .4byte 0x030046B8
_080621A4: .4byte 0x000003FF
_080621A8: .4byte 0x085B0A08
_080621AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080621B2:
	strh r0, [r6, #0x2c]
	ldr r0, _080621C8 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080621CC
	asrs r0, r0, #0xc
	b _080621D2
	.align 2, 0
_080621C8: .4byte 0x085B0A08
_080621CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080621D2:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldr r2, _08062244 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08062248 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806224C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _08062250 @ =0x0000085C
	add r0, r8
	strb r1, [r0]
	ldr r1, _08062254 @ =0x0000085D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08062236
	strb r3, [r1]
_08062236:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062244: .4byte 0x030046B8
_08062248: .4byte 0x000003FF
_0806224C: .4byte 0x0203B400
_08062250: .4byte 0x0000085C
_08062254: .4byte 0x0000085D

	thumb_func_start FUN_08062258
FUN_08062258: @ 0x08062258
	push {r4, r5, lr}
	movs r1, #0x86
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #3
_08062262:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _08062262
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08062278
FUN_08062278: @ 0x08062278
	push {r4, r5, r6, r7, lr}
	ldr r1, _080622C8 @ =0x00000858
	adds r5, r0, r1
	ldr r0, _080622CC @ =0x00001C1E
	bl FUN_0822b10c
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_0806228C:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #3
	ble _0806228C
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080622C8: .4byte 0x00000858
_080622CC: .4byte 0x00001C1E

	thumb_func_start FUN_080622d0
FUN_080622d0: @ 0x080622D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r2, _08062328 @ =0x03003584
	ldr r1, _0806232C @ =0x0000094C
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r4, _08062330 @ =0x00000938
	adds r0, r3, r4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r0, _08062334 @ =0x0000094E
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08062354
	ldr r1, _08062338 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806233C
	movs r5, #0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r3, r2
_0806230E:
	subs r0, r5, #5
	cmp r0, #1
	bls _0806231C
	cmp r5, #0xd
	beq _0806231C
	ldrh r0, [r6]
	strh r0, [r1]
_0806231C:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _0806230E
	b _08062412
	.align 2, 0
_08062328: .4byte 0x03003584
_0806232C: .4byte 0x0000094C
_08062330: .4byte 0x00000938
_08062334: .4byte 0x0000094E
_08062338: .4byte 0x00000359
_0806233C:
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r5, #0xf
_08062344:
	ldrh r0, [r6]
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _08062344
	b _08062412
_08062354:
	ldr r2, _080623BC @ =0x00000359
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080623C0
	movs r5, #0
	mov r8, r1
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r7, r3, r4
_08062368:
	subs r0, r5, #5
	cmp r0, #1
	bls _080623B0
	cmp r5, #0xd
	beq _080623B0
	ldrh r1, [r6]
	movs r0, #0x1f
	mov ip, r0
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08062388
	movs r4, #0x1f
_08062388:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08062398
	movs r1, #0x1f
_08062398:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080623A6
	movs r0, #0x1f
_080623A6:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_080623B0:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _08062368
	b _08062412
	.align 2, 0
_080623BC: .4byte 0x00000359
_080623C0:
	movs r4, #0x1f
	mov ip, r4
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r3, r0
	movs r5, #0xf
_080623CE:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080623E0
	movs r4, #0x1f
_080623E0:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080623F0
	movs r1, #0x1f
_080623F0:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080623FE
	movs r0, #0x1f
_080623FE:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	subs r5, #1
	cmp r5, #0
	bge _080623CE
_08062412:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806241c
FUN_0806241c: @ 0x0806241C
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _08062438 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0806243C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08062440
	movs r0, #1
	b _08062442
	.align 2, 0
_08062438: .4byte 0x030046A0
_0806243C: .4byte 0x00000934
_08062440:
	movs r0, #0
_08062442:
	cmp r0, #0
	bne _08062454
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062460
	movs r3, #8
	b _08062460
_08062454:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062460
	movs r3, #4
_08062460:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08062468
FUN_08062468: @ 0x08062468
	push {r4, lr}
	ldr r1, _080624A4 @ =0x03003584
	ldr r2, [r1]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r2, r2, r1
	movs r3, #0x95
	lsls r3, r3, #4
	adds r1, r0, r3
	ldrb r3, [r1]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r3, [r2]
	ldr r4, _080624A8 @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080624AC @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080624A4: .4byte 0x03003584
_080624A8: .4byte 0x000002AE
_080624AC: .4byte 0x000002BE

	thumb_func_start FUN_080624b0
FUN_080624b0: @ 0x080624B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	mov ip, r2
	mov sb, r3
	cmp r2, #0
	bne _080624F2
	ldr r0, _080624E0 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080624E4
	mov r1, sl
	adds r1, #0xd0
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	b _08062672
	.align 2, 0
_080624E0: .4byte 0x00000359
_080624E4:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	b _0806266E
_080624F2:
	mov r8, r1
	ldr r0, _08062528 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080625C8
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0xd0
	str r1, [sp, #0xc]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
	ldr r2, _0806252C @ =0x0000094E
	add r2, sl
	str r2, [sp, #4]
_08062514:
	ldr r0, [sp]
	subs r0, #5
	cmp r0, #1
	bls _08062522
	ldr r3, [sp]
	cmp r3, #0xd
	bne _08062530
_08062522:
	ldrh r0, [r6]
	b _080625AA
	.align 2, 0
_08062528: .4byte 0x00000359
_0806252C: .4byte 0x0000094E
_08062530:
	mov r4, r8
	ldrh r2, [r4]
	movs r7, #0x1f
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #4]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08062546
	movs r4, #0x1f
_08062546:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _08062554
	movs r2, #0x1f
_08062554:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _08062560
	movs r5, #0x1f
_08062560:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	adds r4, r4, r0
	ldr r0, [sp, #0x34]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x34]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080625AA:
	strh r0, [r6, #0x20]
	movs r0, #2
	add r8, r0
	adds r6, #2
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	ble _08062514
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, sl
	ldr r2, [sp, #0xc]
	str r0, [r2]
	b _08062672
_080625C8:
	movs r3, #0
	str r3, [sp]
	ldr r4, _08062684 @ =0x0000094E
	add r4, sl
	str r4, [sp, #8]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
_080625D8:
	mov r7, r8
	ldrh r2, [r7]
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080625EC
	movs r4, #0x1f
_080625EC:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	movs r7, #0x1f
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080625FC
	movs r2, #0x1f
_080625FC:
	lsrs r0, r3, #0x1a
	movs r3, #0x1f
	ands r0, r3
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0806260A
	movs r5, #0x1f
_0806260A:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	movs r7, #0x1f
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r7, r0
	ldr r7, [sp, #0x34]
	asrs r4, r7
	mov r0, ip
	muls r0, r2, r0
	adds r2, r0, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	asrs r2, r7
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
	strh r0, [r6, #0x20]
	movs r4, #2
	add r8, r4
	adds r6, #2
	ldr r7, [sp]
	adds r7, #1
	str r7, [sp]
	cmp r7, #0xf
	ble _080625D8
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xb1
	lsls r0, r0, #2
_0806266E:
	add r0, sl
	str r0, [r1, #0xc]
_08062672:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062684: .4byte 0x0000094E

	thumb_func_start FUN_08062688
FUN_08062688: @ 0x08062688
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _08062710 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080626AA
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08062468
_080626AA:
	adds r0, r5, #0
	bl FUN_0806241c
	adds r2, r0, #0
	ldr r6, _08062714 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _080626C8
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _080626D6
_080626C8:
	strh r4, [r1]
	ldr r1, _08062718 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080622d0
_080626D6:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r4, [r2]
	cmp r4, #0
	beq _080626E4
	b _0806281A
_080626E4:
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _08062770
	ldr r6, _0806271C @ =0x00000121
	adds r0, r0, r6
	ldr r2, _08062720 @ =0x00000962
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _08062724 @ =0x03003584
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r3, _08062728 @ =0x00000964
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _0806272C
	adds r2, r1, #0
	b _08062742
	.align 2, 0
_08062710: .4byte 0x00000951
_08062714: .4byte 0x0000094C
_08062718: .4byte 0x0000094E
_0806271C: .4byte 0x00000121
_08062720: .4byte 0x00000962
_08062724: .4byte 0x03003584
_08062728: .4byte 0x00000964
_0806272C:
	cmp r1, #0x2f
	bhi _08062734
	movs r2, #0x20
	b _08062742
_08062734:
	cmp r1, #0x4f
	bhi _08062740
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _08062742
_08062740:
	movs r2, #0
_08062742:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080624b0
	ldr r6, _0806276C @ =0x00000964
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _08062766
	b _080628DC
_08062766:
	movs r0, #0
	b _080628DA
	.align 2, 0
_0806276C: .4byte 0x00000964
_08062770:
	ldr r0, _080627AC @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _080627DE
	ldr r1, _080627B0 @ =0x03003584
	ldr r6, _080627B4 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0806279E
	movs r0, #0x30
	strh r0, [r3]
_0806279E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _080627B8
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080627CC
	.align 2, 0
_080627AC: .4byte 0x00000964
_080627B0: .4byte 0x03003584
_080627B4: .4byte 0x00000962
_080627B8:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080627CC
	strh r4, [r3]
_080627CC:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080624b0
	b _080628DC
_080627DE:
	ldr r1, _08062800 @ =0x00000962
	adds r0, r5, r1
	strh r4, [r0]
	strh r4, [r3]
	ldr r2, _08062804 @ =0x00000359
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062808
	adds r1, r5, #0
	adds r1, #0xd0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r0, r5, r3
	str r0, [r1]
	b _080628DC
	.align 2, 0
_08062800: .4byte 0x00000962
_08062804: .4byte 0x00000359
_08062808:
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080628DC
_0806281A:
	ldr r3, _08062860 @ =0x00000964
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _080628B2
	ldr r1, _08062864 @ =0x03003584
	ldr r6, _08062868 @ =0x0000095E
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r2, _0806286C @ =0x00000359
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806288A
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062850:
	subs r0, r3, #5
	cmp r0, #1
	bls _0806285A
	cmp r3, #0xd
	bne _08062870
_0806285A:
	ldrh r0, [r4]
	b _08062872
	.align 2, 0
_08062860: .4byte 0x00000964
_08062864: .4byte 0x03003584
_08062868: .4byte 0x0000095E
_0806286C: .4byte 0x00000359
_08062870:
	ldrh r0, [r1]
_08062872:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062850
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _080628D0
_0806288A:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_08062892:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08062892
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080628D0
_080628B2:
	ldr r1, _080628E4 @ =0x03003584
	ldr r3, _080628E8 @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
_080628D0:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
_080628DA:
	strh r0, [r1]
_080628DC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080628E4: .4byte 0x03003584
_080628E8: .4byte 0x0000095E

	thumb_func_start FUN_080628ec
FUN_080628ec: @ 0x080628EC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _08062990 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _0806290E
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08062468
_0806290E:
	adds r0, r5, #0
	bl FUN_0806241c
	adds r2, r0, #0
	ldr r6, _08062994 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _0806292C
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0806293A
_0806292C:
	strh r4, [r1]
	ldr r1, _08062998 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080622d0
_0806293A:
	ldr r2, _0806299C @ =0x0000096C
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _08062A1C
	ldr r3, _080629A0 @ =0x00000964
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r6, #0x96
	lsls r6, r6, #4
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0x1f
	bls _080629EC
	ldr r1, _080629A4 @ =0x03003584
	subs r2, #0xe
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _080629A8 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080629C6
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062980:
	subs r0, r3, #5
	cmp r0, #1
	bls _0806298A
	cmp r3, #0xd
	bne _080629AC
_0806298A:
	ldrh r0, [r4]
	b _080629AE
	.align 2, 0
_08062990: .4byte 0x00000951
_08062994: .4byte 0x0000094C
_08062998: .4byte 0x0000094E
_0806299C: .4byte 0x0000096C
_080629A0: .4byte 0x00000964
_080629A4: .4byte 0x03003584
_080629A8: .4byte 0x00000359
_080629AC:
	ldrh r0, [r1]
_080629AE:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062980
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _08062C0C
_080629C6:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_080629CE:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _080629CE
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	b _08062C0A
_080629EC:
	ldr r1, _08062A14 @ =0x03003584
	ldr r3, _08062A18 @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r4]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08062C0C
	.align 2, 0
_08062A14: .4byte 0x03003584
_08062A18: .4byte 0x0000095E
_08062A1C:
	cmp r0, #2
	bne _08062A96
	ldr r6, _08062A48 @ =0x00000964
	adds r1, r5, r6
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08062A4C @ =0x03003584
	ldr r2, _08062A50 @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r4, r1, r0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08062A54
	adds r2, r1, #0
	b _08062A6A
	.align 2, 0
_08062A48: .4byte 0x00000964
_08062A4C: .4byte 0x03003584
_08062A50: .4byte 0x0000095E
_08062A54:
	cmp r1, #0x2f
	bhi _08062A5C
	movs r2, #0x20
	b _08062A6A
_08062A5C:
	cmp r1, #0x4f
	bhi _08062A68
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _08062A6A
_08062A68:
	movs r2, #0
_08062A6A:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080624b0
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _08062A90
	b _08062C0C
_08062A90:
	movs r0, #0
	strh r0, [r1]
	b _08062C0C
_08062A96:
	movs r0, #0x96
	lsls r0, r0, #4
	adds r2, r5, r0
	ldrh r4, [r2]
	cmp r4, #0
	beq _08062B70
	ldr r1, _08062AE8 @ =0x00000964
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08062B3A
	ldr r1, _08062AEC @ =0x03003584
	ldr r2, _08062AF0 @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _08062AF4 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062B12
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_08062AD8:
	subs r0, r3, #5
	cmp r0, #1
	bls _08062AE2
	cmp r3, #0xd
	bne _08062AF8
_08062AE2:
	ldrh r0, [r4]
	b _08062AFA
	.align 2, 0
_08062AE8: .4byte 0x00000964
_08062AEC: .4byte 0x03003584
_08062AF0: .4byte 0x0000095E
_08062AF4: .4byte 0x00000359
_08062AF8:
	ldrh r0, [r1]
_08062AFA:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08062AD8
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _08062B58
_08062B12:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_08062B1A:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08062B1A
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _08062B58
_08062B3A:
	ldr r1, _08062B68 @ =0x03003584
	ldr r3, _08062B6C @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080624b0
_08062B58:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08062C0C
	.align 2, 0
_08062B68: .4byte 0x03003584
_08062B6C: .4byte 0x0000095E
_08062B70:
	ldr r0, _08062BAC @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08062BDE
	ldr r1, _08062BB0 @ =0x03003584
	ldr r6, _08062BB4 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08062B9E
	movs r0, #0x30
	strh r0, [r3]
_08062B9E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _08062BB8
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _08062BCC
	.align 2, 0
_08062BAC: .4byte 0x00000964
_08062BB0: .4byte 0x03003584
_08062BB4: .4byte 0x00000962
_08062BB8:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _08062BCC
	strh r4, [r3]
_08062BCC:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080624b0
	b _08062C0C
_08062BDE:
	strh r4, [r3]
	ldr r1, _08062BF8 @ =0x00000359
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062BFC
	adds r1, r5, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	b _08062C0C
	.align 2, 0
_08062BF8: .4byte 0x00000359
_08062BFC:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r5, r6
_08062C0A:
	str r0, [r1, #0xc]
_08062C0C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08062c14
FUN_08062c14: @ 0x08062C14
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x18]
	cmp r0, #0
	bne _08062C2C
	ldr r0, _08062C28 @ =0x0000094A
	adds r1, r1, r0
	movs r0, #0x1d
	b _08062C32
	.align 2, 0
_08062C28: .4byte 0x0000094A
_08062C2C:
	ldr r0, _08062C38 @ =0x0000094A
	adds r1, r1, r0
	movs r0, #0x28
_08062C32:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08062C38: .4byte 0x0000094A

	thumb_func_start FUN_08062c3c
FUN_08062c3c: @ 0x08062C3C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08062C4E
	b _08063064
_08062C4E:
	lsls r0, r0, #2
	ldr r1, _08062C58 @ =_08062C5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062C58: .4byte _08062C5C
_08062C5C: @ jump table
	.4byte _08062C74 @ case 0
	.4byte _08062D40 @ case 1
	.4byte _08062E0C @ case 2
	.4byte _08062EE0 @ case 3
	.4byte _08062FAC @ case 4
	.4byte _08063020 @ case 5
_08062C74:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062C94
	ldr r5, _08062C90 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062CEA
	.align 2, 0
_08062C90: .4byte 0x00000938
_08062C94:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062CB0
	ldr r0, _08062CA8 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062CAC @ =0x00000129
	b _08062CEA
	.align 2, 0
_08062CA8: .4byte 0x00000938
_08062CAC: .4byte 0x00000129
_08062CB0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062CC8
	ldr r2, _08062CC4 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062CEA
	.align 2, 0
_08062CC4: .4byte 0x00000938
_08062CC8:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062CE4
	ldr r5, _08062CDC @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062CE0 @ =0x0000012B
	b _08062CEA
	.align 2, 0
_08062CDC: .4byte 0x00000938
_08062CE0: .4byte 0x0000012B
_08062CE4:
	ldr r0, _08062D24 @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x1d
_08062CEA:
	strh r0, [r1]
	ldr r2, _08062D28 @ =0x0000093A
	adds r1, r4, r2
	ldr r0, _08062D2C @ =0x00000121
	strh r0, [r1]
	ldr r5, _08062D30 @ =0x0000093C
	adds r1, r4, r5
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _08062D34 @ =0x0000093E
	adds r1, r4, r0
	ldr r0, _08062D38 @ =0x00000123
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	adds r0, #1
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	movs r0, #0x1f
	strh r0, [r1]
	ldr r0, _08062D3C @ =0x00000944
	adds r1, r4, r0
	movs r0, #0x21
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	b _08063060
	.align 2, 0
_08062D24: .4byte 0x00000938
_08062D28: .4byte 0x0000093A
_08062D2C: .4byte 0x00000121
_08062D30: .4byte 0x0000093C
_08062D34: .4byte 0x0000093E
_08062D38: .4byte 0x00000123
_08062D3C: .4byte 0x00000944
_08062D40:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062D60
	ldr r0, _08062D5C @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062DB6
	.align 2, 0
_08062D5C: .4byte 0x00000938
_08062D60:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062D7C
	ldr r2, _08062D74 @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062D78 @ =0x00000129
	b _08062DB6
	.align 2, 0
_08062D74: .4byte 0x00000938
_08062D78: .4byte 0x00000129
_08062D7C:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062D94
	ldr r5, _08062D90 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062DB6
	.align 2, 0
_08062D90: .4byte 0x00000938
_08062D94:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062DB0
	ldr r0, _08062DA8 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062DAC @ =0x0000012B
	b _08062DB6
	.align 2, 0
_08062DA8: .4byte 0x00000938
_08062DAC: .4byte 0x0000012B
_08062DB0:
	ldr r2, _08062DF0 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x26
_08062DB6:
	strh r0, [r1]
	ldr r5, _08062DF4 @ =0x0000093A
	adds r1, r4, r5
	ldr r0, _08062DF8 @ =0x00000121
	strh r0, [r1]
	ldr r0, _08062DFC @ =0x0000093C
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _08062E00 @ =0x0000093E
	adds r1, r4, r2
	ldr r0, _08062E04 @ =0x00000123
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062E08 @ =0x00000942
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x21
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	b _08063060
	.align 2, 0
_08062DF0: .4byte 0x00000938
_08062DF4: .4byte 0x0000093A
_08062DF8: .4byte 0x00000121
_08062DFC: .4byte 0x0000093C
_08062E00: .4byte 0x0000093E
_08062E04: .4byte 0x00000123
_08062E08: .4byte 0x00000942
_08062E0C:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062E30
	ldr r5, _08062E28 @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062E2C @ =0x0000026F
	b _08062E86
	.align 2, 0
_08062E28: .4byte 0x00000938
_08062E2C: .4byte 0x0000026F
_08062E30:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062E48
	ldr r0, _08062E44 @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x9c
	lsls r0, r0, #2
	b _08062E86
	.align 2, 0
_08062E44: .4byte 0x00000938
_08062E48:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062E64
	ldr r2, _08062E5C @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062E60 @ =0x0000026E
	b _08062E86
	.align 2, 0
_08062E5C: .4byte 0x00000938
_08062E60: .4byte 0x0000026E
_08062E64:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062E80
	ldr r5, _08062E78 @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062E7C @ =0x00000271
	b _08062E86
	.align 2, 0
_08062E78: .4byte 0x00000938
_08062E7C: .4byte 0x00000271
_08062E80:
	ldr r0, _08062EC4 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062EC8 @ =0x00000266
_08062E86:
	strh r0, [r1]
	ldr r2, _08062ECC @ =0x0000093A
	adds r1, r4, r2
	ldr r0, _08062ED0 @ =0x0000026D
	strh r0, [r1]
	ldr r5, _08062ED4 @ =0x0000093C
	adds r1, r4, r5
	subs r0, #2
	strh r0, [r1]
	ldr r0, _08062ED8 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x9a
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	adds r0, #1
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062EDC @ =0x00000944
	adds r1, r4, r0
	movs r0, #0x9b
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	subs r0, #5
	b _08063062
	.align 2, 0
_08062EC4: .4byte 0x00000938
_08062EC8: .4byte 0x00000266
_08062ECC: .4byte 0x0000093A
_08062ED0: .4byte 0x0000026D
_08062ED4: .4byte 0x0000093C
_08062ED8: .4byte 0x0000093E
_08062EDC: .4byte 0x00000944
_08062EE0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062F00
	ldr r0, _08062EFC @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062F56
	.align 2, 0
_08062EFC: .4byte 0x00000938
_08062F00:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062F1C
	ldr r2, _08062F14 @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062F18 @ =0x00000129
	b _08062F56
	.align 2, 0
_08062F14: .4byte 0x00000938
_08062F18: .4byte 0x00000129
_08062F1C:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062F34
	ldr r5, _08062F30 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062F56
	.align 2, 0
_08062F30: .4byte 0x00000938
_08062F34:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062F50
	ldr r0, _08062F48 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062F4C @ =0x0000012B
	b _08062F56
	.align 2, 0
_08062F48: .4byte 0x00000938
_08062F4C: .4byte 0x0000012B
_08062F50:
	ldr r2, _08062F90 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x1d
_08062F56:
	strh r0, [r1]
	ldr r5, _08062F94 @ =0x0000093A
	adds r1, r4, r5
	ldr r0, _08062F98 @ =0x00000121
	strh r0, [r1]
	ldr r0, _08062F9C @ =0x0000093C
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _08062FA0 @ =0x0000093E
	adds r1, r4, r2
	ldr r0, _08062FA4 @ =0x00000123
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062FA8 @ =0x00000942
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x21
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	b _08063060
	.align 2, 0
_08062F90: .4byte 0x00000938
_08062F94: .4byte 0x0000093A
_08062F98: .4byte 0x00000121
_08062F9C: .4byte 0x0000093C
_08062FA0: .4byte 0x0000093E
_08062FA4: .4byte 0x00000123
_08062FA8: .4byte 0x00000942
_08062FAC:
	ldr r0, _08063004 @ =0x00000387
	adds r2, r4, r0
	ldr r5, _08063008 @ =0x00000207
	adds r1, r5, #0
	ldrb r0, [r2]
	adds r3, r1, r0
	ldr r5, _0806300C @ =0x00000938
	adds r0, r4, r5
	strh r3, [r0]
	ldr r0, _08063010 @ =0x0000093A
	adds r3, r4, r0
	ldr r0, _08063014 @ =0x0000020F
	strh r0, [r3]
	ldrb r5, [r2]
	adds r3, r1, r5
	ldr r5, _08063018 @ =0x0000093C
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r2, [r2]
	adds r1, r1, r2
	ldr r2, _0806301C @ =0x00000946
	adds r0, r4, r2
	strh r1, [r0]
	b _08063064
	.align 2, 0
_08063004: .4byte 0x00000387
_08063008: .4byte 0x00000207
_0806300C: .4byte 0x00000938
_08063010: .4byte 0x0000093A
_08063014: .4byte 0x0000020F
_08063018: .4byte 0x0000093C
_0806301C: .4byte 0x00000946
_08063020:
	ldr r5, _0806306C @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x27
	strh r0, [r1]
	ldr r0, _08063070 @ =0x0000093A
	adds r1, r4, r0
	ldr r0, _08063074 @ =0x00000121
	strh r0, [r1]
	ldr r2, _08063078 @ =0x0000093C
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	ldr r0, _0806307C @ =0x00000123
	strh r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x1f
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	movs r0, #0x21
	strh r0, [r1]
	ldr r0, _08063080 @ =0x00000946
	adds r1, r4, r0
_08063060:
	movs r0, #0x1e
_08063062:
	strh r0, [r1]
_08063064:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806306C: .4byte 0x00000938
_08063070: .4byte 0x0000093A
_08063074: .4byte 0x00000121
_08063078: .4byte 0x0000093C
_0806307C: .4byte 0x00000123
_08063080: .4byte 0x00000946

	thumb_func_start FUN_08063084
FUN_08063084: @ 0x08063084
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08062c14
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r0, _080630DC @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080630E0 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080630E4 @ =0x0000094A
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r1, r4, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r3, r4, r1
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ldrh r0, [r5]
	strh r0, [r1, #6]
	ldr r0, [r2]
	str r3, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08062688
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080630DC: .4byte 0x0000094C
_080630E0: .4byte 0x0000FFFF
_080630E4: .4byte 0x0000094A

	thumb_func_start FUN_080630e8
FUN_080630e8: @ 0x080630E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _0806310C @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063114
	ldr r2, _08063110 @ =0x000004C4
	adds r0, r7, r2
	bl FUN_082466ec
	b _080631F2
	.align 2, 0
_0806310C: .4byte 0x000004C5
_08063110: .4byte 0x000004C4
_08063114:
	cmp r0, #2
	bne _08063122
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0806312E
_08063122:
	cmp r0, #3
	bne _0806312E
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806312E:
	ldr r1, _08063204 @ =0x000004CC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r3]
	ldr r6, _08063208 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r3, #2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0806320C @ =0x0000FFFF
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r3, #4]
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _08063210 @ =0x0203B400
	ldr r1, _08063214 @ =0x030046B8
	mov sl, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _08063218 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x14]
	ands r3, r6
	orrs r3, r0
	str r3, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	mov r0, r8
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r1, [r2]
	mov r2, sb
	ands r1, r2
	subs r1, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x1c]
	ands r0, r6
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	ldr r2, _0806321C @ =0x000004C4
	adds r0, r7, r2
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #3
	add r2, sp, #0xc
	bl FUN_08246728
_080631F2:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063204: .4byte 0x000004CC
_08063208: .4byte 0xFFFF0000
_0806320C: .4byte 0x0000FFFF
_08063210: .4byte 0x0203B400
_08063214: .4byte 0x030046B8
_08063218: .4byte 0x000003FF
_0806321C: .4byte 0x000004C4

	thumb_func_start FUN_08063220
FUN_08063220: @ 0x08063220
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08063244 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806323C
	adds r4, r0, #0
_08063230:
	adds r0, r5, #0
	bl FUN_080630e8
	subs r4, #1
	cmp r4, #0
	bne _08063230
_0806323C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063244: .4byte 0x000004C7

	thumb_func_start FUN_08063248
FUN_08063248: @ 0x08063248
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08063260 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063264
	subs r1, #1
	adds r0, r5, r1
	bl FUN_08246790
	b _0806327C
	.align 2, 0
_08063260: .4byte 0x000004C5
_08063264:
	ldr r1, _08063284 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806327C
	adds r4, r0, #0
_08063270:
	adds r0, r5, #0
	bl FUN_080630e8
	subs r4, #1
	cmp r4, #0
	bne _08063270
_0806327C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063284: .4byte 0x000004C7

	thumb_func_start FUN_08063288
FUN_08063288: @ 0x08063288
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov sb, r1
	ldr r0, _08063324 @ =0x000004C7
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080632BC
	ldr r1, _08063328 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, sb
	beq _080632B6
	cmp r0, #3
	bne _080632B0
	b _08063462
_080632B0:
	adds r0, r7, #0
	bl FUN_08063248
_080632B6:
	ldrb r0, [r4]
	cmp r0, #0
	bne _080632D2
_080632BC:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0806332C @ =0x000003DA
	adds r0, r7, r1
	strh r2, [r0]
_080632D2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08063344
	ldr r0, _08063330 @ =0x0203B400
	mov r8, r0
	ldr r6, _08063334 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _08063338 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0806333C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #5
	lsls r0, r0, #0x10
	ldr r1, _08063340 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _080633E2
	.align 2, 0
_08063324: .4byte 0x000004C7
_08063328: .4byte 0x000004C5
_0806332C: .4byte 0x000003DA
_08063330: .4byte 0x0203B400
_08063334: .4byte 0x030046B8
_08063338: .4byte 0x000003FF
_0806333C: .4byte 0xFFFF0000
_08063340: .4byte 0x0000FFFF
_08063344:
	cmp r0, #3
	bne _080633A0
	ldr r1, _0806338C @ =0x0203B400
	mov r8, r1
	ldr r6, _08063390 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _08063394 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08063398 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	ldr r1, _0806339C @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _080633E2
	.align 2, 0
_0806338C: .4byte 0x0203B400
_08063390: .4byte 0x030046B8
_08063394: .4byte 0x000003FF
_08063398: .4byte 0xFFFF0000
_0806339C: .4byte 0x0000FFFF
_080633A0:
	ldr r6, _08063410 @ =0x0203B400
	ldr r4, _08063414 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08063418 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0806341C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _08063420 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_080633E2:
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	ldr r2, _08063424 @ =0x000004C4
	adds r0, r7, r2
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r1, sb
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0806345A
	ldr r1, _08063428 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063430
	ldr r0, _0806342C @ =0x00000191
	bl PlaySound_082406e0
	b _0806345A
	.align 2, 0
_08063410: .4byte 0x0203B400
_08063414: .4byte 0x030046B8
_08063418: .4byte 0x000003FF
_0806341C: .4byte 0xFFFF0000
_08063420: .4byte 0x0000FFFF
_08063424: .4byte 0x000004C4
_08063428: .4byte 0x000004C5
_0806342C: .4byte 0x00000191
_08063430:
	cmp r0, #2
	bne _08063450
	ldr r2, _08063448 @ =0x00000376
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	ldr r0, _0806344C @ =0x00000133
	bl PlaySound_082406e0
	b _0806345A
	.align 2, 0
_08063448: .4byte 0x00000376
_0806344C: .4byte 0x00000133
_08063450:
	cmp r0, #3
	bne _0806345A
	ldr r0, _08063470 @ =0x00000133
	bl PlaySound_082406e0
_0806345A:
	ldr r0, _08063474 @ =0x0000043E
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_08063462:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063470: .4byte 0x00000133
_08063474: .4byte 0x0000043E

	thumb_func_start FUN_08063478
FUN_08063478: @ 0x08063478
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08063498
FUN_08063498: @ 0x08063498
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	ldr r1, _080634F8 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063516
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080634E0
	adds r0, r4, #0
	bl FUN_08063478
	ldr r2, _080634FC @ =0x085ABAB4
	ldr r3, _08063500 @ =0x000004C5
	adds r1, r4, r3
	ldrb r1, [r1]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	blt _080634E0
	adds r0, r4, #0
	bl FUN_080630e8
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _08063504 @ =0x00000401
	adds r0, r4, r2
	strb r1, [r0]
_080634E0:
	ldr r3, _080634F8 @ =0x000004C7
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063516
	ldr r1, _08063500 @ =0x000004C5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063508
	movs r5, #3
	b _08063516
	.align 2, 0
_080634F8: .4byte 0x000004C7
_080634FC: .4byte 0x085ABAB4
_08063500: .4byte 0x000004C5
_08063504: .4byte 0x00000401
_08063508:
	cmp r0, #2
	bne _08063510
	movs r5, #4
	b _08063516
_08063510:
	cmp r0, #3
	bne _08063516
	movs r5, #5
_08063516:
	ldr r2, _08063548 @ =0x00000402
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08063522
	movs r5, #7
_08063522:
	cmp r5, r6
	bne _08063554
	ldr r0, _0806354C @ =0x00000954
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _08063562
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08063542
	ldr r1, _08063550 @ =0x00000952
	adds r0, r4, r1
	ldrh r5, [r0]
_08063542:
	subs r0, r2, #1
	strh r0, [r3]
	b _08063562
	.align 2, 0
_08063548: .4byte 0x00000402
_0806354C: .4byte 0x00000954
_08063550: .4byte 0x00000952
_08063554:
	ldr r2, _0806356C @ =0x00000952
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _08063570 @ =0x00000954
	adds r1, r4, r3
	movs r0, #0x40
	strh r0, [r1]
_08063562:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0806356C: .4byte 0x00000952
_08063570: .4byte 0x00000954

	thumb_func_start FUN_08063574
FUN_08063574: @ 0x08063574
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	cmp r6, #1
	beq _08063590
	cmp r6, #1
	bgt _0806358A
	cmp r6, #0
	beq _08063610
	b _0806361A
_0806358A:
	cmp r6, #2
	beq _080635CC
	b _0806361A
_08063590:
	ldr r1, _080635C0 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080635AA
	ldr r2, _080635C4 @ =0x000004C5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _08063610
	adds r0, r5, #0
	bl FUN_08063220
_080635AA:
	ldr r1, _080635C8 @ =0x0000043E
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _08063610
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _08063610
	.align 2, 0
_080635C0: .4byte 0x000004C7
_080635C4: .4byte 0x000004C5
_080635C8: .4byte 0x0000043E
_080635CC:
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08063610
	ldr r4, _08063620 @ =0x03002B64
	ldr r2, _08063624 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x41
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08063628 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	bl Mod
	ldr r1, _0806362C @ =0x00000456
	adds r2, r5, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r1, #1
	adds r1, r1, r0
	movs r0, #7
	ands r1, r0
	strh r1, [r4]
	strb r1, [r2]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08063610:
	lsls r1, r6, #1
	ldr r2, _08063630 @ =0x0000043C
	adds r0, r5, r2
	adds r0, r0, r1
	strh r7, [r0]
_0806361A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063620: .4byte 0x03002B64
_08063624: .4byte 0x030046B8
_08063628: .4byte 0x0203B400
_0806362C: .4byte 0x00000456
_08063630: .4byte 0x0000043C

	thumb_func_start FUN_08063634
FUN_08063634: @ 0x08063634
	push {r4, lr}
	adds r3, r0, #0
	lsls r2, r1, #1
	ldr r4, _0806365C @ =0x0000043C
	adds r0, r3, r4
	adds r0, r0, r2
	movs r2, #0
	strh r2, [r0]
	cmp r1, #2
	bne _08063654
	ldr r0, _08063660 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x10]
	ldr r2, _08063664 @ =0x00000456
	adds r0, r3, r2
	strb r1, [r0]
_08063654:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806365C: .4byte 0x0000043C
_08063660: .4byte 0x030046A0
_08063664: .4byte 0x00000456

	thumb_func_start FUN_08063668
FUN_08063668: @ 0x08063668
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, _080636A4 @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _080636A8 @ =0x030046A0
	ldr r5, [r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r3, r0, r2
	ldr r2, [r3]
	cmp r2, #0
	ble _080636C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080636B4
	ldr r7, _080636AC @ =0x00000942
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bgt _080636B0
	movs r0, #0
	b _080636B2
	.align 2, 0
_080636A4: .4byte 0x0000038E
_080636A8: .4byte 0x030046A0
_080636AC: .4byte 0x00000942
_080636B0:
	subs r0, r2, r0
_080636B2:
	str r0, [r3]
_080636B4:
	movs r6, #6
	ldr r2, _080636C0 @ =0x00000958
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080636E0
	.align 2, 0
_080636C0: .4byte 0x00000958
_080636C4:
	ldr r7, _080636F0 @ =0x00000958
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080636E0
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080636DC
	movs r6, #6
_080636DC:
	subs r0, r2, #1
	strh r0, [r3]
_080636E0:
	movs r5, #0
_080636E2:
	cmp r5, #1
	beq _080636FA
	cmp r5, #1
	bgt _080636F4
	cmp r5, #0
	beq _08063748
	b _080637C4
	.align 2, 0
_080636F0: .4byte 0x00000958
_080636F4:
	cmp r5, #2
	beq _08063798
	b _080637C4
_080636FA:
	ldr r0, _0806371C @ =0x0000043E
	adds r2, r4, r0
	ldrh r1, [r2]
	cmp r1, #0
	beq _08063724
	ldr r0, [r4, #0x1c]
	ands r0, r5
	cmp r0, #0
	beq _08063710
	subs r0, r1, #1
	strh r0, [r2]
_08063710:
	movs r6, #2
	ldr r2, _08063720 @ =0x00000956
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080637C4
	.align 2, 0
_0806371C: .4byte 0x0000043E
_08063720: .4byte 0x00000956
_08063724:
	ldr r7, _08063744 @ =0x00000956
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080637C4
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806373C
	movs r6, #2
_0806373C:
	subs r0, r2, #1
	strh r0, [r3]
	b _080637C4
	.align 2, 0
_08063744: .4byte 0x00000956
_08063748:
	ldr r0, _08063790 @ =0x0000043C
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080637C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	subs r0, r2, #1
	strh r0, [r3]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	movs r2, #0x98
	lsls r2, r2, #4
	adds r0, r4, r2
	str r0, [sp]
	ldr r7, _08063794 @ =0x00000984
	adds r0, r4, r7
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	subs r7, #8
	adds r3, r4, r7
	bl FUN_08016e0c
	b _080637C4
	.align 2, 0
_08063790: .4byte 0x0000043C
_08063794: .4byte 0x00000984
_08063798:
	movs r0, #0x88
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080637C4
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080637C4
	subs r0, r2, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080637C4
	ldr r0, _080637D4 @ =0x030046A0
	ldr r0, [r0]
	ldrh r1, [r0, #0x10]
	ldr r2, _080637D8 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_080637C4:
	adds r5, #1
	cmp r5, #2
	ble _080636E2
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080637D4: .4byte 0x030046A0
_080637D8: .4byte 0x00000456

	thumb_func_start FUN_080637dc
FUN_080637dc: @ 0x080637DC
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08063800 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080637FC
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08063804
_080637FC:
	adds r0, r2, #0
	b _0806380A
	.align 2, 0
_08063800: .4byte 0x0000095C
_08063804:
	ldr r1, _08063810 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_0806380A:
	pop {r1}
	bx r1
	.align 2, 0
_08063810: .4byte 0x0000095A

	thumb_func_start FUN_08063814
FUN_08063814: @ 0x08063814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08063888 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _0806382A
	b _08063948
_0806382A:
	subs r1, #4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _08063894
	ldr r0, _0806388C @ =0x0000097A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x3f
	bhi _08063858
	cmp r0, #0
	bne _08063852
	movs r0, #0xf7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _08063890 @ =0x000003F1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08063852:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08063858:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0806388C @ =0x0000097A
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	adds r5, r2, #0
	b _080638FA
	.align 2, 0
_08063888: .4byte 0x00000446
_0806388C: .4byte 0x0000097A
_08063890: .4byte 0x000003F1
_08063894:
	ldr r0, _080638D4 @ =0x0000097A
	adds r6, r4, r0
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080638FA
	ldr r1, _080638D8 @ =0x000003F1
	adds r7, r4, r1
	ldrb r0, [r7]
	cmp r0, #0
	beq _080638B6
	ldr r0, _080638DC @ =0x00000336
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r7]
_080638B6:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080638E0
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080638F4
	.align 2, 0
_080638D4: .4byte 0x0000097A
_080638D8: .4byte 0x000003F1
_080638DC: .4byte 0x00000336
_080638E0:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080638F4:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080638FA:
	ldr r1, _0806391C @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _08063920
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	b _08063928
	.align 2, 0
_0806391C: .4byte 0x00000442
_08063920:
	ldr r0, [r5]
	ldr r1, _08063940 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r5]
_08063928:
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080639C0
	ldr r0, _08063944 @ =0x00000446
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080639C0
	.align 2, 0
_08063940: .4byte 0xFFFFFDFF
_08063944: .4byte 0x00000446
_08063948:
	ldr r1, _08063988 @ =0x0000097A
	adds r6, r4, r1
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080639AE
	ldr r0, _0806398C @ =0x000003F1
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0806396A
	ldr r0, _08063990 @ =0x00000336
	bl PlaySound_082406e0
	mov r1, r8
	strb r1, [r7]
_0806396A:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08063994
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080639A8
	.align 2, 0
_08063988: .4byte 0x0000097A
_0806398C: .4byte 0x000003F1
_08063990: .4byte 0x00000336
_08063994:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080639A8:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080639AE:
	ldr r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080639C0
	ldr r0, _080639CC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5]
_080639C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080639CC: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080639d0
FUN_080639d0: @ 0x080639D0
	push {lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf3
	ands r0, r1
	cmp r0, #0
	beq _080639F2
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080639F2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080639f8
FUN_080639f8: @ 0x080639F8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r2, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _08063A34
	adds r0, r5, #0
	bl FUN_08063814
	adds r0, r5, #0
	bl FUN_080639d0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08063668
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_08063498
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_080637dc
	adds r2, r0, #0
	b _08063A50
_08063A34:
	ldr r1, _08063A60 @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08063A64 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #0xb2
	lsls r6, r6, #2
	adds r0, r0, r6
	ldr r0, [r0]
	cmp r0, #0
	ble _08063A50
	movs r2, #6
_08063A50:
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _08063A68
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_080628ec
	b _08063A70
	.align 2, 0
_08063A60: .4byte 0x0000038E
_08063A64: .4byte 0x030046A0
_08063A68:
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_08062688
_08063A70:
	adds r0, r5, #0
	bl FUN_08061384
	adds r0, r5, #0
	bl FUN_080614bc
	adds r0, r5, #0
	bl FUN_08061c68
	adds r0, r5, #0
	bl FUN_08061e2c
	ldr r0, _08063B08 @ =0x00000714
	adds r1, r5, r0
	ldr r2, _08063B0C @ =0x000006AC
	adds r0, r5, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r6, _08063B10 @ =0x00000992
	adds r1, r5, r6
	ldrh r0, [r1]
	cmp r0, #0
	beq _08063ACE
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08063ACE
	ldr r0, _08063B14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	subs r6, #2
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_08063ACE:
	ldr r1, _08063B18 @ =0x00000604
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2c]
	adds r0, r0, r2
	ldr r6, _08063B1C @ =0x000005FC
	adds r1, r5, r6
	strh r0, [r1]
	ldr r1, _08063B20 @ =0x00000606
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	adds r6, #2
	adds r1, r5, r6
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x30]
	adds r0, r0, r2
	adds r6, #2
	adds r1, r5, r6
	strh r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08063B08: .4byte 0x00000714
_08063B0C: .4byte 0x000006AC
_08063B10: .4byte 0x00000992
_08063B14: .4byte 0x0000098C
_08063B18: .4byte 0x00000604
_08063B1C: .4byte 0x000005FC
_08063B20: .4byte 0x00000606

	thumb_func_start FUN_08063b24
FUN_08063b24: @ 0x08063B24
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08063B64 @ =0x000004C4
	adds r0, r4, r1
	bl FUN_08247504
	ldr r1, _08063B68 @ =0x0000060C
	adds r0, r4, r1
	bl FUN_080138fc
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	adds r0, r4, #0
	bl FUN_08061db4
	adds r0, r4, #0
	bl FUN_08062258
	adds r0, r4, #0
	bl FUN_08061b98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063B64: .4byte 0x000004C4
_08063B68: .4byte 0x0000060C

	thumb_func_start FUN_08063b6c
FUN_08063b6c: @ 0x08063B6C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _08063B98 @ =0x00000359
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _08063BA0
	ldr r3, _08063B9C @ =0x000004C4
	adds r0, r5, r3
	movs r4, #0x82
	lsls r4, r4, #1
	adds r1, r5, r4
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
	adds r4, r5, #0
	adds r4, #0xa8
	b _08063BB6
	.align 2, 0
_08063B98: .4byte 0x00000359
_08063B9C: .4byte 0x000004C4
_08063BA0:
	ldr r1, _08063CBC @ =0x000004C4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #1
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
_08063BB6:
	ldr r2, _08063CC0 @ =0x000005FC
	adds r1, r5, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r3, _08063CC4 @ =0x00000604
	adds r0, r5, r3
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08063CC8 @ =0x00000606
	adds r0, r5, r4
	strh r2, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r2, [r0]
	adds r4, #6
	adds r0, r5, r4
	bl FUN_0801385c
	bl FUN_080dc44c
	ldr r1, _08063CCC @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08063BFA
	ldr r2, _08063CD0 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08063BFA
	movs r1, #1
_08063BFA:
	cmp r1, #0
	beq _08063C0E
	ldr r3, _08063CD4 @ =0x0000097A
	adds r1, r5, r3
	movs r0, #0x40
	strh r0, [r1]
	ldr r4, _08063CD8 @ =0x000003F1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_08063C0E:
	adds r0, r5, #0
	bl FUN_08063084
	adds r0, r5, #0
	bl FUN_08061458
	adds r0, r5, #0
	bl FUN_0806161c
	adds r0, r5, #0
	bl FUN_08061dd4
	adds r0, r5, #0
	bl FUN_08062278
	adds r0, r5, #0
	bl FUN_08061bac
	ldr r1, _08063CDC @ =0x0000097C
	adds r0, r5, r1
	movs r2, #0
	movs r1, #4
	strb r1, [r0]
	ldr r3, _08063CE0 @ =0x0000097D
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08063CE4 @ =0x0000097E
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	movs r3, #0
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	ldr r1, _08063CE8 @ =0x00000978
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r2, [r0]
	subs r4, #0x18
	adds r0, r5, r4
	strh r2, [r0]
	subs r1, #4
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _08063CEC @ =0x03002BAC
	strh r2, [r0]
	ldr r0, _08063CF0 @ =0x03002B90
	strh r2, [r0]
	ldr r1, _08063CF4 @ =0x03002B84
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08063CF8 @ =0x03002BF0
	strh r2, [r0]
	ldr r2, _08063CFC @ =0x000003FF
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063CBC: .4byte 0x000004C4
_08063CC0: .4byte 0x000005FC
_08063CC4: .4byte 0x00000604
_08063CC8: .4byte 0x00000606
_08063CCC: .4byte 0x00000446
_08063CD0: .4byte 0x00000442
_08063CD4: .4byte 0x0000097A
_08063CD8: .4byte 0x000003F1
_08063CDC: .4byte 0x0000097C
_08063CE0: .4byte 0x0000097D
_08063CE4: .4byte 0x0000097E
_08063CE8: .4byte 0x00000978
_08063CEC: .4byte 0x03002BAC
_08063CF0: .4byte 0x03002B90
_08063CF4: .4byte 0x03002B84
_08063CF8: .4byte 0x03002BF0
_08063CFC: .4byte 0x000003FF
_08063D00:
	.byte 0x03, 0x48, 0x00, 0x68, 0x03, 0x49, 0x40, 0x18, 0x00, 0x21, 0x40, 0x5E, 0x70, 0x47, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x42, 0x09, 0x00, 0x00

	thumb_func_start FUN_08063d18
FUN_08063d18: @ 0x08063D18
	push {lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _08063D58 @ =0x0000043C
	adds r1, r3, r0
_08063D22:
	ldrh r0, [r1]
	cmp r0, #0
	bne _08063D68
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	ble _08063D22
	ldr r1, _08063D5C @ =0x0000038E
	adds r0, r3, r1
	ldrb r0, [r0]
	ldr r1, _08063D60 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08063D68
	ldr r1, _08063D64 @ =0x000004C7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08063D68
	movs r0, #0
	b _08063D6A
	.align 2, 0
_08063D58: .4byte 0x0000043C
_08063D5C: .4byte 0x0000038E
_08063D60: .4byte 0x030046A0
_08063D64: .4byte 0x000004C7
_08063D68:
	movs r0, #0xa
_08063D6A:
	pop {r1}
	bx r1
	.align 2, 0
_08063D70:
	.byte 0x00, 0xB5, 0xFD, 0xF7, 0x53, 0xF8, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0, 0x0A, 0x20
	.byte 0x02, 0xBC, 0x08, 0x47, 0x02, 0x49, 0x40, 0x18, 0x00, 0x88, 0xC0, 0x08, 0x70, 0x47, 0x00, 0x00
	.byte 0x62, 0x03, 0x00, 0x00, 0xD7, 0x21, 0x89, 0x00, 0x40, 0x18, 0x00, 0x88, 0xC0, 0x08, 0x70, 0x47
	.byte 0x02, 0x49, 0x40, 0x18, 0x00, 0x88, 0xC0, 0x08, 0x70, 0x47, 0x00, 0x00, 0x5E, 0x03, 0x00, 0x00

	thumb_func_start FUN_08063db0
FUN_08063db0: @ 0x08063DB0
	push {lr}
	adds r2, r0, #0
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08063DD0 @ =0x0000036A
	adds r2, r2, r1
	ldrh r1, [r2]
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_08063DD0: .4byte 0x0000036A

	thumb_func_start FUN_08063dd4
FUN_08063dd4: @ 0x08063DD4
	push {lr}
	adds r2, r0, #0
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08063DF4 @ =0x00000366
	adds r2, r2, r1
	ldrh r1, [r2]
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_08063DF4: .4byte 0x00000366

	thumb_func_start FUN_08063df8
FUN_08063df8: @ 0x08063DF8
	push {lr}
	ldr r2, _08063E18 @ =0x00000366
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	bl Div
	pop {r1}
	bx r1
	.align 2, 0
_08063E18: .4byte 0x00000366

	thumb_func_start FUN_08063e1c
FUN_08063e1c: @ 0x08063E1C
	push {lr}
	ldr r2, _08063E3C @ =0x00000366
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	subs r2, r1, r2
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	bl Div
	rsbs r0, r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08063E3C: .4byte 0x00000366
_08063E40:
	.byte 0x00, 0xB5, 0x80, 0x20, 0x91, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x0D, 0xD0, 0x05, 0x48, 0x00, 0x68
	.byte 0x8A, 0x21, 0x89, 0x00, 0x40, 0x18, 0x00, 0x88, 0x00, 0x04, 0x80, 0x15, 0x0A, 0x28, 0x38, 0xDD
	.byte 0x0A, 0x20, 0x36, 0xE0, 0xA0, 0x46, 0x00, 0x03, 0x80, 0x20, 0x40, 0x00, 0x08, 0x40, 0x00, 0x28
	.byte 0x08, 0xD0, 0x02, 0x48, 0x00, 0x68, 0x02, 0x49, 0xEC, 0xE7, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03
	.byte 0x2A, 0x02, 0x00, 0x00, 0x80, 0x20, 0x80, 0x00, 0x08, 0x40, 0x00, 0x28, 0x06, 0xD0, 0x02, 0x48
	.byte 0x00, 0x68, 0x8B, 0x21, 0x89, 0x00, 0xDD, 0xE7, 0xA0, 0x46, 0x00, 0x03, 0x80, 0x20, 0xC0, 0x00
	.byte 0x08, 0x40, 0x00, 0x28, 0x08, 0xD0, 0x02, 0x48, 0x00, 0x68, 0x02, 0x49, 0xD2, 0xE7, 0x00, 0x00
	.byte 0xA0, 0x46, 0x00, 0x03, 0x2E, 0x02, 0x00, 0x00, 0x80, 0x20, 0x00, 0x01, 0x01, 0x40, 0x00, 0x29
	.byte 0x06, 0xD0, 0x02, 0x48, 0x00, 0x68, 0x8C, 0x21, 0x89, 0x00, 0xC3, 0xE7, 0xA0, 0x46, 0x00, 0x03
	.byte 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x08, 0x4A, 0x10, 0x68, 0x01, 0x30
	.byte 0x07, 0x49, 0x08, 0x40, 0x10, 0x60, 0x40, 0x00, 0x06, 0x49, 0x40, 0x18, 0x00, 0x88, 0x64, 0x21
	.byte 0xE8, 0xF1, 0x68, 0xF9, 0x0A, 0x28, 0x07, 0xDD, 0x00, 0x20, 0x06, 0xE0, 0xB8, 0x46, 0x00, 0x03
	.byte 0xFF, 0x03, 0x00, 0x00, 0x00, 0xB4, 0x03, 0x02, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x00, 0xB5, 0x80, 0x21, 0x90, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0
	.byte 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x80, 0x21, 0x49, 0x00, 0x90, 0x6B
	.byte 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47
	.byte 0x00, 0xB5, 0x80, 0x21, 0x89, 0x00, 0x90, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20
	.byte 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0xB5, 0x80, 0x21, 0xC9, 0x00, 0x90, 0x6B
	.byte 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47
	.byte 0x00, 0xB5, 0x80, 0x21, 0x09, 0x01, 0x90, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20
	.byte 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0xB5, 0x04, 0x22, 0x88, 0x6B, 0x10, 0x40
	.byte 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x00, 0xB5, 0x08, 0x22, 0x88, 0x6B, 0x10, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0
	.byte 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x10, 0x22, 0x88, 0x6B, 0x10, 0x40
	.byte 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0, 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x00, 0xB5, 0x20, 0x22, 0x88, 0x6B, 0x10, 0x40, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20, 0x00, 0xE0
	.byte 0x0A, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x08, 0x4A, 0x10, 0x68, 0x01, 0x30
	.byte 0x07, 0x49, 0x08, 0x40, 0x10, 0x60, 0x40, 0x00, 0x06, 0x49, 0x40, 0x18, 0x00, 0x88, 0x64, 0x21
	.byte 0xE8, 0xF1, 0xE0, 0xF8, 0x0A, 0x28, 0x07, 0xDD, 0x00, 0x20, 0x07, 0xE0, 0xB8, 0x46, 0x00, 0x03
	.byte 0xFF, 0x03, 0x00, 0x00, 0x00, 0xB4, 0x03, 0x02, 0x80, 0x20, 0x40, 0x01, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_08064020
FUN_08064020: @ 0x08064020
	push {lr}
	ldr r2, _08064044 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08064048 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806404C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0xa
	ble _08064050
	movs r0, #0
	b _08064054
	.align 2, 0
_08064044: .4byte 0x030046B8
_08064048: .4byte 0x000003FF
_0806404C: .4byte 0x0203B400
_08064050:
	movs r0, #0x80
	lsls r0, r0, #0xc
_08064054:
	pop {r1}
	bx r1

	thumb_func_start FUN_08064058
FUN_08064058: @ 0x08064058
	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080640D0
	movs r1, #4
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080640D0
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08064098
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _080640D0
	subs r3, #2
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080640D0
_08064098:
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r3, r2, r4
	ldr r1, _080640D8 @ =0x00000366
	adds r0, r2, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _080640D0
	adds r0, r1, #1
	strh r0, [r3]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r3, r2, #0
	adds r3, #0x2c
	movs r4, #0x97
	lsls r4, r4, #4
	adds r1, r2, r4
	str r1, [sp]
	adds r4, #8
	adds r1, r2, r4
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #1
	movs r2, #1
	bl FUN_0805fe7c
_080640D0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080640D8: .4byte 0x00000366

	thumb_func_start FUN_080640dc
FUN_080640dc: @ 0x080640DC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r1, #0
	ldr r2, _08064128 @ =0x00000A9C
	adds r0, r3, r2
	movs r5, #2
_080640EA:
	str r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #0x18]
	adds r0, #4
	subs r5, #1
	cmp r5, #0
	bge _080640EA
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	movs r5, #0
	adds r4, r0, #0
_0806410C:
	lsls r0, r5, #2
	adds r1, r6, r0
	ldrb r1, [r1, #0x18]
	subs r1, #1
	adds r2, r0, #0
	cmp r1, #0x1e
	bls _0806411C
	b _080643C2
_0806411C:
	lsls r0, r1, #2
	ldr r1, _0806412C @ =_08064130
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08064128: .4byte 0x00000A9C
_0806412C: .4byte _08064130
_08064130: @ jump table
	.4byte _080641AC @ case 0
	.4byte _080641D4 @ case 1
	.4byte _0806424C @ case 2
	.4byte _08064260 @ case 3
	.4byte _0806438A @ case 4
	.4byte _080643A0 @ case 5
	.4byte _080643B4 @ case 6
	.4byte _080641FC @ case 7
	.4byte _08064210 @ case 8
	.4byte _080641E8 @ case 9
	.4byte _08064238 @ case 10
	.4byte _08064224 @ case 11
	.4byte _080641C0 @ case 12
	.4byte _080641AC @ case 13
	.4byte _080641D4 @ case 14
	.4byte _08064288 @ case 15
	.4byte _08064274 @ case 16
	.4byte _08064300 @ case 17
	.4byte _08064314 @ case 18
	.4byte _08064328 @ case 19
	.4byte _0806433C @ case 20
	.4byte _0806429C @ case 21
	.4byte _080642B0 @ case 22
	.4byte _080642C4 @ case 23
	.4byte _080642D8 @ case 24
	.4byte _080642EC @ case 25
	.4byte _08064350 @ case 26
	.4byte _08064364 @ case 27
	.4byte _08064380 @ case 28
	.4byte _0806437C @ case 29
	.4byte _08064378 @ case 30
_080641AC:
	ldr r1, _080641B8 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641BC @ =0x08063D01
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641B8: .4byte 0x00000A9C
_080641BC: .4byte 0x08063D01
_080641C0:
	ldr r1, _080641CC @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641D0 @ =FUN_08063d18
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641CC: .4byte 0x00000A9C
_080641D0: .4byte FUN_08063d18
_080641D4:
	ldr r1, _080641E0 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641E4 @ =0x08063D71
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641E0: .4byte 0x00000A9C
_080641E4: .4byte 0x08063D71
_080641E8:
	ldr r1, _080641F4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641F8 @ =0x08063D85
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641F4: .4byte 0x00000A9C
_080641F8: .4byte 0x08063D85
_080641FC:
	ldr r1, _08064208 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806420C @ =0x08063D95
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064208: .4byte 0x00000A9C
_0806420C: .4byte 0x08063D95
_08064210:
	ldr r1, _0806421C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064220 @ =0x08063DA1
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806421C: .4byte 0x00000A9C
_08064220: .4byte 0x08063DA1
_08064224:
	ldr r1, _08064230 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064234 @ =FUN_08063db0
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064230: .4byte 0x00000A9C
_08064234: .4byte FUN_08063db0
_08064238:
	ldr r1, _08064244 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064248 @ =FUN_08063dd4
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064244: .4byte 0x00000A9C
_08064248: .4byte FUN_08063dd4
_0806424C:
	ldr r1, _08064258 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806425C @ =FUN_08063df8
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064258: .4byte 0x00000A9C
_0806425C: .4byte FUN_08063df8
_08064260:
	ldr r1, _0806426C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064270 @ =FUN_08063e1c
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806426C: .4byte 0x00000A9C
_08064270: .4byte FUN_08063e1c
_08064274:
	ldr r1, _08064280 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064284 @ =0x08063E41
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064280: .4byte 0x00000AB4
_08064284: .4byte 0x08063E41
_08064288:
	ldr r1, _08064294 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064298 @ =0x08063ED9
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064294: .4byte 0x00000AB4
_08064298: .4byte 0x08063ED9
_0806429C:
	ldr r1, _080642A8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642AC @ =0x08063F11
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642A8: .4byte 0x00000AB4
_080642AC: .4byte 0x08063F11
_080642B0:
	ldr r1, _080642BC @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642C0 @ =0x08063F29
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642BC: .4byte 0x00000AB4
_080642C0: .4byte 0x08063F29
_080642C4:
	ldr r1, _080642D0 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642D4 @ =0x08063F41
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642D0: .4byte 0x00000AB4
_080642D4: .4byte 0x08063F41
_080642D8:
	ldr r1, _080642E4 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642E8 @ =0x08063F59
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642E4: .4byte 0x00000AB4
_080642E8: .4byte 0x08063F59
_080642EC:
	ldr r1, _080642F8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642FC @ =0x08063F71
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642F8: .4byte 0x00000AB4
_080642FC: .4byte 0x08063F71
_08064300:
	ldr r1, _0806430C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064310 @ =0x08063F89
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806430C: .4byte 0x00000AB4
_08064310: .4byte 0x08063F89
_08064314:
	ldr r1, _08064320 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064324 @ =0x08063FA1
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064320: .4byte 0x00000AB4
_08064324: .4byte 0x08063FA1
_08064328:
	ldr r1, _08064334 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064338 @ =0x08063FB9
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064334: .4byte 0x00000AB4
_08064338: .4byte 0x08063FB9
_0806433C:
	ldr r1, _08064348 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806434C @ =0x08063FD1
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064348: .4byte 0x00000AB4
_0806434C: .4byte 0x08063FD1
_08064350:
	ldr r1, _0806435C @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064360 @ =0x08063FE9
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806435C: .4byte 0x00000AA8
_08064360: .4byte 0x08063FE9
_08064364:
	ldr r1, _08064370 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064374 @ =FUN_08064020
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064370: .4byte 0x00000AA8
_08064374: .4byte FUN_08064020
_08064378:
	movs r1, #1
	b _08064382
_0806437C:
	movs r1, #2
	b _08064382
_08064380:
	movs r1, #4
_08064382:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	b _080643C2
_0806438A:
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r2, _0806439C @ =0x00000A95
	adds r1, r3, r2
	movs r0, #0
	b _080643C0
	.align 2, 0
_0806439C: .4byte 0x00000A95
_080643A0:
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080643B0 @ =0x00000A95
	adds r1, r3, r0
	movs r0, #4
	b _080643C0
	.align 2, 0
_080643B0: .4byte 0x00000A95
_080643B4:
	movs r0, #8
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldr r2, _080643D0 @ =0x00000A95
	adds r1, r3, r2
_080643C0:
	strb r0, [r1]
_080643C2:
	adds r5, #1
	cmp r5, #2
	bgt _080643CA
	b _0806410C
_080643CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080643D0: .4byte 0x00000A95

	thumb_func_start FUN_080643d4
FUN_080643d4: @ 0x080643D4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r6, r5, r0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080643EE
	b _080645F0
_080643EE:
	ldr r2, _08064404 @ =0x00000A75
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080643FA
	b _08064648
_080643FA:
	lsls r0, r0, #2
	ldr r1, _08064408 @ =_0806440C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08064404: .4byte 0x00000A75
_08064408: .4byte _0806440C
_0806440C: @ jump table
	.4byte _08064420 @ case 0
	.4byte _08064470 @ case 1
	.4byte _080644B0 @ case 2
	.4byte _080644F4 @ case 3
	.4byte _08064544 @ case 4
_08064420:
	ldr r3, _0806445C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x5a
	orrs r0, r2
	ldr r1, _08064460 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _08064464 @ =0xFFE70000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #1
	ldr r3, _08064468 @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0806446C @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #0xa
	b _0806457E
	.align 2, 0
_0806445C: .4byte 0xFFFF0000
_08064460: .4byte 0x0000FFFF
_08064464: .4byte 0xFFE70000
_08064468: .4byte 0x00000A7C
_0806446C: .4byte 0x00000A7E
_08064470:
	ldr r3, _080644A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _080644A8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #2
	ldr r3, _080644AC @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x40
	b _08064576
	.align 2, 0
_080644A4: .4byte 0xFFFF0000
_080644A8: .4byte 0x0000FFFF
_080644AC: .4byte 0x00000A7C
_080644B0:
	ldr r3, _080644E8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x50
	orrs r0, r2
	ldr r1, _080644EC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #4
	ldr r3, _080644F0 @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x30
	b _08064576
	.align 2, 0
_080644E8: .4byte 0xFFFF0000
_080644EC: .4byte 0x0000FFFF
_080644F0: .4byte 0x00000A7C
_080644F4:
	ldr r3, _08064530 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _08064534 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _08064538 @ =0xFFB00000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #8
	ldr r3, _0806453C @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08064540 @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #5
	b _0806457E
	.align 2, 0
_08064530: .4byte 0xFFFF0000
_08064534: .4byte 0x0000FFFF
_08064538: .4byte 0xFFB00000
_0806453C: .4byte 0x00000A7C
_08064540: .4byte 0x00000A7E
_08064544:
	ldr r3, _080645D0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _080645D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _080645D8 @ =0xFFE70000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #0x10
	ldr r3, _080645DC @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x20
_08064576:
	strh r0, [r1]
	ldr r0, _080645E0 @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #0x14
_0806457E:
	strh r0, [r1]
	adds r3, r2, #0
	ldr r2, _080645E4 @ =0x00002101
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r2, _080645E8 @ =0x00000A7A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _080645DC @ =0x00000A7C
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_082364f8
	ldr r1, _080645EC @ =dark_django_0806f990
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	b _08064648
	.align 2, 0
_080645D0: .4byte 0xFFFF0000
_080645D4: .4byte 0x0000FFFF
_080645D8: .4byte 0xFFE70000
_080645DC: .4byte 0x00000A7C
_080645E0: .4byte 0x00000A7E
_080645E4: .4byte 0x00002101
_080645E8: .4byte 0x00000A7A
_080645EC: .4byte dark_django_0806f990
_080645F0:
	movs r4, #0
	movs r2, #0xaa
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r3, sp, #0x14
	strh r4, [r3]
	ldr r0, _08064650 @ =0x0000FFEC
	strh r0, [r3, #2]
	strh r4, [r3, #4]
	ldr r2, _08064654 @ =0x00002101
	adds r1, r5, #0
	adds r1, #0x28
	adds r0, #0x14
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #2
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
_08064648:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064650: .4byte 0x0000FFEC
_08064654: .4byte 0x00002101

	thumb_func_start FUN_08064658
FUN_08064658: @ 0x08064658
	movs r2, #0xa7
	lsls r2, r2, #4
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start weapon_08064664
weapon_08064664: @ 0x08064664
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r5, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _080646A8
	adds r0, r5, #0
	bl FUN_08064658
	movs r3, #0xa7
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _080646A0
	mov r1, sp
	ldr r0, _0806469C @ =gWeaponDB
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	b _080646C8
	.align 2, 0
_0806469C: .4byte gWeaponDB
_080646A0:
	mov r1, sp
	bl FUN_08242a98
	b _080646C8
_080646A8:
	movs r4, #0xa7
	lsls r4, r4, #4
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	ldr r1, _0806470C @ =gWeaponDB
	mov r0, sp
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r1, r2
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
_080646C8:
	mov r0, sp
	ldrb r0, [r0]
	ldr r3, _08064710 @ =0x00000A74
	adds r4, r5, r3
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #1]
	ldr r1, _08064714 @ =0x00000A75
	adds r6, r5, r1
	strb r0, [r6]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r2, _08064718 @ =0x00000A78
	adds r0, r5, r2
	strh r1, [r0]
	mov r0, sp
	bl FUN_0807a6cc
	ldr r3, _0806471C @ =0x00000A7A
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_080640dc
	ldrb r0, [r4]
	cmp r0, #0x3d
	bne _08064728
	ldr r4, _08064720 @ =0x00000A98
	adds r1, r5, r4
	ldr r0, _08064724 @ =FUN_08071b14
	str r0, [r1]
	b _08064738
	.align 2, 0
_0806470C: .4byte gWeaponDB
_08064710: .4byte 0x00000A74
_08064714: .4byte 0x00000A75
_08064718: .4byte 0x00000A78
_0806471C: .4byte 0x00000A7A
_08064720: .4byte 0x00000A98
_08064724: .4byte FUN_08071b14
_08064728:
	ldr r0, _0806475C @ =0x00000A98
	adds r2, r5, r0
	ldr r1, _08064760 @ =0x085ABAB8
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_08064738:
	adds r0, r5, #0
	bl FUN_080643d4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _08064754
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08064754:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806475C: .4byte 0x00000A98
_08064760: .4byte 0x085ABAB8

	thumb_func_start FUN_08064764
FUN_08064764: @ 0x08064764
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r3, r5, r0
	ldrh r2, [r3, #0x3e]
	cmp r2, #0
	ble _08064830
	movs r6, #0x40
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ands r6, r1
	cmp r6, #0
	beq _0806478A
	movs r0, #0
	strh r0, [r3, #0x3e]
	b _08064830
_0806478A:
	ldr r3, _080647C8 @ =0x00000A75
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	bhi _08064826
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0806479E
	asrs r2, r2, #1
_0806479E:
	movs r0, #0xa7
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r1, [r4]
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _080647CC
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bls _08064826
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	subs r0, #1
	strb r0, [r1, #1]
	b _080647E6
	.align 2, 0
_080647C8: .4byte 0x00000A75
_080647CC:
	ldrb r3, [r1, #0x18]
	cmp r3, #0
	beq _080647FC
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	ldr r1, _080647F8 @ =0x07CF0000
	cmp r0, r1
	bls _08064826
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x18]
_080647E6:
	ldr r0, [r4]
	strh r6, [r0, #2]
	bl FUN_0809c4f4
	ldr r1, [r4]
	adds r0, r5, #0
	bl weapon_08064664
	b _08064826
	.align 2, 0
_080647F8: .4byte 0x07CF0000
_080647FC:
	ldrb r0, [r1, #0x14]
	cmp r0, #0
	beq _08064826
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	ldr r1, _08064838 @ =0x07CF0000
	cmp r0, r1
	bls _08064826
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x14]
	ldr r0, [r4]
	strh r3, [r0, #2]
	bl FUN_0809c4f4
	ldr r1, [r4]
	adds r0, r5, #0
	bl weapon_08064664
_08064826:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1, #0x3e]
_08064830:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064838: .4byte 0x07CF0000

	thumb_func_start FUN_0806483c
FUN_0806483c: @ 0x0806483C
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	movs r1, #0
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #3
_08064856:
	strh r1, [r0]
	strh r1, [r0, #8]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08064856
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, _08064884 @ =0xF000000F
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	adds r2, r0, #0
	cmp r3, #0
	bne _0806488C
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r2, _08064888 @ =0x0000094C
	adds r1, r4, r2
	b _08064A50
	.align 2, 0
_08064884: .4byte 0xF000000F
_08064888: .4byte 0x0000094C
_0806488C:
	ldrb r0, [r3, #3]
	subs r0, #1
	cmp r0, #0x1f
	bls _08064896
	b _08064A46
_08064896:
	lsls r0, r0, #2
	ldr r1, _080648A0 @ =_080648A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080648A0: .4byte _080648A4
_080648A4: @ jump table
	.4byte _08064988 @ case 0
	.4byte _080649A0 @ case 1
	.4byte _080649BC @ case 2
	.4byte _080649D8 @ case 3
	.4byte _08064924 @ case 4
	.4byte _08064934 @ case 5
	.4byte _08064940 @ case 6
	.4byte _0806494C @ case 7
	.4byte _08064958 @ case 8
	.4byte _08064964 @ case 9
	.4byte _08064970 @ case 10
	.4byte _0806497C @ case 11
	.4byte _080649DC @ case 12
	.4byte _080649E0 @ case 13
	.4byte _08064A46 @ case 14
	.4byte _08064A06 @ case 15
	.4byte _080649E6 @ case 16
	.4byte _080649EC @ case 17
	.4byte _080649F2 @ case 18
	.4byte _080649F8 @ case 19
	.4byte _08064A0C @ case 20
	.4byte _08064A12 @ case 21
	.4byte _080649FE @ case 22
	.4byte _08064A02 @ case 23
	.4byte _08064A18 @ case 24
	.4byte _080649C8 @ case 25
	.4byte _08064A1E @ case 26
	.4byte _08064A24 @ case 27
	.4byte _08064A2A @ case 28
	.4byte _08064A30 @ case 29
	.4byte _08064A36 @ case 30
	.4byte _08064A3C @ case 31
_08064924:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #7
	b _08064A40
_08064934:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	str r0, [r1]
	b _08064A46
_08064940:
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #4
	str r0, [r1]
	b _08064A46
_0806494C:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #8
	str r0, [r1]
	b _08064A46
_08064958:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x10
	str r0, [r1]
	b _08064A46
_08064964:
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x20
	str r0, [r1]
	b _08064A46
_08064970:
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0x3c
	str r0, [r1]
	b _08064A46
_0806497C:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x40
	str r0, [r1]
	b _08064A46
_08064988:
	ldrb r1, [r3, #4]
	movs r2, #3
	ldr r3, _0806499C @ =0x0000027A
	adds r0, r4, r3
_08064990:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08064990
	b _08064A46
	.align 2, 0
_0806499C: .4byte 0x0000027A
_080649A0:
	ldrb r1, [r3, #4]
	rsbs r1, r1, #0
	movs r2, #3
	ldr r3, _080649B8 @ =0x0000027A
	adds r0, r4, r3
_080649AA:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _080649AA
	b _08064A46
	.align 2, 0
_080649B8: .4byte 0x0000027A
_080649BC:
	ldrb r1, [r3, #4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08064A46
_080649C8:
	ldrb r1, [r3, #4]
	ldr r3, _080649D4 @ =0x00000272
	adds r0, r4, r3
	strh r1, [r0]
	b _08064A46
	.align 2, 0
_080649D4: .4byte 0x00000272
_080649D8:
	movs r1, #0x10
	b _08064A40
_080649DC:
	movs r1, #0x80
	b _08064A40
_080649E0:
	movs r1, #0x80
	lsls r1, r1, #5
	b _08064A40
_080649E6:
	movs r1, #0x80
	lsls r1, r1, #3
	b _08064A40
_080649EC:
	movs r1, #0x80
	lsls r1, r1, #1
	b _08064A40
_080649F2:
	movs r1, #0x80
	lsls r1, r1, #2
	b _08064A40
_080649F8:
	movs r1, #0x80
	lsls r1, r1, #4
	b _08064A40
_080649FE:
	movs r1, #0x20
	b _08064A40
_08064A02:
	movs r1, #0x40
	b _08064A40
_08064A06:
	movs r1, #0x80
	lsls r1, r1, #6
	b _08064A40
_08064A0C:
	movs r1, #0x80
	lsls r1, r1, #8
	b _08064A40
_08064A12:
	movs r1, #0x80
	lsls r1, r1, #9
	b _08064A40
_08064A18:
	movs r1, #0x80
	lsls r1, r1, #0xa
	b _08064A40
_08064A1E:
	movs r1, #0x80
	lsls r1, r1, #0xb
	b _08064A40
_08064A24:
	movs r1, #0x80
	lsls r1, r1, #0xc
	b _08064A40
_08064A2A:
	movs r1, #0x80
	lsls r1, r1, #0xd
	b _08064A40
_08064A30:
	movs r1, #0x80
	lsls r1, r1, #0xe
	b _08064A40
_08064A36:
	movs r1, #0x80
	lsls r1, r1, #0xf
	b _08064A40
_08064A3C:
	movs r1, #0x80
	lsls r1, r1, #0x10
_08064A40:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08064A46:
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r0, _08064A5C @ =0x0000094C
	adds r1, r4, r0
_08064A50:
	ldr r0, _08064A60 @ =0x0000FFFF
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064A5C: .4byte 0x0000094C
_08064A60: .4byte 0x0000FFFF

	thumb_func_start FUN_08064a64
FUN_08064a64: @ 0x08064A64
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	bne _08064A90
	movs r0, #0x99
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08064A88 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _08064A8C @ =0x00000266
	adds r0, r4, r1
	strh r2, [r0]
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	b _08064AAA
	.align 2, 0
_08064A88: .4byte 0x0000FFFF
_08064A8C: .4byte 0x00000266
_08064A90:
	ldrb r1, [r2]
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r1, [r2, #1]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r1, [r2, #2]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
_08064AAA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0806483c
	adds r0, r4, #0
	bl FUN_080612bc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CheckHeartJokerEmblem
CheckHeartJokerEmblem: @ 0x08064AC0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x34
	bl CheckItemOwn
	cmp r0, #0
	beq _08064ADE
	movs r2, #0x80
	lsls r2, r2, #0x15
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08064ADE:
	movs r0, #0x37
	bl CheckItemOwn
	cmp r0, #0
	beq _08064AF8
	movs r2, #0x80
	lsls r2, r2, #0x16
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08064AF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08064b00
FUN_08064b00: @ 0x08064B00
	push {lr}
	adds r2, r0, #0
	ldr r0, _08064B18 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _08064B20
	ldr r0, _08064B1C @ =0x085ABACC
	b _08064B22
	.align 2, 0
_08064B18: .4byte 0x030047A4
_08064B1C: .4byte 0x085ABACC
_08064B20:
	ldr r0, _08064B2C @ =0x085ABAF0
_08064B22:
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08064B2C: .4byte 0x085ABAF0

	thumb_func_start FUN_08064b30
FUN_08064b30: @ 0x08064B30
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _08064B46
	movs r0, #0
	b _08064B8A
_08064B46:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	adds r2, r0, #0
	movs r3, #0x64
	movs r0, #0x80
	lsls r0, r0, #1
	movs r6, #0xde
	lsls r6, r6, #2
	adds r1, r5, r6
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08064B66
	movs r3, #0x50
_08064B66:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _08064B78
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08064B78
	subs r3, #0x14
_08064B78:
	cmp r3, #0x63
	bgt _08064B88
	adds r0, r2, #0
	muls r0, r3, r0
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
_08064B88:
	adds r0, r2, #0
_08064B8A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08064b90
FUN_08064b90: @ 0x08064B90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08064b30
	adds r2, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bgt _08064BCC
	movs r1, #8
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08064BCC
	ldr r0, _08064BC8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _08064BD4
	.align 2, 0
_08064BC8: .4byte 0x030046A0
_08064BCC:
	movs r3, #0xda
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
_08064BD4:
	cmp r0, r2
	bge _08064BDC
	movs r0, #0
	b _08064BDE
_08064BDC:
	movs r0, #1
_08064BDE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08064be4
FUN_08064be4: @ 0x08064BE4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08064b30
	adds r2, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bgt _08064C2E
	movs r1, #8
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08064C2E
	ldr r0, _08064C24 @ =0x030046A0
	ldr r0, [r0]
	adds r3, #0x44
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, r2
	bge _08064C28
	movs r0, #0
	str r0, [r1]
	b _08064C42
	.align 2, 0
_08064C24: .4byte 0x030046A0
_08064C28:
	subs r0, r0, r2
	str r0, [r1]
	b _08064C42
_08064C2E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	bge _08064C3E
	movs r0, #0
	b _08064C40
_08064C3E:
	subs r0, r0, r2
_08064C40:
	strh r0, [r1]
_08064C42:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08064c48
FUN_08064c48: @ 0x08064C48
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	blt _08064C94
	adds r0, r4, #0
	bl FUN_0824347c
	adds r5, r0, #0
	cmp r4, #5
	bgt _08064C64
	adds r0, r6, #0
	movs r1, #2
	b _08064C6C
_08064C64:
	subs r0, r4, #6
	movs r1, #4
	lsls r1, r0
	adds r0, r6, #0
_08064C6C:
	bl FUN_08060ed8
	adds r1, r0, #0
	cmp r1, #0
	bne _08064C94
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _08064C98
	cmp r5, #0
	bne _08064C8C
	cmp r4, #1
	beq _08064C94
	b _08064CF8
_08064C8C:
	cmp r5, #1
	beq _08064CF8
	cmp r5, #2
	bne _08064CFE
_08064C94:
	movs r0, #0
	b _08064CFE
_08064C98:
	cmp r1, #1
	bne _08064CDC
	cmp r5, #0
	bne _08064CB6
	cmp r4, #0
	beq _08064C94
	cmp r4, #2
	beq _08064C94
	cmp r4, #3
	beq _08064C94
	cmp r4, #4
	beq _08064C94
	cmp r4, #5
	beq _08064C94
	b _08064CF8
_08064CB6:
	cmp r5, #1
	beq _08064C94
	cmp r5, #2
	bne _08064CFE
	cmp r4, #0xe
	bne _08064CF8
	ldr r0, _08064CD4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08064CD8 @ =0x00000252
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bge _08064C94
	b _08064CF8
	.align 2, 0
_08064CD4: .4byte 0x030046A0
_08064CD8: .4byte 0x00000252
_08064CDC:
	cmp r1, #5
	beq _08064CF8
	cmp r1, #2
	bne _08064CEA
	cmp r4, #0xf
	beq _08064CF8
	b _08064C94
_08064CEA:
	cmp r1, #3
	bne _08064CF4
	cmp r4, #0x10
	beq _08064CF8
	b _08064C94
_08064CF4:
	cmp r4, #0xe
	bne _08064CFC
_08064CF8:
	movs r0, #1
	b _08064CFE
_08064CFC:
	movs r0, #0
_08064CFE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08064d04
FUN_08064d04: @ 0x08064D04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08064D40 @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08064D48
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bgt _08064D48
	adds r0, r4, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064D48
	ldr r1, _08064D44 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08064D48
	movs r0, #0
	ldrsb r0, [r5, r0]
	b _08064D4C
	.align 2, 0
_08064D40: .4byte 0x00000283
_08064D44: .4byte 0x00000A75
_08064D48:
	movs r0, #1
	rsbs r0, r0, #0
_08064D4C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08064d54
FUN_08064d54: @ 0x08064D54
	push {lr}
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _08064D66
	movs r0, #1
	b _08064D68
_08064D66:
	movs r0, #0
_08064D68:
	pop {r1}
	bx r1

	thumb_func_start FUN_08064d6c
FUN_08064d6c: @ 0x08064D6C
	push {lr}
	adds r2, r1, #0
	ldr r1, _08064D9C @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _08064DA0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _08064DA8
	ldr r3, _08064DA4 @ =0x00000942
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	blt _08064DA8
	movs r0, #1
	b _08064DAA
	.align 2, 0
_08064D9C: .4byte 0x0000038E
_08064DA0: .4byte 0x030046A0
_08064DA4: .4byte 0x00000942
_08064DA8:
	movs r0, #0
_08064DAA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08064db0
FUN_08064db0: @ 0x08064DB0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r2, [r4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	cmp r1, #0
	blt _08064E1A
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _08064DD6
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	b _08064FCE
_08064DD6:
	ldrb r6, [r4, #5]
	cmp r6, #0
	bne _08064E1A
	cmp r1, #5
	bgt _08064E2C
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _08064DF4
	strb r6, [r4, #3]
	ldr r2, _08064DF0 @ =0x00000951
	adds r0, r5, r2
	strb r6, [r0]
	b _08064E1A
	.align 2, 0
_08064DF0: .4byte 0x00000951
_08064DF4:
	movs r6, #1
	strb r6, [r4, #3]
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _08064E1A
	ldr r1, _08064E24 @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08064E28 @ =0x00000964
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x13
	adds r1, r5, r2
	strb r0, [r1]
_08064E1A:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	b _08064FCE
	.align 2, 0
_08064E24: .4byte 0x00000979
_08064E28: .4byte 0x00000964
_08064E2C:
	adds r0, r2, #0
	subs r0, #0xe
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08064E3A
	b _08064F50
_08064E3A:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #1
	bls _08064E48
	b _08064FCE
_08064E48:
	cmp r1, #0xf
	bne _08064EA8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08064EA0
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064F12
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #4
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	ldr r0, _08064EA4 @ =0x00000382
	adds r1, r5, r0
	movs r0, #0xbe
	strb r0, [r1]
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064EA0:
	movs r0, #0xc
	b _08064FCE
	.align 2, 0
_08064EA4: .4byte 0x00000382
_08064EA8:
	cmp r1, #0x10
	bne _08064EFC
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08064EF8
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064F12
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #0x20
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064EF8:
	movs r0, #0xd
	b _08064FCE
_08064EFC:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08064F4C
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	bne _08064F16
_08064F12:
	ldrb r0, [r4]
	b _08064FCE
_08064F16:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r2, #0x3c
	adds r1, r5, r2
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xe8
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	str r6, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r6, [r4]
	adds r0, r5, #0
	bl FUN_08064be4
_08064F4C:
	movs r0, #0xe
	b _08064FCE
_08064F50:
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bhi _08064FCE
	cmp r1, #0x11
	bne _08064F6E
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064FC8
	movs r0, #0xb
	b _08064FCE
_08064F6E:
	cmp r1, #6
	bne _08064F76
	movs r0, #0xa
	b _08064FCE
_08064F76:
	cmp r1, #7
	beq _08064F7E
	cmp r1, #9
	bne _08064F82
_08064F7E:
	movs r0, #9
	b _08064FCE
_08064F82:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #8
	bne _08064F9E
	adds r0, r5, #0
	bl FUN_08064b90
	cmp r0, #0
	beq _08064FC8
	adds r0, r5, #0
	bl FUN_08064be4
	movs r0, #2
	b _08064FCE
_08064F9E:
	cmp r0, #0xb
	bne _08064FA6
	movs r0, #2
	b _08064FCE
_08064FA6:
	cmp r0, #0xd
	bne _08064FBC
	ldr r1, _08064FB8 @ =0x000003FB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08064FC8
	movs r0, #0x11
	b _08064FCE
	.align 2, 0
_08064FB8: .4byte 0x000003FB
_08064FBC:
	cmp r0, #0xa
	bne _08064FC4
	movs r0, #0xf
	b _08064FCE
_08064FC4:
	cmp r0, #0xc
	beq _08064FCC
_08064FC8:
	ldrb r0, [r6]
	b _08064FCE
_08064FCC:
	movs r0, #0x10
_08064FCE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08064fd8
FUN_08064fd8: @ 0x08064FD8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r7
	bne _08064FEE
	b _080650FE
_08064FEE:
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _08064FFE
	movs r1, #0
	strb r1, [r4, #3]
	ldr r2, _08065010 @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_08064FFE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08065014
	adds r0, r5, #0
	movs r1, #0xc
	b _0806501C
	.align 2, 0
_08065010: .4byte 0x00000951
_08065014:
	cmp r0, #3
	bne _08065024
	adds r0, r5, #0
	movs r1, #0xd
_0806501C:
	movs r2, #0
	bl FUN_08060b84
	b _08065032
_08065024:
	cmp r0, #4
	bne _08065032
	adds r0, r5, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
_08065032:
	movs r6, #0
	strb r7, [r4]
	lsls r0, r7, #0x18
	cmp r0, #0
	bge _08065068
	strb r6, [r4, #3]
	movs r0, #0xff
	strb r0, [r4, #1]
	strb r6, [r4, #2]
	strb r6, [r4, #4]
	ldr r2, _08065060 @ =0x00000979
	adds r0, r5, r2
	strb r6, [r0]
	ldr r1, _08065064 @ =0x00000962
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080650F0
	subs r2, #0x15
	adds r0, r5, r2
	strh r6, [r0]
	b _080650F0
	.align 2, 0
_08065060: .4byte 0x00000979
_08065064: .4byte 0x00000962
_08065068:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_0824347c
	strb r0, [r4, #1]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	strb r0, [r4, #2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	strb r0, [r4, #4]
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _080650FE
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080650D8
	movs r6, #1
	strb r6, [r4, #3]
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _080650FE
	ldr r1, _080650CC @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080650D0 @ =0x00000964
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, _080650D4 @ =0x00000121
	adds r0, r0, r1
	subs r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x11
	adds r1, r5, r2
	strb r0, [r1]
	b _080650FE
	.align 2, 0
_080650CC: .4byte 0x00000979
_080650D0: .4byte 0x00000964
_080650D4: .4byte 0x00000121
_080650D8:
	strb r6, [r4, #3]
	ldr r1, _08065104 @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08065108 @ =0x00000962
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0
	bne _080650F0
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080650F0:
	movs r1, #0x95
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0806510C @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_080650FE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065104: .4byte 0x00000979
_08065108: .4byte 0x00000962
_0806510C: .4byte 0x00000951

	thumb_func_start FUN_08065110
FUN_08065110: @ 0x08065110
	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0806513C
	ldr r0, _08065138 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _0806515E
	.align 2, 0
_08065138: .4byte 0x030046A0
_0806513C:
	ldr r1, _08065154 @ =0x03002BB0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08065158 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5e
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0806515C
	movs r0, #9
	b _0806515E
	.align 2, 0
_08065154: .4byte 0x03002BB0
_08065158: .4byte 0x030046A0
_0806515C:
	movs r0, #8
_0806515E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08065164
FUN_08065164: @ 0x08065164
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, _08065180 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _08065184
	movs r0, #0xff
	b _0806518A
	.align 2, 0
_08065180: .4byte 0x030047A4
_08065184:
	adds r0, r5, #0
	bl FUN_08065110
_0806518A:
	strb r0, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _080651A2
	movs r0, #0xff
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #4]
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	b _080651F4
_080651A2:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_0824347c
	strb r0, [r4, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	strb r0, [r4, #4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	strb r0, [r4, #2]
	ldr r1, _080651D8 @ =0x03002BB0
	ldrh r1, [r1]
	adds r2, r1, #0
	strb r1, [r4, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080651DC
	strb r0, [r4, #3]
	b _080651F4
	.align 2, 0
_080651D8: .4byte 0x03002BB0
_080651DC:
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _080651F4
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080651F4
	adds r1, #1
	ldr r2, _080651FC @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_080651F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080651FC: .4byte 0x00000951

	thumb_func_start FUN_08065200
FUN_08065200: @ 0x08065200
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08065212
	bl fetch_082316e4
_08065212:
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806521c
FUN_0806521c: @ 0x0806521C
	push {lr}
	ldr r1, _0806523C @ =0x0000FFFF
	adds r3, r1, #0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #9
_0806522A:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0806522A
	pop {r0}
	bx r0
	.align 2, 0
_0806523C: .4byte 0x0000FFFF
