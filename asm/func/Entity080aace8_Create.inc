	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xd4
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AAD28
	ldr r1, _080AAD20 @ =Entity080aace8_Update
	ldr r2, _080AAD24 @ =Entity080aace8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity080aace8_Init
	cmp r0, #0
	bge _080AAD28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AAD2A
	.align 2, 0
_080AAD20: .4byte Entity080aace8_Update
_080AAD24: .4byte Entity080aace8_Destroy
_080AAD28:
	adds r0, r4, #0
_080AAD2A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
