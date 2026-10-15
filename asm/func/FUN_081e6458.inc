	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E64A8 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6496
	ldr r2, _081E64AC @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #5
	bl TextPanel_SetMessage
	ldr r0, _081E64B0 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl LinkShopManager_AllowSoftReset
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081E6496:
	ldr r2, _081E64B0 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E64B4
	adds r0, #1
	strh r0, [r1]
	b _081E64C2
	.align 2, 0
_081E64A8: .4byte 0x00001614
_081E64AC: .4byte 0x0000160C
_081E64B0: .4byte 0x0000162A
_081E64B4:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E64C8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E64C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E64C8: .4byte 0x00001610
