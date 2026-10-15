	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r5, r1, #0
	mov r8, r3
	ldr r6, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	ldr r3, _080D8480 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r4, #0x80
	orrs r0, r4
	ldr r1, _080D8484 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	ldr r3, _080D8488 @ =0x00002001
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r3, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	ldr r2, [sp, #0x38]
	movs r3, #0x40
	bl Hitbox_SetAttack
	adds r0, r5, #0
	movs r1, #0
	mov r2, sb
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8480: .4byte 0xFFFF0000
_080D8484: .4byte 0x0000FFFF
_080D8488: .4byte 0x00002001
