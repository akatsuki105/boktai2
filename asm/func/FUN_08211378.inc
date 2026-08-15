	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0x28
	adds r2, r4, #0
	adds r2, #0x24
	ldrb r2, [r2]
	adds r2, #0x1e
	movs r3, #0
	bl Sprite_SetSprite
	bl FUN_082111b8
	cmp r0, #0
	beq _082113B4
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #1
_082113A4:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _082113A4
	b _082113CC
_082113B4:
	movs r3, #1
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #1
_082113BE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _082113BE
_082113CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
