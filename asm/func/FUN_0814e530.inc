	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0814E550 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E554
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E556
	.align 2, 0
_0814E550: .4byte 0x0000046D
_0814E554:
	movs r0, #0
_0814E556:
	cmp r0, #0
	beq _0814E55C
	b _0814E67A
_0814E55C:
	movs r2, #4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _0814E572
	movs r0, #1
	b _0814E574
_0814E572:
	movs r0, #0
_0814E574:
	cmp r0, #0
	bne _0814E57A
	b _0814E672
_0814E57A:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _0814E5C0 @ =0x000006BC
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0814E5C8
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
	ldr r2, _0814E5C4 @ =0x00000484
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
	bge _0814E64E
	b _0814E65C
	.align 2, 0
_0814E5C0: .4byte 0x000006BC
_0814E5C4: .4byte 0x00000484
_0814E5C8:
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r1, _0814E614 @ =0x000006D7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0814E61C
	ldrb r1, [r4, #5]
	adds r0, r4, #0
	bl FUN_0814b090
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814E67A
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
	ldr r2, _0814E618 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0814E67A
	.align 2, 0
_0814E614: .4byte 0x000006D7
_0814E618: .4byte 0x00000484
_0814E61C:
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0814E654 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E658 @ =0x00000484
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
	blt _0814E65C
_0814E64E:
	asrs r0, r0, #5
	b _0814E662
	.align 2, 0
_0814E654: .4byte 0x00000469
_0814E658: .4byte 0x00000484
_0814E65C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0814E662:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _0814E67A
_0814E672:
	adds r0, r4, #0
	movs r1, #1
	bl Enemy_PlayAnim
_0814E67A:
	pop {r4, r5}
	pop {r0}
	bx r0
