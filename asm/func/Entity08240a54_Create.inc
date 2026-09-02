	push {r4, lr}
	movs r0, #3
	movs r1, #0x18
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08240A88
	ldr r1, _08240A80 @ =Entity08240a54_Update
	ldr r2, _08240A84 @ =Entity08240a54_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08240a54_Init
	cmp r0, #0
	bge _08240A88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08240A8A
	.align 2, 0
_08240A80: .4byte Entity08240a54_Update
_08240A84: .4byte Entity08240a54_Destroy
_08240A88:
	adds r0, r4, #0
_08240A8A:
	pop {r4}
	pop {r1}
	bx r1
