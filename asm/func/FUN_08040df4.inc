	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity286F_FindSpriteData
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _08040E28
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _08040E28
	movs r0, #0
	b _08040E2C
_08040E28:
	movs r0, #1
	rsbs r0, r0, #0
_08040E2C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
