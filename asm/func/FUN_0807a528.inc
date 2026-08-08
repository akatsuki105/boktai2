	push {r4, r5, r6, lr}
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r4, r0, r3
	movs r5, #0
	movs r3, #8
	strb r3, [r4]
	ldr r4, _0807A564 @ =0x0000037E
	adds r3, r0, r4
	movs r4, #0
	strh r5, [r3]
	ldr r6, _0807A568 @ =0x0000037D
	adds r3, r0, r6
	strb r4, [r3]
	ldr r4, _0807A56C @ =0x000003F6
	adds r3, r0, r4
	strh r5, [r3]
	adds r6, #0x33
	adds r5, r0, r6
	ldr r3, [r1]
	ldr r4, [r1, #4]
	str r3, [r5]
	str r4, [r5, #4]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A564: .4byte 0x0000037E
_0807A568: .4byte 0x0000037D
_0807A56C: .4byte 0x000003F6
