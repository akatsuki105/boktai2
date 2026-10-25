	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r1, #0
	mov sl, r1
	movs r2, #0
	mov sb, r2
	mov r0, sb
	strh r0, [r4]
	ldr r1, _081FC3E4 @ =0x085AE60C
	adds r6, r5, #0
	adds r6, #0xa6
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _081FC3CE
	b _081FC5A8
_081FC3CE:
	ldr r1, _081FC3E8 @ =0x000007DA
	adds r1, r1, r5
	mov r8, r1
	ldrh r7, [r1]
	cmp r7, #1
	beq _081FC474
	cmp r7, #1
	bgt _081FC3EC
	cmp r7, #0
	beq _081FC3F4
	b _081FC5A8
	.align 2, 0
_081FC3E4: .4byte 0x085AE60C
_081FC3E8: .4byte 0x000007DA
_081FC3EC:
	cmp r7, #2
	bne _081FC3F2
	b _081FC51C
_081FC3F2:
	b _081FC5A8
_081FC3F4:
	adds r0, r5, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, #2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl Div
	lsls r1, r0, #3
	subs r1, r1, r0
	cmp r4, r1
	bge _081FC43A
	ldrb r0, [r6]
	cmp r0, #7
	beq _081FC422
	movs r0, #7
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC422:
	movs r1, #1
	movs r0, #1
	mov r2, r8
	strh r0, [r2]
	mov r0, sl
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _081FC5A8
_081FC43A:
	ldrb r0, [r6]
	cmp r0, #2
	beq _081FC45C
	cmp r0, #2
	bgt _081FC44A
	cmp r0, #0
	beq _081FC450
	b _081FC5A8
_081FC44A:
	cmp r0, #5
	beq _081FC468
	b _081FC5A8
_081FC450:
	movs r0, #2
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC45C:
	movs r0, #5
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC468:
	mov r1, sl
	strb r1, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC474:
	adds r0, r5, #0
	adds r0, #0x90
	adds r1, r5, #0
	adds r1, #0x92
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r1, r1, #0x12
	cmp r0, r1
	bge _081FC4AC
	ldrb r0, [r6]
	cmp r0, #7
	beq _081FC494
	movs r0, #7
	b _081FC49C
_081FC494:
	movs r0, #2
	mov r2, r8
	strh r0, [r2]
	movs r0, #3
_081FC49C:
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	mov r1, sb
	str r1, [r0]
	subs r0, #0x14
	strb r7, [r0]
	b _081FC5A8
_081FC4AC:
	ldrb r0, [r6]
	cmp r0, #5
	bls _081FC4B4
	b _081FC5A8
_081FC4B4:
	lsls r0, r0, #2
	ldr r1, _081FC4C0 @ =_081FC4C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FC4C0: .4byte _081FC4C4
_081FC4C4: @ jump table
	.4byte _081FC4DC @ case 0
	.4byte _081FC504 @ case 1
	.4byte _081FC50C @ case 2
	.4byte _081FC5A8 @ case 3
	.4byte _081FC508 @ case 4
	.4byte _081FC510 @ case 5
_081FC4DC:
	ldr r2, _081FC4F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC4FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FC500 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _081FC560
	movs r0, #4
	b _081FC592
	.align 2, 0
_081FC4F8: .4byte 0x030046B8
_081FC4FC: .4byte 0x000003FF
_081FC500: .4byte 0x0203B400
_081FC504:
	movs r0, #2
	b _081FC592
_081FC508:
	movs r0, #2
	b _081FC592
_081FC50C:
	movs r0, #5
	b _081FC592
_081FC510:
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	b _081FC59E
_081FC51C:
	ldrb r0, [r6]
	subs r0, #1
	cmp r0, #4
	bhi _081FC5A8
	lsls r0, r0, #2
	ldr r1, _081FC530 @ =_081FC534
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FC530: .4byte _081FC534
_081FC534: @ jump table
	.4byte _081FC584 @ case 0
	.4byte _081FC58C @ case 1
	.4byte _081FC548 @ case 2
	.4byte _081FC588 @ case 3
	.4byte _081FC590 @ case 4
_081FC548:
	ldr r2, _081FC574 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC578 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FC57C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FC580
_081FC560:
	movs r2, #1
	adds r0, r5, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _081FC5A8
	.align 2, 0
_081FC574: .4byte 0x030046B8
_081FC578: .4byte 0x000003FF
_081FC57C: .4byte 0x0203B400
_081FC580:
	movs r0, #4
	b _081FC592
_081FC584:
	movs r0, #2
	b _081FC592
_081FC588:
	movs r0, #2
	b _081FC592
_081FC58C:
	movs r0, #5
	b _081FC592
_081FC590:
	movs r0, #3
_081FC592:
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
_081FC59E:
	str r1, [r0]
_081FC5A0:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_081FC5A8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
