	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080220A8 @ =0x00000434
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080220B4
	ldr r1, _080220AC @ =DoorManager_Update
	ldr r2, _080220B0 @ =DoorManager_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl DoorManager_Init
	cmp r0, #0
	bge _080220B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080220B6
	.align 2, 0
_080220A8: .4byte 0x00000434
_080220AC: .4byte DoorManager_Update
_080220B0: .4byte DoorManager_Destroy
_080220B4:
	adds r0, r4, #0
_080220B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
