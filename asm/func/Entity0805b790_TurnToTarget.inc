	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x7c
	ldr r2, [r4, #0xc]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r1, [r4, #3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r3, r0, #0x18
	ldrb r1, [r4, #8]
	rsbs r0, r1, #0
	cmp r3, r0
	bge _0805B35A
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0805B360
_0805B35A:
	cmp r3, r1
	ble _0805B360
	adds r2, r1, #0
_0805B360:
	ldrb r0, [r4, #3]
	adds r0, r0, r2
	strb r0, [r4, #3]
	pop {r4, r5}
	pop {r0}
	bx r0
