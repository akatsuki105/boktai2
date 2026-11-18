	push {r4, lr}
	adds r3, r0, #0
	movs r1, #9
	ldrsb r1, [r3, r1]
	cmp r1, #0x40
	ble _0819869E
	ldr r2, _08198704 @ =0x00000187
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r1, #0x3f
	bgt _0819869E
	movs r1, #0x40
_0819869E:
	strb r1, [r3, #9]
	cmp r1, #0x40
	bne _081986FE
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _08198708 @ =FUN_081985d8
	str r0, [r1]
	ldr r2, _0819870C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198710 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08198714 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #1
	ands r0, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	cmp r0, #0
	beq _081986D2
	movs r1, #1
_081986D2:
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	movs r1, #0x8b
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r4, [r0]
	subs r2, #0x6b
	adds r0, r3, r2
	strb r4, [r0]
	ldr r0, _08198718 @ =0x00000111
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, _0819871C @ =FUN_08199c38
	str r0, [r1]
_081986FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08198704: .4byte 0x00000187
_08198708: .4byte FUN_081985d8
_0819870C: .4byte 0x030046B8
_08198710: .4byte 0x000003FF
_08198714: .4byte 0x0203B400
_08198718: .4byte 0x00000111
_0819871C: .4byte FUN_08199c38
