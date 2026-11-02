	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_081E9F38:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E9F48
	movs r0, #1
	b _081E9F4A
_081E9F48:
	movs r0, #0
_081E9F4A:
	cmp r0, #0
	bne _081E9F64
	movs r0, #0x87
	lsls r0, r0, #2
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0xb]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081E9F70
_081E9F64:
	movs r0, #0xc
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _081E9F38
	movs r0, #0
_081E9F70:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
