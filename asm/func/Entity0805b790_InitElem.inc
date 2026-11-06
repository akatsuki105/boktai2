	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	movs r0, #0
	movs r5, #0
	strb r0, [r7, #2]
	movs r6, #1
	strb r6, [r7, #1]
	strh r5, [r7, #4]
	strb r0, [r7, #3]
	adds r4, r7, #0
	adds r4, #0x60
	adds r2, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #3
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0x7c
	adds r0, r0, r7
	mov r8, r0
	str r5, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805B2E0 @ =0x05000002
	bl CpuSet
	subs r4, #0x50
	ldr r2, _0805B2E4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r5, #0x1e
	orrs r0, r5
	ldr r1, _0805B2E8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r3, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805B2EC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805B2F0 @ =Entity0805b790_OnHit
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	str r6, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #0x10
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B2E0: .4byte 0x05000002
_0805B2E4: .4byte 0xFFFF0000
_0805B2E8: .4byte 0x0000FFFF
_0805B2EC: .4byte 0x00002001
_0805B2F0: .4byte Entity0805b790_OnHit
