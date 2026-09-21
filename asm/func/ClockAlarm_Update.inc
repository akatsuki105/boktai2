	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3b
	ble _0801B39C
	strh r5, [r4, #0x1e]
	b _0801B4F0
_0801B39C:
	bl GetHour
	strh r0, [r4, #0x18]
	bl GetMinute
	strh r0, [r4, #0x1a]
	bl GetSecond
	strh r0, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	movs r3, #0x1a
	ldrsh r2, [r4, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	ldr r0, _0801B408 @ =0x0000A8DE
	ldr r3, _0801B40C @ =0xFFFF5722
	adds r2, r1, r3
	cmp r1, r0
	bge _0801B3DC
	subs r2, r0, r1
_0801B3DC:
	ldr r0, _0801B410 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B3E6
	ldr r0, _0801B414 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B3E6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B3EE
	rsbs r0, r0, #0
_0801B3EE:
	cmp r0, #0x1e
	bgt _0801B418
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B420
	strb r5, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl ClockAlarm_Fire
	b _0801B420
	.align 2, 0
_0801B408: .4byte 0x0000A8DE
_0801B40C: .4byte 0xFFFF5722
_0801B410: .4byte 0x0000A8BF
_0801B414: .4byte 0xFFFEAE80
_0801B418:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_0801B420:
	ldr r2, _0801B474 @ =0x030047E0
	ldrb r0, [r2, #0xa]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xb]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B444
	subs r2, r1, r0
_0801B444:
	ldr r0, _0801B478 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B44E
	ldr r1, _0801B47C @ =0xFFFEAE80
	adds r2, r2, r1
_0801B44E:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B456
	rsbs r0, r0, #0
_0801B456:
	cmp r0, r3
	bgt _0801B480
	adds r1, r4, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B488
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl ClockAlarm_Fire
	b _0801B488
	.align 2, 0
_0801B474: .4byte 0x030047E0
_0801B478: .4byte 0x0000A8BF
_0801B47C: .4byte 0xFFFEAE80
_0801B480:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
_0801B488:
	ldr r2, _0801B4DC @ =0x030047E0
	ldrb r0, [r2, #0xc]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xd]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B4AC
	subs r2, r1, r0
_0801B4AC:
	ldr r0, _0801B4E0 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B4B6
	ldr r0, _0801B4E4 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B4B6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B4BE
	rsbs r0, r0, #0
_0801B4BE:
	cmp r0, r3
	bgt _0801B4E8
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B4F0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	bl ClockAlarm_Fire
	b _0801B4F0
	.align 2, 0
_0801B4DC: .4byte 0x030047E0
_0801B4E0: .4byte 0x0000A8BF
_0801B4E4: .4byte 0xFFFEAE80
_0801B4E8:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
_0801B4F0:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
