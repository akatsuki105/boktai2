	ldr r1, _080F36DC @ =0x0000062C
	adds r2, r0, r1
	ldr r1, _080F36E0 @ =0x085AD3D4
	str r1, [r2]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _080F36E4 @ =0x085AD3E4
	str r1, [r2]
	ldr r1, _080F36E8 @ =0x00000634
	adds r2, r0, r1
	ldr r1, _080F36EC @ =0x085AD3F0
	str r1, [r2]
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _080F36F0 @ =0x085AD42C
	str r1, [r2]
	ldr r1, _080F36F4 @ =0x0000063C
	adds r2, r0, r1
	ldr r1, _080F36F8 @ =0x085AD430
	str r1, [r2]
	movs r1, #0xc8
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _080F36FC @ =0x085AD434
	str r1, [r2]
	ldr r1, _080F3700 @ =0x00000644
	adds r2, r0, r1
	ldr r1, _080F3704 @ =0x085AD438
	str r1, [r2]
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _080F3708 @ =0x085AD444
	str r1, [r2]
	ldr r1, _080F370C @ =0x0000064C
	adds r2, r0, r1
	ldr r1, _080F3710 @ =0x085AD448
	str r1, [r2]
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _080F3714 @ =0x085AD460
	str r1, [r0]
	bx lr
	.align 2, 0
_080F36DC: .4byte 0x0000062C
_080F36E0: .4byte 0x085AD3D4
_080F36E4: .4byte 0x085AD3E4
_080F36E8: .4byte 0x00000634
_080F36EC: .4byte 0x085AD3F0
_080F36F0: .4byte 0x085AD42C
_080F36F4: .4byte 0x0000063C
_080F36F8: .4byte 0x085AD430
_080F36FC: .4byte 0x085AD434
_080F3700: .4byte 0x00000644
_080F3704: .4byte 0x085AD438
_080F3708: .4byte 0x085AD444
_080F370C: .4byte 0x0000064C
_080F3710: .4byte 0x085AD448
_080F3714: .4byte 0x085AD460
