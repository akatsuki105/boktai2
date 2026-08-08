	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	ldr r0, _080785B8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	beq _0807867A
	ldr r0, _080785BC @ =0x000009C3
	cmp r1, r0
	bgt _080785C0
	movs r0, #0xf9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	b _080785CA
	.align 2, 0
_080785B8: .4byte 0x030046A0
_080785BC: .4byte 0x000009C3
_080785C0:
	movs r2, #0xf9
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #2
_080785CA:
	strh r0, [r1]
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xf
	bls _0807867A
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0807861C
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _08078614 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08078618 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _08078652
	.align 2, 0
_08078614: .4byte 0xFFFF0000
_08078618: .4byte 0x0000FFFF
_0807861C:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r3, _08078684 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08078688 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x20
	orrs r0, r2
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_08078652:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r4, #0
	str r4, [sp]
	movs r1, #6
	str r1, [sp, #4]
	movs r1, #3
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	movs r1, #0xf9
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
_0807867A:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08078684: .4byte 0x0000FFFF
_08078688: .4byte 0xFFFF0000
