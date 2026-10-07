	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BBF24 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BBEFE
	b _080BC00A
_080BBEFE:
	adds r0, r5, #0
	bl FUN_080bba88
	adds r4, r0, #0
	ldr r1, _080BBF28 @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BBF48
	cmp r4, #4
	bgt _080BBF2C
	cmp r4, #1
	beq _080BBF32
	b _080BC000
	.align 2, 0
_080BBF24: .4byte 0x030044E0
_080BBF28: .4byte 0x00001438
_080BBF2C:
	cmp r4, #5
	beq _080BBF9C
	b _080BC000
_080BBF32:
	adds r0, r5, #0
	bl FUN_080bb688
	ldr r1, _080BBF44 @ =Entity3019_SwapSelectedArmor
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC01E
	.align 2, 0
_080BBF44: .4byte Entity3019_SwapSelectedArmor
_080BBF48:
	ldr r0, _080BBF84 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBF88 @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBF8C @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BBF90 @ =0x000012F4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BBF94 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BBF98 @ =FUN_080bc11c
	b _080BBFDE
	.align 2, 0
_080BBF84: .4byte 0x00000107
_080BBF88: .4byte 0x000012E8
_080BBF8C: .4byte 0x0000140E
_080BBF90: .4byte 0x000012F4
_080BBF94: .4byte 0x00001278
_080BBF98: .4byte FUN_080bc11c
_080BBF9C:
	ldr r0, _080BBFE8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BBFEC @ =0x000012E8
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BBFF0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _080BBFF4 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba07c
	ldr r1, _080BBFF8 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BBFFC @ =FUN_080bc1ec
_080BBFDE:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BC04E
	.align 2, 0
_080BBFE8: .4byte 0x00000107
_080BBFEC: .4byte 0x000012E8
_080BBFF0: .4byte 0x0000140E
_080BBFF4: .4byte 0x030046A0
_080BBFF8: .4byte 0x00001278
_080BBFFC: .4byte FUN_080bc1ec
_080BC000:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BC01E
_080BC00A:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BC024
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC01E:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BC04E
_080BC024:
	ldr r0, _080BC070 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BC04E
	ldr r0, _080BC074 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080bb294
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bb8f4
_080BC04E:
	ldr r1, _080BC070 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BC078 @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BC074 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BC070: .4byte 0x00001408
_080BC074: .4byte 0x00000D98
_080BC078: .4byte 0x00000C78
