	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r0, #0
	movs r0, #0xff
	ands r6, r0
	cmp r5, #0
	ble _08230A66
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08230A66
	movs r1, #3
_08230A54:
	strb r6, [r4]
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	ble _08230A66
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08230A54
_08230A66:
	lsls r0, r6, #8
	orrs r0, r6
	lsls r1, r6, #0x10
	orrs r0, r1
	lsls r6, r6, #0x18
	orrs r6, r0
	str r6, [sp]
	movs r7, #4
	rsbs r7, r7, #0
	ands r7, r5
	adds r2, r7, #0
	cmp r7, #0
	bge _08230A82
	adds r2, r7, #3
_08230A82:
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	movs r0, #0xa0
	lsls r0, r0, #0x13
	orrs r2, r0
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	adds r4, r4, r7
	movs r0, #3
	ands r5, r0
	cmp r5, #0
	ble _08230AA8
_08230A9E:
	strb r6, [r4]
	subs r5, #1
	adds r4, #1
	cmp r5, #0
	bgt _08230A9E
_08230AA8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
