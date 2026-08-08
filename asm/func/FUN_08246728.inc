	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov ip, r3
	movs r5, #0
	movs r0, #0
	movs r3, #0
	adds r1, r4, #0
	adds r1, #0xc
_0824673E:
	ldrb r2, [r1]
	cmp r2, #1
	bne _0824676E
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	strb r3, [r1]
	movs r0, #0xa
	strb r0, [r1, #1]
	strh r3, [r1, #2]
	movs r5, #1
	ldrb r1, [r4, #1]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	ldr r0, [sp, #0x24]
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r2, r7, #0
	mov r3, ip
	bl FUN_08014730
	b _08246776
_0824676E:
	adds r1, #0x48
	adds r0, #1
	cmp r0, #3
	ble _0824673E
_08246776:
	cmp r5, #0
	beq _08246786
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #2]
	subs r0, #1
	strb r0, [r4, #2]
_08246786:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
