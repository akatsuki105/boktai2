	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x16
	movs r1, #4
	movs r2, #6
	movs r3, #2
	bl TextPanel_Create
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	movs r0, #0x14
	movs r1, #0xc
	movs r2, #8
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	bl Marquee_Clear
	bl FUN_08049f84
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081daf44
	ldr r0, [r5]
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5]
	ldr r2, _081DB120 @ =0x00000322
	adds r4, r7, r2
	ldrb r1, [r4]
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
	ldrb r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, [r6]
	mov r2, r8
	ldr r1, [r2]
	bl TextPanel_SetScript
	ldr r0, [r6]
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r4, r7, r1
	ldrb r1, [r4]
	adds r1, #5
	bl TextPanel_SetMessage
	ldr r0, [r6]
	bl TextPanel_Start
	ldrb r1, [r4]
	ldr r2, _081DB124 @ =0x0000032A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB120: .4byte 0x00000322
_081DB124: .4byte 0x0000032A
