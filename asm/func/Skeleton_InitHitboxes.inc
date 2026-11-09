	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x4c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r4, _08103608 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r6, #0x80
	orrs r0, r6
	ldr r1, _0810360C @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	mov r8, r1
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r6
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	ldr r2, _08103610 @ =0x0000410B
	movs r1, #0xcb
	lsls r1, r1, #3
	add r1, sl
	ldr r0, _08103614 @ =Skeleton_OnDodgeHurt
	str r0, [sp]
	str r5, [sp, #4]
	str r2, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	bl Enemy_RegisterHitbox
	ldr r0, [sp, #0x1c]
	ands r0, r4
	orrs r0, r6
	mov r1, sb
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r6
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08103618 @ =Skeleton_OnHurt
	str r5, [sp]
	adds r0, r5, #0
	bl Enemy_RegisterHurtbox
	ldr r0, [sp, #0x2c]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	mov r1, sb
	ands r0, r1
	movs r6, #0xc8
	lsls r6, r6, #0xf
	orrs r0, r6
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x34]
	add r2, sp, #0x34
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0810361C @ =Skeleton_OnHit
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl Enemy_InitAtkHitbox
	str r6, [sp, #0x3c]
	add r2, sp, #0x3c
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	mov r1, r8
	str r1, [sp, #0x44]
	add r3, sp, #0x44
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r0, #0xd5
	lsls r0, r0, #3
	add sl, r0
	ldr r0, _08103620 @ =Skeleton_OnAtkHitbox2Hit
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r5, #0
	mov r1, sl
	bl Enemy_InitHitboxWithAtk
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103608: .4byte 0xFFFF0000
_0810360C: .4byte 0x0000FFFF
_08103610: .4byte 0x0000410B
_08103614: .4byte Skeleton_OnDodgeHurt
_08103618: .4byte Skeleton_OnHurt
_0810361C: .4byte Skeleton_OnHit
_08103620: .4byte Skeleton_OnAtkHitbox2Hit
