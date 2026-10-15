	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x84
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805A358
	ldr r1, _0805A350 @ =Entity0805a31c_Update
	ldr r2, _0805A354 @ =Entity0805a31c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805a31c_Init
	cmp r0, #0
	bge _0805A358
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805A35A
	.align 2, 0
_0805A350: .4byte Entity0805a31c_Update
_0805A354: .4byte Entity0805a31c_Destroy
_0805A358:
	adds r0, r4, #0
_0805A35A:
	pop {r4, r5}
	pop {r1}
	bx r1
