	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	adds r7, r1, #0
	mov sl, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805AE84
	movs r4, #0
	strb r4, [r7]
	adds r2, r7, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_0805a8d0
	adds r0, r7, #0
	adds r0, #0xe8
	mov r2, sb
	ldr r1, [r2, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
_0805AE84:
	add r3, sp, #0x10
	ldrb r4, [r7, #0xa]
	movs r5, #0x14
	ldr r2, _0805AEA8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AEAC
	asrs r1, r0, #0xc
	b _0805AEB2
	.align 2, 0
_0805AEA8: .4byte 0x085B0A08
_0805AEAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805AEB2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805AECA
	asrs r0, r0, #0xc
	b _0805AED0
_0805AECA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805AED0:
	strh r0, [r3, #4]
	adds r6, r7, #0
	adds r6, #0x14
	add r1, sp, #0x10
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	movs r1, #3
	mov ip, r1
	mov r2, ip
	ands r2, r0
	mov ip, r2
	cmp r2, #0
	bne _0805AF74
	ldr r4, _0805AF88 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0805AF8C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	ldr r5, _0805AF90 @ =0x0203B400
	ldr r4, _0805AF94 @ =0x030046B8
	mov r8, r4
	ldr r0, [r4]
	adds r0, #1
	ldr r4, _0805AF98 @ =0x000003FF
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #1
	ands r1, r3
	adds r1, #1
	adds r0, #1
	ands r0, r4
	lsls r3, r0, #1
	adds r3, r3, r5
	ldrb r3, [r3]
	adds r0, #1
	ands r0, r4
	mov r4, r8
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	adds r0, #0x10
	mov r4, ip
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	bl FUN_080ddcc8
	ldr r0, _0805AF9C @ =0x00000339
	bl PlaySound_082406e0
_0805AF74:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0805AFA0
	mov r0, sb
	adds r1, r7, #0
	mov r2, sl
	bl FUN_0805a6ec
	b _0805AFA6
	.align 2, 0
_0805AF88: .4byte 0xFFFF0000
_0805AF8C: .4byte 0x0000FFFF
_0805AF90: .4byte 0x0203B400
_0805AF94: .4byte 0x030046B8
_0805AF98: .4byte 0x000003FF
_0805AF9C: .4byte 0x00000339
_0805AFA0:
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
_0805AFA6:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
