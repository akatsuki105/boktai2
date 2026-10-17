	push {r4, lr}
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A844
	ldr r1, _0801A83C @ =Entity4F5C_Update
	ldr r2, _0801A840 @ =Entity4F5C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4F5C_Init
	cmp r0, #0
	bge _0801A844
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A846
	.align 2, 0
_0801A83C: .4byte Entity4F5C_Update
_0801A840: .4byte Entity4F5C_Destroy
_0801A844:
	adds r0, r4, #0
_0801A846:
	pop {r4}
	pop {r1}
	bx r1
