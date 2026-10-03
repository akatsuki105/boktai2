	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0804D34C @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804D364
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r0, sp
	bl rfu_UNI_PARENT_getDRAC_ACK
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0804D360
	adds r2, r4, #0
	adds r2, #0xe7
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D350
	adds r0, r4, #0
	adds r0, #0xe8
	strb r3, [r0]
	subs r0, #0xb2
	strb r3, [r0]
	b _0804D360
	.align 2, 0
_0804D34C: .4byte 0x03002B58
_0804D350:
	adds r1, r4, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804D360:
	bl rfu_REQ_recvData
_0804D364:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
