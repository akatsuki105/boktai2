	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7014 @ =0x0300019C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081D6FEE
	b _081D7342
_081D6FEE:
	adds r2, r5, #0
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	bne _081D7020
	movs r2, #4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7018
	movs r0, #1
	b _081D701A
	.align 2, 0
_081D7014: .4byte 0x0300019C
_081D7018:
	movs r0, #0
_081D701A:
	cmp r0, #0
	bne _081D7020
	b _081D72A0
_081D7020:
	adds r0, r5, #0
	adds r0, #0xf4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r6, r0, #0
	cmp r1, #0
	ble _081D7030
	b _081D713A
_081D7030:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x28
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _081D707C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7084
_081D707C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7084:
	str r0, [r5]
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
	beq _081D70A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D70B0
_081D70A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D70B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D70E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081D7120
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D70EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D70E0
	ldrb r0, [r4, #5]
_081D70E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D70FC
	.align 2, 0
_081D70E8: .4byte 0x0000FFFF
_081D70EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D70FC
	strh r1, [r4, #8]
_081D70FC:
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
	bne _081D7120
	movs r0, #1
	strb r0, [r4, #7]
_081D7120:
	adds r1, r5, #0
	adds r1, #0xfe
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	movs r6, #0x82
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	b _081D7342
_081D713A:
	movs r2, #1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7150
	movs r0, #1
	b _081D7152
_081D7150:
	movs r0, #0
_081D7152:
	adds r7, r0, #0
	cmp r7, #0
	beq _081D7194
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #3
	beq _081D7188
	ldrh r4, [r6]
	cmp r4, #3
	ble _081D7174
	subs r0, r4, #6
	cmp r0, #0
	bge _081D7172
	rsbs r0, r0, #0
_081D7172:
	adds r4, r0, #0
_081D7174:
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08237040
	strh r4, [r6]
_081D7188:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x22
	str r0, [r1]
	b _081D7342
_081D7194:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x24
	str r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r4, r0, r4
	adds r6, r5, #0
	adds r6, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, r4
	bge _081D72A0
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _081D71FE
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7206
_081D71FE:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7206:
	str r0, [r5]
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
	beq _081D722A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7232
_081D722A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7232:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081D7268 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D72A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D726C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7262
	ldrb r0, [r4, #5]
_081D7262:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D727C
	.align 2, 0
_081D7268: .4byte 0x0000FFFF
_081D726C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D727C
	strh r1, [r4, #8]
_081D727C:
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
	bne _081D72A0
	movs r0, #1
	strb r0, [r4, #7]
_081D72A0:
	mov r6, sl
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081D733C
	adds r0, r5, #0
	adds r0, #0xf4
	adds r2, r5, #0
	adds r2, #0xf6
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r6, r0, #0
	adds r7, r2, #0
	cmp r3, r1
	bge _081D72CE
	adds r0, r4, #0
	adds r0, #0xa
	strh r0, [r6]
	b _081D7334
_081D72CE:
	movs r1, #4
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D72DE
	movs r0, #1
	b _081D72E0
_081D72DE:
	movs r0, #0
_081D72E0:
	cmp r0, #0
	beq _081D7334
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #4
	str r4, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	mov r1, sb
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _081D7306
	movs r0, #1
	b _081D7308
_081D7306:
	movs r0, #0
_081D7308:
	cmp r0, #0
	beq _081D7326
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x94
	strh r0, [r1]
_081D7326:
	ldrh r0, [r7]
	strh r0, [r6]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x30
	str r0, [r1]
_081D7334:
	ldr r0, _081D7354 @ =0x00000105
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081D733C:
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
_081D7342:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D7354: .4byte 0x00000105
