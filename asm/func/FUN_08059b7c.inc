	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x20
	movs r5, #0x82
	lsls r5, r5, #1
_08059B8E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08059B9E
	str r2, [r4]
	adds r0, r3, #0
	b _08059BA8
_08059B9E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _08059B8E
	movs r0, #0
_08059BA8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
