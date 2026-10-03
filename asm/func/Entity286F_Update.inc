	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08043F2C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	cmp r2, #0
	beq _08043F34
	ldr r0, _08043F30 @ =0x00000434
	adds r1, r5, r0
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08043F3A
	.align 2, 0
_08043F2C: .4byte 0x03002BE0
_08043F30: .4byte 0x00000434
_08043F34:
	ldr r1, _08043F70 @ =0x00000434
	adds r0, r5, r1
	str r2, [r0]
_08043F3A:
	bl FUN_08018a08
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	bl Time_GetHour
	adds r1, r5, #0
	adds r1, #0x22
	strb r0, [r1]
	bl Time_GetMinute
	adds r2, r5, #0
	adds r2, #0x23
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x21
	ldrb r3, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r3, r0
	beq _08043F74
	subs r1, #1
	movs r0, #1
	b _08043F7A
	.align 2, 0
_08043F70: .4byte 0x00000434
_08043F74:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
_08043F7A:
	strb r0, [r1]
	ldrb r0, [r2]
	movs r2, #0
	strb r0, [r4]
	ldr r0, [r5, #0x28]
	movs r1, #1
	subs r1, r1, r0
	str r1, [r5, #0x28]
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	beq _08043FAE
_08043F9A:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r4, [r0]
	adds r0, r5, #0
	bl FUN_080411a0
	adds r1, r4, #0
	cmp r1, #0
	bne _08043F9A
_08043FAE:
	adds r0, r5, #0
	bl FUN_08041918
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08043FC6
	adds r0, #0x24
	bl FUN_080417dc
_08043FC6:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
