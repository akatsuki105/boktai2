	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080986D8 @ =0x000009EE
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080986EC
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080986B6
	ldr r2, _080986DC @ =0x000020C4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080986E0 @ =0x000020C6
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080986B6:
	ldr r1, _080986E4 @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r3]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _080986E8 @ =0x000020D8
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _0809871C
	.align 2, 0
_080986D8: .4byte 0x000009EE
_080986DC: .4byte 0x000020C4
_080986E0: .4byte 0x000020C6
_080986E4: .4byte 0x000020AC
_080986E8: .4byte 0x000020D8
_080986EC:
	ldr r1, _08098724 @ =0x000020D8
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _08098728 @ =0x000020D9
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0809872C @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	subs r1, #0x43
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08098730 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x10
	bl UnregisterMagic
	adds r0, r4, #0
	bl FUN_0809820c
_0809871C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098724: .4byte 0x000020D8
_08098728: .4byte 0x000020D9
_0809872C: .4byte 0x000020AC
_08098730: .4byte 0x00003AEB
