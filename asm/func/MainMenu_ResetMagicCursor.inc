	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r2, r0, #0
	ldr r0, _08097B04 @ =0x00003AE8
	adds r0, r0, r2
	mov sb, r0
	strb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08097B4A
	movs r4, #0
	ldr r1, _08097B08 @ =0x00003AF0
	adds r1, r1, r2
	mov sl, r1
	ldr r0, _08097B0C @ =0x00003FF0
	adds r0, r0, r2
	mov sb, r0
	mov r8, sl
	movs r7, #0xff
_08097AE8:
	movs r3, #0
	mov r0, r8
	adds r1, r4, r0
	lsls r6, r4, #2
	mov r0, sb
	adds r2, r6, r0
_08097AF4:
	adds r5, r6, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08097B10
	strb r5, [r1]
	b _08097B16
	.align 2, 0
_08097B04: .4byte 0x00003AE8
_08097B08: .4byte 0x00003AF0
_08097B0C: .4byte 0x00003FF0
_08097B10:
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
_08097B16:
	adds r1, #4
	adds r2, #1
	adds r3, #1
	cmp r3, #3
	ble _08097AF4
	adds r4, #1
	cmp r4, #3
	ble _08097AE8
	movs r4, #0
	movs r2, #0xff
	mov r6, sl
	adds r6, #0x10
_08097B2E:
	adds r5, r4, #1
	adds r1, r4, r6
	movs r3, #4
_08097B34:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08097B34
	adds r4, r5, #0
	cmp r4, #3
	ble _08097B2E
	b _08097BF4
_08097B4A:
	movs r4, #0
	ldr r1, _08097BB4 @ =0x00003AF0
	adds r1, r1, r2
	mov sl, r1
	ldr r0, _08097BB8 @ =0x00003B10
	adds r0, r2, r0
	str r0, [sp]
	mov r6, sl
_08097B5A:
	adds r5, r4, #1
	adds r2, r4, r6
	movs r3, #3
_08097B60:
	mov r1, sb
	ldrb r0, [r1, #6]
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08097B60
	adds r4, r5, #0
	cmp r4, #3
	ble _08097B5A
	movs r5, #0
_08097B76:
	adds r6, r5, #0
	adds r6, #0x10
	movs r0, #1
	ands r0, r5
	lsls r1, r0, #1
	cmp r5, #1
	bgt _08097BBC
	movs r4, #0
	adds r5, #1
	mov r8, r5
	lsls r0, r0, #3
	mov ip, r0
	mov r7, sl
	adds r7, #0x10
_08097B92:
	adds r3, r1, #0
	adds r2, r3, #2
	adds r5, r4, #1
	cmp r3, r2
	bge _08097BAC
	adds r0, r4, r7
	add r0, ip
	subs r3, r2, r3
_08097BA2:
	strb r6, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08097BA2
_08097BAC:
	adds r4, r5, #0
	cmp r4, #2
	ble _08097B92
	b _08097BDA
	.align 2, 0
_08097BB4: .4byte 0x00003AF0
_08097BB8: .4byte 0x00003B10
_08097BBC:
	adds r3, r1, #0
	adds r2, r3, #2
	adds r5, #1
	mov r8, r5
	cmp r3, r2
	bge _08097BDA
	lsls r0, r0, #3
	adds r0, #0x1b
	add r0, sb
	subs r3, r2, r3
_08097BD0:
	strb r6, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08097BD0
_08097BDA:
	mov r5, r8
	cmp r5, #3
	ble _08097B76
	movs r4, #0
	ldr r2, [sp]
	movs r3, #0xff
_08097BE6:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08097BE6
_08097BF4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
