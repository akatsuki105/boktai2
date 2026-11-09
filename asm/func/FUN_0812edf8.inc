	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0812EE10 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EE14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812EE16
	.align 2, 0
_0812EE10: .4byte 0x0000046D
_0812EE14:
	movs r0, #0
_0812EE16:
	cmp r0, #0
	beq _0812EE52
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r7, r1
	bl AuxShadow_Show
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r3, _0812EF24 @ =0x00000474
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0x94
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0812EE52:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812EF1E
	ldr r3, _0812EF28 @ =0x0000044C
	adds r4, r7, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _0812EE7A
	movs r5, #0xaa
	lsls r5, r5, #2
	adds r0, r7, r5
	bl AuxShadow_Remove
	movs r0, #1
	strb r0, [r4]
_0812EE7A:
	ldr r0, _0812EF24 @ =0x00000474
	adds r2, r7, r0
	ldr r1, _0812EF2C @ =0xFFFFF7FF
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	movs r6, #0
	strh r1, [r2]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r3, r7, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r2, _0812EF30 @ =0x000005A4
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #5
	mov ip, r5
	movs r1, #0x14
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0812EF34 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0812EF38 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812EF3C @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	ldr r3, _0812EF40 @ =FUN_080e68d8
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0812EF44 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812EF48 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0812EF4C @ =0x0000046A
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r2, [r0]
_0812EF1E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EF24: .4byte 0x00000474
_0812EF28: .4byte 0x0000044C
_0812EF2C: .4byte 0xFFFFF7FF
_0812EF30: .4byte 0x000005A4
_0812EF34: .4byte 0x00000554
_0812EF38: .4byte 0x00000551
_0812EF3C: .4byte 0x00000552
_0812EF40: .4byte FUN_080e68d8
_0812EF44: .4byte 0x0000046B
_0812EF48: .4byte 0x00000469
_0812EF4C: .4byte 0x0000046A
