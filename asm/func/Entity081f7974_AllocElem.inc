	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	movs r5, #1
	mov r3, ip
	adds r3, #0x83
	mov r4, ip
	adds r4, #0x3c
_081F74B4:
	adds r0, r5, #0
	lsls r0, r2
	mov r6, ip
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F74C6
	movs r0, #1
	b _081F74C8
_081F74C6:
	movs r0, #0
_081F74C8:
	cmp r0, #0
	bne _081F74DC
	adds r0, r5, #0
	lsls r0, r2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #0x38]
	strb r2, [r3]
	adds r0, r4, #0
	b _081F74E8
_081F74DC:
	adds r3, #0x48
	adds r4, #0x48
	adds r2, #1
	cmp r2, #0xf
	ble _081F74B4
	movs r0, #0
_081F74E8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
