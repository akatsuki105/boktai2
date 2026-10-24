	push {r4, lr}
	ldr r1, _080A4E0C @ =0x000008BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4E00
	ldr r1, _080A4E10 @ =Entity1E98_Update
	ldr r2, _080A4E14 @ =Entity1E98_Destroy
	bl SetEntityRoutine
	movs r0, #0
	strb r0, [r4, #0x18]
_080A4E00:
	ldr r0, _080A4E18 @ =0x03002C44
	str r4, [r0]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A4E0C: .4byte 0x000008BC
_080A4E10: .4byte Entity1E98_Update
_080A4E14: .4byte Entity1E98_Destroy
_080A4E18: .4byte 0x03002C44
