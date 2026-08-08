	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r7, #0x1e
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r6, r5, r1
	ldr r1, [r6]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6]
	cmp r0, #0
	beq _08220234
	movs r2, #0xed
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r5, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	str r0, [r1]
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
	movs r3, #0xf6
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r4, [r0]
_08220234:
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	cmp r0, #0x1e
	blt _0822024E
	movs r2, #0x88
	lsls r2, r2, #0xf
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0822024E:
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #1
	bne _0822025C
	b _082203B8
_0822025C:
	cmp r0, #1
	bgt _08220266
	cmp r0, #0
	beq _0822026E
	b _08220424
_08220266:
	cmp r0, #0x63
	bne _0822026C
	b _082203E8
_0822026C:
	b _08220424
_0822026E:
	movs r0, #2
	ldr r1, [r6]
	ands r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6]
	cmp r0, #0
	beq _08220288
	movs r2, #0xfd
	lsls r2, r2, #2
	adds r0, r5, r2
	str r7, [r0]
_08220288:
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #7
	bne _082202A6
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne _082202A6
	ldr r0, _082202C4 @ =0x0000035E
	bl PlaySound_082406e0
_082202A6:
	movs r0, #0xfd
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	ble _082202C8
	subs r2, r0, #1
	str r2, [r1]
	adds r0, r5, #0
	movs r1, #1
	adds r3, r7, #0
	bl FUN_0821c2a0
	b _082202E2
	.align 2, 0
_082202C4: .4byte 0x0000035E
_082202C8:
	cmn r0, r7
	ble _082202E2
	subs r0, #1
	str r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	bge _082202D8
	rsbs r2, r2, #0
_082202D8:
	adds r0, r5, #0
	movs r1, #1
	adds r3, r7, #0
	bl FUN_0821c2a0
_082202E2:
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, r7
	bne _08220378
	ldr r2, _0822035C @ =0x000003D9
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0xf
	subs r3, r0, r1
	cmp r3, #0
	ble _0822033E
	add r2, sp, #0x10
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	ldr r4, _08220360 @ =0x00000BF8
	adds r0, r5, r4
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #0x4d
	ldrb r2, [r1]
	movs r4, #0xf5
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r4, #0
	ldrsh r1, [r1, r4]
	str r1, [sp]
	movs r1, #0x1e
	str r1, [sp, #4]
	movs r1, #8
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0x32
	bl FUN_0805e940
	movs r0, #0xea
	bl PlaySound_082406e0
_0822033E:
	movs r0, #0x20
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08220368
	ldr r2, _08220364 @ =0x00000809
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08220370
	.align 2, 0
_0822035C: .4byte 0x000003D9
_08220360: .4byte 0x00000BF8
_08220364: .4byte 0x00000809
_08220368:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_08220370:
	ldr r3, _082203B0 @ =0x000003DB
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
_08220378:
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldr r0, [r0]
	cmp r0, #0x96
	ble _08220424
	ldr r1, _082203B4 @ =0x000002D9
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08220424
	movs r1, #1
	movs r3, #0xe8
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	adds r1, r5, r4
	movs r0, #0
	str r0, [r1]
	subs r4, #0x18
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08220424
	.align 2, 0
_082203B0: .4byte 0x000003DB
_082203B4: .4byte 0x000002D9
_082203B8:
	ldr r0, [r6]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0xd2
	ble _08220424
	movs r1, #0x63
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	str r0, [r1]
	ldr r0, [r6]
	movs r1, #2
	b _08220420
_082203E8:
	movs r4, #2
	ldr r0, [r6]
	adds r2, r0, #0
	ands r2, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	cmp r2, #0
	beq _0822040E
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_0822040E:
	ldr r1, _0822042C @ =0x000002D9
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08220424
	movs r1, #0x10
	ldr r0, [r6]
_08220420:
	orrs r0, r1
	str r0, [r6]
_08220424:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822042C: .4byte 0x000002D9
