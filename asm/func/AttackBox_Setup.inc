	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r7, r3, #0
	ldr r3, [sp, #0x38]
	adds r6, r5, #0
	ldr r2, _080DD7C8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080DD7CC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080DD7D0 @ =0x00002001
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bne _080DD7D8
	ldr r0, _080DD7D4 @ =0x00240004
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
	b _080DD7EC
	.align 2, 0
_080DD7C8: .4byte 0xFFFF0000
_080DD7CC: .4byte 0x0000FFFF
_080DD7D0: .4byte 0x00002001
_080DD7D4: .4byte 0x00240004
_080DD7D8:
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
_080DD7EC:
	ldr r0, _080DD814 @ =0x00003246
	strh r0, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD814: .4byte 0x00003246
