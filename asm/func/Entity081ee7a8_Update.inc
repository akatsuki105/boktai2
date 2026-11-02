	push {r4, r5, r6, r7, lr}
	ldr r7, _081EE744 @ =0x085AE4D4
	adds r4, r0, #0
	adds r4, #0x74
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0x2f
_081EE71A:
	movs r0, #0x14
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _081EE730
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081EE730:
	adds r4, #0x70
	adds r5, #0x70
	subs r6, #1
	cmp r6, #0
	bge _081EE71A
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EE744: .4byte 0x085AE4D4
