	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #8
	adds r2, r1, #0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08085B20 @ =0x0203B400
	mov r8, r0
	ldr r1, _08085B24 @ =0x030046B8
	mov ip, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r6, _08085B28 @ =0x000003FF
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0xf
	movs r4, #0x1f
	mov sb, r4
	mov r4, sb
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085B2C @ =0xFFFF0000
	mov sl, r1
	ldr r5, [sp]
	ands r5, r1
	orrs r5, r0
	str r5, [sp]
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r4, [r0]
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0xf
	mov r0, sb
	ands r4, r0
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r4, sl
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	adds r3, #1
	ands r3, r6
	mov r0, ip
	str r3, [r0]
	lsls r3, r3, #1
	add r3, r8
	ldrh r3, [r3]
	asrs r1, r5, #0x10
	subs r1, #0x10
	movs r0, #0x3f
	ands r3, r0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08085B30 @ =0x0000FFFF
	ands r0, r5
	orrs r0, r1
	str r0, [sp]
	movs r0, #1
	mov r1, sp
	bl FUN_080155e4
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085B20: .4byte 0x0203B400
_08085B24: .4byte 0x030046B8
_08085B28: .4byte 0x000003FF
_08085B2C: .4byte 0xFFFF0000
_08085B30: .4byte 0x0000FFFF
