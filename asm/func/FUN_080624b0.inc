	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	mov ip, r2
	mov sb, r3
	cmp r2, #0
	bne _080624F2
	ldr r0, _080624E0 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080624E4
	mov r1, sl
	adds r1, #0xd0
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	b _08062672
	.align 2, 0
_080624E0: .4byte 0x00000359
_080624E4:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	b _0806266E
_080624F2:
	mov r8, r1
	ldr r0, _08062528 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080625C8
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0xd0
	str r1, [sp, #0xc]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
	ldr r2, _0806252C @ =0x0000094E
	add r2, sl
	str r2, [sp, #4]
_08062514:
	ldr r0, [sp]
	subs r0, #5
	cmp r0, #1
	bls _08062522
	ldr r3, [sp]
	cmp r3, #0xd
	bne _08062530
_08062522:
	ldrh r0, [r6]
	b _080625AA
	.align 2, 0
_08062528: .4byte 0x00000359
_0806252C: .4byte 0x0000094E
_08062530:
	mov r4, r8
	ldrh r2, [r4]
	movs r7, #0x1f
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #4]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08062546
	movs r4, #0x1f
_08062546:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _08062554
	movs r2, #0x1f
_08062554:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _08062560
	movs r5, #0x1f
_08062560:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	adds r4, r4, r0
	ldr r0, [sp, #0x34]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x34]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080625AA:
	strh r0, [r6, #0x20]
	movs r0, #2
	add r8, r0
	adds r6, #2
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	ble _08062514
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, sl
	ldr r2, [sp, #0xc]
	str r0, [r2]
	b _08062672
_080625C8:
	movs r3, #0
	str r3, [sp]
	ldr r4, _08062684 @ =0x0000094E
	add r4, sl
	str r4, [sp, #8]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
_080625D8:
	mov r7, r8
	ldrh r2, [r7]
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080625EC
	movs r4, #0x1f
_080625EC:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	movs r7, #0x1f
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080625FC
	movs r2, #0x1f
_080625FC:
	lsrs r0, r3, #0x1a
	movs r3, #0x1f
	ands r0, r3
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0806260A
	movs r5, #0x1f
_0806260A:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	movs r7, #0x1f
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r7, r0
	ldr r7, [sp, #0x34]
	asrs r4, r7
	mov r0, ip
	muls r0, r2, r0
	adds r2, r0, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	asrs r2, r7
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
	strh r0, [r6, #0x20]
	movs r4, #2
	add r8, r4
	adds r6, #2
	ldr r7, [sp]
	adds r7, #1
	str r7, [sp]
	cmp r7, #0xf
	ble _080625D8
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xb1
	lsls r0, r0, #2
_0806266E:
	add r0, sl
	str r0, [r1, #0xc]
_08062672:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062684: .4byte 0x0000094E
