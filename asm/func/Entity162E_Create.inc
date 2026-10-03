	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08089B40
	ldr r1, _08089B38 @ =Entity162E_Update
	ldr r2, _08089B3C @ =Entity162E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity162E_Init
	cmp r0, #0
	bge _08089B40
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08089B42
	.align 2, 0
_08089B38: .4byte Entity162E_Update
_08089B3C: .4byte Entity162E_Destroy
_08089B40:
	adds r0, r4, #0
_08089B42:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
