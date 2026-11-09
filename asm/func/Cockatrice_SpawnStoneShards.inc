	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	adds r0, r1, #0
	ldr r1, _0815CA08 @ =0xFFFF0000
	mov sl, r1
	ldr r5, [sp, #0xc]
	ands r5, r1
	ldr r3, _0815CA0C @ =0x0000FFF9
	mov ip, r3
	orrs r5, r3
	str r5, [sp, #0xc]
	ldr r1, _0815CA10 @ =0x0203B400
	mov sb, r1
	ldr r7, _0815CA14 @ =0x030046B8
	ldr r4, [r7]
	adds r4, #1
	ldr r3, _0815CA18 @ =0x000003FF
	mov r8, r3
	ands r4, r3
	lsls r1, r4, #1
	add r1, sb
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r3, #0x14
	lsls r3, r3, #0x10
	ldr r6, _0815CA1C @ =0x0000FFFF
	adds r1, r6, #0
	ands r1, r5
	orrs r1, r3
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	mov r5, sl
	ands r1, r5
	mov r3, ip
	orrs r1, r3
	str r1, [sp, #0x10]
	adds r4, #1
	mov r5, r8
	ands r4, r5
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1]
	movs r3, #3
	mov ip, r3
	mov r5, ip
	ands r1, r5
	adds r1, #0xf
	ldr r5, [sp, #0x14]
	mov r3, sl
	ands r5, r3
	orrs r5, r1
	str r5, [sp, #0x14]
	adds r4, #1
	mov r1, r8
	ands r4, r1
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1]
	movs r3, #7
	ands r1, r3
	adds r1, #0xf
	lsls r1, r1, #0x10
	ands r6, r5
	orrs r6, r1
	str r6, [sp, #0x14]
	adds r4, #1
	mov r3, r8
	ands r4, r3
	str r4, [r7]
	lsls r4, r4, #1
	add r4, sb
	ldrh r3, [r4]
	mov r5, ip
	ands r3, r5
	adds r3, #0xf
	add r4, sp, #0x14
	ldr r1, [r4, #4]
	mov r5, sl
	ands r1, r5
	orrs r1, r3
	str r1, [r4, #4]
	adds r2, #8
	str r4, [sp]
	movs r1, #0x2d
	str r1, [sp, #4]
	movs r1, #0x1f
	str r1, [sp, #8]
	movs r1, #3
	add r3, sp, #0xc
	bl ScatterEffect_Spawn
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CA08: .4byte 0xFFFF0000
_0815CA0C: .4byte 0x0000FFF9
_0815CA10: .4byte 0x0203B400
_0815CA14: .4byte 0x030046B8
_0815CA18: .4byte 0x000003FF
_0815CA1C: .4byte 0x0000FFFF
