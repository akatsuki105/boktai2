	push {r4, lr}
	movs r1, #0xc5
	lsls r1, r1, #5
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080BEAD4
	ldr r1, _080BEACC @ =Entity744F_Update
	ldr r2, _080BEAD0 @ =Entity744F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity744F_Init
	cmp r0, #0
	bge _080BEAD4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080BEAD6
	.align 2, 0
_080BEACC: .4byte Entity744F_Update
_080BEAD0: .4byte Entity744F_Destroy
_080BEAD4:
	adds r0, r4, #0
_080BEAD6:
	pop {r4}
	pop {r1}
	bx r1
