	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r3, #0
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r0, r0, r4
	mov sl, r0
	ldr r1, _0808D430 @ =0x00000C02
	adds r1, r1, r4
	mov sb, r1
	ldr r7, _0808D434 @ =0x00000DAC
	adds r6, r4, r7
	movs r0, #2
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r1, r1, r4
	mov r8, r1
	ldr r7, _0808D438 @ =0x00000C14
	adds r2, r4, r7
	adds r5, r4, #0
_0808D408:
	mov r0, sl
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D440
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bne _0808D440
	ldr r7, _0808D43C @ =0x00000C09
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808D440
	ldr r0, [r2]
	mov r1, ip
	ands r0, r1
	b _0808D446
	.align 2, 0
_0808D430: .4byte 0x00000C02
_0808D434: .4byte 0x00000DAC
_0808D438: .4byte 0x00000C14
_0808D43C: .4byte 0x00000C09
_0808D440:
	ldr r0, [r2]
	movs r7, #1
	orrs r0, r7
_0808D446:
	str r0, [r2]
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D474
	ldr r1, _0808D470 @ =0x00000D98
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r3, r0
	bne _0808D474
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	mov r7, ip
	ands r0, r7
	b _0808D482
	.align 2, 0
_0808D470: .4byte 0x00000D98
_0808D474:
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	movs r7, #1
	orrs r0, r7
_0808D482:
	str r0, [r1]
	adds r2, #0x64
	adds r5, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D408
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
