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
	ldr r2, _0813384C @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133850
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133852
	.align 2, 0
_0813384C: .4byte 0x0000046D
_08133850:
	movs r0, #0
_08133852:
	cmp r0, #0
	beq _0813385E
	ldr r1, _08133874 @ =0x00000AD9
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_0813385E:
	ldr r0, _08133874 @ =0x00000AD9
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08133878
	ldrb r3, [r6, #5]
	b _08133882
	.align 2, 0
_08133874: .4byte 0x00000AD9
_08133878:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_08133882:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081338A4 @ =gSineTable
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
	blt _081338A8
	asrs r1, r0, #0xc
	b _081338AE
	.align 2, 0
_081338A4: .4byte gSineTable
_081338A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081338AE:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081338C6
	asrs r2, r0, #0xc
	b _081338CC
_081338C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081338CC:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _081338E4 @ =0x00000AD9
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08133A6A
	.align 2, 0
_081338E4: .4byte 0x00000AD9
_081338E8:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #2
	ldr r3, _08133904 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08133908
	movs r0, #1
	b _0813390A
	.align 2, 0
_08133904: .4byte 0x00000755
_08133908:
	movs r0, #0
_0813390A:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08133914
	b _08133A68
_08133914:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #5
	add r0, r8
	movs r1, #5
	ldr r3, _08133930 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08133934
	movs r0, #1
	b _08133936
	.align 2, 0
_08133930: .4byte 0x00000755
_08133934:
	movs r0, #0
_08133936:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _08133942
	b _08133A68
_08133942:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #5
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _08133990 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _08133994 @ =0x0000076E
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
	beq _08133998
	cmp r3, #1
	beq _081339EC
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08133A60
	.align 2, 0
_08133990: .4byte 0x0000076C
_08133994: .4byte 0x0000076E
_08133998:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081339B8 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081339B8 @ =gSineTable
	cmp r0, #0
	blt _081339BC
	asrs r3, r0, #0xc
	b _081339C2
	.align 2, 0
_081339B8: .4byte gSineTable
_081339BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081339C2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _081339E8 @ =0x00000674
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
	bge _08133A40
	b _08133A48
	.align 2, 0
_081339E8: .4byte 0x00000674
_081339EC:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08133A10 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08133A14
	asrs r3, r0, #0xc
	b _08133A1A
	.align 2, 0
_08133A10: .4byte gSineTable
_08133A14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08133A1A:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08133A44 @ =0x00000674
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
	blt _08133A48
_08133A40:
	asrs r2, r0, #0xc
	b _08133A4E
	.align 2, 0
_08133A44: .4byte 0x00000674
_08133A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08133A4E:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #5
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_08133A60:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08133A68:
	mov r7, sl
_08133A6A:
	ldr r0, _08133AC4 @ =0x00000B3A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _08133A78
	b _081338E8
_08133A78:
	ldr r2, _08133AC8 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_081370f4
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _08133AB2
	ldr r4, _08133ACC @ =FUN_08133ad8
	movs r3, #0x23
	ldr r0, _08133AD0 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08133AD4 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_08133AB2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08133AC4: .4byte 0x00000B3A
_08133AC8: .4byte 0x0000FFFF
_08133ACC: .4byte FUN_08133ad8
_08133AD0: .4byte 0x0000046D
_08133AD4: .4byte 0x0000046B
