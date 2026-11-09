	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r1, r0, #0
	movs r2, #0
	adds r4, r1, #0
	adds r4, #0x40
	movs r0, #0x1d
	mov r8, r0
	movs r7, #0x40
	mov ip, r7
	movs r0, #0xd3
	mov sb, r0
	movs r6, #0x70
	adds r3, r4, #0
	movs r5, #0
_081DBD06:
	cmp r2, #1
	beq _081DBD28
	cmp r2, #1
	bgt _081DBD14
	cmp r2, #0
	beq _081DBD1E
	b _081DBD5C
_081DBD14:
	cmp r2, #2
	beq _081DBD38
	cmp r2, #3
	beq _081DBD48
	b _081DBD5C
_081DBD1E:
	mov r7, r8
	strh r7, [r4]
	adds r0, r1, #0
	adds r0, #0x42
	b _081DBD32
_081DBD28:
	adds r0, r1, #0
	adds r0, #0xa0
	mov r7, sb
	strh r7, [r0]
	adds r0, #2
_081DBD32:
	mov r7, ip
	strh r7, [r0]
	b _081DBD60
_081DBD38:
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, r8
	strh r7, [r0]
	movs r7, #0x81
	lsls r7, r7, #1
	b _081DBD56
_081DBD48:
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, sb
	strh r7, [r0]
	movs r7, #0xb1
	lsls r7, r7, #1
_081DBD56:
	adds r0, r1, r7
	strh r6, [r0]
	b _081DBD60
_081DBD5C:
	strh r5, [r3]
	strh r5, [r3, #2]
_081DBD60:
	adds r3, #0x60
	adds r2, #1
	cmp r2, #7
	ble _081DBD06
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
