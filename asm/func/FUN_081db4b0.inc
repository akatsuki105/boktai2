	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r1, _081DB4C8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB504
	cmp r0, #1
	bgt _081DB4CC
	cmp r0, #0
	beq _081DB4D2
	b _081DB572
	.align 2, 0
_081DB4C8: .4byte 0x0000032D
_081DB4CC:
	cmp r0, #2
	beq _081DB538
	b _081DB572
_081DB4D2:
	ldr r3, _081DB500 @ =0x00000322
	adds r5, r2, r3
	ldrb r1, [r5]
	movs r0, #0xca
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x16
	adds r1, r2, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r5]
	b _081DB564
	.align 2, 0
_081DB500: .4byte 0x00000322
_081DB504:
	ldr r0, _081DB52C @ =0x00000323
	adds r5, r2, r0
	ldrb r3, [r5]
	ldr r1, _081DB530 @ =0x00000329
	adds r4, r2, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	beq _081DB572
	ldr r1, _081DB534 @ =0x085AE1FC
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	bl FUN_081db3c0
	ldrb r0, [r5]
	strb r0, [r4]
	b _081DB572
	.align 2, 0
_081DB52C: .4byte 0x00000323
_081DB530: .4byte 0x00000329
_081DB534: .4byte 0x085AE1FC
_081DB538:
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r5, r2, r3
	ldrb r1, [r5]
	ldr r0, _081DB578 @ =0x0000032A
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x18
	adds r1, r2, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r5]
	adds r1, #5
_081DB564:
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r5]
	strb r0, [r6]
_081DB572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB578: .4byte 0x0000032A
