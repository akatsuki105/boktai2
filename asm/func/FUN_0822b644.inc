	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	bne _0822B650
	bl FUN_0822e8b4
_0822B650:
	adds r0, r4, #0
	bl GetTilemapBuffer
	movs r1, #0x80
	lsls r1, r1, #4
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
