	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812927E
	b _081293E6
_0812927E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812928C
	b _081293E6
_0812928C:
	movs r0, #0x80
	lsls r0, r0, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081292A0
	b _081293E6
_081292A0:
	movs r3, #0x10
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08129334
	ldr r3, _08129318 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0812931C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _08129320 @ =0x00002201
	strh r1, [r0, #6]
	ldr r4, _08129324 @ =0x00000226
	adds r1, r5, r4
	ldrh r1, [r1]
	ldr r3, _08129328 @ =0x0000022E
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r4, #0x1a
	adds r3, r5, r4
	ldr r3, [r3]
	ldr r4, _0812932C @ =0x00200004
	orrs r3, r4
	str r3, [sp]
	ldr r4, _08129330 @ =0x00000236
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x80
	lsls r0, r0, #7
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081293E6
	.align 2, 0
_08129318: .4byte 0xFFFF0000
_0812931C: .4byte 0x0000FFFF
_08129320: .4byte 0x00002201
_08129324: .4byte 0x00000226
_08129328: .4byte 0x0000022E
_0812932C: .4byte 0x00200004
_08129330: .4byte 0x00000236
_08129334:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0812939C
	movs r2, #0x20
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	strh r3, [r0, #0xa]
	ldr r1, _0812938C @ =0x00002201
	strh r1, [r0, #6]
	ldr r3, _08129390 @ =0x00000226
	adds r1, r5, r3
	ldrh r1, [r1]
	ldr r4, _08129394 @ =0x0000022E
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #0x12
	adds r3, r5, r4
	ldr r3, [r3]
	movs r4, #0x80
	lsls r4, r4, #0xa
	orrs r3, r4
	str r3, [sp]
	ldr r4, _08129398 @ =0x00000236
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
	b _081293E6
	.align 2, 0
_0812938C: .4byte 0x00002201
_08129390: .4byte 0x00000226
_08129394: .4byte 0x0000022E
_08129398: .4byte 0x00000236
_0812939C:
	movs r2, #0x20
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	strh r3, [r0, #0xa]
	ldr r1, _081293F0 @ =0x00002201
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r3, r5, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #8
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl Hitbox_SetAttack
_081293E6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081293F0: .4byte 0x00002201
