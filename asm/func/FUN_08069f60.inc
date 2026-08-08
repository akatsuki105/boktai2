	push {r4, lr}
	adds r4, r0, #0
	movs r1, #8
	bl FUN_08060c40
	ldr r1, _08069F7C @ =0x0000037D
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _08069F80
	cmp r3, #1
	beq _0806A01E
	b _0806A04A
	.align 2, 0
_08069F7C: .4byte 0x0000037D
_08069F80:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x2c
	beq _08069FD2
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08069FC4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08069FBC @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08069FC0 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08069FD2
	.align 2, 0
_08069FBC: .4byte 0x000002E6
_08069FC0: .4byte 0x000002E7
_08069FC4:
	lsrs r0, r1, #0x19
	ldr r2, _0806A010 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0806A014 @ =0x000002E7
	adds r0, r4, r1
	strb r3, [r0]
_08069FD2:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _0806A018
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _0806A04A
	.align 2, 0
_0806A010: .4byte 0x000002E6
_0806A014: .4byte 0x000002E7
_0806A018:
	subs r0, #0x1e
	strh r0, [r1]
	b _0806A04A
_0806A01E:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x13
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806A04A
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806A04A:
	pop {r4}
	pop {r0}
	bx r0
