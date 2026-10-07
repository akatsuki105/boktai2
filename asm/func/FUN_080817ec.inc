	movs r1, #1
	str r1, [r0, #0x1c]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r0, r1
	ldr r1, _08081824 @ =FUN_08084330
	str r1, [r2]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _08081828 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _0808182C @ =0x03002B68
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r0, #0x24]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08081824: .4byte FUN_08084330
_08081828: .4byte 0x0000037D
_0808182C: .4byte 0x03002B68
