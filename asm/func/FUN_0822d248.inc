	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0822D2A0 @ =0x0300445C
	ldr r1, [r0]
	cmp r1, #0x40
	bne _0822D2B8
	ldr r0, _0822D2A4 @ =0x0300404C
	ldr r0, [r0]
	cmp r0, #0x40
	beq _0822D294
	movs r5, #0
	ldr r0, _0822D2A8 @ =0x03004458
	ldr r0, [r0]
	cmp r5, r0
	bge _0822D294
	ldr r6, _0822D2AC @ =0x03003584
	ldr r4, _0822D2B0 @ =0x03004470
_0822D272:
	ldrh r0, [r4]
	lsls r0, r0, #5
	ldr r1, [r6]
	adds r3, r1, r0
	lsls r1, r5, #5
	ldr r0, _0822D2B4 @ =gObjectPlttBuffer
	adds r1, r1, r0
	adds r0, r3, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #2
	adds r5, #1
	ldr r0, _0822D2A8 @ =0x03004458
	ldr r0, [r0]
	cmp r5, r0
	blt _0822D272
_0822D294:
	ldr r0, _0822D2A4 @ =0x0300404C
	ldr r1, _0822D2A0 @ =0x0300445C
	ldr r1, [r1]
	str r1, [r0]
	b _0822D60A
	.align 2, 0
_0822D2A0: .4byte 0x0300445C
_0822D2A4: .4byte 0x0300404C
_0822D2A8: .4byte 0x03004458
_0822D2AC: .4byte 0x03003584
_0822D2B0: .4byte 0x03004470
_0822D2B4: .4byte gObjectPlttBuffer
_0822D2B8:
	asrs r1, r1, #1
	str r1, [sp]
	movs r0, #0x20
	subs r1, r0, r1
	mov sl, r1
	ldr r0, _0822D3C0 @ =0x03004464
	ldrh r0, [r0]
	cmp r0, #0
	beq _0822D2CC
	b _0822D45C
_0822D2CC:
	movs r5, #0
	ldr r0, _0822D3C4 @ =0x03004470
	mov sl, r0
_0822D2D2:
	ldr r1, _0822D3C8 @ =0x03004490
	ldrh r2, [r1]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0822D300
	lsls r0, r5, #1
	add r0, sl
	ldrh r1, [r0]
	adds r6, r5, #1
	cmp r1, #0x1d
	bne _0822D2EC
	b _0822D444
_0822D2EC:
	cmp r1, #0x26
	bne _0822D2F2
	b _0822D444
_0822D2F2:
	cmp r1, #0x27
	bne _0822D2F8
	b _0822D444
_0822D2F8:
	ldr r0, _0822D3CC @ =0x00000117
	cmp r1, r0
	bne _0822D300
	b _0822D444
_0822D300:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0822D33A
	lsls r0, r5, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r0, _0822D3D0 @ =0x000002A9
	adds r6, r5, #1
	cmp r1, r0
	bne _0822D318
	b _0822D444
_0822D318:
	subs r0, #0x2f
	cmp r1, r0
	bne _0822D320
	b _0822D444
_0822D320:
	ldr r3, _0822D3D4 @ =0x000002FA
	cmp r1, r3
	bne _0822D328
	b _0822D444
_0822D328:
	cmp r1, #0x1d
	bne _0822D32E
	b _0822D444
_0822D32E:
	cmp r1, #0x26
	bne _0822D334
	b _0822D444
_0822D334:
	cmp r1, #0x27
	bne _0822D33A
	b _0822D444
_0822D33A:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0822D35E
	lsls r0, r5, #1
	add r0, sl
	ldrh r0, [r0]
	adds r6, r5, #1
	cmp r0, #0x1d
	beq _0822D444
	cmp r0, #0x26
	beq _0822D444
	cmp r0, #0x27
	beq _0822D444
	ldr r7, _0822D3D8 @ =0xFFFFFDF9
	adds r0, r0, r7
	cmp r0, #8
	bls _0822D444
_0822D35E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0822D37E
	lsls r0, r5, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r3, _0822D3DC @ =0xFFFFFD05
	adds r0, r1, r3
	adds r6, r5, #1
	cmp r0, #3
	bls _0822D444
	ldr r7, _0822D3E0 @ =0xFFFFFD31
	adds r0, r1, r7
	cmp r0, #3
	bls _0822D444
