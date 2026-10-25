	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r3, r1, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r4, _08036C04 @ =0x0203B400
	mov sb, r4
	ldr r5, _08036C08 @ =0x030046B8
	ldr r4, [r5]
	adds r4, #1
	ldr r0, _08036C0C @ =0x000003FF
	mov r8, r0
	ands r4, r0
	lsls r0, r4, #1
	add r0, sb
	ldrh r1, [r0]
	add r0, sp, #0x18
	ldrh r0, [r0]
	subs r0, #0x40
	movs r5, #0x7f
	mov sl, r5
	mov r5, sl
	ands r1, r5
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08036C10 @ =0xFFFF0000
	mov ip, r1
	ldr r6, [sp, #0x18]
	ands r6, r1
	orrs r6, r0
	str r6, [sp, #0x18]
	adds r4, #1
	mov r5, r8
	ands r4, r5
	lsls r0, r4, #1
	add r0, sb
	ldrh r5, [r0]
	asrs r1, r6, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r5, r0
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r0, _08036C14 @ =0x0000FFFF
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r4, #1
	mov r0, r8
	ands r4, r0
	ldr r1, _08036C08 @ =0x030046B8
	str r4, [r1]
	lsls r4, r4, #1
	add r4, sb
	ldrh r4, [r4]
	add r0, sp, #0x18
	ldrh r1, [r0, #4]
	subs r1, #0x40
	mov r5, sl
	ands r4, r5
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x1c]
	mov r4, ip
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, #6
	str r0, [sp]
	ldr r0, _08036C18 @ =0x00003001
	str r0, [sp, #4]
	movs r0, #0x30
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r2, #0x10
	bl FUN_08015c28
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036C04: .4byte 0x0203B400
_08036C08: .4byte 0x030046B8
_08036C0C: .4byte 0x000003FF
_08036C10: .4byte 0xFFFF0000
_08036C14: .4byte 0x0000FFFF
_08036C18: .4byte 0x00003001
