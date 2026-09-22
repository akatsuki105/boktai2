	push {r4, r5, lr}
	ldr r0, _08047874 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	bne _08047878
	movs r0, #0
	b _080478CC
	.align 2, 0
_08047874: .4byte 0x030000C4
_08047878:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _080478D4 @ =0x00000179
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrb r2, [r2]
	ldr r5, _080478D8 @ =0x0000017B
	adds r3, r4, r5
	ldrb r3, [r3]
	bl FUN_0822ea60
	ldr r2, _080478DC @ =TextBox_StateIdle
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r4, r3
	str r2, [r1]
	adds r5, #0x99
	adds r2, r4, r5
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	adds r2, r4, #0
	adds r2, #0x18
	movs r1, #0xff
	strb r1, [r2, #0x15]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r1, [r2, #8]
	orrs r1, r3
	str r1, [r2, #8]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r1, _080478E0 @ =0x0000FFFF
	strh r1, [r2]
_080478CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080478D4: .4byte 0x00000179
_080478D8: .4byte 0x0000017B
_080478DC: .4byte TextBox_StateIdle
_080478E0: .4byte 0x0000FFFF
