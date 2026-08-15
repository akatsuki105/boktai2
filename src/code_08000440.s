	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08000440
FUN_08000440: @ 0x08000440
	push {lr}
	ldr r1, _08000458 @ =0x03000000
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xc
_0800044A:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800044A
	pop {r0}
	bx r0
	.align 2, 0
_08000458: .4byte 0x03000000

	thumb_func_start FUN_0800045c
FUN_0800045c: @ 0x0800045C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	b _080005A8
_0800046E:
	mov r1, sl
	lsls r0, r1, #1
	adds r1, r5, #0
	adds r1, #0x94
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r2, sl
	lsls r0, r2, #4
	adds r0, #0xa4
	adds r3, r5, r0
	cmp r1, #6
	bls _08000488
	b _080005A4
_08000488:
	lsls r0, r1, #2
	ldr r1, _08000494 @ =_08000498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08000494: .4byte _08000498
_08000498: @ jump table
	.4byte _080004B4 @ case 0
	.4byte _080004C2 @ case 1
	.4byte _080004F2 @ case 2
	.4byte _08000520 @ case 3
	.4byte _080005A4 @ case 4
	.4byte _080005A4 @ case 5
	.4byte _08000598 @ case 6
_080004B4:
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	b _080005A4
_080004C2:
	adds r1, r5, #0
	adds r1, #0x70
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldrh r1, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	strh r1, [r0]
	subs r0, #2
	strh r2, [r0]
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #7
	str r0, [r5, #0x40]
	movs r2, #4
	ldrsh r0, [r3, r2]
	lsls r0, r0, #7
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x20]
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x24]
	str r0, [r5, #0x4c]
	b _080005A4
_080004F2:
	adds r0, r5, #0
	adds r0, #0x78
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x7c
	strh r0, [r2]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r3, r5, #0
	adds r3, #0x7e
	strh r0, [r3]
	adds r0, r5, #0
	adds r0, #0x88
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x1b]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	b _0800058E
_08000520:
	adds r1, r5, #0
	adds r1, #0x78
	movs r0, #1
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x7c
	ldrh r0, [r4]
	adds r2, r5, #0
	adds r2, #0x80
	strh r0, [r2]
	movs r0, #0x7e
	adds r0, r0, r5
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #0x82
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	ldrh r0, [r3]
	adds r6, r5, #0
	adds r6, #0x7a
	strh r0, [r6]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x84
	strh r0, [r1]
	ldrh r0, [r3, #4]
	lsls r0, r0, #8
	adds r7, r5, #0
	adds r7, #0x86
	strh r0, [r7]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r6]
	bl Div
	adds r1, r5, #0
	adds r1, #0x88
	strh r0, [r1]
	ldrh r0, [r7]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r6]
	bl Div
	adds r1, r5, #0
	adds r1, #0x8a
	strh r0, [r1]
	ldrb r0, [r5, #0x1b]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	mov r3, sb
_0800058E:
	ldrh r2, [r3]
	lsrs r2, r2, #8
	bl FUN_0822f178
	b _080005A4
_08000598:
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [r5, #0x58]
	movs r2, #2
	ldrsh r0, [r3, r2]
	str r0, [r5, #0x5c]
_080005A4:
	movs r3, #1
	add sl, r3
_080005A8:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r0, [r0]
	cmp sl, r0
	bhs _080005B4
	b _0800046E
_080005B4:
	adds r1, r5, #0
	adds r1, #0x90
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Video_GenerateBackgroundMaps
Video_GenerateBackgroundMaps: @ 0x080005CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_0800045c
	movs r0, #0
	mov r8, r0
	ldrb r1, [r6, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080006C4
	ldr r4, _0800060C @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08000614
	ldr r2, _08000610 @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r7, #8
	ldrsh r0, [r4, r7]
	adds r3, r1, r0
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	adds r4, r1, r0
	b _08000620
	.align 2, 0
_0800060C: .4byte 0x03003540
_08000610: .4byte 0x030047C8
_08000614:
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x13
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x13
_08000620:
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08000632
	ldr r0, [r6, #0x50]
	subs r3, r3, r0
	ldr r0, [r6, #0x54]
	subs r4, r4, r0
_08000632:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08000642
	ldr r0, [r6, #0x58]
	adds r3, r3, r0
	ldr r0, [r6, #0x5c]
	adds r4, r4, r0
_08000642:
	adds r0, r6, #0
	adds r0, #0x76
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r5, r0, #0
	cmp r1, #0x80
	bne _08000658
	adds r7, r3, #0
	subs r7, #0x78
	adds r5, r4, #0
	b _08000692
_08000658:
	ldr r2, [r6, #0x68]
	subs r3, r3, r2
	ldr r1, [r6, #0x6c]
	subs r4, r4, r1
	movs r7, #0
	ldrsh r0, [r5, r7]
	muls r0, r3, r0
	cmp r0, #0
	blt _0800066E
	asrs r0, r0, #7
	b _08000674
_0800066E:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08000674:
	adds r0, r0, r2
	adds r7, r0, #0
	subs r7, #0x78
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08000688
	asrs r0, r0, #7
	b _0800068E
_08000688:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_0800068E:
	adds r0, r0, r1
	adds r5, r0, #0
_08000692:
	subs r5, #0x5a
	adds r4, r5, #0
	adds r4, #0x5a
	adds r0, r7, #0
	subs r0, #8
	cmp r0, #0
	blt _080006A4
	asrs r1, r0, #3
	b _080006AA
_080006A4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080006AA:
	adds r0, r4, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080006B6
	asrs r0, r0, #3
	b _080006BC
_080006B6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080006BC:
	movs r3, #2
	rsbs r3, r3, #0
	mov r8, r3
	b _08000814
_080006C4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08000710
	ldr r1, [r6, #0x38]
	ldr r0, [r6, #0x30]
	adds r1, r1, r0
	str r1, [r6, #0x38]
	ldr r0, [r6, #0x60]
	cmp r1, r0
	ble _080006DE
	subs r0, r1, r0
	b _080006E4
_080006DE:
	cmn r1, r0
	bge _080006E6
	adds r0, r1, r0
_080006E4:
	str r0, [r6, #0x38]
_080006E6:
	ldr r1, [r6, #0x3c]
	ldr r0, [r6, #0x34]
	adds r1, r1, r0
	str r1, [r6, #0x3c]
	ldr r0, [r6, #0x64]
	cmp r1, r0
	ble _080006F8
	subs r0, r1, r0
	b _080006FE
_080006F8:
	cmn r1, r0
	bge _08000700
	adds r0, r1, r0
_080006FE:
	str r0, [r6, #0x3c]
_08000700:
	ldr r0, [r6, #0x38]
	ldr r1, [r6, #0x28]
	adds r0, r0, r1
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x3c]
	ldr r1, [r6, #0x2c]
	adds r0, r0, r1
	b _0800076C
_08000710:
	movs r3, #0x70
	adds r3, r3, r6
	mov sb, r3
	ldrh r0, [r3]
	cmp r0, #1
	bne _0800076E
	adds r4, r6, #0
	adds r4, #0x74
	ldrh r1, [r4]
	adds r7, r6, #0
	adds r7, #0x72
	ldrh r3, [r7]
	subs r5, r1, r3
	ldr r0, [r6, #0x48]
	muls r0, r5, r0
	ldr r2, [r6, #0x40]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x4c]
	muls r0, r5, r0
	ldrh r2, [r7]
	ldr r1, [r6, #0x44]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r4]
	bl Div
	str r0, [r6, #0x24]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4]
	cmp r0, r4
	blo _0800076E
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	strh r1, [r7]
	ldr r0, [r6, #0x40]
	str r0, [r6, #0x20]
	ldr r0, [r6, #0x44]
_0800076C:
	str r0, [r6, #0x24]
_0800076E:
	ldr r0, [r6, #0x20]
	cmp r0, #0
	blt _08000778
	asrs r0, r0, #7
	b _0800077E
_08000778:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_0800077E:
	adds r7, r0, #0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	blt _0800078A
	asrs r0, r0, #7
	b _08000790
_0800078A:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08000790:
	adds r5, r0, #0
	ldrb r1, [r6, #0x1a]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080007E6
	ldr r0, [r6, #0x60]
	asrs r4, r0, #7
	ldr r0, [r6, #0x64]
	asrs r0, r0, #7
	mov r8, r0
	ldr r3, _080007F4 @ =0x030047C8
	movs r0, #0
	ldrsh r2, [r3, r0]
	mov ip, r2
	ldr r2, _080007F8 @ =0x03003540
	movs r0, #8
	ldrsh r1, [r2, r0]
	mov sb, r1
	mov r0, ip
	add r0, sb
	adds r7, r7, r0
	movs r1, #2
	ldrsh r0, [r3, r1]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r5, r5, r0
	cmp r4, #0
	beq _080007D6
	adds r0, r7, #0
	adds r1, r4, #0
	bl Mod
	adds r7, r0, #0
_080007D6:
	mov r0, r8
	cmp r0, #0
	beq _080007E6
	adds r0, r5, #0
	mov r1, r8
	bl Mod
	adds r5, r0, #0
_080007E6:
	adds r4, r5, #0
	cmp r7, #0
	bge _080007FC
	rsbs r0, r7, #0
	asrs r0, r0, #3
	mvns r1, r0
	b _080007FE
	.align 2, 0
_080007F4: .4byte 0x030047C8
_080007F8: .4byte 0x03003540
_080007FC:
	asrs r1, r7, #3
_080007FE:
	cmp r4, #0
	bge _0800080C
	rsbs r0, r4, #0
	asrs r0, r0, #3
	mvns r0, r0
	mov r8, r0
	b _08000810
_0800080C:
	asrs r4, r4, #3
	mov r8, r4
_08000810:
	movs r0, #2
	rsbs r0, r0, #0
_08000814:
	mov r2, r8
	ands r2, r0
	mov r8, r2
	ldrb r0, [r6, #0x1b]
	str r5, [sp]
	mov r2, r8
	adds r3, r7, #0
	bl Video_GenerateBGMap
	adds r4, r6, #0
	adds r4, #0x78
	ldrh r0, [r4]
	cmp r0, #1
	bne _08000872
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r6, #0
	adds r0, #0x88
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r3, r6, #0
	adds r3, #0x7e
	adds r0, r6, #0
	adds r0, #0x8a
	ldrh r2, [r0]
	ldrh r7, [r3]
	adds r2, r2, r7
	strh r2, [r3]
	ldrb r0, [r6, #0x1b]
	ldrh r1, [r1]
	lsrs r1, r1, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x18
	bl FUN_0822f178
	adds r1, r6, #0
	adds r1, #0x7a
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08000872
	strh r0, [r4]
_08000872:
	ldrb r1, [r6, #0x1a]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080008B6
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080008A4
	movs r0, #0x80
	lsls r0, r0, #0x11
	ldrb r2, [r6, #0x1b]
	lsls r0, r2
	lsrs r0, r0, #0x10
	ldr r2, _080008A0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080008B6
	.align 2, 0
_080008A0: .4byte 0x03003E78
_080008A4:
	movs r0, #0x80
	lsls r0, r0, #0x11
	ldrb r3, [r6, #0x1b]
	lsls r0, r3
	lsrs r0, r0, #0x10
	ldr r2, _080008D4 @ =0x03003E78
	ldrh r1, [r2]
	bics r1, r0
	strh r1, [r2]
_080008B6:
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080008D4: .4byte 0x03003E78

	thumb_func_start FUN_080008d8
FUN_080008d8: @ 0x080008D8
	ldr r1, _080008E8 @ =0x03000000
	ldrb r0, [r0, #0x1b]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]

	thumb_func_start FUN_080008e4
FUN_080008e4: @ 0x080008E4
	movs r0, #0
	bx lr
	.align 2, 0
_080008E8: .4byte 0x03000000

	thumb_func_start FUN_080008ec
FUN_080008ec: @ 0x080008EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r2, #0
	ldr r2, _08000948 @ =0x03000000
	ldrb r0, [r6, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r5, [r0]
	strh r1, [r5, #0x18]
	ldrb r0, [r6]
	strb r0, [r5, #0x1a]
	ldrb r0, [r6, #1]
	strb r0, [r5, #0x1b]
	ldrb r1, [r5, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _0800094C @ =0x03003ED0
	adds r0, r0, r1
	mov sl, r0
	ldrh r0, [r6, #2]
	str r0, [r5, #0x1c]
	bl FUN_0822ccc4
	str r0, [sp, #0x10]
	ldrb r1, [r5, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08000954
	ldr r0, _08000950 @ =0x000056C2
	bl FUN_08230e70
	ldr r0, [r0, #4]
	movs r2, #8
	ldrsh r1, [r0, r2]
	mov r8, r1
	movs r4, #0xa
	ldrsh r3, [r0, r4]
	mov sb, r3
	b _0800095A
	.align 2, 0
_08000948: .4byte 0x03000000
_0800094C: .4byte 0x03003ED0
_08000950: .4byte 0x000056C2
_08000954:
	movs r0, #0
	mov r8, r0
	mov sb, r0
_0800095A:
	ldrb r1, [r5, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08000988
	ldr r3, _08000980 @ =0x030047C8
	movs r2, #0
	ldrsh r1, [r3, r2]
	ldr r2, _08000984 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r2, r1, r0
	b _0800098C
	.align 2, 0
_08000980: .4byte 0x030047C8
_08000984: .4byte 0x03003540
_08000988:
	ldr r4, [r6, #4]
	ldr r2, [r6, #8]
_0800098C:
	ldr r0, [r6, #0x14]
	adds r1, r5, #0
	adds r1, #0x76
	movs r3, #0
	strh r0, [r1]
	adds r0, r4, #0
	subs r0, #0x78
	mov r1, sl
	strh r0, [r1, #0x20]
	adds r0, r2, #0
	subs r0, #0x5a
	strh r0, [r1, #0x22]
	lsls r1, r4, #7
	str r1, [r5, #0x20]
	lsls r0, r2, #7
	str r0, [r5, #0x24]
	str r1, [r5, #0x28]
	str r0, [r5, #0x2c]
	str r1, [r5, #0x40]
	str r0, [r5, #0x44]
	ldr r0, [r6, #0xc]
	str r0, [r5, #0x30]
	ldr r0, [r6, #0x10]
	str r0, [r5, #0x34]
	str r3, [r5, #0x38]
	str r3, [r5, #0x3c]
	mov r2, r8
	asrs r0, r2, #7
	str r0, [r5, #0x50]
	mov r4, sb
	asrs r0, r4, #7
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x28]
	str r0, [r5, #0x58]
	ldr r0, [r6, #0x2c]
	str r0, [r5, #0x5c]
	ldr r0, [r6, #0x18]
	lsls r0, r0, #0xa
	str r0, [r5, #0x60]
	ldr r0, [r6, #0x1c]
	lsls r0, r0, #0xa
	str r0, [r5, #0x64]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x68]
	ldr r0, [r6, #0x24]
	str r0, [r5, #0x6c]
	adds r0, r5, #0
	adds r0, #0x70
	strh r3, [r0]
	adds r0, #4
	strh r3, [r0]
	subs r0, #2
	strh r3, [r0]
	adds r0, #6
	strh r3, [r0]
	ldr r0, [r6, #0x38]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x7c
	strh r0, [r2]
	ldr r0, [r6, #0x3c]
	lsls r0, r0, #8
	movs r1, #0x7e
	adds r1, r1, r5
	mov ip, r1
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x88
	strh r3, [r4]
	adds r7, r5, #0
	adds r7, #0x8a
	strh r3, [r7]
	ldrh r1, [r2]
	adds r0, r5, #0
	adds r0, #0x84
	strh r1, [r0]
	mov r3, ip
	ldrh r0, [r3]
	adds r1, r5, #0
	adds r1, #0x86
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r4]
	ldrh r0, [r3]
	strh r0, [r7]
	ldrb r1, [r5, #0x1a]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r7, r0, #0x1f
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08000A60
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08000A60
	mov r0, sl
	strh r7, [r0]
	ldrb r0, [r5, #0x1b]
	ldr r1, [r6, #0x30]
	bl SetBGPrioDirect
	b _08000A82
_08000A60:
	ldrb r0, [r5, #0x1b]
	bl GetTilemapBuffer
	ldrb r3, [r5, #0x1b]
	adds r1, r7, #0
	mov r2, r8
	str r2, [sp]
	mov r4, sb
	str r4, [sp, #4]
	ldr r2, [r6, #0x30]
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r3, #0
	ldr r2, [sp, #0x10]
	movs r3, #0
	bl FUN_0822bfbc
_08000A82:
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08000a94
FUN_08000a94: @ 0x08000A94
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r5, #0x34]
	cmp r0, #0
	bne _08000AAA
	movs r1, #0x94
	lsls r1, r1, #1
	movs r0, #9
	b _08000AB0
_08000AAA:
	movs r1, #0x94
	lsls r1, r1, #1
	movs r0, #0xb
_08000AB0:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08000AE4
	ldr r1, _08000ADC @ =Video_GenerateBackgroundMaps
	ldr r2, _08000AE0 @ =FUN_080008d8
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080008ec
	cmp r0, #0
	bge _08000AE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08000AE6
	.align 2, 0
_08000ADC: .4byte Video_GenerateBackgroundMaps
_08000AE0: .4byte FUN_080008d8
_08000AE4:
	adds r0, r4, #0
_08000AE6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08000aec
FUN_08000aec: @ 0x08000AEC
	push {r4, r5, lr}
	sub sp, #0x40
	adds r5, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strb r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strb r0, [r1, #1]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x72
	movs r1, #0x80
	bl Script_GetKeywordValue
	str r0, [sp, #0x14]
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _08000B48
	cmp r0, #1
	bgt _08000B32
	cmp r0, #0
	beq _08000B3C
	b _08000B52
_08000B32:
	cmp r0, #2
	beq _08000B42
	cmp r0, #3
	beq _08000B48
	b _08000B52
_08000B3C:
	movs r0, #0x70
	movs r1, #0
	b _08000B4C
_08000B42:
	movs r0, #0x70
	movs r1, #3
	b _08000B4C
_08000B48:
	movs r0, #0x70
	movs r1, #1
_08000B4C:
	bl Script_GetKeywordValue
	str r0, [sp, #0x30]
_08000B52:
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x34]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08000B82
	bl VM_GetPC
	cmp r0, #0
	beq _08000B72
	bl VM_GetValueAt
_08000B72:
	str r0, [sp, #4]
	bl VM_GetPC
	cmp r0, #0
	beq _08000B84
	bl VM_GetValueAt
	b _08000B84
_08000B82:
	str r0, [sp, #4]
_08000B84:
	str r0, [sp, #8]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08000BAC
	bl VM_GetPC
	cmp r0, #0
	beq _08000B9C
	bl VM_GetValueAt
_08000B9C:
	str r0, [sp, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _08000BAE
	bl VM_GetValueAt
	b _08000BAE
_08000BAC:
	str r0, [sp, #0xc]
_08000BAE:
	str r0, [sp, #0x10]
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _08000BD6
	bl VM_GetPC
	cmp r0, #0
	beq _08000BC6
	bl VM_GetValueAt
_08000BC6:
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _08000BD8
	bl VM_GetValueAt
	b _08000BD8
_08000BD6:
	str r0, [sp, #0x18]
_08000BD8:
	str r0, [sp, #0x1c]
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08000C04
	bl VM_GetPC
	cmp r0, #0
	beq _08000BF2
	bl VM_GetValueAt
	b _08000BF4
_08000BF2:
	movs r0, #0x78
_08000BF4:
	str r0, [sp, #0x20]
	bl VM_GetPC
	cmp r0, #0
	beq _08000C08
	bl VM_GetValueAt
	b _08000C0A
_08000C04:
	movs r0, #0x78
	str r0, [sp, #0x20]
_08000C08:
	movs r0, #0x5a
_08000C0A:
	str r0, [sp, #0x24]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08000C32
	bl VM_GetPC
	cmp r0, #0
	beq _08000C22
	bl VM_GetValueAt
_08000C22:
	str r0, [sp, #0x28]
	bl VM_GetPC
	cmp r0, #0
	beq _08000C34
	bl VM_GetValueAt
	b _08000C34
_08000C32:
	str r0, [sp, #0x28]
_08000C34:
	str r0, [sp, #0x2c]
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _08000C72
	bl VM_GetPC
	cmp r0, #0
	beq _08000C50
	bl VM_GetValueAt
	adds r4, r0, #0
	b _08000C52
_08000C50:
	movs r4, #0
_08000C52:
	bl VM_GetPC
	cmp r0, #0
	beq _08000C62
	bl VM_GetValueAt
	adds r2, r0, #0
	b _08000C64
_08000C62:
	movs r2, #8
_08000C64:
	str r4, [sp, #0x38]
	str r2, [sp, #0x3c]
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r1, r4, #0
	bl FUN_0822f178
_08000C72:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_08000a94
	add sp, #0x40
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08000c84
FUN_08000c84: @ 0x08000C84
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, [r0, #0xc]
	movs r3, #0
	ldrh r0, [r0, #4]
	cmp r3, r0
	bge _08000CA8
	adds r1, r0, #0
_08000C96:
	ldrh r0, [r2, #4]
	cmp r0, r4
	bne _08000CA0
	adds r0, r3, #0
	b _08000CAA
_08000CA0:
	adds r2, #0xc
	adds r3, #1
	cmp r3, r1
	blt _08000C96
_08000CA8:
	movs r0, #0
_08000CAA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Video_LoadTileMap
Video_LoadTileMap: @ 0x08000CB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_0822ccc4
	adds r6, r0, #0
	add r4, sp, #0x1c
	adds r1, r4, #0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r4, #0xc]
	adds r0, r0, r6
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	adds r0, r0, r6
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x14]
	adds r0, r0, r6
	str r0, [r4, #0x14]
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _08000D24
	bl VM_GetPC
	cmp r0, #0
	beq _08000D10
	bl VM_GetValueAt
	lsls r0, r0, #7
	b _08000D12
_08000D10:
	movs r0, #0
_08000D12:
	mov r8, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08000D28
	bl VM_GetValueAt
	lsls r7, r0, #7
	b _08000D2A
_08000D24:
	movs r2, #0
	mov r8, r2
_08000D28:
	movs r7, #0
_08000D2A:
	movs r0, #0x6e
	movs r1, #1
	bl Script_GetKeywordValue
	mov sb, r0
	movs r5, #0
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08000D6C
	bl VM_GetPC
	adds r2, r0, #0
	movs r5, #1
	add r4, sp, #0xc
_08000D4C:
	cmp r2, #0
	beq _08000D60
	adds r0, r2, #0
	bl VM_GetValueAt
	str r0, [r4]
	bl VM_GetPC
	adds r2, r0, #0
	b _08000D62
_08000D60:
	str r2, [r4]
_08000D62:
	adds r4, #4
	add r1, sp, #0x18
	cmp r4, r1
	ble _08000D4C
	b _08000D7A
_08000D6C:
	movs r4, #3
	add r1, sp, #0x18
_08000D70:
	str r4, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	bge _08000D70
_08000D7A:
	cmp r5, #0
	bne _08000DBA
	movs r0, #0x63
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08000DBA
	bl VM_GetPC
	adds r1, r0, #0
	add r5, sp, #0xc
	movs r4, #3
_08000D94:
	cmp r1, #0
	beq _08000DB2
	adds r0, r1, #0
	bl VM_GetValueAt
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r0, sp, #0x1c
	bl FUN_08000c84
	str r0, [r5]
	bl VM_GetPC
	adds r1, r0, #0
_08000DB2:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08000D94
_08000DBA:
	ldrb r1, [r6]
	cmp r1, #0x4d
	bne _08000DE4
	ldrb r1, [r6, #1]
	cmp r1, #0x50
	bne _08000DE4
	mov r5, r8
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	add r2, sp, #0xc
	str r2, [sp, #8]
	mov r0, sl
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0822c0b8
_08000DE4:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08000df4
FUN_08000df4: @ 0x08000DF4
	push {r4, r5, r6, lr}
	sub sp, #0x18
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_0822ccc4
	adds r5, r0, #0
	mov r1, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [sp, #0xc]
	adds r0, r0, r5
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, r0, r5
	str r0, [sp, #0x14]
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08000E4A
	bl VM_GetPC
	cmp r0, #0
	beq _08000E4A
	bl VM_GetValueAt
	b _08000E74
_08000E4A:
	movs r4, #0
	movs r0, #0
	cmp r0, #0
	bne _08000E78
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08000E78
	bl VM_GetPC
	cmp r0, #0
	beq _08000E78
	bl VM_GetValueAt
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sp
	bl FUN_08000c84
_08000E74:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08000E78:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0822c398
	adds r0, r4, #0
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08000e8c
FUN_08000e8c: @ 0x08000E8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov r8, r0
	adds r0, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	bl FUN_0822ccc4
	adds r5, r0, #0
	mov r1, sp
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [sp, #0xc]
	adds r0, r0, r5
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, r0, r5
	str r0, [sp, #0x14]
	cmp r4, #0
	bne _08000ED4
	mov r0, sp
	adds r1, r6, #0
	bl FUN_08000c84
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08000ED4:
	mov r0, r8
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0822c398
	adds r0, r6, #0
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Video_LoadTileSet
Video_LoadTileSet: @ 0x08000EEC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x9c
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08000F54 @ =0x0000CEEF
	adds r1, r4, #0
	bl GetFile
	mov r8, r0
	movs r6, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08000F58
	movs r5, #0
	add r4, sp, #4
_08000F38:
	cmp r5, #0x3f
	bgt _08000F68
	bl VM_GetPC
	cmp r0, #0
	beq _08000F68
	bl VM_GetValueAt
	strh r0, [r4]
	adds r6, #1
	adds r4, #2
	adds r5, #1
	b _08000F38
	.align 2, 0
_08000F54: .4byte 0x0000CEEF
_08000F58:
	movs r1, #0
	mov r0, sp
	adds r0, #0x82
_08000F5E:
	strh r1, [r0]
	subs r0, #2
	add r2, sp, #4
	cmp r0, r2
	bge _08000F5E
_08000F68:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08000F8C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_0822ccc4
	add r2, sp, #0x84
	adds r1, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldrh r7, [r2, #0xa]
_08000F8C:
	str r7, [sp]
	mov r0, sb
	mov r1, r8
	adds r2, r6, #0
	add r3, sp, #4
	bl FUN_0822bc44
	movs r0, #0
	add sp, #0x9c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08000fac
FUN_08000fac: @ 0x08000FAC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r5, r2, #0
	mov ip, r3
	ldr r1, _08001000 @ =0x03000000
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _08000FFA
	adds r0, r3, #0
	adds r0, #0x90
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #7
	bhi _08000FFA
	lsls r1, r1, #1
	adds r0, #4
	adds r0, r0, r1
	strh r6, [r0]
	movs r2, #0
	cmp r2, r5
	bge _08000FF4
	adds r7, r4, #0
	adds r3, #0xa4
	mov r6, ip
_08000FE0:
	lsls r0, r2, #1
	ldr r1, [r7]
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r3, r0
	ldm r6!, {r1}
	strh r1, [r0]
	adds r2, #1
	cmp r2, r5
	blt _08000FE0
_08000FF4:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_08000FFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001000: .4byte 0x03000000

	thumb_func_start FUN_08001004
FUN_08001004: @ 0x08001004
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08001040
	mov r5, sp
	b _08001034
_0800102C:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_08001034:
	bl VM_GetPC
	cmp r0, #0
	beq _08001040
	cmp r4, #7
	ble _0800102C
_08001040:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, sp
	bl FUN_08000fac
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08001054
FUN_08001054: @ 0x08001054
	push {lr}
	ldr r1, _0800106C @ =0x03000010
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xc
_0800105E:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800105E
	pop {r0}
	bx r0
	.align 2, 0
_0800106C: .4byte 0x03000010

	thumb_func_start FUN_08001070
FUN_08001070: @ 0x08001070
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0
	mov sl, r0
	b _080011C0
_08001082:
	mov r1, sl
	lsls r0, r1, #1
	adds r1, r7, #0
	adds r1, #0x68
	adds r1, r1, r0
	ldrh r1, [r1]
	mov r2, sl
	lsls r0, r2, #4
	adds r0, #0x78
	adds r3, r7, r0
	cmp r1, #5
	bls _0800109C
	b _080011BC
_0800109C:
	lsls r0, r1, #2
	ldr r1, _080010A8 @ =_080010AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080010A8: .4byte _080010AC
_080010AC: @ jump table
	.4byte _080010C4 @ case 0
	.4byte _080010D6 @ case 1
	.4byte _08001124 @ case 2
	.4byte _08001134 @ case 3
	.4byte _080011AC @ case 4
	.4byte _080011B4 @ case 5
_080010C4:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	strh r0, [r7, #0x26]
	strh r0, [r7, #0x28]
	b _080011BC
_080010D6:
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldrh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x48
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x46
	strh r2, [r0]
	movs r1, #2
	ldrsh r0, [r3, r1]
	lsls r0, r0, #4
	strh r0, [r7, #0x38]
	movs r2, #4
	ldrsh r0, [r3, r2]
	lsls r0, r0, #4
	strh r0, [r7, #0x3a]
	movs r3, #0x38
	ldrsh r0, [r7, r3]
	movs r2, #0x1e
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	strh r0, [r7, #0x26]
	movs r3, #0x3a
	ldrsh r0, [r7, r3]
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	strh r0, [r7, #0x28]
	b _080011BC
_08001124:
	ldrb r0, [r7, #0x1b]
	movs r4, #0
	ldrsh r1, [r3, r4]
	movs r4, #2
	ldrsh r2, [r3, r4]
	bl FUN_0822f178
	b _080011BC
_08001134:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #1
	strh r0, [r1]
	movs r0, #0x52
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0x56
	strh r0, [r2]
	movs r1, #0x54
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	adds r6, r7, #0
	adds r6, #0x58
	strh r0, [r6]
	ldrh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x50
	strh r0, [r4]
	ldrh r0, [r3, #2]
	lsls r0, r0, #8
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r3, #4]
	lsls r0, r0, #8
	adds r5, r7, #0
	adds r5, #0x5c
	strh r0, [r5]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	adds r1, r7, #0
	adds r1, #0x5e
	strh r0, [r1]
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	ldrh r1, [r4]
	bl Div
	adds r1, r7, #0
	adds r1, #0x60
	strh r0, [r1]
	ldrb r0, [r7, #0x1b]
	mov r2, sb
	ldrh r1, [r2]
	lsrs r1, r1, #8
	mov r3, r8
	ldrh r2, [r3]
	lsrs r2, r2, #8
	bl FUN_0822f178
	b _080011BC
_080011AC:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	b _080011BA
_080011B4:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #1
_080011BA:
	strb r0, [r1]
_080011BC:
	movs r4, #1
	add sl, r4
_080011C0:
	ldr r0, [r7, #0x64]
	cmp sl, r0
	bhs _080011C8
	b _08001082
_080011C8:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080011d8
FUN_080011d8: @ 0x080011D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrb r1, [r7, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08001208 @ =0x03003ED0
	adds r0, r0, r1
	mov r8, r0
	adds r0, r7, #0
	bl FUN_08001070
	adds r1, r7, #0
	adds r1, #0x4c
	ldrb r1, [r1]
	cmp r1, #0
	bne _0800120C
	movs r0, #0
	b _08001416
	.align 2, 0
_08001208: .4byte 0x03003ED0
_0800120C:
	adds r4, r7, #0
	adds r4, #0x40
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r5, r1, #4
	adds r3, r7, #0
	adds r3, #0x42
	movs r2, #0
	ldrsh r1, [r3, r2]
	lsls r1, r1, #4
	mov ip, r1
	ldrb r2, [r7, #0x1a]
	movs r1, #8
	ands r1, r2
	mov sl, r4
	str r3, [sp]
	cmp r1, #0
	beq _080012DE
	ldr r1, _08001284 @ =0x03002BAC
	ldrh r2, [r1]
	adds r1, r7, #0
	adds r1, #0x4a
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r6, r2, #0
	muls r6, r1, r6
	ldr r1, _08001288 @ =0x03002B90
	ldrh r2, [r1]
	adds r2, #0xa0
	movs r4, #0xff
	ands r2, r4
	ldr r1, _0800128C @ =0x085B0A08
	mov sb, r1
	adds r1, r2, #0
	adds r1, #0x40
	ands r1, r4
	lsls r1, r1, #1
	add r1, sb
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r3, r1, #0
	muls r3, r6, r3
	ldr r1, [r7, #0x30]
	adds r3, r1, r3
	str r3, [r7, #0x30]
	ands r2, r4
	lsls r2, r2, #1
	add r2, sb
	movs r4, #0
	ldrsh r1, [r2, r4]
	adds r2, r1, #0
	muls r2, r6, r2
	ldr r1, [r7, #0x34]
	adds r1, r1, r2
	str r1, [r7, #0x34]
	cmp r3, #0
	blt _08001290
	asrs r1, r3, #0x12
	b _08001296
	.align 2, 0
_08001284: .4byte 0x03002BAC
_08001288: .4byte 0x03002B90
_0800128C: .4byte 0x085B0A08
_08001290:
	rsbs r1, r3, #0
	asrs r1, r1, #0x12
	rsbs r1, r1, #0
_08001296:
	adds r2, r1, #0
	ldr r1, [r7, #0x34]
	cmp r1, #0
	blt _080012A2
	asrs r1, r1, #0x12
	b _080012A8
_080012A2:
	rsbs r1, r1, #0
	asrs r1, r1, #0x12
	rsbs r1, r1, #0
_080012A8:
	adds r3, r1, #0
	cmp r2, r5
	ble _080012B2
	subs r2, r2, r5
	b _080012B8
_080012B2:
	cmn r2, r5
	bge _080012B8
	adds r2, r2, r5
_080012B8:
	cmp r3, ip
	ble _080012C2
	mov r5, ip
	subs r3, r3, r5
	b _080012CA
_080012C2:
	mov r1, ip
	cmn r3, r1
	bge _080012CA
	add r3, ip
_080012CA:
	ldrh r1, [r7, #0x22]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	ldrh r2, [r7, #0x24]
	adds r2, r2, r3
	strh r2, [r7, #0x20]
	mov r2, r8
	strh r1, [r2, #0x20]
	ldrh r1, [r7, #0x20]
	b _08001358
_080012DE:
	movs r3, #0x2a
	ldrsh r2, [r7, r3]
	ldr r1, [r7, #0x30]
	adds r1, r1, r2
	str r1, [r7, #0x30]
	cmp r1, r5
	ble _080012F0
	subs r1, r1, r5
	b _080012F6
_080012F0:
	cmn r1, r5
	bge _080012F8
	adds r1, r1, r5
_080012F6:
	str r1, [r7, #0x30]
_080012F8:
	movs r4, #0x2c
	ldrsh r2, [r7, r4]
	ldr r1, [r7, #0x34]
	adds r1, r1, r2
	str r1, [r7, #0x34]
	cmp r1, ip
	ble _0800130C
	mov r5, ip
	subs r1, r1, r5
	b _08001314
_0800130C:
	mov r2, ip
	cmn r1, r2
	bge _08001316
	add r1, ip
_08001314:
	str r1, [r7, #0x34]
_08001316:
	ldr r1, [r7, #0x30]
	ldrh r2, [r7, #0x22]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	ldr r1, [r7, #0x34]
	ldrh r2, [r7, #0x24]
	adds r1, r1, r2
	strh r1, [r7, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r7, r3]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	blt _08001336
	asrs r1, r2, #0x14
	b _0800133C
_08001336:
	rsbs r1, r1, #0
	asrs r1, r1, #4
	rsbs r1, r1, #0
_0800133C:
	mov r4, r8
	strh r1, [r4, #0x20]
	movs r5, #0x20
	ldrsh r1, [r7, r5]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	blt _08001350
	asrs r1, r2, #0x14
	b _08001356
_08001350:
	rsbs r1, r1, #0
	asrs r1, r1, #4
	rsbs r1, r1, #0
_08001356:
	mov r2, r8
_08001358:
	strh r1, [r2, #0x22]
	ldr r4, _08001390 @ =0x030047C8
	movs r3, #0
	ldrsh r2, [r4, r3]
	ldr r3, _08001394 @ =0x03003540
	movs r5, #8
	ldrsh r1, [r3, r5]
	adds r5, r2, r1
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r4, #0xa
	ldrsh r1, [r3, r4]
	adds r4, r2, r1
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #0
	beq _08001398
	adds r0, r5, #0
	subs r0, #0x78
	bl Mod
	adds r2, r0, #0
	mov r3, r8
	ldrh r1, [r3, #0x20]
	adds r1, r1, r2
	strh r1, [r3, #0x20]
	b _080013A2
	.align 2, 0
_08001390: .4byte 0x030047C8
_08001394: .4byte 0x03003540
_08001398:
	mov r2, r8
	ldrh r1, [r2, #0x20]
	subs r1, #0x78
	adds r1, r1, r5
	strh r1, [r2, #0x20]
_080013A2:
	ldr r3, [sp]
	movs r5, #0
	ldrsh r1, [r3, r5]
	cmp r1, #0
	beq _080013C0
	adds r0, r4, #0
	subs r0, #0x5a
	bl Mod
	adds r2, r0, #0
	mov r3, r8
	ldrh r1, [r3, #0x22]
	adds r1, r1, r2
	strh r1, [r3, #0x22]
	b _080013CA
_080013C0:
	mov r5, r8
	ldrh r1, [r5, #0x22]
	subs r1, #0x5a
	adds r1, r1, r4
	strh r1, [r5, #0x22]
_080013CA:
	adds r4, r7, #0
	adds r4, #0x4e
	ldrh r1, [r4]
	cmp r1, #1
	bne _08001416
	adds r3, r7, #0
	adds r3, #0x52
	adds r0, r7, #0
	adds r0, #0x5e
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	adds r0, #0x60
	ldrh r2, [r0]
	ldrh r5, [r1]
	adds r2, r2, r5
	strh r2, [r1]
	ldrb r0, [r7, #0x1b]
	ldrh r1, [r3]
	lsrs r1, r1, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x18
	bl FUN_0822f178
	adds r2, r7, #0
	adds r2, #0x50
	ldrh r1, [r2]
	subs r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	bne _08001416
	strh r1, [r4]
_08001416:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08001428
FUN_08001428: @ 0x08001428
	adds r1, r0, #0
	ldr r2, _08001438 @ =0x03000010
	ldrb r1, [r1, #0x1b]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #0
	str r2, [r1]
	bx lr
	.align 2, 0
_08001438: .4byte 0x03000010

	thumb_func_start FUN_0800143c
FUN_0800143c: @ 0x0800143C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, _080014C0 @ =0x03000010
	ldrb r0, [r6, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	str r7, [r0]
	strh r1, [r7, #0x18]
	ldrb r0, [r6]
	strb r0, [r7, #0x1a]
	ldrb r0, [r6, #1]
	strb r0, [r7, #0x1b]
	ldrb r1, [r7, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _080014C4 @ =0x03003ED0
	adds r0, r0, r1
	mov sb, r0
	ldrh r0, [r6, #2]
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x1c]
	bl FUN_0822ccc4
	adds r5, r0, #0
	ldrb r1, [r7, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001496
	ldr r0, _080014C8 @ =0x000056C2
	bl FUN_08230e70
	ldr r1, [r0, #4]
	movs r2, #8
	ldrsh r0, [r1, r2]
	str r0, [r6, #0xc]
	movs r3, #0xa
	ldrsh r0, [r1, r3]
	str r0, [r6, #0x10]
_08001496:
	ldrb r1, [r7, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080014D4
	ldr r3, _080014CC @ =0x030047C8
	movs r4, #0
	ldrsh r1, [r3, r4]
	ldr r2, _080014D0 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r4, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r0, r1, r0
	ldr r1, [r6, #0x1c]
	mov r8, r1
	b _080014DC
	.align 2, 0
_080014C0: .4byte 0x03000010
_080014C4: .4byte 0x03003ED0
_080014C8: .4byte 0x000056C2
_080014CC: .4byte 0x030047C8
_080014D0: .4byte 0x03003540
_080014D4:
	ldr r4, [r6, #4]
	ldr r0, [r6, #8]
	ldr r2, [r6, #0x1c]
	mov r8, r2
_080014DC:
	lsls r1, r4, #4
	movs r2, #0
	strh r1, [r7, #0x1e]
	lsls r0, r0, #4
	strh r0, [r7, #0x20]
	strh r1, [r7, #0x22]
	strh r0, [r7, #0x24]
	strh r1, [r7, #0x38]
	strh r0, [r7, #0x3a]
	ldr r0, [r6, #0x14]
	strh r0, [r7, #0x2a]
	ldr r0, [r6, #0x18]
	strh r0, [r7, #0x2c]
	str r2, [r7, #0x30]
	str r2, [r7, #0x34]
	ldr r0, [r6, #0xc]
	strh r0, [r7, #0x3c]
	ldr r0, [r6, #0x10]
	strh r0, [r7, #0x3e]
	ldr r0, [r6, #0x20]
	lsls r0, r0, #3
	adds r1, r7, #0
	adds r1, #0x40
	strh r0, [r1]
	ldr r0, [r6, #0x24]
	lsls r0, r0, #3
	adds r1, #2
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	adds r0, #6
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r7, #0x1b]
	bl GetTilemapBuffer
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0x4d
	bne _0800154A
	ldrb r0, [r5, #1]
	cmp r0, #0x50
	bne _0800154A
	mov r3, sb
	strh r4, [r3]
	ldrb r0, [r7, #0x1b]
	ldr r1, [r6, #0x28]
	bl SetBGPrioDirect
	b _08001568
_0800154A:
	ldrb r0, [r7, #0x1b]
	movs r4, #0xc
	ldrsh r1, [r6, r4]
	str r1, [sp]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	str r1, [sp, #4]
	ldr r1, [r6, #0x28]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822bfbc
_08001568:
	adds r0, r7, #0
	adds r0, #0x4a
	movs r4, #0
	mov sb, r4
	mov r1, r8
	strh r1, [r0]
	ldrh r5, [r7, #0x1e]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x14
	ldrh r4, [r7, #0x20]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	adds r0, r5, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	mov r8, r0
	adds r0, r4, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r0
	ldrb r0, [r7, #0x1b]
	str r4, [sp]
	mov r1, r8
	adds r3, r5, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	adds r0, #0x4e
	mov r2, sb
	strh r2, [r0]
	ldr r3, [r6, #0x34]
	mov ip, r3
	lsls r0, r3, #8
	adds r4, r7, #0
	adds r4, #0x52
	strh r0, [r4]
	ldr r0, [r6, #0x38]
	mov r8, r0
	lsls r0, r0, #8
	adds r2, r7, #0
	adds r2, #0x54
	strh r0, [r2]
	adds r5, r7, #0
	adds r5, #0x5e
	mov r1, sb
	strh r1, [r5]
	adds r3, r7, #0
	adds r3, #0x60
	strh r1, [r3]
	ldrh r0, [r4]
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r1, [r2]
	adds r0, r7, #0
	adds r0, #0x5c
	strh r1, [r0]
	ldrh r0, [r4]
	strh r0, [r5]
	ldrh r0, [r2]
	strh r0, [r3]
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _080015FE
	ldrb r0, [r7, #0x1b]
	mov r1, ip
	mov r2, r8
	bl FUN_0822f178
_080015FE:
	movs r0, #0
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08001610
FUN_08001610: @ 0x08001610
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	bne _08001622
	movs r0, #9
	b _08001624
_08001622:
	movs r0, #0xb
_08001624:
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800165C
	ldr r1, _08001654 @ =FUN_080011d8
	ldr r2, _08001658 @ =FUN_08001428
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_0800143c
	cmp r0, #0
	bge _0800165C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800165E
	.align 2, 0
_08001654: .4byte FUN_080011d8
_08001658: .4byte FUN_08001428
_0800165C:
	adds r0, r4, #0
_0800165E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08001664
FUN_08001664: @ 0x08001664
	push {r4, r5, lr}
	sub sp, #0x3c
	adds r5, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strb r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strb r0, [r1, #1]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x72
	movs r1, #0x80
	bl Script_GetKeywordValue
	str r0, [sp, #0x1c]
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x2c]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080016C8
	bl VM_GetPC
	cmp r0, #0
	beq _080016B8
	bl VM_GetValueAt
_080016B8:
	str r0, [sp, #4]
	bl VM_GetPC
	cmp r0, #0
	beq _080016CA
	bl VM_GetValueAt
	b _080016CA
_080016C8:
	str r0, [sp, #4]
_080016CA:
	str r0, [sp, #8]
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _080016F6
	bl VM_GetPC
	cmp r0, #0
	beq _080016E4
	bl VM_GetValueAt
	lsls r0, r0, #4
_080016E4:
	str r0, [sp, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _080016F8
	bl VM_GetValueAt
	lsls r0, r0, #4
	b _080016F8
_080016F6:
	str r0, [sp, #0xc]
_080016F8:
	str r0, [sp, #0x10]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08001720
	bl VM_GetPC
	cmp r0, #0
	beq _08001710
	bl VM_GetValueAt
_08001710:
	str r0, [sp, #0x14]
	bl VM_GetPC
	cmp r0, #0
	beq _08001722
	bl VM_GetValueAt
	b _08001722
_08001720:
	str r0, [sp, #0x14]
_08001722:
	str r0, [sp, #0x18]
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0800174A
	bl VM_GetPC
	cmp r0, #0
	beq _0800173A
	bl VM_GetValueAt
_0800173A:
	str r0, [sp, #0x20]
	bl VM_GetPC
	cmp r0, #0
	beq _0800174C
	bl VM_GetValueAt
	b _0800174C
_0800174A:
	str r0, [sp, #0x20]
_0800174C:
	str r0, [sp, #0x24]
	movs r0, #0x62
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08001786
	bl VM_GetPC
	cmp r0, #0
	beq _0800176A
	bl VM_GetValueAt
	adds r4, r0, #0
	b _0800176C
_0800176A:
	movs r4, #0
_0800176C:
	bl VM_GetPC
	cmp r0, #0
	beq _0800177A
	bl VM_GetValueAt
	b _0800177C
_0800177A:
	movs r0, #8
_0800177C:
	str r4, [sp, #0x34]
	str r0, [sp, #0x38]
	movs r0, #1
	str r0, [sp, #0x30]
	b _0800178E
_08001786:
	movs r0, #0x10
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
	str r1, [sp, #0x30]
_0800178E:
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080017B6
	cmp r0, #1
	bgt _080017A0
	cmp r0, #0
	beq _080017AA
	b _080017C0
_080017A0:
	cmp r0, #2
	beq _080017B0
	cmp r0, #3
	beq _080017B6
	b _080017C0
_080017AA:
	movs r0, #0x70
	movs r1, #0
	b _080017BA
_080017B0:
	movs r0, #0x70
	movs r1, #3
	b _080017BA
_080017B6:
	movs r0, #0x70
	movs r1, #1
_080017BA:
	bl Script_GetKeywordValue
	str r0, [sp, #0x28]
_080017C0:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_08001610
	add sp, #0x3c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080017d4
FUN_080017d4: @ 0x080017D4
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	ldr r1, _08001824 @ =0x03000010
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0800181C
	ldr r1, [r2, #0x64]
	cmp r1, #7
	bhi _0800181C
	lsls r1, r1, #1
	adds r0, r2, #0
	adds r0, #0x68
	adds r0, r0, r1
	strh r5, [r0]
	movs r3, #0
	cmp r3, r4
	bge _08001816
	adds r5, r2, #0
	adds r5, #0x78
_08001802:
	lsls r0, r3, #1
	ldr r1, [r2, #0x64]
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r5, r0
	ldm r6!, {r1}
	strh r1, [r0]
	adds r3, #1
	cmp r3, r4
	blt _08001802
_08001816:
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
_0800181C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001824: .4byte 0x03000010

	thumb_func_start FUN_08001828
FUN_08001828: @ 0x08001828
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08001864
	mov r5, sp
	b _08001858
_08001850:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_08001858:
	bl VM_GetPC
	cmp r0, #0
	beq _08001864
	cmp r4, #7
	ble _08001850
_08001864:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, sp
	bl FUN_080017d4
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08001878
FUN_08001878: @ 0x08001878
	ldr r1, _08001880 @ =0x03002B2C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08001880: .4byte 0x03002B2C

	thumb_func_start FUN_08001884
FUN_08001884: @ 0x08001884
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x20]
	ldr r1, [sp, #0x24]
	lsrs r5, r5, #1
	movs r0, #0x20
	subs r0, r0, r5
	mov sb, r0
	subs r1, r1, r3
	cmp r1, #0
	beq _0800192E
	cmp r5, #0x1f
	bls _080018CC
	lsls r0, r3, #1
	adds r3, r2, r0
	adds r4, r4, r0
	lsls r1, r1, #1
	cmp r1, #0
	bge _080018B8
	adds r1, #3
_080018B8:
	lsls r2, r1, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r3, #0
	adds r1, r4, #0
	bl CpuSet
	b _0800192E
_080018CC:
	lsls r0, r3, #1
	adds r6, r6, r0
	mov r8, r6
	adds r2, r2, r0
	mov ip, r2
	adds r7, r4, r0
	cmp r1, #0
	ble _0800192E
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	adds r6, r1, #0
_080018E4:
	mov r1, r8
	ldrh r0, [r1]
	ldr r3, _0800193C @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	mov r2, ip
	ldrh r1, [r2]
	adds r0, r1, #0
	ldr r2, _0800193C @ =0x00007C1F
	ands r0, r2
	adds r2, r0, #0
	muls r2, r5, r2
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, _08001940 @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	muls r1, r5, r1
	mov r0, sb
	muls r0, r4, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	strh r2, [r7]
	movs r1, #2
	add r8, r1
	add ip, r1
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _080018E4
_0800192E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800193C: .4byte 0x00007C1F
_08001940: .4byte 0x000F83E0

	thumb_func_start FUN_08001944
FUN_08001944: @ 0x08001944
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x1c]
	lsrs r4, r4, #1
	subs r2, r0, r3
	cmp r2, #0
	beq _080019C8
	cmp r4, #0x1f
	bls _08001980
	lsls r0, r3, #1
	adds r1, r1, r0
	adds r3, r5, r0
	lsls r0, r2, #1
	cmp r0, #0
	bge _0800196C
	adds r0, #3
_0800196C:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	b _080019C8
_08001980:
	lsls r0, r3, #1
	adds r6, r1, r0
	adds r5, r5, r0
	cmp r2, #0
	ble _080019C8
	ldr r0, _080019D4 @ =0x00007C1F
	mov sb, r0
	ldr r1, _080019D8 @ =0x000F83E0
	mov r8, r1
	adds r3, r2, #0
	movs r0, #0xf8
	lsls r0, r0, #2
	mov ip, r0
	movs r7, #0xf8
	lsls r7, r7, #7
_0800199E:
	ldrh r2, [r6]
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	adds r1, r0, #0
	muls r1, r4, r1
	mov r0, r8
	ands r1, r0
	mov r0, ip
	ands r2, r0
	adds r0, r2, #0
	muls r0, r4, r0
	ands r0, r7
	orrs r1, r0
	lsrs r1, r1, #5
	strh r1, [r5]
	adds r6, #2
	adds r5, #2
	subs r3, #1
	cmp r3, #0
	bne _0800199E
_080019C8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080019D4: .4byte 0x00007C1F
_080019D8: .4byte 0x000F83E0

	thumb_func_start FUN_080019dc
FUN_080019dc: @ 0x080019DC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _08001A10 @ =0x000092B3
	bl GetFile
	adds r1, r0, #0
	adds r1, #0x14
	ldr r0, _08001A14 @ =0x00000434
	adds r4, r4, r0
	movs r0, #0xd0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0x32
	movs r3, #0
	bl FUN_08001944
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A10: .4byte 0x000092B3
_08001A14: .4byte 0x00000434

	thumb_func_start FUN_08001a18
FUN_08001a18: @ 0x08001A18
	push {lr}
	ldr r2, [r0, #0x2c]
	movs r3, #0xcf
_08001A1E:
	strh r1, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08001A1E
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_08001a34
FUN_08001a34: @ 0x08001A34
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001A46
	ldr r0, [r4, #0x30]
	b _08001A48
_08001A46:
	ldr r0, [r4, #0x24]
_08001A48:
	ldr r1, [r4, #0x2c]
	ldr r2, _08001A60 @ =0x04000068
	bl CpuSet
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08001A60: .4byte 0x04000068

	thumb_func_start FUN_08001a64
FUN_08001a64: @ 0x08001A64
	push {lr}
	ldr r0, _08001A78 @ =gClock
	ldrb r0, [r0, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08001A7C
	movs r0, #0x40
	b _08001A7E
	.align 2, 0
_08001A78: .4byte gClock
_08001A7C:
	movs r0, #0x20
_08001A7E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08001a84
FUN_08001a84: @ 0x08001A84
	ldr r1, _08001A90 @ =0x00000642
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
_08001A90: .4byte 0x00000642

	thumb_func_start FUN_08001a94
FUN_08001a94: @ 0x08001A94
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08001AB0 @ =0x00000642
	adds r5, r6, r0
	ldrb r4, [r5]
	adds r0, r6, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001AB4
	ldrb r0, [r5]
	adds r0, #4
	strb r0, [r5]
	b _08001AC4
	.align 2, 0
_08001AB0: .4byte 0x00000642
_08001AB4:
	adds r0, r6, #0
	bl FUN_08001a64
	strb r0, [r5]
	ldr r0, _08001ACC @ =0x00000644
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
_08001AC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001ACC: .4byte 0x00000644

	thumb_func_start FUN_08001ad0
FUN_08001ad0: @ 0x08001AD0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FUN_08001a64
	ldr r1, _08001B00 @ =0x00000642
	adds r5, r7, r1
	ldrb r4, [r5]
	subs r6, r4, r0
	cmp r6, #0
	bge _08001AE6
	rsbs r6, r6, #0
_08001AE6:
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001B04
	adds r1, r6, #0
	cmp r1, #8
	ble _08001AF8
	movs r1, #8
_08001AF8:
	ldrb r0, [r5]
	adds r0, r0, r1
	b _08001B24
	.align 2, 0
_08001B00: .4byte 0x00000642
_08001B04:
	ldrb r4, [r5]
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	ble _08001B1E
	adds r1, r6, #0
	cmp r1, #8
	ble _08001B18
	movs r1, #8
_08001B18:
	ldrb r0, [r5]
	subs r0, r0, r1
	b _08001B24
_08001B1E:
	adds r0, r7, #0
	bl FUN_08001a64
_08001B24:
	strb r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08001b2c
FUN_08001b2c: @ 0x08001B2C
	push {lr}
	adds r3, r0, #0
	ldr r0, _08001B40 @ =0x00000642
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #1
	bls _08001B44
	subs r0, #2
	strb r0, [r2]
	b _08001B4E
	.align 2, 0
_08001B40: .4byte 0x00000642
_08001B44:
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08001B54 @ =0x00000644
	adds r0, r3, r2
	strb r1, [r0]
_08001B4E:
	pop {r0}
	bx r0
	.align 2, 0
_08001B54: .4byte 0x00000644

	thumb_func_start FUN_08001b58
FUN_08001b58: @ 0x08001B58
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrb r3, [r0]
	movs r0, #0
	mov r8, r0
	str r0, [sp]
	movs r6, #0xd0
	str r6, [sp, #4]
	adds r0, r5, #0
	bl FUN_08001884
	ldr r1, [r4, #0x2c]
	ldr r2, _08001BC4 @ =0x04000068
	adds r0, r5, #0
	bl CpuSet
	adds r0, r4, #0
	bl FUN_080019dc
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, _08001BC8 @ =0x00000434
	adds r2, r4, r3
	ldr r3, _08001BCC @ =0x00000642
	adds r1, r4, r3
	ldrb r3, [r1]
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	str r5, [r4, #0x30]
	adds r4, #0x20
	movs r0, #1
	strb r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08001BC4: .4byte 0x04000068
_08001BC8: .4byte 0x00000434
_08001BCC: .4byte 0x00000642

	thumb_func_start FUN_08001bd0
FUN_08001bd0: @ 0x08001BD0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r6, #0x34
	str r6, [r0, #0x30]
	movs r4, #0
	movs r5, #0xd0
	ldr r1, [r0, #0x24]
	ldr r2, [r0, #0x28]
	movs r3, #0xc8
	lsls r3, r3, #3
	adds r7, r0, r3
	ldrb r3, [r7]
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r6, #0
	bl FUN_08001884
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bls _08001C06
	movs r0, #0x40
	strb r0, [r7]
_08001C06:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001c10
FUN_08001c10: @ 0x08001C10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	bl FUN_08017b70
	cmp r0, #0
	beq _08001C98
	ldr r0, _08001CA4 @ =0x0000064A
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08001C42
	ldr r1, _08001CA8 @ =0x085AA624
	ldr r2, _08001CAC @ =0x00000644
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08001C42:
	ldr r7, _08001CB0 @ =0x00000642
	adds r3, r6, r7
	ldr r0, _08001CB4 @ =0x00000643
	adds r1, r6, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08001C5E
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi _08001C7E
_08001C5E:
	movs r5, #0
	movs r4, #0xd0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x34
	ldr r7, _08001CB8 @ =0x00000434
	adds r2, r6, r7
	ldrb r3, [r3]
	str r5, [sp]
	str r4, [sp, #4]
	bl FUN_08001884
	mov r0, r8
	strh r5, [r0]
_08001C7E:
	ldr r2, _08001CB0 @ =0x00000642
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08001C90
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r0, r6, r7
	str r0, [r6, #0x30]
_08001C90:
	ldrb r1, [r1]
	ldr r2, _08001CB4 @ =0x00000643
	adds r0, r6, r2
	strb r1, [r0]
_08001C98:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001CA4: .4byte 0x0000064A
_08001CA8: .4byte 0x085AA624
_08001CAC: .4byte 0x00000644
_08001CB0: .4byte 0x00000642
_08001CB4: .4byte 0x00000643
_08001CB8: .4byte 0x00000434

	thumb_func_start FUN_08001cbc
FUN_08001cbc: @ 0x08001CBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	ldr r0, _08001D38 @ =0x00000654
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	mov sb, r0
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	ldr r0, _08001D3C @ =0x00000659
	add r0, r8
	ldrb r0, [r0]
	adds r0, r2, r0
	str r0, [sp, #4]
	cmp r0, #0xc
	ble _08001CF8
	ldr r1, _08001D40 @ =0x0000065A
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd
	str r0, [sp, #4]
_08001CF8:
	mov r1, sb
	cmp r1, #0x1f
	ble _08001D4C
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
_08001D0C:
	ldr r0, _08001D44 @ =0x0000065C
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08001D2E
	lsls r2, r4, #5
	mov r7, r8
	ldr r0, [r7, #0x28]
	adds r0, r0, r2
	ldr r1, [r7, #0x2c]
	adds r1, r1, r2
	ldr r2, _08001D48 @ =0x04000008
	bl CpuSet
_08001D2E:
	adds r4, #1
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _08001D0C
	b _08001DF0
	.align 2, 0
_08001D38: .4byte 0x00000654
_08001D3C: .4byte 0x00000659
_08001D40: .4byte 0x0000065A
_08001D44: .4byte 0x0000065C
_08001D48: .4byte 0x04000008
_08001D4C:
	movs r0, #0x20
	mov r1, sb
	subs r1, r0, r1
	str r1, [sp]
	adds r4, r2, #0
	mov r2, r8
	adds r2, #0x20
	str r2, [sp, #0xc]
	ldr r3, [sp, #4]
	cmp r4, r3
	bge _08001DF0
	ldr r7, _08001E14 @ =0x0000065C
	add r7, r8
	str r7, [sp, #8]
_08001D68:
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	asrs r1, r4
	movs r0, #1
	ands r1, r0
	adds r2, r4, #1
	str r2, [sp, #0x10]
	cmp r1, #0
	beq _08001DE8
	lsls r1, r4, #5
	mov r3, r8
	ldr r0, [r3, #0x2c]
	adds r0, r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x24]
	adds r6, r0, r1
	ldr r0, [r3, #0x28]
	adds r5, r0, r1
	movs r7, #0xf8
	lsls r7, r7, #2
	mov sl, r7
	movs r0, #0xf
	mov ip, r0
_08001D96:
	ldrh r0, [r6]
	ldr r3, _08001E18 @ =0x00007C1F
	ands r3, r0
	mov r4, sl
	ands r4, r0
	ldrh r1, [r5]
	adds r0, r1, #0
	ldr r2, _08001E18 @ =0x00007C1F
	ands r0, r2
	mov r2, sb
	muls r2, r0, r2
	ldr r7, [sp]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, _08001E1C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r0, sb
	muls r0, r1, r0
	adds r1, r4, #0
	muls r1, r7, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	orrs r2, r0
	lsrs r2, r2, #5
	ldr r1, [sp, #0x14]
	strh r2, [r1]
	adds r1, #2
	str r1, [sp, #0x14]
	adds r6, #2
	adds r5, #2
	movs r2, #1
	rsbs r2, r2, #0
	add ip, r2
	mov r3, ip
	cmp r3, #0
	bge _08001D96
_08001DE8:
	ldr r4, [sp, #0x10]
	ldr r7, [sp, #4]
	cmp r4, r7
	blt _08001D68
_08001DF0:
	movs r0, #0xcb
	lsls r0, r0, #3
	add r0, r8
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001E14: .4byte 0x0000065C
_08001E18: .4byte 0x00007C1F
_08001E1C: .4byte 0x000F83E0

	thumb_func_start FUN_08001e20
FUN_08001e20: @ 0x08001E20
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0x1d]
	lsls r6, r2, #4
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08001E3A
	lsls r1, r2, #5
	ldr r0, [r4, #0x30]
	b _08001E3E
_08001E3A:
	lsls r1, r2, #5
	ldr r0, [r4, #0x24]
_08001E3E:
	adds r5, r0, r1
	ldrb r3, [r4, #0x1d]
	ldrb r2, [r4, #0x1f]
	adds r0, r3, r2
	cmp r0, #0xd
	bgt _08001E4E
	lsls r1, r2, #4
	b _08001E54
_08001E4E:
	movs r0, #0xd
	subs r0, r0, r3
	lsls r1, r0, #4
_08001E54:
	ldr r0, [r4, #0x2c]
	ldr r2, [r4, #0x28]
	movs r3, #0x1c
	ldrsb r3, [r4, r3]
	str r6, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	bl FUN_08001884
	ldrb r0, [r4, #0x1f]
	ldrb r1, [r4, #0x1d]
	adds r0, r0, r1
	movs r1, #0
	strb r0, [r4, #0x1d]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _08001E92
	strb r1, [r4, #0x1d]
	ldrb r0, [r4, #0x1e]
	ldrb r2, [r4, #0x1c]
	adds r0, r0, r2
	strb r0, [r4, #0x1c]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x40
	ble _08001E92
	strb r1, [r4, #0x1c]
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x24]
	strb r1, [r4, #0x1b]
_08001E92:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001ea4
FUN_08001ea4: @ 0x08001EA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001EE4 @ =0x03004040
	ldr r0, _08001EE8 @ =0x0000063C
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r1, r1, #6
	adds r0, #2
	adds r3, r4, r0
	ldrh r0, [r3]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r5]
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	ldrh r3, [r3]
	lsls r0, r3
	cmp r1, r0
	blt _08001EF0
	movs r0, #0
	str r0, [r5]
	ldrb r0, [r4, #0x1b]
	cmp r0, #3
	bne _08001EEC
	movs r0, #0
	b _08001EEE
	.align 2, 0
_08001EE4: .4byte 0x03004040
_08001EE8: .4byte 0x0000063C
_08001EEC:
	movs r0, #6
_08001EEE:
	strb r0, [r4, #0x1b]
_08001EF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08001ef8
FUN_08001ef8: @ 0x08001EF8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08001F40 @ =0x03004040
	ldr r0, _08001F44 @ =0x0000063C
	adds r2, r4, r0
	ldrh r0, [r2]
	lsls r0, r0, #6
	ldr r1, _08001F48 @ =0x0000063E
	adds r3, r4, r1
	ldrh r1, [r3]
	asrs r0, r1
	str r0, [r5]
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	ldrh r3, [r3]
	lsls r0, r3
	cmp r1, r0
	blt _08001F3A
	bl FUN_0822d00c
	movs r1, #0x40
	str r1, [r5]
	ldr r2, _08001F4C @ =0x03004494
	ldr r3, _08001F50 @ =0x00001084
	adds r1, r3, #0
	strh r1, [r2]
	strh r1, [r0]
	movs r0, #0
	strb r0, [r4, #0x1b]
_08001F3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08001F40: .4byte 0x03004040
_08001F44: .4byte 0x0000063C
_08001F48: .4byte 0x0000063E
_08001F4C: .4byte 0x03004494
_08001F50: .4byte 0x00001084

	thumb_func_start FUN_08001f54
FUN_08001f54: @ 0x08001F54
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08001FD8 @ =0x03002B2C
	ldr r4, [r0]
	cmp r4, #0
	beq _0800200C
	lsls r0, r3, #1
	ldr r3, _08001FDC @ =0x00000634
	adds r5, r4, r3
	adds r3, r5, r0
	movs r6, #0
	strh r1, [r3]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08002004
	ldrb r1, [r4, #0x1a]
	ands r0, r1
	cmp r0, #0
	beq _08001FE4
	mov r6, sp
	adds r6, #2
	mov r0, sp
	adds r1, r6, #0
	bl FUN_0823ce10
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r1, [r0]
	ldr r0, _08001FE0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x28]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, #2
	beq _08001FC2
	ldrh r0, [r6]
	cmp r0, #2
	bne _08001FC8
_08001FC2:
	adds r0, r4, #0
	bl FUN_080019dc
_08001FC8:
	adds r0, r4, #0
	bl FUN_08001b58
	movs r0, #0
	strb r0, [r4, #0x1d]
	movs r0, #0x40
	strb r0, [r4, #0x1c]
	b _08001FFC
	.align 2, 0
_08001FD8: .4byte 0x03002B2C
_08001FDC: .4byte 0x00000634
_08001FE0: .4byte 0x000092B3
_08001FE4:
	ldrh r1, [r3]
	ldr r0, _08002014 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x24]
	ldr r1, [r4, #0x2c]
	ldr r2, _08002018 @ =0x04000068
	bl CpuSet
	strb r6, [r4, #0x1d]
	strb r6, [r4, #0x1c]
_08001FFC:
	movs r0, #7
	strb r0, [r4, #0x1e]
	movs r0, #4
	strb r0, [r4, #0x1f]
_08002004:
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
_0800200C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002014: .4byte 0x000092B3
_08002018: .4byte 0x04000068

	thumb_func_start FUN_0800201c
FUN_0800201c: @ 0x0800201C
	push {r4, r5, lr}
	ldr r0, _08002058 @ =0x03002B2C
	ldr r0, [r0]
	cmp r0, #0
	beq _08002050
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08001f54
_08002050:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002058: .4byte 0x03002B2C

	thumb_func_start FUN_0800205c
FUN_0800205c: @ 0x0800205C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r0, _080020B4 @ =0x03002B2C
	ldr r2, [r0]
	cmp r2, #0
	beq _080020AE
	ldr r0, _080020B8 @ =0x00000664
	adds r5, r2, r0
	ldr r1, [r5]
	cmp r1, #7
	bhi _080020AE
	lsls r1, r1, #1
	movs r7, #0xcd
	lsls r7, r7, #3
	adds r0, r2, r7
	adds r0, r0, r1
	strh r3, [r0]
	movs r3, #0
	cmp r3, r4
	bge _080020A4
	adds r7, r5, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r5, r2, r0
_08002090:
	lsls r0, r3, #1
	ldr r1, [r7]
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r5, r0
	ldm r6!, {r1}
	strh r1, [r0]
	adds r3, #1
	cmp r3, r4
	blt _08002090
_080020A4:
	ldr r7, _080020B8 @ =0x00000664
	adds r1, r2, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080020AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080020B4: .4byte 0x03002B2C
_080020B8: .4byte 0x00000664

	thumb_func_start FUN_080020bc
FUN_080020bc: @ 0x080020BC
	push {r4, r5, r6, lr}
	sub sp, #0x20
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080020EE
	mov r5, sp
	b _080020E2
_080020DA:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_080020E2:
	bl VM_GetPC
	cmp r0, #0
	beq _080020EE
	cmp r4, #7
	ble _080020DA
_080020EE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0800205c
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08002100
FUN_08002100: @ 0x08002100
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x20
	movs r1, #0
	strb r1, [r2]
	movs r7, #0
	ldr r2, _0800211C @ =0x00000664
	adds r1, r6, r2
	b _08002232
	.align 2, 0
_0800211C: .4byte 0x00000664
_08002120:
	lsls r1, r7, #1
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r2, r6, r3
	adds r2, r2, r1
	ldrh r3, [r2]
	lsls r1, r7, #4
	movs r4, #0xcf
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r4, r6, r1
	movs r5, #0
	strh r5, [r2]
	ldrb r1, [r6, #0x1b]
	cmp r1, #3
	bhi _080021FC
	subs r1, r3, #1
	cmp r1, #5
	bhi _0800222C
	lsls r1, r1, #2
	ldr r2, _08002150 @ =_08002154
	adds r1, r1, r2
	ldr r1, [r1]
	mov pc, r1
	.align 2, 0
_08002150: .4byte _08002154
_08002154: @ jump table
	.4byte _0800216C @ case 0
	.4byte _080021A4 @ case 1
	.4byte _080021C4 @ case 2
	.4byte _080021A4 @ case 3
	.4byte _080021C4 @ case 4
	.4byte _080021E0 @ case 5
_0800216C:
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r1, r1, #1
	ldr r2, _0800219C @ =0x00000634
	adds r0, r6, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080021A0 @ =0x000092B3
	bl GetFile
	adds r1, r0, #0
	adds r1, #0x14
	str r1, [r6, #0x28]
	movs r2, #0
	movs r1, #1
	strb r1, [r6, #0x1b]
	strb r2, [r6, #0x1d]
	ldrh r1, [r4, #2]
	strb r1, [r6, #0x1c]
	ldrh r1, [r4, #4]
	strb r1, [r6, #0x1e]
	ldrh r1, [r4, #6]
	strb r1, [r6, #0x1f]
	b _0800222C
	.align 2, 0
_0800219C: .4byte 0x00000634
_080021A0: .4byte 0x000092B3
_080021A4:
	cmp r3, #2
	bne _080021AC
	strb r3, [r6, #0x1b]
	b _080021B0
_080021AC:
	movs r1, #4
	strb r1, [r6, #0x1b]
_080021B0:
	ldr r3, _080021C0 @ =0x0000063C
	adds r2, r6, r3
	movs r1, #0
	strh r1, [r2]
	ldrh r2, [r4]
	adds r3, #2
	b _08002210
	.align 2, 0
_080021C0: .4byte 0x0000063C
_080021C4:
	cmp r3, #3
	bne _080021CC
	strb r3, [r6, #0x1b]
	b _080021D0
_080021CC:
	movs r1, #5
	strb r1, [r6, #0x1b]
_080021D0:
	ldr r1, _080021DC @ =0x0000063C
	adds r2, r6, r1
	movs r1, #0
	strh r1, [r2]
	b _0800220C
	.align 2, 0
_080021DC: .4byte 0x0000063C
_080021E0:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #5
	orrs r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	lsls r0, r0, #0xa
	orrs r1, r0
	adds r0, r6, #0
	bl FUN_08001a18
	b _0800222C
_080021FC:
	cmp r3, #4
	beq _08002204
	cmp r3, #5
	bne _0800222C
_08002204:
	strb r3, [r6, #0x1b]
	ldr r2, _080022E0 @ =0x0000063C
	adds r1, r6, r2
	strh r5, [r1]
_0800220C:
	ldrh r2, [r4]
	ldr r3, _080022E4 @ =0x0000063E
_08002210:
	adds r1, r6, r3
	strh r2, [r1]
	ldr r3, _080022E8 @ =0x03004494
	ldrh r2, [r4, #6]
	lsls r2, r2, #0xa
	ldrh r1, [r4, #4]
	lsls r1, r1, #5
	orrs r2, r1
	ldrh r1, [r4, #2]
	orrs r2, r1
	strh r2, [r3]
	ldr r2, _080022EC @ =0x03004454
	ldrh r1, [r4, #8]
	strh r1, [r2]
_0800222C:
	adds r7, #1
	ldr r4, _080022F0 @ =0x00000664
	adds r1, r6, r4
_08002232:
	ldr r1, [r1]
	cmp r7, r1
	bhs _0800223A
	b _08002120
_0800223A:
	ldr r7, _080022F0 @ =0x00000664
	adds r1, r6, r7
	movs r4, #0
	str r4, [r1]
	ldrb r2, [r6, #0x1a]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _0800230C
	ldr r0, _080022F4 @ =0x0000064C
	adds r0, r0, r6
	mov r8, r0
	ldr r7, _080022F8 @ =gClock
	ldrh r0, [r0]
	ldrb r1, [r7, #0xe]
	cmp r0, r1
	beq _080022A2
	mov r5, sp
	adds r5, #2
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0823ce10
	movs r2, #0xc8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #3
	adds r0, r6, r3
	strh r4, [r0]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r1, _080022FC @ =0x00000634
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08002300 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _08002300 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
_080022A2:
	ldrb r0, [r7, #0xe]
	mov r2, r8
	strh r0, [r2]
	ldrb r1, [r7, #0xf]
	ldr r3, _08002304 @ =0x0000064E
	adds r0, r6, r3
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x34
	str r0, [r6, #0x30]
	movs r7, #0xc8
	lsls r7, r7, #3
	adds r4, r6, r7
	ldrb r0, [r4]
	cmp r0, #0x3f
	bhi _080022C8
	adds r0, r6, #0
	bl FUN_08001bd0
_080022C8:
	adds r0, r6, #0
	bl FUN_08001c10
	adds r0, r6, #0
	bl FUN_08001a34
	ldrb r2, [r4]
	ldr r3, _08002308 @ =0x00000641
	adds r1, r6, r3
	strb r2, [r1]
	b _080023B4
	.align 2, 0
_080022E0: .4byte 0x0000063C
_080022E4: .4byte 0x0000063E
_080022E8: .4byte 0x03004494
_080022EC: .4byte 0x03004454
_080022F0: .4byte 0x00000664
_080022F4: .4byte 0x0000064C
_080022F8: .4byte gClock
_080022FC: .4byte 0x00000634
_08002300: .4byte 0x000092B3
_08002304: .4byte 0x0000064E
_08002308: .4byte 0x00000641
_0800230C:
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _080023B4
	ldr r4, _08002364 @ =0x0000065E
	adds r5, r6, r4
	ldrh r1, [r5]
	adds r4, r1, #0
	cmp r4, #0
	bne _080023A0
	movs r7, #0xca
	lsls r7, r7, #3
	adds r3, r6, r7
	ldrh r1, [r3]
	adds r1, #1
	strh r1, [r3]
	adds r7, #2
	adds r2, r6, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080023A4
	strh r4, [r3]
	ldr r1, _08002368 @ =0x00000654
	adds r2, r6, r1
	adds r7, #4
	adds r3, r6, r7
	ldrh r1, [r3]
	ldrh r7, [r2]
	adds r1, r1, r7
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bgt _0800236C
	strh r4, [r2]
	ldrh r1, [r3]
	rsbs r1, r1, #0
	strh r1, [r3]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r6, r2
	b _0800237E
	.align 2, 0
_08002364: .4byte 0x0000065E
_08002368: .4byte 0x00000654
_0800236C:
	cmp r1, #0x3f
	ble _08002382
	movs r1, #0x40
	strh r1, [r2]
	ldrh r1, [r3]
	rsbs r1, r1, #0
	strh r1, [r3]
	ldr r3, _08002398 @ =0x00000662
	adds r1, r6, r3
_0800237E:
	ldrh r1, [r1]
	strh r1, [r5]
_08002382:
	ldr r4, _0800239C @ =0x0000065A
	adds r2, r6, r4
	movs r3, #0
	movs r1, #1
	strb r1, [r2]
	movs r7, #0xcb
	lsls r7, r7, #3
	adds r1, r6, r7
	strb r3, [r1]
	b _080023A4
	.align 2, 0
_08002398: .4byte 0x00000662
_0800239C: .4byte 0x0000065A
_080023A0:
	subs r1, #1
	strh r1, [r5]
_080023A4:
	ldr r2, _080023D4 @ =0x0000065A
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _080023B4
	adds r0, r6, #0
	bl FUN_08001cbc
_080023B4:
	ldr r2, _080023D8 @ =0x085AA634
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080023C8
	adds r0, r6, #0
	bl _call_via_r1
_080023C8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080023D4: .4byte 0x0000065A
_080023D8: .4byte 0x085AA634

	thumb_func_start FUN_080023dc
FUN_080023dc: @ 0x080023DC
	ldr r2, _080023E4 @ =0x03002B2C
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_080023E4: .4byte 0x03002B2C

	thumb_func_start FUN_080023e8
FUN_080023e8: @ 0x080023E8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08002440 @ =0x03002B2C
	str r6, [r0]
	movs r5, #0
	movs r4, #0
	strh r1, [r6, #0x18]
	ldr r0, _08002444 @ =0x03004250
	str r0, [r6, #0x2c]
	ldr r0, _08002448 @ =0x03004040
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _0800244C @ =0x03004048
	str r1, [r0]
	ldr r1, _08002450 @ =0x03004494
	ldr r2, _08002454 @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08002458 @ =0x03004454
	strh r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #0x1a]
	strb r5, [r6, #0x1d]
	movs r3, #0xc9
	lsls r3, r3, #3
	adds r0, r6, r3
	strh r4, [r0]
	strb r5, [r6, #0x1b]
	movs r0, #7
	strb r0, [r6, #0x1e]
	movs r0, #4
	strb r0, [r6, #0x1f]
	movs r0, #0x70
	bl prepare_08231510
	mov r5, sp
	adds r5, #2
	cmp r0, #0
	beq _08002478
	b _0800246C
	.align 2, 0
_08002440: .4byte 0x03002B2C
_08002444: .4byte 0x03004250
_08002448: .4byte 0x03004040
_0800244C: .4byte 0x03004048
_08002450: .4byte 0x03004494
_08002454: .4byte 0x00001084
_08002458: .4byte 0x03004454
_0800245C:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r3, _080024F4 @ =0x00000634
	adds r1, r6, r3
	adds r1, r1, r2
	strh r0, [r1]
	adds r4, #1
_0800246C:
	bl VM_GetPC
	cmp r0, #0
	beq _08002478
	cmp r4, #3
	ble _0800245C
_08002478:
	ldr r1, _080024F8 @ =0x0000063C
	adds r0, r6, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _080024FC @ =0x0000063E
	adds r0, r6, r3
	strh r1, [r0]
	strb r2, [r6, #0x1c]
	ldr r0, _08002500 @ =0x0000064E
	adds r7, r6, r0
	strh r1, [r7]
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r4, r6, r1
	strb r2, [r4]
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08002510
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0823ce10
	movs r0, #0x40
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r2, _080024F4 @ =0x00000634
	adds r4, r6, r2
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08002504 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _08002504 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	adds r0, r6, #0
	bl FUN_08001b58
	ldr r1, _08002508 @ =gClock
	ldrb r0, [r1, #0xf]
	strh r0, [r7]
	ldrb r1, [r1, #0xe]
	ldr r3, _0800250C @ =0x0000064C
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r6, r1
	b _08002612
	.align 2, 0
_080024F4: .4byte 0x00000634
_080024F8: .4byte 0x0000063C
_080024FC: .4byte 0x0000063E
_08002500: .4byte 0x0000064E
_08002504: .4byte 0x000092B3
_08002508: .4byte gClock
_0800250C: .4byte 0x0000064C
_08002510:
	movs r7, #2
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0800251C
	b _08002638
_0800251C:
	mov r4, sp
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r2, _080025A8 @ =0x00000634
	adds r4, r6, r2
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _080025AC @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _080025AC @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	movs r0, #0x61
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080025C4
	bl Script_GetValue
	ldr r3, _080025B0 @ =0x00000652
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080025B4 @ =0x00000656
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _080025B8 @ =0x00000659
	adds r1, r6, r3
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _080025BC @ =0x0000065C
	adds r1, r6, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r6, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080025C0 @ =0x00000662
	adds r1, r6, r2
	strh r0, [r1]
	b _080025F0
	.align 2, 0
_080025A8: .4byte 0x00000634
_080025AC: .4byte 0x000092B3
_080025B0: .4byte 0x00000652
_080025B4: .4byte 0x00000656
_080025B8: .4byte 0x00000659
_080025BC: .4byte 0x0000065C
_080025C0: .4byte 0x00000662
_080025C4:
	ldr r3, _0800261C @ =0x00000652
	adds r1, r6, r3
	movs r0, #4
	strh r0, [r1]
	ldr r1, _08002620 @ =0x00000656
	adds r0, r6, r1
	strh r7, [r0]
	adds r3, #7
	adds r1, r6, r3
	movs r0, #8
	strb r0, [r1]
	ldr r0, _08002624 @ =0x0000065C
	adds r1, r6, r0
	ldr r0, _08002628 @ =0x0000FFFF
	strh r0, [r1]
	adds r3, #7
	adds r1, r6, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0800262C @ =0x00000662
	adds r0, r6, r1
	strh r2, [r0]
_080025F0:
	movs r2, #0xca
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _08002630 @ =0x00000654
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #6
	adds r0, r6, r3
	strb r2, [r0]
	ldr r0, [r6, #0x24]
_08002612:
	ldr r1, [r6, #0x2c]
	ldr r2, _08002634 @ =0x04000068
	bl CpuSet
	b _08002682
	.align 2, 0
_0800261C: .4byte 0x00000652
_08002620: .4byte 0x00000656
_08002624: .4byte 0x0000065C
_08002628: .4byte 0x0000FFFF
_0800262C: .4byte 0x00000662
_08002630: .4byte 0x00000654
_08002634: .4byte 0x04000068
_08002638:
	mov r4, sp
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r1, _0800269C @ =0x00000634
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _080026A0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _080026A0 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x2c]
	ldr r2, _080026A4 @ =0x04000068
	bl CpuSet
_08002682:
	ldr r2, _080026A8 @ =0x00000644
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800269C: .4byte 0x00000634
_080026A0: .4byte 0x000092B3
_080026A4: .4byte 0x04000068
_080026A8: .4byte 0x00000644

	thumb_func_start FUN_080026ac
FUN_080026ac: @ 0x080026AC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080026E8 @ =0x03002B2C
	ldr r0, [r0]
	cmp r0, #0
	bne _080026F6
	movs r1, #0xdf
	lsls r1, r1, #3
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080026F4
	ldr r1, _080026EC @ =FUN_08002100
	ldr r2, _080026F0 @ =FUN_080023dc
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_080023e8
	cmp r0, #0
	bge _080026F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080026F6
	.align 2, 0
_080026E8: .4byte 0x03002B2C
_080026EC: .4byte FUN_08002100
_080026F0: .4byte FUN_080023dc
_080026F4:
	adds r0, r4, #0
_080026F6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080026fc
FUN_080026fc: @ 0x080026FC
	push {lr}
	adds r1, r0, #0
	ldr r0, _08002714 @ =0x03002B2C
	ldr r0, [r0]
	cmp r0, #0
	beq _0800270E
	ldr r2, _08002718 @ =0x00000644
	adds r0, r0, r2
	strb r1, [r0]
_0800270E:
	pop {r0}
	bx r0
	.align 2, 0
_08002714: .4byte 0x03002B2C
_08002718: .4byte 0x00000644

	thumb_func_start FUN_0800271c
FUN_0800271c: @ 0x0800271C
	push {lr}
	ldr r0, _0800272C @ =0x03002B2C
	ldr r0, [r0]
	cmp r0, #0
	beq _08002730
	adds r0, #0x20
	ldrb r0, [r0]
	b _08002732
	.align 2, 0
_0800272C: .4byte 0x03002B2C
_08002730:
	movs r0, #0
_08002732:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002738
FUN_08002738: @ 0x08002738
	ldr r1, _08002740 @ =0x03002B30
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08002740: .4byte 0x03002B30

	thumb_func_start FUN_08002744
FUN_08002744: @ 0x08002744
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, _08002778 @ =0x0300445C
	ldrh r1, [r2, #0x20]
	lsls r1, r1, #6
	ldrh r0, [r2, #0x22]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r4]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r5, [r2, #0x22]
	lsls r0, r5
	cmp r1, r0
	blt _08002780
	str r3, [r4]
	ldrh r0, [r2, #0x1e]
	cmp r0, #2
	bne _0800277C
	strh r3, [r2, #0x1e]
	b _08002780
	.align 2, 0
_08002778: .4byte 0x0300445C
_0800277C:
	movs r0, #5
	strh r0, [r2, #0x1e]
_08002780:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08002788
FUN_08002788: @ 0x08002788
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _080027B8 @ =0x0300445C
	ldrh r0, [r2, #0x20]
	lsls r0, r0, #6
	ldrh r1, [r2, #0x22]
	asrs r0, r1
	str r0, [r3]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r4, [r2, #0x22]
	lsls r0, r4
	cmp r1, r0
	blt _080027B2
	movs r0, #0x40
	str r0, [r3]
	movs r0, #0
	strh r0, [r2, #0x1e]
_080027B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080027B8: .4byte 0x0300445C

	thumb_func_start FUN_080027bc
FUN_080027bc: @ 0x080027BC
	push {r4, r5, lr}
	ldr r0, _080027E0 @ =0x03002B30
	ldr r4, [r0]
	cmp r4, #0
	beq _080027FA
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4, #0x24]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080027FA
	movs r5, #0
	adds r4, #0x26
	b _080027EE
	.align 2, 0
_080027E0: .4byte 0x03002B30
_080027E4:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
_080027EE:
	bl VM_GetPC
	cmp r0, #0
	beq _080027FA
	cmp r5, #6
	ble _080027E4
_080027FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08002800
FUN_08002800: @ 0x08002800
	push {lr}
	adds r3, r0, #0
	ldr r0, _08002828 @ =0x03002B30
	ldr r0, [r0]
	cmp r0, #0
	beq _08002822
	strh r3, [r0, #0x24]
	cmp r1, #0
	ble _08002822
	adds r3, r0, #0
	adds r3, #0x26
_08002816:
	ldm r2!, {r0}
	strh r0, [r3]
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _08002816
_08002822:
	pop {r0}
	bx r0
	.align 2, 0
_08002828: .4byte 0x03002B30

	thumb_func_start FUN_0800282c
FUN_0800282c: @ 0x0800282C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x1e]
	cmp r1, #2
	bhi _0800286C
	ldrh r1, [r4, #0x24]
	cmp r1, #2
	beq _0800285E
	cmp r1, #2
	bgt _08002846
	cmp r1, #1
	beq _08002850
	b _08002898
_08002846:
	cmp r1, #3
	beq _08002850
	cmp r1, #4
	beq _0800285E
	b _08002898
_08002850:
	ldrh r1, [r4, #0x24]
	cmp r1, #1
	beq _08002858
	movs r1, #3
_08002858:
	strh r1, [r4, #0x1e]
	movs r1, #0
	b _0800287A
_0800285E:
	ldrh r1, [r4, #0x24]
	cmp r1, #2
	beq _08002866
	movs r1, #4
_08002866:
	strh r1, [r4, #0x1e]
	movs r1, #0
	b _0800287A
_0800286C:
	ldrh r2, [r4, #0x24]
	cmp r2, #3
	beq _08002876
	cmp r2, #4
	bne _08002898
_08002876:
	movs r1, #0
	strh r2, [r4, #0x1e]
_0800287A:
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x26]
	strh r1, [r4, #0x22]
	ldr r3, _080028A8 @ =0x03004464
	ldrh r2, [r4, #0x2a]
	lsls r2, r2, #5
	ldrh r1, [r4, #0x28]
	orrs r2, r1
	ldrh r1, [r4, #0x2c]
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r3]
	ldr r2, _080028AC @ =0x03004490
	ldrh r1, [r4, #0x2e]
	strh r1, [r2]
_08002898:
	ldrh r1, [r4, #0x1e]
	cmp r1, #2
	beq _080028C2
	cmp r1, #2
	bgt _080028B0
	cmp r1, #1
	beq _080028BA
	b _080028C8
	.align 2, 0
_080028A8: .4byte 0x03004464
_080028AC: .4byte 0x03004490
_080028B0:
	cmp r1, #3
	beq _080028BA
	cmp r1, #4
	beq _080028C2
	b _080028C8
_080028BA:
	adds r0, r4, #0
	bl FUN_08002788
	b _080028C8
_080028C2:
	adds r0, r4, #0
	bl FUN_08002744
_080028C8:
	movs r1, #0
	strh r1, [r4, #0x24]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080028d4
FUN_080028d4: @ 0x080028D4
	ldr r2, _080028DC @ =0x03002B30
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_080028DC: .4byte 0x03002B30

	thumb_func_start FUN_080028e0
FUN_080028e0: @ 0x080028E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08002930 @ =0x03002B30
	str r4, [r0]
	movs r5, #0
	strh r1, [r4, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r4, #0x1a]
	strh r5, [r4, #0x1c]
	strh r5, [r4, #0x1e]
	strh r5, [r4, #0x20]
	strh r5, [r4, #0x22]
	strh r5, [r4, #0x24]
	movs r1, #0
	movs r0, #6
	adds r4, #0x32
_08002906:
	strh r1, [r4]
	subs r4, #2
	subs r0, #1
	cmp r0, #0
	bge _08002906
	movs r2, #0
	ldr r0, _08002934 @ =0x0300445C
	movs r1, #0x40
	str r1, [r0]
	ldr r0, _08002938 @ =0x0300404C
	str r1, [r0]
	ldr r1, _0800293C @ =0x03004464
	ldr r3, _08002940 @ =0x00001084
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _08002944 @ =0x03004490
	strh r2, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08002930: .4byte 0x03002B30
_08002934: .4byte 0x0300445C
_08002938: .4byte 0x0300404C
_0800293C: .4byte 0x03004464
_08002940: .4byte 0x00001084
_08002944: .4byte 0x03004490

	thumb_func_start FUN_08002948
FUN_08002948: @ 0x08002948
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xb
	movs r1, #0x34
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08002984
	ldr r1, _0800297C @ =FUN_0800282c
	ldr r2, _08002980 @ =FUN_080028d4
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_080028e0
	cmp r0, #0
	bge _08002984
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08002986
	.align 2, 0
_0800297C: .4byte FUN_0800282c
_08002980: .4byte FUN_080028d4
_08002984:
	adds r0, r4, #0
_08002986:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800298c
FUN_0800298c: @ 0x0800298C
	push {r4, r5, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r4, r3, #0
	adds r4, #0x90
	movs r1, #0
	ldr r2, [r3, #0x20]
	b _080029A2
_0800299E:
	adds r4, #8
	adds r1, #1
_080029A2:
	cmp r1, r2
	bge _080029AC
	ldrh r0, [r4]
	cmp r0, #0
	bne _0800299E
_080029AC:
	ldr r0, [r3, #0x20]
	cmp r1, r0
	beq _080029C4
	adds r0, r5, #0
	bl FUN_0823b2d0
	str r0, [r4, #4]
	cmp r0, #0
	beq _080029C4
	movs r0, #1
	strh r0, [r4]
	strh r5, [r4, #2]
_080029C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080029cc
FUN_080029cc: @ 0x080029CC
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r2, r4, #0
	adds r2, #0x90
	movs r3, #0
	ldr r0, [r4, #0x20]
	cmp r3, r0
	bge _080029FA
	movs r1, #0
_080029E2:
	ldrh r0, [r2, #2]
	cmp r0, r5
	bne _080029F0
	strh r1, [r2]
	str r1, [r2, #4]
	strh r1, [r2, #2]
	b _080029FA
_080029F0:
	adds r2, #8
	adds r3, #1
	ldr r0, [r4, #0x20]
	cmp r3, r0
	blt _080029E2
_080029FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08002a00
FUN_08002a00: @ 0x08002A00
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08002A38 @ =0x00007BE3
	bl FUN_08230e70
	adds r2, r0, #0
	cmp r2, #0
	beq _08002A3C
	ldr r1, [r2, #0x28]
	cmp r1, #0xf
	bhi _08002A3C
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2c
	adds r0, r0, r1
	strh r4, [r0]
	ldr r1, [r2, #0x28]
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2e
	adds r0, r0, r1
	strh r5, [r0]
	ldr r0, [r2, #0x28]
	adds r0, #1
	str r0, [r2, #0x28]
	movs r0, #0
	b _08002A40
	.align 2, 0
_08002A38: .4byte 0x00007BE3
_08002A3C:
	movs r0, #1
	rsbs r0, r0, #0
_08002A40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002a48
FUN_08002a48: @ 0x08002A48
	push {lr}
	ldrh r1, [r0]
	movs r0, #0
	bl FUN_08002a00
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002a58
FUN_08002a58: @ 0x08002A58
	push {lr}
	ldrh r1, [r0]
	movs r0, #1
	bl FUN_08002a00
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002a68
FUN_08002a68: @ 0x08002A68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	str r0, [sp, #0x44]
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	bne _08002AAE
	movs r0, #1
	ldr r1, [sp, #0x44]
	str r0, [r1, #0x1c]
	movs r5, #0
	ldr r0, [r1, #0x24]
	adds r6, r1, #0
	adds r6, #0x88
	cmp r5, r0
	bge _08002AAE
_08002A8E:
	ldr r1, [r6]
	movs r0, #0x2c
	muls r0, r5, r0
	adds r1, r0, r1
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08002AA4
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0822a340
_08002AA4:
	adds r5, #1
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x24]
	cmp r5, r0
	blt _08002A8E
_08002AAE:
	movs r5, #0
	ldr r3, [sp, #0x44]
	ldr r0, [r3, #0x28]
	adds r6, r3, #0
	adds r6, #0x88
	adds r7, r3, #0
	adds r7, #0x90
	cmp r5, r0
	bhs _08002AF6
	adds r4, r3, #0
	adds r4, #0x2e
_08002AC4:
	lsls r1, r5, #2
	ldr r0, [sp, #0x44]
	adds r0, #0x2c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08002AD8
	cmp r0, #1
	beq _08002AE2
	b _08002AEA
_08002AD8:
	ldrh r1, [r4]
	ldr r0, [sp, #0x44]
	bl FUN_0800298c
	b _08002AEA
_08002AE2:
	ldrh r1, [r4]
	ldr r0, [sp, #0x44]
	bl FUN_080029cc
_08002AEA:
	adds r4, #4
	adds r5, #1
	ldr r1, [sp, #0x44]
	ldr r0, [r1, #0x28]
	cmp r5, r0
	blo _08002AC4
_08002AF6:
	movs r0, #0
	ldr r2, [sp, #0x44]
	str r0, [r2, #0x28]
	movs r3, #0
	str r3, [sp, #0x48]
	ldr r6, [r6]
	mov r8, r6
	mov sb, r7
	movs r7, #0
	ldr r0, [r2, #0x20]
	cmp r3, r0
	blt _08002B10
	b _08002E24
_08002B10:
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x58]
	mov r1, sp
	adds r1, #0x2c
	str r1, [sp, #0x5c]
_08002B1C:
	mov r2, sb
	ldr r4, [r2, #4]
	ldrh r0, [r2]
	adds r3, r7, #1
	str r3, [sp, #0x60]
	adds r2, #8
	str r2, [sp, #0x64]
	cmp r0, #0
	bne _08002B30
	b _08002E14
_08002B30:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08002B42
	ldr r0, [r0, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08002B42
	b _08002E14
_08002B42:
	ldr r1, [r4, #0x28]
	cmp r1, #0
	beq _08002B5E
	ldr r1, [r1]
	movs r0, #1
	ands r1, r0
	adds r0, r7, #1
	str r0, [sp, #0x60]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x64]
	cmp r1, #0
	beq _08002B5E
	b _08002E14
_08002B5E:
	movs r1, #1
	ldrh r0, [r4, #2]
	ands r0, r1
	adds r3, r7, #1
	str r3, [sp, #0x60]
	mov r1, sb
	adds r1, #8
	str r1, [sp, #0x64]
	cmp r0, #0
	beq _08002B74
	b _08002E14
_08002B74:
	movs r3, #0xa
	ldrsh r2, [r4, r3]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r2, r0
	str r2, [sp, #0x50]
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r0, [sp, #0x50]
	asrs r0, r0, #8
	str r0, [sp, #0x54]
	str r0, [sp]
	movs r5, #0xff
	str r5, [sp, #0x10]
	ldrh r1, [r4, #8]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002BE0
	ldrh r1, [r4, #0xc]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002BC4
	adds r0, r3, #1
	str r0, [sp, #0x20]
	str r2, [sp, #0x2c]
	ldr r1, [sp, #0x58]
	str r0, [r1, #4]
	adds r0, r2, #1
	ldr r2, [sp, #0x5c]
	str r0, [r2, #4]
	str r3, [r1, #8]
	str r0, [r2, #8]
	movs r3, #0
	b _08002C28
_08002BC4:
	subs r0, r3, #1
	str r0, [sp, #0x20]
	adds r1, r2, #1
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x58]
	str r3, [r2, #4]
	ldr r0, [sp, #0x5c]
	str r1, [r0, #4]
	adds r0, r3, #1
	str r0, [r2, #8]
	ldr r2, [sp, #0x5c]
	str r1, [r2, #8]
	movs r3, #1
	b _08002C28
_08002BE0:
	ldrh r1, [r4, #0xc]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002C12
	adds r0, r3, #1
	str r0, [sp, #0x20]
	subs r1, r2, #1
	str r1, [sp, #0x2c]
	ldr r3, [sp, #0x58]
	str r0, [r3, #4]
	ldr r1, [sp, #0x5c]
	str r2, [r1, #4]
	str r0, [r3, #8]
	adds r0, r2, #1
	str r0, [r1, #8]
	movs r2, #2
	str r2, [sp, #0x4c]
	mov r3, sp
	adds r3, #0x20
	str r3, [sp, #0x68]
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x6c]
	b _08002C36
_08002C12:
	adds r0, r3, #1
	str r0, [sp, #0x20]
	str r2, [sp, #0x2c]
	ldr r1, [sp, #0x58]
	str r0, [r1, #4]
	adds r0, r2, #1
	ldr r2, [sp, #0x5c]
	str r0, [r2, #4]
	str r3, [r1, #8]
	str r0, [r2, #8]
	movs r3, #3
_08002C28:
	str r3, [sp, #0x4c]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x68]
	mov r1, sp
	adds r1, #0x2c
	str r1, [sp, #0x6c]
_08002C36:
	movs r5, #0
	mov r2, sp
	adds r2, #0x38
	str r2, [sp, #0x70]
	add r6, sp, #0x10
	adds r3, r7, #1
	str r3, [sp, #0x60]
	mov r0, sb
	adds r0, #8
	str r0, [sp, #0x64]
	movs r1, #1
	str r1, [sp, #0x74]
	add r2, sp, #4
	mov sl, r2
	movs r3, #4
	str r3, [sp, #0x78]
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0x70]
	str r1, [sp, #0x80]
	movs r2, #0
	str r2, [sp, #0x84]
_08002C64:
	ldr r3, [sp, #0x6c]
	ldr r1, [sp, #0x84]
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r2, _08002C98 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, [sp, #0x68]
	ldr r2, [sp, #0x84]
	adds r0, r3, r2
	ldr r0, [r0]
	adds r4, r1, r0
	ldr r3, [sp, #0x80]
	str r4, [r3]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08002C9C
	adds r3, r0, #4
	b _08002CA8
	.align 2, 0
_08002C98: .4byte 0x030046A4
_08002C9C:
	ldr r1, _08002CC8 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r3, r0, r1
_08002CA8:
	cmp r3, #0
	beq _08002CBA
	ldrh r1, [r3, #2]
	movs r2, #0x10
	mov sb, r2
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _08002CCC
_08002CBA:
	movs r0, #0
	mov r3, sl
	str r0, [r3]
	movs r0, #0xff
	ldr r1, [sp, #0x7c]
	b _08002D3A
	.align 2, 0
_08002CC8: .4byte 0x030046A4
_08002CCC:
	ldrb r1, [r3]
	movs r2, #0xf
	mov ip, r2
	mov r0, ip
	ands r0, r1
	mov r1, sl
	str r0, [r1]
	ldr r4, [sp]
	subs r0, r0, r4
	ldr r7, [sp, #0x74]
	cmp r0, #0
	bge _08002CE6
	rsbs r0, r0, #0
_08002CE6:
	cmp r0, #1
	ble _08002D34
	ldr r0, [sp, #0x80]
	ldr r2, [r0]
	ldr r1, _08002D18 @ =0x030046A4
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _08002D0C
	lsls r0, r2, #2
	adds r0, #0xc
	adds r2, r1, r0
	cmp r2, #0
	beq _08002D0C
	ldrh r1, [r2, #2]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _08002D1C
_08002D0C:
	lsls r0, r7, #2
	adds r0, r6, r0
	movs r1, #0xff
	str r1, [r0]
	b _08002D3C
	.align 2, 0
_08002D18: .4byte 0x030046A4
_08002D1C:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	cmp r0, r4
	bgt _08002D2C
	ldr r2, [sp, #0x78]
	adds r1, r6, r2
	b _08002D38
_08002D2C:
	ldr r3, [sp, #0x78]
	adds r1, r6, r3
	ldrb r0, [r2, #1]
	b _08002D3A
_08002D34:
	ldr r0, [sp, #0x78]
	adds r1, r6, r0
_08002D38:
	ldrb r0, [r3, #1]
_08002D3A:
	str r0, [r1]
_08002D3C:
	ldr r1, [sp, #0x74]
	adds r1, #1
	str r1, [sp, #0x74]
	movs r2, #4
	add sl, r2
	ldr r3, [sp, #0x78]
	adds r3, #4
	str r3, [sp, #0x78]
	ldr r0, [sp, #0x7c]
	adds r0, #4
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0x80]
	adds r1, #4
	str r1, [sp, #0x80]
	ldr r2, [sp, #0x84]
	adds r2, #4
	str r2, [sp, #0x84]
	adds r5, #1
	cmp r5, #2
	bgt _08002D66
	b _08002C64
_08002D66:
	movs r5, #0
_08002D68:
	adds r0, r5, #1
	lsls r2, r0, #2
	mov r3, sp
	adds r1, r3, r2
	ldr r3, [sp]
	ldr r1, [r1]
	adds r7, r0, #0
	cmp r3, r1
	bge _08002E0E
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #0xff
	beq _08002E0E
	ldr r0, [sp, #0x4c]
	cmp r0, #1
	bne _08002D8E
	ldr r0, [sp, #8]
	cmp r3, r0
	bge _08002E0E
_08002D8E:
	ldr r1, [sp, #0x4c]
	cmp r1, #2
	bne _08002D9A
	ldr r0, [sp, #8]
	cmp r3, r0
	bge _08002E0E
_08002D9A:
	lsls r2, r5, #2
	ldr r3, [sp, #0x70]
	adds r0, r3, r2
	ldr r3, [sp, #0x54]
	lsls r1, r3, #0x10
	ldr r5, [r0]
	orrs r5, r1
	ldr r0, [sp, #0x44]
	adds r0, #0x8c
	ldr r4, [r0]
	movs r3, #0
	ldr r0, [sp, #0x48]
	cmp r3, r0
	bge _08002DC8
	b _08002DC2
_08002DB8:
	adds r3, #1
	adds r4, #4
	ldr r1, [sp, #0x48]
	cmp r3, r1
	bge _08002DC8
_08002DC2:
	ldr r0, [r4]
	cmp r0, r5
	bne _08002DB8
_08002DC8:
	ldr r0, [sp, #0x48]
	cmp r3, r0
	bne _08002E0E
	lsls r0, r7, #2
	adds r0, r6, r0
	ldr r0, [r0]
	mov r1, r8
	strh r0, [r1, #0x10]
	ldr r3, [sp, #0x68]
	adds r0, r3, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	adds r0, #0x80
	strh r0, [r1, #0x1c]
	add r0, sp, #0x50
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	ldr r1, [sp, #0x6c]
	adds r0, r1, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	adds r0, #0x80
	mov r2, r8
	strh r0, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	str r5, [r4]
	ldr r3, [sp, #0x48]
	adds r3, #1
	str r3, [sp, #0x48]
	movs r0, #0x2c
	add r8, r0
_08002E0E:
	adds r5, r7, #0
	cmp r5, #2
	ble _08002D68
_08002E14:
	ldr r7, [sp, #0x60]
	ldr r1, [sp, #0x64]
	mov sb, r1
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x20]
	cmp r7, r0
	bge _08002E24
	b _08002B1C
_08002E24:
	ldr r3, [sp, #0x44]
	ldr r0, [r3, #0x24]
	ldr r1, [sp, #0x48]
	cmp r1, r0
	bge _08002E4C
	movs r1, #1
_08002E30:
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x2c
	add r8, r3
	ldr r0, [sp, #0x48]
	adds r0, #1
	str r0, [sp, #0x48]
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x24]
	ldr r3, [sp, #0x48]
	cmp r3, r0
	blt _08002E30
_08002E4C:
	movs r0, #0
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002e60
FUN_08002e60: @ 0x08002E60
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	b _08002E82
_08002E68:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [r0]
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r0, r1
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08002E80
	adds r0, r1, #0
	bl FUN_0822a4e0
_08002E80:
	adds r4, #1
_08002E82:
	ldr r0, [r5, #0x24]
	cmp r4, r0
	blt _08002E68
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08002e90
FUN_08002e90: @ 0x08002E90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0
	strh r1, [r6, #0x18]
	strh r2, [r6, #0x1a]
	str r0, [r6, #0x1c]
	str r0, [r6, #0x28]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08002EB8
	bl Script_GetValue
	adds r1, r0, #0
	adds r4, r6, #0
	adds r4, #0x6c
	b _08002EC8
_08002EB8:
	adds r4, r6, #0
	adds r4, #0x6c
	ldr r0, _08002EDC @ =0x08251B2C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
_08002EC8:
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r7, r4, #0
	cmp r0, #0
	bne _08002EE0
	movs r0, #1
	rsbs r0, r0, #0
	b _08002F32
	.align 2, 0
_08002EDC: .4byte 0x08251B2C
_08002EE0:
	movs r5, #0
	ldr r0, [r6, #0x24]
	cmp r5, r0
	bge _08002F14
	movs r0, #0x88
	adds r0, r0, r6
	mov r8, r0
_08002EEE:
	movs r0, #0x2c
	muls r0, r5, r0
	mov r1, r8
	ldr r4, [r1]
	adds r4, r4, r0
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0822a4b0
	ldr r0, [r4, #0x18]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r5, #1
	ldr r0, [r6, #0x24]
	cmp r5, r0
	blt _08002EEE
_08002F14:
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x2c
	bl FUN_0822ceb4
	movs r0, #0
	movs r1, #0x10
	bl FUN_0822cec8
	ldr r0, _08002F3C @ =0x00007BE3
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
_08002F32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08002F3C: .4byte 0x00007BE3

	thumb_func_start FUN_08002f40
FUN_08002f40: @ 0x08002F40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08002F68
	bl Script_GetValue
	adds r5, r0, #0
	b _08002F6A
_08002F68:
	movs r5, #8
_08002F6A:
	lsls r0, r5, #5
	adds r0, r0, r5
	lsls r0, r0, #2
	mov r8, r0
	lsls r0, r5, #3
	adds r6, r0, #0
	adds r6, #0x90
	mov r0, r8
	adds r1, r0, r6
	lsls r0, r5, #1
	adds r7, r0, r5
	lsls r0, r7, #2
	adds r1, r1, r0
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08002FCC
	ldr r1, _08002FC4 @ =0x08002A69
	ldr r2, _08002FC8 @ =0x08002E61
	bl SetEntityRoutine
	adds r1, r4, #0
	adds r1, #0x88
	adds r0, r4, r6
	str r0, [r1]
	adds r1, #4
	add r0, r8
	str r0, [r1]
	str r5, [r4, #0x20]
	str r7, [r4, #0x24]
	adds r0, r4, #0
	mov r1, sl
	mov r2, sb
	bl FUN_08002e90
	cmp r0, #0
	bge _08002FCC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08002FCE
	.align 2, 0
_08002FC4: .4byte 0x08002A69
_08002FC8: .4byte 0x08002E61
_08002FCC:
	adds r0, r4, #0
_08002FCE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08002fdc
FUN_08002fdc: @ 0x08002FDC
	push {r4, lr}
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08002FFE
	adds r0, r4, #0
	bl FUN_08002a00
	b _08003002
_08002FFE:
	movs r0, #1
	rsbs r0, r0, #0
_08003002:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08003008
FUN_08003008: @ 0x08003008
	ldr r1, _08003010 @ =0x03000020
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08003010: .4byte 0x03000020

	thumb_func_start FUN_08003014
FUN_08003014: @ 0x08003014
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	mov r8, r1
	ldr r3, _0800308C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08003090 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r7, #0
	add r4, sp, #0x10
	ldr r6, _08003094 @ =0x030046B8
	ldr r5, _08003098 @ =0x000003FF
_08003042:
	ldr r0, [r6]
	adds r2, r0, #1
	ands r2, r5
	str r2, [r6]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _080030A0
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _0800309C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r3, [r4]
	adds r0, r0, r3
	add r1, sp, #0x10
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _0800309C @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r4, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	b _080030CC
	.align 2, 0
_0800308C: .4byte 0xFFFF0000
_08003090: .4byte 0x0000FFFF
_08003094: .4byte 0x030046B8
_08003098: .4byte 0x000003FF
_0800309C: .4byte 0x0203B400
_080030A0:
	adds r1, r2, #1
	ands r1, r5
	lsls r2, r1, #1
	ldr r3, _080030F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r0, [r4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	add r2, sp, #0x10
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r1, [r4, #4]
	adds r0, r0, r1
_080030CC:
	strh r0, [r4, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	adds r7, #1
	cmp r7, #9
	ble _08003042
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080030F8: .4byte 0x0203B400

	thumb_func_start FUN_080030fc
FUN_080030fc: @ 0x080030FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003130
	cmp r2, #1
	bgt _08003112
	cmp r2, #0
	beq _0800311C
	b _08003148
_08003112:
	cmp r2, #2
	beq _08003134
	cmp r2, #3
	beq _08003144
	b _08003148
_0800311C:
	ldr r0, _0800312C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _08003148
	.align 2, 0
_0800312C: .4byte 0x030046A4
_08003130:
	movs r0, #1
	b _08003148
_08003134:
	ldr r0, _08003140 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _08003148
	.align 2, 0
_08003140: .4byte 0x030046A4
_08003144:
	movs r0, #1
	rsbs r0, r0, #0
_08003148:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800315A
	adds r4, r0, #4
	b _08003166
_0800315A:
	ldr r0, _0800318C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r4, r1, r0
_08003166:
	cmp r4, #0
	beq _0800319E
	ldrb r3, [r4]
	lsrs r0, r3, #4
	cmp r0, #0
	bne _08003190
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	blo _0800319E
	ldrh r1, [r4, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800319E
	b _080031A2
	.align 2, 0
_0800318C: .4byte 0x030046A4
_08003190:
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bhs _080031A2
_0800319E:
	movs r0, #0
	b _080031A4
_080031A2:
	movs r0, #1
_080031A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080031ac
FUN_080031ac: @ 0x080031AC
	push {lr}
	cmp r0, #5
	bne _080031C0
	ldr r0, _080031BC @ =0x00000151
	bl PlaySound_082406e0
	b _080031C6
	.align 2, 0
_080031BC: .4byte 0x00000151
_080031C0:
	ldr r0, _080031CC @ =0x00000151
	bl PlaySound_082406e0
_080031C6:
	pop {r0}
	bx r0
	.align 2, 0
_080031CC: .4byte 0x00000151

	thumb_func_start FUN_080031d0
FUN_080031d0: @ 0x080031D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003204
	cmp r2, #1
	bgt _080031E8
	cmp r2, #0
	beq _080031F2
	b _0800321C
_080031E8:
	cmp r2, #2
	beq _08003208
	cmp r2, #3
	beq _08003218
	b _0800321C
_080031F2:
	ldr r0, _08003200 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _0800321C
	.align 2, 0
_08003200: .4byte 0x030046A4
_08003204:
	movs r0, #1
	b _0800321C
_08003208:
	ldr r0, _08003214 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _0800321C
	.align 2, 0
_08003214: .4byte 0x030046A4
_08003218:
	movs r0, #1
	rsbs r0, r0, #0
_0800321C:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800322E
	adds r0, #4
	b _0800323A
_0800322E:
	ldr r0, _08003254 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800323A:
	cmp r0, #0
	beq _08003262
	ldrb r2, [r0]
	movs r0, #0xf
	ldrb r3, [r6]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	blo _08003258
	movs r0, #1
	b _08003264
	.align 2, 0
_08003254: .4byte 0x030046A4
_08003258:
	ldrb r0, [r5]
	cmp r0, #5
	bne _08003262
	bl FUN_080031ac
_08003262:
	movs r0, #0
_08003264:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800326c
FUN_0800326c: @ 0x0800326C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
_08003274:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_080030fc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800328A
	adds r6, #1
_0800328A:
	adds r4, #1
	cmp r4, #3
	ble _08003274
	cmp r6, #2
	bgt _08003298
	movs r0, #0
	b _0800329A
_08003298:
	movs r0, #1
_0800329A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080032a0
FUN_080032a0: @ 0x080032A0
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, _080032C0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080032C4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080032C8
	movs r0, #1
	b _080032CA
	.align 2, 0
_080032C0: .4byte 0x030046A0
_080032C4: .4byte 0x00000934
_080032C8:
	movs r0, #0
_080032CA:
	cmp r0, #0
	beq _08003338
	ldr r0, _0800332C @ =0x00000145
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	adds r4, r0, #0
	asrs r2, r4, #0x10
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #0x10
	ldr r3, _08003330 @ =0x0000FFFF
	ands r4, r3
	adds r0, r4, #0
	orrs r0, r2
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003334 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_08016110
	b _080033A2
	.align 2, 0
_0800332C: .4byte 0x00000145
_08003330: .4byte 0x0000FFFF
_08003334: .4byte 0xFFFF0000
_08003338:
	ldrb r0, [r4]
	cmp r0, #1
	beq _0800334C
	cmp r0, #1
	bgt _08003348
	cmp r0, #0
	beq _0800334C
	b _08003358
_08003348:
	cmp r0, #6
	bgt _08003358
_0800334C:
	ldr r0, _08003354 @ =0x00000143
	bl PlaySound_082406e0
	b _0800335E
	.align 2, 0
_08003354: .4byte 0x00000143
_08003358:
	ldr r0, _08003394 @ =0x00000143
	bl PlaySound_082406e0
_0800335E:
	adds r0, r4, #0
	bl FUN_0800326c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003398
	movs r0, #0
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r0, #0xa8
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015ce0
	b _080033A2
	.align 2, 0
_08003394: .4byte 0x00000143
_08003398:
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0x90
	bl FUN_08003014
_080033A2:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080033ac
FUN_080033ac: @ 0x080033AC
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r4, #0x10]
	adds r0, r4, #0
	bl FUN_080031d0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003484
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _08003408
	cmp r0, #1
	bgt _080033E2
	cmp r0, #0
	beq _080033EC
	b _0800345A
_080033E2:
	cmp r0, #2
	beq _08003428
	cmp r0, #3
	beq _08003444
	b _0800345A
_080033EC:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003404 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0xb0
	b _0800345A
	.align 2, 0
_08003404: .4byte 0xFFFF0000
_08003408:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003424 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x10
	rsbs r1, r1, #0
	b _0800345A
	.align 2, 0
_08003424: .4byte 0xFFFF0000
_08003428:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003440 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r1, #0x30
	b _0800345A
	.align 2, 0
_08003440: .4byte 0xFFFF0000
_08003444:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800348C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x70
_0800345A:
	str r1, [sp]
	movs r0, #0x1f
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #2
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015ce0
	ldrb r0, [r4]
	bl FUN_080031ac
_08003484:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800348C: .4byte 0xFFFF0000

	thumb_func_start FUN_08003490
FUN_08003490: @ 0x08003490
	push {lr}
	cmp r0, #1
	beq _080034AE
	cmp r0, #1
	bgt _080034A0
	cmp r0, #0
	beq _080034A4
	b _080034BC
_080034A0:
	cmp r0, #5
	bgt _080034BC
_080034A4:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080034C4
_080034AE:
	ldr r0, _080034B8 @ =0x00000137
	bl PlaySound_082406e0
	b _080034C4
	.align 2, 0
_080034B8: .4byte 0x00000137
_080034BC:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080034C4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080034c8
FUN_080034c8: @ 0x080034C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r0, r2, #0
	movs r3, #0
	adds r4, r0, #0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08003508
	movs r1, #7
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	b _0800359E
_08003508:
	cmp r2, #1
	bne _08003574
	movs r6, #4
	ldr r0, [r5, #0x38]
	ands r0, r6
	cmp r0, #0
	beq _0800359A
	ldr r0, _08003570 @ =0x00010007
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	bne _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r7, #0xa
	strb r7, [r4, #0x18]
	movs r0, #2
	strb r0, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800359E
	strb r7, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0xc
	str r1, [sp]
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	b _0800359E
	.align 2, 0
_08003570: .4byte 0x00010007
_08003574:
	cmp r2, #2
	bne _0800359A
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800359A
	ldrh r0, [r4, #0x16]
	subs r0, #0x18
	strh r0, [r4, #0x16]
	movs r0, #0xa
	strb r0, [r4, #0x18]
	strb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r1, [r4, #0x1c]
	bl FUN_0822b20c
	movs r3, #1
_0800359A:
	cmp r3, #0
	beq _080035D6
_0800359E:
	ldrh r0, [r4, #4]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080035B6
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080035C4
	movs r0, #1
	strh r0, [r4, #0x16]
_080035B6:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080035C4
	movs r0, #0
	strh r0, [r4, #0x16]
	b _080035D6
_080035C4:
	movs r1, #4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _080035D6
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080035D6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080035e0
FUN_080035e0: @ 0x080035E0
	bx lr
	.align 2, 0

	thumb_func_start FUN_080035e4
FUN_080035e4: @ 0x080035E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r0, _08003674 @ =0x03000020
	ldr r7, [r0]
	ldr r3, [r7, #0x70]
	movs r6, #0
	ldrh r0, [r7, #0x18]
	cmp r6, r0
	bge _08003690
	movs r1, #0xf
	mov r8, r1
	ldr r2, _08003678 @ =FUN_080040f0
	mov sl, r2
	movs r0, #0
	mov sb, r0
_0800360A:
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08003682
	cmp r3, ip
	beq _08003682
	adds r2, r3, #0
	adds r2, #0xbc
	mov r5, ip
	adds r5, #0xbc
	adds r0, r3, #0
	adds r0, #0xba
	mov r1, ip
	adds r1, #0xba
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08003682
	ldrh r4, [r3, #4]
	cmp r4, #0
	bne _08003682
	ldrb r0, [r2]
	ldrb r2, [r5]
	mov r1, r8
	ands r1, r0
	mov r0, r8
	ands r0, r2
	cmp r1, r0
	bls _08003682
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r3, r1
	mov r2, sl
	str r2, [r0]
	strh r4, [r3, #2]
	movs r0, #1
	strb r0, [r3, #0x11]
	movs r0, #2
	strh r0, [r3, #4]
	strh r4, [r3, #0xc]
	strh r4, [r3, #0xe]
	mov r0, sb
	strb r0, [r3, #0x10]
	ldrh r1, [r3, #0x36]
	strh r1, [r3, #0x12]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08003680
	ldr r2, _0800367C @ =0xFFFFFF00
	adds r0, r1, r2
	strh r0, [r3, #0x12]
	b _08003682
	.align 2, 0
_08003674: .4byte 0x03000020
_08003678: .4byte FUN_080040f0
_0800367C: .4byte 0xFFFFFF00
_08003680:
	strh r4, [r3, #0x12]
_08003682:
	adds r6, #1
	movs r0, #0xce
	lsls r0, r0, #1
	adds r3, r3, r0
	ldrh r1, [r7, #0x18]
	cmp r6, r1
	blt _0800360A
_08003690:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080036a0
FUN_080036a0: @ 0x080036A0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xb8
	bl FUN_082342a8
	adds r0, r4, #0
	adds r0, #0xc8
	bl FUN_08236424
	ldrb r1, [r4, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080036CC
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_08002a58
_080036CC:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_0823b284
	movs r0, #0
	strb r0, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080036e0
FUN_080036e0: @ 0x080036E0
	push {r4, r5, r6, lr}
	ldr r0, _080036F0 @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _080036F4
	movs r0, #1
	rsbs r0, r0, #0
	b _08003716
	.align 2, 0
_080036F0: .4byte 0x03000020
_080036F4:
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _0800370E
_080036FA:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _08003706
	adds r0, r4, #0
	bl FUN_080036a0
_08003706:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_0800370E:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080036FA
	movs r0, #0
_08003716:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800371c
FUN_0800371c: @ 0x0800371C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0800372C @ =0x03000020
	ldr r5, [r0]
	cmp r5, #0
	bne _08003730
	movs r0, #1
	rsbs r0, r0, #0
	b _08003772
	.align 2, 0
_0800372C: .4byte 0x03000020
_08003730:
	ldr r1, [r5, #0x70]
	movs r4, #0
	ldrh r0, [r5, #0x18]
	cmp r4, r0
	bge _08003770
	ldr r6, _08003778 @ =FUN_080041c4
_0800373C:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _08003762
	ldrb r3, [r1]
	cmp r3, #1
	bne _08003762
	movs r0, #0
	strh r0, [r1, #0x16]
	ldrh r2, [r1, #4]
	cmp r2, #0
	bne _08003762
	movs r7, #0xcc
	lsls r7, r7, #1
	adds r0, r1, r7
	str r6, [r0]
	strh r2, [r1, #2]
	strb r3, [r1, #0x11]
	movs r0, #3
	strh r0, [r1, #4]
_08003762:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #1
	ldrh r7, [r5, #0x18]
	cmp r4, r7
	blt _0800373C
_08003770:
	movs r0, #0
_08003772:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08003778: .4byte FUN_080041c4

	thumb_func_start FUN_0800377c
FUN_0800377c: @ 0x0800377C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0800378C @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _08003790
	movs r0, #1
	rsbs r0, r0, #0
	b _080037C2
	.align 2, 0
_0800378C: .4byte 0x03000020
_08003790:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _080037BA
_080037A0:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080037B2
	ldrh r0, [r4, #0x2c]
	cmp r0, r7
	bne _080037B2
	adds r0, r4, #0
	bl FUN_080036a0
_080037B2:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_080037BA:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080037A0
	movs r0, #0
_080037C2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080037c8
FUN_080037c8: @ 0x080037C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r6, r0, #0
	ldr r0, _080038AC @ =0x0000015B
	bl PlaySound_082406e0
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0x1e
	str r0, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0
	mov sl, r1
	str r1, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	str r2, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #2
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	movs r1, #0x1e
	str r1, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r2, sl
	str r2, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r1, r8
	str r1, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #6
	adds r2, r7, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _080038B0 @ =0xFFFF0000
	ldrh r1, [r6, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r5, _080038B4 @ =0x0000FFFF
	ldrh r0, [r6, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r6, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _080038B8 @ =0x0000FFF1
	orrs r0, r4
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	movs r1, #0x1e
	orrs r0, r1
	ands r0, r5
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	movs r2, #0x1e
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080038AC: .4byte 0x0000015B
_080038B0: .4byte 0xFFFF0000
_080038B4: .4byte 0x0000FFFF
_080038B8: .4byte 0x0000FFF1

	thumb_func_start FUN_080038bc
FUN_080038bc: @ 0x080038BC
	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r4, r0, #0
	ldr r0, _08003960 @ =0x00000135
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0x34
	movs r5, #0x1e
	str r5, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x18
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #4
	movs r1, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r2, _08003964 @ =0xFFFF0000
	ldrh r1, [r4, #0x36]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r6, _08003968 @ =0x0000FFFF
	ldrh r0, [r4, #0x34]
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r4, #0x38]
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r2
	ldr r4, _0800396C @ =0x0000FFF1
	orrs r0, r4
	ands r0, r6
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldr r0, [sp, #0x30]
	ands r0, r2
	orrs r0, r5
	ands r0, r6
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x30]
	add r1, sp, #0x30
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #2
	add r2, sp, #0x20
	bl FUN_08014730
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003960: .4byte 0x00000135
_08003964: .4byte 0xFFFF0000
_08003968: .4byte 0x0000FFFF
_0800396C: .4byte 0x0000FFF1

	thumb_func_start FUN_08003970
FUN_08003970: @ 0x08003970
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r6, #0x34
	movs r7, #0x1e
	str r7, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #1
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	str r7, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r0, r8
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #5
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080039ec
FUN_080039ec: @ 0x080039EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x18]
	ldr r2, _08003A44 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08003A48 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	add r5, sp, #0x10
	ldr r0, _08003A4C @ =0x0203B400
	mov sb, r0
	ldr r1, _08003A50 @ =0x030046B8
	mov r8, r1
	ldr r7, _08003A54 @ =0x000003FF
	adds r6, r2, #0
	movs r2, #2
	str r2, [sp, #0x1c]
	movs r3, #0xff
	mov sl, r3
	adds r4, r5, #0
_08003A2A:
	ldr r2, [sp, #0x18]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	beq _08003AA0
	cmp r0, #1
	bgt _08003A58
	cmp r0, #0
	beq _08003A62
	b _08003B40
	.align 2, 0
_08003A44: .4byte 0xFFFF0000
_08003A48: .4byte 0x0000FFFF
_08003A4C: .4byte 0x0203B400
_08003A50: .4byte 0x030046B8
_08003A54: .4byte 0x000003FF
_08003A58:
	cmp r0, #2
	beq _08003ABA
	cmp r0, #3
	beq _08003AF8
	b _08003B40
_08003A62:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	adds r1, #0x78
	movs r0, #0xf
	ands r2, r0
	adds r1, r1, r2
	b _08003B34
_08003AA0:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	subs r1, #0x78
	movs r0, #0xf
	ands r3, r0
	subs r1, r1, r3
	b _08003B10
_08003ABA:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x78
	movs r0, #0xf
	ands r2, r0
	subs r1, r1, r2
	b _08003B34
_08003AF8:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	adds r1, #0x78
	movs r0, #0xf
	ands r3, r0
	adds r1, r1, r3
_08003B10:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r3, r8
	str r2, [r3]
	lsls r2, r2, #1
	add r2, sb
	ldrh r0, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x80
	mov r2, sl
	ands r0, r2
	adds r1, r1, r0
_08003B34:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
_08003B40:
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	ldr r3, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0x1c]
	cmp r3, #0
	blt _08003B60
	b _08003A2A
_08003B60:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08003b70
FUN_08003b70: @ 0x08003B70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	movs r0, #0xbc
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	movs r2, #0
	str r2, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BB4 @ =0x03002B8C
	ldrh r0, [r0]
	cmp r0, #0
	beq _08003BA4
	ldr r0, _08003BB8 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #2
	bne _08003BA4
	movs r2, #1
_08003BA4:
	cmp r2, #0
	bne _08003BAE
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003BBC
_08003BAE:
	movs r0, #0x10
	movs r2, #0x10
	b _08003BC0
	.align 2, 0
_08003BB4: .4byte 0x03002B8C
_08003BB8: .4byte 0x03002B60
_08003BBC:
	movs r0, #4
	movs r2, #0x40
_08003BC0:
	str r2, [sp, #8]
	mov r2, r8
	cmp r2, #1
	beq _08003BF4
	cmp r2, #1
	bgt _08003BD2
	cmp r2, #0
	beq _08003BDE
	b _08003C14
_08003BD2:
	mov r2, r8
	cmp r2, #2
	beq _08003BFA
	cmp r2, #3
	beq _08003C0C
	b _08003C14
_08003BDE:
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, _08003BF0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r1, r0, #0
	b _08003C14
	.align 2, 0
_08003BF0: .4byte 0x030046A4
_08003BF4:
	str r0, [sp]
	movs r1, #1
	b _08003C14
_08003BFA:
	str r0, [sp, #4]
	ldr r0, _08003C08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	b _08003C14
	.align 2, 0
_08003C08: .4byte 0x030046A4
_08003C0C:
	rsbs r0, r0, #0
	str r0, [sp]
	movs r1, #1
	rsbs r1, r1, #0
_08003C14:
	adds r4, r4, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	mov sb, r4
	cmp r0, #0
	beq _08003C28
	adds r6, r0, #4
	b _08003C36
_08003C28:
	ldr r0, _08003CA4 @ =0x030046A4
	ldr r1, [r0]
	mov r2, sb
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r6, r1, r0
_08003C36:
	cmp r6, #0
	beq _08003D06
	ldrb r1, [r6]
	movs r4, #0xf0
	lsrs r7, r1, #4
	cmp r7, #0
	bne _08003D04
	movs r0, #0xf
	mov ip, r0
	mov r2, sl
	ldrb r0, [r2]
	mov r3, ip
	ands r3, r1
	mov r2, ip
	ands r2, r0
	cmp r3, r2
	bhs _08003D06
	ldrh r1, [r6, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08003D06
	subs r0, r2, r3
	cmp r0, #1
	ble _08003CAC
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r0, r8
	strb r0, [r5, #0x10]
	ldr r1, _08003CA8 @ =FUN_08003f80
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r5, #0xe]
	movs r0, #2
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r2, sb
	strh r2, [r0]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r5, #0x14]
	movs r0, #3
	b _08003D08
	.align 2, 0
_08003CA4: .4byte 0x030046A4
_08003CA8: .4byte FUN_08003f80
_08003CAC:
	lsls r0, r3, #8
	strh r0, [r5, #0x12]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	ble _08003CBE
	subs r0, #1
_08003CBE:
	ands r4, r1
	orrs r4, r0
	mov r0, sl
	strb r4, [r0]
	ldrb r0, [r6, #1]
	mov r1, sl
	strb r0, [r1, #1]
	mov r2, r8
	strb r2, [r5, #0x10]
	ldr r1, _08003D00 @ =FUN_08003f80
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #0xc]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r5, #0xe]
	strh r0, [r5, #4]
	adds r0, r5, #0
	adds r0, #0xba
	mov r1, sb
	strh r1, [r0]
	mov r2, sp
	ldrh r2, [r2, #8]
	strh r2, [r5, #0x14]
	movs r0, #1
	b _08003D08
	.align 2, 0
_08003D00: .4byte FUN_08003f80
_08003D04:
	subs r0, r7, #1
_08003D06:
	movs r0, #0
_08003D08:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08003d18
FUN_08003d18: @ 0x08003D18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	str r1, [sp]
	ldr r0, _08003D38 @ =0x03000020
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08003D3C
	movs r0, #1
	rsbs r0, r0, #0
	b _08003F14
	.align 2, 0
_08003D38: .4byte 0x03000020
_08003D3C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003D60
	cmp r1, #0
	blt _08003D60
	ldr r0, _08003D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003D60
	ldr r0, _08003D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003D6C
_08003D60:
	movs r4, #0
	b _08003D7A
	.align 2, 0
_08003D64: .4byte 0x030046A8
_08003D68: .4byte 0x030046AC
_08003D6C:
	ldr r0, _08003D8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08003D7A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08003D90
	adds r0, #4
	b _08003D9C
	.align 2, 0
_08003D8C: .4byte 0x030046A4
_08003D90:
	ldr r0, _08003DC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003D9C:
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003DC2
	cmp r1, #0
	blt _08003DC2
	ldr r0, _08003DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003DC2
	ldr r0, _08003DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003DD4
_08003DC2:
	movs r0, #0
	b _08003DE2
	.align 2, 0
_08003DC8: .4byte 0x030046A4
_08003DCC: .4byte 0x030046A8
_08003DD0: .4byte 0x030046AC
_08003DD4:
	ldr r0, _08003DF8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08003DE2:
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, [sp]
	cmp r2, #1
	beq _08003E1C
	cmp r2, #1
	bgt _08003DFC
	cmp r2, #0
	beq _08003E08
	b _08003E3A
	.align 2, 0
_08003DF8: .4byte 0x030046A4
_08003DFC:
	ldr r0, [sp]
	cmp r0, #2
	beq _08003E22
	cmp r0, #3
	beq _08003E34
	b _08003E3A
_08003E08:
	ldr r0, _08003E18 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	b _08003E38
	.align 2, 0
_08003E18: .4byte 0x030046A4
_08003E1C:
	movs r2, #1
	str r2, [sp, #4]
	b _08003E3A
_08003E22:
	ldr r0, _08003E30 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	str r1, [sp, #4]
	b _08003E3A
	.align 2, 0
_08003E30: .4byte 0x030046A4
_08003E34:
	movs r0, #1
	rsbs r0, r0, #0
_08003E38:
	str r0, [sp, #4]
_08003E3A:
	ldr r1, [sp, #0x10]
	ldr r5, [r1, #0x70]
	movs r2, #0
	mov sb, r2
	ldrh r0, [r1, #0x18]
	cmp sb, r0
	bge _08003F12
	movs r3, #0xf
	adds r7, r5, #0
	adds r7, #0x25
	adds r6, r5, #0
	adds r6, #0xba
_08003E52:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08003EFC
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08003EFC
	movs r1, #0xbc
	adds r1, r1, r5
	mov r8, r1
	ldr r2, [sp, #8]
	ldr r0, [sp, #4]
	adds r4, r2, r0
	mov sl, r6
	ldrh r1, [r6]
	cmp r4, r1
	bne _08003EFC
	ldr r2, [sp, #0xc]
	ldrb r0, [r2]
	adds r1, r3, #0
	ands r1, r0
	adds r1, #1
	ldrb r2, [r6, #2]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x14]
	bl FUN_08234224
	ldr r3, [sp, #0x14]
	cmp r0, #0
	beq _08003E9A
	adds r0, #4
	b _08003EA6
_08003E9A:
	ldr r0, _08003EF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003EA6:
	ldrb r0, [r0]
	adds r1, r3, #0
	ands r1, r0
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08003EC8
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003F12
_08003EC8:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r5, #0
	ldr r2, [sp]
	bl FUN_08003b70
	adds r4, r0, #0
	cmp r4, #0
	ble _08003EF4
	ldrb r0, [r5]
	bl FUN_08003490
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003EEA
	movs r4, #1
	rsbs r4, r4, #0
_08003EEA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003EF4
	subs r0, #1
	strb r0, [r7]
_08003EF4:
	adds r0, r4, #0
	b _08003F14
	.align 2, 0
_08003EF8: .4byte 0x030046A4
_08003EFC:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r6, r6, r0
	adds r5, r5, r0
	movs r1, #1
	add sb, r1
	ldr r2, [sp, #0x10]
	ldrh r2, [r2, #0x18]
	cmp sb, r2
	blt _08003E52
_08003F12:
	movs r0, #0
_08003F14:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08003f24
FUN_08003f24: @ 0x08003F24
	push {lr}
	ldr r2, _08003F34 @ =0x085AA650
	adds r1, r1, r2
	ldrb r1, [r1]
	bl FUN_08003d18
	pop {r1}
	bx r1
	.align 2, 0
_08003F34: .4byte 0x085AA650

	thumb_func_start FUN_08003f38
FUN_08003f38: @ 0x08003F38
	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2]
	cmp r3, #1
	bne _08003F64
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	ldr r1, _08003F60 @ =FUN_080041c4
	movs r4, #0xcc
	lsls r4, r4, #1
	adds r0, r2, r4
	str r1, [r0]
	movs r0, #0
	strh r0, [r2, #2]
	strb r3, [r2, #0x11]
	movs r0, #3
	strh r0, [r2, #4]
	b _08003F7A
	.align 2, 0
_08003F60: .4byte FUN_080041c4
_08003F64:
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	movs r0, #0
	movs r1, #3
	strb r1, [r2, #0x19]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r2, r3
	str r0, [r1]
_08003F7A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08003f80
FUN_08003f80: @ 0x08003F80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0x2c
	adds r6, r5, #0
	adds r6, #0xbc
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08003FA2
	movs r0, #0
	strb r0, [r5, #0x11]
	ldrh r1, [r6, #2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #2]
_08003FA2:
	ldrh r0, [r5, #0xc]
	strh r0, [r2, #0x10]
	ldrh r0, [r5, #0xe]
	strh r0, [r2, #0x14]
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	strh r1, [r2, #0xa]
	ldrh r0, [r5, #4]
	cmp r0, #2
	bne _08003FC0
	ldr r3, _08004048 @ =0xFFFFFF00
	adds r0, r1, r3
	strh r0, [r2, #0xa]
_08003FC0:
	ldrh r0, [r2, #0xa]
	adds r1, r5, #0
	adds r1, #0xaa
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r4, r5, r0
	subs r1, #0x76
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldrb r0, [r5]
	cmp r0, #1
	beq _08003FF4
	ldrh r1, [r5, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08003FF4
	adds r0, r5, #0
	bl FUN_080039ec
_08003FF4:
	ldrh r0, [r5, #2]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r5, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x14]
	cmp r0, r2
	blo _080040DE
	ldrb r2, [r6]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xe
	bgt _08004016
	adds r1, #1
_08004016:
	movs r0, #0xf0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r0, #0xff
	strb r0, [r6, #1]
	ldrb r4, [r5]
	cmp r4, #1
	bne _08004094
	ldrh r2, [r5, #4]
	cmp r2, #2
	bne _08004050
	ldr r1, _0800404C @ =FUN_080040f0
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	strh r7, [r5, #2]
	strb r4, [r5, #0x11]
	strh r2, [r5, #4]
	strh r7, [r5, #0xc]
	strh r7, [r5, #0xe]
	mov r0, r8
	strb r0, [r5, #0x10]
	b _080040DE
	.align 2, 0
_08004048: .4byte 0xFFFFFF00
_0800404C: .4byte FUN_080040f0
_08004050:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	ldrb r2, [r5, #0x10]
	adds r0, r5, #0
	bl FUN_08003b70
	cmp r0, #0
	bne _080040DE
	adds r0, r5, #0
	bl FUN_080033ac
	ldr r1, _0800408C @ =FUN_08003f38
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	strb r4, [r5, #0x11]
	strh r7, [r5, #4]
	strh r7, [r5, #0xc]
	strh r7, [r5, #0xe]
	mov r3, r8
	strb r3, [r5, #0x10]
	ldrh r1, [r6, #2]
	ldr r0, _08004090 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r6, #2]
	b _080040DE
	.align 2, 0
_0800408C: .4byte FUN_08003f38
_08004090: .4byte 0x0000FFFE
_08004094:
	ldrh r2, [r5, #4]
	cmp r2, #2
	bne _080040B4
	ldr r0, _080040B0 @ =FUN_080040f0
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r5, r3
	str r0, [r1]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	strh r2, [r5, #4]
	b _080040D4
	.align 2, 0
_080040B0: .4byte FUN_080040f0
_080040B4:
	adds r0, r5, #0
	bl FUN_080033ac
	ldr r1, _080040E8 @ =FUN_08003f38
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	strh r7, [r5, #2]
	movs r0, #1
	strb r0, [r5, #0x11]
	strh r7, [r5, #4]
	ldrh r1, [r6, #2]
	ldr r0, _080040EC @ =0x0000FFFE
	ands r0, r1
	strh r0, [r6, #2]
_080040D4:
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0xc]
	strh r0, [r5, #0xe]
	strb r1, [r5, #0x10]
_080040DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080040E8: .4byte FUN_08003f38
_080040EC: .4byte 0x0000FFFE

	thumb_func_start FUN_080040f0
FUN_080040f0: @ 0x080040F0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800413E
	movs r0, #0
	strb r0, [r4, #0x11]
	ldrh r0, [r4, #0x12]
	lsrs r0, r0, #8
	adds r2, r0, #1
	cmp r2, #0xf
	ble _0800411E
	ldrb r0, [r3]
	movs r1, #0xf0
	ands r1, r0
	movs r0, #0xf
	orrs r1, r0
	strb r1, [r3]
	b _08004128
_0800411E:
	ldrb r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08004128:
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _0800413E
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
_0800413E:
	ldrh r0, [r4, #0x12]
	ldrh r1, [r5, #0xa]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800415C
	ldr r0, _08004158 @ =0x0000FFF0
	b _08004162
	.align 2, 0
_08004158: .4byte 0x0000FFF0
_0800415C:
	cmp r1, #0
	ble _08004164
	movs r0, #0
_08004162:
	strh r0, [r5, #0x12]
_08004164:
	movs r0, #0x12
	ldrsh r3, [r5, r0]
	cmp r3, #0
	bne _080041B4
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _08004186
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4, #0x16]
	b _08004198
_08004186:
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	ldr r0, _080041BC @ =0x0000FFDE
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080032a0
_08004198:
	ldr r1, _080041C0 @ =FUN_08003f38
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	movs r2, #0
	movs r1, #0
	strh r1, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r1, [r4, #0xc]
	strh r1, [r4, #0xe]
	strb r2, [r4, #0x10]
	strh r1, [r4, #4]
_080041B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080041BC: .4byte 0x0000FFDE
_080041C0: .4byte FUN_08003f38

	thumb_func_start FUN_080041c4
FUN_080041c4: @ 0x080041C4
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800422C
	movs r5, #0
	strb r5, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	strb r5, [r0]
	adds r0, #0x6c
	strh r5, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0800422C
	ldrh r0, [r4, #0x2c]
	str r0, [sp]
	ldrb r0, [r4]
	str r0, [sp, #4]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	str r0, [sp, #8]
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	ldr r1, _0800425C @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
	str r5, [r4, #0x28]
_0800422C:
	adds r2, r4, #0
	adds r2, #0x20
	ldrb r0, [r2]
	adds r5, r2, #0
	cmp r0, #0
	bne _08004280
	ldrh r0, [r4, #2]
	movs r1, #2
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bne _08004266
	adds r0, r4, #0
	adds r0, #0x9c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08004260
	adds r1, r4, #0
	adds r1, #0x8c
	movs r0, #1
	strh r0, [r1, #0x10]
	b _08004266
	.align 2, 0
_0800425C: .4byte 0xFFFF0000
_08004260:
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_08004266:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080042AE
_08004280:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080042A6
	movs r0, #2
	strb r0, [r4, #0x19]
	b _080042AE
_080042A6:
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_080042AE:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080042b8
FUN_080042b8: @ 0x080042B8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080042DA
	movs r0, #0
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #3
	strb r1, [r0]
	adds r0, #0x6c
	strh r1, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080042DA:
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r2, [r3]
	cmp r2, #0
	beq _08004306
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08004318
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
	b _08004318
_08004306:
	ldr r0, _08004320 @ =FUN_08003f38
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r4, r3
	str r0, [r1]
	strh r2, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r2, [r4, #4]
_08004318:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08004320: .4byte FUN_08003f38

	thumb_func_start FUN_08004324
FUN_08004324: @ 0x08004324
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r5, [r6, #0x70]
	movs r0, #0
	mov r8, r0
	ldrh r1, [r6, #0x18]
	cmp r8, r1
	blt _0800433E
	b _080044E8
_0800433E:
	adds r7, r5, #0
	adds r7, #0xce
	mov sb, r0
	adds r4, r5, #0
	adds r4, #0x18
_08004348:
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _08004350
	b _080044D2
_08004350:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _080043C0
	cmp r0, #3
	bne _0800436E
	ldr r1, _080043B8 @ =0x085AA658
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0800436E
	adds r0, r5, #0
	bl _call_via_r1
_0800436E:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _080043AA
	ldrh r0, [r4, #0x14]
	str r0, [sp, #4]
	ldrb r0, [r5]
	str r0, [sp, #8]
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	str r0, [sp, #0xc]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x14]
	ldr r1, _080043BC @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r0, [r4, #0x10]
	bl Script_ExecById
	mov r1, sb
	str r1, [r4, #0x10]
_080043AA:
	adds r0, r5, #0
	bl FUN_080035e4
	adds r0, r5, #0
	bl FUN_080036a0
	b _080044D2
	.align 2, 0
_080043B8: .4byte 0x085AA658
_080043BC: .4byte 0xFFFF0000
_080043C0:
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_0823b4b8
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _080043DA
	adds r0, r5, #0
	bl _call_via_r1
_080043DA:
	ldrb r1, [r5, #1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800440E
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08004404
	ldrh r0, [r4, #0x16]
	ldr r2, _08004400 @ =0x0000FFFD
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #0x16]
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_08234660
	b _08004418
	.align 2, 0
_08004400: .4byte 0x0000FFFD
_08004404:
	ldrh r0, [r4, #0x16]
	movs r1, #2
	orrs r0, r1
	strh r0, [r4, #0x16]
	b _08004418
_0800440E:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
_08004418:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08004422
	subs r0, #1
	strb r0, [r4, #9]
_08004422:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004446
	ldr r0, _0800443C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08004440
	movs r0, #1
	b _08004442
	.align 2, 0
_0800443C: .4byte 0x030046A0
_08004440:
	movs r0, #0
_08004442:
	cmp r0, #0
	beq _08004450
_08004446:
	ldr r0, [r4, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08004456
_08004450:
	ldr r0, [r4, #0x74]
	movs r1, #1
	orrs r0, r1
_08004456:
	str r0, [r4, #0x74]
	ldrb r1, [r4]
	cmp r1, #0
	bne _08004466
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _0800446C
_08004466:
	subs r0, r1, #1
	strb r0, [r4]
	b _080044B0
_0800446C:
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _08004492
	ldr r0, _08004488 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _0800448C
	movs r0, #1
	b _0800448E
	.align 2, 0
_08004488: .4byte 0x030046A0
_0800448C:
	movs r0, #0
_0800448E:
	cmp r0, #0
	beq _080044B0
_08004492:
	ldrh r0, [r7]
	ldr r2, _080044AC @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r7]
	adds r0, r5, #0
	adds r0, #0xc8
	adds r1, r5, #0
	adds r1, #0x34
	movs r2, #0
	bl FUN_082364c4
	b _080044B8
	.align 2, 0
_080044AC: .4byte 0x0000FFFB
_080044B0:
	ldrh r0, [r7]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7]
_080044B8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _080044D2
	subs r0, #1
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080044D2
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r4, #2]
	bl FUN_0822b20c
_080044D2:
	movs r0, #1
	add r8, r0
	movs r1, #0xce
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r4, r4, r1
	adds r5, r5, r1
	ldrh r2, [r6, #0x18]
	cmp r8, r2
	bge _080044E8
	b _08004348
_080044E8:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	beq _0800454E
	adds r0, r6, #0
	adds r0, #0x30
	ldr r1, [r6, #0x20]
	ldr r2, [r6, #0x28]
	movs r4, #0x1c
	ldrsh r3, [r6, r4]
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	adds r0, r6, #0
	adds r0, #0x50
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x2c]
	movs r5, #0x1c
	ldrsh r3, [r6, r5]
	str r4, [sp]
	bl rgb555_08237468
	ldrb r0, [r6, #0x1b]
	cmp r0, #0
	bne _08004532
	ldrh r0, [r6, #0x1c]
	adds r0, #1
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800454E
	movs r0, #0x20
	strh r0, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1b]
	b _0800454E
_08004532:
	ldrh r0, [r6, #0x1c]
	subs r0, #1
	movs r1, #0
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800454E
	movs r0, #0
	strh r0, [r6, #0x1c]
	strb r1, [r6, #0x1b]
	ldrb r0, [r6, #0x1f]
	cmp r0, #0
	beq _0800454E
	strb r1, [r6, #0x1f]
_0800454E:
	ldrb r1, [r6, #0x1a]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r6, #0x1a]
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004568
FUN_08004568: @ 0x08004568
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080036e0
	ldr r0, [r4, #0x70]
	bl Free
	ldr r1, _08004584 @ =0x03000020
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004584: .4byte 0x03000020

	thumb_func_start FUN_08004588
FUN_08004588: @ 0x08004588
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080045F8 @ =0x03000020
	str r5, [r0]
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	bne _0800459A
	movs r0, #8
	strh r0, [r5, #0x18]
_0800459A:
	ldrh r0, [r5, #0x18]
	movs r4, #0xce
	lsls r4, r4, #1
	muls r0, r4, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x70]
	cmp r2, #0
	beq _08004604
	ldrh r0, [r5, #0x18]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r2, #0
	bl ClearMemory
	movs r0, #0
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1b]
	strh r0, [r5, #0x1c]
	ldr r0, _080045FC @ =0x03003584
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x20]
	adds r0, #0x20
	str r0, [r5, #0x24]
	adds r0, #0x20
	str r0, [r5, #0x28]
	adds r1, #0xa0
	str r1, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x30
	ldr r4, _08004600 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x50
	adds r2, r4, #0
	bl CpuSet
	movs r0, #0
	b _08004608
	.align 2, 0
_080045F8: .4byte 0x03000020
_080045FC: .4byte 0x03003584
_08004600: .4byte 0x04000008
_08004604:
	movs r0, #1
	rsbs r0, r0, #0
_08004608:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004610
FUN_08004610: @ 0x08004610
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08004654 @ =0x03000020
	ldr r0, [r0]
	cmp r0, #0
	bne _08004662
	movs r0, #8
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004660
	ldr r1, _08004658 @ =FUN_08004324
	ldr r2, _0800465C @ =FUN_08004568
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #8
	bl Script_GetKeywordValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08004588
	cmp r0, #0
	bge _08004660
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004662
	.align 2, 0
_08004654: .4byte 0x03000020
_08004658: .4byte FUN_08004324
_0800465C: .4byte FUN_08004568
_08004660:
	adds r0, r4, #0
_08004662:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004668
FUN_08004668: @ 0x08004668
	push {r4, lr}
	ldr r1, [r0, #0x70]
	movs r2, #0
	ldrh r0, [r0, #0x18]
	cmp r2, r0
	bge _0800468C
	movs r4, #0xce
	lsls r4, r4, #1
	adds r3, r0, #0
_0800467A:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _08004684
	adds r0, r1, #0
	b _0800468E
_08004684:
	adds r1, r1, r4
	adds r2, #1
	cmp r2, r3
	blt _0800467A
_0800468C:
	movs r0, #0
_0800468E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004694
FUN_08004694: @ 0x08004694
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, [r0, #0x70]
	movs r3, #0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bge _080046C0
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r0, #0
_080046A8:
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _080046B8
	ldrh r0, [r2, #0x2c]
	cmp r0, r4
	bne _080046B8
	adds r0, r2, #0
	b _080046C2
_080046B8:
	adds r2, r2, r5
	adds r3, #1
	cmp r3, r1
	blt _080046A8
_080046C0:
	movs r0, #0
_080046C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080046c8
FUN_080046c8: @ 0x080046C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _080046F8 @ =0x03000020
	ldr r4, [r0]
	cmp r4, #0
	beq _080046F0
	adds r0, r4, #0
	bl FUN_08004668
	adds r7, r0, #0
	cmp r7, #0
	bne _080046FC
_080046F0:
	movs r0, #1
	rsbs r0, r0, #0
	b _080049F4
	.align 2, 0
_080046F8: .4byte 0x03000020
_080046FC:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r2, #0
	movs r1, #1
	strb r1, [r7, #0x1e]
	strb r5, [r7]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08004718
	strb r1, [r4, #0x1e]
_08004718:
	strb r6, [r7, #1]
	strh r2, [r7, #2]
	strh r2, [r7, #4]
	adds r6, r7, #0
	adds r6, #0x70
	adds r0, r6, #0
	ldr r1, [sp, #0x44]
	bl FUN_0822b16c
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [sp, #0x48]
	strh r0, [r4, #0x10]
	movs r0, #0xa8
	adds r0, r0, r7
	mov r8, r0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r0, sl
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r1, #0x10
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp, #0x20]
	str r5, [sp, #0x1c]
	cmp r0, #0
	beq _08004798
	subs r4, #0x58
	adds r0, r4, #0
	bl FUN_08241574
	str r0, [r7, #8]
	mov sl, r4
	b _080047A0
_08004798:
	str r0, [r7, #8]
	movs r3, #0x34
	adds r3, r3, r7
	mov sl, r3
_080047A0:
	movs r0, #0
	movs r3, #0
	strh r3, [r7, #0xc]
	strh r3, [r7, #0xe]
	strb r0, [r7, #0x10]
	movs r1, #4
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080047CC
	ldr r0, _080047C8 @ =0x080042B9
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	strh r3, [r7, #2]
	b _080047D8
	.align 2, 0
_080047C8: .4byte 0x080042B9
_080047CC:
	ldr r0, _08004808 @ =FUN_08003f38
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r7, r3
	str r0, [r1]
	strh r2, [r7, #2]
_080047D8:
	movs r0, #1
	strb r0, [r7, #0x11]
	ldrh r0, [r7, #0x34]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004802
	cmp r1, #0
	blt _08004802
	ldr r0, _0800480C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004802
	ldr r0, _08004810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004814
_08004802:
	movs r5, #0
	b _08004822
	.align 2, 0
_08004808: .4byte FUN_08003f38
_0800480C: .4byte 0x030046A8
_08004810: .4byte 0x030046AC
_08004814:
	ldr r0, _08004834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08004822:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08004838
	adds r0, #4
	b _08004844
	.align 2, 0
_08004834: .4byte 0x030046A4
_08004838:
	ldr r0, _08004964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08004844:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0xe
	bgt _08004850
	adds r4, #1
_08004850:
	adds r0, r7, #0
	adds r0, #0xb8
	movs r1, #0xff
	str r1, [sp]
	movs r2, #0
	mov sb, r2
	str r2, [sp, #4]
	adds r1, r5, #0
	adds r3, r4, #0
	bl FUN_08234270
	lsls r0, r4, #8
	movs r6, #0
	strh r0, [r7, #0x12]
	ldr r2, _08004968 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800496C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r8, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0xc8
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004970 @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08004974 @ =FUN_080034c8
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x80
	add r1, sp, #0xc
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004978 @ =0x00002801
	movs r0, #1
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800497C @ =FUN_080035e0
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldr r1, _08004980 @ =0x000005DC
	adds r0, r4, #0
	movs r2, #0x32
	bl FUN_082364f0
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x34]
	mov r0, sb
	str r0, [r4, #0x38]
	ldr r0, [sp, #0x4c]
	strh r0, [r7, #0x16]
	strb r6, [r7, #0x18]
	strb r6, [r7, #0x19]
	strb r6, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x20
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x23
	movs r0, #4
	strb r0, [r1]
	ldr r2, _08004984 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08004988 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800498C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _08004990
	strh r2, [r7, #0x1a]
	b _08004998
	.align 2, 0
_08004964: .4byte 0x030046A4
_08004968: .4byte 0xFFFF0000
_0800496C: .4byte 0x0000FFFF
_08004970: .4byte 0x00004041
_08004974: .4byte FUN_080034c8
_08004978: .4byte 0x00002801
_0800497C: .4byte FUN_080035e0
_08004980: .4byte 0x000005DC
_08004984: .4byte 0x030046B8
_08004988: .4byte 0x000003FF
_0800498C: .4byte 0x0203B400
_08004990:
	adds r0, r7, #0
	adds r0, #0x76
	ldrh r0, [r0]
	strh r0, [r7, #0x1a]
_08004998:
	ldrh r1, [r7, #0x1a]
	ldr r0, [sp, #0x20]
	bl FUN_0822b20c
	ldr r0, [sp, #0x54]
	strh r0, [r7, #0x1c]
	ldrh r1, [r7, #0x2c]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, sl
	str r1, [r0]
	ldr r0, [sp, #0x58]
	str r0, [r7, #0x28]
	ldrb r1, [r7, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080049D8
	ldr r0, [sp, #0x1c]
	bl FUN_08002a48
	cmp r0, #0
	bge _080049D8
	ldrb r1, [r7, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r7, #1]
_080049D8:
	ldrb r0, [r7]
	cmp r0, #5
	bne _080049E6
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #1
	b _080049EC
_080049E6:
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #0
_080049EC:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
_080049F4:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004a04
FUN_08004a04: @ 0x08004A04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x4d
	bl prepare_08231510
	cmp r0, #0
	beq _08004A48
	bl Script_GetValue
	cmp r0, #0
	beq _08004A48
	movs r0, #0x10
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_08004A48:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08004A90
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08004A88 @ =0xFFFF0000
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08004A8C @ =0x0000FFFF
	ldr r1, [sp, #0x18]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x18]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	b _08004A9A
	.align 2, 0
_08004A88: .4byte 0xFFFF0000
_08004A8C: .4byte 0x0000FFFF
_08004A90:
	ldr r1, _08004AA8 @ =0xFFFF0000
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	ands r0, r1
	str r0, [sp, #0x1c]
_08004A9A:
	cmp r7, #0
	beq _08004AEC
	cmp r7, #1
	bne _08004AB0
	ldr r1, _08004AAC @ =0x000084EE
	b _08004AEE
	.align 2, 0
_08004AA8: .4byte 0xFFFF0000
_08004AAC: .4byte 0x000084EE
_08004AB0:
	cmp r7, #2
	bne _08004ABC
	ldr r1, _08004AB8 @ =0x00009D40
	b _08004AEE
	.align 2, 0
_08004AB8: .4byte 0x00009D40
_08004ABC:
	cmp r7, #3
	bne _08004AC8
	ldr r1, _08004AC4 @ =0x00009D43
	b _08004AEE
	.align 2, 0
_08004AC4: .4byte 0x00009D43
_08004AC8:
	cmp r7, #4
	bne _08004AD4
	ldr r1, _08004AD0 @ =0x00002097
	b _08004AEE
	.align 2, 0
_08004AD0: .4byte 0x00002097
_08004AD4:
	cmp r7, #5
	bne _08004AE0
	ldr r1, _08004ADC @ =0x000005A2
	b _08004AEE
	.align 2, 0
_08004ADC: .4byte 0x000005A2
_08004AE0:
	cmp r7, #6
	bne _08004AEC
	ldr r1, _08004AE8 @ =0x0000B306
	b _08004AEE
	.align 2, 0
_08004AE8: .4byte 0x0000B306
_08004AEC:
	ldr r1, _08004B14 @ =0x00009D41
_08004AEE:
	movs r0, #0x61
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0x80
	bl Script_GetKeywordValue
	mov sl, r0
	cmp r7, #0
	bne _08004B1C
	ldr r5, _08004B18 @ =0x0000023D
	b _08004B6A
	.align 2, 0
_08004B14: .4byte 0x00009D41
_08004B18: .4byte 0x0000023D
_08004B1C:
	cmp r7, #1
	bne _08004B28
	ldr r5, _08004B24 @ =0x00000241
	b _08004B6A
	.align 2, 0
_08004B24: .4byte 0x00000241
_08004B28:
	cmp r7, #2
	beq _08004B38
	cmp r7, #3
	bne _08004B34
	movs r5, #0x4f
	b _08004B6A
_08004B34:
	cmp r7, #4
	bne _08004B40
_08004B38:
	ldr r5, _08004B3C @ =0x000001FD
	b _08004B6A
	.align 2, 0
_08004B3C: .4byte 0x000001FD
_08004B40:
	cmp r7, #5
	bne _08004B48
	movs r5, #0x8b
	b _08004B6A
_08004B48:
	cmp r7, #6
	bne _08004B5E
	mov r0, r8
	cmp r0, #0
	beq _08004B56
	cmp r0, #2
	bne _08004B5A
_08004B56:
	movs r5, #2
	b _08004B6A
_08004B5A:
	movs r5, #3
	b _08004B6A
_08004B5E:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl Script_GetKeywordValue
	adds r5, r0, #0
_08004B6A:
	movs r4, #0x99
	lsls r4, r4, #1
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	str r6, [sp]
	mov r1, r8
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	mov r2, sb
	add r3, sp, #0x18
	bl FUN_080046c8
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004ba4
FUN_08004ba4: @ 0x08004BA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08004BD8 @ =0x03000020
	ldr r7, [r0]
	cmp r7, #0
	beq _08004BD2
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08004BD2
	adds r0, r7, #0
	bl FUN_08004694
	adds r5, r0, #0
	cmp r5, #0
	beq _08004BD2
	ldrb r0, [r5]
	cmp r0, #6
	beq _08004BDC
_08004BD2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08004C68
	.align 2, 0
_08004BD8: .4byte 0x03000020
_08004BDC:
	adds r6, r5, #0
	adds r6, #0x8c
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x53
	movs r1, #1
	bl Script_GetKeywordValue
	mov r8, r0
	cmp r4, #0
	bne _08004C24
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C04
	cmp r0, #2
	bne _08004C14
_08004C04:
	movs r0, #2
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #2
	bl FUN_0822b20c
	b _08004C68
_08004C14:
	movs r0, #3
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #3
	bl FUN_0822b20c
	b _08004C68
_08004C24:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08004C30
	cmp r0, #2
	bne _08004C44
_08004C30:
	movs r0, #4
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #4
	bl FUN_0822b20c
	adds r1, r7, #0
	adds r1, #0x30
	b _08004C56
_08004C44:
	movs r0, #5
	strh r0, [r5, #0x1a]
	adds r0, r5, #0
	adds r0, #0x70
	movs r1, #5
	bl FUN_0822b20c
	adds r1, r7, #0
	adds r1, #0x50
_08004C56:
	str r1, [r5, #0x7c]
	movs r1, #1
	strb r1, [r7, #0x1f]
	mov r1, r8
	cmp r1, #0
	beq _08004C68
	ldr r0, _08004C74 @ =0x00000149
	bl PlaySound_082406e0
_08004C68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08004C74: .4byte 0x00000149

	thumb_func_start FUN_08004c78
FUN_08004c78: @ 0x08004C78
	ldr r1, _08004C80 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08004C80: .4byte 0x03000024

	thumb_func_start FUN_08004c84
FUN_08004c84: @ 0x08004C84
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	str r0, [r1, #0x1c]
	ldr r2, _08004CA4 @ =0x03000024
	ldr r0, [r2]
	ldr r0, [r0, #0x18]
	str r0, [r1, #0x20]
	cmp r0, #0
	beq _08004C9A
	str r1, [r0, #0x1c]
_08004C9A:
	ldr r0, [r2]
	str r1, [r0, #0x18]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CA4: .4byte 0x03000024

	thumb_func_start FUN_08004ca8
FUN_08004ca8: @ 0x08004CA8
	push {lr}
	ldr r2, [r0, #0x1c]
	ldr r1, [r0, #0x20]
	cmp r2, #0
	beq _08004CB6
	str r1, [r2, #0x20]
	b _08004CBC
_08004CB6:
	ldr r0, _08004CC8 @ =0x03000024
	ldr r0, [r0]
	str r1, [r0, #0x18]
_08004CBC:
	cmp r1, #0
	beq _08004CC2
	str r2, [r1, #0x1c]
_08004CC2:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08004CC8: .4byte 0x03000024

	thumb_func_start FUN_08004ccc
FUN_08004ccc: @ 0x08004CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _08004D04 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004CF0
	ldr r0, _08004D08 @ =0x00002153
	movs r1, #0
	bl FUN_08004fac
	cmp r0, #0
	beq _08004D98
_08004CF0:
	movs r0, #0x24
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _08004D0C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004D9A
	.align 2, 0
_08004D04: .4byte 0x03000024
_08004D08: .4byte 0x00002153
_08004D0C:
	adds r0, r5, #0
	movs r1, #0x24
	bl ClearMemory
	strh r6, [r5]
	movs r0, #1
	strb r0, [r5, #2]
	strb r7, [r5, #3]
	mov r0, r8
	strb r0, [r5, #4]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004D44
	cmp r1, #0
	blt _08004D44
	ldr r0, _08004D48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004D44
	ldr r0, _08004D4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004D50
_08004D44:
	movs r0, #0
	b _08004D5E
	.align 2, 0
_08004D48: .4byte 0x030046A8
_08004D4C: .4byte 0x030046AC
_08004D50:
	ldr r0, _08004D6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08004D5E:
	strh r0, [r5, #8]
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08004D70
	asrs r0, r0, #8
	b _08004D76
	.align 2, 0
_08004D6C: .4byte 0x030046A4
_08004D70:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08004D76:
	strb r0, [r5, #5]
	ldr r0, [sp, #0x20]
	strh r0, [r5, #6]
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234270
	adds r0, r5, #0
	bl FUN_08004c84
_08004D98:
	movs r0, #0
_08004D9A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004da8
FUN_08004da8: @ 0x08004DA8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08004DBE
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #2]
_08004DBE:
	ldr r0, _08004DDC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	beq _08004DCC
	adds r0, r4, #0
	bl FUN_08004ca8
_08004DCC:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08004DDC: .4byte 0x03000024

	thumb_func_start FUN_08004de0
FUN_08004de0: @ 0x08004DE0
	push {r4, lr}
	ldr r0, _08004DF0 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004DF4
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E08
	.align 2, 0
_08004DF0: .4byte 0x03000024
_08004DF4:
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _08004E06
_08004DFA:
	ldr r4, [r0, #0x20]
	bl FUN_08004da8
	adds r0, r4, #0
	cmp r0, #0
	bne _08004DFA
_08004E06:
	movs r0, #0
_08004E08:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e10
FUN_08004e10: @ 0x08004E10
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E24 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E28
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E44
	.align 2, 0
_08004E24: .4byte 0x03000024
_08004E28:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E42
_08004E2E:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E3C
	adds r0, r1, #0
	bl FUN_08004da8
_08004E3C:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E2E
_08004E42:
	movs r0, #0
_08004E44:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e4c
FUN_08004e4c: @ 0x08004E4C
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E60 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E64
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E8C
	.align 2, 0
_08004E60: .4byte 0x03000024
_08004E64:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E8A
_08004E6A:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E84
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _08004E84
	movs r0, #0
	strb r0, [r1, #2]
	adds r0, r1, #0
	adds r0, #0xc
	bl FUN_082342a8
_08004E84:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E6A
_08004E8A:
	movs r0, #0
_08004E8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004e94
FUN_08004e94: @ 0x08004E94
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08004EAC @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004EB0
	movs r0, #1
	rsbs r0, r0, #0
	b _08004EE6
	.align 2, 0
_08004EAC: .4byte 0x03000024
_08004EB0:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004EE4
_08004EB6:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	cmp r0, r7
	bne _08004EDE
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _08004EDE
	movs r0, #1
	strb r0, [r5, #2]
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234270
_08004EDE:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004EB6
_08004EE4:
	movs r0, #0
_08004EE6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08004ef0
FUN_08004ef0: @ 0x08004EF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	mov sb, r1
	mov r8, r2
	adds r7, r3, #0
	ldr r0, [sp, #0x30]
	mov sl, r0
	ldr r0, _08004F18 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004F1C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004F74
	.align 2, 0
_08004F18: .4byte 0x03000024
_08004F1C:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004F72
_08004F22:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	ldr r1, [sp, #8]
	cmp r0, r1
	bne _08004F6C
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq _08004F38
	mov r2, r8
	strb r2, [r5, #3]
_08004F38:
	cmp sb, r0
	beq _08004F40
	mov r1, sb
	strb r1, [r5, #4]
_08004F40:
	ldr r2, [sp, #0x2c]
	cmp r2, r0
	beq _08004F48
	strh r2, [r5, #8]
_08004F48:
	cmp sl, r0
	beq _08004F50
	mov r2, sl
	strb r2, [r5, #5]
_08004F50:
	cmp r7, r0
	beq _08004F56
	strh r7, [r5, #6]
_08004F56:
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234208
_08004F6C:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004F22
_08004F72:
	movs r0, #0
_08004F74:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004f84
FUN_08004f84: @ 0x08004F84
	movs r0, #0
	bx lr

	thumb_func_start FUN_08004f88
FUN_08004f88: @ 0x08004F88
	push {lr}
	bl FUN_08004de0
	ldr r1, _08004F98 @ =0x03000024
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08004F98: .4byte 0x03000024

	thumb_func_start FUN_08004f9c
FUN_08004f9c: @ 0x08004F9C
	ldr r1, _08004FA8 @ =0x03000024
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r0, #0
	bx lr
	.align 2, 0
_08004FA8: .4byte 0x03000024

	thumb_func_start FUN_08004fac
FUN_08004fac: @ 0x08004FAC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08004FE4
	ldr r1, _08004FDC @ =FUN_08004f84
	ldr r2, _08004FE0 @ =FUN_08004f88
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08004f9c
	cmp r0, #0
	bge _08004FE4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08004FE6
	.align 2, 0
_08004FDC: .4byte FUN_08004f84
_08004FE0: .4byte FUN_08004f88
_08004FE4:
	adds r0, r4, #0
_08004FE6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08004fec
FUN_08004fec: @ 0x08004FEC
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005004
FUN_08005004: @ 0x08005004
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e4c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800501c
FUN_0800501c: @ 0x0800501C
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_08004e94
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005034
FUN_08005034: @ 0x08005034
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6e
	adds r1, r4, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800510A
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080050D0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080050D4 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #8
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080050CC
	cmp r1, #0
	blt _080050CC
	ldr r0, _080050D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080050CC
	ldr r0, _080050DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080050E0
_080050CC:
	movs r2, #0
	b _080050EE
	.align 2, 0
_080050D0: .4byte 0xFFFF0000
_080050D4: .4byte 0x0000FFFF
_080050D8: .4byte 0x030046A8
_080050DC: .4byte 0x030046AC
_080050E0:
	ldr r0, _080050FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r3
_080050EE:
	add r0, sp, #8
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08005100
	asrs r0, r0, #8
	b _08005106
	.align 2, 0
_080050FC: .4byte 0x030046A4
_08005100:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08005106:
	adds r1, r0, #0
	b _0800510E
_0800510A:
	adds r1, r4, #0
	adds r2, r1, #0
_0800510E:
	str r2, [sp]
	str r1, [sp, #4]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_08004ef0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800512c
FUN_0800512c: @ 0x0800512C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080051A4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800519C @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080051A0 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _080051AE
	.align 2, 0
_0800519C: .4byte 0xFFFF0000
_080051A0: .4byte 0x0000FFFF
_080051A4:
	ldr r1, _080051CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_080051AE:
	str r5, [sp]
	mov r0, r8
	add r1, sp, #4
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08004ccc
	movs r0, #0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080051CC: .4byte 0xFFFF0000

	thumb_func_start FUN_080051d0
FUN_080051d0: @ 0x080051D0
	ldr r1, _080051D8 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080051D8: .4byte 0x03000028

	thumb_func_start FUN_080051dc
FUN_080051dc: @ 0x080051DC
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r2, r0, #0
	adds r3, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005228
	str r3, [sp]
	movs r1, #0
	add r5, sp, #0x14
	ldr r4, [r2, #0x54]
	adds r3, r2, #0
	adds r3, #0x44
	add r2, sp, #4
_080051FA:
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r1, #1
	cmp r1, #3
	ble _080051FA
	ldr r0, _08005224 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r5, #4]
	cmp r4, #0
	beq _08005230
	adds r0, r4, #0
	adds r1, r5, #0
	bl Script_ExecById
	b _08005230
	.align 2, 0
_08005224: .4byte 0xFFFF0000
_08005228:
	ldr r1, [r2, #0x58]
	adds r0, r3, #0
	bl _call_via_r1
_08005230:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08005238
FUN_08005238: @ 0x08005238
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	blt _08005278
	ldrb r0, [r4, #0x1b]
	cmp r5, r0
	blt _0800524A
	subs r5, r0, #1
_0800524A:
	lsls r0, r5, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ldr r2, _08005274 @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	movs r2, #0x92
	lsls r2, r2, #1
	b _080052A4
	.align 2, 0
_08005274: .4byte 0xFFFFFDFF
_08005278:
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	lsls r0, r0, #2
	adds r0, #0x64
	adds r3, r4, r0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	subs r0, #7
	subs r2, #0xdc
_080052A4:
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldrb r1, [r3]
	adds r1, #1
	ldrb r0, [r3, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #0x5e
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r3, #1]
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r4, r0]
	cmp r5, r0
	beq _080052D6
	movs r0, #0xdc
	bl PlaySound_082406e0
_080052D6:
	strb r5, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080052e0
FUN_080052e0: @ 0x080052E0
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r3, r5, #0
	movs r1, #0
	adds r0, #0x34
	ldrb r2, [r0]
	cmp r1, r2
	bge _08005322
	mov r2, ip
	adds r2, #0x2c
_080052F8:
	adds r3, r3, r4
	ldrb r0, [r0]
	cmp r3, r0
	ble _08005304
	adds r3, r0, #0
	b _0800530A
_08005304:
	cmp r3, #0
	bge _0800530A
	movs r3, #0
_0800530A:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005316
	adds r0, r3, #0
	b _08005324
_08005316:
	adds r1, #1
	mov r0, ip
	adds r0, #0x34
	ldrb r6, [r0]
	cmp r1, r6
	blt _080052F8
_08005322:
	adds r0, r5, #0
_08005324:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800532c
FUN_0800532c: @ 0x0800532C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0x18
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _08005394
	ldr r0, _0800538C @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	bne _08005378
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800539E
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _08005378
	b _08005522
_08005378:
	movs r1, #0x19
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_08005238
	ldr r0, _08005390 @ =0x00000107
	bl PlaySound_082406e0
	b _08005522
	.align 2, 0
_0800538C: .4byte 0x030044E0
_08005390: .4byte 0x00000107
_08005394:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _080053A4
_0800539E:
	subs r0, #1
	strb r0, [r1]
	b _08005522
_080053A4:
	ldr r0, _080053C4 @ =0x030044E0
	ldrh r0, [r0]
	ldr r1, [r5, #0x40]
	ands r1, r0
	cmp r1, #0
	beq _080053C8
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	beq _080053D0
	subs r0, r1, #1
	mov r1, r8
	strb r0, [r1]
	b _080053D0
	.align 2, 0
_080053C4: .4byte 0x030044E0
_080053C8:
	adds r0, r5, #0
	adds r0, #0x3e
	strb r1, [r0]
	mov r8, r0
_080053D0:
	ldr r0, _08005408 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080054C8
	movs r2, #0x18
	ldrsb r2, [r5, r2]
	lsls r0, r2, #2
	adds r0, #0x64
	adds r7, r5, r0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800540C
	subs r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x1c
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r1, r0
	bge _08005468
	b _08005466
	.align 2, 0
_08005408: .4byte 0x030044E0
_0800540C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08005420
	adds r1, r2, #1
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r7, [r7, #3]
	adds r0, r0, r7
	b _080054B4
_08005420:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08005476
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _0800544C
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _08005452
_0800544C:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_08005452:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _08005466
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _08005468
_08005466:
	adds r1, r0, #0
_08005468:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r1, r8
	strb r0, [r1]
	b _080054C8
_08005476:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080054C8
	ldrb r1, [r7, #3]
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r6, r2, r0
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080052e0
	adds r2, r0, #0
	ldrb r0, [r7, #3]
	cmp r0, r2
	bne _080054A0
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	b _080054A6
_080054A0:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r1, r0, r6
_080054A6:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	blt _080054BA
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r2
_080054B4:
	ldrb r0, [r0]
	cmp r1, r0
	ble _080054BC
_080054BA:
	adds r1, r0, #0
_080054BC:
	adds r0, r5, #0
	bl FUN_08005238
	movs r0, #0x1e
	mov r2, r8
	strb r0, [r2]
_080054C8:
	ldr r0, _080054FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08005500
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08005522
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
	b _08005522
	.align 2, 0
_080054FC: .4byte 0x030044E0
_08005500:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08005522
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08047864
	movs r1, #0x18
	ldrsb r1, [r5, r1]
	adds r0, r5, #0
	bl FUN_080051dc
	adds r0, r5, #0
	bl KillEntity
_08005522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800552c
FUN_0800552c: @ 0x0800552C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _0800556C
	bl FUN_08048914
	cmp r0, #0
	beq _0800556C
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	bne _0800554C
	adds r0, r5, #0
	bl FUN_0800532c
	b _08005550
_0800554C:
	subs r0, #1
	strb r0, [r5, #0x1a]
_08005550:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xe4
	adds r1, r4, #0
	bl FUN_082372cc
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
_0800556C:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08005574
FUN_08005574: @ 0x08005574
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08005598 @ =0x03000028
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005598: .4byte 0x03000028

	thumb_func_start FUN_0800559c
FUN_0800559c: @ 0x0800559C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r2, [r2]
	adds r3, r4, #0
	adds r3, #0x39
	ldrb r3, [r3]
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r4, #0x5c]
	bl FUN_080478f0
	ldr r0, [r4, #0x60]
	bl FUN_08047a28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080055d4
FUN_080055d4: @ 0x080055D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _080055EE
	b _080057E2
_080055EE:
	ldr r1, _08005638 @ =0x08251B3C
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080056D0
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3f
	adds r1, r1, r6
	mov sb, r1
	adds r1, r6, #0
	adds r1, #0x36
	str r1, [sp]
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r1, r6, #0
	adds r1, #0x37
	str r1, [sp, #4]
	movs r1, #0x34
	adds r1, r1, r6
	mov sl, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, r4, #1
	b _08005662
	.align 2, 0
_08005638: .4byte 0x08251B3C
_0800563C:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005648
	movs r4, #1
	mov ip, r4
	b _08005654
_08005648:
	mov r0, ip
	cmp r0, #0
	beq _08005654
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005654:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _08005662
	cmp r0, #0
	bne _0800563C
	adds r5, #1
_08005662:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005680
	cmp r3, #0
	beq _08005680
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	mov r2, sb
	strb r0, [r2]
	b _08005686
_08005680:
	movs r0, #0
	mov r3, sb
	strb r0, [r3]
_08005686:
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	mov r4, r8
	ldrb r1, [r4]
	ldr r2, [sp]
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, #0x64
	movs r3, #0
	strb r1, [r0]
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r6, r1
	ldr r4, [sp, #4]
	ldrb r2, [r4]
	lsls r2, r2, #3
	mov r4, sl
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r1, #0x65
	strb r2, [r1]
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	ldrb r1, [r4]
	adds r0, #0x67
	strb r1, [r0]
	strb r3, [r7]
	b _08005854
_080056D0:
	ldr r1, _08005700 @ =0x08251B44
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _0800574C
	movs r0, #0
	mov ip, r0
	movs r3, #0
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, r4, #1
	b _0800572A
	.align 2, 0
_08005700: .4byte 0x08251B44
_08005704:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _08005710
	movs r4, #1
	mov ip, r4
	b _0800571C
_08005710:
	mov r0, ip
	cmp r0, #0
	beq _0800571C
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_0800571C:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _0800572A
	cmp r0, #0
	bne _08005704
	adds r5, #1
_0800572A:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _08005744
	cmp r3, #0
	beq _08005744
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _08005746
_08005744:
	movs r0, #0
_08005746:
	bl FUN_080488bc
	b _080057C6
_0800574C:
	ldr r1, _0800577C @ =0x08251B4C
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	movs r3, #0
	mov ip, r3
	ldrb r0, [r4]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0x3b
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x3a
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, r4, #1
	b _080057A6
	.align 2, 0
_0800577C: .4byte 0x08251B4C
_08005780:
	ldrb r1, [r5]
	cmp r1, #0x3d
	bne _0800578C
	movs r4, #1
	mov ip, r4
	b _08005798
_0800578C:
	mov r0, ip
	cmp r0, #0
	beq _08005798
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_08005798:
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0x3e
	beq _080057A6
	cmp r0, #0
	bne _08005780
	adds r5, #1
_080057A6:
	adds r1, r2, r3
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	cmp r1, #0
	beq _080057C0
	cmp r3, #0
	beq _080057C0
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08048c2c
	b _080057C2
_080057C0:
	movs r0, #0
_080057C2:
	bl FUN_0804889c
_080057C6:
	adds r1, r0, #0
	ldrb r0, [r7]
	adds r0, r0, r1
	strb r0, [r7]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	b _08005854
_080057E2:
	ldr r1, _08005814 @ =0x08251B50
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08005848
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	cmp r1, #0
	beq _08005818
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r6, #0
	adds r7, #0x3a
	b _0800582A
	.align 2, 0
_08005814: .4byte 0x08251B50
_08005818:
	ldrb r0, [r6, #0x1b]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r2, r6, #0
	adds r2, #0x3a
	ldrb r1, [r2]
	adds r0, #0x66
	strb r1, [r0]
	adds r7, r2, #0
_0800582A:
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	movs r1, #0
	strb r0, [r6, #0x1b]
	strb r1, [r7]
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r6, #0
	adds r1, #0x2c
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08005854
_08005848:
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r4, r0, #0
	b _08005858
_08005854:
	adds r4, r5, #1
	adds r0, r4, #0
_08005858:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08005868
FUN_08005868: @ 0x08005868
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r4, #0x1b]
	adds r1, r4, #0
	adds r1, #0x3a
	strb r0, [r1]
	movs r3, #0
	adds r7, r4, #0
	adds r7, #0x1c
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	adds r0, r7, #0
	movs r1, #7
_0800589A:
	strb r3, [r0]
	strb r3, [r0, #8]
	strb r3, [r0, #0x10]
	adds r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0800589A
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r1, r1, #0x18
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0x39
	cmp r1, #0
	blt _08005984
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _080059B2
	cmp r1, #0x3c
	bne _080058DC
	b _080059AA
_080058CA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080055d4
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080059B2
	b _08005998
_080058DC:
	ldrb r0, [r2]
	cmp r0, #0xa
	bne _08005922
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _08005904
	subs r0, #1
	b _08005906
_08005904:
	movs r0, #0
_08005906:
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	bhs _08005980
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r1, [r4, #0x1b]
	strb r1, [r0]
	b _08005980
_08005922:
	cmp r0, #0x1f
	bne _0800596E
	adds r0, r2, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0800594C @ =0x0000FFFF
	cmp r1, r0
	bne _08005950
_08005936:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	b _080059B2
	.align 2, 0
_0800594C: .4byte 0x0000FFFF
_08005950:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08005936
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080059B2
_0800596E:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08005980:
	adds r2, #1
	b _08005998
_08005984:
	adds r1, r4, #0
	adds r1, #0x3a
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r1, #1
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	adds r2, #2
_08005998:
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08005984
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080059B2
	cmp r0, #0x3c
	bne _080058DC
_080059AA:
	adds r2, #1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080058CA
_080059B2:
	ldrb r0, [r5]
	ldrb r6, [r6]
	cmp r0, r6
	bhs _080059CC
	mov r3, r8
	adds r2, r3, r0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080059C8
	subs r1, r0, #1
	b _080059CA
_080059C8:
	movs r1, #0
_080059CA:
	strb r1, [r2]
_080059CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080059d8
FUN_080059d8: @ 0x080059D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r5, r3, #0
	ldr r0, _08005A04 @ =0x03000028
	str r7, [r0]
	ldr r0, _08005A08 @ =0x0000CB05
	ldr r1, _08005A0C @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08005A10
	movs r0, #1
	rsbs r0, r0, #0
	b _08005B34
	.align 2, 0
_08005A04: .4byte 0x03000028
_08005A08: .4byte 0x0000CB05
_08005A0C: .4byte 0x0000B343
_08005A10:
	adds r0, r7, #0
	adds r0, #0xe4
	str r0, [sp, #0x18]
	adds r1, r0, #0
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	bl FUN_0822f284
	mov r6, r8
	str r6, [r7, #0x5c]
	mov r0, sb
	str r0, [r7, #0x60]
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x18]
	mov sb, r1
	cmp r0, #0
	beq _08005A48
	movs r0, #0xff
	strb r0, [r7, #0x18]
	ldr r0, [r5]
	b _08005A4C
_08005A48:
	ldr r0, [r5]
	strb r0, [r7, #0x18]
_08005A4C:
	cmp r0, #0
	bge _08005A52
	movs r0, #0
_08005A52:
	strb r0, [r7, #0x19]
	ldr r1, [r5, #8]
	adds r0, r7, #0
	adds r0, #0x3c
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x3d
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x3e
	movs r3, #0
	strb r3, [r0]
	ldr r0, _08005B44 @ =0x030044E0
	ldrh r0, [r0]
	str r0, [r7, #0x40]
	ldr r0, [r5, #0xc]
	subs r1, #7
	strb r0, [r1]
	ldr r0, [r5, #0x10]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r5, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	strb r1, [r0]
	ldr r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x39
	strb r0, [r1]
	movs r0, #2
	strb r0, [r7, #0x1a]
	ldr r2, _08005B48 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #1
	orrs r0, r1
	ldr r1, _08005B4C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r4, #0x82
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	mov r0, r8
	mov r1, sb
	movs r2, #0x8b
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r6, r7, r1
	movs r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0x8f
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	movs r1, #0
	str r1, [sp]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #7
	movs r3, #1
	bl FUN_082370cc
	ldr r1, [r7, #0x5c]
	cmp r1, #0
	beq _08005B24
	adds r0, r7, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r7, r1]
	adds r0, r7, #0
	bl FUN_08005238
	adds r0, r7, #0
	bl FUN_0800559c
_08005B24:
	bl FUN_080488fc
	cmp r0, #0
	bne _08005B32
	ldr r0, _08005B50 @ =0x00000107
	bl PlaySound_082406e0
_08005B32:
	movs r0, #0
_08005B34:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005B44: .4byte 0x030044E0
_08005B48: .4byte 0xFFFF0000
_08005B4C: .4byte 0x0000FFFF
_08005B50: .4byte 0x00000107

	thumb_func_start FUN_08005b54
FUN_08005b54: @ 0x08005B54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08005B70 @ =0x03000028
	ldr r5, [r0]
	cmp r5, #0
	beq _08005B74
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005B70: .4byte 0x03000028
_08005B74:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005BB8
	ldr r1, _08005BB0 @ =FUN_0800552c
	ldr r2, _08005BB4 @ =FUN_08005574
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r0, #0x35
	strb r5, [r0]
	str r6, [r4, #0x58]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080059d8
	cmp r0, #0
	bge _08005BB8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005BBA
	.align 2, 0
_08005BB0: .4byte FUN_0800552c
_08005BB4: .4byte FUN_08005574
_08005BB8:
	adds r0, r4, #0
_08005BBA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005bc8
FUN_08005bc8: @ 0x08005BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	ldr r0, _08005BDC @ =0x03000028
	ldr r0, [r0]
	cmp r0, #0
	beq _08005BE0
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005BDC: .4byte 0x03000028
_08005BE0:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08005BF2
	bl FUN_0823d340
	adds r6, r0, #0
	b _08005BF4
_08005BF2:
	movs r6, #0
_08005BF4:
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08005C12
	bl Script_GetValue
	mov r8, r0
_08005C12:
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #4]
	movs r0, #0x77
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp]
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #8]
	movs r0, #0x61
	bl prepare_08231510
	adds r5, r0, #0
	cmp r5, #0
	beq _08005C54
	bl Script_GetValue
	str r0, [sp, #0xc]
	bl Script_GetValue
	str r0, [sp, #0x10]
	bl Script_GetValue
	str r0, [sp, #0x14]
	bl Script_GetValue
	b _08005C7A
_08005C54:
	add r4, sp, #0x2c
	adds r0, r4, #0
	bl FUN_08048870
	cmp r0, #0
	bne _08005C70
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	str r0, [sp, #0x10]
	ldr r0, [r4, #8]
	str r0, [sp, #0x14]
	ldr r0, [r4, #0xc]
	b _08005C7A
_08005C70:
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r0, #0x18
	str r0, [sp, #0x14]
	movs r0, #3
_08005C7A:
	str r0, [sp, #0x18]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _08005CA4
	add r5, sp, #0x1c
	adds r4, r5, #0
_08005C8A:
	bl VM_GetPC
	cmp r0, #0
	beq _08005C96
	bl Script_GetValue
_08005C96:
	str r0, [r4]
	adds r4, #4
	adds r0, r5, #0
	adds r0, #0xc
	cmp r4, r0
	ble _08005C8A
	b _08005CB4
_08005CA4:
	add r5, sp, #0x1c
	adds r1, r5, #0
	movs r2, #0
	add r0, sp, #0x28
_08005CAC:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08005CAC
_08005CB4:
	movs r1, #0xe2
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08005D0C
	ldr r1, _08005D04 @ =FUN_0800552c
	ldr r2, _08005D08 @ =FUN_08005574
	bl SetEntityRoutine
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	str r0, [r4, #0x54]
	adds r3, r5, #0
	adds r2, r4, #0
	adds r2, #0x44
	movs r1, #3
_08005CE0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005CE0
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, sp
	bl FUN_080059d8
	cmp r0, #0
	bge _08005D0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08005D0E
	.align 2, 0
_08005D04: .4byte FUN_0800552c
_08005D08: .4byte FUN_08005574
_08005D0C:
	adds r0, r4, #0
_08005D0E:
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005d1c
FUN_08005d1c: @ 0x08005D1C
	push {r4, lr}
	ldr r0, _08005D74 @ =0x03000028
	ldr r4, [r0]
	cmp r4, #0
	beq _08005D6C
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08005D6C
	bl FUN_0823d340
	str r0, [r4, #0x5c]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x60]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08005D50
	bl Script_GetValue
	strb r0, [r4, #0x18]
_08005D50:
	ldr r1, [r4, #0x5c]
	cmp r1, #0
	beq _08005D6C
	adds r0, r4, #0
	bl FUN_08005868
	movs r1, #0x18
	ldrsb r1, [r4, r1]
	adds r0, r4, #0
	bl FUN_08005238
	adds r0, r4, #0
	bl FUN_0800559c
_08005D6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08005D74: .4byte 0x03000028

	thumb_func_start FUN_08005d78
FUN_08005d78: @ 0x08005D78
	ldr r1, _08005D80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08005D80: .4byte 0x0300002C

	thumb_func_start FUN_08005d84
FUN_08005d84: @ 0x08005D84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r4, r0, #0
	adds r7, r2, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r6, #0
	beq _08005DB4
	movs r1, #4
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08005DB4
	adds r2, r1, #0
	movs r3, #0xc
	ldr r1, _08005DBC @ =0x03002BC0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	adds r5, r2, #0
	cmp r0, #0
	beq _08005DC0
_08005DB4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08005E24
	.align 2, 0
_08005DBC: .4byte 0x03002BC0
_08005DC0:
	ldrb r0, [r4, #5]
	cmp r0, #1
	bne _08005DD6
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
	adds r0, #0x40
	b _08005DE2
_08005DD6:
	ldr r1, [r4, #0x2c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp]
	movs r2, #2
	ldrsh r0, [r1, r2]
_08005DE2:
	str r0, [sp, #4]
	movs r2, #4
	ldrsh r0, [r1, r2]
	str r0, [sp, #8]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #0x10]
	add r2, sp, #0x28
	adds r4, #0x38
	add r3, sp, #0x14
	movs r1, #2
_08005DFE:
	ldm r4!, {r0}
	stm r3!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08005DFE
	str r5, [sp, #0x20]
	str r7, [sp, #0x24]
	ldr r1, _08005E2C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	bl Script_ExecById
_08005E24:
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08005E2C: .4byte 0xFFFF0000

	thumb_func_start FUN_08005e30
FUN_08005e30: @ 0x08005E30
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r1, #4
	ldr r3, _08005E58 @ =0x0300002C
	ldr r0, [r3]
	ldr r0, [r0, #0x28]
	str r0, [r1]
	cmp r0, #0
	beq _08005E4E
	adds r0, #0xb4
	str r2, [r0]
_08005E4E:
	ldr r0, [r3]
	str r2, [r0, #0x28]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E58: .4byte 0x0300002C

	thumb_func_start FUN_08005e5c
FUN_08005e5c: @ 0x08005E5C
	push {lr}
	adds r1, r0, #0
	adds r1, #0xb4
	ldr r1, [r1]
	adds r0, #0xb8
	ldr r2, [r0]
	cmp r1, #0
	beq _08005E74
	adds r0, r1, #0
	adds r0, #0xb8
	str r2, [r0]
	b _08005E7A
_08005E74:
	ldr r0, _08005E8C @ =0x0300002C
	ldr r0, [r0]
	str r2, [r0, #0x28]
_08005E7A:
	cmp r2, #0
	beq _08005E84
	adds r0, r2, #0
	adds r0, #0xb4
	str r1, [r0]
_08005E84:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08005E8C: .4byte 0x0300002C

	thumb_func_start FUN_08005e90
FUN_08005e90: @ 0x08005E90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08005e5c
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08013c70
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _08005EAA
	bl Free
_08005EAA:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _08005EB4
	bl Free
_08005EB4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _08005EC4
	bl FUN_0822dabc
	ldr r0, [r4, #0x1c]
	bl Free
_08005EC4:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _08005ED4
	bl FUN_0822a4e0
	ldr r0, [r4, #0x20]
	bl Free
_08005ED4:
	adds r0, r4, #0
	bl Free
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08005ee4
FUN_08005ee4: @ 0x08005EE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	beq _08005F42
	subs r0, #1
	strb r0, [r7, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08005F06
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x10]
	strh r0, [r1]
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	b _08005F42
_08005F06:
	ldr r6, _08005F48 @ =0x0203B400
	ldr r3, _08005F4C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _08005F50 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r4, [r7, #0x2c]
	movs r2, #0xf
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	subs r0, #4
	strh r0, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ldr r2, [r7, #0x2c]
	movs r1, #7
	ands r0, r1
	ldrh r7, [r7, #0x12]
	adds r0, r0, r7
	subs r0, #4
	strh r0, [r2, #4]
_08005F42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005F48: .4byte 0x0203B400
_08005F4C: .4byte 0x030046B8
_08005F50: .4byte 0x000003FF

	thumb_func_start FUN_08005f54
FUN_08005f54: @ 0x08005F54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov sl, r0
	adds r5, r1, #0
	add r7, sp, #0x10
	ldr r3, [r5, #0x2c]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x11
	ldrh r1, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x11
	subs r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F84
	asrs r1, r1, #8
	b _08005F8A
_08005F84:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005F8A:
	strh r1, [r7]
	adds r2, r6, r4
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	cmp r1, #0
	blt _08005F9C
	asrs r1, r1, #8
	b _08005FA2
_08005F9C:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r1, r1, #0
_08005FA2:
	adds r4, r1, #0
	movs r1, #2
	ldrsh r2, [r3, r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	cmp r1, #0
	blt _08005FB6
	asrs r2, r1, #8
	b _08005FBC
_08005FB6:
	rsbs r1, r1, #0
	asrs r1, r1, #8
	rsbs r2, r1, #0
_08005FBC:
	subs r1, r4, r2
	strh r1, [r7, #2]
	adds r1, r4, r2
	strh r1, [r7, #4]
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	beq _08005FE2
	subs r1, #1
	strb r1, [r5, #0xd]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08005FE2
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
_08005FE2:
	movs r2, #1
	str r2, [sp, #0x20]
	movs r6, #0
	mov r8, r6
	mov r7, sl
	adds r7, #0x2c
	str r7, [sp, #0x24]
	add r1, sp, #0x10
	mov sb, r1
_08005FF4:
	mov r2, r8
	lsls r3, r2, #2
	ldr r6, [sp, #0x24]
	adds r1, r6, r3
	ldr r6, [r1]
	cmp r6, #0
	bne _08006004
	b _08006170
_08006004:
	movs r1, #0xc
	ldr r2, _080060F4 @ =0x03002BC0
	adds r2, r3, r2
	ldr r2, [r2]
	ands r2, r1
	cmp r2, #0
	beq _08006014
	b _08006170
_08006014:
	ldr r3, [r5, #0x2c]
	mov r7, r8
	lsls r1, r7, #3
	mov r2, sl
	adds r4, r1, r2
	adds r4, #0x3c
	mov r7, sb
	movs r1, #2
	ldrsh r2, [r7, r1]
	movs r7, #2
	ldrsh r1, [r4, r7]
	subs r2, r2, r1
	mov ip, r2
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r7, #0x2e
	ldrsh r1, [r6, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _0800603E
	rsbs r1, r1, #0
_0800603E:
	cmp r1, #0x7f
	bgt _08006068
	mov r1, sb
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r7, #0
	ldrsh r1, [r4, r7]
	subs r1, r2, r1
	cmp r1, #0
	bge _08006054
	rsbs r1, r1, #0
_08006054:
	cmp r1, #0xe
	bgt _08006068
	movs r1, #0x18
	rsbs r1, r1, #0
	cmp ip, r1
	blt _08006068
	movs r1, #1
	mov r2, ip
	cmp r2, #4
	ble _0800606A
_08006068:
	movs r1, #0
_0800606A:
	cmp r1, #0
	bne _08006070
	b _08006170
_08006070:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080060F8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _080060FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006100
	movs r6, #0
	ldrsh r0, [r5, r6]
	movs r7, #2
	ldrsh r1, [r5, r7]
	bl CheckEmptySlotExist
	adds r1, r0, #0
	cmp r1, #0
	bne _08006100
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0800616C
	ldrb r1, [r5, #0xd]
	cmp r1, #0
	bne _0800616C
	movs r2, #0
	ldrsh r1, [r5, r2]
	cmp r1, #3
	bgt _080060DE
	adds r0, r1, #0
	movs r7, #2
	ldrsh r1, [r5, r7]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #1
	mov r3, r8
	bl FUN_080177b4
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080060DE:
	movs r1, #0x24
	strb r1, [r5, #0xd]
	movs r1, #4
	strb r1, [r5, #0xf]
	ldr r2, [r5, #0x2c]
	ldrh r1, [r2]
	strh r1, [r5, #0x10]
	ldrh r1, [r2, #4]
	strh r1, [r5, #0x12]
	b _0800616C
	.align 2, 0
_080060F4: .4byte 0x03002BC0
_080060F8: .4byte 0x0000FFFF
_080060FC: .4byte 0x030047A4
_08006100:
	mov r0, r8
	strb r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #3
	bgt _08006124
	movs r6, #2
	ldrsh r1, [r5, r6]
	add r2, sp, #0x18
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r2, #0
	mov r3, r8
	bl FUN_080177b4
_08006124:
	ldr r6, _08006168 @ =0x030047A4
	ldr r0, [r6]
	movs r4, #0x80
	lsls r4, r4, #4
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
	ldr r0, [r6]
	ands r0, r4
	cmp r0, #0
	bne _08006154
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r2, #2
	ldrsh r1, [r5, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006156
_08006154:
	movs r2, #1
_08006156:
	ldrh r1, [r5, #0x34]
	adds r0, r5, #0
	bl FUN_08005d84
	ldrb r2, [r5, #6]
	movs r1, #1
	orrs r1, r2
	strb r1, [r5, #6]
	b _0800617C
	.align 2, 0
_08006168: .4byte 0x030047A4
_0800616C:
	movs r6, #0
	str r6, [sp, #0x20]
_08006170:
	movs r7, #1
	add r8, r7
	mov r1, r8
	cmp r1, #3
	bgt _0800617C
	b _08005FF4
_0800617C:
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r5, #0xe]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08006194
FUN_08006194: @ 0x08006194
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08006254 @ =0x0300002C
	ldr r6, [r0]
	cmp r6, #0
	bne _080061AA
	b _080062C2
_080061AA:
	ldrb r0, [r7, #4]
	mov r8, r0
	ldr r4, [r6, #0x28]
	cmp r4, #0
	bne _080061B6
	b _080062C2
_080061B6:
	movs r1, #0
	mov sb, r1
_080061BA:
	ldrb r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0800624C
	ldrh r1, [r4, #4]
	ldr r0, _08006258 @ =0x000001FF
	cmp r1, r0
	bne _0800624C
	adds r3, r7, #0
	adds r3, #8
	ldr r2, [r4, #0x2c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #8
	ldrsh r0, [r7, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061E2
	rsbs r1, r1, #0
_080061E2:
	cmp r1, #0x5f
	bgt _08006210
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080061F6
	rsbs r1, r1, #0
_080061F6:
	cmp r1, #0x7f
	bgt _08006210
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0800620A
	rsbs r1, r1, #0
_0800620A:
	movs r0, #1
	cmp r1, #0x5f
	ble _08006212
_08006210:
	movs r0, #0
_08006212:
	cmp r0, #0
	beq _0800624C
	ldr r1, _0800625C @ =0x03002BE0
	mov r5, r8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08006260
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08006260
	ldrb r0, [r4, #0x15]
	cmp r0, #1
	bne _08006260
	adds r5, r6, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	bne _0800624C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xf
	strb r0, [r5]
_0800624C:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r4, [r0]
	b _080062BC
	.align 2, 0
_08006254: .4byte 0x0300002C
_08006258: .4byte 0x000001FF
_0800625C: .4byte 0x03002BE0
_08006260:
	mov r2, r8
	strb r2, [r4, #4]
	ldr r0, _080062B0 @ =0x0000010F
	bl PlaySound_0824078c
	ldr r0, _080062B4 @ =FUN_0800676c
	str r0, [r4, #0x44]
	mov r5, sb
	str r5, [r4, #0x18]
	strb r5, [r4, #9]
	ldr r0, [r4, #0x28]
	ldr r1, [r6, #0x1c]
	str r5, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _080062B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080062A2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r4, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _080062A4
_080062A2:
	movs r2, #1
_080062A4:
	ldrh r1, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_08005d84
	movs r0, #1
	b _080062C4
	.align 2, 0
_080062B0: .4byte 0x0000010F
_080062B4: .4byte FUN_0800676c
_080062B8: .4byte 0x030047A4
_080062BC:
	cmp r4, #0
	beq _080062C2
	b _080061BA
_080062C2:
	movs r0, #0
_080062C4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080062d4
FUN_080062d4: @ 0x080062D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	ldr r0, [r5, #0x2c]
	movs r1, #2
	ldrsh r7, [r0, r1]
	adds r6, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800630A
	cmp r1, #0
	blt _0800630A
	ldr r0, _08006310 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800630A
	ldr r0, _08006314 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006318
_0800630A:
	movs r4, #0
	b _08006326
	.align 2, 0
_08006310: .4byte 0x030046A8
_08006314: .4byte 0x030046AC
_08006318:
	ldr r0, _08006338 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08006326:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800633C
	adds r0, #4
	b _08006348
	.align 2, 0
_08006338: .4byte 0x030046A4
_0800633C:
	ldr r0, _0800635C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006348:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08006360
	cmp r3, #2
	beq _08006364
	b _08006368
	.align 2, 0
_0800635C: .4byte 0x030046A4
_08006360:
	ldrb r0, [r6, #4]
	b _08006366
_08006364:
	ldrb r0, [r6]
_08006366:
	subs r2, r2, r0
_08006368:
	subs r0, r7, r2
	cmp r0, #0
	ble _0800638E
	ldr r2, [r5, #0x2c]
	adds r1, r0, #0
	cmp r1, #0x20
	ble _08006378
	movs r1, #0x20
_08006378:
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08005f54
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	b _0800639C
_0800638E:
	ldr r1, [r5, #0x2c]
	adds r0, r2, #1
	movs r2, #0
	strh r0, [r1, #2]
	ldr r0, _080063A8 @ =FUN_080063ac
	str r0, [r5, #0x44]
	str r2, [r5, #0x18]
_0800639C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080063A8: .4byte FUN_080063ac

	thumb_func_start FUN_080063ac
FUN_080063ac: @ 0x080063AC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, [r4, #0x2c]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080063D8
	cmp r1, #0
	blt _080063D8
	ldr r0, _080063DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080063D8
	ldr r0, _080063E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080063E4
_080063D8:
	movs r5, #0
	b _080063F2
	.align 2, 0
_080063DC: .4byte 0x030046A8
_080063E0: .4byte 0x030046AC
_080063E4:
	ldr r0, _08006404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080063F2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006408
	adds r0, #4
	b _08006414
	.align 2, 0
_08006404: .4byte 0x030046A4
_08006408:
	ldr r0, _08006428 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08006414:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0800642C
	cmp r3, #2
	beq _08006430
	b _08006434
	.align 2, 0
_08006428: .4byte 0x030046A4
_0800642C:
	ldrb r0, [r6, #4]
	b _08006432
_08006430:
	ldrb r0, [r6]
_08006432:
	subs r2, r2, r0
_08006434:
	ldr r0, [r4, #0x18]
	cmp r0, #2
	bhi _08006442
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _0800646A
_08006442:
	cmp r0, #5
	bls _08006464
	ldr r0, _08006460 @ =FUN_080065a4
	str r0, [r4, #0x44]
	movs r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x2c]
	adds r0, r2, #1
	strh r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_080139a0
	b _08006480
	.align 2, 0
_08006460: .4byte FUN_080065a4
_08006464:
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_0800646A:
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006480:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006488
FUN_08006488: @ 0x08006488
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080064C4
_080064BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080064C4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080064E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080064F0
_080064E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080064F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006528 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006560
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800652C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006520
	ldrb r0, [r4, #5]
_08006520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800653C
	.align 2, 0
_08006528: .4byte 0x0000FFFF
_0800652C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800653C
	strh r1, [r4, #8]
_0800653C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006560
	movs r0, #1
	strb r0, [r4, #7]
_08006560:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006570
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006570:
	ldr r0, [r7, #0x18]
	cmp r0, #3
	bhi _0800657E
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	adds r0, #8
	b _08006596
_0800657E:
	cmp r0, #7
	bls _08006590
	ldr r0, _0800658C @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r0, #0
	b _0800659C
	.align 2, 0
_0800658C: .4byte FUN_08006678
_08006590:
	ldr r1, [r7, #0x2c]
	ldrh r0, [r1, #2]
	subs r0, #8
_08006596:
	strh r0, [r1, #2]
	ldr r0, [r7, #0x18]
	adds r0, #1
_0800659C:
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080065a4
FUN_080065a4: @ 0x080065A4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r2, [r4, #8]
	cmp r2, #0
	bne _080065C8
	ldr r1, [r4, #0x18]
	ldr r0, _080065C0 @ =0x00000383
	cmp r1, r0
	bls _080065C8
	ldr r0, _080065C4 @ =FUN_08006640
	str r0, [r4, #0x44]
	str r2, [r4, #0x18]
	b _08006636
	.align 2, 0
_080065C0: .4byte 0x00000383
_080065C4: .4byte FUN_08006640
_080065C8:
	ldr r0, [r4, #0x18]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0xf
	bne _08006622
	ldr r0, [r4, #0x2c]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080065F8
	cmp r1, #0
	blt _080065F8
	ldr r0, _080065FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080065F8
	ldr r0, _08006600 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08006604
_080065F8:
	movs r0, #0
	b _08006612
	.align 2, 0
_080065FC: .4byte 0x030046A8
_08006600: .4byte 0x030046AC
_08006604:
	ldr r0, _0800663C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08006612:
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08006622
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r4, #0x18]
_08006622:
	adds r0, r4, #0
	bl FUN_08005ee4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_08006636:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800663C: .4byte 0x030046A4

	thumb_func_start FUN_08006640
FUN_08006640: @ 0x08006640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0x2d
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006662
	ldrb r1, [r4, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #6]
	b _0800666A
_08006662:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08005f54
_0800666A:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006678
FUN_08006678: @ 0x08006678
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066AC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080066B4
_080066AC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080066B4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080066D8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080066E0
_080066D8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080066E0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006718 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006750
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800671C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006710
	ldrb r0, [r4, #5]
_08006710:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800672C
	.align 2, 0
_08006718: .4byte 0x0000FFFF
_0800671C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800672C
	strh r1, [r4, #8]
_0800672C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006750
	movs r0, #1
	strb r0, [r4, #7]
_08006750:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006760
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006760:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800676c
FUN_0800676c: @ 0x0800676C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r1, #0
	ldr r5, [r6, #0x20]
	ldr r4, [r6, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _080067A2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080067AA
_080067A2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080067AA:
	str r0, [r5]
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
	beq _080067CE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080067D6
_080067CE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080067D6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006830
	.align 2, 0
_08006810: .4byte 0x0000FFFF
_08006814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800682E
_0800681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800682E
	strh r1, [r4, #8]
	movs r3, #1
	b _08006830
_0800682E:
	movs r3, #0
_08006830:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _08006858
	movs r0, #1
	strb r0, [r4, #7]
	b _08006858
_08006856:
	movs r3, #0
_08006858:
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08006868
	ldr r0, [r6, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006868:
	cmp r3, #0
	beq _08006920
	ldr r0, [r6, #0x2c]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080068CC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, _080068D0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl CheckEmptySlotExist
	cmp r0, #0
	bne _080068D8
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068C6
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #1
	bl FUN_080177b4
_080068C6:
	ldr r0, _080068D4 @ =FUN_08006a80
	b _080068FC
	.align 2, 0
_080068CC: .4byte 0x0000FFFF
_080068D0: .4byte 0x030047A4
_080068D4: .4byte FUN_08006a80
_080068D8:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt _080068FA
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r3, #4
	ldrsb r3, [r6, r3]
	add r2, sp, #0x10
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x18
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	movs r2, #0
	bl FUN_080177b4
_080068FA:
	ldr r0, _08006918 @ =FUN_08006930
_080068FC:
	str r0, [r6, #0x44]
	movs r2, #0
	str r2, [r6, #0x18]
	ldr r0, [r6, #0x28]
	ldr r1, _0800691C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	str r2, [sp]
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _08006926
	.align 2, 0
_08006918: .4byte FUN_08006930
_0800691C: .4byte 0x0300002C
_08006920:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08006926:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006930
FUN_08006930: @ 0x08006930
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006964
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0800696C
_08006964:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800696C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006990
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006998
_08006990:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006998:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080069D0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006A08
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080069D4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080069C8
	ldrb r0, [r4, #5]
_080069C8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080069E4
	.align 2, 0
_080069D0: .4byte 0x0000FFFF
_080069D4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080069E4
	strh r1, [r4, #8]
_080069E4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006A08
	movs r0, #1
	strb r0, [r4, #7]
_08006A08:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006A18
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006A18:
	ldr r1, [r7, #0x18]
	cmp r1, #8
	bne _08006A58
	ldr r0, _08006A54 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08006A34
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08006A34:
	ldrh r4, [r7, #0x34]
	movs r1, #0
	ldrsh r0, [r7, r1]
	movs r2, #2
	ldrsh r1, [r7, r2]
	bl CheckEmptySlotExist
	movs r2, #0
	cmp r0, #1
	bne _08006A4A
	movs r2, #1
_08006A4A:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08005d84
	b _08006A74
	.align 2, 0
_08006A54: .4byte 0x030047A4
_08006A58:
	cmp r1, #8
	bls _08006A74
	ldr r0, [r7, #0x20]
	movs r2, #0x1e
	movs r3, #0x5a
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08006A74
	ldrb r1, [r7, #6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #6]
_08006A74:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08006a80
FUN_08006a80: @ 0x08006A80
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AB6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006ABE
_08006AB6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006ABE:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006AE2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006AEA
_08006AE2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006AEA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006B20 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08006B58
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006B24
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006B1A
	ldrb r0, [r4, #5]
_08006B1A:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006B34
	.align 2, 0
_08006B20: .4byte 0x0000FFFF
_08006B24:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006B34
	strh r1, [r4, #8]
_08006B34:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006B58
	movs r0, #1
	strb r0, [r4, #7]
_08006B58:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006B68
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006B68:
	ldr r0, [r7, #0x18]
	cmp r0, #0x1f
	bls _08006B8A
	ldr r0, _08006B98 @ =FUN_08006ba0
	str r0, [r7, #0x44]
	movs r0, #0
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x28]
	ldr r1, _08006B9C @ =0x0300002C
	ldr r1, [r1]
	ldr r1, [r1, #0x1c]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
_08006B8A:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006B98: .4byte FUN_08006ba0
_08006B9C: .4byte 0x0300002C

	thumb_func_start FUN_08006ba0
FUN_08006ba0: @ 0x08006BA0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	ldr r5, [r7, #0x20]
	ldr r4, [r7, #0x28]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006BD8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08006BE0
_08006BD8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08006BE0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08006C04
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08006C0C
_08006C04:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08006C0C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08006C44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08006C8A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08006C4E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08006C48
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r3, #1
	b _08006C64
	.align 2, 0
_08006C44: .4byte 0x0000FFFF
_08006C48:
	subs r0, #1
	strh r0, [r4, #8]
	b _08006C62
_08006C4E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08006C62
	strh r1, [r4, #8]
	movs r3, #1
	b _08006C64
_08006C62:
	movs r3, #0
_08006C64:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _08006C8C
	movs r0, #1
	strb r0, [r4, #7]
	b _08006C8C
_08006C8A:
	movs r3, #0
_08006C8C:
	ldrb r0, [r7, #7]
	cmp r0, #0
	beq _08006C9C
	ldr r0, [r7, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_08006C9C:
	cmp r3, #0
	beq _08006CC0
	ldr r0, _08006CBC @ =FUN_08006678
	str r0, [r7, #0x44]
	movs r2, #0
	str r2, [r7, #0x18]
	movs r0, #0xff
	strb r0, [r7, #4]
	ldr r0, [r7, #0x28]
	mov r3, ip
	ldr r1, [r3, #0x1c]
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	b _08006CC6
	.align 2, 0
_08006CBC: .4byte FUN_08006678
_08006CC0:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_08006CC6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08006cd0
FUN_08006cd0: @ 0x08006CD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	movs r6, #0
	ldr r0, _08006D20 @ =0x03002BE0
	mov r8, r0
_08006CE2:
	lsls r1, r6, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	mov r0, sl
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _08006D64
	lsls r0, r6, #3
	mov r7, sl
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r2, #0
	adds r5, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D24
	asrs r0, r0, #8
	b _08006D2A
	.align 2, 0
_08006D20: .4byte 0x03002BE0
_08006D24:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D2A:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006D3C
	asrs r0, r0, #8
	b _08006D42
_08006D3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08006D42:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08006D56
	asrs r1, r0, #8
	b _08006D5C
_08006D56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08006D5C:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_08006D64:
	adds r6, #1
	cmp r6, #3
	ble _08006CE2
	mov r1, sl
	ldr r3, [r1, #0x28]
	movs r2, #0x24
	add r2, sl
	mov sb, r2
	cmp r3, #0
	bne _08006D7A
	b _08006F3C
_08006D7A:
	movs r5, #1
	movs r6, #2
	rsbs r6, r6, #0
_08006D80:
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	ldrb r1, [r3, #6]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08006D9A
	adds r0, r3, #0
	bl FUN_08005e90
	b _08006F34
_08006D9A:
	ldrh r0, [r3, #0x16]
	cmp r0, #0
	beq _08006DC4
	ldr r0, _08006DB8 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0x92
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	bne _08006DBC
	movs r0, #1
	b _08006DBE
	.align 2, 0
_08006DB8: .4byte 0x030046A0
_08006DBC:
	movs r0, #0
_08006DBE:
	cmp r0, #0
	bne _08006DC4
	b _08006F12
_08006DC4:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006DD0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_08006DD0:
	ldr r1, [r3, #0x20]
	adds r4, r1, #0
	cmp r1, #0
	bne _08006DDA
	b _08006F2A
_08006DDA:
	ldrb r0, [r3, #9]
	cmp r0, #0
	bne _08006DE2
	b _08006F0C
_08006DE2:
	ldr r0, _08006DFC @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _08006E00
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0
	strb r0, [r3, #0xb]
_08006DF4:
	strb r0, [r3, #0xc]
_08006DF6:
	strb r5, [r3, #0xa]
	b _08006F2A
	.align 2, 0
_08006DFC: .4byte 0x03002B48
_08006E00:
	ldr r0, _08006E34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08006E48
	ldr r0, _08006E38 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _08006E44
	ldr r2, _08006E3C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08006E2E
	ldr r7, _08006E40 @ =0x00000442
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E2E
	movs r2, #1
_08006E2E:
	adds r0, r2, #0
	b _08006E70
	.align 2, 0
_08006E34: .4byte 0x030047A4
_08006E38: .4byte 0x03002BE0
_08006E3C: .4byte 0x00000446
_08006E40: .4byte 0x00000442
_08006E44:
	movs r0, #0
	b _08006E70
_08006E48:
	ldr r0, _08006E9C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _08006E74
	ldr r0, _08006EA0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08006E6E
	ldr r0, _08006EA4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _08006E6E
	movs r1, #1
_08006E6E:
	adds r0, r1, #0
_08006E70:
	cmp r0, #0
	beq _08006ED8
_08006E74:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	beq _08006E7E
	movs r0, #0x1f
	strb r0, [r3, #0xb]
_08006E7E:
	ldrb r1, [r3, #0xb]
	adds r2, r1, #0
	cmp r2, #0
	beq _08006EB0
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EA8
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ED2
	.align 2, 0
_08006E9C: .4byte 0x030046A0
_08006EA0: .4byte 0x03002B8C
_08006EA4: .4byte 0x03002B60
_08006EA8:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ED2
_08006EB0:
	ldrb r0, [r3, #0xc]
	cmp r0, #0x2f
	bhi _08006EBE
	ldr r0, [r4]
	ands r0, r6
	str r0, [r4]
	b _08006ECC
_08006EBE:
	cmp r0, #0x47
	bhi _08006ECA
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006ECC
_08006ECA:
	strb r2, [r3, #0xc]
_08006ECC:
	ldrb r0, [r3, #0xc]
	adds r0, #1
	strb r0, [r3, #0xc]
_08006ED2:
	movs r0, #0
	strb r0, [r3, #0xa]
	b _08006F2A
_08006ED8:
	ldrb r0, [r3, #0xa]
	cmp r0, #0
	bne _08006EE2
	movs r0, #0x2f
	strb r0, [r3, #0xb]
_08006EE2:
	ldrb r1, [r3, #0xb]
	cmp r1, #0
	beq _08006F04
	subs r1, #1
	strb r1, [r3, #0xb]
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bls _08006EFA
	ldr r0, [r4]
	orrs r0, r5
	b _08006EFE
_08006EFA:
	ldr r0, [r4]
	ands r0, r6
_08006EFE:
	str r0, [r4]
	movs r0, #0
	b _08006DF4
_08006F04:
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
	b _08006DF6
_08006F0C:
	ldr r0, [r1]
	ands r0, r6
	b _08006F28
_08006F12:
	ldr r1, [r3, #0x1c]
	cmp r1, #0
	beq _08006F1E
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08006F1E:
	ldr r1, [r3, #0x20]
	cmp r1, #0
	beq _08006F2A
	ldr r0, [r1]
	orrs r0, r5
_08006F28:
	str r0, [r1]
_08006F2A:
	ldr r2, [r3, #0x44]
	mov r0, sl
	adds r1, r3, #0
	bl _call_via_r2
_08006F34:
	mov r3, r8
	cmp r3, #0
	beq _08006F3C
	b _08006D80
_08006F3C:
	mov r7, sb
	ldrb r0, [r7]
	cmp r0, #0
	beq _08006F48
	subs r0, #1
	strb r0, [r7]
_08006F48:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08006f58
FUN_08006f58: @ 0x08006F58
	push {r4, lr}
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _08006F72
_08006F60:
	adds r0, r1, #0
	adds r0, #0xb8
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_08005e90
	adds r1, r4, #0
	cmp r1, #0
	bne _08006F60
_08006F72:
	ldr r1, _08006F80 @ =0x0300002C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08006F80: .4byte 0x0300002C

	thumb_func_start FUN_08006f84
FUN_08006f84: @ 0x08006F84
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08006FE4 @ =0x0300002C
	str r5, [r0]
	ldr r0, _08006FE8 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x18]
	movs r4, #0
	ldr r0, _08006FEC @ =0x00003876
	strh r0, [r5, #0x20]
	ldr r0, _08006FF0 @ =0x0000922E
	ldr r1, _08006FF4 @ =0x00009AF2
	bl GetFile
	str r0, [r5, #0x1c]
	str r4, [r5, #0x28]
	movs r7, #0
_08006FA8:
	ldr r0, _08006FF8 @ =0x03002BE0
	lsls r1, r7, #2
	adds r0, r1, r0
	ldr r2, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	cmp r2, #0
	beq _0800703C
	lsls r0, r7, #3
	adds r3, r0, r5
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08006FFC
	asrs r0, r0, #8
	b _08007002
	.align 2, 0
_08006FE4: .4byte 0x0300002C
_08006FE8: .4byte 0x00001C1A
_08006FEC: .4byte 0x00003876
_08006FF0: .4byte 0x0000922E
_08006FF4: .4byte 0x00009AF2
_08006FF8: .4byte 0x03002BE0
_08006FFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08007002:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08007014
	asrs r0, r0, #8
	b _0800701A
_08007014:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800701A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800702E
	asrs r1, r0, #8
	b _08007034
_0800702E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_08007034:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_0800703C:
	adds r7, #1
	cmp r7, #3
	ble _08006FA8
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800704c
FUN_0800704c: @ 0x0800704C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x5c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007084
	ldr r1, _0800707C @ =FUN_08006cd0
	ldr r2, _08007080 @ =FUN_08006f58
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08006f84
	cmp r0, #0
	bge _08007084
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007086
	.align 2, 0
_0800707C: .4byte FUN_08006cd0
_08007080: .4byte FUN_08006f58
_08007084:
	adds r0, r4, #0
_08007086:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800708c
FUN_0800708c: @ 0x0800708C
	push {lr}
	ldr r0, _080070A4 @ =0x0300002C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800709E
	movs r0, #0
	movs r1, #0
	bl FUN_0800704c
_0800709E:
	pop {r1}
	bx r1
	.align 2, 0
_080070A4: .4byte 0x0300002C

	thumb_func_start FUN_080070a8
FUN_080070a8: @ 0x080070A8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0800708c
	adds r4, r0, #0
	cmp r4, #0
	beq _08007126
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007126
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r6, [r5]
	strh r7, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	strb r2, [r5, #5]
	strb r2, [r5, #6]
	strb r2, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, _0800712C @ =FUN_080062d4
	str r0, [r5, #0x44]
	strb r2, [r5, #0xc]
	ldr r0, [sp, #0x44]
	strb r0, [r5, #0x14]
	mov r0, r8
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_0800710A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800710A
	movs r0, #0x28
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007130
	adds r0, r5, #0
	bl Free
_08007126:
	movs r0, #1
	rsbs r0, r0, #0
	b _080071FC
	.align 2, 0
_0800712C: .4byte FUN_080062d4
_08007130:
	movs r1, #0x28
	bl ClearMemory
	ldr r0, [r5, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0
	bl FUN_0822d9f0
	ldr r0, [r5, #0x1c]
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0xa
	rsbs r2, r2, #0
	bl FUN_0822dad4
	mov r0, sb
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _0800717C
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r1, r0, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #1
	b _08007196
_0800717C:
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	lsls r0, r0, #5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #2
_08007196:
	strb r0, [r1, #0xf]
	ldr r2, [r5, #0x1c]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r1, [r5, #0x1c]
	movs r0, #0x10
	strb r0, [r1, #0x10]
	ldr r0, [r5, #0x1c]
	adds r0, #0x18
	str r0, [r5, #0x2c]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _080071BE
	bl FUN_08241574
	strh r0, [r5, #0x16]
	b _080071C4
_080071BE:
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r5, #0x16]
_080071C4:
	movs r4, #0
	ldr r0, [sp, #0x40]
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r5, #0x1c]
	adds r1, #0x18
	movs r2, #0x28
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r5, #0
	bl FUN_08005e30
	movs r0, #0
_080071FC:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800720c
FUN_0800720c: @ 0x0800720C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08007260
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007258 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800725C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _0800726C
	.align 2, 0
_08007258: .4byte 0xFFFF0000
_0800725C: .4byte 0x0000FFFF
_08007260:
	ldr r2, _08007284 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_0800726C:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _08007288
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	b _0800728C
	.align 2, 0
_08007284: .4byte 0xFFFF0000
_08007288:
	movs r0, #0
	mov sb, r0
_0800728C:
	mov r8, r0
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x24]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x4f
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x18
_080072BA:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x10
	cmp r0, r2
	bge _080072BA
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080072E8
	movs r4, #0
	add r5, sp, #0x10
	b _080072DC
_080072D4:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_080072DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080072E8
	cmp r4, #2
	ble _080072D4
_080072E8:
	add r0, sp, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x1c
	mov r1, sb
	mov r2, r8
	ldr r3, [sp, #0x24]
	bl FUN_080070a8
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007310
FUN_08007310: @ 0x08007310
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	bl FUN_0800708c
	mov r8, r0
	cmp r0, #0
	bne _0800732E
	b _08007428
_0800732E:
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007428
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r4, [r5]
	strh r6, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	strb r2, [r5, #6]
	strb r7, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0800738C
	ldr r0, _08007380 @ =FUN_08006488
	str r0, [r5, #0x44]
	ldr r0, _08007384 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08007390
	ldr r0, _08007388 @ =0x0000026F
	bl PlaySound_082406e0
	b _08007390
	.align 2, 0
_08007380: .4byte FUN_08006488
_08007384: .4byte 0x030047A4
_08007388: .4byte 0x0000026F
_0800738C:
	ldr r0, _080073CC @ =FUN_08006678
	str r0, [r5, #0x44]
_08007390:
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x30]
	ldr r0, [sp, #0x40]
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x44]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_080073A0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _080073A0
	movs r0, #0x2c
	bl Malloc
	str r0, [r5, #0x20]
	cmp r0, #0
	beq _08007422
	movs r1, #0x2c
	bl ClearMemory
	movs r0, #0x1c
	bl Malloc
	str r0, [r5, #0x24]
	cmp r0, #0
	bne _080073D0
	ldr r0, [r5, #0x20]
	b _0800741A
	.align 2, 0
_080073CC: .4byte FUN_08006678
_080073D0:
	movs r1, #0x1c
	bl ClearMemory
	movs r0, #0x10
	bl Malloc
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _080073F0
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _080073EC
	bl Free
_080073EC:
	ldr r0, [r5, #0x24]
	b _0800741A
_080073F0:
	movs r1, #0x10
	bl ClearMemory
	ldr r0, [r5, #0x24]
	mov r2, r8
	ldrh r1, [r2, #0x20]
	bl FUN_0822b16c
	cmp r0, #0
	bne _0800742E
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800740E
	bl Free
_0800740E:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08007418
	bl Free
_08007418:
	ldr r0, [r5, #0x28]
_0800741A:
	cmp r0, #0
	beq _08007422
	bl Free
_08007422:
	adds r0, r5, #0
	bl Free
_08007428:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007630
_0800742E:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	movs r2, #0
	bl FUN_0822a470
	ldr r2, [r5, #0x20]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r5, #0x20]
	adds r6, r0, #0
	adds r6, #0x1c
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800746E
	cmp r1, #0
	blt _0800746E
	ldr r0, _08007474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800746E
	ldr r0, _08007478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800747C
_0800746E:
	movs r4, #0
	b _0800748A
	.align 2, 0
_08007474: .4byte 0x030046A8
_08007478: .4byte 0x030046AC
_0800747C:
	ldr r0, _0800749C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800748A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080074A0
	adds r0, #4
	b _080074AC
	.align 2, 0
_0800749C: .4byte 0x030046A4
_080074A0:
	ldr r0, _080074C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080074AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080074C4
	cmp r2, #2
	beq _080074C8
	b _080074CC
	.align 2, 0
_080074C0: .4byte 0x030046A4
_080074C4:
	ldrb r0, [r6, #4]
	b _080074CA
_080074C8:
	ldrb r0, [r6]
_080074CA:
	subs r1, r1, r0
_080074CC:
	ldr r0, [r5, #0x20]
	strh r1, [r0, #0x1e]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _080074E0
	ldr r0, [r5, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_080074E0:
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x4c]
	strb r0, [r5, #9]
	add r0, sp, #0x50
	ldrb r0, [r0]
	strb r0, [r5, #0x15]
	ldr r1, [sp, #0x50]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08007508
	ldr r0, [r5, #0x24]
	ldr r1, _08007504 @ =0x0000028A
	bl FUN_0822b20c
	b _08007524
	.align 2, 0
_08007504: .4byte 0x0000028A
_08007508:
	cmp r0, #1
	bne _0800751C
	ldr r0, [r5, #0x24]
	ldr r1, _08007518 @ =0x0000028D
	bl FUN_0822b20c
	b _08007524
	.align 2, 0
_08007518: .4byte 0x0000028D
_0800751C:
	ldr r0, [r5, #0x24]
	ldr r1, _08007568 @ =0x0000028E
	bl FUN_0822b20c
_08007524:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080075CA
	ldr r2, [r5, #0x20]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0800756C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08007580
	ldr r0, _08007570 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800757C
	ldr r2, _08007574 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08007562
	ldr r3, _08007578 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _08007562
	movs r2, #1
_08007562:
	adds r0, r2, #0
	b _080075B0
	.align 2, 0
_08007568: .4byte 0x0000028E
_0800756C: .4byte 0x030047A4
_08007570: .4byte 0x03002BE0
_08007574: .4byte 0x00000446
_08007578: .4byte 0x00000442
_0800757C:
	movs r0, #0
	b _080075B0
_08007580:
	ldr r0, _080075B8 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _080075B4
	ldr r0, _080075BC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _080075B4
	ldr r0, _080075C0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080075AE
	ldr r0, _080075C4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080075AE
	movs r1, #1
_080075AE:
	adds r0, r1, #0
_080075B0:
	cmp r0, #0
	beq _080075C8
_080075B4:
	movs r0, #0
	b _080075CA
	.align 2, 0
_080075B8: .4byte 0x03002B48
_080075BC: .4byte 0x030046A0
_080075C0: .4byte 0x03002B8C
_080075C4: .4byte 0x03002B60
_080075C8:
	movs r0, #1
_080075CA:
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x28]
	mov r3, r8
	ldr r1, [r3, #0x1c]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq _080075EE
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	bl FUN_08241574
	strh r0, [r5, #0x16]
	b _080075F4
_080075EE:
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r5, #0x16]
_080075F4:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, [r5, #0x20]
	adds r1, #0x1c
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r4, #0
	bl FUN_080139a0
	adds r0, r5, #0
	bl FUN_08005e30
	movs r0, #0
_08007630:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007640
FUN_08007640: @ 0x08007640
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08007694
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800768C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08007690 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _080076A0
	.align 2, 0
_0800768C: .4byte 0xFFFF0000
_08007690: .4byte 0x0000FFFF
_08007694:
	ldr r2, _080076B8 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_080076A0:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080076BC
	bl Script_GetValue
	str r0, [sp, #0x34]
	bl Script_GetValue
	b _080076C0
	.align 2, 0
_080076B8: .4byte 0xFFFF0000
_080076BC:
	movs r0, #0
	str r0, [sp, #0x34]
_080076C0:
	mov sl, r0
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x30]
	movs r0, #0x67
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x38]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x3c]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x24
_0800770C:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x1c
	cmp r0, r2
	bge _0800770C
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0800773A
	movs r4, #0
	add r5, sp, #0x1c
	b _0800772E
_08007726:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_0800772E:
	bl VM_GetPC
	cmp r0, #0
	beq _0800773A
	cmp r4, #2
	ble _08007726
_0800773A:
	mov r0, r8
	str r0, [sp]
	ldr r2, [sp, #0x38]
	str r2, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	add r0, sp, #0x28
	ldr r1, [sp, #0x34]
	mov r2, sl
	ldr r3, [sp, #0x30]
	bl FUN_08007310
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007770
FUN_08007770: @ 0x08007770
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0800708c
	adds r1, r0, #0
	cmp r1, #0
	bne _08007784
	movs r0, #1
	rsbs r0, r0, #0
	b _080077A2
_08007784:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _080077A2
_0800778A:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, r5
	bne _0800779C
	adds r0, r2, #0
	bl FUN_08005e90
_0800779C:
	adds r2, r4, #0
	cmp r2, #0
	bne _0800778A
_080077A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080077a8
FUN_080077a8: @ 0x080077A8
	push {lr}
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	bl FUN_08007770
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080077bc
FUN_080077bc: @ 0x080077BC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	bl FUN_0800708c
	adds r1, r0, #0
	cmp r1, #0
	bne _080077D4
	movs r0, #1
	rsbs r0, r0, #0
	b _08007816
_080077D4:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _08007816
	ldr r1, _0800781C @ =FUN_08006640
	mov ip, r1
_080077DE:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, #0
	bne _08007810
	ldrb r1, [r2, #0x14]
	cmp r1, #0
	beq _08007810
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, r6
	bne _08007810
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r1, r5
	bne _08007810
	ldr r1, [r2, #0x44]
	cmp r1, ip
	beq _08007810
	ldr r3, [r2, #0x2c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r3]
	str r2, [r3, #4]
_08007810:
	adds r2, r4, #0
	cmp r2, #0
	bne _080077DE
_08007816:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800781C: .4byte FUN_08006640

	thumb_func_start FUN_08007820
FUN_08007820: @ 0x08007820
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08007874
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007888 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800788C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
_08007874:
	mov r0, sp
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080077bc
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007888: .4byte 0xFFFF0000
_0800788C: .4byte 0x0000FFFF

	thumb_func_start FUN_08007890
FUN_08007890: @ 0x08007890
	str r1, [r0, #0x1c]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #3]
	bx lr

	thumb_func_start FUN_0800789c
FUN_0800789c: @ 0x0800789C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _080078AA
	movs r0, #0
	b _080078B0
_080078AA:
	movs r0, #0
	strb r0, [r1, #3]
	movs r0, #1
_080078B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080078b4
FUN_080078b4: @ 0x080078B4
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_08236524
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #0x3e]
	subs r0, r0, r1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080078E0
	movs r0, #0
	strh r0, [r5, #4]
	ldr r0, _080078DC @ =0x0000014F
	bl PlaySound_082406e0
	b _080078E8
	.align 2, 0
_080078DC: .4byte 0x0000014F
_080078E0:
	movs r0, #0xa7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080078E8:
	movs r0, #4
	strb r0, [r5, #9]
	adds r0, r5, #0
	adds r0, #0x20
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007958 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800795C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x20]
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	ldr r2, _08007960 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08007964
	asrs r2, r0, #0xc
	b _0800796A
	.align 2, 0
_08007958: .4byte 0xFFFF0000
_0800795C: .4byte 0x0000FFFF
_08007960: .4byte 0x085B0A08
_08007964:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0800796A:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08007998 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r1, _0800799C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080079A0
	asrs r2, r0, #0xc
	b _080079A6
	.align 2, 0
_08007998: .4byte 0xFFFF0000
_0800799C: .4byte 0x085B0A08
_080079A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080079A6:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080079EC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r0, #0xa4
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	add r2, sp, #0x1c
	bl FUN_080149dc
	movs r0, #0xa
	strb r0, [r5, #0xb]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080079EC: .4byte 0xFFFF0000

	thumb_func_start FUN_080079f0
FUN_080079f0: @ 0x080079F0
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08007A20 @ =0x0000F680
	adds r0, r5, #0
	bl FUN_0822b16c
	cmp r0, #0
	beq _08007A28
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	ldr r1, _08007A24 @ =FUN_08007a34
	adds r0, r4, #0
	bl FUN_08007890
	movs r0, #0
	strb r0, [r4, #2]
	b _08007A2C
	.align 2, 0
_08007A20: .4byte 0x0000F680
_08007A24: .4byte FUN_08007a34
_08007A28:
	movs r0, #1
	rsbs r0, r0, #0
_08007A2C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007a34
FUN_08007a34: @ 0x08007A34
	push {lr}
	adds r0, r1, #0
	bl FUN_0800789c
	pop {r0}
	bx r0

	thumb_func_start FUN_08007a40
FUN_08007a40: @ 0x08007A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov sb, r1
	mov r0, sb
	bl FUN_0800789c
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08007A60
	b _08007B88
_08007A60:
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	beq _08007A84
	ldrh r0, [r1]
	str r0, [sp, #0x20]
	ldr r1, _08007B7C @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r0, sp, #0x20
	str r0, [r1, #4]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	bl Script_ExecById
_08007A84:
	mov r0, sb
	ldrb r1, [r0, #0xa]
	adds r0, #0x3c
	strh r1, [r0, #0x10]
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007B80 @ =FUN_08007a34
	mov r0, sb
	bl FUN_08007890
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl FUN_0822b20c
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r5, sp, #0x2c
	ldrh r0, [r5]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007B7C @ =0xFFFF0000
	ldr r1, [sp, #0x2c]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08007B84 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	ldrh r0, [r5, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	movs r6, #0x80
	lsls r6, r6, #1
	str r6, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r7, #3
	str r7, [sp, #0xc]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #0xa
	mov r8, r2
	str r2, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #6
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	str r6, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080149dc
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r2, #6
	str r2, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	str r6, [sp, #0x14]
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #4
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08014da0
	b _08007C1E
	.align 2, 0
_08007B7C: .4byte 0xFFFF0000
_08007B80: .4byte FUN_08007a34
_08007B84: .4byte 0x0000FFFF
_08007B88:
	mov r2, sb
	ldrb r0, [r2, #9]
	cmp r0, #0
	beq _08007BA4
	subs r0, #1
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BA4
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl FUN_0822b20c
_08007BA4:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq _08007C1E
	subs r0, #1
	strb r0, [r1, #0xb]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BC8
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _08007BC4 @ =0x0000FFFB
	ands r0, r1
	b _08007BD2
	.align 2, 0
_08007BC4: .4byte 0x0000FFFB
_08007BC8:
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
_08007BD2:
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r0, _08007C30 @ =0x0203B400
	mov r8, r0
	ldr r4, _08007C34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _08007C38 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	mov r3, sb
	adds r3, #0x58
	ldrh r0, [r3]
	subs r0, #8
	movs r5, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	mov r2, sb
	adds r2, #0x5c
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08007C1E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007C30: .4byte 0x0203B400
_08007C34: .4byte 0x030046B8
_08007C38: .4byte 0x000003FF

	thumb_func_start FUN_08007c3c
FUN_08007c3c: @ 0x08007C3C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x68
	bl FUN_08236424
	adds r4, #0x3c
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007c58
FUN_08007c58: @ 0x08007C58
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _08007C86
	adds r4, r1, #0
	movs r5, #0
	b _08007C80
_08007C68:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08007C7C
	ldr r2, [r4, #0x1c]
	cmp r2, #0
	beq _08007C7C
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_08007C7C:
	adds r5, #1
	adds r4, #0xb8
_08007C80:
	ldr r0, [r6, #0x18]
	cmp r5, r0
	blt _08007C68
_08007C86:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007c90
FUN_08007c90: @ 0x08007C90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _08007CBC
	adds r5, r1, #0
	movs r6, #0
	b _08007CAC
_08007CA0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08007c3c
	adds r6, #1
	adds r5, #0xb8
_08007CAC:
	ldr r0, [r4, #0x18]
	cmp r6, r0
	blt _08007CA0
	ldr r0, [r4, #0x1c]
	bl Free
	movs r0, #0
	str r0, [r4, #0x1c]
_08007CBC:
	ldr r1, _08007CC8 @ =0x03000030
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007CC8: .4byte 0x03000030

	thumb_func_start FUN_08007ccc
FUN_08007ccc: @ 0x08007CCC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08007CF8 @ =0x03000030
	str r5, [r0]
	movs r0, #0x6e
	movs r1, #4
	bl Script_GetKeywordValue
	str r0, [r5, #0x18]
	movs r1, #0xb8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007CFC
	movs r0, #1
	rsbs r0, r0, #0
	bl exit
	.align 2, 0
_08007CF8: .4byte 0x03000030
_08007CFC:
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r5, #0x1c]
	movs r6, #0
	b _08007D14
_08007D08:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080079f0
	adds r6, #1
	adds r4, #0xb8
_08007D14:
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blt _08007D08
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007d24
FUN_08007d24: @ 0x08007D24
	push {r4, lr}
	ldr r0, _08007D58 @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	bne _08007D66
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007D64
	ldr r1, _08007D5C @ =FUN_08007c58
	ldr r2, _08007D60 @ =FUN_08007c90
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08007ccc
	cmp r0, #0
	bge _08007D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007D66
	.align 2, 0
_08007D58: .4byte 0x03000030
_08007D5C: .4byte FUN_08007c58
_08007D60: .4byte FUN_08007c90
_08007D64:
	adds r0, r4, #0
_08007D66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007d6c
FUN_08007d6c: @ 0x08007D6C
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bge _08007D8C
	adds r3, r0, #0
_08007D7A:
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08007D84
	adds r0, r1, #0
	b _08007D8E
_08007D84:
	adds r2, #1
	adds r1, #0xb8
	cmp r2, r3
	blt _08007D7A
_08007D8C:
	movs r0, #0
_08007D8E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007d94
FUN_08007d94: @ 0x08007D94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	ldr r0, _08007E3C @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	beq _08007E36
	bl FUN_08007d6c
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r1, #0
	mov sb, r1
	movs r4, #0
	strh r0, [r6]
	mov r0, sb
	strb r0, [r6, #9]
	movs r0, #0x6c
	movs r1, #0xa
	bl Script_GetKeywordValue
	strh r0, [r6, #4]
	strh r4, [r6, #6]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08007DE8
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	strh r0, [r6, #0x12]
	bl Script_GetValue
	strh r0, [r6, #0x14]
_08007DE8:
	ldr r1, _08007E40 @ =0x0000F680
	movs r0, #0x74
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x50
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #8]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0xc]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r7, r6, #0
	adds r7, #0x20
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08007E44
_08007E36:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007EDA
	.align 2, 0
_08007E3C: .4byte 0x03000030
_08007E40: .4byte 0x0000F680
_08007E44:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0822a4fc
	mov r1, r8
	strh r1, [r5, #0x10]
	movs r0, #2
	strb r0, [r5, #7]
	ldr r1, _08007EE8 @ =FUN_08007a40
	adds r0, r6, #0
	bl FUN_08007890
	mov r0, r8
	adds r0, #1
	strb r0, [r6, #0xa]
	mov r0, sb
	strb r0, [r6, #9]
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08007EEC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	orrs r0, r4
	ldr r3, _08007EF0 @ =0x0000FFFF
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	ldr r1, _08007EF4 @ =0x0000FF80
	orrs r0, r1
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldrh r1, [r6]
	ldr r2, _08007EF8 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08007EFC @ =FUN_080078b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r1, r6, #0
	adds r1, #0x10
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r1, #1
	strb r1, [r6, #2]
_08007EDA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08007EE8: .4byte FUN_08007a40
_08007EEC: .4byte 0xFFFF0000
_08007EF0: .4byte 0x0000FFFF
_08007EF4: .4byte 0x0000FF80
_08007EF8: .4byte 0x00004001
_08007EFC: .4byte FUN_080078b4

	thumb_func_start FUN_08007f00
FUN_08007f00: @ 0x08007F00
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bhs _08007F20
	adds r3, r0, #0
_08007F0E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08007F18
	adds r0, r1, #0
	b _08007F22
_08007F18:
	adds r2, #1
	adds r1, #0xe8
	cmp r2, r3
	blo _08007F0E
_08007F20:
	movs r0, #0
_08007F22:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007f28
FUN_08007f28: @ 0x08007F28
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0xc]
	movs r1, #1
	strb r1, [r0, #4]
	bx lr

	thumb_func_start FUN_08007f34
FUN_08007f34: @ 0x08007F34
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08007F42
	movs r0, #0
	b _08007F48
_08007F42:
	movs r0, #0
	strb r0, [r1, #4]
	movs r0, #1
_08007F48:
	pop {r1}
	bx r1

	thumb_func_start FUN_08007f4c
FUN_08007f4c: @ 0x08007F4C
	push {lr}
	adds r3, r2, #0
	ldrb r1, [r2, #2]
	cmp r1, #1
	bne _08007F6A
	movs r1, #4
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r2, #0
	movs r1, #3
	bl FUN_08007f28
	b _08007F80
_08007F6A:
	cmp r1, #2
	bne _08007F80
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08007F80
	adds r0, r3, #0
	movs r1, #4
	bl FUN_08007f28
_08007F80:
	pop {r0}
	bx r0

	thumb_func_start FUN_08007f84
FUN_08007f84: @ 0x08007F84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0xe4
	adds r0, r0, r7
	mov sb, r0
	adds r4, #0x20
	str r4, [r0]
	add r5, sp, #0x14
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0800804C @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x34
	movs r0, #2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f4d8
	mov r0, sb
	ldr r1, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	adds r5, r7, #0
	adds r5, #0x94
	ldr r2, _08008050 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08008054 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x24]
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r7, #0x10]
	ldr r2, _08008058 @ =0x00004001
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0800805C @ =FUN_08007f4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800804C: .4byte 0x05000002
_08008050: .4byte 0xFFFF0000
_08008054: .4byte 0x0000FFFF
_08008058: .4byte 0x00004001
_0800805C: .4byte FUN_08007f4c

	thumb_func_start FUN_08008060
FUN_08008060: @ 0x08008060
	push {lr}
	sub sp, #0x14
	adds r2, r0, #0
	ldrh r0, [r2, #0x12]
	cmp r0, #0
	beq _0800809E
	ldrh r0, [r2, #0x10]
	str r0, [sp]
	ldrb r0, [r2, #2]
	cmp r0, #3
	bne _0800807A
	movs r0, #1
	b _08008080
_0800807A:
	cmp r0, #4
	bne _08008082
	movs r0, #0
_08008080:
	str r0, [sp, #4]
_08008082:
	ldr r0, [r2, #0x1c]
	str r0, [sp, #8]
	ldr r1, _080080A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2, #0x12]
	bl Script_ExecById
_0800809E:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_080080A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080080a8
FUN_080080a8: @ 0x080080A8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080080ac
FUN_080080ac: @ 0x080080AC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080080EE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080080F8 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080080FC @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl FUN_0822f63c
_080080EE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080080F8: .4byte 0x085AA670
_080080FC: .4byte 0x085AA678

	thumb_func_start FUN_08008100
FUN_08008100: @ 0x08008100
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _08008142
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _08008164 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008168 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0822f63c
_08008142:
	movs r1, #8
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _0800815A
	adds r1, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, r1
	blt _0800815A
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08007f28
_0800815A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008164: .4byte 0x085AA670
_08008168: .4byte 0x085AA678

	thumb_func_start FUN_0800816c
FUN_0800816c: @ 0x0800816C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08007f34
	cmp r0, #0
	beq _080081BE
	adds r4, r5, #0
	adds r4, #0x34
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _080081D4 @ =0x085AA670
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080081D8 @ =0x085AA678
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0822f63c
	movs r0, #0xa
	strb r0, [r5, #5]
	ldr r0, _080081DC @ =0x0000014B
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08008060
_080081BE:
	ldr r0, [r5, #0xc]
	cmp r0, #0xa
	ble _080081CC
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08007f28
_080081CC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080081D4: .4byte 0x085AA670
_080081D8: .4byte 0x085AA678
_080081DC: .4byte 0x0000014B

	thumb_func_start FUN_080081e0
FUN_080081e0: @ 0x080081E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r1, #0
	adds r0, r7, #0
	bl FUN_08007f34
	cmp r0, #0
	bne _080081FA
	b _080082FE
_080081FA:
	adds r5, r7, #0
	adds r5, #0x34
	adds r0, r7, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _0800831C @ =0x085AA670
	ldr r0, [r7, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008320 @ =0x085AA678
	ldr r0, [r7, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r5, #0
	bl FUN_0822f63c
	movs r0, #0xa
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_08008060
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	adds r6, r7, #0
	adds r6, #0x54
	ldr r2, _08008324 @ =0xFFFF0000
	movs r0, #0x56
	adds r0, r0, r7
	mov sl, r0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldrh r0, [r6]
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x58
	adds r1, r1, r7
	mov sb, r1
	ldrh r1, [r1]
	add r5, sp, #0x1c
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #4
	str r3, [sp, #0x10]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	subs r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	adds r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	adds r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	subs r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
_080082FE:
	ldr r0, [r7, #0xc]
	cmp r0, #0xa
	ble _0800830C
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08007f28
_0800830C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800831C: .4byte 0x085AA670
_08008320: .4byte 0x085AA678
_08008324: .4byte 0xFFFF0000
_08008328: .4byte 0x00002001

	thumb_func_start FUN_0800832c
FUN_0800832c: @ 0x0800832C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x28
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	beq _08008342
	subs r0, #1
	strh r0, [r4, #0xa]
	b _08008388
_08008342:
	adds r6, r4, #0
	adds r6, #0x54
	add r7, sp, #0x10
	ldrh r0, [r4, #0x26]
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	add r3, sp, #0xc
	bl FUN_08234e78
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08008374
	adds r0, r5, #0
	bl FUN_08234e3c
	ldr r0, [r5, #8]
	ldrh r1, [r0, #4]
	ldr r0, _08008390 @ =0x00000FFF
	ands r0, r1
	strh r0, [r4, #0xa]
_08008374:
	ldrh r0, [r7]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r7, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08008388:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008390: .4byte 0x00000FFF

	thumb_func_start FUN_08008394
FUN_08008394: @ 0x08008394
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x20]
	cmp r3, #0
	beq _080083B8
	ldrh r1, [r3]
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r2, #6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x58
	strh r1, [r0]
_080083B8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080083bc
FUN_080083bc: @ 0x080083BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	movs r1, #0
	mov r8, r1
	ldr r1, [r7, #0x18]
	cmp r8, r1
	bhs _080084AC
	adds r6, r4, #0
	adds r6, #0x94
_080083D4:
	ldrb r1, [r4]
	adds r5, r4, #0
	adds r5, #0x9a
	cmp r1, #0
	beq _0800849E
	ldr r2, [r4, #0x14]
	cmp r2, #0
	blt _08008414
	ldr r1, _080083F8 @ =0x030046A0
	ldr r1, [r1]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r1, r3
	ldr r1, [r1]
	cmp r1, r2
	bne _080083FC
	movs r1, #1
	b _080083FE
	.align 2, 0
_080083F8: .4byte 0x030046A0
_080083FC:
	movs r1, #0
_080083FE:
	cmp r1, #0
	bne _08008414
	ldr r1, [r4, #0x3c]
	movs r2, #1
	orrs r1, r2
	str r1, [r4, #0x3c]
	ldrh r2, [r6, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r6, #6]
	b _0800849E
_08008414:
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	ldrh r0, [r6, #6]
	ldr r2, _08008448 @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _0800844C @ =0x085AA67C
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08008450
	adds r0, r4, #0
	bl FUN_0800832c
	b _0800845A
	.align 2, 0
_08008448: .4byte 0x0000FFFB
_0800844C: .4byte 0x085AA67C
_08008450:
	cmp r0, #2
	bne _0800845A
	adds r0, r4, #0
	bl FUN_08008394
_0800845A:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, [r6, #0x50]
	bl FUN_082372cc
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08008498
	subs r1, #1
	strb r1, [r4, #5]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008490
	ldrh r1, [r5]
	ldr r3, _0800848C @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008496
	.align 2, 0
_0800848C: .4byte 0x0000FFFB
_08008490:
	ldrh r2, [r5]
	movs r1, #4
	orrs r1, r2
_08008496:
	strh r1, [r5]
_08008498:
	ldr r1, [r4, #0xc]
	adds r1, #1
	str r1, [r4, #0xc]
_0800849E:
	movs r1, #1
	add r8, r1
	adds r6, #0xe8
	adds r4, #0xe8
	ldr r1, [r7, #0x18]
	cmp r8, r1
	blo _080083D4
_080084AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080084b8
FUN_080084b8: @ 0x080084B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _080084DC
_080084C2:
	ldrb r1, [r4]
	cmp r1, #0
	beq _080084D8
	adds r0, r4, #0
	adds r0, #0x94
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x34
	bl FUN_0822f1c0
_080084D8:
	adds r5, #1
	adds r4, #0xe8
_080084DC:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _080084C2
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _080084F2
	adds r0, r1, #0
	bl Free
	movs r1, #0
	str r1, [r6, #0x1c]
_080084F2:
	ldr r2, _08008500 @ =0x03000034
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08008500: .4byte 0x03000034

	thumb_func_start FUN_08008504
FUN_08008504: @ 0x08008504
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08008538 @ =0x03000034
	str r6, [r0]
	movs r5, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	mov sb, r6
_0800851C:
	ldr r0, _0800853C @ =0x085AA66C
	lsls r1, r5, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, _08008540 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008544
	movs r0, #1
	rsbs r0, r0, #0
	b _080085A2
	.align 2, 0
_08008538: .4byte 0x03000034
_0800853C: .4byte 0x085AA66C
_08008540: .4byte 0x0000CB05
_08008544:
	mov r1, sb
	adds r1, #0x20
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl FUN_0822f284
	movs r7, #0x20
	add r8, r7
	movs r0, #0x20
	add sb, r0
	adds r5, #1
	cmp r5, #1
	ble _0800851C
	movs r0, #0x6e
	movs r1, #8
	bl Script_GetKeywordValue
	str r0, [r6, #0x18]
	movs r1, #0xe8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r6, #0x1c]
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _0800859C
_08008590:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08007f84
	adds r5, #1
	adds r4, #0xe8
_0800859C:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _08008590
_080085A2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080085b0
FUN_080085b0: @ 0x080085B0
	push {r4, lr}
	ldr r0, _080085E4 @ =0x03000034
	ldr r0, [r0]
	cmp r0, #0
	bne _080085F2
	movs r0, #0xa
	movs r1, #0x60
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080085F0
	ldr r1, _080085E8 @ =FUN_080083bc
	ldr r2, _080085EC @ =FUN_080084b8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08008504
	cmp r0, #0
	bge _080085F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080085F2
	.align 2, 0
_080085E4: .4byte 0x03000034
_080085E8: .4byte FUN_080083bc
_080085EC: .4byte FUN_080084b8
_080085F0:
	adds r0, r4, #0
_080085F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080085f8
FUN_080085f8: @ 0x080085F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _080086C8 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _080086C2
	adds r0, r7, #0
	bl FUN_08007f00
	adds r6, r0, #0
	cmp r6, #0
	beq _080086C2
	movs r0, #0
	strb r0, [r6, #1]
	movs r4, #0
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0800866A
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r0, #0x28
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08234de8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080086C2
	movs r0, #1
	strb r0, [r6, #1]
	ldr r0, [r6, #0x30]
	ldrh r1, [r0, #4]
	ldr r0, _080086CC @ =0x00000FFF
	ands r0, r1
	strh r0, [r6, #0xa]
	bl Script_GetValue
	strh r0, [r6, #0x24]
	bl Script_GetValue
	strh r0, [r6, #0x26]
	ldr r1, [r6, #0x30]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	movs r4, #1
_0800866A:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0800869C
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl FUN_081d553c
	adds r1, r0, #0
	str r1, [r6, #0x20]
	cmp r1, #0
	beq _080086C2
	movs r0, #2
	strb r0, [r6, #1]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r4, #1
_0800869C:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080086BE
	bl Script_GetValue
	add r1, sp, #4
	strh r0, [r1]
	bl Script_GetValue
	add r4, sp, #4
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	movs r4, #1
_080086BE:
	cmp r4, #0
	bne _080086D0
_080086C2:
	movs r0, #1
	rsbs r0, r0, #0
	b _08008860
	.align 2, 0
_080086C8: .4byte 0x03000034
_080086CC: .4byte 0x00000FFF
_080086D0:
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08007f28
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x64
	movs r1, #0x78
	bl Script_GetKeywordValue
	strh r0, [r6, #8]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x10]
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x18]
	adds r4, r6, #0
	adds r4, #0xe4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r7, r0
	str r0, [r4]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x12]
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x1c]
	ldrb r0, [r6, #1]
	adds r7, r4, #0
	cmp r0, #2
	beq _080087B8
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08008758
	cmp r1, #0
	blt _08008758
	ldr r0, _0800875C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08008758
	ldr r0, _08008760 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08008764
_08008758:
	movs r4, #0
	b _08008772
	.align 2, 0
_0800875C: .4byte 0x030046A8
_08008760: .4byte 0x030046AC
_08008764:
	ldr r0, _08008784 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08008772:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08008788
	adds r0, #4
	b _08008794
	.align 2, 0
_08008784: .4byte 0x030046A4
_08008788:
	ldr r0, _080087A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08008794:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080087AC
	cmp r2, #2
	beq _080087B0
	b _080087B4
	.align 2, 0
_080087A8: .4byte 0x030046A4
_080087AC:
	ldrb r0, [r5, #4]
	b _080087B2
_080087B0:
	ldrb r0, [r5]
_080087B2:
	subs r1, r1, r0
_080087B4:
	add r0, sp, #4
	strh r1, [r0, #2]
_080087B8:
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080087CC
	add r0, sp, #4
	bl FUN_08241574
	b _080087D0
_080087CC:
	movs r0, #1
	rsbs r0, r0, #0
_080087D0:
	str r0, [r6, #0x14]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _08008824
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _0800881C @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08008820 @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r4, #0
	bl FUN_0822f63c
	b _08008852
	.align 2, 0
_0800881C: .4byte 0x085AA670
_08008820: .4byte 0x085AA678
_08008824:
	adds r4, r6, #0
	adds r4, #0x34
	ldr r1, [r7]
	ldr r2, _08008868 @ =0x085AA670
	ldr r0, [r6, #0x18]
	lsls r0, r0, #2
	adds r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _0800886C @ =0x085AA678
	ldr r0, [r6, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0822f63c
_08008852:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a3f0
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
_08008860:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008868: .4byte 0x085AA670
_0800886C: .4byte 0x085AA678

	thumb_func_start FUN_08008870
FUN_08008870: @ 0x08008870
	push {r4, r5, lr}
	ldr r0, _08008898 @ =0x03000034
	ldr r4, [r0]
	cmp r4, #0
	beq _080088B4
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl Script_GetKeywordValue
	adds r3, r0, #0
	ldr r1, [r4, #0x1c]
	movs r2, #0
	b _080088AE
	.align 2, 0
_08008898: .4byte 0x03000034
_0800889C:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080088AA
	ldrh r0, [r1, #0x10]
	cmp r0, r5
	bne _080088AA
	strh r3, [r1, #8]
_080088AA:
	adds r2, #1
	adds r1, #0xe8
_080088AE:
	ldr r0, [r4, #0x18]
	cmp r2, r0
	blo _0800889C
_080088B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080088bc
FUN_080088bc: @ 0x080088BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080088F0 @ =0x03000034
	ldr r7, [r0]
	cmp r7, #0
	beq _08008912
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x6d
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	cmp r6, r4
	beq _08008912
	cmp r6, #4
	bgt _08008912
	ldr r4, [r7, #0x1c]
	movs r5, #0
	b _0800890C
	.align 2, 0
_080088F0: .4byte 0x03000034
_080088F4:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08008908
	ldrh r0, [r4, #0x10]
	cmp r0, r8
	bne _08008908
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08007f28
_08008908:
	adds r5, #1
	adds r4, #0xe8
_0800890C:
	ldr r0, [r7, #0x18]
	cmp r5, r0
	blo _080088F4
_08008912:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800891c
FUN_0800891c: @ 0x0800891C
	movs r2, #0
	strb r1, [r0, #1]
	str r2, [r0, #4]
	movs r1, #1
	strb r1, [r0, #2]
	bx lr

	thumb_func_start FUN_08008928
FUN_08008928: @ 0x08008928
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08008936
	movs r0, #0
	b _0800893C
_08008936:
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #1
_0800893C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08008940
FUN_08008940: @ 0x08008940
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r2, #0
	ldr r0, _08008980 @ =0x03000038
	ldr r5, [r0]
	cmp r5, #0
	beq _080089B0
	ldrb r4, [r6, #1]
	cmp r4, #0
	bne _08008984
	movs r1, #4
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0800891c
	movs r1, #1
	adds r0, r1, #0
	ldrb r2, [r6]
	lsls r0, r2
	ldrh r2, [r5, #0x34]
	orrs r0, r2
	strh r0, [r5, #0x34]
	ldrb r6, [r6]
	lsls r1, r6
	ldrh r0, [r5, #0x38]
	orrs r1, r0
	strh r1, [r5, #0x38]
	b _080089B0
	.align 2, 0
_08008980: .4byte 0x03000038
_08008984:
	cmp r4, #1
	bne _080089B0
	movs r1, #8
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080089B0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0800891c
	adds r0, r4, #0
	ldrb r1, [r6]
	lsls r0, r1
	ldrh r1, [r5, #0x36]
	orrs r0, r1
	strh r0, [r5, #0x36]
	ldrb r6, [r6]
	lsls r4, r6
	ldrh r0, [r5, #0x38]
	orrs r4, r0
	strh r4, [r5, #0x38]
_080089B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080089b8
FUN_080089b8: @ 0x080089B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	movs r4, #0
	strb r7, [r1]
	mov r0, r8
	movs r1, #0
	bl FUN_0800891c
	mov r0, r8
	strb r4, [r0, #3]
	mov r5, r8
	adds r5, #0x58
	mov r6, sb
	adds r6, #0x4c
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	adds r0, #0x44
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
	subs r5, #0x50
	subs r0, r7, #1
	cmp r0, #1
	bhi _08008A3C
	ldr r2, _08008A34 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08008A38 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x60
	b _08008A58
	.align 2, 0
_08008A34: .4byte 0xFFFF0000
_08008A38: .4byte 0x0000FFFF
_08008A3C:
	ldr r2, _08008AD4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _08008AD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x18
_08008A58:
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, _08008ADC @ =0x085AA690
	lsls r2, r7, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r0, #0x10
	lsls r0, r0, #0x10
	ldr r4, _08008AD4 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _08008AE0 @ =0x085AA698
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldr r2, _08008AE4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08008AE8 @ =FUN_08008940
	adds r0, r5, #0
	mov r2, r8
	bl FUN_0823651c
	mov r1, sb
	adds r1, #0x3c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008AD4: .4byte 0xFFFF0000
_08008AD8: .4byte 0x0000FFFF
_08008ADC: .4byte 0x085AA690
_08008AE0: .4byte 0x085AA698
_08008AE4: .4byte 0x00004001
_08008AE8: .4byte FUN_08008940

	thumb_func_start FUN_08008aec
FUN_08008aec: @ 0x08008AEC
	push {r4, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r4, r1, #0
	ldrh r0, [r3, #0x1a]
	cmp r0, #0
	beq _08008B5C
	str r2, [sp]
	cmp r4, #1
	bne _08008B12
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0xf
	beq _08008B28
	movs r0, #0
	str r0, [sp, #8]
	b _08008B2A
_08008B12:
	cmp r4, #0
	bne _08008B2A
	str r4, [sp, #4]
	ldrh r1, [r3, #0x1c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08008B28
	movs r0, #1
	str r0, [sp, #8]
	b _08008B2A
_08008B28:
	str r4, [sp, #8]
_08008B2A:
	ldrh r0, [r3, #0x38]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0x24]
	str r0, [sp, #0x10]
	ldr r0, [r3, #0x28]
	str r0, [sp, #0x14]
	ldr r0, [r3, #0x2c]
	str r0, [sp, #0x18]
	ldr r0, [r3, #0x30]
	str r0, [sp, #0x1c]
	ldr r1, _08008B64 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r3, #0x1a]
	bl Script_ExecById
_08008B5C:
	add sp, #0x28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08008B64: .4byte 0xFFFF0000

	thumb_func_start FUN_08008b68
FUN_08008b68: @ 0x08008B68
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008BF0
	ldr r0, [r5, #0x60]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x60]
	ldrb r0, [r5]
	lsls r1, r0
	ldrh r0, [r6, #0x1c]
	bics r0, r1
	movs r3, #0
	strh r0, [r6, #0x1c]
	ldr r1, _08008BF8 @ =0x085AA690
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x3c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08008BFC @ =0xFFFF0000
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r2, [r6, #0x3e]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r2, r6, #0
	adds r2, #0x40
	ldr r1, _08008C00 @ =0x085AA698
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r2, _08008C04 @ =0x00002001
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	movs r0, #2
	str r0, [sp, #0x14]
	add r0, sp, #0x1c
	str r0, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015ce0
_08008BF0:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008BF8: .4byte 0x085AA690
_08008BFC: .4byte 0xFFFF0000
_08008C00: .4byte 0x085AA698
_08008C04: .4byte 0x00002001

	thumb_func_start FUN_08008c08
FUN_08008c08: @ 0x08008C08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08008928
	cmp r0, #0
	beq _08008C2E
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	movs r0, #1
	ldrb r1, [r4]
	lsls r0, r1
	ldrh r1, [r5, #0x1c]
	orrs r0, r1
	strh r0, [r5, #0x1c]
_08008C2E:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x4c
	bl FUN_082372cc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08008c48
FUN_08008c48: @ 0x08008C48
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08008C94 @ =0x030047A4
	ldr r1, _08008C98 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08008C6E
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08009064
_08008C6E:
	adds r5, r6, #0
	adds r5, #0x44
	adds r2, r6, #0
	adds r2, #0x3c
	ldrh r0, [r6, #0x3c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r2, #0
	cmp r0, #0
	blt _08008C9C
	asrs r0, r0, #8
	b _08008CA2
	.align 2, 0
_08008C94: .4byte 0x030047A4
_08008C98: .4byte 0x030047A0
_08008C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CA2:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008CB4
	asrs r0, r0, #8
	b _08008CBA
_08008CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CBA:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008CCE
	asrs r0, r0, #8
	b _08008CD4
_08008CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CD4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08008D30 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r4, r6, #0
	adds r4, #0xcc
	movs r5, #3
_08008CF8:
	ldr r1, _08008D34 @ =0x085AA6A0
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	adds r0, #8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	ldrb r1, [r4, #3]
	cmp r1, #0
	beq _08008D44
	subs r1, #1
	strb r1, [r4, #3]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008D3C
	ldrh r1, [r4, #0xe]
	ldr r3, _08008D38 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008D42
	.align 2, 0
_08008D30: .4byte 0x030047C8
_08008D34: .4byte 0x085AA6A0
_08008D38: .4byte 0x0000FFFB
_08008D3C:
	ldrh r2, [r4, #0xe]
	movs r1, #4
	orrs r1, r2
_08008D42:
	strh r1, [r4, #0xe]
_08008D44:
	ldr r1, [r4, #4]
	adds r1, #1
	str r1, [r4, #4]
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008CF8
	movs r5, #4
	ldrh r2, [r6, #0x1c]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xf
	bne _08008DC4
	ldr r0, [r6, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x6c
	adds r1, r6, #0
	adds r1, #0x4c
	bl FUN_082372cc
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	str r1, [r3]
	str r2, [r3, #4]
	adds r1, r6, #0
	adds r1, #0x89
	ldrb r1, [r1]
	ands r5, r1
	cmp r5, #0
	beq _08008DD6
	movs r0, #0x10
	str r0, [sp]
	ldr r2, _08008DBC @ =0x085AA6A8
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #2
	mov r3, sp
	bl FUN_08000fac
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, _08008DC0 @ =0x03003E78
	ldrh r2, [r3]
	orrs r1, r2
	strh r1, [r3]
	b _08008DD6
	.align 2, 0
_08008DBC: .4byte 0x085AA6A8
_08008DC0: .4byte 0x03003E78
_08008DC4:
	ldr r3, _08008E34 @ =0x03003E78
	ldr r1, _08008E38 @ =0xFFFFFDFF
	ldrh r2, [r3]
	ands r1, r2
	strh r1, [r3]
	ldr r1, [r6, #0x74]
	movs r2, #1
	orrs r1, r2
	str r1, [r6, #0x74]
_08008DD6:
	ldrh r1, [r6, #0x34]
	cmp r1, #0
	beq _08008E00
	ldr r0, _08008E3C @ =0x0000014B
	bl PlaySound_082406e0
	movs r5, #0
_08008DE4:
	ldrh r1, [r6, #0x34]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008DFA
	adds r0, r6, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_08008aec
_08008DFA:
	adds r5, #1
	cmp r5, #3
	ble _08008DE4
_08008E00:
	ldrh r1, [r6, #0x36]
	cmp r1, #0
	beq _08008E24
	movs r5, #0
_08008E08:
	ldrh r1, [r6, #0x36]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008E1E
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08008aec
_08008E1E:
	adds r5, #1
	cmp r5, #3
	ble _08008E08
_08008E24:
	movs r1, #0
	strh r1, [r6, #0x34]
	strh r1, [r6, #0x36]
	strh r1, [r6, #0x38]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008E34: .4byte 0x03003E78
_08008E38: .4byte 0xFFFFFDFF
_08008E3C: .4byte 0x0000014B

	thumb_func_start FUN_08008e40
FUN_08008e40: @ 0x08008E40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x6c
	bl FUN_0822f1c0
	adds r4, #0xcc
	movs r5, #3
_08008E4E:
	adds r0, r4, #0
	adds r0, #8
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x58
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008E4E
	ldr r2, _08008E74 @ =0x03000038
	movs r1, #0
	str r1, [r2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08008E74: .4byte 0x03000038

	thumb_func_start FUN_08008e78
FUN_08008e78: @ 0x08008E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08008EA0 @ =0x03000038
	str r7, [r0]
	ldr r0, _08008EA4 @ =0x0000CB05
	ldr r1, _08008EA8 @ =0x0000F099
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008EAC
	movs r0, #1
	rsbs r0, r0, #0
	b _08009000
	.align 2, 0
_08008EA0: .4byte 0x03000038
_08008EA4: .4byte 0x0000CB05
_08008EA8: .4byte 0x0000F099
_08008EAC:
	adds r1, r7, #0
	adds r1, #0x4c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x4c
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822f284
	movs r4, #0
	movs r5, #0
	mov r0, r8
	strh r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x1a]
	strh r5, [r7, #0x1c]
	strb r4, [r7, #0x1e]
	strb r4, [r7, #0x1f]
	str r5, [r7, #0x20]
	movs r0, #0x61
	bl prepare_08231510
	str r6, [sp, #0x10]
	subs r6, #0xc
	movs r1, #0x44
	adds r1, r1, r7
	mov sb, r1
	movs r3, #0x3c
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x6c
	adds r4, r4, r7
	mov sl, r4
	adds r5, r7, #0
	adds r5, #0xcc
	str r5, [sp, #0x14]
	cmp r0, #0
	beq _08008F24
	subs r5, #0xa8
	movs r4, #3
_08008F0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08008F1C
	bl Script_GetValue
	str r0, [r5]
_08008F1C:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08008F0E
_08008F24:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _08008F40
	bl Script_GetValue
	strh r0, [r7, #0x3c]
	bl Script_GetValue
	strh r0, [r7, #0x3e]
	bl Script_GetValue
	b _08008F44
_08008F40:
	strh r0, [r7, #0x3c]
	strh r0, [r7, #0x3e]
_08008F44:
	strh r0, [r6]
	mov r6, sb
	mov r5, r8
	ldrh r0, [r7, #0x3c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F66
	asrs r0, r0, #8
	b _08008F6C
_08008F66:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F6C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F7E
	asrs r0, r0, #8
	b _08008F84
_08008F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F84:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008F98
	asrs r0, r0, #8
	b _08008F9E
_08008F98:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F9E:
	subs r2, r4, r0
	movs r5, #0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _08009010 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	str r5, [sp]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #6
	movs r3, #1
	bl FUN_082370cc
	ldr r5, [sp, #0x14]
	movs r4, #0
_08008FEE:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080089b8
	adds r4, #1
	adds r5, #0xb8
	cmp r4, #3
	ble _08008FEE
_08009000:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009010: .4byte 0x030047C8

	thumb_func_start FUN_08009014
FUN_08009014: @ 0x08009014
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08009050 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _0800905E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800905C
	ldr r1, _08009054 @ =FUN_08008c48
	ldr r2, _08009058 @ =FUN_08008e40
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08008e78
	cmp r0, #0
	bge _0800905C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800905E
	.align 2, 0
_08009050: .4byte 0x03000038
_08009054: .4byte FUN_08008c48
_08009058: .4byte FUN_08008e40
_0800905C:
	adds r0, r4, #0
_0800905E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009064
FUN_08009064: @ 0x08009064
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r1, _08009080 @ =0x03000038
	ldr r4, [r1]
	cmp r4, #0
	bne _08009084
	movs r0, #1
	rsbs r0, r0, #0
	b _08009116
	.align 2, 0
_08009080: .4byte 0x03000038
_08009084:
	cmp r6, #0
	bge _080090D6
	adds r5, r4, #0
	adds r5, #0xcc
	movs r6, #0
	movs r3, #1
_08009090:
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _080090CC
	adds r0, r5, #0
	adds r1, r7, #0
	str r3, [sp]
	bl FUN_0800891c
	ldr r3, [sp]
	cmp r7, #0
	bne _080090B2
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _080090BC
_080090B2:
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_080090BC:
	mov r1, r8
	cmp r1, #0
	beq _080090CC
	adds r1, r3, #0
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_080090CC:
	adds r6, #1
	adds r5, #0xb8
	cmp r6, #3
	ble _08009090
	b _08009116
_080090D6:
	movs r1, #0xb8
	muls r1, r6, r1
	adds r1, #0xcc
	adds r5, r4, r1
	ldrb r1, [r5, #1]
	cmp r1, r7
	beq _08009116
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0800891c
	cmp r7, #0
	bne _080090FC
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x36]
	orrs r1, r2
	strh r1, [r4, #0x36]
	b _08009106
_080090FC:
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x34]
	orrs r1, r2
	strh r1, [r4, #0x34]
_08009106:
	mov r1, r8
	cmp r1, #0
	beq _08009116
	movs r1, #1
	lsls r1, r6
	ldrh r2, [r4, #0x38]
	orrs r1, r2
	strh r1, [r4, #0x38]
_08009116:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009124
FUN_08009124: @ 0x08009124
	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x69
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009064
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009154
FUN_08009154: @ 0x08009154
	push {lr}
	ldr r0, _08009164 @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _08009168
	movs r0, #1
	rsbs r0, r0, #0
	b _08009188
	.align 2, 0
_08009164: .4byte 0x03000038
_08009168:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_08009170:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _08009178
	adds r3, #1
_08009178:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _08009170
	movs r0, #0
	cmp r3, #4
	bne _08009188
	movs r0, #1
_08009188:
	pop {r1}
	bx r1

	thumb_func_start FUN_0800918c
FUN_0800918c: @ 0x0800918C
	push {lr}
	ldr r0, _0800919C @ =0x03000038
	ldr r0, [r0]
	cmp r0, #0
	bne _080091A0
	movs r0, #1
	rsbs r0, r0, #0
	b _080091C0
	.align 2, 0
_0800919C: .4byte 0x03000038
_080091A0:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0xcc
	movs r2, #3
_080091A8:
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _080091B0
	adds r3, #1
_080091B0:
	subs r2, #1
	adds r1, #0xb8
	cmp r2, #0
	bge _080091A8
	movs r0, #0
	cmp r3, #0
	bne _080091C0
	movs r0, #1
_080091C0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080091c4
FUN_080091c4: @ 0x080091C4
	adds r2, r0, #0
	strb r1, [r2, #5]
	movs r1, #1
	strb r1, [r2, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080091d0
FUN_080091d0: @ 0x080091D0
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _080091DE
	movs r0, #0
	b _080091E4
_080091DE:
	movs r0, #0
	strb r0, [r1, #6]
	movs r0, #1
_080091E4:
	pop {r1}
	bx r1

	thumb_func_start FUN_080091e8
FUN_080091e8: @ 0x080091E8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x50
	ldr r1, _0800921C @ =0x0000A850
	adds r0, r6, #0
	bl FUN_0822b16c
	cmp r0, #0
	beq _08009220
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r4, #0x10]
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	movs r0, #0
	b _08009224
	.align 2, 0
_0800921C: .4byte 0x0000A850
_08009220:
	movs r0, #1
	rsbs r0, r0, #0
_08009224:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800922c
FUN_0800922c: @ 0x0800922C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	cmp r2, #0
	beq _0800923C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
_0800923C:
	ldr r3, [r4, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	bge _0800926E
	movs r7, #1
	ldr r5, [r4, #0x1c]
	adds r4, r0, #0
_0800924C:
	adds r0, r7, #0
	lsls r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08009266
	ldrh r0, [r3]
	cmp r0, r6
	bne _08009266
	cmp r2, #0
	beq _08009262
	str r1, [r2]
_08009262:
	adds r0, r3, #0
	b _08009270
_08009266:
	adds r1, #1
	adds r3, #0x6c
	cmp r1, r4
	blt _0800924C
_0800926E:
	movs r0, #0
_08009270:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009278
FUN_08009278: @ 0x08009278
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r1, [r2, #4]
	cmp r1, #0
	bne _08009292
	adds r1, r3, #0
	adds r1, #0x4c
	adds r0, r4, #0
	bl FUN_0822b20c
_08009292:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009298
FUN_08009298: @ 0x08009298
	push {r4, lr}
	adds r3, r1, #0
	adds r4, r3, #0
	adds r4, #0x24
	ldrh r1, [r2]
	strh r1, [r3, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r3, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r3, #0x20]
	ldrh r1, [r2]
	strh r1, [r4, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r4, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r4, #0x20]
	ldrb r1, [r3, #2]
	cmp r1, #0
	beq _080092CC
	ldrh r1, [r3, #0x1c]
	adds r1, #0x80
	strh r1, [r3, #0x1c]
	ldrh r1, [r4, #0x20]
	subs r1, #0x80
	strh r1, [r4, #0x20]
	b _080092D8
_080092CC:
	ldrh r1, [r3, #0x20]
	adds r1, #0x80
	strh r1, [r3, #0x20]
	ldrh r1, [r4, #0x1c]
	subs r1, #0x80
	strh r1, [r4, #0x1c]
_080092D8:
	ldrh r1, [r4, #0x1c]
	adds r1, #0x3c
	strh r1, [r4, #0x1c]
	ldrh r1, [r4, #0x20]
	adds r1, #0x3c
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x1e]
	adds r1, #0x14
	strh r1, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080092f0
FUN_080092f0: @ 0x080092F0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _0800935C
	ldrb r0, [r4, #5]
	cmp r0, #1
	beq _08009330
	cmp r0, #1
	bgt _0800930A
	cmp r0, #0
	beq _08009310
	b _0800935C
_0800930A:
	cmp r0, #2
	beq _08009350
	b _0800935C
_08009310:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08009320
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08009278
	b _0800935C
_08009320:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	subs r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009330:
	ldrb r0, [r4, #7]
	cmp r0, #4
	bls _08009340
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
	b _0800935C
_08009340:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	adds r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009350:
	movs r0, #5
	strb r0, [r4, #7]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
_0800935C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009364
FUN_08009364: @ 0x08009364
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x24]
	ldr r1, _0800938C @ =0x0000186C
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08009390
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08009390
	movs r0, #0x19
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08009390
	movs r0, #1
	b _08009392
	.align 2, 0
_0800938C: .4byte 0x0000186C
_08009390:
	movs r0, #0
_08009392:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009398
FUN_08009398: @ 0x08009398
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r2, #0
	cmp r5, #0
	beq _080093D4
	ldrh r0, [r1]
	str r0, [sp]
	movs r3, #0
	add r4, sp, #0x14
	adds r1, #0x14
	add r2, sp, #4
_080093AE:
	movs r6, #0
	ldrsh r0, [r1, r6]
	stm r2!, {r0}
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _080093AE
	ldr r0, _080093DC @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_080093D4:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080093DC: .4byte 0xFFFF0000

	thumb_func_start FUN_080093e0
FUN_080093e0: @ 0x080093E0
	adds r2, r0, #0
	movs r3, #0
	strb r1, [r2, #0x19]
	strb r3, [r2, #0x1a]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080093ec
FUN_080093ec: @ 0x080093EC
	adds r2, r0, #0
	strb r1, [r2, #0x19]
	movs r1, #1
	strb r1, [r2, #0x1a]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080093f8
FUN_080093f8: @ 0x080093F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _080094A4
	movs r0, #6
	ldr r1, _08009468 @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080094A4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080094A4
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x28
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r5, r3]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	ldr r0, [r5, #0x10]
	cmp r4, r0
	bhs _080094A4
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0800946C
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009472
	.align 2, 0
_08009468: .4byte 0x03002BC0
_0800946C:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009472:
	cmp r2, r1
	beq _0800947E
	cmp r3, r1
	beq _0800947E
	cmp r4, r1
	bne _080094A4
_0800947E:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _08009498
	cmp r3, r0
	beq _08009498
	cmp r4, r0
	beq _08009498
	movs r1, #0
_08009498:
	cmp r1, #0
	beq _080094A4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080091c4
_080094A4:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080094ac
FUN_080094ac: @ 0x080094AC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _0800958C
	movs r0, #6
	ldr r1, _0800951C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0800958C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0800958C
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x28
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r5, r3]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	ldr r0, [r5, #0x10]
	cmp r4, r0
	bhs _0800958C
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _08009520
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009526
	.align 2, 0
_0800951C: .4byte 0x03002BC0
_08009520:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009526:
	cmp r2, r1
	beq _08009532
	cmp r3, r1
	beq _08009532
	cmp r4, r1
	bne _0800958C
_08009532:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _0800954C
	cmp r3, r0
	beq _0800954C
	cmp r4, r0
	beq _0800954C
	movs r1, #0
_0800954C:
	cmp r1, #0
	beq _0800958C
	ldr r0, _08009588 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08009594
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08009364
	cmp r0, #0
	beq _08009594
	movs r0, #5
	strb r0, [r5, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08009278
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080091c4
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080093e0
	b _08009594
	.align 2, 0
_08009588: .4byte 0x030044E0
_0800958C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080091c4
_08009594:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800959c
FUN_0800959c: @ 0x0800959C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	bl FUN_080091d0
	ldr r0, [r7, #0x24]
	cmp r0, #0
	beq _08009640
	movs r0, #6
	ldr r1, _0800960C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08009640
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08009640
	movs r1, #0x1c
	ldrsh r0, [r6, r1]
	movs r2, #0x28
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r6, r3]
	movs r3, #0x2c
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r2, r1, #3
	movs r1, #7
	ands r2, r1
	ldr r1, [r6, #0x10]
	cmp r4, r1
	bhs _08009640
	ldrb r1, [r6, #2]
	cmp r1, #0
	beq _08009610
	movs r3, #0
	movs r4, #1
	movs r5, #2
	b _08009616
	.align 2, 0
_0800960C: .4byte 0x03002BC0
_08009610:
	movs r3, #6
	movs r4, #7
	movs r5, #0
_08009616:
	cmp r3, r2
	beq _08009622
	cmp r4, r2
	beq _08009622
	cmp r5, r2
	bne _08009640
_08009622:
	ldr r1, [r7, #0x24]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #1
	cmp r3, r1
	beq _0800963C
	cmp r4, r1
	beq _0800963C
	cmp r5, r1
	beq _0800963C
	movs r2, #0
_0800963C:
	cmp r2, #0
	bne _0800964A
_08009640:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080091c4
	movs r0, #0
_0800964A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009650
FUN_08009650: @ 0x08009650
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08009662
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x28]
	str r1, [r5, #0x2c]
_08009662:
	ldr r4, [r5, #0x20]
	movs r6, #0
	b _080096DA
_08009668:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _080096D6
	ldr r1, [r4, #8]
	cmp r1, #0
	blt _080096AA
	ldr r0, _08009690 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, r1
	bne _08009694
	movs r0, #1
	b _08009696
	.align 2, 0
_08009690: .4byte 0x030046A0
_08009694:
	movs r0, #0
_08009696:
	cmp r0, #0
	bne _080096AA
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096D6
	ldr r0, [r4, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x24]
	b _080096D6
_080096AA:
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _080096BA
	ldr r0, [r4, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x24]
_080096BA:
	ldr r0, _08009714 @ =0x085AA6AC
	ldrb r1, [r4, #5]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r3, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080092f0
_080096D6:
	adds r6, #1
	adds r4, #0x6c
_080096DA:
	ldrb r0, [r5, #0x18]
	cmp r6, r0
	blt _08009668
	ldrb r3, [r5, #0x1a]
	movs r2, #0x1a
	ldrsb r2, [r5, r2]
	cmp r2, #0
	blt _08009734
	ldrb r6, [r5, #0x19]
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _08009734
	adds r1, r0, #0
	movs r0, #0x6c
	muls r1, r0, r1
	ldr r0, [r5, #0x20]
	adds r4, r0, r1
	cmp r2, #0
	bne _08009718
	movs r0, #0xff
	strb r0, [r5, #0x1a]
	ldrh r2, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
	b _08009734
	.align 2, 0
_08009714: .4byte 0x085AA6AC
_08009718:
	cmp r2, #1
	bne _08009734
	movs r1, #0xff
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r5, #0x1a]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r5, #0x19]
	ldrh r2, [r4, #0xe]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08009398
_08009734:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800973c
FUN_0800973c: @ 0x0800973C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x20]
	movs r5, #0
	b _08009752
_08009746:
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0822a4e0
	adds r5, #1
	adds r4, #0x6c
_08009752:
	ldrb r0, [r6, #0x18]
	cmp r5, r0
	blt _08009746
	ldr r0, [r6, #0x20]
	cmp r0, #0
	beq _08009762
	bl Free
_08009762:
	ldr r1, _08009770 @ =0x0300003C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009770: .4byte 0x0300003C

	thumb_func_start FUN_08009774
FUN_08009774: @ 0x08009774
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080097AC @ =0x0300003C
	str r4, [r0]
	movs r0, #0x6e
	movs r1, #1
	bl Script_GetKeywordValue
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #0xff
	strb r0, [r4, #0x19]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0x18]
	movs r5, #0x6c
	muls r0, r5, r0
	bl Malloc
	adds r2, r0, #0
	str r2, [r4, #0x20]
	cmp r2, #0
	bne _080097B0
_080097A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _080097FC
	.align 2, 0
_080097AC: .4byte 0x0300003C
_080097B0:
	ldrb r0, [r4, #0x18]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r0, r2, #0
	bl ClearMemory
	ldr r6, [r4, #0x20]
	movs r5, #0
	b _080097D4
_080097C2:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080091e8
	cmp r0, #0
	blt _080097A6
	adds r5, #1
	adds r6, #0x6c
_080097D4:
	ldrb r0, [r4, #0x18]
	cmp r5, r0
	blt _080097C2
	ldr r0, _080097F0 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x24]
	cmp r0, #0
	beq _080097F4
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	b _080097FA
	.align 2, 0
_080097F0: .4byte 0x03002BE0
_080097F4:
	strh r0, [r4, #0x28]
	strh r0, [r4, #0x2a]
	strh r0, [r4, #0x2c]
_080097FA:
	movs r0, #0
_080097FC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009804
FUN_08009804: @ 0x08009804
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800983C @ =0x0300003C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800984A
	movs r0, #8
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08009848
	ldr r1, _08009840 @ =FUN_08009650
	ldr r2, _08009844 @ =FUN_0800973c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08009774
	cmp r0, #0
	bge _08009848
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800984A
	.align 2, 0
_0800983C: .4byte 0x0300003C
_08009840: .4byte FUN_08009650
_08009844: .4byte FUN_0800973c
_08009848:
	adds r0, r4, #0
_0800984A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009850
FUN_08009850: @ 0x08009850
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0800990C @ =0x0300003C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _08009868
	b _08009A00
_08009868:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	mov r0, r8
	ldr r5, [r0, #0x20]
	movs r1, #0
	mov sl, r1
	ldrb r3, [r0, #0x18]
	cmp sl, r3
	blt _08009882
	b _080099F4
_08009882:
	mov sb, sp
_08009884:
	movs r1, #1
	mov r0, sl
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08009896
	b _080099E4
_08009896:
	adds r7, r5, #0
	adds r7, #0x24
	movs r4, #0
	strh r2, [r5]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #8]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0xc]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0xe]
	movs r0, #0x44
	movs r1, #0xe6
	bl Script_GetKeywordValue
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	str r0, [r5, #0x10]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08009910
	adds r6, r5, #0
	adds r6, #0x14
	adds r4, r6, #0
_080098F2:
	bl VM_GetPC
	cmp r0, #0
	beq _080098FE
	bl Script_GetValue
_080098FE:
	strh r0, [r4]
	adds r4, #2
	adds r0, r6, #6
	cmp r4, r0
	ble _080098F2
	b _08009922
	.align 2, 0
_0800990C: .4byte 0x0300003C
_08009910:
	adds r1, r5, #0
	adds r1, #0x14
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_0800991A:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800991A
_08009922:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800996C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ldr r2, _08009964 @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08009968 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sb
	ldr r1, [r3, #4]
	ldr r2, _08009964 @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	b _0800997A
	.align 2, 0
_08009964: .4byte 0xFFFF0000
_08009968: .4byte 0x0000FFFF
_0800996C:
	movs r0, #0
	str r0, [sp]
	mov r3, sb
	ldr r0, [r3, #4]
	ldr r1, _08009994 @ =0xFFFF0000
	ands r0, r1
	str r0, [r3, #4]
_0800997A:
	mov r0, r8
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08009298
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _08009998
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_08241574
	b _0800999C
	.align 2, 0
_08009994: .4byte 0xFFFF0000
_08009998:
	movs r0, #1
	rsbs r0, r0, #0
_0800999C:
	str r0, [r5, #8]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08009278
	ldrb r1, [r5, #4]
	cmp r1, #1
	bne _080099B2
	ldr r0, [r7]
	orrs r0, r1
	b _080099BA
_080099B2:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_080099BA:
	str r0, [r7]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080099CC
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _080099D2
_080099CC:
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
_080099D2:
	str r0, [r7]
	movs r1, #1
	mov r3, sl
	lsls r1, r3
	mov r2, r8
	ldr r0, [r2, #0x1c]
	orrs r0, r1
	str r0, [r2, #0x1c]
	b _080099F4
_080099E4:
	movs r3, #1
	add sl, r3
	adds r5, #0x6c
	mov r0, r8
	ldrb r0, [r0, #0x18]
	cmp sl, r0
	bge _080099F4
	b _08009884
_080099F4:
	mov r1, r8
	ldrb r1, [r1, #0x18]
	cmp sl, r1
	beq _08009A00
	movs r0, #0
	b _08009A04
_08009A00:
	movs r0, #1
	rsbs r0, r0, #0
_08009A04:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009a14
FUN_08009a14: @ 0x08009A14
	push {r4, lr}
	ldr r0, _08009A34 @ =0x0300003C
	ldr r4, [r0]
	cmp r4, #0
	beq _08009A2E
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _08009A2E
	adds r1, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	blt _08009A38
_08009A2E:
	movs r0, #1
	rsbs r0, r0, #0
	b _08009A52
	.align 2, 0
_08009A34: .4byte 0x0300003C
_08009A38:
	adds r0, r4, #0
	bl FUN_080093ec
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	movs r0, #0x6c
	muls r1, r0, r1
	ldr r0, [r4, #0x20]
	adds r0, r0, r1
	movs r1, #0
	bl FUN_080091c4
	movs r0, #0
_08009A52:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009a58
FUN_08009a58: @ 0x08009A58
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _08009A84 @ =0x0300003C
	ldr r6, [r0]
	cmp r6, #0
	beq _08009A7C
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0800922c
	adds r5, r0, #0
	cmp r5, #0
	bne _08009A88
_08009A7C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08009AF6
	.align 2, 0
_08009A84: .4byte 0x0300003C
_08009A88:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08009AD0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08009AC8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08009ACC @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _08009ADA
	.align 2, 0
_08009AC8: .4byte 0xFFFF0000
_08009ACC: .4byte 0x0000FFFF
_08009AD0:
	ldr r1, _08009B00 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_08009ADA:
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08009298
	ldr r1, [r5, #8]
	cmp r1, #0
	blt _08009AF6
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_08241574
	adds r1, r0, #0
	str r1, [r5, #8]
_08009AF6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009B00: .4byte 0xFFFF0000

	thumb_func_start FUN_08009b04
FUN_08009b04: @ 0x08009B04
	ldr r1, _08009B0C @ =0x03000040
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08009B0C: .4byte 0x03000040

	thumb_func_start FUN_08009b10
FUN_08009b10: @ 0x08009B10
	push {lr}
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0x2c
_08009B18:
	ldrb r0, [r1, #5]
	cmp r0, #0
	bne _08009B22
	adds r0, r1, #0
	b _08009B2C
_08009B22:
	adds r1, #0x9c
	adds r2, #1
	cmp r2, #0xf
	ble _08009B18
	movs r0, #0
_08009B2C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08009b30
FUN_08009b30: @ 0x08009B30
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08009B64
	movs r0, #0xe0
	lsls r0, r0, #1
	ldr r3, [r3, #0x34]
	ands r3, r0
	cmp r3, #0
	bne _08009B64
	adds r1, r4, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	strb r0, [r2, #2]
	strh r3, [r2, #0xa]
	strb r0, [r2, #7]
	ldrh r1, [r2, #0x1a]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #0x1a]
_08009B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009b6c
FUN_08009b6c: @ 0x08009B6C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r2, _08009BF8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ldr r1, _08009BFC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0xa0
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r2, _08009C00 @ =0x00004020
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08009C04 @ =FUN_08009b30
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	adds r4, #0x50
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #0xc
	bl FUN_0822dafc
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	movs r1, #1
	strb r1, [r5, #5]
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08009BF8: .4byte 0xFFFF0000
_08009BFC: .4byte 0x0000FFFF
_08009C00: .4byte 0x00004020
_08009C04: .4byte FUN_08009b30

	thumb_func_start FUN_08009c08
FUN_08009c08: @ 0x08009C08
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822dabc
	adds r0, r4, #0
	adds r0, #0x14
	bl FUN_08236424
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009c28
FUN_08009c28: @ 0x08009C28
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009C3E
	movs r0, #0
	strb r0, [r2, #7]
	ldr r0, [r2, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x64]
_08009C3E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009c44
FUN_08009c44: @ 0x08009C44
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009CA6
	movs r5, #0
	strb r5, [r6, #7]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08009D20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
_08009CA6:
	ldr r0, [r6, #0x64]
	movs r2, #1
	mov ip, r2
	ands r0, r2
	cmp r0, #0
	beq _08009D24
	ldrh r0, [r6, #0xa]
	adds r1, r0, #1
	strh r1, [r6, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0xc]
	cmp r0, r1
	bhi _08009CC4
	b _08009E20
_08009CC4:
	movs r5, #0
	strh r5, [r6, #0xa]
	ldr r2, _08009D18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08009D1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08009D20 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x78
	strh r0, [r6, #0xc]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x20]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x28]
	str r5, [sp]
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _08009E1E
	.align 2, 0
_08009D18: .4byte 0x030046B8
_08009D1C: .4byte 0x000003FF
_08009D20: .4byte 0x0203B400
_08009D24:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x20]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	mov r1, ip
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, ip
	ands r0, r2
	cmp r1, r0
	beq _08009D6A
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009D72
_08009D6A:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009D72:
	str r0, [r6, #0x64]
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
	beq _08009D96
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009D9E
_08009D96:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009D9E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009DD8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08009E10
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08009DE2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08009DDC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08009DF8
	.align 2, 0
_08009DD8: .4byte 0x0000FFFF
_08009DDC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08009DF6
_08009DE2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08009DF6
	strh r1, [r4, #8]
	movs r2, #1
	b _08009DF8
_08009DF6:
	movs r2, #0
_08009DF8:
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
	b _08009E12
_08009E10:
	movs r2, #0
_08009E12:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _08009E20
	ldr r0, [r6, #0x64]
	movs r1, #1
	orrs r0, r1
_08009E1E:
	str r0, [r6, #0x64]
_08009E20:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08009e28
FUN_08009e28: @ 0x08009E28
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009E36
	movs r0, #0
	strb r0, [r2, #7]
_08009E36:
	ldrh r0, [r2, #0xa]
	adds r1, r0, #1
	strh r1, [r2, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _08009E50
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	strh r1, [r2, #0xa]
	movs r0, #1
	strb r0, [r2, #7]
_08009E50:
	pop {r0}
	bx r0

	thumb_func_start FUN_08009e54
FUN_08009e54: @ 0x08009E54
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08009EA2
	movs r5, #0
	strb r5, [r6, #7]
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r4, r6, #0
	adds r4, #0x64
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r7, #0x24]
	str r5, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08009EA2:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #1
	bne _08009EC0
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EC0
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_08009EC0:
	ldrh r0, [r2]
	cmp r0, #2
	bne _08009EDA
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009EDA
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
_08009EDA:
	ldrh r0, [r2]
	cmp r0, #4
	bne _08009F46
	adds r0, r6, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _08009F46
	ldr r3, _08009F38 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0xa
	orrs r0, r2
	ldr r1, _08009F3C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrb r0, [r6, #4]
	ldrb r2, [r6, #3]
	movs r1, #0x10
	orrs r1, r2
	ldrh r2, [r6, #0xe]
	adds r3, r6, #0
	adds r3, #0x7c
	add r4, sp, #0xc
	str r4, [sp]
	ldrh r4, [r6, #0x10]
	str r4, [sp, #4]
	ldrh r4, [r6, #0x12]
	str r4, [sp, #8]
	bl FUN_0800a8e0
	ldrb r0, [r6, #3]
	cmp r0, #2
	bne _08009F40
	movs r0, #0xae
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08009F46
	.align 2, 0
_08009F38: .4byte 0xFFFF0000
_08009F3C: .4byte 0x0000FFFF
_08009F40:
	ldr r0, _08009F8C @ =0x0000011D
	bl PlaySound_0824078c
_08009F46:
	adds r5, r6, #0
	adds r5, #0x64
	ldr r3, [r7, #0x1c]
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
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
	beq _08009F90
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _08009F98
	.align 2, 0
_08009F8C: .4byte 0x0000011D
_08009F90:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08009F98:
	str r0, [r6, #0x64]
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
	beq _08009FBC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08009FC4
_08009FBC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08009FC4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08009FFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800A034
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800A006
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800A000
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0800A01C
	.align 2, 0
_08009FFC: .4byte 0x0000FFFF
_0800A000:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800A01A
_0800A006:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800A01A
	strh r1, [r4, #8]
	movs r2, #1
	b _0800A01C
_0800A01A:
	movs r2, #0
_0800A01C:
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
	b _0800A036
_0800A034:
	movs r2, #0
_0800A036:
	strb r2, [r6, #8]
	cmp r2, #0
	beq _0800A046
	movs r1, #1
	strb r1, [r6, #6]
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_0800A046:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800a050
FUN_0800a050: @ 0x0800A050
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r3, #0
	ldr r0, _0800A09C @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A0E8
	cmp r1, #0
	beq _0800A0E8
	ldr r0, _0800A0A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A0B4
	ldr r0, _0800A0A4 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A0B0
	ldr r2, _0800A0A8 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A096
	ldr r4, _0800A0AC @ =0x00000442
	adds r0, r1, r4
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A096
	movs r2, #1
_0800A096:
	adds r0, r2, #0
	b _0800A0E4
	.align 2, 0
_0800A09C: .4byte gClock
_0800A0A0: .4byte 0x030047A4
_0800A0A4: .4byte 0x03002BE0
_0800A0A8: .4byte 0x00000446
_0800A0AC: .4byte 0x00000442
_0800A0B0:
	movs r0, #0
	b _0800A0E4
_0800A0B4:
	ldr r0, _0800A110 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A0E8
	ldr r0, _0800A114 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A0E8
	ldr r0, _0800A118 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A0E2
	ldr r0, _0800A11C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A0E2
	movs r1, #1
_0800A0E2:
	adds r0, r1, #0
_0800A0E4:
	cmp r0, #0
	beq _0800A120
_0800A0E8:
	movs r3, #1
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A0F8:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A104
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A104:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A0F8
	b _0800A142
	.align 2, 0
_0800A110: .4byte 0x03002B48
_0800A114: .4byte 0x030046A0
_0800A118: .4byte 0x03002B8C
_0800A11C: .4byte 0x03002B60
_0800A120:
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _0800A142
	movs r2, #1
	adds r1, r5, #0
	adds r1, #0x2e
	movs r4, #0xf
_0800A12E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A13A
	strb r0, [r1]
	strh r0, [r1, #8]
	strb r2, [r1, #5]
_0800A13A:
	adds r1, #0x9c
	subs r4, #1
	cmp r4, #0
	bge _0800A12E
_0800A142:
	strb r3, [r5, #0x18]
	movs r4, #0
	ldr r7, _0800A16C @ =0x085AA6B8
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r6, r0, #2
_0800A14E:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A182
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _0800A170
	adds r0, r5, #0
	bl FUN_08009c08
	b _0800A182
	.align 2, 0
_0800A16C: .4byte 0x085AA6B8
_0800A170:
	strb r0, [r1, #8]
	ldrb r0, [r1, #2]
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_0800A182:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A14E
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a190
FUN_0800a190: @ 0x0800A190
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0800A196:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A1AA
	adds r0, r5, #0
	bl FUN_08009c08
_0800A1AA:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A196
	ldr r1, _0800A1BC @ =0x03000040
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A1BC: .4byte 0x03000040

	thumb_func_start FUN_0800a1c0
FUN_0800a1c0: @ 0x0800A1C0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800A20C @ =0x03000040
	str r5, [r0]
	ldr r0, _0800A210 @ =gClock
	ldrb r1, [r0, #0xe]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800A25C
	cmp r1, #0
	beq _0800A25C
	ldr r0, _0800A214 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800A228
	ldr r0, _0800A218 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800A224
	ldr r2, _0800A21C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0800A208
	ldr r3, _0800A220 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A208
	movs r2, #1
_0800A208:
	adds r0, r2, #0
	b _0800A258
	.align 2, 0
_0800A20C: .4byte 0x03000040
_0800A210: .4byte gClock
_0800A214: .4byte 0x030047A4
_0800A218: .4byte 0x03002BE0
_0800A21C: .4byte 0x00000446
_0800A220: .4byte 0x00000442
_0800A224:
	movs r0, #0
	b _0800A258
_0800A228:
	ldr r0, _0800A290 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0800A25C
	ldr r0, _0800A294 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _0800A25C
	ldr r0, _0800A298 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0800A256
	ldr r0, _0800A29C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0800A256
	movs r1, #1
_0800A256:
	adds r0, r1, #0
_0800A258:
	cmp r0, #0
	beq _0800A25E
_0800A25C:
	movs r0, #1
_0800A25E:
	strb r0, [r5, #0x18]
	ldr r0, _0800A2A0 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r5, #0x1c]
	ldr r0, _0800A2A4 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x20]
	ldr r4, _0800A2A8 @ =0x0000922E
	ldr r1, _0800A2AC @ =0x0000D1B8
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x24]
	ldr r1, _0800A2B0 @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x28]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800A290: .4byte 0x03002B48
_0800A294: .4byte 0x030046A0
_0800A298: .4byte 0x03002B8C
_0800A29C: .4byte 0x03002B60
_0800A2A0: .4byte 0x00001C1A
_0800A2A4: .4byte 0x00001C1C
_0800A2A8: .4byte 0x0000922E
_0800A2AC: .4byte 0x0000D1B8
_0800A2B0: .4byte 0x0000D41F

	thumb_func_start FUN_0800a2b4
FUN_0800a2b4: @ 0x0800A2B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0800A2E4 @ =0x000009EC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800A2F0
	ldr r1, _0800A2E8 @ =FUN_0800a050
	ldr r2, _0800A2EC @ =FUN_0800a190
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800a1c0
	cmp r0, #0
	bge _0800A2F0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800A2F2
	.align 2, 0
_0800A2E4: .4byte 0x000009EC
_0800A2E8: .4byte FUN_0800a050
_0800A2EC: .4byte FUN_0800a190
_0800A2F0:
	adds r0, r4, #0
_0800A2F2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a2f8
FUN_0800a2f8: @ 0x0800A2F8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0800A324 @ =0x03000040
	ldr r7, [r0]
	cmp r7, #0
	bne _0800A312
	movs r0, #0
	movs r1, #0
	bl FUN_0800a2b4
	adds r7, r0, #0
	cmp r7, #0
	beq _0800A31E
_0800A312:
	adds r0, r7, #0
	bl FUN_08009b10
	adds r6, r0, #0
	cmp r6, #0
	bne _0800A328
_0800A31E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A40C
	.align 2, 0
_0800A324: .4byte 0x03000040
_0800A328:
	adds r0, r6, #0
	movs r1, #0x9c
	bl ClearMemory
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0
	movs r5, #0
	strh r0, [r6]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #4]
	strb r4, [r6, #8]
	strb r4, [r6, #2]
	strh r5, [r6, #0xa]
	movs r0, #1
	strb r0, [r6, #7]
	strh r5, [r6, #0xc]
	strb r4, [r6, #6]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08009b6c
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800A3B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800A3A8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800A3AC @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _0800A3BA
	.align 2, 0
_0800A3A8: .4byte 0xFFFF0000
_0800A3AC: .4byte 0x0000FFFF
_0800A3B0:
	ldr r1, _0800A3F8 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0800A3BA:
	adds r0, r6, #0
	adds r0, #0x14
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0800A3FC
	bl Script_GetValue
	strh r0, [r6, #0xe]
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	b _0800A408
	.align 2, 0
_0800A3F8: .4byte 0xFFFF0000
_0800A3FC:
	movs r0, #0x32
	strh r0, [r6, #0xe]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r6, #0x10]
	movs r0, #0x64
_0800A408:
	strh r0, [r6, #0x12]
	movs r0, #0
_0800A40C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a414
FUN_0800a414: @ 0x0800A414
	push {r4, lr}
	sub sp, #8
	ldr r0, _0800A454 @ =0x03000040
	ldr r0, [r0]
	movs r4, #0
	cmp r0, #0
	beq _0800A438
	adds r1, r0, #0
	adds r1, #0x2c
	movs r2, #0xf
_0800A428:
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A430
	adds r4, #1
_0800A430:
	adds r1, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _0800A428
_0800A438:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800A454: .4byte 0x03000040

	thumb_func_start FUN_0800a458
FUN_0800a458: @ 0x0800A458
	push {r4, r5, lr}
	ldr r0, _0800A484 @ =0x03000040
	ldr r5, [r0]
	cmp r5, #0
	beq _0800A47E
	movs r4, #0
_0800A464:
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x2c
	adds r1, r5, r0
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A478
	adds r0, r5, #0
	bl FUN_08009c08
_0800A478:
	adds r4, #1
	cmp r4, #0xf
	ble _0800A464
_0800A47E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800A484: .4byte 0x03000040

	thumb_func_start FUN_0800a488
FUN_0800a488: @ 0x0800A488
	ldr r1, _0800A490 @ =0x03000044
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800A490: .4byte 0x03000044

	thumb_func_start FUN_0800a494
FUN_0800a494: @ 0x0800A494
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x30
	movs r5, #3
_0800A49E:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A49E
	movs r1, #0
	strb r1, [r6]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a4b8
FUN_0800a4b8: @ 0x0800A4B8
	push {r4, r5, r6, lr}
	ldr r0, _0800A4C8 @ =0x03000044
	ldr r5, [r0]
	cmp r5, #0
	bne _0800A4CC
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A4EE
	.align 2, 0
_0800A4C8: .4byte 0x03000044
_0800A4CC:
	adds r4, r5, #0
	adds r4, #0x28
	movs r6, #5
_0800A4D2:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800A4E0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800a494
_0800A4E0:
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _0800A4D2
	movs r0, #0
_0800A4EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a4f4
FUN_0800a4f4: @ 0x0800A4F4
	push {lr}
	bl FUN_0800a4b8
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800a500
FUN_0800a500: @ 0x0800A500
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	str r2, [sp, #8]
	ldr r0, [r0, #0x1c]
	movs r1, #1
	mov sl, r1
	ands r1, r0
	mov sl, r1
	movs r1, #3
	mov sb, r1
	ands r1, r0
	mov sb, r1
	movs r6, #0
	adds r5, r7, #0
	adds r5, #8
_0800A52A:
	ldrb r0, [r7, #2]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrb r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0800A568 @ =0x085AA730
	adds r1, r1, r0
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #8]
	str r0, [sp, #4]
	ldr r4, [r1]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	mov r3, sl
	bl _call_via_r4
	adds r5, #0x50
	adds r6, #1
	cmp r6, #3
	ble _0800A52A
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A568: .4byte 0x085AA730

	thumb_func_start FUN_0800a56c
FUN_0800a56c: @ 0x0800A56C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _0800A5E8 @ =0x030047A4
	ldr r2, _0800A5EC @ =0x030047A0
	ldr r3, [r0]
	ldr r0, [r2]
	orrs r3, r0
	ands r1, r3
	cmp r1, #0
	beq _0800A59A
	movs r0, #0x80
	lsls r0, r0, #1
	ands r3, r0
	cmp r3, #0
	bne _0800A59A
	b _0800A79C
_0800A59A:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r3, [r0]
	ldrh r0, [r3, #0x2c]
	ldr r4, _0800A5F0 @ =0xFFFF0000
	ldr r2, [sp, #0x28]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x28]
	ldrh r1, [r3, #0x2e]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800A5F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldrh r2, [r3, #0x30]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	add r3, sp, #0x30
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A5F8
	asrs r0, r0, #8
	b _0800A5FE
	.align 2, 0
_0800A5E8: .4byte 0x030047A4
_0800A5EC: .4byte 0x030047A0
_0800A5F0: .4byte 0xFFFF0000
_0800A5F4: .4byte 0x0000FFFF
_0800A5F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A5FE:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A610
	asrs r0, r0, #8
	b _0800A616
_0800A610:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A616:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A62A
	asrs r1, r0, #8
	b _0800A630
_0800A62A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A630:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
	mov r4, sp
	movs r1, #0x28
	add r1, sb
	mov r8, r1
	mov r7, r8
	movs r2, #5
	mov sl, r2
_0800A646:
	ldrb r0, [r7]
	cmp r0, #0
	bne _0800A64E
	b _0800A77E
_0800A64E:
	ldrb r0, [r7, #2]
	cmp r0, #2
	bne _0800A664
	mov r1, sp
	ldrh r0, [r1, #0x28]
	strh r0, [r4]
	add r1, sp, #0x28
	ldrh r0, [r1, #2]
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	b _0800A6A6
_0800A664:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800A690
	ldrh r0, [r1, #0x2c]
	adds r0, #0x18
	strh r0, [r4]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	subs r0, #0x18
	b _0800A6A6
_0800A690:
	ldrh r0, [r1, #0x2c]
	subs r0, #0x20
	strh r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	adds r0, #0x20
_0800A6A6:
	strh r0, [r4, #4]
	add r6, sp, #8
	mov r3, sp
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6C8
	asrs r0, r0, #8
	b _0800A6CE
_0800A6C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6CE:
	strh r0, [r6]
	adds r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6E0
	asrs r0, r0, #8
	b _0800A6E6
_0800A6E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6E6:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A6FA
	asrs r1, r0, #8
	b _0800A700
_0800A6FA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A700:
	subs r0, r2, r1
	strh r0, [r6, #2]
	adds r0, r2, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r4, #8]
	subs r0, #5
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #5
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0x10]
	adds r0, #5
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x12]
	adds r0, #5
	strh r0, [r4, #0x12]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldrh r0, [r4, #0x18]
	subs r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	subs r0, #0x14
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x20]
	adds r0, #8
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x22]
	adds r0, #0x14
	strh r0, [r4, #0x22]
	mov r0, sb
	mov r1, r8
	mov r2, sp
	bl FUN_0800a500
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0800A774
	subs r0, #1
	strb r0, [r7, #4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800A774
	ldrb r0, [r7, #2]
	ldr r1, _0800A7B0 @ =0x085AA724
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
_0800A774:
	ldrh r0, [r7, #6]
	cmp r0, #0
	beq _0800A77E
	subs r0, #1
	strh r0, [r7, #6]
_0800A77E:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r7, r7, r1
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	blt _0800A794
	b _0800A646
_0800A794:
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
_0800A79C:
	movs r0, #0
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A7B0: .4byte 0x085AA724

	thumb_func_start FUN_0800a7b4
FUN_0800a7b4: @ 0x0800A7B4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r2, #0
_0800A7BA:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x28
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r6, r2, #1
	cmp r0, #0
	beq _0800A7E4
	adds r4, r1, #0
	adds r4, #0x30
	movs r5, #3
_0800A7D6:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A7D6
_0800A7E4:
	adds r2, r6, #0
	cmp r2, #5
	ble _0800A7BA
	movs r1, #0
	ldr r0, _0800A7F8 @ =0x03000044
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A7F8: .4byte 0x03000044

	thumb_func_start FUN_0800a7fc
FUN_0800a7fc: @ 0x0800A7FC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0800A86C @ =0x03000044
	str r6, [r0]
	ldr r0, _0800A870 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r6, #0x20]
	ldr r0, _0800A874 @ =0x0000922E
	ldr r1, _0800A878 @ =0x0000D1B8
	bl GetFile
	str r0, [r6, #0x24]
	movs r2, #0
_0800A818:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, #0x28
	adds r0, r6, r0
	movs r1, #0
	strb r1, [r0]
	adds r7, r2, #1
	adds r4, r0, #0
	adds r4, #0x30
	movs r5, #3
_0800A832:
	ldr r1, [r6, #0x20]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0800A832
	adds r2, r7, #0
	cmp r2, #5
	ble _0800A818
	movs r2, #0
	str r2, [r6, #0x1c]
	ldr r0, _0800A87C @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r0, r6, r3
	str r1, [r0]
	cmp r1, #0
	bne _0800A880
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A896
	.align 2, 0
_0800A86C: .4byte 0x03000044
_0800A870: .4byte 0x00001C1A
_0800A874: .4byte 0x0000922E
_0800A878: .4byte 0x0000D1B8
_0800A87C: .4byte 0x03002BE0
_0800A880:
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _0800A892
	movs r0, #1
	str r0, [r6, #0x18]
	b _0800A894
_0800A892:
	str r2, [r6, #0x18]
_0800A894:
	movs r0, #0
_0800A896:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a89c
FUN_0800a89c: @ 0x0800A89C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0800A8CC @ =0x000007DC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800A8D8
	ldr r1, _0800A8D0 @ =FUN_0800a56c
	ldr r2, _0800A8D4 @ =FUN_0800a7b4
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800a7fc
	cmp r0, #0
	bge _0800A8D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800A8DA
	.align 2, 0
_0800A8CC: .4byte 0x000007DC
_0800A8D0: .4byte FUN_0800a56c
_0800A8D4: .4byte FUN_0800a7b4
_0800A8D8:
	adds r0, r4, #0
_0800A8DA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800a8e0
FUN_0800a8e0: @ 0x0800A8E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r5, r2, #0
	str r3, [sp, #8]
	ldr r0, _0800A914 @ =0x03000044
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	ldr r0, _0800A918 @ =0x0000FC73
	movs r1, #0
	bl FUN_0800a89c
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	movs r0, #1
	rsbs r0, r0, #0
	b _0800AC6E
	.align 2, 0
_0800A914: .4byte 0x03000044
_0800A918: .4byte 0x0000FC73
_0800A91C:
	ldr r0, _0800A97C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	bne _0800A926
	b _0800AC6C
_0800A926:
	movs r0, #0xf0
	ands r0, r4
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	movs r0, #0xf
	ands r4, r0
	ldr r0, [sp, #4]
	cmp r0, #4
	ble _0800A93E
	movs r1, #4
	str r1, [sp, #4]
_0800A93E:
	ldr r2, [sp, #0x50]
	cmp r2, #0
	bne _0800A948
	movs r0, #1
	str r0, [sp, #0x50]
_0800A948:
	ldr r0, _0800A980 @ =0x085AA700
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0
	str r1, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r1, #0x28
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
_0800A95E:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800A968
	b _0800AC54
_0800A968:
	strb r4, [r1, #2]
	strb r5, [r1, #3]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #1]
	cmp r3, #0
	beq _0800A984
	strb r0, [r1, #4]
	b _0800A98A
	.align 2, 0
_0800A97C: .4byte 0x03002BE0
_0800A980: .4byte 0x085AA700
_0800A984:
	movs r0, #0xe
	ldr r3, [sp, #0x20]
	strb r0, [r3, #4]
_0800A98A:
	movs r0, #0
	str r0, [sp, #0x14]
	mov sl, r0
	ldr r1, [sp, #4]
	cmp sl, r1
	blt _0800A998
	b _0800AC1A
_0800A998:
	ldr r7, _0800AB4C @ =0x030046B8
	ldr r5, [sp, #0x24]
	adds r5, #0x10
	ldr r2, [sp, #0x24]
	adds r2, #0x20
	mov sb, r2
	ldr r3, [sp, #0x24]
	adds r3, #8
	mov r8, r3
	ldr r0, [sp, #0x24]
	adds r0, #0x30
	str r0, [sp, #0x1c]
	mov sl, r1
_0800A9B2:
	movs r2, #1
	mov r1, r8
	strb r2, [r1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x50]
	bl Mod
	ldr r2, [sp, #0x4c]
	adds r0, r2, r0
	mov r3, r8
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r3, #6]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r3, #1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strb r0, [r1, #2]
	ldr r0, [r7]
	adds r0, #1
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x80
	rsbs r1, r1, #0
	orrs r0, r1
	mov r2, r8
	strb r0, [r2, #3]
	ldr r0, [r5, #0x20]
	adds r1, #0x7e
	ands r0, r1
	str r0, [r5, #0x20]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	strh r0, [r5, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AA5E
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x38]
	adds r1, r1, r0
	strh r1, [r5, #0x38]
_0800AA5E:
	ldr r1, [sp, #8]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x3a]
	ldr r2, [sp, #0x48]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _0800AA90
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x48]
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	ldrh r1, [r5, #0x3a]
	adds r1, r1, r0
	strh r1, [r5, #0x3a]
_0800AA90:
	ldr r3, [sp, #8]
	ldrh r0, [r3, #4]
	strh r0, [r5, #0x3c]
	ldr r1, [sp, #0x48]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AAC2
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x3c]
	adds r1, r1, r0
	strh r1, [r5, #0x3c]
_0800AAC2:
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #0x24]
	ldr r3, _0800AB58 @ =0x085AA6D0
	ldr r2, [r0, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r3, #0
	str r3, [sp]
	mov r0, sb
	bl FUN_08236fac
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r5, #0x18]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	cmp r1, #2
	ble _0800AAF6
	movs r2, #0
	str r2, [sp, #0x14]
_0800AAF6:
	movs r3, #0
	strh r3, [r5]
	strh r3, [r5, #2]
	strh r3, [r5, #4]
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x20]
	mov ip, r0
	mov r4, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x10]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0800AB5C
	ldr r0, [r5, #0x20]
	movs r1, #4
	orrs r0, r1
	b _0800AB64
	.align 2, 0
_0800AB4C: .4byte 0x030046B8
_0800AB50: .4byte 0x000003FF
_0800AB54: .4byte 0x0203B400
_0800AB58: .4byte 0x085AA6D0
_0800AB5C:
	ldr r0, [r5, #0x20]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800AB64:
	str r0, [r5, #0x20]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800AB88
	ldr r0, [r5, #0x20]
	movs r1, #8
	orrs r0, r1
	b _0800AB90
_0800AB88:
	ldr r0, [r5, #0x20]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800AB90:
	str r0, [r5, #0x20]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0800ABC8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0800ABF2
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800ABCC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800ABC0
	ldrb r0, [r4, #5]
_0800ABC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800ABDC
	.align 2, 0
_0800ABC8: .4byte 0x0000FFFF
_0800ABCC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800ABDC
	strh r1, [r4, #8]
_0800ABDC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800ABF2:
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl FUN_0822da50
	adds r5, #0x50
	movs r3, #0x50
	add sb, r3
	add r8, r3
	ldr r0, [sp, #0x1c]
	adds r0, #0x50
	str r0, [sp, #0x1c]
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r2, sl
	cmp r2, #0
	beq _0800AC16
	b _0800A9B2
_0800AC16:
	ldr r3, [sp, #4]
	mov sl, r3
_0800AC1A:
	mov r0, sl
	cmp r0, #3
	bgt _0800AC48
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #4
	adds r0, #0x30
	ldr r1, [sp, #0x24]
	adds r4, r0, r1
_0800AC2C:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822da50
	adds r4, #0x50
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _0800AC2C
_0800AC48:
	movs r0, #0x28
	ldr r1, [sp, #0x20]
	strh r0, [r1, #6]
	movs r0, #1
	strb r0, [r1]
	b _0800AC6C
_0800AC54:
	ldr r0, [sp, #0x20]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	adds r0, r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	cmp r2, #5
	bgt _0800AC6C
	b _0800A95E
_0800AC6C:
	movs r0, #0
_0800AC6E:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ac80
FUN_0800ac80: @ 0x0800AC80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r5, r2, #0
	str r3, [sp, #8]
	ldr r0, _0800ACB4 @ =0x03000044
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800ACBC
	ldr r0, _0800ACB8 @ =0x0000FC73
	movs r1, #0
	bl FUN_0800a89c
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800ACBC
	movs r0, #1
	rsbs r0, r0, #0
	b _0800AF6C
	.align 2, 0
_0800ACB4: .4byte 0x03000044
_0800ACB8: .4byte 0x0000FC73
_0800ACBC:
	movs r0, #0xf0
	ands r0, r4
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	movs r0, #0xf
	ands r4, r0
	ldr r0, [sp, #4]
	cmp r0, #4
	ble _0800ACD4
	movs r1, #4
	str r1, [sp, #4]
_0800ACD4:
	ldr r2, [sp, #0x4c]
	cmp r2, #0
	bne _0800ACDE
	movs r0, #1
	str r0, [sp, #0x4c]
_0800ACDE:
	ldr r0, _0800AD10 @ =0x085AA700
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0
	str r1, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r1, #0x28
	str r1, [sp, #0x20]
	mov r8, r1
_0800ACF4:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800ACFE
	b _0800AF56
_0800ACFE:
	strb r4, [r1, #2]
	strb r5, [r1, #3]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #1]
	cmp r3, #0
	beq _0800AD14
	strb r0, [r1, #4]
	b _0800AD1A
	.align 2, 0
_0800AD10: .4byte 0x085AA700
_0800AD14:
	movs r0, #0xe
	mov r3, r8
	strb r0, [r3, #4]
_0800AD1A:
	movs r0, #0
	str r0, [sp, #0x14]
	mov sb, r0
	ldr r1, [sp, #4]
	cmp sb, r1
	blt _0800AD28
	b _0800AF1C
_0800AD28:
	ldr r2, _0800AD4C @ =0x030046B8
	mov sl, r2
	ldr r7, [sp, #0x20]
	adds r7, #0x20
	ldr r5, [sp, #0x20]
	adds r5, #8
	ldr r3, [sp, #0x20]
	adds r3, #0x30
	str r3, [sp, #0x1c]
_0800AD3A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _0800AD50
	mov r1, sb
	lsls r0, r1, #3
	ldr r2, [sp, #0x44]
	adds r4, r2, r0
	b _0800AD52
	.align 2, 0
_0800AD4C: .4byte 0x030046B8
_0800AD50:
	ldr r4, [sp, #8]
_0800AD52:
	movs r6, #0
	movs r3, #1
	strb r3, [r5]
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0800AE5C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0800AE60 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r1, [sp, #0x48]
	adds r0, r1, r0
	strh r0, [r5, #4]
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5, #6]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0800AE5C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0800AE60 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r5, #1]
	ldr r0, [r3]
	adds r0, #1
	ldr r3, _0800AE5C @ =0x000003FF
	ands r0, r3
	mov r1, sl
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r5, #2]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r3
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x80
	rsbs r1, r1, #0
	orrs r0, r1
	strb r0, [r5, #3]
	ldr r0, [r5, #0x28]
	adds r1, #0x7e
	ands r0, r1
	str r0, [r5, #0x28]
	ldrh r0, [r4]
	strh r0, [r7, #0x28]
	ldrh r0, [r4, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r4, #4]
	strh r0, [r7, #0x2c]
	ldr r2, [sp, #0x10]
	ldr r1, [r2, #0x24]
	ldr r3, _0800AE64 @ =0x085AA6D0
	ldr r2, [r2, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r2, [r0]
	str r6, [sp]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08236fac
	mov r3, sp
	ldrh r3, [r3, #0x14]
	strh r3, [r5, #0x20]
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #2
	ble _0800AE0C
	movs r1, #0
	str r1, [sp, #0x14]
_0800AE0C:
	strh r6, [r5, #8]
	strh r6, [r5, #0xa]
	strh r6, [r5, #0xc]
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r2, [sp, #0x10]
	ldr r3, [r2, #0x20]
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x18]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #0x30]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0800AE68
	ldr r0, [r5, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800AE70
	.align 2, 0
_0800AE5C: .4byte 0x000003FF
_0800AE60: .4byte 0x0203B400
_0800AE64: .4byte 0x085AA6D0
_0800AE68:
	ldr r0, [r5, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800AE70:
	str r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800AE94
	ldr r0, [r5, #0x28]
	movs r1, #8
	orrs r0, r1
	b _0800AE9C
_0800AE94:
	ldr r0, [r5, #0x28]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800AE9C:
	str r0, [r5, #0x28]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0800AED4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0800AEFE
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800AED8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800AECC
	ldrb r0, [r4, #5]
_0800AECC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800AEE8
	.align 2, 0
_0800AED4: .4byte 0x0000FFFF
_0800AED8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800AEE8
	strh r1, [r4, #8]
_0800AEE8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800AEFE:
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl FUN_0822da50
	adds r7, #0x50
	adds r5, #0x50
	ldr r3, [sp, #0x1c]
	adds r3, #0x50
	str r3, [sp, #0x1c]
	movs r0, #1
	add sb, r0
	ldr r1, [sp, #4]
	cmp sb, r1
	bge _0800AF1C
	b _0800AD3A
_0800AF1C:
	mov r2, sb
	cmp r2, #3
	bgt _0800AF4A
	lsls r0, r2, #2
	add r0, sb
	lsls r0, r0, #4
	adds r0, #0x30
	ldr r3, [sp, #0x20]
	adds r4, r0, r3
_0800AF2E:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822da50
	adds r4, #0x50
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _0800AF2E
_0800AF4A:
	movs r0, #0x28
	mov r2, r8
	strh r0, [r2, #6]
	movs r0, #1
	strb r0, [r2]
	b _0800AF6A
_0800AF56:
	movs r0, #0xa4
	lsls r0, r0, #1
	add r8, r0
	ldr r1, [sp, #0x20]
	adds r1, r1, r0
	str r1, [sp, #0x20]
	adds r2, #1
	cmp r2, #5
	bgt _0800AF6A
	b _0800ACF4
_0800AF6A:
	movs r0, #0
_0800AF6C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800af7c
FUN_0800af7c: @ 0x0800AF7C
	push {r4, lr}
	ldr r0, _0800AF8C @ =0x03000044
	ldr r0, [r0]
	cmp r0, #0
	bne _0800AF90
	movs r0, #0
	b _0800AFB0
	.align 2, 0
_0800AF8C: .4byte 0x03000044
_0800AF90:
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x28
	movs r4, #0xa4
	lsls r4, r4, #1
	movs r2, #5
_0800AF9C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800AFA6
	ldrb r0, [r1, #1]
	adds r3, r3, r0
_0800AFA6:
	adds r1, r1, r4
	subs r2, #1
	cmp r2, #0
	bge _0800AF9C
	adds r0, r3, #0
_0800AFB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800afb8
FUN_0800afb8: @ 0x0800AFB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0800B05C @ =0x03000044
	ldr r7, [r0]
	cmp r7, #0
	beq _0800B04A
	movs r1, #0
_0800AFCE:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x28
	adds r5, r7, r0
	ldrb r0, [r5]
	adds r1, #1
	mov sb, r1
	cmp r0, #0
	beq _0800B044
	ldrb r0, [r5, #2]
	cmp r0, #2
	bne _0800B044
	movs r0, #0
	strb r0, [r5, #2]
	ldr r0, _0800B060 @ =0x085AA6D0
	mov sl, r0
	adds r4, r5, #0
	adds r4, #8
	adds r6, r5, #0
	adds r6, #0x20
	movs r2, #3
	mov r8, r2
_0800B000:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800B034
	ldr r1, [r7, #0x24]
	ldr r2, [r7, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	ldrb r2, [r5, #2]
	adds r0, r0, r2
	lsls r0, r0, #2
	add r0, sl
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08236fac
	ldrb r0, [r4]
	cmp r0, #2
	bhi _0800B034
	ldrh r0, [r4, #4]
	cmp r0, #0xb3
	bhi _0800B034
	movs r0, #0xb4
	strh r0, [r4, #4]
_0800B034:
	adds r4, #0x50
	adds r6, #0x50
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r2, r8
	cmp r2, #0
	bge _0800B000
_0800B044:
	mov r1, sb
	cmp r1, #5
	ble _0800AFCE
_0800B04A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B05C: .4byte 0x03000044
_0800B060: .4byte 0x085AA6D0

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

	thumb_func_start FUN_0800c134
FUN_0800c134: @ 0x0800C134
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

	thumb_func_start FUN_0800c248
FUN_0800c248: @ 0x0800C248
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

	thumb_func_start FUN_0800c26c
FUN_0800c26c: @ 0x0800C26C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r7, r0, #0
	movs r4, #0
	strh r1, [r7, #0x18]
	movs r0, #0x6c
	movs r1, #0xc8
	bl Script_GetKeywordValue
	strh r0, [r7, #0x26]
	movs r0, #1
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x28]
	movs r0, #0x6e
	movs r1, #4
	bl Script_GetKeywordValue
	strh r0, [r7, #0x36]
	movs r0, #0x65
	movs r1, #0x32
	bl Script_GetKeywordValue
	strh r0, [r7, #0x38]
	strh r4, [r7, #0x2a]
	strh r4, [r7, #0x2c]
	strh r4, [r7, #0x2e]
	movs r0, #0x70
	bl prepare_08231510
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
	bl FUN_0822b16c
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

	thumb_func_start FUN_0800c3c4
FUN_0800c3c4: @ 0x0800C3C4
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
	ldr r1, _0800C3FC @ =FUN_0800c134
	ldr r2, _0800C400 @ =FUN_0800c248
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0800c26c
	cmp r0, #0
	bge _0800C404
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800C406
	.align 2, 0
_0800C3FC: .4byte FUN_0800c134
_0800C400: .4byte FUN_0800c248
_0800C404:
	adds r0, r4, #0
_0800C406:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c40c
FUN_0800c40c: @ 0x0800C40C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	bl FUN_08236524
	ldrh r1, [r5, #0x3e]
	cmp r1, #0
	beq _0800C458
	ldrh r0, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800C432
	movs r0, #0
	strh r0, [r4, #2]
	b _0800C454
_0800C432:
	movs r0, #0xa
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r1, #4
	ldr r0, [r7, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _0800C454
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0800C454:
	movs r0, #0
	strh r0, [r5, #0x3e]
_0800C458:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800c460
FUN_0800c460: @ 0x0800C460
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r0, r6, #0
	adds r0, #0x2c
	bl FUN_08236424
	adds r0, r6, #0
	adds r0, #0x8c
	bl FUN_0822a4e0
	adds r0, r6, #0
	adds r0, #0x7c
	bl FUN_082342a8
	movs r2, #1
	lsls r2, r5
	ldr r1, [r4, #0x1c]
	bics r1, r2
	str r1, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c490
FUN_0800c490: @ 0x0800C490
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r0, #0xa5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r6, #0x14
	movs r7, #0x1e
	str r7, [sp]
	movs r5, #0x10
	str r5, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov r8, r0
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #3
	movs r1, #3
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	str r7, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, sb
	str r0, [sp, #0x14]
	mov r0, r8
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #8
	movs r1, #7
	adds r2, r6, #0
	movs r3, #0x3c
	bl FUN_08014da0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800c50c
FUN_0800c50c: @ 0x0800C50C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	ldr r0, _0800C5B8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	mov sb, r1
	cmp r0, #0
	beq _0800C52A
	adds r0, #0x2c
	mov sb, r0
_0800C52A:
	movs r4, #0
	ldr r6, [r7, #0x20]
	mov r8, r4
	ldrb r2, [r7, #0x18]
	cmp r8, r2
	blt _0800C538
	b _0800C66E
_0800C538:
	movs r0, #4
	mov sl, r0
	adds r5, r6, #0
_0800C53E:
	movs r1, #1
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0800C54E
	b _0800C65E
_0800C54E:
	movs r1, #2
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800C5C0
	ldrh r0, [r5, #8]
	cmp r0, #0
	beq _0800C5A6
	ldrh r0, [r5]
	str r0, [sp]
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	str r0, [sp, #4]
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r2, #0x18
	ldrsh r0, [r5, r2]
	str r0, [sp, #0xc]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x10]
	movs r2, #0xe
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x14]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x18]
	movs r2, #0x12
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x1c]
	ldr r1, _0800C5BC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #8]
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #8]
_0800C5A6:
	adds r0, r6, #0
	bl FUN_0800c490
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, r8
	bl FUN_0800c460
	b _0800C65E
	.align 2, 0
_0800C5B8: .4byte 0x03002BE0
_0800C5BC: .4byte 0xFFFF0000
_0800C5C0:
	ldrb r1, [r5, #0xa]
	cmp r1, #0
	beq _0800C5E8
	ldrh r0, [r5, #0x32]
	mov r2, sl
	orrs r0, r2
	strh r0, [r5, #0x32]
	subs r0, r1, #1
	strb r0, [r5, #0xa]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800C5F2
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, _0800C5E4 @ =0x0000011B
	bl FUN_0822b20c
	b _0800C5F2
	.align 2, 0
_0800C5E4: .4byte 0x0000011B
_0800C5E8:
	ldrh r1, [r5, #0x32]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5, #0x32]
_0800C5F2:
	mov r0, sb
	cmp r0, #0
	beq _0800C65E
	cmp r4, #0
	bne _0800C65E
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x1c
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x26
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	mov r0, sb
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #0x20
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _0800C640
	movs r2, #0x28
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bgt _0800C640
	movs r0, #1
	b _0800C642
_0800C640:
	movs r0, #0
_0800C642:
	cmp r0, #0
	beq _0800C65E
	adds r4, r7, #0
	adds r4, #0x24
	adds r1, r6, #0
	adds r1, #0x14
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r4, #1
_0800C65E:
	movs r0, #1
	add r8, r0
	adds r5, #0xd4
	adds r6, #0xd4
	ldrb r1, [r7, #0x18]
	cmp r8, r1
	bge _0800C66E
	b _0800C53E
_0800C66E:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c680
FUN_0800c680: @ 0x0800C680
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x20]
	cmp r1, #0
	beq _0800C6BA
	adds r6, r1, #0
	movs r5, #0
	b _0800C6AA
_0800C690:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _0800C6A6
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_0800c460
_0800C6A6:
	adds r5, #1
	adds r6, #0xd4
_0800C6AA:
	ldrb r0, [r4, #0x18]
	cmp r5, r0
	blt _0800C690
	ldr r0, [r4, #0x20]
	bl Free
	movs r0, #0
	str r0, [r4, #0x20]
_0800C6BA:
	ldr r1, _0800C6C8 @ =0x03002B34
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800C6C8: .4byte 0x03002B34

	thumb_func_start FUN_0800c6cc
FUN_0800c6cc: @ 0x0800C6CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0800C788 @ =0x03002B34
	str r7, [r0]
	movs r0, #0x6d
	movs r1, #8
	bl Script_GetKeywordValue
	movs r5, #0
	strb r0, [r7, #0x18]
	str r5, [r7, #0x1c]
	movs r0, #0x70
	movs r1, #5
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x66
	movs r1, #0xa
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x69
	movs r1, #0xa
	bl Script_GetKeywordValue
	adds r6, r0, #0
	adds r4, r7, #0
	adds r4, #0x24
	ldr r2, _0800C78C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xa4
	orrs r0, r3
	ldr r1, _0800C790 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0800C794 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, sb
	mov r2, r8
	movs r3, #0
	bl FUN_082364f8
	ldrb r0, [r7, #0x18]
	movs r4, #0xd4
	muls r0, r4, r0
	bl Malloc
	adds r3, r0, #0
	str r3, [r7, #0x20]
	cmp r3, #0
	beq _0800C798
	ldrb r0, [r7, #0x18]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r3, #0
	bl ClearMemory
	movs r0, #0
	b _0800C79C
	.align 2, 0
_0800C788: .4byte 0x03002B34
_0800C78C: .4byte 0xFFFF0000
_0800C790: .4byte 0x0000FFFF
_0800C794: .4byte 0x00002001
_0800C798:
	movs r0, #1
	rsbs r0, r0, #0
_0800C79C:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800c7ac
FUN_0800c7ac: @ 0x0800C7AC
	push {r4, lr}
	ldr r0, _0800C7E0 @ =0x03002B34
	ldr r0, [r0]
	cmp r0, #0
	bne _0800C7EE
	movs r0, #8
	movs r1, #0x74
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800C7EC
	ldr r1, _0800C7E4 @ =FUN_0800c50c
	ldr r2, _0800C7E8 @ =FUN_0800c680
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0800c6cc
	cmp r0, #0
	bge _0800C7EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800C7EE
	.align 2, 0
_0800C7E0: .4byte 0x03002B34
_0800C7E4: .4byte FUN_0800c50c
_0800C7E8: .4byte FUN_0800c680
_0800C7EC:
	adds r0, r4, #0
_0800C7EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c7f4
FUN_0800c7f4: @ 0x0800C7F4
	push {r4, lr}
	movs r1, #0
	ldrb r2, [r0, #0x18]
	cmp r1, r2
	bge _0800C816
	movs r4, #1
	ldr r3, [r0, #0x1c]
_0800C802:
	adds r0, r4, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _0800C810
	adds r0, r1, #0
	b _0800C81A
_0800C810:
	adds r1, #1
	cmp r1, r2
	blt _0800C802
_0800C816:
	movs r0, #1
	rsbs r0, r0, #0
_0800C81A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800c820
FUN_0800c820: @ 0x0800C820
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	str r0, [sp, #0x1c]
	adds r4, r1, #0
	adds r6, r2, #0
	str r3, [sp, #0x20]
	ldr r7, [sp, #0x50]
	ldr r0, _0800C870 @ =0x03002B34
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _0800C842
	b _0800CA0A
_0800C842:
	mov r0, sl
	bl FUN_0800c7f4
	str r0, [sp, #0x24]
	cmp r0, #0
	bge _0800C850
	b _0800CA0A
_0800C850:
	movs r0, #0xd4
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	muls r1, r0, r1
	mov r3, sl
	ldr r0, [r3, #0x20]
	adds r5, r0, r1
	strh r4, [r5]
	strh r6, [r5, #2]
	cmp r7, #0
	beq _0800C874
	ldr r0, [sp, #0x1c]
	bl FUN_08241574
	str r0, [r5, #4]
	b _0800C876
	.align 2, 0
_0800C870: .4byte 0x03002B34
_0800C874:
	str r7, [r5, #4]
_0800C876:
	ldr r0, [r5, #4]
	cmp r0, #0
	bge _0800C87E
	b _0800CA0A
_0800C87E:
	ldr r0, [sp, #0x54]
	strh r0, [r5, #8]
	adds r7, r5, #0
	adds r7, #0x14
	adds r6, r5, #0
	adds r6, #0x2c
	add r4, sp, #0x14
	movs r0, #0x1c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0x24
	adds r1, r1, r5
	mov sb, r1
	adds r2, r5, #0
	adds r2, #0x7c
	str r2, [sp, #0x28]
	adds r3, r5, #0
	adds r3, #0xb8
	str r3, [sp, #0x2c]
	ldr r3, [sp, #0x58]
	adds r1, r5, #0
	adds r1, #0xc
	movs r2, #3
_0800C8AC:
	ldm r3!, {r0}
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800C8AC
	ldr r2, [sp, #0x1c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	ldr r2, _0800C990 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800C994 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5]
	ldr r2, _0800C998 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _0800C99C @ =FUN_0800c40c
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	bl FUN_08236400
	ldr r1, _0800C9A0 @ =0x0000FF5C
	ldr r0, _0800C9A4 @ =0x0000FF80
	strh r0, [r5, #0x1e]
	strh r1, [r5, #0x20]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r7, #2]
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0xa4
	movs r0, #0x80
	strh r0, [r5, #0x26]
	strh r1, [r5, #0x28]
	ldrh r0, [r5, #0x14]
	adds r0, #0xa4
	strh r0, [r5, #0x24]
	ldrh r0, [r7, #2]
	mov r1, sb
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800C98C
	cmp r1, #0
	blt _0800C98C
	ldr r0, _0800C9A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800C98C
	ldr r0, _0800C9AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800C9B0
_0800C98C:
	movs r4, #0
	b _0800C9BE
	.align 2, 0
_0800C990: .4byte 0xFFFF0000
_0800C994: .4byte 0x0000FFFF
_0800C998: .4byte 0x00004001
_0800C99C: .4byte FUN_0800c40c
_0800C9A0: .4byte 0x0000FF5C
_0800C9A4: .4byte 0x0000FF80
_0800C9A8: .4byte 0x030046A8
_0800C9AC: .4byte 0x030046AC
_0800C9B0:
	ldr r0, _0800C9D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800C9BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800C9D4
	adds r0, #4
	b _0800C9E0
	.align 2, 0
_0800C9D0: .4byte 0x030046A4
_0800C9D4:
	ldr r0, _0800CA10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800C9E0:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800C9EC
	adds r3, #1
_0800C9EC:
	movs r0, #0xff
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08234270
	ldr r1, _0800CA14 @ =0x000004B3
	ldr r0, [sp, #0x2c]
	bl FUN_0822b16c
	cmp r0, #0
	bne _0800CA18
_0800CA0A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800CA46
	.align 2, 0
_0800CA10: .4byte 0x030046A4
_0800CA14: .4byte 0x000004B3
_0800CA18:
	adds r4, r5, #0
	adds r4, #0x8c
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	movs r2, #0
	bl FUN_0822a470
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r4, #0x10]
	adds r3, r5, #0
	adds r3, #0xa8
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	str r1, [r3]
	str r2, [r3, #4]
	movs r2, #1
	ldr r3, [sp, #0x24]
	lsls r2, r3
	mov r3, sl
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
_0800CA46:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800ca58
FUN_0800ca58: @ 0x0800CA58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x6c
	movs r1, #0x64
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0800CABC
	add r5, sp, #0x1c
	add r4, sp, #0xc
_0800CAA4:
	bl VM_GetPC
	cmp r0, #0
	beq _0800CAB0
	bl Script_GetValue
_0800CAB0:
	str r0, [r4]
	adds r4, #4
	add r0, sp, #0x18
	cmp r4, r0
	ble _0800CAA4
	b _0800CACC
_0800CABC:
	add r5, sp, #0x1c
	movs r1, #0
	add r0, sp, #0x18
_0800CAC2:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0xc
	cmp r0, r2
	bge _0800CAC2
_0800CACC:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800CB14
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800CB0C @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800CB10 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r5, #4]
	b _0800CB1E
	.align 2, 0
_0800CB0C: .4byte 0xFFFF0000
_0800CB10: .4byte 0x0000FFFF
_0800CB14:
	ldr r1, _0800CB68 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	ldr r0, [r5, #4]
	ands r0, r1
	str r0, [r5, #4]
_0800CB1E:
	ldr r0, _0800CB6C @ =0xFFFFFF00
	adds r4, r0, #0
	ldrh r1, [r5]
	ands r1, r4
	movs r0, #0x80
	orrs r1, r0
	ldr r3, _0800CB68 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r2, [r0, #4]
	ands r2, r4
	movs r1, #0x80
	orrs r2, r1
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	str r7, [sp]
	str r6, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_0800c820
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CB68: .4byte 0xFFFF0000
_0800CB6C: .4byte 0xFFFFFF00

	thumb_func_start FUN_0800cb70
FUN_0800cb70: @ 0x0800CB70
	ldr r0, _0800CB78 @ =0x03002B38
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800CB78: .4byte 0x03002B38

	thumb_func_start FUN_0800cb7c
FUN_0800cb7c: @ 0x0800CB7C
	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800CBC8
	adds r0, r4, #0
	adds r0, #0xa8
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xf0
	bl FUN_0822a4e0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082342a8
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	ldrh r1, [r4, #0x28]
	movs r0, #1
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x48
	cmp r0, #0
	bne _0800CBBE
	adds r0, r5, #0
	bl FUN_08002a58
_0800CBBE:
	adds r0, r5, #0
	bl FUN_0823b284
	movs r0, #0
	strb r0, [r4]
_0800CBC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800cbd0
FUN_0800cbd0: @ 0x0800CBD0
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	cmp r0, r1
	beq _0800CBFE
	movs r0, #7
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800CBFE
	adds r4, r2, #0
	adds r4, #0x40
	ldrb r0, [r4]
	cmp r0, #0
	bne _0800CBFE
	movs r0, #1
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r3, #0x38]
	str r0, [r2, #0x24]
	movs r0, #0xa
	strb r0, [r4]
_0800CBFE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800cc04
FUN_0800cc04: @ 0x0800CC04
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800cc08
FUN_0800cc08: @ 0x0800CC08
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r3, r0
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r2, #3
	ldr r0, _0800CC64 @ =0x030046A4
	ldr r4, [r0]
	ands r1, r2
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r1, r3, #0
	adds r1, #0x50
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CC5E
	cmp r1, #0
	blt _0800CC5E
	ldr r0, _0800CC68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CC5E
	ldr r0, _0800CC6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CC70
_0800CC5E:
	movs r0, #0
	b _0800CC7C
	.align 2, 0
_0800CC64: .4byte 0x030046A4
_0800CC68: .4byte 0x030046A8
_0800CC6C: .4byte 0x030046AC
_0800CC70:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0800CC7C:
	adds r4, r0, r5
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800CC8E
	adds r3, r0, #4
	b _0800CC9A
_0800CC8E:
	ldr r0, _0800CCC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_0800CC9A:
	cmp r3, #0
	beq _0800CCC8
	ldrb r4, [r3]
	lsrs r0, r4, #4
	cmp r0, #0
	bne _0800CCC8
	movs r0, #0xf
	ldrb r2, [r6]
	adds r1, r0, #0
	ands r1, r4
	ands r0, r2
	cmp r1, r0
	bhs _0800CCC8
	ldrh r1, [r3, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800CCC8
	movs r0, #1
	b _0800CCCA
	.align 2, 0
_0800CCC4: .4byte 0x030046A4
_0800CCC8:
	movs r0, #0
_0800CCCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800ccd0
FUN_0800ccd0: @ 0x0800CCD0
	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r5, [r4, #3]
	cmp r5, #1
	bne _0800CD24
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800CCE6
	ldr r0, _0800CD20 @ =0x00000219
	bl PlaySound_082406e0
_0800CCE6:
	ldrb r1, [r4, #2]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	movs r0, #3
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r5, [r4, #1]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #1
	b _0800CD64
	.align 2, 0
_0800CD20: .4byte 0x00000219
_0800CD24:
	movs r0, #1
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800CD62
	cmp r1, #0
	bne _0800CD38
	ldr r0, _0800CD6C @ =0x00000219
	bl PlaySound_082406e0
_0800CD38:
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
_0800CD62:
	movs r0, #0
_0800CD64:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800CD6C: .4byte 0x00000219

	thumb_func_start FUN_0800cd70
FUN_0800cd70: @ 0x0800CD70
	push {lr}
	adds r2, r1, #0
	ldrb r3, [r2, #3]
	cmp r3, #0
	beq _0800CD7E
	movs r0, #0
	b _0800CDAE
_0800CD7E:
	movs r0, #2
	movs r1, #2
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldrb r0, [r2, #2]
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2, #2]
	strh r3, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #1
_0800CDAE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800cdb4
FUN_0800cdb4: @ 0x0800CDB4
	push {r4, lr}
	adds r2, r1, #0
	ldrh r1, [r2, #0x3e]
	subs r1, #1
	movs r3, #0
	strh r1, [r2, #0x3e]
	movs r4, #0xa
	movs r0, #0xa
	strh r0, [r2, #0x3a]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _0800CE02
	strh r3, [r2, #0x3e]
	ldrb r0, [r2, #3]
	cmp r0, #1
	bhi _0800CE18
	ldrb r1, [r2, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #2]
	movs r0, #6
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #0x85
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #1
	b _0800CE1A
_0800CE02:
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _0800CE20 @ =0x00000217
	bl PlaySound_082406e0
_0800CE18:
	movs r0, #0
_0800CE1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800CE20: .4byte 0x00000217

	thumb_func_start FUN_0800ce24
FUN_0800ce24: @ 0x0800CE24
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _0800CF14
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r3, r6, r0
	ldr r0, _0800CE60 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CE5C
	cmp r1, #0
	blt _0800CE5C
	ldr r0, _0800CE64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CE5C
	ldr r0, _0800CE68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CE6C
_0800CE5C:
	movs r0, #0
	b _0800CE7A
	.align 2, 0
_0800CE60: .4byte 0x03002BE0
_0800CE64: .4byte 0x030046A8
_0800CE68: .4byte 0x030046AC
_0800CE6C:
	ldr r0, _0800CEA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800CE7A:
	ldrh r1, [r3, #2]
	movs r2, #2
	bl FUN_08232888
	cmp r0, #0
	blt _0800CF04
	adds r1, r6, #0
	adds r1, #0x31
	strb r0, [r1]
	ldr r0, [r6, #0x20]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CEA4
	adds r0, r6, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r7, r0, #0
	b _0800CEAE
	.align 2, 0
_0800CEA0: .4byte 0x030046A4
_0800CEA4:
	adds r1, r6, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	adds r7, r1, #0
_0800CEAE:
	adds r0, r6, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800CF04
	movs r5, #4
	ldrb r1, [r6, #2]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	strb r5, [r6, #3]
	str r4, [r6, #4]
	movs r0, #1
	strb r0, [r6, #1]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bne _0800CEF4
	ldr r0, _0800CEF0 @ =0x00000216
	bl PlaySound_082406e0
	b _0800CEFA
	.align 2, 0
_0800CEF0: .4byte 0x00000216
_0800CEF4:
	ldr r0, _0800CF00 @ =0x00000215
	bl PlaySound_082406e0
_0800CEFA:
	movs r0, #1
	b _0800CF24
	.align 2, 0
_0800CF00: .4byte 0x00000215
_0800CF04:
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF10 @ =0x00000217
	bl PlaySound_082406e0
	b _0800CF22
	.align 2, 0
_0800CF10: .4byte 0x00000217
_0800CF14:
	cmp r0, #1
	bne _0800CF22
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF2C @ =0x00000217
	bl PlaySound_082406e0
_0800CF22:
	movs r0, #0
_0800CF24:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CF2C: .4byte 0x00000217

	thumb_func_start FUN_0800cf30
FUN_0800cf30: @ 0x0800CF30
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	cmp r2, #0
	blt _0800CF44
	movs r1, #1
	ldr r0, [r4, #4]
	ands r0, r1
	ands r1, r2
	cmp r1, r0
	bne _0800CF7E
_0800CF44:
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0, #2]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800CF60
	adds r0, #4
	b _0800CF6C
_0800CF60:
	ldr r0, _0800CF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800CF6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	subs r0, r0, r1
	cmp r0, #0xff
	bgt _0800CF88
_0800CF7E:
	movs r0, #0
	b _0800CF96
	.align 2, 0
_0800CF84: .4byte 0x030046A4
_0800CF88:
	movs r0, #0
	strh r1, [r4, #0x32]
	movs r1, #5
	strb r1, [r4, #3]
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800CF96:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800cf9c
FUN_0800cf9c: @ 0x0800CF9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800CFBE
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
_0800CFBE:
	ldrh r0, [r4, #0x2a]
	movs r1, #1
	orrs r1, r0
	strh r1, [r4, #0x2a]
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D062
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CFE4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800CFE4:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CFFC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800CFFC:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D014
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D014:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D02C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D02C:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D036
	movs r0, #0x78
	b _0800D05C
_0800D036:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D044
	movs r0, #0x7b
	b _0800D05C
_0800D044:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D050
	movs r0, #0x7c
	b _0800D05C
_0800D050:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D05C
	movs r0, #0x79
_0800D05C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D06C
_0800D062:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D06C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d074
FUN_0800d074: @ 0x0800D074
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D086
	movs r0, #0
	strb r0, [r4, #1]
_0800D086:
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D122
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D0A4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800D0A4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D0BC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800D0BC:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D0D4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D0D4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D0EC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D0EC:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D0F6
	movs r0, #0x78
	b _0800D11C
_0800D0F6:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D104
	movs r0, #0x7b
	b _0800D11C
_0800D104:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D110
	movs r0, #0x7c
	b _0800D11C
_0800D110:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D11C
	movs r0, #0x79
_0800D11C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D12C
_0800D122:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D12C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d134
FUN_0800d134: @ 0x0800D134
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D14A
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x86
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0800D14A:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D174
	strh r2, [r4, #0x34]
	movs r0, #1
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r0, [r4, #1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
_0800D174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d17c
FUN_0800d17c: @ 0x0800D17C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D192
	movs r0, #0
	strb r0, [r4, #1]
	ldr r0, _0800D1C8 @ =0x0000021A
	bl PlaySound_082406e0
_0800D192:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r3, #0x20
	ldrsh r0, [r5, r3]
	adds r1, r1, r0
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	cmp r0, r1
	blt _0800D1C0
	strh r1, [r4, #0x34]
	strb r2, [r4, #3]
	movs r0, #0
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800D1C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D1C8: .4byte 0x0000021A

	thumb_func_start FUN_0800d1cc
FUN_0800d1cc: @ 0x0800D1CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D1E6
	movs r0, #0
	strb r0, [r4, #1]
_0800D1E6:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x31
	mov r5, sp
	ldrb r6, [r0]
	ldr r2, _0800D214 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D218
	asrs r1, r0, #0xc
	b _0800D21E
	.align 2, 0
_0800D214: .4byte 0x085B0A08
_0800D218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D21E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _0800D238
	asrs r0, r0, #0xc
	b _0800D23E
_0800D238:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D23E:
	strh r0, [r5, #4]
	adds r2, r3, #0
	adds r2, #8
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r3, #8]
	adds r0, r0, r5
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r1, [r1, #4]
	ldrh r0, [r2, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldrh r0, [r3, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0800D282
	cmp r1, #0
	blt _0800D282
	ldr r0, _0800D288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D282
	ldr r0, _0800D28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D290
_0800D282:
	movs r0, #0
	b _0800D29E
	.align 2, 0
_0800D288: .4byte 0x030046A8
_0800D28C: .4byte 0x030046AC
_0800D290:
	ldr r0, _0800D2E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D29E:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r6, #0
	movs r7, #0
	strh r0, [r2]
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bls _0800D358
	ldrh r2, [r3, #8]
	ldr r1, _0800D2EC @ =0xFFFFFF00
	adds r0, r1, #0
	ands r0, r2
	adds r0, #0x80
	strh r0, [r3, #8]
	ldrh r0, [r3, #0xc]
	ands r1, r0
	adds r1, #0x80
	strh r1, [r3, #0xc]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0800D2F0
	strb r6, [r4, #3]
	str r7, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
	subs r0, #6
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	b _0800D326
	.align 2, 0
_0800D2E8: .4byte 0x030046A4
_0800D2EC: .4byte 0xFFFFFF00
_0800D2F0:
	adds r0, r4, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800D302
	movs r0, #4
	strb r0, [r4, #3]
	str r7, [r4, #4]
	b _0800D322
_0800D302:
	strb r6, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	movs r2, #1
	rsbs r2, r2, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0800cf30
	cmp r0, #0
	bne _0800D326
	strb r6, [r4, #3]
	str r0, [r4, #4]
_0800D322:
	movs r0, #1
	strb r0, [r4, #1]
_0800D326:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D330
	movs r0, #0x78
	b _0800D356
_0800D330:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D33E
	movs r0, #0x7b
	b _0800D356
_0800D33E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D34A
	movs r0, #0x7c
	b _0800D356
_0800D34A:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D356
	movs r0, #0x79
_0800D356:
	strh r0, [r4, #0x2e]
_0800D358:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800d364
FUN_0800d364: @ 0x0800D364
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r5, r2, r0
	adds r4, r2, #0
	adds r4, #0x48
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0800D37C
	movs r0, #0
	strb r0, [r2, #1]
_0800D37C:
	ldrh r0, [r2, #0x2a]
	movs r1, #0x10
	movs r6, #0
	orrs r1, r0
	strh r1, [r2, #0x2a]
	ldrh r0, [r4, #0xa]
	subs r0, #0x10
	strh r0, [r4, #0xa]
	ldrh r3, [r2, #0x32]
	lsls r0, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	bge _0800D3EA
	strh r3, [r4, #0xa]
	asrs r0, r1, #0x18
	movs r1, #0xf
	ands r0, r1
	adds r3, r0, #1
	cmp r3, #0xf
	ble _0800D3A6
	movs r3, #0xf
_0800D3A6:
	ldrb r0, [r5, #4]
	movs r1, #0xf0
	ands r1, r0
	orrs r1, r3
	strb r1, [r5, #4]
	movs r0, #2
	ldrb r1, [r2, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800D3DC
	movs r1, #1
	strb r1, [r2, #3]
	movs r0, #0
	str r0, [r2, #4]
	strb r1, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
	ldr r0, _0800D3D8 @ =0x00000143
	bl PlaySound_082406e0
	b _0800D3EA
	.align 2, 0
_0800D3D8: .4byte 0x00000143
_0800D3DC:
	strb r6, [r2, #3]
	str r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldr r0, _0800D3F0 @ =0x0000021B
	bl PlaySound_082406e0
_0800D3EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D3F0: .4byte 0x0000021B

	thumb_func_start FUN_0800d3f4
FUN_0800d3f4: @ 0x0800D3F4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D42E
	movs r0, #0
	strb r0, [r4, #1]
	add r2, sp, #4
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r2, #0
	ldrh r0, [r0]
	adds r0, #0x40
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	strh r0, [r2, #4]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	movs r1, #0x90
	movs r2, #0x28
	movs r3, #8
	bl FUN_08019814
_0800D42E:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r3, #0
	orrs r1, r0
	strh r1, [r4, #0x2a]
	ldr r2, [r4, #4]
	cmp r2, #0xf
	bhi _0800D448
	movs r0, #7
	ands r0, r2
	cmp r0, #4
	bne _0800D456
	b _0800D450
_0800D448:
	movs r0, #3
	ands r0, r2
	cmp r0, #2
	bne _0800D456
_0800D450:
	movs r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0x2a]
_0800D456:
	cmp r2, #0x1f
	bls _0800D462
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
_0800D462:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d46c
FUN_0800d46c: @ 0x0800D46C
	movs r0, #0
	strh r0, [r1, #0x2a]
	ldrb r0, [r1, #3]
	adds r2, r1, #0
	adds r2, #0x45
	strb r0, [r2]
	ldrb r0, [r1, #2]
	adds r1, #0x46
	strb r0, [r1]
	bx lr

	thumb_func_start FUN_0800d480
FUN_0800d480: @ 0x0800D480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	adds r5, r1, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800D4C6
	cmp r1, #0
	blt _0800D4C6
	ldr r0, _0800D4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D4C6
	ldr r0, _0800D4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D4D4
_0800D4C6:
	movs r0, #0
	b _0800D4E2
	.align 2, 0
_0800D4CC: .4byte 0x030046A8
_0800D4D0: .4byte 0x030046AC
_0800D4D4:
	ldr r0, _0800D508 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D4E2:
	movs r1, #1
	bl FUN_08234224
	adds r0, r5, #0
	adds r0, #0x48
	bl FUN_0823b4b8
	ldrh r1, [r5, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D50C
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D508: .4byte 0x030046A4
_0800D50C:
	ldrb r0, [r5, #3]
	cmp r0, #1
	bne _0800D530
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	ldr r1, _0800D52C @ =0x0000FFFD
	ands r1, r0
	strh r1, [r2]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D52C: .4byte 0x0000FFFD
_0800D530:
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_0800D53C:
	movs r2, #1
	ldrb r0, [r5, #2]
	ands r0, r2
	cmp r0, #0
	beq _0800D5B0
	mov r4, r8
	movs r6, #0x24
	ldrsh r0, [r4, r6]
	cmp r0, #0xf
	ble _0800D558
	ldrh r1, [r5, #0x2a]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D558:
	ldrh r1, [r5, #0x38]
	movs r3, #0x38
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _0800D5B0
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _0800D5B0
	subs r0, r1, #1
	strh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800D5B0
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r5, #2]
	ands r0, r1
	strb r0, [r5, #2]
	cmp r0, #0
	bne _0800D58A
	movs r0, #0x78
	b _0800D5AE
_0800D58A:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D598
	movs r0, #0x7b
	b _0800D5AE
_0800D598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D5A4
	movs r0, #0x7c
	b _0800D5AE
_0800D5A4:
	ands r1, r2
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D5AE
	movs r0, #0x79
_0800D5AE:
	strh r0, [r5, #0x2e]
_0800D5B0:
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #0xc
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5C8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D5FC
_0800D5C8:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0xc4
	mov r6, sl
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	movs r1, #1
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5FC
	mov r2, r8
	ldrh r0, [r2, #0x20]
	ldrh r3, [r5, #0x36]
	adds r0, r0, r3
	strh r0, [r5, #0x34]
_0800D5FC:
	adds r4, r5, #0
	adds r4, #0xf0
	movs r1, #4
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D614
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D658
_0800D614:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r6, #0x86
	lsls r6, r6, #1
	adds r2, r5, r6
	mov r3, sl
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sb
	ldrh r6, [r0, #2]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800D642
	adds r0, #4
	b _0800D64E
_0800D642:
	ldr r0, _0800D6AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800D64E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r4, #0x1e]
_0800D658:
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	beq _0800D66C
	subs r0, #1
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x3c]
	ldrh r1, [r5, #0x2a]
	movs r0, #2
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D66C:
	movs r1, #2
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D720
	ldr r2, _0800D6B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800D6B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800D6B8 @ =0x0203B400
	adds r0, r0, r1
	add r4, sp, #0x20
	ldrh r3, [r0]
	ldrh r6, [r5, #0x3c]
	ldr r2, _0800D6BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _0800D6C0
	asrs r1, r0, #0xc
	b _0800D6C6
	.align 2, 0
_0800D6AC: .4byte 0x030046A4
_0800D6B0: .4byte 0x030046B8
_0800D6B4: .4byte 0x000003FF
_0800D6B8: .4byte 0x0203B400
_0800D6BC: .4byte 0x085B0A08
_0800D6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D6C6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0800D6E2
	asrs r0, r0, #0xc
	b _0800D6E8
_0800D6E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D6E8:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xc4
	add r0, sp, #0x20
	ldrh r4, [r0]
	ldrh r3, [r1]
	adds r0, r4, r3
	strh r0, [r1]
	ldrh r3, [r7, #2]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r2, [r7, #4]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r6, [r0]
	adds r4, r4, r6
	strh r4, [r0]
	ldrh r1, [r0, #2]
	adds r3, r3, r1
	strh r3, [r0, #2]
	ldrh r3, [r0, #4]
	adds r2, r2, r3
	strh r2, [r0, #4]
_0800D720:
	movs r6, #0x96
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0x10
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D738
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D738:
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r1, r5, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D75A
	subs r0, #1
	strb r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D75A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_0800D762:
	strh r0, [r4, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x20
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D7E4
	ldr r0, [r5, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800D7A8
	ldr r3, _0800D7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0800D7A4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0800D7C6
	.align 2, 0
_0800D7A0: .4byte 0xFFFF0000
_0800D7A4: .4byte 0x0000FFFF
_0800D7A8:
	ldr r3, _0800D82C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _0800D830 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x90
_0800D7C6:
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0800D7E4:
	adds r0, r5, #0
	adds r0, #0x45
	ldrb r0, [r0]
	ldrb r1, [r5, #3]
	cmp r0, r1
	beq _0800D7FE
	cmp r1, #0
	beq _0800D7FE
	ldr r0, _0800D834 @ =0xFFFFFDFF
	mov r2, sb
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0800D7FE:
	adds r1, r5, #0
	adds r1, #0x41
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D838
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800D85A
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
	.align 2, 0
_0800D82C: .4byte 0xFFFF0000
_0800D830: .4byte 0x0000FFFF
_0800D834: .4byte 0xFFFFFDFF
_0800D838:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
_0800D850:
	cmp r0, #0x7a
	bne _0800D85A
	mov r0, r8
	adds r0, #0x54
_0800D858:
	str r0, [r4, #0xc]
_0800D85A:
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r3, [r5, #2]
	ldrb r1, [r2]
	cmp r3, r1
	beq _0800D8AC
	ldr r6, [r5, #8]
	cmp r6, #0
	beq _0800D8AC
	mov r4, sl
	ldrh r0, [r4]
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	bics r0, r1
	str r0, [sp, #8]
	ldrb r0, [r2]
	bics r0, r3
	str r0, [sp, #0xc]
	add r4, sp, #0x30
	adds r3, r5, #0
	adds r3, #0xc
	add r2, sp, #0x10
	movs r1, #3
_0800D88A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800D88A
	ldr r0, _0800D8C4 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	bl Script_ExecById
_0800D8AC:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D8C4: .4byte 0xFFFF0000

	thumb_func_start FUN_0800d8c8
FUN_0800d8c8: @ 0x0800D8C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0800D8F0 @ =0x085B0A08
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D8F4
	asrs r0, r0, #0xc
	b _0800D8FA
	.align 2, 0
_0800D8F0: .4byte 0x085B0A08
_0800D8F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D8FA:
	strh r0, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r4, [r5, #0x74]
	movs r7, #0
	ldr r0, [r5, #0x1c]
	movs r1, #0x34
	adds r1, r1, r5
	mov r8, r1
	adds r2, r5, #0
	adds r2, #0x54
	str r2, [sp, #4]
	movs r1, #0x23
	adds r1, r1, r5
	mov sl, r1
	cmp r7, r0
	bhs _0800D976
	ldr r2, _0800D9B8 @ =0x085AA774
	mov sb, r2
_0800D926:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d46c
	ldrb r0, [r4, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d480
	adds r6, r4, #0
	adds r6, #0x44
	ldrb r0, [r6]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cb7c
	movs r0, #0
	strb r0, [r6]
_0800D968:
	adds r7, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r5, #0x1c]
	cmp r7, r0
	blo _0800D926
_0800D976:
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2c]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	movs r4, #5
	str r4, [sp]
	mov r0, r8
	bl rgb555_08237468
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x30]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	str r4, [sp]
	ldr r0, [sp, #4]
	bl rgb555_08237468
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D9BC
	ldrh r0, [r5, #0x24]
	adds r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800D9D0
	movs r0, #0x20
	strh r0, [r5, #0x24]
	movs r0, #1
	b _0800D9CE
	.align 2, 0
_0800D9B8: .4byte 0x085AA774
_0800D9BC:
	ldrh r0, [r5, #0x24]
	subs r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D9D0
	movs r0, #0
	strh r0, [r5, #0x24]
	mov r1, sl
_0800D9CE:
	strb r0, [r1]
_0800D9D0:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800d9e4
FUN_0800d9e4: @ 0x0800D9E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x74]
	movs r6, #0
	b _0800D9FE
_0800D9EE:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800cb7c
	adds r6, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r5, r5, r0
_0800D9FE:
	ldr r0, [r4, #0x1c]
	cmp r6, r0
	blo _0800D9EE
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _0800DA12
	bl Free
	movs r0, #0
	str r0, [r4, #0x74]
_0800DA12:
	ldr r1, _0800DA20 @ =0x03002B38
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0800DA20: .4byte 0x03002B38

	thumb_func_start FUN_0800da24
FUN_0800da24: @ 0x0800DA24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800DA4C @ =0x03002B38
	str r5, [r0]
	movs r4, #0
	str r4, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #2
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x74]
	cmp r2, #0
	bne _0800DA50
	movs r0, #1
	rsbs r0, r0, #0
	b _0800DAB8
	.align 2, 0
_0800DA4C: .4byte 0x03002B38
_0800DA50:
	ldr r0, [r5, #0x1c]
	lsls r1, r0, #7
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r2, #0
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x23
	strb r4, [r0]
	strh r4, [r5, #0x24]
	ldr r0, _0800DAC0 @ =0x03003584
	ldr r1, [r0]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r0, r1, r2
	str r0, [r5, #0x28]
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r1, r3
	str r2, [r5, #0x2c]
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x34
	ldr r4, _0800DAC4 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x28]
	adds r1, r5, #0
	adds r1, #0x54
	adds r2, r4, #0
	bl CpuSet
	ldr r1, [r5, #0x74]
	movs r2, #0
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	bhs _0800DAB6
	movs r4, #0
	movs r3, #0xfe
	lsls r3, r3, #1
_0800DAAA:
	strb r4, [r1]
	adds r2, #1
	adds r1, r1, r3
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	blo _0800DAAA
_0800DAB6:
	movs r0, #0
_0800DAB8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800DAC0: .4byte 0x03003584
_0800DAC4: .4byte 0x04000008

	thumb_func_start FUN_0800dac8
FUN_0800dac8: @ 0x0800DAC8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0800cb70
	adds r4, r0, #0
	cmp r4, #0
	bne _0800DB16
	movs r0, #9
	movs r1, #0x78
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800DB14
	ldr r1, _0800DB0C @ =FUN_0800d8c8
	ldr r2, _0800DB10 @ =FUN_0800d9e4
	bl SetEntityRoutine
	movs r0, #0x6d
	movs r1, #4
	bl Script_GetKeywordValue
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800da24
	cmp r0, #0
	bge _0800DB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800DB16
	.align 2, 0
_0800DB0C: .4byte FUN_0800d8c8
_0800DB10: .4byte FUN_0800d9e4
_0800DB14:
	adds r0, r4, #0
_0800DB16:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db1c
FUN_0800db1c: @ 0x0800DB1C
	push {r4, lr}
	ldr r1, [r0, #0x74]
	movs r2, #0
	ldr r0, [r0, #0x1c]
	cmp r2, r0
	bhs _0800DB40
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r3, r0, #0
_0800DB2E:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800DB38
	adds r0, r1, #0
	b _0800DB42
_0800DB38:
	adds r2, #1
	adds r1, r1, r4
	cmp r2, r3
	blo _0800DB2E
_0800DB40:
	movs r0, #0
_0800DB42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db48
FUN_0800db48: @ 0x0800DB48
	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, [r0, #0x74]
	movs r3, #0
	ldr r0, [r0, #0x1c]
	cmp r3, r0
	bhs _0800DB78
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r1, r0, #0
_0800DB5C:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0800DB70
	adds r0, r2, #0
	adds r0, #0x48
	ldrh r0, [r0]
	cmp r0, r4
	bne _0800DB70
	adds r0, r2, #0
	b _0800DB7A
_0800DB70:
	adds r3, #1
	adds r2, r2, r5
	cmp r3, r1
	blo _0800DB5C
_0800DB78:
	movs r0, #0
_0800DB7A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800db80
FUN_0800db80: @ 0x0800DB80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	bl FUN_0800cb70
	str r0, [sp, #0x24]
	cmp r0, #0
	beq _0800DBB8
	ldr r0, [sp, #0x24]
	bl FUN_0800db1c
	adds r5, r0, #0
	cmp r5, #0
	beq _0800DBB8
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	ldr r0, [sp, #0x24]
	mov r1, r8
	bl FUN_0800db48
	cmp r0, #0
	beq _0800DBBE
_0800DBB8:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E0C0
_0800DBBE:
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800DBEE
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800DBEE
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DBE4
	movs r2, #1
	b _0800DBF0
_0800DBE4:
	movs r0, #4
	ands r1, r0
	movs r2, #6
	cmp r1, #0
	beq _0800DBF0
_0800DBEE:
	movs r2, #0
_0800DBF0:
	movs r0, #0
	strb r2, [r5, #3]
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800DC40
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800DC38 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800DC3C @ =0x0000FFFF
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
	b _0800DC4A
	.align 2, 0
_0800DC38: .4byte 0xFFFF0000
_0800DC3C: .4byte 0x0000FFFF
_0800DC40:
	ldr r1, _0800DCA0 @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800DC4A:
	ldr r0, _0800DCA4 @ =0xFFFFFF00
	adds r3, r0, #0
	add r0, sp, #0xc
	ldrh r1, [r0]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r2, _0800DCA0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r6, sp, #0xc
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DC9C
	cmp r1, #0
	blt _0800DC9C
	ldr r0, _0800DCA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DC9C
	ldr r0, _0800DCAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DCB0
_0800DC9C:
	movs r4, #0
	b _0800DCBE
	.align 2, 0
_0800DCA0: .4byte 0xFFFF0000
_0800DCA4: .4byte 0xFFFFFF00
_0800DCA8: .4byte 0x030046A8
_0800DCAC: .4byte 0x030046AC
_0800DCB0:
	ldr r0, _0800DCD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800DCBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800DCD4
	adds r0, #4
	b _0800DCE0
	.align 2, 0
_0800DCD0: .4byte 0x030046A4
_0800DCD4:
	ldr r0, _0800DCF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DCE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800DCF8
	cmp r2, #2
	beq _0800DCFC
	b _0800DD00
	.align 2, 0
_0800DCF4: .4byte 0x030046A4
_0800DCF8:
	ldrb r0, [r6, #4]
	b _0800DCFE
_0800DCFC:
	ldrb r0, [r6]
_0800DCFE:
	subs r1, r1, r0
_0800DD00:
	add r0, sp, #0xc
	strh r1, [r0, #2]
	movs r0, #0x50
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r5, #8]
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _0800DD8A
	adds r6, r5, #0
	adds r6, #0xc
	adds r1, r5, #0
	adds r1, #0x42
	str r1, [sp, #0x48]
	adds r2, r5, #0
	adds r2, #0x30
	str r2, [sp, #0x38]
	adds r3, r5, #0
	adds r3, #0x31
	str r3, [sp, #0x3c]
	adds r4, r5, #0
	adds r4, #0x40
	str r4, [sp, #0x40]
	adds r0, r5, #0
	adds r0, #0x41
	str r0, [sp, #0x44]
	adds r1, #0x66
	str r1, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r2, #0xc0
	str r2, [sp, #0x28]
	movs r3, #0xd4
	adds r3, r3, r5
	mov sb, r3
	movs r4, #0x86
	lsls r4, r4, #1
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	mov r1, r8
	lsls r1, r1, #0x10
	str r1, [sp, #0x34]
	subs r2, #0xa0
	str r2, [sp, #0x4c]
	add r3, sp, #0x14
	mov r8, r3
	mov r4, sp
	adds r4, #0x1c
	str r4, [sp, #0x30]
	adds r4, r6, #0
_0800DD70:
	bl VM_GetPC
	cmp r0, #0
	beq _0800DD7C
	bl Script_GetValue
_0800DD7C:
	str r0, [r4]
	adds r4, #4
	adds r0, r6, #0
	adds r0, #0xc
	cmp r4, r0
	ble _0800DD70
	b _0800DDEC
_0800DD8A:
	adds r0, r5, #0
	adds r0, #0x42
	str r0, [sp, #0x48]
	adds r1, r5, #0
	adds r1, #0x30
	str r1, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x31
	str r2, [sp, #0x3c]
	adds r3, r5, #0
	adds r3, #0x40
	str r3, [sp, #0x40]
	adds r4, r5, #0
	adds r4, #0x41
	str r4, [sp, #0x44]
	adds r0, #0x66
	str r0, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r1, #0xc0
	str r1, [sp, #0x28]
	movs r2, #0xd4
	adds r2, r2, r5
	mov sb, r2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #0x2c]
	movs r4, #0x48
	adds r4, r4, r5
	mov sl, r4
	mov r0, r8
	lsls r0, r0, #0x10
	str r0, [sp, #0x34]
	subs r1, #0xa0
	str r1, [sp, #0x4c]
	add r2, sp, #0x14
	mov r8, r2
	mov r3, sp
	adds r3, #0x1c
	str r3, [sp, #0x30]
	subs r1, #0x44
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x18
_0800DDE4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800DDE4
_0800DDEC:
	movs r4, #0
	str r4, [r5, #0x1c]
	str r4, [r5, #0x20]
	str r4, [r5, #0x24]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x28]
	strh r4, [r5, #0x2a]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0800DE12
	add r0, sp, #0xc
	bl FUN_08241574
_0800DE12:
	strh r0, [r5, #0x2c]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _0800DE1E
	movs r0, #0x78
	b _0800DE44
_0800DE1E:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800DE2C
	movs r0, #0x7b
	b _0800DE44
_0800DE2C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800DE38
	movs r0, #0x7c
	b _0800DE44
_0800DE38:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800DE44
	movs r0, #0x79
_0800DE44:
	strh r0, [r5, #0x2e]
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x46
	bl Script_GetKeywordValue
	adds r2, r0, #0
	ldr r4, [sp, #0x48]
	strh r2, [r4]
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800DE64
	strh r2, [r5, #0x38]
	b _0800DE66
_0800DE64:
	strh r1, [r5, #0x38]
_0800DE66:
	movs r0, #0
	movs r2, #0
	strh r2, [r5, #0x3a]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	add r0, sp, #0xc
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x32]
	movs r1, #0x28
	strh r1, [r5, #0x36]
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DE88
	cmp r0, #3
	bne _0800DE8C
_0800DE88:
	strh r2, [r5, #0x34]
	b _0800DE8E
_0800DE8C:
	strh r1, [r5, #0x34]
_0800DE8E:
	movs r0, #0x6c
	movs r1, #1
	bl Script_GetKeywordValue
	movs r1, #0
	strh r0, [r5, #0x3e]
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r6, [sp, #0x50]
	ldr r1, _0800DEC0 @ =0x0000BCA8
	adds r0, r7, #0
	bl FUN_0822b16c
	ldrh r1, [r5, #0x2e]
	adds r0, r7, #0
	bl FUN_0822b20c
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800DEC4
	ldr r0, [sp, #0x24]
	adds r0, #0x34
	b _0800DECC
	.align 2, 0
_0800DEC0: .4byte 0x0000BCA8
_0800DEC4:
	cmp r0, #0x7a
	bne _0800DECE
	ldr r0, [sp, #0x24]
	adds r0, #0x54
_0800DECC:
	str r0, [r7, #0xc]
_0800DECE:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r6, #0x10]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
	ldr r6, [sp, #0x28]
	ldr r1, _0800DF3C @ =0x0000BCA8
	mov r0, sb
	bl FUN_0822b16c
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, #0
	mov r1, sb
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	add r0, sp, #0xc
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DF38
	cmp r1, #0
	blt _0800DF38
	ldr r0, _0800DF40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DF38
	ldr r0, _0800DF44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DF48
_0800DF38:
	movs r6, #0
	b _0800DF56
	.align 2, 0
_0800DF3C: .4byte 0x0000BCA8
_0800DF40: .4byte 0x030046A8
_0800DF44: .4byte 0x030046AC
_0800DF48:
	ldr r0, _0800DF68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_0800DF56:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800DF6C
	adds r0, #4
	b _0800DF78
	.align 2, 0
_0800DF68: .4byte 0x030046A4
_0800DF6C:
	ldr r0, _0800E0D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DF78:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800DF84
	adds r3, #1
_0800DF84:
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #0xff
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08234270
	ldrh r0, [r4]
	movs r6, #2
	movs r7, #0
	orrs r0, r6
	strh r0, [r4]
	mov r4, sl
	ldr r2, [sp, #0x34]
	lsrs r1, r2, #0x10
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #0xc
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	ldr r1, [sp, #0x50]
	bl FUN_0823b46c
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DFD4
	adds r1, r5, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
_0800DFD4:
	mov r3, sl
	ldrh r1, [r3]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [sp, #0x4c]
	str r2, [r0]
	ldr r2, _0800E0D4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800E0D8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r4, r8
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x1c]
	ldr r1, [sp, #0x30]
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r6, r5, r2
	mov r3, sl
	ldrh r1, [r3]
	ldr r2, _0800E0DC @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	ldr r4, [sp, #0x30]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E0E0 @ =FUN_0800cbd0
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	bl FUN_08236400
	movs r1, #0x90
	add r0, sp, #0x14
	strh r1, [r0]
	movs r0, #0x80
	mov r2, r8
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r6, r5, r3
	mov r4, sl
	ldrh r1, [r4]
	ldr r2, _0800E0E4 @ =0x00002801
	movs r4, #1
	str r4, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r3, [sp, #0x30]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E0E8 @ =FUN_0800cc04
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r6, #0
	movs r1, #0x32
	movs r2, #0
	bl FUN_082364f0
	ldr r0, _0800E0EC @ =0x00010100
	str r0, [r6, #0x34]
	movs r0, #4
	str r0, [r6, #0x38]
	ldrh r0, [r5, #0x28]
	ands r4, r0
	cmp r4, #0
	bne _0800E0BA
	mov r0, sl
	bl FUN_08002a48
	cmp r0, #0
	bge _0800E0BA
	ldrh r0, [r5, #0x28]
	movs r1, #1
	orrs r0, r1
	strh r0, [r5, #0x28]
_0800E0BA:
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
_0800E0C0:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E0D0: .4byte 0x030046A4
_0800E0D4: .4byte 0xFFFF0000
_0800E0D8: .4byte 0x0000FFFF
_0800E0DC: .4byte 0x00004041
_0800E0E0: .4byte FUN_0800cbd0
_0800E0E4: .4byte 0x00002801
_0800E0E8: .4byte FUN_0800cc04
_0800E0EC: .4byte 0x00010100

	thumb_func_start FUN_0800e0f0
FUN_0800e0f0: @ 0x0800E0F0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r5, #0
	adds r0, r2, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800E122
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800E118
	ldr r1, [r2, #0x70]
	ldr r0, [r3, #0x34]
	cmp r1, r0
	bne _0800E124
	b _0800E122
_0800E118:
	ldr r0, [r2, #0x70]
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800E124
_0800E122:
	movs r5, #1
_0800E124:
	movs r4, #0
	adds r0, r2, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0800E150
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E146
	ldr r1, [r2, #0x74]
	ldr r0, [r3, #0x38]
	cmp r1, r0
	bne _0800E152
	b _0800E150
_0800E146:
	ldr r0, [r2, #0x74]
	ldr r1, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0800E152
_0800E150:
	movs r4, #1
_0800E152:
	cmp r5, #0
	beq _0800E16C
	cmp r4, #0
	beq _0800E16C
	ldrh r0, [r3, #0x3e]
	ldrh r1, [r6, #0x3e]
	adds r0, r0, r1
	strh r0, [r6, #0x3e]
	adds r2, #0x84
	ldr r0, [r3, #0xc]
	ldr r1, [r3, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
_0800E16C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800e174
FUN_0800e174: @ 0x0800E174
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x18
	adds r1, r4, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E194
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #0x1e]
	movs r0, #4
	orrs r0, r1
	b _0800E19A
_0800E194:
	ldrh r1, [r4, #0x1e]
	ldr r0, _0800E204 @ =0x0000FFFB
	ands r0, r1
_0800E19A:
	strh r0, [r4, #0x1e]
	ldrh r0, [r6, #0x3e]
	cmp r0, #0
	beq _0800E246
	adds r0, r4, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x6a
	ldrh r0, [r5]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800E212
	adds r1, r4, #0
	adds r1, #0x82
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E1EE
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0xc
	bl Script_ExecById
_0800E1EE:
	adds r0, r4, #0
	adds r0, #0x6e
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800E208
	adds r0, r4, #0
	bl KillEntity
	b _0800E242
	.align 2, 0
_0800E204: .4byte 0x0000FFFB
_0800E208:
	adds r0, r4, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	strh r0, [r5]
	b _0800E242
_0800E212:
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	cmp r0, #0
	beq _0800E242
	adds r0, r4, #0
	adds r0, #0x84
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0x86
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x88
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	ldrh r0, [r1]
	add r1, sp, #0x14
	bl Script_ExecById
_0800E242:
	movs r0, #0
	strh r0, [r6, #0x3e]
_0800E246:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e250
FUN_0800e250: @ 0x0800E250
	push {lr}
	adds r0, #0x18
	bl FUN_08236424
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e260
FUN_0800e260: @ 0x0800E260
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, #0x68
	strh r6, [r0]
	movs r0, #0x6c
	movs r1, #0x64
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x6c
	strh r0, [r1]
	subs r1, #2
	strh r0, [r1]
	movs r0, #0x53
	movs r1, #0x10
	bl Script_GetKeywordValue
	str r0, [r5, #0x78]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800E2D0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E2C8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E2CC @ =0x0000FFFF
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
	b _0800E2DA
	.align 2, 0
_0800E2C8: .4byte 0xFFFF0000
_0800E2CC: .4byte 0x0000FFFF
_0800E2D0:
	ldr r1, _0800E31C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800E2DA:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0800E324
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E31C @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E320 @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x14
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r7, r2, #0
	b _0800E332
	.align 2, 0
_0800E31C: .4byte 0xFFFF0000
_0800E320: .4byte 0x0000FFFF
_0800E324:
	ldr r2, _0800E374 @ =0xFFFF0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r7, r1, #0
_0800E332:
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _0800E37C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E374 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E378 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r3, r2, #0
	b _0800E38A
	.align 2, 0
_0800E374: .4byte 0xFFFF0000
_0800E378: .4byte 0x0000FFFF
_0800E37C:
	ldr r2, _0800E3EC @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r3, r1, #0
_0800E38A:
	adds r4, r5, #0
	adds r4, #0x18
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800E3F0 @ =0x00004001
	ldr r0, [r5, #0x78]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0800E3F4 @ =FUN_0800e0f0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, #0x56
	strh r0, [r4]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0800E3F8
	bl Script_GetValue
	str r0, [r5, #0x70]
	b _0800E402
	.align 2, 0
_0800E3EC: .4byte 0xFFFF0000
_0800E3F0: .4byte 0x00004001
_0800E3F4: .4byte FUN_0800e0f0
_0800E3F8:
	str r0, [r5, #0x70]
	ldrh r0, [r4]
	movs r1, #8
	orrs r0, r1
	strh r0, [r4]
_0800E402:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0800E414
	bl Script_GetValue
	str r0, [r5, #0x74]
	b _0800E41E
_0800E414:
	str r0, [r5, #0x74]
	ldrh r1, [r4]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4]
_0800E41E:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x80
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x82
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	strh r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e45c
FUN_0800e45c: @ 0x0800E45C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x8c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800E494
	ldr r1, _0800E48C @ =FUN_0800e174
	ldr r2, _0800E490 @ =FUN_0800e250
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800e260
	cmp r0, #0
	bge _0800E494
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800E496
	.align 2, 0
_0800E48C: .4byte FUN_0800e174
_0800E490: .4byte FUN_0800e250
_0800E494:
	adds r0, r4, #0
_0800E496:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e49c
FUN_0800e49c: @ 0x0800E49C
	ldr r1, _0800E4A4 @ =0x03002B3C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800E4A4: .4byte 0x03002B3C

	thumb_func_start FUN_0800e4a8
FUN_0800e4a8: @ 0x0800E4A8
	push {r4, r5, lr}
	adds r1, r0, #0
	adds r5, r2, #0
	ldrb r4, [r2, #2]
	cmp r4, #0
	bne _0800E4D2
	ldr r0, [r1, #0x38]
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800E4C8
	lsls r3, r3, #1
	ldrh r0, [r2, #0x10]
	subs r0, r0, r3
	strh r0, [r2, #0x10]
_0800E4C8:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _0800E4D2
	strh r4, [r5, #0x10]
_0800E4D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e4d8
FUN_0800e4d8: @ 0x0800E4D8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800e4dc
FUN_0800e4dc: @ 0x0800E4DC
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	adds r0, r2, #0
	adds r0, #0xec
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	ldr r1, [r3, #0x1c]
	str r1, [r0]
	cmp r1, #0
	beq _0800E4FA
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E4FA:
	str r2, [r3, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800e504
FUN_0800e504: @ 0x0800E504
	push {lr}
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0xec
	ldr r2, [r0]
	adds r1, #0xf0
	ldr r1, [r1]
	cmp r2, #0
	beq _0800E51E
	adds r0, r2, #0
	adds r0, #0xf0
	str r1, [r0]
	b _0800E520
_0800E51E:
	str r1, [r3, #0x1c]
_0800E520:
	cmp r1, #0
	beq _0800E52A
	adds r0, r1, #0
	adds r0, #0xec
	str r2, [r0]
_0800E52A:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0800e530
FUN_0800e530: @ 0x0800E530
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _0800E546
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_08013c70
	movs r0, #0
	strb r0, [r4, #0xb]
_0800E546:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800e54c
FUN_0800e54c: @ 0x0800E54C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x44
	bl FUN_0822a4e0
	ldr r0, _0800E590 @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	beq _0800E564
	adds r1, r4, #0
	bl FUN_0800e504
_0800E564:
	adds r0, r4, #0
	bl FUN_0800e530
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800E57A
	bl FUN_08236424
	ldr r0, [r4, #0x20]
	bl Free
_0800E57A:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800E584
	bl Free
_0800E584:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800E590: .4byte 0x03002B3C

	thumb_func_start FUN_0800e594
FUN_0800e594: @ 0x0800E594
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0800E5EC @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800E5BE
	ldr r0, _0800E5F0 @ =0x0000C0DB
	movs r1, #0
	bl FUN_0800f110
	cmp r0, #0
	bne _0800E5BE
	b _0800E832
_0800E5BE:
	movs r0, #0xf4
	bl Malloc
	adds r6, r0, #0
	cmp r6, #0
	bne _0800E5CC
	b _0800E832
_0800E5CC:
	adds r0, r6, #0
	movs r1, #0xf4
	bl ClearMemory
	strh r4, [r6]
	movs r0, #0
	mov sb, r0
	mov r3, r8
	cmp r3, #1
	ble _0800E5F4
	movs r0, #2
	strb r0, [r6, #2]
	subs r0, #4
	add r0, r8
	mov sb, r0
	b _0800E5F8
	.align 2, 0
_0800E5EC: .4byte 0x03002B3C
_0800E5F0: .4byte 0x0000C0DB
_0800E5F4:
	mov r3, r8
	strb r3, [r6, #2]
_0800E5F8:
	movs r0, #0
	strb r0, [r6, #4]
	strh r0, [r6, #6]
	movs r2, #1
	strb r2, [r6, #3]
	strb r5, [r6, #5]
	strh r7, [r6, #8]
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E61A
	strb r2, [r6, #0xc]
	b _0800E61E
_0800E61A:
	movs r0, #0
	strb r0, [r6, #0xc]
_0800E61E:
	ldr r0, [sp, #0x48]
	strh r0, [r6, #0x12]
	adds r5, r6, #0
	adds r5, #0x18
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r5, #0
	cmp r2, #0
	blt _0800E64C
	cmp r1, #0
	blt _0800E64C
	ldr r0, _0800E650 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800E64C
	ldr r0, _0800E654 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800E658
_0800E64C:
	movs r4, #0
	b _0800E666
	.align 2, 0
_0800E650: .4byte 0x030046A8
_0800E654: .4byte 0x030046AC
_0800E658:
	ldr r0, _0800E678 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800E666:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800E67C
	adds r0, #4
	b _0800E688
	.align 2, 0
_0800E678: .4byte 0x030046A4
_0800E67C:
	ldr r0, _0800E69C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800E688:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800E6A0
	cmp r2, #2
	beq _0800E6A4
	b _0800E6A8
	.align 2, 0
_0800E69C: .4byte 0x030046A4
_0800E6A0:
	ldrb r0, [r5, #4]
	b _0800E6A6
_0800E6A4:
	ldrb r0, [r5]
_0800E6A6:
	subs r1, r1, r0
_0800E6A8:
	strh r1, [r6, #0x14]
	ldr r0, [sp, #0x4c]
	strh r0, [r6, #0x10]
	ldrb r0, [r6, #5]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0800E760
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x20]
	cmp r0, #0
	bne _0800E6C6
	b _0800E832
_0800E6C6:
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E6F4
	ldr r2, _0800E6EC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0xb4
	orrs r0, r3
	ldr r1, _0800E6F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	b _0800E706
	.align 2, 0
_0800E6EC: .4byte 0xFFFF0000
_0800E6F0: .4byte 0x0000FFFF
_0800E6F4:
	ldr r2, _0800E750 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _0800E754 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
_0800E706:
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r5, r1, #0
	ldr r0, [r6, #0x20]
	ldrh r1, [r6]
	ldr r2, _0800E758 @ =0x00004001
	movs r3, #0x10
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x20]
	ldr r1, _0800E75C @ =FUN_0800e4a8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x20]
	bl FUN_08236400
	ldr r0, [r6, #0x20]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E762
	.align 2, 0
_0800E750: .4byte 0xFFFF0000
_0800E754: .4byte 0x0000FFFF
_0800E758: .4byte 0x00004001
_0800E75C: .4byte FUN_0800e4a8
_0800E760:
	str r1, [r6, #0x20]
_0800E762:
	ldrb r1, [r6, #5]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0800E818
	movs r0, #0x50
	bl Malloc
	str r0, [r6, #0x24]
	cmp r0, #0
	beq _0800E832
	movs r1, #0x50
	bl ClearMemory
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0800E7A8
	movs r3, #0
	movs r2, #0x78
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0xa0
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x50
	b _0800E7BC
_0800E7A8:
	movs r2, #0x3c
	add r0, sp, #0x1c
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x50
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r0, sp, #0x24
	strh r3, [r0]
	movs r1, #0x28
_0800E7BC:
	strh r1, [r0, #2]
	strh r3, [r0, #4]
	adds r5, r0, #0
	movs r4, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _0800E7CC
	ldr r4, _0800E80C @ =0x00200004
_0800E7CC:
	ldr r0, [r6, #0x24]
	ldrh r1, [r6]
	ldr r2, _0800E810 @ =0x00002001
	movs r3, #0x20
	str r3, [sp]
	add r3, sp, #0x1c
	str r3, [sp, #4]
	str r5, [sp, #8]
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r6, #0x24]
	movs r3, #0x80
	lsls r3, r3, #6
	str r4, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x54]
	bl FUN_082364f8
	ldr r0, [r6, #0x24]
	ldr r1, _0800E814 @ =FUN_0800e4d8
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [r6, #0x24]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0800E81A
	.align 2, 0
_0800E80C: .4byte 0x00200004
_0800E810: .4byte 0x00002001
_0800E814: .4byte FUN_0800e4d8
_0800E818:
	str r0, [r6, #0x24]
_0800E81A:
	adds r4, r6, #0
	adds r4, #0x28
	ldr r1, _0800E838 @ =0x085AA790
	ldrb r0, [r6, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _0800E83C
_0800E832:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E8F6
	.align 2, 0
_0800E838: .4byte 0x085AA790
_0800E83C:
	adds r0, r6, #0
	adds r0, #0x44
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x4b
	movs r5, #2
	strb r5, [r0]
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x60]
	str r1, [r6, #0x64]
	mov r0, r8
	cmp r0, #1
	ble _0800E868
	ldr r1, _0800E880 @ =0x0000027B
	add r1, sb
	adds r0, r4, #0
	bl FUN_0822b20c
_0800E868:
	ldrb r1, [r6, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800E884
	ldr r0, [r6, #0x44]
	orrs r0, r5
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x78
	b _0800E894
	.align 2, 0
_0800E880: .4byte 0x0000027B
_0800E884:
	ldr r0, [r6, #0x44]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x44]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r1, #0x40
_0800E894:
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r6, #0xc]
	cmp r0, #0
	beq _0800E8B6
	adds r0, r6, #0
	adds r0, #0x70
	ldr r1, _0800E904 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800E8B6:
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x6b
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0xc8
	lsls r1, r1, #4
	str r1, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r4, #0
	str r4, [sp, #0x18]
	adds r1, r7, #0
	movs r2, #0x50
	movs r3, #7
	bl FUN_08013ba8
	strb r5, [r6, #0xb]
	strb r4, [r6, #0xd]
	adds r0, r6, #0
	adds r0, #0xec
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r0, _0800E904 @ =0x03002B3C
	ldr r0, [r0]
	adds r1, r6, #0
	bl FUN_0800e4dc
_0800E8F6:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E904: .4byte 0x03002B3C

	thumb_func_start FUN_0800e908
FUN_0800e908: @ 0x0800E908
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x50
	movs r1, #0xc8
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x46
	movs r1, #0x32
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800E9B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E9A8 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E9AC @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	b _0800E9BA
	.align 2, 0
_0800E9A8: .4byte 0xFFFF0000
_0800E9AC: .4byte 0x0000FFFF
_0800E9B0:
	ldr r1, _0800E9E4 @ =0xFFFF0000
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r1
	str r0, [sp, #0x18]
_0800E9BA:
	mov r0, r8
	str r0, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	add r0, sp, #0x14
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	mov r2, sl
	mov r3, sb
	bl FUN_0800e594
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E9E4: .4byte 0xFFFF0000

	thumb_func_start FUN_0800e9e8
FUN_0800e9e8: @ 0x0800E9E8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EA12
	movs r2, #0
	strb r2, [r4, #3]
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800EA12
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EA40 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
_0800EA12:
	ldrh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x12]
	subs r0, r0, r1
	strh r0, [r4, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #0x14]
	cmp r0, r1
	bgt _0800EA6C
	strh r1, [r4, #0x1a]
	ldrb r0, [r4, #2]
	cmp r0, #2
	bne _0800EA54
	ldrb r1, [r4, #5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800EA48
	ldr r0, _0800EA44 @ =0x0000029D
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA40: .4byte 0x03002B3C
_0800EA44: .4byte 0x0000029D
_0800EA48:
	ldr r0, _0800EA50 @ =0x000001FF
	bl PlaySound_082406e0
	b _0800EA5C
	.align 2, 0
_0800EA50: .4byte 0x000001FF
_0800EA54:
	movs r0, #0xa3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0800EA5C:
	movs r2, #1
	movs r1, #0
	strb r2, [r4, #4]
	movs r0, #0
	strh r1, [r4, #6]
	strb r2, [r4, #3]
	strb r0, [r4, #0xf]
	strb r0, [r4, #0xe]
_0800EA6C:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bls _0800EA9C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0800EA94
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EA92
	strb r1, [r4, #0xf]
_0800EA92:
	strb r1, [r4, #0xe]
_0800EA94:
	ldrb r1, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EA9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EAAC
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EAAC:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EAC2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EAC2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800eacc
FUN_0800eacc: @ 0x0800EACC
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EB30
	movs r4, #0
	strb r4, [r5, #3]
	adds r0, r5, #0
	adds r0, #0x70
	ldr r1, _0800EB78 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r2, _0800EB7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800EB80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800EB84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #8
	str r2, [sp]
	str r2, [sp, #4]
	str r4, [sp, #8]
	adds r2, #0xf8
	str r2, [sp, #0xc]
	movs r2, #0x18
	str r2, [sp, #0x10]
	movs r2, #0x10
	str r2, [sp, #0x14]
	movs r2, #9
	movs r3, #0x14
	bl FUN_080166ac
_0800EB30:
	ldrb r0, [r5, #2]
	cmp r0, #1
	bls _0800EB60
	ldrb r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0800EB58
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800EB56
	strb r1, [r5, #0xf]
_0800EB56:
	strb r1, [r5, #0xe]
_0800EB58:
	ldrb r1, [r5, #0xf]
	adds r0, r5, #0
	adds r0, #0x44
	strh r1, [r0, #0x10]
_0800EB60:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _0800EB88
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBFE
	.align 2, 0
_0800EB78: .4byte 0x03002B3C
_0800EB7C: .4byte 0x030046B8
_0800EB80: .4byte 0x000003FF
_0800EB84: .4byte 0x0203B400
_0800EB88:
	ldrh r0, [r5, #6]
	adds r1, r0, #1
	strh r1, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _0800EBA4
	movs r0, #2
	movs r1, #0
	strb r0, [r5, #4]
	strh r1, [r5, #6]
	movs r0, #1
	strb r0, [r5, #3]
	b _0800EBD8
_0800EBA4:
	ldrh r0, [r5, #6]
	movs r1, #0x1e
	subs r1, r1, r0
	asrs r2, r1, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800EBC6
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, r0, r2
	b _0800EBD6
_0800EBC6:
	adds r1, r5, #0
	adds r1, #0x60
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	adds r0, r0, r2
_0800EBD6:
	strh r0, [r1]
_0800EBD8:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800EBE8
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EBE8:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800EBFE
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800EBFE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800ec08
FUN_0800ec08: @ 0x0800EC08
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800EC80
	movs r0, #0
	strb r0, [r5, #3]
	adds r0, r5, #0
	bl FUN_0800e530
	ldr r0, _0800EC94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0800EC7C
	ldr r2, _0800EC98 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0800EC9C @ =0x0000FFF1
	orrs r0, r3
	ldr r4, _0800ECA0 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #0x18
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
_0800EC7C:
	movs r0, #0x1e
	strh r0, [r5, #8]
_0800EC80:
	ldrh r0, [r5, #6]
	cmp r0, #0xb
	bhi _0800ECA4
	ldrh r0, [r5, #0x1a]
	adds r0, #8
	strh r0, [r5, #0x1a]
	movs r0, #0x28
	bl FUN_0823b9cc
	b _0800ECB6
	.align 2, 0
_0800EC94: .4byte 0x030047A4
_0800EC98: .4byte 0xFFFF0000
_0800EC9C: .4byte 0x0000FFF1
_0800ECA0: .4byte 0x0000FFFF
_0800ECA4:
	ldrh r0, [r5, #0x1a]
	subs r0, #4
	strh r0, [r5, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, #0x14]
	cmp r0, r1
	bge _0800ECB6
	strh r1, [r5, #0x1a]
_0800ECB6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800ECC6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800ECC6:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800ECDC
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800ECDC:
	ldrh r1, [r5, #6]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bhi _0800ECF0
	ldr r0, [r5, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0800ECF8
_0800ECF0:
	ldr r0, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0800ECF8:
	str r0, [r5, #0x44]
	adds r0, r2, #1
	strh r0, [r5, #6]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #8]
	cmp r0, r1
	bls _0800ED0C
	movs r0, #1
	strb r0, [r5, #0xd]
_0800ED0C:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800ed14
FUN_0800ed14: @ 0x0800ED14
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0800ED86
	movs r0, #0
	strb r0, [r5, #3]
	ldr r0, _0800EDA4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0800ED82
	ldr r2, _0800EDA8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0800EDAC @ =0x0000FFF1
	orrs r0, r3
	ldr r4, _0800EDB0 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ands r0, r4
	movs r1, #0xb0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r2, r5, #0
	adds r2, #0x18
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
_0800ED82:
	movs r0, #0x19
	strh r0, [r5, #8]
_0800ED86:
	ldrh r0, [r5, #6]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0xe
	bhi _0800EDB4
	lsrs r1, r1, #0x12
	subs r1, #0x10
	ldrh r0, [r5, #0x1a]
	subs r0, r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x28
	bl FUN_0823b9cc
	b _0800EDD6
	.align 2, 0
_0800EDA4: .4byte 0x030047A4
_0800EDA8: .4byte 0xFFFF0000
_0800EDAC: .4byte 0x0000FFF1
_0800EDB0: .4byte 0x0000FFFF
_0800EDB4:
	ldrh r0, [r5, #6]
	adds r1, r0, #0
	subs r1, #0xf
	cmp r1, #0xf
	bgt _0800EDC4
	ldrh r0, [r5, #0x1a]
	subs r0, r0, r1
	b _0800EDC8
_0800EDC4:
	ldrh r0, [r5, #0x1a]
	subs r0, #0x10
_0800EDC8:
	strh r0, [r5, #0x1a]
	movs r1, #0x1a
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, #0x14]
	cmp r0, r1
	bge _0800EDD6
	strh r1, [r5, #0x1a]
_0800EDD6:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800EDE6
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EDE6:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0800EDFC
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r5, #0x24]
	bl FUN_08236400
_0800EDFC:
	ldrh r1, [r5, #6]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bhi _0800EE10
	ldr r0, [r5, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0800EE18
_0800EE10:
	ldr r0, [r5, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0800EE18:
	str r0, [r5, #0x44]
	adds r0, r2, #1
	strh r0, [r5, #6]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #8]
	cmp r0, r1
	bls _0800EE32
	adds r0, r5, #0
	bl FUN_0800e530
	movs r0, #1
	strb r0, [r5, #0xd]
_0800EE32:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800ee3c
FUN_0800ee3c: @ 0x0800EE3C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EE60
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EE88 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_0800EE60:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _0800EE78
	ldrh r0, [r4, #6]
	adds r1, r0, #1
	strh r1, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #8]
	cmp r0, r1
	bls _0800EE8C
_0800EE78:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #4]
	strh r1, [r4, #6]
	movs r0, #1
	strb r0, [r4, #3]
	b _0800EEB2
	.align 2, 0
_0800EE88: .4byte 0x03002B3C
_0800EE8C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0800EE9C
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
_0800EE9C:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0800EEB2
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x24]
	bl FUN_08236400
_0800EEB2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800eebc
FUN_0800eebc: @ 0x0800EEBC
	push {lr}
	sub sp, #0x18
	adds r3, r0, #0
	adds r0, #0x60
	ldr r2, _0800EF04 @ =0xFFFF0000
	adds r1, r3, #0
	adds r1, #0x62
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	ldrh r0, [r0]
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	adds r0, #0x64
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0800EF04: .4byte 0xFFFF0000

	thumb_func_start FUN_0800ef08
FUN_0800ef08: @ 0x0800EF08
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0800EF40
	movs r2, #0
	strb r2, [r4, #3]
	adds r0, r4, #0
	adds r0, #0x70
	ldr r1, _0800EF60 @ =0x03002B3C
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0800EF3A
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0800EF3A:
	adds r0, r4, #0
	bl FUN_0800e530
_0800EF40:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _0800EF56
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _0800EF52
	adds r0, r4, #0
	bl FUN_0800eebc
_0800EF52:
	movs r0, #1
	strb r0, [r4, #0xd]
_0800EF56:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800EF60: .4byte 0x03002B3C

	thumb_func_start FUN_0800ef64
FUN_0800ef64: @ 0x0800EF64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _0800EF74
	b _0800F0A8
_0800EF74:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_0800EF7C:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r7, [r0]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0800EF90
	adds r0, r4, #0
	bl FUN_0800e54c
	b _0800F0A0
_0800EF90:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800F082
	adds r6, r4, #0
	adds r6, #0x44
	adds r3, r4, #0
	adds r3, #0x70
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0800EFCA
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	b _0800EFD2
_0800EFCA:
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800EFD2:
	str r0, [r4, #0x44]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0800EFF6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800EFFE
_0800EFF6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800EFFE:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _0800F038 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _0800F07E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800F042
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0800F03C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _0800F058
	.align 2, 0
_0800F038: .4byte 0x0000FFFF
_0800F03C:
	subs r0, #1
	strh r0, [r3, #8]
	b _0800F056
_0800F042:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0800F056
	strh r1, [r3, #8]
	movs r2, #1
	b _0800F058
_0800F056:
	movs r2, #0
_0800F058:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800F080
	mov r5, r8
	strb r5, [r3, #7]
	b _0800F080
_0800F07E:
	movs r2, #0
_0800F080:
	strb r2, [r4, #0xa]
_0800F082:
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	str r0, [r4, #0x60]
	str r1, [r4, #0x64]
	ldr r2, _0800F0B8 @ =0x085AA7A0
	ldrb r1, [r4, #4]
	lsls r1, r1, #2
	ldrb r0, [r4, #2]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0800F0A0:
	adds r4, r7, #0
	cmp r4, #0
	beq _0800F0A8
	b _0800EF7C
_0800F0A8:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0B8: .4byte 0x085AA7A0

	thumb_func_start FUN_0800f0bc
FUN_0800f0bc: @ 0x0800F0BC
	push {r4, lr}
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0800F0D6
_0800F0C4:
	adds r0, r1, #0
	adds r0, #0xf0
	ldr r4, [r0]
	adds r0, r1, #0
	bl FUN_0800e54c
	adds r1, r4, #0
	cmp r1, #0
	bne _0800F0C4
_0800F0D6:
	ldr r1, _0800F0E4 @ =0x03002B3C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F0E4: .4byte 0x03002B3C

	thumb_func_start FUN_0800f0e8
FUN_0800f0e8: @ 0x0800F0E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0800F104 @ =0x03002B3C
	str r4, [r0]
	ldr r0, _0800F108 @ =0x0000922E
	ldr r1, _0800F10C @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F104: .4byte 0x03002B3C
_0800F108: .4byte 0x0000922E
_0800F10C: .4byte 0x0000931E

	thumb_func_start FUN_0800f110
FUN_0800f110: @ 0x0800F110
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800F148 @ =0x03002B3C
	ldr r0, [r0]
	cmp r0, #0
	bne _0800F156
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800F154
	ldr r1, _0800F14C @ =FUN_0800ef64
	ldr r2, _0800F150 @ =FUN_0800f0bc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0800f0e8
	cmp r0, #0
	bge _0800F154
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800F156
	.align 2, 0
_0800F148: .4byte 0x03002B3C
_0800F14C: .4byte FUN_0800ef64
_0800F150: .4byte FUN_0800f0bc
_0800F154:
	adds r0, r4, #0
_0800F156:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800f15c
FUN_0800f15c: @ 0x0800F15C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _0800F258 @ =0x000002DA
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r5, r2
	bge _0800F19E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r7, r4, r3
	adds r6, r4, #0
	adds r6, #0x54
	mov ip, r5
	adds r3, r0, #0
_0800F184:
	lsls r2, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r6, r2
	mov r0, ip
	strh r0, [r2]
	adds r5, #1
	ldrh r1, [r3]
	cmp r5, r1
	blt _0800F184
_0800F19E:
	ldr r2, _0800F258 @ =0x000002DA
	adds r0, r4, r2
	ldrh r5, [r0]
	movs r3, #0xb7
	lsls r3, r3, #2
	mov ip, r3
	adds r0, r4, r3
	ldr r1, _0800F25C @ =0x000002D6
	adds r1, r1, r4
	mov sl, r1
	subs r2, #2
	adds r2, r4, r2
	str r2, [sp]
	ldrh r0, [r0]
	cmp r5, r0
	bge _0800F210
	ldr r3, _0800F260 @ =0x0203B400
	mov sb, r3
	ldr r6, _0800F264 @ =0x030046B8
	ldr r0, _0800F25C @ =0x000002D6
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r7, r4, r1
_0800F1D0:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0800F268 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r2, r1, #0
	muls r2, r0, r2
	asrs r2, r2, #0x12
	lsls r3, r5, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r3, r3, r0
	adds r1, r4, #0
	adds r1, #0x54
	adds r1, r1, r3
	lsls r0, r2, #8
	orrs r2, r0
	strh r2, [r1]
	adds r5, #1
	mov r1, ip
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r5, r0
	blt _0800F1D0
_0800F210:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r5, [r0]
	cmp r5, #0x9f
	bgt _0800F23E
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r6, r4, r3
	adds r3, r4, #0
	adds r3, #0x54
	movs r4, #0
_0800F228:
	lsls r2, r5, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r4, [r2]
	adds r5, #1
	cmp r5, #0x9f
	ble _0800F228
_0800F23E:
	mov r1, sl
	ldr r2, [sp]
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0800F26C
	movs r0, #0
	b _0800F274
	.align 2, 0
_0800F258: .4byte 0x000002DA
_0800F25C: .4byte 0x000002D6
_0800F260: .4byte 0x0203B400
_0800F264: .4byte 0x030046B8
_0800F268: .4byte 0x000003FF
_0800F26C:
	cmp r0, #0x80
	ble _0800F276
	movs r0, #0x80
	mov r1, sl
_0800F274:
	strh r0, [r1]
_0800F276:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800f288
FUN_0800f288: @ 0x0800F288
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F2B0
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r5, #0
	ldrsh r1, [r1, r5]
	bl Div
	ldr r1, _0800F2E0 @ =0x03004040
	str r0, [r1]
_0800F2B0:
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4e
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	ble _0800F2D8
	strh r3, [r2]
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
_0800F2D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2E0: .4byte 0x03004040

	thumb_func_start FUN_0800f2e4
FUN_0800f2e4: @ 0x0800F2E4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0800F30C
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r1, r4, #0
	adds r1, #0x4e
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r1, _0800F340 @ =0x03004040
	str r0, [r1]
_0800F30C:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0800F33A
	strh r2, [r1]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	str r2, [r0]
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0800F334
	movs r1, #0
	bl Script_ExecById
_0800F334:
	adds r0, r4, #0
	bl KillEntity
_0800F33A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F340: .4byte 0x03004040

	thumb_func_start FUN_0800f344
FUN_0800f344: @ 0x0800F344
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x46
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _0800F35C
	ldr r0, _0800F3DC @ =0x0300445C
	ldr r1, _0800F3E0 @ =0x03004040
	ldr r1, [r1]
	str r1, [r0]
_0800F35C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0800F3F4
	ldr r0, _0800F3E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0800F3F4
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3E8 @ =0x0000040C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3EC @ =0x0000046C
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0800F3F0 @ =0x000004CC
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _0800F3C8
	ldr r1, _0800F3DC @ =0x0300445C
	ldr r0, _0800F3E0 @ =0x03004040
	str r2, [r0]
	str r2, [r1]
_0800F3C8:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	beq _0800F3D4
	movs r1, #0
	bl Script_ExecById
_0800F3D4:
	adds r0, r5, #0
	bl KillEntity
	b _0800F506
	.align 2, 0
_0800F3DC: .4byte 0x0300445C
_0800F3E0: .4byte 0x03004040
_0800F3E4: .4byte 0x030044E0
_0800F3E8: .4byte 0x0000040C
_0800F3EC: .4byte 0x0000046C
_0800F3F0: .4byte 0x000004CC
_0800F3F4:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r1, [r6]
	cmp r1, #0
	beq _0800F406
	adds r0, r5, #0
	bl _call_via_r1
_0800F406:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r7, r5, r3
	ldr r1, [r7]
	cmp r1, #0
	beq _0800F43A
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #6
	adds r2, #0x54
	adds r2, r5, r2
	movs r0, #0
	movs r1, #2
	bl FUN_0822ee58
	ldrh r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r4]
_0800F43A:
	ldrh r2, [r5, #0x38]
	cmp r2, #1
	beq _0800F4A8
	cmp r2, #1
	bgt _0800F44A
	cmp r2, #0
	beq _0800F450
	b _0800F500
_0800F44A:
	cmp r2, #2
	beq _0800F4B4
	b _0800F500
_0800F450:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4a
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0800F500
	movs r0, #1
	strh r0, [r5, #0x38]
	strh r2, [r5, #0x3a]
	ldr r0, _0800F498 @ =FUN_0800f288
	str r0, [r6]
	ldr r1, _0800F49C @ =0x000002DA
	adds r0, r5, r1
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F486
	movs r0, #0xe1
	bl PlaySound_082406e0
_0800F486:
	ldr r3, _0800F4A0 @ =0x000002D6
	adds r1, r5, r3
	movs r0, #0x80
	strh r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _0800F4A4 @ =0x0000FFFE
	b _0800F4FA
	.align 2, 0
_0800F498: .4byte FUN_0800f288
_0800F49C: .4byte 0x000002DA
_0800F4A0: .4byte 0x000002D6
_0800F4A4: .4byte 0x0000FFFE
_0800F4A8:
	ldr r0, [r6]
	cmp r0, #0
	bne _0800F500
	movs r0, #2
	strh r0, [r5, #0x38]
	b _0800F500
_0800F4B4:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r4, #0
	strh r0, [r5, #0x3a]
	ldrh r1, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _0800F500
	movs r0, #3
	strh r0, [r5, #0x38]
	strh r4, [r5, #0x3a]
	ldr r0, _0800F510 @ =FUN_0800f2e4
	str r0, [r6]
	ldr r3, _0800F514 @ =0x000002DA
	adds r0, r5, r3
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F4EC
	movs r0, #0xe3
	bl PlaySound_082406e0
_0800F4EC:
	ldr r3, _0800F518 @ =0x000002D6
	adds r0, r5, r3
	strh r4, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
_0800F4FA:
	strh r0, [r1]
	ldr r0, _0800F51C @ =FUN_0800f15c
	str r0, [r7]
_0800F500:
	ldr r0, [r5, #0x3c]
	adds r0, #1
	str r0, [r5, #0x3c]
_0800F506:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F510: .4byte FUN_0800f2e4
_0800F514: .4byte 0x000002DA
_0800F518: .4byte 0x000002D6
_0800F51C: .4byte FUN_0800f15c

	thumb_func_start FUN_0800f520
FUN_0800f520: @ 0x0800F520
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0822f0d8
	bl FUN_0822ed10
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0800F570 @ =0x0000040C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _0800F574 @ =0x0000046C
	adds r4, r4, r0
	movs r5, #1
_0800F558:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0800F558
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800F570: .4byte 0x0000040C
_0800F574: .4byte 0x0000046C

	thumb_func_start FUN_0800f578
FUN_0800f578: @ 0x0800F578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r1, _0800F5D4 @ =0x03004250
	movs r4, #0
	ldr r0, _0800F5D8 @ =0x00001084
	strh r0, [r1]
	ldr r1, _0800F5DC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	str r4, [sp, #0x10]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	strh r4, [r0]
	strh r4, [r5, #0x38]
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x44
	strh r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x46
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800F5E0
	adds r1, #4
	movs r0, #0x40
	strh r0, [r1]
	b _0800F5E6
	.align 2, 0
_0800F5D4: .4byte 0x03004250
_0800F5D8: .4byte 0x00001084
_0800F5DC: .4byte 0xFFFF0000
_0800F5E0:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r4, [r0]
_0800F5E6:
	adds r1, r5, #0
	adds r1, #0x4e
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0x80
	bl Script_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x4c
	strh r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x73
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r5, #0x40]
	movs r0, #0x6f
	adds r1, r4, #0
	bl Script_GetKeywordValue
	ldr r2, _0800F688 @ =0x000002DE
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x74
	adds r1, r4, #0
	bl Script_GetKeywordValue
	ldr r3, _0800F68C @ =0x000002DF
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0800F662
	bl FUN_0823d340
_0800F662:
	str r0, [r5, #0x50]
	movs r0, #0x79
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0800F694
	bl Script_GetValue
	ldr r7, _0800F690 @ =0x000002DA
	adds r1, r5, r7
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _0800F6A2
	.align 2, 0
_0800F688: .4byte 0x000002DE
_0800F68C: .4byte 0x000002DF
_0800F690: .4byte 0x000002DA
_0800F694:
	ldr r3, _0800F6B8 @ =0x000002DA
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
_0800F6A2:
	ldr r0, _0800F6BC @ =0x0000CB05
	ldr r1, _0800F6C0 @ =0x0000E89F
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0800F6C4
	movs r0, #1
	rsbs r0, r0, #0
	b _0800F942
	.align 2, 0
_0800F6B8: .4byte 0x000002DA
_0800F6BC: .4byte 0x0000CB05
_0800F6C0: .4byte 0x0000E89F
_0800F6C4:
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r7}
	stm r0!, {r3, r7}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	mov sl, r4
	cmp r6, #0
	blt _0800F710
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	adds r2, r6, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x87
	lsls r3, r3, #4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	b _0800F72E
_0800F710:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _0800F7D4 @ =0x00000871
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x17
	bl FUN_0822f3fc
_0800F72E:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r4, _0800F7D4 @ =0x00000871
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	movs r2, #0x16
	mov r3, r8
	bl FUN_0822f3fc
	mov r0, sb
	cmp r0, #0
	beq _0800F766
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F766:
	ldr r2, _0800F7D8 @ =0x0000040C
	adds r1, r5, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r7, r5, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #1
	cmp r0, #0
	beq _0800F77C
	movs r2, #0x26
_0800F77C:
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r1, #0
	mov r1, sl
	mov r3, r8
	bl FUN_0822f3fc
	ldr r0, _0800F7DC @ =0x000002DE
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0800F7E4
	ldr r1, _0800F7E0 @ =0x00000414
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Mod
	str r0, [sp, #0x18]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Div
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	ldr r0, [r1, #4]
	adds r0, #0xc
	str r0, [r1, #4]
	adds r0, r1, #0
	b _0800F804
	.align 2, 0
_0800F7D4: .4byte 0x00000871
_0800F7D8: .4byte 0x0000040C
_0800F7DC: .4byte 0x000002DE
_0800F7E0: .4byte 0x00000414
_0800F7E4:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _0800F7FA
	ldr r2, _0800F8EC @ =0x00000414
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F7FA:
	movs r0, #2
	str r0, [sp, #0x18]
	movs r1, #0xc
	add r0, sp, #0x18
	str r1, [r0, #4]
_0800F804:
	adds r3, r5, #0
	adds r3, #0x46
	str r3, [sp, #0x24]
	adds r6, r0, #0
	ldr r7, _0800F8F0 @ =0x0000046C
	adds r4, r5, r7
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov r8, r1
_0800F818:
	ldrh r2, [r6]
	movs r7, #0
	str r7, [sp]
	str r7, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	ldr r3, _0800F8F4 @ =0x00000871
	bl FUN_0822f3fc
	ldr r1, _0800F8F8 @ =0x000002DE
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0800F850
	ldr r2, _0800F8FC @ =0x00000474
	adds r0, r5, r2
	add r0, sb
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F850:
	adds r6, #4
	adds r4, #0x60
	movs r3, #0x60
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0800F818
	ldr r2, _0800F900 @ =0x000002DF
	adds r6, r5, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r2, #0
	cmp r0, #0
	blt _0800F874
	adds r2, r0, #0
_0800F874:
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r0, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _0800F8F4 @ =0x00000871
	str r7, [sp]
	str r7, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl FUN_0822f3fc
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0800F8AA
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F8AA:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	beq _0800F90C
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0800F904 @ =0x0000539C
	bl FUN_08047dc0
	ldr r0, [r5, #0x50]
	bl FUN_080478f0
	ldr r0, [sp, #0x20]
	bl FUN_08047a28
	movs r0, #0
	movs r1, #7
	movs r2, #0x1a
	movs r3, #2
	bl FUN_08047b8c
	bl FUN_080488dc
	ldr r1, _0800F908 @ =0x03003ED0
	lsls r0, r0, #2
	subs r0, #0x78
	strh r0, [r1, #0x20]
	movs r0, #0
	movs r1, #0
	movs r2, #0x11
	bl FUN_0822ece4
	b _0800F916
	.align 2, 0
_0800F8EC: .4byte 0x00000414
_0800F8F0: .4byte 0x0000046C
_0800F8F4: .4byte 0x00000871
_0800F8F8: .4byte 0x000002DE
_0800F8FC: .4byte 0x00000474
_0800F900: .4byte 0x000002DF
_0800F904: .4byte 0x0000539C
_0800F908: .4byte 0x03003ED0
_0800F90C:
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl FUN_0822ece4
_0800F916:
	ldr r2, [sp, #0x24]
	movs r4, #0
	ldrsh r3, [r2, r4]
	cmp r3, #0
	bne _0800F940
	ldr r0, _0800F954 @ =0x03004040
	str r3, [r0]
	ldr r0, _0800F958 @ =0x03004494
	ldr r7, _0800F95C @ =0x00001084
	adds r2, r7, #0
	strh r2, [r0]
	ldr r1, _0800F960 @ =0x03004454
	ldr r4, _0800F964 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _0800F968 @ =0x0300445C
	str r3, [r0]
	ldr r0, _0800F96C @ =0x03004464
	strh r2, [r0]
	ldr r0, _0800F970 @ =0x03004490
	strh r3, [r0]
_0800F940:
	movs r0, #0
_0800F942:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F954: .4byte 0x03004040
_0800F958: .4byte 0x03004494
_0800F95C: .4byte 0x00001084
_0800F960: .4byte 0x03004454
_0800F964: .4byte 0x0000FFFF
_0800F968: .4byte 0x0300445C
_0800F96C: .4byte 0x03004464
_0800F970: .4byte 0x03004490

	thumb_func_start FUN_0800f974
FUN_0800f974: @ 0x0800F974
	push {r4, lr}
	ldr r1, _0800F9A0 @ =0x0000052C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800F9AC
	ldr r1, _0800F9A4 @ =FUN_0800f344
	ldr r2, _0800F9A8 @ =FUN_0800f520
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0800f578
	cmp r0, #0
	bge _0800F9AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800F9AE
	.align 2, 0
_0800F9A0: .4byte 0x0000052C
_0800F9A4: .4byte FUN_0800f344
_0800F9A8: .4byte FUN_0800f520
_0800F9AC:
	adds r0, r4, #0
_0800F9AE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800f9b4
FUN_0800f9b4: @ 0x0800F9B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r1, #4
	str r2, [sp, #4]
	ldrh r2, [r0, #0x1c]
	lsls r2, r2, #2
	adds r1, #0x24
	adds r2, r1, r2
	ldr r2, [r2]
	str r2, [sp, #8]
	ldrh r2, [r0, #0x1e]
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	mov sl, r1
	ldrh r7, [r0, #0x20]
	cmp r7, #0x40
	ble _0800F9E2
	movs r7, #0x40
_0800F9E2:
	movs r0, #0x1f
	mov sb, r0
	movs r1, #0x1f
	mov ip, r1
	movs r0, #0x40
	subs r0, r0, r7
	mov r8, r0
	movs r2, #0xf
	str r2, [sp]
_0800F9F4:
	ldr r0, [sp, #8]
	ldrh r3, [r0]
	mov r6, ip
	ands r6, r3
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x15
	mov r1, sb
	ands r5, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r0, sl
	ldrh r2, [r0]
	mov r0, ip
	ands r0, r2
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x15
	ands r4, r1
	lsrs r2, r2, #0x1a
	ands r2, r1
	muls r0, r7, r0
	mov r1, r8
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r6, r0, #6
	adds r0, r4, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r5, r1
	adds r0, r0, r1
	asrs r4, r0, #6
	adds r0, r2, #0
	muls r0, r7, r0
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	asrs r1, r0, #6
	mov r2, ip
	ands r6, r2
	ands r4, r2
	ands r1, r2
	lsls r0, r4, #5
	orrs r6, r0
	lsls r0, r1, #0xa
	orrs r6, r0
	ldr r0, [sp, #4]
	strh r6, [r0]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #2
	add sl, r2
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
	cmp r0, #0
	bge _0800F9F4
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800fa78
FUN_0800fa78: @ 0x0800FA78
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0800FB20 @ =gClock
	ldrh r0, [r5, #0x26]
	ldrb r1, [r1, #0xe]
	cmp r0, r1
	beq _0800FA98
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0x1e
	bl FUN_0823ce10
	movs r0, #0
	strh r0, [r5, #0x20]
_0800FA98:
	ldrh r0, [r5, #0x20]
	cmp r0, #0x3f
	bhi _0800FACE
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FABC
	adds r4, r5, #0
	adds r4, #0x28
_0800FAAA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAAA
_0800FABC:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0800FACE
	movs r0, #0x40
	strh r0, [r5, #0x20]
_0800FACE:
	ldr r1, _0800FB24 @ =0x03004044
	ldr r0, _0800FB28 @ =0x03004458
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0800FB2C @ =0x03004450
	movs r0, #0
	str r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FB0C
	adds r2, r1, #0
	adds r7, r5, #0
	adds r7, #0x2c
	adds r4, r5, #0
	adds r4, #0x28
_0800FAEE:
	ldrh r0, [r4, #2]
	adds r1, r7, #0
	str r2, [sp]
	bl FUN_0822d190
	ldr r2, [sp]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	adds r7, #0x30
	adds r4, #0x30
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _0800FAEE
_0800FB0C:
	ldr r0, _0800FB20 @ =gClock
	ldrb r1, [r0, #0xf]
	strh r1, [r5, #0x24]
	ldrb r0, [r0, #0xe]
	strh r0, [r5, #0x26]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FB20: .4byte gClock
_0800FB24: .4byte 0x03004044
_0800FB28: .4byte 0x03004458
_0800FB2C: .4byte 0x03004450

	thumb_func_start FUN_0800fb30
FUN_0800fb30: @ 0x0800FB30
	movs r0, #0
	bx lr

	thumb_func_start FUN_0800fb34
FUN_0800fb34: @ 0x0800FB34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strh r0, [r5, #0x1a]
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _0800FB8C
	movs r6, #0
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	b _0800FB6E
_0800FB62:
	bl Script_GetValue
	lsls r1, r6, #1
	add r1, sp
	strh r0, [r1]
	adds r6, #1
_0800FB6E:
	cmp r6, #5
	bgt _0800FBA6
	bl VM_GetPC
	cmp r0, #0
	bne _0800FB62
	movs r1, #0
	lsls r0, r6, #1
	add r0, sp
_0800FB80:
	strh r1, [r0]
	adds r0, #2
	adds r6, #1
	cmp r6, #5
	ble _0800FB80
	b _0800FBA6
_0800FB8C:
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	movs r1, #0
	mov r0, sp
	adds r0, #0xa
_0800FB9E:
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0800FB9E
_0800FBA6:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800FC02
	movs r6, #0
	ldr r0, _0800FBC0 @ =0x03003584
	mov sl, r0
	mov r7, sp
	adds r4, r5, #0
	adds r4, #0x28
	b _0800FBF6
	.align 2, 0
_0800FBC0: .4byte 0x03003584
_0800FBC4:
	bl Script_GetValue
	strh r0, [r4]
	ldrh r0, [r4]
	bl FUN_0823cdf8
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r4, #2]
	ldrh r1, [r4, #2]
	lsls r1, r1, #5
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	adds r0, #0x20
	str r0, [r4, #0x28]
	adds r0, #0x20
	str r0, [r4, #0x2c]
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	strh r0, [r5, #0x1a]
	adds r7, #2
	adds r4, #0x30
	adds r6, #1
_0800FBF6:
	cmp r6, #5
	bgt _0800FC02
	bl VM_GetPC
	cmp r0, #0
	bne _0800FBC4
_0800FC02:
	mov r0, sb
	mov r1, r8
	bl FUN_0823ce10
	movs r0, #0x40
	strh r0, [r5, #0x20]
	ldr r1, _0800FC48 @ =gClock
	ldrb r0, [r1, #0xf]
	strh r0, [r5, #0x24]
	ldrb r0, [r1, #0xe]
	strh r0, [r5, #0x26]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FC36
	adds r4, r5, #0
	adds r4, #0x28
_0800FC24:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r2, [r5, #0x1a]
	cmp r6, r2
	blt _0800FC24
_0800FC36:
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FC48: .4byte gClock

	thumb_func_start FUN_0800fc4c
FUN_0800fc4c: @ 0x0800FC4C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800FC88
	ldr r1, _0800FC80 @ =FUN_0800fa78
	ldr r2, _0800FC84 @ =FUN_0800fb30
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0800fb34
	cmp r0, #0
	bge _0800FC88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800FC8A
	.align 2, 0
_0800FC80: .4byte FUN_0800fa78
_0800FC84: .4byte FUN_0800fb30
_0800FC88:
	adds r0, r4, #0
_0800FC8A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800fc90
FUN_0800fc90: @ 0x0800FC90
	ldr r1, _0800FC98 @ =0x03000048
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800FC98: .4byte 0x03000048

	thumb_func_start FUN_0800fc9c
FUN_0800fc9c: @ 0x0800FC9C
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0800FCC0 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800FCC0: .4byte 0x03003ED0

	thumb_func_start FUN_0800fcc4
FUN_0800fcc4: @ 0x0800FCC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r2
	movs r2, #0
	cmp r1, #9
	ble _0800FCD8
	movs r2, #1
_0800FCD8:
	str r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r0, r1, r0
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #6
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FCFC:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD04:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD04
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FCFC
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0xa
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FD54:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD5E:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD5E
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FD54
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD90: .4byte 0xFFFFD000
_0800FD94: .4byte 0x03003ED0

	thumb_func_start FUN_0800fd98
FUN_0800fd98: @ 0x0800FD98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	bl GetHour
	adds r4, r0, #0
	bl GetMinute
	mov sb, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FDDA:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FDE2:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FDE2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FDDA
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x14
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FE32:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FE3C:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FE3C
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FE32
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE6C: .4byte 0xFFFFD000
_0800FE70: .4byte 0x03003ED0

	thumb_func_start FUN_0800fe74
FUN_0800fe74: @ 0x0800FE74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0800FEB0 @ =gClock
	cmp r0, #0
	bne _0800FE88
	b _0801001E
_0800FE88:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _0800FE96
	cmp r0, #4
	beq _0800FE96
	cmp r0, #5
	bne _0800FEB4
_0800FE96:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r1, _0800FEB0 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _0800FEB0 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _0800FECC
	.align 2, 0
_0800FEB0: .4byte gClock
_0800FEB4:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _0800FF24 @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_0800FECC:
	movs r4, #0
	ldr r1, _0800FF28 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _0800FF2C @ =0x03003ED0
	mov sb, r2
_0800FED8:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_0800FEDE:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0800FEDE
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FED8
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0800FF1C
	cmp r0, #4
	beq _0800FF1C
	cmp r0, #5
	bne _0800FF30
_0800FF1C:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _0800FF36
	.align 2, 0
_0800FF24: .4byte gClock
_0800FF28: .4byte 0xFFFFD000
_0800FF2C: .4byte 0x03003ED0
_0800FF30:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_0800FF36:
	movs r4, #0
	ldr r2, _08010030 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_0800FF3E:
	movs r2, #0
	cmp r2, ip
	bge _0800FF5A
	adds r3, r6, #0
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_0800FF4C:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _0800FF4C
_0800FF5A:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FF3E
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FF9A:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFA2:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFA2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _0800FF9A
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FFF2:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFFC:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFFC
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _0800FFF2
_0801001E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010030: .4byte 0x03003ED0
_08010034: .4byte 0xFFFFD000

	thumb_func_start FUN_08010038
FUN_08010038: @ 0x08010038
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	add r4, sp, #4
	add r5, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl ParseBCDDate
	ldrh r1, [r6, #0x28]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08010066
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r0, r6, #0
	bl FUN_0800fcc4
_08010066:
	ldrh r1, [r6, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08010076
	adds r0, r6, #0
	bl FUN_0800fd98
_08010076:
	ldrh r1, [r6, #0x28]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08010086
	adds r0, r6, #0
	bl FUN_0800fe74
_08010086:
	movs r0, #0
	strh r0, [r6, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08010094
FUN_08010094: @ 0x08010094
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080100DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080100AE
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080100E8
_080100AE:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080100E0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080100E4 @ =FUN_080104c8
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
	movs r0, #1
	b _080100EA
	.align 2, 0
_080100DC: .4byte 0x030044E0
_080100E0: .4byte 0x0000FFFF
_080100E4: .4byte FUN_080104c8
_080100E8:
	movs r0, #0
_080100EA:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080100f4
FUN_080100f4: @ 0x080100F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r2, [r5]
	cmp r2, #0
	bne _08010138
	subs r0, #0x16
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _08010180 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010184 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08010188 @ =0x000002CA
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801018C @ =FUN_08010718
	str r0, [r1]
_08010138:
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r5]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08010166
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, #0x1c
	adds r1, r4, r2
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
	ldr r2, _08010190 @ =0x03003E78
	ldr r0, _08010194 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08010166:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08010198 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010180: .4byte 0x000002C6
_08010184: .4byte 0x00001084
_08010188: .4byte 0x000002CA
_0801018C: .4byte FUN_08010718
_08010190: .4byte 0x03003E78
_08010194: .4byte 0xFFFFFEFF
_08010198: .4byte 0x0000FFFC

	thumb_func_start FUN_0801019c
FUN_0801019c: @ 0x0801019C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r6, [r5]
	cmp r6, #0
	bne _080101DA
	movs r0, #0xe3
	bl PlaySound_082406e0
	ldr r2, _08010218 @ =0x000002B2
	adds r1, r4, r2
	movs r0, #0x74
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _0801021C @ =0x000002AE
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	adds r3, #0x20
	adds r1, r4, r3
	ldr r0, _08010220 @ =FUN_0801084c
	str r0, [r1]
_080101DA:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	ldr r2, _08010224 @ =0x000002BE
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _0801020A
	ldrh r1, [r4, #0x28]
	ldr r0, _08010228 @ =0x0000FFFC
	ands r0, r1
	movs r2, #0
	strh r0, [r4, #0x28]
	ldr r1, _0801022C @ =FUN_080100f4
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_0801020A:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010218: .4byte 0x000002B2
_0801021C: .4byte 0x000002AE
_08010220: .4byte FUN_0801084c
_08010224: .4byte 0x000002BE
_08010228: .4byte 0x0000FFFC
_0801022C: .4byte FUN_080100f4

	thumb_func_start FUN_08010230
FUN_08010230: @ 0x08010230
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrh r5, [r6]
	cmp r5, #0
	bne _080102A0
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r2, _0801032C @ =0x000002C2
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xb1
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	ldr r0, _08010330 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010334 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #8
	adds r0, r4, r2
	movs r2, #4
	strh r2, [r0]
	adds r7, #0xc
	adds r1, r4, r7
	ldr r0, _08010338 @ =FUN_08010718
	str r0, [r1]
	ldr r1, _0801033C @ =0x000002B2
	adds r0, r4, r1
	strh r5, [r0]
	subs r7, #0x1c
	adds r1, r4, r7
	movs r0, #0x74
	strh r0, [r1]
	ldr r1, _08010340 @ =0x000002AE
	adds r0, r4, r1
	strh r5, [r0]
	movs r5, #0xac
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	adds r7, #0x20
	adds r1, r4, r7
	ldr r0, _08010344 @ =FUN_0801084c
	str r0, [r1]
_080102A0:
	ldrh r0, [r6]
	cmp r0, #0x30
	bne _080102E8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0800fc9c
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08010348 @ =0x03003ED0
	mov r8, r0
	mov ip, r8
_080102BA:
	movs r2, #0
	mov r5, ip
	movs r6, #0x18
	ldrsh r0, [r5, r6]
	lsls r0, r0, #1
	adds r5, r3, #1
	cmp r2, r0
	bge _080102E2
	movs r7, #0xd0
	lsls r7, r7, #8
	adds r6, r7, #0
	mov r3, r8
_080102D2:
	strh r6, [r1]
	adds r1, #2
	adds r2, #1
	movs r7, #0x18
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	cmp r2, r0
	blt _080102D2
_080102E2:
	adds r3, r5, #0
	cmp r3, #0xe
	ble _080102BA
_080102E8:
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010318
	ldr r1, _0801034C @ =FUN_0801019c
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r1, [r0]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0
	strh r0, [r1]
_08010318:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801032C: .4byte 0x000002C2
_08010330: .4byte 0x000002C6
_08010334: .4byte 0x00001084
_08010338: .4byte FUN_08010718
_0801033C: .4byte 0x000002B2
_08010340: .4byte 0x000002AE
_08010344: .4byte FUN_0801084c
_08010348: .4byte 0x03003ED0
_0801034C: .4byte FUN_0801019c

	thumb_func_start FUN_08010350
FUN_08010350: @ 0x08010350
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _08010398
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080103A0 @ =0x000002BA
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010390
	ldr r1, _080103A4 @ =FUN_08010230
	adds r2, #0x12
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #8
	adds r1, r4, r2
	ldr r0, _080103A8 @ =FUN_080109b0
	str r0, [r1]
_08010390:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010398:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080103A0: .4byte 0x000002BA
_080103A4: .4byte FUN_08010230
_080103A8: .4byte FUN_080109b0

	thumb_func_start FUN_080103ac
FUN_080103ac: @ 0x080103AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r6, r0, #0
	cmp r6, #0
	bne _08010448
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0801041A
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r1, _08010450 @ =0x000002B2
	adds r0, r4, r1
	strh r6, [r0]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xa0
	strh r0, [r1]
	ldr r0, _08010454 @ =0x000002AE
	adds r1, r4, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	subs r2, #4
	adds r1, r4, r2
	ldr r0, _08010458 @ =0x0000FFFE
	strh r0, [r1]
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801045C @ =FUN_0801084c
	str r0, [r1]
	adds r2, #0x16
	adds r1, r4, r2
	ldr r0, _08010460 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08010464 @ =FUN_080105ec
	str r0, [r1]
_0801041A:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010440
	ldr r0, _08010468 @ =FUN_0801046c
	adds r2, #0x14
	adds r1, r4, r2
	str r0, [r1]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08010440:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010448:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010450: .4byte 0x000002B2
_08010454: .4byte 0x000002AE
_08010458: .4byte 0x0000FFFE
_0801045C: .4byte FUN_0801084c
_08010460: .4byte 0x00001084
_08010464: .4byte FUN_080105ec
_08010468: .4byte FUN_0801046c

	thumb_func_start FUN_0801046c
FUN_0801046c: @ 0x0801046C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _080104B6
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080104BC @ =0x000002B6
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080104AE
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _080104C0 @ =FUN_080109b0
	str r0, [r1]
	ldr r1, _080104C4 @ =FUN_08010350
	adds r2, #0x16
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
_080104AE:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_080104B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080104BC: .4byte 0x000002B6
_080104C0: .4byte FUN_080109b0
_080104C4: .4byte FUN_08010350

	thumb_func_start FUN_080104c8
FUN_080104c8: @ 0x080104C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0x20
	subs r5, r0, r1
	movs r0, #0
	ldr r2, [r7, #0x20]
	mov sb, r2
	movs r1, #0xf8
	lsls r1, r1, #7
	mov sl, r1
_080104EC:
	movs r6, #0
	lsls r2, r0, #4
	mov ip, r2
	adds r0, #1
	mov r8, r0
_080104F6:
	mov r0, ip
	adds r4, r0, r6
	lsls r4, r4, #1
	add r4, sb
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r5, r2
	movs r0, #0xf8
	lsls r0, r0, #3
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r5, r3
	movs r0, #0xf8
	lsls r0, r0, #8
	ands r3, r0
	mov r0, sl
	ands r0, r1
	adds r1, r0, #0
	muls r1, r5, r1
	movs r0, #0xf8
	lsls r0, r0, #0xd
	ands r1, r0
	orrs r2, r3
	orrs r2, r1
	asrs r2, r2, #6
	strh r2, [r4]
	adds r6, #1
	cmp r6, #0xf
	ble _080104F6
	mov r0, r8
	cmp r0, #1
	ble _080104EC
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08010574
	movs r0, #0
	bl FUN_0822b644
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r7, r2
	bl Script_ExecById
	adds r0, r7, #0
	bl KillEntity
	b _0801057C
_08010574:
	ldrh r0, [r7, #0x28]
	movs r1, #0xf
	orrs r0, r1
	strh r0, [r7, #0x28]
_0801057C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801058c
FUN_0801058c: @ 0x0801058C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0x80
	lsls r6, r6, #1
	ldr r5, _080105DC @ =0x03003E78
	ldrh r0, [r5]
	bics r0, r6
	strh r0, [r5]
	adds r0, r4, #0
	bl FUN_08010094
	cmp r0, #0
	bne _080105D4
	ldrh r0, [r4, #0x2a]
	ldr r2, _080105E0 @ =0x0000FFFF
	adds r1, r0, r2
	strh r1, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080105D4
	ldrh r1, [r5]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _080105E4 @ =0x03000048
	ldr r2, [r0]
	ldr r1, _080105E8 @ =FUN_080103ac
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r2, r4
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r3, [r0]
_080105D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080105DC: .4byte 0x03003E78
_080105E0: .4byte 0x0000FFFF
_080105E4: .4byte 0x03000048
_080105E8: .4byte FUN_080103ac

	thumb_func_start FUN_080105ec
FUN_080105ec: @ 0x080105EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r7, r0
	ble _0801060C
	adds r7, r0, #0
_0801060C:
	subs r0, r0, r7
	mov ip, r0
	ldr r0, _0801070C @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp]
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	str r2, [sp, #4]
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	str r3, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r4, _08010710 @ =0x000002C2
	add r4, r8
	str r4, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x10]
_0801063E:
	ldr r3, [sp, #0xc]
	ldrh r6, [r3]
	adds r4, r1, #0
	adds r4, #0x10
	str r4, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r6, r0
	bge _080106CA
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r3, r8
	ldr r3, [r3, #0x20]
	mov sb, r3
	adds r0, r6, r1
	lsls r5, r0, #1
_08010664:
	mov r4, sl
	adds r0, r4, r5
	mov r1, sb
	adds r1, r1, r5
	str r1, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r3, [sp]
	mov r0, ip
	muls r0, r3, r0
	adds r2, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r4, [sp, #4]
	mov r0, ip
	muls r0, r4, r0
	adds r3, r3, r0
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r4, [sp, #8]
	mov r1, ip
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	ldr r0, [sp, #0x1c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #1
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	cmp r6, r1
	blt _08010664
_080106CA:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r0, #1
	ble _0801063E
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _080106EE
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_080106EE:
	ldr r0, _08010714 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801070C: .4byte 0x000002C6
_08010710: .4byte 0x000002C2
_08010714: .4byte 0x000002CA

	thumb_func_start FUN_08010718
FUN_08010718: @ 0x08010718
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	mov ip, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp ip, r0
	ble _0801073A
	mov ip, r0
_0801073A:
	mov r1, ip
	subs r7, r0, r1
	ldr r0, _08010840 @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r2, r0
	str r2, [sp]
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r1, r0
	str r1, [sp, #4]
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r2, r0
	str r2, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r2, _08010844 @ =0x000002C2
	add r2, r8
	str r2, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x1c]
_0801076C:
	ldr r2, [sp, #0xc]
	ldrh r6, [r2]
	adds r2, r1, #0
	adds r2, #0x10
	str r2, [sp, #0x24]
	adds r0, #1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	ldrh r0, [r0]
	cmp r6, r0
	bge _08010800
	ldr r0, [sp]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x10]
	ldr r0, [sp, #4]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x14]
	ldr r0, [sp, #8]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x18]
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r0, r8
	ldr r0, [r0, #0x20]
	mov sb, r0
	adds r0, r6, r1
	lsls r5, r0, #1
_080107AA:
	mov r1, sl
	adds r0, r1, r5
	mov r2, sb
	adds r4, r2, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r0, [sp, #0x10]
	adds r2, r0, r2
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r0, [sp, #0x14]
	adds r3, r0, r3
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r1, [sp, #0x18]
	adds r0, r1, r0
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	strh r2, [r4]
	adds r5, #2
	adds r6, #1
	ldr r2, [sp, #0x1c]
	ldrh r2, [r2]
	cmp r6, r2
	blt _080107AA
_08010800:
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x20]
	cmp r0, #1
	ble _0801076C
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _08010824
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_08010824:
	ldr r0, _08010848 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010840: .4byte 0x000002C6
_08010844: .4byte 0x000002C2
_08010848: .4byte 0x000002CA

	thumb_func_start FUN_0801084c
FUN_0801084c: @ 0x0801084C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	movs r4, #0
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r1, [r0]
	cmp r4, r1
	bge _0801088C
	movs r6, #0xab
	lsls r6, r6, #2
	add r6, ip
	mov r5, ip
	adds r5, #0x2c
	movs r7, #0
	adds r3, r0, #0
_08010874:
	lsls r2, r4, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r5, r2
	strh r7, [r2]
	adds r4, #1
	ldrh r2, [r3]
	cmp r4, r2
	blt _08010874
_0801088C:
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r4, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	mov r8, r0
	mov r0, ip
	add r0, r8
	ldr r1, _08010970 @ =0x000002AE
	add r1, ip
	str r1, [sp]
	movs r2, #0xac
	lsls r2, r2, #2
	add r2, ip
	str r2, [sp, #4]
	ldrh r0, [r0]
	cmp r4, r0
	bge _080108FC
	ldr r0, _08010974 @ =0x0203B400
	mov sl, r0
	ldr r5, _08010978 @ =0x030046B8
	movs r7, #0xab
	lsls r7, r7, #2
	add r7, ip
	ldr r6, _08010970 @ =0x000002AE
	add r6, ip
	ldr r1, _0801097C @ =0x000003FF
	mov sb, r1
_080108C4:
	ldr r0, [r5]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sl
	ldrh r3, [r0]
	lsls r2, r4, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r1, ip
	adds r1, #0x2c
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	muls r0, r3, r0
	asrs r0, r0, #0x12
	strh r0, [r1]
	adds r4, #1
	mov r0, ip
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	blt _080108C4
_080108FC:
	movs r0, #0xad
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	cmp r4, #0x9f
	bgt _0801092A
	movs r5, #0xab
	lsls r5, r5, #2
	add r5, ip
	mov r3, ip
	adds r3, #0x2c
	movs r6, #0
_08010914:
	lsls r2, r4, #1
	ldrh r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r6, [r2]
	adds r4, #1
	cmp r4, #0x9f
	ble _08010914
_0801092A:
	movs r0, #0xab
	lsls r0, r0, #2
	add r0, ip
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	add r0, ip
	ldr r1, _08010980 @ =0x03003518
	str r0, [r1]
	ldr r0, _08010984 @ =0x0400004C
	ldr r2, _08010988 @ =0x03002CA0
	str r0, [r2]
	movs r0, #1
	ldr r1, _0801098C @ =0x03003510
	strh r0, [r1]
	ldr r2, _08010990 @ =0x03003514
	strh r0, [r2]
	ldr r1, [sp]
	ldr r2, [sp, #4]
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010994
	movs r0, #0
	strh r0, [r1]
	b _080109A0
	.align 2, 0
_0801096C: .4byte 0x000002B2
_08010970: .4byte 0x000002AE
_08010974: .4byte 0x0203B400
_08010978: .4byte 0x030046B8
_0801097C: .4byte 0x000003FF
_08010980: .4byte 0x03003518
_08010984: .4byte 0x0400004C
_08010988: .4byte 0x03002CA0
_0801098C: .4byte 0x03003510
_08010990: .4byte 0x03003514
_08010994:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080109A0
	ldr r0, [sp]
	strh r1, [r0]
_080109A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080109b0
FUN_080109b0: @ 0x080109B0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp]
	adds r1, r5, #0
	adds r1, #0x2c
	ldr r2, _080109FC @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r2, _08010A00 @ =0x03003518
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _08010A04 @ =0x03002CA0
	ldr r0, _08010A08 @ =0x0400004C
	str r0, [r1]
	ldr r1, _08010A0C @ =0x03003510
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08010A10 @ =0x03003514
	strh r4, [r0]
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080109FC: .4byte 0x05000091
_08010A00: .4byte 0x03003518
_08010A04: .4byte 0x03002CA0
_08010A08: .4byte 0x0400004C
_08010A0C: .4byte 0x03003510
_08010A10: .4byte 0x03003514

	thumb_func_start FUN_08010a14
FUN_08010a14: @ 0x08010A14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A2C
	adds r0, r5, #0
	bl _call_via_r1
_08010A2C:
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A3E
	adds r0, r5, #0
	bl _call_via_r1
_08010A3E:
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A50
	adds r0, r5, #0
	bl _call_via_r1
_08010A50:
	movs r0, #0xab
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	movs r4, #0
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08010038
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010a7c
FUN_08010a7c: @ 0x08010A7C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	str r5, [sp]
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _08010AC4 @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r3, _08010AC8 @ =0x03003518
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #6
	adds r1, #0x2c
	adds r4, r4, r1
	str r4, [r3]
	ldr r2, _08010ACC @ =0x03002CA0
	ldr r1, _08010AD0 @ =0x0400004C
	str r1, [r2]
	ldr r2, _08010AD4 @ =0x03003510
	movs r1, #1
	strh r1, [r2]
	ldr r1, _08010AD8 @ =0x03003514
	strh r5, [r1]
	ldr r1, _08010ADC @ =0x03000048
	str r5, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08010AC4: .4byte 0x05000091
_08010AC8: .4byte 0x03003518
_08010ACC: .4byte 0x03002CA0
_08010AD0: .4byte 0x0400004C
_08010AD4: .4byte 0x03003510
_08010AD8: .4byte 0x03003514
_08010ADC: .4byte 0x03000048

	thumb_func_start FUN_08010ae0
FUN_08010ae0: @ 0x08010AE0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _08010B40 @ =0x03000048
	str r6, [r0]
	ldr r3, _08010B44 @ =0x03003E78
	ldr r0, _08010B48 @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r0, r2
	strh r0, [r3]
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08010B4C @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08010B50 @ =0x030043F0
	str r0, [r6, #0x20]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x61
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08010B7E
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r6, r2
	str r0, [r1]
	movs r4, #0
	b _08010B68
	.align 2, 0
_08010B40: .4byte 0x03000048
_08010B44: .4byte 0x03003E78
_08010B48: .4byte 0xFFFFFEFF
_08010B4C: .4byte 0x0000596F
_08010B50: .4byte 0x030043F0
_08010B54:
	bl Script_GetValue
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r2, [r1]
	lsls r1, r4, #2
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_08010B68:
	cmp r4, #7
	bgt _08010B74
	bl VM_GetPC
	cmp r0, #0
	bne _08010B54
_08010B74:
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	b _08010B86
_08010B7E:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08010B86:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _08010BE4
	movs r4, #0
	b _08010BB4
_08010B94:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r3, _08010BDC @ =0x000002B6
	adds r1, r6, r3
	adds r3, r1, r2
	strh r0, [r3]
	ldr r1, _08010BE0 @ =0x085AA810
	adds r2, r2, r1
	ldrh r2, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r2
	bhs _08010BB2
	strh r2, [r3]
_08010BB2:
	adds r4, #1
_08010BB4:
	cmp r4, #5
	bgt _08010BFA
	bl VM_GetPC
	cmp r0, #0
	bne _08010B94
	ldr r1, _08010BE0 @ =0x085AA810
	lsls r0, r4, #1
	adds r2, r0, r1
	ldr r1, _08010BDC @ =0x000002B6
	adds r0, r0, r1
	adds r1, r0, r6
_08010BCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #5
	ble _08010BCC
	b _08010BFA
	.align 2, 0
_08010BDC: .4byte 0x000002B6
_08010BE0: .4byte 0x085AA810
_08010BE4:
	ldr r2, _08010C20 @ =0x085AA810
	ldr r3, _08010C24 @ =0x000002B6
	adds r1, r6, r3
	movs r4, #5
_08010BEC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _08010BEC
_08010BFA:
	movs r0, #0
	strb r0, [r6, #0x1b]
	ldr r0, _08010C28 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08010C1A
	ldr r0, _08010C2C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	adds r5, r0, #0
	cmp r5, #0
	bne _08010C30
_08010C1A:
	movs r0, #1
	rsbs r0, r0, #0
	b _08010D0C
	.align 2, 0
_08010C20: .4byte 0x085AA810
_08010C24: .4byte 0x000002B6
_08010C28: .4byte 0x0000C091
_08010C2C: .4byte 0x000092B3
_08010C30:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08010C46
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08010C46
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08010C62
_08010C46:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08010C62:
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r5, r1
	str r0, [r6, #0x24]
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, [r6, #0x20]
	ldr r2, _08010D14 @ =0x05000018
	add r0, sp, #0x10
	bl CpuSet
	ldr r2, _08010D18 @ =0x04000008
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x77
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x2a]
	ldr r1, _08010D1C @ =FUN_0801058c
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _08010D20 @ =0x000002C2
	adds r0, r6, r1
	strh r4, [r0]
	subs r2, #8
	adds r1, r6, r2
	movs r0, #0x10
	strh r0, [r1]
	subs r3, #0x12
	adds r1, r6, r3
	ldr r0, _08010D24 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r0, r6, r2
	movs r5, #1
	strh r5, [r0]
	adds r3, #0xa
	adds r0, r6, r3
	str r4, [r0]
	str r4, [sp, #0x14]
	add r0, sp, #0x14
	adds r1, r6, #0
	adds r1, #0x2c
	ldr r2, _08010D28 @ =0x05000091
	bl CpuSet
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08010D2C @ =0x000002AE
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r5, [r0]
	ldr r1, _08010D30 @ =0x000002B2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r1, r6, r2
	movs r0, #0xa0
	strh r0, [r1]
	adds r3, #0x24
	adds r0, r6, r3
	str r4, [r0]
	movs r0, #0xf
	strh r0, [r6, #0x28]
	movs r0, #0
_08010D0C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08010D14: .4byte 0x05000018
_08010D18: .4byte 0x04000008
_08010D1C: .4byte FUN_0801058c
_08010D20: .4byte 0x000002C2
_08010D24: .4byte 0x00001084
_08010D28: .4byte 0x05000091
_08010D2C: .4byte 0x000002AE
_08010D30: .4byte 0x000002B2

	thumb_func_start FUN_08010d34
FUN_08010d34: @ 0x08010D34
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08010D70
	ldr r1, _08010D68 @ =FUN_08010a14
	ldr r2, _08010D6C @ =FUN_08010a7c
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08010ae0
	cmp r0, #0
	bge _08010D70
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08010D72
	.align 2, 0
_08010D68: .4byte FUN_08010a14
_08010D6C: .4byte FUN_08010a7c
_08010D70:
	adds r0, r4, #0
_08010D72:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08010d78
FUN_08010d78: @ 0x08010D78
	ldr r1, _08010D80 @ =0x0300004C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08010D80: .4byte 0x0300004C

	thumb_func_start FUN_08010d84
FUN_08010d84: @ 0x08010D84
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _08010DA8 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010DA8: .4byte 0x03003ED0

	thumb_func_start FUN_08010dac
FUN_08010dac: @ 0x08010DAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08010DE8 @ =gClock
	cmp r0, #0
	bne _08010DC0
	b _08010F56
_08010DC0:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _08010DCE
	cmp r0, #4
	beq _08010DCE
	cmp r0, #5
	bne _08010DEC
_08010DCE:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r1, _08010DE8 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _08010DE8 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _08010E04
	.align 2, 0
_08010DE8: .4byte gClock
_08010DEC:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _08010E5C @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_08010E04:
	movs r4, #0
	ldr r1, _08010E60 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _08010E64 @ =0x03003ED0
	mov sb, r2
_08010E10:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_08010E16:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _08010E16
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E10
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	ldr r7, _08010E5C @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08010E54
	cmp r0, #4
	beq _08010E54
	cmp r0, #5
	bne _08010E68
_08010E54:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _08010E6E
	.align 2, 0
_08010E5C: .4byte gClock
_08010E60: .4byte 0xFFFFD000
_08010E64: .4byte 0x03003ED0
_08010E68:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_08010E6E:
	movs r4, #0
	ldr r2, _08010F68 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_08010E76:
	movs r2, #0
	cmp r2, ip
	bge _08010E92
	adds r3, r6, #0
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_08010E84:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _08010E84
_08010E92:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _08010E76
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010ED2:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_08010EDA:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010EDA
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _08010ED2
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_08010d84
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010F6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010F68 @ =0x03003ED0
	mov r8, r1
_08010F2A:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_08010F34:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08010F34
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _08010F2A
_08010F56:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010F68: .4byte 0x03003ED0
_08010F6C: .4byte 0xFFFFD000

	thumb_func_start FUN_08010f70
FUN_08010f70: @ 0x08010F70
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	add r5, sp, #4
	add r6, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r5, #0
	adds r2, r6, #0
	bl ParseBCDDate
	movs r5, #0
	movs r0, #0xf
	strh r0, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08010dac
	strh r5, [r4, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08010fa0
FUN_08010fa0: @ 0x08010FA0
	push {lr}
	bl FUN_08010f70
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08010fac
FUN_08010fac: @ 0x08010FAC
	ldr r2, _08010FB4 @ =0x0300004C
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_08010FB4: .4byte 0x0300004C

	thumb_func_start FUN_08010fb8
FUN_08010fb8: @ 0x08010FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0801100C @ =0x0300004C
	str r6, [r0]
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08011010 @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08011014 @ =0x030043F0
	str r0, [r6, #0x20]
	strb r4, [r6, #0x1b]
	ldr r0, _08011018 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08011006
	ldr r0, _0801101C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	mov r8, r0
	cmp r0, #0
	bne _08011020
_08011006:
	movs r0, #1
	rsbs r0, r0, #0
	b _080110B6
	.align 2, 0
_0801100C: .4byte 0x0300004C
_08011010: .4byte 0x0000596F
_08011014: .4byte 0x030043F0
_08011018: .4byte 0x0000C091
_0801101C: .4byte 0x000092B3
_08011020:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08011036
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08011036
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08011052
_08011036:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08011052:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08010d84
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _080110C4 @ =0x03003ED0
	mov ip, r0
	ldr r1, [r6, #0x20]
	mov sb, r1
_08011076:
	movs r3, #0
	mov r5, ip
	movs r7, #0x18
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r1, r4, #1
	cmp r3, r0
	bge _0801109E
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
	ldr r4, _080110C4 @ =0x03003ED0
_0801108E:
	strh r5, [r2]
	adds r2, #2
	adds r3, #1
	movs r7, #0x18
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	cmp r3, r0
	blt _0801108E
_0801109E:
	adds r4, r1, #0
	cmp r4, #0xe
	ble _08011076
	movs r0, #0xda
	lsls r0, r0, #1
	add r0, r8
	str r0, [r6, #0x24]
	ldr r2, _080110C8 @ =0x04000018
	mov r1, sb
	bl CpuSet
	movs r0, #0
_080110B6:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080110C4: .4byte 0x03003ED0
_080110C8: .4byte 0x04000018

	thumb_func_start FUN_080110cc
FUN_080110cc: @ 0x080110CC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08011108
	ldr r1, _08011100 @ =FUN_08010fa0
	ldr r2, _08011104 @ =FUN_08010fac
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08010fb8
	cmp r0, #0
	bge _08011108
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801110A
	.align 2, 0
_08011100: .4byte FUN_08010fa0
_08011104: .4byte FUN_08010fac
_08011108:
	adds r0, r4, #0
_0801110A:
	pop {r4, r5}
	pop {r1}
	bx r1

