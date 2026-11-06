	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0
	mov r8, r0
	stm r1!, {r0}
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805D67C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0xc
	adds r4, #0x1c
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Setup
	adds r5, r6, #0
	adds r5, #0x38
	ldr r2, _0805D680 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #8
	orrs r0, r4
	ldr r1, _0805D684 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	mov r0, r8
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805D688 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0805D68C @ =Entity0805d79c_OnHit
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	mov r0, r8
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805D67C: .4byte 0x05000002
_0805D680: .4byte 0xFFFF0000
_0805D684: .4byte 0x0000FFFF
_0805D688: .4byte 0x00002001
_0805D68C: .4byte Entity0805d79c_OnHit
