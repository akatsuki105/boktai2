	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r4, r0, #0
	cmp r5, #0
	ble _082309F6
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _082309F6
	movs r2, #0
	movs r1, #3
_082309E4:
	strb r2, [r4]
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	ble _082309F6
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _082309E4
_082309F6:
	movs r0, #0
	str r0, [sp]
	movs r6, #4
	rsbs r6, r6, #0
	ands r6, r5
	adds r2, r6, #0
	cmp r6, #0
	bge _08230A08
	adds r2, r6, #3
_08230A08:
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	movs r0, #0xa0
	lsls r0, r0, #0x13
	orrs r2, r0
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	adds r4, r4, r6
	movs r0, #3
	ands r5, r0
	cmp r5, #0
	ble _08230A30
	movs r0, #0
_08230A26:
	strb r0, [r4]
	subs r5, #1
	adds r4, #1
	cmp r5, #0
	bgt _08230A26
_08230A30:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
