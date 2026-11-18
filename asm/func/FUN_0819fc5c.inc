	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819FCA0 @ =0x00000A7C
	adds r6, r0, r1
	adds r1, #0x3c
	adds r4, r0, r1
	adds r1, #0xf0
	adds r5, r0, r1
	movs r7, #2
_0819FC74:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r4, #0x50
	adds r5, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819FC74
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FCA0: .4byte 0x00000A7C
