	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r5, _08178068 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	movs r1, #0x80
	orrs r0, r1
	ldr r2, _0817806C @ =0x0000FFFF
	mov r8, r2
	ands r0, r2
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _08178070 @ =Sandworm_OnHurt
	str r4, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	bl Enemy_RegisterHurtbox
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r2, #0x52
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _08178074 @ =Sandworm_OnHit
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r4, #0
	bl Enemy_InitAtkHitbox
	movs r2, #0x94
	lsls r2, r2, #1
	adds r4, r4, r2
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08178068: .4byte 0xFFFF0000
_0817806C: .4byte 0x0000FFFF
_08178070: .4byte Sandworm_OnHurt
_08178074: .4byte Sandworm_OnHit
