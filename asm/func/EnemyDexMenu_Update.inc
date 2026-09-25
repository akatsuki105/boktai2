	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x14]
	movs r4, #0
	adds r0, r7, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	bne _0820E0CC
	b _0820E548
_0820E0CC:
	cmp r0, #1
	bgt _0820E0D6
	cmp r0, #0
	beq _0820E0DE
	b _0820E730
_0820E0D6:
	cmp r0, #2
	bne _0820E0DC
	b _0820E748
_0820E0DC:
	b _0820E730
_0820E0DE:
	ldr r0, _0820E0FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E10E
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	beq _0820E100
	subs r0, #1
	b _0820E102
	.align 2, 0
_0820E0FC: .4byte 0x030044E0
_0820E100:
	movs r0, #8
_0820E102:
	strb r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0820E13A
_0820E10E:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E134
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #7
	bhi _0820E128
	adds r0, #1
	strb r0, [r1]
	b _0820E12A
_0820E128:
	strb r4, [r1]
_0820E12A:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
_0820E134:
	cmp r4, #0
	bne _0820E13A
	b _0820E420
_0820E13A:
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	adds r5, r7, #0
	adds r5, #0x26
	movs r1, #0
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0x48
	strb r1, [r0]
	movs r1, #1
	str r1, [sp, #0x14]
	adds r0, r7, #0
	bl FUN_0820d21c
	ldrb r0, [r4]
	bl FUN_0820cbdc
	mov sl, r0
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov sb, r0
	movs r2, #0
	mov r8, r2
	str r4, [sp, #0x2c]
	str r5, [sp, #0x30]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x28]
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0820E1EC @ =0x00000854
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _0820E1F0 @ =0x000005B4
	adds r2, r7, r2
	str r2, [sp, #0x24]
	adds r3, r7, #0
	adds r3, #0x4c
	str r3, [sp, #0x34]
	ldr r0, _0820E1F4 @ =0x00000D94
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _0820E1F8 @ =0x00000E54
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _0820E1FC @ =0x00000D8C
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _0820E200 @ =0x00000E4C
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	cmp r8, sb
	bge _0820E220
	adds r4, #3
	movs r5, #5
_0820E1B6:
	ldr r0, [r4]
	ldr r2, _0820E204 @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0x14
	bl TextPanel_SetRect
	mov r6, sl
	add r6, r8
	adds r0, r6, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E208
	ldr r0, [r4]
	adds r1, r6, #0
	bl TextPanel_SetMessage
	b _0820E210
	.align 2, 0
_0820E1EC: .4byte 0x00000854
_0820E1F0: .4byte 0x000005B4
_0820E1F4: .4byte 0x00000D94
_0820E1F8: .4byte 0x00000E54
_0820E1FC: .4byte 0x00000D8C
_0820E200: .4byte 0x00000E4C
_0820E204: .4byte 0x00001110
_0820E208:
	ldr r0, [r4]
	movs r1, #0x39
	bl TextPanel_SetMessage
_0820E210:
	ldm r4!, {r0}
	bl TextPanel_Start
	adds r5, #2
	movs r3, #1
	add r8, r3
	cmp r8, sb
	blt _0820E1B6
_0820E220:
	movs r3, #1
	ldr r1, [sp, #0x28]
	movs r2, #4
_0820E226:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820E226
	movs r3, #1
	ldr r1, [sp, #0x40]
	movs r2, #2
_0820E23A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820E23A
	movs r6, #0
	movs r3, #0
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _0820E2CE
	lsls r0, r0, #2
	ldr r1, _0820E260 @ =_0820E264
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820E260: .4byte _0820E264
_0820E264: @ jump table
	.4byte _0820E288 @ case 0
	.4byte _0820E28E @ case 1
	.4byte _0820E294 @ case 2
	.4byte _0820E29E @ case 3
	.4byte _0820E2A6 @ case 4
	.4byte _0820E2AC @ case 5
	.4byte _0820E2B6 @ case 6
	.4byte _0820E2BC @ case 7
	.4byte _0820E2C6 @ case 8
_0820E288:
	movs r1, #0
	movs r2, #0
	b _0820E298
_0820E28E:
	movs r1, #0
	movs r2, #1
	b _0820E298
_0820E294:
	movs r1, #0
	movs r2, #2
_0820E298:
	movs r6, #0x70
	movs r3, #0x13
	b _0820E2D2
_0820E29E:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820E2D2
_0820E2A6:
	movs r1, #2
	movs r2, #0
	b _0820E2B0
_0820E2AC:
	movs r1, #2
	movs r2, #1
_0820E2B0:
	movs r6, #0x60
	movs r3, #0x13
	b _0820E2D2
_0820E2B6:
	movs r1, #3
	movs r2, #0
	b _0820E2C0
_0820E2BC:
	movs r1, #3
	movs r2, #1
_0820E2C0:
	movs r6, #0x80
	movs r3, #0x13
	b _0820E2D2
_0820E2C6:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820E2D2
_0820E2CE:
	movs r1, #0
	movs r2, #1
_0820E2D2:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	adds r0, r1, r0
	ldr r1, [r0]
	movs r4, #2
	rsbs r4, r4, #0
	ands r1, r4
	str r1, [r0]
	cmp r2, #0
	blt _0820E30A
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	ldr r0, [sp, #0x40]
	adds r2, r0, r1
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r1, r7, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, _0820E44C @ =0x0000038E
	adds r1, r1, r0
	strh r3, [r1]
_0820E30A:
	movs r1, #0
	ldr r2, [sp, #0x44]
	mov r8, r2
	movs r5, #1
_0820E312:
	lsls r6, r1, #1
	adds r4, r1, #1
	adds r0, r6, r1
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820E320:
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E320
	adds r1, r6, r1
	lsls r1, r1, #5
	ldr r0, [sp, #0x24]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r1, r4, #0
	cmp r1, #6
	ble _0820E312
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r2, [sp, #0x2c]
	ldrb r0, [r2]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x18]
	movs r3, #0
	mov sb, r3
	cmp sb, sl
	bge _0820E3B2
	ldr r0, _0820E450 @ =0x000005CC
	adds r6, r7, r0
	ldr r4, [sp, #0x24]
	movs r1, #0x28
	mov r8, r1
	ldr r2, _0820E454 @ =0x0000084C
	adds r5, r7, r2
_0820E36E:
	ldr r2, [sp, #0x18]
	add r2, sb
	movs r3, #0
	str r3, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r0, #0x28
	strh r0, [r6]
	mov r1, r8
	strh r1, [r6, #2]
	adds r6, #0x60
	adds r4, #0x60
	movs r2, #0x10
	add r8, r2
	adds r5, #0xc0
	movs r3, #1
	add sb, r3
	cmp sb, sl
	blt _0820E36E
_0820E3B2:
	movs r4, #1
	ldr r2, [sp, #0x20]
	ldr r1, [sp, #0x3c]
	movs r3, #1
_0820E3BA:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E3BA
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #0x98
	str r0, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	str r4, [sp]
	movs r0, #0xb0
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	adds r0, r7, #0
	bl FUN_0820d188
_0820E420:
	ldr r0, _0820E458 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0820E47E
	adds r6, r7, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0
	beq _0820E47E
	adds r4, r7, #0
	adds r4, #0x48
	ldrb r0, [r4]
	cmp r0, #0
	beq _0820E45C
	subs r0, r1, #1
	strb r0, [r6]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0820E476
	.align 2, 0
_0820E44C: .4byte 0x0000038E
_0820E450: .4byte 0x000005CC
_0820E454: .4byte 0x0000084C
_0820E458: .4byte 0x030044E0
_0820E45C:
	adds r5, r7, #0
	adds r5, #0x25
	ldrb r0, [r5]
	bl FUN_0820cbec
	subs r0, #1
	strb r0, [r4]
	ldrb r0, [r5]
	bl FUN_0820cbdc
	ldrb r1, [r4]
	adds r1, r1, r0
	strb r1, [r6]
_0820E476:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0820E4DE
_0820E47E:
	ldr r0, _0820E4BC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0820E4D8
	adds r6, r7, #0
	adds r6, #0x26
	ldrb r0, [r6]
	cmp r0, #0x37
	bhi _0820E4D8
	adds r5, r7, #0
	adds r5, #0x48
	ldrb r4, [r5]
	movs r2, #0x25
	adds r2, r2, r7
	mov r8, r2
	ldrb r0, [r2]
	bl FUN_0820cbec
	subs r0, #1
	cmp r4, r0
	bge _0820E4C0
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0820E4CE
	.align 2, 0
_0820E4BC: .4byte 0x030044E0
_0820E4C0:
	mov r3, r8
	ldrb r0, [r3]
	bl FUN_0820cbdc
	movs r1, #0
	strb r0, [r6]
	strb r1, [r5]
_0820E4CE:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	str r0, [sp, #0x14]
_0820E4D8:
	ldr r1, [sp, #0x14]
	cmp r1, #0
	beq _0820E4EE
_0820E4DE:
	adds r0, r7, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x8e
	strh r0, [r1]
_0820E4EE:
	ldr r4, _0820E53C @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E50E
	adds r0, r7, #0
	movs r1, #1
	bl FUN_0820e080
	adds r0, r7, #0
	bl FUN_0820d188
	movs r0, #0xdd
	bl PlaySound_082406e0
_0820E50E:
	ldrh r1, [r4, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0820E51A
	b _0820E730
_0820E51A:
	ldr r2, _0820E540 @ =0x00001258
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0820E52A
	movs r1, #0
	bl Script_ExecById
_0820E52A:
	ldr r0, _0820E544 @ =0x00000119
	bl PlaySound_082406e0
	adds r1, r7, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	b _0820E730
	.align 2, 0
_0820E53C: .4byte 0x030044E0
_0820E540: .4byte 0x00001258
_0820E544: .4byte 0x00000119
_0820E548:
	ldr r0, _0820E564 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0820E574
	adds r1, r7, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #0
	beq _0820E568
	subs r0, #1
	b _0820E56A
	.align 2, 0
_0820E564: .4byte 0x030044E0
_0820E568:
	movs r0, #3
_0820E56A:
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0820E59E
_0820E574:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0820E598
	adds r1, r7, #0
	adds r1, #0x27
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0820E58C
	adds r0, #1
	strb r0, [r1]
	b _0820E58E
_0820E58C:
	strb r4, [r1]
_0820E58E:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #1
	str r3, [sp, #0x14]
_0820E598:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _0820E5B2
_0820E59E:
	adds r0, r7, #0
	adds r0, #0x27
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0820d250
_0820E5B2:
	ldr r0, _0820E5D0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820E5E2
	adds r1, r7, #0
	adds r1, #0x26
	ldrb r0, [r1]
	cmp r0, #0x37
	bhi _0820E5D4
	adds r0, #1
	b _0820E5D6
	.align 2, 0
_0820E5D0: .4byte 0x030044E0
_0820E5D4:
	movs r0, #0
_0820E5D6:
	strb r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0820E614
_0820E5E2:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E610
	adds r0, r7, #0
	adds r0, #0x26
	ldrb r1, [r0]
	str r0, [sp, #0x30]
	cmp r1, #0
	beq _0820E600
	subs r0, r1, #1
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	b _0820E606
_0820E600:
	movs r0, #0x38
	ldr r2, [sp, #0x30]
	strb r0, [r2]
_0820E606:
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #1
_0820E610:
	cmp r4, #0
	beq _0820E6D0
_0820E614:
	adds r0, r7, #0
	bl FUN_0820d250
	movs r4, #0
	adds r3, r7, #0
	adds r3, #0x26
	str r3, [sp, #0x30]
	ldr r0, _0820E6B0 @ =0x000005B4
	adds r0, r7, r0
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0x4c
	str r1, [sp, #0x34]
	ldr r2, _0820E6B4 @ =0x0000084C
	adds r2, r2, r7
	mov sb, r2
	ldr r3, _0820E6B8 @ =0x00000854
	adds r3, r3, r7
	mov r8, r3
	movs r5, #1
_0820E63C:
	lsls r1, r4, #1
	adds r6, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #6
	mov r3, r8
	adds r2, r0, r3
	movs r3, #1
_0820E64A:
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820E64A
	adds r1, r1, r4
	lsls r1, r1, #5
	ldr r0, [sp, #0x24]
	adds r1, r0, r1
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r4, r6, #0
	cmp r4, #6
	ble _0820E63C
	ldr r1, [sp, #0x30]
	ldrb r2, [r1]
	adds r2, #1
	movs r1, #0
	str r1, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r0, sb
	ldr r1, [sp, #0x34]
	movs r3, #2
	bl FUN_082376a4
	ldr r2, [sp, #0x30]
	ldrb r0, [r2]
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820E6C0
	ldr r3, _0820E6BC @ =0x0000125C
	adds r4, r7, r3
	ldr r0, [r4]
	bl FUN_0820feb0
	ldr r0, [r4]
	ldr r2, [sp, #0x30]
	ldrb r1, [r2]
	bl FUN_0820fe98
	b _0820E6CA
	.align 2, 0
_0820E6B0: .4byte 0x000005B4
_0820E6B4: .4byte 0x0000084C
_0820E6B8: .4byte 0x00000854
_0820E6BC: .4byte 0x0000125C
_0820E6C0:
	ldr r3, _0820E70C @ =0x0000125C
	adds r0, r7, r3
	ldr r0, [r0]
	bl FUN_0820fea8
_0820E6CA:
	adds r0, r7, #0
	bl FUN_0820d188
_0820E6D0:
	ldr r0, _0820E710 @ =0x0000114D
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0820E71C
	ldr r0, _0820E714 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820E730
	ldr r2, _0820E718 @ =0x0000110E
	adds r1, r7, r2
	ldrh r0, [r1]
	movs r4, #1
	orrs r0, r4
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0820cc30
	adds r0, r7, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x8e
	strh r0, [r1]
	strb r4, [r5]
	b _0820E730
	.align 2, 0
_0820E70C: .4byte 0x0000125C
_0820E710: .4byte 0x0000114D
_0820E714: .4byte 0x030044E0
_0820E718: .4byte 0x0000110E
_0820E71C:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0820e080
	adds r0, r7, #0
	bl FUN_0820d188
	movs r0, #0xde
	bl PlaySound_082406e0
_0820E730:
	adds r0, r7, #0
	bl FUN_0820d188
	adds r0, r7, #0
	bl FUN_0820d690
	adds r0, r7, #0
	bl FUN_0820d5f8
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
_0820E748:
	movs r0, #0
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
