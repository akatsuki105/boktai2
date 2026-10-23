	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6AA0 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6A54
	ldr r1, _081E6AA4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r3, _081E6AA8 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6A54:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6ABC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AA8 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6AAC @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _081E6AB0 @ =0x000014B4
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AB4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6AA0 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E6AB8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6B42
	.align 2, 0
_081E6AA0: .4byte 0x00001614
_081E6AA4: .4byte 0x00001608
_081E6AA8: .4byte 0x00001514
_081E6AAC: .4byte 0x00001624
_081E6AB0: .4byte 0x000014B4
_081E6AB4: .4byte FUN_081e653c
_081E6AB8: .4byte 0x00001616
_081E6ABC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E6AEC @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E6AF0 @ =0x00000AC8
	adds r1, r4, r2
	bl MainSprite_AdvanceAnim
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6B42
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r3, _081E6AF4 @ =0x00001610
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E6AF8
	movs r0, #1
	b _081E6AFA
	.align 2, 0
_081E6AEC: .4byte 0x00000808
_081E6AF0: .4byte 0x00000AC8
_081E6AF4: .4byte 0x00001610
_081E6AF8:
	movs r0, #0
_081E6AFA:
	cmp r0, #0
	beq _081E6B42
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bne _081E6B42
	bl Marquee_Clear
	adds r0, r4, #0
	bl FUN_081e4544
	ldr r3, _081E6B48 @ =0x0000161A
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #0x19
	ldr r2, _081E6B4C @ =0x00001617
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #0x12
	adds r0, r4, r3
	ldr r0, [r0]
	bl TextPanel_Start
	ldr r0, _081E6B50 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r4, #0x18]
	ldr r0, _081E6B54 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6B58 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6B42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6B48: .4byte 0x0000161A
_081E6B4C: .4byte 0x00001617
_081E6B50: .4byte FUN_081e6f28
_081E6B54: .4byte 0x00001614
_081E6B58: .4byte 0x00001616
