	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BAD68 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BAD42
	b _080BAE3E
_080BAD42:
	adds r0, r5, #0
	bl FUN_080ba980
	adds r4, r0, #0
	ldr r1, _080BAD6C @ =0x00001438
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	beq _080BAD8C
	cmp r4, #4
	bgt _080BAD70
	cmp r4, #1
	beq _080BAD76
	b _080BAE34
	.align 2, 0
_080BAD68: .4byte 0x030044E0
_080BAD6C: .4byte 0x00001438
_080BAD70:
	cmp r4, #5
	beq _080BADDC
	b _080BAE34
_080BAD76:
	adds r0, r5, #0
	bl FUN_080ba624
	ldr r1, _080BAD88 @ =Entity3019_SwapSelectedItem
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE52
	.align 2, 0
_080BAD88: .4byte Entity3019_SwapSelectedItem
_080BAD8C:
	ldr r0, _080BADC8 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r1, _080BADD0 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r1, _080BADCC @ =0x000012E4
	adds r0, r0, r1
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba07c
	ldr r1, _080BADD4 @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BADD8 @ =FUN_080baf50
	b _080BAE14
	.align 2, 0
_080BADC8: .4byte 0x00000107
_080BADCC: .4byte 0x000012E4
_080BADD0: .4byte 0x0000140E
_080BADD4: .4byte 0x00001278
_080BADD8: .4byte FUN_080baf50
_080BADDC:
	ldr r0, _080BAE20 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BAE24 @ =0x000012E4
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _080BAE28 @ =0x0000140E
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r3, r0, #0
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_080ba07c
	ldr r1, _080BAE2C @ =0x00001278
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x77
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #0
	bl FUN_080b9740
	ldr r1, _080BAE30 @ =FUN_080bb01c
_080BAE14:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAE82
	.align 2, 0
_080BAE20: .4byte 0x00000107
_080BAE24: .4byte 0x000012E4
_080BAE28: .4byte 0x0000140E
_080BAE2C: .4byte 0x00001278
_080BAE30: .4byte FUN_080bb01c
_080BAE34:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BAE52
_080BAE3E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BAE58
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080baa64
_080BAE52:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BAE82
_080BAE58:
	ldr r0, _080BAEA4 @ =0x00001408
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BAE82
	ldr r0, _080BAEA8 @ =0x00000D98
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ba85c
_080BAE82:
	ldr r1, _080BAEA4 @ =0x00001408
	adds r0, r5, r1
	ldr r1, _080BAEAC @ =0x00000C78
	adds r2, r5, r1
	subs r1, #0x60
	adds r3, r5, r1
	movs r1, #0
	bl FUN_080b95d0
	ldr r1, _080BAEA8 @ =0x00000D98
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BAEA4: .4byte 0x00001408
_080BAEA8: .4byte 0x00000D98
_080BAEAC: .4byte 0x00000C78
