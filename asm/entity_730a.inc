	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080223f4
FUN_080223f4: @ 0x080223F4
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _08022418 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	beq _0802241C
	movs r0, #0
	strh r4, [r3]
	strb r2, [r3, #2]
	strb r0, [r3, #6]
	strb r0, [r3, #7]
	strb r0, [r3, #3]
	adds r0, r1, #0
	adds r1, r3, #0
	bl FUN_080220e8
	b _08022420
	.align 2, 0
_08022418: .4byte 0x03002B4C
_0802241C:
	movs r0, #1
	rsbs r0, r0, #0
_08022420:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022428
FUN_08022428: @ 0x08022428
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802243C @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022440
	bl FUN_08022104
	b _08022444
	.align 2, 0
_0802243C: .4byte 0x03002B4C
_08022440:
	movs r0, #1
	rsbs r0, r0, #0
_08022444:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022448
FUN_08022448: @ 0x08022448
	push {lr}
	ldr r0, _08022458 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	bne _0802245C
	movs r0, #1
	rsbs r0, r0, #0
	b _0802246E
	.align 2, 0
_08022458: .4byte 0x03002B4C
_0802245C:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _0802246A
	movs r0, #1
	strb r0, [r1, #0x1e]
	movs r0, #0
	b _0802246E
_0802246A:
	movs r0, #2
	rsbs r0, r0, #0
_0802246E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022474
FUN_08022474: @ 0x08022474
	push {lr}
	ldrb r1, [r1, #3]
	cmp r1, #0
	bne _08022480
	movs r0, #0
	b _08022484
_08022480:
	strb r1, [r0, #3]
	movs r0, #1
_08022484:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022488
FUN_08022488: @ 0x08022488
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, r1
	beq _08022496
	movs r0, #0
	b _080224A0
_08022496:
	bl FUN_08022448
	movs r0, #0
	strb r0, [r4, #3]
	movs r0, #1
_080224A0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080224a8
FUN_080224a8: @ 0x080224A8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080224B8 @ =0x03002B4C
	ldr r3, [r0]
	cmp r3, #0
	bne _080224C6
	b _080224E8
	.align 2, 0
_080224B8: .4byte 0x03002B4C
_080224BC:
	adds r0, r3, #0
	adds r0, #0x48
	adds r0, r0, r4
	ldrh r0, [r0]
	b _080224EA
_080224C6:
	movs r2, #0
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r2, r0
	bge _080224E8
	adds r5, r0, #0
	adds r1, r3, #0
	adds r1, #0x28
_080224D8:
	lsls r4, r2, #1
	ldrh r0, [r1]
	cmp r0, r6
	beq _080224BC
	adds r1, #2
	adds r2, #1
	cmp r2, r5
	blt _080224D8
_080224E8:
	movs r0, #0
_080224EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080224f0
FUN_080224f0: @ 0x080224F0
	push {lr}
	adds r1, r0, #0
	ldr r0, _08022504 @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022508
	bl FUN_08022128
	b _0802250C
	.align 2, 0
_08022504: .4byte 0x03002B4C
_08022508:
	movs r0, #1
	rsbs r0, r0, #0
_0802250C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022510
FUN_08022510: @ 0x08022510
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08022530 @ =0x03002B4C
	ldr r7, [r0]
	cmp r7, #0
	beq _08022528
	adds r1, r7, #0
	adds r1, #0x23
	ldrb r0, [r1]
	cmp r0, #1
	bne _08022534
_08022528:
	movs r0, #1
	rsbs r0, r0, #0
	b _080225C8
	.align 2, 0
_08022530: .4byte 0x03002B4C
_08022534:
	movs r0, #0
	mov r8, r0
	movs r5, #1
	strb r5, [r1]
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x64
	adds r1, r4, #0
	bl Script_GetKeywordValue
	movs r6, #0
	strh r0, [r7, #0x18]
	movs r0, #0x63
	adds r1, r4, #0
	bl Script_GetKeywordValue
	subs r0, #1
	strh r0, [r7, #0x1a]
	mov r0, r8
	strh r0, [r7, #0x1c]
	strb r5, [r7, #0x1e]
	strb r6, [r7, #0x1f]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x22
	strb r6, [r4]
	movs r0, #0x70
	bl prepare_08231510
	adds r6, r7, #0
	adds r6, #0x78
	cmp r0, #0
	beq _080225BE
	movs r5, #0
	b _0802259A
_08022582:
	bl Script_GetValue
	ldrb r2, [r4]
	lsls r2, r2, #1
	adds r1, r7, #0
	adds r1, #0x48
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
_0802259A:
	cmp r5, #0xf
	bgt _080225BE
	bl VM_GetPC
	cmp r0, #0
	beq _080225BE
	bl Script_GetValue
	ldrb r2, [r4]
	lsls r2, r2, #1
	adds r1, r7, #0
	adds r1, #0x28
	adds r1, r1, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	bne _08022582
_080225BE:
	movs r0, #0
	str r0, [r7, #0x6c]
	strb r0, [r6, #6]
	strb r0, [r6, #7]
	strb r0, [r6, #3]
_080225C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080225d4
FUN_080225d4: @ 0x080225D4
	push {lr}
	ldr r0, _08022608 @ =0x03002B4C
	ldr r2, [r0]
	cmp r2, #0
	beq _08022610
	adds r0, r2, #0
	adds r0, #0x23
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0802260C @ =0x0000FFFF
	strh r0, [r2, #0x18]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2, #0x1a]
	movs r0, #0
	strh r1, [r2, #0x1c]
	strb r0, [r2, #0x1e]
	strb r0, [r2, #0x1f]
	strh r1, [r2, #0x20]
	adds r3, r2, #0
	adds r3, #0x22
	strb r0, [r3]
	str r1, [r2, #0x6c]
	movs r0, #0
	b _08022614
	.align 2, 0
_08022608: .4byte 0x03002B4C
_0802260C: .4byte 0x0000FFFF
_08022610:
	movs r0, #1
	rsbs r0, r0, #0
_08022614:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022618
FUN_08022618: @ 0x08022618
	push {lr}
	ldr r0, _08022630 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	beq _08022628
	ldr r0, [r1, #0x70]
	cmp r0, #0
	bne _08022634
_08022628:
	movs r0, #1
	rsbs r0, r0, #0
	b _0802263E
	.align 2, 0
_08022630: .4byte 0x03002B4C
_08022634:
	movs r0, #0
	str r0, [r1, #0x70]
	bl FUN_08022448
	movs r0, #0
_0802263E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022644
FUN_08022644: @ 0x08022644
	push {lr}
	ldr r0, _0802265C @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022656
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #1
	beq _08022660
_08022656:
	movs r0, #0
	b _08022662
	.align 2, 0
_0802265C: .4byte 0x03002B4C
_08022660:
	movs r0, #1
_08022662:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022668
FUN_08022668: @ 0x08022668
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, _080226A4 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xe
	ldrsh r1, [r2, r0]
	movs r5, #0x10
	ldrsh r4, [r2, r5]
	movs r0, #0x12
	ldrsh r3, [r2, r0]
	movs r5, #0x14
	ldrsh r0, [r2, r5]
	str r0, [sp]
	add r0, sp, #4
	adds r2, r4, #0
	bl FUN_08019814
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080226a8
FUN_080226a8: @ 0x080226A8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r2, #0
	ldrh r0, [r5, #8]
	bl FUN_0823b2d0
	adds r4, r0, #0
	cmp r4, #0
	beq _080226F4
	ldrh r0, [r4, #8]
	ldr r3, _080226FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022700 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r4, #0xc
	ldrsh r2, [r5, r4]
	movs r0, #0xe
	ldrsh r3, [r5, r0]
	movs r4, #0x10
	ldrsh r0, [r5, r4]
	str r0, [sp]
	add r0, sp, #4
	bl FUN_08019814
_080226F4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226FC: .4byte 0xFFFF0000
_08022700: .4byte 0x0000FFFF

	thumb_func_start FUN_08022704
FUN_08022704: @ 0x08022704
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r2, #0
	adds r4, #8
	movs r5, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08022718
	ldr r5, _0802276C @ =0x00000FFF
_08022718:
	movs r7, #0xc
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022728
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r5, r0
_08022728:
	movs r7, #0xe
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022738
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r5, r0
_08022738:
	movs r7, #8
	ldrsh r0, [r2, r7]
	movs r6, #3
	cmp r0, #0
	bne _08022744
	movs r6, #2
_08022744:
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r7, #4
	ldrsh r2, [r4, r7]
	movs r0, #6
	ldrsh r3, [r4, r0]
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp]
	str r5, [sp, #4]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802276C: .4byte 0x00000FFF

	thumb_func_start FUN_08022770
FUN_08022770: @ 0x08022770
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r4, #0
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08022782
	ldr r4, _080227F0 @ =0x00000FFF
_08022782:
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _08022792
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r4, r0
_08022792:
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080227A2
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r4, r0
_080227A2:
	movs r5, #2
	ldrsh r0, [r2, r5]
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r3, #6
	ldrsh r1, [r2, r3]
	str r1, [sp, #8]
	movs r5, #8
	ldrsh r3, [r2, r5]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	cmp r0, #0
	bne _080227D0
	cmp r1, #0
	bne _080227D0
	cmp r3, #0
	bne _080227D0
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_080227D0:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #3
	cmp r0, #0
	bne _080227DC
	movs r1, #2
_080227DC:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_0800205c
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080227F0: .4byte 0x00000FFF

	thumb_func_start FUN_080227f4
FUN_080227f4: @ 0x080227F4
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r1, #2
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r5, #4
	ldrsh r1, [r2, r5]
	str r1, [sp, #4]
	movs r0, #6
	ldrsh r3, [r2, r0]
	str r3, [sp, #8]
	movs r5, #8
	ldrsh r4, [r2, r5]
	str r4, [sp, #0xc]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	str r0, [sp, #0x10]
	cmp r1, #0
	bne _0802282C
	cmp r3, #0
	bne _0802282C
	cmp r4, #0
	bne _0802282C
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_0802282C:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #2
	cmp r0, #0
	bne _08022838
	movs r1, #1
_08022838:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802284c
FUN_0802284c: @ 0x0802284C
	movs r3, #8
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x50]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x54]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0802285c
FUN_0802285c: @ 0x0802285C
	movs r1, #0
	str r1, [r0, #0x50]
	str r1, [r0, #0x54]
	bx lr

	thumb_func_start Entity730A_Update_Helper_08022864
Entity730A_Update_Helper_08022864: @ 0x08022864
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x18
	movs r7, #0
	ldr r0, _0802287C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #0
	adds r0, #0x1e
	b _08022968
	.align 2, 0
_0802287C: .4byte 0x03002B4C
_08022880:
	ldr r0, _080228B0 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #7
	bhi _0802295E
	lsls r0, r0, #2
	ldr r1, _080228B4 @ =_080228B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080228B0: .4byte 0x03002B4C
_080228B4: .4byte _080228B8
_080228B8: @ jump table
	.4byte _080228D8 @ case 0
	.4byte _080228E4 @ case 1
	.4byte _080228F0 @ case 2
	.4byte _080228FC @ case 3
	.4byte _08022908 @ case 4
	.4byte _08022914 @ case 5
	.4byte _08022920 @ case 6
	.4byte _08022934 @ case 7
_080228D8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022668
	b _0802292A
_080228E4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080226a8
	b _0802292A
_080228F0:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022704
	b _0802292A
_080228FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022770
	b _0802292A
_08022908:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080227f4
	b _0802292A
_08022914:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802284c
	b _0802292A
_08022920:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802285c
_0802292A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
	b _0802295E
_08022934:
	ldrh r0, [r4, #8]
	ldr r3, _0802297C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022980 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0805f68c
_0802295E:
	adds r7, #1
	ldr r0, _08022984 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
_08022968:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022880
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802297C: .4byte 0xFFFF0000
_08022980: .4byte 0x0000FFFF
_08022984: .4byte 0x03002B4C

	thumb_func_start Entity730A_Update
Entity730A_Update: @ 0x08022988
	push {r4, lr}
	adds r4, r0, #0
	bl Entity730A_Update_Helper_08022864
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq _080229A4
	cmp r0, #0
	ble _0802299E
	subs r0, #1
	str r0, [r4, #0x50]
_0802299E:
	ldr r0, [r4, #0x54]
	bl FUN_0823b9cc
_080229A4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

