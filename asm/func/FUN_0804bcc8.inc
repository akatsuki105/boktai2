	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r2, _0804BD08 @ =0x01000020
	adds r1, r5, #0
	bl CpuSet
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BD10
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r7, #0x22]
	movs r1, #8
	orrs r0, r1
	orrs r0, r4
	ldr r1, _0804BD0C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD12
	.align 2, 0
_0804BD08: .4byte 0x01000020
_0804BD0C: .4byte 0x0000FEFF
_0804BD10:
	strb r4, [r5]
_0804BD12:
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0804BD38
	movs r0, #1
	strb r0, [r5, #1]
	ldrh r1, [r7, #0x22]
	movs r0, #0x10
	orrs r0, r1
	ldr r1, _0804BD34 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD3A
	.align 2, 0
_0804BD34: .4byte 0x0000FDFF
_0804BD38:
	strb r0, [r5, #1]
_0804BD3A:
	movs r0, #1
	strb r0, [r5, #3]
	movs r3, #0
	ldr r4, _0804BDD0 @ =0x03005800
	adds r2, r5, #4
	movs r1, #1
_0804BD46:
	ldrb r0, [r7, #0x19]
	asrs r0, r3
	ands r0, r1
	cmp r0, #0
	beq _0804BD56
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_0804BD56:
	adds r3, #1
	cmp r3, #3
	ble _0804BD46
	ldrb r0, [r7, #0x19]
	lsls r0, r0, #1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #2]
	ldr r0, [r4]
	adds r0, #0xa9
	adds r1, r2, #0
	movs r2, #8
	bl StrCopyPadded
	ldr r1, [r4]
	adds r1, #0x94
	ldrh r1, [r1]
	strh r1, [r5, #0x36]
	movs r3, #0
	mov r8, r4
_0804BD7E:
	ldrb r2, [r7, #0x19]
	asrs r2, r3
	movs r1, #1
	ands r2, r1
	adds r6, r3, #1
	cmp r2, #0
	beq _0804BDBC
	lsls r4, r3, #5
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0x15
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, #0xe
	adds r1, r5, r1
	movs r2, #8
	bl StrCopyPadded
	lsls r1, r6, #1
	adds r2, r5, #0
	adds r2, #0x36
	adds r2, r2, r1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r1, r4
	ldrh r1, [r1, #0x14]
	strh r1, [r2]
_0804BDBC:
	adds r3, r6, #0
	cmp r3, #3
	ble _0804BD7E
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804BDD0: .4byte 0x03005800
