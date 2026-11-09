	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _08193A28 @ =0x00000E43
	adds r2, r0, r3
	adds r3, #1
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08193A22
	movs r0, #0
	strb r0, [r2]
_08193A22:
	pop {r0}
	bx r0
	.align 2, 0
_08193A28: .4byte 0x00000E43
