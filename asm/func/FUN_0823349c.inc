	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	mov r8, r1
	str r2, [sp, #0x50]
	ldr r0, [sp, #0x88]
	ldr r1, [sp, #0x8c]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x58]
	movs r5, #0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _082334D2
	movs r5, #0x10
	b _082334D8
_082334D2:
	cmp r0, #0
	bge _082334D8
	movs r5, #0x20
_082334D8:
	ldr r2, [sp, #0x50]
	movs r4, #4
	ldrsh r0, [r2, r4]
	ldrh r1, [r2, #4]
	mov sb, r1
	cmp r0, #0
	ble _082334EA
	movs r0, #1
	b _082334F0
_082334EA:
	cmp r0, #0
	bge _082334F2
	movs r0, #2
_082334F0:
	orrs r5, r0
_082334F2:
	mov r4, r8
	ldrh r2, [r4]
	lsls r0, r2, #0x10
	asrs r4, r0, #0x18
	mov r0, r8
	ldrh r1, [r0, #4]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	adds r6, r1, #0
	cmp r4, #0
	blt _0823351C
	cmp r3, #0
	blt _0823351C
	ldr r0, _08233520 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0823351C
	ldr r0, _08233524 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _08233528
_0823351C:
	movs r0, #0
	b _08233536
	.align 2, 0
_08233520: .4byte 0x030046A8
_08233524: .4byte 0x030046AC
_08233528:
	ldr r0, _08233580 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
_08233536:
	strh r0, [r7, #6]
	ldr r1, [sp, #0x50]
	ldrh r0, [r1]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	ldr r3, _08233584 @ =0xFFFF0000
	ldrh r1, [r1, #2]
	mov r2, r8
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r2, _08233588 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	mov r4, sb
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	cmp r5, #0x22
	bls _08233574
	bl FUN_08233d40
_08233574:
	lsls r0, r5, #2
	ldr r1, _0823358C @ =_08233590
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08233580: .4byte 0x030046A4
_08233584: .4byte 0xFFFF0000
_08233588: .4byte 0x0000FFFF
_0823358C: .4byte _08233590
_08233590: @ jump table
	.4byte _0823361C @ case 0
	.4byte _0823374C @ case 1
	.4byte _082337D2 @ case 2
	.4byte _08233D40 @ case 3
	.4byte _08233D40 @ case 4
	.4byte _08233D40 @ case 5
	.4byte _08233D40 @ case 6
	.4byte _08233D40 @ case 7
	.4byte _08233D40 @ case 8
	.4byte _08233D40 @ case 9
	.4byte _08233D40 @ case 10
	.4byte _08233D40 @ case 11
	.4byte _08233D40 @ case 12
	.4byte _08233D40 @ case 13
	.4byte _08233D40 @ case 14
	.4byte _08233D40 @ case 15
	.4byte _0823362A @ case 16
	.4byte _08233858 @ case 17
	.4byte _08233AAA @ case 18
	.4byte _08233D40 @ case 19
	.4byte _08233D40 @ case 20
	.4byte _08233D40 @ case 21
	.4byte _08233D40 @ case 22
	.4byte _08233D40 @ case 23
	.4byte _08233D40 @ case 24
	.4byte _08233D40 @ case 25
	.4byte _08233D40 @ case 26
	.4byte _08233D40 @ case 27
	.4byte _08233D40 @ case 28
	.4byte _08233D40 @ case 29
	.4byte _08233D40 @ case 30
	.4byte _08233D40 @ case 31
	.4byte _082336C8 @ case 32
	.4byte _08233998 @ case 33
	.4byte _08233BE8 @ case 34
_0823361C:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_0823362A:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r1, [r4]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0823367C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233680
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
	.align 2, 0
_0823367C: .4byte 0xFFFF0000
_08233680:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082336BA
	mov r1, sp
	ldrh r0, [r1, #8]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r1, #8]
	ldrh r0, [r1, #0xc]
	adds r0, r4, r0
	strh r0, [r1, #0xc]
	b _08233CDC
_082336BA:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_082336C8:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	mov r1, sl
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233702
	mov r4, sp
	ldrh r0, [r4, #8]
	add r0, sl
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233CDA
_08233702:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823373E
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823373E:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_0823374C:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233788
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
_08233788:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082337C4
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	b _08233CDC
_082337C4:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_082337D2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823380E
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823380E:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823384A
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823384A:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_08233858:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233894
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
_08233894:
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	add r5, sp, #0x10
	add r1, sl
	ldrh r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0823390C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r1, r5, #0
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	mov sb, r0
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x18
	ldr r2, [sp, #0x54]
	adds r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	mov r1, sb
	cmp r1, #0
	beq _08233910
	cmp r0, #0
	beq _0823397A
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_0823390C: .4byte 0xFFFF0000
_08233910:
	cmp r0, #0
	bne _08233950
	ldrh r0, [r7, #6]
	ldr r4, _0823394C @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	mov r2, sl
	subs r1, r1, r2
	strh r1, [r4, #8]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1, #0xc]
	b _08233CDC
	.align 2, 0
_0823394C: .4byte 0x030046A8
_08233950:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldrh r0, [r5]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r5]
	ldr r4, [sp, #0x50]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	bl FUN_082332f8
	b _08233D3C
_0823397A:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233D30
_08233998:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082339D4
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	b _08233CDC
_082339D4:
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	add r0, sp, #0x20
	mov sb, r0
	mov r2, sl
	subs r1, r1, r2
	ldrh r4, [r0]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233A50 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x5c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x28
	ldr r2, [sp, #0x54]
	adds r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x5c]
	cmp r1, #0
	beq _08233A54
	cmp r0, #0
	beq _08233A8C
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233A50: .4byte 0xFFFF0000
_08233A54:
	cmp r0, #0
	beq _08233A5A
	b _08233CEC
_08233A5A:
	ldrh r0, [r7, #6]
	ldr r4, _08233A88 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	add r1, sl
	strh r1, [r4, #8]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233CDA
	.align 2, 0
_08233A88: .4byte 0x030046A8
_08233A8C:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233D30
_08233AAA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	subs r0, r0, r2
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233AE4
	mov r4, sp
	ldrh r0, [r4, #8]
	mov r1, sl
	subs r0, r0, r1
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	b _08233CDA
_08233AE4:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0]
	add r2, sp, #0x30
	mov sb, r2
	add r1, sl
	ldrh r4, [r2]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233B5C @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x30]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x60]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x38
	ldr r2, [sp, #0x54]
	subs r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x60]
	cmp r1, #0
	beq _08233B60
	cmp r0, #0
	beq _08233BCA
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233B5C: .4byte 0xFFFF0000
_08233B60:
	cmp r0, #0
	bne _08233B9C
	ldrh r0, [r7, #6]
	ldr r4, _08233B98 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	mov r2, sl
	subs r1, r1, r2
	strh r1, [r4, #8]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	mov r1, sp
	strh r0, [r1, #0xc]
	b _08233CDC
	.align 2, 0
_08233B98: .4byte 0x030046A8
_08233B9C:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	mov r2, sb
	ldrh r0, [r2]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2]
	ldr r1, [sp, #0x50]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	mov r4, sb
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	bl FUN_082332f8
	b _08233D3C
_08233BCA:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r1, [sp, #0x50]
	ldrh r0, [r1]
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	b _08233D30
_08233BE8:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r1]
	adds r4, r1, #0
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233C2E
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	bl FUN_082332f8
	b _08233D3C
_08233C2E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0]
	add r2, sp, #0x40
	mov sb, r2
	mov r4, sl
	subs r1, r1, r4
	ldrh r0, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233CA8 @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x40]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x64]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x48
	ldr r2, [sp, #0x54]
	subs r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x64]
	cmp r1, #0
	beq _08233CAC
	cmp r0, #0
	beq _08233D14
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233CA8: .4byte 0xFFFF0000
_08233CAC:
	cmp r0, #0
	bne _08233CEC
	ldrh r0, [r7, #6]
	ldr r4, _08233CE8 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	add r1, sl
	strh r1, [r4, #8]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
_08233CDA:
	strh r0, [r4, #0xc]
_08233CDC:
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	bl FUN_082332f8
	b _08233D3C
	.align 2, 0
_08233CE8: .4byte 0x030046A8
_08233CEC:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	mov r2, sb
	ldrh r0, [r2]
	add r0, sl
	strh r0, [r2]
	ldr r4, [sp, #0x50]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r7, #0
	mov r1, r8
	bl FUN_082332f8
	b _08233D3C
_08233D14:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
_08233D30:
	strh r0, [r6, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_082332f8
_08233D3C:
	movs r0, #1
_08233D3E:
	strb r0, [r7]

_08233D40:
FUN_08233d40:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
