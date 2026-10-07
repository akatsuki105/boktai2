	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	movs r0, #0
	mov r8, r0
	mov r1, sb
	ldrh r0, [r1, #0x1a]
	add r2, sp, #0x20
	mov sl, r2
	cmp r8, r0
	bge _081DDD3A
	adds r3, r0, #0
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sb
	mov r1, sp
_081DDD24:
	mov r4, r8
	str r4, [r1]
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [r1, #0x10]
	adds r2, #2
	adds r1, #4
	movs r0, #1
	add r8, r0
	cmp r8, r3
	blt _081DDD24
_081DDD3A:
	mov r1, sb
	ldrh r1, [r1, #0x1a]
	mov ip, r1
	mov r2, r8
	cmp r2, #3
	bgt _081DDD5E
	movs r1, #1
	rsbs r1, r1, #0
	lsls r0, r2, #2
	add r0, sp
_081DDD4E:
	str r1, [r0]
	str r1, [r0, #0x10]
	adds r0, #4
	movs r4, #1
	add r8, r4
	mov r2, r8
	cmp r2, #3
	ble _081DDD4E
_081DDD5E:
	movs r4, #0
	mov r8, r4
_081DDD62:
	movs r0, #3
	cmp r0, r8
	ble _081DDD94
	add r7, sp, #0x10
_081DDD6A:
	subs r6, r0, #1
	lsls r5, r6, #2
	adds r3, r7, r5
	lsls r4, r0, #2
	adds r2, r7, r4
	ldr r0, [r3]
	ldr r1, [r2]
	cmp r0, r1
	bge _081DDD8E
	str r0, [r2]
	str r1, [r3]
	mov r0, sp
	adds r2, r0, r4
	ldr r3, [r2]
	adds r1, r0, r5
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_081DDD8E:
	adds r0, r6, #0
	cmp r0, r8
	bgt _081DDD6A
_081DDD94:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #2
	ble _081DDD62
	mov r1, sl
	movs r2, #0
	mov r0, sl
	adds r0, #0xc
_081DDDA6:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _081DDDA6
	movs r3, #0
	movs r0, #1
	str r0, [sp, #0x20]
	str r3, [sp, #0x30]
	mov r8, r0
	cmp r8, ip
	bge _081DDDE4
	mov r6, sl
	add r2, sp, #0x10
	mov r4, ip
	add r5, sp, #0x34
_081DDDC4:
	ldr r1, [r2, #4]
	ldr r0, [r2]
	cmp r1, r0
	bge _081DDDCE
	mov r3, r8
_081DDDCE:
	stm r5!, {r3}
	lsls r1, r3, #2
	adds r1, r6, r1
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r2, #4
	movs r0, #1
	add r8, r0
	cmp r8, r4
	blt _081DDDC4
_081DDDE4:
	movs r1, #0
	mov r8, r1
	mov r2, ip
	cmp r8, r2
	bge _081DDE86
	movs r4, #0xa0
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x40]
	mov r6, sp
_081DDDF8:
	mov r0, r8
	lsls r1, r0, #2
	ldr r7, [r6]
	add r0, sp, #0x30
	adds r0, r0, r1
	ldr r5, [r0]
	lsls r1, r5, #1
	movs r0, #0xaa
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _081DDE34 @ =0x085AE3D4
	lsls r0, r2, #2
	adds r0, r5, r0
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, [sp, #0x40]
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	cmp r0, #0
	blt _081DDE38
	asrs r0, r0, #6
	b _081DDE3E
	.align 2, 0
_081DDE34: .4byte 0x085AE3D4
_081DDE38:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081DDE3E:
	cmp r0, #0
	ble _081DDE4A
	cmp r0, #0x3c
	ble _081DDE54
	movs r0, #0x3c
	b _081DDE54
_081DDE4A:
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081DDE54
	adds r0, r1, #0
_081DDE54:
	adds r4, r4, r0
	lsls r0, r5, #2
	add r0, sl
	ldr r1, [r0]
	cmp r1, #1
	ble _081DDE68
	adds r0, r4, #0
	bl Div
	adds r4, r0, #0
_081DDE68:
	lsls r0, r7, #2
	movs r1, #0xa2
	lsls r1, r1, #1
	add r1, sb
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	adds r6, #4
	movs r4, #1
	add r8, r4
	mov r0, sb
	ldrh r2, [r0, #0x1a]
	cmp r8, r2
	blt _081DDDF8
_081DDE86:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
