	push {r4, lr}
	str r1, [r0, #0x48]
	movs r3, #0
	str r3, [r0, #0x4c]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r0, r2
	ldr r2, _08222A84 @ =0x085B0080
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r4]
	movs r2, #1
	ldr r1, [r0, #0x40]
	orrs r1, r2
	str r3, [r0, #0x50]
	str r3, [r0, #0x54]
	movs r2, #2
	orrs r1, r2
	str r1, [r0, #0x40]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08222A84: .4byte 0x085B0080
