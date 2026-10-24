	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	mov sl, r3
	ldr r5, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r3, [sp, #0x38]
	adds r0, #0x18
	adds r1, r7, #0
	adds r1, #0x44
	mov r2, r8
	bl FUN_080d83a8
	adds r4, r7, #0
	adds r4, #0x60
	str r5, [sp]
	str r6, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, sl
	bl Entity080d84f8_InitHitbox
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	mov r2, sp
	ldrh r2, [r2, #0x3c]
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
