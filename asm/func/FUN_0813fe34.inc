	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0813FE54 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FE58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FE5A
	.align 2, 0
_0813FE54: .4byte 0x0000046C
_0813FE58:
	movs r0, #0
_0813FE5A:
	cmp r0, #0
	beq _0813FF26
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0813FECC @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	movs r6, #0xd6
	lsls r6, r6, #3
	adds r1, r4, r6
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813FED0 @ =0x05000002
	bl CpuSet
	ldr r2, _0813FED4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813FED8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813FEDC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r2, _0813FEE0 @ =gSineTable
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0813FEE4
	asrs r1, r0, #7
	b _0813FEEA
	.align 2, 0
_0813FECC: .4byte 0x0000046D
_0813FED0: .4byte 0x05000002
_0813FED4: .4byte 0x030046B8
_0813FED8: .4byte 0x000003FF
_0813FEDC: .4byte 0x0203B400
_0813FEE0: .4byte gSineTable
_0813FEE4:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FEEA:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	ldr r2, _0813FF14 @ =gSineTable
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0813FF18
	asrs r1, r0, #7
	b _0813FF1E
	.align 2, 0
_0813FF14: .4byte gSineTable
_0813FF18:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF1E:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_0813FF26:
	ldr r6, _0813FF4C @ =0x00000484
	adds r0, r5, r6
	ldr r0, [r0]
	cmp r0, #5
	bgt _0813FF8E
	ldr r1, _0813FF50 @ =gSineTable
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, r1, #0
	cmp r0, #0
	blt _0813FF54
	asrs r1, r0, #7
	b _0813FF5A
	.align 2, 0
_0813FF4C: .4byte 0x00000484
_0813FF50: .4byte gSineTable
_0813FF54:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF5A:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0813FF80
	asrs r1, r0, #7
	b _0813FF86
_0813FF80:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF86:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_0813FF8E:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r6, r1, r0
	cmp r6, #0
	bne _0813FFEE
	adds r0, r5, #0
	bl FUN_08140904
	str r6, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08140000 @ =0x05000002
	bl CpuSet
	ldr r0, _08140004 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_08140970
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08140008 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0814000C @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0813FFEE:
	ldr r6, _08140010 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140000: .4byte 0x05000002
_08140004: .4byte 0x03002BE0
_08140008: .4byte 0x00000469
_0814000C: .4byte 0x0000046A
_08140010: .4byte 0x00000484
