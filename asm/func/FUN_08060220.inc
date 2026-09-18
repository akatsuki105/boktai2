	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	adds r6, r0, #0
	mov r1, sp
	bl FUN_080601f0
	adds r5, r0, #0
	cmp r5, #0
	bne _08060242
	movs r0, #1
	rsbs r0, r0, #0
	b _080602E6
_08060242:
	movs r0, #1
	movs r1, #0
	strb r0, [r5]
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	ldr r0, [sp, #0x1c]
	strh r0, [r5, #0xe]
	strb r4, [r5, #8]
	strh r7, [r5, #4]
	mov r0, r8
	strh r0, [r5, #6]
	ldr r0, [sp, #0x24]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x2c]
	str r1, [r5, #0x30]
	ldr r4, _080602B0 @ =0x0203B400
	ldr r2, _080602B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _080602B8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _08060292
	movs r3, #1
_08060292:
	ldr r0, [sp, #0x20]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, #0x36
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	cmp r3, #0
	beq _080602BC
	ldr r0, [r5, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080602C4
	.align 2, 0
_080602B0: .4byte 0x0203B400
_080602B4: .4byte 0x030046B8
_080602B8: .4byte 0x000003FF
_080602BC:
	ldr r0, [r5, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080602C4:
	str r0, [r5, #0x10]
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_0822a340
	ldr r0, [sp]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x1c]
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r0, #0
_080602E6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
