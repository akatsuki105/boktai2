	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r6, r4, #0
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081FF626
	ldr r2, _081FF604 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r5, _081FF608 @ =0x000003FF
	ands r1, r5
	str r1, [r2]
	lsls r0, r1, #1
	ldr r3, _081FF60C @ =0x0203B400
	adds r0, r0, r3
	movs r3, #0xff
	ldrb r0, [r0]
	cmp r0, #0xef
	bgt _081FF610
	adds r0, r4, #0
	adds r0, #0x50
	bl FUN_081fae7c
	b _081FF626
	.align 2, 0
_081FF604: .4byte 0x030046B8
_081FF608: .4byte 0x000003FF
_081FF60C: .4byte 0x0203B400
_081FF610:
	adds r0, r1, #1
	ands r0, r5
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FF654 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r3
	adds r0, r4, #0
	bl FUN_081fad7c
_081FF626:
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081FF654: .4byte 0x0203B400
