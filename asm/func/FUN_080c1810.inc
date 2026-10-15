	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _080C182A
	adds r0, r4, #0
	bl KillEntity
	b _080C18D4
_080C182A:
	adds r0, r4, #0
	bl FUN_080c13f8
	ldr r0, [r4, #0x18]
	ldr r1, _080C1860 @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080C1868
	adds r0, r4, #0
	bl FUN_080c17e8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	strh r0, [r4, #0x2c]
	ldr r1, _080C1864 @ =FUN_080c18dc
	adds r0, r4, #0
	bl Entity080c1abc_SetUpdateCallback
	b _080C18D4
	.align 2, 0
_080C1860: .4byte 0x0000037D
_080C1864: .4byte FUN_080c18dc
_080C1868:
	adds r0, r4, #0
	bl FUN_080c1574
	ldr r0, [r4, #0x18]
	ldr r1, _080C189C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C18A0
	adds r1, r4, #0
	adds r1, #0x70
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r1, #0
	cmp r5, #3
	bne _080C188E
	adds r0, r4, #0
	bl FUN_080c1664
_080C188E:
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
	b _080C18B8
	.align 2, 0
_080C189C: .4byte 0x0000037D
_080C18A0:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #1
	strb r0, [r1]
	adds r2, r1, #0
	adds r6, r4, #0
	adds r6, #0x70
_080C18B8:
	ldrh r0, [r6]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C18CA
	ldrb r0, [r2]
	adds r0, #1
	b _080C18CC
_080C18CA:
	ldrb r0, [r2]
_080C18CC:
	strh r0, [r4, #0x2c]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_080C18D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
