	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E79B0 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E799A
	bl Marquee_Clear
	bl Marquee_CloseGlobal
	ldr r1, _081E79B4 @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_081e3fe0
	adds r0, r6, #0
	bl FUN_081e4450
	adds r0, r6, #0
	bl FUN_081e2b08
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r0, r6, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E79B8 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E79BC @ =0x00001608
	adds r0, r6, r2
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E79C0 @ =0x0000160C
	adds r4, r6, r0
	ldr r0, [r4]
	bl TextPanel_Hide
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r6, #0x20]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081E79C4 @ =0x000015F0
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0x16
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r1, _081E79C8 @ =0x0000162A
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E799A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E79B4 @ =0x00001610
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E79CC
	movs r0, #1
	b _081E79CE
	.align 2, 0
_081E79B0: .4byte 0x00001614
_081E79B4: .4byte 0x00001610
_081E79B8: .4byte 0x00001604
_081E79BC: .4byte 0x00001608
_081E79C0: .4byte 0x0000160C
_081E79C4: .4byte 0x000015F0
_081E79C8: .4byte 0x0000162A
_081E79CC:
	movs r0, #0
_081E79CE:
	cmp r0, #0
	beq _081E79DC
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	b _081E7A22
_081E79DC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E79EC
	movs r0, #1
	b _081E79EE
_081E79EC:
	movs r0, #0
_081E79EE:
	cmp r0, #0
	beq _081E7A22
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7A22
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7A22
	bl LinkShopManager_StopLinkWatch
	ldr r0, _081E7A2C @ =FUN_081e7a38
	movs r2, #0x1b
	str r0, [r6, #0x18]
	ldr r0, _081E7A30 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7A34 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
_081E7A22:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7A2C: .4byte FUN_081e7a38
_081E7A30: .4byte 0x00001614
_081E7A34: .4byte 0x00001616
