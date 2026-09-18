	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, #8
	add r0, r8
	mov ip, r0
	mov r7, ip
	adds r7, #0x28
	adds r6, r7, #0
	mov r0, sb
	ldr r3, [r0, #0x20]
	mov r4, ip
	adds r4, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x18]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BD56
	mov r1, ip
	ldr r0, [r1, #0x28]
	movs r1, #4
	orrs r0, r1
	b _0800BD60
_0800BD56:
	mov r1, ip
	ldr r0, [r1, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800BD60:
	mov r2, ip
	str r0, [r2, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800BD86
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0800BD8E
_0800BD86:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800BD8E:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0800BDC8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0800BE00
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800BDD2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800BDCC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0800BDE8
	.align 2, 0
_0800BDC8: .4byte 0x0000FFFF
_0800BDCC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800BDE6
_0800BDD2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800BDE6
	strh r1, [r4, #8]
	movs r2, #1
	b _0800BDE8
_0800BDE6:
	movs r2, #0
_0800BDE8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _0800BE02
_0800BE00:
	movs r2, #0
_0800BE02:
	cmp r2, #0
	beq _0800BE2A
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, r8
	ldrb r0, [r2, #1]
	subs r0, #1
	strb r0, [r2, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800BE2A
	mov r0, sb
	mov r1, r8
	bl Entity0800a89c_ReleaseSwarm
_0800BE2A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
