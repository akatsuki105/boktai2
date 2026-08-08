	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov sl, r1
	adds r7, r2, #0
	mov r8, r3
	ldr r2, _080DE788 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _080DE78C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	adds r4, r6, #0
	adds r4, #0x3c
	ldr r2, _080DE790 @ =0x00002401
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	mov r0, r8
	str r0, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sl
	adds r2, r7, #0
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _080DE794 @ =FUN_080de3b4
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0x1c
	adds r0, r0, r6
	mov r8, r0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r4, #0x50
	ldr r2, _080DE798 @ =0x00004001
	mov r0, sb
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	ldr r1, [sp, #0x40]
	ldr r2, [sp, #0x44]
	ldr r3, [sp, #0x48]
	bl FUN_08236514
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080DE79C @ =FUN_080de52c
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
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
_080DE788: .4byte 0xFFFF0000
_080DE78C: .4byte 0x0000FFFF
_080DE790: .4byte 0x00002401
_080DE794: .4byte FUN_080de3b4
_080DE798: .4byte 0x00004001
_080DE79C: .4byte FUN_080de52c
