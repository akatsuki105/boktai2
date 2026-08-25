	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r2, #0
	cmp r5, #4
	bhi _082111B0
	cmp r4, #0
	blt _082111B0
	cmp r4, #1
	bgt _082111B0
	bl AlbumMenu_GetPhotoSlotCount
	lsls r1, r4, #2
	adds r1, r1, r4
	adds r1, #1
	adds r1, r5, r1
	cmp r0, r1
	blt _082111B0
	movs r0, #1
	b _082111B2
_082111B0:
	movs r0, #0
_082111B2:
	pop {r4, r5}
	pop {r1}
	bx r1
