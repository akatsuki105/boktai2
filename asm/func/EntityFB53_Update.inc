	push {r4, lr}
	adds r4, r0, #0
	bl SuspendSunlight
	ldr r0, _0804B920 @ =0x03002B54
	ldr r0, [r0]
	cmp r0, #0
	beq _0804B8E8
	ldrb r1, [r4, #0x1a]
	movs r0, #0x70
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B8E8:
	ldrb r0, [r4, #0x18]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0804B906
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804B906
	movs r0, #9
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
_0804B906:
	ldr r0, _0804B924 @ =0x085AB5B8
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B920: .4byte 0x03002B54
_0804B924: .4byte 0x085AB5B8
