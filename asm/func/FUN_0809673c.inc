	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809678C
	movs r3, #0
	ldr r6, _08096780 @ =0x030046A0
	ldr r0, _08096784 @ =0x00003FE0
	adds r4, r5, r0
	ldr r0, [r6]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r0, r1
_08096764:
	adds r1, r4, r3
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08096764
	ldr r0, [r6]
	adds r0, #0x5c
	ldrh r1, [r0]
	ldr r2, _08096788 @ =0x00003FDC
	adds r0, r5, r2
	strb r1, [r0]
	b _080967B0
	.align 2, 0
_08096780: .4byte 0x030046A0
_08096784: .4byte 0x00003FE0
_08096788: .4byte 0x00003FDC
_0809678C:
	ldr r0, _080967B8 @ =0x00003FE0
	adds r1, r5, r0
	movs r0, #0xa
	strb r0, [r1]
	movs r3, #1
	adds r2, r1, #0
	movs r4, #0xff
_0809679A:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _0809679A
	ldr r2, _080967BC @ =0x00003FDC
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_080967B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080967B8: .4byte 0x00003FE0
_080967BC: .4byte 0x00003FDC
