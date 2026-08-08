	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FUN_08230e88
	ldr r1, _08230F78 @ =0x03000740
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r6, r0, r1
	adds r4, r6, #0
	adds r4, #8
	ldr r5, [r6]
	movs r3, #0
	cmp r3, r5
	bge _08230F28
	ldrh r0, [r7]
	mov ip, r0
	adds r2, r5, #0
_08230F16:
	ldrh r0, [r4]
	adds r1, r3, #1
	cmp r0, ip
	bne _08230F20
	adds r5, r1, #0
_08230F20:
	adds r3, r1, #0
	adds r4, #8
	cmp r3, r2
	blt _08230F16
_08230F28:
	ldr r3, [r6]
	lsls r4, r5, #3
	cmp r3, r5
	ble _08230F44
	lsls r0, r3, #3
	adds r2, r0, r6
_08230F34:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	subs r2, #8
	subs r3, #1
	cmp r3, r5
	bgt _08230F34
_08230F44:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #8
	adds r4, r6, r0
	ldrh r0, [r7]
	movs r1, #0
	strh r0, [r4]
	strb r1, [r4, #2]
	ldrb r0, [r7, #3]
	strb r0, [r4, #3]
	ldr r5, [r7, #4]
	ldr r1, [r6, #4]
	lsls r0, r1, #1
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r2, r6, r0
	str r2, [r4, #4]
	ldrb r0, [r7, #3]
	adds r1, r1, r0
	str r1, [r6, #4]
	movs r3, #0
	b _08230F86
	.align 2, 0
_08230F78: .4byte 0x03000740
_08230F7C:
	ldrh r0, [r5]
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #1
_08230F86:
	ldrb r0, [r7, #3]
	cmp r3, r0
	blt _08230F7C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
