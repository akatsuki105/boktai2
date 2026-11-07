	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0xa0
	lsls r4, r4, #1
	cmp r0, r4
	ble _081404E8
	ldr r0, _081404E4 @ =0x00000667
	adds r1, r3, r0
	movs r0, #0xff
	b _081404F4
	.align 2, 0
_081404E4: .4byte 0x00000667
_081404E8:
	ldr r4, _08140518 @ =0xFFFFFEC0
	cmp r0, r4
	bge _081404F8
	ldr r0, _0814051C @ =0x00000667
	adds r1, r3, r0
	movs r0, #1
_081404F4:
	strb r0, [r1]
	strh r4, [r2]
_081404F8:
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r2, r3, r1
	subs r1, #1
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08140518: .4byte 0xFFFFFEC0
_0814051C: .4byte 0x00000667
