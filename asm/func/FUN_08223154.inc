	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0
	str r0, [sp]
	movs r1, #0x1f
	mov sb, r1
	ldr r2, _0822332C @ =0x00000F08
	adds r2, r5, r2
	str r2, [sp, #4]
	ldr r4, _08223330 @ =0x00000F0A
	adds r4, r4, r5
	mov sl, r4
_08223176:
	ldr r0, [sp]
	lsls r0, r0, #1
	mov r8, r0
	ldr r1, _08223334 @ =0x00000EC4
	adds r0, r5, r1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sb
	ands r0, r1
	ldr r2, _08223338 @ =0xFFFFFF00
	ands r6, r2
	orrs r6, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #8
	ldr r2, _0822333C @ =0xFFFF00FF
	ands r6, r2
	orrs r6, r0
	lsrs r1, r1, #0x1a
	ands r1, r4
	lsls r1, r1, #0x10
	ldr r4, _08223340 @ =0xFF00FFFF
	ands r6, r4
	orrs r6, r1
	ldr r1, _08223344 @ =0x00000EA4
	adds r0, r5, r1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sb
	ands r0, r1
	ldr r2, _08223338 @ =0xFFFFFF00
	ands r7, r2
	orrs r7, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x15
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #8
	ldr r2, _0822333C @ =0xFFFF00FF
	ands r7, r2
	orrs r7, r0
	lsrs r1, r1, #0x1a
	ands r1, r4
	lsls r1, r1, #0x10
	ldr r4, _08223340 @ =0xFF00FFFF
	ands r7, r4
	orrs r7, r1
	lsls r1, r7, #0x18
	asrs r1, r1, #0x18
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	ldr r2, [sp, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r1, r0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r0, r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp, #8]
	ldr r4, _08223338 @ =0xFFFFFF00
	ands r3, r4
	orrs r3, r0
	lsls r1, r7, #0x10
	asrs r1, r1, #0x18
	lsls r4, r6, #0x10
	asrs r4, r4, #0x18
	subs r1, r1, r4
	mov ip, r1
	ldr r1, [sp, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x10
	ldr r3, [sp, #8]
	ldr r0, _0822333C @ =0xFFFF00FF
	ands r3, r0
	orrs r3, r4
	lsls r1, r7, #8
	asrs r1, r1, #0x18
	lsls r4, r6, #8
	asrs r4, r4, #0x18
	subs r1, r1, r4
	mov ip, r1
	ldr r1, [sp, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sl
	ldrh r1, [r2]
	str r3, [sp, #8]
	bl Div
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #8
	ldr r3, [sp, #8]
	ldr r4, _08223340 @ =0xFF00FFFF
	ands r3, r4
	orrs r3, r0
	ldr r0, _08223348 @ =0x00000EE4
	adds r2, r5, r0
	add r2, r8
	lsls r1, r3, #8
	asrs r1, r1, #0x18
	lsls r1, r1, #0xa
	lsls r0, r3, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	bgt _0822328A
	b _08223176
_0822328A:
	ldr r2, _0822332C @ =0x00000F08
	adds r1, r5, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0822331A
	ldr r4, _0822334C @ =0x00000F48
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	ldr r1, _08223350 @ =0x00000DC8
	adds r0, r5, r1
	ldr r1, _08223354 @ =0x00000117
	bl FUN_0822b20c
	ldr r2, _08223358 @ =0x00000DD4
	adds r1, r5, r2
	subs r4, #0x44
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0822335C @ =0x00000F16
	adds r4, r5, r0
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08223360 @ =0x00000F18
	adds r3, r5, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0xd0
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _0822330C
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _0822330C
	ldr r2, _08223364 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r4, _08223368 @ =0x00000F42
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0822336C @ =0x00000DF2
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _08223370 @ =0x00000F43
	adds r0, r5, r2
	strb r1, [r0]
_0822330C:
	movs r0, #1
	movs r4, #0xf2
	lsls r4, r4, #4
	adds r2, r5, r4
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_0822331A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822332C: .4byte 0x00000F08
_08223330: .4byte 0x00000F0A
_08223334: .4byte 0x00000EC4
_08223338: .4byte 0xFFFFFF00
_0822333C: .4byte 0xFFFF00FF
_08223340: .4byte 0xFF00FFFF
_08223344: .4byte 0x00000EA4
_08223348: .4byte 0x00000EE4
_0822334C: .4byte 0x00000F48
_08223350: .4byte 0x00000DC8
_08223354: .4byte 0x00000117
_08223358: .4byte 0x00000DD4
_0822335C: .4byte 0x00000F16
_08223360: .4byte 0x00000F18
_08223364: .4byte 0x00000DEC
_08223368: .4byte 0x00000F42
_0822336C: .4byte 0x00000DF2
_08223370: .4byte 0x00000F43
