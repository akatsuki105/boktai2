	ldr r1, _081300E4 @ =0x00000634
	adds r2, r0, r1
	ldr r1, _081300E8 @ =0x085AD6BC
	str r1, [r2]
	ldr r1, _081300EC @ =0x00000644
	adds r0, r0, r1
	ldr r1, _081300F0 @ =0x085AD700
	str r1, [r0]
	bx lr
	.align 2, 0
_081300E4: .4byte 0x00000634
_081300E8: .4byte 0x085AD6BC
_081300EC: .4byte 0x00000644
_081300F0: .4byte 0x085AD700
