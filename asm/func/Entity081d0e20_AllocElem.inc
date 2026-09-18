	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r7, #1
_081CFC68:
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x68]
	ands r0, r1
	cmp r0, #0
	beq _081CFC78
	movs r0, #1
	b _081CFC7A
_081CFC78:
	movs r0, #0
_081CFC7A:
	cmp r0, #0
	bne _081CFCAA
	movs r0, #0xc0
	bl Malloc
	adds r4, r0, #0
	movs r1, #0xc0
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x68]
	orrs r0, r1
	str r0, [r5, #0x68]
	adds r0, r4, #0
	adds r0, #0xb4
	strh r6, [r0]
	lsls r1, r6, #2
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081CFCB2
_081CFCAA:
	adds r6, #1
	cmp r6, #0xb
	ble _081CFC68
	movs r0, #0
_081CFCB2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
