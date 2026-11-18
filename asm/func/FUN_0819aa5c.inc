	push {lr}
	adds r3, r2, #0
	ldr r0, _0819AA90 @ =0x00000CBB
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0819AA8C
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r3, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0819AA8C:
	pop {r0}
	bx r0
	.align 2, 0
_0819AA90: .4byte 0x00000CBB
