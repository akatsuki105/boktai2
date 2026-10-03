	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08050d64
	movs r2, #0
	cmp r0, #0x3c
	bgt _080501DE
	movs r2, #2
	cmp r0, #0x19
	ble _080501DE
	movs r2, #1
_080501DE:
	adds r0, r5, #0
	adds r0, #0xec
	adds r4, r5, #0
	adds r4, #0xcc
	adds r2, #0xd4
	adds r1, r4, #0
	movs r3, #0
	bl MainSprite_SetPose
	bl FUN_08050d7c
	movs r2, #0
	adds r1, r4, #0
	cmp r0, #0x3c
	bgt _08050204
	movs r2, #2
	cmp r0, #0x19
	ble _08050204
	movs r2, #1
_08050204:
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0xd7
	movs r3, #0
	bl MainSprite_SetPose
	pop {r4, r5}
	pop {r0}
	bx r0
