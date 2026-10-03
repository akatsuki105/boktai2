	push {r4, lr}
	ldr r0, _08047314 @ =0x030000C0
	ldr r0, [r0]
	cmp r0, #0
	bne _08047326
	ldr r1, _08047318 @ =0x00001A30
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08047324
	ldr r1, _0804731C @ =EntityAB4E_Update
	ldr r2, _08047320 @ =EntityAB4E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityAB4E_Init
	cmp r0, #0
	bge _08047324
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08047326
	.align 2, 0
_08047314: .4byte 0x030000C0
_08047318: .4byte 0x00001A30
_0804731C: .4byte EntityAB4E_Update
_08047320: .4byte EntityAB4E_Destroy
_08047324:
	adds r0, r4, #0
_08047326:
	pop {r4}
	pop {r1}
	bx r1
