	push {r4, lr}
	ldr r2, _0820FFD8 @ =0x03003584
	ldr r3, [r2]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r3, r3, r2
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r3, r3, r2
	ldrh r2, [r3]
	ldr r4, _0820FFDC @ =0x00000D72
	adds r1, r0, r4
	strh r2, [r1]
	adds r3, #2
	ldrh r2, [r3]
	adds r4, #2
	adds r1, r0, r4
	strh r2, [r1]
	ldrh r2, [r3, #2]
	ldr r3, _0820FFE0 @ =0x00000D82
	adds r1, r0, r3
	strh r2, [r1]
	subs r4, #0x74
	adds r1, r0, r4
	ldr r2, _0820FFE4 @ =0x00000D68
	adds r0, r0, r2
	str r0, [r1, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820FFD8: .4byte 0x03003584
_0820FFDC: .4byte 0x00000D72
_0820FFE0: .4byte 0x00000D82
_0820FFE4: .4byte 0x00000D68
