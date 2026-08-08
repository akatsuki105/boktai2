	push {r4, r5, lr}
	ldr r0, _082247D8 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _082247A8
	ldr r0, _082247DC @ =0x0000BB34
	movs r1, #0
	bl FUN_08229c6c
	adds r4, r0, #0
	cmp r4, #0
	beq _0822485A
_082247A8:
	movs r0, #0x70
	movs r1, #0
	bl FUN_0823174c
	ldr r2, _082247E0 @ =0x00000F0C
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _082247EC
	bl fetch_082316e4
	ldr r2, _082247E4 @ =0x00000E8C
	adds r1, r4, r2
	strh r0, [r1]
	bl fetch_082316e4
	ldr r2, _082247E8 @ =0x00000E8E
	adds r1, r4, r2
	strh r0, [r1]
	b _082247F8
	.align 2, 0
_082247D8: .4byte 0x03000248
_082247DC: .4byte 0x0000BB34
_082247E0: .4byte 0x00000F0C
_082247E4: .4byte 0x00000E8C
_082247E8: .4byte 0x00000E8E
_082247EC:
	ldr r2, _08224860 @ =0x00000E8E
	adds r0, r4, r2
	strh r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_082247F8:
	ldr r0, _08224864 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08224868 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x90
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _0822484C
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _0822484C
	ldr r2, _0822486C @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _08224870 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08224874 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0822484C:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_0822485A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08224860: .4byte 0x00000E8E
_08224864: .4byte 0x00000F16
_08224868: .4byte 0x00000F18
_0822486C: .4byte 0x00000DEC
_08224870: .4byte 0x00000F42
_08224874: .4byte 0x00000DF2
