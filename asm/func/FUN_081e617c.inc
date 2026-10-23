	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E6248 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E6210
	bl Marquee_Clear
	bl Marquee_CloseGlobal
	ldr r1, _081E624C @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
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
	ldr r2, _081E6250 @ =0x0000160C
	adds r4, r6, r2
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r3, _081E6254 @ =0x000015F4
	adds r1, r6, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #6
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	bl LinkShopManager_StopLinkWatch
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r4, _081E6258 @ =0x0000162A
	adds r0, r6, r4
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E6210:
	ldr r0, _081E6258 @ =0x0000162A
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x3b
	bne _081E622C
	bl LinkShopManager_Kill
	movs r2, #0x80
	lsls r2, r2, #0xe
	ldr r3, _081E624C @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E622C:
	ldrh r0, [r4]
	cmp r0, #0x3c
	beq _081E6234
	b _081E636A
_081E6234:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r4, _081E624C @ =0x00001610
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E625C
	movs r0, #1
	b _081E625E
	.align 2, 0
_081E6248: .4byte 0x00001614
_081E624C: .4byte 0x00001610
_081E6250: .4byte 0x0000160C
_081E6254: .4byte 0x000015F4
_081E6258: .4byte 0x0000162A
_081E625C:
	movs r0, #0
_081E625E:
	cmp r0, #0
	beq _081E62AC
	ldr r1, _081E6298 @ =0x00000E28
	adds r0, r6, r1
	bl AddWeapon
	ldr r3, _081E629C @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r2, r0, r4
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, _081E62A0 @ =0x000015E2
	adds r0, r6, r4
	ldrh r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081E6286
	movs r1, #0
_081E6286:
	strh r1, [r2]
	ldr r0, [r3]
	ldr r2, _081E62A4 @ =0x0000091A
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #1
	ldr r2, _081E62A8 @ =0x0000270F
	b _081E62E6
	.align 2, 0
_081E6298: .4byte 0x00000E28
_081E629C: .4byte 0x030046A0
_081E62A0: .4byte 0x000015E2
_081E62A4: .4byte 0x0000091A
_081E62A8: .4byte 0x0000270F
_081E62AC:
	ldr r4, _081E6310 @ =0x00001599
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl RemoveWeapon
	ldr r4, _081E6314 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r2, _081E6318 @ =0x000015E2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r0, [r3, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, _081E631C @ =0x0000270F
	cmp r0, r2
	ble _081E62D8
	adds r0, r2, #0
_081E62D8:
	strh r0, [r3]
	ldr r0, [r4]
	ldr r3, _081E6320 @ =0x00000918
	adds r1, r0, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r0, #1
_081E62E6:
	cmp r0, r2
	ble _081E62EC
	adds r0, r2, #0
_081E62EC:
	strh r0, [r1]
	bl Save_WriteExtraToNextSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6330
	ldr r0, _081E6324 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r0, _081E6328 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E632C @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6310: .4byte 0x00001599
_081E6314: .4byte 0x030046A0
_081E6318: .4byte 0x000015E2
_081E631C: .4byte 0x0000270F
_081E6320: .4byte 0x00000918
_081E6324: .4byte FUN_081e6458
_081E6328: .4byte 0x00001614
_081E632C: .4byte 0x00001616
_081E6330:
	movs r0, #0x96
	lsls r0, r0, #2
	movs r1, #0
	bl LinkConnect_Create
	cmp r0, #0
	bne _081E6360
	ldr r0, _081E6354 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r3, _081E6358 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r4, _081E635C @ =0x00001616
	adds r0, r6, r4
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6354: .4byte FUN_081e6458
_081E6358: .4byte 0x00001614
_081E635C: .4byte 0x00001616
_081E6360:
	ldr r1, _081E637C @ =FUN_081e4b68
	ldr r2, _081E6380 @ =FUN_081e4bb8
	adds r0, r6, #0
	bl LinkConnect_SetCallbacks
_081E636A:
	ldr r0, _081E6384 @ =0x0000162A
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E6374:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E637C: .4byte FUN_081e4b68
_081E6380: .4byte FUN_081e4bb8
_081E6384: .4byte 0x0000162A
