	push {r4, r5, lr}
	movs r2, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r3, r0, r1
	movs r5, #1
	movs r1, #0x47
	adds r1, r1, r0
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EE81A:
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081EE82A
	movs r0, #1
	b _081EE82C
_081EE82A:
	movs r0, #0
_081EE82C:
	cmp r0, #0
	bne _081EE842
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	b _081EE850
_081EE842:
	movs r1, #0x30
	add ip, r1
	adds r4, #0x30
	adds r2, #1
	cmp r2, #0xb
	ble _081EE81A
	movs r0, #0
_081EE850:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
