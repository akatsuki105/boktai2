	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r7, r0, #6
	adds r7, #0x40
	ands r7, r3
	ldr r2, _08108278 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810827C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108280 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r3
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	cmp r0, #0x7f
	bgt _081080F6
	movs r0, #1
	mov sb, r0
_081080F6:
	movs r1, #8
	adds r1, r1, r4
	mov sl, r1
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0xa0
	adds r6, r4, r1
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	movs r0, #0x91
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	str r0, [sp, #0x10]
	adds r1, #8
	adds r4, r4, r1
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #2
	bl Entity081f959c_Spawn
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #3
	bl Entity081f959c_Spawn
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #4
	bl Entity081f959c_Spawn
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #5
	bl Entity081f959c_Spawn
	movs r3, #2
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl Entity081f959c_Spawn
	movs r3, #3
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl Entity081f959c_Spawn
	movs r3, #4
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl Entity081f959c_Spawn
	movs r3, #5
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl Entity081f959c_Spawn
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08108278: .4byte 0x030046B8
_0810827C: .4byte 0x000003FF
_08108280: .4byte 0x0203B400
