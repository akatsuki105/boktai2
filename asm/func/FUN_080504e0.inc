	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805051A
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_0804fa94
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	movs r2, #4
	ldr r1, _08050540 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0805051A:
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r2, [r4, #0x20]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	bne _08050548
	ldr r0, _08050544 @ =0xFFFFFCFF
	ands r2, r0
	str r2, [r4, #0x20]
	movs r1, #8
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	str r2, [r4, #0x24]
	b _0805054E
	.align 2, 0
_08050540: .4byte 0x030044BC
_08050544: .4byte 0xFFFFFCFF
_08050548:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_0805054E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
