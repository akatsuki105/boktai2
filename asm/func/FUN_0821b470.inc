	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	mov sb, sp
	mov r5, sl
	adds r5, #0x7c
	mov r7, sl
	adds r7, #0xaa
	mov r4, sl
	adds r4, #0x94
	mov r8, r5
	movs r0, #7
	str r0, [sp, #8]
_0821B492:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0821B554
	movs r6, #0x12
	ldrsh r0, [r4, r6]
	cmp r0, #0
	blt _0821B51A
	mov r3, sp
	adds r2, r0, #0
	movs r1, #0xf
	mov ip, r1
	ldr r0, _0821B4CC @ =0x085B0A08
	adds r1, r2, #0
	adds r1, #0x40
	movs r6, #0xff
	ands r1, r6
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r6, #0
	ldrsh r1, [r1, r6]
	mov r6, ip
	muls r6, r1, r6
	adds r1, r6, #0
	adds r6, r0, #0
	cmp r1, #0
	blt _0821B4D0
	asrs r1, r1, #0xc
	b _0821B4D6
	.align 2, 0
_0821B4CC: .4byte 0x085B0A08
_0821B4D0:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0821B4D6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	cmp r0, #0
	blt _0821B4F6
	asrs r0, r0, #0xc
	b _0821B4FC
_0821B4F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821B4FC:
	strh r0, [r3, #4]
	mov r1, sb
	ldrh r0, [r1]
	ldrh r6, [r4]
	adds r0, r0, r6
	strh r0, [r4]
	ldrh r0, [r1, #2]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	mov r6, sb
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
_0821B51A:
	ldrh r0, [r4, #0x14]
	subs r0, #1
	movs r6, #0
	strh r0, [r4, #0x14]
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	ldrb r0, [r4, #0x16]
	cmp r0, #8
	bne _0821B53A
	mov r0, sl
	ldr r1, [r0, #0x78]
	mov r0, r8
	movs r2, #3
	bl FUN_0822dafc
_0821B53A:
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r4, #0x17]
	cmp r0, r1
	blo _0821B554
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strh r6, [r4, #0x10]
_0821B554:
	adds r5, #0x30
	adds r7, #0x30
	adds r4, #0x30
	movs r6, #0x30
	add r8, r6
	ldr r0, [sp, #8]
	subs r0, #1
	str r0, [sp, #8]
	cmp r0, #0
	bge _0821B492
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
