	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A334
	ldr r1, _0808A32C @ =Entity28CB_Update
	ldr r2, _0808A330 @ =Entity28CB_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity28CB_Init
	cmp r0, #0
	bge _0808A334
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0808A336
	.align 2, 0
_0808A32C: .4byte Entity28CB_Update
_0808A330: .4byte Entity28CB_Destroy
_0808A334:
	adds r0, r4, #0
_0808A336:
	pop {r4, r5}
	pop {r1}
	bx r1
