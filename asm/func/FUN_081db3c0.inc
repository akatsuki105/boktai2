	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0x63
	ble _081DB410
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xcc
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc4
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x60
	adds r1, r5, r3
	movs r0, #0xbc
	strh r0, [r1]
	ldr r1, _081DB40C @ =0x00000222
	adds r0, r5, r1
	strh r2, [r0]
	subs r3, #0x18
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081DB440
	.align 2, 0
_081DB40C: .4byte 0x00000222
_081DB410:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc8
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc0
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x48
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
_081DB440:
	str r0, [r2]
	movs r2, #0
	cmp r4, #0x63
	ble _081DB450
_081DB448:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081DB448
_081DB450:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #9
	ble _081DB472
_081DB46A:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081DB46A
_081DB472:
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #0
	ble _081DB494
_081DB48C:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081DB48C
_081DB494:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
