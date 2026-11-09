	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08133478 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813347C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813347E
	.align 2, 0
_08133478: .4byte 0x0000046D
_0813347C:
	movs r0, #0
_0813347E:
	cmp r0, #0
	beq _0813348A
	ldr r1, _081334A0 @ =0x00000AD9
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0813348A:
	ldr r0, _081334A0 @ =0x00000AD9
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081334A4
	ldrb r3, [r6, #5]
	b _081334AE
	.align 2, 0
_081334A0: .4byte 0x00000AD9
_081334A4:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_081334AE:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081334D0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081334D4
	asrs r1, r0, #0xc
	b _081334DA
	.align 2, 0
_081334D0: .4byte gSineTable
_081334D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081334DA:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081334F2
	asrs r2, r0, #0xc
	b _081334F8
_081334F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081334F8:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _08133510 @ =0x00000AD9
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08133696
	.align 2, 0
_08133510: .4byte 0x00000AD9
_08133514:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #2
	ldr r3, _08133530 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08133534
	movs r0, #1
	b _08133536
	.align 2, 0
_08133530: .4byte 0x00000755
_08133534:
	movs r0, #0
_08133536:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08133540
	b _08133694
_08133540:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #5
	ldr r3, _0813355C @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133560
	movs r0, #1
	b _08133562
	.align 2, 0
_0813355C: .4byte 0x00000755
_08133560:
	movs r0, #0
_08133562:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _0813356E
	b _08133694
_0813356E:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #5
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _081335BC @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _081335C0 @ =0x0000076E
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _081335C4
	cmp r3, #1
	beq _08133618
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _0813368C
	.align 2, 0
_081335BC: .4byte 0x0000076C
_081335C0: .4byte 0x0000076E
_081335C4:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081335E4 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081335E4 @ =gSineTable
	cmp r0, #0
	blt _081335E8
	asrs r3, r0, #0xc
	b _081335EE
	.align 2, 0
_081335E4: .4byte gSineTable
_081335E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081335EE:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133614 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _0813366C
	b _08133674
	.align 2, 0
_08133614: .4byte 0x00000674
_08133618:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _0813363C @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08133640
	asrs r3, r0, #0xc
	b _08133646
	.align 2, 0
_0813363C: .4byte gSineTable
_08133640:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08133646:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133670 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08133674
_0813366C:
	asrs r2, r0, #0xc
	b _0813367A
	.align 2, 0
_08133670: .4byte 0x00000674
_08133674:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0813367A:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_0813368C:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08133694:
	mov r7, sl
_08133696:
	ldr r0, _081336D4 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _081336A4
	b _08133514
_081336A4:
	ldr r0, _081336D8 @ =0x00000B46
	add r0, r8
	ldr r2, [sp]
	ldrh r0, [r0]
	cmp r2, r0
	ble _081336E0
	ldr r3, _081336DC @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	movs r2, #0xb3
	lsls r2, r2, #4
	add r2, r8
	subs r0, #5
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081336EA
	.align 2, 0
_081336D4: .4byte 0x00000B3A
_081336D8: .4byte 0x00000B46
_081336DC: .4byte 0x0000046B
_081336E0:
	ldr r2, _081336FC @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_081370f4
_081336EA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081336FC: .4byte 0x0000FFFF
