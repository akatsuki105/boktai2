	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08089c7c
	cmp r0, #0
	beq _08089D1E
	movs r0, #0x4e
	adds r0, r0, r4
	mov ip, r0
	movs r3, #2
	rsbs r3, r3, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r4, r0
_08089D00:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _08089D00
	movs r0, #0
	movs r1, #1
	mov r2, ip
	strh r1, [r2]
	str r0, [r4, #0x64]
	movs r0, #0xe3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08089D1E:
	pop {r4}
	pop {r0}
	bx r0
