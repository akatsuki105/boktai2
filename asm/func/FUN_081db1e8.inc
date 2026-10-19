	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _081DB220 @ =0x085AE1B4
	mov sl, r0
	ldr r1, _081DB224 @ =0x0000032D
	adds r3, r2, r1
	movs r7, #4
	add r7, sl
	mov sb, r7
	ldr r6, _081DB228 @ =0x085AE1CC
	adds r0, r6, #4
	mov r8, r0
	ldr r5, _081DB22C @ =0x085AE1E4
	adds r1, r5, #4
	mov ip, r1
_081DB210:
	cmp r4, #1
	beq _081DB252
	cmp r4, #1
	bgt _081DB230
	cmp r4, #0
	beq _081DB236
	b _081DB28C
	.align 2, 0
_081DB220: .4byte 0x085AE1B4
_081DB224: .4byte 0x0000032D
_081DB228: .4byte 0x085AE1CC
_081DB22C: .4byte 0x085AE1E4
_081DB230:
	cmp r4, #2
	beq _081DB26E
	b _081DB28C
_081DB236:
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sl
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sb
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x42
	b _081DB28A
_081DB252:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa0
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	b _081DB28A
_081DB26E:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	adds r7, #2
	adds r1, r2, r7
_081DB28A:
	strh r0, [r1]
_081DB28C:
	adds r4, #1
	cmp r4, #6
	ble _081DB210
	adds r4, r2, #0
	adds r4, #0x88
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r3, r2, #0
	adds r3, #0xe8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _081DB2E8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DB2CA
	ldr r7, _081DB2EC @ =0x00000325
	adds r0, r2, r7
	ldrb r1, [r0]
	cmp r1, #1
	bne _081DB2CA
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081DB2CA:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081DB2F0 @ =0x00000282
	adds r0, r2, r3
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB2E8: .4byte 0x0000032D
_081DB2EC: .4byte 0x00000325
_081DB2F0: .4byte 0x00000282
