	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r4, r0, #0
	mov r8, r1
	ldr r2, _08218BC0 @ =0x04000008
	mov r0, r8
	mov r1, sp
	bl CpuSet
	movs r0, #0xbd
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_08231660
	adds r0, #0x54
	bl FUN_08231978
	adds r7, r0, #0
	movs r1, #0
	mov ip, r1
_08218B62:
	mov r1, ip
	lsls r0, r1, #1
	mov r1, sp
	adds r5, r1, r0
	ldrb r1, [r5]
	cmp r1, #0
	bne _08218B76
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08218B88
_08218B76:
	mov r6, ip
	adds r6, #1
	ldrb r0, [r7]
	cmp r1, r0
	bne _08218BDE
	ldrb r0, [r5, #1]
	ldrb r1, [r7, #1]
	cmp r0, r1
	bne _08218BDE
_08218B88:
	movs r0, #0
	strb r0, [r5, #1]
	strb r0, [r5]
	mov r6, ip
	adds r6, #1
	adds r4, r6, #0
	cmp r6, #4
	bgt _08218BDE
	lsls r0, r6, #1
	mov r1, sp
	adds r2, r0, r1
_08218B9E:
	ldrb r1, [r2]
	cmp r1, #0
	bne _08218BAA
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _08218BC4
_08218BAA:
	ldrb r3, [r7]
	cmp r1, r3
	bne _08218BB8
	ldrb r0, [r2, #1]
	ldrb r1, [r7, #1]
	cmp r0, r1
	beq _08218BC4
_08218BB8:
	strb r3, [r5]
	ldrb r0, [r7, #1]
	strb r0, [r5, #1]
	b _08218BDE
	.align 2, 0
_08218BC0: .4byte 0x04000008
_08218BC4:
	mov r0, ip
	cmp r0, #0
	bne _08218BD6
	cmp r4, #4
	bne _08218BD6
	mov r0, r8
	bl FUN_08218b20
	b _08218C1E
_08218BD6:
	adds r2, #2
	adds r4, #1
	cmp r4, #4
	ble _08218B9E
_08218BDE:
	mov ip, r6
	cmp r6, #4
	ble _08218B62
	movs r0, #0
	str r0, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _08218C2C @ =0x05000008
	mov r1, r8
	bl CpuSet
	movs r1, #0
	mov ip, r1
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	beq _08218C1E
	mov r2, sp
	mov r1, r8
_08218C02:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, #1]
	strb r0, [r1, #1]
	adds r2, #2
	adds r1, #2
	movs r0, #1
	add ip, r0
	mov r0, ip
	cmp r0, #4
	bgt _08218C1E
	ldrb r0, [r2]
	cmp r0, #0
	bne _08218C02
_08218C1E:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08218C2C: .4byte 0x05000008
