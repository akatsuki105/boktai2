	push {r4, lr}
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, _08140A3C @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r1, r2
	movs r4, #0
	strh r1, [r3]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r2, _08140A40 @ =0xFBFFFFFF
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
	ldr r1, _08140A44 @ =0x0000024E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08140A3C: .4byte 0xFFFFFEFF
_08140A40: .4byte 0xFBFFFFFF
_08140A44: .4byte 0x0000024E
