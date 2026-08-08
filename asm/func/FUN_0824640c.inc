	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _0824644C @ =0x08DBD800
_08246418:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _08246436
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_08246436:
	adds r5, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r4, r4, r0
	cmp r5, #7
	ble _08246418
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824644C: .4byte 0x08DBD800
