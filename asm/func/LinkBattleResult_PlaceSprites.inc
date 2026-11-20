	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r3, r7, r1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r5, #0xd8
	adds r1, r7, #0
	movs r6, #3
_081DCAC0:
	strh r5, [r1, #0x38]
	strh r5, [r2, #0x38]
	strh r5, [r3, #0x38]
	strh r5, [r4]
	movs r0, #0x20
	strh r0, [r1, #0x3a]
	movs r0, #0x40
	strh r0, [r2, #0x3a]
	movs r0, #0x60
	strh r0, [r3, #0x3a]
	movs r0, #0x80
	strh r0, [r4, #2]
	adds r4, #0x60
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #8
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081DCAC0
	ldr r1, _081DCB44 @ =0x00000859
	adds r0, r7, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #3
	bgt _081DCB2C
	movs r3, #1
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r1, #0xe0
	adds r1, r1, r7
	adds r0, #0x20
	adds r2, r0, r7
	movs r4, #0xc0
	lsls r4, r4, #1
_081DCB0A:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r2, #0x60]
	orrs r0, r3
	str r0, [r2, #0x60]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r1, #0x60]
	orrs r0, r3
	str r0, [r1, #0x60]
	adds r1, r1, r4
	adds r2, r2, r4
	adds r6, #1
	cmp r6, #3
	ble _081DCB0A
_081DCB2C:
	movs r0, #0xc7
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081DCB48 @ =0x0000FFF8
	strh r0, [r1]
	ldr r0, _081DCB4C @ =0x0000063A
	adds r1, r7, r0
	ldr r0, _081DCB50 @ =0x0000FFC8
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCB44: .4byte 0x00000859
_081DCB48: .4byte 0x0000FFF8
_081DCB4C: .4byte 0x0000063A
_081DCB50: .4byte 0x0000FFC8
