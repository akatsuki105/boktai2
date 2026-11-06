	push {r4, r5, r6, r7, lr}
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r0, r1
	ldr r2, [r1, #0x1c]
	ldr r3, [r1, #0x20]
	movs r1, #0x88
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	movs r6, #5
_081F5B60:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r2, [r5]
	str r3, [r5, #4]
	adds r3, r1, #0
	adds r2, r0, #0
	adds r5, r5, r7
	adds r4, r4, r7
	subs r6, #1
	cmp r6, #0
	bge _081F5B60
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
