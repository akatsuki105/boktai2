	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081E2530 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E253E
	adds r3, r0, #0
	ldr r1, _081E2534 @ =0x00001003
	ldr r0, [r3, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2538
	movs r0, #1
	b _081E253A
	.align 2, 0
_081E2530: .4byte 0x03002C6C
_081E2534: .4byte 0x00001003
_081E2538:
	movs r0, #0
_081E253A:
	cmp r0, #0
	beq _081E2542
_081E253E:
	movs r0, #0
	b _081E25CE
_081E2542:
	cmp r4, #3
	bne _081E2558
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	ldr r0, [r5, #4]
	str r0, [r3, #0x44]
	ldr r0, [r5, #8]
_081E2552:
	str r0, [r3, #0x48]
_081E2554:
	strh r2, [r3, #0x3e]
	b _081E25AA
_081E2558:
	cmp r4, #4
	bne _081E256A
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0xc]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x10]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x14]
	b _081E2552
_081E256A:
	cmp r4, #5
	bne _081E257C
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0x18]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x20]
	b _081E2552
_081E257C:
	cmp r4, #0xa
	bne _081E2588
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E2588:
	cmp r4, #0xb
	bne _081E2590
	strh r4, [r3, #0x3c]
	b _081E2554
_081E2590:
	cmp r4, #0xc
	bne _081E259C
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E259C:
	cmp r4, #6
	beq _081E25A8
	cmp r4, #7
	beq _081E25A8
	cmp r4, #8
	bne _081E25CC
_081E25A8:
	strh r4, [r3, #0x3c]
_081E25AA:
	ldr r2, _081E25D4 @ =LinkShopManager_StateSendWait
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x64]
	ands r0, r1
	str r2, [r3, #0x4c]
	adds r0, r3, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r3, #0x64]
	orrs r0, r1
	str r0, [r3, #0x64]
_081E25CC:
	movs r0, #1
_081E25CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E25D4: .4byte LinkShopManager_StateSendWait
