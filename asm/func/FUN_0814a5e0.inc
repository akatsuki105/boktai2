	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldrb r0, [r3, #5]
	subs r1, r7, r0
	cmp r1, #0x80
	ble _0814A5F8
	ldr r0, _0814A5F4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814A606
	.align 2, 0
_0814A5F4: .4byte 0xFFFFFF00
_0814A5F8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814A606
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814A606:
	cmp r1, #0
	bge _0814A60C
	rsbs r1, r1, #0
_0814A60C:
	ldr r4, _0814A624 @ =0x000001FD
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _0814A620
	ldr r5, _0814A628 @ =0x00000553
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #2
	bne _0814A62C
_0814A620:
	movs r0, #0
	b _0814A6DA
	.align 2, 0
_0814A624: .4byte 0x000001FD
_0814A628: .4byte 0x00000553
_0814A62C:
	ldr r2, _0814A68C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _0814A690 @ =0x0000046D
	adds r0, r3, r4
	movs r5, #0
	movs r6, #1
	strb r6, [r0]
	subs r4, #2
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r3, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r4, #0
	strh r5, [r0]
	movs r1, #0x80
	subs r2, #0x48
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0814A69C
	movs r1, #0xd
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r3, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r4, [r0]
	ldr r4, _0814A694 @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _0814A698 @ =0x00000484
	adds r0, r3, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r3, r2
	b _0814A6BC
	.align 2, 0
_0814A68C: .4byte Enemy_ClearStateBegun
_0814A690: .4byte 0x0000046D
_0814A694: .4byte 0x0000046A
_0814A698: .4byte 0x00000484
_0814A69C:
	movs r1, #6
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r4, [r0]
	ldr r4, _0814A6E0 @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r3, r5
	str r2, [r0]
	ldr r1, _0814A6E4 @ =0x0000046C
	adds r0, r3, r1
_0814A6BC:
	strb r6, [r0]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	movs r0, #1
_0814A6DA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814A6E0: .4byte 0x0000046A
_0814A6E4: .4byte 0x0000046C
