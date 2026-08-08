	push {r4, r5, lr}
	adds r4, r0, #0
	bl ClearTilemapBuffer
	movs r3, #0
	ldr r2, _0822B6C4 @ =0x03003EA8
	ldr r1, _0822B6C8 @ =0x03003E80
	ldr r5, _0822B6CC @ =0x03003E60
	movs r0, #3
_0822B676:
	stm r5!, {r3}
	strh r3, [r1]
	strh r3, [r2]
	adds r2, #2
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _0822B676
	ldr r3, _0822B6D0 @ =0x03003E78
	movs r2, #0
	strh r2, [r3]
	ldr r0, _0822B6D4 @ =0x03003EB4
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r5, #0
	strh r1, [r0]
	ldr r0, _0822B6D8 @ =0x03003E9C
	strh r1, [r0]
	ldr r0, _0822B6DC @ =0x03003E50
	strh r2, [r0]
	ldr r0, _0822B6E0 @ =0x03003E70
	movs r1, #0
	adds r2, r5, #0
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	strh r2, [r0, #6]
	ldr r0, _0822B6E4 @ =0x03003E98
	str r1, [r0]
	ldr r0, _0822B6E8 @ =0x03003EA0
	str r1, [r0]
	ldr r0, _0822B6EC @ =0x03003E8C
	strh r4, [r0]
	cmp r4, #0
	beq _0822B6F0
	cmp r4, #1
	beq _0822B730
	b _0822B750
	.align 2, 0
_0822B6C4: .4byte 0x03003EA8
_0822B6C8: .4byte 0x03003E80
_0822B6CC: .4byte 0x03003E60
_0822B6D0: .4byte 0x03003E78
_0822B6D4: .4byte 0x03003EB4
_0822B6D8: .4byte 0x03003E9C
_0822B6DC: .4byte 0x03003E50
_0822B6E0: .4byte 0x03003E70
_0822B6E4: .4byte 0x03003E98
_0822B6E8: .4byte 0x03003EA0
_0822B6EC: .4byte 0x03003E8C
_0822B6F0:
	ldr r1, _0822B718 @ =0x04000008
	ldr r2, _0822B71C @ =0x00003F08
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r5, _0822B720 @ =0x00003E01
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0822B724 @ =0x00003D03
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r5, _0822B728 @ =0x00003C01
	adds r0, r5, #0
	strh r0, [r1]
	subs r1, #0xe
	ldr r2, _0822B72C @ =0x00007160
	b _0822B74C
	.align 2, 0
_0822B718: .4byte 0x04000008
_0822B71C: .4byte 0x00003F08
_0822B720: .4byte 0x00003E01
_0822B724: .4byte 0x00003D03
_0822B728: .4byte 0x00003C01
_0822B72C: .4byte 0x00007160
_0822B730:
	ldr r1, _0822B760 @ =0x04000008
	ldr r5, _0822B764 @ =0x00003F08
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0822B768 @ =0x00003E42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r5, _0822B76C @ =0x00009D81
	adds r0, r5, #0
	strh r0, [r1]
	subs r1, #0xc
	ldr r2, _0822B770 @ =0x00007161
_0822B74C:
	adds r0, r2, #0
	strh r0, [r1]
_0822B750:
	ldr r0, _0822B774 @ =0xFFFFF1FF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822B760: .4byte 0x04000008
_0822B764: .4byte 0x00003F08
_0822B768: .4byte 0x00003E42
_0822B76C: .4byte 0x00009D81
_0822B770: .4byte 0x00007161
_0822B774: .4byte 0xFFFFF1FF
