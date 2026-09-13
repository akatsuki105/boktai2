	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016698
	ldr r1, _08016690 @ =Entity08016660_Update
	ldr r2, _08016694 @ =Entity08016660_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity08016660_Init
	cmp r0, #0
	bge _08016698
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801669A
	.align 2, 0
_08016690: .4byte Entity08016660_Update
_08016694: .4byte Entity08016660_Destroy
_08016698:
	adds r0, r4, #0
_0801669A:
	pop {r4, r5}
	pop {r1}
	bx r1
