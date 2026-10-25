	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6890 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6838
	ldr r1, _081E6894 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r3, _081E6898 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6838:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E68AC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6898 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E689C @ =0x000014B4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E68A0 @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _081E68A4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6890 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E68A8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6A06
	.align 2, 0
_081E6890: .4byte 0x00001614
_081E6894: .4byte 0x00001608
_081E6898: .4byte 0x00001514
_081E689C: .4byte 0x000014B4
_081E68A0: .4byte 0x00001624
_081E68A4: .4byte FUN_081e653c
_081E68A8: .4byte 0x00001616
_081E68AC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E68E0 @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E68E4 @ =0x00000AC8
	adds r1, r4, r2
	bl MainSprite_AdvanceAnim
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E68CA
	b _081E6A06
_081E68CA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, _081E68E8 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E68EC
	movs r0, #1
	b _081E68EE
	.align 2, 0
_081E68E0: .4byte 0x00000808
_081E68E4: .4byte 0x00000AC8
_081E68E8: .4byte 0x00001610
_081E68EC:
	movs r0, #0
_081E68EE:
	cmp r0, #0
	bne _081E68F4
	b _081E6A06
_081E68F4:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	beq _081E6904
	b _081E6A06
_081E6904:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6914
	movs r0, #1
	b _081E6916
_081E6914:
	movs r0, #0
_081E6916:
	cmp r0, #0
	beq _081E69A8
	ldr r0, _081E695C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _081E6960 @ =0x000015E4
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E696C
	ldr r0, _081E6964 @ =0x00001617
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x10
	beq _081E6A06
	bl Marquee_Clear
	ldr r1, _081E6968 @ =0x000015F0
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #0x10
	b _081E6992
	.align 2, 0
_081E695C: .4byte 0x030046A0
_081E6960: .4byte 0x000015E4
_081E6964: .4byte 0x00001617
_081E6968: .4byte 0x000015F0
_081E696C:
	ldr r2, _081E699C @ =0x00001617
	adds r5, r4, r2
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x11
	beq _081E6A06
	bl Marquee_Clear
	ldr r3, _081E69A0 @ =0x000015F0
	adds r0, r4, r3
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl GetStringByID
	bl Marquee_SetText
	movs r0, #0x11
_081E6992:
	strb r0, [r5]
	ldr r0, _081E69A4 @ =FUN_081e6b5c
	movs r2, #7
	b _081E69F6
	.align 2, 0
_081E699C: .4byte 0x00001617
_081E69A0: .4byte 0x000015F0
_081E69A4: .4byte FUN_081e6b5c
_081E69A8:
	bl Marquee_Clear
	ldr r2, _081E6A0C @ =0x0000161A
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _081E69F2
	adds r0, r4, #0
	bl FUN_081e4544
	ldrb r0, [r5]
	adds r0, #0x19
	ldr r3, _081E6A10 @ =0x00001617
	adds r1, r4, r3
	strb r0, [r1]
	ldr r1, _081E6A14 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Start
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r2, _081E6A18 @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E69F2
	ldr r3, _081E6A1C @ =0x00001514
	adds r0, r4, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E69F2:
	ldr r0, _081E6A20 @ =FUN_081e7414
	movs r2, #4
_081E69F6:
	str r0, [r4, #0x18]
	ldr r0, _081E6A24 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6A28 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6A06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6A0C: .4byte 0x0000161A
_081E6A10: .4byte 0x00001617
_081E6A14: .4byte 0x00001608
_081E6A18: .4byte 0x00000BC4
_081E6A1C: .4byte 0x00001514
_081E6A20: .4byte FUN_081e7414
_081E6A24: .4byte 0x00001614
_081E6A28: .4byte 0x00001616
