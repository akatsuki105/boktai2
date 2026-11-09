	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	adds r4, r7, #0
	adds r4, #0x68
	adds r2, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #1
	bl AuxSprite_Setup
	movs r6, #0
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x84
	adds r0, r0, r7
	mov r8, r0
	str r6, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805F0B4 @ =0x05000002
	bl CpuSet
	adds r5, r7, #0
	adds r5, #0x18
	ldr r2, _0805F0B8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x64
	orrs r0, r4
	ldr r1, _0805F0BC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	str r6, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805F0C0 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805F0C4 @ =Entity0805f2dc_OnHit
	adds r0, r5, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	str r6, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x32
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F0B4: .4byte 0x05000002
_0805F0B8: .4byte 0xFFFF0000
_0805F0BC: .4byte 0x0000FFFF
_0805F0C0: .4byte 0x00002001
_0805F0C4: .4byte Entity0805f2dc_OnHit
