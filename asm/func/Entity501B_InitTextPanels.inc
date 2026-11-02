	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #2
	movs r1, #5
	movs r2, #0x1a
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x1a
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DFF4A:
	lsls r0, r5, #2
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	adds r5, #1
	cmp r5, #1
	ble _081DFF4A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
