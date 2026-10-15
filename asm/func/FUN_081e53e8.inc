	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E5454
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r6, _081E543C @ =0x00001514
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r7, _081E5440 @ =0x00001624
	adds r0, r5, r7
	strb r2, [r0]
	ldr r0, _081E5444 @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E5448 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E544C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _081E5450 @ =0x00001616
	adds r0, r5, r6
	strb r1, [r0]
	b _081E5634
	.align 2, 0
_081E543C: .4byte 0x00001514
_081E5440: .4byte 0x00001624
_081E5444: .4byte 0x000014B4
_081E5448: .4byte FUN_081e653c
_081E544C: .4byte 0x00001614
_081E5450: .4byte 0x00001616
_081E5454:
	ldr r7, _081E54D8 @ =0x00001614
	adds r7, r7, r5
	mov r8, r7
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E54F8
	ldr r1, _081E54DC @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E54E0 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r6, #0xa5
	lsls r6, r6, #4
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r7, _081E54E4 @ =0x0000161C
	adds r1, r5, r7
	ldr r0, _081E54E8 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _081E54EC @ =0x00000E28
	adds r1, r5, r0
	adds r2, #0x85
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r5, r2
	adds r0, r1, #0
	ldr r3, _081E54F0 @ =0x00000BC4
	adds r2, r2, r3
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	ldr r6, _081E54F4 @ =0x00001622
	adds r0, r5, r6
	movs r1, #0
	strb r4, [r0]
	mov r7, r8
	strb r1, [r7]
	b _081E5634
	.align 2, 0
_081E54D8: .4byte 0x00001614
_081E54DC: .4byte 0x00001608
_081E54E0: .4byte 0x00001514
_081E54E4: .4byte 0x0000161C
_081E54E8: .4byte 0x03002CF0
_081E54EC: .4byte 0x00000E28
_081E54F0: .4byte 0x00000BC4
_081E54F4: .4byte 0x00001622
_081E54F8:
	adds r0, r5, #0
	bl FUN_081e2ee8
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E550A
	b _081E5634
_081E550A:
	ldr r1, _081E5520 @ =0x00001622
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _081E557C
	cmp r0, #2
	bgt _081E5524
	cmp r0, #1
	beq _081E552A
	b _081E5634
	.align 2, 0
_081E5520: .4byte 0x00001622
_081E5524:
	cmp r0, #3
	beq _081E55CC
	b _081E5634
_081E552A:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5540 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5544
	movs r0, #1
	b _081E5546
	.align 2, 0
_081E5540: .4byte 0x00001610
_081E5544:
	movs r0, #0
_081E5546:
	cmp r0, #0
	beq _081E555C
	ldr r3, _081E5558 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E5558: .4byte 0x00000E28
_081E555C:
	ldr r6, _081E5574 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	ldr r7, _081E5578 @ =0x00001622
	adds r1, r5, r7
	movs r0, #2
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E5574: .4byte 0x00000E28
_081E5578: .4byte 0x00001622
_081E557C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5590 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5594
	movs r0, #1
	b _081E5596
	.align 2, 0
_081E5590: .4byte 0x00001610
_081E5594:
	movs r0, #0
_081E5596:
	cmp r0, #0
	beq _081E55AC
	ldr r3, _081E55A8 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55A8: .4byte 0x00000E28
_081E55AC:
	ldr r6, _081E55C4 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	ldr r7, _081E55C8 @ =0x00001622
	adds r1, r5, r7
	movs r0, #3
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E55C4: .4byte 0x00000E28
_081E55C8: .4byte 0x00001622
_081E55CC:
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _081E55E4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E55E8
	movs r0, #1
	b _081E55EA
	.align 2, 0
_081E55E4: .4byte 0x00001610
_081E55E8:
	movs r0, #0
_081E55EA:
	cmp r0, #0
	beq _081E5600
	ldr r2, _081E55FC @ =0x00000E28
	adds r1, r5, r2
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55FC: .4byte 0x00000E28
_081E5600:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5610
	movs r0, #1
	b _081E5612
_081E5610:
	movs r0, #0
_081E5612:
	cmp r0, #0
	beq _081E5634
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5634
	ldr r0, _081E5640 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E5644 @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081E5648 @ =0x00001616
	adds r0, r5, r6
	strb r2, [r0]
_081E5634:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5640: .4byte FUN_081e57f4
_081E5644: .4byte 0x00001614
_081E5648: .4byte 0x00001616
