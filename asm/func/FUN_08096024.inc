	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809605C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809606C
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _08096060 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08096064 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	ldr r1, _08096068 @ =weapon_08095d4c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080960A4
	.align 2, 0
_0809605C: .4byte 0x030044E0
_08096060: .4byte 0x00001464
_08096064: .4byte 0x00003AEB
_08096068: .4byte weapon_08095d4c
_0809606C:
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080960A4
	ldr r0, _080960B8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080960BC @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080960C0 @ =FUN_080962b0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_080960A4:
	ldr r1, _080960C4 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080960B8: .4byte 0x0000144C
_080960BC: .4byte 0x0000204C
_080960C0: .4byte FUN_080962b0
_080960C4: .4byte 0x00001444
