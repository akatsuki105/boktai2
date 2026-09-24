	push {r4, r5, r6, r7, lr}
	mov ip, r0
	mov r7, ip
	ldr r5, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
	ldr r0, _081D770C @ =0x0300019C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D76D8
	b _081D780E
_081D76D8:
	mov r4, ip
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r2, ip
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7710
	movs r0, #4
	orrs r5, r0
	mov r0, ip
	str r5, [r0]
	b _081D771A
	.align 2, 0
_081D770C: .4byte 0x0300019C
_081D7710:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
_081D771A:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D773C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D7744
_081D773C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7744:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D777C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D77B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7774
	ldrb r0, [r4, #5]
_081D7774:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7790
	.align 2, 0
_081D777C: .4byte 0x0000FFFF
_081D7780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7790
	strh r1, [r4, #8]
_081D7790:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D77B4
	movs r0, #1
	strb r0, [r4, #7]
_081D77B4:
	mov r2, ip
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _081D77F2
	mov r0, ip
	adds r0, #0xf4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081D77EC
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x28
	str r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	movs r0, #4
	strh r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	strb r3, [r0]
	b _081D780E
_081D77EC:
	movs r0, #0
	strb r0, [r2]
	b _081D780E
_081D77F2:
	mov r2, ip
	adds r2, #0xf4
	mov r0, ip
	adds r0, #0xf6
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D780E
	adds r0, r3, #0
	adds r0, #0xa
	strh r0, [r2]
_081D780E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
