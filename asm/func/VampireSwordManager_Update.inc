	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x20
	movs r6, #0
_0805A236:
	movs r0, #1
	lsls r0, r6
	ldr r1, [r7, #0x18]
	ands r1, r0
	adds r5, r4, #0
	adds r5, #0xe8
	cmp r1, #0
	beq _0805A2AC
	ldr r1, _0805A280 @ =0x085AB9EC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r0, [r4, #0xd]
	adds r0, #0x60
	rsbs r0, r0, #0
	strb r0, [r1, #6]
	ldrb r1, [r4, #4]
	ldrb r0, [r4, #3]
	cmp r0, r1
	beq _0805A2AC
	strb r1, [r4, #3]
	ldrb r0, [r4, #3]
	cmp r0, #1
	beq _0805A298
	cmp r0, #1
	bgt _0805A284
	cmp r0, #0
	beq _0805A28A
	b _0805A2AC
	.align 2, 0
_0805A280: .4byte 0x085AB9EC
_0805A284:
	cmp r0, #2
	beq _0805A2A4
	b _0805A2AC
_0805A28A:
	adds r0, r5, #0
	ldr r1, _0805A294 @ =0x0000012D
	bl Video_SetAuxSpritePltt
	b _0805A2AC
	.align 2, 0
_0805A294: .4byte 0x0000012D
_0805A298:
	adds r0, r5, #0
	movs r1, #0x98
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _0805A2AC
_0805A2A4:
	adds r0, r5, #0
	ldr r1, _0805A2C0 @ =0x00000131
	bl Video_SetAuxSpritePltt
_0805A2AC:
	adds r6, #1
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #7
	ble _0805A236
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805A2C0: .4byte 0x00000131
