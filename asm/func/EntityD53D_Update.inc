	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x18]
	cmp r5, #0
	bne _0804ECFA
	bl FUN_0804e59c
	cmp r0, #1
	bne _0804ECEE
	strb r0, [r4, #0x18]
	b _0804ECF6
_0804ECEE:
	cmp r0, #2
	bne _0804ECFA
	strb r0, [r4, #0x18]
	movs r0, #1
_0804ECF6:
	strb r0, [r4, #0x19]
	str r5, [r4, #0x1c]
_0804ECFA:
	ldr r0, _0804ED14 @ =0x085AB664
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804ED14: .4byte 0x085AB664
