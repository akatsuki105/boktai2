	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08094490 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	ldr r2, _08094494 @ =0x00001C2C
	adds r1, r4, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08094498 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080944A8
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809449C @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080944A0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	ldr r1, _080944A4 @ =FUN_08094200
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _080944E0
	.align 2, 0
_08094490: .4byte 0x00001444
_08094494: .4byte 0x00001C2C
_08094498: .4byte 0x030044E0
_0809449C: .4byte 0x00001464
_080944A0: .4byte 0x00003AEB
_080944A4: .4byte FUN_08094200
_080944A8:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080944E0
	ldr r0, _080944E8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080944EC @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080944F0 @ =FUN_0809458c
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
_080944E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080944E8: .4byte 0x0000144C
_080944EC: .4byte 0x0000204C
_080944F0: .4byte FUN_0809458c
