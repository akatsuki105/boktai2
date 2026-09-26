	push {r4, lr}
	ldr r4, _0804A9F0 @ =gCredits
	ldr r0, [r4]
	cmp r0, #0
	beq _0804A9F4
	bl Credits_Start
	ldr r0, [r4]
	b _0804AA2A
	.align 2, 0
_0804A9F0: .4byte gCredits
_0804A9F4:
	movs r1, #0xed
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804AA28
	ldr r1, _0804AA20 @ =Credits_Update
	ldr r2, _0804AA24 @ =Credits_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Credits_Init
	cmp r0, #0
	bge _0804AA28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804AA2A
	.align 2, 0
_0804AA20: .4byte Credits_Update
_0804AA24: .4byte Credits_Destroy
_0804AA28:
	adds r0, r4, #0
_0804AA2A:
	pop {r4}
	pop {r1}
	bx r1
