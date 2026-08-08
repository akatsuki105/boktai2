	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _082251AC
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _082251A8 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _082251AE
	.align 2, 0
_082251A8: .4byte 0x00000F14
_082251AC:
	movs r0, #0
_082251AE:
	cmp r0, #0
	beq _08225220
	ldr r3, _08225254 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08225258 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _0822525C @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x14
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _08225260 @ =0x00000D9C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #0xf
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	str r0, [r2]
	ldr r1, _08225264 @ =0x00000DA5
	adds r0, r6, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _08225268 @ =0x00000DA4
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _0822526C @ =0x00000DBA
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #0xa0
	strh r0, [r1]
	adds r2, #0xfa
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_08223984
	ldr r3, _08225270 @ =0x00000DC8
	adds r0, r6, r3
	ldr r1, _08225274 @ =0x00000117
	bl FUN_0822b20c
_08225220:
	ldr r0, _08225260 @ =0x00000D9C
	adds r5, r6, r0
	ldr r1, _08225258 @ =0x00000DE4
	adds r4, r6, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08225278
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08225280
	.align 2, 0
_08225254: .4byte 0x00000F15
_08225258: .4byte 0x00000DE4
_0822525C: .4byte 0x00000E34
_08225260: .4byte 0x00000D9C
_08225264: .4byte 0x00000DA5
_08225268: .4byte 0x00000DA4
_0822526C: .4byte 0x00000DBA
_08225270: .4byte 0x00000DC8
_08225274: .4byte 0x00000117
_08225278:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08225280:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082252A4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082252AC
_082252A4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082252AC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082252E4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0822532A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082252EE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082252E8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225304
	.align 2, 0
_082252E4: .4byte 0x0000FFFF
_082252E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225302
_082252EE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225302
	strh r1, [r4, #8]
	movs r2, #1
	b _08225304
_08225302:
	movs r2, #0
_08225304:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0822532C
	movs r0, #1
	strb r0, [r4, #7]
	b _0822532C
_0822532A:
	movs r2, #0
_0822532C:
	ldr r3, _082253B8 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	cmp r2, #0
	beq _082253B0
	ldr r1, _082253BC @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_08013698
	ldr r3, _082253C0 @ =0x00000F16
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldr r1, _082253C4 @ =0x00000F18
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bne _08225378
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08225378
	ldr r2, _082253C8 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _082253CC @ =0x00000F42
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _082253D0 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _082253D4 @ =0x00000F43
	adds r0, r6, r2
	strb r1, [r0]
_08225378:
	movs r0, #1
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	movs r4, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _082253D8 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _082253DC @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #0
	movs r3, #4
	bl FUN_08236fac
	ldr r3, _082253E0 @ =0x00000F0C
	adds r0, r6, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _082253B0
	str r4, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl FUN_082318ac
_082253B0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082253B8: .4byte 0x00000F14
_082253BC: .4byte 0x00000DF4
_082253C0: .4byte 0x00000F16
_082253C4: .4byte 0x00000F18
_082253C8: .4byte 0x00000DEC
_082253CC: .4byte 0x00000F42
_082253D0: .4byte 0x00000DF2
_082253D4: .4byte 0x00000F43
_082253D8: .4byte 0x00000DE4
_082253DC: .4byte 0x00000E34
_082253E0: .4byte 0x00000F0C
