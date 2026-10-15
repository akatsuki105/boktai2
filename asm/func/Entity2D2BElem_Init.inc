	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0xe4
	adds r0, r0, r7
	mov sb, r0
	adds r4, #0x20
	str r4, [r0]
	add r5, sp, #0x14
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0800804C @ =0x05000002
	bl CpuSet
	adds r6, r7, #0
	adds r6, #0x34
	movs r0, #2
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_Setup
	mov r0, sb
	ldr r1, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r5, r7, #0
	adds r5, #0x94
	ldr r2, _08008050 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08008054 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x24]
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r7, #0x10]
	ldr r2, _08008058 @ =0x00004001
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0800805C @ =Entity2D2BElem_OnHit
	adds r0, r5, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800804C: .4byte 0x05000002
_08008050: .4byte 0xFFFF0000
_08008054: .4byte 0x0000FFFF
_08008058: .4byte 0x00004001
_0800805C: .4byte Entity2D2BElem_OnHit
