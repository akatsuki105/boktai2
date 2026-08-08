	push {lr}
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _082407B0 @ =0x030047A4
	ldr r1, _082407B4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _082407AA
	adds r0, r3, #0
	bl PlaySound_082406e0
_082407AA:
	pop {r0}
	bx r0
	.align 2, 0
_082407B0: .4byte 0x030047A4
_082407B4: .4byte 0x030047A0
