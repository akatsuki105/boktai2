	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r3, r0, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0821D940
	ldr r2, _0821D934 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _0821D938 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
	adds r4, r0, #0
	orrs r4, r1
	ands r2, r5
	ldr r0, _0821D93C @ =0x0000FF80
	b _0821D95A
	.align 2, 0
_0821D934: .4byte 0xFFFF0000
_0821D938: .4byte 0x0000FFFF
_0821D93C: .4byte 0x0000FF80
_0821D940:
	ldr r2, _0821D9E8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	ldr r1, _0821D9EC @ =0x0000FF80
	orrs r0, r1
	adds r1, #0x7f
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
	adds r4, r0, #0
	orrs r4, r1
	ands r2, r5
	movs r0, #0x40
_0821D95A:
	adds r5, r2, #0
	orrs r5, r0
	adds r3, #0x50
	str r3, [sp, #0x10]
	ldr r0, _0821D9F0 @ =0x030046B8
	mov sl, r0
	ldr r1, _0821D9F4 @ =0x000003FF
	mov sb, r1
	movs r2, #0x7f
	mov r8, r2
	movs r7, #1
	add r6, sp, #8
_0821D972:
	mov r0, sl
	ldr r1, [r0]
	adds r1, #1
	mov r2, sb
	ands r1, r2
	lsls r0, r1, #1
	ldr r2, _0821D9F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, r4, r0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r2, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r2
	str r0, [sp, #8]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0821D9F8 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, r5, r0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6, #4]
	ldr r2, _0821D9E8 @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [r6, #4]
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r1, sp, #8
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0a0
	subs r7, #1
	cmp r7, #0
	bge _0821D972
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821D9E8: .4byte 0xFFFF0000
_0821D9EC: .4byte 0x0000FF80
_0821D9F0: .4byte 0x030046B8
_0821D9F4: .4byte 0x000003FF
_0821D9F8: .4byte 0x0203B400
