	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x24
	movs r5, #0xb3
	lsls r5, r5, #2
_08245C5E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08245C6E
	str r2, [r4]
	adds r0, r3, #0
	b _08245C78
_08245C6E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _08245C5E
	movs r0, #0
_08245C78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
