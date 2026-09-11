	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A903C
	ldr r1, _080A9034 @ =Entity080a8ff8_Update
	ldr r2, _080A9038 @ =Entity080a8ff8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Entity080a8ff8_Init
	cmp r0, #0
	bge _080A903C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A903E
	.align 2, 0
_080A9034: .4byte Entity080a8ff8_Update
_080A9038: .4byte Entity080a8ff8_Destroy
_080A903C:
	adds r0, r4, #0
_080A903E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
