	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _0823807C @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _0823808E
	bl FUN_082379ec
	ldr r0, _08238080 @ =0x03000794
	ldr r5, [r0]
	ldr r0, _08238084 @ =0x0300079C
	ldr r4, [r0]
	bl FUN_082379f8
	adds r4, #1
	adds r4, r4, r7
	cmp r4, #0x3f
	bgt _0823808C
	ldr r1, _08238088 @ =0x030007E0
	adds r0, r5, r1
	strb r7, [r0]
	adds r5, #1
	movs r0, #0x3f
	ands r5, r0
	cmp r7, #0
	ble _08238062
	adds r4, r1, #0
	movs r3, #0x3f
	adds r2, r7, #0
_08238050:
	adds r1, r5, r4
	ldrb r0, [r6]
	strb r0, [r1]
	adds r6, #1
	adds r5, #1
	ands r5, r3
	subs r2, #1
	cmp r2, #0
	bne _08238050
_08238062:
	bl FUN_082379ec
	ldr r0, _08238080 @ =0x03000794
	str r5, [r0]
	ldr r1, _08238084 @ =0x0300079C
	ldr r0, [r1]
	adds r0, #1
	adds r0, r0, r7
	str r0, [r1]
	bl FUN_082379f8
	adds r0, r7, #0
	b _0823808E
	.align 2, 0
_0823807C: .4byte 0x030046D4
_08238080: .4byte 0x03000794
_08238084: .4byte 0x0300079C
_08238088: .4byte 0x030007E0
_0823808C:
	movs r0, #0
_0823808E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
