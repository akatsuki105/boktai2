	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _08202EA4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08202EA8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x8c
	ldr r2, _08202EAC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _08202EB0 @ =InkBallShot_OnHit
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202EA4: .4byte 0xFFFF0000
_08202EA8: .4byte 0x0000FFFF
_08202EAC: .4byte 0x00002001
_08202EB0: .4byte InkBallShot_OnHit
