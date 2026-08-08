	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r7, r5, r0
	ldr r2, _0821CB74 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0821CB78 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov sb, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	movs r1, #0x10
	str r1, [sp]
	add r2, sp, #0xc
	str r2, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0821CB7C @ =0x00002001
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x50
	adds r3, r3, r5
	mov sl, r3
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldr r0, _0821CB80 @ =0x0821C745
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r1, _0821CB84 @ =0x000003BE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0
	str r6, [sp]
	ldr r3, _0821CB88 @ =0x000003C2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x93
	lsls r0, r0, #2
	adds r7, r5, r0
	movs r1, #0xa0
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	mov r2, sb
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	strh r6, [r4]
	strh r0, [r4, #2]
	strh r6, [r4, #4]
	movs r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0821CB7C @ =0x00002001
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	bl FUN_0823651c
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0821CB8C @ =0x000003C6
	adds r0, r5, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r5, r5, r0
	movs r3, #0
	ldrsh r0, [r5, r3]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821CB74: .4byte 0xFFFF0000
_0821CB78: .4byte 0x0000FFFF
_0821CB7C: .4byte 0x00002001
_0821CB80: .4byte 0x0821C745
_0821CB84: .4byte 0x000003BE
_0821CB88: .4byte 0x000003C2
_0821CB8C: .4byte 0x000003C6
