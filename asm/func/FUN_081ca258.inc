	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _081CA278 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA27C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA27E
	.align 2, 0
_081CA278: .4byte 0x0000046D
_081CA27C:
	movs r0, #0
_081CA27E:
	cmp r0, #0
	beq _081CA284
	b _081CA3A2
_081CA284:
	movs r2, #4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081CA29A
	movs r0, #1
	b _081CA29C
_081CA29A:
	movs r0, #0
_081CA29C:
	cmp r0, #0
	bne _081CA2A2
	b _081CA39A
_081CA2A2:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _081CA2E8 @ =0x000006BC
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _081CA2F0
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA2EC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bge _081CA376
	b _081CA384
	.align 2, 0
_081CA2E8: .4byte 0x000006BC
_081CA2EC: .4byte 0x00000484
_081CA2F0:
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r1, _081CA33C @ =0x000006D7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _081CA344
	ldrb r1, [r4, #5]
	adds r0, r4, #0
	bl DogLink_PickWalkDest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CA3A2
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA340 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _081CA3A2
	.align 2, 0
_081CA33C: .4byte 0x000006D7
_081CA340: .4byte 0x00000484
_081CA344:
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CA37C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA380 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _081CA384
_081CA376:
	asrs r0, r0, #5
	b _081CA38A
	.align 2, 0
_081CA37C: .4byte 0x00000469
_081CA380: .4byte 0x00000484
_081CA384:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081CA38A:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _081CA3A2
_081CA39A:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
_081CA3A2:
	pop {r4, r5}
	pop {r0}
	bx r0
