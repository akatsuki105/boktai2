	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	ldr r0, _08233334 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _0823330C
	b _08233422
_0823330C:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _08233330
	cmp r2, #0
	blt _08233330
	ldr r0, _08233338 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08233330
	ldr r0, _0823333C @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08233340
_08233330:
	movs r0, #0
	b _0823334A
	.align 2, 0
_08233334: .4byte 0x030046A4
_08233338: .4byte 0x030046A8
_0823333C: .4byte 0x030046AC
_08233340:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_0823334A:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823335E
	adds r2, r0, #4
	b _0823336A
_0823335E:
	ldr r0, _082333C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r2, r1, r0
_0823336A:
	ldrh r0, [r4, #6]
	cmp r0, r5
	beq _08233392
	strh r0, [r4, #4]
	ldrb r0, [r4, #0xb]
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
	ldrh r0, [r4, #0xe]
	strh r0, [r4, #0xc]
	strh r5, [r4, #6]
	ldrb r0, [r2]
	lsrs r0, r0, #4
	strb r0, [r4, #0xb]
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #9]
	ldrh r0, [r2, #2]
	strh r0, [r4, #0xe]
_08233392:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7]
	str r1, [r7, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082333BE
	cmp r1, #0
	blt _082333BE
	ldr r0, _082333C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082333BE
	ldr r0, _082333CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082333D0
_082333BE:
	movs r4, #0
	b _082333DE
	.align 2, 0
_082333C4: .4byte 0x030046A4
_082333C8: .4byte 0x030046A8
_082333CC: .4byte 0x030046AC
_082333D0:
	ldr r0, _082333F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082333DE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082333F4
	adds r0, #4
	b _08233400
	.align 2, 0
_082333F0: .4byte 0x030046A4
_082333F4:
	ldr r0, _08233414 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08233400:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08233418
	cmp r2, #2
	beq _0823341C
	b _08233420
	.align 2, 0
_08233414: .4byte 0x030046A4
_08233418:
	ldrb r0, [r6, #4]
	b _0823341E
_0823341C:
	ldrb r0, [r6]
_0823341E:
	subs r1, r1, r0
_08233420:
	strh r1, [r7, #2]
_08233422:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
