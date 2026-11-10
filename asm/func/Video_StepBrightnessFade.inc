	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r5, #0
	cmp r1, #0
	beq _0821B230
	cmp r1, #1
	beq _0821B23E
	b _0821B24C
_0821B230:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, r2
	blt _0821B24C
	str r2, [r4, #4]
	b _0821B24A
_0821B23E:
	ldr r0, [r4, #4]
	subs r0, #1
	str r0, [r4, #4]
	cmp r0, #0
	bgt _0821B24C
	str r5, [r4, #4]
_0821B24A:
	movs r5, #1
_0821B24C:
	ldr r0, [r4, #4]
	lsls r0, r0, #0x18
	lsls r1, r2, #2
	bl Div
	str r0, [r4]
	ldr r1, _0821B27C @ =0x03004040
	ldrh r0, [r4, #2]
	str r0, [r1]
	ldr r1, _0821B280 @ =0x0300445C
	ldrh r0, [r4, #2]
	str r0, [r1]
	ldr r2, _0821B284 @ =0x03004454
	ldrh r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0821B288 @ =0x03004490
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0821B27C: .4byte 0x03004040
_0821B280: .4byte 0x0300445C
_0821B284: .4byte 0x03004454
_0821B288: .4byte 0x03004490
