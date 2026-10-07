	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D14A
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x86
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0800D14A:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D174
	strh r2, [r4, #0x34]
	movs r0, #1
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r0, [r4, #1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
_0800D174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
