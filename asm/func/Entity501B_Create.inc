	push {r4, lr}
	movs r1, #0xfb
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E0C0C
	ldr r1, _081E0C04 @ =Entity501B_Update
	ldr r2, _081E0C08 @ =Entity501B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity501B_Init
	cmp r0, #0
	bge _081E0C0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E0C0E
	.align 2, 0
_081E0C04: .4byte Entity501B_Update
_081E0C08: .4byte Entity501B_Destroy
_081E0C0C:
	adds r0, r4, #0
_081E0C0E:
	pop {r4}
	pop {r1}
	bx r1
