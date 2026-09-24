	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	adds r2, r1, #0
	adds r2, #0xa0
	ldr r0, [r2]
	cmp r0, #0
	beq _081D8092
	movs r5, #0
	adds r6, r2, #0
	adds r7, r1, #0
	adds r7, #0xa4
	ldr r0, _081D8018 @ =0x085AE118
	mov r8, r0
	adds r4, r3, #0
_081D8008:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D801C
	movs r0, #1
	b _081D801E
	.align 2, 0
_081D8018: .4byte 0x085AE118
_081D801C:
	movs r0, #0
_081D801E:
	cmp r0, #0
	beq _081D8086
	ldr r0, [r4]
	movs r1, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8038
	movs r0, #1
	b _081D803A
_081D8038:
	movs r0, #0
_081D803A:
	cmp r0, #0
	beq _081D8072
	ldr r0, [r4]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, _081D805C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D8060
	movs r0, #1
	b _081D8062
	.align 2, 0
_081D805C: .4byte 0x030046A0
_081D8060:
	movs r0, #0
_081D8062:
	cmp r0, #0
	bne _081D8072
	ldr r0, [r4]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _081D8086
_081D8072:
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	bl _call_via_r1
_081D8086:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x1f
	ble _081D8008
	movs r0, #0xff
	strb r0, [r7]
_081D8092:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
