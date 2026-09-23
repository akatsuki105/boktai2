	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r0, [r5]
	adds r0, #0xf
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x88
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble _08020BFC
	strh r2, [r5]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	movs r0, #0xaa
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	subs r1, #0x4b
	movs r0, #0
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020C14 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08020C18 @ =FUN_08020cd8
	str r0, [r4, #0x30]
_08020BFC:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	ldrh r5, [r5]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0x72
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020C14: .4byte 0x0000FFFC
_08020C18: .4byte FUN_08020cd8
