	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #2
	rsbs r6, r6, #0
	ldr r0, _08098C20 @ =0x000021CC
	adds r2, r5, r0
	movs r3, #0x68
	subs r0, #0x60
	adds r1, r5, r0
	movs r4, #3
_08098BF0:
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0x28
	strh r0, [r1, #0x18]
	strh r3, [r1, #0x1a]
	ldr r0, [r1, #0x60]
	ands r0, r6
	str r0, [r1, #0x60]
	movs r0, #0x30
	strh r0, [r2, #0x18]
	strh r3, [r2, #0x1a]
	adds r2, #0xc0
	adds r3, #8
	adds r1, #0xc0
	subs r4, #1
	cmp r4, #0
	bge _08098BF0
	adds r0, r5, #0
	bl FUN_08098af4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098C20: .4byte 0x000021CC
