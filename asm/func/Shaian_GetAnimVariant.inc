	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0817CE3C
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0817CE40
_0817CE3C:
	str r1, [r3]
	movs r0, #0
_0817CE40:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
