	push {lr}
	adds r2, r0, #0
	movs r1, #4
	ldr r0, _0821D7C0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0821D7BC
	ldr r0, _0821D7C4 @ =0x085B0010
	adds r1, r2, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_0821D7BC:
	pop {r0}
	bx r0
	.align 2, 0
_0821D7C0: .4byte 0x03002BC0
_0821D7C4: .4byte 0x085B0010
