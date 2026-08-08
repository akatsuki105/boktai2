	push {r4, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r1, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r2, r3, #0x18
	cmp r0, #0
	bne _080E53A2
	adds r0, r4, #0
	bl FUN_080e510c
_080E53A2:
	pop {r4}
	pop {r0}
	bx r0
