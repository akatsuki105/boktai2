	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r2, r0, #0
	str r1, [sp, #0x10]
	ldr r0, _08094AF0 @ =0x00003AE8
	adds r0, r2, r0
	str r0, [sp, #0x14]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	bne _08094AF8
	movs r0, #0
	ldr r5, [sp, #0x14]
	strb r0, [r5]
	movs r4, #0
	ldr r0, _08094AF4 @ =0x00003AF0
	adds r5, r2, r0
	movs r2, #0xff
_08094ACC:
	adds r7, r4, #1
	adds r1, r4, r5
	movs r3, #8
_08094AD2:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08094AD2
	adds r4, r7, #0
	cmp r4, #3
	ble _08094ACC
	movs r0, #0
	ldr r1, [sp, #0x14]
	strb r0, [r1, #8]
	b _08094C5C
	.align 2, 0
_08094AF0: .4byte 0x00003AE8
_08094AF4: .4byte 0x00003AF0
_08094AF8:
	mov r4, sp
	ldrb r5, [r4, #0x10]
	ldr r4, [sp, #0x14]
	strb r5, [r4]
	movs r4, #0
	ldr r0, _08094B50 @ =0x00003AF0
	adds r0, r2, r0
	str r0, [sp, #0x18]
	ldr r1, _08094B54 @ =0x00003B10
	adds r1, r2, r1
	str r1, [sp, #0x1c]
	ldr r5, _08094B58 @ =0x00003B13
	adds r5, r2, r5
	str r5, [sp, #0x20]
	adds r2, r0, #0
_08094B16:
	adds r7, r4, #1
	lsls r0, r4, #2
	movs r3, #3
	adds r1, r0, #3
	adds r0, r4, r2
	adds r0, #0xc
_08094B22:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _08094B22
	adds r4, r7, #0
	cmp r4, #3
	ble _08094B16
	movs r6, #0
	movs r3, #1
	movs r2, #1
	rsbs r2, r2, #0
	mov r1, sp
_08094B3E:
	ldr r0, [sp, #0x10]
	asrs r0, r6
	ands r0, r3
	cmp r0, #0
	beq _08094B5C
	adds r0, r6, #0
	adds r0, #0x10
	str r0, [r1]
	b _08094B5E
	.align 2, 0
_08094B50: .4byte 0x00003AF0
_08094B54: .4byte 0x00003B10
_08094B58: .4byte 0x00003B13
_08094B5C:
	str r2, [r1]
_08094B5E:
	adds r1, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B3E
	movs r6, #0
	movs r4, #3
	mov r3, sp
_08094B6C:
	ldr r2, [r3]
	cmp r2, #0
	blt _08094B84
	adds r0, r6, #2
	ands r0, r4
	lsls r0, r0, #2
	mov r5, sp
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	bge _08094B84
	str r2, [r1]
_08094B84:
	adds r3, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B6C
	movs r6, #0
	movs r4, #1
	mov r3, sp
_08094B92:
	ldr r2, [r3]
	cmp r2, #0
	blt _08094BB0
	asrs r0, r6, #1
	lsls r0, r0, #1
	adds r1, r6, #1
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r5, sp
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	bge _08094BB0
	str r2, [r1]
_08094BB0:
	adds r3, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B92
	movs r6, #0
_08094BBA:
	movs r5, #1
	ands r5, r6
	lsls r0, r5, #1
	mov ip, r0
	cmp r6, #1
	bgt _08094C04
	movs r4, #0
	adds r1, r6, #1
	mov sl, r1
	lsls r5, r5, #3
	mov sb, r5
	ldr r5, [sp, #0x18]
	adds r5, #0x10
	mov r8, r5
_08094BD6:
	mov r3, ip
	adds r2, r3, #2
	adds r7, r4, #1
	cmp r3, r2
	bge _08094BFC
	lsls r0, r6, #2
	mov r1, sp
	adds r5, r1, r0
	mov r1, r8
	adds r0, r4, r1
	mov r4, sb
	adds r1, r4, r0
	subs r3, r2, r3
_08094BF0:
	ldr r0, [r5]
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bne _08094BF0
_08094BFC:
	adds r4, r7, #0
	cmp r4, #2
	ble _08094BD6
	b _08094C2A
_08094C04:
	mov r3, ip
	adds r2, r3, #2
	adds r0, r6, #1
	mov sl, r0
	cmp r3, r2
	bge _08094C2A
	lsls r0, r6, #2
	add r0, sp
	ldr r1, [r0]
	lsls r0, r5, #3
	adds r0, #0x1b
	ldr r4, [sp, #0x14]
	adds r0, r0, r4
	subs r3, r2, r3
_08094C20:
	strb r1, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08094C20
_08094C2A:
	mov r6, sl
	cmp r6, #3
	ble _08094BBA
	movs r4, #0
	ldr r2, [sp, #0x1c]
	movs r3, #0xff
_08094C36:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _08094C36
	movs r0, #0x20
	ldr r5, [sp, #0x10]
	ands r0, r5
	cmp r0, #0
	beq _08094C56
	movs r0, #0x15
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	b _08094C5C
_08094C56:
	movs r0, #0xff
	ldr r4, [sp, #0x20]
	strb r0, [r4]
_08094C5C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
