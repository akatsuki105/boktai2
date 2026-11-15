	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x24]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x2a]
	lsls r0, r0, #4
	ldrh r2, [r4, #0x28]
	ldr r3, _080A133C @ =0xFFFFF000
	adds r1, r2, r3
	subs r1, r0, r1
	ldr r3, _080A1340 @ =0x00000FFF
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080A1344
	movs r0, #0x80
	lsls r0, r0, #5
	subs r1, r0, r1
	adds r0, r2, r0
	asrs r1, r1, #4
	subs r0, r0, r1
	b _080A1348
	.align 2, 0
_080A133C: .4byte 0xFFFFF000
_080A1340: .4byte 0x00000FFF
_080A1344:
	asrs r0, r1, #4
	adds r0, r2, r0
_080A1348:
	ands r0, r3
	strh r0, [r4, #0x28]
	ldr r1, _080A1370 @ =0x03002BAC
	ldrh r0, [r4, #0x24]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldr r1, _080A1374 @ =0x03002B90
	ldrh r0, [r4, #0x28]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A1378
	cmp r0, #1
	bgt _080A1368
	b _080A1470
_080A1368:
	cmp r0, #2
	beq _080A13F0
	b _080A1470
	.align 2, 0
_080A1370: .4byte 0x03002BAC
_080A1374: .4byte 0x03002B90
_080A1378:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A138C
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A13AE
_080A138C:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A13D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A13AE:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _080A13D4 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A13DC
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A13D0: .4byte 0x030046B8
_080A13D4: .4byte 0x000003FF
_080A13D8: .4byte 0x0203B400
_080A13DC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A13EC @ =0x0203B400
	adds r0, r0, r1
	b _080A144E
	.align 2, 0
_080A13EC: .4byte 0x0203B400
_080A13F0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1404
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A1426
_080A1404:
	ldr r2, _080A1430 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1434 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080A1438 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A1426:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A143C
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A1430: .4byte 0x030046B8
_080A1434: .4byte 0x000003FF
_080A1438: .4byte 0x0203B400
_080A143C:
	ldr r2, _080A1460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A1468 @ =0x0203B400
	adds r0, r0, r5
_080A144E:
	ldrh r0, [r0]
	ldrh r1, [r4, #0x22]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x2c]
	b _080A1470
	.align 2, 0
_080A1460: .4byte 0x030046B8
_080A1464: .4byte 0x000003FF
_080A1468: .4byte 0x0203B400
_080A146C:
	subs r0, #1
_080A146E:
	strh r0, [r4, #0x2c]
_080A1470:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
