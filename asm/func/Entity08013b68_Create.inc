	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013BA0
	ldr r1, _08013B98 @ =Entity08013b68_Update
	ldr r2, _08013B9C @ =Entity08013b68_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08013b68_Init
	cmp r0, #0
	bge _08013BA0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013BA2
	.align 2, 0
_08013B98: .4byte Entity08013b68_Update
_08013B9C: .4byte Entity08013b68_Destroy
_08013BA0:
	adds r0, r4, #0
_08013BA2:
	pop {r4, r5}
	pop {r1}
	bx r1
