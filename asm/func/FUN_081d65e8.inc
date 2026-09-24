	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	add r0, sp, #0x10
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _081D66A8 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #2]
	ldr r5, _081D66AC @ =0x0203B400
	ldr r7, _081D66B0 @ =0x030046B8
	mov ip, r7
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _081D66B4 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov sb, r1
	mov r7, sb
	ands r0, r7
	adds r0, #0xf
	ldr r1, _081D66B8 @ =0xFFFF0000
	mov sl, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D66BC @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ands r1, r7
	adds r1, #0xf
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r7, sl
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, ip
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r6, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r2, r6, #0
	mov r3, r8
	bl FUN_08014730
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D66A8: .4byte 0x05000002
_081D66AC: .4byte 0x0203B400
_081D66B0: .4byte 0x030046B8
_081D66B4: .4byte 0x000003FF
_081D66B8: .4byte 0xFFFF0000
_081D66BC: .4byte 0x0000FFFF
