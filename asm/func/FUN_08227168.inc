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
	beq _08227198
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08227194 @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _0822719A
	.align 2, 0
_08227194: .4byte 0x00000F14
_08227198:
	movs r0, #0
_0822719A:
	cmp r0, #0
	beq _082271CC
	ldr r3, _08227210 @ =0x00000F15
	adds r1, r7, r3
	movs r2, #0
	movs r0, #0x13
	strb r0, [r1]
	ldr r1, _08227214 @ =0x00000DE4
	adds r0, r7, r1
	subs r3, #0xe1
	adds r1, r7, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #0x13
	movs r3, #0
	bl FUN_08236fac
	ldr r1, _08227218 @ =0x00000DF4
	adds r0, r7, r1
	bl FUN_08013698
	ldr r2, _0822721C @ =0x00000F48
	adds r1, r7, r2
	ldr r0, _08227220 @ =FUN_082230d0
	str r0, [r1]
_082271CC:
	ldr r3, _0822721C @ =0x00000F48
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _082271DC
	adds r0, r7, #0
	bl _call_via_r1
_082271DC:
	ldr r0, _08227224 @ =0x00000D9C
	adds r5, r7, r0
	ldr r1, _08227214 @ =0x00000DE4
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
	beq _08227228
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08227230
	.align 2, 0
_08227210: .4byte 0x00000F15
_08227214: .4byte 0x00000DE4
_08227218: .4byte 0x00000DF4
_0822721C: .4byte 0x00000F48
_08227220: .4byte FUN_082230d0
_08227224: .4byte 0x00000D9C
_08227228:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08227230:
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
	beq _08227254
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0822725C
_08227254:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0822725C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08227294 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _082272DA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0822729E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08227298
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082272B4
	.align 2, 0
_08227294: .4byte 0x0000FFFF
_08227298:
	subs r0, #1
	strh r0, [r4, #8]
	b _082272B2
_0822729E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082272B2
	strh r1, [r4, #8]
	movs r2, #1
	b _082272B4
_082272B2:
	movs r2, #0
_082272B4:
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
	bne _082272DC
	movs r0, #1
	strb r0, [r4, #7]
	b _082272DC
_082272DA:
	movs r2, #0
_082272DC:
	ldr r3, _082272EC @ =0x00000F14
	adds r0, r7, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082272EC: .4byte 0x00000F14
