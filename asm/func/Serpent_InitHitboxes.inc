	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r6, _0819022C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r6
	movs r2, #0x80
	orrs r0, r2
	ldr r5, _08190230 @ =0x0000FFFF
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r6
	orrs r0, r2
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	ldr r3, _08190234 @ =Serpent_OnHurt
	str r4, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	bl Enemy_RegisterHurtbox
	ldr r0, [sp, #0x18]
	ands r0, r6
	movs r2, #0x52
	orrs r0, r2
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	movs r5, #0
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	ldr r3, _08190238 @ =Serpent_OnHit
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r4, #0
	bl Enemy_InitAtkHitbox
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819022C: .4byte 0xFFFF0000
_08190230: .4byte 0x0000FFFF
_08190234: .4byte Serpent_OnHurt
_08190238: .4byte Serpent_OnHit
