	push {r4, r5, lr}
	ldr r5, _080DBE8C @ =0x03000164
	ldr r0, [r5]
	cmp r0, #0
	bne _080DBE9E
	ldr r1, _080DBE90 @ =0x00000A28
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DBE9C
	ldr r1, _080DBE94 @ =Entity080dbe54_Update
	ldr r2, _080DBE98 @ =Entity080dbe54_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity080dbe54_Init
	cmp r0, #0
	bge _080DBE9C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DBE9E
	.align 2, 0
_080DBE8C: .4byte 0x03000164
_080DBE90: .4byte 0x00000A28
_080DBE94: .4byte Entity080dbe54_Update
_080DBE98: .4byte Entity080dbe54_Destroy
_080DBE9C:
	adds r0, r4, #0
_080DBE9E:
	pop {r4, r5}
	pop {r1}
	bx r1
