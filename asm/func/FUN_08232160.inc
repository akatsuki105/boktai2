	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov r4, sp
	movs r5, #0
	mov r1, sp
	bl FUN_0823201c
	adds r7, r0, #0
	mov r0, sp
	movs r1, #0
	bl FUN_082320e4
	adds r6, r0, #0
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r4, #3]
	orrs r2, r0
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	cmp r0, r1
	bne _082321A8
	ldr r0, _082321A4 @ =0x0300469C
	b _082321AA
	.align 2, 0
_082321A4: .4byte 0x0300469C
_082321A8:
	ldr r0, _082321D8 @ =0x03004694
_082321AA:
	ldr r3, [r0]
	ldr r0, _082321DC @ =0x0000FFFF
	ands r0, r2
	adds r3, r3, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _082321C0
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_082321C0:
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08231ef0
	adds r0, r7, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082321D8: .4byte 0x03004694
_082321DC: .4byte 0x0000FFFF
