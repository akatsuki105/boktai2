	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B4A70 @ =0x030046A0
	ldr r2, [r0]
	ldr r0, _080B4A74 @ =0x0000082E
	adds r1, r4, r0
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x2e
	ldrsh r2, [r2, r1]
	cmp r0, #0
	bne _080B4A78
	movs r3, #0
	b _080B4A8A
	.align 2, 0
_080B4A70: .4byte 0x030046A0
_080B4A74: .4byte 0x0000082E
_080B4A78:
	subs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r3, r0, #1
_080B4A8A:
	movs r0, #0xf0
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080B4AB4 @ =0x0000079A
	adds r1, r4, r3
	ldr r0, _080B4AB8 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4AB4: .4byte 0x0000079A
_080B4AB8: .4byte 0x0000FFD8
