	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r4, [sp, #0x28]
	ldr r2, _080E3A10 @ =0x00002401
	movs r0, #0x94
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrh r1, [r7]
	movs r0, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	mov r6, r8
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	lsls r3, r4, #1
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r7, r2
	adds r0, r0, r3
	ldrh r2, [r0]
	lsls r4, r4, #2
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r0, r7, r6
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [sp]
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r0, r7, r4
	adds r0, r0, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	adds r1, r7, #0
	adds r1, #8
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	mov r1, sb
	ldr r2, [sp, #0x2c]
	bl FUN_0823651c
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3A10: .4byte 0x00002401
