	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08216CBC @ =0x0000166C
	adds r5, r4, r0
	adds r0, r4, #0
	bl FUN_08216a90
	ldr r1, _08216CC0 @ =0x000016CC
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #0x4e
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, [r5, #0x68]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x68]
	adds r0, r4, #0
	bl FUN_08216bdc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08216CBC: .4byte 0x0000166C
_08216CC0: .4byte 0x000016CC
