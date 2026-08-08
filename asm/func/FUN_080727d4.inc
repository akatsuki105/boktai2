	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08072804 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _08072860
	ldr r1, _08072808 @ =0x000004A9
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrb r2, [r3]
	adds r0, r2, #0
	subs r0, #8
	subs r1, r1, r0
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0807280C
	adds r0, r2, #7
	b _0807280E
	.align 2, 0
_08072804: .4byte 0x0000037E
_08072808: .4byte 0x000004A9
_0807280C:
	adds r0, r2, #1
_0807280E:
	movs r1, #7
	ands r0, r1
	strb r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _0807283C
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08072834 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08072838 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807284A
	.align 2, 0
_08072834: .4byte 0x000002E6
_08072838: .4byte 0x000002E7
_0807283C:
	ldr r1, _08072854 @ =0x000002E6
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08072858 @ =0x000002E7
	adds r0, r4, r2
	strb r1, [r0]
_0807284A:
	ldr r0, _0807285C @ =0x0000037E
	adds r1, r4, r0
	movs r0, #0
	b _08072862
	.align 2, 0
_08072854: .4byte 0x000002E6
_08072858: .4byte 0x000002E7
_0807285C: .4byte 0x0000037E
_08072860:
	adds r0, #1
_08072862:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r2, _080728A4 @ =0x000004A9
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0807289E
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_0807289E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080728A4: .4byte 0x000004A9
