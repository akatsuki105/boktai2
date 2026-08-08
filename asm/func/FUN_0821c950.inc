	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov sl, r1
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r5, r0
	ldr r2, _0821CA3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _0821CA40 @ =0x0000FFFF
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
	ldr r2, _0821CA44 @ =0x00005101
	movs r6, #0x10
	str r6, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x50
	adds r0, r0, r5
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0821CA48 @ =FUN_0821c6c4
	adds r0, r7, #0
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r2, _0821CA4C @ =0x00000802
	adds r0, r7, #0
	mov r1, sl
	movs r3, #1
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r7, r5, r3
	movs r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	mov r3, sb
	strh r0, [r3, #2]
	strh r1, [r3, #4]
	strh r2, [r4]
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	ldr r2, _0821CA50 @ =0x00004003
	str r6, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0821CA54 @ =0x0821C741
	adds r0, r7, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821CA3C: .4byte 0xFFFF0000
_0821CA40: .4byte 0x0000FFFF
_0821CA44: .4byte 0x00005101
_0821CA48: .4byte FUN_0821c6c4
_0821CA4C: .4byte 0x00000802
_0821CA50: .4byte 0x00004003
_0821CA54: .4byte 0x0821C741
