	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082028F8 @ =0x000006DB
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _08202908
	ldr r1, _082028FC @ =0x000006D4
	adds r2, r4, r1
	ldr r1, _08202900 @ =0x085AE7F8
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r2, [r3]
	ldr r1, _08202904 @ =0x000006DC
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	strb r1, [r3]
	str r1, [r4, #0x18]
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0820290A
	.align 2, 0
_082028F8: .4byte 0x000006DB
_082028FC: .4byte 0x000006D4
_08202900: .4byte 0x085AE7F8
_08202904: .4byte 0x000006DC
_08202908:
	movs r0, #0
_0820290A:
	pop {r4}
	pop {r1}
	bx r1
