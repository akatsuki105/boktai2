	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov ip, r0
	ldr r6, _08023304 @ =0x0203B400
	ldr r5, _08023308 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _0802330C @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	movs r0, #0x7f
	ands r3, r0
	mov r0, ip
	adds r0, #0x50
	ldrh r0, [r0]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08023310 @ =0xFFFF0000
	mov r8, r2
	ldr r2, [sp, #0x10]
	mov r7, r8
	ands r2, r7
	orrs r2, r0
	str r2, [sp, #0x10]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r4, ip
	adds r4, #0x52
	movs r0, #0x1f
	ands r1, r0
	ldrh r4, [r4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	ldr r0, _08023314 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, ip
	adds r0, #0x54
	subs r3, #0x7f
	ldrh r0, [r0]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r0, #0xc
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08023304: .4byte 0x0203B400
_08023308: .4byte 0x030046B8
_0802330C: .4byte 0x000003FF
_08023310: .4byte 0xFFFF0000
_08023314: .4byte 0x0000FFFF
