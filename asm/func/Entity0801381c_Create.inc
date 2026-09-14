	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013854
	ldr r1, _0801384C @ =Entity0801381c_Update
	ldr r2, _08013850 @ =Entity0801381c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0801381c_Init
	cmp r0, #0
	bge _08013854
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013856
	.align 2, 0
_0801384C: .4byte Entity0801381c_Update
_08013850: .4byte Entity0801381c_Destroy
_08013854:
	adds r0, r4, #0
_08013856:
	pop {r4, r5}
	pop {r1}
	bx r1
