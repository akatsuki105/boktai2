	push {lr}
	ldr r0, _0822B640 @ =gTilemapBuffer
	movs r1, #0x80
	lsls r1, r1, #6
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_0822B640: .4byte gTilemapBuffer
