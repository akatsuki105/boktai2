	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x88
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08211BA4
	ldr r1, _08211B9C @ =AlbumMenu_Update
	ldr r2, _08211BA0 @ =AlbumMenu_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl AlbumMenu_Init
	cmp r0, #0
	bge _08211BA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08211BA6
	.align 2, 0
_08211B9C: .4byte AlbumMenu_Update
_08211BA0: .4byte AlbumMenu_Destroy
_08211BA4:
	adds r0, r4, #0
_08211BA6:
	pop {r4, r5}
	pop {r1}
	bx r1
