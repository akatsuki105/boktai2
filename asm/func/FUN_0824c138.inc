	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x18
	ldr r0, _0824C1B0 @ =gRfuLinkStatus
	lsrs r1, r1, #0x13
	adds r1, #0x14
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #0x19
	mov r1, sp
	movs r2, #4
	bl FUN_0824c0f8
	mov r0, sp
	ldrb r2, [r0, #3]
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x1d
	adds r0, #3
	strb r0, [r4]
	lsrs r1, r1, #0x19
	movs r0, #0xf
	ands r1, r0
	strb r1, [r4, #1]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #4
	mov r1, sp
	ldrb r2, [r1, #2]
	lsrs r1, r2, #4
	orrs r0, r1
	strb r0, [r4, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #1
	mov r1, sp
	ldrb r5, [r1, #1]
	lsls r1, r5, #0x18
	lsrs r2, r1, #0x1f
	orrs r0, r2
	strb r0, [r4, #3]
	lsrs r1, r1, #0x19
	movs r0, #0x3f
	ands r1, r0
	strb r1, [r4, #4]
	ands r3, r5
	lsls r3, r3, #5
	mov r0, sp
	ldrb r1, [r0]
	lsrs r0, r1, #3
	orrs r3, r0
	strb r3, [r4, #5]
	movs r0, #7
	ands r0, r1
	strb r0, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824C1B0: .4byte gRfuLinkStatus
