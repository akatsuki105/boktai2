	push {lr}
	ldr r0, _0820D114 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r1, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0820D11C
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r1, [r1]
	ldr r0, _0820D118 @ =0x01FFFFFF
	cmp r1, r0
	bne _0820D11C
	movs r0, #1
	b _0820D11E
	.align 2, 0
_0820D114: .4byte 0x030046A0
_0820D118: .4byte 0x01FFFFFF
_0820D11C:
	movs r0, #0
_0820D11E:
	pop {r1}
	bx r1
	.align 2, 0
