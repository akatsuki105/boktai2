	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov ip, r0
	adds r7, r2, #0
	str r3, [sp, #0x10]
	ldr r0, _08070590 @ =0x0203B400
	mov sb, r0
	ldr r6, _08070594 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _08070598 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0807059C @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080705A0 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #3
	ldr r2, _080705A4 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080705A8
	asrs r0, r0, #0xc
	b _080705AE
	.align 2, 0
_08070590: .4byte 0x0203B400
_08070594: .4byte 0x030046B8
_08070598: .4byte 0x000003FF
_0807059C: .4byte 0xFFFF0000
_080705A0: .4byte 0x0000FFFF
_080705A4: .4byte 0x085B0A08
_080705A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080705AE:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080705CC
	asrs r0, r0, #0xc
	b _080705D2
_080705CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080705D2:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08070600 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x10]
	bl FUN_08061d20
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070600: .4byte 0xFFFF0000
