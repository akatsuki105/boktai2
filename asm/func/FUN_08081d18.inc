	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r2, r0, #0
	adds r0, #0x90
	ldr r5, [r0]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08081D94
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r6, r2, r0
	adds r0, r1, #2
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _08081D94
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _08081D9C @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08081DA0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	str r5, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	subs r0, #0x64
	strh r0, [r6]
_08081D94:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081D9C: .4byte 0x0000FFFF
_08081DA0: .4byte 0xFFFF0000
