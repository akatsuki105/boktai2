	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	add r2, sp, #0x10
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r2, #2]
	add r5, sp, #0x18
	ldr r7, _08028DAC @ =0x0203B400
	movs r0, #2
	mov sl, r0
	ldr r1, _08028DB0 @ =0x030046B8
	mov sb, r1
	ldr r6, _08028DB4 @ =0x000003FF
	movs r0, #3
	mov r8, r0
_08028CE4:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r5, #4]
	ldr r1, _08028DB8 @ =0xFFFF0000
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r5, #4]
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
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #3
	adds r2, r5, #0
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
	add r0, sp, #0x10
	movs r1, #3
	adds r2, r5, #0
	bl EmitSmoke
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _08028CE4
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028DAC: .4byte 0x0203B400
_08028DB0: .4byte 0x030046B8
_08028DB4: .4byte 0x000003FF
_08028DB8: .4byte 0xFFFF0000
