	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0823BCC0 @ =gCamera
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _0823BCDC
	cmp r3, #1
	bgt _0823BCC4
	movs r0, #0
	strh r0, [r2, #0x1c]
	b _0823BCD6
	.align 2, 0
_0823BCC0: .4byte gCamera
_0823BCC4:
	movs r0, #1
	strh r0, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #6
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x6a
	strh r3, [r0]
_0823BCD6:
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x1e]
_0823BCDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
