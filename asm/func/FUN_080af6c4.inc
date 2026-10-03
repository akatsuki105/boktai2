	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080AF744 @ =0x000006AC
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_080af4f8
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_080af508
	adds r1, r0, #0
	cmp r4, #0
	bgt _080AF6EC
	b _080AF878
_080AF6EC:
	cmp r1, #0
	bgt _080AF6F2
	b _080AF878
_080AF6F2:
	movs r6, #0
	movs r7, #0
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, r0, #0
	cmp r3, #2
	bne _080AF758
	adds r0, r4, #0
	muls r0, r1, r0
	lsls r6, r0, #2
	ldr r2, _080AF748 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF74C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _080AF750 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, _080AF754 @ =0x0000069C
	adds r2, r5, r4
	str r7, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
	b _080AF7A4
	.align 2, 0
_080AF744: .4byte 0x000006AC
_080AF748: .4byte 0x030046B8
_080AF74C: .4byte 0x000003FF
_080AF750: .4byte 0x0203B400
_080AF754: .4byte 0x0000069C
_080AF758:
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080AF766
	cmp r3, #7
	bne _080AF7A4
_080AF766:
	adds r6, r4, #0
	muls r6, r1, r6
	ldr r2, _080AF7FC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF800 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF804 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080AF808 @ =0x000006A4
	adds r2, r5, r3
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
_080AF7A4:
	cmp r6, #0
	ble _080AF7BE
	ldr r0, _080AF80C @ =0x00000BF8
	add r0, r8
	ldrh r0, [r0]
	muls r0, r6, r0
	movs r1, #0x64
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080AF7BE
	movs r6, #1
_080AF7BE:
	ldr r0, _080AF810 @ =0x00000696
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, r0, r6
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _080AF7E6
	ldrh r0, [r4]
	movs r1, #0x28
	bl Div
	adds r7, r7, r0
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #3
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
_080AF7E6:
	ldr r1, _080AF814 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r2, r0, r3
	ldr r0, [r2]
	cmp r0, r7
	bgt _080AF818
	movs r0, #0
	b _080AF81A
	.align 2, 0
_080AF7FC: .4byte 0x030046B8
_080AF800: .4byte 0x000003FF
_080AF804: .4byte 0x0203B400
_080AF808: .4byte 0x000006A4
_080AF80C: .4byte 0x00000BF8
_080AF810: .4byte 0x00000696
_080AF814: .4byte 0x030046A0
_080AF818:
	subs r0, r0, r7
_080AF81A:
	str r0, [r2]
	ldr r5, _080AF884 @ =0x03002C58
	ldr r0, [r5]
	ldr r3, _080AF888 @ =0x0000133F
	adds r2, r0, r3
	ldrb r4, [r2]
	cmp r4, #0
	bne _080AF878
	ldr r0, [r1]
	movs r6, #0xae
	lsls r6, r6, #2
	adds r1, r0, r6
	adds r6, #4
	adds r0, r0, r6
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	bgt _080AF878
	movs r0, #1
	strb r0, [r2]
	ldr r1, [r5]
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AF88C @ =0x00001FFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	ldr r0, [r5]
	movs r1, #4
	bl FUN_080ad204
_080AF878:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF884: .4byte 0x03002C58
_080AF888: .4byte 0x0000133F
_080AF88C: .4byte 0x00001FFF
