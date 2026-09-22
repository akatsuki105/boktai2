	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov sl, r1
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _08047BAC @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	bne _08047BB0
	movs r0, #0
	b _08047BFC
	.align 2, 0
_08047BAC: .4byte 0x030000C4
_08047BB0:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	ldr r1, _08047C0C @ =0x00000179
	adds r1, r1, r5
	mov r8, r1
	ldrb r1, [r1]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r7, r5, r2
	ldrb r2, [r7]
	ldr r3, _08047C10 @ =0x0000017B
	adds r6, r5, r3
	ldrb r3, [r6]
	bl FUN_0822ea60
	mov r0, sb
	strb r0, [r4]
	mov r2, sl
	mov r1, r8
	strb r2, [r1]
	mov r3, sp
	ldrb r3, [r3, #4]
	strb r3, [r7]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x18
	ldrb r1, [r4]
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r7]
	ldrb r4, [r6]
	str r4, [sp]
	bl FUN_08049650
_08047BFC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047C0C: .4byte 0x00000179
_08047C10: .4byte 0x0000017B
