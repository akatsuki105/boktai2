	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r1, _0801C3EC @ =0x030046A0
	ldr r1, [r1]
	adds r5, r1, #0
	adds r5, #0x60
	movs r7, #0
	movs r6, #3
_0801C3B8:
	ldr r2, _0801C3F0 @ =0x00000C24
	adds r1, r7, r2
	mov r2, ip
	adds r4, r2, r1
	movs r1, #0
	ldrsh r3, [r5, r1]
	cmp r3, #0
	blt _0801C3F4
	movs r2, #3
	ands r2, r3
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x90
	strh r1, [r4, #0x20]
	asrs r2, r3, #2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x20
	strh r1, [r4, #0x22]
	ldr r1, [r4, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0801C3FA
	.align 2, 0
_0801C3EC: .4byte 0x030046A0
_0801C3F0: .4byte 0x00000C24
_0801C3F4:
	ldr r1, [r4, #8]
	movs r2, #1
	orrs r1, r2
_0801C3FA:
	str r1, [r4, #8]
	adds r5, #2
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _0801C3B8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
