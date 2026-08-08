	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _0807A490 @ =0x000003BD
	adds r2, r5, r0
	strb r4, [r2]
	adds r4, #4
	movs r0, #7
	ands r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807A49C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807A494 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0807A498 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0807A4AA
	.align 2, 0
_0807A490: .4byte 0x000003BD
_0807A494: .4byte 0x000002E6
_0807A498: .4byte 0x000002E7
_0807A49C:
	lsrs r1, r1, #0x19
	ldr r2, _0807A4BC @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0807A4C0 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0807A4AA:
	strb r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A4BC: .4byte 0x000002E6
_0807A4C0: .4byte 0x000002E7
