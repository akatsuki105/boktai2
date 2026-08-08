	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08211118
	bl fetch_082316e4
	ldr r1, _0821111C @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08211118:
	pop {r0}
	bx r0
	.align 2, 0
_0821111C: .4byte 0x030046A0
