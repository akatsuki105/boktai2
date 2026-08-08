	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	add r1, sp, #8
	bl FUN_08245c4c
	adds r5, r0, #0
	cmp r5, #0
	bne _08246522
	movs r0, #1
	rsbs r0, r0, #0
	b _0824660C
_08246522:
	movs r1, #0
	strb r1, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r2, #0
	strh r1, [r5, #6]
	strb r4, [r5, #9]
	lsls r0, r4, #8
	strh r0, [r5, #0xa]
	strh r0, [r5, #0xc]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x10]
	ldr r0, [sp, #0x30]
	strb r0, [r5, #2]
	movs r0, #0x40
	strh r0, [r5, #0xe]
	strb r2, [r5, #8]
	str r6, [r5, #0x6c]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r6, #0
	movs r1, #0x84
	adds r1, r1, r5
	mov r8, r1
	movs r2, #0x14
	adds r2, r2, r5
	mov sl, r2
	adds r7, r5, #0
	adds r7, #0xd4
_08246566:
	lsls r2, r6, #3
	adds r2, r2, r5
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	adds r6, #1
	adds r4, #0x2c
	cmp r6, #8
	ble _08246566
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r5, #2]
	ldr r2, _0824661C @ =0x0000015F
	adds r1, r1, r2
	bl FUN_0822b20c
	mov r0, r8
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r7, #6]
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #0xa]
	strh r0, [r7, #0xa]
	ldr r4, _08246620 @ =0x08DBD7D0
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	mov r2, sb
	ldrh r1, [r2, #0x1c]
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	mov r0, r8
	movs r2, #0x1e
	movs r3, #0x10
	bl FUN_082364f8
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r1, r0, r4
	ldr r2, [r1]
	adds r4, #4
	adds r0, r0, r4
	ldr r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08236514
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
	movs r0, #0
_0824660C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824661C: .4byte 0x0000015F
_08246620: .4byte 0x08DBD7D0
