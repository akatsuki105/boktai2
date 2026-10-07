	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _082464E8 @ =0x00001684
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _082464F4
	ldr r1, _082464EC @ =Entity082464b8_Update
	ldr r2, _082464F0 @ =Entity082464b8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity082464b8_Init
	cmp r0, #0
	bge _082464F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _082464F6
	.align 2, 0
_082464E8: .4byte 0x00001684
_082464EC: .4byte Entity082464b8_Update
_082464F0: .4byte Entity082464b8_Destroy
_082464F4:
	adds r0, r4, #0
_082464F6:
	pop {r4, r5}
	pop {r1}
	bx r1
