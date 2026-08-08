	push {r4, r5, r6, lr}
	sub sp, #0x18
	mov ip, r0
	movs r0, #0xe5
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	cmp r0, #7
	beq _0821E60A
	cmp r0, #9
	beq _0821E60E
	movs r0, #0
	b _0821E72E
_0821E60A:
	movs r6, #0xc8
	b _0821E610
_0821E60E:
	movs r6, #0x80
_0821E610:
	mov r4, sp
	movs r0, #0xed
	lsls r0, r0, #2
	add r0, ip
	ldr r3, [r0]
	ldr r2, _0821E638 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0821E63C
	asrs r1, r0, #0xc
	b _0821E642
	.align 2, 0
_0821E638: .4byte 0x085B0A08
_0821E63C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821E642:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0821E65E
	asrs r0, r0, #0xc
	b _0821E664
_0821E65E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821E664:
	strh r0, [r4, #4]
	mov r2, ip
	adds r2, #0x50
	mov r3, sp
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	rsbs r1, r6, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0821E6FC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	add r5, sp, #8
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r1, r6, #0
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r6, [r2]
	adds r4, r0, r6
	strh r4, [r2]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r3, r0, r1
	strh r3, [r2, #4]
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	adds r2, r0, #0
	cmp r2, #0
	bne _0821E700
	movs r6, #0
	b _0821E72C
	.align 2, 0
_0821E6FC: .4byte 0xFFFF0000
_0821E700:
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r6, #0
	ldrsh r0, [r5, r6]
	movs r6, #0
	cmp r1, r0
	blt _0821E72C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _0821E72C
	movs r0, #4
	ldrsh r2, [r2, r0]
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r2, r0
	blt _0821E72C
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bgt _0821E72C
	movs r6, #1
_0821E72C:
	adds r0, r6, #0
_0821E72E:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
