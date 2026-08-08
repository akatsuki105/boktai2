	push {r4, r5, r6, lr}
	bl GetDate
	ldr r4, _08241FC8 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
	bl GetHour
	ldr r1, [r4]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r1, r5
	str r0, [r1]
	bl GetMinute
	adds r6, r0, #0
	ldr r2, [r4]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r1, r2, r3
	str r6, [r1]
	ldr r1, _08241FCC @ =gClock
	ldrb r3, [r1, #0xc]
	ldrb r1, [r1, #0xd]
	movs r4, #0
	adds r2, r2, r5
	ldr r2, [r2]
	cmp r2, r3
	blt _08241FB4
	cmp r2, r3
	bne _08241FB6
	cmp r6, r1
	bge _08241FB6
_08241FB4:
	movs r4, #1
_08241FB6:
	ldr r1, _08241FC8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r1, r1, r2
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08241FC8: .4byte 0x030046A0
_08241FCC: .4byte gClock
