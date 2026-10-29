	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C5C82
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C5C82:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #2
	bgt _080C5CB0
	ldr r2, _080C5CAC @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	b _080C5D04
	.align 2, 0
_080C5CAC: .4byte 0x000002F2
_080C5CB0:
	cmp r5, #3
	bne _080C5CBE
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080c4a54
	b _080C5D62
_080C5CBE:
	cmp r5, #0x1a
	ble _080C5D62
	cmp r5, #0x1d
	bgt _080C5CEC
	cmp r5, #0x1b
	bne _080C5CE0
	ldr r2, _080C5CE8 @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x20
	strh r0, [r1]
_080C5CE0:
	adds r0, r4, #0
	bl Jormungandr_EasePos
	b _080C5D62
	.align 2, 0
_080C5CE8: .4byte 0x000002F2
_080C5CEC:
	cmp r5, #0x20
	bgt _080C5D14
	ldr r2, _080C5D10 @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x30
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x30
_080C5D04:
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4a2c
	b _080C5D62
	.align 2, 0
_080C5D10: .4byte 0x000002F2
_080C5D14:
	cmp r5, #0x21
	bne _080C5D58
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080C5D54 @ =0x000002FA
	adds r1, r4, r0
	subs r2, #0x70
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0x72
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C5D62
	.align 2, 0
_080C5D54: .4byte 0x000002FA
_080C5D58:
	cmp r5, #0x21
	ble _080C5D62
	adds r0, r4, #0
	bl Jormungandr_EasePos
_080C5D62:
	cmp r5, #0x1a
	bne _080C5D76
	ldr r0, _080C5DB8 @ =0x00000232
	bl PlaySound_082406e0
	ldr r1, _080C5DBC @ =0x00001934
	adds r0, r6, r1
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D76:
	cmp r5, #0x1c
	bne _080C5D84
	ldr r2, _080C5DC4 @ =0x00001E84
	adds r0, r6, r2
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D84:
	cmp r5, #0x1e
	bne _080C5D92
	ldr r1, _080C5DC8 @ =0x0000212C
	adds r0, r6, r1
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D92:
	cmp r5, #0x20
	bne _080C5DA0
	ldr r2, _080C5DCC @ =0x00001BDC
	adds r0, r6, r2
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5DA0:
	cmp r5, #0x28
	bne _080C5DB0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl MsgQueue_EndWait
_080C5DB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C5DB8: .4byte 0x00000232
_080C5DBC: .4byte 0x00001934
_080C5DC0: .4byte 0x080C2825
_080C5DC4: .4byte 0x00001E84
_080C5DC8: .4byte 0x0000212C
_080C5DCC: .4byte 0x00001BDC
