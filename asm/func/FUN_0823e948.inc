	push {r4, r5, r6, r7, lr}
	ldr r3, _0823E9BC @ =0x00000000
	ldr r2, _0823E9B8 @ =0x40E92B10
	bl __subdf3
	ldr r2, _0823E9C0 @ =0x3F4845C7
	ldr r3, _0823E9C4 @ =0x0994535F
	bl __adddf3
	ldr r2, _0823E9C8 @ =0x40E1D5A0
	ldr r3, _0823E9CC @ =0x00000000
	bl __divdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823E9D0 @ =0x3F8A9FBE
	ldr r3, _0823E9D4 @ =0x76C8B439
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0823E9D8 @ =0x40377075
	ldr r1, _0823E9DC @ =0xF6FD21FF
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823E9E0 @ =0x409E3800
	ldr r3, _0823E9E4 @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	bl __muldf3
	ldr r2, _0823E9E8 @ =0x406D6000
	ldr r3, _0823E9EC @ =0x00000000
	bl __adddf3
	ldr r2, _0823E9F0 @ =0x3F91DF46
	ldr r3, _0823E9F4 @ =0xA2529D34
	bl __muldf3
	bl fdlibm_cos
	ldr r2, _0823E9F8 @ =0x3F654C98
	ldr r3, _0823E9FC @ =0x5F06F694
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __adddf3
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823E9B8: .4byte 0x40E92B10
_0823E9BC: .4byte 0x00000000
_0823E9C0: .4byte 0x3F4845C7
_0823E9C4: .4byte 0x0994535F
_0823E9C8: .4byte 0x40E1D5A0
_0823E9CC: .4byte 0x00000000
_0823E9D0: .4byte 0x3F8A9FBE
_0823E9D4: .4byte 0x76C8B439
_0823E9D8: .4byte 0x40377075
_0823E9DC: .4byte 0xF6FD21FF
_0823E9E0: .4byte 0x409E3800
_0823E9E4: .4byte 0x00000000
_0823E9E8: .4byte 0x406D6000
_0823E9EC: .4byte 0x00000000
_0823E9F0: .4byte 0x3F91DF46
_0823E9F4: .4byte 0xA2529D34
_0823E9F8: .4byte 0x3F654C98
_0823E9FC: .4byte 0x5F06F694
