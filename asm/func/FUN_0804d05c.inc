	push {r4, r5, lr}
	mov ip, r0
	movs r2, #0x9a
	lsls r2, r2, #1
	add r2, ip
	lsls r1, r1, #0x19
	lsrs r3, r1, #0x18
	movs r1, #0
	ldrb r4, [r2, #2]
	movs r5, #2
_0804D070:
	adds r0, r5, #0
	lsls r0, r1
	ands r0, r4
	ands r0, r3
	cmp r0, #0
	beq _0804D086
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D086
	subs r0, #1
	strb r0, [r2, #3]
_0804D086:
	adds r1, #1
	cmp r1, #4
	ble _0804D070
	ldrb r1, [r2, #2]
	bics r1, r3
	strb r1, [r2, #2]
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, r1
	bne _0804D0A6
	mov r1, ip
	adds r1, #0xe8
	movs r0, #0
	strb r0, [r1]
_0804D0A6:
	pop {r4, r5}
	pop {r0}
	bx r0
