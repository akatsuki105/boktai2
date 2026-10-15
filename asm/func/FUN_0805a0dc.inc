	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	movs r0, #0xbc
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805A120
	movs r0, #0
	strb r0, [r4, #1]
	movs r3, #0
	movs r0, #0xa
	strh r0, [r4, #0xe]
	ldrb r0, [r4, #0xc]
	adds r0, #0x80
	strb r0, [r4, #0xc]
	mov r2, ip
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x6c
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	strb r3, [r4, #4]
_0805A120:
	mov r3, sp
	ldrb r5, [r4, #0xc]
	ldrh r6, [r4, #0xe]
	ldr r2, _0805A144 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _0805A148
	asrs r1, r0, #0xc
	b _0805A14E
	.align 2, 0
_0805A144: .4byte 0x085B0A08
_0805A148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805A14E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805A166
	asrs r0, r0, #0xc
	b _0805A16C
_0805A166:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805A16C:
	strh r0, [r3, #4]
	mov r1, ip
	adds r1, #0x1c
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r5, ip
	strh r0, [r5, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r1, #4]
	adds r0, r0, r5
	strh r0, [r1, #4]
	ldrh r0, [r4, #8]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805A1AC
	asrs r2, r0, #0xc
	b _0805A1B2
_0805A1AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805A1B2:
	ldrh r0, [r4, #0x12]
	adds r0, r0, r2
	mov r2, ip
	strh r0, [r2, #0x1e]
	ldrb r0, [r4, #0xd]
	adds r0, #0x10
	strb r0, [r4, #0xd]
	ldrh r1, [r4, #8]
	cmp r1, #0xf
	bhi _0805A1E6
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0805A1D8
	mov r3, ip
	ldr r0, [r3]
	orrs r0, r2
	b _0805A206
_0805A1D8:
	mov r5, ip
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	b _0805A208
_0805A1E6:
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bhi _0805A1FC
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _0805A208
_0805A1FC:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0805A206:
	str r0, [r3]
_0805A208:
	ldrh r0, [r4, #8]
	cmp r0, #0x1f
	bls _0805A21A
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl FUN_08059d38
	b _0805A21E
_0805A21A:
	adds r0, #1
	strh r0, [r4, #8]
_0805A21E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
