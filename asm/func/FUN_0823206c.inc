	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4]
	lsls r2, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r4, #3]
	orrs r2, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r2
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _082320A0
	ldr r0, _0823209C @ =0x030046A0
	b _082320B2
	.align 2, 0
_0823209C: .4byte 0x030046A0
_082320A0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _082320B0
	ldr r0, _082320AC @ =0x03004690
	b _082320B2
	.align 2, 0
_082320AC: .4byte 0x03004690
_082320B0:
	ldr r0, _082320DC @ =0x03004698
_082320B2:
	ldr r3, [r0]
	ldr r0, _082320E0 @ =0x0000FFFF
	ands r0, r2
	adds r3, r3, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _082320C8
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_082320C8:
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08231ef0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082320DC: .4byte 0x03004698
_082320E0: .4byte 0x0000FFFF
