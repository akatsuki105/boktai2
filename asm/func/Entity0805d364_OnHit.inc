	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B9B0 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r5, #0x3e]
	adds r4, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl CreateDamageNumber
	ldrh r0, [r5, #0x3e]
	bl FUN_080298b8
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805B9AC: .4byte 0xFFFF0000
_0805B9B0: .4byte 0x0000FFFF
