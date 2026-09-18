	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080601DC @ =0x000007C4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080601E8
	ldr r1, _080601E0 @ =Entity080601a8_Update
	ldr r2, _080601E4 @ =Entity080601a8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity080601a8_Init
	cmp r0, #0
	bge _080601E8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080601EA
	.align 2, 0
_080601DC: .4byte 0x000007C4
_080601E0: .4byte Entity080601a8_Update
_080601E4: .4byte Entity080601a8_Destroy
_080601E8:
	adds r0, r4, #0
_080601EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
