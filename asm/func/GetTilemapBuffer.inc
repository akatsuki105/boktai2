	lsls r0, r0, #0xb
	ldr r1, _0822B62C @ =gTilemapBuffer
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0822B62C: .4byte gTilemapBuffer
