	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r1, r4, #0
	adds r1, #0x5a
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r4, #0x64]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08089E18
	adds r0, r4, #0
	bl FUN_08089c60
	b _08089E22
_08089E18:
	cmp r1, #2
	bne _08089E22
	adds r0, r4, #0
	bl FUN_08089c44
_08089E22:
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r1]
	subs r0, #0x46
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08089E88
	strh r2, [r1]
	subs r1, #6
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #4
	subs r1, #4
	strh r0, [r1]
	str r2, [r4, #0x64]
	movs r0, #0xe2
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08089c44
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	movs r1, #0xfa
	str r1, [sp, #0xc]
	movs r1, #8
	movs r2, #1
	movs r3, #1
	bl FUN_08015a90
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0
	beq _08089E8E
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
	b _08089E8E
_08089E88:
	ldr r0, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x64]
_08089E8E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
