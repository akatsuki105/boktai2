	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x44]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #0xa]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	asrs r2, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0805A926
	movs r1, #0xfe
	b _0805A92C
_0805A926:
	cmp r2, #2
	ble _0805A92C
	movs r1, #2
_0805A92C:
	ldrb r0, [r4, #0xa]
	adds r0, r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0
