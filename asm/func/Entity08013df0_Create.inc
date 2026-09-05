	push {r4, lr}
	ldr r0, _08013E24 @ =0x03002B40
	ldr r0, [r0]
	cmp r0, #0
	bne _08013E32
	movs r0, #9
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013E30
	ldr r1, _08013E28 @ =Entity08013df0_Update
	ldr r2, _08013E2C @ =Entity08013df0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08013df0_Init
	cmp r0, #0
	bge _08013E30
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013E32
	.align 2, 0
_08013E24: .4byte 0x03002B40
_08013E28: .4byte Entity08013df0_Update
_08013E2C: .4byte Entity08013df0_Destroy
_08013E30:
	adds r0, r4, #0
_08013E32:
	pop {r4}
	pop {r1}
	bx r1
