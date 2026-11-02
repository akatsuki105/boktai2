	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x18]
	ldr r2, _08003A44 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08003A48 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	add r5, sp, #0x10
	ldr r0, _08003A4C @ =0x0203B400
	mov sb, r0
	ldr r1, _08003A50 @ =0x030046B8
	mov r8, r1
	ldr r7, _08003A54 @ =0x000003FF
	adds r6, r2, #0
	movs r2, #2
	str r2, [sp, #0x1c]
	movs r3, #0xff
	mov sl, r3
	adds r4, r5, #0
_08003A2A:
	ldr r2, [sp, #0x18]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	beq _08003AA0
	cmp r0, #1
	bgt _08003A58
	cmp r0, #0
	beq _08003A62
	b _08003B40
	.align 2, 0
_08003A44: .4byte 0xFFFF0000
_08003A48: .4byte 0x0000FFFF
_08003A4C: .4byte 0x0203B400
_08003A50: .4byte 0x030046B8
_08003A54: .4byte 0x000003FF
_08003A58:
	cmp r0, #2
	beq _08003ABA
	cmp r0, #3
	beq _08003AF8
	b _08003B40
_08003A62:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	adds r1, #0x78
	movs r0, #0xf
	ands r2, r0
	adds r1, r1, r2
	b _08003B34
_08003AA0:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	subs r1, #0x78
	movs r0, #0xf
	ands r3, r0
	subs r1, r1, r3
	b _08003B10
_08003ABA:
	mov r3, r8
	ldr r2, [r3]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r1, #0x80
	mov r3, sl
	ands r0, r3
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sb
	ldrh r2, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x78
	movs r0, #0xf
	ands r2, r0
	subs r1, r1, r2
	b _08003B34
_08003AF8:
	mov r1, r8
	ldr r2, [r1]
	adds r2, #1
	ands r2, r7
	lsls r0, r2, #1
	add r0, sb
	ldrh r3, [r0]
	ldrh r1, [r5]
	adds r1, #0x78
	movs r0, #0xf
	ands r3, r0
	adds r1, r1, r3
_08003B10:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r7
	mov r3, r8
	str r2, [r3]
	lsls r2, r2, #1
	add r2, sb
	ldrh r0, [r2]
	ldrh r1, [r4, #4]
	subs r1, #0x80
	mov r2, sl
	ands r0, r2
	adds r1, r1, r0
_08003B34:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
_08003B40:
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	ldr r3, [sp, #0x1c]
	subs r3, #1
	str r3, [sp, #0x1c]
	cmp r3, #0
	blt _08003B60
	b _08003A2A
_08003B60:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
