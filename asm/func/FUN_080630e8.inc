	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _0806310C @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08063114
	ldr r2, _08063110 @ =0x000004C4
	adds r0, r7, r2
	bl FUN_082466ec
	b _080631F2
	.align 2, 0
_0806310C: .4byte 0x000004C5
_08063110: .4byte 0x000004C4
_08063114:
	cmp r0, #2
	bne _08063122
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0806312E
_08063122:
	cmp r0, #3
	bne _0806312E
	movs r0, #0x9a
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806312E:
	ldr r1, _08063204 @ =0x000004CC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r3]
	ldr r6, _08063208 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r3, #2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0806320C @ =0x0000FFFF
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r3, #4]
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _08063210 @ =0x0203B400
	ldr r1, _08063214 @ =0x030046B8
	mov sl, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _08063218 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x14]
	ands r3, r6
	orrs r3, r0
	str r3, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	mov r0, r8
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r1, [r2]
	mov r2, sb
	ands r1, r2
	subs r1, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x1c]
	ands r0, r6
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	ldr r2, _0806321C @ =0x000004C4
	adds r0, r7, r2
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #3
	add r2, sp, #0xc
	bl FUN_08246728
_080631F2:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063204: .4byte 0x000004CC
_08063208: .4byte 0xFFFF0000
_0806320C: .4byte 0x0000FFFF
_08063210: .4byte 0x0203B400
_08063214: .4byte 0x030046B8
_08063218: .4byte 0x000003FF
_0806321C: .4byte 0x000004C4
