	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _0813743C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _08137440 @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r5
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08137444 @ =Centipede_OnHurt
	mov r0, r8
	str r0, [sp]
	add r1, sp, #8
	bl Enemy_RegisterHurtbox
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08137448 @ =Centipede_OnHit
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	bl Enemy_InitAtkHitbox
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813743C: .4byte 0xFFFF0000
_08137440: .4byte 0x0000FFFF
_08137444: .4byte Centipede_OnHurt
_08137448: .4byte Centipede_OnHit
