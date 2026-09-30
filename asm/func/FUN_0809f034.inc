	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x96
	lsls r0, r0, #2
	adds r6, r4, r0
	ldr r2, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _0809F090
	movs r1, #0x40
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F0A2
	ldr r0, _0809F08C @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r5, r0, r7
	ldr r3, [r5]
	cmp r3, #0
	ble _0809F0A2
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	subs r7, #0x52
	adds r1, r2, r7
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0809F0A2
	subs r0, r3, #1
	str r0, [r5]
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0809F0A2
	.align 2, 0
_0809F08C: .4byte 0x030046A0
_0809F090:
	adds r0, r4, #0
	adds r0, #0x44
	ldr r1, _0809F0B4 @ =0x0000013D
	bl Video_SetAuxSpritePltt
	ldr r7, _0809F0B8 @ =0x0000025E
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
_0809F0A2:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F0B4: .4byte 0x0000013D
_0809F0B8: .4byte 0x0000025E
