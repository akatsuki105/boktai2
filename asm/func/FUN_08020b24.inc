	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #6]
	movs r2, #3
	orrs r0, r2
	strh r0, [r1, #6]
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020B80 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08020B84 @ =FUN_08020c1c
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B80: .4byte 0x0000FFFE
_08020B84: .4byte FUN_08020c1c
