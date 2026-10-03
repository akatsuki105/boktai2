	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B73E
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B73E
	ldr r1, [r4, #0x2c]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x30]
	movs r1, #0xb
	bl TextPanel_SetMessage
_0804B73E:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3c
	bne _0804B76A
	bl Save_WriteSystemData
	movs r2, #0
	strb r0, [r4, #0x1f]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne _0804B75E
	movs r0, #6
	strb r0, [r4, #0x18]
	strb r1, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B75E:
	movs r0, #7
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B76A:
	adds r0, #1
	str r0, [r4, #0x24]
_0804B76E:
	pop {r4}
	pop {r0}
	bx r0
