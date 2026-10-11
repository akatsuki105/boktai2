	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	bge _0809FEDC
	adds r4, r6, #0
	adds r4, #0x1c
_0809FECC:
	adds r0, r4, #0
	bl Entity1DBEElem_Update
	adds r4, #0xf4
	adds r5, #1
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _0809FECC
_0809FEDC:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
