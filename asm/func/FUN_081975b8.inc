	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081975DE
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _081975E0
_081975DE:
	movs r0, #0
_081975E0:
	cmp r0, #0
	beq _081975F6
	ldr r0, _08197638 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0x96
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _0819763C @ =FUN_08195c94
	str r0, [r1]
_081975F6:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r0, _08197638 @ =0x00000C64
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08197630
	movs r0, #1
	movs r1, #4
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08197640 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08197644 @ =FUN_08197ad4
	str r0, [r1]
	ldr r0, _08197648 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _0819764C @ =FUN_08196580
	str r0, [r1]
_08197630:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197638: .4byte 0x00000C64
_0819763C: .4byte FUN_08195c94
_08197640: .4byte 0x00000C38
_08197644: .4byte FUN_08197ad4
_08197648: .4byte 0x00000C48
_0819764C: .4byte FUN_08196580
