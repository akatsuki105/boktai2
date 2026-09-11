	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x74]
	cmp r1, #0
	beq _080221A4
	adds r4, r6, #0
	adds r4, #0x24
	movs r7, #0
_0802217C:
	ldr r5, [r1, #0x30]
	adds r0, r1, #6
	ldrb r2, [r4]
	adds r0, r0, r2
	strb r7, [r0]
	movs r3, #0
	adds r2, r1, #0
	adds r2, #8
_0802218C:
	lsls r1, r3, #2
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r2, r1
	str r7, [r1]
	adds r3, #1
	cmp r3, #3
	ble _0802218C
	adds r1, r5, #0
	cmp r1, #0
	bne _0802217C
_080221A4:
	adds r2, r6, #0
	adds r2, #0x24
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
