	movs r1, #1
	strb r1, [r0, #0x18]
	ldr r1, _08241F58 @ =FUN_08241cf4
	str r1, [r0, #0x2c]
	movs r1, #0
	strb r1, [r0, #0x19]
	strh r1, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r2, _08241F5C @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x94
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08241F60 @ =0x03004870
	ldrh r1, [r1]
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08241F64 @ =0x00000942
	adds r0, r0, r1
	ldr r1, _08241F68 @ =0x03004874
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_08241F58: .4byte FUN_08241cf4
_08241F5C: .4byte 0x030046A0
_08241F60: .4byte 0x03004870
_08241F64: .4byte 0x00000942
_08241F68: .4byte 0x03004874
