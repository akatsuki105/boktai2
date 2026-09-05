	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #0
	beq _08050604
	movs r1, #0
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x34
	strb r1, [r0]
	ldrh r0, [r6, #0x1e]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r4, r1, #4
	subs r4, r4, r1
	lsls r4, r4, #4
	ldr r5, [r6, #0x44]
	adds r5, r4, r5
	ldr r0, [r6, #0x50]
	adds r4, r4, r0
	bl FUN_0804e458
	ldr r1, _0805066C @ =gSystemSaveData
	ldr r1, [r1]
	ldr r3, [r1, #0xc]
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r2, r6, #0
	adds r2, #0xc8
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, #4]
	ldr r2, _08050670 @ =FUN_0804fbf0
	str r2, [sp, #8]
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_08052b3c
	movs r3, #1
	adds r1, r6, #0
	adds r1, #0xf4
	movs r2, #1
_080505F6:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080505F6
_08050604:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050662
	adds r4, r6, #0
	adds r4, #0xbc
	movs r1, #0xa
	adds r0, r6, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r6, #0x24]
	adds r0, r6, #0
	adds r0, #0x35
	strb r2, [r0]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_0804fb6c
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	adds r3, r0, #0
	str r3, [r4]
	cmp r3, #0
	blt _08050662
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r3, #0
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
_08050662:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805066C: .4byte gSystemSaveData
_08050670: .4byte FUN_0804fbf0
