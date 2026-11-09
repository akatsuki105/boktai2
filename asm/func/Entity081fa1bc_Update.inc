	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4, #0x18]
	adds r3, r4, #0
	adds r3, #0x44
	ldrh r5, [r3]
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r1, #0x96
	lsls r1, r1, #1
	cmp r2, r1
	ble _081FA262
	bl KillEntity
	b _081FA266
_081FA262:
	adds r1, r5, #1
	strh r1, [r3]
_081FA266:
	pop {r4, r5}
	pop {r1}
	bx r1
