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
	beq _08227000
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08226FFC @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _08227002
	.align 2, 0
_08226FFC: .4byte 0x00000F14
_08227000:
	movs r0, #0
_08227002:
	cmp r0, #0
	beq _08227034
	ldr r3, _08227078 @ =0x00000F15
	adds r1, r7, r3
	movs r2, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _0822707C @ =0x00000DE4
	adds r0, r7, r1
	subs r3, #0xe1
	adds r1, r7, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #0xb
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08227080 @ =0x00000DF4
	adds r0, r7, r1
	bl FUN_08013698
	ldr r2, _08227084 @ =0x00000F48
	adds r1, r7, r2
	ldr r0, _08227088 @ =0x08222CE1
	str r0, [r1]
_08227034:
	ldr r3, _08227084 @ =0x00000F48
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08227044
	adds r0, r7, #0
	bl _call_via_r1
_08227044:
	ldr r0, _0822708C @ =0x00000D9C
	adds r5, r7, r0
	ldr r1, _0822707C @ =0x00000DE4
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
	beq _08227090
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08227098
	.align 2, 0
_08227078: .4byte 0x00000F15
_0822707C: .4byte 0x00000DE4
_08227080: .4byte 0x00000DF4
_08227084: .4byte 0x00000F48
_08227088: .4byte 0x08222CE1
_0822708C: .4byte 0x00000D9C
_08227090:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08227098:
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
	beq _082270BC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082270C4
_082270BC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082270C4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082270FC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08227142
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08227106
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08227100
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0822711C
	.align 2, 0
_082270FC: .4byte 0x0000FFFF
_08227100:
	subs r0, #1
	strh r0, [r4, #8]
	b _0822711A
_08227106:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0822711A
	strh r1, [r4, #8]
	movs r2, #1
	b _0822711C
_0822711A:
	movs r2, #0
_0822711C:
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
	bne _08227144
	movs r0, #1
	strb r0, [r4, #7]
	b _08227144
_08227142:
	movs r2, #0
_08227144:
	ldr r3, _08227160 @ =0x00000F14
	adds r0, r7, r3
	strb r2, [r0]
	cmp r2, #0
	beq _08227156
	ldr r0, _08227164 @ =0x00000DEC
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_08227156:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08227160: .4byte 0x00000F14
_08227164: .4byte 0x00000DEC
