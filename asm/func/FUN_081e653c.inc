	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E6584 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E654E
	b _081E664A
_081E654E:
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl Video_SetBGLayer
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r1, #1
	ldr r2, _081E6588 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E658C
	movs r0, #1
	b _081E658E
	.align 2, 0
_081E6584: .4byte 0x00001614
_081E6588: .4byte 0x00001610
_081E658C:
	movs r0, #0
_081E658E:
	cmp r0, #0
	beq _081E65A8
	bl Marquee_Clear
	bl Marquee_RequestClose
	ldr r0, _081E6660 @ =0x00001610
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E65A8:
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E6664 @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E6668 @ =0x00001608
	adds r5, r7, r0
	ldr r0, [r5]
	bl TextPanel_Hide
	ldr r1, _081E666C @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081E6670 @ =0x000015F0
	adds r6, r7, r2
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xe
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r0, [r5]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl TextPanel_SetRect
	ldr r0, [r5]
	ldr r1, [r6]
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #0x12
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	ldr r0, _081E6674 @ =0x00001614
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
_081E664A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6660 @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6678
	movs r0, #1
	b _081E667A
	.align 2, 0
_081E6660: .4byte 0x00001610
_081E6664: .4byte 0x00001604
_081E6668: .4byte 0x00001608
_081E666C: .4byte 0x0000160C
_081E6670: .4byte 0x000015F0
_081E6674: .4byte 0x00001614
_081E6678:
	movs r0, #0
_081E667A:
	cmp r0, #0
	beq _081E6688
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	b _081E66CA
_081E6688:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6698
	movs r0, #1
	b _081E669A
_081E6698:
	movs r0, #0
_081E669A:
	cmp r0, #0
	beq _081E66CA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _081E66CA
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E66CA
	ldr r0, _081E66D4 @ =FUN_081e66e0
	movs r2, #0x12
	str r0, [r7, #0x18]
	ldr r0, _081E66D8 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E66DC @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E66CA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E66D4: .4byte FUN_081e66e0
_081E66D8: .4byte 0x00001614
_081E66DC: .4byte 0x00001616
