	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08040E88
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [r1]
	b _08040E92
_08040E88:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	str r0, [r3, #0x1c]
_08040E92:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08040EAA
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [r1]
_08040EAA:
	pop {r0}
	bx r0
	.align 2, 0
