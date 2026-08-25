	push {r4, lr}
	movs r1, #0x85
	lsls r1, r1, #4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B5AA8
	ldr r1, _080B5AA0 @ =EntityE9D3_Update
	ldr r2, _080B5AA4 @ =EntityE9D3_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityE9D3_Init
	cmp r0, #0
	bge _080B5AA8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B5AAA
	.align 2, 0
_080B5AA0: .4byte EntityE9D3_Update
_080B5AA4: .4byte EntityE9D3_Destroy
_080B5AA8:
	adds r0, r4, #0
_080B5AAA:
	pop {r4}
	pop {r1}
	bx r1
