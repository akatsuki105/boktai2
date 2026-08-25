	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0821117E
_08211170:
	adds r0, r4, #0
	bl AlbumMenu_GetPhotoSlotCount
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r5
	blt _08211170
_0821117E:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
