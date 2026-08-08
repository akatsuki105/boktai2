	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	ldr r6, _080F8BA0 @ =0xFFFF0000
	ldr r4, [sp, #0xc]
	ands r4, r6
	ldr r5, _080F8BA4 @ =0x0000FFF4
	orrs r4, r5
	str r4, [sp, #0xc]
	ldr r0, _080F8BA8 @ =0x0203B400
	mov sb, r0
	ldr r7, _080F8BAC @ =0x030046B8
	ldr r1, [r7]
	adds r1, #1
	ldr r0, _080F8BB0 @ =0x000003FF
	mov r8, r0
	ands r1, r0
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	movs r0, #7
	mov ip, r0
	mov r0, ip
	ands r2, r0
	lsls r2, r2, #0x10
	ldr r3, _080F8BB4 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r5
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ands r2, r6
	movs r4, #0x18
	orrs r2, r4
	str r2, [sp, #0x14]
	adds r1, #1
	mov r5, r8
	ands r1, r5
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	mov r5, ip
	ands r0, r5
	adds r0, #3
	lsls r0, r0, #0x10
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #0x14]
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ands r0, r6
	orrs r0, r4
	str r0, [r5, #4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sb
	ldrh r4, [r1]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	mov r0, sl
	bl FUN_080f8abc
	adds r1, r0, #0
	movs r0, #8
	add sl, r0
	str r5, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	movs r0, #0x3f
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r2, sl
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F8BA0: .4byte 0xFFFF0000
_080F8BA4: .4byte 0x0000FFF4
_080F8BA8: .4byte 0x0203B400
_080F8BAC: .4byte 0x030046B8
_080F8BB0: .4byte 0x000003FF
_080F8BB4: .4byte 0x0000FFFF