_0822D37E:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0822D3A4
	lsls r0, r5, #1
	add r0, sl
	ldrh r1, [r0]
	adds r6, r5, #1
	ldr r0, _0822D3D4 @ =0x000002FA
	cmp r1, r0
	beq _0822D444
	ldr r2, _0822D3E4 @ =0xFFFFFD5B
	adds r0, r1, r2
	cmp r0, #5
	bls _0822D444
	ldr r3, _0822D3E8 @ =0xFFFFFD10
	adds r0, r1, r3
	cmp r0, #4
	bls _0822D444
_0822D3A4:
	ldr r0, _0822D3EC @ =0x03004458
	ldr r0, [r0]
	cmp r5, r0
	bge _0822D3F8
	ldr r1, _0822D3F0 @ =0x03003584
	lsls r0, r5, #1
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r3, r1, r0
	lsls r0, r5, #5
	ldr r1, _0822D3F4 @ =gObjectPlttBuffer
	b _0822D3FE
	.align 2, 0
_0822D3C0: .4byte 0x03004464
_0822D3C4: .4byte 0x03004470
_0822D3C8: .4byte 0x03004490
_0822D3CC: .4byte 0x00000117
_0822D3D0: .4byte 0x000002A9
_0822D3D4: .4byte 0x000002FA
_0822D3D8: .4byte 0xFFFFFDF9
_0822D3DC: .4byte 0xFFFFFD05
_0822D3E0: .4byte 0xFFFFFD31
_0822D3E4: .4byte 0xFFFFFD5B
_0822D3E8: .4byte 0xFFFFFD10
_0822D3EC: .4byte 0x03004458
_0822D3F0: .4byte 0x03003584
_0822D3F4: .4byte gObjectPlttBuffer
_0822D3F8:
	lsls r0, r5, #5
	ldr r1, _0822D450 @ =gObjectPlttBuffer
	adds r3, r0, r1
_0822D3FE:
	adds r4, r0, r1
	adds r6, r5, #1
	ldr r7, _0822D454 @ =0x00007C1F
	mov sb, r7
	ldr r0, _0822D458 @ =0x000F83E0
	mov r8, r0
	movs r5, #0xf
	movs r1, #0xf8
	lsls r1, r1, #2
	mov ip, r1
_0822D412:
	ldrh r2, [r3]
	adds r0, r2, #0
	mov r7, sb
	ands r0, r7
	ldr r7, [sp]
	adds r1, r0, #0
	muls r1, r7, r1
	mov r0, r8
	ands r1, r0
	mov r7, ip
	ands r2, r7
	ldr r7, [sp]
	adds r0, r2, #0
	muls r0, r7, r0
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r0, r2
	orrs r1, r0
	lsrs r1, r1, #5
	strh r1, [r4]
	adds r3, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0822D412
_0822D444:
	adds r5, r6, #0
	cmp r5, #0xf
	bgt _0822D44C
	b _0822D2D2
_0822D44C:
	b _0822D602
	.align 2, 0
