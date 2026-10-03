	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08096B14
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
	b _08096B3E
_08096B14:
	cmp r2, #0x15
	bne _08096B20
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08096B3E
_08096B20:
	cmp r2, #0x14
	bne _08096B2C
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08096B3E
_08096B2C:
	cmp r2, #0x10
	bne _08096B38
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08096B3E
_08096B38:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08096B3E:
	strh r0, [r3, #2]
	pop {r0}
	bx r0
