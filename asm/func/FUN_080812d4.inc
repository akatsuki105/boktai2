	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	mov ip, r2
	str r3, [sp, #4]
	cmp r2, #0
	bne _080812F8
	adds r1, r0, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	b _080813BE
_080812F8:
	mov sl, r1
	movs r3, #0
	mov r8, r3
	ldr r7, [sp]
	adds r7, #0xd0
	str r7, [sp, #0xc]
	ldr r0, [sp]
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r6, r0, r1
	ldr r2, _08081324 @ =0x0000094E
	adds r2, r0, r2
	str r2, [sp, #8]
_08081312:
	mov r0, r8
	subs r0, #5
	cmp r0, #1
	bls _08081320
	mov r3, r8
	cmp r3, #0xd
	bne _08081328
_08081320:
	ldrh r0, [r6]
	b _080813A0
	.align 2, 0
_08081324: .4byte 0x0000094E
_08081328:
	mov r7, sl
	ldrh r2, [r7]
	movs r7, #0x1f
	movs r0, #0x1f
	mov sb, r0
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08081340
	movs r4, #0x1f
_08081340:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _0808134E
	movs r2, #0x1f
_0808134E:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0808135A
	movs r5, #0x1f
_0808135A:
	ldrh r1, [r6]
	mov r0, sb
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	ldr r7, [sp, #4]
	muls r0, r7, r0
	adds r4, r4, r0
	ldr r0, [sp, #0x30]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	ldr r7, [sp, #4]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x30]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	asrs r0, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080813A0:
	strh r0, [r6, #0x20]
	movs r2, #2
	add sl, r2
	adds r6, #2
	movs r3, #1
	add r8, r3
	mov r7, r8
	cmp r7, #0xf
	ble _08081312
	ldr r1, [sp]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r3, [sp, #0xc]
	str r0, [r3]
_080813BE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
