	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080738C8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _080738CC
	cmp r5, #1
	beq _08073974
	b _080739D2
	.align 2, 0
_080738C8: .4byte 0x0000037D
_080738CC:
	ldr r2, _08073900 @ =0x0000037E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08073924
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807390C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08073904 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08073908 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807391A
	.align 2, 0
_08073900: .4byte 0x0000037E
_08073904: .4byte 0x000002E6
_08073908: .4byte 0x000002E7
_0807390C:
	lsrs r0, r1, #0x19
	ldr r2, _0807394C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _08073950 @ =0x000002E7
	adds r0, r4, r1
	strb r5, [r0]
_0807391A:
	ldr r2, _08073954 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08073924:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08073958 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _0807395C
	subs r0, #0x1e
	strh r0, [r1]
	b _080739D2
	.align 2, 0
_0807394C: .4byte 0x000002E6
_08073950: .4byte 0x000002E7
_08073954: .4byte 0x0000037E
_08073958: .4byte 0x000003F6
_0807395C:
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _080739D2
_08073974:
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
	beq _080739D2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r2, [r0]
	cmp r2, #4
	bls _080739B8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080739B0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _080739B4 @ =0x000002E7
	adds r0, r4, r1
	strb r5, [r0]
	b _080739C6
	.align 2, 0
_080739B0: .4byte 0x000002E6
_080739B4: .4byte 0x000002E7
_080739B8:
	ldr r1, _080739D8 @ =0x000002E6
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080739DC @ =0x000002E7
	adds r0, r4, r2
	strb r1, [r0]
_080739C6:
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080739D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080739D8: .4byte 0x000002E6
_080739DC: .4byte 0x000002E7
