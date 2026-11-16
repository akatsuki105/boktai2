	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	adds r2, r1, #0
	adds r0, r1, #0
	muls r0, r1, r0
	mov sb, r0
	ldr r3, _0801AE60 @ =0x000002F6
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _0801ADA6
	movs r3, #0
_0801ADA6:
	adds r7, r0, r1
	cmp r7, #0xb4
	ble _0801ADAE
	movs r7, #0xb4
_0801ADAE:
	subs r0, r2, r0
	mov r0, r8
	lsls r2, r0, #1
	adds r1, r2, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r5, r6, r0
	mov sl, r2
	cmp r3, #0
	ble _0801ADD4
	movs r0, #0
	adds r4, r3, #0
_0801ADCA:
	strh r0, [r5]
	subs r4, #1
	adds r5, #2
	cmp r4, #0
	bne _0801ADCA
_0801ADD4:
	adds r4, r3, #0
	cmp r4, r7
	bge _0801AE28
	movs r3, #0xff
_0801ADDC:
	ldr r1, _0801AE60 @ =0x000002F6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r0, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sb
	subs r0, r2, r0
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r1, r0
	adds r1, r1, r0
	ldr r3, [sp]
	cmp r2, #0
	bge _0801AE10
	movs r2, #0
_0801AE10:
	cmp r1, #0xf0
	ble _0801AE16
	movs r1, #0xf0
_0801AE16:
	ands r2, r3
	lsls r0, r2, #8
	ands r1, r3
	orrs r0, r1
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, r7
	blt _0801ADDC
_0801AE28:
	adds r4, r7, #0
	cmp r4, #0xb3
	bgt _0801AE3A
	movs r0, #0
_0801AE30:
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, #0xb3
	ble _0801AE30
_0801AE3A:
	mov r1, sl
	add r1, r8
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AE60: .4byte 0x000002F6
