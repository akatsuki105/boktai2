	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08213628 @ =0x0000CB05
	ldr r1, _0821362C @ =0x0000D353
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	adds r2, #0x18
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	adds r0, #0x18
	bl OpenSpriteSetFile
	adds r0, r4, #0
	bl FUN_082125a0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08213628: .4byte 0x0000CB05
_0821362C: .4byte 0x0000D353
