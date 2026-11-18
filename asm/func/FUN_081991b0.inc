	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	mov r8, r0
	movs r3, #0
	ldr r7, _0819921C @ =0x00000183
	adds r4, r2, r7
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	bge _08199232
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r6, r2, r0
	movs r1, #0
	mov sb, r1
	movs r1, #1
	subs r7, #0x72
	adds r7, r7, r2
	mov ip, r7
	subs r0, #0x26
	adds r0, r0, r2
	mov sl, r0
	movs r7, #0x8b
	lsls r7, r7, #1
	adds r5, r2, r7
_081991F2:
	ldrb r0, [r6]
	ldrb r7, [r2, #6]
	adds r0, r0, r7
	strb r0, [r2, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _08199228
	strb r1, [r5]
	ldr r3, _08199220 @ =0x00000117
	adds r0, r2, r3
	strb r1, [r0]
	mov r7, ip
	ldrb r0, [r7]
	orrs r1, r0
	strb r1, [r7]
	ldr r0, _08199224 @ =FUN_08199c38
	mov r1, sl
	str r0, [r1]
	b _08199254
	.align 2, 0
_0819921C: .4byte 0x00000183
_08199220: .4byte 0x00000117
_08199224: .4byte FUN_08199c38
_08199228:
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	blt _081991F2
_08199232:
	ldr r0, _08199264 @ =0x00000CEC
	add r0, r8
	ldr r0, [r0]
	movs r3, #7
	ands r0, r3
	cmp r0, #0
	bne _08199254
	ldr r7, _08199268 @ =0x00000183
	adds r1, r2, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _08199254
	strb r3, [r1]
_08199254:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199264: .4byte 0x00000CEC
_08199268: .4byte 0x00000183
