	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r1, r0, r1
	str r1, [sp, #0x1c]
	add r0, sp, #0x10
	mov sl, r0
	ldr r7, _08028BF4 @ =0x0203B400
	movs r1, #2
	str r1, [sp, #0x18]
	ldr r0, _08028BF8 @ =0x030046B8
	mov sb, r0
	ldr r6, _08028BFC @ =0x000003FF
	movs r1, #3
	mov r8, r1
_08028B28:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r1, #0xa4
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sl
	ldr r0, [r1, #4]
	ldr r1, _08028C00 @ =0xFFFF0000
	ands r0, r1
	movs r1, #0xa4
	orrs r0, r1
	mov r1, sl
	str r0, [r1, #4]
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	ldr r5, [sp, #0x1c]
	adds r5, #0x20
	str r2, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #3
	add r2, sp, #0x10
	bl EmitSmoke
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	str r2, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #3
	add r2, sp, #0x10
	bl EmitSmoke
	ldr r0, [sp, #0x18]
	subs r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0
	bge _08028B28
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028BF4: .4byte 0x0203B400
_08028BF8: .4byte 0x030046B8
_08028BFC: .4byte 0x000003FF
_08028C00: .4byte 0xFFFF0000
