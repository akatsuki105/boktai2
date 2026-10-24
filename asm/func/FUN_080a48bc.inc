	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080A48DE
	ldr r0, _080A48FC @ =0x000001A9
	bl PlaySound_082406e0
	movs r1, #0
	movs r0, #0x20
	strb r0, [r4, #0x1b]
	strb r1, [r4, #0x19]
_080A48DE:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A49BC
	subs r0, #1
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080A4904
	ldr r0, _080A4900 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080A4912
	.align 2, 0
_080A48FC: .4byte 0x000001A9
_080A4900: .4byte 0x03003584
_080A4904:
	cmp r0, #0xf
	bls _080A4928
	ldr r0, _080A4920 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
_080A4912:
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080A4924 @ =0x04000008
	bl CpuSet
	b _080A49BC
	.align 2, 0
_080A4920: .4byte 0x03003584
_080A4924: .4byte 0x04000008
_080A4928:
	ldrb r7, [r4, #0x1b]
	movs r0, #0x10
	subs r0, r0, r7
	str r0, [sp]
	ldr r0, _080A49CC @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r3, r3, r0
	mov sl, r3
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r5, r5, r0
	mov r8, r5
	movs r6, #0
	mov sb, r6
	adds r4, #0x1c
	str r4, [sp, #4]
	movs r0, #0x1f
	mov ip, r0
_080A4950:
	mov r1, sl
	ldrh r3, [r1]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r5, ip
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	adds r5, r2, #0
	muls r5, r7, r5
	ldr r2, [sp]
	muls r0, r2, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	adds r2, r6, #0
	muls r2, r7, r2
	ldr r6, [sp]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	adds r0, r3, #0
	muls r0, r7, r0
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sb
	lsls r1, r3, #1
	ldr r6, [sp, #4]
	adds r1, r6, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r0, #2
	add sl, r0
	add r8, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xf
	ble _080A4950
_080A49BC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49CC: .4byte 0x03003584
