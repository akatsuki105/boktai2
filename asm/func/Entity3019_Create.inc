	push {r4, lr}
	movs r1, #0xaa
	lsls r1, r1, #5
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080BCD8C
	ldr r1, _080BCD84 @ =Entity3019_Update
	ldr r2, _080BCD88 @ =Entity3019_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity3019_Init
	cmp r0, #0
	bge _080BCD8C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080BCD8E
	.align 2, 0
_080BCD84: .4byte Entity3019_Update
_080BCD88: .4byte Entity3019_Destroy
_080BCD8C:
	adds r0, r4, #0
_080BCD8E:
	pop {r4}
	pop {r1}
	bx r1
