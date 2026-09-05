	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FUN_08001a64
	ldr r1, _08001B00 @ =0x00000642
	adds r5, r7, r1
	ldrb r4, [r5]
	subs r6, r4, r0
	cmp r6, #0
	bge _08001AE6
	rsbs r6, r6, #0
_08001AE6:
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	bge _08001B04
	adds r1, r6, #0
	cmp r1, #8
	ble _08001AF8
	movs r1, #8
_08001AF8:
	ldrb r0, [r5]
	adds r0, r0, r1
	b _08001B24
	.align 2, 0
_08001B00: .4byte 0x00000642
_08001B04:
	ldrb r4, [r5]
	adds r0, r7, #0
	bl FUN_08001a64
	cmp r4, r0
	ble _08001B1E
	adds r1, r6, #0
	cmp r1, #8
	ble _08001B18
	movs r1, #8
_08001B18:
	ldrb r0, [r5]
	subs r0, r0, r1
	b _08001B24
_08001B1E:
	adds r0, r7, #0
	bl FUN_08001a64
_08001B24:
	strb r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
