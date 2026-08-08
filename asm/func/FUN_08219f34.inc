	push {r4, lr}
	str r1, [r0, #0x54]
	movs r3, #0
	str r3, [r0, #0x58]
	ldr r2, _08219F60 @ =0x00001FE8
	adds r4, r0, r2
	ldr r2, _08219F64 @ =0x085AFF84
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r4]
	movs r2, #1
	ldr r1, [r0, #0x44]
	orrs r1, r2
	str r3, [r0, #0x5c]
	str r3, [r0, #0x60]
	movs r2, #2
	orrs r1, r2
	str r1, [r0, #0x44]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08219F60: .4byte 0x00001FE8
_08219F64: .4byte 0x085AFF84
