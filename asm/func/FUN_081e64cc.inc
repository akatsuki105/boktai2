	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E6518 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6508
	ldr r2, _081E651C @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #2
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r0, _081E6520 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl LinkShopManager_AllowSoftReset
_081E6508:
	ldr r2, _081E6520 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E6524
	adds r0, #1
	strh r0, [r1]
	b _081E6532
	.align 2, 0
_081E6518: .4byte 0x00001614
_081E651C: .4byte 0x0000160C
_081E6520: .4byte 0x0000162A
_081E6524:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E6538 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E6532:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E6538: .4byte 0x00001610
