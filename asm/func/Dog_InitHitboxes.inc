	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x3c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r4, _0814ABFC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r6, #0x40
	orrs r0, r6
	ldr r2, _0814AC00 @ =0x0000FFFF
	mov sl, r2
	ands r0, r2
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
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0814AC04 @ =Dog_OnHurt
	str r5, [sp]
	adds r0, r5, #0
	add r1, sp, #0xc
	bl Enemy_RegisterHurtbox
	ldr r0, [sp, #0x1c]
	ands r0, r4
	orrs r0, r6
	mov r2, sl
	ands r0, r2
	movs r1, #0xf0
	lsls r1, r1, #0xf
	mov sl, r1
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r6
	str r0, [r1, #4]
	mov r2, r8
	str r2, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0814AC08 @ =Dog_OnHit
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl Enemy_InitAtkHitbox
	mov r0, sl
	str r0, [sp, #0x2c]
	add r2, sp, #0x2c
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	mov r1, r8
	str r1, [sp, #0x34]
	add r3, sp, #0x34
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r0, #0xcb
	lsls r0, r0, #3
	add sb, r0
	ldr r0, _0814AC0C @ =FUN_0814b89c
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	bl Enemy_InitHitboxWithAtk
	movs r0, #0x80
	lsls r0, r0, #1
	mov r2, sb
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814ABFC: .4byte 0xFFFF0000
_0814AC00: .4byte 0x0000FFFF
_0814AC04: .4byte Dog_OnHurt
_0814AC08: .4byte Dog_OnHit
_0814AC0C: .4byte FUN_0814b89c
