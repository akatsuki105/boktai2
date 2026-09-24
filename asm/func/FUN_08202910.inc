	push {lr}
	adds r2, r0, #0
	ldr r0, _08202938 @ =0x000006D9
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r2, #0x18]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r2, #0x18]
	ldr r3, _0820293C @ =0x000006D4
	adds r0, r2, r3
	ldr r3, [r0]
	cmp r3, #0
	beq _08202934
	adds r0, r2, #0
	bl _call_via_r3
_08202934:
	pop {r0}
	bx r0
	.align 2, 0
_08202938: .4byte 0x000006D9
_0820293C: .4byte 0x000006D4
