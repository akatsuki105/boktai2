	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x70
	movs r1, #0xe7
	adds r1, r1, r5
	mov sb, r1
	ldrb r0, [r1]
	mov r2, r8
	ldrb r1, [r2, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D044
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r6, [r0]
	cmp r6, #0
	beq _0804CF92
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	adds r1, r5, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	b _0804D044
_0804CF92:
	ldrb r0, [r7]
	str r0, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r7, #0
	bl FUN_0823a790
	adds r4, r5, #0
	adds r4, #0x36
	strb r6, [r4]
	str r6, [sp]
	ldr r2, _0804D054 @ =0x05000004
	mov r0, sp
	adds r1, r7, #0
	bl CpuSet
	movs r2, #0
	mov r0, sb
	str r0, [sp, #0xc]
	str r4, [sp, #8]
	adds r6, r5, #0
	adds r6, #0xea
	movs r1, #0xec
	adds r1, r1, r5
	mov ip, r1
	movs r0, #0xe6
	adds r0, r0, r5
	mov sl, r0
	movs r1, #2
	mov sb, r1
	adds r3, r5, #0
	adds r3, #0x82
	adds r4, #0x40
_0804CFD6:
	mov r1, sb
	lsls r1, r2
	mov r5, r8
	ldrb r0, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0804CFE8
	ldrh r0, [r3]
	strh r0, [r4]
_0804CFE8:
	adds r3, #4
	adds r4, #2
	adds r2, #1
	cmp r2, #3
	ble _0804CFD6
	ldrh r0, [r6]
	strh r0, [r7, #4]
	mov r1, ip
	ldrh r0, [r1]
	strh r0, [r6]
	ldr r0, _0804D058 @ =0x0000FFFF
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #2]
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	movs r2, #0
	ldr r3, [sp, #4]
	adds r3, #1
	movs r5, #2
_0804D012:
	mov r0, r8
	ldrb r1, [r0, #2]
	adds r0, r5, #0
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	beq _0804D026
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
_0804D026:
	adds r2, #1
	cmp r2, #3
	ble _0804D012
	strb r3, [r7]
	movs r1, #1
	ldr r2, [sp, #0xc]
	strb r1, [r2]
	mov r5, sl
	strb r1, [r5]
	mov r2, r8
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	ldr r5, [sp, #8]
	strb r1, [r5]
_0804D044:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D054: .4byte 0x05000004
_0804D058: .4byte 0x0000FFFF
