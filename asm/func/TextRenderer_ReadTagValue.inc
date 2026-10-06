	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0
	str r0, [r3, #0x2c]
	str r0, [r3, #0x30]
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	adds r6, r3, #0
	adds r6, #0x34
	cmp r0, #0
	beq _08048D2A
_08048CFC:
	ldrb r2, [r4]
	cmp r2, #0x3d
	bne _08048D08
	movs r0, #1
	str r0, [r3, #0x2c]
	b _08048D18
_08048D08:
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _08048D18
	ldr r1, [r3, #0x30]
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	str r1, [r3, #0x30]
_08048D18:
	adds r5, #1
	adds r4, #1
	cmp r5, #0x3f
	bgt _08048D2A
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	cmp r0, #0
	bne _08048CFC
_08048D2A:
	adds r0, r3, #0
	adds r0, #0x34
	ldr r1, [r3, #0x30]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
