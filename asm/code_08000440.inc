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
	bl GetTilemapFile
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
	bl GetTilemapFile
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
	bl GetTilemapFile
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
	bl GetTilemapFile
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
	bl GetTilemapFile
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
	bl GetTilemapFile
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

