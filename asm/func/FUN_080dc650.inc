	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r2, _080DC74C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _080DC750 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r6, sp, #0x14
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	movs r1, #0x3c
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	ldrh r1, [r2]
	ldr r2, _080DC754 @ =0x00002003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sb
	movs r3, #0
	bl Hitbox_Init
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r5, r7, #0
	adds r5, #0x1c
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC758 @ =FUN_080dc4a8
	mov r0, sb
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	mov r1, r8
	strh r1, [r6]
	strh r0, [r6, #2]
	strh r1, [r6, #4]
	adds r4, r7, #0
	adds r4, #0x8c
	mov r2, sl
	ldrh r1, [r2]
	ldr r2, _080DC75C @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC760 @ =FUN_080dc614
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC74C: .4byte 0xFFFF0000
_080DC750: .4byte 0x0000FFFF
_080DC754: .4byte 0x00002003
_080DC758: .4byte FUN_080dc4a8
_080DC75C: .4byte 0x00004001
_080DC760: .4byte FUN_080dc614
