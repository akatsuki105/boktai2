	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0819D11C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D120
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D122
	.align 2, 0
_0819D11C: .4byte 0x0000046D
_0819D120:
	movs r0, #0
_0819D122:
	cmp r0, #0
	beq _0819D148
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnimNoFacing
	adds r0, r7, #0
	bl Ax_StopChase
	adds r0, r7, #0
	bl Ax_ResumeHover
_0819D148:
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0819D168
	asrs r0, r0, #2
	b _0819D16E
_0819D168:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0819D16E:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0819D18E
	asrs r0, r0, #2
	b _0819D194
_0819D18E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0819D194:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0819D19E
	movs r3, #0xc8
	b _0819D1A8
_0819D19E:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0819D1A8
	adds r3, r0, #0
_0819D1A8:
	cmp r2, #0xc8
	ble _0819D1B0
	movs r2, #0xc8
	b _0819D1BA
_0819D1B0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0819D1BA
	adds r2, r0, #0
_0819D1BA:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0819D1DE
	cmp r2, #0
	bne _0819D1DE
	movs r0, #1
	b _0819D1E0
_0819D1DE:
	movs r0, #0
_0819D1E0:
	cmp r0, #0
	beq _0819D262
	ldr r1, _0819D26C @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	subs r3, #4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl Ax_ResumeHover
	movs r2, #0x10
	ldr r1, _0819D270 @ =0x00000E48
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0819D274 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #9
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0819D278 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0819D27C @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r5, [r0]
_0819D262:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D26C: .4byte 0x0000046B
_0819D270: .4byte 0x00000E48
_0819D274: .4byte 0x0000024E
_0819D278: .4byte 0x0000046A
_0819D27C: .4byte 0x00000484
