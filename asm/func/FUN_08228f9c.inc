	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08228FCC
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228FC8 @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _08228FCE
	.align 2, 0
_08228FC8: .4byte 0x00000F14
_08228FCC:
	movs r0, #0
_08228FCE:
	cmp r0, #0
	beq _08229004
	ldr r3, _08229048 @ =0x00000F15
	adds r1, r7, r3
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _0822904C @ =0x00000DE4
	adds r0, r7, r1
	ldr r2, _08229050 @ =0x00000E34
	adds r1, r7, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r7, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0xb
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08229054 @ =0x00000DF4
	adds r0, r7, r1
	bl FUN_080136b4
	ldr r2, _08229058 @ =0x00000F48
	adds r1, r7, r2
	ldr r0, _0822905C @ =0x08222CE1
	str r0, [r1]
_08229004:
	ldr r3, _08229058 @ =0x00000F48
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08229014
	adds r0, r7, #0
	bl _call_via_r1
_08229014:
	ldr r0, _08229060 @ =0x00000D9C
	adds r5, r7, r0
	ldr r1, _0822904C @ =0x00000DE4
	adds r4, r7, r1
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
	beq _08229064
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0822906C
	.align 2, 0
_08229048: .4byte 0x00000F15
_0822904C: .4byte 0x00000DE4
_08229050: .4byte 0x00000E34
_08229054: .4byte 0x00000DF4
_08229058: .4byte 0x00000F48
_0822905C: .4byte 0x08222CE1
_08229060: .4byte 0x00000D9C
_08229064:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0822906C:
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
	beq _08229090
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08229098
_08229090:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08229098:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082290D0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08229116
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082290DA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082290D4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082290F0
	.align 2, 0
_082290D0: .4byte 0x0000FFFF
_082290D4:
	subs r0, #1
	strh r0, [r4, #8]
	b _082290EE
_082290DA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082290EE
	strh r1, [r4, #8]
	movs r2, #1
	b _082290F0
_082290EE:
	movs r2, #0
_082290F0:
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
	bne _08229118
	movs r0, #1
	strb r0, [r4, #7]
	b _08229118
_08229116:
	movs r2, #0
_08229118:
	ldr r3, _08229134 @ =0x00000F14
	adds r0, r7, r3
	strb r2, [r0]
	cmp r2, #0
	beq _0822912A
	ldr r0, _08229138 @ =0x00000DEC
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_0822912A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08229134: .4byte 0x00000F14
_08229138: .4byte 0x00000DEC
