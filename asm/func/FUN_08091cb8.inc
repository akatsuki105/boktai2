	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08091CE0 @ =0x03002BE0
	ldr r5, [r0]
	cmp r5, #0
	bne _08091CC6
	b _08091E26
_08091CC6:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091CE4
	adds r0, r4, #0
	bl item_08091774
	cmp r0, #1
	bne _08091CFA
	b _08091E26
	.align 2, 0
_08091CE0: .4byte 0x03002BE0
_08091CE4:
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08091CFA
	adds r0, r4, #0
	bl item_08091774
	cmp r0, #0
	bne _08091CFA
	b _08091E26
_08091CFA:
	cmp r4, #0x1e
	bne _08091D06
	movs r0, #0
_08091D00:
	bl FUN_080916bc
	b _08091E22
_08091D06:
	cmp r4, #0x1f
	bne _08091D0E
	movs r0, #1
	b _08091D00
_08091D0E:
	adds r0, r4, #0
	subs r0, #0x1b
	cmp r0, #2
	bhi _08091D1A
	movs r0, #2
	b _08091D00
_08091D1A:
	cmp r4, #0x31
	bne _08091D22
	movs r0, #3
	b _08091D00
_08091D22:
	cmp r4, #1
	bne _08091D32
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08091D82
_08091D32:
	adds r0, r4, #0
	bl item_08091788
	subs r0, #1
	cmp r0, #4
	bhi _08091E26
	lsls r0, r0, #2
	ldr r1, _08091D48 @ =_08091D4C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08091D48: .4byte _08091D4C
_08091D4C: @ jump table
	.4byte _08091D82 @ case 0
	.4byte _08091D60 @ case 1
	.4byte _08091D70 @ case 2
	.4byte _08091D8C @ case 3
	.4byte _08091DEC @ case 4
_08091D60:
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, _08091D6C @ =0x00000366
	b _08091D78
	.align 2, 0
_08091D6C: .4byte 0x00000366
_08091D70:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, _08091D88 @ =0x0000036A
_08091D78:
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08091E26
_08091D82:
	movs r0, #1
	b _08091E28
	.align 2, 0
_08091D88: .4byte 0x0000036A
_08091D8C:
	movs r2, #0
	ldr r1, _08091DDC @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r3, r0, r1
	ldr r0, _08091DE0 @ =0x0000043C
	adds r1, r5, r0
	movs r6, #1
_08091D9A:
	ldrh r0, [r1]
	cmp r0, #0
	beq _08091DAA
	ldrh r0, [r3, #6]
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	bne _08091D82
_08091DAA:
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	ble _08091D9A
	ldr r1, _08091DE4 @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08091DE8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08091E26
	ldr r1, _08091DDC @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	movs r0, #8
	ands r0, r1
	b _08091E22
	.align 2, 0
_08091DDC: .4byte 0x08DAA8D8
_08091DE0: .4byte 0x0000043C
_08091DE4: .4byte 0x0000038E
_08091DE8: .4byte 0x030046A0
_08091DEC:
	ldr r0, _08091E30 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08091E26
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetWeapon
	adds r1, r0, #0
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08091D82
	ldrb r0, [r1, #0x14]
	cmp r0, #0
	bne _08091D82
	ldrb r0, [r1, #0x18]
_08091E22:
	cmp r0, #0
	bne _08091D82
_08091E26:
	movs r0, #0
_08091E28:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091E30: .4byte 0x030046A0
