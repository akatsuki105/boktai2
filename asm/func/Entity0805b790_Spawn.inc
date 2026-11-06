	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r4, r3, #0
	add r1, sp, #8
	bl Entity0805b790_AllocElem
	adds r5, r0, #0
	cmp r5, #0
	bne _0805B7F8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B886
_0805B7F8:
	adds r6, r5, #0
	adds r6, #0x60
	movs r1, #0
	strb r4, [r5]
	ldrb r0, [r5]
	cmp r0, #1
	beq _0805B816
	cmp r0, #1
	bgt _0805B810
	cmp r0, #0
	beq _0805B81A
	b _0805B822
_0805B810:
	cmp r0, #2
	beq _0805B81A
	b _0805B822
_0805B816:
	strb r0, [r5, #2]
	b _0805B81E
_0805B81A:
	strb r1, [r5, #2]
	movs r0, #1
_0805B81E:
	strb r0, [r5, #1]
	strh r1, [r5, #4]
_0805B822:
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #6]
	ldr r0, [sp, #0x28]
	strb r0, [r5, #3]
	movs r2, #1
	strb r2, [r5, #8]
	mov r0, r8
	str r0, [r5, #0xc]
	adds r1, r5, #0
	adds r1, #0x10
	ldr r0, [r7, #0x20]
	mov r8, r1
	cmp r0, #0
	bne _0805B842
	str r2, [sp]
	b _0805B846
_0805B842:
	movs r0, #2
	str r0, [sp]
_0805B846:
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r1, #0
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	movs r3, #0x10
	bl Hitbox_SetAttack
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r4, #1
	strh r4, [r6, #0x10]
	adds r1, r5, #0
	adds r1, #0x7c
	mov r0, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	lsls r4, r0
	ldr r0, [r7, #0x18]
	orrs r0, r4
	str r0, [r7, #0x18]
	movs r0, #0
_0805B886:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
