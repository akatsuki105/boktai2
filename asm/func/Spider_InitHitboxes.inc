	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r4, _0813017C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r1, #0x80
	orrs r0, r1
	ldr r2, _08130180 @ =0x0000FFFF
	mov r8, r2
	ands r0, r2
	movs r5, #0x80
	lsls r5, r5, #0x10
	orrs r0, r5
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08130184 @ =Spider_OnHurt
	str r6, [sp]
	ldr r0, _08130188 @ =0x0000510B
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	bl Enemy_RegisterHurtboxWithFlags
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0813018C @ =Spider_OnHit
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	bl Enemy_InitAtkHitbox
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813017C: .4byte 0xFFFF0000
_08130180: .4byte 0x0000FFFF
_08130184: .4byte Spider_OnHurt
_08130188: .4byte 0x0000510B
_0813018C: .4byte Spider_OnHit
