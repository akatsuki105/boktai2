	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x32
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804C44C
	movs r0, #0
	strb r0, [r7]
_0804C44C:
	adds r4, r5, #0
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r6, r0, #0
	cmp r6, #0
	beq _0804C45E
	subs r0, #1
	strb r0, [r4]
	b _0804C568
_0804C45E:
	bl PollRfuSoftReset
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C48A
	cmp r1, #0
	bgt _0804C476
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804C47C
	b _0804C568
_0804C476:
	cmp r1, #1
	beq _0804C490
	b _0804C568
_0804C47C:
	movs r0, #0x1b
	strb r6, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r6, [r5, #0x44]
	movs r0, #1
	strb r0, [r7]
	b _0804C568
_0804C48A:
	movs r0, #0x3c
	strb r0, [r4]
	b _0804C568
_0804C490:
	movs r4, #3
	strb r6, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r6, [r5, #0x44]
	strb r1, [r7]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r6, r0, #0
	ldr r2, _0804C4DC @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0804C4E0 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r7, _0804C4E4 @ =0x0203B400
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0804C4F2
	bl Time_GetSpanOfTime
	adds r4, r0, #0
	bl Time_GetHour
	adds r1, r0, #0
	subs r4, #1
	cmp r4, #2
	bhi _0804C4E8
	movs r0, #1
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #0
	b _0804C504
	.align 2, 0
_0804C4DC: .4byte 0x030046B8
_0804C4E0: .4byte 0x000003FF
_0804C4E4: .4byte 0x0203B400
_0804C4E8:
	movs r0, #3
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #2
	b _0804C504
_0804C4F2:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0804C574 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r4
	adds r0, #4
_0804C504:
	adds r0, r6, r0
	bl Textbox_LookupString
	adds r4, r0, #0
	ldr r0, _0804C578 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xf0
	lsls r7, r7, #2
	adds r0, r0, r7
	adds r7, r5, #0
	adds r7, #0x60
	adds r1, r7, #0
	movs r2, #8
	bl FUN_0804e6d8
	adds r6, r5, #0
	adds r6, #0x50
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xb
	bl FUN_0804e6d8
	adds r1, r5, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r2, r5, #0
	adds r2, #0x5b
	strb r0, [r2]
	ldrh r0, [r1]
	lsrs r0, r0, #8
	subs r1, #0x10
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r3, #0
	cmp r1, #0
	beq _0804C558
	movs r3, #3
_0804C558:
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	adds r0, r2, #0
	movs r2, #0x11
	bl FUN_0823a730
_0804C568:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C574: .4byte 0x0203B400
_0804C578: .4byte 0x030046A0
