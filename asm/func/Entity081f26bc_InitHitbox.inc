	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r2, _081F1918 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081F191C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
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
	adds r7, r6, #0
	adds r7, #0x1c
	ldr r2, _081F1920 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r4, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081F1924 @ =FUN_081f1888
	adds r0, r7, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081F1928
	ldr r1, [r6]
	adds r1, #0x1c
	adds r0, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	b _081F1934
	.align 2, 0
_081F1918: .4byte 0xFFFF0000
_081F191C: .4byte 0x0000FFFF
_081F1920: .4byte 0x00002001
_081F1924: .4byte FUN_081f1888
_081F1928:
	ldr r1, [r6]
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
_081F1934:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
