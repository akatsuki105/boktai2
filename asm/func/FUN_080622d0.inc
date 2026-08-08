	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r2, _08062328 @ =0x03003584
	ldr r1, _0806232C @ =0x0000094C
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r4, _08062330 @ =0x00000938
	adds r0, r3, r4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r0, _08062334 @ =0x0000094E
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08062354
	ldr r1, _08062338 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806233C
	movs r5, #0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r3, r2
_0806230E:
	subs r0, r5, #5
	cmp r0, #1
	bls _0806231C
	cmp r5, #0xd
	beq _0806231C
	ldrh r0, [r6]
	strh r0, [r1]
_0806231C:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _0806230E
	b _08062412
	.align 2, 0
_08062328: .4byte 0x03003584
_0806232C: .4byte 0x0000094C
_08062330: .4byte 0x00000938
_08062334: .4byte 0x0000094E
_08062338: .4byte 0x00000359
_0806233C:
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r5, #0xf
_08062344:
	ldrh r0, [r6]
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _08062344
	b _08062412
_08062354:
	ldr r2, _080623BC @ =0x00000359
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080623C0
	movs r5, #0
	mov r8, r1
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r7, r3, r4
_08062368:
	subs r0, r5, #5
	cmp r0, #1
	bls _080623B0
	cmp r5, #0xd
	beq _080623B0
	ldrh r1, [r6]
	movs r0, #0x1f
	mov ip, r0
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08062388
	movs r4, #0x1f
_08062388:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08062398
	movs r1, #0x1f
_08062398:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080623A6
	movs r0, #0x1f
_080623A6:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_080623B0:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _08062368
	b _08062412
	.align 2, 0
_080623BC: .4byte 0x00000359
_080623C0:
	movs r4, #0x1f
	mov ip, r4
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r3, r0
	movs r5, #0xf
_080623CE:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080623E0
	movs r4, #0x1f
_080623E0:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080623F0
	movs r1, #0x1f
_080623F0:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080623FE
	movs r0, #0x1f
_080623FE:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	subs r5, #1
	cmp r5, #0
	bge _080623CE
_08062412:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
