	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A7408 @ =0x085AD014
	ldr r2, _080A740C @ =0x00000341
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl GameOverManager_UpdateLetters
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7408: .4byte 0x085AD014
_080A740C: .4byte 0x00000341
