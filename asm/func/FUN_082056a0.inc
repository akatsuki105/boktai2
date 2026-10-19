	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _082056C4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _082058BA
	.align 2, 0
_082056C4: .4byte 0x03002B4C
_082056C8:
	ldr r0, _082056FC @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _082056F0
	b _082058AC
_082056F0:
	lsls r0, r0, #2
	ldr r1, _08205700 @ =_08205704
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082056FC: .4byte 0x03002B4C
_08205700: .4byte _08205704
_08205704: @ jump table
	.4byte _082057AC @ case 0
	.4byte _082058AC @ case 1
	.4byte _082057FC @ case 2
	.4byte _082057B6 @ case 3
	.4byte _08205812 @ case 4
	.4byte _08205816 @ case 5
	.4byte _0820581A @ case 6
	.4byte _08205866 @ case 7
	.4byte _0820586A @ case 8
	.4byte _08205882 @ case 9
	.4byte _0820586E @ case 10
	.4byte _082058AC @ case 11
	.4byte _082058AC @ case 12
	.4byte _082058AC @ case 13
	.4byte _082058AC @ case 14
	.4byte _082058AC @ case 15
	.4byte _082058AC @ case 16
	.4byte _082058AC @ case 17
	.4byte _082058AC @ case 18
	.4byte _082058AC @ case 19
	.4byte _082058AC @ case 20
	.4byte _082058AC @ case 21
	.4byte _082058AC @ case 22
	.4byte _082058AC @ case 23
	.4byte _082058AC @ case 24
	.4byte _082058AC @ case 25
	.4byte _082058AC @ case 26
	.4byte _082058AC @ case 27
	.4byte _082058AC @ case 28
	.4byte _082058AC @ case 29
	.4byte _082058AC @ case 30
	.4byte _082058AC @ case 31
	.4byte _082058AC @ case 32
	.4byte _082058AC @ case 33
	.4byte _082058AC @ case 34
	.4byte _082058AC @ case 35
	.4byte _082058AC @ case 36
	.4byte _082058AC @ case 37
	.4byte _082058AC @ case 38
	.4byte _082058AC @ case 39
	.4byte _082058AC @ case 40
	.4byte _08205894 @ case 41
_082057AC:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820588C
_082057B6:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820588E
_082057FC:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820588E
_08205812:
	movs r1, #4
	b _08205884
_08205816:
	movs r1, #5
	b _08205884
_0820581A:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0
	strb r0, [r6, #0x1b]
	ldrh r0, [r7, #4]
	cmp r0, #1
	bne _08205832
	ldrh r1, [r6, #0xc]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #0xc]
_08205832:
	ldrb r2, [r6, #0x1b]
	adds r0, r6, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r1, r2, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r0, r1
	strb r0, [r6, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r6, #0x19]
	movs r0, #0x10
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r4, [r6, #0x14]
	b _0820588E
_08205866:
	movs r1, #0x11
	b _08205884
_0820586A:
	movs r1, #0x13
	b _08205884
_0820586E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _082058AC
_08205882:
	movs r1, #0x14
_08205884:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820588C:
	str r0, [r6, #0x14]
_0820588E:
	movs r0, #1
	strb r0, [r6, #8]
	b _082058AC
_08205894:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_082058AC:
	movs r1, #1
	add r8, r1
	ldr r0, _082058D4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_082058BA:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _082058C6
	b _082056C8
_082058C6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082058D4: .4byte 0x03002B4C
