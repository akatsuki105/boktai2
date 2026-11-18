	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819FDD4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FDD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r7, r1, #0
	ldr r2, _0819FDDC @ =0x0000095C
	adds r4, r4, r2
	movs r6, #2
_0819FD70:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r7, [sp, #8]
	adds r0, r4, #0
	ldr r2, _0819FDE0 @ =0x00002401
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0819FDE4 @ =0x0000022A
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0819FDE8 @ =0x00000232
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	adds r1, r5, #0
	adds r1, #8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _0819FDEC @ =Ax_OnHit
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r4, #0x50
	subs r6, #1
	cmp r6, #0
	bge _0819FD70
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FDD4: .4byte 0xFFFF0000
_0819FDD8: .4byte 0x0000FFFF
_0819FDDC: .4byte 0x0000095C
_0819FDE0: .4byte 0x00002401
_0819FDE4: .4byte 0x0000022A
_0819FDE8: .4byte 0x00000232
_0819FDEC: .4byte Ax_OnHit
