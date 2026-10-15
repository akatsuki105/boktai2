	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805A48E
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805A4A6
_0805A48E:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0805A4A6:
	strb r0, [r4, #0xa]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805A508 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805A50C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	movs r2, #0
	strh r0, [r5, #0x3e]
	ldrh r0, [r4, #0x12]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r4, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805A514
	strh r2, [r4, #0x12]
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	ldr r0, _0805A510 @ =0x00000339
	bl PlaySound_082406e0
	b _0805A524
	.align 2, 0
_0805A508: .4byte 0xFFFF0000
_0805A50C: .4byte 0x0000FFFF
_0805A510: .4byte 0x00000339
_0805A514:
	movs r0, #5
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r2, [r4, #6]
	movs r0, #0xcd
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805A524:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
