	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08060A08
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08060A00 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _08060A04 @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _08060A16
	.align 2, 0
_08060A00: .4byte 0x000002E6
_08060A04: .4byte 0x000002E7
_08060A08:
	ldr r1, _08060A1C @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08060A20 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_08060A16:
	pop {r0}
	bx r0
	.align 2, 0
_08060A1C: .4byte 0x000002E6
_08060A20: .4byte 0x000002E7
