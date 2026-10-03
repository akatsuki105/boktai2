	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08095318
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
	b _08095366
_08095318:
	cmp r2, #0x15
	bne _08095324
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095324:
	cmp r2, #0x14
	bne _08095330
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08095366
_08095330:
	cmp r2, #0x10
	bne _0809533C
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08095366
_0809533C:
	cmp r2, #0x11
	bne _08095348
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x4c
	b _08095366
_08095348:
	cmp r2, #0x12
	bne _08095354
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095354:
	cmp r2, #0x13
	bne _08095360
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095360:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08095366:
	strh r0, [r3, #2]
	pop {r0}
	bx r0
