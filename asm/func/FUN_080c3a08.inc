	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r3, r1, #0
	ldr r1, _080C3A44 @ =0x00001904
	adds r2, r0, r1
	ldr r4, _080C3A48 @ =0x000025BE
	adds r1, r0, r4
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldr r2, [r2]
	adds r1, r1, r2
	mov sb, r1
	ldr r5, _080C3A4C @ =0x000025BF
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r8, r2
	cmp r3, #0xf
	ble _080C3A58
	ldr r1, _080C3A50 @ =0x03004250
	ldr r2, _080C3A54 @ =0x04000010
	mov r0, r8
	bl CpuSet
	b _080C3AE0
	.align 2, 0
_080C3A44: .4byte 0x00001904
_080C3A48: .4byte 0x000025BE
_080C3A4C: .4byte 0x000025BF
_080C3A50: .4byte 0x03004250
_080C3A54: .4byte 0x04000010
_080C3A58:
	movs r0, #0x10
	subs r0, r0, r3
	mov ip, r0
	adds r7, r3, #0
	movs r0, #0
_080C3A62:
	movs r1, #0
	mov sl, r1
	lsls r3, r0, #5
	str r3, [sp, #4]
	adds r0, #1
	str r0, [sp]
_080C3A6E:
	mov r4, sb
	ldrh r3, [r4]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r5, #0x1f
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
	mov r5, ip
	muls r5, r2, r5
	muls r0, r7, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, ip
	muls r2, r6, r2
	adds r0, r4, #0
	muls r0, r7, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, ip
	muls r0, r3, r0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sl
	lsls r1, r3, #1
	ldr r4, [sp, #4]
	adds r1, r1, r4
	ldr r3, _080C3AF0 @ =0x03004250
	adds r1, r1, r3
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r4, #2
	add sb, r4
	add r8, r4
	movs r5, #1
	add sl, r5
	mov r0, sl
	cmp r0, #0xf
	ble _080C3A6E
	ldr r0, [sp]
	cmp r0, #1
	ble _080C3A62
_080C3AE0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3AF0: .4byte 0x03004250
