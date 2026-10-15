	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov sb, r0
	mov r8, r1
	adds r7, r2, #0
	movs r4, #0
	strb r7, [r1]
	mov r0, r8
	movs r1, #0
	bl Entity5DA5Elem_SetState
	mov r0, r8
	strb r4, [r0, #3]
	mov r5, r8
	adds r5, #0x58
	mov r6, sb
	adds r6, #0x4c
	movs r0, #2
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	adds r0, #0x44
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	adds r2, r7, #2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl MainSprite_SetAnim
	subs r5, #0x50
	subs r0, r7, #1
	cmp r0, #1
	bhi _08008A3C
	ldr r2, _08008A34 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08008A38 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x60
	b _08008A58
	.align 2, 0
_08008A34: .4byte 0xFFFF0000
_08008A38: .4byte 0x0000FFFF
_08008A3C:
	ldr r2, _08008AD4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _08008AD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x18
_08008A58:
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, _08008ADC @ =0x085AA690
	lsls r2, r7, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r0, #0x10
	lsls r0, r0, #0x10
	ldr r4, _08008AD4 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, _08008AE0 @ =0x085AA698
	adds r2, r2, r0
	ldrh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldr r2, _08008AE4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _08008AE8 @ =Entity5DA5Elem_OnHit
	adds r0, r5, #0
	mov r2, r8
	bl Hitbox_SetHandler
	mov r1, sb
	adds r1, #0x3c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008AD4: .4byte 0xFFFF0000
_08008AD8: .4byte 0x0000FFFF
_08008ADC: .4byte 0x085AA690
_08008AE0: .4byte 0x085AA698
_08008AE4: .4byte 0x00004001
_08008AE8: .4byte Entity5DA5Elem_OnHit
