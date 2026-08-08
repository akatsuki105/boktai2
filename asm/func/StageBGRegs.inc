	push {r4, lr}
	ldr r3, _0822B8A8 @ =0x03003EC0
	ldr r2, _0822B8AC @ =0x03003ED0
	ldrh r1, [r2, #0x20]
	movs r4, #0xff
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r1, [r2, #0x22]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #2]
	adds r0, r2, #0
	adds r0, #0x50
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x52
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #6]
	ldr r0, _0822B8B0 @ =0x03003E8C
	ldrh r0, [r0]
	cmp r0, #0
	bne _0822B8B4
	adds r0, r2, #0
	adds r0, #0x80
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #8]
	adds r0, r2, #0
	adds r0, #0x82
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #0xa]
	adds r0, r2, #0
	adds r0, #0xb0
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #0xc]
	adds r0, r2, #0
	adds r0, #0xb2
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3, #0xe]
	b _0822B8D6
	.align 2, 0
_0822B8A8: .4byte 0x03003EC0
_0822B8AC: .4byte 0x03003ED0
_0822B8B0: .4byte 0x03003E8C
_0822B8B4:
	ldr r2, _0822B8DC @ =0x03003E90
	ldr r1, _0822B8E0 @ =0x03003E70
	ldrh r0, [r1]
	strh r0, [r2]
	ldrh r0, [r1, #2]
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	strh r0, [r2, #4]
	ldrh r0, [r1, #6]
	strh r0, [r2, #6]
	ldr r1, _0822B8E4 @ =0x03003EB8
	ldr r0, _0822B8E8 @ =0x03003E98
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0822B8EC @ =0x03003EA0
	ldr r0, [r0]
	str r0, [r1, #4]
_0822B8D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822B8DC: .4byte 0x03003E90
_0822B8E0: .4byte 0x03003E70
_0822B8E4: .4byte 0x03003EB8
_0822B8E8: .4byte 0x03003E98
_0822B8EC: .4byte 0x03003EA0
