	push {r4, r5, r6, r7, lr}
	ldr r0, _0822B810 @ =0x03003E78
	movs r4, #0
	strh r4, [r0]
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r3, _0822B814 @ =0x04000008
	ldrh r2, [r3]
	ldr r1, _0822B818 @ =0x0000FFBF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r3, #2
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r2, _0822B81C @ =0x0400000E
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldr r0, _0822B820 @ =0x04000050
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #2
	strh r4, [r0]
	movs r6, #0
	movs r5, #0
	ldr r1, _0822B824 @ =0x040000D4
	ldr r4, _0822B828 @ =0x03003E80
	ldr r0, _0822B82C @ =0x03003E60
	mov ip, r0
	ldr r7, _0822B830 @ =0x085B0110
	movs r3, #0xc0
	lsls r3, r3, #0x13
	ldr r2, _0822B834 @ =0x03003EA8
_0822B7E0:
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	stm r0!, {r5}
	strh r5, [r4]
	strh r5, [r2]
	str r7, [r1]
	str r3, [r1, #4]
	ldr r0, _0822B838 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r4, #2
	movs r0, #0x80
	lsls r0, r0, #7
	adds r3, r3, r0
	adds r2, #2
	adds r6, #1
	cmp r6, #3
	ble _0822B7E0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822B810: .4byte 0x03003E78
_0822B814: .4byte 0x04000008
_0822B818: .4byte 0x0000FFBF
_0822B81C: .4byte 0x0400000E
_0822B820: .4byte 0x04000050
_0822B824: .4byte 0x040000D4
_0822B828: .4byte 0x03003E80
_0822B82C: .4byte 0x03003E60
_0822B830: .4byte 0x085B0110
_0822B834: .4byte 0x03003EA8
_0822B838: .4byte 0x84000008
