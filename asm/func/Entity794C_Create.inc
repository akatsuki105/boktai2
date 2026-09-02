	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #5
	movs r1, #0xd8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08240E9C
	ldr r1, _08240E94 @ =Entity794C_Update
	ldr r2, _08240E98 @ =Entity794C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity794C_Init
	cmp r0, #0
	bge _08240E9C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08240E9E
	.align 2, 0
_08240E94: .4byte Entity794C_Update
_08240E98: .4byte Entity794C_Destroy
_08240E9C:
	adds r0, r4, #0
_08240E9E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
