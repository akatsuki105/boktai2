	push {lr}
	ldrb r3, [r0, #0xc]
	adds r2, r0, #0
	adds r2, #0xd
	ldrb r0, [r0, #9]
	cmp r0, #1
	ble _08238218
	subs r1, r0, #1
_0823820C:
	ldrb r0, [r2]
	eors r3, r0
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bne _0823820C
_08238218:
	cmp r3, #0
	bne _08238220
	movs r0, #0
	b _08238224
_08238220:
	movs r0, #1
	rsbs r0, r0, #0
_08238224:
	pop {r1}
	bx r1
