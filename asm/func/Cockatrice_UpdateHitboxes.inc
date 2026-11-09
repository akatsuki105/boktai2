	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	movs r1, #0x40
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815E888
	b _0815E9A0
_0815E888:
	movs r1, #2
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r0, r2, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815E89C
	movs r0, #1
	b _0815E89E
_0815E89C:
	movs r0, #0
_0815E89E:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815E93C
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r1, _0815E92C @ =0x00000226
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _0815E930 @ =0x0000022E
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	movs r5, #0x90
	lsls r5, r5, #2
	adds r0, r6, r5
	ldr r0, [r0]
	str r0, [sp]
	subs r5, #0xa
	adds r0, r6, r5
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	bl Hitbox_SetAttack
	movs r0, #0x10
	movs r5, #0
	strh r0, [r4, #0xa]
	ldr r3, _0815E934 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0815E938 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r2, r6, #0
	adds r2, #0xd8
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r0, r6, #0
	adds r0, #0xec
	strh r5, [r0]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	rsbs r0, r0, #0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r1, r6, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xf0
	strh r5, [r0]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	b _0815E99E
	.align 2, 0
_0815E92C: .4byte 0x00000226
_0815E930: .4byte 0x0000022E
_0815E934: .4byte 0xFFFF0000
_0815E938: .4byte 0x0000FFFF
_0815E93C:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x10
	strh r0, [r4, #0xa]
	movs r1, #0x40
	add r0, sp, #8
	strh r1, [r0]
	movs r3, #0x80
	strh r3, [r0, #2]
	strh r1, [r0, #4]
	adds r2, r6, #0
	adds r2, #0xd8
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r0, r6, #0
	adds r0, #0xec
	strh r5, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
_0815E99E:
	strh r0, [r2, #6]
_0815E9A0:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
