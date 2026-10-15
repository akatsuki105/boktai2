	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1B00
	ldr r1, _080C1AF8 @ =Entity080c1abc_Update
	ldr r2, _080C1AFC @ =Entity080c1abc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Entity080c1abc_Init
	cmp r0, #0
	bge _080C1B00
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1B02
	.align 2, 0
_080C1AF8: .4byte Entity080c1abc_Update
_080C1AFC: .4byte Entity080c1abc_Destroy
_080C1B00:
	adds r0, r4, #0
_080C1B02:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
