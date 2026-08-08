	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08224FDC
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225010 @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
_08224FDC:
	ldr r0, _08225014 @ =0x00000D9C
	adds r3, r7, r0
	ldr r2, _08225018 @ =0x00000E38
	adds r1, r7, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08225076
	ldr r2, _0822501C @ =0x00000DEC
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08225024
	cmp r2, #1
	bge _0822504C
	cmp r2, #0
	beq _0822502C
	ldr r0, _08225020 @ =0x00000E3A
	adds r1, r7, r0
	b _0822506C
	.align 2, 0
_08225010: .4byte 0x00000F14
_08225014: .4byte 0x00000D9C
_08225018: .4byte 0x00000E38
_0822501C: .4byte 0x00000DEC
_08225020: .4byte 0x00000E3A
_08225024:
	ldr r0, _08225040 @ =0x00000E3A
	adds r1, r7, r0
	cmp r2, #3
	bne _0822506C
_0822502C:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08225044
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _0822506A
	.align 2, 0
_08225040: .4byte 0x00000E3A
_08225044:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _0822506A
_0822504C:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08225064
	ldr r2, _08225060 @ =0x00000E3A
	adds r1, r7, r2
	movs r0, #0xff
	b _0822506A
	.align 2, 0
_08225060: .4byte 0x00000E3A
_08225064:
	ldr r0, _082250AC @ =0x00000E3A
	adds r1, r7, r0
	movs r0, #8
_0822506A:
	strb r0, [r1]
_0822506C:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08225076:
	ldr r2, _082250B0 @ =0x00000D9C
	adds r5, r7, r2
	ldr r0, _082250B4 @ =0x00000DE4
	adds r4, r7, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082250B8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082250C0
	.align 2, 0
_082250AC: .4byte 0x00000E3A
_082250B0: .4byte 0x00000D9C
_082250B4: .4byte 0x00000DE4
_082250B8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082250C0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082250E4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082250EC
_082250E4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082250EC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08225124 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0822516A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0822512E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08225128
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08225144
	.align 2, 0
_08225124: .4byte 0x0000FFFF
_08225128:
	subs r0, #1
	strh r0, [r4, #8]
	b _08225142
_0822512E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08225142
	strh r1, [r4, #8]
	movs r2, #1
	b _08225144
_08225142:
	movs r2, #0
_08225144:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _0822516C
	movs r0, #1
	strb r0, [r4, #7]
	b _0822516C
_0822516A:
	movs r2, #0
_0822516C:
	ldr r1, _08225178 @ =0x00000F14
	adds r0, r7, r1
	strb r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08225178: .4byte 0x00000F14
