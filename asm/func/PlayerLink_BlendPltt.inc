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
	bne _080CD7C2
	ldr r0, _080CD7B0 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD7B4
	mov r1, sl
	adds r1, #0xd0
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	b _080CD942
	.align 2, 0
_080CD7B0: .4byte 0x00000359
_080CD7B4:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	b _080CD93E
_080CD7C2:
	mov r8, r1
	ldr r0, _080CD7F8 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD898
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0xd0
	str r1, [sp, #0xc]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
	ldr r2, _080CD7FC @ =0x0000094E
	add r2, sl
	str r2, [sp, #4]
_080CD7E4:
	ldr r0, [sp]
	subs r0, #5
	cmp r0, #1
	bls _080CD7F2
	ldr r3, [sp]
	cmp r3, #0xd
	bne _080CD800
_080CD7F2:
	ldrh r0, [r6]
	b _080CD87A
	.align 2, 0
_080CD7F8: .4byte 0x00000359
_080CD7FC: .4byte 0x0000094E
_080CD800:
	mov r4, r8
	ldrh r2, [r4]
	movs r7, #0x1f
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #4]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD816
	movs r4, #0x1f
_080CD816:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD824
	movs r2, #0x1f
_080CD824:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD830
	movs r5, #0x1f
_080CD830:
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
_080CD87A:
	strh r0, [r6, #0x20]
	movs r0, #2
	add r8, r0
	adds r6, #2
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	ble _080CD7E4
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, sl
	ldr r2, [sp, #0xc]
	str r0, [r2]
	b _080CD942
_080CD898:
	movs r3, #0
	str r3, [sp]
	ldr r4, _080CD954 @ =0x0000094E
	add r4, sl
	str r4, [sp, #8]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
_080CD8A8:
	mov r7, r8
	ldrh r2, [r7]
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD8BC
	movs r4, #0x1f
_080CD8BC:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	movs r7, #0x1f
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD8CC
	movs r2, #0x1f
_080CD8CC:
	lsrs r0, r3, #0x1a
	movs r3, #0x1f
	ands r0, r3
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD8DA
	movs r5, #0x1f
_080CD8DA:
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
	ble _080CD8A8
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xb1
	lsls r0, r0, #2
_080CD93E:
	add r0, sl
	str r0, [r1, #0xc]
_080CD942:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD954: .4byte 0x0000094E
