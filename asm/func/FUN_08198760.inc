	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _081987FC @ =0x00000181
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	movs r2, #0
	mov sl, r2
	mov r4, r8
	strb r0, [r4]
	ldr r0, _08198800 @ =gSineTable
	mov sb, r0
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0xc8
	muls r0, r4, r0
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	bl Div
	ldr r2, _08198804 @ =0x00000AFC
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r1, r5, #0
	bl Div
	movs r4, #0xb0
	lsls r4, r4, #4
	adds r1, r6, r4
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819884A
	ldr r1, _08198808 @ =0x00000C58
	adds r0, r6, r1
	ldr r3, [r0]
	ldr r0, _0819880C @ =FUN_08199c98
	cmp r3, r0
	bne _08198810
	movs r0, #1
	movs r1, #2
	b _0819882A
	.align 2, 0
_081987FC: .4byte 0x00000181
_08198800: .4byte gSineTable
_08198804: .4byte 0x00000AFC
_08198808: .4byte 0x00000C58
_0819880C: .4byte FUN_08199c98
_08198810:
	ldr r0, _0819881C @ =FUN_08199cf0
	cmp r3, r0
	bne _08198820
	movs r0, #1
	movs r1, #3
	b _0819882A
	.align 2, 0
_0819881C: .4byte FUN_08199cf0
_08198820:
	ldr r0, _08198858 @ =FUN_08199d48
	cmp r3, r0
	bne _0819884A
	movs r0, #1
	movs r1, #4
_0819882A:
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r2, r7, r4
	strb r0, [r2]
	adds r4, #1
	adds r2, r7, r4
	strb r1, [r2]
	ldr r1, _0819885C @ =0x00000111
	adds r2, r7, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	str r3, [r0]
_0819884A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08198858: .4byte FUN_08199d48
_0819885C: .4byte 0x00000111
