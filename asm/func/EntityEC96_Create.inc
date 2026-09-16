	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xd8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801362C
	ldr r1, _08013624 @ =EntityEC96_Update
	ldr r2, _08013628 @ =EntityEC96_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityEC96_Init
	cmp r0, #0
	bge _0801362C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801362E
	.align 2, 0
_08013624: .4byte EntityEC96_Update
_08013628: .4byte EntityEC96_Destroy
_0801362C:
	adds r0, r4, #0
_0801362E:
	pop {r4, r5}
	pop {r1}
	bx r1
