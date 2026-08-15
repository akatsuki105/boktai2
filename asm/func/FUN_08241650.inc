	ldr r0, _08241678 @ =gUnkSolarEntity
	movs r1, #0
	str r1, [r0]
	ldr r2, _0824167C @ =0x030046A0
	ldr r0, [r2]
	movs r3, #0x94
	lsls r3, r3, #4
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _08241680 @ =0x00000942
	adds r0, r0, r2
	strh r1, [r0]
	ldr r0, _08241684 @ =0x03004870
	strh r1, [r0]
	ldr r0, _08241688 @ =0x03004874
	strh r1, [r0]
	ldr r0, _0824168C @ =0x0300486C
	strh r1, [r0]
	bx lr
	.align 2, 0
_08241678: .4byte gUnkSolarEntity
_0824167C: .4byte 0x030046A0
_08241680: .4byte 0x00000942
_08241684: .4byte 0x03004870
_08241688: .4byte 0x03004874
_0824168C: .4byte 0x0300486C
