	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	ldrh r1, [r5, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081E8D62
	b _081E8E72
_081E8D62:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _081E8D6E
	b _081E8E72
_081E8D6E:
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _081E8E2A
	ldrb r2, [r2, #2]
	ldr r0, [r5, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081E8DC4
	adds r2, #0x20
	movs r0, #0xff
	ands r2, r0
	cmp r2, #0
	blt _081E8D94
	asrs r0, r2, #6
	b _081E8D9A
_081E8D94:
	rsbs r0, r2, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8D9A:
	adds r2, r0, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081E8DB2
	asrs r0, r1, #6
	b _081E8DB8
_081E8DB2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8DB8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081E8DC0
	rsbs r0, r0, #0
_081E8DC0:
	cmp r0, #2
	bne _081E8DC8
_081E8DC4:
	movs r0, #1
	b _081E8DCA
_081E8DC8:
	movs r0, #0
_081E8DCA:
	cmp r0, #0
	beq _081E8E72
	movs r0, #3
	strb r0, [r3]
	adds r1, r3, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E14
	asrs r0, r0, #5
	b _081E8E1A
_081E8E14:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E1A:
	strh r0, [r6, #0x22]
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	b _081E8E72
_081E8E2A:
	movs r0, #3
	strb r0, [r3]
	adds r0, r3, #0
	adds r0, #0xe6
	strh r4, [r0]
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E6A
	asrs r0, r0, #5
	b _081E8E70
_081E8E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E70:
	strh r0, [r6, #0x22]
_081E8E72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
