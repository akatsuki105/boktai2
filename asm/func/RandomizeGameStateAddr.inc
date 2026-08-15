	ldr r0, _08231C64 @ =0x0400010C
	ldrh r2, [r0]
	ldr r1, _08231C68 @ =gGameStateBuffer
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #3
	adds r1, r0, r1
	ldr r0, _08231C6C @ =0x030046A0
	str r1, [r0]
	ldr r2, _08231C70 @ =0x0300469C
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r0, r1, r3
	str r0, [r2]
	ldr r2, _08231C74 @ =0x03004698
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r1, r3
	str r0, [r2]
	ldr r2, _08231C78 @ =0x03004694
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r0, r1, r3
	str r0, [r2]
	ldr r0, _08231C7C @ =0x03004690
	movs r2, #0xf0
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_08231C64: .4byte 0x0400010C
_08231C68: .4byte gGameStateBuffer
_08231C6C: .4byte 0x030046A0
_08231C70: .4byte 0x0300469C
_08231C74: .4byte 0x03004698
_08231C78: .4byte 0x03004694
_08231C7C: .4byte 0x03004690
