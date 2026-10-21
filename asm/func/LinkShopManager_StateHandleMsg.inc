	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1E3E
	movs r0, #0
	strb r0, [r1]
_081E1E3E:
	movs r1, #2
	ldr r0, [r4, #0x64]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081E1E5A
	movs r0, #1
	b _081E1E5C
_081E1E5A:
	movs r0, #0
_081E1E5C:
	cmp r0, #0
	beq _081E1EA0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, _081E1E98 @ =0x030046A0
	ldr r2, [r0]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x40]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x44]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x48]
_081E1E8C:
	ldr r2, _081E1E9C @ =LinkShopManager_StateSendWait
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	b _081E1F10
	.align 2, 0
_081E1E98: .4byte 0x030046A0
_081E1E9C: .4byte LinkShopManager_StateSendWait
_081E1EA0:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1EB2
	movs r0, #1
	b _081E1EB4
_081E1EB2:
	movs r0, #0
_081E1EB4:
	cmp r0, #0
	beq _081E1EDC
	ldr r1, _081E1ED4 @ =0xFFFFFEFF
	ands r1, r2
	str r1, [r4, #0x64]
	movs r0, #0
	strh r0, [r4, #0x3c]
	ldr r0, _081E1ED8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x40]
	b _081E1E8C
	.align 2, 0
_081E1ED4: .4byte 0xFFFFFEFF
_081E1ED8: .4byte 0x030046A0
_081E1EDC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E1EEA
	movs r0, #1
	b _081E1EEC
_081E1EEA:
	movs r0, #0
_081E1EEC:
	cmp r0, #0
	beq _081E1F34
	ldr r0, _081E1F2C @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r4, #0x64]
	movs r0, #2
	strh r0, [r4, #0x3c]
	bl CountSellableWeapons
	str r0, [r4, #0x40]
	bl CountSellableOrEmptySlots
	str r0, [r4, #0x44]
	ldr r2, _081E1F30 @ =LinkShopManager_StateSendWait
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
_081E1F10:
	str r2, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1F74
	.align 2, 0
_081E1F2C: .4byte 0xFFFFFDFF
_081E1F30: .4byte LinkShopManager_StateSendWait
_081E1F34:
	ldr r2, [r4, #0x7c]
	cmp r2, #0
	beq _081E1F44
	ldr r0, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x3c
	bl _call_via_r2
_081E1F44:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1F56
	movs r0, #1
	b _081E1F58
_081E1F56:
	movs r0, #0
_081E1F58:
	cmp r0, #0
	bne _081E1F74
	ldr r1, _081E1F7C @ =LinkShopManager_StateIdle
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1F74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1F7C: .4byte LinkShopManager_StateIdle
