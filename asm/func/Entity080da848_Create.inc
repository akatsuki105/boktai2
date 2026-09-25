	push {r4, lr}
	ldr r0, _080DA880 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA88E
	movs r1, #0xa0
	lsls r1, r1, #4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DA88C
	ldr r1, _080DA884 @ =Entity080da848_Update
	ldr r2, _080DA888 @ =Entity080da848_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080da848_Init
	cmp r0, #0
	bge _080DA88C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DA88E
	.align 2, 0
_080DA880: .4byte 0x0300015C
_080DA884: .4byte Entity080da848_Update
_080DA888: .4byte Entity080da848_Destroy
_080DA88C:
	adds r0, r4, #0
_080DA88E:
	pop {r4}
	pop {r1}
	bx r1