_0822D450: .4byte gObjectPlttBuffer
_0822D454: .4byte 0x00007C1F
_0822D458: .4byte 0x000F83E0
_0822D45C:
	ldr r3, _0822D568 @ =0x00007C1F
	ands r3, r0
	str r3, [sp, #4]
	movs r7, #0xf8
	lsls r7, r7, #2
	adds r1, r7, #0
	ands r1, r0
	str r1, [sp, #8]
	movs r5, #0
	ldr r2, _0822D56C @ =0x03004470
	mov sb, r2
_0822D472:
	ldr r3, _0822D570 @ =0x03004490
	ldrh r2, [r3]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0822D4A0
	lsls r0, r5, #1
	add r0, sb
	ldrh r1, [r0]
	adds r6, r5, #1
	cmp r1, #0x1d
	bne _0822D48C
	b _0822D5FA
_0822D48C:
	cmp r1, #0x26
	bne _0822D492
	b _0822D5FA
_0822D492:
	cmp r1, #0x27
	bne _0822D498
	b _0822D5FA
_0822D498:
	ldr r0, _0822D574 @ =0x00000117
	cmp r1, r0
	bne _0822D4A0
	b _0822D5FA
_0822D4A0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0822D4DA
	lsls r0, r5, #1
	add r0, sb
	ldrh r1, [r0]
	ldr r0, _0822D578 @ =0x000002A9
	adds r6, r5, #1
	cmp r1, r0
	bne _0822D4B8
	b _0822D5FA
_0822D4B8:
	subs r0, #0x2f
	cmp r1, r0
	bne _0822D4C0
	b _0822D5FA
_0822D4C0:
	ldr r7, _0822D57C @ =0x000002FA
	cmp r1, r7
	bne _0822D4C8
	b _0822D5FA
_0822D4C8:
	cmp r1, #0x1d
	bne _0822D4CE
	b _0822D5FA
_0822D4CE:
	cmp r1, #0x26
	bne _0822D4D4
	b _0822D5FA
_0822D4D4:
	cmp r1, #0x27
	bne _0822D4DA
	b _0822D5FA
_0822D4DA:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0822D504
	lsls r0, r5, #1
	add r0, sb
	ldrh r0, [r0]
	adds r6, r5, #1
	cmp r0, #0x1d
	bne _0822D4F0
	b _0822D5FA
_0822D4F0:
	cmp r0, #0x26
	bne _0822D4F6
	b _0822D5FA
_0822D4F6:
	cmp r0, #0x27
	bne _0822D4FC
	b _0822D5FA
_0822D4FC:
	ldr r1, _0822D580 @ =0xFFFFFDF9
	adds r0, r0, r1
	cmp r0, #8
	bls _0822D5FA
_0822D504:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0822D524
	lsls r0, r5, #1
	add r0, sb
	ldrh r1, [r0]
	ldr r3, _0822D584 @ =0xFFFFFD05
	adds r0, r1, r3
	adds r6, r5, #1
	cmp r0, #3
	bls _0822D5FA
	ldr r7, _0822D588 @ =0xFFFFFD31
	adds r0, r1, r7
	cmp r0, #3
	bls _0822D5FA
_0822D524:
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0822D54A
	lsls r0, r5, #1
	add r0, sb
	ldrh r1, [r0]
	adds r6, r5, #1
	ldr r0, _0822D57C @ =0x000002FA
	cmp r1, r0
	beq _0822D5FA
	ldr r2, _0822D58C @ =0xFFFFFD5B
	adds r0, r1, r2
	cmp r0, #5
	bls _0822D5FA
	ldr r3, _0822D590 @ =0xFFFFFD10
	adds r0, r1, r3
	cmp r0, #4
	bls _0822D5FA
_0822D54A:
	ldr r7, _0822D594 @ =0x03004458
	ldr r0, [r7]
	cmp r5, r0
	bge _0822D5A0
	lsls r0, r5, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r2, _0822D598 @ =0x03003584
	ldr r1, [r2]
	adds r3, r1, r0
	lsls r0, r5, #5
	ldr r1, _0822D59C @ =gObjectPlttBuffer
	b _0822D5A8
	.align 2, 0
_0822D568: .4byte 0x00007C1F
_0822D56C: .4byte 0x03004470
_0822D570: .4byte 0x03004490
_0822D574: .4byte 0x00000117
_0822D578: .4byte 0x000002A9
_0822D57C: .4byte 0x000002FA
_0822D580: .4byte 0xFFFFFDF9
_0822D584: .4byte 0xFFFFFD05
_0822D588: .4byte 0xFFFFFD31
_0822D58C: .4byte 0xFFFFFD5B
_0822D590: .4byte 0xFFFFFD10
_0822D594: .4byte 0x03004458
_0822D598: .4byte 0x03003584
_0822D59C: .4byte gObjectPlttBuffer
_0822D5A0:
	lsls r0, r5, #5
	ldr r7, _0822D61C @ =gObjectPlttBuffer
	adds r3, r0, r7
	adds r1, r7, #0
_0822D5A8:
	adds r4, r0, r1
	adds r6, r5, #1
	ldr r1, [sp, #8]
	mov r0, sl
	muls r0, r1, r0
	mov ip, r0
	ldr r2, _0822D620 @ =0x00007C1F
	mov r8, r2
	movs r5, #0xf
	ldr r0, [sp, #4]
	mov r7, sl
	muls r7, r0, r7
	str r7, [sp, #0xc]
_0822D5C2:
	ldrh r1, [r3]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	ldr r7, [sp]
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r0, [sp, #0xc]
	adds r2, r2, r0
	ldr r0, _0822D624 @ =0x000F83E0
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r1, r0
	adds r0, r1, #0
	muls r0, r7, r0
	add r0, ip
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	orrs r2, r0
	lsrs r2, r2, #5
	strh r2, [r4]
	adds r3, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0822D5C2
_0822D5FA:
	adds r5, r6, #0
	cmp r5, #0xf
	bgt _0822D602
	b _0822D472
_0822D602:
	ldr r1, _0822D628 @ =0x0300445C
	ldr r0, [r1]
	ldr r2, _0822D62C @ =0x0300404C
	str r0, [r2]
_0822D60A:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D61C: .4byte gObjectPlttBuffer
_0822D620: .4byte 0x00007C1F
_0822D624: .4byte 0x000F83E0
_0822D628: .4byte 0x0300445C
_0822D62C: .4byte 0x0300404C
