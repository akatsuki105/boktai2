	adds r2, r0, #0
	ldr r0, _08198890 @ =0x00000185
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _08198894 @ =FUN_08198898
	str r0, [r1]
	ldrh r1, [r2, #0x1c]
	subs r3, #0x38
	adds r0, r2, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x1e]
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	ldrh r1, [r2, #0x20]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	bx lr
	.align 2, 0
_08198890: .4byte 0x00000185
_08198894: .4byte FUN_08198898
