	push {lr}
	adds r2, r0, #0
	ldr r1, _080810E8 @ =0x0000038E
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _080810EC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _080810E4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080810E4
	bl Time_GetSpanOfTime
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _080810E4
	cmp r1, #0
	bne _080810F0
_080810E4:
	movs r0, #1
	b _080810F2
	.align 2, 0
_080810E8: .4byte 0x0000038E
_080810EC: .4byte 0x030046A0
_080810F0:
	movs r0, #0
_080810F2:
	pop {r1}
	bx r1
	.align 2, 0
