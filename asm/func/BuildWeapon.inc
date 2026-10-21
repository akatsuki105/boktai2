	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r5]
	strb r0, [r4]
	ldrh r0, [r5, #6]
	strh r0, [r4, #2]
	ldrh r0, [r5, #8]
	strb r0, [r4, #1]
	ldrb r0, [r5, #0xc]
	cmp r0, #0
	bne _08242A66
	movs r0, #0
	strb r0, [r4, #4]
	movs r2, #1
	adds r1, r4, #4
	movs r3, #0
_08242A5A:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _08242A5A
	b _08242A7C
_08242A66:
	movs r2, #0
	adds r6, r4, #4
	adds r3, r5, #0
	adds r3, #0xc
_08242A6E:
	adds r0, r6, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _08242A6E
_08242A7C:
	adds r3, r5, #0
	adds r1, r4, #0
	movs r2, #2
_08242A82:
	ldr r0, [r3, #0x18]
	str r0, [r1, #0x10]
	adds r3, #4
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _08242A82
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
