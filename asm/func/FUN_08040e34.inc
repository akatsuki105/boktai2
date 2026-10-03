	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, [r3, #0x1c]
	cmp r0, #0
	beq _08040E48
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	str r2, [r0]
_08040E48:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, [r3, #0x1c]
	str r0, [r1]
	str r2, [r3, #0x1c]
	movs r0, #1
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
