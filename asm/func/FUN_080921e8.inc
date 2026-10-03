	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _0809220C
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08092236
_0809220C:
	cmp r2, #0x15
	bne _08092218
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08092236
_08092218:
	cmp r2, #0x14
	bne _08092224
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08092236
_08092224:
	cmp r2, #0x10
	bne _08092230
	movs r0, #0x1c
	strh r0, [r3]
	movs r0, #0x58
	b _08092236
_08092230:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08092236:
	strh r0, [r3, #2]
	pop {r0}
	bx r0
