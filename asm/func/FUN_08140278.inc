	push {r4, r5, lr}
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814030E
	ldr r0, _081402AC @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0814030E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081402B0
	movs r0, #1
	b _081402B2
	.align 2, 0
_081402AC: .4byte 0x03002BE0
_081402B0:
	movs r0, #0
_081402B2:
	cmp r0, #0
	beq _0814030E
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _08140314 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08140318 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0814030E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08140314: .4byte 0x0000046A
_08140318: .4byte 0x00000484
