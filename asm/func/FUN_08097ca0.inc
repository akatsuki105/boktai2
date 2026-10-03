	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08097CE4
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	cmp r2, #7
	bgt _08097CC8
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x10
	b _08097D1A
_08097CC8:
	cmp r2, #0xb
	bgt _08097CD8
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x18
	b _08097D1A
_08097CD8:
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08097D1A
_08097CE4:
	cmp r2, #0x10
	bne _08097CF0
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08097D1A
_08097CF0:
	cmp r2, #0x11
	bne _08097CFC
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x4c
	b _08097D1A
_08097CFC:
	cmp r2, #0x12
	bne _08097D08
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x68
	b _08097D1A
_08097D08:
	cmp r2, #0x13
	bne _08097D14
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x68
	b _08097D1A
_08097D14:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08097D1A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0
