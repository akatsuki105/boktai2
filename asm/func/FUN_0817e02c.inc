	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_0817dfcc
	cmp r0, #0
	bge _0817E044
	b _0817E198
_0817E044:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r2, #0x8b
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E0B4
	ldr r3, _0817E0A0 @ =0x000007A4
	adds r0, r5, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E0B4
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0817E0A4 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E0A8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #6
	ldr r0, _0817E0AC @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E0B0 @ =0xFFFFF3FF
	b _0817E17C
	.align 2, 0
_0817E0A0: .4byte 0x000007A4
_0817E0A4: .4byte 0x00000469
_0817E0A8: .4byte 0x00000484
_0817E0AC: .4byte 0x00000898
_0817E0B0: .4byte 0xFFFFF3FF
_0817E0B4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0817E110 @ =0x000008B2
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E124
	ldr r1, _0817E114 @ =0x000007A5
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E124
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E118 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #6
	ldr r0, _0817E11C @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E120 @ =0xFFFFF5FF
	b _0817E17C
	.align 2, 0
_0817E110: .4byte 0x000008B2
_0817E114: .4byte 0x000007A5
_0817E118: .4byte 0x00000484
_0817E11C: .4byte 0x00000898
_0817E120: .4byte 0xFFFFF5FF
_0817E124:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0817E184 @ =0x000008B4
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _0817E198
	ldr r1, _0817E188 @ =0x000007A6
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0817E198
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0817E18C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #6
	ldr r0, _0817E190 @ =0x00000898
	adds r2, r5, r0
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _0817E194 @ =0xFFFFF9FF
_0817E17C:
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	b _0817E19A
	.align 2, 0
_0817E184: .4byte 0x000008B4
_0817E188: .4byte 0x000007A6
_0817E18C: .4byte 0x00000484
_0817E190: .4byte 0x00000898
_0817E194: .4byte 0xFFFFF9FF
_0817E198:
	movs r0, #0
_0817E19A:
	pop {r4, r5}
	pop {r1}
	bx r1
