	push {lr}
	ldr r0, _0804E5E4 @ =0x03002B58
	ldr r3, [r0]
	cmp r3, #0
	beq _0804E5DE
	adds r0, r3, #0
	adds r0, #0x3f
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x1f
	strb r1, [r3, #0x1c]
	strh r0, [r3, #0x38]
	str r1, [r3, #0x44]
	adds r0, r3, #0
	adds r0, #0x32
	strb r2, [r0]
_0804E5DE:
	pop {r0}
	bx r0
	.align 2, 0
_0804E5E4: .4byte 0x03002B58
